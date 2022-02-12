int SSL_use_certificate(SSL *ssl, X509 *x)
{
if (x == NULL)
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (!ssl_cert_inst(&ssl->cert))
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE,ERR_R_MALLOC_FAILURE);
return(0);
}
return(ssl_set_cert(ssl->cert,x));
}
int SSL_use_certificate_file(SSL *ssl, const char *file, int type)
{
int j;
BIO *in;
int ret=0;
X509 *x=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE_FILE,ERR_R_SYS_LIB);
goto end;
}
if (type == SSL_FILETYPE_ASN1)
{
j=ERR_R_ASN1_LIB;
x=d2i_X509_bio(in,NULL);
}
else if (type == SSL_FILETYPE_PEM)
{
j=ERR_R_PEM_LIB;
x=PEM_read_bio_X509(in,NULL,ssl->ctx->default_passwd_callback,ssl->ctx->default_passwd_callback_userdata);
}
else
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE_FILE,SSL_R_BAD_SSL_FILETYPE);
goto end;
}
if (x == NULL)
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE_FILE,j);
goto end;
}
ret=SSL_use_certificate(ssl,x);
end:
if (x != NULL) X509_free(x);
if (in != NULL) BIO_free(in);
return(ret);
}
int SSL_use_certificate_ASN1(SSL *ssl, const unsigned char *d, int len)
{
X509 *x;
int ret;
x=d2i_X509(NULL,&d,(long)len);
if (x == NULL)
{
SSLerr(SSL_F_SSL_USE_CERTIFICATE_ASN1,ERR_R_ASN1_LIB);
return(0);
}
ret=SSL_use_certificate(ssl,x);
X509_free(x);
return(ret);
}
int SSL_use_RSAPrivateKey(SSL *ssl, RSA *rsa)
{
EVP_PKEY *pkey;
int ret;
if (rsa == NULL)
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (!ssl_cert_inst(&ssl->cert))
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY,ERR_R_MALLOC_FAILURE);
return(0);
}
if ((pkey=EVP_PKEY_new()) == NULL)
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY,ERR_R_EVP_LIB);
return(0);
}
RSA_up_ref(rsa);
EVP_PKEY_assign_RSA(pkey,rsa);
ret=ssl_set_pkey(ssl->cert,pkey);
EVP_PKEY_free(pkey);
return(ret);
}
static int ssl_set_pkey(CERT *c, EVP_PKEY *pkey)
{
int i;
i=ssl_cert_type(NULL,pkey);
if (i < 0)
{
SSLerr(SSL_F_SSL_SET_PKEY,SSL_R_UNKNOWN_CERTIFICATE_TYPE);
return(0);
}
if (c->pkeys[i].x509 != NULL)
{
EVP_PKEY *pktmp;
pktmp = X509_get_pubkey(c->pkeys[i].x509);
EVP_PKEY_copy_parameters(pktmp,pkey);
EVP_PKEY_free(pktmp);
ERR_clear_error();
#ifndef OPENSSL_NO_RSA
if ((pkey->type == EVP_PKEY_RSA) &&
(RSA_flags(pkey->pkey.rsa) & RSA_METHOD_FLAG_NO_CHECK))
;
else
#endif
if (!X509_check_private_key(c->pkeys[i].x509,pkey))
{
X509_free(c->pkeys[i].x509);
c->pkeys[i].x509 = NULL;
return 0;
}
}
if (c->pkeys[i].privatekey != NULL)
EVP_PKEY_free(c->pkeys[i].privatekey);
CRYPTO_add(&pkey->references,1,CRYPTO_LOCK_EVP_PKEY);
c->pkeys[i].privatekey=pkey;
c->key= &(c->pkeys[i]);
c->valid=0;
return(1);
}
int SSL_use_RSAPrivateKey_file(SSL *ssl, const char *file, int type)
{
int j,ret=0;
BIO *in;
RSA *rsa=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY_FILE,ERR_R_SYS_LIB);
goto end;
}
if (type == SSL_FILETYPE_ASN1)
{
j=ERR_R_ASN1_LIB;
rsa=d2i_RSAPrivateKey_bio(in,NULL);
}
else if (type == SSL_FILETYPE_PEM)
{
j=ERR_R_PEM_LIB;
rsa=PEM_read_bio_RSAPrivateKey(in,NULL,
ssl->ctx->default_passwd_callback,ssl->ctx->default_passwd_callback_userdata);
}
else
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY_FILE,SSL_R_BAD_SSL_FILETYPE);
goto end;
}
if (rsa == NULL)
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY_FILE,j);
goto end;
}
ret=SSL_use_RSAPrivateKey(ssl,rsa);
RSA_free(rsa);
end:
if (in != NULL) BIO_free(in);
return(ret);
}
int SSL_use_RSAPrivateKey_ASN1(SSL *ssl, unsigned char *d, long len)
{
int ret;
const unsigned char *p;
RSA *rsa;
p=d;
if ((rsa=d2i_RSAPrivateKey(NULL,&p,(long)len)) == NULL)
{
SSLerr(SSL_F_SSL_USE_RSAPRIVATEKEY_ASN1,ERR_R_ASN1_LIB);
return(0);
}
ret=SSL_use_RSAPrivateKey(ssl,rsa);
RSA_free(rsa);
return(ret);
}
int SSL_use_PrivateKey(SSL *ssl, EVP_PKEY *pkey)
{
int ret;
if (pkey == NULL)
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (!ssl_cert_inst(&ssl->cert))
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY,ERR_R_MALLOC_FAILURE);
return(0);
}
ret=ssl_set_pkey(ssl->cert,pkey);
return(ret);
}
int SSL_use_PrivateKey_file(SSL *ssl, const char *file, int type)
{
int j,ret=0;
BIO *in;
EVP_PKEY *pkey=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY_FILE,ERR_R_SYS_LIB);
goto end;
}
if (type == SSL_FILETYPE_PEM)
{
j=ERR_R_PEM_LIB;
pkey=PEM_read_bio_PrivateKey(in,NULL,
ssl->ctx->default_passwd_callback,ssl->ctx->default_passwd_callback_userdata);
}
else if (type == SSL_FILETYPE_ASN1)
{
j = ERR_R_ASN1_LIB;
pkey = d2i_PrivateKey_bio(in,NULL);
}
else
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY_FILE,SSL_R_BAD_SSL_FILETYPE);
goto end;
}
if (pkey == NULL)
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY_FILE,j);
goto end;
}
ret=SSL_use_PrivateKey(ssl,pkey);
EVP_PKEY_free(pkey);
end:
if (in != NULL) BIO_free(in);
return(ret);
}
int SSL_use_PrivateKey_ASN1(int type, SSL *ssl, const unsigned char *d, long len)
{
int ret;
const unsigned char *p;
EVP_PKEY *pkey;
p=d;
if ((pkey=d2i_PrivateKey(type,NULL,&p,(long)len)) == NULL)
{
SSLerr(SSL_F_SSL_USE_PRIVATEKEY_ASN1,ERR_R_ASN1_LIB);
return(0);
}
ret=SSL_use_PrivateKey(ssl,pkey);
EVP_PKEY_free(pkey);
return(ret);
}
int SSL_CTX_use_certificate(SSL_CTX *ctx, X509 *x)
{
if (x == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (!ssl_cert_inst(&ctx->cert))
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE,ERR_R_MALLOC_FAILURE);
return(0);
}
return(ssl_set_cert(ctx->cert, x));
}
static int ssl_set_cert(CERT *c, X509 *x)
{
EVP_PKEY *pkey;
int i;
pkey=X509_get_pubkey(x);
if (pkey == NULL)
{
SSLerr(SSL_F_SSL_SET_CERT,SSL_R_X509_LIB);
return(0);
}
i=ssl_cert_type(x,pkey);
if (i < 0)
{
SSLerr(SSL_F_SSL_SET_CERT,SSL_R_UNKNOWN_CERTIFICATE_TYPE);
EVP_PKEY_free(pkey);
return(0);
}
if (c->pkeys[i].privatekey != NULL)
{
EVP_PKEY_copy_parameters(pkey,c->pkeys[i].privatekey);
ERR_clear_error();
#ifndef OPENSSL_NO_RSA
if ((c->pkeys[i].privatekey->type == EVP_PKEY_RSA) &&
(RSA_flags(c->pkeys[i].privatekey->pkey.rsa) &
RSA_METHOD_FLAG_NO_CHECK))
;
else
#endif
if (!X509_check_private_key(x,c->pkeys[i].privatekey))
{
EVP_PKEY_free(c->pkeys[i].privatekey);
c->pkeys[i].privatekey=NULL;
ERR_clear_error();
}
}
EVP_PKEY_free(pkey);
if (c->pkeys[i].x509 != NULL)
X509_free(c->pkeys[i].x509);
CRYPTO_add(&x->references,1,CRYPTO_LOCK_X509);
c->pkeys[i].x509=x;
c->key= &(c->pkeys[i]);
c->valid=0;
return(1);
}
int SSL_CTX_use_certificate_file(SSL_CTX *ctx, const char *file, int type)
{
int j;
BIO *in;
int ret=0;
X509 *x=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_FILE,ERR_R_SYS_LIB);
goto end;
}
if (type == SSL_FILETYPE_ASN1)
{
j=ERR_R_ASN1_LIB;
x=d2i_X509_bio(in,NULL);
}
else if (type == SSL_FILETYPE_PEM)
{
j=ERR_R_PEM_LIB;
x=PEM_read_bio_X509(in,NULL,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata);
}
else
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_FILE,SSL_R_BAD_SSL_FILETYPE);
goto end;
}
if (x == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_FILE,j);
goto end;
}
ret=SSL_CTX_use_certificate(ctx,x);
end:
if (x != NULL) X509_free(x);
if (in != NULL) BIO_free(in);
return(ret);
}
int SSL_CTX_use_certificate_ASN1(SSL_CTX *ctx, int len, const unsigned char *d)
{
X509 *x;
int ret;
x=d2i_X509(NULL,&d,(long)len);
if (x == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_ASN1,ERR_R_ASN1_LIB);
return(0);
}
ret=SSL_CTX_use_certificate(ctx,x);
X509_free(x);
return(ret);
}
int SSL_CTX_use_RSAPrivateKey(SSL_CTX *ctx, RSA *rsa)
{
int ret;
EVP_PKEY *pkey;
if (rsa == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (!ssl_cert_inst(&ctx->cert))
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY,ERR_R_MALLOC_FAILURE);
return(0);
}
if ((pkey=EVP_PKEY_new()) == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY,ERR_R_EVP_LIB);
return(0);
}
RSA_up_ref(rsa);
EVP_PKEY_assign_RSA(pkey,rsa);
ret=ssl_set_pkey(ctx->cert, pkey);
EVP_PKEY_free(pkey);
return(ret);
}
int SSL_CTX_use_RSAPrivateKey_file(SSL_CTX *ctx, const char *file, int type)
{
int j,ret=0;
BIO *in;
RSA *rsa=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_FILE,ERR_R_SYS_LIB);
goto end;
}
if (type == SSL_FILETYPE_ASN1)
{
j=ERR_R_ASN1_LIB;
rsa=d2i_RSAPrivateKey_bio(in,NULL);
}
else if (type == SSL_FILETYPE_PEM)
{
j=ERR_R_PEM_LIB;
rsa=PEM_read_bio_RSAPrivateKey(in,NULL,
ctx->default_passwd_callback,ctx->default_passwd_callback_userdata);
}
else
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_FILE,SSL_R_BAD_SSL_FILETYPE);
goto end;
}
if (rsa == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_FILE,j);
goto end;
}
ret=SSL_CTX_use_RSAPrivateKey(ctx,rsa);
RSA_free(rsa);
end:
if (in != NULL) BIO_free(in);
return(ret);
}
int SSL_CTX_use_RSAPrivateKey_ASN1(SSL_CTX *ctx, const unsigned char *d, long len)
{
int ret;
const unsigned char *p;
RSA *rsa;
p=d;
if ((rsa=d2i_RSAPrivateKey(NULL,&p,(long)len)) == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_RSAPRIVATEKEY_ASN1,ERR_R_ASN1_LIB);
return(0);
}
ret=SSL_CTX_use_RSAPrivateKey(ctx,rsa);
RSA_free(rsa);
return(ret);
}
int SSL_CTX_use_PrivateKey(SSL_CTX *ctx, EVP_PKEY *pkey)
{
if (pkey == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY,ERR_R_PASSED_NULL_PARAMETER);
return(0);
}
if (!ssl_cert_inst(&ctx->cert))
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY,ERR_R_MALLOC_FAILURE);
return(0);
}
return(ssl_set_pkey(ctx->cert,pkey));
}
int SSL_CTX_use_PrivateKey_file(SSL_CTX *ctx, const char *file, int type)
{
int j,ret=0;
BIO *in;
EVP_PKEY *pkey=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY_FILE,ERR_R_SYS_LIB);
goto end;
}
if (type == SSL_FILETYPE_PEM)
{
j=ERR_R_PEM_LIB;
pkey=PEM_read_bio_PrivateKey(in,NULL,
ctx->default_passwd_callback,ctx->default_passwd_callback_userdata);
}
else if (type == SSL_FILETYPE_ASN1)
{
j = ERR_R_ASN1_LIB;
pkey = d2i_PrivateKey_bio(in,NULL);
}
else
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY_FILE,SSL_R_BAD_SSL_FILETYPE);
goto end;
}
if (pkey == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY_FILE,j);
goto end;
}
ret=SSL_CTX_use_PrivateKey(ctx,pkey);
EVP_PKEY_free(pkey);
end:
if (in != NULL) BIO_free(in);
return(ret);
}
int SSL_CTX_use_PrivateKey_ASN1(int type, SSL_CTX *ctx, const unsigned char *d,
long len)
{
int ret;
const unsigned char *p;
EVP_PKEY *pkey;
p=d;
if ((pkey=d2i_PrivateKey(type,NULL,&p,(long)len)) == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_PRIVATEKEY_ASN1,ERR_R_ASN1_LIB);
return(0);
}
ret=SSL_CTX_use_PrivateKey(ctx,pkey);
EVP_PKEY_free(pkey);
return(ret);
}
int SSL_CTX_use_certificate_chain_file(SSL_CTX *ctx, const char *file)
{
BIO *in;
int ret=0;
X509 *x=NULL;
in=BIO_new(BIO_s_file_internal());
if (in == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_CHAIN_FILE,ERR_R_BUF_LIB);
goto end;
}
if (BIO_read_filename(in,file) <= 0)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_CHAIN_FILE,ERR_R_SYS_LIB);
goto end;
}
x=PEM_read_bio_X509(in,NULL,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata);
if (x == NULL)
{
SSLerr(SSL_F_SSL_CTX_USE_CERTIFICATE_CHAIN_FILE,ERR_R_PEM_LIB);
goto end;
}
ret=SSL_CTX_use_certificate(ctx,x);
if (ERR_peek_error() != 0)
ret = 0;
if (ret)
{
X509 *ca;
int r;
unsigned long err;
if (ctx->extra_certs != NULL)
{
sk_X509_pop_free(ctx->extra_certs, X509_free);
ctx->extra_certs = NULL;
}
while ((ca = PEM_read_bio_X509(in,NULL,ctx->default_passwd_callback,ctx->default_passwd_callback_userdata))
!= NULL)
{
r = SSL_CTX_add_extra_chain_cert(ctx, ca);
if (!r)
{
X509_free(ca);
ret = 0;
goto end;
}
}
err = ERR_peek_last_error();
if (ERR_GET_LIB(err) == ERR_LIB_PEM && ERR_GET_REASON(err) == PEM_R_NO_START_LINE)
ERR_clear_error();
else
ret = 0;
}
end:
if (x != NULL) X509_free(x);
if (in != NULL) BIO_free(in);
return(ret);
}
