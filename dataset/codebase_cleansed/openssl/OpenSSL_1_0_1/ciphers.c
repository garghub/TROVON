int MAIN(int argc, char **argv)
{
int ret=1,i;
int verbose=0,Verbose=0;
const char **pp;
const char *p;
int badops=0;
SSL_CTX *ctx=NULL;
SSL *ssl=NULL;
char *ciphers=NULL;
const SSL_METHOD *meth=NULL;
STACK_OF(SSL_CIPHER) *sk;
char buf[512];
BIO *STDout=NULL;
#if !defined(OPENSSL_NO_SSL2) && !defined(OPENSSL_NO_SSL3)
meth=SSLv23_server_method();
#elif !defined(OPENSSL_NO_SSL3)
meth=SSLv3_server_method();
#elif !defined(OPENSSL_NO_SSL2)
meth=SSLv2_server_method();
#endif
apps_startup();
if (bio_err == NULL)
bio_err=BIO_new_fp(stderr,BIO_NOCLOSE);
STDout=BIO_new_fp(stdout,BIO_NOCLOSE);
#ifdef OPENSSL_SYS_VMS
{
BIO *tmpbio = BIO_new(BIO_f_linebuffer());
STDout = BIO_push(tmpbio, STDout);
}
#endif
if (!load_config(bio_err, NULL))
goto end;
argc--;
argv++;
while (argc >= 1)
{
if (strcmp(*argv,"-v") == 0)
verbose=1;
else if (strcmp(*argv,"-V") == 0)
verbose=Verbose=1;
#ifndef OPENSSL_NO_SSL2
else if (strcmp(*argv,"-ssl2") == 0)
meth=SSLv2_client_method();
#endif
#ifndef OPENSSL_NO_SSL3
else if (strcmp(*argv,"-ssl3") == 0)
meth=SSLv3_client_method();
#endif
#ifndef OPENSSL_NO_TLS1
else if (strcmp(*argv,"-tls1") == 0)
meth=TLSv1_client_method();
#endif
else if ((strncmp(*argv,"-h",2) == 0) ||
(strcmp(*argv,"-?") == 0))
{
badops=1;
break;
}
else
{
ciphers= *argv;
}
argc--;
argv++;
}
if (badops)
{
for (pp=ciphers_usage; (*pp != NULL); pp++)
BIO_printf(bio_err,"%s",*pp);
goto end;
}
OpenSSL_add_ssl_algorithms();
ctx=SSL_CTX_new(meth);
if (ctx == NULL) goto err;
if (ciphers != NULL) {
if(!SSL_CTX_set_cipher_list(ctx,ciphers)) {
BIO_printf(bio_err, "Error in cipher list\n");
goto err;
}
}
ssl=SSL_new(ctx);
if (ssl == NULL) goto err;
if (!verbose)
{
for (i=0; ; i++)
{
p=SSL_get_cipher_list(ssl,i);
if (p == NULL) break;
if (i != 0) BIO_printf(STDout,":");
BIO_printf(STDout,"%s",p);
}
BIO_printf(STDout,"\n");
}
else
{
sk=SSL_get_ciphers(ssl);
for (i=0; i<sk_SSL_CIPHER_num(sk); i++)
{
SSL_CIPHER *c;
c = sk_SSL_CIPHER_value(sk,i);
if (Verbose)
{
unsigned long id = SSL_CIPHER_get_id(c);
int id0 = (int)(id >> 24);
int id1 = (int)((id >> 16) & 0xffL);
int id2 = (int)((id >> 8) & 0xffL);
int id3 = (int)(id & 0xffL);
if ((id & 0xff000000L) == 0x02000000L)
BIO_printf(STDout, " 0x%02X,0x%02X,0x%02X - ", id1, id2, id3);
else if ((id & 0xff000000L) == 0x03000000L)
BIO_printf(STDout, " 0x%02X,0x%02X - ", id2, id3);
else
BIO_printf(STDout, "0x%02X,0x%02X,0x%02X,0x%02X - ", id0, id1, id2, id3);
}
BIO_puts(STDout,SSL_CIPHER_description(c,buf,sizeof buf));
}
}
ret=0;
if (0)
{
err:
SSL_load_error_strings();
ERR_print_errors(bio_err);
}
end:
if (ctx != NULL) SSL_CTX_free(ctx);
if (ssl != NULL) SSL_free(ssl);
if (STDout != NULL) BIO_free_all(STDout);
apps_shutdown();
OPENSSL_EXIT(ret);
}
