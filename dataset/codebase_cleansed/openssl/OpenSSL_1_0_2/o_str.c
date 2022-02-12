int OPENSSL_strncasecmp(const char *str1, const char *str2, size_t n)
{
#if defined(OPENSSL_IMPLEMENTS_strncasecmp)
while (*str1 && *str2 && n) {
int res = toupper(*str1) - toupper(*str2);
if (res)
return res < 0 ? -1 : 1;
str1++;
str2++;
n--;
}
if (n == 0)
return 0;
if (*str1)
return 1;
if (*str2)
return -1;
return 0;
#else
return strncasecmp(str1, str2, n);
#endif
}
int OPENSSL_strcasecmp(const char *str1, const char *str2)
{
#if defined(OPENSSL_IMPLEMENTS_strncasecmp)
return OPENSSL_strncasecmp(str1, str2, (size_t)-1);
#else
return strcasecmp(str1, str2);
#endif
}
int OPENSSL_memcmp(const void *v1, const void *v2, size_t n)
{
const unsigned char *c1 = v1, *c2 = v2;
int ret = 0;
while (n && (ret = *c1 - *c2) == 0)
n--, c1++, c2++;
return ret;
}
