void PKCS5_PBE_add(void)
{
#ifndef OPENSSL_NO_DES
# ifndef OPENSSL_NO_MD5
EVP_PBE_alg_add(NID_pbeWithMD5AndDES_CBC, EVP_des_cbc(), EVP_md5(),
PKCS5_PBE_keyivgen);
# endif
# ifndef OPENSSL_NO_MD2
EVP_PBE_alg_add(NID_pbeWithMD2AndDES_CBC, EVP_des_cbc(), EVP_md2(),
PKCS5_PBE_keyivgen);
# endif
# ifndef OPENSSL_NO_SHA
EVP_PBE_alg_add(NID_pbeWithSHA1AndDES_CBC, EVP_des_cbc(), EVP_sha1(),
PKCS5_PBE_keyivgen);
# endif
#endif
#ifndef OPENSSL_NO_RC2
# ifndef OPENSSL_NO_MD5
EVP_PBE_alg_add(NID_pbeWithMD5AndRC2_CBC, EVP_rc2_64_cbc(), EVP_md5(),
PKCS5_PBE_keyivgen);
# endif
# ifndef OPENSSL_NO_MD2
EVP_PBE_alg_add(NID_pbeWithMD2AndRC2_CBC, EVP_rc2_64_cbc(), EVP_md2(),
PKCS5_PBE_keyivgen);
# endif
# ifndef OPENSSL_NO_SHA
EVP_PBE_alg_add(NID_pbeWithSHA1AndRC2_CBC, EVP_rc2_64_cbc(), EVP_sha1(),
PKCS5_PBE_keyivgen);
# endif
#endif
#ifndef OPENSSL_NO_HMAC
EVP_PBE_alg_add(NID_pbes2, NULL, NULL, PKCS5_v2_PBE_keyivgen);
#endif
}
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *cctx, const char *pass, int passlen,
ASN1_TYPE *param, const EVP_CIPHER *cipher, const EVP_MD *md,
int en_de)
{
EVP_MD_CTX ctx;
unsigned char md_tmp[EVP_MAX_MD_SIZE];
unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
int i;
PBEPARAM *pbe;
int saltlen, iter;
unsigned char *salt;
const unsigned char *pbuf;
pbuf = param->value.sequence->data;
if (!param || (param->type != V_ASN1_SEQUENCE) ||
!(pbe = d2i_PBEPARAM (NULL, &pbuf, param->value.sequence->length))) {
EVPerr(EVP_F_PKCS5_PBE_KEYIVGEN,EVP_R_DECODE_ERROR);
return 0;
}
if (!pbe->iter) iter = 1;
else iter = ASN1_INTEGER_get (pbe->iter);
salt = pbe->salt->data;
saltlen = pbe->salt->length;
if(!pass) passlen = 0;
else if(passlen == -1) passlen = strlen(pass);
EVP_MD_CTX_init(&ctx);
EVP_DigestInit_ex(&ctx, md, NULL);
EVP_DigestUpdate(&ctx, pass, passlen);
EVP_DigestUpdate(&ctx, salt, saltlen);
PBEPARAM_free(pbe);
EVP_DigestFinal_ex(&ctx, md_tmp, NULL);
for (i = 1; i < iter; i++) {
EVP_DigestInit_ex(&ctx, md, NULL);
EVP_DigestUpdate(&ctx, md_tmp, EVP_MD_size(md));
EVP_DigestFinal_ex (&ctx, md_tmp, NULL);
}
EVP_MD_CTX_cleanup(&ctx);
OPENSSL_assert(EVP_CIPHER_key_length(cipher) <= (int)sizeof(md_tmp));
memcpy(key, md_tmp, EVP_CIPHER_key_length(cipher));
OPENSSL_assert(EVP_CIPHER_iv_length(cipher) <= 16);
memcpy(iv, md_tmp + (16 - EVP_CIPHER_iv_length(cipher)),
EVP_CIPHER_iv_length(cipher));
EVP_CipherInit_ex(cctx, cipher, NULL, key, iv, en_de);
OPENSSL_cleanse(md_tmp, EVP_MAX_MD_SIZE);
OPENSSL_cleanse(key, EVP_MAX_KEY_LENGTH);
OPENSSL_cleanse(iv, EVP_MAX_IV_LENGTH);
return 1;
}
