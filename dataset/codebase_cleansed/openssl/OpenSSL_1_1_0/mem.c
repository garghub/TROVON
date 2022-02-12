int CRYPTO_set_mem_functions(
void *(*m)(size_t, const char *, int),
void *(*r)(void *, size_t, const char *, int),
void (*f)(void *, const char *, int))
{
if (!allow_customize)
return 0;
if (m)
malloc_impl = m;
if (r)
realloc_impl = r;
if (f)
free_impl = f;
return 1;
}
int CRYPTO_set_mem_debug(int flag)
{
if (!allow_customize)
return 0;
call_malloc_debug = flag;
return 1;
}
void CRYPTO_get_mem_functions(
void *(**m)(size_t, const char *, int),
void *(**r)(void *, size_t, const char *, int),
void (**f)(void *, const char *, int))
{
if (m != NULL)
*m = malloc_impl;
if (r != NULL)
*r = realloc_impl;
if (f != NULL)
*f = free_impl;
}
void *CRYPTO_malloc(size_t num, const char *file, int line)
{
void *ret = NULL;
if (malloc_impl != NULL && malloc_impl != CRYPTO_malloc)
return malloc_impl(num, file, line);
if (num <= 0)
return NULL;
allow_customize = 0;
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
if (call_malloc_debug) {
CRYPTO_mem_debug_malloc(NULL, num, 0, file, line);
ret = malloc(num);
CRYPTO_mem_debug_malloc(ret, num, 1, file, line);
} else {
ret = malloc(num);
}
#else
osslargused(file); osslargused(line);
ret = malloc(num);
#endif
return ret;
}
void *CRYPTO_zalloc(size_t num, const char *file, int line)
{
void *ret = CRYPTO_malloc(num, file, line);
if (ret != NULL)
memset(ret, 0, num);
return ret;
}
void *CRYPTO_realloc(void *str, size_t num, const char *file, int line)
{
if (realloc_impl != NULL && realloc_impl != &CRYPTO_realloc)
return realloc_impl(str, num, file, line);
if (str == NULL)
return CRYPTO_malloc(num, file, line);
if (num == 0) {
CRYPTO_free(str, file, line);
return NULL;
}
allow_customize = 0;
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
if (call_malloc_debug) {
void *ret;
CRYPTO_mem_debug_realloc(str, NULL, num, 0, file, line);
ret = realloc(str, num);
CRYPTO_mem_debug_realloc(str, ret, num, 1, file, line);
return ret;
}
#else
osslargused(file); osslargused(line);
#endif
return realloc(str, num);
}
void *CRYPTO_clear_realloc(void *str, size_t old_len, size_t num,
const char *file, int line)
{
void *ret = NULL;
if (str == NULL)
return CRYPTO_malloc(num, file, line);
if (num == 0) {
CRYPTO_clear_free(str, old_len, file, line);
return NULL;
}
if (num < old_len) {
OPENSSL_cleanse((char*)str + num, old_len - num);
return str;
}
ret = CRYPTO_malloc(num, file, line);
if (ret != NULL) {
memcpy(ret, str, old_len);
CRYPTO_clear_free(str, old_len, file, line);
}
return ret;
}
void CRYPTO_free(void *str, const char *file, int line)
{
if (free_impl != NULL && free_impl != &CRYPTO_free) {
free_impl(str, file, line);
return;
}
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
if (call_malloc_debug) {
CRYPTO_mem_debug_free(str, 0, file, line);
free(str);
CRYPTO_mem_debug_free(str, 1, file, line);
} else {
free(str);
}
#else
free(str);
#endif
}
void CRYPTO_clear_free(void *str, size_t num, const char *file, int line)
{
if (str == NULL)
return;
if (num)
OPENSSL_cleanse(str, num);
CRYPTO_free(str, file, line);
}
