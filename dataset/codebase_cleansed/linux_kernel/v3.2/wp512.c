static void wp512_process_buffer(struct wp512_ctx *wctx) {
int i, r;
u64 K[8];
u64 block[8];
u64 state[8];
u64 L[8];
const __be64 *buffer = (const __be64 *)wctx->buffer;
for (i = 0; i < 8; i++)
block[i] = be64_to_cpu(buffer[i]);
state[0] = block[0] ^ (K[0] = wctx->hash[0]);
state[1] = block[1] ^ (K[1] = wctx->hash[1]);
state[2] = block[2] ^ (K[2] = wctx->hash[2]);
state[3] = block[3] ^ (K[3] = wctx->hash[3]);
state[4] = block[4] ^ (K[4] = wctx->hash[4]);
state[5] = block[5] ^ (K[5] = wctx->hash[5]);
state[6] = block[6] ^ (K[6] = wctx->hash[6]);
state[7] = block[7] ^ (K[7] = wctx->hash[7]);
for (r = 0; r < WHIRLPOOL_ROUNDS; r++) {
L[0] = C0[(int)(K[0] >> 56) ] ^
C1[(int)(K[7] >> 48) & 0xff] ^
C2[(int)(K[6] >> 40) & 0xff] ^
C3[(int)(K[5] >> 32) & 0xff] ^
C4[(int)(K[4] >> 24) & 0xff] ^
C5[(int)(K[3] >> 16) & 0xff] ^
C6[(int)(K[2] >> 8) & 0xff] ^
C7[(int)(K[1] ) & 0xff] ^
rc[r];
L[1] = C0[(int)(K[1] >> 56) ] ^
C1[(int)(K[0] >> 48) & 0xff] ^
C2[(int)(K[7] >> 40) & 0xff] ^
C3[(int)(K[6] >> 32) & 0xff] ^
C4[(int)(K[5] >> 24) & 0xff] ^
C5[(int)(K[4] >> 16) & 0xff] ^
C6[(int)(K[3] >> 8) & 0xff] ^
C7[(int)(K[2] ) & 0xff];
L[2] = C0[(int)(K[2] >> 56) ] ^
C1[(int)(K[1] >> 48) & 0xff] ^
C2[(int)(K[0] >> 40) & 0xff] ^
C3[(int)(K[7] >> 32) & 0xff] ^
C4[(int)(K[6] >> 24) & 0xff] ^
C5[(int)(K[5] >> 16) & 0xff] ^
C6[(int)(K[4] >> 8) & 0xff] ^
C7[(int)(K[3] ) & 0xff];
L[3] = C0[(int)(K[3] >> 56) ] ^
C1[(int)(K[2] >> 48) & 0xff] ^
C2[(int)(K[1] >> 40) & 0xff] ^
C3[(int)(K[0] >> 32) & 0xff] ^
C4[(int)(K[7] >> 24) & 0xff] ^
C5[(int)(K[6] >> 16) & 0xff] ^
C6[(int)(K[5] >> 8) & 0xff] ^
C7[(int)(K[4] ) & 0xff];
L[4] = C0[(int)(K[4] >> 56) ] ^
C1[(int)(K[3] >> 48) & 0xff] ^
C2[(int)(K[2] >> 40) & 0xff] ^
C3[(int)(K[1] >> 32) & 0xff] ^
C4[(int)(K[0] >> 24) & 0xff] ^
C5[(int)(K[7] >> 16) & 0xff] ^
C6[(int)(K[6] >> 8) & 0xff] ^
C7[(int)(K[5] ) & 0xff];
L[5] = C0[(int)(K[5] >> 56) ] ^
C1[(int)(K[4] >> 48) & 0xff] ^
C2[(int)(K[3] >> 40) & 0xff] ^
C3[(int)(K[2] >> 32) & 0xff] ^
C4[(int)(K[1] >> 24) & 0xff] ^
C5[(int)(K[0] >> 16) & 0xff] ^
C6[(int)(K[7] >> 8) & 0xff] ^
C7[(int)(K[6] ) & 0xff];
L[6] = C0[(int)(K[6] >> 56) ] ^
C1[(int)(K[5] >> 48) & 0xff] ^
C2[(int)(K[4] >> 40) & 0xff] ^
C3[(int)(K[3] >> 32) & 0xff] ^
C4[(int)(K[2] >> 24) & 0xff] ^
C5[(int)(K[1] >> 16) & 0xff] ^
C6[(int)(K[0] >> 8) & 0xff] ^
C7[(int)(K[7] ) & 0xff];
L[7] = C0[(int)(K[7] >> 56) ] ^
C1[(int)(K[6] >> 48) & 0xff] ^
C2[(int)(K[5] >> 40) & 0xff] ^
C3[(int)(K[4] >> 32) & 0xff] ^
C4[(int)(K[3] >> 24) & 0xff] ^
C5[(int)(K[2] >> 16) & 0xff] ^
C6[(int)(K[1] >> 8) & 0xff] ^
C7[(int)(K[0] ) & 0xff];
K[0] = L[0];
K[1] = L[1];
K[2] = L[2];
K[3] = L[3];
K[4] = L[4];
K[5] = L[5];
K[6] = L[6];
K[7] = L[7];
L[0] = C0[(int)(state[0] >> 56) ] ^
C1[(int)(state[7] >> 48) & 0xff] ^
C2[(int)(state[6] >> 40) & 0xff] ^
C3[(int)(state[5] >> 32) & 0xff] ^
C4[(int)(state[4] >> 24) & 0xff] ^
C5[(int)(state[3] >> 16) & 0xff] ^
C6[(int)(state[2] >> 8) & 0xff] ^
C7[(int)(state[1] ) & 0xff] ^
K[0];
L[1] = C0[(int)(state[1] >> 56) ] ^
C1[(int)(state[0] >> 48) & 0xff] ^
C2[(int)(state[7] >> 40) & 0xff] ^
C3[(int)(state[6] >> 32) & 0xff] ^
C4[(int)(state[5] >> 24) & 0xff] ^
C5[(int)(state[4] >> 16) & 0xff] ^
C6[(int)(state[3] >> 8) & 0xff] ^
C7[(int)(state[2] ) & 0xff] ^
K[1];
L[2] = C0[(int)(state[2] >> 56) ] ^
C1[(int)(state[1] >> 48) & 0xff] ^
C2[(int)(state[0] >> 40) & 0xff] ^
C3[(int)(state[7] >> 32) & 0xff] ^
C4[(int)(state[6] >> 24) & 0xff] ^
C5[(int)(state[5] >> 16) & 0xff] ^
C6[(int)(state[4] >> 8) & 0xff] ^
C7[(int)(state[3] ) & 0xff] ^
K[2];
L[3] = C0[(int)(state[3] >> 56) ] ^
C1[(int)(state[2] >> 48) & 0xff] ^
C2[(int)(state[1] >> 40) & 0xff] ^
C3[(int)(state[0] >> 32) & 0xff] ^
C4[(int)(state[7] >> 24) & 0xff] ^
C5[(int)(state[6] >> 16) & 0xff] ^
C6[(int)(state[5] >> 8) & 0xff] ^
C7[(int)(state[4] ) & 0xff] ^
K[3];
L[4] = C0[(int)(state[4] >> 56) ] ^
C1[(int)(state[3] >> 48) & 0xff] ^
C2[(int)(state[2] >> 40) & 0xff] ^
C3[(int)(state[1] >> 32) & 0xff] ^
C4[(int)(state[0] >> 24) & 0xff] ^
C5[(int)(state[7] >> 16) & 0xff] ^
C6[(int)(state[6] >> 8) & 0xff] ^
C7[(int)(state[5] ) & 0xff] ^
K[4];
L[5] = C0[(int)(state[5] >> 56) ] ^
C1[(int)(state[4] >> 48) & 0xff] ^
C2[(int)(state[3] >> 40) & 0xff] ^
C3[(int)(state[2] >> 32) & 0xff] ^
C4[(int)(state[1] >> 24) & 0xff] ^
C5[(int)(state[0] >> 16) & 0xff] ^
C6[(int)(state[7] >> 8) & 0xff] ^
C7[(int)(state[6] ) & 0xff] ^
K[5];
L[6] = C0[(int)(state[6] >> 56) ] ^
C1[(int)(state[5] >> 48) & 0xff] ^
C2[(int)(state[4] >> 40) & 0xff] ^
C3[(int)(state[3] >> 32) & 0xff] ^
C4[(int)(state[2] >> 24) & 0xff] ^
C5[(int)(state[1] >> 16) & 0xff] ^
C6[(int)(state[0] >> 8) & 0xff] ^
C7[(int)(state[7] ) & 0xff] ^
K[6];
L[7] = C0[(int)(state[7] >> 56) ] ^
C1[(int)(state[6] >> 48) & 0xff] ^
C2[(int)(state[5] >> 40) & 0xff] ^
C3[(int)(state[4] >> 32) & 0xff] ^
C4[(int)(state[3] >> 24) & 0xff] ^
C5[(int)(state[2] >> 16) & 0xff] ^
C6[(int)(state[1] >> 8) & 0xff] ^
C7[(int)(state[0] ) & 0xff] ^
K[7];
state[0] = L[0];
state[1] = L[1];
state[2] = L[2];
state[3] = L[3];
state[4] = L[4];
state[5] = L[5];
state[6] = L[6];
state[7] = L[7];
}
wctx->hash[0] ^= state[0] ^ block[0];
wctx->hash[1] ^= state[1] ^ block[1];
wctx->hash[2] ^= state[2] ^ block[2];
wctx->hash[3] ^= state[3] ^ block[3];
wctx->hash[4] ^= state[4] ^ block[4];
wctx->hash[5] ^= state[5] ^ block[5];
wctx->hash[6] ^= state[6] ^ block[6];
wctx->hash[7] ^= state[7] ^ block[7];
}
static int wp512_init(struct shash_desc *desc) {
struct wp512_ctx *wctx = shash_desc_ctx(desc);
int i;
memset(wctx->bitLength, 0, 32);
wctx->bufferBits = wctx->bufferPos = 0;
wctx->buffer[0] = 0;
for (i = 0; i < 8; i++) {
wctx->hash[i] = 0L;
}
return 0;
}
static int wp512_update(struct shash_desc *desc, const u8 *source,
unsigned int len)
{
struct wp512_ctx *wctx = shash_desc_ctx(desc);
int sourcePos = 0;
unsigned int bits_len = len * 8;
int sourceGap = (8 - ((int)bits_len & 7)) & 7;
int bufferRem = wctx->bufferBits & 7;
int i;
u32 b, carry;
u8 *buffer = wctx->buffer;
u8 *bitLength = wctx->bitLength;
int bufferBits = wctx->bufferBits;
int bufferPos = wctx->bufferPos;
u64 value = bits_len;
for (i = 31, carry = 0; i >= 0 && (carry != 0 || value != 0ULL); i--) {
carry += bitLength[i] + ((u32)value & 0xff);
bitLength[i] = (u8)carry;
carry >>= 8;
value >>= 8;
}
while (bits_len > 8) {
b = ((source[sourcePos] << sourceGap) & 0xff) |
((source[sourcePos + 1] & 0xff) >> (8 - sourceGap));
buffer[bufferPos++] |= (u8)(b >> bufferRem);
bufferBits += 8 - bufferRem;
if (bufferBits == WP512_BLOCK_SIZE * 8) {
wp512_process_buffer(wctx);
bufferBits = bufferPos = 0;
}
buffer[bufferPos] = b << (8 - bufferRem);
bufferBits += bufferRem;
bits_len -= 8;
sourcePos++;
}
if (bits_len > 0) {
b = (source[sourcePos] << sourceGap) & 0xff;
buffer[bufferPos] |= b >> bufferRem;
} else {
b = 0;
}
if (bufferRem + bits_len < 8) {
bufferBits += bits_len;
} else {
bufferPos++;
bufferBits += 8 - bufferRem;
bits_len -= 8 - bufferRem;
if (bufferBits == WP512_BLOCK_SIZE * 8) {
wp512_process_buffer(wctx);
bufferBits = bufferPos = 0;
}
buffer[bufferPos] = b << (8 - bufferRem);
bufferBits += (int)bits_len;
}
wctx->bufferBits = bufferBits;
wctx->bufferPos = bufferPos;
return 0;
}
static int wp512_final(struct shash_desc *desc, u8 *out)
{
struct wp512_ctx *wctx = shash_desc_ctx(desc);
int i;
u8 *buffer = wctx->buffer;
u8 *bitLength = wctx->bitLength;
int bufferBits = wctx->bufferBits;
int bufferPos = wctx->bufferPos;
__be64 *digest = (__be64 *)out;
buffer[bufferPos] |= 0x80U >> (bufferBits & 7);
bufferPos++;
if (bufferPos > WP512_BLOCK_SIZE - WP512_LENGTHBYTES) {
if (bufferPos < WP512_BLOCK_SIZE) {
memset(&buffer[bufferPos], 0, WP512_BLOCK_SIZE - bufferPos);
}
wp512_process_buffer(wctx);
bufferPos = 0;
}
if (bufferPos < WP512_BLOCK_SIZE - WP512_LENGTHBYTES) {
memset(&buffer[bufferPos], 0,
(WP512_BLOCK_SIZE - WP512_LENGTHBYTES) - bufferPos);
}
bufferPos = WP512_BLOCK_SIZE - WP512_LENGTHBYTES;
memcpy(&buffer[WP512_BLOCK_SIZE - WP512_LENGTHBYTES],
bitLength, WP512_LENGTHBYTES);
wp512_process_buffer(wctx);
for (i = 0; i < WP512_DIGEST_SIZE/8; i++)
digest[i] = cpu_to_be64(wctx->hash[i]);
wctx->bufferBits = bufferBits;
wctx->bufferPos = bufferPos;
return 0;
}
static int wp384_final(struct shash_desc *desc, u8 *out)
{
u8 D[64];
wp512_final(desc, D);
memcpy (out, D, WP384_DIGEST_SIZE);
memset (D, 0, WP512_DIGEST_SIZE);
return 0;
}
static int wp256_final(struct shash_desc *desc, u8 *out)
{
u8 D[64];
wp512_final(desc, D);
memcpy (out, D, WP256_DIGEST_SIZE);
memset (D, 0, WP512_DIGEST_SIZE);
return 0;
}
static int __init wp512_mod_init(void)
{
int ret = 0;
ret = crypto_register_shash(&wp512);
if (ret < 0)
goto out;
ret = crypto_register_shash(&wp384);
if (ret < 0)
{
crypto_unregister_shash(&wp512);
goto out;
}
ret = crypto_register_shash(&wp256);
if (ret < 0)
{
crypto_unregister_shash(&wp512);
crypto_unregister_shash(&wp384);
}
out:
return ret;
}
static void __exit wp512_mod_fini(void)
{
crypto_unregister_shash(&wp512);
crypto_unregister_shash(&wp384);
crypto_unregister_shash(&wp256);
}
