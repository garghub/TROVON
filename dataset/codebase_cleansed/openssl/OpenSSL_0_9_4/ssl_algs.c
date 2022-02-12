int SSL_library_init(void)
{
#ifndef NO_DES
EVP_add_cipher(EVP_des_cbc());
EVP_add_cipher(EVP_des_ede3_cbc());
#endif
#ifndef NO_IDEA
EVP_add_cipher(EVP_idea_cbc());
#endif
#ifndef NO_RC4
EVP_add_cipher(EVP_rc4());
#endif
#ifndef NO_RC2
EVP_add_cipher(EVP_rc2_cbc());
#endif
#ifndef NO_MD2
EVP_add_digest(EVP_md2());
#endif
#ifndef NO_MD5
EVP_add_digest(EVP_md5());
EVP_add_digest_alias(SN_md5,"ssl2-md5");
EVP_add_digest_alias(SN_md5,"ssl3-md5");
#endif
#ifndef NO_SHA
EVP_add_digest(EVP_sha1());
EVP_add_digest_alias(SN_sha1,"ssl3-sha1");
#endif
#if !defined(NO_SHA) && !defined(NO_DSA)
EVP_add_digest(EVP_dss1());
#endif
#if 0
EVP_add_digest(EVP_sha());
EVP_add_digest(EVP_dss());
#endif
return(1);
}
