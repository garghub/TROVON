static int cast_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
CAST_set_key(&data(ctx)->ks, EVP_CIPHER_CTX_key_length(ctx), key);
return 1;
}
