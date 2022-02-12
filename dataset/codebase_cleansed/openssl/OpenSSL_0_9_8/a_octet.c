ASN1_OCTET_STRING *ASN1_OCTET_STRING_dup(ASN1_OCTET_STRING *x)
{ return M_ASN1_OCTET_STRING_dup(x); }
int ASN1_OCTET_STRING_cmp(ASN1_OCTET_STRING *a, ASN1_OCTET_STRING *b)
{ return M_ASN1_OCTET_STRING_cmp(a, b); }
int ASN1_OCTET_STRING_set(ASN1_OCTET_STRING *x, const unsigned char *d, int len)
{ return M_ASN1_OCTET_STRING_set(x, d, len); }
