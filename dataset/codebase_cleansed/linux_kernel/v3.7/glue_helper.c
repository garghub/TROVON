static int __glue_ecb_crypt_128bit(const struct common_glue_ctx *gctx,
struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
void *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = 128 / 8;
unsigned int nbytes, i, func_bytes;
bool fpu_enabled = false;
int err;
err = blkcipher_walk_virt(desc, walk);
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
fpu_enabled = glue_fpu_begin(bsize, gctx->fpu_blocks_limit,
desc, fpu_enabled, nbytes);
for (i = 0; i < gctx->num_funcs; i++) {
func_bytes = bsize * gctx->funcs[i].num_blocks;
if (nbytes >= func_bytes) {
do {
gctx->funcs[i].fn_u.ecb(ctx, wdst,
wsrc);
wsrc += func_bytes;
wdst += func_bytes;
nbytes -= func_bytes;
} while (nbytes >= func_bytes);
if (nbytes < bsize)
goto done;
}
}
done:
err = blkcipher_walk_done(desc, walk, nbytes);
}
glue_fpu_end(fpu_enabled);
return err;
}
int glue_ecb_crypt_128bit(const struct common_glue_ctx *gctx,
struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return __glue_ecb_crypt_128bit(gctx, desc, &walk);
}
static unsigned int __glue_cbc_encrypt_128bit(const common_glue_func_t fn,
struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
void *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = 128 / 8;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 *iv = (u128 *)walk->iv;
do {
u128_xor(dst, src, iv);
fn(ctx, (u8 *)dst, (u8 *)dst);
iv = dst;
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
*(u128 *)walk->iv = *iv;
return nbytes;
}
int glue_cbc_encrypt_128bit(const common_glue_func_t fn,
struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
nbytes = __glue_cbc_encrypt_128bit(fn, desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
return err;
}
static unsigned int
__glue_cbc_decrypt_128bit(const struct common_glue_ctx *gctx,
struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
void *ctx = crypto_blkcipher_ctx(desc->tfm);
const unsigned int bsize = 128 / 8;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 last_iv;
unsigned int num_blocks, func_bytes;
unsigned int i;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
for (i = 0; i < gctx->num_funcs; i++) {
num_blocks = gctx->funcs[i].num_blocks;
func_bytes = bsize * num_blocks;
if (nbytes >= func_bytes) {
do {
nbytes -= func_bytes - bsize;
src -= num_blocks - 1;
dst -= num_blocks - 1;
gctx->funcs[i].fn_u.cbc(ctx, dst, src);
nbytes -= bsize;
if (nbytes < bsize)
goto done;
u128_xor(dst, dst, src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= func_bytes);
if (nbytes < bsize)
goto done;
}
}
done:
u128_xor(dst, dst, (u128 *)walk->iv);
*(u128 *)walk->iv = last_iv;
return nbytes;
}
int glue_cbc_decrypt_128bit(const struct common_glue_ctx *gctx,
struct blkcipher_desc *desc,
struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
const unsigned int bsize = 128 / 8;
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
fpu_enabled = glue_fpu_begin(bsize, gctx->fpu_blocks_limit,
desc, fpu_enabled, nbytes);
nbytes = __glue_cbc_decrypt_128bit(gctx, desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
glue_fpu_end(fpu_enabled);
return err;
}
static void glue_ctr_crypt_final_128bit(const common_glue_ctr_func_t fn_ctr,
struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
void *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 *src = (u8 *)walk->src.virt.addr;
u8 *dst = (u8 *)walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
u128 ctrblk;
u128 tmp;
be128_to_u128(&ctrblk, (be128 *)walk->iv);
memcpy(&tmp, src, nbytes);
fn_ctr(ctx, &tmp, &tmp, &ctrblk);
memcpy(dst, &tmp, nbytes);
u128_to_be128((be128 *)walk->iv, &ctrblk);
}
static unsigned int __glue_ctr_crypt_128bit(const struct common_glue_ctx *gctx,
struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
const unsigned int bsize = 128 / 8;
void *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ctrblk;
unsigned int num_blocks, func_bytes;
unsigned int i;
be128_to_u128(&ctrblk, (be128 *)walk->iv);
for (i = 0; i < gctx->num_funcs; i++) {
num_blocks = gctx->funcs[i].num_blocks;
func_bytes = bsize * num_blocks;
if (nbytes >= func_bytes) {
do {
gctx->funcs[i].fn_u.ctr(ctx, dst, src, &ctrblk);
src += num_blocks;
dst += num_blocks;
nbytes -= func_bytes;
} while (nbytes >= func_bytes);
if (nbytes < bsize)
goto done;
}
}
done:
u128_to_be128((be128 *)walk->iv, &ctrblk);
return nbytes;
}
int glue_ctr_crypt_128bit(const struct common_glue_ctx *gctx,
struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
const unsigned int bsize = 128 / 8;
bool fpu_enabled = false;
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, bsize);
while ((nbytes = walk.nbytes) >= bsize) {
fpu_enabled = glue_fpu_begin(bsize, gctx->fpu_blocks_limit,
desc, fpu_enabled, nbytes);
nbytes = __glue_ctr_crypt_128bit(gctx, desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
glue_fpu_end(fpu_enabled);
if (walk.nbytes) {
glue_ctr_crypt_final_128bit(
gctx->funcs[gctx->num_funcs - 1].fn_u.ctr, desc, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
