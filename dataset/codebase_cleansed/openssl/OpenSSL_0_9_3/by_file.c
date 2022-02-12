X509_LOOKUP_METHOD *X509_LOOKUP_file(void)
{
return(&x509_file_lookup);
}
static int by_file_ctrl(X509_LOOKUP *ctx, int cmd, const char *argp, long argl,
char **ret)
{
int ok=0,ok2=0;
char *file;
switch (cmd)
{
case X509_L_FILE_LOAD:
if (argl == X509_FILETYPE_DEFAULT)
{
ok=X509_load_cert_file(ctx,X509_get_default_cert_file(),
X509_FILETYPE_PEM);
ok2=X509_load_crl_file(ctx,X509_get_default_cert_file(),
X509_FILETYPE_PEM);
if (!ok || !ok2)
{
X509err(X509_F_BY_FILE_CTRL,X509_R_LOADING_DEFAULTS);
}
else
{
file=(char *)Getenv(X509_get_default_cert_file_env());
ok=X509_load_cert_file(ctx,file,
X509_FILETYPE_PEM);
ok2=X509_load_crl_file(ctx,file,
X509_FILETYPE_PEM);
}
}
else
{
ok=X509_load_cert_file(ctx,argp,(int)argl);
ok2=X509_load_crl_file(ctx,argp,(int)argl);
}
break;
}
return((ok && ok2)?ok:0);
}
int X509_load_cert_file(X509_LOOKUP *ctx, const char *file, int type)
{
int ret=0;
BIO *in=NULL;
int i,count=0;
X509 *x=NULL;
if (file == NULL) return(1);
in=BIO_new(BIO_s_file_internal());
if ((in == NULL) || (BIO_read_filename(in,file) <= 0))
{
X509err(X509_F_X509_LOAD_CERT_FILE,ERR_R_SYS_LIB);
goto err;
}
if (type == X509_FILETYPE_PEM)
{
for (;;)
{
x=PEM_read_bio_X509(in,NULL,NULL);
if (x == NULL)
{
if ((ERR_GET_REASON(ERR_peek_error()) ==
PEM_R_NO_START_LINE) && (count > 0))
{
ERR_clear_error();
break;
}
else
{
X509err(X509_F_X509_LOAD_CERT_FILE,
ERR_R_PEM_LIB);
goto err;
}
}
i=X509_STORE_add_cert(ctx->store_ctx,x);
if (!i) goto err;
count++;
X509_free(x);
x=NULL;
}
ret=count;
}
else if (type == X509_FILETYPE_ASN1)
{
x=d2i_X509_bio(in,NULL);
if (x == NULL)
{
X509err(X509_F_X509_LOAD_CERT_FILE,ERR_R_ASN1_LIB);
goto err;
}
i=X509_STORE_add_cert(ctx->store_ctx,x);
if (!i) goto err;
ret=i;
}
else
{
X509err(X509_F_X509_LOAD_CERT_FILE,X509_R_BAD_X509_FILETYPE);
goto err;
}
err:
if (x != NULL) X509_free(x);
if (in != NULL) BIO_free(in);
return(ret);
}
int X509_load_crl_file(X509_LOOKUP *ctx, const char *file, int type)
{
int ret=0;
BIO *in=NULL;
int i,count=0;
X509_CRL *x=NULL;
if (file == NULL) return(1);
in=BIO_new(BIO_s_file_internal());
if ((in == NULL) || (BIO_read_filename(in,file) <= 0))
{
X509err(X509_F_X509_LOAD_CRL_FILE,ERR_R_SYS_LIB);
goto err;
}
if (type == X509_FILETYPE_PEM)
{
for (;;)
{
x=PEM_read_bio_X509_CRL(in,NULL,NULL);
if (x == NULL)
{
if ((ERR_GET_REASON(ERR_peek_error()) ==
PEM_R_NO_START_LINE) && (count > 0))
{
ERR_clear_error();
break;
}
else
{
X509err(X509_F_X509_LOAD_CRL_FILE,
ERR_R_PEM_LIB);
goto err;
}
}
i=X509_STORE_add_crl(ctx->store_ctx,x);
if (!i) goto err;
count++;
X509_CRL_free(x);
x=NULL;
}
ret=count;
}
else if (type == X509_FILETYPE_ASN1)
{
x=d2i_X509_CRL_bio(in,NULL);
if (x == NULL)
{
X509err(X509_F_X509_LOAD_CRL_FILE,ERR_R_ASN1_LIB);
goto err;
}
i=X509_STORE_add_crl(ctx->store_ctx,x);
if (!i) goto err;
ret=i;
}
else
{
X509err(X509_F_X509_LOAD_CRL_FILE,X509_R_BAD_X509_FILETYPE);
goto err;
}
err:
if (x != NULL) X509_CRL_free(x);
if (in != NULL) BIO_free(in);
return(ret);
}
