int main(argc, argv)
int argc;
char *argv[];
{
char *host;
BIO *out;
char buf[1024 * 10], *p;
SSL_CTX *ssl_ctx = NULL;
SSL *ssl;
BIO *ssl_bio;
int i, len, off, ret = 1;
if (argc <= 1)
host = "localhost:4433";
else
host = argv[1];
#ifdef WATT32
dbug_init();
sock_init();
#endif
SSL_load_error_strings();
OpenSSL_add_ssl_algorithms();
ssl_ctx = SSL_CTX_new(SSLv23_client_method());
ssl = SSL_new(ssl_ctx);
SSL_set_connect_state(ssl);
ssl_bio = BIO_new(BIO_f_ssl());
BIO_set_ssl(ssl_bio, ssl, BIO_CLOSE);
out = BIO_new(BIO_s_connect());
BIO_set_conn_hostname(out, host);
BIO_set_nbio(out, 1);
out = BIO_push(ssl_bio, out);
p = "GET / HTTP/1.0\r\n\r\n";
len = strlen(p);
off = 0;
for (;;) {
i = BIO_write(out, &(p[off]), len);
if (i <= 0) {
if (BIO_should_retry(out)) {
fprintf(stderr, "write DELAY\n");
sleep(1);
continue;
} else {
goto err;
}
}
off += i;
len -= i;
if (len <= 0)
break;
}
for (;;) {
i = BIO_read(out, buf, sizeof(buf));
if (i == 0)
break;
if (i < 0) {
if (BIO_should_retry(out)) {
fprintf(stderr, "read DELAY\n");
sleep(1);
continue;
}
goto err;
}
fwrite(buf, 1, i, stdout);
}
ret = 1;
if (0) {
err:
if (ERR_peek_error() == 0) {
fprintf(stderr, "errno=%d ", errno);
perror("error");
} else
ERR_print_errors_fp(stderr);
}
BIO_free_all(out);
if (ssl_ctx != NULL)
SSL_CTX_free(ssl_ctx);
exit(!ret);
return (ret);
}
