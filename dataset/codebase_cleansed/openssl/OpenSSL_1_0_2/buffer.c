BUF_MEM *BUF_MEM_new(void)
{
BUF_MEM *ret;
ret = OPENSSL_malloc(sizeof(BUF_MEM));
if (ret == NULL) {
BUFerr(BUF_F_BUF_MEM_NEW, ERR_R_MALLOC_FAILURE);
return (NULL);
}
ret->length = 0;
ret->max = 0;
ret->data = NULL;
return (ret);
}
void BUF_MEM_free(BUF_MEM *a)
{
if (a == NULL)
return;
if (a->data != NULL) {
memset(a->data, 0, (unsigned int)a->max);
OPENSSL_free(a->data);
}
OPENSSL_free(a);
}
int BUF_MEM_grow(BUF_MEM *str, size_t len)
{
char *ret;
size_t n;
if (str->length >= len) {
str->length = len;
return (len);
}
if (str->max >= len) {
memset(&str->data[str->length], 0, len - str->length);
str->length = len;
return (len);
}
if (len > LIMIT_BEFORE_EXPANSION) {
BUFerr(BUF_F_BUF_MEM_GROW, ERR_R_MALLOC_FAILURE);
return 0;
}
n = (len + 3) / 3 * 4;
if (str->data == NULL)
ret = OPENSSL_malloc(n);
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
int BUF_MEM_grow_clean(BUF_MEM *str, size_t len)
{
char *ret;
size_t n;
if (str->length >= len) {
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
if (str->data == NULL)
ret = OPENSSL_malloc(n);
else
ret = OPENSSL_realloc_clean(str->data, str->max, n);
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
