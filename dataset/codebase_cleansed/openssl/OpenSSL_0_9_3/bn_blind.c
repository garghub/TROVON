BN_BLINDING *BN_BLINDING_new(BIGNUM *A, BIGNUM *Ai, BIGNUM *mod)
{
BN_BLINDING *ret=NULL;
bn_check_top(Ai);
bn_check_top(mod);
if ((ret=(BN_BLINDING *)Malloc(sizeof(BN_BLINDING))) == NULL)
{
BNerr(BN_F_BN_BLINDING_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
memset(ret,0,sizeof(BN_BLINDING));
if ((ret->A=BN_new()) == NULL) goto err;
if ((ret->Ai=BN_new()) == NULL) goto err;
if (!BN_copy(ret->A,A)) goto err;
if (!BN_copy(ret->Ai,Ai)) goto err;
ret->mod=mod;
return(ret);
err:
if (ret != NULL) BN_BLINDING_free(ret);
return(NULL);
}
void BN_BLINDING_free(BN_BLINDING *r)
{
if(r == NULL)
return;
if (r->A != NULL) BN_free(r->A );
if (r->Ai != NULL) BN_free(r->Ai);
Free(r);
}
int BN_BLINDING_update(BN_BLINDING *b, BN_CTX *ctx)
{
int ret=0;
if ((b->A == NULL) || (b->Ai == NULL))
{
BNerr(BN_F_BN_BLINDING_UPDATE,BN_R_NOT_INITIALIZED);
goto err;
}
if (!BN_mod_mul(b->A,b->A,b->A,b->mod,ctx)) goto err;
if (!BN_mod_mul(b->Ai,b->Ai,b->Ai,b->mod,ctx)) goto err;
ret=1;
err:
return(ret);
}
int BN_BLINDING_convert(BIGNUM *n, BN_BLINDING *b, BN_CTX *ctx)
{
bn_check_top(n);
if ((b->A == NULL) || (b->Ai == NULL))
{
BNerr(BN_F_BN_BLINDING_CONVERT,BN_R_NOT_INITIALIZED);
return(0);
}
return(BN_mod_mul(n,n,b->A,b->mod,ctx));
}
int BN_BLINDING_invert(BIGNUM *n, BN_BLINDING *b, BN_CTX *ctx)
{
int ret;
bn_check_top(n);
if ((b->A == NULL) || (b->Ai == NULL))
{
BNerr(BN_F_BN_BLINDING_INVERT,BN_R_NOT_INITIALIZED);
return(0);
}
if ((ret=BN_mod_mul(n,n,b->Ai,b->mod,ctx)) >= 0)
{
if (!BN_BLINDING_update(b,ctx))
return(0);
}
return(ret);
}
