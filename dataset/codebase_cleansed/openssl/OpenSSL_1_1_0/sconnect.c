int main(argc, argv)
int argc;
char *argv[];
{
const char *hostport = HOSTPORT;
const char *CAfile = CAFILE;
char *hostname;
char *cp;
BIO *out = NULL;
char buf[1024 * 10], *p;
SSL_CTX *ssl_ctx = NULL;
SSL *ssl;
BIO *ssl_bio;
int i, len, off, ret = 1;
if (argc > 1)
hostport = argv[1];
if (argc > 2)
CAfile = argv[2];
hostname = OPENSSL_strdup(hostport);
if ((cp = strchr(hostname, ':')) != NULL)
*cp = 0;
#ifdef WATT32
dbug_init();
sock_init();
#endif
SSL_load_error_strings();
OpenSSL_add_ssl_algorithms();
ssl_ctx = SSL_CTX_new(TLS_client_method());
SSL_CTX_set_verify(ssl_ctx, SSL_VERIFY_PEER, NULL);
SSL_CTX_load_verify_locations(ssl_ctx, CAfile, NULL);
ssl = SSL_new(ssl_ctx);
SSL_set_connect_state(ssl);
if (SSL_set1_host(ssl, hostname) <= 0)
goto err;
ssl_bio = BIO_new(BIO_f_ssl());
BIO_set_ssl(ssl_bio, ssl, BIO_CLOSE);
out = BIO_new(BIO_s_connect());
BIO_set_conn_hostname(out, hostport);
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
goto done;
err:
if (ERR_peek_error() == 0) {
fprintf(stderr, "errno=%d ", errno);
perror("error");
} else
ERR_print_errors_fp(stderr);
done:
BIO_free_all(out);
SSL_CTX_free(ssl_ctx);
return (ret == 1);
}
