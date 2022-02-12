DSA_METHOD *DSA_meth_new(const char *name, int flags)
{
DSA_METHOD *dsam = OPENSSL_zalloc(sizeof(DSA_METHOD));
if (dsam != NULL) {
dsam->name = OPENSSL_strdup(name);
if (dsam->name == NULL) {
OPENSSL_free(dsam);
DSAerr(DSA_F_DSA_METH_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
dsam->flags = flags;
}
return dsam;
}
void DSA_meth_free(DSA_METHOD *dsam)
{
if (dsam != NULL) {
OPENSSL_free(dsam->name);
OPENSSL_free(dsam);
}
}
DSA_METHOD *DSA_meth_dup(const DSA_METHOD *dsam)
{
DSA_METHOD *ret;
ret = OPENSSL_malloc(sizeof(DSA_METHOD));
if (ret != NULL) {
memcpy(ret, dsam, sizeof(*dsam));
ret->name = OPENSSL_strdup(dsam->name);
if (ret->name == NULL) {
OPENSSL_free(ret);
DSAerr(DSA_F_DSA_METH_DUP, ERR_R_MALLOC_FAILURE);
return NULL;
}
}
return ret;
}
const char *DSA_meth_get0_name(const DSA_METHOD *dsam)
{
return dsam->name;
}
int DSA_meth_set1_name(DSA_METHOD *dsam, const char *name)
{
char *tmpname;
tmpname = OPENSSL_strdup(name);
if (tmpname == NULL) {
DSAerr(DSA_F_DSA_METH_SET1_NAME, ERR_R_MALLOC_FAILURE);
return 0;
}
OPENSSL_free(dsam->name);
dsam->name = tmpname;
return 1;
}
int DSA_meth_get_flags(DSA_METHOD *dsam)
{
return dsam->flags;
}
int DSA_meth_set_flags(DSA_METHOD *dsam, int flags)
{
dsam->flags = flags;
return 1;
}
void *DSA_meth_get0_app_data(const DSA_METHOD *dsam)
{
return dsam->app_data;
}
int DSA_meth_set0_app_data(DSA_METHOD *dsam, void *app_data)
{
dsam->app_data = app_data;
return 1;
}
int DSA_meth_set_sign(DSA_METHOD *dsam,
DSA_SIG *(*sign) (const unsigned char *, int, DSA *))
{
dsam->dsa_do_sign = sign;
return 1;
}
int DSA_meth_set_sign_setup(DSA_METHOD *dsam,
int (*sign_setup) (DSA *, BN_CTX *, BIGNUM **, BIGNUM **))
{
dsam->dsa_sign_setup = sign_setup;
return 1;
}
int DSA_meth_set_verify(DSA_METHOD *dsam,
int (*verify) (const unsigned char *, int, DSA_SIG *, DSA *))
{
dsam->dsa_do_verify = verify;
return 1;
}
int DSA_meth_set_mod_exp(DSA_METHOD *dsam,
int (*mod_exp) (DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *,
const BIGNUM *, const BIGNUM *, const BIGNUM *, BN_CTX *,
BN_MONT_CTX *))
{
dsam->dsa_mod_exp = mod_exp;
return 1;
}
int DSA_meth_set_bn_mod_exp(DSA_METHOD *dsam,
int (*bn_mod_exp) (DSA *, BIGNUM *, const BIGNUM *, const BIGNUM *,
const BIGNUM *, BN_CTX *, BN_MONT_CTX *))
{
dsam->bn_mod_exp = bn_mod_exp;
return 1;
}
int DSA_meth_set_init(DSA_METHOD *dsam, int (*init)(DSA *))
{
dsam->init = init;
return 1;
}
int DSA_meth_set_finish(DSA_METHOD *dsam, int (*finish) (DSA *))
{
dsam->finish = finish;
return 1;
}
int DSA_meth_set_paramgen(DSA_METHOD *dsam,
int (*paramgen) (DSA *, int, const unsigned char *, int, int *,
unsigned long *, BN_GENCB *))
{
dsam->dsa_paramgen = paramgen;
return 1;
}
int DSA_meth_set_keygen(DSA_METHOD *dsam, int (*keygen) (DSA *))
{
dsam->dsa_keygen = keygen;
return 1;
}
