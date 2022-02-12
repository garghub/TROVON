ASN1_METHOD *RSAPrivateKey_asn1_meth(void)
{
return(&method);
}
static int rsa_cb(int operation, ASN1_VALUE **pval, const ASN1_ITEM *it)
{
if(operation == ASN1_OP_NEW_PRE) {
*pval = (ASN1_VALUE *)RSA_new();
if(*pval) return 2;
return 0;
} else if(operation == ASN1_OP_FREE_PRE) {
RSA_free((RSA *)*pval);
*pval = NULL;
return 2;
}
return 1;
}
RSA *RSAPrivateKey_dup(RSA *rsa)
{
return ASN1_item_dup(ASN1_ITEM_rptr(RSAPrivateKey), rsa);
}
