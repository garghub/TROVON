static int crc32c_sparc64_setkey(struct crypto_shash *hash, const u8 *key,
unsigned int keylen)
{
u32 *mctx = crypto_shash_ctx(hash);
if (keylen != sizeof(u32)) {
crypto_shash_set_flags(hash, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
*(__le32 *)mctx = le32_to_cpup((__le32 *)key);
return 0;
}
static int crc32c_sparc64_init(struct shash_desc *desc)
{
u32 *mctx = crypto_shash_ctx(desc->tfm);
u32 *crcp = shash_desc_ctx(desc);
*crcp = *mctx;
return 0;
}
static void crc32c_compute(u32 *crcp, const u64 *data, unsigned int len)
{
unsigned int asm_len;
asm_len = len & ~7U;
if (asm_len) {
crc32c_sparc64(crcp, data, asm_len);
data += asm_len / 8;
len -= asm_len;
}
if (len)
*crcp = __crc32c_le(*crcp, (const unsigned char *) data, len);
}
static int crc32c_sparc64_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
u32 *crcp = shash_desc_ctx(desc);
crc32c_compute(crcp, (const u64 *) data, len);
return 0;
}
static int __crc32c_sparc64_finup(u32 *crcp, const u8 *data, unsigned int len,
u8 *out)
{
u32 tmp = *crcp;
crc32c_compute(&tmp, (const u64 *) data, len);
*(__le32 *) out = ~cpu_to_le32(tmp);
return 0;
}
static int crc32c_sparc64_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_sparc64_finup(shash_desc_ctx(desc), data, len, out);
}
static int crc32c_sparc64_final(struct shash_desc *desc, u8 *out)
{
u32 *crcp = shash_desc_ctx(desc);
*(__le32 *) out = ~cpu_to_le32p(crcp);
return 0;
}
static int crc32c_sparc64_digest(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return __crc32c_sparc64_finup(crypto_shash_ctx(desc->tfm), data, len,
out);
}
static int crc32c_sparc64_cra_init(struct crypto_tfm *tfm)
{
u32 *key = crypto_tfm_ctx(tfm);
*key = ~0;
return 0;
}
static bool __init sparc64_has_crc32c_opcode(void)
{
unsigned long cfr;
if (!(sparc64_elf_hwcap & HWCAP_SPARC_CRYPTO))
return false;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
if (!(cfr & CFR_CRC32C))
return false;
return true;
}
static int __init crc32c_sparc64_mod_init(void)
{
if (sparc64_has_crc32c_opcode()) {
pr_info("Using sparc64 crc32c opcode optimized CRC32C implementation\n");
return crypto_register_shash(&alg);
}
pr_info("sparc64 crc32c opcode not available.\n");
return -ENODEV;
}
static void __exit crc32c_sparc64_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
