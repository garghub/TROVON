const DSA_METHOD *DSA_OpenSSL(void)
{
return &openssl_dsa_meth;
}
static DSA_SIG *dsa_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
BIGNUM *kinv = NULL;
BIGNUM *m;
BIGNUM *xr;
BN_CTX *ctx = NULL;
int reason = ERR_R_BN_LIB;
DSA_SIG *ret = NULL;
int rv = 0;
m = BN_new();
xr = BN_new();
if (m == NULL || xr == NULL)
goto err;
if (!dsa->p || !dsa->q || !dsa->g) {
reason = DSA_R_MISSING_PARAMETERS;
goto err;
}
ret = DSA_SIG_new();
if (ret == NULL)
goto err;
ret->r = BN_new();
ret->s = BN_new();
if (ret->r == NULL || ret->s == NULL)
goto err;
ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
redo:
if (!dsa_sign_setup(dsa, ctx, &kinv, &ret->r, dgst, dlen))
goto err;
if (dlen > BN_num_bytes(dsa->q))
dlen = BN_num_bytes(dsa->q);
if (BN_bin2bn(dgst, dlen, m) == NULL)
goto err;
if (!BN_mod_mul(xr, dsa->priv_key, ret->r, dsa->q, ctx))
goto err;
if (!BN_add(ret->s, xr, m))
goto err;
if (BN_cmp(ret->s, dsa->q) > 0)
if (!BN_sub(ret->s, ret->s, dsa->q))
goto err;
if (!BN_mod_mul(ret->s, ret->s, kinv, dsa->q, ctx))
goto err;
if (BN_is_zero(ret->r) || BN_is_zero(ret->s))
goto redo;
rv = 1;
err:
if (rv == 0) {
DSAerr(DSA_F_DSA_DO_SIGN, reason);
DSA_SIG_free(ret);
ret = NULL;
}
BN_CTX_free(ctx);
BN_clear_free(m);
BN_clear_free(xr);
BN_clear_free(kinv);
return ret;
}
static int dsa_sign_setup_no_digest(DSA *dsa, BN_CTX *ctx_in,
BIGNUM **kinvp, BIGNUM **rp)
{
return dsa_sign_setup(dsa, ctx_in, kinvp, rp, NULL, 0);
}
static int dsa_sign_setup(DSA *dsa, BN_CTX *ctx_in,
BIGNUM **kinvp, BIGNUM **rp,
const unsigned char *dgst, int dlen)
{
BN_CTX *ctx = NULL;
BIGNUM *k, *kinv = NULL, *r = *rp;
int ret = 0;
if (!dsa->p || !dsa->q || !dsa->g) {
DSAerr(DSA_F_DSA_SIGN_SETUP, DSA_R_MISSING_PARAMETERS);
return 0;
}
k = BN_new();
if (k == NULL)
goto err;
if (ctx_in == NULL) {
if ((ctx = BN_CTX_new()) == NULL)
goto err;
} else
ctx = ctx_in;
do {
if (dgst != NULL) {
if (!BN_generate_dsa_nonce(k, dsa->q, dsa->priv_key, dgst,
dlen, ctx))
goto err;
} else if (!BN_rand_range(k, dsa->q))
goto err;
} while (BN_is_zero(k));
BN_set_flags(k, BN_FLG_CONSTTIME);
if (dsa->flags & DSA_FLAG_CACHE_MONT_P) {
if (!BN_MONT_CTX_set_locked(&dsa->method_mont_p,
dsa->lock, dsa->p, ctx))
goto err;
}
if (!BN_add(k, k, dsa->q))
goto err;
if (BN_num_bits(k) <= BN_num_bits(dsa->q)) {
if (!BN_add(k, k, dsa->q))
goto err;
}
if ((dsa)->meth->bn_mod_exp != NULL) {
if (!dsa->meth->bn_mod_exp(dsa, r, dsa->g, k, dsa->p, ctx,
dsa->method_mont_p))
goto err;
} else {
if (!BN_mod_exp_mont(r, dsa->g, k, dsa->p, ctx, dsa->method_mont_p))
goto err;
}
if (!BN_mod(r, r, dsa->q, ctx))
goto err;
if ((kinv = BN_mod_inverse(NULL, k, dsa->q, ctx)) == NULL)
goto err;
BN_clear_free(*kinvp);
*kinvp = kinv;
kinv = NULL;
ret = 1;
err:
if (!ret)
DSAerr(DSA_F_DSA_SIGN_SETUP, ERR_R_BN_LIB);
if (ctx != ctx_in)
BN_CTX_free(ctx);
BN_clear_free(k);
return ret;
}
static int dsa_do_verify(const unsigned char *dgst, int dgst_len,
DSA_SIG *sig, DSA *dsa)
{
BN_CTX *ctx;
BIGNUM *u1, *u2, *t1;
BN_MONT_CTX *mont = NULL;
const BIGNUM *r, *s;
int ret = -1, i;
if (!dsa->p || !dsa->q || !dsa->g) {
DSAerr(DSA_F_DSA_DO_VERIFY, DSA_R_MISSING_PARAMETERS);
return -1;
}
i = BN_num_bits(dsa->q);
if (i != 160 && i != 224 && i != 256) {
DSAerr(DSA_F_DSA_DO_VERIFY, DSA_R_BAD_Q_VALUE);
return -1;
}
if (BN_num_bits(dsa->p) > OPENSSL_DSA_MAX_MODULUS_BITS) {
DSAerr(DSA_F_DSA_DO_VERIFY, DSA_R_MODULUS_TOO_LARGE);
return -1;
}
u1 = BN_new();
u2 = BN_new();
t1 = BN_new();
ctx = BN_CTX_new();
if (u1 == NULL || u2 == NULL || t1 == NULL || ctx == NULL)
goto err;
DSA_SIG_get0(sig, &r, &s);
if (BN_is_zero(r) || BN_is_negative(r) ||
BN_ucmp(r, dsa->q) >= 0) {
ret = 0;
goto err;
}
if (BN_is_zero(s) || BN_is_negative(s) ||
BN_ucmp(s, dsa->q) >= 0) {
ret = 0;
goto err;
}
if ((BN_mod_inverse(u2, s, dsa->q, ctx)) == NULL)
goto err;
if (dgst_len > (i >> 3))
dgst_len = (i >> 3);
if (BN_bin2bn(dgst, dgst_len, u1) == NULL)
goto err;
if (!BN_mod_mul(u1, u1, u2, dsa->q, ctx))
goto err;
if (!BN_mod_mul(u2, r, u2, dsa->q, ctx))
goto err;
if (dsa->flags & DSA_FLAG_CACHE_MONT_P) {
mont = BN_MONT_CTX_set_locked(&dsa->method_mont_p,
dsa->lock, dsa->p, ctx);
if (!mont)
goto err;
}
if (dsa->meth->dsa_mod_exp != NULL) {
if (!dsa->meth->dsa_mod_exp(dsa, t1, dsa->g, u1, dsa->pub_key, u2,
dsa->p, ctx, mont))
goto err;
} else {
if (!BN_mod_exp2_mont(t1, dsa->g, u1, dsa->pub_key, u2, dsa->p, ctx,
mont))
goto err;
}
if (!BN_mod(u1, t1, dsa->q, ctx))
goto err;
ret = (BN_ucmp(u1, r) == 0);
err:
if (ret < 0)
DSAerr(DSA_F_DSA_DO_VERIFY, ERR_R_BN_LIB);
BN_CTX_free(ctx);
BN_free(u1);
BN_free(u2);
BN_free(t1);
return (ret);
}
static int dsa_init(DSA *dsa)
{
dsa->flags |= DSA_FLAG_CACHE_MONT_P;
return (1);
}
static int dsa_finish(DSA *dsa)
{
BN_MONT_CTX_free(dsa->method_mont_p);
return (1);
}
