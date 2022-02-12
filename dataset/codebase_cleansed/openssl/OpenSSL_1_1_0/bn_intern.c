signed char *bn_compute_wNAF(const BIGNUM *scalar, int w, size_t *ret_len)
{
int window_val;
signed char *r = NULL;
int sign = 1;
int bit, next_bit, mask;
size_t len = 0, j;
if (BN_is_zero(scalar)) {
r = OPENSSL_malloc(1);
if (r == NULL) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_MALLOC_FAILURE);
goto err;
}
r[0] = 0;
*ret_len = 1;
return r;
}
if (w <= 0 || w > 7) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
bit = 1 << w;
next_bit = bit << 1;
mask = next_bit - 1;
if (BN_is_negative(scalar)) {
sign = -1;
}
if (scalar->d == NULL || scalar->top == 0) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
len = BN_num_bits(scalar);
r = OPENSSL_malloc(len + 1);
if (r == NULL) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_MALLOC_FAILURE);
goto err;
}
window_val = scalar->d[0] & mask;
j = 0;
while ((window_val != 0) || (j + w + 1 < len)) {
int digit = 0;
if (window_val & 1) {
if (window_val & bit) {
digit = window_val - next_bit;
#if 1
if (j + w + 1 >= len) {
digit = window_val & (mask >> 1);
}
#endif
} else {
digit = window_val;
}
if (digit <= -bit || digit >= bit || !(digit & 1)) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
window_val -= digit;
if (window_val != 0 && window_val != next_bit
&& window_val != bit) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
}
r[j++] = sign * digit;
window_val >>= 1;
window_val += bit * BN_is_bit_set(scalar, j + w);
if (window_val > next_bit) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
}
if (j > len + 1) {
BNerr(BN_F_BN_COMPUTE_WNAF, ERR_R_INTERNAL_ERROR);
goto err;
}
*ret_len = j;
return r;
err:
OPENSSL_free(r);
return NULL;
}
int bn_get_top(const BIGNUM *a)
{
return a->top;
}
void bn_set_top(BIGNUM *a, int top)
{
a->top = top;
}
int bn_get_dmax(const BIGNUM *a)
{
return a->dmax;
}
void bn_set_all_zero(BIGNUM *a)
{
int i;
for (i = a->top; i < a->dmax; i++)
a->d[i] = 0;
}
int bn_copy_words(BN_ULONG *out, const BIGNUM *in, int size)
{
if (in->top > size)
return 0;
memset(out, 0, sizeof(*out) * size);
memcpy(out, in->d, sizeof(*out) * in->top);
return 1;
}
BN_ULONG *bn_get_words(const BIGNUM *a)
{
return a->d;
}
void bn_set_static_words(BIGNUM *a, BN_ULONG *words, int size)
{
a->d = words;
a->dmax = a->top = size;
a->neg = 0;
a->flags |= BN_FLG_STATIC_DATA;
bn_correct_top(a);
}
int bn_set_words(BIGNUM *a, BN_ULONG *words, int num_words)
{
if (bn_wexpand(a, num_words) == NULL) {
BNerr(BN_F_BN_SET_WORDS, ERR_R_MALLOC_FAILURE);
return 0;
}
memcpy(a->d, words, sizeof(BN_ULONG) * num_words);
a->top = num_words;
bn_correct_top(a);
return 1;
}
size_t bn_sizeof_BIGNUM(void)
{
return sizeof(BIGNUM);
}
BIGNUM *bn_array_el(BIGNUM *base, int el)
{
return &base[el];
}
