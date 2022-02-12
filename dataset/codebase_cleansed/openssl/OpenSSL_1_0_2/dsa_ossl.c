const DSA_METHOD *DSA_OpenSSL(void)
{
return &openssl_dsa_meth;
}
static DSA_SIG *dsa_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
BIGNUM *kinv = NULL, *r = NULL, *s = NULL;
BIGNUM m;
BIGNUM xr;
BN_CTX *ctx = NULL;
int reason = ERR_R_BN_LIB;
DSA_SIG *ret = NULL;
int noredo = 0;
BN_init(&m);
BN_init(&xr);
if (!dsa->p || !dsa->q || !dsa->g) {
reason = DSA_R_MISSING_PARAMETERS;
goto err;
}
s = BN_new();
if (s == NULL)
goto err;
ctx = BN_CTX_new();
if (ctx == NULL)
goto err;
redo:
if ((dsa->kinv == NULL) || (dsa->r == NULL)) {
if (!DSA_sign_setup(dsa, ctx, &kinv, &r))
goto err;
} else {
kinv = dsa->kinv;
dsa->kinv = NULL;
r = dsa->r;
dsa->r = NULL;
noredo = 1;
}
if (dlen > BN_num_bytes(dsa->q))
dlen = BN_num_bytes(dsa->q);
if (BN_bin2bn(dgst, dlen, &m) == NULL)
goto err;
if (!BN_mod_mul(&xr, dsa->priv_key, r, dsa->q, ctx))
goto err;
if (!BN_add(s, &xr, &m))
goto err;
if (BN_cmp(s, dsa->q) > 0)
if (!BN_sub(s, s, dsa->q))
goto err;
if (!BN_mod_mul(s, s, kinv, dsa->q, ctx))
goto err;
ret = DSA_SIG_new();
if (ret == NULL)
goto err;
if (BN_is_zero(r) || BN_is_zero(s)) {
if (noredo) {
reason = DSA_R_NEED_NEW_SETUP_VALUES;
goto err;
}
goto redo;
}
ret->r = r;
ret->s = s;
err:
if (!ret) {
DSAerr(DSA_F_DSA_DO_SIGN, reason);
BN_free(r);
BN_free(s);
}
if (ctx != NULL)
BN_CTX_free(ctx);
BN_clear_free(&m);
BN_clear_free(&xr);
if (kinv != NULL)
BN_clear_free(kinv);
return (ret);
}
static int dsa_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp,
BIGNUM **rp)
{
BN_CTX *ctx;
BIGNUM k, kq, *K, *kinv = NULL, *r = NULL;
int ret = 0;
if (!dsa->p || !dsa->q || !dsa->g) {
DSAerr(DSA_F_DSA_SIGN_SETUP, DSA_R_MISSING_PARAMETERS);
return 0;
}
BN_init(&k);
BN_init(&kq);
if (ctx_in == NULL) {
if ((ctx = BN_CTX_new()) == NULL)
goto err;
} else
ctx = ctx_in;
if ((r = BN_new()) == NULL)
goto err;
do
if (!BN_rand_range(&k, dsa->q))
goto err;
while (BN_is_zero(&k)) ;
if ((dsa->flags & DSA_FLAG_NO_EXP_CONSTTIME) == 0) {
BN_set_flags(&k, BN_FLG_CONSTTIME);
}
if (dsa->flags & DSA_FLAG_CACHE_MONT_P) {
if (!BN_MONT_CTX_set_locked(&dsa->method_mont_p,
CRYPTO_LOCK_DSA, dsa->p, ctx))
goto err;
}
if ((dsa->flags & DSA_FLAG_NO_EXP_CONSTTIME) == 0) {
if (!BN_copy(&kq, &k))
goto err;
if (!BN_add(&kq, &kq, dsa->q))
goto err;
if (BN_num_bits(&kq) <= BN_num_bits(dsa->q)) {
if (!BN_add(&kq, &kq, dsa->q))
goto err;
}
K = &kq;
} else {
K = &k;
}
DSA_BN_MOD_EXP(goto err, dsa, r, dsa->g, K, dsa->p, ctx,
dsa->method_mont_p);
if (!BN_mod(r, r, dsa->q, ctx))
goto err;
if ((kinv = BN_mod_inverse(NULL, &k, dsa->q, ctx)) == NULL)
goto err;
if (*kinvp != NULL)
BN_clear_free(*kinvp);
*kinvp = kinv;
kinv = NULL;
if (*rp != NULL)
BN_clear_free(*rp);
*rp = r;
ret = 1;
err:
if (!ret) {
DSAerr(DSA_F_DSA_SIGN_SETUP, ERR_R_BN_LIB);
if (r != NULL)
BN_clear_free(r);
}
if (ctx_in == NULL)
BN_CTX_free(ctx);
BN_clear_free(&k);
BN_clear_free(&kq);
return (ret);
}
static int dsa_do_verify(const unsigned char *dgst, int dgst_len,
DSA_SIG *sig, DSA *dsa)
{
BN_CTX *ctx;
BIGNUM u1, u2, t1;
BN_MONT_CTX *mont = NULL;
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
BN_init(&u1);
BN_init(&u2);
BN_init(&t1);
if ((ctx = BN_CTX_new()) == NULL)
goto err;
if (BN_is_zero(sig->r) || BN_is_negative(sig->r) ||
BN_ucmp(sig->r, dsa->q) >= 0) {
ret = 0;
goto err;
}
if (BN_is_zero(sig->s) || BN_is_negative(sig->s) ||
BN_ucmp(sig->s, dsa->q) >= 0) {
ret = 0;
goto err;
}
if ((BN_mod_inverse(&u2, sig->s, dsa->q, ctx)) == NULL)
goto err;
if (dgst_len > (i >> 3))
dgst_len = (i >> 3);
if (BN_bin2bn(dgst, dgst_len, &u1) == NULL)
goto err;
if (!BN_mod_mul(&u1, &u1, &u2, dsa->q, ctx))
goto err;
if (!BN_mod_mul(&u2, sig->r, &u2, dsa->q, ctx))
goto err;
if (dsa->flags & DSA_FLAG_CACHE_MONT_P) {
mont = BN_MONT_CTX_set_locked(&dsa->method_mont_p,
CRYPTO_LOCK_DSA, dsa->p, ctx);
if (!mont)
goto err;
}
DSA_MOD_EXP(goto err, dsa, &t1, dsa->g, &u1, dsa->pub_key, &u2, dsa->p,
ctx, mont);
if (!BN_mod(&u1, &t1, dsa->q, ctx))
goto err;
ret = (BN_ucmp(&u1, sig->r) == 0);
err:
if (ret < 0)
DSAerr(DSA_F_DSA_DO_VERIFY, ERR_R_BN_LIB);
if (ctx != NULL)
BN_CTX_free(ctx);
BN_free(&u1);
BN_free(&u2);
BN_free(&t1);
return (ret);
}
static int dsa_init(DSA *dsa)
{
dsa->flags |= DSA_FLAG_CACHE_MONT_P;
return (1);
}
static int dsa_finish(DSA *dsa)
{
if (dsa->method_mont_p)
BN_MONT_CTX_free(dsa->method_mont_p);
return (1);
}
