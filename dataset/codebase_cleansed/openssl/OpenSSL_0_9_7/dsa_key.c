int DSA_generate_key(DSA *dsa)
{
int ok=0;
BN_CTX *ctx=NULL;
BIGNUM *pub_key=NULL,*priv_key=NULL;
if ((ctx=BN_CTX_new()) == NULL) goto err;
if (dsa->priv_key == NULL)
{
if ((priv_key=BN_new()) == NULL) goto err;
}
else
priv_key=dsa->priv_key;
do
if (!BN_rand_range(priv_key,dsa->q)) goto err;
while (BN_is_zero(priv_key));
if (dsa->pub_key == NULL)
{
if ((pub_key=BN_new()) == NULL) goto err;
}
else
pub_key=dsa->pub_key;
if (!BN_mod_exp(pub_key,dsa->g,priv_key,dsa->p,ctx)) goto err;
dsa->priv_key=priv_key;
dsa->pub_key=pub_key;
ok=1;
err:
if ((pub_key != NULL) && (dsa->pub_key == NULL)) BN_free(pub_key);
if ((priv_key != NULL) && (dsa->priv_key == NULL)) BN_free(priv_key);
if (ctx != NULL) BN_CTX_free(ctx);
return(ok);
}
