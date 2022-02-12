int X509_certificate_type(X509 *x, EVP_PKEY *pkey)
{
EVP_PKEY *pk;
int ret = 0, i;
if (x == NULL)
return (0);
if (pkey == NULL)
pk = X509_get_pubkey(x);
else
pk = pkey;
if (pk == NULL)
return (0);
switch (pk->type) {
case EVP_PKEY_RSA:
ret = EVP_PK_RSA | EVP_PKT_SIGN;
ret |= EVP_PKT_ENC;
break;
case EVP_PKEY_DSA:
ret = EVP_PK_DSA | EVP_PKT_SIGN;
break;
case EVP_PKEY_EC:
ret = EVP_PK_EC | EVP_PKT_SIGN | EVP_PKT_EXCH;
break;
case EVP_PKEY_DH:
ret = EVP_PK_DH | EVP_PKT_EXCH;
break;
case NID_id_GostR3410_94:
case NID_id_GostR3410_2001:
ret = EVP_PKT_EXCH | EVP_PKT_SIGN;
break;
default:
break;
}
i = OBJ_obj2nid(x->sig_alg->algorithm);
if (i && OBJ_find_sigid_algs(i, NULL, &i)) {
switch (i) {
case NID_rsaEncryption:
case NID_rsa:
ret |= EVP_PKS_RSA;
break;
case NID_dsa:
case NID_dsa_2:
ret |= EVP_PKS_DSA;
break;
case NID_X9_62_id_ecPublicKey:
ret |= EVP_PKS_EC;
break;
default:
break;
}
}
if (EVP_PKEY_size(pk) <= 1024 / 8)
ret |= EVP_PKT_EXP;
if (pkey == NULL)
EVP_PKEY_free(pk);
return (ret);
}
