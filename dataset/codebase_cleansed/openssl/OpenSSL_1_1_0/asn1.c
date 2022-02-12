int FuzzerInitialize(int *argc, char ***argv) {
return 1;
}
int FuzzerTestOneInput(const uint8_t *buf, size_t len) {
int n;
ASN1_PCTX *pctx = ASN1_PCTX_new();
ASN1_PCTX_set_flags(pctx, ASN1_PCTX_FLAGS_SHOW_ABSENT |
ASN1_PCTX_FLAGS_SHOW_SEQUENCE | ASN1_PCTX_FLAGS_SHOW_SSOF |
ASN1_PCTX_FLAGS_SHOW_TYPE | ASN1_PCTX_FLAGS_SHOW_FIELD_STRUCT_NAME);
ASN1_PCTX_set_str_flags(pctx, ASN1_STRFLGS_UTF8_CONVERT |
ASN1_STRFLGS_SHOW_TYPE | ASN1_STRFLGS_DUMP_ALL);
for (n = 0; item_type[n] != NULL; ++n) {
const uint8_t *b = buf;
unsigned char *der = NULL;
const ASN1_ITEM *i = ASN1_ITEM_ptr(item_type[n]);
ASN1_VALUE *o = ASN1_item_d2i(NULL, &b, len, i);
if (o != NULL) {
BIO *bio = BIO_new(BIO_s_null());
ASN1_item_print(bio, o, 4, i, pctx);
BIO_free(bio);
ASN1_item_i2d(o, &der, i);
OPENSSL_free(der);
ASN1_item_free(o, i);
}
}
ASN1_PCTX_free(pctx);
return 0;
}
