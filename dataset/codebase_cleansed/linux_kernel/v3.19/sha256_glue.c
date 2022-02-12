static int sha224_sparc64_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA224_H0;
sctx->state[1] = SHA224_H1;
sctx->state[2] = SHA224_H2;
sctx->state[3] = SHA224_H3;
sctx->state[4] = SHA224_H4;
sctx->state[5] = SHA224_H5;
sctx->state[6] = SHA224_H6;
sctx->state[7] = SHA224_H7;
sctx->count = 0;
return 0;
}
static int sha256_sparc64_init(struct shash_desc *desc)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
sctx->state[0] = SHA256_H0;
sctx->state[1] = SHA256_H1;
sctx->state[2] = SHA256_H2;
sctx->state[3] = SHA256_H3;
sctx->state[4] = SHA256_H4;
sctx->state[5] = SHA256_H5;
sctx->state[6] = SHA256_H6;
sctx->state[7] = SHA256_H7;
sctx->count = 0;
return 0;
}
static void __sha256_sparc64_update(struct sha256_state *sctx, const u8 *data,
unsigned int len, unsigned int partial)
{
unsigned int done = 0;
sctx->count += len;
if (partial) {
done = SHA256_BLOCK_SIZE - partial;
memcpy(sctx->buf + partial, data, done);
sha256_sparc64_transform(sctx->state, sctx->buf, 1);
}
if (len - done >= SHA256_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA256_BLOCK_SIZE;
sha256_sparc64_transform(sctx->state, data + done, rounds);
done += rounds * SHA256_BLOCK_SIZE;
}
memcpy(sctx->buf, data + done, len - done);
}
static int sha256_sparc64_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA256_BLOCK_SIZE;
if (partial + len < SHA256_BLOCK_SIZE) {
sctx->count += len;
memcpy(sctx->buf + partial, data, len);
} else
__sha256_sparc64_update(sctx, data, len, partial);
return 0;
}
static int sha256_sparc64_final(struct shash_desc *desc, u8 *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be32 *dst = (__be32 *)out;
__be64 bits;
static const u8 padding[SHA256_BLOCK_SIZE] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count % SHA256_BLOCK_SIZE;
padlen = (index < 56) ? (56 - index) : ((SHA256_BLOCK_SIZE+56) - index);
if (padlen <= 56) {
sctx->count += padlen;
memcpy(sctx->buf + index, padding, padlen);
} else {
__sha256_sparc64_update(sctx, padding, padlen, index);
}
__sha256_sparc64_update(sctx, (const u8 *)&bits, sizeof(bits), 56);
for (i = 0; i < 8; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha224_sparc64_final(struct shash_desc *desc, u8 *hash)
{
u8 D[SHA256_DIGEST_SIZE];
sha256_sparc64_final(desc, D);
memcpy(hash, D, SHA224_DIGEST_SIZE);
memzero_explicit(D, SHA256_DIGEST_SIZE);
return 0;
}
static int sha256_sparc64_export(struct shash_desc *desc, void *out)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha256_sparc64_import(struct shash_desc *desc, const void *in)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static bool __init sparc64_has_sha256_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_SHA256))
return false;
return true;
}
static int __init sha256_sparc64_mod_init(void)
{
if (sparc64_has_sha256_opcode()) {
int ret = crypto_register_shash(&sha224);
if (ret < 0)
return ret;
ret = crypto_register_shash(&sha256);
if (ret < 0) {
crypto_unregister_shash(&sha224);
return ret;
}
pr_info("Using sparc64 sha256 opcode optimized SHA-256/SHA-224 implementation\n");
return 0;
}
pr_info("sparc64 sha256 opcode not available.\n");
return -ENODEV;
}
static void __exit sha256_sparc64_mod_fini(void)
{
crypto_unregister_shash(&sha224);
crypto_unregister_shash(&sha256);
}
