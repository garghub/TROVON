int main(argc,argv)
int argc;
char *argv[];
{
char *keyfile=NULL;
BIO *in;
EVP_PKEY *pkey;
X509 *x509;
PKCS7 *p7;
PKCS7_SIGNER_INFO *si;
X509_STORE_CTX cert_ctx;
X509_STORE *cert_store=NULL;
BIO *data,*detached=NULL,*p7bio=NULL;
char buf[1024*4];
unsigned char *pp;
int i,printit=0;
STACK_OF(PKCS7_SIGNER_INFO) *sk;
OpenSSL_add_all_algorithms();
bio_err=BIO_new_fp(stderr,BIO_NOCLOSE);
data=BIO_new(BIO_s_file());
pp=NULL;
while (argc > 1)
{
argc--;
argv++;
if (strcmp(argv[0],"-p") == 0)
{
printit=1;
}
else if ((strcmp(argv[0],"-k") == 0) && (argc >= 2)) {
keyfile = argv[1];
argc-=1;
argv+=1;
} else if ((strcmp(argv[0],"-d") == 0) && (argc >= 2))
{
detached=BIO_new(BIO_s_file());
if (!BIO_read_filename(detached,argv[1]))
goto err;
argc-=1;
argv+=1;
}
else break;
}
if (!BIO_read_filename(data,argv[0])) goto err;
if(!keyfile) {
fprintf(stderr, "No private key file specified\n");
goto err;
}
if ((in=BIO_new_file(keyfile,"r")) == NULL) goto err;
if ((x509=PEM_read_bio_X509(in,NULL,NULL,NULL)) == NULL) goto err;
BIO_reset(in);
if ((pkey=PEM_read_bio_PrivateKey(in,NULL,NULL,NULL)) == NULL)
goto err;
BIO_free(in);
if (pp == NULL)
BIO_set_fp(data,stdin,BIO_NOCLOSE);
if ((p7=PEM_read_bio_PKCS7(data,NULL,NULL,NULL)) == NULL) goto err;
cert_store=X509_STORE_new();
X509_STORE_set_default_paths(cert_store);
X509_STORE_load_locations(cert_store,NULL,"../../certs");
X509_STORE_set_verify_cb_func(cert_store,verify_callback);
ERR_clear_error();
p7bio=PKCS7_dataDecode(p7,pkey,detached,x509);
if (p7bio == NULL)
{
printf("problems decoding\n");
goto err;
}
for (;;)
{
i=BIO_read(p7bio,buf,sizeof(buf));
if (i <= 0) break;
fwrite(buf,1, i, stdout);
}
sk=PKCS7_get_signer_info(p7);
if (sk == NULL)
{
fprintf(stderr, "there are no signatures on this data\n");
}
else
{
ERR_clear_error();
for (i=0; i<sk_PKCS7_SIGNER_INFO_num(sk); i++)
{
si=sk_PKCS7_SIGNER_INFO_value(sk,i);
i=PKCS7_dataVerify(cert_store,&cert_ctx,p7bio,p7,si);
if (i <= 0)
goto err;
else
fprintf(stderr,"Signature verified\n");
}
}
X509_STORE_free(cert_store);
exit(0);
err:
ERR_load_crypto_strings();
ERR_print_errors_fp(stderr);
exit(1);
}
int verify_callback(int ok, X509_STORE_CTX *ctx)
{
char buf[256];
X509 *err_cert;
int err,depth;
err_cert=X509_STORE_CTX_get_current_cert(ctx);
err= X509_STORE_CTX_get_error(ctx);
depth= X509_STORE_CTX_get_error_depth(ctx);
X509_NAME_oneline(X509_get_subject_name(err_cert),buf,256);
BIO_printf(bio_err,"depth=%d %s\n",depth,buf);
if (!ok)
{
BIO_printf(bio_err,"verify error:num=%d:%s\n",err,
X509_verify_cert_error_string(err));
if (depth < 6)
{
ok=1;
X509_STORE_CTX_set_error(ctx,X509_V_OK);
}
else
{
ok=0;
X509_STORE_CTX_set_error(ctx,X509_V_ERR_CERT_CHAIN_TOO_LONG);
}
}
switch (ctx->error)
{
case X509_V_ERR_UNABLE_TO_GET_ISSUER_CERT:
X509_NAME_oneline(X509_get_issuer_name(ctx->current_cert),buf,256);
BIO_printf(bio_err,"issuer= %s\n",buf);
break;
case X509_V_ERR_CERT_NOT_YET_VALID:
case X509_V_ERR_ERROR_IN_CERT_NOT_BEFORE_FIELD:
BIO_printf(bio_err,"notBefore=");
ASN1_UTCTIME_print(bio_err,X509_get_notBefore(ctx->current_cert));
BIO_printf(bio_err,"\n");
break;
case X509_V_ERR_CERT_HAS_EXPIRED:
case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
BIO_printf(bio_err,"notAfter=");
ASN1_UTCTIME_print(bio_err,X509_get_notAfter(ctx->current_cert));
BIO_printf(bio_err,"\n");
break;
}
BIO_printf(bio_err,"verify return:%d\n",ok);
return(ok);
}
