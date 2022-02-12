EVP_PKEY *d2i_PrivateKey(int type, EVP_PKEY **a, const unsigned char **pp,
long length)
{
EVP_PKEY *ret;
if ((a == NULL) || (*a == NULL))
{
if ((ret=EVP_PKEY_new()) == NULL)
{
ASN1err(ASN1_F_D2I_PRIVATEKEY,ERR_R_EVP_LIB);
return(NULL);
}
}
else ret= *a;
ret->save_type=type;
ret->type=EVP_PKEY_type(type);
switch (ret->type)
{
#ifndef OPENSSL_NO_RSA
case EVP_PKEY_RSA:
if ((ret->pkey.rsa=d2i_RSAPrivateKey(NULL,
(const unsigned char **)pp,length)) == NULL)
{
ASN1err(ASN1_F_D2I_PRIVATEKEY,ERR_R_ASN1_LIB);
goto err;
}
break;
#endif
#ifndef OPENSSL_NO_DSA
case EVP_PKEY_DSA:
if ((ret->pkey.dsa=d2i_DSAPrivateKey(NULL,
(const unsigned char **)pp,length)) == NULL)
{
ASN1err(ASN1_F_D2I_PRIVATEKEY,ERR_R_ASN1_LIB);
goto err;
}
break;
#endif
#ifndef OPENSSL_NO_EC
case EVP_PKEY_EC:
if ((ret->pkey.ec = d2i_ECPrivateKey(NULL,
(const unsigned char **)pp, length)) == NULL)
{
ASN1err(ASN1_F_D2I_PRIVATEKEY, ERR_R_ASN1_LIB);
goto err;
}
break;
#endif
default:
ASN1err(ASN1_F_D2I_PRIVATEKEY,ASN1_R_UNKNOWN_PUBLIC_KEY_TYPE);
goto err;
}
if (a != NULL) (*a)=ret;
return(ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret))) EVP_PKEY_free(ret);
return(NULL);
}
EVP_PKEY *d2i_AutoPrivateKey(EVP_PKEY **a, const unsigned char **pp,
long length)
{
STACK_OF(ASN1_TYPE) *inkey;
const unsigned char *p;
int keytype;
p = *pp;
inkey = d2i_ASN1_SET_OF_ASN1_TYPE(NULL, &p, length, d2i_ASN1_TYPE,
ASN1_TYPE_free, V_ASN1_SEQUENCE, V_ASN1_UNIVERSAL);
if(sk_ASN1_TYPE_num(inkey) == 6)
keytype = EVP_PKEY_DSA;
else if (sk_ASN1_TYPE_num(inkey) == 4)
keytype = EVP_PKEY_EC;
else keytype = EVP_PKEY_RSA;
sk_ASN1_TYPE_pop_free(inkey, ASN1_TYPE_free);
return d2i_PrivateKey(keytype, a, pp, length);
}
