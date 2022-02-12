X509_INFO *X509_INFO_new(void)
{
X509_INFO *ret = NULL;
ret = (X509_INFO *)OPENSSL_malloc(sizeof(X509_INFO));
if (ret == NULL) {
ASN1err(ASN1_F_X509_INFO_NEW, ERR_R_MALLOC_FAILURE);
return (NULL);
}
ret->enc_cipher.cipher = NULL;
ret->enc_len = 0;
ret->enc_data = NULL;
ret->references = 1;
ret->x509 = NULL;
ret->crl = NULL;
ret->x_pkey = NULL;
return (ret);
}
void X509_INFO_free(X509_INFO *x)
{
int i;
if (x == NULL)
return;
i = CRYPTO_add(&x->references, -1, CRYPTO_LOCK_X509_INFO);
#ifdef REF_PRINT
REF_PRINT("X509_INFO", x);
#endif
if (i > 0)
return;
#ifdef REF_CHECK
if (i < 0) {
fprintf(stderr, "X509_INFO_free, bad reference count\n");
abort();
}
#endif
if (x->x509 != NULL)
X509_free(x->x509);
if (x->crl != NULL)
X509_CRL_free(x->crl);
if (x->x_pkey != NULL)
X509_PKEY_free(x->x_pkey);
if (x->enc_data != NULL)
OPENSSL_free(x->enc_data);
OPENSSL_free(x);
}
