size_t Poly1305_ctx_size ()
{
return sizeof(struct poly1305_context);
}
static unsigned int U8TOU32(const unsigned char *p)
{
return (((unsigned int)(p[0] & 0xff)) |
((unsigned int)(p[1] & 0xff) << 8) |
((unsigned int)(p[2] & 0xff) << 16) |
((unsigned int)(p[3] & 0xff) << 24));
}
static u64 U8TOU64(const unsigned char *p)
{
return (((u64)(p[0] & 0xff)) |
((u64)(p[1] & 0xff) << 8) |
((u64)(p[2] & 0xff) << 16) |
((u64)(p[3] & 0xff) << 24) |
((u64)(p[4] & 0xff) << 32) |
((u64)(p[5] & 0xff) << 40) |
((u64)(p[6] & 0xff) << 48) |
((u64)(p[7] & 0xff) << 56));
}
static void U64TO8(unsigned char *p, u64 v)
{
p[0] = (unsigned char)((v) & 0xff);
p[1] = (unsigned char)((v >> 8) & 0xff);
p[2] = (unsigned char)((v >> 16) & 0xff);
p[3] = (unsigned char)((v >> 24) & 0xff);
p[4] = (unsigned char)((v >> 32) & 0xff);
p[5] = (unsigned char)((v >> 40) & 0xff);
p[6] = (unsigned char)((v >> 48) & 0xff);
p[7] = (unsigned char)((v >> 56) & 0xff);
}
static void poly1305_init(void *ctx, const unsigned char key[16])
{
poly1305_internal *st = (poly1305_internal *) ctx;
st->h[0] = 0;
st->h[1] = 0;
st->h[2] = 0;
st->r[0] = U8TOU64(&key[0]) & 0x0ffffffc0fffffff;
st->r[1] = U8TOU64(&key[8]) & 0x0ffffffc0ffffffc;
}
static void
poly1305_blocks(void *ctx, const unsigned char *inp, size_t len, u32 padbit)
{
poly1305_internal *st = (poly1305_internal *)ctx;
u64 r0, r1;
u64 s1;
u64 h0, h1, h2, c;
u128 d0, d1;
r0 = st->r[0];
r1 = st->r[1];
s1 = r1 + (r1 >> 2);
h0 = st->h[0];
h1 = st->h[1];
h2 = st->h[2];
while (len >= POLY1305_BLOCK_SIZE) {
h0 = (u64)(d0 = (u128)h0 + U8TOU64(inp + 0));
h1 = (u64)(d1 = (u128)h1 + (d0 >> 64) + U8TOU64(inp + 8));
h2 += (u64)(d1 >> 64) + padbit;
d0 = ((u128)h0 * r0) +
((u128)h1 * s1);
d1 = ((u128)h0 * r1) +
((u128)h1 * r0) +
(h2 * s1);
h2 = (h2 * r0);
h0 = (u64)d0;
h1 = (u64)(d1 += d0 >> 64);
h2 += (u64)(d1 >> 64);
c = (h2 >> 2) + (h2 & ~3UL);
h2 &= 3;
h0 += c;
h1 += (c = CONSTANT_TIME_CARRY(h0,c));
h2 += CONSTANT_TIME_CARRY(h1,c);
inp += POLY1305_BLOCK_SIZE;
len -= POLY1305_BLOCK_SIZE;
}
st->h[0] = h0;
st->h[1] = h1;
st->h[2] = h2;
}
static void poly1305_emit(void *ctx, unsigned char mac[16],
const u32 nonce[4])
{
poly1305_internal *st = (poly1305_internal *) ctx;
u64 h0, h1, h2;
u64 g0, g1, g2;
u128 t;
u64 mask;
h0 = st->h[0];
h1 = st->h[1];
h2 = st->h[2];
g0 = (u64)(t = (u128)h0 + 5);
g1 = (u64)(t = (u128)h1 + (t >> 64));
g2 = h2 + (u64)(t >> 64);
mask = 0 - (g2 >> 2);
g0 &= mask;
g1 &= mask;
mask = ~mask;
h0 = (h0 & mask) | g0;
h1 = (h1 & mask) | g1;
h0 = (u64)(t = (u128)h0 + nonce[0] + ((u64)nonce[1]<<32));
h1 = (u64)(t = (u128)h1 + nonce[2] + ((u64)nonce[3]<<32) + (t >> 64));
U64TO8(mac + 0, h0);
U64TO8(mac + 8, h1);
}
static void U32TO8(unsigned char *p, unsigned int v)
{
p[0] = (unsigned char)((v) & 0xff);
p[1] = (unsigned char)((v >> 8) & 0xff);
p[2] = (unsigned char)((v >> 16) & 0xff);
p[3] = (unsigned char)((v >> 24) & 0xff);
}
static void poly1305_init(void *ctx, const unsigned char key[16])
{
poly1305_internal *st = (poly1305_internal *) ctx;
st->h[0] = 0;
st->h[1] = 0;
st->h[2] = 0;
st->h[3] = 0;
st->h[4] = 0;
st->r[0] = U8TOU32(&key[0]) & 0x0fffffff;
st->r[1] = U8TOU32(&key[4]) & 0x0ffffffc;
st->r[2] = U8TOU32(&key[8]) & 0x0ffffffc;
st->r[3] = U8TOU32(&key[12]) & 0x0ffffffc;
}
static void
poly1305_blocks(void *ctx, const unsigned char *inp, size_t len, u32 padbit)
{
poly1305_internal *st = (poly1305_internal *)ctx;
u32 r0, r1, r2, r3;
u32 s1, s2, s3;
u32 h0, h1, h2, h3, h4, c;
u64 d0, d1, d2, d3;
r0 = st->r[0];
r1 = st->r[1];
r2 = st->r[2];
r3 = st->r[3];
s1 = r1 + (r1 >> 2);
s2 = r2 + (r2 >> 2);
s3 = r3 + (r3 >> 2);
h0 = st->h[0];
h1 = st->h[1];
h2 = st->h[2];
h3 = st->h[3];
h4 = st->h[4];
while (len >= POLY1305_BLOCK_SIZE) {
h0 = (u32)(d0 = (u64)h0 + U8TOU32(inp + 0));
h1 = (u32)(d1 = (u64)h1 + (d0 >> 32) + U8TOU32(inp + 4));
h2 = (u32)(d2 = (u64)h2 + (d1 >> 32) + U8TOU32(inp + 8));
h3 = (u32)(d3 = (u64)h3 + (d2 >> 32) + U8TOU32(inp + 12));
h4 += (u32)(d3 >> 32) + padbit;
d0 = ((u64)h0 * r0) +
((u64)h1 * s3) +
((u64)h2 * s2) +
((u64)h3 * s1);
d1 = ((u64)h0 * r1) +
((u64)h1 * r0) +
((u64)h2 * s3) +
((u64)h3 * s2) +
(h4 * s1);
d2 = ((u64)h0 * r2) +
((u64)h1 * r1) +
((u64)h2 * r0) +
((u64)h3 * s3) +
(h4 * s2);
d3 = ((u64)h0 * r3) +
((u64)h1 * r2) +
((u64)h2 * r1) +
((u64)h3 * r0) +
(h4 * s3);
h4 = (h4 * r0);
h0 = (u32)d0;
h1 = (u32)(d1 += d0 >> 32);
h2 = (u32)(d2 += d1 >> 32);
h3 = (u32)(d3 += d2 >> 32);
h4 += (u32)(d3 >> 32);
c = (h4 >> 2) + (h4 & ~3U);
h4 &= 3;
h0 += c;
h1 += (c = CONSTANT_TIME_CARRY(h0,c));
h2 += (c = CONSTANT_TIME_CARRY(h1,c));
h3 += (c = CONSTANT_TIME_CARRY(h2,c));
h4 += CONSTANT_TIME_CARRY(h3,c);
inp += POLY1305_BLOCK_SIZE;
len -= POLY1305_BLOCK_SIZE;
}
st->h[0] = h0;
st->h[1] = h1;
st->h[2] = h2;
st->h[3] = h3;
st->h[4] = h4;
}
static void poly1305_emit(void *ctx, unsigned char mac[16],
const u32 nonce[4])
{
poly1305_internal *st = (poly1305_internal *) ctx;
u32 h0, h1, h2, h3, h4;
u32 g0, g1, g2, g3, g4;
u64 t;
u32 mask;
h0 = st->h[0];
h1 = st->h[1];
h2 = st->h[2];
h3 = st->h[3];
h4 = st->h[4];
g0 = (u32)(t = (u64)h0 + 5);
g1 = (u32)(t = (u64)h1 + (t >> 32));
g2 = (u32)(t = (u64)h2 + (t >> 32));
g3 = (u32)(t = (u64)h3 + (t >> 32));
g4 = h4 + (u32)(t >> 32);
mask = 0 - (g4 >> 2);
g0 &= mask;
g1 &= mask;
g2 &= mask;
g3 &= mask;
mask = ~mask;
h0 = (h0 & mask) | g0;
h1 = (h1 & mask) | g1;
h2 = (h2 & mask) | g2;
h3 = (h3 & mask) | g3;
h0 = (u32)(t = (u64)h0 + nonce[0]);
h1 = (u32)(t = (u64)h1 + (t >> 32) + nonce[1]);
h2 = (u32)(t = (u64)h2 + (t >> 32) + nonce[2]);
h3 = (u32)(t = (u64)h3 + (t >> 32) + nonce[3]);
U32TO8(mac + 0, h0);
U32TO8(mac + 4, h1);
U32TO8(mac + 8, h2);
U32TO8(mac + 12, h3);
}
void Poly1305_Init(POLY1305 *ctx, const unsigned char key[32])
{
ctx->nonce[0] = U8TOU32(&key[16]);
ctx->nonce[1] = U8TOU32(&key[20]);
ctx->nonce[2] = U8TOU32(&key[24]);
ctx->nonce[3] = U8TOU32(&key[28]);
#ifndef POLY1305_ASM
poly1305_init(ctx->opaque, key);
#else
if (!poly1305_init(ctx->opaque, key, &ctx->func)) {
ctx->func.blocks = poly1305_blocks;
ctx->func.emit = poly1305_emit;
}
#endif
ctx->num = 0;
}
void Poly1305_Update(POLY1305 *ctx, const unsigned char *inp, size_t len)
{
#ifdef POLY1305_ASM
poly1305_blocks_f poly1305_blocks_p = ctx->func.blocks;
#endif
size_t rem, num;
if ((num = ctx->num)) {
rem = POLY1305_BLOCK_SIZE - num;
if (len >= rem) {
memcpy(ctx->data + num, inp, rem);
poly1305_blocks(ctx->opaque, ctx->data, POLY1305_BLOCK_SIZE, 1);
inp += rem;
len -= rem;
} else {
memcpy(ctx->data + num, inp, len);
ctx->num = num + len;
return;
}
}
rem = len % POLY1305_BLOCK_SIZE;
len -= rem;
if (len >= POLY1305_BLOCK_SIZE) {
poly1305_blocks(ctx->opaque, inp, len, 1);
inp += len;
}
if (rem)
memcpy(ctx->data, inp, rem);
ctx->num = rem;
}
void Poly1305_Final(POLY1305 *ctx, unsigned char mac[16])
{
#ifdef POLY1305_ASM
poly1305_blocks_f poly1305_blocks_p = ctx->func.blocks;
poly1305_emit_f poly1305_emit_p = ctx->func.emit;
#endif
size_t num;
if ((num = ctx->num)) {
ctx->data[num++] = 1;
while (num < POLY1305_BLOCK_SIZE)
ctx->data[num++] = 0;
poly1305_blocks(ctx->opaque, ctx->data, POLY1305_BLOCK_SIZE, 0);
}
poly1305_emit(ctx->opaque, mac, ctx->nonce);
OPENSSL_cleanse(ctx, sizeof(*ctx));
}
