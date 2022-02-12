BUF_MEM *BUF_MEM_new_ex(unsigned long flags)
{
BUF_MEM *ret;
ret = BUF_MEM_new();
if (ret != NULL)
ret->flags = flags;
return (ret);
}
BUF_MEM *BUF_MEM_new(void)
{
BUF_MEM *ret;
ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
BUFerr(BUF_F_BUF_MEM_NEW, ERR_R_MALLOC_FAILURE);
return (NULL);
}
return (ret);
}
void BUF_MEM_free(BUF_MEM *a)
{
if (a == NULL)
return;
if (a->data != NULL) {
if (a->flags & BUF_MEM_FLAG_SECURE)
OPENSSL_secure_free(a->data);
else
OPENSSL_clear_free(a->data, a->max);
}
OPENSSL_free(a);
}
static char *sec_alloc_realloc(BUF_MEM *str, size_t len)
{
char *ret;
ret = OPENSSL_secure_malloc(len);
if (str->data != NULL) {
if (ret != NULL)
memcpy(ret, str->data, str->length);
OPENSSL_secure_free(str->data);
}
return (ret);
}
size_t BUF_MEM_grow(BUF_MEM *str, size_t len)
{
char *ret;
size_t n;
if (str->length >= len) {
str->length = len;
return (len);
}
if (str->max >= len) {
if (str->data != NULL)
memset(&str->data[str->length], 0, len - str->length);
str->length = len;
return (len);
}
if (len > LIMIT_BEFORE_EXPANSION) {
BUFerr(BUF_F_BUF_MEM_GROW, ERR_R_MALLOC_FAILURE);
return 0;
}
n = (len + 3) / 3 * 4;
if ((str->flags & BUF_MEM_FLAG_SECURE))
ret = sec_alloc_realloc(str, n);
else
ret = OPENSSL_realloc(str->data, n);
if (ret == NULL) {
BUFerr(BUF_F_BUF_MEM_GROW, ERR_R_MALLOC_FAILURE);
len = 0;
} else {
str->data = ret;
str->max = n;
memset(&str->data[str->length], 0, len - str->length);
str->length = len;
}
return (len);
}
size_t BUF_MEM_grow_clean(BUF_MEM *str, size_t len)
{
char *ret;
size_t n;
if (str->length >= len) {
if (str->data != NULL)
memset(&str->data[len], 0, str->length - len);
str->length = len;
return (len);
}
if (str->max >= len) {
memset(&str->data[str->length], 0, len - str->length);
str->length = len;
return (len);
}
if (len > LIMIT_BEFORE_EXPANSION) {
BUFerr(BUF_F_BUF_MEM_GROW_CLEAN, ERR_R_MALLOC_FAILURE);
return 0;
}
n = (len + 3) / 3 * 4;
if ((str->flags & BUF_MEM_FLAG_SECURE))
ret = sec_alloc_realloc(str, n);
else
ret = OPENSSL_clear_realloc(str->data, str->max, n);
if (ret == NULL) {
BUFerr(BUF_F_BUF_MEM_GROW_CLEAN, ERR_R_MALLOC_FAILURE);
len = 0;
} else {
str->data = ret;
str->max = n;
memset(&str->data[str->length], 0, len - str->length);
str->length = len;
}
return (len);
}
void BUF_reverse(unsigned char *out, const unsigned char *in, size_t size)
{
size_t i;
if (in) {
out += size - 1;
for (i = 0; i < size; i++)
*out-- = *in++;
} else {
unsigned char *q;
char c;
q = out + size - 1;
for (i = 0; i < size / 2; i++) {
c = *q;
*q-- = *out;
*out++ = c;
}
}
}
