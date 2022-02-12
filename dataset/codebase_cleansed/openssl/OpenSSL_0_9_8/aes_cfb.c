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
void AES_cfbr_encrypt_block(const unsigned char *in,unsigned char *out,
const int nbits,const AES_KEY *key,
unsigned char *ivec,const int enc)
{
int n,rem,num;
unsigned char ovec[AES_BLOCK_SIZE*2];
if (nbits<=0 || nbits>128) return;
memcpy(ovec,ivec,AES_BLOCK_SIZE);
AES_encrypt(ivec,ivec,key);
num = (nbits+7)/8;
if (enc)
for(n=0 ; n < num ; ++n)
out[n] = (ovec[AES_BLOCK_SIZE+n] = in[n] ^ ivec[n]);
else
for(n=0 ; n < num ; ++n)
out[n] = (ovec[AES_BLOCK_SIZE+n] = in[n]) ^ ivec[n];
rem = nbits%8;
num = nbits/8;
if(rem==0)
memcpy(ivec,ovec+num,AES_BLOCK_SIZE);
else
for(n=0 ; n < AES_BLOCK_SIZE ; ++n)
ivec[n] = ovec[n+num]<<rem | ovec[n+num+1]>>(8-rem);
}
void AES_cfb1_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char *ivec, int *num, const int enc)
{
unsigned int n;
unsigned char c[1],d[1];
assert(in && out && key && ivec && num);
assert(*num == 0);
memset(out,0,(length+7)/8);
for(n=0 ; n < length ; ++n)
{
c[0]=(in[n/8]&(1 << (7-n%8))) ? 0x80 : 0;
AES_cfbr_encrypt_block(c,d,1,key,ivec,enc);
out[n/8]=(out[n/8]&~(1 << (7-n%8)))|((d[0]&0x80) >> (n%8));
}
}
void AES_cfb8_encrypt(const unsigned char *in, unsigned char *out,
const unsigned long length, const AES_KEY *key,
unsigned char *ivec, int *num, const int enc)
{
unsigned int n;
assert(in && out && key && ivec && num);
assert(*num == 0);
for(n=0 ; n < length ; ++n)
AES_cfbr_encrypt_block(&in[n],&out[n],8,key,ivec,enc);
}
