static int bnrand(int pseudorand, BIGNUM *rnd, int bits, int top, int bottom)
{
unsigned char *buf = NULL;
int ret = 0, bit, bytes, mask;
time_t tim;
if (bits == 0) {
BN_zero(rnd);
return 1;
}
bytes = (bits + 7) / 8;
bit = (bits - 1) % 8;
mask = 0xff << (bit + 1);
buf = (unsigned char *)OPENSSL_malloc(bytes);
if (buf == NULL) {
BNerr(BN_F_BNRAND, ERR_R_MALLOC_FAILURE);
goto err;
}
time(&tim);
RAND_add(&tim, sizeof(tim), 0.0);
if (pseudorand) {
if (RAND_pseudo_bytes(buf, bytes) == -1)
goto err;
} else {
if (RAND_bytes(buf, bytes) <= 0)
goto err;
}
#if 1
if (pseudorand == 2) {
int i;
unsigned char c;
for (i = 0; i < bytes; i++) {
RAND_pseudo_bytes(&c, 1);
if (c >= 128 && i > 0)
buf[i] = buf[i - 1];
else if (c < 42)
buf[i] = 0;
else if (c < 84)
buf[i] = 255;
}
}
#endif
if (top != -1) {
if (top) {
if (bit == 0) {
buf[0] = 1;
buf[1] |= 0x80;
} else {
buf[0] |= (3 << (bit - 1));
}
} else {
buf[0] |= (1 << bit);
}
}
buf[0] &= ~mask;
if (bottom)
buf[bytes - 1] |= 1;
if (!BN_bin2bn(buf, bytes, rnd))
goto err;
ret = 1;
err:
if (buf != NULL) {
OPENSSL_cleanse(buf, bytes);
OPENSSL_free(buf);
}
bn_check_top(rnd);
return (ret);
}
int BN_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
return bnrand(0, rnd, bits, top, bottom);
}
int BN_pseudo_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
return bnrand(1, rnd, bits, top, bottom);
}
int BN_bntest_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
return bnrand(2, rnd, bits, top, bottom);
}
static int bn_rand_range(int pseudo, BIGNUM *r, const BIGNUM *range)
{
int (*bn_rand) (BIGNUM *, int, int, int) =
pseudo ? BN_pseudo_rand : BN_rand;
int n;
int count = 100;
if (range->neg || BN_is_zero(range)) {
BNerr(BN_F_BN_RAND_RANGE, BN_R_INVALID_RANGE);
return 0;
}
n = BN_num_bits(range);
if (n == 1)
BN_zero(r);
else if (!BN_is_bit_set(range, n - 2) && !BN_is_bit_set(range, n - 3)) {
do {
if (!bn_rand(r, n + 1, -1, 0))
return 0;
if (BN_cmp(r, range) >= 0) {
if (!BN_sub(r, r, range))
return 0;
if (BN_cmp(r, range) >= 0)
if (!BN_sub(r, r, range))
return 0;
}
if (!--count) {
BNerr(BN_F_BN_RAND_RANGE, BN_R_TOO_MANY_ITERATIONS);
return 0;
}
}
while (BN_cmp(r, range) >= 0);
} else {
do {
if (!bn_rand(r, n, -1, 0))
return 0;
if (!--count) {
BNerr(BN_F_BN_RAND_RANGE, BN_R_TOO_MANY_ITERATIONS);
return 0;
}
}
while (BN_cmp(r, range) >= 0);
}
bn_check_top(r);
return 1;
}
int BN_rand_range(BIGNUM *r, const BIGNUM *range)
{
return bn_rand_range(0, r, range);
}
int BN_pseudo_rand_range(BIGNUM *r, const BIGNUM *range)
{
return bn_rand_range(1, r, range);
}
