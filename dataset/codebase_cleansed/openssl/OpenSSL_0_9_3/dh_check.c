int DH_check(DH *dh, int *ret)
{
int ok=0;
BN_CTX *ctx=NULL;
BN_ULONG l;
BIGNUM *q=NULL;
*ret=0;
ctx=BN_CTX_new();
if (ctx == NULL) goto err;
q=BN_new();
if (q == NULL) goto err;
if (BN_is_word(dh->g,DH_GENERATOR_2))
{
l=BN_mod_word(dh->p,24);
if (l != 11) *ret|=DH_NOT_SUITABLE_GENERATOR;
}
else if (BN_is_word(dh->g,DH_GENERATOR_5))
{
l=BN_mod_word(dh->p,10);
if ((l != 3) && (l != 7))
*ret|=DH_NOT_SUITABLE_GENERATOR;
}
else
*ret|=DH_UNABLE_TO_CHECK_GENERATOR;
if (!BN_is_prime(dh->p,BN_prime_checks,NULL,ctx,NULL))
*ret|=DH_CHECK_P_NOT_PRIME;
else
{
if (!BN_rshift1(q,dh->p)) goto err;
if (!BN_is_prime(q,BN_prime_checks,NULL,ctx,NULL))
*ret|=DH_CHECK_P_NOT_STRONG_PRIME;
}
ok=1;
err:
if (ctx != NULL) BN_CTX_free(ctx);
if (q != NULL) BN_free(q);
return(ok);
}
