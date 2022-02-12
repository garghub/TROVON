int i2d_PublicKey(EVP_PKEY *a, unsigned char **pp)
{
switch (a->type)
{
#ifndef NO_RSA
case EVP_PKEY_RSA:
return(i2d_RSAPublicKey(a->pkey.rsa,pp));
#endif
#ifndef NO_DSA
case EVP_PKEY_DSA:
return(i2d_DSAPublicKey(a->pkey.dsa,pp));
#endif
default:
ASN1err(ASN1_F_I2D_PUBLICKEY,ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE);
return(-1);
}
}
