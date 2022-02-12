int main(int argc, char **argv)
{
BIO *bio_err;
X509 *x509=NULL;
EVP_PKEY *pkey=NULL;
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ON);
bio_err=BIO_new_fp(stderr, BIO_NOCLOSE);
mkcert(&x509,&pkey,512,0,365);
RSA_print_fp(stdout,pkey->pkey.rsa,0);
X509_print_fp(stdout,x509);
PEM_write_PrivateKey(stdout,pkey,NULL,NULL,0,NULL, NULL);
PEM_write_X509(stdout,x509);
X509_free(x509);
EVP_PKEY_free(pkey);
ENGINE_cleanup();
CRYPTO_cleanup_all_ex_data();
CRYPTO_mem_leaks(bio_err);
BIO_free(bio_err);
return(0);
}
static void callback(int p, int n, void *arg)
{
char c='B';
if (p == 0) c='.';
if (p == 1) c='+';
if (p == 2) c='*';
if (p == 3) c='\n';
fputc(c,stderr);
}
int mkcert(X509 **x509p, EVP_PKEY **pkeyp, int bits, int serial, int days)
{
X509 *x;
EVP_PKEY *pk;
RSA *rsa;
X509_NAME *name=NULL;
if ((pkeyp == NULL) || (*pkeyp == NULL))
{
if ((pk=EVP_PKEY_new()) == NULL)
{
abort();
return(0);
}
}
else
pk= *pkeyp;
if ((x509p == NULL) || (*x509p == NULL))
{
if ((x=X509_new()) == NULL)
goto err;
}
else
x= *x509p;
rsa=RSA_generate_key(bits,RSA_F4,callback,NULL);
if (!EVP_PKEY_assign_RSA(pk,rsa))
{
abort();
goto err;
}
rsa=NULL;
X509_set_version(x,2);
ASN1_INTEGER_set(X509_get_serialNumber(x),serial);
X509_gmtime_adj(X509_get_notBefore(x),0);
X509_gmtime_adj(X509_get_notAfter(x),(long)60*60*24*days);
X509_set_pubkey(x,pk);
name=X509_get_subject_name(x);
X509_NAME_add_entry_by_txt(name,"C",
MBSTRING_ASC, "UK", -1, -1, 0);
X509_NAME_add_entry_by_txt(name,"CN",
MBSTRING_ASC, "OpenSSL Group", -1, -1, 0);
X509_set_issuer_name(x,name);
add_ext(x, NID_basic_constraints, "critical,CA:TRUE");
add_ext(x, NID_key_usage, "critical,keyCertSign,cRLSign");
add_ext(x, NID_subject_key_identifier, "hash");
add_ext(x, NID_netscape_cert_type, "sslCA");
add_ext(x, NID_netscape_comment, "example comment extension");
#ifdef CUSTOM_EXT
{
int nid;
nid = OBJ_create("1.2.3.4", "MyAlias", "My Test Alias Extension");
X509V3_EXT_add_alias(nid, NID_netscape_comment);
add_ext(x, nid, "example comment alias");
}
#endif
if (!X509_sign(x,pk,EVP_md5()))
goto err;
*x509p=x;
*pkeyp=pk;
return(1);
err:
return(0);
}
int add_ext(X509 *cert, int nid, char *value)
{
X509_EXTENSION *ex;
X509V3_CTX ctx;
X509V3_set_ctx_nodb(&ctx);
X509V3_set_ctx(&ctx, cert, cert, NULL, NULL, 0);
ex = X509V3_EXT_conf_nid(NULL, &ctx, nid, value);
if (!ex)
return 0;
X509_add_ext(cert,ex,-1);
X509_EXTENSION_free(ex);
return 1;
}
