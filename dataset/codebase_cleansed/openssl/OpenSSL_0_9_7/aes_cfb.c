void AES_cfb128_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char *ivec, int *num, const int enc) {
unsigned int n;
unsigned long l = length;
unsigned char c;
assert(in && out && key && ivec && num);
n = *num;
if (enc) {
while (l--) {
if (n == 0) {
AES_encrypt(ivec, ivec, key);
}
ivec[n] = *(out++) = *(in++) ^ ivec[n];
n = (n+1) % AES_BLOCK_SIZE;
}
} else {
while (l--) {
if (n == 0) {
AES_encrypt(ivec, ivec, key);
}
c = *(in);
*(out++) = *(in++) ^ ivec[n];
ivec[n] = c;
n = (n+1) % AES_BLOCK_SIZE;
}
}
*num=n;
}
