static int md5_sparc64_init(struct shash_desc *desc)
{
struct md5_state *mctx = shash_desc_ctx(desc);
mctx->hash[0] = cpu_to_le32(MD5_H0);
mctx->hash[1] = cpu_to_le32(MD5_H1);
mctx->hash[2] = cpu_to_le32(MD5_H2);
mctx->hash[3] = cpu_to_le32(MD5_H3);
mctx->byte_count = 0;
return 0;
}
static void __md5_sparc64_update(struct md5_state *sctx, const u8 *data,
unsigned int len, unsigned int partial)
{
unsigned int done = 0;
sctx->byte_count += len;
if (partial) {
done = MD5_HMAC_BLOCK_SIZE - partial;
memcpy((u8 *)sctx->block + partial, data, done);
md5_sparc64_transform(sctx->hash, (u8 *)sctx->block, 1);
}
if (len - done >= MD5_HMAC_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / MD5_HMAC_BLOCK_SIZE;
md5_sparc64_transform(sctx->hash, data + done, rounds);
done += rounds * MD5_HMAC_BLOCK_SIZE;
}
memcpy(sctx->block, data + done, len - done);
}
static int md5_sparc64_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct md5_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->byte_count % MD5_HMAC_BLOCK_SIZE;
if (partial + len < MD5_HMAC_BLOCK_SIZE) {
sctx->byte_count += len;
memcpy((u8 *)sctx->block + partial, data, len);
} else
__md5_sparc64_update(sctx, data, len, partial);
return 0;
}
static int md5_sparc64_final(struct shash_desc *desc, u8 *out)
{
struct md5_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
u32 *dst = (u32 *)out;
__le64 bits;
static const u8 padding[MD5_HMAC_BLOCK_SIZE] = { 0x80, };
bits = cpu_to_le64(sctx->byte_count << 3);
index = sctx->byte_count % MD5_HMAC_BLOCK_SIZE;
padlen = (index < 56) ? (56 - index) : ((MD5_HMAC_BLOCK_SIZE+56) - index);
if (padlen <= 56) {
sctx->byte_count += padlen;
memcpy((u8 *)sctx->block + index, padding, padlen);
} else {
__md5_sparc64_update(sctx, padding, padlen, index);
}
__md5_sparc64_update(sctx, (const u8 *)&bits, sizeof(bits), 56);
for (i = 0; i < MD5_HASH_WORDS; i++)
dst[i] = sctx->hash[i];
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int md5_sparc64_export(struct shash_desc *desc, void *out)
{
struct md5_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int md5_sparc64_import(struct shash_desc *desc, const void *in)
{
struct md5_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static bool __init sparc64_has_md5_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_MD5))
return false;
return true;
}
static int __init md5_sparc64_mod_init(void)
{
if (sparc64_has_md5_opcode()) {
pr_info("Using sparc64 md5 opcode optimized MD5 implementation\n");
return crypto_register_shash(&alg);
}
pr_info("sparc64 md5 opcode not available.\n");
return -ENODEV;
}
static void __exit md5_sparc64_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
