int BN_GENCB_call(BN_GENCB *cb, int a, int b)
{
if (!cb)
return 1;
switch (cb->ver) {
case 1:
if (!cb->cb.cb_1)
return 1;
cb->cb.cb_1(a, b, cb->arg);
return 1;
case 2:
return cb->cb.cb_2(a, b, cb);
default:
break;
}
return 0;
}
int BN_generate_prime_ex(BIGNUM *ret, int bits, int safe,
const BIGNUM *add, const BIGNUM *rem, BN_GENCB *cb)
{
BIGNUM *t;
int found = 0;
int i, j, c1 = 0;
BN_CTX *ctx = NULL;
prime_t *mods = NULL;
int checks = BN_prime_checks_for_size(bits);
if (bits < 2) {
BNerr(BN_F_BN_GENERATE_PRIME_EX, BN_R_BITS_TOO_SMALL);
return 0;
} else if (bits == 2 && safe) {
BNerr(BN_F_BN_GENERATE_PRIME_EX, BN_R_BITS_TOO_SMALL);
return 0;
}
mods = OPENSSL_zalloc(sizeof(*mods) * NUMPRIMES);
if (mods == NULL)
goto err;
ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
BN_CTX_start(ctx);
t = BN_CTX_get(ctx);
if (!t)
goto err;
loop:
if (add == NULL) {
if (!probable_prime(ret, bits, mods))
goto err;
} else {
if (safe) {
if (!probable_prime_dh_safe(ret, bits, add, rem, ctx))
goto err;
} else {
if (!bn_probable_prime_dh(ret, bits, add, rem, ctx))
goto err;
}
}
if (!BN_GENCB_call(cb, 0, c1++))
goto err;
if (!safe) {
i = BN_is_prime_fasttest_ex(ret, checks, ctx, 0, cb);
if (i == -1)
goto err;
if (i == 0)
goto loop;
} else {
if (!BN_rshift1(t, ret))
goto err;
for (i = 0; i < checks; i++) {
j = BN_is_prime_fasttest_ex(ret, 1, ctx, 0, cb);
if (j == -1)
goto err;
if (j == 0)
goto loop;
j = BN_is_prime_fasttest_ex(t, 1, ctx, 0, cb);
if (j == -1)
goto err;
if (j == 0)
goto loop;
if (!BN_GENCB_call(cb, 2, c1 - 1))
goto err;
}
}
found = 1;
err:
OPENSSL_free(mods);
if (ctx != NULL)
BN_CTX_end(ctx);
BN_CTX_free(ctx);
bn_check_top(ret);
return found;
}
int BN_is_prime_ex(const BIGNUM *a, int checks, BN_CTX *ctx_passed,
BN_GENCB *cb)
{
return BN_is_prime_fasttest_ex(a, checks, ctx_passed, 0, cb);
}
int BN_is_prime_fasttest_ex(const BIGNUM *a, int checks, BN_CTX *ctx_passed,
int do_trial_division, BN_GENCB *cb)
{
int i, j, ret = -1;
int k;
BN_CTX *ctx = NULL;
BIGNUM *A1, *A1_odd, *check;
BN_MONT_CTX *mont = NULL;
const BIGNUM *A = NULL;
if (BN_cmp(a, BN_value_one()) <= 0)
return 0;
if (checks == BN_prime_checks)
checks = BN_prime_checks_for_size(BN_num_bits(a));
if (!BN_is_odd(a))
return BN_is_word(a, 2);
if (do_trial_division) {
for (i = 1; i < NUMPRIMES; i++) {
BN_ULONG mod = BN_mod_word(a, primes[i]);
if (mod == (BN_ULONG)-1)
goto err;
if (mod == 0)
return 0;
}
if (!BN_GENCB_call(cb, 1, -1))
goto err;
}
if (ctx_passed != NULL)
ctx = ctx_passed;
else if ((ctx = BN_CTX_new()) == NULL)
goto err;
BN_CTX_start(ctx);
if (a->neg) {
BIGNUM *t;
if ((t = BN_CTX_get(ctx)) == NULL)
goto err;
BN_copy(t, a);
t->neg = 0;
A = t;
} else
A = a;
A1 = BN_CTX_get(ctx);
A1_odd = BN_CTX_get(ctx);
check = BN_CTX_get(ctx);
if (check == NULL)
goto err;
if (!BN_copy(A1, A))
goto err;
if (!BN_sub_word(A1, 1))
goto err;
if (BN_is_zero(A1)) {
ret = 0;
goto err;
}
k = 1;
while (!BN_is_bit_set(A1, k))
k++;
if (!BN_rshift(A1_odd, A1, k))
goto err;
mont = BN_MONT_CTX_new();
if (mont == NULL)
goto err;
if (!BN_MONT_CTX_set(mont, A, ctx))
goto err;
for (i = 0; i < checks; i++) {
if (!BN_pseudo_rand_range(check, A1))
goto err;
if (!BN_add_word(check, 1))
goto err;
j = witness(check, A, A1, A1_odd, k, ctx, mont);
if (j == -1)
goto err;
if (j) {
ret = 0;
goto err;
}
if (!BN_GENCB_call(cb, 1, i))
goto err;
}
ret = 1;
err:
if (ctx != NULL) {
BN_CTX_end(ctx);
if (ctx_passed == NULL)
BN_CTX_free(ctx);
}
BN_MONT_CTX_free(mont);
return (ret);
}
int bn_probable_prime_dh_retry(BIGNUM *rnd, int bits, BN_CTX *ctx)
{
int i;
int ret = 0;
loop:
if (!BN_rand(rnd, bits, BN_RAND_TOP_ONE, BN_RAND_BOTTOM_ODD))
goto err;
for (i = 1; i < NUMPRIMES; i++) {
BN_ULONG mod = BN_mod_word(rnd, (BN_ULONG)primes[i]);
if (mod == (BN_ULONG)-1)
goto err;
if (mod <= 1) {
goto loop;
}
}
ret = 1;
err:
bn_check_top(rnd);
return (ret);
}
int bn_probable_prime_dh_coprime(BIGNUM *rnd, int bits, BN_CTX *ctx)
{
int i;
BIGNUM *offset_index;
BIGNUM *offset_count;
int ret = 0;
OPENSSL_assert(bits > prime_multiplier_bits);
BN_CTX_start(ctx);
if ((offset_index = BN_CTX_get(ctx)) == NULL)
goto err;
if ((offset_count = BN_CTX_get(ctx)) == NULL)
goto err;
if (!BN_add_word(offset_count, prime_offset_count))
goto err;
loop:
if (!BN_rand(rnd, bits - prime_multiplier_bits,
BN_RAND_TOP_ONE, BN_RAND_BOTTOM_ODD))
goto err;
if (BN_is_bit_set(rnd, bits))
goto loop;
if (!BN_rand_range(offset_index, offset_count))
goto err;
if (!BN_mul_word(rnd, prime_multiplier)
|| !BN_add_word(rnd, prime_offsets[BN_get_word(offset_index)]))
goto err;
for (i = first_prime_index; i < NUMPRIMES; i++) {
BN_ULONG mod = BN_mod_word(rnd, (BN_ULONG)primes[i]);
if (mod == (BN_ULONG)-1)
goto err;
if (mod <= 1)
goto loop;
}
ret = 1;
err:
BN_CTX_end(ctx);
bn_check_top(rnd);
return ret;
}
static int witness(BIGNUM *w, const BIGNUM *a, const BIGNUM *a1,
const BIGNUM *a1_odd, int k, BN_CTX *ctx,
BN_MONT_CTX *mont)
{
if (!BN_mod_exp_mont(w, w, a1_odd, a, ctx, mont))
return -1;
if (BN_is_one(w))
return 0;
if (BN_cmp(w, a1) == 0)
return 0;
while (--k) {
if (!BN_mod_mul(w, w, w, a, ctx))
return -1;
if (BN_is_one(w))
return 1;
if (BN_cmp(w, a1) == 0)
return 0;
}
bn_check_top(w);
return 1;
}
static int probable_prime(BIGNUM *rnd, int bits, prime_t *mods)
{
int i;
BN_ULONG delta;
BN_ULONG maxdelta = BN_MASK2 - primes[NUMPRIMES - 1];
char is_single_word = bits <= BN_BITS2;
again:
if (!BN_rand(rnd, bits, BN_RAND_TOP_TWO, BN_RAND_BOTTOM_ODD))
return (0);
for (i = 1; i < NUMPRIMES; i++) {
BN_ULONG mod = BN_mod_word(rnd, (BN_ULONG)primes[i]);
if (mod == (BN_ULONG)-1)
return 0;
mods[i] = (prime_t) mod;
}
if (is_single_word) {
BN_ULONG size_limit;
if (bits == BN_BITS2) {
size_limit = ~((BN_ULONG)0) - BN_get_word(rnd);
} else {
size_limit = (((BN_ULONG)1) << bits) - BN_get_word(rnd) - 1;
}
if (size_limit < maxdelta)
maxdelta = size_limit;
}
delta = 0;
loop:
if (is_single_word) {
BN_ULONG rnd_word = BN_get_word(rnd);
for (i = 1; i < NUMPRIMES && primes[i] < rnd_word; i++) {
if ((mods[i] + delta) % primes[i] == 0) {
delta += 2;
if (delta > maxdelta)
goto again;
goto loop;
}
}
} else {
for (i = 1; i < NUMPRIMES; i++) {
if (((mods[i] + delta) % primes[i]) <= 1) {
delta += 2;
if (delta > maxdelta)
goto again;
goto loop;
}
}
}
if (!BN_add_word(rnd, delta))
return (0);
if (BN_num_bits(rnd) != bits)
goto again;
bn_check_top(rnd);
return (1);
}
int bn_probable_prime_dh(BIGNUM *rnd, int bits,
const BIGNUM *add, const BIGNUM *rem, BN_CTX *ctx)
{
int i, ret = 0;
BIGNUM *t1;
BN_CTX_start(ctx);
if ((t1 = BN_CTX_get(ctx)) == NULL)
goto err;
if (!BN_rand(rnd, bits, BN_RAND_TOP_ONE, BN_RAND_BOTTOM_ODD))
goto err;
if (!BN_mod(t1, rnd, add, ctx))
goto err;
if (!BN_sub(rnd, rnd, t1))
goto err;
if (rem == NULL) {
if (!BN_add_word(rnd, 1))
goto err;
} else {
if (!BN_add(rnd, rnd, rem))
goto err;
}
loop:
for (i = 1; i < NUMPRIMES; i++) {
BN_ULONG mod = BN_mod_word(rnd, (BN_ULONG)primes[i]);
if (mod == (BN_ULONG)-1)
goto err;
if (mod <= 1) {
if (!BN_add(rnd, rnd, add))
goto err;
goto loop;
}
}
ret = 1;
err:
BN_CTX_end(ctx);
bn_check_top(rnd);
return (ret);
}
static int probable_prime_dh_safe(BIGNUM *p, int bits, const BIGNUM *padd,
const BIGNUM *rem, BN_CTX *ctx)
{
int i, ret = 0;
BIGNUM *t1, *qadd, *q;
bits--;
BN_CTX_start(ctx);
t1 = BN_CTX_get(ctx);
q = BN_CTX_get(ctx);
qadd = BN_CTX_get(ctx);
if (qadd == NULL)
goto err;
if (!BN_rshift1(qadd, padd))
goto err;
if (!BN_rand(q, bits, BN_RAND_TOP_ONE, BN_RAND_BOTTOM_ODD))
goto err;
if (!BN_mod(t1, q, qadd, ctx))
goto err;
if (!BN_sub(q, q, t1))
goto err;
if (rem == NULL) {
if (!BN_add_word(q, 1))
goto err;
} else {
if (!BN_rshift1(t1, rem))
goto err;
if (!BN_add(q, q, t1))
goto err;
}
if (!BN_lshift1(p, q))
goto err;
if (!BN_add_word(p, 1))
goto err;
loop:
for (i = 1; i < NUMPRIMES; i++) {
BN_ULONG pmod = BN_mod_word(p, (BN_ULONG)primes[i]);
BN_ULONG qmod = BN_mod_word(q, (BN_ULONG)primes[i]);
if (pmod == (BN_ULONG)-1 || qmod == (BN_ULONG)-1)
goto err;
if (pmod == 0 || qmod == 0) {
if (!BN_add(p, p, padd))
goto err;
if (!BN_add(q, q, qadd))
goto err;
goto loop;
}
}
ret = 1;
err:
BN_CTX_end(ctx);
bn_check_top(p);
return (ret);
}
