void ECDH_set_default_method(const ECDH_METHOD *meth)
{
default_ECDH_method = meth;
}
const ECDH_METHOD *ECDH_get_default_method(void)
{
if (!default_ECDH_method) {
#ifdef OPENSSL_FIPS
if (FIPS_mode())
return FIPS_ecdh_openssl();
else
return ECDH_OpenSSL();
#else
default_ECDH_method = ECDH_OpenSSL();
#endif
}
return default_ECDH_method;
}
int ECDH_set_method(EC_KEY *eckey, const ECDH_METHOD *meth)
{
ECDH_DATA *ecdh;
ecdh = ecdh_check(eckey);
if (ecdh == NULL)
return 0;
#if 0
mtmp = ecdh->meth;
if (mtmp->finish)
mtmp->finish(eckey);
#endif
#ifndef OPENSSL_NO_ENGINE
if (ecdh->engine) {
ENGINE_finish(ecdh->engine);
ecdh->engine = NULL;
}
#endif
ecdh->meth = meth;
#if 0
if (meth->init)
meth->init(eckey);
#endif
return 1;
}
static ECDH_DATA *ECDH_DATA_new_method(ENGINE *engine)
{
ECDH_DATA *ret;
ret = (ECDH_DATA *)OPENSSL_malloc(sizeof(ECDH_DATA));
if (ret == NULL) {
ECDHerr(ECDH_F_ECDH_DATA_NEW_METHOD, ERR_R_MALLOC_FAILURE);
return (NULL);
}
ret->init = NULL;
ret->meth = ECDH_get_default_method();
ret->engine = engine;
#ifndef OPENSSL_NO_ENGINE
if (!ret->engine)
ret->engine = ENGINE_get_default_ECDH();
if (ret->engine) {
ret->meth = ENGINE_get_ECDH(ret->engine);
if (!ret->meth) {
ECDHerr(ECDH_F_ECDH_DATA_NEW_METHOD, ERR_R_ENGINE_LIB);
ENGINE_finish(ret->engine);
OPENSSL_free(ret);
return NULL;
}
}
#endif
ret->flags = ret->meth->flags;
CRYPTO_new_ex_data(CRYPTO_EX_INDEX_ECDH, ret, &ret->ex_data);
#if 0
if ((ret->meth->init != NULL) && !ret->meth->init(ret)) {
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_ECDH, ret, &ret->ex_data);
OPENSSL_free(ret);
ret = NULL;
}
#endif
return (ret);
}
static void *ecdh_data_new(void)
{
return (void *)ECDH_DATA_new_method(NULL);
}
static void *ecdh_data_dup(void *data)
{
ECDH_DATA *r = (ECDH_DATA *)data;
if (r == NULL)
return NULL;
return (void *)ecdh_data_new();
}
void ecdh_data_free(void *data)
{
ECDH_DATA *r = (ECDH_DATA *)data;
#ifndef OPENSSL_NO_ENGINE
if (r->engine)
ENGINE_finish(r->engine);
#endif
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_ECDH, r, &r->ex_data);
OPENSSL_cleanse((void *)r, sizeof(ECDH_DATA));
OPENSSL_free(r);
}
ECDH_DATA *ecdh_check(EC_KEY *key)
{
ECDH_DATA *ecdh_data;
void *data = EC_KEY_get_key_method_data(key, ecdh_data_dup,
ecdh_data_free, ecdh_data_free);
if (data == NULL) {
ecdh_data = (ECDH_DATA *)ecdh_data_new();
if (ecdh_data == NULL)
return NULL;
data = EC_KEY_insert_key_method_data(key, (void *)ecdh_data,
ecdh_data_dup, ecdh_data_free,
ecdh_data_free);
if (data != NULL) {
ecdh_data_free(ecdh_data);
ecdh_data = (ECDH_DATA *)data;
}
} else
ecdh_data = (ECDH_DATA *)data;
#ifdef OPENSSL_FIPS
if (FIPS_mode() && !(ecdh_data->flags & ECDH_FLAG_FIPS_METHOD)
&& !(EC_KEY_get_flags(key) & EC_FLAG_NON_FIPS_ALLOW)) {
ECDHerr(ECDH_F_ECDH_CHECK, ECDH_R_NON_FIPS_METHOD);
return NULL;
}
#endif
return ecdh_data;
}
int ECDH_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func)
{
return CRYPTO_get_ex_new_index(CRYPTO_EX_INDEX_ECDH, argl, argp,
new_func, dup_func, free_func);
}
int ECDH_set_ex_data(EC_KEY *d, int idx, void *arg)
{
ECDH_DATA *ecdh;
ecdh = ecdh_check(d);
if (ecdh == NULL)
return 0;
return (CRYPTO_set_ex_data(&ecdh->ex_data, idx, arg));
}
void *ECDH_get_ex_data(EC_KEY *d, int idx)
{
ECDH_DATA *ecdh;
ecdh = ecdh_check(d);
if (ecdh == NULL)
return NULL;
return (CRYPTO_get_ex_data(&ecdh->ex_data, idx));
}
