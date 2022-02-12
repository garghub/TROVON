static void *s2i_asn1_int(X509V3_EXT_METHOD *meth, X509V3_CTX *ctx,
const char *value)
{
return s2i_ASN1_INTEGER(meth, value);
}
