int X509_verify(X509 *a, EVP_PKEY *r)
{
return(ASN1_verify((int (*)())i2d_X509_CINF,a->sig_alg,
a->signature,(char *)a->cert_info,r));
}
int X509_REQ_verify(X509_REQ *a, EVP_PKEY *r)
{
return( ASN1_verify((int (*)())i2d_X509_REQ_INFO,
a->sig_alg,a->signature,(char *)a->req_info,r));
}
int X509_CRL_verify(X509_CRL *a, EVP_PKEY *r)
{
return(ASN1_verify((int (*)())i2d_X509_CRL_INFO,
a->sig_alg, a->signature,(char *)a->crl,r));
}
int NETSCAPE_SPKI_verify(NETSCAPE_SPKI *a, EVP_PKEY *r)
{
return(ASN1_verify((int (*)())i2d_NETSCAPE_SPKAC,
a->sig_algor,a->signature, (char *)a->spkac,r));
}
int X509_sign(X509 *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_sign((int (*)())i2d_X509_CINF, x->cert_info->signature,
x->sig_alg, x->signature, (char *)x->cert_info,pkey,md));
}
int X509_REQ_sign(X509_REQ *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_sign((int (*)())i2d_X509_REQ_INFO,x->sig_alg, NULL,
x->signature, (char *)x->req_info,pkey,md));
}
int X509_CRL_sign(X509_CRL *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_sign((int (*)())i2d_X509_CRL_INFO,x->crl->sig_alg,
x->sig_alg, x->signature, (char *)x->crl,pkey,md));
}
int NETSCAPE_SPKI_sign(NETSCAPE_SPKI *x, EVP_PKEY *pkey, const EVP_MD *md)
{
return(ASN1_sign((int (*)())i2d_NETSCAPE_SPKAC, x->sig_algor,NULL,
x->signature, (char *)x->spkac,pkey,md));
}
X509_ATTRIBUTE *X509_ATTRIBUTE_dup(X509_ATTRIBUTE *xa)
{
return((X509_ATTRIBUTE *)ASN1_dup((int (*)())i2d_X509_ATTRIBUTE,
(char *(*)())d2i_X509_ATTRIBUTE,(char *)xa));
}
X509 *X509_dup(X509 *x509)
{
return((X509 *)ASN1_dup((int (*)())i2d_X509,
(char *(*)())d2i_X509,(char *)x509));
}
X509_EXTENSION *X509_EXTENSION_dup(X509_EXTENSION *ex)
{
return((X509_EXTENSION *)ASN1_dup(
(int (*)())i2d_X509_EXTENSION,
(char *(*)())d2i_X509_EXTENSION,(char *)ex));
}
X509 *d2i_X509_fp(FILE *fp, X509 **x509)
{
return((X509 *)ASN1_d2i_fp((char *(*)())X509_new,
(char *(*)())d2i_X509, (fp),(unsigned char **)(x509)));
}
int i2d_X509_fp(FILE *fp, X509 *x509)
{
return(ASN1_i2d_fp(i2d_X509,fp,(unsigned char *)x509));
}
X509 *d2i_X509_bio(BIO *bp, X509 **x509)
{
return((X509 *)ASN1_d2i_bio((char *(*)())X509_new,
(char *(*)())d2i_X509, (bp),(unsigned char **)(x509)));
}
int i2d_X509_bio(BIO *bp, X509 *x509)
{
return(ASN1_i2d_bio(i2d_X509,bp,(unsigned char *)x509));
}
X509_CRL *X509_CRL_dup(X509_CRL *crl)
{
return((X509_CRL *)ASN1_dup((int (*)())i2d_X509_CRL,
(char *(*)())d2i_X509_CRL,(char *)crl));
}
X509_CRL *d2i_X509_CRL_fp(FILE *fp, X509_CRL **crl)
{
return((X509_CRL *)ASN1_d2i_fp((char *(*)())
X509_CRL_new,(char *(*)())d2i_X509_CRL, (fp),
(unsigned char **)(crl)));
}
int i2d_X509_CRL_fp(FILE *fp, X509_CRL *crl)
{
return(ASN1_i2d_fp(i2d_X509_CRL,fp,(unsigned char *)crl));
}
X509_CRL *d2i_X509_CRL_bio(BIO *bp, X509_CRL **crl)
{
return((X509_CRL *)ASN1_d2i_bio((char *(*)())
X509_CRL_new,(char *(*)())d2i_X509_CRL, (bp),
(unsigned char **)(crl)));
}
int i2d_X509_CRL_bio(BIO *bp, X509_CRL *crl)
{
return(ASN1_i2d_bio(i2d_X509_CRL,bp,(unsigned char *)crl));
}
PKCS7 *PKCS7_dup(PKCS7 *p7)
{
return((PKCS7 *)ASN1_dup((int (*)())i2d_PKCS7,
(char *(*)())d2i_PKCS7,(char *)p7));
}
PKCS7 *d2i_PKCS7_fp(FILE *fp, PKCS7 **p7)
{
return((PKCS7 *)ASN1_d2i_fp((char *(*)())
PKCS7_new,(char *(*)())d2i_PKCS7, (fp),
(unsigned char **)(p7)));
}
int i2d_PKCS7_fp(FILE *fp, PKCS7 *p7)
{
return(ASN1_i2d_fp(i2d_PKCS7,fp,(unsigned char *)p7));
}
PKCS7 *d2i_PKCS7_bio(BIO *bp, PKCS7 **p7)
{
return((PKCS7 *)ASN1_d2i_bio((char *(*)())
PKCS7_new,(char *(*)())d2i_PKCS7, (bp),
(unsigned char **)(p7)));
}
int i2d_PKCS7_bio(BIO *bp, PKCS7 *p7)
{
return(ASN1_i2d_bio(i2d_PKCS7,bp,(unsigned char *)p7));
}
X509_REQ *X509_REQ_dup(X509_REQ *req)
{
return((X509_REQ *)ASN1_dup((int (*)())i2d_X509_REQ,
(char *(*)())d2i_X509_REQ,(char *)req));
}
X509_REQ *d2i_X509_REQ_fp(FILE *fp, X509_REQ **req)
{
return((X509_REQ *)ASN1_d2i_fp((char *(*)())
X509_REQ_new, (char *(*)())d2i_X509_REQ, (fp),
(unsigned char **)(req)));
}
int i2d_X509_REQ_fp(FILE *fp, X509_REQ *req)
{
return(ASN1_i2d_fp(i2d_X509_REQ,fp,(unsigned char *)req));
}
X509_REQ *d2i_X509_REQ_bio(BIO *bp, X509_REQ **req)
{
return((X509_REQ *)ASN1_d2i_bio((char *(*)())
X509_REQ_new, (char *(*)())d2i_X509_REQ, (bp),
(unsigned char **)(req)));
}
int i2d_X509_REQ_bio(BIO *bp, X509_REQ *req)
{
return(ASN1_i2d_bio(i2d_X509_REQ,bp,(unsigned char *)req));
}
RSA *RSAPublicKey_dup(RSA *rsa)
{
return((RSA *)ASN1_dup((int (*)())i2d_RSAPublicKey,
(char *(*)())d2i_RSAPublicKey,(char *)rsa));
}
RSA *RSAPrivateKey_dup(RSA *rsa)
{
return((RSA *)ASN1_dup((int (*)())i2d_RSAPrivateKey,
(char *(*)())d2i_RSAPrivateKey,(char *)rsa));
}
RSA *d2i_RSAPrivateKey_fp(FILE *fp, RSA **rsa)
{
return((RSA *)ASN1_d2i_fp((char *(*)())
RSA_new,(char *(*)())d2i_RSAPrivateKey, (fp),
(unsigned char **)(rsa)));
}
int i2d_RSAPrivateKey_fp(FILE *fp, RSA *rsa)
{
return(ASN1_i2d_fp(i2d_RSAPrivateKey,fp,(unsigned char *)rsa));
}
RSA *d2i_RSAPublicKey_fp(FILE *fp, RSA **rsa)
{
return((RSA *)ASN1_d2i_fp((char *(*)())
RSA_new,(char *(*)())d2i_RSAPublicKey, (fp),
(unsigned char **)(rsa)));
}
int i2d_RSAPublicKey_fp(FILE *fp, RSA *rsa)
{
return(ASN1_i2d_fp(i2d_RSAPublicKey,fp,(unsigned char *)rsa));
}
RSA *d2i_RSAPrivateKey_bio(BIO *bp, RSA **rsa)
{
return((RSA *)ASN1_d2i_bio((char *(*)())
RSA_new,(char *(*)())d2i_RSAPrivateKey, (bp),
(unsigned char **)(rsa)));
}
int i2d_RSAPrivateKey_bio(BIO *bp, RSA *rsa)
{
return(ASN1_i2d_bio(i2d_RSAPrivateKey,bp,(unsigned char *)rsa));
}
RSA *d2i_RSAPublicKey_bio(BIO *bp, RSA **rsa)
{
return((RSA *)ASN1_d2i_bio((char *(*)())
RSA_new,(char *(*)())d2i_RSAPublicKey, (bp),
(unsigned char **)(rsa)));
}
int i2d_RSAPublicKey_bio(BIO *bp, RSA *rsa)
{
return(ASN1_i2d_bio(i2d_RSAPublicKey,bp,(unsigned char *)rsa));
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
X509_ALGOR *X509_ALGOR_dup(X509_ALGOR *xn)
{
return((X509_ALGOR *)ASN1_dup((int (*)())i2d_X509_ALGOR,
(char *(*)())d2i_X509_ALGOR,(char *)xn));
}
X509_NAME *X509_NAME_dup(X509_NAME *xn)
{
return((X509_NAME *)ASN1_dup((int (*)())i2d_X509_NAME,
(char *(*)())d2i_X509_NAME,(char *)xn));
}
X509_NAME_ENTRY *X509_NAME_ENTRY_dup(X509_NAME_ENTRY *ne)
{
return((X509_NAME_ENTRY *)ASN1_dup((int (*)())i2d_X509_NAME_ENTRY,
(char *(*)())d2i_X509_NAME_ENTRY,(char *)ne));
}
int X509_digest(X509 *data, EVP_MD *type, unsigned char *md,
unsigned int *len)
{
return(ASN1_digest((int (*)())i2d_X509,type,(char *)data,md,len));
}
int X509_NAME_digest(X509_NAME *data, EVP_MD *type, unsigned char *md,
unsigned int *len)
{
return(ASN1_digest((int (*)())i2d_X509_NAME,type,(char *)data,md,len));
}
int PKCS7_ISSUER_AND_SERIAL_digest(PKCS7_ISSUER_AND_SERIAL *data, EVP_MD *type,
unsigned char *md, unsigned int *len)
{
return(ASN1_digest((int (*)())i2d_PKCS7_ISSUER_AND_SERIAL,type,
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
