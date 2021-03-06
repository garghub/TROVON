int main(int argc, char *argv[])
{
char *port = "*:4433";
BIO *ssl_bio, *tmp;
SSL_CTX *ctx;
SSL_CONF_CTX *cctx;
char buf[512];
BIO *in = NULL;
int ret = 1, i;
char **args = argv + 1;
int nargs = argc - 1;
SSL_load_error_strings();
OpenSSL_add_ssl_algorithms();
ctx = SSL_CTX_new(TLS_server_method());
cctx = SSL_CONF_CTX_new();
SSL_CONF_CTX_set_flags(cctx, SSL_CONF_FLAG_SERVER);
SSL_CONF_CTX_set_flags(cctx, SSL_CONF_FLAG_CERTIFICATE);
SSL_CONF_CTX_set_ssl_ctx(cctx, ctx);
while (*args && **args == '-') {
int rv;
rv = SSL_CONF_cmd_argv(cctx, &nargs, &args);
if (rv == -3) {
fprintf(stderr, "Missing argument for %s\n", *args);
goto err;
}
if (rv < 0) {
fprintf(stderr, "Error in command %s\n", *args);
ERR_print_errors_fp(stderr);
goto err;
}
if (rv > 0)
continue;
if (strcmp(*args, "-port") == 0) {
port = args[1];
if (port == NULL) {
fprintf(stderr, "Missing -port argument\n");
goto err;
}
args += 2;
nargs -= 2;
continue;
} else {
fprintf(stderr, "Unknown argument %s\n", *args);
goto err;
}
}
if (!SSL_CONF_CTX_finish(cctx)) {
fprintf(stderr, "Finish error\n");
ERR_print_errors_fp(stderr);
goto err;
}
#ifdef ITERATE_CERTS
{
X509 *x;
int rv;
rv = SSL_CTX_set_current_cert(ctx, SSL_CERT_SET_FIRST);
while (rv) {
X509 *x = SSL_CTX_get0_certificate(ctx);
X509_NAME_print_ex_fp(stdout, X509_get_subject_name(x), 0,
XN_FLAG_ONELINE);
printf("\n");
rv = SSL_CTX_set_current_cert(ctx, SSL_CERT_SET_NEXT);
}
fflush(stdout);
}
#endif
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
if (i < 0)
goto err;
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
