void AES_ofb128_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char *ivec, int *num) {
unsigned int n;
unsigned long l=length;
assert(in && out && key && ivec && num);
n = *num;
while (l--) {
if (n == 0) {
AES_encrypt(ivec, ivec, key);
}
*(out++) = *(in++) ^ ivec[n];
n = (n+1) % AES_BLOCK_SIZE;
}
*num=n;
}
