int MAIN(int argc, char **argv)
{
int ret=1,i;
int verbose=0;
char **pp;
const char *p;
int badops=0;
SSL_CTX *ctx=NULL;
SSL *ssl=NULL;
char *ciphers=NULL;
SSL_METHOD *meth=NULL;
STACK_OF(SSL_CIPHER) *sk;
char buf[512];
BIO *STDout=NULL;
#if !defined(NO_SSL2) && !defined(NO_SSL3)
meth=SSLv23_server_method();
#elif !defined(NO_SSL3)
meth=SSLv3_server_method();
#elif !defined(NO_SSL2)
meth=SSLv2_server_method();
#endif
apps_startup();
if (bio_err == NULL)
bio_err=BIO_new_fp(stderr,BIO_NOCLOSE);
STDout=BIO_new_fp(stdout,BIO_NOCLOSE);
argc--;
argv++;
while (argc >= 1)
{
if (strcmp(*argv,"-v") == 0)
verbose=1;
#ifndef NO_SSL2
else if (strcmp(*argv,"-ssl2") == 0)
meth=SSLv2_client_method();
#endif
#ifndef NO_SSL3
else if (strcmp(*argv,"-ssl3") == 0)
meth=SSLv3_client_method();
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
BIO_printf(bio_err,*pp);
goto end;
}
SSLeay_add_ssl_algorithms();
ctx=SSL_CTX_new(meth);
if (ctx == NULL) goto err;
if (ciphers != NULL)
SSL_CTX_set_cipher_list(ctx,ciphers);
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
BIO_puts(STDout,SSL_CIPHER_description(
sk_SSL_CIPHER_value(sk,i),
buf,512));
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
if (STDout != NULL) BIO_free(STDout);
EXIT(ret);
}
