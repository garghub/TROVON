X509_PKEY *X509_PKEY_new(void)
{
X509_PKEY *ret = NULL;
ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL)
goto err;
ret->enc_algor = X509_ALGOR_new();
ret->enc_pkey = ASN1_OCTET_STRING_new();
if (ret->enc_algor == NULL || ret->enc_pkey == NULL)
goto err;
return ret;
err:
X509_PKEY_free(ret);
ASN1err(ASN1_F_X509_PKEY_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
void X509_PKEY_free(X509_PKEY *x)
{
if (x == NULL)
return;
X509_ALGOR_free(x->enc_algor);
ASN1_OCTET_STRING_free(x->enc_pkey);
EVP_PKEY_free(x->dec_pkey);
if (x->key_free)
OPENSSL_free(x->key_data);
OPENSSL_free(x);
}
