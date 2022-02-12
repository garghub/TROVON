static int sha512_ssse3_init(struct shash_desc *desc)
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
static int __sha512_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len, unsigned int partial)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int done = 0;
sctx->count[0] += len;
if (sctx->count[0] < len)
sctx->count[1]++;
if (partial) {
done = SHA512_BLOCK_SIZE - partial;
memcpy(sctx->buf + partial, data, done);
sha512_transform_asm(sctx->buf, sctx->state, 1);
}
if (len - done >= SHA512_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA512_BLOCK_SIZE;
sha512_transform_asm(data + done, sctx->state, (u64) rounds);
done += rounds * SHA512_BLOCK_SIZE;
}
memcpy(sctx->buf, data + done, len - done);
return 0;
}
static int sha512_ssse3_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count[0] % SHA512_BLOCK_SIZE;
int res;
if (partial + len < SHA512_BLOCK_SIZE) {
sctx->count[0] += len;
if (sctx->count[0] < len)
sctx->count[1]++;
memcpy(sctx->buf + partial, data, len);
return 0;
}
if (!irq_fpu_usable()) {
res = crypto_sha512_update(desc, data, len);
} else {
kernel_fpu_begin();
res = __sha512_ssse3_update(desc, data, len, partial);
kernel_fpu_end();
}
return res;
}
static int sha512_ssse3_final(struct shash_desc *desc, u8 *out)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be64 *dst = (__be64 *)out;
__be64 bits[2];
static const u8 padding[SHA512_BLOCK_SIZE] = { 0x80, };
bits[1] = cpu_to_be64(sctx->count[0] << 3);
bits[0] = cpu_to_be64(sctx->count[1] << 3) | sctx->count[0] >> 61;
index = sctx->count[0] & 0x7f;
padlen = (index < 112) ? (112 - index) : ((128+112) - index);
if (!irq_fpu_usable()) {
crypto_sha512_update(desc, padding, padlen);
crypto_sha512_update(desc, (const u8 *)&bits, sizeof(bits));
} else {
kernel_fpu_begin();
if (padlen <= 112) {
sctx->count[0] += padlen;
if (sctx->count[0] < padlen)
sctx->count[1]++;
memcpy(sctx->buf + index, padding, padlen);
} else {
__sha512_ssse3_update(desc, padding, padlen, index);
}
__sha512_ssse3_update(desc, (const u8 *)&bits,
sizeof(bits), 112);
kernel_fpu_end();
}
for (i = 0; i < 8; i++)
dst[i] = cpu_to_be64(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha512_ssse3_export(struct shash_desc *desc, void *out)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha512_ssse3_import(struct shash_desc *desc, const void *in)
{
struct sha512_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int sha384_ssse3_init(struct shash_desc *desc)
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
static int sha384_ssse3_final(struct shash_desc *desc, u8 *hash)
{
u8 D[SHA512_DIGEST_SIZE];
sha512_ssse3_final(desc, D);
memcpy(hash, D, SHA384_DIGEST_SIZE);
memset(D, 0, SHA512_DIGEST_SIZE);
return 0;
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
static int __init sha512_ssse3_mod_init(void)
{
if (cpu_has_ssse3)
sha512_transform_asm = sha512_transform_ssse3;
#ifdef CONFIG_AS_AVX
if (avx_usable()) {
#ifdef CONFIG_AS_AVX2
if (boot_cpu_has(X86_FEATURE_AVX2))
sha512_transform_asm = sha512_transform_rorx;
else
#endif
sha512_transform_asm = sha512_transform_avx;
}
#endif
if (sha512_transform_asm) {
#ifdef CONFIG_AS_AVX
if (sha512_transform_asm == sha512_transform_avx)
pr_info("Using AVX optimized SHA-512 implementation\n");
#ifdef CONFIG_AS_AVX2
else if (sha512_transform_asm == sha512_transform_rorx)
pr_info("Using AVX2 optimized SHA-512 implementation\n");
#endif
else
#endif
pr_info("Using SSSE3 optimized SHA-512 implementation\n");
return crypto_register_shashes(algs, ARRAY_SIZE(algs));
}
pr_info("Neither AVX nor SSSE3 is available/usable.\n");
return -ENODEV;
}
static void __exit sha512_ssse3_mod_fini(void)
{
crypto_unregister_shashes(algs, ARRAY_SIZE(algs));
}
