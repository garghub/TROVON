static void ctr128_inc(unsigned char *counter) {
u32 c,n=16;
do {
n -= 4;
c = GETU32(counter+n);
++c; c &= 0xFFFFFFFF;
PUTU32(counter + n, c);
if (c) return;
} while (n);
}
static void ctr128_inc_aligned(unsigned char *counter) {
size_t *data,c,n;
const union { long one; char little; } is_endian = {1};
if (is_endian.little) {
ctr128_inc(counter);
return;
}
data = (size_t *)counter;
n = 16/sizeof(size_t);
do {
--n;
c = data[n];
++c;
data[n] = c;
if (c) return;
} while (n);
}
void CRYPTO_ctr128_encrypt(const unsigned char *in, unsigned char *out,
size_t len, const void *key,
unsigned char ivec[16], unsigned char ecount_buf[16],
unsigned int *num, block128_f block)
{
unsigned int n;
size_t l=0;
assert(in && out && key && ecount_buf && num);
assert(*num < 16);
n = *num;
#if !defined(OPENSSL_SMALL_FOOTPRINT)
if (16%sizeof(size_t) == 0) do {
while (n && len) {
*(out++) = *(in++) ^ ecount_buf[n];
--len;
n = (n+1) % 16;
}
#if defined(STRICT_ALIGNMENT)
if (((size_t)in|(size_t)out|(size_t)ivec)%sizeof(size_t) != 0)
break;
#endif
while (len>=16) {
(*block)(ivec, ecount_buf, key);
ctr128_inc_aligned(ivec);
for (n=0; n<16; n+=sizeof(size_t))
*(size_t *)(out+n) =
*(size_t *)(in+n) ^ *(size_t *)(ecount_buf+n);
len -= 16;
out += 16;
in += 16;
}
n = 0;
if (len) {
(*block)(ivec, ecount_buf, key);
ctr128_inc_aligned(ivec);
while (len--) {
out[n] = in[n] ^ ecount_buf[n];
++n;
}
}
*num = n;
return;
} while(0);
#endif
while (l<len) {
if (n==0) {
(*block)(ivec, ecount_buf, key);
ctr128_inc(ivec);
}
out[l] = in[l] ^ ecount_buf[n];
++l;
n = (n+1) % 16;
}
*num=n;
}
