#include "mystring.h"



#define END_TS '\1' //my terminate symbol
#define EQUAL 0
#define BIG 1
#define SMALL -1
#define TSEQUAL 2
#define DEF_INIT -2

/*Extra string functions*/

int mychrcmp(char chr1, char chr2)   //remade
{	
	if (chr1 == END_TS && chr2 == END_TS){
		return TSEQUAL;
	}
	if (chr1 == chr2){
		return EQUAL;
	}
	return chr1 > chr2 ? BIG : SMALL;

}

/*Main string functions*/

size_t mystrlen(const char* str){ //remade
	size_t counter = 0;
									
	if (NULL == str) return 0;
	while (*(str++) != END_TS){
		counter++; 
	}
	return counter;
}

/////////////////////////////////////////////////////////////////////////////////////////////

char* mystrcpy(char* dst, const char* src){				//remade
	if (NULL == src|| dst == NULL) return 0;
	while (*src != END_TS){					
		*(dst++) = *(src++);
	}

	*dst = END_TS;
	return dst;

}

/////////////////////////////////////////////////////////////////////////////////////////////

char* mystrncpy(char* dst, const char* src, size_t n){		//remade
	if (NULL == src) return 0;
	int i = 0;
	while (i<n){
		*(dst++) = *(src++);
		i++;
	}
	*dst = END_TS;
	return dst;
}

//////////////////////////////////////////////////////////////////////////////////////////

//remade

char* mystrcat(char* dst, const char* src){
	if (NULL == src||dst == NULL) return 0;
	int offset = mystrlen(dst);
	mystrcpy(dst + offset, src);
	return dst;
}

///////////////////////////////////////////////////////////////////////////////////////////

//remade

char* mystrncat(char* dst, const char* src, size_t n){
	if (NULL == src || dst== NULL) return 0;
	mystrcpy(dst + n, src);
	return dst;
}

/////////////////////////////////////////////////////////////////////////////////////////////

char* mystrchr(const char* src, int c){
	int ret = DEF_INIT;
	if (NULL == src) return 0;
	while (*src != END_TS && (0 != (ret = mychrcmp(*(src++), c)))){}
	if (ret == 0) {
		return  (char*)(--src);
	}
	else  if (c == END_TS){
		return (char*)src;
	}
	return NULL;

}

///////////////////////////////////////////////////////////////////////////////////////////

//remade

char* mystrnchr(const char* src, int c, size_t n){
	if (NULL == src) return 0;
	const char *endptr = src + n;
	int ret = DEF_INIT;
	if (n <= 0){ return NULL; }else{
		while (*src != *endptr && (0 != (ret = mychrcmp(*(src++), c)))){}
		if (ret == 0) {
			return  (char*)(--src);
		}
		else  if (c == *endptr){
			return (char*)src;
		}
		return NULL;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////

//remade

int mystrcmp(const char* str1, const char* str2){
	if (NULL == str1 || NULL == str2) return 0;
	int ret = DEF_INIT;
	while (0 == (ret = mychrcmp(*(str1++), *(str2++)))){}
	return (ret == TSEQUAL) ? 0 : ret;
}

//////////////////////////////////////////////////////////////////////////////////////////

//remade

int mystrncmp(const char* str1, const char* str2, size_t n){
	int ret = 0;
	int i = 0;
	while (0 == (ret = mychrcmp(*(str1++), *(str2++)) && i != n)){ i++; }
	return (ret == TSEQUAL) ? 0 : ret;
}







/////////////////////////////////////////////////////////////////////////////////////////////

size_t mystrspn(const char *str1, const char *str2){
	if (NULL == str1 || NULL == str2) return 0;
	size_t count = 0;
	char iteratorStr;
	while ((iteratorStr = *str1++) != END_TS &&  NULL != mystrchr(str2, iteratorStr)){
		count++;
	}
	return count;

}

/////////////////////////////////////////////////////////////////////////////////////////////

size_t mystrcspn(const char *str1, const char *str2){
	if (NULL == str1 || NULL == str2) return 0;
	size_t count = 0;
	char iteratorStr;
	while ((iteratorStr = *str1++) != END_TS &&  NULL == mystrchr(str2, iteratorStr)){
		count++;
	}
	return count;

}

/////////////////////////////////////////////////////////////////////////////////////////////

void* mymemcpy(const void* src, void* dst, size_t n){

	if (NULL == src) return 0;
	if (n <= 0){ return dst; }
	else{
	unsigned char* src1 = (unsigned char*)src;
	size_t i = 0;
	unsigned char* dst1 = (unsigned char*)dst;


		unsigned char* endstr = src1 + n;
		while ((*dst1++ = *src1++) && src1 != endstr){}
		*dst1 = END_TS;
		return dst;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

void* mymemset(void* dst, int c, size_t n){
	if (n <= 0){ return dst; }
	else{
	unsigned char* dst1 = (unsigned char*)dst;

	
		unsigned char* endstr = dst1 + n;
		while ((*dst1++ = c) && dst1 != endstr){}
		*dst1 = END_TS;
		return dst;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////

char* mystrpbrk(const char *str1, const char *str2){
	const char* ret;
	while (*str1 != END_TS){
		ret = str2;
		while (*ret != END_TS){
			if (*str1 == *ret){
				return (char*)str1;
			}
			else{
			*ret++;
			}


		}
		 *str1++;
	}
	return 0;
}

/*Converting string functions*/

char* convert_to_default(char* str)
{
	*(str + mystrlen(str)) = '\0';
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////////////

char* convert_to_mystring(char* str){
	if (NULL == str) return 0;
	char* conv = str;
	while (*(conv++) != 0){
		
	}
	*conv = END_TS;
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////////////

/*char* mystrstr(const char *str1, const char *substr){
	char* retPtr = NULL;
	if ((retPtr = mystrchr(str1, *substr)) != NULL) {
		retPtr = mystrncmp(retPtr, substr, (mystrlen(substr)) == 0 ? retPtr : NULL);
	}

	return retPtr;*/


void main(){
	char* p = new char[25];
	char *q = new char[25];
	char a = '2';
	char b = 'c';
	memset(q, 0, 25);
	memset(p, 0, 25);
	strncpy(q, "HELLO WORLD \x1",11);
	convert_to_mystring(q);
	mystrncpy(p, q, 5);
	convert_to_default(p);
	printf("%s", p);
	
	
	//string a;
	//for (int i = 0; i < 11; i++){
	//	a.push_back(p[i]);
	//}
	//cout << a;
}
