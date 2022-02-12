BIO *BIO_new_PKCS7(BIO *out, PKCS7 *p7)
{
return BIO_new_NDEF(out, (ASN1_VALUE *)p7, ASN1_ITEM_rptr(PKCS7));
}
