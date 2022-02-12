static void salsa20_wordtobyte(u8 output[64], const u32 input[16])
{
u32 x[16];
int i;
memcpy(x, input, sizeof(x));
for (i = 20; i > 0; i -= 2) {
x[ 4] ^= rol32((x[ 0] + x[12]), 7);
x[ 8] ^= rol32((x[ 4] + x[ 0]), 9);
x[12] ^= rol32((x[ 8] + x[ 4]), 13);
x[ 0] ^= rol32((x[12] + x[ 8]), 18);
x[ 9] ^= rol32((x[ 5] + x[ 1]), 7);
x[13] ^= rol32((x[ 9] + x[ 5]), 9);
x[ 1] ^= rol32((x[13] + x[ 9]), 13);
x[ 5] ^= rol32((x[ 1] + x[13]), 18);
x[14] ^= rol32((x[10] + x[ 6]), 7);
x[ 2] ^= rol32((x[14] + x[10]), 9);
x[ 6] ^= rol32((x[ 2] + x[14]), 13);
x[10] ^= rol32((x[ 6] + x[ 2]), 18);
x[ 3] ^= rol32((x[15] + x[11]), 7);
x[ 7] ^= rol32((x[ 3] + x[15]), 9);
x[11] ^= rol32((x[ 7] + x[ 3]), 13);
x[15] ^= rol32((x[11] + x[ 7]), 18);
x[ 1] ^= rol32((x[ 0] + x[ 3]), 7);
x[ 2] ^= rol32((x[ 1] + x[ 0]), 9);
x[ 3] ^= rol32((x[ 2] + x[ 1]), 13);
x[ 0] ^= rol32((x[ 3] + x[ 2]), 18);
x[ 6] ^= rol32((x[ 5] + x[ 4]), 7);
x[ 7] ^= rol32((x[ 6] + x[ 5]), 9);
x[ 4] ^= rol32((x[ 7] + x[ 6]), 13);
x[ 5] ^= rol32((x[ 4] + x[ 7]), 18);
x[11] ^= rol32((x[10] + x[ 9]), 7);
x[ 8] ^= rol32((x[11] + x[10]), 9);
x[ 9] ^= rol32((x[ 8] + x[11]), 13);
x[10] ^= rol32((x[ 9] + x[ 8]), 18);
x[12] ^= rol32((x[15] + x[14]), 7);
x[13] ^= rol32((x[12] + x[15]), 9);
x[14] ^= rol32((x[13] + x[12]), 13);
x[15] ^= rol32((x[14] + x[13]), 18);
}
for (i = 0; i < 16; ++i)
x[i] += input[i];
for (i = 0; i < 16; ++i)
U32TO8_LITTLE(output + 4 * i,x[i]);
}
static void salsa20_keysetup(struct salsa20_ctx *ctx, const u8 *k, u32 kbytes)
{
const char *constants;
ctx->input[1] = U8TO32_LITTLE(k + 0);
ctx->input[2] = U8TO32_LITTLE(k + 4);
ctx->input[3] = U8TO32_LITTLE(k + 8);
ctx->input[4] = U8TO32_LITTLE(k + 12);
if (kbytes == 32) {
k += 16;
constants = sigma;
} else {
constants = tau;
}
ctx->input[11] = U8TO32_LITTLE(k + 0);
ctx->input[12] = U8TO32_LITTLE(k + 4);
ctx->input[13] = U8TO32_LITTLE(k + 8);
ctx->input[14] = U8TO32_LITTLE(k + 12);
ctx->input[0] = U8TO32_LITTLE(constants + 0);
ctx->input[5] = U8TO32_LITTLE(constants + 4);
ctx->input[10] = U8TO32_LITTLE(constants + 8);
ctx->input[15] = U8TO32_LITTLE(constants + 12);
}
static void salsa20_ivsetup(struct salsa20_ctx *ctx, const u8 *iv)
{
ctx->input[6] = U8TO32_LITTLE(iv + 0);
ctx->input[7] = U8TO32_LITTLE(iv + 4);
ctx->input[8] = 0;
ctx->input[9] = 0;
}
static void salsa20_encrypt_bytes(struct salsa20_ctx *ctx, u8 *dst,
const u8 *src, unsigned int bytes)
{
u8 buf[64];
if (dst != src)
memcpy(dst, src, bytes);
while (bytes) {
salsa20_wordtobyte(buf, ctx->input);
ctx->input[8]++;
if (!ctx->input[8])
ctx->input[9]++;
if (bytes <= 64) {
crypto_xor(dst, buf, bytes);
return;
}
crypto_xor(dst, buf, 64);
bytes -= 64;
dst += 64;
}
}
static int setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keysize)
{
struct salsa20_ctx *ctx = crypto_tfm_ctx(tfm);
salsa20_keysetup(ctx, key, keysize);
return 0;
}
static int encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
struct crypto_blkcipher *tfm = desc->tfm;
struct salsa20_ctx *ctx = crypto_blkcipher_ctx(tfm);
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, 64);
salsa20_ivsetup(ctx, walk.iv);
if (likely(walk.nbytes == nbytes))
{
salsa20_encrypt_bytes(ctx, walk.dst.virt.addr,
walk.src.virt.addr, nbytes);
return blkcipher_walk_done(desc, &walk, 0);
}
while (walk.nbytes >= 64) {
salsa20_encrypt_bytes(ctx, walk.dst.virt.addr,
walk.src.virt.addr,
walk.nbytes - (walk.nbytes % 64));
err = blkcipher_walk_done(desc, &walk, walk.nbytes % 64);
}
if (walk.nbytes) {
salsa20_encrypt_bytes(ctx, walk.dst.virt.addr,
walk.src.virt.addr, walk.nbytes);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static int __init salsa20_generic_mod_init(void)
{
return crypto_register_alg(&alg);
}
static void __exit salsa20_generic_mod_fini(void)
{
crypto_unregister_alg(&alg);
}
