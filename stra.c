/* Implementation of Str Module using Array Notation */
#include "str.h"
#include <stdlib.h>
#include <assert.h>



size_t Str_getLength(const char s[])
{
    size_t len = 0;
    assert(s != NULL);
    while (s[len] != '\0')
        len++;
    return len;
}

char* Str_copy(char dest[], const char src[])
{
    size_t len = Str_getLength(src);
    size_t i;
    assert(src != NULL);
    assert(dest != NULL);
    for (i = 0; i < len; i++)
        dest[i] = src[i];
    dest[len] = '\0';
    return dest;
}

char* Str_concat(char dest[], const char src[])
{
    size_t len_src = Str_getLength(src);
    size_t len_dest = Str_getLength(dest);
    size_t i;
    assert(src != NULL);
    assert(dest != NULL);
    for (i = 0; i < len_src; i++)
        dest[len_dest+i] = src[i];
    dest[len_dest+len_src] = '\0';
    return dest;
}

int Str_compare(const char str1[], const char str2[])
{
    size_t i = 0;
    int result = 0;
    assert(str1 != NULL);
    assert(str2 != NULL);
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
    size_t len_s = Str_getLength(s);   
    size_t len_subs = Str_getLength(subs);
    size_t i;
    assert(s != NULL);
    assert(subs != NULL);
    if (len_subs == 0) return s; 
    for (i = 0; i < len_s; i++)
    {
        size_t count = 0;
        while (s[i+count]==subs[count])
        {
            if (count == len_subs-1) return &s[i];
            else count++;
        }
    }
    return NULL;
}
