int EVP_PKEY_decrypt_old(unsigned char *key, const unsigned char *ek, int ekl,
EVP_PKEY *priv)
{
int ret = -1;
#ifndef OPENSSL_NO_RSA
if (EVP_PKEY_id(priv) != EVP_PKEY_RSA) {
#endif
EVPerr(EVP_F_EVP_PKEY_DECRYPT_OLD, EVP_R_PUBLIC_KEY_NOT_RSA);
#ifndef OPENSSL_NO_RSA
goto err;
}
ret =
RSA_private_decrypt(ekl, ek, key, EVP_PKEY_get0_RSA(priv),
RSA_PKCS1_PADDING);
err:
#endif
return (ret);
}
