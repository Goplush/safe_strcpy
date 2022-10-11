#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
bool init_flag;


inline int ErrorHandeler(int flag){
    
    /* handeler code */
    switch (flag)
    {
    case 0:
        break;
    case -1:
        printf("The source string is too long or illigal( without a '\\0' at the end) \n");
        return(-1);
    case -2:
        printf("The destination array is too small, autofixing...\n");
        return;
    case -3:
        printf("No enough memory space for copying, please try again later!\n");
        return(-3);
    default:
        printf("Some unknown error occured, error number is %d",flag);
        return(-114514);
    }
        
}

int strcpy_s(char* dst, char* src, int max_len){
    int prog_status = 0, real_len = 0;
    char* cursor = src;
    while(real_len < max_len){
        char c = *cursor++;
        if(c == '\0'){break;}
        real_len++;
    }
    if(real_len == max_len){prog_status=ErrorHandeler(-1);}
    if(sizeof(dst)/sizeof(char) < real_len){
        ErrorHandeler(-2);
        dst = (char*) realloc((void*)dst, (real_len+1)*sizeof(char));
        if(dst== NULL){prog_status = ErrorHandeler(-3);}
    }
    dst[real_len] = '\0';
    int i = 0;
    while (i<real_len)
    {
        dst[i] = src[i];
        i++;
    }
    return prog_status;
    
}