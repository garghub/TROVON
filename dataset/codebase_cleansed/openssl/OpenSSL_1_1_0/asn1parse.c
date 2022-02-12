int FuzzerInitialize(int *argc, char ***argv) {
return 1;
}
int FuzzerTestOneInput(const uint8_t *buf, size_t len) {
static BIO *bio_out;
if (bio_out == NULL)
bio_out = BIO_new_file("/dev/null", "w");
(void)ASN1_parse_dump(bio_out, buf, len, 0, 0);
return 0;
}
