int FuzzerInitialize(int *argc, char ***argv) {
return 1;
}
int FuzzerTestOneInput(const uint8_t *buf, size_t len) {
const unsigned char *p = buf;
unsigned char *der = NULL;
X509_CRL *crl = d2i_X509_CRL(NULL, &p, len);
if (crl != NULL) {
BIO *bio = BIO_new(BIO_s_null());
X509_CRL_print(bio, crl);
BIO_free(bio);
i2d_X509_CRL(crl, &der);
OPENSSL_free(der);
X509_CRL_free(crl);
}
return 0;
}
