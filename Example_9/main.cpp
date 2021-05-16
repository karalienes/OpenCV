#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main () {
    char haystack[20] = "TutorialsPoint";
    char needle[10] = "u";
    char *ret;

    ret = strstr(haystack, needle);

    printf("The substring is: %s\n", ret);

    return(0);
}