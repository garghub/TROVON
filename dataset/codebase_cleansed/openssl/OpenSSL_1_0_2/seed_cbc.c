void SEED_cbc_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const SEED_KEY_SCHEDULE *ks,
unsigned char ivec[SEED_BLOCK_SIZE], int enc)
{
if (enc)
CRYPTO_cbc128_encrypt(in, out, len, ks, ivec,
(block128_f) SEED_encrypt);
else
CRYPTO_cbc128_decrypt(in, out, len, ks, ivec,
(block128_f) SEED_decrypt);
}
