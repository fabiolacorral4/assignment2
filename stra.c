#include "str.h"
#include <stdlib.h>
#include <assert.h>

/* Implementation of Str Module using Array Notation */

size_t Str_getLength(const char s[])
{
    assert(s != NULL);
    size_t len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

char* Str_copy(char dest[], const char src[])
{
    assert(src != NULL);
    assert(dest != NULL);
    size_t len = Str_getLength(src);
    for (size_t i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}

char* Str_concat(char dest[], const char src[])
{
    assert(src != NULL);
    assert(dest != NULL);
    size_t len_src = Str_getLength(src);
    size_t len_dest = Str_getLength(dest);
    for (size_t i = 0; i < len_src; i++)
        dest[len_dest+i] = src[i];
    dest[len_dest+len_src] = '\0';
    return dest;
}

int Str_compare(const char str1[], const char str2[])
{
    assert(str1 != NULL);
    assert(str2 != NULL);
    size_t i = 0;
    int result = 0;
    while (str1[i] != '\0')
    {
        if (str1[i]==str2[i]){
            i++;
            continue;
        } 
        else if (str1[i]<str2[i])
        {
            result = -1;
            return result;
        }
        else if (str1[i]>str2[i])
        {
            result = 1;
            return result;
        }
    }
    if (Str_getLength(str1) < Str_getLength(str2)) result = -1;
    return result;
}

const char* Str_search(const char s[], const char subs[])
{
    assert(s != NULL);
    assert(subs != NULL);
    size_t len_s = Str_getLength(s);   
    size_t len_subs = Str_getLength(subs);
    if (len_subs == 0) return s; 
    for (size_t i = 0; i < len_s; i++)
    {
        int count = 0;
        while (s[i+count]==subs[count])
        {
            if (count == len_subs-1) return &s[i];
            else count++;
        }
    }
    return NULL;
}
