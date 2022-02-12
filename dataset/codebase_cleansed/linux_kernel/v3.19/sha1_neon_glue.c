static int sha1_neon_init(struct shash_desc *desc)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha1_state){
.state = { SHA1_H0, SHA1_H1, SHA1_H2, SHA1_H3, SHA1_H4 },
};
return 0;
}
static int __sha1_neon_update(struct shash_desc *desc, const u8 *data,
unsigned int len, unsigned int partial)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int done = 0;
sctx->count += len;
if (partial) {
done = SHA1_BLOCK_SIZE - partial;
memcpy(sctx->buffer + partial, data, done);
sha1_transform_neon(sctx->state, sctx->buffer, 1);
}
if (len - done >= SHA1_BLOCK_SIZE) {
const unsigned int rounds = (len - done) / SHA1_BLOCK_SIZE;
sha1_transform_neon(sctx->state, data + done, rounds);
done += rounds * SHA1_BLOCK_SIZE;
}
memcpy(sctx->buffer, data + done, len - done);
return 0;
}
static int sha1_neon_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int partial = sctx->count % SHA1_BLOCK_SIZE;
int res;
if (partial + len < SHA1_BLOCK_SIZE) {
sctx->count += len;
memcpy(sctx->buffer + partial, data, len);
return 0;
}
if (!may_use_simd()) {
res = sha1_update_arm(desc, data, len);
} else {
kernel_neon_begin();
res = __sha1_neon_update(desc, data, len, partial);
kernel_neon_end();
}
return res;
}
static int sha1_neon_final(struct shash_desc *desc, u8 *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int i, index, padlen;
__be32 *dst = (__be32 *)out;
__be64 bits;
static const u8 padding[SHA1_BLOCK_SIZE] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count % SHA1_BLOCK_SIZE;
padlen = (index < 56) ? (56 - index) : ((SHA1_BLOCK_SIZE+56) - index);
if (!may_use_simd()) {
sha1_update_arm(desc, padding, padlen);
sha1_update_arm(desc, (const u8 *)&bits, sizeof(bits));
} else {
kernel_neon_begin();
if (padlen <= 56) {
sctx->count += padlen;
memcpy(sctx->buffer + index, padding, padlen);
} else {
__sha1_neon_update(desc, padding, padlen, index);
}
__sha1_neon_update(desc, (const u8 *)&bits, sizeof(bits), 56);
kernel_neon_end();
}
for (i = 0; i < 5; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof(*sctx));
return 0;
}
static int sha1_neon_export(struct shash_desc *desc, void *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha1_neon_import(struct shash_desc *desc, const void *in)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init sha1_neon_mod_init(void)
{
if (!cpu_has_neon())
return -ENODEV;
return crypto_register_shash(&alg);
}
static void __exit sha1_neon_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
