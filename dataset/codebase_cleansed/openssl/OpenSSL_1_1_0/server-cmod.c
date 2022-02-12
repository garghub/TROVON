int main(int argc, char *argv[])
{
unsigned char buf[512];
char *port = "*:4433";
BIO *in = NULL;
BIO *ssl_bio, *tmp;
SSL_CTX *ctx;
int ret = 1, i;
SSL_load_error_strings();
OpenSSL_add_ssl_algorithms();
if (CONF_modules_load_file("cmod.cnf", "testapp", 0) <= 0) {
fprintf(stderr, "Error processing config file\n");
goto err;
}
ctx = SSL_CTX_new(TLS_server_method());
if (SSL_CTX_config(ctx, "server") == 0) {
fprintf(stderr, "Error configuring server.\n");
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
i = BIO_read(in, buf, sizeof(buf));
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
