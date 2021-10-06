#include <stddef.h>

#ifndef STR
#define STR

/* function that returns length of string */
size_t Str_getLength(const char s[]);

/* function that returns a copy of string src in string dest */
char* Str_copy(char dest[], const char src[]);

/* function that appends the string src to the end of string dest */
char* Str_concat(char dest[], const char src[]);

/* function that compares str1 to str2  */
int Str_compare(const char str1[], const char str2[]);

/* function that finds first occurence of the entire string subs
in the string s */
const char* Str_search(const char s[], const char subs[]);

#endif

