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
blocks = (nbytes <= 8) ? -1 : 1;
aes_ctr_encrypt(tail, tsrc, (u8 *)ctx->key_enc, rounds,
blocks, walk.iv, first);
memcpy(tdst, tail, nbytes);
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
static void aes_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(aes_simd_algs) && aes_simd_algs[i]; i++)
simd_skcipher_free(aes_simd_algs[i]);
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
for (i = 0; i < ARRAY_SIZE(aes_algs); i++) {
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
return err;
}
