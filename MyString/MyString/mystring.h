#pragma once
#include<stdio.h> 
#include <string.h>
#include <string>
#include <iostream>
using namespace std;

typedef unsigned int size_t;

/* @brief  function count length of string
* @param  [in] str - address of the string
* @return length of string
*/
size_t mystrlen(const char* str);
/* @brief  function copy string1 to string 2
* @param  [in, out] dst -1st string address
* @param  [in] src - 2nd string adress
* @return dst address
*/
char* mystrcpy(char* dst, const char* src);

/* @brief  function compare 2 characters
* @param  [in] chr1 -1st character
* @param  [in] chr2 - 2nd character 
* @return  0 if equal, 1 if 1st > 2nd, -1 if 1st <2nd, 2 if 1st = terminate symbol 
*/
int mychrcmp(char chr1, char chr2);

/* @brief  function concatenate string 2 with string 1
* @param  [in, out] dst - 1st string address
* @param  [in] src - 2nd string address
* @return  dst address, with concatenated strings
*/

char* mystrcat(char* dst, const char* src);

/* @brief  function compare 2 strings
* @param  [in] str1 -1st string
* @param  [in] str2 - 2nd string
* @return  0 if equal, 1 if 1st > 2nd, -1 if 1st <2nd, 
*/
int mystrcmp(const char* str1, const char*str2);

/* @brief  function copy n elements of string 1 to string 2
* @param  [in, out] dst -1st string address
* @param  [in] src - 2nd string adress
* @param [in] n - number of elements to copy
* @return dst address
*/
char* mystrncpy(char* dst, const char* src, size_t n);

/* @brief function retun first occurrence of character in string
* @param  [in, out] src - string adress
* @param  [in] c -  character
* @return src address
*/
char* mystrchr(const char* src, int c);

/* @brief function retun first occurrence of character in first n characters of string
* @param  [in, out] src - string adress
* @param  [in] c -  character
* @param  [in] n -  number of characters
* @return src address
*/
char* mystrnchr(const char* src, int c, size_t n);

/* @brief function covert from string with default terminate symbol to string with TS which use mystring.h function
* @param  [in, out] str - string adress
* @return str address
*/
char* convert_to_mystring(char* str);

/* @brief  function compare n elements of 2 strings
* @param  [in] str1 -1st string
* @param  [in] str2 - 2nd string
* @param  [in] n - number of elements
* @return  0 if equal, 1 if 1st > 2nd, -1 if 1st <2nd,
*/
int mystrncmp(const char* str1, const char* str2, size_t n);

/* @brief  function concatenate n elements of string 2 with string 1
* @param  [in, out] dst - 1st string address
* @param  [in] src - 2nd string address
* @param  [in] n - number of elements
* @return  dst address, with concatenated strings
*/

char* mystrncat(char*, const char*, size_t);  
/* @brief  function copy n bytes of src to dst memory address
* @param  [in, out] dst - 1st string address
* @param  [in] src - 2nd string address
* @param  [in] n - number of elements
* @return  dst address, with copied bytes
*/
void* mymemcpy(const void* src, void* dst, size_t n);

/* @brief  function set n bytes of dst with c character 
* @param  [in, out] dst - 1st string address
* @param  [in] n - number of elements
* @param  [in] c - character
* @return  dst address, with set bytes
*/
void* mymemset(void* dst, int c, size_t n);


/* @brief  function return length of elements(in a row)
* in string 1 that are same as in string 2
* @param  [in] str1 - 1st string address
* @param  [in] str2 - 2nd string address
* @return  length of elements(in a row)
*/
size_t mystrspn(const char *str1, const char *str2);


/*@brief function return length of elements(in a row) in string 1
* that aren't same as in string 2
* @param [in] str1 - 1st string address
* @param [in] str2 - 2nd string address
* @return length of elements(in a row)
*/
size_t mystrcspn(const char *str1, const char *str2);

/* @brief function look for the first element in the string 1 
that matches any element specified in string 2.
* @param  [in] str1 - 1st string address
* @param  [in] str2 - 2nd string address
* @return  str1 address
*/
char* mystrpbrk(const char *str1, const char *str2);
/* @brief function convert mystring.h TS to Null terminated 
* @param  [in] str - string address
* @return  str address
*/

char* convert_to_default(char* str);

char* mystrstr(const char *str1, const char *substr);