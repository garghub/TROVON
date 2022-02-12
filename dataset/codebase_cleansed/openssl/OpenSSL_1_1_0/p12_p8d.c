PKCS8_PRIV_KEY_INFO *PKCS8_decrypt(const X509_SIG *p8, const char *pass,
int passlen)
{
const X509_ALGOR *dalg;
const ASN1_OCTET_STRING *doct;
X509_SIG_get0(p8, &dalg, &doct);
return PKCS12_item_decrypt_d2i(dalg,
ASN1_ITEM_rptr(PKCS8_PRIV_KEY_INFO), pass,
passlen, doct, 1);
}
