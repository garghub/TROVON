static void octeon_md5_store_hash(struct md5_state *ctx)
{
u64 *hash = (u64 *)ctx->hash;
write_octeon_64bit_hash_dword(hash[0], 0);
write_octeon_64bit_hash_dword(hash[1], 1);
}
static void octeon_md5_read_hash(struct md5_state *ctx)
{
u64 *hash = (u64 *)ctx->hash;
hash[0] = read_octeon_64bit_hash_dword(0);
hash[1] = read_octeon_64bit_hash_dword(1);
}
static void octeon_md5_transform(const void *_block)
{
const u64 *block = _block;
write_octeon_64bit_block_dword(block[0], 0);
write_octeon_64bit_block_dword(block[1], 1);
write_octeon_64bit_block_dword(block[2], 2);
write_octeon_64bit_block_dword(block[3], 3);
write_octeon_64bit_block_dword(block[4], 4);
write_octeon_64bit_block_dword(block[5], 5);
write_octeon_64bit_block_dword(block[6], 6);
octeon_md5_start(block[7]);
}
static int octeon_md5_init(struct shash_desc *desc)
{
struct md5_state *mctx = shash_desc_ctx(desc);
mctx->hash[0] = cpu_to_le32(0x67452301);
mctx->hash[1] = cpu_to_le32(0xefcdab89);
mctx->hash[2] = cpu_to_le32(0x98badcfe);
mctx->hash[3] = cpu_to_le32(0x10325476);
mctx->byte_count = 0;
return 0;
}
static int octeon_md5_update(struct shash_desc *desc, const u8 *data,
unsigned int len)
{
struct md5_state *mctx = shash_desc_ctx(desc);
const u32 avail = sizeof(mctx->block) - (mctx->byte_count & 0x3f);
struct octeon_cop2_state state;
unsigned long flags;
mctx->byte_count += len;
if (avail > len) {
memcpy((char *)mctx->block + (sizeof(mctx->block) - avail),
data, len);
return 0;
}
memcpy((char *)mctx->block + (sizeof(mctx->block) - avail), data,
avail);
flags = octeon_crypto_enable(&state);
octeon_md5_store_hash(mctx);
octeon_md5_transform(mctx->block);
data += avail;
len -= avail;
while (len >= sizeof(mctx->block)) {
octeon_md5_transform(data);
data += sizeof(mctx->block);
len -= sizeof(mctx->block);
}
octeon_md5_read_hash(mctx);
octeon_crypto_disable(&state, flags);
memcpy(mctx->block, data, len);
return 0;
}
static int octeon_md5_final(struct shash_desc *desc, u8 *out)
{
struct md5_state *mctx = shash_desc_ctx(desc);
const unsigned int offset = mctx->byte_count & 0x3f;
char *p = (char *)mctx->block + offset;
int padding = 56 - (offset + 1);
struct octeon_cop2_state state;
unsigned long flags;
*p++ = 0x80;
flags = octeon_crypto_enable(&state);
octeon_md5_store_hash(mctx);
if (padding < 0) {
memset(p, 0x00, padding + sizeof(u64));
octeon_md5_transform(mctx->block);
p = (char *)mctx->block;
padding = 56;
}
memset(p, 0, padding);
mctx->block[14] = cpu_to_le32(mctx->byte_count << 3);
mctx->block[15] = cpu_to_le32(mctx->byte_count >> 29);
octeon_md5_transform(mctx->block);
octeon_md5_read_hash(mctx);
octeon_crypto_disable(&state, flags);
memcpy(out, mctx->hash, sizeof(mctx->hash));
memset(mctx, 0, sizeof(*mctx));
return 0;
}
static int octeon_md5_export(struct shash_desc *desc, void *out)
{
struct md5_state *ctx = shash_desc_ctx(desc);
memcpy(out, ctx, sizeof(*ctx));
return 0;
}
static int octeon_md5_import(struct shash_desc *desc, const void *in)
{
struct md5_state *ctx = shash_desc_ctx(desc);
memcpy(ctx, in, sizeof(*ctx));
return 0;
}
static int __init md5_mod_init(void)
{
if (!octeon_has_crypto())
return -ENOTSUPP;
return crypto_register_shash(&alg);
}
static void __exit md5_mod_fini(void)
{
crypto_unregister_shash(&alg);
}
