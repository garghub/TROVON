RSA_METHOD *RSA_meth_new(const char *name, int flags)
{
RSA_METHOD *meth = OPENSSL_zalloc(sizeof(RSA_METHOD));
if (meth != NULL) {
meth->name = OPENSSL_strdup(name);
if (meth->name == NULL) {
OPENSSL_free(meth);
RSAerr(RSA_F_RSA_METH_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
meth->flags = flags;
}
return meth;
}
void RSA_meth_free(RSA_METHOD *meth)
{
if (meth != NULL) {
OPENSSL_free(meth->name);
OPENSSL_free(meth);
}
}
RSA_METHOD *RSA_meth_dup(const RSA_METHOD *meth)
{
RSA_METHOD *ret;
ret = OPENSSL_malloc(sizeof(RSA_METHOD));
if (ret != NULL) {
memcpy(ret, meth, sizeof(*meth));
ret->name = OPENSSL_strdup(meth->name);
if (ret->name == NULL) {
OPENSSL_free(ret);
RSAerr(RSA_F_RSA_METH_DUP, ERR_R_MALLOC_FAILURE);
return NULL;
}
}
return ret;
}
const char *RSA_meth_get0_name(const RSA_METHOD *meth)
{
return meth->name;
}
int RSA_meth_set1_name(RSA_METHOD *meth, const char *name)
{
char *tmpname;
tmpname = OPENSSL_strdup(name);
if (tmpname == NULL) {
RSAerr(RSA_F_RSA_METH_SET1_NAME, ERR_R_MALLOC_FAILURE);
return 0;
}
OPENSSL_free(meth->name);
meth->name = tmpname;
return 1;
}
int RSA_meth_get_flags(RSA_METHOD *meth)
{
return meth->flags;
}
int RSA_meth_set_flags(RSA_METHOD *meth, int flags)
{
meth->flags = flags;
return 1;
}
void *RSA_meth_get0_app_data(const RSA_METHOD *meth)
{
return meth->app_data;
}
int RSA_meth_set0_app_data(RSA_METHOD *meth, void *app_data)
{
meth->app_data = app_data;
return 1;
}
int RSA_meth_set_pub_enc(RSA_METHOD *meth,
int (*pub_enc) (int flen, const unsigned char *from,
unsigned char *to, RSA *rsa,
int padding))
{
meth->rsa_pub_enc = pub_enc;
return 1;
}
int RSA_meth_set_pub_dec(RSA_METHOD *meth,
int (*pub_dec) (int flen, const unsigned char *from,
unsigned char *to, RSA *rsa,
int padding))
{
meth->rsa_pub_dec = pub_dec;
return 1;
}
int RSA_meth_set_priv_enc(RSA_METHOD *meth,
int (*priv_enc) (int flen, const unsigned char *from,
unsigned char *to, RSA *rsa,
int padding))
{
meth->rsa_priv_enc = priv_enc;
return 1;
}
int RSA_meth_set_priv_dec(RSA_METHOD *meth,
int (*priv_dec) (int flen, const unsigned char *from,
unsigned char *to, RSA *rsa,
int padding))
{
meth->rsa_priv_dec = priv_dec;
return 1;
}
int RSA_meth_set_mod_exp(RSA_METHOD *meth,
int (*mod_exp) (BIGNUM *r0, const BIGNUM *I, RSA *rsa,
BN_CTX *ctx))
{
meth->rsa_mod_exp = mod_exp;
return 1;
}
int RSA_meth_set_bn_mod_exp(RSA_METHOD *meth,
int (*bn_mod_exp) (BIGNUM *r,
const BIGNUM *a,
const BIGNUM *p,
const BIGNUM *m,
BN_CTX *ctx,
BN_MONT_CTX *m_ctx))
{
meth->bn_mod_exp = bn_mod_exp;
return 1;
}
int RSA_meth_set_init(RSA_METHOD *meth, int (*init) (RSA *rsa))
{
meth->init = init;
return 1;
}
int RSA_meth_set_finish(RSA_METHOD *meth, int (*finish) (RSA *rsa))
{
meth->finish = finish;
return 1;
}
int RSA_meth_set_sign(RSA_METHOD *meth,
int (*sign) (int type, const unsigned char *m,
unsigned int m_length,
unsigned char *sigret, unsigned int *siglen,
const RSA *rsa))
{
meth->rsa_sign = sign;
return 1;
}
int RSA_meth_set_verify(RSA_METHOD *meth,
int (*verify) (int dtype, const unsigned char *m,
unsigned int m_length,
const unsigned char *sigbuf,
unsigned int siglen, const RSA *rsa))
{
meth->rsa_verify = verify;
return 1;
}
int RSA_meth_set_keygen(RSA_METHOD *meth,
int (*keygen) (RSA *rsa, int bits, BIGNUM *e,
BN_GENCB *cb))
{
meth->rsa_keygen = keygen;
return 1;
}
