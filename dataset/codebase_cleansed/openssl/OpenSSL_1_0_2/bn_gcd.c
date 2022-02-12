int BN_gcd(BIGNUM *r, const BIGNUM *in_a, const BIGNUM *in_b, BN_CTX *ctx)
{
BIGNUM *a, *b, *t;
int ret = 0;
bn_check_top(in_a);
bn_check_top(in_b);
BN_CTX_start(ctx);
a = BN_CTX_get(ctx);
b = BN_CTX_get(ctx);
if (a == NULL || b == NULL)
goto err;
if (BN_copy(a, in_a) == NULL)
goto err;
if (BN_copy(b, in_b) == NULL)
goto err;
a->neg = 0;
b->neg = 0;
if (BN_cmp(a, b) < 0) {
t = a;
a = b;
b = t;
}
t = euclid(a, b);
if (t == NULL)
goto err;
if (BN_copy(r, t) == NULL)
goto err;
ret = 1;
err:
BN_CTX_end(ctx);
bn_check_top(r);
return (ret);
}
static BIGNUM *euclid(BIGNUM *a, BIGNUM *b)
{
BIGNUM *t;
int shifts = 0;
bn_check_top(a);
bn_check_top(b);
while (!BN_is_zero(b)) {
if (BN_is_odd(a)) {
if (BN_is_odd(b)) {
if (!BN_sub(a, a, b))
goto err;
if (!BN_rshift1(a, a))
goto err;
if (BN_cmp(a, b) < 0) {
t = a;
a = b;
b = t;
}
} else {
if (!BN_rshift1(b, b))
goto err;
if (BN_cmp(a, b) < 0) {
t = a;
a = b;
b = t;
}
}
} else {
if (BN_is_odd(b)) {
if (!BN_rshift1(a, a))
goto err;
if (BN_cmp(a, b) < 0) {
t = a;
a = b;
b = t;
}
} else {
if (!BN_rshift1(a, a))
goto err;
if (!BN_rshift1(b, b))
goto err;
shifts++;
}
}
}
if (shifts) {
if (!BN_lshift(a, a, shifts))
goto err;
}
bn_check_top(a);
return (a);
err:
return (NULL);
}
BIGNUM *BN_mod_inverse(BIGNUM *in,
const BIGNUM *a, const BIGNUM *n, BN_CTX *ctx)
{
BIGNUM *A, *B, *X, *Y, *M, *D, *T, *R = NULL;
BIGNUM *ret = NULL;
int sign;
if ((BN_get_flags(a, BN_FLG_CONSTTIME) != 0)
|| (BN_get_flags(n, BN_FLG_CONSTTIME) != 0)) {
return BN_mod_inverse_no_branch(in, a, n, ctx);
}
bn_check_top(a);
bn_check_top(n);
BN_CTX_start(ctx);
A = BN_CTX_get(ctx);
B = BN_CTX_get(ctx);
X = BN_CTX_get(ctx);
D = BN_CTX_get(ctx);
M = BN_CTX_get(ctx);
Y = BN_CTX_get(ctx);
T = BN_CTX_get(ctx);
if (T == NULL)
goto err;
if (in == NULL)
R = BN_new();
else
R = in;
if (R == NULL)
goto err;
BN_one(X);
BN_zero(Y);
if (BN_copy(B, a) == NULL)
goto err;
if (BN_copy(A, n) == NULL)
goto err;
A->neg = 0;
if (B->neg || (BN_ucmp(B, A) >= 0)) {
if (!BN_nnmod(B, B, A, ctx))
goto err;
}
sign = -1;
if (BN_is_odd(n) && (BN_num_bits(n) <= (BN_BITS <= 32 ? 450 : 2048))) {
int shift;
while (!BN_is_zero(B)) {
shift = 0;
while (!BN_is_bit_set(B, shift)) {
shift++;
if (BN_is_odd(X)) {
if (!BN_uadd(X, X, n))
goto err;
}
if (!BN_rshift1(X, X))
goto err;
}
if (shift > 0) {
if (!BN_rshift(B, B, shift))
goto err;
}
shift = 0;
while (!BN_is_bit_set(A, shift)) {
shift++;
if (BN_is_odd(Y)) {
if (!BN_uadd(Y, Y, n))
goto err;
}
if (!BN_rshift1(Y, Y))
goto err;
}
if (shift > 0) {
if (!BN_rshift(A, A, shift))
goto err;
}
if (BN_ucmp(B, A) >= 0) {
if (!BN_uadd(X, X, Y))
goto err;
if (!BN_usub(B, B, A))
goto err;
} else {
if (!BN_uadd(Y, Y, X))
goto err;
if (!BN_usub(A, A, B))
goto err;
}
}
} else {
while (!BN_is_zero(B)) {
BIGNUM *tmp;
if (BN_num_bits(A) == BN_num_bits(B)) {
if (!BN_one(D))
goto err;
if (!BN_sub(M, A, B))
goto err;
} else if (BN_num_bits(A) == BN_num_bits(B) + 1) {
if (!BN_lshift1(T, B))
goto err;
if (BN_ucmp(A, T) < 0) {
if (!BN_one(D))
goto err;
if (!BN_sub(M, A, B))
goto err;
} else {
if (!BN_sub(M, A, T))
goto err;
if (!BN_add(D, T, B))
goto err;
if (BN_ucmp(A, D) < 0) {
if (!BN_set_word(D, 2))
goto err;
} else {
if (!BN_set_word(D, 3))
goto err;
if (!BN_sub(M, M, B))
goto err;
}
}
} else {
if (!BN_div(D, M, A, B, ctx))
goto err;
}
tmp = A;
A = B;
B = M;
if (BN_is_one(D)) {
if (!BN_add(tmp, X, Y))
goto err;
} else {
if (BN_is_word(D, 2)) {
if (!BN_lshift1(tmp, X))
goto err;
} else if (BN_is_word(D, 4)) {
if (!BN_lshift(tmp, X, 2))
goto err;
} else if (D->top == 1) {
if (!BN_copy(tmp, X))
goto err;
if (!BN_mul_word(tmp, D->d[0]))
goto err;
} else {
if (!BN_mul(tmp, D, X, ctx))
goto err;
}
if (!BN_add(tmp, tmp, Y))
goto err;
}
M = Y;
Y = X;
X = tmp;
sign = -sign;
}
}
if (sign < 0) {
if (!BN_sub(Y, n, Y))
goto err;
}
if (BN_is_one(A)) {
if (!Y->neg && BN_ucmp(Y, n) < 0) {
if (!BN_copy(R, Y))
goto err;
} else {
if (!BN_nnmod(R, Y, n, ctx))
goto err;
}
} else {
BNerr(BN_F_BN_MOD_INVERSE, BN_R_NO_INVERSE);
goto err;
}
ret = R;
err:
if ((ret == NULL) && (in == NULL))
BN_free(R);
BN_CTX_end(ctx);
bn_check_top(ret);
return (ret);
}
static BIGNUM *BN_mod_inverse_no_branch(BIGNUM *in,
const BIGNUM *a, const BIGNUM *n,
BN_CTX *ctx)
{
BIGNUM *A, *B, *X, *Y, *M, *D, *T, *R = NULL;
BIGNUM local_A, local_B;
BIGNUM *pA, *pB;
BIGNUM *ret = NULL;
int sign;
bn_check_top(a);
bn_check_top(n);
BN_CTX_start(ctx);
A = BN_CTX_get(ctx);
B = BN_CTX_get(ctx);
X = BN_CTX_get(ctx);
D = BN_CTX_get(ctx);
M = BN_CTX_get(ctx);
Y = BN_CTX_get(ctx);
T = BN_CTX_get(ctx);
if (T == NULL)
goto err;
if (in == NULL)
R = BN_new();
else
R = in;
if (R == NULL)
goto err;
BN_one(X);
BN_zero(Y);
if (BN_copy(B, a) == NULL)
goto err;
if (BN_copy(A, n) == NULL)
goto err;
A->neg = 0;
if (B->neg || (BN_ucmp(B, A) >= 0)) {
pB = &local_B;
BN_with_flags(pB, B, BN_FLG_CONSTTIME);
if (!BN_nnmod(B, pB, A, ctx))
goto err;
}
sign = -1;
while (!BN_is_zero(B)) {
BIGNUM *tmp;
pA = &local_A;
BN_with_flags(pA, A, BN_FLG_CONSTTIME);
if (!BN_div(D, M, pA, B, ctx))
goto err;
tmp = A;
A = B;
B = M;
if (!BN_mul(tmp, D, X, ctx))
goto err;
if (!BN_add(tmp, tmp, Y))
goto err;
M = Y;
Y = X;
X = tmp;
sign = -sign;
}
if (sign < 0) {
if (!BN_sub(Y, n, Y))
goto err;
}
if (BN_is_one(A)) {
if (!Y->neg && BN_ucmp(Y, n) < 0) {
if (!BN_copy(R, Y))
goto err;
} else {
if (!BN_nnmod(R, Y, n, ctx))
goto err;
}
} else {
BNerr(BN_F_BN_MOD_INVERSE_NO_BRANCH, BN_R_NO_INVERSE);
goto err;
}
ret = R;
err:
if ((ret == NULL) && (in == NULL))
BN_free(R);
BN_CTX_end(ctx);
bn_check_top(ret);
return (ret);
}
