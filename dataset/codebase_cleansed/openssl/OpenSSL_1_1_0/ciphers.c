static unsigned int dummy_psk(SSL *ssl, const char *hint, char *identity,
unsigned int max_identity_len,
unsigned char *psk,
unsigned int max_psk_len)
{
return 0;
}
static char *dummy_srp(SSL *ssl, void *arg)
{
return "";
}
int ciphers_main(int argc, char **argv)
{
SSL_CTX *ctx = NULL;
SSL *ssl = NULL;
STACK_OF(SSL_CIPHER) *sk = NULL;
const SSL_METHOD *meth = TLS_server_method();
int ret = 1, i, verbose = 0, Verbose = 0, use_supported = 0;
#ifndef OPENSSL_NO_SSL_TRACE
int stdname = 0;
#endif
#ifndef OPENSSL_NO_PSK
int psk = 0;
#endif
#ifndef OPENSSL_NO_SRP
int srp = 0;
#endif
const char *p;
char *ciphers = NULL, *prog;
char buf[512];
OPTION_CHOICE o;
int min_version = 0, max_version = 0;
prog = opt_init(argc, argv, ciphers_options);
while ((o = opt_next()) != OPT_EOF) {
switch (o) {
case OPT_EOF:
case OPT_ERR:
opthelp:
BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
goto end;
case OPT_HELP:
opt_help(ciphers_options);
ret = 0;
goto end;
case OPT_V:
verbose = 1;
break;
case OPT_UPPER_V:
verbose = Verbose = 1;
break;
case OPT_S:
use_supported = 1;
break;
case OPT_STDNAME:
#ifndef OPENSSL_NO_SSL_TRACE
stdname = verbose = 1;
#endif
break;
case OPT_SSL3:
min_version = SSL3_VERSION;
max_version = SSL3_VERSION;
break;
case OPT_TLS1:
min_version = TLS1_VERSION;
max_version = TLS1_VERSION;
break;
case OPT_TLS1_1:
min_version = TLS1_1_VERSION;
max_version = TLS1_1_VERSION;
break;
case OPT_TLS1_2:
min_version = TLS1_2_VERSION;
max_version = TLS1_2_VERSION;
break;
case OPT_PSK:
#ifndef OPENSSL_NO_PSK
psk = 1;
#endif
break;
case OPT_SRP:
#ifndef OPENSSL_NO_SRP
srp = 1;
#endif
break;
}
}
argv = opt_rest();
argc = opt_num_rest();
if (argc == 1)
ciphers = *argv;
else if (argc != 0)
goto opthelp;
ctx = SSL_CTX_new(meth);
if (ctx == NULL)
goto err;
if (SSL_CTX_set_min_proto_version(ctx, min_version) == 0)
goto err;
if (SSL_CTX_set_max_proto_version(ctx, max_version) == 0)
goto err;
#ifndef OPENSSL_NO_PSK
if (psk)
SSL_CTX_set_psk_client_callback(ctx, dummy_psk);
#endif
#ifndef OPENSSL_NO_SRP
if (srp)
SSL_CTX_set_srp_client_pwd_callback(ctx, dummy_srp);
#endif
if (ciphers != NULL) {
if (!SSL_CTX_set_cipher_list(ctx, ciphers)) {
BIO_printf(bio_err, "Error in cipher list\n");
goto err;
}
}
ssl = SSL_new(ctx);
if (ssl == NULL)
goto err;
if (use_supported)
sk = SSL_get1_supported_ciphers(ssl);
else
sk = SSL_get_ciphers(ssl);
if (!verbose) {
for (i = 0; i < sk_SSL_CIPHER_num(sk); i++) {
const SSL_CIPHER *c = sk_SSL_CIPHER_value(sk, i);
p = SSL_CIPHER_get_name(c);
if (p == NULL)
break;
if (i != 0)
BIO_printf(bio_out, ":");
BIO_printf(bio_out, "%s", p);
}
BIO_printf(bio_out, "\n");
} else {
for (i = 0; i < sk_SSL_CIPHER_num(sk); i++) {
const SSL_CIPHER *c;
c = sk_SSL_CIPHER_value(sk, i);
if (Verbose) {
unsigned long id = SSL_CIPHER_get_id(c);
int id0 = (int)(id >> 24);
int id1 = (int)((id >> 16) & 0xffL);
int id2 = (int)((id >> 8) & 0xffL);
int id3 = (int)(id & 0xffL);
if ((id & 0xff000000L) == 0x03000000L)
BIO_printf(bio_out, " 0x%02X,0x%02X - ", id2, id3);
else
BIO_printf(bio_out, "0x%02X,0x%02X,0x%02X,0x%02X - ", id0, id1, id2, id3);
}
#ifndef OPENSSL_NO_SSL_TRACE
if (stdname) {
const char *nm = SSL_CIPHER_standard_name(c);
if (nm == NULL)
nm = "UNKNOWN";
BIO_printf(bio_out, "%s - ", nm);
}
#endif
BIO_puts(bio_out, SSL_CIPHER_description(c, buf, sizeof buf));
}
}
ret = 0;
goto end;
err:
ERR_print_errors(bio_err);
end:
if (use_supported)
sk_SSL_CIPHER_free(sk);
SSL_CTX_free(ctx);
SSL_free(ssl);
return (ret);
}
