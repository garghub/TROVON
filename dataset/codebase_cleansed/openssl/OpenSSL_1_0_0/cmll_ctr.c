void Camellia_ctr128_encrypt(const unsigned char *in, unsigned char *out,
size_t length, const CAMELLIA_KEY *key,
unsigned char ivec[CAMELLIA_BLOCK_SIZE],
unsigned char ecount_buf[CAMELLIA_BLOCK_SIZE],
unsigned int *num)
{
CRYPTO_ctr128_encrypt(in,out,length,key,ivec,ecount_buf,num,(block128_f)Camellia_encrypt);
}
