int FuzzerInitialize(int *argc, char ***argv) {
const uint8_t *bufp = kRSAPrivateKeyDER;
RSA *privkey;
EVP_PKEY *pkey;
int ret;
X509 *cert;
ctx = SSL_CTX_new(SSLv23_method());
privkey = d2i_RSAPrivateKey(NULL, &bufp, sizeof(kRSAPrivateKeyDER));
OPENSSL_assert(privkey != NULL);
pkey = EVP_PKEY_new();
EVP_PKEY_assign_RSA(pkey, privkey);
ret = SSL_CTX_use_PrivateKey(ctx, pkey);
OPENSSL_assert(ret == 1);
EVP_PKEY_free(pkey);
bufp = kCertificateDER;
cert = d2i_X509(NULL, &bufp, sizeof(kCertificateDER));
OPENSSL_assert(cert != NULL);
ret = SSL_CTX_use_certificate(ctx, cert);
OPENSSL_assert(ret == 1);
X509_free(cert);
return 1;
}
int FuzzerTestOneInput(const uint8_t *buf, size_t len) {
SSL *server = SSL_new(ctx);
BIO *in = BIO_new(BIO_s_mem());
BIO *out = BIO_new(BIO_s_mem());
SSL_set_bio(server, in, out);
SSL_set_accept_state(server);
OPENSSL_assert((size_t)BIO_write(in, buf, len) == len);
if (SSL_do_handshake(server) == 1) {
uint8_t tmp[1024];
for (;;) {
if (SSL_read(server, tmp, sizeof(tmp)) <= 0) {
break;
}
}
}
SSL_free(server);
return 0;
}
