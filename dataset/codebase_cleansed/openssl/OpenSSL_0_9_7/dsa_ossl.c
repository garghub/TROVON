const DSA_METHOD *DSA_OpenSSL(void)
{
return &openssl_dsa_meth;
}
static DSA_SIG *dsa_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
BIGNUM *kinv=NULL,*r=NULL,*s=NULL;
BIGNUM m;
BIGNUM xr;
BN_CTX *ctx=NULL;
int i,reason=ERR_R_BN_LIB;
DSA_SIG *ret=NULL;
if (!dsa->p || !dsa->q || !dsa->g)
{
reason=DSA_R_MISSING_PARAMETERS;
goto err;
}
BN_init(&m);
BN_init(&xr);
s=BN_new();
if (s == NULL) goto err;
i=BN_num_bytes(dsa->q);
if ((dlen > i) || (dlen > 50))
{
reason=DSA_R_DATA_TOO_LARGE_FOR_KEY_SIZE;
goto err;
}
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
if ((dsa->kinv == NULL) || (dsa->r == NULL))
{
if (!DSA_sign_setup(dsa,ctx,&kinv,&r)) goto err;
}
else
{
kinv=dsa->kinv;
dsa->kinv=NULL;
r=dsa->r;
dsa->r=NULL;
}
if (BN_bin2bn(dgst,dlen,&m) == NULL) goto err;
if (!BN_mod_mul(&xr,dsa->priv_key,r,dsa->q,ctx)) goto err;
if (!BN_add(s, &xr, &m)) goto err;
if (BN_cmp(s,dsa->q) > 0)
BN_sub(s,s,dsa->q);
if (!BN_mod_mul(s,s,kinv,dsa->q,ctx)) goto err;
ret=DSA_SIG_new();
if (ret == NULL) goto err;
ret->r = r;
ret->s = s;
err:
if (!ret)
{
DSAerr(DSA_F_DSA_DO_SIGN,reason);
BN_free(r);
BN_free(s);
}
if (ctx != NULL) BN_CTX_free(ctx);
BN_clear_free(&m);
BN_clear_free(&xr);
if (kinv != NULL)
BN_clear_free(kinv);
return(ret);
}
static int dsa_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp)
{
BN_CTX *ctx;
BIGNUM k,*kinv=NULL,*r=NULL;
int ret=0;
if (!dsa->p || !dsa->q || !dsa->g)
{
DSAerr(DSA_F_DSA_SIGN_SETUP,DSA_R_MISSING_PARAMETERS);
return 0;
}
if (ctx_in == NULL)
{
if ((ctx=BN_CTX_new()) == NULL) goto err;
}
else
ctx=ctx_in;
BN_init(&k);
if ((r=BN_new()) == NULL) goto err;
kinv=NULL;
do
if (!BN_rand_range(&k, dsa->q)) goto err;
while (BN_is_zero(&k));
if ((dsa->method_mont_p == NULL) && (dsa->flags & DSA_FLAG_CACHE_MONT_P))
{
if ((dsa->method_mont_p=(char *)BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set((BN_MONT_CTX *)dsa->method_mont_p,
dsa->p,ctx)) goto err;
}
if (!dsa->meth->bn_mod_exp(dsa, r,dsa->g,&k,dsa->p,ctx,
(BN_MONT_CTX *)dsa->method_mont_p)) goto err;
if (!BN_mod(r,r,dsa->q,ctx)) goto err;
if ((kinv=BN_mod_inverse(NULL,&k,dsa->q,ctx)) == NULL) goto err;
if (*kinvp != NULL) BN_clear_free(*kinvp);
*kinvp=kinv;
kinv=NULL;
if (*rp != NULL) BN_clear_free(*rp);
*rp=r;
ret=1;
err:
if (!ret)
{
DSAerr(DSA_F_DSA_SIGN_SETUP,ERR_R_BN_LIB);
if (kinv != NULL) BN_clear_free(kinv);
if (r != NULL) BN_clear_free(r);
}
if (ctx_in == NULL) BN_CTX_free(ctx);
if (kinv != NULL) BN_clear_free(kinv);
BN_clear_free(&k);
return(ret);
}
static int dsa_do_verify(const unsigned char *dgst, int dgst_len, DSA_SIG *sig,
DSA *dsa)
{
BN_CTX *ctx;
BIGNUM u1,u2,t1;
BN_MONT_CTX *mont=NULL;
int ret = -1;
if (!dsa->p || !dsa->q || !dsa->g)
{
DSAerr(DSA_F_DSA_DO_VERIFY,DSA_R_MISSING_PARAMETERS);
return -1;
}
if ((ctx=BN_CTX_new()) == NULL) goto err;
BN_init(&u1);
BN_init(&u2);
BN_init(&t1);
if (BN_is_zero(sig->r) || sig->r->neg || BN_ucmp(sig->r, dsa->q) >= 0)
{
ret = 0;
goto err;
}
if (BN_is_zero(sig->s) || sig->s->neg || BN_ucmp(sig->s, dsa->q) >= 0)
{
ret = 0;
goto err;
}
if ((BN_mod_inverse(&u2,sig->s,dsa->q,ctx)) == NULL) goto err;
if (BN_bin2bn(dgst,dgst_len,&u1) == NULL) goto err;
if (!BN_mod_mul(&u1,&u1,&u2,dsa->q,ctx)) goto err;
if (!BN_mod_mul(&u2,sig->r,&u2,dsa->q,ctx)) goto err;
if ((dsa->method_mont_p == NULL) && (dsa->flags & DSA_FLAG_CACHE_MONT_P))
{
if ((dsa->method_mont_p=(char *)BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set((BN_MONT_CTX *)dsa->method_mont_p,
dsa->p,ctx)) goto err;
}
mont=(BN_MONT_CTX *)dsa->method_mont_p;
#if 0
{
BIGNUM t2;
BN_init(&t2);
if (!BN_mod_exp_mont(&t1,dsa->g,&u1,dsa->p,ctx,mont)) goto err;
if (!BN_mod_exp_mont(&t2,dsa->pub_key,&u2,dsa->p,ctx,mont)) goto err;
if (!BN_mod_mul(&u1,&t1,&t2,dsa->p,ctx)) goto err_bn;
BN_free(&t2);
}
if (!BN_mod(&u1,&u1,dsa->q,ctx)) goto err;
#else
{
if (!dsa->meth->dsa_mod_exp(dsa, &t1,dsa->g,&u1,dsa->pub_key,&u2,
dsa->p,ctx,mont)) goto err;
if (!BN_mod(&u1,&t1,dsa->q,ctx)) goto err;
}
#endif
ret=(BN_ucmp(&u1, sig->r) == 0);
err:
if (ret != 1) DSAerr(DSA_F_DSA_DO_VERIFY,ERR_R_BN_LIB);
if (ctx != NULL) BN_CTX_free(ctx);
BN_free(&u1);
BN_free(&u2);
BN_free(&t1);
return(ret);
}
static int dsa_init(DSA *dsa)
{
dsa->flags|=DSA_FLAG_CACHE_MONT_P;
return(1);
}
static int dsa_finish(DSA *dsa)
{
if(dsa->method_mont_p)
BN_MONT_CTX_free((BN_MONT_CTX *)dsa->method_mont_p);
return(1);
}
static int dsa_mod_exp(DSA *dsa, BIGNUM *rr, BIGNUM *a1, BIGNUM *p1,
BIGNUM *a2, BIGNUM *p2, BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *in_mont)
{
return BN_mod_exp2_mont(rr, a1, p1, a2, p2, m, ctx, in_mont);
}
static int dsa_bn_mod_exp(DSA *dsa, BIGNUM *r, BIGNUM *a, const BIGNUM *p,
const BIGNUM *m, BN_CTX *ctx,
BN_MONT_CTX *m_ctx)
{
return BN_mod_exp_mont(r, a, p, m, ctx, m_ctx);
}
