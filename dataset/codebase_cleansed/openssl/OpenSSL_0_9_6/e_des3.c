static int des_ede_ecb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
BLOCK_CIPHER_ecb_loop()
des_ecb3_encrypt((des_cblock *)(in + i), (des_cblock *)(out + i),
ctx->c.des_ede.ks1, ctx->c.des_ede.ks2, ctx->c.des_ede.ks3,
ctx->encrypt);
return 1;
}
static int des_ede_ofb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
des_ede3_ofb64_encrypt(in, out, (long)inl,
ctx->c.des_ede.ks1, ctx->c.des_ede.ks2, ctx->c.des_ede.ks3,
(des_cblock *)ctx->iv, &ctx->num);
return 1;
}
static int des_ede_cbc_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
des_ede3_cbc_encrypt(in, out, (long)inl,
ctx->c.des_ede.ks1, ctx->c.des_ede.ks2, ctx->c.des_ede.ks3,
(des_cblock *)ctx->iv, ctx->encrypt);
return 1;
}
static int des_ede_cfb_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
const unsigned char *in, unsigned int inl)
{
des_ede3_cfb64_encrypt(in, out, (long)inl,
ctx->c.des_ede.ks1, ctx->c.des_ede.ks2, ctx->c.des_ede.ks3,
(des_cblock *)ctx->iv, &ctx->num, ctx->encrypt);
return 1;
}
static int des_ede_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
des_set_key_unchecked(&deskey[0],ctx->c.des_ede.ks1);
des_set_key_unchecked(&deskey[1],ctx->c.des_ede.ks2);
memcpy( (char *)ctx->c.des_ede.ks3,
(char *)ctx->c.des_ede.ks1,
sizeof(ctx->c.des_ede.ks1));
return 1;
}
static int des_ede3_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
des_cblock *deskey = (des_cblock *)key;
des_set_key_unchecked(&deskey[0],ctx->c.des_ede.ks1);
des_set_key_unchecked(&deskey[1],ctx->c.des_ede.ks2);
des_set_key_unchecked(&deskey[2],ctx->c.des_ede.ks3);
return 1;
}
EVP_CIPHER *EVP_des_ede(void)
{
return &des_ede_ecb;
}
EVP_CIPHER *EVP_des_ede3(void)
{
return &des_ede3_ecb;
}
