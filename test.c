#include<stdlib.h>
#include<stdio.h>
#include"strcpy_s.h"

void test_arr_len(){
    char arr[4] = {'a','\0'};
    printf("size of arr is %d\n",sizeof(arr)/sizeof(char));
    return;
}

void test_strcpy_s(){
    char* arr = (char*)calloc(10,sizeof(char));
    char* dest = (char*) malloc(5*sizeof(char));
    printf("Please input a string within 10 letters to be copied :\n");
    scanf("%s",arr);
    strcpy_s(dest, arr, 1);
    printf("The destination string copied is:\n%s",dest);
    return;
}
int main(){
    test_strcpy_s();
    return 0;
}
