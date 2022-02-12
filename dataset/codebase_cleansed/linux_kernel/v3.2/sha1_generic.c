static int sha1_init(struct shash_desc *desc)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
*sctx = (struct sha1_state){
.state = { SHA1_H0, SHA1_H1, SHA1_H2, SHA1_H3, SHA1_H4 },
};
return 0;
}
int crypto_sha1_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
unsigned int partial, done;
const u8 *src;
partial = sctx->count % SHA1_BLOCK_SIZE;
sctx->count += len;
done = 0;
src = data;
if ((partial + len) >= SHA1_BLOCK_SIZE) {
u32 temp[SHA_WORKSPACE_WORDS];
if (partial) {
done = -partial;
memcpy(sctx->buffer + partial, data,
done + SHA1_BLOCK_SIZE);
src = sctx->buffer;
}
do {
sha_transform(sctx->state, src, temp);
done += SHA1_BLOCK_SIZE;
src = data + done;
} while (done + SHA1_BLOCK_SIZE <= len);
memset(temp, 0, sizeof(temp));
partial = 0;
}
memcpy(sctx->buffer + partial, src, len - done);
return 0;
}
static int sha1_final(struct shash_desc *desc, u8 *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
__be32 *dst = (__be32 *)out;
u32 i, index, padlen;
__be64 bits;
static const u8 padding[64] = { 0x80, };
bits = cpu_to_be64(sctx->count << 3);
index = sctx->count & 0x3f;
padlen = (index < 56) ? (56 - index) : ((64+56) - index);
crypto_sha1_update(desc, padding, padlen);
crypto_sha1_update(desc, (const u8 *)&bits, sizeof(bits));
for (i = 0; i < 5; i++)
dst[i] = cpu_to_be32(sctx->state[i]);
memset(sctx, 0, sizeof *sctx);
return 0;
}
static int sha1_export(struct shash_desc *desc, void *out)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(out, sctx, sizeof(*sctx));
return 0;
}
static int sha1_import(struct shash_desc *desc, const void *in)
{
struct sha1_state *sctx = shash_desc_ctx(desc);
memcpy(sctx, in, sizeof(*sctx));
return 0;
}
static int __init sha1_generic_mod_init(void)
{
return crypto_register_shash(&alg);
}
static void __exit sha1_generic_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
