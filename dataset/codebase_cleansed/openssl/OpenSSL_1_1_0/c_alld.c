void openssl_add_all_digests_int(void)
{
#ifndef OPENSSL_NO_MD4
EVP_add_digest(EVP_md4());
#endif
#ifndef OPENSSL_NO_MD5
EVP_add_digest(EVP_md5());
EVP_add_digest_alias(SN_md5, "ssl3-md5");
EVP_add_digest(EVP_md5_sha1());
#endif
EVP_add_digest(EVP_sha1());
EVP_add_digest_alias(SN_sha1, "ssl3-sha1");
EVP_add_digest_alias(SN_sha1WithRSAEncryption, SN_sha1WithRSA);
#if !defined(OPENSSL_NO_MDC2) && !defined(OPENSSL_NO_DES)
EVP_add_digest(EVP_mdc2());
#endif
#ifndef OPENSSL_NO_RMD160
EVP_add_digest(EVP_ripemd160());
EVP_add_digest_alias(SN_ripemd160, "ripemd");
EVP_add_digest_alias(SN_ripemd160, "rmd160");
#endif
EVP_add_digest(EVP_sha224());
EVP_add_digest(EVP_sha256());
EVP_add_digest(EVP_sha384());
EVP_add_digest(EVP_sha512());
#ifndef OPENSSL_NO_WHIRLPOOL
EVP_add_digest(EVP_whirlpool());
#endif
#ifndef OPENSSL_NO_BLAKE2
EVP_add_digest(EVP_blake2b512());
EVP_add_digest(EVP_blake2s256());
#endif
}
