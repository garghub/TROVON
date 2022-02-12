int i2d_PrivateKey(EVP_PKEY *a, unsigned char **pp)
{
if (a->ameth && a->ameth->old_priv_encode) {
return a->ameth->old_priv_encode(a, pp);
}
if (a->ameth && a->ameth->priv_encode) {
PKCS8_PRIV_KEY_INFO *p8 = EVP_PKEY2PKCS8(a);
int ret = i2d_PKCS8_PRIV_KEY_INFO(p8, pp);
PKCS8_PRIV_KEY_INFO_free(p8);
return ret;
}
ASN1err(ASN1_F_I2D_PRIVATEKEY, ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE);
return (-1);
}
