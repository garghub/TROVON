EVP_PKEY *PEM_read_bio_PrivateKey(BIO *bp, EVP_PKEY **x, pem_password_cb *cb, void *u)
{
char *nm=NULL;
const unsigned char *p=NULL;
unsigned char *data=NULL;
long len;
EVP_PKEY *ret=NULL;
if (!PEM_bytes_read_bio(&data, &len, &nm, PEM_STRING_EVP_PKEY, bp, cb, u))
return NULL;
p = data;
if (strcmp(nm,PEM_STRING_RSA) == 0)
ret=d2i_PrivateKey(EVP_PKEY_RSA,x,&p,len);
else if (strcmp(nm,PEM_STRING_DSA) == 0)
ret=d2i_PrivateKey(EVP_PKEY_DSA,x,&p,len);
else if (strcmp(nm,PEM_STRING_ECPRIVATEKEY) == 0)
ret=d2i_PrivateKey(EVP_PKEY_EC,x,&p,len);
else if (strcmp(nm,PEM_STRING_PKCS8INF) == 0) {
PKCS8_PRIV_KEY_INFO *p8inf;
p8inf=d2i_PKCS8_PRIV_KEY_INFO(NULL, &p, len);
if(!p8inf) goto p8err;
ret = EVP_PKCS82PKEY(p8inf);
if(x) {
if(*x) EVP_PKEY_free((EVP_PKEY *)*x);
*x = ret;
}
PKCS8_PRIV_KEY_INFO_free(p8inf);
} else if (strcmp(nm,PEM_STRING_PKCS8) == 0) {
PKCS8_PRIV_KEY_INFO *p8inf;
X509_SIG *p8;
int klen;
char psbuf[PEM_BUFSIZE];
p8 = d2i_X509_SIG(NULL, &p, len);
if(!p8) goto p8err;
if (cb) klen=cb(psbuf,PEM_BUFSIZE,0,u);
else klen=PEM_def_callback(psbuf,PEM_BUFSIZE,0,u);
if (klen <= 0) {
PEMerr(PEM_F_PEM_READ_BIO_PRIVATEKEY,
PEM_R_BAD_PASSWORD_READ);
X509_SIG_free(p8);
goto err;
}
p8inf = PKCS8_decrypt(p8, psbuf, klen);
X509_SIG_free(p8);
if(!p8inf) goto p8err;
ret = EVP_PKCS82PKEY(p8inf);
if(x) {
if(*x) EVP_PKEY_free((EVP_PKEY *)*x);
*x = ret;
}
PKCS8_PRIV_KEY_INFO_free(p8inf);
}
p8err:
if (ret == NULL)
PEMerr(PEM_F_PEM_READ_BIO_PRIVATEKEY,ERR_R_ASN1_LIB);
err:
OPENSSL_free(nm);
OPENSSL_free(data);
return(ret);
}
EVP_PKEY *PEM_read_PrivateKey(FILE *fp, EVP_PKEY **x, pem_password_cb *cb, void *u)
{
BIO *b;
EVP_PKEY *ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
PEMerr(PEM_F_PEM_READ_PRIVATEKEY,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=PEM_read_bio_PrivateKey(b,x,cb,u);
BIO_free(b);
return(ret);
}
