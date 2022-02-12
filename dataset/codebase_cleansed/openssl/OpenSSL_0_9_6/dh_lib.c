void DH_set_default_method(DH_METHOD *meth)
{
default_DH_method = meth;
}
DH_METHOD *DH_get_default_method(void)
{
if(!default_DH_method) default_DH_method = DH_OpenSSL();
return default_DH_method;
}
DH_METHOD *DH_set_method(DH *dh, DH_METHOD *meth)
{
DH_METHOD *mtmp;
mtmp = dh->meth;
if (mtmp->finish) mtmp->finish(dh);
dh->meth = meth;
if (meth->init) meth->init(dh);
return mtmp;
}
DH *DH_new(void)
{
return DH_new_method(NULL);
}
DH *DH_new_method(DH_METHOD *meth)
{
DH *ret;
ret=(DH *)OPENSSL_malloc(sizeof(DH));
if (ret == NULL)
{
DHerr(DH_F_DH_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
if(meth) ret->meth = meth;
else ret->meth = DH_get_default_method();
ret->pad=0;
ret->version=0;
ret->p=NULL;
ret->g=NULL;
ret->length=0;
ret->pub_key=NULL;
ret->priv_key=NULL;
ret->q=NULL;
ret->j=NULL;
ret->seed = NULL;
ret->seedlen = 0;
ret->counter = NULL;
ret->method_mont_p=NULL;
ret->references = 1;
ret->flags=ret->meth->flags;
if ((ret->meth->init != NULL) && !ret->meth->init(ret))
{
OPENSSL_free(ret);
ret=NULL;
}
else
CRYPTO_new_ex_data(dh_meth,ret,&ret->ex_data);
return(ret);
}
void DH_free(DH *r)
{
int i;
if(r == NULL) return;
i = CRYPTO_add(&r->references, -1, CRYPTO_LOCK_DH);
#ifdef REF_PRINT
REF_PRINT("DH",r);
#endif
if (i > 0) return;
#ifdef REF_CHECK
if (i < 0)
{
fprintf(stderr,"DH_free, bad reference count\n");
abort();
}
#endif
CRYPTO_free_ex_data(dh_meth, r, &r->ex_data);
if(r->meth->finish) r->meth->finish(r);
if (r->p != NULL) BN_clear_free(r->p);
if (r->g != NULL) BN_clear_free(r->g);
if (r->q != NULL) BN_clear_free(r->q);
if (r->j != NULL) BN_clear_free(r->j);
if (r->seed) OPENSSL_free(r->seed);
if (r->counter != NULL) BN_clear_free(r->counter);
if (r->pub_key != NULL) BN_clear_free(r->pub_key);
if (r->priv_key != NULL) BN_clear_free(r->priv_key);
OPENSSL_free(r);
}
int DH_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
dh_meth_num++;
return(CRYPTO_get_ex_new_index(dh_meth_num-1,
&dh_meth,argl,argp,new_func,dup_func,free_func));
}
int DH_set_ex_data(DH *d, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&d->ex_data,idx,arg));
}
void *DH_get_ex_data(DH *d, int idx)
{
return(CRYPTO_get_ex_data(&d->ex_data,idx));
}
int DH_size(DH *dh)
{
return(BN_num_bytes(dh->p));
}
