void ERR_load_crypto_strings(void)
{
static int done=0;
if (done) return;
done=1;
#ifndef NO_ERR
ERR_load_ASN1_strings();
ERR_load_BN_strings();
ERR_load_BUF_strings();
ERR_load_BIO_strings();
ERR_load_CONF_strings();
#ifndef NO_RSA
#ifdef RSAref
ERR_load_RSAREF_strings();
#else
ERR_load_RSA_strings();
#endif
#endif
#ifndef NO_DH
ERR_load_DH_strings();
#endif
#ifndef NO_DSA
ERR_load_DSA_strings();
#endif
ERR_load_ERR_strings();
ERR_load_EVP_strings();
ERR_load_OBJ_strings();
ERR_load_PEM_strings();
ERR_load_X509_strings();
ERR_load_X509V3_strings();
ERR_load_CRYPTO_strings();
ERR_load_PKCS7_strings();
ERR_load_PKCS12_strings();
ERR_load_RAND_strings();
#endif
}
