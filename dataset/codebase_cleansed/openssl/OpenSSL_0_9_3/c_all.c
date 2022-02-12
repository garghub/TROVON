void SSLeay_add_all_algorithms(void)
{
SSLeay_add_all_ciphers();
SSLeay_add_all_digests();
}
void SSLeay_add_all_ciphers(void)
{
#ifndef NO_DES
EVP_add_cipher(EVP_des_cfb());
EVP_add_cipher(EVP_des_ede_cfb());
EVP_add_cipher(EVP_des_ede3_cfb());
EVP_add_cipher(EVP_des_ofb());
EVP_add_cipher(EVP_des_ede_ofb());
EVP_add_cipher(EVP_des_ede3_ofb());
EVP_add_cipher(EVP_desx_cbc());
EVP_add_cipher_alias(SN_desx_cbc,"DESX");
EVP_add_cipher_alias(SN_desx_cbc,"desx");
EVP_add_cipher(EVP_des_cbc());
EVP_add_cipher_alias(SN_des_cbc,"DES");
EVP_add_cipher_alias(SN_des_cbc,"des");
EVP_add_cipher(EVP_des_ede_cbc());
EVP_add_cipher(EVP_des_ede3_cbc());
EVP_add_cipher_alias(SN_des_ede3_cbc,"DES3");
EVP_add_cipher_alias(SN_des_ede3_cbc,"des3");
EVP_add_cipher(EVP_des_ecb());
EVP_add_cipher(EVP_des_ede());
EVP_add_cipher(EVP_des_ede3());
#endif
#ifndef NO_RC4
EVP_add_cipher(EVP_rc4());
EVP_add_cipher(EVP_rc4_40());
#endif
#ifndef NO_IDEA
EVP_add_cipher(EVP_idea_ecb());
EVP_add_cipher(EVP_idea_cfb());
EVP_add_cipher(EVP_idea_ofb());
EVP_add_cipher(EVP_idea_cbc());
EVP_add_cipher_alias(SN_idea_cbc,"IDEA");
EVP_add_cipher_alias(SN_idea_cbc,"idea");
#endif
#ifndef NO_RC2
EVP_add_cipher(EVP_rc2_ecb());
EVP_add_cipher(EVP_rc2_cfb());
EVP_add_cipher(EVP_rc2_ofb());
EVP_add_cipher(EVP_rc2_cbc());
EVP_add_cipher(EVP_rc2_40_cbc());
EVP_add_cipher(EVP_rc2_64_cbc());
EVP_add_cipher_alias(SN_rc2_cbc,"RC2");
EVP_add_cipher_alias(SN_rc2_cbc,"rc2");
#endif
#ifndef NO_BF
EVP_add_cipher(EVP_bf_ecb());
EVP_add_cipher(EVP_bf_cfb());
EVP_add_cipher(EVP_bf_ofb());
EVP_add_cipher(EVP_bf_cbc());
EVP_add_cipher_alias(SN_bf_cbc,"BF");
EVP_add_cipher_alias(SN_bf_cbc,"bf");
EVP_add_cipher_alias(SN_bf_cbc,"blowfish");
#endif
#ifndef NO_CAST
EVP_add_cipher(EVP_cast5_ecb());
EVP_add_cipher(EVP_cast5_cfb());
EVP_add_cipher(EVP_cast5_ofb());
EVP_add_cipher(EVP_cast5_cbc());
EVP_add_cipher_alias(SN_cast5_cbc,"CAST");
EVP_add_cipher_alias(SN_cast5_cbc,"cast");
EVP_add_cipher_alias(SN_cast5_cbc,"CAST-cbc");
EVP_add_cipher_alias(SN_cast5_cbc,"cast-cbc");
#endif
#ifndef NO_RC5
EVP_add_cipher(EVP_rc5_32_12_16_ecb());
EVP_add_cipher(EVP_rc5_32_12_16_cfb());
EVP_add_cipher(EVP_rc5_32_12_16_ofb());
EVP_add_cipher(EVP_rc5_32_12_16_cbc());
EVP_add_cipher_alias(SN_rc5_cbc,"rc5");
EVP_add_cipher_alias(SN_rc5_cbc,"RC5");
#endif
}
void SSLeay_add_all_digests(void)
{
#ifndef NO_MD2
EVP_add_digest(EVP_md2());
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
PKCS12_PBE_add();
}
