void DH_set_default_method(const DH_METHOD *meth)
{
default_DH_method = meth;
}
const DH_METHOD *DH_get_default_method(void)
{
if(!default_DH_method)
default_DH_method = DH_OpenSSL();
return default_DH_method;
}
int DH_set_method(DH *dh, const DH_METHOD *meth)
{
const DH_METHOD *mtmp;
mtmp = dh->meth;
if (mtmp->finish) mtmp->finish(dh);
#ifndef OPENSSL_NO_ENGINE
if (dh->engine)
{
ENGINE_finish(dh->engine);
dh->engine = NULL;
}
#endif
dh->meth = meth;
if (meth->init) meth->init(dh);
return 1;
}
DH *DH_new(void)
{
return DH_new_method(NULL);
}
DH *DH_new_method(ENGINE *engine)
{
DH *ret;
ret=(DH *)OPENSSL_malloc(sizeof(DH));
if (ret == NULL)
{
DHerr(DH_F_DH_NEW_METHOD,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->meth = DH_get_default_method();
#ifndef OPENSSL_NO_ENGINE
if (engine)
{
if (!ENGINE_init(engine))
{
DHerr(DH_F_DH_NEW_METHOD, ERR_R_ENGINE_LIB);
OPENSSL_free(ret);
return NULL;
}
ret->engine = engine;
}
else
ret->engine = ENGINE_get_default_DH();
if(ret->engine)
{
ret->meth = ENGINE_get_DH(ret->engine);
if(!ret->meth)
{
DHerr(DH_F_DH_NEW_METHOD,ERR_R_ENGINE_LIB);
ENGINE_finish(ret->engine);
OPENSSL_free(ret);
return NULL;
}
}
#endif
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
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_DH, ret, &ret->ex_data);
if ((ret->meth->init != NULL) && !ret->meth->init(ret))
{
#ifndef OPENSSL_NO_ENGINE
if (ret->engine)
ENGINE_finish(ret->engine);
#endif
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_DH, ret, &ret->ex_data);
OPENSSL_free(ret);
ret=NULL;
}
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
if (r->meth->finish)
r->meth->finish(r);
#ifndef OPENSSL_NO_ENGINE
if (r->engine)
ENGINE_finish(r->engine);
#endif
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_DH, r, &r->ex_data);
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
int DH_up_ref(DH *r)
{
int i = CRYPTO_add(&r->references, 1, CRYPTO_LOCK_DH);
#ifdef REF_PRINT
REF_PRINT("DH",r);
#endif
#ifdef REF_CHECK
if (i < 2)
{
fprintf(stderr, "DH_up, bad reference count\n");
abort();
}
#endif
return ((i > 1) ? 1 : 0);
}
int DH_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_DH, argl, argp,
new_func, dup_func, free_func);
}
int DH_set_ex_data(DH *d, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&d->ex_data,idx,arg));
}
void *DH_get_ex_data(DH *d, int idx)
{
return(CRYPTO_get_ex_data(&d->ex_data,idx));
}
int DH_size(const DH *dh)
{
return(BN_num_bytes(dh->p));
}
