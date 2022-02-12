static void AES_ctr128_inc(unsigned char *counter) {
unsigned long c;
#ifdef L_ENDIAN
c = GETU32(counter + 8);
c++;
PUTU32(counter + 8, c);
#else
c = GETU32(counter + 4);
c++;
PUTU32(counter + 4, c);
#endif
if (c)
return;
#ifdef L_ENDIAN
c = GETU32(counter + 12);
c++;
PUTU32(counter + 12, c);
#else
c = GETU32(counter + 0);
c++;
PUTU32(counter + 0, c);
#endif
}
void AES_ctr128_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char counter[AES_BLOCK_SIZE],
unsigned char ecount_buf[AES_BLOCK_SIZE],
unsigned int *num) {
unsigned int n;
unsigned long l=length;
assert(in && out && key && counter && num);
assert(*num < AES_BLOCK_SIZE);
n = *num;
while (l--) {
if (n == 0) {
AES_encrypt(counter, ecount_buf, key);
AES_ctr128_inc(counter);
}
*(out++) = *(in++) ^ ecount_buf[n];
n = (n+1) % AES_BLOCK_SIZE;
}
*num=n;
}
