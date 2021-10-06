/* header file to be used in both stra.c and strp.c 
contains declarations of string-processing functons */
#include <stddef.h>
#ifndef STR
#define STR

/* function that returns length of string */
size_t Str_getLength(const char s[]);

/* function that returns a copy of string src in string dest */
char* Str_copy(char dest[], const char src[]);

/* function that appends the string src to the end of string dest 
and returns a pointer to te dest string */
char* Str_concat(char dest[], const char src[]);

/* function that compares str1 to str2 
and returns 0 if string are equal, -1 is str1 is less than str2,
and 1 is str1 is greater than str2 */
int Str_compare(const char str1[], const char str2[]);

/* function that finds and returns pointer to first occurence
of the entire string subs in the string s  */
const char* Str_search(const char s[], const char subs[]);

#endif

