int i2d_PrivateKey(EVP_PKEY *a, unsigned char **pp)
{
#ifndef OPENSSL_NO_RSA
if (a->type == EVP_PKEY_RSA)
{
return(i2d_RSAPrivateKey(a->pkey.rsa,pp));
}
else
#endif
#ifndef OPENSSL_NO_DSA
if (a->type == EVP_PKEY_DSA)
{
return(i2d_DSAPrivateKey(a->pkey.dsa,pp));
}
#endif
ASN1err(ASN1_F_I2D_PRIVATEKEY,ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE);
return(-1);
}
