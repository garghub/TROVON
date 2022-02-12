int X509_certificate_type(X509 *x, EVP_PKEY *pkey)
{
EVP_PKEY *pk;
int ret=0,i;
if (x == NULL) return(0);
if (pkey == NULL)
pk=X509_get_pubkey(x);
else
pk=pkey;
if (pk == NULL) return(0);
switch (pk->type)
{
case EVP_PKEY_RSA:
ret=EVP_PK_RSA|EVP_PKT_SIGN;
ret|=EVP_PKT_ENC;
break;
case EVP_PKEY_DSA:
ret=EVP_PK_DSA|EVP_PKT_SIGN;
break;
case EVP_PKEY_DH:
ret=EVP_PK_DH|EVP_PKT_EXCH;
break;
default:
break;
}
i=X509_get_signature_type(x);
switch (i)
{
case EVP_PKEY_RSA:
ret|=EVP_PKS_RSA;
break;
case EVP_PKS_DSA:
ret|=EVP_PKS_DSA;
break;
default:
break;
}
if (EVP_PKEY_size(pk) <= 512)
ret|=EVP_PKT_EXP;
if(pkey==NULL) EVP_PKEY_free(pk);
return(ret);
}
