int DSA_do_verify(const unsigned char *dgst, int dgst_len, DSA_SIG *sig,
DSA *dsa)
{
BN_CTX *ctx;
BIGNUM u1,u2,t1;
BN_MONT_CTX *mont=NULL;
int ret = -1;
if ((ctx=BN_CTX_new()) == NULL) goto err;
BN_init(&u1);
BN_init(&u2);
BN_init(&t1);
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
if (!BN_mod_exp2_mont(&t1,dsa->g,&u1,dsa->pub_key,&u2,dsa->p,ctx,mont))
goto err;
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
int DSA_verify(int type, const unsigned char *dgst, int dgst_len,
unsigned char *sigbuf, int siglen, DSA *dsa)
{
DSA_SIG *s;
int ret=-1;
s = DSA_SIG_new();
if (s == NULL) return(ret);
if (d2i_DSA_SIG(&s,&sigbuf,siglen) == NULL) goto err;
ret=DSA_do_verify(dgst,dgst_len,s,dsa);
err:
DSA_SIG_free(s);
return(ret);
}
