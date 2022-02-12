int X509_verify(X509 *a, EVP_PKEY *r)
{
return(ASN1_item_verify(ASN1_ITEM_rptr(X509_CINF),a->sig_alg,
a->signature,a->cert_info,r));
}
int X509_REQ_verify(X509_REQ *a, EVP_PKEY *r)
{
return( ASN1_item_verify(ASN1_ITEM_rptr(X509_REQ_INFO),
a->sig_alg,a->signature,a->req_info,r));
}
int X509_CRL_verify(X509_CRL *a, EVP_PKEY *r)
{
return(ASN1_item_verify(ASN1_ITEM_rptr(X509_CRL_INFO),
a->sig_alg, a->signature,a->crl,r));
}
int NETSCAPE_SPKI_verify(NETSCAPE_SPKI *a, EVP_PKEY *r)
{
return(ASN1_item_verify(ASN1_ITEM_rptr(NETSCAPE_SPKAC),
a->sig_algor,a->signature,a->spkac,r));
}
int X509_sign(X509 *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_item_sign(ASN1_ITEM_rptr(X509_CINF), x->cert_info->signature,
x->sig_alg, x->signature, x->cert_info,pkey,md));
}
int X509_REQ_sign(X509_REQ *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_item_sign(ASN1_ITEM_rptr(X509_REQ_INFO),x->sig_alg, NULL,
x->signature, x->req_info,pkey,md));
}
int X509_CRL_sign(X509_CRL *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_item_sign(ASN1_ITEM_rptr(X509_CRL_INFO),x->crl->sig_alg,
x->sig_alg, x->signature, x->crl,pkey,md));
}
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_item_sign(ASN1_ITEM_rptr(NETSCAPE_SPKAC), x->sig_algor,NULL,
x->signature, x->spkac,pkey,md));
}
X509 *d2i_X509_fp(FILE *fp, X509 **x509)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(X509), fp, x509);
}
int i2d_X509_fp(FILE *fp, X509 *x509)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(X509), fp, x509);
}
X509 *d2i_X509_bio(BIO *bp, X509 **x509)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(X509), bp, x509);
}
int i2d_X509_bio(BIO *bp, X509 *x509)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(X509), bp, x509);
}
X509_CRL *d2i_X509_CRL_fp(FILE *fp, X509_CRL **crl)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(X509_CRL), fp, crl);
}
int i2d_X509_CRL_fp(FILE *fp, X509_CRL *crl)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(X509_CRL), fp, crl);
}
X509_CRL *d2i_X509_CRL_bio(BIO *bp, X509_CRL **crl)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(X509_CRL), bp, crl);
}
int i2d_X509_CRL_bio(BIO *bp, X509_CRL *crl)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(X509_CRL), bp, crl);
}
PKCS7 *d2i_PKCS7_fp(FILE *fp, PKCS7 **p7)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(PKCS7), fp, p7);
}
int i2d_PKCS7_fp(FILE *fp, PKCS7 *p7)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(PKCS7), fp, p7);
}
PKCS7 *d2i_PKCS7_bio(BIO *bp, PKCS7 **p7)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(PKCS7), bp, p7);
}
int i2d_PKCS7_bio(BIO *bp, PKCS7 *p7)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(PKCS7), bp, p7);
}
X509_REQ *d2i_X509_REQ_fp(FILE *fp, X509_REQ **req)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(X509_REQ), fp, req);
}
int i2d_X509_REQ_fp(FILE *fp, X509_REQ *req)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(X509_REQ), fp, req);
}
X509_REQ *d2i_X509_REQ_bio(BIO *bp, X509_REQ **req)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(X509_REQ), bp, req);
}
int i2d_X509_REQ_bio(BIO *bp, X509_REQ *req)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(X509_REQ), bp, req);
}
RSA *d2i_RSAPrivateKey_fp(FILE *fp, RSA **rsa)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(RSAPrivateKey), fp, rsa);
}
int i2d_RSAPrivateKey_fp(FILE *fp, RSA *rsa)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(RSAPrivateKey), fp, rsa);
}
RSA *d2i_RSAPublicKey_fp(FILE *fp, RSA **rsa)
{
return ASN1_item_d2i_fp(ASN1_ITEM_rptr(RSAPublicKey), fp, rsa);
}
RSA *d2i_RSA_PUBKEY_fp(FILE *fp, RSA **rsa)
{
return((RSA *)ASN1_d2i_fp((char *(*)())
RSA_new,(char *(*)())d2i_RSA_PUBKEY, (fp),
(unsigned char **)(rsa)));
}
int i2d_RSAPublicKey_fp(FILE *fp, RSA *rsa)
{
return ASN1_item_i2d_fp(ASN1_ITEM_rptr(RSAPublicKey), fp, rsa);
}
int i2d_RSA_PUBKEY_fp(FILE *fp, RSA *rsa)
{
return(ASN1_i2d_fp(i2d_RSA_PUBKEY,fp,(unsigned char *)rsa));
}
RSA *d2i_RSAPrivateKey_bio(BIO *bp, RSA **rsa)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(RSAPrivateKey), bp, rsa);
}
int i2d_RSAPrivateKey_bio(BIO *bp, RSA *rsa)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(RSAPrivateKey), bp, rsa);
}
RSA *d2i_RSAPublicKey_bio(BIO *bp, RSA **rsa)
{
return ASN1_item_d2i_bio(ASN1_ITEM_rptr(RSAPublicKey), bp, rsa);
}
RSA *d2i_RSA_PUBKEY_bio(BIO *bp, RSA **rsa)
{
return((RSA *)ASN1_d2i_bio((char *(*)())
RSA_new,(char *(*)())d2i_RSA_PUBKEY, (bp),
(unsigned char **)(rsa)));
}
int i2d_RSAPublicKey_bio(BIO *bp, RSA *rsa)
{
return ASN1_item_i2d_bio(ASN1_ITEM_rptr(RSAPublicKey), bp, rsa);
}
int i2d_RSA_PUBKEY_bio(BIO *bp, RSA *rsa)
{
return(ASN1_i2d_bio(i2d_RSA_PUBKEY,bp,(unsigned char *)rsa));
}
DSA *d2i_DSAPrivateKey_fp(FILE *fp, DSA **dsa)
{
return((DSA *)ASN1_d2i_fp((char *(*)())
DSA_new,(char *(*)())d2i_DSAPrivateKey, (fp),
(unsigned char **)(dsa)));
}
int i2d_DSAPrivateKey_fp(FILE *fp, DSA *dsa)
{
return(ASN1_i2d_fp(i2d_DSAPrivateKey,fp,(unsigned char *)dsa));
}
DSA *d2i_DSA_PUBKEY_fp(FILE *fp, DSA **dsa)
{
return((DSA *)ASN1_d2i_fp((char *(*)())
DSA_new,(char *(*)())d2i_DSA_PUBKEY, (fp),
(unsigned char **)(dsa)));
}
int i2d_DSA_PUBKEY_fp(FILE *fp, DSA *dsa)
{
return(ASN1_i2d_fp(i2d_DSA_PUBKEY,fp,(unsigned char *)dsa));
}
DSA *d2i_DSAPrivateKey_bio(BIO *bp, DSA **dsa)
{
return((DSA *)ASN1_d2i_bio((char *(*)())
DSA_new,(char *(*)())d2i_DSAPrivateKey, (bp),
(unsigned char **)(dsa)));
}
int i2d_DSAPrivateKey_bio(BIO *bp, DSA *dsa)
{
return(ASN1_i2d_bio(i2d_DSAPrivateKey,bp,(unsigned char *)dsa));
}
DSA *d2i_DSA_PUBKEY_bio(BIO *bp, DSA **dsa)
{
return((DSA *)ASN1_d2i_bio((char *(*)())
DSA_new,(char *(*)())d2i_DSA_PUBKEY, (bp),
(unsigned char **)(dsa)));
}
int i2d_DSA_PUBKEY_bio(BIO *bp, DSA *dsa)
{
return(ASN1_i2d_bio(i2d_DSA_PUBKEY,bp,(unsigned char *)dsa));
}
int X509_pubkey_digest(const X509 *data, const EVP_MD *type, unsigned char *md,
unsigned int *len)
{
ASN1_BIT_STRING *key;
key = X509_get0_pubkey_bitstr(data);
if(!key) return 0;
return EVP_Digest(key->data, key->length, md, len, type, NULL);
}
int X509_digest(const X509 *data, const EVP_MD *type, unsigned char *md,
unsigned int *len)
{
return(ASN1_item_digest(ASN1_ITEM_rptr(X509),type,(char *)data,md,len));
}
int X509_CRL_digest(const X509_CRL *data, const EVP_MD *type, unsigned char *md,
unsigned int *len)
{
return(ASN1_item_digest(ASN1_ITEM_rptr(X509_CRL),type,(char *)data,md,len));
}
int X509_REQ_digest(const X509_REQ *data, const EVP_MD *type, unsigned char *md,
unsigned int *len)
{
return(ASN1_item_digest(ASN1_ITEM_rptr(X509_REQ),type,(char *)data,md,len));
}
int X509_NAME_digest(const X509_NAME *data, const EVP_MD *type, unsigned char *md,
unsigned int *len)
{
return(ASN1_item_digest(ASN1_ITEM_rptr(X509_NAME),type,(char *)data,md,len));
}
int PKCS7_ISSUER_AND_SERIAL_digest(PKCS7_ISSUER_AND_SERIAL *data, const EVP_MD *type,
unsigned char *md, unsigned int *len)
{
return(ASN1_item_digest(ASN1_ITEM_rptr(PKCS7_ISSUER_AND_SERIAL),type,
(char *)data,md,len));
}
X509_SIG *d2i_PKCS8_fp(FILE *fp, X509_SIG **p8)
{
return((X509_SIG *)ASN1_d2i_fp((char *(*)())X509_SIG_new,
(char *(*)())d2i_X509_SIG, (fp),(unsigned char **)(p8)));
}
int i2d_PKCS8_fp(FILE *fp, X509_SIG *p8)
{
return(ASN1_i2d_fp(i2d_X509_SIG,fp,(unsigned char *)p8));
}
X509_SIG *d2i_PKCS8_bio(BIO *bp, X509_SIG **p8)
{
return((X509_SIG *)ASN1_d2i_bio((char *(*)())X509_SIG_new,
(char *(*)())d2i_X509_SIG, (bp),(unsigned char **)(p8)));
}
int i2d_PKCS8_bio(BIO *bp, X509_SIG *p8)
{
return(ASN1_i2d_bio(i2d_X509_SIG,bp,(unsigned char *)p8));
}
PKCS8_PRIV_KEY_INFO *d2i_PKCS8_PRIV_KEY_INFO_fp(FILE *fp,
PKCS8_PRIV_KEY_INFO **p8inf)
{
return((PKCS8_PRIV_KEY_INFO *)ASN1_d2i_fp(
(char *(*)())PKCS8_PRIV_KEY_INFO_new,
(char *(*)())d2i_PKCS8_PRIV_KEY_INFO, (fp),
(unsigned char **)(p8inf)));
}
int i2d_PKCS8_PRIV_KEY_INFO_fp(FILE *fp, PKCS8_PRIV_KEY_INFO *p8inf)
{
return(ASN1_i2d_fp(i2d_PKCS8_PRIV_KEY_INFO,fp,(unsigned char *)p8inf));
}
int i2d_PKCS8PrivateKeyInfo_fp(FILE *fp, EVP_PKEY *key)
{
PKCS8_PRIV_KEY_INFO *p8inf;
int ret;
p8inf = EVP_PKEY2PKCS8(key);
if(!p8inf) return 0;
ret = i2d_PKCS8_PRIV_KEY_INFO_fp(fp, p8inf);
PKCS8_PRIV_KEY_INFO_free(p8inf);
return ret;
}
int i2d_PrivateKey_fp(FILE *fp, EVP_PKEY *pkey)
{
return(ASN1_i2d_fp(i2d_PrivateKey,fp,(unsigned char *)pkey));
}
EVP_PKEY *d2i_PrivateKey_fp(FILE *fp, EVP_PKEY **a)
{
return((EVP_PKEY *)ASN1_d2i_fp((char *(*)())EVP_PKEY_new,
(char *(*)())d2i_AutoPrivateKey, (fp),(unsigned char **)(a)));
}
int i2d_PUBKEY_fp(FILE *fp, EVP_PKEY *pkey)
{
return(ASN1_i2d_fp(i2d_PUBKEY,fp,(unsigned char *)pkey));
}
EVP_PKEY *d2i_PUBKEY_fp(FILE *fp, EVP_PKEY **a)
{
return((EVP_PKEY *)ASN1_d2i_fp((char *(*)())EVP_PKEY_new,
(char *(*)())d2i_PUBKEY, (fp),(unsigned char **)(a)));
}
PKCS8_PRIV_KEY_INFO *d2i_PKCS8_PRIV_KEY_INFO_bio(BIO *bp,
PKCS8_PRIV_KEY_INFO **p8inf)
{
return((PKCS8_PRIV_KEY_INFO *)ASN1_d2i_bio(
(char *(*)())PKCS8_PRIV_KEY_INFO_new,
(char *(*)())d2i_PKCS8_PRIV_KEY_INFO, (bp),
(unsigned char **)(p8inf)));
}
int i2d_PKCS8_PRIV_KEY_INFO_bio(BIO *bp, PKCS8_PRIV_KEY_INFO *p8inf)
{
return(ASN1_i2d_bio(i2d_PKCS8_PRIV_KEY_INFO,bp,(unsigned char *)p8inf));
}
int i2d_PKCS8PrivateKeyInfo_bio(BIO *bp, EVP_PKEY *key)
{
PKCS8_PRIV_KEY_INFO *p8inf;
int ret;
p8inf = EVP_PKEY2PKCS8(key);
if(!p8inf) return 0;
ret = i2d_PKCS8_PRIV_KEY_INFO_bio(bp, p8inf);
PKCS8_PRIV_KEY_INFO_free(p8inf);
return ret;
}
int i2d_PrivateKey_bio(BIO *bp, EVP_PKEY *pkey)
{
return(ASN1_i2d_bio(i2d_PrivateKey,bp,(unsigned char *)pkey));
}
EVP_PKEY *d2i_PrivateKey_bio(BIO *bp, EVP_PKEY **a)
{
return((EVP_PKEY *)ASN1_d2i_bio((char *(*)())EVP_PKEY_new,
(char *(*)())d2i_AutoPrivateKey, (bp),(unsigned char **)(a)));
}
int i2d_PUBKEY_bio(BIO *bp, EVP_PKEY *pkey)
{
return(ASN1_i2d_bio(i2d_PUBKEY,bp,(unsigned char *)pkey));
}
EVP_PKEY *d2i_PUBKEY_bio(BIO *bp, EVP_PKEY **a)
{
return((EVP_PKEY *)ASN1_d2i_bio((char *(*)())EVP_PKEY_new,
(char *(*)())d2i_PUBKEY, (bp),(unsigned char **)(a)));
}
