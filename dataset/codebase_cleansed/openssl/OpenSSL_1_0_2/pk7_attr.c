int PKCS7_add_attrib_content_type(PKCS7_SIGNER_INFO *si, ASN1_OBJECT *coid)
{
if (PKCS7_get_signed_attribute(si, NID_pkcs9_contentType))
return 0;
if (!coid)
coid = OBJ_nid2obj(NID_pkcs7_data);
return PKCS7_add_signed_attribute(si, NID_pkcs9_contentType,
V_ASN1_OBJECT, coid);
}
int PKCS7_add0_attrib_signing_time(PKCS7_SIGNER_INFO *si, ASN1_TIME *t)
{
if (!t && !(t = X509_gmtime_adj(NULL, 0))) {
PKCS7err(PKCS7_F_PKCS7_ADD0_ATTRIB_SIGNING_TIME,
ERR_R_MALLOC_FAILURE);
return 0;
}
return PKCS7_add_signed_attribute(si, NID_pkcs9_signingTime,
V_ASN1_UTCTIME, t);
}
int PKCS7_add1_attrib_digest(PKCS7_SIGNER_INFO *si,
const unsigned char *md, int mdlen)
{
ASN1_OCTET_STRING *os;
os = ASN1_OCTET_STRING_new();
if (!os)
return 0;
if (!ASN1_STRING_set(os, md, mdlen)
|| !PKCS7_add_signed_attribute(si, NID_pkcs9_messageDigest,
V_ASN1_OCTET_STRING, os)) {
ASN1_OCTET_STRING_free(os);
return 0;
}
return 1;
}
