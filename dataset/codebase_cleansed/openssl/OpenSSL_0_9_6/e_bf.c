static int bf_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
BF_set_key(&(ctx->c.bf_ks),EVP_CIPHER_CTX_key_length(ctx),key);
return 1;
}
