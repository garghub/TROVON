int SSL_SESSION_print_fp(FILE *fp, SSL_SESSION *x)
{
BIO *b;
int ret;
if ((b=BIO_new(BIO_s_file_internal())) == NULL)
{
SSLerr(SSL_F_SSL_SESSION_PRINT_FP,ERR_R_BUF_LIB);
return(0);
}
BIO_set_fp(b,fp,BIO_NOCLOSE);
ret=SSL_SESSION_print(b,x);
BIO_free(b);
return(ret);
}
int SSL_SESSION_print(BIO *bp, SSL_SESSION *x)
{
unsigned int i;
char str[128],*s;
if (x == NULL) goto err;
if (BIO_puts(bp,"SSL-Session:\n") <= 0) goto err;
if (x->ssl_version == SSL2_VERSION)
s="SSLv2";
else if (x->ssl_version == SSL3_VERSION)
s="SSLv3";
else if (x->ssl_version == TLS1_VERSION)
s="TLSv1";
else
s="unknown";
sprintf(str," Protocol : %s\n",s);
if (BIO_puts(bp,str) <= 0) goto err;
if (x->cipher == NULL)
{
if (((x->cipher_id) & 0xff000000) == 0x02000000)
sprintf(str," Cipher : %06lX\n",x->cipher_id&0xffffff);
else
sprintf(str," Cipher : %04lX\n",x->cipher_id&0xffff);
}
else
sprintf(str," Cipher : %s\n",(x->cipher == NULL)?"unknown":x->cipher->name);
if (BIO_puts(bp,str) <= 0) goto err;
if (BIO_puts(bp," Session-ID: ") <= 0) goto err;
for (i=0; i<x->session_id_length; i++)
{
sprintf(str,"%02X",x->session_id[i]);
if (BIO_puts(bp,str) <= 0) goto err;
}
if (BIO_puts(bp,"\n Session-ID-ctx: ") <= 0) goto err;
for (i=0; i<x->sid_ctx_length; i++)
{
sprintf(str,"%02X",x->sid_ctx[i]);
if (BIO_puts(bp,str) <= 0) goto err;
}
if (BIO_puts(bp,"\n Master-Key: ") <= 0) goto err;
for (i=0; i<(unsigned int)x->master_key_length; i++)
{
sprintf(str,"%02X",x->master_key[i]);
if (BIO_puts(bp,str) <= 0) goto err;
}
if (BIO_puts(bp,"\n Key-Arg : ") <= 0) goto err;
if (x->key_arg_length == 0)
{
if (BIO_puts(bp,"None") <= 0) goto err;
}
else
for (i=0; i<x->key_arg_length; i++)
{
sprintf(str,"%02X",x->key_arg[i]);
if (BIO_puts(bp,str) <= 0) goto err;
}
if (x->compress_meth != 0)
{
SSL_COMP *comp;
ssl_cipher_get_evp(x,NULL,NULL,&comp);
if (comp == NULL)
{
sprintf(str,"\n Compression: %d",x->compress_meth);
if (BIO_puts(bp,str) <= 0) goto err;
}
else
{
sprintf(str,"\n Compression: %d (%s)",
comp->id,comp->method->name);
if (BIO_puts(bp,str) <= 0) goto err;
}
}
if (x->time != 0L)
{
sprintf(str,"\n Start Time: %ld",x->time);
if (BIO_puts(bp,str) <= 0) goto err;
}
if (x->timeout != 0L)
{
sprintf(str,"\n Timeout : %ld (sec)",x->timeout);
if (BIO_puts(bp,str) <= 0) goto err;
}
if (BIO_puts(bp,"\n") <= 0) goto err;
if (BIO_puts(bp, " Verify return code ") <= 0) goto err;
sprintf(str, "%ld (%s)\n", x->verify_result,
X509_verify_cert_error_string(x->verify_result));
if (BIO_puts(bp,str) <= 0) goto err;
return(1);
err:
return(0);
}
