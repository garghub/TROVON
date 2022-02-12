BUF_MEM *BUF_MEM_new(void)
{
BUF_MEM *ret;
ret=OPENSSL_malloc(sizeof(BUF_MEM));
if (ret == NULL)
{
BUFerr(BUF_F_BUF_MEM_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->length=0;
ret->max=0;
ret->data=NULL;
return(ret);
}
void BUF_MEM_free(BUF_MEM *a)
{
if(a == NULL)
return;
if (a->data != NULL)
{
memset(a->data,0,(unsigned int)a->max);
OPENSSL_free(a->data);
}
OPENSSL_free(a);
}
int BUF_MEM_grow(BUF_MEM *str, int len)
{
char *ret;
unsigned int n;
if (str->length >= len)
{
str->length=len;
return(len);
}
if (str->max >= len)
{
memset(&str->data[str->length],0,len-str->length);
str->length=len;
return(len);
}
n=(len+3)/3*4;
if (str->data == NULL)
ret=OPENSSL_malloc(n);
else
ret=OPENSSL_realloc(str->data,n);
if (ret == NULL)
{
BUFerr(BUF_F_BUF_MEM_GROW,ERR_R_MALLOC_FAILURE);
len=0;
}
else
{
str->data=ret;
str->max=n;
memset(&str->data[str->length],0,len-str->length);
str->length=len;
}
return(len);
}
int BUF_MEM_grow_clean(BUF_MEM *str, int len)
{
char *ret;
unsigned int n;
if (str->length >= len)
{
memset(&str->data[len],0,str->length-len);
str->length=len;
return(len);
}
if (str->max >= len)
{
memset(&str->data[str->length],0,len-str->length);
str->length=len;
return(len);
}
n=(len+3)/3*4;
if (str->data == NULL)
ret=OPENSSL_malloc(n);
else
ret=OPENSSL_realloc_clean(str->data,str->max,n);
if (ret == NULL)
{
BUFerr(BUF_F_BUF_MEM_GROW,ERR_R_MALLOC_FAILURE);
len=0;
}
else
{
str->data=ret;
str->max=n;
memset(&str->data[str->length],0,len-str->length);
str->length=len;
}
return(len);
}
char *BUF_strdup(const char *str)
{
char *ret;
int n;
if (str == NULL) return(NULL);
n=strlen(str);
ret=OPENSSL_malloc(n+1);
if (ret == NULL)
{
BUFerr(BUF_F_BUF_STRDUP,ERR_R_MALLOC_FAILURE);
return(NULL);
}
memcpy(ret,str,n+1);
return(ret);
}
size_t BUF_strlcpy(char *dst, const char *src, size_t size)
{
size_t l = 0;
for(; size > 1 && *src; size--)
{
*dst++ = *src++;
l++;
}
if (size)
*dst = '\0';
return l + strlen(src);
}
size_t BUF_strlcat(char *dst, const char *src, size_t size)
{
size_t l = 0;
for(; size > 0 && *dst; size--, dst++)
l++;
return l + BUF_strlcpy(dst, src, size);
}
