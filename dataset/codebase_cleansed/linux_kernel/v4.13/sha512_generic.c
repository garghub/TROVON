static inline u64 Ch(u64 x, u64 y, u64 z)
{
return z ^ (x & (y ^ z));
}
static inline u64 Maj(u64 x, u64 y, u64 z)
{
return (x & y) | (z & (x | y));
}
static inline void LOAD_OP(int I, u64 *W, const u8 *input)
{
W[I] = get_unaligned_be64((__u64 *)input + I);
}
static inline void BLEND_OP(int I, u64 *W)
{
W[I & 15] += s1(W[(I-2) & 15]) + W[(I-7) & 15] + s0(W[(I-15) & 15]);
}
static void
sha512_transform(u64 *state, const u8 *input)
{
u64 a, b, c, d, e, f, g, h, t1, t2;
int i;
u64 W[16];
a=state[0]; b=state[1]; c=state[2]; d=state[3];
e=state[4]; f=state[5]; g=state[6]; h=state[7];
for (i=0; i<80; i+=8) {
if (!(i & 8)) {
int j;
if (i < 16) {
for (j = 0; j < 16; j++)
LOAD_OP(i + j, W, input);
} else {
for (j = 0; j < 16; j++) {
BLEND_OP(i + j, W);
}
}
}
t1 = h + e1(e) + Ch(e,f,g) + sha512_K[i ] + W[(i & 15)];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + sha512_K[i+1] + W[(i & 15) + 1];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + sha512_K[i+2] + W[(i & 15) + 2];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + sha512_K[i+3] + W[(i & 15) + 3];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + sha512_K[i+4] + W[(i & 15) + 4];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + sha512_K[i+5] + W[(i & 15) + 5];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + sha512_K[i+6] + W[(i & 15) + 6];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + sha512_K[i+7] + W[(i & 15) + 7];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
}
state[0] += a; state[1] += b; state[2] += c; state[3] += d;
state[4] += e; state[5] += f; state[6] += g; state[7] += h;
a = b = c = d = e = f = g = h = t1 = t2 = 0;
}
static void sha512_generic_block_fn(struct sha512_state *sst, u8 const *src,
int blocks)
{
while (blocks--) {
sha512_transform(sst->state, src);
src += SHA512_BLOCK_SIZE;
}
}
int crypto_sha512_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha512_base_do_update(desc, data, len, sha512_generic_block_fn);
}
static int sha512_final(struct shash_desc *desc, u8 *hash)
{
sha512_base_do_finalize(desc, sha512_generic_block_fn);
return sha512_base_finish(desc, hash);
}
int crypto_sha512_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *hash)
{
sha512_base_do_update(desc, data, len, sha512_generic_block_fn);
return sha512_final(desc, hash);
}
static int __init sha512_generic_mod_init(void)
{
return crypto_register_shashes(sha512_algs, ARRAY_SIZE(sha512_algs));
}
static void __exit sha512_generic_mod_fini(void)
{
crypto_unregister_shashes(sha512_algs, ARRAY_SIZE(sha512_algs));
}
