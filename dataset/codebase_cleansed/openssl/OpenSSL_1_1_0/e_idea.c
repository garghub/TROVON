static int idea_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, size_t inl)
{
BLOCK_CIPHER_ecb_loop()
IDEA_ecb_encrypt(in + i, out + i, &EVP_C_DATA(EVP_IDEA_KEY,ctx)->ks);
return 1;
}
static int idea_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
if (!enc) {
if (EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_OFB_MODE)
enc = 1;
else if (EVP_CIPHER_CTX_mode(ctx) == EVP_CIPH_CFB_MODE)
enc = 1;
}
if (enc)
IDEA_set_encrypt_key(key, &EVP_C_DATA(EVP_IDEA_KEY,ctx)->ks);
else {
IDEA_KEY_SCHEDULE tmp;
IDEA_set_encrypt_key(key, &tmp);
IDEA_set_decrypt_key(&tmp, &EVP_C_DATA(EVP_IDEA_KEY,ctx)->ks);
OPENSSL_cleanse((unsigned char *)&tmp, sizeof(IDEA_KEY_SCHEDULE));
}
return 1;
}
