void SEED_cfb128_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const SEED_KEY_SCHEDULE *ks,
unsigned char ivec[SEED_BLOCK_SIZE], int *num, int enc)
{
CRYPTO_cfb128_encrypt(in,out,len,ks,ivec,num,enc,(block128_f)SEED_encrypt);
}
