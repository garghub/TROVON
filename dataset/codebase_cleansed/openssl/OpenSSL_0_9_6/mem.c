int CRYPTO_set_mem_functions(void *(*m)(size_t), void *(*r)(void *, size_t),
void (*f)(void *))
{
if (!allow_customize)
return 0;
if ((m == NULL) || (r == NULL) || (f == NULL))
return 0;
malloc_func=m;
realloc_func=r;
free_func=f;
malloc_locked_func=m;
free_locked_func=f;
return 1;
}
int CRYPTO_set_locked_mem_functions(void *(*m)(size_t), void (*f)(void *))
{
if (!allow_customize)
return 0;
if ((m == NULL) || (f == NULL))
return 0;
malloc_locked_func=m;
free_locked_func=f;
return 1;
}
int CRYPTO_set_mem_debug_functions(void (*m)(void *,int,const char *,int,int),
void (*r)(void *,void *,int,const char *,int,int),
void (*f)(void *,int),
void (*so)(long),
long (*go)(void))
{
if (!allow_customize_debug)
return 0;
malloc_debug_func=m;
realloc_debug_func=r;
free_debug_func=f;
set_debug_options_func=so;
get_debug_options_func=go;
return 1;
}
void CRYPTO_get_mem_functions(void *(**m)(size_t), void *(**r)(void *, size_t),
void (**f)(void *))
{
if (m != NULL) *m=malloc_func;
if (r != NULL) *r=realloc_func;
if (f != NULL) *f=free_func;
}
void CRYPTO_get_locked_mem_functions(void *(**m)(size_t), void (**f)(void *))
{
if (m != NULL) *m=malloc_locked_func;
if (f != NULL) *f=free_locked_func;
}
void CRYPTO_get_mem_debug_functions(void (**m)(void *,int,const char *,int,int),
void (**r)(void *,void *,int,const char *,int,int),
void (**f)(void *,int),
void (**so)(long),
long (**go)(void))
{
if (m != NULL) *m=malloc_debug_func;
if (r != NULL) *r=realloc_debug_func;
if (f != NULL) *f=free_debug_func;
if (so != NULL) *so=set_debug_options_func;
if (go != NULL) *go=get_debug_options_func;
}
void *CRYPTO_malloc_locked(int num, const char *file, int line)
{
void *ret = NULL;
allow_customize = 0;
if (malloc_debug_func != NULL)
{
allow_customize_debug = 0;
malloc_debug_func(NULL, num, file, line, 0);
}
ret = malloc_locked_func(num);
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: > 0x%p (%d)\n", ret, num);
#endif
if (malloc_debug_func != NULL)
malloc_debug_func(ret, num, file, line, 1);
return ret;
}
void CRYPTO_free_locked(void *str)
{
if (free_debug_func != NULL)
free_debug_func(str, 0);
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: < 0x%p\n", str);
#endif
free_locked_func(str);
if (free_debug_func != NULL)
free_debug_func(NULL, 1);
}
void *CRYPTO_malloc(int num, const char *file, int line)
{
void *ret = NULL;
allow_customize = 0;
if (malloc_debug_func != NULL)
{
allow_customize_debug = 0;
malloc_debug_func(NULL, num, file, line, 0);
}
ret = malloc_func(num);
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: > 0x%p (%d)\n", ret, num);
#endif
if (malloc_debug_func != NULL)
malloc_debug_func(ret, num, file, line, 1);
return ret;
}
void *CRYPTO_realloc(void *str, int num, const char *file, int line)
{
void *ret = NULL;
if (realloc_debug_func != NULL)
realloc_debug_func(str, NULL, num, file, line, 0);
ret = realloc_func(str,num);
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: | 0x%p -> 0x%p (%d)\n", str, ret, num);
#endif
if (realloc_debug_func != NULL)
realloc_debug_func(str, ret, num, file, line, 1);
return ret;
}
void CRYPTO_free(void *str)
{
if (free_debug_func != NULL)
free_debug_func(str, 0);
#ifdef LEVITTE_DEBUG
fprintf(stderr, "LEVITTE_DEBUG: < 0x%p\n", str);
#endif
free_func(str);
if (free_debug_func != NULL)
free_debug_func(NULL, 1);
}
void *CRYPTO_remalloc(void *a, int num, const char *file, int line)
{
if (a != NULL) OPENSSL_free(a);
a=(char *)OPENSSL_malloc(num);
return(a);
}
void CRYPTO_set_mem_debug_options(long bits)
{
if (set_debug_options_func != NULL)
set_debug_options_func(bits);
}
long CRYPTO_get_mem_debug_options(void)
{
if (get_debug_options_func != NULL)
return get_debug_options_func();
return 0;
}
