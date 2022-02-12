void interrupt()
{
done = 1;
}
void sigsetup(void)
{
struct sigaction sa;
sa.sa_flags = SA_RESETHAND;
sa.sa_handler = interrupt;
sigemptyset(&sa.sa_mask);
sigaction(SIGINT, &sa, NULL);
}
int main(int argc, char *argv[])
{
char *port = NULL;
BIO *in = NULL;
BIO *ssl_bio, *tmp;
SSL_CTX *ctx;
char buf[512];
int ret = 1, i;
if (argc <= 1)
port = "*:4433";
else
port = argv[1];
SSL_load_error_strings();
OpenSSL_add_ssl_algorithms();
ctx = SSL_CTX_new(TLS_server_method());
if (!SSL_CTX_use_certificate_chain_file(ctx, CERT_FILE))
goto err;
if (!SSL_CTX_use_PrivateKey_file(ctx, CERT_FILE, SSL_FILETYPE_PEM))
goto err;
if (!SSL_CTX_check_private_key(ctx))
goto err;
ssl_bio = BIO_new_ssl(ctx, 0);
if ((in = BIO_new_accept(port)) == NULL)
goto err;
BIO_set_accept_bios(in, ssl_bio);
sigsetup();
again:
if (BIO_do_accept(in) <= 0)
goto err;
while (!done) {
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
