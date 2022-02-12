void ERR_load_crypto_strings(void)
{
static int done=0;
if (done) return;
done=1;
#ifndef OPENSSL_NO_ERR
ERR_load_ERR_strings();
ERR_load_BN_strings();
#ifndef OPENSSL_NO_RSA
ERR_load_RSA_strings();
#endif
#ifndef OPENSSL_NO_DH
ERR_load_DH_strings();
#endif
ERR_load_EVP_strings();
ERR_load_BUF_strings();
ERR_load_OBJ_strings();
ERR_load_PEM_strings();
#ifndef OPENSSL_NO_DSA
ERR_load_DSA_strings();
#endif
ERR_load_X509_strings();
ERR_load_ASN1_strings();
ERR_load_CONF_strings();
ERR_load_CRYPTO_strings();
#ifndef OPENSSL_NO_EC
ERR_load_EC_strings();
#endif
#ifndef OPENSSL_NO_ECDSA
ERR_load_ECDSA_strings();
#endif
#ifndef OPENSSL_NO_ECDH
ERR_load_ECDH_strings();
#endif
ERR_load_BIO_strings();
ERR_load_PKCS7_strings();
ERR_load_X509V3_strings();
ERR_load_PKCS12_strings();
ERR_load_RAND_strings();
ERR_load_DSO_strings();
#ifndef OPENSSL_NO_ENGINE
ERR_load_ENGINE_strings();
#endif
ERR_load_OCSP_strings();
ERR_load_UI_strings();
#endif
}
