static int skcipher_aes_setkey(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
return aes_setkey(crypto_skcipher_tfm(tfm), in_key, key_len);
}
static int xts_set_key(struct crypto_skcipher *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int ret;
ret = xts_verify_key(tfm, in_key, key_len);
if (ret)
return ret;
ret = aes_expandkey(&ctx->key1, in_key, key_len / 2);
if (!ret)
ret = aes_expandkey(&ctx->key2, &in_key[key_len / 2],
key_len / 2);
if (!ret)
return 0;
crypto_skcipher_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
static int ecb_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_ecb_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, rounds, blocks, first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ecb_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_ecb_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, rounds, blocks, first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_cbc_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, rounds, blocks, walk.iv,
first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbc_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_cbc_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_dec, rounds, blocks, walk.iv,
first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int ctr_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key_length / 4;
struct skcipher_walk walk;
int blocks;
err = skcipher_walk_virt(&walk, req, true);
first = 1;
kernel_neon_begin();
while ((blocks = (walk.nbytes / AES_BLOCK_SIZE))) {
aes_ctr_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key_enc, rounds, blocks, walk.iv,
first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
first = 0;
}
if (walk.nbytes) {
u8 __aligned(8) tail[AES_BLOCK_SIZE];
unsigned int nbytes = walk.nbytes;
u8 *tdst = walk.dst.virt.addr;
u8 *tsrc = walk.src.virt.addr;
blocks = -1;
aes_ctr_encrypt(tail, NULL, (u8 *)ctx->key_enc, rounds,
blocks, walk.iv, first);
if (tdst != tsrc)
memcpy(tdst, tsrc, nbytes);
crypto_xor(tdst, tail, nbytes);
err = skcipher_walk_done(&walk, 0);
}
kernel_neon_end();
return err;
}
static int xts_encrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key1.key_length / 4;
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_xts_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_enc, rounds, blocks,
(u8 *)ctx->key2.key_enc, walk.iv, first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int xts_decrypt(struct skcipher_request *req)
{
struct crypto_skcipher *tfm = crypto_skcipher_reqtfm(req);
struct crypto_aes_xts_ctx *ctx = crypto_skcipher_ctx(tfm);
int err, first, rounds = 6 + ctx->key1.key_length / 4;
struct skcipher_walk walk;
unsigned int blocks;
err = skcipher_walk_virt(&walk, req, true);
kernel_neon_begin();
for (first = 1; (blocks = (walk.nbytes / AES_BLOCK_SIZE)); first = 0) {
aes_xts_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
(u8 *)ctx->key1.key_dec, rounds, blocks,
(u8 *)ctx->key2.key_enc, walk.iv, first);
err = skcipher_walk_done(&walk, walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
return err;
}
static int cbcmac_setkey(struct crypto_shash *tfm, const u8 *in_key,
unsigned int key_len)
{
struct mac_tfm_ctx *ctx = crypto_shash_ctx(tfm);
int err;
err = aes_expandkey(&ctx->key, in_key, key_len);
if (err)
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return err;
}
static void cmac_gf128_mul_by_x(be128 *y, const be128 *x)
{
u64 a = be64_to_cpu(x->a);
u64 b = be64_to_cpu(x->b);
y->a = cpu_to_be64((a << 1) | (b >> 63));
y->b = cpu_to_be64((b << 1) ^ ((a >> 63) ? 0x87 : 0));
}
static int cmac_setkey(struct crypto_shash *tfm, const u8 *in_key,
unsigned int key_len)
{
struct mac_tfm_ctx *ctx = crypto_shash_ctx(tfm);
be128 *consts = (be128 *)ctx->consts;
u8 *rk = (u8 *)ctx->key.key_enc;
int rounds = 6 + key_len / 4;
int err;
err = cbcmac_setkey(tfm, in_key, key_len);
if (err)
return err;
kernel_neon_begin();
aes_ecb_encrypt(ctx->consts, (u8[AES_BLOCK_SIZE]){}, rk, rounds, 1, 1);
kernel_neon_end();
cmac_gf128_mul_by_x(consts, consts);
cmac_gf128_mul_by_x(consts + 1, consts);
return 0;
}
static int xcbc_setkey(struct crypto_shash *tfm, const u8 *in_key,
unsigned int key_len)
{
static u8 const ks[3][AES_BLOCK_SIZE] = {
{ [0 ... AES_BLOCK_SIZE - 1] = 0x1 },
{ [0 ... AES_BLOCK_SIZE - 1] = 0x2 },
{ [0 ... AES_BLOCK_SIZE - 1] = 0x3 },
};
struct mac_tfm_ctx *ctx = crypto_shash_ctx(tfm);
u8 *rk = (u8 *)ctx->key.key_enc;
int rounds = 6 + key_len / 4;
u8 key[AES_BLOCK_SIZE];
int err;
err = cbcmac_setkey(tfm, in_key, key_len);
if (err)
return err;
kernel_neon_begin();
aes_ecb_encrypt(key, ks[0], rk, rounds, 1, 1);
aes_ecb_encrypt(ctx->consts, ks[1], rk, rounds, 2, 0);
kernel_neon_end();
return cbcmac_setkey(tfm, key, sizeof(key));
}
static int mac_init(struct shash_desc *desc)
{
struct mac_desc_ctx *ctx = shash_desc_ctx(desc);
memset(ctx->dg, 0, AES_BLOCK_SIZE);
ctx->len = 0;
return 0;
}
static int mac_update(struct shash_desc *desc, const u8 *p, unsigned int len)
{
struct mac_tfm_ctx *tctx = crypto_shash_ctx(desc->tfm);
struct mac_desc_ctx *ctx = shash_desc_ctx(desc);
int rounds = 6 + tctx->key.key_length / 4;
while (len > 0) {
unsigned int l;
if ((ctx->len % AES_BLOCK_SIZE) == 0 &&
(ctx->len + len) > AES_BLOCK_SIZE) {
int blocks = len / AES_BLOCK_SIZE;
len %= AES_BLOCK_SIZE;
kernel_neon_begin();
aes_mac_update(p, tctx->key.key_enc, rounds, blocks,
ctx->dg, (ctx->len != 0), (len != 0));
kernel_neon_end();
p += blocks * AES_BLOCK_SIZE;
if (!len) {
ctx->len = AES_BLOCK_SIZE;
break;
}
ctx->len = 0;
}
l = min(len, AES_BLOCK_SIZE - ctx->len);
if (l <= AES_BLOCK_SIZE) {
crypto_xor(ctx->dg + ctx->len, p, l);
ctx->len += l;
len -= l;
p += l;
}
}
return 0;
}
static int cbcmac_final(struct shash_desc *desc, u8 *out)
{
struct mac_tfm_ctx *tctx = crypto_shash_ctx(desc->tfm);
struct mac_desc_ctx *ctx = shash_desc_ctx(desc);
int rounds = 6 + tctx->key.key_length / 4;
kernel_neon_begin();
aes_mac_update(NULL, tctx->key.key_enc, rounds, 0, ctx->dg, 1, 0);
kernel_neon_end();
memcpy(out, ctx->dg, AES_BLOCK_SIZE);
return 0;
}
static int cmac_final(struct shash_desc *desc, u8 *out)
{
struct mac_tfm_ctx *tctx = crypto_shash_ctx(desc->tfm);
struct mac_desc_ctx *ctx = shash_desc_ctx(desc);
int rounds = 6 + tctx->key.key_length / 4;
u8 *consts = tctx->consts;
if (ctx->len != AES_BLOCK_SIZE) {
ctx->dg[ctx->len] ^= 0x80;
consts += AES_BLOCK_SIZE;
}
kernel_neon_begin();
aes_mac_update(consts, tctx->key.key_enc, rounds, 1, ctx->dg, 0, 1);
kernel_neon_end();
memcpy(out, ctx->dg, AES_BLOCK_SIZE);
return 0;
}
static void aes_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(aes_simd_algs); i++)
if (aes_simd_algs[i])
simd_skcipher_free(aes_simd_algs[i]);
crypto_unregister_shashes(mac_algs, ARRAY_SIZE(mac_algs));
crypto_unregister_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
}
static int __init aes_init(void)
{
struct simd_skcipher_alg *simd;
const char *basename;
const char *algname;
const char *drvname;
int err;
int i;
err = crypto_register_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
if (err)
return err;
err = crypto_register_shashes(mac_algs, ARRAY_SIZE(mac_algs));
if (err)
goto unregister_ciphers;
for (i = 0; i < ARRAY_SIZE(aes_algs); i++) {
if (!(aes_algs[i].base.cra_flags & CRYPTO_ALG_INTERNAL))
continue;
algname = aes_algs[i].base.cra_name + 2;
drvname = aes_algs[i].base.cra_driver_name + 2;
basename = aes_algs[i].base.cra_driver_name;
simd = simd_skcipher_create_compat(algname, drvname, basename);
err = PTR_ERR(simd);
if (IS_ERR(simd))
goto unregister_simds;
aes_simd_algs[i] = simd;
}
return 0;
unregister_simds:
aes_exit();
unregister_ciphers:
crypto_unregister_skciphers(aes_algs, ARRAY_SIZE(aes_algs));
return err;
}
