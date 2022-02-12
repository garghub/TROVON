int FuzzerInitialize(int *argc, char ***argv) {
return 1;
}
int FuzzerTestOneInput(const uint8_t *buf, size_t len) {
const uint8_t **pp = &buf;
unsigned char *der = NULL;
STACK_OF(SCT) *scts = d2i_SCT_LIST(NULL, pp, len);
if (scts != NULL) {
BIO *bio = BIO_new(BIO_s_null());
SCT_LIST_print(scts, bio, 4, "\n", NULL);
BIO_free(bio);
if (i2d_SCT_LIST(scts, &der)) {
}
OPENSSL_free(der);
SCT_LIST_free(scts);
}
return 0;
}
