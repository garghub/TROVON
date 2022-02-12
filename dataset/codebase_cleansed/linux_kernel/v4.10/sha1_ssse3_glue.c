static int sha1_update(struct shash_desc *desc, const u8 *data,
unsigned int len, sha1_transform_fn *sha1_xform)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
if (!irq_fpu_usable() ||
(sctx->count % SHA1_BLOCK_SIZE) + len < SHA1_BLOCK_SIZE)
return crypto_sha1_update(desc, data, len);
BUILD_BUG_ON(offsetof(struct sha1_state, state) != 0);
kernel_fpu_begin();
sha1_base_do_update(desc, data, len,
(sha1_block_fn *)sha1_xform);
kernel_fpu_end();
return 0;
}
static int sha1_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out, sha1_transform_fn *sha1_xform)
{
if (!irq_fpu_usable())
return crypto_sha1_finup(desc, data, len, out);
kernel_fpu_begin();
if (len)
sha1_base_do_update(desc, data, len,
(sha1_block_fn *)sha1_xform);
sha1_base_do_finalize(desc, (sha1_block_fn *)sha1_xform);
kernel_fpu_end();
return sha1_base_finish(desc, out);
}
static int sha1_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha1_update(desc, data, len,
(sha1_transform_fn *) sha1_transform_ssse3);
}
static int sha1_ssse3_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha1_finup(desc, data, len, out,
(sha1_transform_fn *) sha1_transform_ssse3);
}
static int sha1_ssse3_final(struct shash_desc *desc, u8 *out)
{
return sha1_ssse3_finup(desc, NULL, 0, out);
}
static int register_sha1_ssse3(void)
{
if (boot_cpu_has(X86_FEATURE_SSSE3))
return crypto_register_shash(&sha1_ssse3_alg);
return 0;
}
static void unregister_sha1_ssse3(void)
{
if (boot_cpu_has(X86_FEATURE_SSSE3))
crypto_unregister_shash(&sha1_ssse3_alg);
}
static int sha1_avx_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha1_update(desc, data, len,
(sha1_transform_fn *) sha1_transform_avx);
}
static int sha1_avx_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha1_finup(desc, data, len, out,
(sha1_transform_fn *) sha1_transform_avx);
}
static int sha1_avx_final(struct shash_desc *desc, u8 *out)
{
return sha1_avx_finup(desc, NULL, 0, out);
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
static int register_sha1_avx(void)
{
if (avx_usable())
return crypto_register_shash(&sha1_avx_alg);
return 0;
}
static void unregister_sha1_avx(void)
{
if (avx_usable())
crypto_unregister_shash(&sha1_avx_alg);
}
static inline int register_sha1_avx(void) { return 0; }
static inline void unregister_sha1_avx(void) { }
static bool avx2_usable(void)
{
if (avx_usable() && boot_cpu_has(X86_FEATURE_AVX2)
&& boot_cpu_has(X86_FEATURE_BMI1)
&& boot_cpu_has(X86_FEATURE_BMI2))
return true;
return false;
}
static void sha1_apply_transform_avx2(u32 *digest, const char *data,
unsigned int rounds)
{
if (rounds >= SHA1_AVX2_BLOCK_OPTSIZE)
sha1_transform_avx2(digest, data, rounds);
else
sha1_transform_avx(digest, data, rounds);
}
static int sha1_avx2_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha1_update(desc, data, len,
(sha1_transform_fn *) sha1_apply_transform_avx2);
}
static int sha1_avx2_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha1_finup(desc, data, len, out,
(sha1_transform_fn *) sha1_apply_transform_avx2);
}
static int sha1_avx2_final(struct shash_desc *desc, u8 *out)
{
return sha1_avx2_finup(desc, NULL, 0, out);
}
static int register_sha1_avx2(void)
{
if (avx2_usable())
return crypto_register_shash(&sha1_avx2_alg);
return 0;
}
static void unregister_sha1_avx2(void)
{
if (avx2_usable())
crypto_unregister_shash(&sha1_avx2_alg);
}
static inline int register_sha1_avx2(void) { return 0; }
static inline void unregister_sha1_avx2(void) { }
static int sha1_ni_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
return sha1_update(desc, data, len,
(sha1_transform_fn *) sha1_ni_transform);
}
static int sha1_ni_finup(struct shash_desc *desc, const u8 *data,
unsigned int len, u8 *out)
{
return sha1_finup(desc, data, len, out,
(sha1_transform_fn *) sha1_ni_transform);
}
static int sha1_ni_final(struct shash_desc *desc, u8 *out)
{
return sha1_ni_finup(desc, NULL, 0, out);
}
static int register_sha1_ni(void)
{
if (boot_cpu_has(X86_FEATURE_SHA_NI))
return crypto_register_shash(&sha1_ni_alg);
return 0;
}
static void unregister_sha1_ni(void)
{
if (boot_cpu_has(X86_FEATURE_SHA_NI))
crypto_unregister_shash(&sha1_ni_alg);
}
static inline int register_sha1_ni(void) { return 0; }
static inline void unregister_sha1_ni(void) { }
static int __init sha1_ssse3_mod_init(void)
{
if (register_sha1_ssse3())
goto fail;
if (register_sha1_avx()) {
unregister_sha1_ssse3();
goto fail;
}
if (register_sha1_avx2()) {
unregister_sha1_avx();
unregister_sha1_ssse3();
goto fail;
}
if (register_sha1_ni()) {
unregister_sha1_avx2();
unregister_sha1_avx();
unregister_sha1_ssse3();
goto fail;
}
return 0;
fail:
return -ENODEV;
}
static void __exit sha1_ssse3_mod_fini(void)
{
unregister_sha1_ni();
unregister_sha1_avx2();
unregister_sha1_avx();
unregister_sha1_ssse3();
}
