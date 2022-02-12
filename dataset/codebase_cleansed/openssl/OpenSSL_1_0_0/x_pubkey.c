static int pubkey_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_FREE_POST)
{
X509_PUBKEY *pubkey = (X509_PUBKEY *)*pval;
EVP_PKEY_free(pubkey->pkey);
}
return 1;
}
RSA *d2i_RSA_PUBKEY(RSA **a, const unsigned char **pp,
long length)
{
EVP_PKEY *pkey;
RSA *key;
const unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if (!pkey) return NULL;
key = EVP_PKEY_get1_RSA(pkey);
EVP_PKEY_free(pkey);
if (!key) return NULL;
*pp = q;
if (a)
{
RSA_free(*a);
*a = key;
}
return key;
}
int i2d_RSA_PUBKEY(RSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if (!a) return 0;
pktmp = EVP_PKEY_new();
if (!pktmp)
{
ASN1err(ASN1_F_I2D_RSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_RSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
DSA *d2i_DSA_PUBKEY(DSA **a, const unsigned char **pp,
long length)
{
EVP_PKEY *pkey;
DSA *key;
const unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if (!pkey) return NULL;
key = EVP_PKEY_get1_DSA(pkey);
EVP_PKEY_free(pkey);
if (!key) return NULL;
*pp = q;
if (a)
{
DSA_free(*a);
*a = key;
}
return key;
}
int i2d_DSA_PUBKEY(DSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if(!a) return 0;
pktmp = EVP_PKEY_new();
if(!pktmp)
{
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
if (!pkey) return(NULL);
key = EVP_PKEY_get1_EC_KEY(pkey);
EVP_PKEY_free(pkey);
if (!key) return(NULL);
*pp = q;
if (a)
{
EC_KEY_free(*a);
*a = key;
}
return(key);
}
int i2d_EC_PUBKEY(EC_KEY *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if (!a) return(0);
if ((pktmp = EVP_PKEY_new()) == NULL)
{
ASN1err(ASN1_F_I2D_EC_PUBKEY, ERR_R_MALLOC_FAILURE);
return(0);
}
EVP_PKEY_set1_EC_KEY(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return(ret);
}
int X509_PUBKEY_set0_param(X509_PUBKEY *pub, ASN1_OBJECT *aobj,
int ptype, void *pval,
unsigned char *penc, int penclen)
{
if (!X509_ALGOR_set0(pub->algor, aobj, ptype, pval))
return 0;
if (penc)
{
if (pub->public_key->data)
OPENSSL_free(pub->public_key->data);
pub->public_key->data = penc;
pub->public_key->length = penclen;
pub->public_key->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
pub->public_key->flags|=ASN1_STRING_FLAG_BITS_LEFT;
}
return 1;
}
int X509_PUBKEY_get0_param(ASN1_OBJECT **ppkalg,
const unsigned char **pk, int *ppklen,
X509_ALGOR **pa,
X509_PUBKEY *pub)
{
if (ppkalg)
*ppkalg = pub->algor->algorithm;
if (pk)
{
*pk = pub->public_key->data;
*ppklen = pub->public_key->length;
}
if (pa)
*pa = pub->algor;
return 1;
}
