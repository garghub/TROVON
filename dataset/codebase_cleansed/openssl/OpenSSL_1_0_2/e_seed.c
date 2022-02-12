static int seed_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
SEED_set_key(key, ctx->cipher_data);
return 1;
}
