static int pkey_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_FREE_PRE) {
PKCS8_PRIV_KEY_INFO *key = (PKCS8_PRIV_KEY_INFO *)*pval;
if (key->pkey->value.octet_string)
OPENSSL_cleanse(key->pkey->value.octet_string->data,
key->pkey->value.octet_string->length);
}
return 1;
}
