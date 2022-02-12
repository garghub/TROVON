DSA_SIG * DSA_do_sign(const unsigned char *dgst, int dlen, DSA *dsa)
{
BIGNUM *kinv=NULL,*r=NULL,*s=NULL;
BIGNUM m;
BIGNUM xr;
BN_CTX *ctx=NULL;
int i,reason=ERR_R_BN_LIB;
DSA_SIG *ret=NULL;
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
int DSA_sign(int type, const unsigned char *dgst, int dlen, unsigned char *sig,
unsigned int *siglen, DSA *dsa)
{
DSA_SIG *s;
s=DSA_do_sign(dgst,dlen,dsa);
if (s == NULL)
{
*siglen=0;
return(0);
}
*siglen=i2d_DSA_SIG(s,&sig);
DSA_SIG_free(s);
return(1);
}
int DSA_sign_setup(DSA *dsa, BN_CTX *ctx_in, BIGNUM **kinvp, BIGNUM **rp)
{
BN_CTX *ctx;
BIGNUM k,*kinv=NULL,*r=NULL;
int ret=0;
if (ctx_in == NULL)
{
if ((ctx=BN_CTX_new()) == NULL) goto err;
}
else
ctx=ctx_in;
BN_init(&k);
if ((r=BN_new()) == NULL) goto err;
kinv=NULL;
for (;;)
{
if (!BN_rand(&k, BN_num_bits(dsa->q), 1, 0)) goto err;
if (BN_cmp(&k,dsa->q) >= 0)
BN_sub(&k,&k,dsa->q);
if (!BN_is_zero(&k)) break;
}
if ((dsa->method_mont_p == NULL) && (dsa->flags & DSA_FLAG_CACHE_MONT_P))
{
if ((dsa->method_mont_p=(char *)BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set((BN_MONT_CTX *)dsa->method_mont_p,
dsa->p,ctx)) goto err;
}
if (!BN_mod_exp_mont(r,dsa->g,&k,dsa->p,ctx,
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
