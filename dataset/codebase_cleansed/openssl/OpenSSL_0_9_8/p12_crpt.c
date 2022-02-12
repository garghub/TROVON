void PKCS12_PBE_add(void)
{
#ifndef OPENSSL_NO_RC4
EVP_PBE_alg_add(NID_pbe_WithSHA1And128BitRC4, EVP_rc4(), EVP_sha1(),
PKCS12_PBE_keyivgen);
EVP_PBE_alg_add(NID_pbe_WithSHA1And40BitRC4, EVP_rc4_40(), EVP_sha1(),
PKCS12_PBE_keyivgen);
#endif
#ifndef OPENSSL_NO_DES
EVP_PBE_alg_add(NID_pbe_WithSHA1And3_Key_TripleDES_CBC,
EVP_des_ede3_cbc(), EVP_sha1(), PKCS12_PBE_keyivgen);
EVP_PBE_alg_add(NID_pbe_WithSHA1And2_Key_TripleDES_CBC,
EVP_des_ede_cbc(), EVP_sha1(), PKCS12_PBE_keyivgen);
#endif
#ifndef OPENSSL_NO_RC2
EVP_PBE_alg_add(NID_pbe_WithSHA1And128BitRC2_CBC, EVP_rc2_cbc(),
EVP_sha1(), PKCS12_PBE_keyivgen);
EVP_PBE_alg_add(NID_pbe_WithSHA1And40BitRC2_CBC, EVP_rc2_40_cbc(),
EVP_sha1(), PKCS12_PBE_keyivgen);
#endif
}
int PKCS12_PBE_keyivgen(EVP_CIPHER_CTX *ctx, const char *pass, int passlen,
ASN1_TYPE *param, const EVP_CIPHER *cipher, const EVP_MD *md, int en_de)
{
PBEPARAM *pbe;
int saltlen, iter, ret;
unsigned char *salt;
const unsigned char *pbuf;
unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
pbuf = param->value.sequence->data;
if (!param || (param->type != V_ASN1_SEQUENCE) ||
!(pbe = d2i_PBEPARAM (NULL, &pbuf, param->value.sequence->length))) {
PKCS12err(PKCS12_F_PKCS12_PBE_KEYIVGEN,PKCS12_R_DECODE_ERROR);
return 0;
}
if (!pbe->iter) iter = 1;
else iter = ASN1_INTEGER_get (pbe->iter);
salt = pbe->salt->data;
saltlen = pbe->salt->length;
if (!PKCS12_key_gen (pass, passlen, salt, saltlen, PKCS12_KEY_ID,
iter, EVP_CIPHER_key_length(cipher), key, md)) {
PKCS12err(PKCS12_F_PKCS12_PBE_KEYIVGEN,PKCS12_R_KEY_GEN_ERROR);
PBEPARAM_free(pbe);
return 0;
}
if (!PKCS12_key_gen (pass, passlen, salt, saltlen, PKCS12_IV_ID,
iter, EVP_CIPHER_iv_length(cipher), iv, md)) {
PKCS12err(PKCS12_F_PKCS12_PBE_KEYIVGEN,PKCS12_R_IV_GEN_ERROR);
PBEPARAM_free(pbe);
return 0;
}
PBEPARAM_free(pbe);
ret = EVP_CipherInit_ex(ctx, cipher, NULL, key, iv, en_de);
OPENSSL_cleanse(key, EVP_MAX_KEY_LENGTH);
OPENSSL_cleanse(iv, EVP_MAX_IV_LENGTH);
return ret;
}
