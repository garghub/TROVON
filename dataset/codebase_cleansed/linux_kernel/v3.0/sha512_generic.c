static inline u64 Ch(u64 x, u64 y, u64 z)
{
return z ^ (x & (y ^ z));
}
static inline u64 Maj(u64 x, u64 y, u64 z)
{
return (x & y) | (z & (x | y));
}
static inline u64 RORu64(u64 x, u64 y)
{
return (x >> y) | (x << (64 - y));
}
static inline void LOAD_OP(int I, u64 *W, const u8 *input)
{
W[I] = __be64_to_cpu( ((__be64*)(input))[I] );
}
static inline void BLEND_OP(int I, u64 *W)
{
W[I] = s1(W[I-2]) + W[I-7] + s0(W[I-15]) + W[I-16];
}
static void
sha512_transform(u64 *state, const u8 *input)
{
u64 a, b, c, d, e, f, g, h, t1, t2;
int i;
u64 *W = get_cpu_var(msg_schedule);
for (i = 0; i < 16; i++)
LOAD_OP(i, W, input);
for (i = 16; i < 80; i++) {
BLEND_OP(i, W);
}
a=state[0]; b=state[1]; c=state[2]; d=state[3];
e=state[4]; f=state[5]; g=state[6]; h=state[7];
for (i=0; i<80; i+=8) {
t1 = h + e1(e) + Ch(e,f,g) + sha512_K[i ] + W[i ];
t2 = e0(a) + Maj(a,b,c); d+=t1; h=t1+t2;
t1 = g + e1(d) + Ch(d,e,f) + sha512_K[i+1] + W[i+1];
t2 = e0(h) + Maj(h,a,b); c+=t1; g=t1+t2;
t1 = f + e1(c) + Ch(c,d,e) + sha512_K[i+2] + W[i+2];
t2 = e0(g) + Maj(g,h,a); b+=t1; f=t1+t2;
t1 = e + e1(b) + Ch(b,c,d) + sha512_K[i+3] + W[i+3];
t2 = e0(f) + Maj(f,g,h); a+=t1; e=t1+t2;
t1 = d + e1(a) + Ch(a,b,c) + sha512_K[i+4] + W[i+4];
t2 = e0(e) + Maj(e,f,g); h+=t1; d=t1+t2;
t1 = c + e1(h) + Ch(h,a,b) + sha512_K[i+5] + W[i+5];
t2 = e0(d) + Maj(d,e,f); g+=t1; c=t1+t2;
t1 = b + e1(g) + Ch(g,h,a) + sha512_K[i+6] + W[i+6];
t2 = e0(c) + Maj(c,d,e); f+=t1; b=t1+t2;
t1 = a + e1(f) + Ch(f,g,h) + sha512_K[i+7] + W[i+7];
t2 = e0(b) + Maj(b,c,d); e+=t1; a=t1+t2;
}
state[0] += a; state[1] += b; state[2] += c; state[3] += d;
state[4] += e; state[5] += f; state[6] += g; state[7] += h;
a = b = c = d = e = f = g = h = t1 = t2 = 0;
memset(W, 0, sizeof(__get_cpu_var(msg_schedule)));
put_cpu_var(msg_schedule);
}
static int
sha512_init(struct shash_desc *desc)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA512_H0;
sctx->state[1] = SHA512_H1;
sctx->state[2] = SHA512_H2;
sctx->state[3] = SHA512_H3;
sctx->state[4] = SHA512_H4;
sctx->state[5] = SHA512_H5;
sctx->state[6] = SHA512_H6;
sctx->state[7] = SHA512_H7;
sctx->count[0] = sctx->count[1] = 0;
return 0;
}
static int
sha384_init(struct shash_desc *desc)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA384_H0;
sctx->state[1] = SHA384_H1;
sctx->state[2] = SHA384_H2;
sctx->state[3] = SHA384_H3;
sctx->state[4] = SHA384_H4;
sctx->state[5] = SHA384_H5;
sctx->state[6] = SHA384_H6;
sctx->state[7] = SHA384_H7;
sctx->count[0] = sctx->count[1] = 0;
return 0;
}
static int
sha512_update(struct shash_desc *desc, const u8 *data, unsigned int len)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, part_len;
index = sctx->count[0] & 0x7f;
if (!(sctx->count[0] += len))
sctx->count[1]++;
part_len = 128 - index;
if (len >= part_len) {
memcpy(&sctx->buf[index], data, part_len);
sha512_transform(sctx->state, sctx->buf);
for (i = part_len; i + 127 < len; i+=128)
sha512_transform(sctx->state, &data[i]);
index = 0;
} else {
i = 0;
}
memcpy(&sctx->buf[index], &data[i], len - i);
return 0;
}
static int
sha512_final(struct shash_desc *desc, u8 *hash)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
static u8 padding[128] = { 0x80, };
__be64 *dst = (__be64 *)hash;
__be64 bits[2];
unsigned int index, pad_len;
int i;
bits[1] = cpu_to_be64(sctx->count[0] << 3);
bits[0] = cpu_to_be64(sctx->count[1] << 3 | sctx->count[0] >> 61);
index = sctx->count[0] & 0x7f;
pad_len = (index < 112) ? (112 - index) : ((128+112) - index);
sha512_update(desc, padding, pad_len);
sha512_update(desc, (const u8 *)bits, sizeof(bits));
for (i = 0; i < 8; i++)
dst[i] = cpu_to_be64(sctx->state[i]);
memset(sctx, 0, sizeof(struct sha512_state));
return 0;
}
static int sha384_final(struct shash_desc *desc, u8 *hash)
{
u8 D[64];
sha512_final(desc, D);
memcpy(hash, D, 48);
memset(D, 0, 64);
return 0;
}
static int __init sha512_generic_mod_init(void)
{
int ret = 0;
if ((ret = crypto_register_shash(&sha384)) < 0)
goto out;
if ((ret = crypto_register_shash(&sha512)) < 0)
crypto_unregister_shash(&sha384);
out:
return ret;
}
static void __exit sha512_generic_mod_fini(void)
{
crypto_unregister_shash(&sha384);
crypto_unregister_shash(&sha512);
}
