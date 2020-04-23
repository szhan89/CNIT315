#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
void APIcall(char *zipcode){
    /*##########Declaration##########*/
    CURL *curl;
    FILE *fp;
    int result;
    int insert_index=52;//the start location of zipcode insert 
    char *api="http://api.openweathermap.org/data/2.5/forecast?zip=,us&appid=2d2179e0ac9680ea504b01d61da6ba23&mode=Json";//the api used to obtain 5 day weather information of U.S with given zipcode
    char *url=malloc(strlen(zipcode)+strlen(api)+1);//allocate space for the url
    /*###############################*/


    strncpy(url, api, insert_index);//copy the first 52 character to the url
    strcat(url, zipcode);//append the zipcode to the url
    strcat(url, api+insert_index);//append the rest of the the api to the url
    fp = fopen("weather.Json","wb");//create and open a file to store API returned information
    curl=curl_easy_init();//initialize curl handler
    
    curl_easy_setopt(curl, CURLOPT_URL, url);//set access destination
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);//store downloaded data to file
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);//set fail error code
    
    result = curl_easy_perform(curl);//download the API returns and store download status
    
    if(result==CURLE_OK)
        printf("Done!\n");
    else
        printf("ERROR: %s\n", curl_easy_strerror(result));

    fclose(fp);//close file

    curl_easy_cleanup(curl);//clean handler
    
}
