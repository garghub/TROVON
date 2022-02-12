DSA *DSA_new(void)
{
DSA *ret;
ret=(DSA *)Malloc(sizeof(DSA));
if (ret == NULL)
{
DSAerr(DSA_F_DSA_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->pad=0;
ret->version=0;
ret->write_params=1;
ret->p=NULL;
ret->q=NULL;
ret->g=NULL;
ret->flags=DSA_FLAG_CACHE_MONT_P;
ret->pub_key=NULL;
ret->priv_key=NULL;
ret->kinv=NULL;
ret->r=NULL;
ret->method_mont_p=NULL;
ret->references=1;
return(ret);
}
void DSA_free(DSA *r)
{
int i;
if (r == NULL) return;
i=CRYPTO_add(&r->references,-1,CRYPTO_LOCK_DSA);
#ifdef REF_PRINT
REF_PRINT("DSA",r);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"DSA_free, bad reference count\n");
abort();
}
#endif
if (r->p != NULL) BN_clear_free(r->p);
if (r->q != NULL) BN_clear_free(r->q);
if (r->g != NULL) BN_clear_free(r->g);
if (r->pub_key != NULL) BN_clear_free(r->pub_key);
if (r->priv_key != NULL) BN_clear_free(r->priv_key);
if (r->kinv != NULL) BN_clear_free(r->kinv);
if (r->r != NULL) BN_clear_free(r->r);
if (r->method_mont_p != NULL)
BN_MONT_CTX_free((BN_MONT_CTX *)r->method_mont_p);
Free(r);
}
int DSA_size(DSA *r)
{
int ret,i;
ASN1_INTEGER bs;
unsigned char buf[4];
i=BN_num_bits(r->q);
bs.length=(i+7)/8;
bs.data=buf;
bs.type=V_ASN1_INTEGER;
buf[0]=0xff;
i=i2d_ASN1_INTEGER(&bs,NULL);
i+=i;
ret=ASN1_object_size(1,i,V_ASN1_SEQUENCE);
return(ret);
}
