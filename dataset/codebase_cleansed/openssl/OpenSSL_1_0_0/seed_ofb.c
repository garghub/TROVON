void SEED_ofb128_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const SEED_KEY_SCHEDULE *ks,
unsigned char ivec[SEED_BLOCK_SIZE], int *num)
{
CRYPTO_ofb128_encrypt(in,out,len,ks,ivec,num,(block128_f)SEED_encrypt);
}
