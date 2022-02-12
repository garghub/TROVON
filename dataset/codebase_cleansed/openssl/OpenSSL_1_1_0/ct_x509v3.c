static char *i2s_poison(const X509V3_EXT_METHOD *method, void *val)
{
return OPENSSL_strdup("NULL");
}
static void *s2i_poison(const X509V3_EXT_METHOD *method, X509V3_CTX *ctx, const char *str)
{
return ASN1_NULL_new();
}
