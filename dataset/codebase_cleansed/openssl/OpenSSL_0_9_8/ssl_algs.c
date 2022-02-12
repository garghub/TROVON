int SSL_library_init(void)
{
#ifndef OPENSSL_NO_DES
EVP_add_cipher(EVP_des_cbc());
EVP_add_cipher(EVP_des_ede3_cbc());
#endif
#ifndef OPENSSL_NO_IDEA
EVP_add_cipher(EVP_idea_cbc());
#endif
#ifndef OPENSSL_NO_RC4
EVP_add_cipher(EVP_rc4());
#endif
#ifndef OPENSSL_NO_RC2
EVP_add_cipher(EVP_rc2_cbc());
#endif
#ifndef OPENSSL_NO_AES
EVP_add_cipher(EVP_aes_128_cbc());
EVP_add_cipher(EVP_aes_192_cbc());
EVP_add_cipher(EVP_aes_256_cbc());
#endif
#ifndef OPENSSL_NO_MD2
EVP_add_digest(EVP_md2());
#endif
#ifndef OPENSSL_NO_MD5
EVP_add_digest(EVP_md5());
EVP_add_digest_alias(SN_md5,"ssl2-md5");
EVP_add_digest_alias(SN_md5,"ssl3-md5");
#endif
#ifndef OPENSSL_NO_SHA
EVP_add_digest(EVP_sha1());
EVP_add_digest_alias(SN_sha1,"ssl3-sha1");
EVP_add_digest_alias(SN_sha1WithRSAEncryption,SN_sha1WithRSA);
#endif
#if !defined(OPENSSL_NO_SHA) && !defined(OPENSSL_NO_DSA)
EVP_add_digest(EVP_dss1());
EVP_add_digest_alias(SN_dsaWithSHA1,SN_dsaWithSHA1_2);
EVP_add_digest_alias(SN_dsaWithSHA1,"DSS1");
EVP_add_digest_alias(SN_dsaWithSHA1,"dss1");
#endif
#ifndef OPENSSL_NO_ECDSA
EVP_add_digest(EVP_ecdsa());
#endif
#if 0
EVP_add_digest(EVP_sha());
EVP_add_digest(EVP_dss());
#endif
#ifndef OPENSSL_NO_COMP
(void)SSL_COMP_get_compression_methods();
#endif
return(1);
}
