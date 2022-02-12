static int seed_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
const unsigned char *iv, int enc)
{
SEED_set_key(key, &EVP_C_DATA(EVP_SEED_KEY,ctx)->ks);
return 1;
}
