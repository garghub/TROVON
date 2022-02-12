EVP_PKEY *d2i_PrivateKey(int type, EVP_PKEY **a, const unsigned char **pp,
long length)
{
EVP_PKEY *ret;
if ((a == NULL) || (*a == NULL)) {
if ((ret = EVP_PKEY_new()) == NULL) {
ASN1err(ASN1_F_D2I_PRIVATEKEY, ERR_R_EVP_LIB);
return (NULL);
}
} else {
ret = *a;
#ifndef OPENSSL_NO_ENGINE
if (ret->engine) {
ENGINE_finish(ret->engine);
ret->engine = NULL;
}
#endif
}
if (!EVP_PKEY_set_type(ret, type)) {
ASN1err(ASN1_F_D2I_PRIVATEKEY, ASN1_R_UNKNOWN_PUBLIC_KEY_TYPE);
goto err;
}
if (!ret->ameth->old_priv_decode ||
!ret->ameth->old_priv_decode(ret, pp, length)) {
if (ret->ameth->priv_decode) {
PKCS8_PRIV_KEY_INFO *p8 = NULL;
p8 = d2i_PKCS8_PRIV_KEY_INFO(NULL, pp, length);
if (!p8)
goto err;
EVP_PKEY_free(ret);
ret = EVP_PKCS82PKEY(p8);
PKCS8_PRIV_KEY_INFO_free(p8);
} else {
ASN1err(ASN1_F_D2I_PRIVATEKEY, ERR_R_ASN1_LIB);
goto err;
}
}
if (a != NULL)
(*a) = ret;
return (ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
EVP_PKEY_free(ret);
return (NULL);
}
EVP_PKEY *d2i_AutoPrivateKey(EVP_PKEY **a, const unsigned char **pp,
long length)
{
STACK_OF(ASN1_TYPE) *inkey;
const unsigned char *p;
int keytype;
p = *pp;
inkey = d2i_ASN1_SEQUENCE_ANY(NULL, &p, length);
if (sk_ASN1_TYPE_num(inkey) == 6)
keytype = EVP_PKEY_DSA;
else if (sk_ASN1_TYPE_num(inkey) == 4)
keytype = EVP_PKEY_EC;
else if (sk_ASN1_TYPE_num(inkey) == 3) {
PKCS8_PRIV_KEY_INFO *p8 = d2i_PKCS8_PRIV_KEY_INFO(NULL, pp, length);
EVP_PKEY *ret;
sk_ASN1_TYPE_pop_free(inkey, ASN1_TYPE_free);
if (!p8) {
ASN1err(ASN1_F_D2I_AUTOPRIVATEKEY,
ASN1_R_UNSUPPORTED_PUBLIC_KEY_TYPE);
return NULL;
}
ret = EVP_PKCS82PKEY(p8);
PKCS8_PRIV_KEY_INFO_free(p8);
if (a) {
*a = ret;
}
return ret;
} else
keytype = EVP_PKEY_RSA;
sk_ASN1_TYPE_pop_free(inkey, ASN1_TYPE_free);
return d2i_PrivateKey(keytype, a, pp, length);
}
