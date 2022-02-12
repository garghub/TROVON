void OpenSSL_add_all_digests(void)
{
#ifndef NO_MD2
EVP_add_digest(EVP_md2());
#endif
#ifndef NO_MD4
EVP_add_digest(EVP_md4());
#endif
#ifndef NO_MD5
EVP_add_digest(EVP_md5());
EVP_add_digest_alias(SN_md5,"ssl2-md5");
EVP_add_digest_alias(SN_md5,"ssl3-md5");
#endif
#ifndef NO_SHA
EVP_add_digest(EVP_sha());
#ifndef NO_DSA
EVP_add_digest(EVP_dss());
#endif
#endif
#ifndef NO_SHA
EVP_add_digest(EVP_sha1());
EVP_add_digest_alias(SN_sha1,"ssl3-sha1");
EVP_add_digest_alias(SN_sha1WithRSAEncryption,SN_sha1WithRSA);
#ifndef NO_DSA
EVP_add_digest(EVP_dss1());
EVP_add_digest_alias(SN_dsaWithSHA1,SN_dsaWithSHA1_2);
EVP_add_digest_alias(SN_dsaWithSHA1,"DSS1");
EVP_add_digest_alias(SN_dsaWithSHA1,"dss1");
#endif
#endif
#if !defined(NO_MDC2) && !defined(NO_DES)
EVP_add_digest(EVP_mdc2());
#endif
#ifndef NO_RIPEMD
EVP_add_digest(EVP_ripemd160());
EVP_add_digest_alias(SN_ripemd160,"ripemd");
EVP_add_digest_alias(SN_ripemd160,"rmd160");
#endif
}
