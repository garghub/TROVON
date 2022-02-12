static int pkey_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it,
void *exarg)
{
if (operation == ASN1_OP_FREE_PRE) {
PKCS8_PRIV_KEY_INFO *key = (PKCS8_PRIV_KEY_INFO *)*pval;
if (key->pkey)
OPENSSL_cleanse(key->pkey->data, key->pkey->length);
}
return 1;
}
int PKCS8_pkey_add1_attr_by_NID(PKCS8_PRIV_KEY_INFO *p8, int nid, int type,
const unsigned char *bytes, int len)
{
if (X509at_add1_attr_by_NID(&p8->attributes, nid, type, bytes, len) != NULL)
return 1;
return 0;
}
