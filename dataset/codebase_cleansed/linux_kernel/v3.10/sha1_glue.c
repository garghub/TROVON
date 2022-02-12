static int sha1_sparc64_init(struct shash_desc *desc)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha1_state){
.state = { SHA1_H0, SHA1_H1, SHA1_H2, SHA1_H3, SHA1_H4 },
};
return 0;
}
static void __sha1_sparc64_update(struct sha1_state *sctx, const u8 *data,
unsigned int len, unsigned int partial)
{
unsigned int done = 0;
sctx->count += len;
if (partial) {
done = SHA1_BLOCK_SIZE - partial;
memcpy(sctx->buffer + partial, data, done);
sha1_sparc64_transform(sctx->state, sctx->buffer, 1);
}
if (len - done >= SHA1_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA1_BLOCK_SIZE;
sha1_sparc64_transform(sctx->state, data + done, rounds);
done += rounds * SHA1_BLOCK_SIZE;
}
memcpy(sctx->buffer, data + done, len - done);
}
static int sha1_sparc64_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA1_BLOCK_SIZE;
if (partial + len < SHA1_BLOCK_SIZE) {
sctx->count += len;
memcpy(sctx->buffer + partial, data, len);
} else
__sha1_sparc64_update(sctx, data, len, partial);
return 0;
}
static int sha1_sparc64_final(struct shash_desc *desc, u8 *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be32 *dst = (__be32 *)out;
__be64 bits;
static const u8 padding[SHA1_BLOCK_SIZE] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count % SHA1_BLOCK_SIZE;
padlen = (index < 56) ? (56 - index) : ((SHA1_BLOCK_SIZE+56) - index);
if (padlen <= 56) {
sctx->count += padlen;
memcpy(sctx->buffer + index, padding, padlen);
} else {
__sha1_sparc64_update(sctx, padding, padlen, index);
}
__sha1_sparc64_update(sctx, (const u8 *)&bits, sizeof(bits), 56);
for (i = 0; i < 5; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha1_sparc64_export(struct shash_desc *desc, void *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha1_sparc64_import(struct shash_desc *desc, const void *in)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static bool __init sparc64_has_sha1_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_SHA1))
return false;
return true;
}
static int __init sha1_sparc64_mod_init(void)
{
if (sparc64_has_sha1_opcode()) {
pr_info("Using sparc64 sha1 opcode optimized SHA-1 implementation\n");
return crypto_register_shash(&alg);
}
pr_info("sparc64 sha1 opcode not available.\n");
return -ENODEV;
}
static void __exit sha1_sparc64_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
