int MS_CALLBACK verify_callback(int ok, X509_STORE_CTX *ctx)
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
if (verify_depth >= depth)
{
ok=1;
verify_error=X509_V_OK;
}
else
{
ok=0;
verify_error=X509_V_ERR_CERT_CHAIN_TOO_LONG;
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
ASN1_TIME_print(bio_err,X509_get_notBefore(ctx->current_cert));
BIO_printf(bio_err,"\n");
break;
case X509_V_ERR_CERT_HAS_EXPIRED:
case X509_V_ERR_ERROR_IN_CERT_NOT_AFTER_FIELD:
BIO_printf(bio_err,"notAfter=");
ASN1_TIME_print(bio_err,X509_get_notAfter(ctx->current_cert));
BIO_printf(bio_err,"\n");
break;
}
BIO_printf(bio_err,"verify return:%d\n",ok);
return(ok);
}
int set_cert_stuff(SSL_CTX *ctx, char *cert_file, char *key_file)
{
if (cert_file != NULL)
{
if (SSL_CTX_use_certificate_file(ctx,cert_file,
SSL_FILETYPE_PEM) <= 0)
{
BIO_printf(bio_err,"unable to get certificate from '%s'\n",cert_file);
ERR_print_errors(bio_err);
return(0);
}
if (key_file == NULL) key_file=cert_file;
if (SSL_CTX_use_PrivateKey_file(ctx,key_file,
SSL_FILETYPE_PEM) <= 0)
{
BIO_printf(bio_err,"unable to get private key from '%s'\n",key_file);
ERR_print_errors(bio_err);
return(0);
}
if (!SSL_CTX_check_private_key(ctx))
{
BIO_printf(bio_err,"Private key does not match the certificate public key\n");
return(0);
}
}
return(1);
}
long MS_CALLBACK bio_dump_cb(BIO *bio, int cmd, const char *argp, int argi,
long argl, long ret)
{
BIO *out;
out=(BIO *)BIO_get_callback_arg(bio);
if (out == NULL) return(ret);
if (cmd == (BIO_CB_READ|BIO_CB_RETURN))
{
BIO_printf(out,"read from %08X [%08lX] (%d bytes => %ld (0x%X))\n",
bio,argp,argi,ret,ret);
BIO_dump(out,argp,(int)ret);
return(ret);
}
else if (cmd == (BIO_CB_WRITE|BIO_CB_RETURN))
{
BIO_printf(out,"write to %08X [%08lX] (%d bytes => %ld (0x%X))\n",
bio,argp,argi,ret,ret);
BIO_dump(out,argp,(int)ret);
}
return(ret);
}
void MS_CALLBACK apps_ssl_info_callback(SSL *s, int where, int ret)
{
char *str;
int w;
w=where& ~SSL_ST_MASK;
if (w & SSL_ST_CONNECT) str="SSL_connect";
else if (w & SSL_ST_ACCEPT) str="SSL_accept";
else str="undefined";
if (where & SSL_CB_LOOP)
{
BIO_printf(bio_err,"%s:%s\n",str,SSL_state_string_long(s));
}
else if (where & SSL_CB_ALERT)
{
str=(where & SSL_CB_READ)?"read":"write";
BIO_printf(bio_err,"SSL3 alert %s:%s:%s\n",
str,
SSL_alert_type_string_long(ret),
SSL_alert_desc_string_long(ret));
}
else if (where & SSL_CB_EXIT)
{
if (ret == 0)
BIO_printf(bio_err,"%s:failed in %s\n",
str,SSL_state_string_long(s));
else if (ret < 0)
{
BIO_printf(bio_err,"%s:error in %s\n",
str,SSL_state_string_long(s));
}
}
}
