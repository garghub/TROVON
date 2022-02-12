int SSL_SESSION_print_fp(FILE *fp, const SSL_SESSION *x)
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
int SSL_SESSION_print(BIO *bp, const SSL_SESSION *x)
{
unsigned int i;
const char *s;
if (x == NULL) goto err;
if (BIO_puts(bp,"SSL-Session:\n") <= 0) goto err;
if (x->ssl_version == SSL2_VERSION)
s="SSLv2";
else if (x->ssl_version == SSL3_VERSION)
s="SSLv3";
else if (x->ssl_version == TLS1_VERSION)
s="TLSv1";
else if (x->ssl_version == DTLS1_VERSION)
s="DTLSv1";
else if (x->ssl_version == DTLS1_BAD_VER)
s="DTLSv1-bad";
else
s="unknown";
if (BIO_printf(bp," Protocol : %s\n",s) <= 0) goto err;
if (x->cipher == NULL)
{
if (((x->cipher_id) & 0xff000000) == 0x02000000)
{
if (BIO_printf(bp," Cipher : %06lX\n",x->cipher_id&0xffffff) <= 0)
goto err;
}
else
{
if (BIO_printf(bp," Cipher : %04lX\n",x->cipher_id&0xffff) <= 0)
goto err;
}
}
else
{
if (BIO_printf(bp," Cipher : %s\n",((x->cipher == NULL)?"unknown":x->cipher->name)) <= 0)
goto err;
}
if (BIO_puts(bp," Session-ID: ") <= 0) goto err;
for (i=0; i<x->session_id_length; i++)
{
if (BIO_printf(bp,"%02X",x->session_id[i]) <= 0) goto err;
}
if (BIO_puts(bp,"\n Session-ID-ctx: ") <= 0) goto err;
for (i=0; i<x->sid_ctx_length; i++)
{
if (BIO_printf(bp,"%02X",x->sid_ctx[i]) <= 0)
goto err;
}
if (BIO_puts(bp,"\n Master-Key: ") <= 0) goto err;
for (i=0; i<(unsigned int)x->master_key_length; i++)
{
if (BIO_printf(bp,"%02X",x->master_key[i]) <= 0) goto err;
}
if (BIO_puts(bp,"\n Key-Arg : ") <= 0) goto err;
if (x->key_arg_length == 0)
{
if (BIO_puts(bp,"None") <= 0) goto err;
}
else
for (i=0; i<x->key_arg_length; i++)
{
if (BIO_printf(bp,"%02X",x->key_arg[i]) <= 0) goto err;
}
#ifndef OPENSSL_NO_KRB5
if (BIO_puts(bp,"\n Krb5 Principal: ") <= 0) goto err;
if (x->krb5_client_princ_len == 0)
{
if (BIO_puts(bp,"None") <= 0) goto err;
}
else
for (i=0; i<x->krb5_client_princ_len; i++)
{
if (BIO_printf(bp,"%02X",x->krb5_client_princ[i]) <= 0) goto err;
}
#endif
#ifndef OPENSSL_NO_PSK
if (BIO_puts(bp,"\n PSK identity: ") <= 0) goto err;
if (BIO_printf(bp, "%s", x->psk_identity ? x->psk_identity : "None") <= 0) goto err;
if (BIO_puts(bp,"\n PSK identity hint: ") <= 0) goto err;
if (BIO_printf(bp, "%s", x->psk_identity_hint ? x->psk_identity_hint : "None") <= 0) goto err;
#endif
#ifndef OPENSSL_NO_TLSEXT
if (x->tlsext_tick_lifetime_hint)
{
if (BIO_printf(bp,
"\n TLS session ticket lifetime hint: %ld (seconds)",
x->tlsext_tick_lifetime_hint) <=0)
goto err;
}
if (x->tlsext_tick)
{
if (BIO_puts(bp, "\n TLS session ticket:\n") <= 0) goto err;
if (BIO_dump_indent(bp, (char *)x->tlsext_tick, x->tlsext_ticklen, 4) <= 0)
goto err;
}
#endif
#ifndef OPENSSL_NO_COMP
if (x->compress_meth != 0)
{
SSL_COMP *comp = NULL;
ssl_cipher_get_evp(x,NULL,NULL,NULL,NULL,&comp);
if (comp == NULL)
{
if (BIO_printf(bp,"\n Compression: %d",x->compress_meth) <= 0) goto err;
}
else
{
if (BIO_printf(bp,"\n Compression: %d (%s)", comp->id,comp->method->name) <= 0) goto err;
}
}
#endif
if (x->time != 0L)
{
if (BIO_printf(bp, "\n Start Time: %ld",x->time) <= 0) goto err;
}
if (x->timeout != 0L)
{
if (BIO_printf(bp, "\n Timeout : %ld (sec)",x->timeout) <= 0) goto err;
}
if (BIO_puts(bp,"\n") <= 0) goto err;
if (BIO_puts(bp, " Verify return code: ") <= 0) goto err;
if (BIO_printf(bp, "%ld (%s)\n", x->verify_result,
X509_verify_cert_error_string(x->verify_result)) <= 0) goto err;
return(1);
err:
return(0);
}
