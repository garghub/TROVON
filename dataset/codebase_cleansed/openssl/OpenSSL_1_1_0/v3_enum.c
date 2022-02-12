char *i2s_ASN1_ENUMERATED_TABLE(X509V3_EXT_METHOD *method,
const ASN1_ENUMERATED *e)
{
ENUMERATED_NAMES *enam;
long strval;
strval = ASN1_ENUMERATED_get(e);
for (enam = method->usr_data; enam->lname; enam++) {
if (strval == enam->bitnum)
return OPENSSL_strdup(enam->lname);
}
return i2s_ASN1_ENUMERATED(method, e);
}
