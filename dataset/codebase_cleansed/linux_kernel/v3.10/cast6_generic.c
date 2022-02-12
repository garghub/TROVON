static inline void W(u32 *key, unsigned int i)
{
u32 I;
key[6] ^= F1(key[7], Tr[i % 4][0], Tm[i][0]);
key[5] ^= F2(key[6], Tr[i % 4][1], Tm[i][1]);
key[4] ^= F3(key[5], Tr[i % 4][2], Tm[i][2]);
key[3] ^= F1(key[4], Tr[i % 4][3], Tm[i][3]);
key[2] ^= F2(key[3], Tr[i % 4][4], Tm[i][4]);
key[1] ^= F3(key[2], Tr[i % 4][5], Tm[i][5]);
key[0] ^= F1(key[1], Tr[i % 4][6], Tm[i][6]);
key[7] ^= F2(key[0], Tr[i % 4][7], Tm[i][7]);
}
int __cast6_setkey(struct cast6_ctx *c, const u8 *in_key,
unsigned key_len, u32 *flags)
{
int i;
u32 key[8];
__be32 p_key[8];
if (key_len % 4 != 0) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
memset(p_key, 0, 32);
memcpy(p_key, in_key, key_len);
key[0] = be32_to_cpu(p_key[0]);
key[1] = be32_to_cpu(p_key[1]);
key[2] = be32_to_cpu(p_key[2]);
key[3] = be32_to_cpu(p_key[3]);
key[4] = be32_to_cpu(p_key[4]);
key[5] = be32_to_cpu(p_key[5]);
key[6] = be32_to_cpu(p_key[6]);
key[7] = be32_to_cpu(p_key[7]);
for (i = 0; i < 12; i++) {
W(key, 2 * i);
W(key, 2 * i + 1);
c->Kr[i][0] = key[0] & 0x1f;
c->Kr[i][1] = key[2] & 0x1f;
c->Kr[i][2] = key[4] & 0x1f;
c->Kr[i][3] = key[6] & 0x1f;
c->Km[i][0] = key[7];
c->Km[i][1] = key[5];
c->Km[i][2] = key[3];
c->Km[i][3] = key[1];
}
return 0;
}
int cast6_setkey(struct crypto_tfm *tfm, const u8 *key, unsigned int keylen)
{
return __cast6_setkey(crypto_tfm_ctx(tfm), key, keylen,
&tfm->crt_flags);
}
static inline void Q(u32 *block, u8 *Kr, u32 *Km)
{
u32 I;
block[2] ^= F1(block[3], Kr[0], Km[0]);
block[1] ^= F2(block[2], Kr[1], Km[1]);
block[0] ^= F3(block[1], Kr[2], Km[2]);
block[3] ^= F1(block[0], Kr[3], Km[3]);
}
static inline void QBAR(u32 *block, u8 *Kr, u32 *Km)
{
u32 I;
block[3] ^= F1(block[0], Kr[3], Km[3]);
block[0] ^= F3(block[1], Kr[2], Km[2]);
block[1] ^= F2(block[2], Kr[1], Km[1]);
block[2] ^= F1(block[3], Kr[0], Km[0]);
}
void __cast6_encrypt(struct cast6_ctx *c, u8 *outbuf, const u8 *inbuf)
{
const __be32 *src = (const __be32 *)inbuf;
__be32 *dst = (__be32 *)outbuf;
u32 block[4];
u32 *Km;
u8 *Kr;
block[0] = be32_to_cpu(src[0]);
block[1] = be32_to_cpu(src[1]);
block[2] = be32_to_cpu(src[2]);
block[3] = be32_to_cpu(src[3]);
Km = c->Km[0]; Kr = c->Kr[0]; Q(block, Kr, Km);
Km = c->Km[1]; Kr = c->Kr[1]; Q(block, Kr, Km);
Km = c->Km[2]; Kr = c->Kr[2]; Q(block, Kr, Km);
Km = c->Km[3]; Kr = c->Kr[3]; Q(block, Kr, Km);
Km = c->Km[4]; Kr = c->Kr[4]; Q(block, Kr, Km);
Km = c->Km[5]; Kr = c->Kr[5]; Q(block, Kr, Km);
Km = c->Km[6]; Kr = c->Kr[6]; QBAR(block, Kr, Km);
Km = c->Km[7]; Kr = c->Kr[7]; QBAR(block, Kr, Km);
Km = c->Km[8]; Kr = c->Kr[8]; QBAR(block, Kr, Km);
Km = c->Km[9]; Kr = c->Kr[9]; QBAR(block, Kr, Km);
Km = c->Km[10]; Kr = c->Kr[10]; QBAR(block, Kr, Km);
Km = c->Km[11]; Kr = c->Kr[11]; QBAR(block, Kr, Km);
dst[0] = cpu_to_be32(block[0]);
dst[1] = cpu_to_be32(block[1]);
dst[2] = cpu_to_be32(block[2]);
dst[3] = cpu_to_be32(block[3]);
}
static void cast6_encrypt(struct crypto_tfm *tfm, u8 *outbuf, const u8 *inbuf)
{
__cast6_encrypt(crypto_tfm_ctx(tfm), outbuf, inbuf);
}
void __cast6_decrypt(struct cast6_ctx *c, u8 *outbuf, const u8 *inbuf)
{
const __be32 *src = (const __be32 *)inbuf;
__be32 *dst = (__be32 *)outbuf;
u32 block[4];
u32 *Km;
u8 *Kr;
block[0] = be32_to_cpu(src[0]);
block[1] = be32_to_cpu(src[1]);
block[2] = be32_to_cpu(src[2]);
block[3] = be32_to_cpu(src[3]);
Km = c->Km[11]; Kr = c->Kr[11]; Q(block, Kr, Km);
Km = c->Km[10]; Kr = c->Kr[10]; Q(block, Kr, Km);
Km = c->Km[9]; Kr = c->Kr[9]; Q(block, Kr, Km);
Km = c->Km[8]; Kr = c->Kr[8]; Q(block, Kr, Km);
Km = c->Km[7]; Kr = c->Kr[7]; Q(block, Kr, Km);
Km = c->Km[6]; Kr = c->Kr[6]; Q(block, Kr, Km);
Km = c->Km[5]; Kr = c->Kr[5]; QBAR(block, Kr, Km);
Km = c->Km[4]; Kr = c->Kr[4]; QBAR(block, Kr, Km);
Km = c->Km[3]; Kr = c->Kr[3]; QBAR(block, Kr, Km);
Km = c->Km[2]; Kr = c->Kr[2]; QBAR(block, Kr, Km);
Km = c->Km[1]; Kr = c->Kr[1]; QBAR(block, Kr, Km);
Km = c->Km[0]; Kr = c->Kr[0]; QBAR(block, Kr, Km);
dst[0] = cpu_to_be32(block[0]);
dst[1] = cpu_to_be32(block[1]);
dst[2] = cpu_to_be32(block[2]);
dst[3] = cpu_to_be32(block[3]);
}
static void cast6_decrypt(struct crypto_tfm *tfm, u8 *outbuf, const u8 *inbuf)
{
__cast6_decrypt(crypto_tfm_ctx(tfm), outbuf, inbuf);
}
static int __init cast6_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit cast6_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
