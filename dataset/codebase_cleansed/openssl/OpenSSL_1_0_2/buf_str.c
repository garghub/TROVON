size_t BUF_strnlen(const char *str, size_t maxlen)
{
const char *p;
for (p = str; maxlen-- != 0 && *p != '\0'; ++p) ;
return p - str;
}
char *BUF_strdup(const char *str)
{
if (str == NULL)
return (NULL);
return BUF_strndup(str, strlen(str));
}
char *BUF_strndup(const char *str, size_t siz)
{
char *ret;
if (str == NULL)
return (NULL);
siz = BUF_strnlen(str, siz);
ret = OPENSSL_malloc(siz + 1);
if (ret == NULL) {
BUFerr(BUF_F_BUF_STRNDUP, ERR_R_MALLOC_FAILURE);
return (NULL);
}
BUF_strlcpy(ret, str, siz + 1);
return (ret);
}
void *BUF_memdup(const void *data, size_t siz)
{
void *ret;
if (data == NULL)
return (NULL);
ret = OPENSSL_malloc(siz);
if (ret == NULL) {
BUFerr(BUF_F_BUF_MEMDUP, ERR_R_MALLOC_FAILURE);
return (NULL);
}
return memcpy(ret, data, siz);
}
size_t BUF_strlcpy(char *dst, const char *src, size_t size)
{
size_t l = 0;
for (; size > 1 && *src; size--) {
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
for (; size > 0 && *dst; size--, dst++)
l++;
return l + BUF_strlcpy(dst, src, size);
}
