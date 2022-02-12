void PKCS12_PBE_add(void)
{
#ifndef NO_RC4
EVP_PBE_alg_add(NID_pbe_WithSHA1And128BitRC4, EVP_rc4(), EVP_sha1(),
PKCS12_PBE_keyivgen);
EVP_PBE_alg_add(NID_pbe_WithSHA1And40BitRC4, EVP_rc4_40(), EVP_sha1(),
PKCS12_PBE_keyivgen);
#endif
EVP_PBE_alg_add(NID_pbe_WithSHA1And3_Key_TripleDES_CBC,
EVP_des_ede3_cbc(), EVP_sha1(), PKCS12_PBE_keyivgen);
EVP_PBE_alg_add(NID_pbe_WithSHA1And2_Key_TripleDES_CBC,
EVP_des_ede_cbc(), EVP_sha1(), PKCS12_PBE_keyivgen);
#ifndef NO_RC2
EVP_PBE_alg_add(NID_pbe_WithSHA1And128BitRC2_CBC, EVP_rc2_cbc(),
EVP_sha1(), PKCS12_PBE_keyivgen);
EVP_PBE_alg_add(NID_pbe_WithSHA1And40BitRC2_CBC, EVP_rc2_40_cbc(),
EVP_sha1(), PKCS12_PBE_keyivgen);
#endif
}
int PKCS12_PBE_keyivgen (const char *pass, int passlen, unsigned char *salt,
int saltlen, int iter, EVP_CIPHER *cipher, EVP_MD *md,
unsigned char *key, unsigned char *iv)
{
if (!PKCS12_key_gen (pass, passlen, salt, saltlen, PKCS12_KEY_ID,
iter, EVP_CIPHER_key_length(cipher), key, md)) {
PKCS12err(PKCS12_F_PKCS12_PBE_KEYIVGEN,PKCS12_R_KEY_GEN_ERROR);
return 0;
}
if (!PKCS12_key_gen (pass, passlen, salt, saltlen, PKCS12_IV_ID,
iter, EVP_CIPHER_iv_length(cipher), iv, md)) {
PKCS12err(PKCS12_F_PKCS12_PBE_KEYIVGEN,PKCS12_R_IV_GEN_ERROR);
return 0;
}
return 1;
}
