void DSA_set_default_method(const DSA_METHOD *meth)
{
default_DSA_method = meth;
}
const DSA_METHOD *DSA_get_default_method(void)
{
if(!default_DSA_method)
default_DSA_method = DSA_OpenSSL();
return default_DSA_method;
}
DSA *DSA_new(void)
{
return DSA_new_method(NULL);
}
int DSA_set_method(DSA *dsa, const DSA_METHOD *meth)
{
const DSA_METHOD *mtmp;
mtmp = dsa->meth;
if (mtmp->finish) mtmp->finish(dsa);
if (dsa->engine)
{
ENGINE_finish(dsa->engine);
dsa->engine = NULL;
}
dsa->meth = meth;
if (meth->init) meth->init(dsa);
return 1;
}
DSA *DSA_new_method(ENGINE *engine)
{
DSA *ret;
ret=(DSA *)OPENSSL_malloc(sizeof(DSA));
if (ret == NULL)
{
DSAerr(DSA_F_DSA_NEW_METHOD,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->meth = DSA_get_default_method();
if (engine)
{
if (!ENGINE_init(engine))
{
DSAerr(DSA_F_DSA_NEW_METHOD, ERR_R_ENGINE_LIB);
OPENSSL_free(ret);
return NULL;
}
ret->engine = engine;
}
else
ret->engine = ENGINE_get_default_DSA();
if(ret->engine)
{
ret->meth = ENGINE_get_DSA(ret->engine);
if(!ret->meth)
{
DSAerr(DSA_F_DSA_NEW_METHOD,
ERR_R_ENGINE_LIB);
ENGINE_finish(ret->engine);
OPENSSL_free(ret);
return NULL;
}
}
ret->pad=0;
ret->version=0;
ret->write_params=1;
ret->p=NULL;
ret->q=NULL;
ret->g=NULL;
ret->pub_key=NULL;
ret->priv_key=NULL;
ret->kinv=NULL;
ret->r=NULL;
ret->method_mont_p=NULL;
ret->references=1;
ret->flags=ret->meth->flags;
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_DSA, ret, &ret->ex_data);
if ((ret->meth->init != NULL) && !ret->meth->init(ret))
{
if (ret->engine)
ENGINE_finish(ret->engine);
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_DSA, ret, &ret->ex_data);
OPENSSL_free(ret);
ret=NULL;
}
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
if(r->meth->finish)
r->meth->finish(r);
if(r->engine)
ENGINE_finish(r->engine);
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_DSA, r, &r->ex_data);
if (r->p != NULL) BN_clear_free(r->p);
if (r->q != NULL) BN_clear_free(r->q);
if (r->g != NULL) BN_clear_free(r->g);
if (r->pub_key != NULL) BN_clear_free(r->pub_key);
if (r->priv_key != NULL) BN_clear_free(r->priv_key);
if (r->kinv != NULL) BN_clear_free(r->kinv);
if (r->r != NULL) BN_clear_free(r->r);
OPENSSL_free(r);
}
int DSA_up_ref(DSA *r)
{
int i = CRYPTO_add(&r->references, 1, CRYPTO_LOCK_DSA);
#ifdef REF_PRINT
REF_PRINT("DSA",r);
#endif
#ifdef REF_CHECK
if (i < 2)
{
fprintf(stderr, "DSA_up_ref, bad reference count\n");
abort();
}
#endif
return ((i > 1) ? 1 : 0);
}
int DSA_size(const DSA *r)
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
int DSA_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_DSA, argl, argp,
new_func, dup_func, free_func);
}
int DSA_set_ex_data(DSA *d, int idx, void *arg)
{
return(CRYPTO_set_ex_data(&d->ex_data,idx,arg));
}
void *DSA_get_ex_data(DSA *d, int idx)
{
return(CRYPTO_get_ex_data(&d->ex_data,idx));
}
DH *DSA_dup_DH(const DSA *r)
{
DH *ret = NULL;
if (r == NULL)
goto err;
ret = DH_new();
if (ret == NULL)
goto err;
if (r->p != NULL)
if ((ret->p = BN_dup(r->p)) == NULL)
goto err;
if (r->q != NULL)
ret->length = BN_num_bits(r->q);
if (r->g != NULL)
if ((ret->g = BN_dup(r->g)) == NULL)
goto err;
if (r->pub_key != NULL)
if ((ret->pub_key = BN_dup(r->pub_key)) == NULL)
goto err;
if (r->priv_key != NULL)
if ((ret->priv_key = BN_dup(r->priv_key)) == NULL)
goto err;
return ret;
err:
if (ret != NULL)
DH_free(ret);
return NULL;
}
