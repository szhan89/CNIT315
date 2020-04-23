#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

int main(){
  char *usr_zipcode = malloc(5 * sizeof(*usr_zipcode));
  printf("Welcome to Weather Tracker\nPlease Enter Your Area Zipcode:");
   scanf("%s",usr_zipcode);//Store user entered zipcode
   APIcall(usr_zipcode);//Make API call and generate a xml file with the location information
   readJson("1");
    return 0;
}
