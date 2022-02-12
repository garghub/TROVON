static int sha256_update(struct shash_desc *desc, const u8 *data,
unsigned int len, sha256_transform_fn *sha256_xform)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
if (!irq_fpu_usable() ||
(sctx->count % SHA256_BLOCK_SIZE) + len < SHA256_BLOCK_SIZE)
return crypto_sha256_update(desc, data, len);
BUILD_BUG_ON(offsetof(struct sha256_state, state) != 0);
kernel_fpu_begin();
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_xform);
kernel_fpu_end();
return 0;
}
static int sha256_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out, sha256_transform_fn *sha256_xform)
{
if (!irq_fpu_usable())
return crypto_sha256_finup(desc, data, len, out);
kernel_fpu_begin();
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_xform);
sha256_base_do_finalize(desc, (sha256_block_fn *)sha256_xform);
kernel_fpu_end();
return sha256_base_finish(desc, out);
}
static int sha256_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha256_update(desc, data, len, sha256_transform_ssse3);
}
static int sha256_ssse3_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha256_finup(desc, data, len, out, sha256_transform_ssse3);
}
static int sha256_ssse3_final(struct shash_desc *desc, u8 *out)
{
return sha256_ssse3_finup(desc, NULL, 0, out);
}
static int register_sha256_ssse3(void)
{
if (boot_cpu_has(X86_FEATURE_SSSE3))
return crypto_register_shashes(sha256_ssse3_algs,
ARRAY_SIZE(sha256_ssse3_algs));
return 0;
}
static void unregister_sha256_ssse3(void)
{
if (boot_cpu_has(X86_FEATURE_SSSE3))
crypto_unregister_shashes(sha256_ssse3_algs,
ARRAY_SIZE(sha256_ssse3_algs));
}
static int sha256_avx_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha256_update(desc, data, len, sha256_transform_avx);
}
static int sha256_avx_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha256_finup(desc, data, len, out, sha256_transform_avx);
}
static int sha256_avx_final(struct shash_desc *desc, u8 *out)
{
return sha256_avx_finup(desc, NULL, 0, out);
}
static bool avx_usable(void)
{
if (!cpu_has_xfeatures(XFEATURE_MASK_SSE | XFEATURE_MASK_YMM, NULL)) {
if (boot_cpu_has(X86_FEATURE_AVX))
pr_info("AVX detected but unusable.\n");
return false;
}
return true;
}
static int register_sha256_avx(void)
{
if (avx_usable())
return crypto_register_shashes(sha256_avx_algs,
ARRAY_SIZE(sha256_avx_algs));
return 0;
}
static void unregister_sha256_avx(void)
{
if (avx_usable())
crypto_unregister_shashes(sha256_avx_algs,
ARRAY_SIZE(sha256_avx_algs));
}
static inline int register_sha256_avx(void) { return 0; }
static inline void unregister_sha256_avx(void) { }
static int sha256_avx2_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha256_update(desc, data, len, sha256_transform_rorx);
}
static int sha256_avx2_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha256_finup(desc, data, len, out, sha256_transform_rorx);
}
static int sha256_avx2_final(struct shash_desc *desc, u8 *out)
{
return sha256_avx2_finup(desc, NULL, 0, out);
}
static bool avx2_usable(void)
{
if (avx_usable() && boot_cpu_has(X86_FEATURE_AVX2) &&
boot_cpu_has(X86_FEATURE_BMI2))
return true;
return false;
}
static int register_sha256_avx2(void)
{
if (avx2_usable())
return crypto_register_shashes(sha256_avx2_algs,
ARRAY_SIZE(sha256_avx2_algs));
return 0;
}
static void unregister_sha256_avx2(void)
{
if (avx2_usable())
crypto_unregister_shashes(sha256_avx2_algs,
ARRAY_SIZE(sha256_avx2_algs));
}
static inline int register_sha256_avx2(void) { return 0; }
static inline void unregister_sha256_avx2(void) { }
static int sha256_ni_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha256_update(desc, data, len, sha256_ni_transform);
}
static int sha256_ni_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha256_finup(desc, data, len, out, sha256_ni_transform);
}
static int sha256_ni_final(struct shash_desc *desc, u8 *out)
{
return sha256_ni_finup(desc, NULL, 0, out);
}
static int register_sha256_ni(void)
{
if (boot_cpu_has(X86_FEATURE_SHA_NI))
return crypto_register_shashes(sha256_ni_algs,
ARRAY_SIZE(sha256_ni_algs));
return 0;
}
static void unregister_sha256_ni(void)
{
if (boot_cpu_has(X86_FEATURE_SHA_NI))
crypto_unregister_shashes(sha256_ni_algs,
ARRAY_SIZE(sha256_ni_algs));
}
static inline int register_sha256_ni(void) { return 0; }
static inline void unregister_sha256_ni(void) { }
static int __init sha256_ssse3_mod_init(void)
{
if (register_sha256_ssse3())
goto fail;
if (register_sha256_avx()) {
unregister_sha256_ssse3();
goto fail;
}
if (register_sha256_avx2()) {
unregister_sha256_avx();
unregister_sha256_ssse3();
goto fail;
}
if (register_sha256_ni()) {
unregister_sha256_avx2();
unregister_sha256_avx();
unregister_sha256_ssse3();
goto fail;
}
return 0;
fail:
return -ENODEV;
}
static void __exit sha256_ssse3_mod_fini(void)
{
unregister_sha256_ni();
unregister_sha256_avx2();
unregister_sha256_avx();
unregister_sha256_ssse3();
}
