void AES_ctr128_encrypt(const unsigned char *in, unsigned char *out,
size_t length, const AES_KEY *key,
unsigned char ivec[AES_BLOCK_SIZE],
unsigned char ecount_buf[AES_BLOCK_SIZE],
unsigned int *num) {
CRYPTO_ctr128_encrypt(in,out,length,key,ivec,ecount_buf,num,(block128_f)AES_encrypt);
}
