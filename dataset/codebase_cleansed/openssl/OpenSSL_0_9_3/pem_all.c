X509 *PEM_read_X509(FILE *fp, X509 **x, pem_password_cb *cb)
{
return((X509 *)PEM_ASN1_read((char *(*)())d2i_X509,
PEM_STRING_X509,fp,(char **)x,cb));
}
X509 *PEM_read_bio_X509(BIO *bp, X509 **x, pem_password_cb *cb)
{
return((X509 *)PEM_ASN1_read_bio((char *(*)())d2i_X509,
PEM_STRING_X509,bp,(char **)x,cb));
}
int PEM_write_X509(FILE *fp, X509 *x)
{
return(PEM_ASN1_write((int (*)())i2d_X509,PEM_STRING_X509,fp,
(char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_X509(BIO *bp, X509 *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_X509,PEM_STRING_X509,bp,
(char *)x, NULL,NULL,0,NULL));
}
X509_REQ *PEM_read_X509_REQ(FILE *fp, X509_REQ **x, pem_password_cb *cb)
{
return((X509_REQ *)PEM_ASN1_read((char *(*)())d2i_X509_REQ,
PEM_STRING_X509_REQ,fp,(char **)x,cb));
}
X509_REQ *PEM_read_bio_X509_REQ(BIO *bp, X509_REQ **x, pem_password_cb *cb)
{
return((X509_REQ *)PEM_ASN1_read_bio((char *(*)())d2i_X509_REQ,
PEM_STRING_X509_REQ,bp,(char **)x,cb));
}
int PEM_write_X509_REQ(FILE *fp, X509_REQ *x)
{
return(PEM_ASN1_write((int (*)())i2d_X509_REQ,PEM_STRING_X509_REQ,fp,
(char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_X509_REQ(BIO *bp, X509_REQ *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_X509_REQ,PEM_STRING_X509_REQ,
bp,(char *)x, NULL,NULL,0,NULL));
}
X509_CRL *PEM_read_X509_CRL(FILE *fp, X509_CRL **x, pem_password_cb *cb)
{
return((X509_CRL *)PEM_ASN1_read((char *(*)())d2i_X509_CRL,
PEM_STRING_X509_CRL,fp,(char **)x,cb));
}
X509_CRL *PEM_read_bio_X509_CRL(BIO *bp, X509_CRL **x, pem_password_cb *cb)
{
return((X509_CRL *)PEM_ASN1_read_bio((char *(*)())d2i_X509_CRL,
PEM_STRING_X509_CRL,bp,(char **)x,cb));
}
int PEM_write_X509_CRL(FILE *fp, X509_CRL *x)
{
return(PEM_ASN1_write((int (*)())i2d_X509_CRL,PEM_STRING_X509_CRL,fp,
(char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_X509_CRL(BIO *bp, X509_CRL *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_X509_CRL,PEM_STRING_X509_CRL,
bp,(char *)x, NULL,NULL,0,NULL));
}
RSA *PEM_read_RSAPrivateKey(FILE *fp, RSA **x, pem_password_cb *cb)
{
return((RSA *)PEM_ASN1_read((char *(*)())d2i_RSAPrivateKey,
PEM_STRING_RSA,fp,(char **)x,cb));
}
RSA *PEM_read_RSAPublicKey(FILE *fp, RSA **x, pem_password_cb *cb)
{
return((RSA *)PEM_ASN1_read((char *(*)())d2i_RSAPublicKey,
PEM_STRING_RSA_PUBLIC,fp,(char **)x,cb));
}
RSA *PEM_read_bio_RSAPrivateKey(BIO *bp, RSA **x, pem_password_cb *cb)
{
return((RSA *)PEM_ASN1_read_bio((char *(*)())d2i_RSAPrivateKey,
PEM_STRING_RSA,bp,(char **)x,cb));
}
RSA *PEM_read_bio_RSAPublicKey(BIO *bp, RSA **x, pem_password_cb *cb)
{
return((RSA *)PEM_ASN1_read_bio((char *(*)())d2i_RSAPublicKey,
PEM_STRING_RSA_PUBLIC,bp,(char **)x,cb));
}
int PEM_write_RSAPrivateKey(FILE *fp, RSA *x, EVP_CIPHER *enc,
unsigned char *kstr, int klen, pem_password_cb *cb)
{
return(PEM_ASN1_write((int (*)())i2d_RSAPrivateKey,PEM_STRING_RSA,fp,
(char *)x,enc,kstr,klen,cb));
}
int PEM_write_RSAPublicKey(FILE *fp, RSA *x)
{
return(PEM_ASN1_write((int (*)())i2d_RSAPublicKey,
PEM_STRING_RSA_PUBLIC,fp,
(char *)x,NULL,NULL,0,NULL));
}
int PEM_write_bio_RSAPrivateKey(BIO *bp, RSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen, pem_password_cb *cb)
{
return(PEM_ASN1_write_bio((int (*)())i2d_RSAPrivateKey,PEM_STRING_RSA,
bp,(char *)x,enc,kstr,klen,cb));
}
int PEM_write_bio_RSAPublicKey(BIO *bp, RSA *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_RSAPublicKey,
PEM_STRING_RSA_PUBLIC,
bp,(char *)x,NULL,NULL,0,NULL));
}
DSA *PEM_read_DSAPrivateKey(FILE *fp, DSA **x, pem_password_cb *cb)
{
return((DSA *)PEM_ASN1_read((char *(*)())d2i_DSAPrivateKey,
PEM_STRING_DSA,fp,(char **)x,cb));
}
DSA *PEM_read_bio_DSAPrivateKey(BIO *bp, DSA **x, pem_password_cb *cb)
{
return((DSA *)PEM_ASN1_read_bio((char *(*)())d2i_DSAPrivateKey,
PEM_STRING_DSA,bp,(char **)x,cb));
}
int PEM_write_DSAPrivateKey(FILE *fp, DSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen, pem_password_cb *cb)
{
return(PEM_ASN1_write((int (*)())i2d_DSAPrivateKey,PEM_STRING_DSA,fp,
(char *)x,enc,kstr,klen,cb));
}
int PEM_write_bio_DSAPrivateKey(BIO *bp, DSA *x, const EVP_CIPHER *enc,
unsigned char *kstr, int klen, pem_password_cb *cb)
{
return(PEM_ASN1_write_bio((int (*)())i2d_DSAPrivateKey,PEM_STRING_DSA,
bp,(char *)x,enc,kstr,klen,cb));
}
EVP_PKEY *PEM_read_PrivateKey(FILE *fp, EVP_PKEY **x, pem_password_cb *cb)
{
return((EVP_PKEY *)PEM_ASN1_read((char *(*)())d2i_PrivateKey,
PEM_STRING_EVP_PKEY,fp,(char **)x,cb));
}
EVP_PKEY *PEM_read_bio_PrivateKey(BIO *bp, EVP_PKEY **x, pem_password_cb *cb)
{
return((EVP_PKEY *)PEM_ASN1_read_bio((char *(*)())d2i_PrivateKey,
PEM_STRING_EVP_PKEY,bp,(char **)x,cb));
}
int PEM_write_PrivateKey(FILE *fp, EVP_PKEY *x, EVP_CIPHER *enc,
unsigned char *kstr, int klen, pem_password_cb *cb)
{
return(PEM_ASN1_write((int (*)())i2d_PrivateKey,
((x->type == EVP_PKEY_DSA)?PEM_STRING_DSA:PEM_STRING_RSA),
fp,(char *)x,enc,kstr,klen,cb));
}
int PEM_write_bio_PrivateKey(BIO *bp, EVP_PKEY *x, EVP_CIPHER *enc,
unsigned char *kstr, int klen, pem_password_cb *cb)
{
return(PEM_ASN1_write_bio((int (*)())i2d_PrivateKey,
((x->type == EVP_PKEY_DSA)?PEM_STRING_DSA:PEM_STRING_RSA),
bp,(char *)x,enc,kstr,klen,cb));
}
PKCS7 *PEM_read_PKCS7(FILE *fp, PKCS7 **x, pem_password_cb *cb)
{
return((PKCS7 *)PEM_ASN1_read((char *(*)())d2i_PKCS7,
PEM_STRING_PKCS7,fp,(char **)x,cb));
}
PKCS7 *PEM_read_bio_PKCS7(BIO *bp, PKCS7 **x, pem_password_cb *cb)
{
return((PKCS7 *)PEM_ASN1_read_bio((char *(*)())d2i_PKCS7,
PEM_STRING_PKCS7,bp,(char **)x,cb));
}
int PEM_write_PKCS7(FILE *fp, PKCS7 *x)
{
return(PEM_ASN1_write((int (*)())i2d_PKCS7,PEM_STRING_PKCS7,fp,
(char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_PKCS7(BIO *bp, PKCS7 *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_PKCS7,PEM_STRING_PKCS7,bp,
(char *)x, NULL,NULL,0,NULL));
}
DH *PEM_read_DHparams(FILE *fp, DH **x, pem_password_cb *cb)
{
return((DH *)PEM_ASN1_read((char *(*)())d2i_DHparams,
PEM_STRING_DHPARAMS,fp,(char **)x,cb));
}
DH *PEM_read_bio_DHparams(BIO *bp, DH **x, pem_password_cb *cb)
{
return((DH *)PEM_ASN1_read_bio((char *(*)())d2i_DHparams,
PEM_STRING_DHPARAMS,bp,(char **)x,cb));
}
int PEM_write_DHparams(FILE *fp, DH *x)
{
return(PEM_ASN1_write((int (*)())i2d_DHparams,PEM_STRING_DHPARAMS,fp,
(char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_DHparams(BIO *bp, DH *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_DHparams,PEM_STRING_DHPARAMS,
bp,(char *)x, NULL,NULL,0,NULL));
}
DSA *PEM_read_DSAparams(FILE *fp, DSA **x, pem_password_cb *cb)
{
return((DSA *)PEM_ASN1_read((char *(*)())d2i_DSAparams,
PEM_STRING_DSAPARAMS,fp,(char **)x,cb));
}
DSA *PEM_read_bio_DSAparams(BIO *bp, DSA **x, pem_password_cb *cb)
{
return((DSA *)PEM_ASN1_read_bio((char *(*)())d2i_DSAparams,
PEM_STRING_DSAPARAMS,bp,(char **)x,cb));
}
int PEM_write_DSAparams(FILE *fp, DSA *x)
{
return(PEM_ASN1_write((int (*)())i2d_DSAparams,PEM_STRING_DSAPARAMS,fp,
(char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_DSAparams(BIO *bp, DSA *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_DSAparams,PEM_STRING_DSAPARAMS,
bp,(char *)x, NULL,NULL,0,NULL));
}
NETSCAPE_CERT_SEQUENCE *PEM_read_NETSCAPE_CERT_SEQUENCE(FILE *fp,
NETSCAPE_CERT_SEQUENCE **x, pem_password_cb *cb)
{
return((NETSCAPE_CERT_SEQUENCE *)
PEM_ASN1_read((char *(*)())d2i_NETSCAPE_CERT_SEQUENCE,
PEM_STRING_X509,fp,(char **)x,cb));
}
NETSCAPE_CERT_SEQUENCE *PEM_read_bio_NETSCAPE_CERT_SEQUENCE(BIO *bp,
NETSCAPE_CERT_SEQUENCE **x, pem_password_cb *cb)
{
return((NETSCAPE_CERT_SEQUENCE *)
PEM_ASN1_read_bio((char *(*)())d2i_NETSCAPE_CERT_SEQUENCE,
PEM_STRING_X509,bp,(char **)x,cb));
}
int PEM_write_NETSCAPE_CERT_SEQUENCE(FILE *fp, NETSCAPE_CERT_SEQUENCE *x)
{
return(PEM_ASN1_write((int (*)())i2d_NETSCAPE_CERT_SEQUENCE,
PEM_STRING_X509,fp, (char *)x, NULL,NULL,0,NULL));
}
int PEM_write_bio_NETSCAPE_CERT_SEQUENCE(BIO *bp, NETSCAPE_CERT_SEQUENCE *x)
{
return(PEM_ASN1_write_bio((int (*)())i2d_NETSCAPE_CERT_SEQUENCE,
PEM_STRING_X509,bp, (char *)x, NULL,NULL,0,NULL));
}
