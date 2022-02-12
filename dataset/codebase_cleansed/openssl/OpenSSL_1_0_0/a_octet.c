ASN1_OCTET_STRING *ASN1_OCTET_STRING_dup(const ASN1_OCTET_STRING *x)
{ return M_ASN1_OCTET_STRING_dup(x); }
int ASN1_OCTET_STRING_cmp(const ASN1_OCTET_STRING *a, const ASN1_OCTET_STRING *b)
{ return M_ASN1_OCTET_STRING_cmp(a, b); }
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *x, const unsigned char *d, int len)
{ return M_ASN1_OCTET_STRING_set(x, d, len); }
