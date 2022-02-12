DH *DH_new(void)
{
DH *ret;
ret=(DH *)Malloc(sizeof(DH));
if (ret == NULL)
{
DHerr(DH_F_DH_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->pad=0;
ret->version=0;
ret->p=NULL;
ret->g=NULL;
ret->length=0;
ret->pub_key=NULL;
ret->priv_key=NULL;
ret->flags=DH_FLAG_CACHE_MONT_P;
ret->method_mont_p=NULL;
return(ret);
}
void DH_free(DH *r)
{
if(r == NULL) return;
if (r->p != NULL) BN_clear_free(r->p);
if (r->g != NULL) BN_clear_free(r->g);
if (r->pub_key != NULL) BN_clear_free(r->pub_key);
if (r->priv_key != NULL) BN_clear_free(r->priv_key);
if (r->method_mont_p != NULL)
BN_MONT_CTX_free((BN_MONT_CTX *)r->method_mont_p);
Free(r);
}
int DH_size(DH *dh)
{
return(BN_num_bytes(dh->p));
}
