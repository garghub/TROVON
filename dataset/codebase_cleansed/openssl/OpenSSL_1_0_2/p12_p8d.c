PKCS8_PRIV_KEY_INFO *PKCS8_decrypt(X509_SIG *p8, const char *pass,
int passlen)
{
return PKCS12_item_decrypt_d2i(p8->algor,
ASN1_ITEM_rptr(PKCS8_PRIV_KEY_INFO), pass,
passlen, p8->digest, 1);
}
