static int pubkey_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_FREE_POST) {
X509_PUBKEY *pubkey = (X509_PUBKEY *)*pval;
EVP_PKEY_free(pubkey->pkey);
} else if (operation == ASN1_OP_D2I_POST) {
X509_PUBKEY *pubkey = (X509_PUBKEY *)*pval;
EVP_PKEY_free(pubkey->pkey);
ERR_set_mark();
if (x509_pubkey_decode(&pubkey->pkey, pubkey) == -1)
return 0;
ERR_pop_to_mark();
}
return 1;
}
int x509_pubkey_decode(EVP_PKEY **ppkey, X509_PUBKEY *key)
{
EVP_PKEY *pkey = EVP_PKEY_new();
if (pkey == NULL) {
X509err(X509_F_X509_PUBKEY_DECODE, ERR_R_MALLOC_FAILURE);
return -1;
}
if (!EVP_PKEY_set_type(pkey, OBJ_obj2nid(key->algor->algorithm))) {
X509err(X509_F_X509_PUBKEY_DECODE, X509_R_UNSUPPORTED_ALGORITHM);
goto error;
}
if (pkey->ameth->pub_decode) {
if (!pkey->ameth->pub_decode(pkey, key)) {
X509err(X509_F_X509_PUBKEY_DECODE, X509_R_PUBLIC_KEY_DECODE_ERROR);
goto error;
}
} else {
X509err(X509_F_X509_PUBKEY_DECODE, X509_R_METHOD_NOT_SUPPORTED);
goto error;
}
*ppkey = pkey;
return 1;
error:
EVP_PKEY_free(pkey);
return 0;
}
EVP_PKEY *X509_PUBKEY_get0(X509_PUBKEY *key)
{
EVP_PKEY *ret = NULL;
if (key == NULL || key->public_key == NULL)
return NULL;
if (key->pkey != NULL)
return key->pkey;
x509_pubkey_decode(&ret, key);
if (ret != NULL) {
X509err(X509_F_X509_PUBKEY_GET0, ERR_R_INTERNAL_ERROR);
EVP_PKEY_free(ret);
}
return NULL;
}
EVP_PKEY *X509_PUBKEY_get(X509_PUBKEY *key)
{
EVP_PKEY *ret = X509_PUBKEY_get0(key);
if (ret != NULL)
EVP_PKEY_up_ref(ret);
return ret;
}
EVP_PKEY *d2i_PUBKEY(EVP_PKEY **a, const unsigned char **pp, long length)
{
X509_PUBKEY *xpk;
EVP_PKEY *pktmp;
const unsigned char *q;
q = *pp;
xpk = d2i_X509_PUBKEY(NULL, &q, length);
if (!xpk)
return NULL;
pktmp = X509_PUBKEY_get(xpk);
X509_PUBKEY_free(xpk);
if (!pktmp)
return NULL;
*pp = q;
if (a) {
EVP_PKEY_free(*a);
*a = pktmp;
}
return pktmp;
}
int i2d_PUBKEY(EVP_PKEY *a, unsigned char **pp)
{
X509_PUBKEY *xpk = NULL;
int ret;
if (!a)
return 0;
if (!X509_PUBKEY_set(&xpk, a))
return 0;
ret = i2d_X509_PUBKEY(xpk, pp);
X509_PUBKEY_free(xpk);
return ret;
}
RSA *d2i_RSA_PUBKEY(RSA **a, const unsigned char **pp, long length)
{
EVP_PKEY *pkey;
RSA *key;
const unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if (!pkey)
return NULL;
key = EVP_PKEY_get1_RSA(pkey);
EVP_PKEY_free(pkey);
if (!key)
return NULL;
*pp = q;
if (a) {
RSA_free(*a);
*a = key;
}
return key;
}
int i2d_RSA_PUBKEY(RSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if (!a)
return 0;
pktmp = EVP_PKEY_new();
if (pktmp == NULL) {
ASN1err(ASN1_F_I2D_RSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_RSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
DSA *d2i_DSA_PUBKEY(DSA **a, const unsigned char **pp, long length)
{
EVP_PKEY *pkey;
DSA *key;
const unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if (!pkey)
return NULL;
key = EVP_PKEY_get1_DSA(pkey);
EVP_PKEY_free(pkey);
if (!key)
return NULL;
*pp = q;
if (a) {
DSA_free(*a);
*a = key;
}
return key;
}
int i2d_DSA_PUBKEY(DSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if (!a)
return 0;
pktmp = EVP_PKEY_new();
if (pktmp == NULL) {
ASN1err(ASN1_F_I2D_DSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_DSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
EC_KEY *d2i_EC_PUBKEY(EC_KEY **a, const unsigned char **pp, long length)
{
EVP_PKEY *pkey;
EC_KEY *key;
const unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if (!pkey)
return (NULL);
key = EVP_PKEY_get1_EC_KEY(pkey);
EVP_PKEY_free(pkey);
if (!key)
return (NULL);
*pp = q;
if (a) {
EC_KEY_free(*a);
*a = key;
}
return (key);
}
int i2d_EC_PUBKEY(EC_KEY *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if (!a)
return (0);
if ((pktmp = EVP_PKEY_new()) == NULL) {
ASN1err(ASN1_F_I2D_EC_PUBKEY, ERR_R_MALLOC_FAILURE);
return (0);
}
EVP_PKEY_set1_EC_KEY(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return (ret);
}
int X509_PUBKEY_set0_param(X509_PUBKEY *pub, ASN1_OBJECT *aobj,
int ptype, void *pval,
unsigned char *penc, int penclen)
{
if (!X509_ALGOR_set0(pub->algor, aobj, ptype, pval))
return 0;
if (penc) {
OPENSSL_free(pub->public_key->data);
pub->public_key->data = penc;
pub->public_key->length = penclen;
pub->public_key->flags &= ~(ASN1_STRING_FLAG_BITS_LEFT | 0x07);
pub->public_key->flags |= ASN1_STRING_FLAG_BITS_LEFT;
}
return 1;
}
int X509_PUBKEY_get0_param(ASN1_OBJECT **ppkalg,
const unsigned char **pk, int *ppklen,
X509_ALGOR **pa, X509_PUBKEY *pub)
{
if (ppkalg)
*ppkalg = pub->algor->algorithm;
if (pk) {
*pk = pub->public_key->data;
*ppklen = pub->public_key->length;
}
if (pa)
*pa = pub->algor;
return 1;
}
ASN1_BIT_STRING *X509_get0_pubkey_bitstr(const X509 *x)
{
if (x == NULL)
return NULL;
return x->cert_info.key->public_key;
}
