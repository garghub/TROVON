int main(int argc, char *argv[])
{
char *port = "*:4433";
BIO *in = NULL;
BIO *ssl_bio, *tmp;
SSL_CTX *ctx;
SSL_CONF_CTX *cctx = NULL;
CONF *conf = NULL;
STACK_OF(CONF_VALUE) *sect = NULL;
CONF_VALUE *cnf;
long errline = -1;
char buf[512];
int ret = 1, i;
SSL_load_error_strings();
OpenSSL_add_ssl_algorithms();
conf = NCONF_new(NULL);
if (NCONF_load(conf, "accept.cnf", &errline) <= 0) {
if (errline <= 0)
fprintf(stderr, "Error processing config file\n");
else
fprintf(stderr, "Error on line %ld\n", errline);
goto err;
}
sect = NCONF_get_section(conf, "default");
if (sect == NULL) {
fprintf(stderr, "Error retrieving default section\n");
goto err;
}
ctx = SSL_CTX_new(TLS_server_method());
cctx = SSL_CONF_CTX_new();
SSL_CONF_CTX_set_flags(cctx, SSL_CONF_FLAG_SERVER);
SSL_CONF_CTX_set_flags(cctx, SSL_CONF_FLAG_CERTIFICATE);
SSL_CONF_CTX_set_flags(cctx, SSL_CONF_FLAG_FILE);
SSL_CONF_CTX_set_ssl_ctx(cctx, ctx);
for (i = 0; i < sk_CONF_VALUE_num(sect); i++) {
int rv;
cnf = sk_CONF_VALUE_value(sect, i);
rv = SSL_CONF_cmd(cctx, cnf->name, cnf->value);
if (rv > 0)
continue;
if (rv != -2) {
fprintf(stderr, "Error processing %s = %s\n",
cnf->name, cnf->value);
ERR_print_errors_fp(stderr);
goto err;
}
if (strcmp(cnf->name, "Port") == 0) {
port = cnf->value;
} else {
fprintf(stderr, "Unknown configuration option %s\n", cnf->name);
goto err;
}
}
if (!SSL_CONF_CTX_finish(cctx)) {
fprintf(stderr, "Finish error\n");
ERR_print_errors_fp(stderr);
goto err;
}
ssl_bio = BIO_new_ssl(ctx, 0);
if ((in = BIO_new_accept(port)) == NULL)
goto err;
BIO_set_accept_bios(in, ssl_bio);
again:
if (BIO_do_accept(in) <= 0)
goto err;
for (;;) {
i = BIO_read(in, buf, 512);
if (i == 0) {
printf("Done\n");
tmp = BIO_pop(in);
BIO_free_all(tmp);
goto again;
}
if (i < 0) {
if (BIO_should_retry(in))
continue;
goto err;
}
fwrite(buf, 1, i, stdout);
fflush(stdout);
}
ret = 0;
err:
if (ret) {
ERR_print_errors_fp(stderr);
}
BIO_free(in);
exit(ret);
return (!ret);
}
