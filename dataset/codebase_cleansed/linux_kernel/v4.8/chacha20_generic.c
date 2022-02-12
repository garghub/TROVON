static inline u32 le32_to_cpuvp(const void *p)
{
return le32_to_cpup(p);
}
static void chacha20_docrypt(u32 *state, u8 *dst, const u8 *src,
unsigned int bytes)
{
u8 stream[CHACHA20_BLOCK_SIZE];
if (dst != src)
memcpy(dst, src, bytes);
while (bytes >= CHACHA20_BLOCK_SIZE) {
chacha20_block(state, stream);
crypto_xor(dst, stream, CHACHA20_BLOCK_SIZE);
bytes -= CHACHA20_BLOCK_SIZE;
dst += CHACHA20_BLOCK_SIZE;
}
if (bytes) {
chacha20_block(state, stream);
crypto_xor(dst, stream, bytes);
}
}
void crypto_chacha20_init(u32 *state, struct chacha20_ctx *ctx, u8 *iv)
{
static const char constant[16] = "expand 32-byte k";
state[0] = le32_to_cpuvp(constant + 0);
state[1] = le32_to_cpuvp(constant + 4);
state[2] = le32_to_cpuvp(constant + 8);
state[3] = le32_to_cpuvp(constant + 12);
state[4] = ctx->key[0];
state[5] = ctx->key[1];
state[6] = ctx->key[2];
state[7] = ctx->key[3];
state[8] = ctx->key[4];
state[9] = ctx->key[5];
state[10] = ctx->key[6];
state[11] = ctx->key[7];
state[12] = le32_to_cpuvp(iv + 0);
state[13] = le32_to_cpuvp(iv + 4);
state[14] = le32_to_cpuvp(iv + 8);
state[15] = le32_to_cpuvp(iv + 12);
}
int crypto_chacha20_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keysize)
{
struct chacha20_ctx *ctx = crypto_tfm_ctx(tfm);
int i;
if (keysize != CHACHA20_KEY_SIZE)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(ctx->key); i++)
ctx->key[i] = le32_to_cpuvp(key + i * sizeof(u32));
return 0;
}
int crypto_chacha20_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
u32 state[16];
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, CHACHA20_BLOCK_SIZE);
crypto_chacha20_init(state, crypto_blkcipher_ctx(desc->tfm), walk.iv);
while (walk.nbytes >= CHACHA20_BLOCK_SIZE) {
chacha20_docrypt(state, walk.dst.virt.addr, walk.src.virt.addr,
rounddown(walk.nbytes, CHACHA20_BLOCK_SIZE));
err = blkcipher_walk_done(desc, &walk,
walk.nbytes % CHACHA20_BLOCK_SIZE);
}
if (walk.nbytes) {
chacha20_docrypt(state, walk.dst.virt.addr, walk.src.virt.addr,
walk.nbytes);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int __init chacha20_generic_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit chacha20_generic_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
