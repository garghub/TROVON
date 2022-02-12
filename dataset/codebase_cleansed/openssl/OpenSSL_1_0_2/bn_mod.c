int BN_nnmod(BIGNUM *r, const BIGNUM *m, const BIGNUM *d, BN_CTX *ctx)
{
if (!(BN_mod(r, m, d, ctx)))
return 0;
if (!r->neg)
return 1;
return (d->neg ? BN_sub : BN_add) (r, r, d);
}
int BN_mod_add(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
BN_CTX *ctx)
{
if (!BN_add(r, a, b))
return 0;
return BN_nnmod(r, r, m, ctx);
}
int BN_mod_add_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
const BIGNUM *m)
{
if (!BN_uadd(r, a, b))
return 0;
if (BN_ucmp(r, m) >= 0)
return BN_usub(r, r, m);
return 1;
}
int BN_mod_sub(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
BN_CTX *ctx)
{
if (!BN_sub(r, a, b))
return 0;
return BN_nnmod(r, r, m, ctx);
}
int BN_mod_sub_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *b,
const BIGNUM *m)
{
if (!BN_sub(r, a, b))
return 0;
if (r->neg)
return BN_add(r, r, m);
return 1;
}
int BN_mod_mul(BIGNUM *r, const BIGNUM *a, const BIGNUM *b, const BIGNUM *m,
BN_CTX *ctx)
{
BIGNUM *t;
int ret = 0;
bn_check_top(a);
bn_check_top(b);
bn_check_top(m);
BN_CTX_start(ctx);
if ((t = BN_CTX_get(ctx)) == NULL)
goto err;
if (a == b) {
if (!BN_sqr(t, a, ctx))
goto err;
} else {
if (!BN_mul(t, a, b, ctx))
goto err;
}
if (!BN_nnmod(r, t, m, ctx))
goto err;
bn_check_top(r);
ret = 1;
err:
BN_CTX_end(ctx);
return (ret);
}
int BN_mod_sqr(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx)
{
if (!BN_sqr(r, a, ctx))
return 0;
return BN_mod(r, r, m, ctx);
}
int BN_mod_lshift1(BIGNUM *r, const BIGNUM *a, const BIGNUM *m, BN_CTX *ctx)
{
if (!BN_lshift1(r, a))
return 0;
bn_check_top(r);
return BN_nnmod(r, r, m, ctx);
}
int BN_mod_lshift1_quick(BIGNUM *r, const BIGNUM *a, const BIGNUM *m)
{
if (!BN_lshift1(r, a))
return 0;
bn_check_top(r);
if (BN_cmp(r, m) >= 0)
return BN_sub(r, r, m);
return 1;
}
int BN_mod_lshift(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m,
BN_CTX *ctx)
{
BIGNUM *abs_m = NULL;
int ret;
if (!BN_nnmod(r, a, m, ctx))
return 0;
if (m->neg) {
abs_m = BN_dup(m);
if (abs_m == NULL)
return 0;
abs_m->neg = 0;
}
ret = BN_mod_lshift_quick(r, r, n, (abs_m ? abs_m : m));
bn_check_top(r);
if (abs_m)
BN_free(abs_m);
return ret;
}
int BN_mod_lshift_quick(BIGNUM *r, const BIGNUM *a, int n, const BIGNUM *m)
{
if (r != a) {
if (BN_copy(r, a) == NULL)
return 0;
}
while (n > 0) {
int max_shift;
max_shift = BN_num_bits(m) - BN_num_bits(r);
if (max_shift < 0) {
BNerr(BN_F_BN_MOD_LSHIFT_QUICK, BN_R_INPUT_NOT_REDUCED);
return 0;
}
if (max_shift > n)
max_shift = n;
if (max_shift) {
if (!BN_lshift(r, r, max_shift))
return 0;
n -= max_shift;
} else {
if (!BN_lshift1(r, r))
return 0;
--n;
}
if (BN_cmp(r, m) >= 0) {
if (!BN_sub(r, r, m))
return 0;
}
}
bn_check_top(r);
return 1;
}
