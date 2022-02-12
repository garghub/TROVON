static int pubkey_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it)
{
if(operation == ASN1_OP_FREE_POST) {
X509_PUBKEY *pubkey = (X509_PUBKEY *)*pval;
EVP_PKEY_free(pubkey->pkey);
}
return 1;
}
RSA *d2i_RSA_PUBKEY(RSA **a, unsigned char **pp,
long length)
{
EVP_PKEY *pkey;
RSA *key;
unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if(!pkey) return NULL;
key = EVP_PKEY_get1_RSA(pkey);
EVP_PKEY_free(pkey);
if(!key) return NULL;
*pp = q;
if(a) {
RSA_free(*a);
*a = key;
}
return key;
}
int i2d_RSA_PUBKEY(RSA *a, unsigned char **pp)
{
EVP_PKEY *pktmp;
int ret;
if(!a) return 0;
pktmp = EVP_PKEY_new();
if(!pktmp) {
ASN1err(ASN1_F_I2D_RSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_RSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
DSA *d2i_DSA_PUBKEY(DSA **a, unsigned char **pp,
long length)
{
EVP_PKEY *pkey;
DSA *key;
unsigned char *q;
q = *pp;
pkey = d2i_PUBKEY(NULL, &q, length);
if(!pkey) return NULL;
key = EVP_PKEY_get1_DSA(pkey);
EVP_PKEY_free(pkey);
if(!key) return NULL;
*pp = q;
if(a) {
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
if(!pktmp) {
ASN1err(ASN1_F_I2D_DSA_PUBKEY, ERR_R_MALLOC_FAILURE);
return 0;
}
EVP_PKEY_set1_DSA(pktmp, a);
ret = i2d_PUBKEY(pktmp, pp);
EVP_PKEY_free(pktmp);
return ret;
}
