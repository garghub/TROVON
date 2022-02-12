static int sha512_update(struct shash_desc *desc, const u8 *data,
unsigned int len, sha512_transform_fn *sha512_xform)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
if (!irq_fpu_usable() ||
(sctx->count[0] % SHA512_BLOCK_SIZE) + len < SHA512_BLOCK_SIZE)
return crypto_sha512_update(desc, data, len);
BUILD_BUG_ON(offsetof(struct sha512_state, state) != 0);
kernel_fpu_begin();
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_xform);
kernel_fpu_end();
return 0;
}
static int sha512_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out, sha512_transform_fn *sha512_xform)
{
if (!irq_fpu_usable())
return crypto_sha512_finup(desc, data, len, out);
kernel_fpu_begin();
if (len)
sha512_base_do_update(desc, data, len,
(sha512_block_fn *)sha512_xform);
sha512_base_do_finalize(desc, (sha512_block_fn *)sha512_xform);
kernel_fpu_end();
return sha512_base_finish(desc, out);
}
static int sha512_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha512_update(desc, data, len, sha512_transform_ssse3);
}
static int sha512_ssse3_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha512_finup(desc, data, len, out, sha512_transform_ssse3);
}
static int sha512_ssse3_final(struct shash_desc *desc, u8 *out)
{
return sha512_ssse3_finup(desc, NULL, 0, out);
}
static int register_sha512_ssse3(void)
{
if (boot_cpu_has(X86_FEATURE_SSSE3))
return crypto_register_shashes(sha512_ssse3_algs,
ARRAY_SIZE(sha512_ssse3_algs));
return 0;
}
static void unregister_sha512_ssse3(void)
{
if (boot_cpu_has(X86_FEATURE_SSSE3))
crypto_unregister_shashes(sha512_ssse3_algs,
ARRAY_SIZE(sha512_ssse3_algs));
}
static bool avx_usable(void)
{
if (!cpu_has_xfeatures(XFEATURE_MASK_SSE | XFEATURE_MASK_YMM, NULL)) {
if (cpu_has_avx)
pr_info("AVX detected but unusable.\n");
return false;
}
return true;
}
static int sha512_avx_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha512_update(desc, data, len, sha512_transform_avx);
}
static int sha512_avx_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha512_finup(desc, data, len, out, sha512_transform_avx);
}
static int sha512_avx_final(struct shash_desc *desc, u8 *out)
{
return sha512_avx_finup(desc, NULL, 0, out);
}
static int register_sha512_avx(void)
{
if (avx_usable())
return crypto_register_shashes(sha512_avx_algs,
ARRAY_SIZE(sha512_avx_algs));
return 0;
}
static void unregister_sha512_avx(void)
{
if (avx_usable())
crypto_unregister_shashes(sha512_avx_algs,
ARRAY_SIZE(sha512_avx_algs));
}
static inline int register_sha512_avx(void) { return 0; }
static inline void unregister_sha512_avx(void) { }
static int sha512_avx2_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha512_update(desc, data, len, sha512_transform_rorx);
}
static int sha512_avx2_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha512_finup(desc, data, len, out, sha512_transform_rorx);
}
static int sha512_avx2_final(struct shash_desc *desc, u8 *out)
{
return sha512_avx2_finup(desc, NULL, 0, out);
}
static bool avx2_usable(void)
{
if (avx_usable() && boot_cpu_has(X86_FEATURE_AVX2) &&
boot_cpu_has(X86_FEATURE_BMI2))
return true;
return false;
}
static int register_sha512_avx2(void)
{
if (avx2_usable())
return crypto_register_shashes(sha512_avx2_algs,
ARRAY_SIZE(sha512_avx2_algs));
return 0;
}
static void unregister_sha512_avx2(void)
{
if (avx2_usable())
crypto_unregister_shashes(sha512_avx2_algs,
ARRAY_SIZE(sha512_avx2_algs));
}
static inline int register_sha512_avx2(void) { return 0; }
static inline void unregister_sha512_avx2(void) { }
static int __init sha512_ssse3_mod_init(void)
{
if (register_sha512_ssse3())
goto fail;
if (register_sha512_avx()) {
unregister_sha512_ssse3();
goto fail;
}
if (register_sha512_avx2()) {
unregister_sha512_avx();
unregister_sha512_ssse3();
goto fail;
}
return 0;
fail:
return -ENODEV;
}
static void __exit sha512_ssse3_mod_fini(void)
{
unregister_sha512_avx2();
unregister_sha512_avx();
unregister_sha512_ssse3();
}
