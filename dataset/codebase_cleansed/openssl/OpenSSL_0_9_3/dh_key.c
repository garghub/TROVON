int DH_generate_key(DH *dh)
{
int ok=0;
unsigned int i;
BN_CTX ctx;
BN_MONT_CTX *mont;
BIGNUM *pub_key=NULL,*priv_key=NULL;
BN_CTX_init(&ctx);
if (dh->priv_key == NULL)
{
i=dh->length;
if (i == 0)
{
i=BN_num_bits(dh->p)-1;
}
priv_key=BN_new();
if (priv_key == NULL) goto err;
if (!BN_rand(priv_key,i,0,0)) goto err;
}
else
priv_key=dh->priv_key;
if (dh->pub_key == NULL)
{
pub_key=BN_new();
if (pub_key == NULL) goto err;
}
else
pub_key=dh->pub_key;
if ((dh->method_mont_p == NULL) && (dh->flags & DH_FLAG_CACHE_MONT_P))
{
if ((dh->method_mont_p=(char *)BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set((BN_MONT_CTX *)dh->method_mont_p,
dh->p,&ctx)) goto err;
}
mont=(BN_MONT_CTX *)dh->method_mont_p;
if (!BN_mod_exp_mont(pub_key,dh->g,priv_key,dh->p,&ctx,mont)) goto err;
dh->pub_key=pub_key;
dh->priv_key=priv_key;
ok=1;
err:
if (ok != 1)
DHerr(DH_F_DH_GENERATE_KEY,ERR_R_BN_LIB);
if ((pub_key != NULL) && (dh->pub_key == NULL)) BN_free(pub_key);
if ((priv_key != NULL) && (dh->priv_key == NULL)) BN_free(priv_key);
BN_CTX_free(&ctx);
return(ok);
}
int DH_compute_key(unsigned char *key, BIGNUM *pub_key, DH *dh)
{
BN_CTX ctx;
BN_MONT_CTX *mont;
BIGNUM *tmp;
int ret= -1;
BN_CTX_init(&ctx);
tmp= &(ctx.bn[ctx.tos++]);
if (dh->priv_key == NULL)
{
DHerr(DH_F_DH_COMPUTE_KEY,DH_R_NO_PRIVATE_VALUE);
goto err;
}
if ((dh->method_mont_p == NULL) && (dh->flags & DH_FLAG_CACHE_MONT_P))
{
if ((dh->method_mont_p=(char *)BN_MONT_CTX_new()) != NULL)
if (!BN_MONT_CTX_set((BN_MONT_CTX *)dh->method_mont_p,
dh->p,&ctx)) goto err;
}
mont=(BN_MONT_CTX *)dh->method_mont_p;
if (!BN_mod_exp_mont(tmp,pub_key,dh->priv_key,dh->p,&ctx,mont))
{
DHerr(DH_F_DH_COMPUTE_KEY,ERR_R_BN_LIB);
goto err;
}
ret=BN_bn2bin(tmp,key);
err:
BN_CTX_free(&ctx);
return(ret);
}
