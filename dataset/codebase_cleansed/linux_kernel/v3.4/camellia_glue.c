static inline void camellia_enc_blk(struct camellia_ctx *ctx, u8 *dst,
const u8 *src)
{
__camellia_enc_blk(ctx, dst, src, false);
}
static inline void camellia_enc_blk_xor(struct camellia_ctx *ctx, u8 *dst,
const u8 *src)
{
__camellia_enc_blk(ctx, dst, src, true);
}
static inline void camellia_enc_blk_2way(struct camellia_ctx *ctx, u8 *dst,
const u8 *src)
{
__camellia_enc_blk_2way(ctx, dst, src, false);
}
static inline void camellia_enc_blk_xor_2way(struct camellia_ctx *ctx, u8 *dst,
const u8 *src)
{
__camellia_enc_blk_2way(ctx, dst, src, true);
}
static void camellia_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
camellia_enc_blk(crypto_tfm_ctx(tfm), dst, src);
}
static void camellia_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
camellia_dec_blk(crypto_tfm_ctx(tfm), dst, src);
}
static void camellia_setup_tail(u64 *subkey, u64 *subRL, int max)
{
u64 kw4, tt;
u32 dw, tl, tr;
subRL[3] ^= subRL[1];
subRL[5] ^= subRL[1];
subRL[7] ^= subRL[1];
subRL[1] ^= (subRL[1] & ~subRL[9]) << 32;
dw = (subRL[1] & subRL[9]) >> 32,
subRL[1] ^= rol32(dw, 1);
subRL[11] ^= subRL[1];
subRL[13] ^= subRL[1];
subRL[15] ^= subRL[1];
subRL[1] ^= (subRL[1] & ~subRL[17]) << 32;
dw = (subRL[1] & subRL[17]) >> 32,
subRL[1] ^= rol32(dw, 1);
subRL[19] ^= subRL[1];
subRL[21] ^= subRL[1];
subRL[23] ^= subRL[1];
if (max == 24) {
subRL[24] ^= subRL[1];
kw4 = subRL[25];
} else {
subRL[1] ^= (subRL[1] & ~subRL[25]) << 32;
dw = (subRL[1] & subRL[25]) >> 32,
subRL[1] ^= rol32(dw, 1);
subRL[27] ^= subRL[1];
subRL[29] ^= subRL[1];
subRL[31] ^= subRL[1];
subRL[32] ^= subRL[1];
kw4 = subRL[33];
subRL[30] ^= kw4;
subRL[28] ^= kw4;
subRL[26] ^= kw4;
kw4 ^= (kw4 & ~subRL[24]) << 32;
dw = (kw4 & subRL[24]) >> 32,
kw4 ^= rol32(dw, 1);
}
subRL[22] ^= kw4;
subRL[20] ^= kw4;
subRL[18] ^= kw4;
kw4 ^= (kw4 & ~subRL[16]) << 32;
dw = (kw4 & subRL[16]) >> 32,
kw4 ^= rol32(dw, 1);
subRL[14] ^= kw4;
subRL[12] ^= kw4;
subRL[10] ^= kw4;
kw4 ^= (kw4 & ~subRL[8]) << 32;
dw = (kw4 & subRL[8]) >> 32,
kw4 ^= rol32(dw, 1);
subRL[6] ^= kw4;
subRL[4] ^= kw4;
subRL[2] ^= kw4;
subRL[0] ^= kw4;
SET_SUBKEY_LR(0, subRL[0] ^ subRL[2]);
SET_SUBKEY_LR(2, subRL[3]);
SET_SUBKEY_LR(3, subRL[2] ^ subRL[4]);
SET_SUBKEY_LR(4, subRL[3] ^ subRL[5]);
SET_SUBKEY_LR(5, subRL[4] ^ subRL[6]);
SET_SUBKEY_LR(6, subRL[5] ^ subRL[7]);
tl = (subRL[10] >> 32) ^ (subRL[10] & ~subRL[8]);
dw = tl & (subRL[8] >> 32),
tr = subRL[10] ^ rol32(dw, 1);
tt = (tr | ((u64)tl << 32));
SET_SUBKEY_LR(7, subRL[6] ^ tt);
SET_SUBKEY_LR(8, subRL[8]);
SET_SUBKEY_LR(9, subRL[9]);
tl = (subRL[7] >> 32) ^ (subRL[7] & ~subRL[9]);
dw = tl & (subRL[9] >> 32),
tr = subRL[7] ^ rol32(dw, 1);
tt = (tr | ((u64)tl << 32));
SET_SUBKEY_LR(10, subRL[11] ^ tt);
SET_SUBKEY_LR(11, subRL[10] ^ subRL[12]);
SET_SUBKEY_LR(12, subRL[11] ^ subRL[13]);
SET_SUBKEY_LR(13, subRL[12] ^ subRL[14]);
SET_SUBKEY_LR(14, subRL[13] ^ subRL[15]);
tl = (subRL[18] >> 32) ^ (subRL[18] & ~subRL[16]);
dw = tl & (subRL[16] >> 32),
tr = subRL[18] ^ rol32(dw, 1);
tt = (tr | ((u64)tl << 32));
SET_SUBKEY_LR(15, subRL[14] ^ tt);
SET_SUBKEY_LR(16, subRL[16]);
SET_SUBKEY_LR(17, subRL[17]);
tl = (subRL[15] >> 32) ^ (subRL[15] & ~subRL[17]);
dw = tl & (subRL[17] >> 32),
tr = subRL[15] ^ rol32(dw, 1);
tt = (tr | ((u64)tl << 32));
SET_SUBKEY_LR(18, subRL[19] ^ tt);
SET_SUBKEY_LR(19, subRL[18] ^ subRL[20]);
SET_SUBKEY_LR(20, subRL[19] ^ subRL[21]);
SET_SUBKEY_LR(21, subRL[20] ^ subRL[22]);
SET_SUBKEY_LR(22, subRL[21] ^ subRL[23]);
if (max == 24) {
SET_SUBKEY_LR(23, subRL[22]);
SET_SUBKEY_LR(24, subRL[24] ^ subRL[23]);
} else {
tl = (subRL[26] >> 32) ^ (subRL[26] & ~subRL[24]);
dw = tl & (subRL[24] >> 32),
tr = subRL[26] ^ rol32(dw, 1);
tt = (tr | ((u64)tl << 32));
SET_SUBKEY_LR(23, subRL[22] ^ tt);
SET_SUBKEY_LR(24, subRL[24]);
SET_SUBKEY_LR(25, subRL[25]);
tl = (subRL[23] >> 32) ^ (subRL[23] & ~subRL[25]);
dw = tl & (subRL[25] >> 32),
tr = subRL[23] ^ rol32(dw, 1);
tt = (tr | ((u64)tl << 32));
SET_SUBKEY_LR(26, subRL[27] ^ tt);
SET_SUBKEY_LR(27, subRL[26] ^ subRL[28]);
SET_SUBKEY_LR(28, subRL[27] ^ subRL[29]);
SET_SUBKEY_LR(29, subRL[28] ^ subRL[30]);
SET_SUBKEY_LR(30, subRL[29] ^ subRL[31]);
SET_SUBKEY_LR(31, subRL[30]);
SET_SUBKEY_LR(32, subRL[32] ^ subRL[31]);
}
}
static void camellia_setup128(const unsigned char *key, u64 *subkey)
{
u64 kl, kr, ww;
u64 subRL[26];
kl = get_unaligned_be64(key);
kr = get_unaligned_be64(key + 8);
subRL[0] = kl;
subRL[1] = kr;
ROLDQ(kl, kr, 15);
subRL[4] = kl;
subRL[5] = kr;
ROLDQ(kl, kr, 30);
subRL[10] = kl;
subRL[11] = kr;
ROLDQ(kl, kr, 15);
subRL[13] = kr;
ROLDQ(kl, kr, 17);
subRL[16] = kl;
subRL[17] = kr;
ROLDQ(kl, kr, 17);
subRL[18] = kl;
subRL[19] = kr;
ROLDQ(kl, kr, 17);
subRL[22] = kl;
subRL[23] = kr;
kl = subRL[0];
kr = subRL[1];
CAMELLIA_F(kl, CAMELLIA_SIGMA1L, CAMELLIA_SIGMA1R, ww);
kr ^= ww;
CAMELLIA_F(kr, CAMELLIA_SIGMA2L, CAMELLIA_SIGMA2R, kl);
CAMELLIA_F(kl, CAMELLIA_SIGMA3L, CAMELLIA_SIGMA3R, kr);
kr ^= ww;
CAMELLIA_F(kr, CAMELLIA_SIGMA4L, CAMELLIA_SIGMA4R, ww);
kl ^= ww;
subRL[2] = kl;
subRL[3] = kr;
ROLDQ(kl, kr, 15);
subRL[6] = kl;
subRL[7] = kr;
ROLDQ(kl, kr, 15);
subRL[8] = kl;
subRL[9] = kr;
ROLDQ(kl, kr, 15);
subRL[12] = kl;
ROLDQ(kl, kr, 15);
subRL[14] = kl;
subRL[15] = kr;
ROLDQ(kl, kr, 34);
subRL[20] = kl;
subRL[21] = kr;
ROLDQ(kl, kr, 17);
subRL[24] = kl;
subRL[25] = kr;
camellia_setup_tail(subkey, subRL, 24);
}
static void camellia_setup256(const unsigned char *key, u64 *subkey)
{
u64 kl, kr;
u64 krl, krr;
u64 ww;
u64 subRL[34];
kl = get_unaligned_be64(key);
kr = get_unaligned_be64(key + 8);
krl = get_unaligned_be64(key + 16);
krr = get_unaligned_be64(key + 24);
subRL[0] = kl;
subRL[1] = kr;
ROLDQ(kl, kr, 45);
subRL[12] = kl;
subRL[13] = kr;
ROLDQ(kl, kr, 15);
subRL[16] = kl;
subRL[17] = kr;
ROLDQ(kl, kr, 17);
subRL[22] = kl;
subRL[23] = kr;
ROLDQ(kl, kr, 34);
subRL[30] = kl;
subRL[31] = kr;
ROLDQ(krl, krr, 15);
subRL[4] = krl;
subRL[5] = krr;
ROLDQ(krl, krr, 15);
subRL[8] = krl;
subRL[9] = krr;
ROLDQ(krl, krr, 30);
subRL[18] = krl;
subRL[19] = krr;
ROLDQ(krl, krr, 34);
subRL[26] = krl;
subRL[27] = krr;
ROLDQ(krl, krr, 34);
kl = subRL[0] ^ krl;
kr = subRL[1] ^ krr;
CAMELLIA_F(kl, CAMELLIA_SIGMA1L, CAMELLIA_SIGMA1R, ww);
kr ^= ww;
CAMELLIA_F(kr, CAMELLIA_SIGMA2L, CAMELLIA_SIGMA2R, kl);
kl ^= krl;
CAMELLIA_F(kl, CAMELLIA_SIGMA3L, CAMELLIA_SIGMA3R, kr);
kr ^= ww ^ krr;
CAMELLIA_F(kr, CAMELLIA_SIGMA4L, CAMELLIA_SIGMA4R, ww);
kl ^= ww;
krl ^= kl;
krr ^= kr;
CAMELLIA_F(krl, CAMELLIA_SIGMA5L, CAMELLIA_SIGMA5R, ww);
krr ^= ww;
CAMELLIA_F(krr, CAMELLIA_SIGMA6L, CAMELLIA_SIGMA6R, ww);
krl ^= ww;
ROLDQ(kl, kr, 15);
subRL[6] = kl;
subRL[7] = kr;
ROLDQ(kl, kr, 30);
subRL[14] = kl;
subRL[15] = kr;
ROLDQ(kl, kr, 32);
subRL[24] = kl;
subRL[25] = kr;
ROLDQ(kl, kr, 17);
subRL[28] = kl;
subRL[29] = kr;
subRL[2] = krl;
subRL[3] = krr;
ROLDQ(krl, krr, 30);
subRL[10] = krl;
subRL[11] = krr;
ROLDQ(krl, krr, 30);
subRL[20] = krl;
subRL[21] = krr;
ROLDQ(krl, krr, 51);
subRL[32] = krl;
subRL[33] = krr;
camellia_setup_tail(subkey, subRL, 32);
}
static void camellia_setup192(const unsigned char *key, u64 *subkey)
{
unsigned char kk[32];
u64 krl, krr;
memcpy(kk, key, 24);
memcpy((unsigned char *)&krl, key+16, 8);
krr = ~krl;
memcpy(kk+24, (unsigned char *)&krr, 8);
camellia_setup256(kk, subkey);
}
static int __camellia_setkey(struct camellia_ctx *cctx,
const unsigned char *key,
unsigned int key_len, u32 *flags)
{
if (key_len != 16 && key_len != 24 && key_len != 32) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
cctx->key_length = key_len;
switch (key_len) {
case 16:
camellia_setup128(key, cctx->key_table);
break;
case 24:
camellia_setup192(key, cctx->key_table);
break;
case 32:
camellia_setup256(key, cctx->key_table);
break;
}
return 0;
}
static int camellia_setkey(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
return __camellia_setkey(crypto_tfm_ctx(tfm), in_key, key_len,
&tfm->crt_flags);
}
static int ecb_crypt(struct blkcipher_desc *desc, struct blkcipher_walk *walk,
void (*fn)(struct camellia_ctx *, u8 *, const u8 *),
void (*fn_2way)(struct camellia_ctx *, u8 *, const u8 *))
{
struct camellia_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = CAMELLIA_BLOCK_SIZE;
unsigned int nbytes;
int err;
err = blkcipher_walk_virt(desc, walk);
while ((nbytes = walk->nbytes)) {
u8 *wsrc = walk->src.virt.addr;
u8 *wdst = walk->dst.virt.addr;
if (nbytes >= bsize * 2) {
do {
fn_2way(ctx, wdst, wsrc);
wsrc += bsize * 2;
wdst += bsize * 2;
nbytes -= bsize * 2;
} while (nbytes >= bsize * 2);
if (nbytes < bsize)
goto done;
}
do {
fn(ctx, wdst, wsrc);
wsrc += bsize;
wdst += bsize;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
err = blkcipher_walk_done(desc, walk, nbytes);
}
return err;
}
static int ecb_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, camellia_enc_blk, camellia_enc_blk_2way);
}
static int ecb_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_crypt(desc, &walk, camellia_dec_blk, camellia_dec_blk_2way);
}
static unsigned int __cbc_encrypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct camellia_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = CAMELLIA_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 *iv = (u128 *)walk->iv;
do {
u128_xor(dst, src, iv);
camellia_enc_blk(ctx, (u8 *)dst, (u8 *)dst);
iv = dst;
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
u128_xor((u128 *)walk->iv, (u128 *)walk->iv, iv);
return nbytes;
}
static int cbc_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
nbytes = __cbc_encrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
return err;
}
static unsigned int __cbc_decrypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct camellia_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = CAMELLIA_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ivs[2 - 1];
u128 last_iv;
src += nbytes / bsize - 1;
dst += nbytes / bsize - 1;
last_iv = *src;
if (nbytes >= bsize * 2) {
do {
nbytes -= bsize * (2 - 1);
src -= 2 - 1;
dst -= 2 - 1;
ivs[0] = src[0];
camellia_dec_blk_2way(ctx, (u8 *)dst, (u8 *)src);
u128_xor(dst + 1, dst + 1, ivs + 0);
nbytes -= bsize;
if (nbytes < bsize)
goto done;
u128_xor(dst, dst, src - 1);
src -= 1;
dst -= 1;
} while (nbytes >= bsize * 2);
if (nbytes < bsize)
goto done;
}
for (;;) {
camellia_dec_blk(ctx, (u8 *)dst, (u8 *)src);
nbytes -= bsize;
if (nbytes < bsize)
break;
u128_xor(dst, dst, src - 1);
src -= 1;
dst -= 1;
}
done:
u128_xor(dst, dst, (u128 *)walk->iv);
*(u128 *)walk->iv = last_iv;
return nbytes;
}
static int cbc_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt(desc, &walk);
while ((nbytes = walk.nbytes)) {
nbytes = __cbc_decrypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
return err;
}
static inline void u128_to_be128(be128 *dst, const u128 *src)
{
dst->a = cpu_to_be64(src->a);
dst->b = cpu_to_be64(src->b);
}
static inline void be128_to_u128(u128 *dst, const be128 *src)
{
dst->a = be64_to_cpu(src->a);
dst->b = be64_to_cpu(src->b);
}
static inline void u128_inc(u128 *i)
{
i->b++;
if (!i->b)
i->a++;
}
static void ctr_crypt_final(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct camellia_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 keystream[CAMELLIA_BLOCK_SIZE];
u8 *src = walk->src.virt.addr;
u8 *dst = walk->dst.virt.addr;
unsigned int nbytes = walk->nbytes;
u128 ctrblk;
memcpy(keystream, src, nbytes);
camellia_enc_blk_xor(ctx, keystream, walk->iv);
memcpy(dst, keystream, nbytes);
be128_to_u128(&ctrblk, (be128 *)walk->iv);
u128_inc(&ctrblk);
u128_to_be128((be128 *)walk->iv, &ctrblk);
}
static unsigned int __ctr_crypt(struct blkcipher_desc *desc,
struct blkcipher_walk *walk)
{
struct camellia_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int bsize = CAMELLIA_BLOCK_SIZE;
unsigned int nbytes = walk->nbytes;
u128 *src = (u128 *)walk->src.virt.addr;
u128 *dst = (u128 *)walk->dst.virt.addr;
u128 ctrblk;
be128 ctrblocks[2];
be128_to_u128(&ctrblk, (be128 *)walk->iv);
if (nbytes >= bsize * 2) {
do {
if (dst != src) {
dst[0] = src[0];
dst[1] = src[1];
}
u128_to_be128(&ctrblocks[0], &ctrblk);
u128_inc(&ctrblk);
u128_to_be128(&ctrblocks[1], &ctrblk);
u128_inc(&ctrblk);
camellia_enc_blk_xor_2way(ctx, (u8 *)dst,
(u8 *)ctrblocks);
src += 2;
dst += 2;
nbytes -= bsize * 2;
} while (nbytes >= bsize * 2);
if (nbytes < bsize)
goto done;
}
do {
if (dst != src)
*dst = *src;
u128_to_be128(&ctrblocks[0], &ctrblk);
u128_inc(&ctrblk);
camellia_enc_blk_xor(ctx, (u8 *)dst, (u8 *)ctrblocks);
src += 1;
dst += 1;
nbytes -= bsize;
} while (nbytes >= bsize);
done:
u128_to_be128((be128 *)walk->iv, &ctrblk);
return nbytes;
}
static int ctr_crypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct blkcipher_walk walk;
int err;
blkcipher_walk_init(&walk, dst, src, nbytes);
err = blkcipher_walk_virt_block(desc, &walk, CAMELLIA_BLOCK_SIZE);
while ((nbytes = walk.nbytes) >= CAMELLIA_BLOCK_SIZE) {
nbytes = __ctr_crypt(desc, &walk);
err = blkcipher_walk_done(desc, &walk, nbytes);
}
if (walk.nbytes) {
ctr_crypt_final(desc, &walk);
err = blkcipher_walk_done(desc, &walk, 0);
}
return err;
}
static void encrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = CAMELLIA_BLOCK_SIZE;
struct camellia_ctx *ctx = priv;
int i;
while (nbytes >= 2 * bsize) {
camellia_enc_blk_2way(ctx, srcdst, srcdst);
srcdst += bsize * 2;
nbytes -= bsize * 2;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
camellia_enc_blk(ctx, srcdst, srcdst);
}
static void decrypt_callback(void *priv, u8 *srcdst, unsigned int nbytes)
{
const unsigned int bsize = CAMELLIA_BLOCK_SIZE;
struct camellia_ctx *ctx = priv;
int i;
while (nbytes >= 2 * bsize) {
camellia_dec_blk_2way(ctx, srcdst, srcdst);
srcdst += bsize * 2;
nbytes -= bsize * 2;
}
for (i = 0; i < nbytes / bsize; i++, srcdst += bsize)
camellia_dec_blk(ctx, srcdst, srcdst);
}
static int lrw_camellia_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct camellia_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
int err;
err = __camellia_setkey(&ctx->camellia_ctx, key,
keylen - CAMELLIA_BLOCK_SIZE,
&tfm->crt_flags);
if (err)
return err;
return lrw_init_table(&ctx->lrw_table,
key + keylen - CAMELLIA_BLOCK_SIZE);
}
static int lrw_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[2 * 4];
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = &ctx->camellia_ctx,
.crypt_fn = encrypt_callback,
};
return lrw_crypt(desc, dst, src, nbytes, &req);
}
static int lrw_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_lrw_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[2 * 4];
struct lrw_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.table_ctx = &ctx->lrw_table,
.crypt_ctx = &ctx->camellia_ctx,
.crypt_fn = decrypt_callback,
};
return lrw_crypt(desc, dst, src, nbytes, &req);
}
static void lrw_exit_tfm(struct crypto_tfm *tfm)
{
struct camellia_lrw_ctx *ctx = crypto_tfm_ctx(tfm);
lrw_free_table(&ctx->lrw_table);
}
static int xts_camellia_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
struct camellia_xts_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
int err;
if (keylen % 2) {
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
err = __camellia_setkey(&ctx->crypt_ctx, key, keylen / 2, flags);
if (err)
return err;
return __camellia_setkey(&ctx->tweak_ctx, key + keylen / 2, keylen / 2,
flags);
}
static int xts_encrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[2 * 4];
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(camellia_enc_blk),
.crypt_ctx = &ctx->crypt_ctx,
.crypt_fn = encrypt_callback,
};
return xts_crypt(desc, dst, src, nbytes, &req);
}
static int xts_decrypt(struct blkcipher_desc *desc, struct scatterlist *dst,
struct scatterlist *src, unsigned int nbytes)
{
struct camellia_xts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
be128 buf[2 * 4];
struct xts_crypt_req req = {
.tbuf = buf,
.tbuflen = sizeof(buf),
.tweak_ctx = &ctx->tweak_ctx,
.tweak_fn = XTS_TWEAK_CAST(camellia_enc_blk),
.crypt_ctx = &ctx->crypt_ctx,
.crypt_fn = decrypt_callback,
};
return xts_crypt(desc, dst, src, nbytes, &req);
}
static bool is_blacklisted_cpu(void)
{
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return false;
if (boot_cpu_data.x86 == 0x0f) {
return true;
}
return false;
}
static int __init init(void)
{
if (!force && is_blacklisted_cpu()) {
printk(KERN_INFO
"camellia-x86_64: performance on this CPU "
"would be suboptimal: disabling "
"camellia-x86_64.\n");
return -ENODEV;
}
return crypto_register_algs(camellia_algs, ARRAY_SIZE(camellia_algs));
}
static void __exit fini(void)
{
crypto_unregister_algs(camellia_algs, ARRAY_SIZE(camellia_algs));
}
