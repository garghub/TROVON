static int sha256_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha256_state *sctx = shash_desc_ctx(desc);
if (!irq_fpu_usable() ||
(sctx->count % SHA256_BLOCK_SIZE) + len < SHA256_BLOCK_SIZE)
return crypto_sha256_update(desc, data, len);
BUILD_BUG_ON(offsetof(struct sha256_state, state) != 0);
kernel_fpu_begin();
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_transform_asm);
kernel_fpu_end();
return 0;
}
static int sha256_ssse3_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
if (!irq_fpu_usable())
return crypto_sha256_finup(desc, data, len, out);
kernel_fpu_begin();
if (len)
sha256_base_do_update(desc, data, len,
(sha256_block_fn *)sha256_transform_asm);
sha256_base_do_finalize(desc, (sha256_block_fn *)sha256_transform_asm);
kernel_fpu_end();
return sha256_base_finish(desc, out);
}
static int sha256_ssse3_final(struct shash_desc *desc, u8 *out)
{
return sha256_ssse3_finup(desc, NULL, 0, out);
}
static bool __init avx_usable(void)
{
u64 xcr0;
if (!cpu_has_avx || !cpu_has_osxsave)
return false;
xcr0 = xgetbv(XCR_XFEATURE_ENABLED_MASK);
if ((xcr0 & (XSTATE_SSE | XSTATE_YMM)) != (XSTATE_SSE | XSTATE_YMM)) {
pr_info("AVX detected but unusable.\n");
return false;
}
return true;
}
static int __init sha256_ssse3_mod_init(void)
{
if (cpu_has_ssse3)
sha256_transform_asm = sha256_transform_ssse3;
#ifdef CONFIG_AS_AVX
if (avx_usable()) {
#ifdef CONFIG_AS_AVX2
if (boot_cpu_has(X86_FEATURE_AVX2) && boot_cpu_has(X86_FEATURE_BMI2))
sha256_transform_asm = sha256_transform_rorx;
else
#endif
sha256_transform_asm = sha256_transform_avx;
}
#endif
if (sha256_transform_asm) {
#ifdef CONFIG_AS_AVX
if (sha256_transform_asm == sha256_transform_avx)
pr_info("Using AVX optimized SHA-256 implementation\n");
#ifdef CONFIG_AS_AVX2
else if (sha256_transform_asm == sha256_transform_rorx)
pr_info("Using AVX2 optimized SHA-256 implementation\n");
#endif
else
#endif
pr_info("Using SSSE3 optimized SHA-256 implementation\n");
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
pr_info("Neither AVX nor SSSE3 is available/usable.\n");
return -ENODEV;
}
static void __exit sha256_ssse3_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
