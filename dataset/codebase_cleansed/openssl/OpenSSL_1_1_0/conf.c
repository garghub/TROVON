int FuzzerInitialize(int *argc, char ***argv) {
return 1;
}
int FuzzerTestOneInput(const uint8_t *buf, size_t len) {
CONF *conf = NCONF_new(NULL);
BIO *in = BIO_new(BIO_s_mem());
long eline;
OPENSSL_assert((size_t)BIO_write(in, buf, len) == len);
NCONF_load_bio(conf, in, &eline);
NCONF_free(conf);
BIO_free(in);
return 0;
}
