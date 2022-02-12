static int ghash_init(struct shash_desc *desc)
{
struct ghash_desc_ctx *ctx = shash_desc_ctx(desc);
*ctx = (struct ghash_desc_ctx){};
return 0;
}
static void ghash_do_update(int blocks, u64 dg[], const char *src,
struct ghash_key *key, const char *head)
{
if (likely(may_use_simd())) {
kernel_neon_begin();
pmull_ghash_update(blocks, dg, src, key, head);
kernel_neon_end();
} else {
be128 dst = { cpu_to_be64(dg[1]), cpu_to_be64(dg[0]) };
do {
const u8 *in = src;
if (head) {
in = head;
blocks++;
head = NULL;
} else {
src += GHASH_BLOCK_SIZE;
}
crypto_xor((u8 *)&dst, in, GHASH_BLOCK_SIZE);
gf128mul_lle(&dst, &key->k);
} while (--blocks);
dg[0] = be64_to_cpu(dst.b);
dg[1] = be64_to_cpu(dst.a);
}
}
static int ghash_update(struct shash_desc *desc, const u8 *src,
unsigned int len)
{
struct ghash_desc_ctx *ctx = shash_desc_ctx(desc);
unsigned int partial = ctx->count % GHASH_BLOCK_SIZE;
ctx->count += len;
if ((partial + len) >= GHASH_BLOCK_SIZE) {
struct ghash_key *key = crypto_shash_ctx(desc->tfm);
int blocks;
if (partial) {
int p = GHASH_BLOCK_SIZE - partial;
memcpy(ctx->buf + partial, src, p);
src += p;
len -= p;
}
blocks = len / GHASH_BLOCK_SIZE;
len %= GHASH_BLOCK_SIZE;
ghash_do_update(blocks, ctx->digest, src, key,
partial ? ctx->buf : NULL);
src += blocks * GHASH_BLOCK_SIZE;
partial = 0;
}
if (len)
memcpy(ctx->buf + partial, src, len);
return 0;
}
static int ghash_final(struct shash_desc *desc, u8 *dst)
{
struct ghash_desc_ctx *ctx = shash_desc_ctx(desc);
unsigned int partial = ctx->count % GHASH_BLOCK_SIZE;
if (partial) {
struct ghash_key *key = crypto_shash_ctx(desc->tfm);
memset(ctx->buf + partial, 0, GHASH_BLOCK_SIZE - partial);
ghash_do_update(1, ctx->digest, ctx->buf, key, NULL);
}
put_unaligned_be64(ctx->digest[1], dst);
put_unaligned_be64(ctx->digest[0], dst + 8);
*ctx = (struct ghash_desc_ctx){};
return 0;
}
static int __ghash_setkey(struct ghash_key *key,
const u8 *inkey, unsigned int keylen)
{
u64 a, b;
memcpy(&key->k, inkey, GHASH_BLOCK_SIZE);
b = get_unaligned_be64(inkey);
a = get_unaligned_be64(inkey + 8);
key->a = (a << 1) | (b >> 63);
key->b = (b << 1) | (a >> 63);
if (b >> 63)
key->b ^= 0xc200000000000000UL;
return 0;
}
static int ghash_setkey(struct crypto_shash *tfm,
const u8 *inkey, unsigned int keylen)
{
struct ghash_key *key = crypto_shash_ctx(tfm);
if (keylen != GHASH_BLOCK_SIZE) {
crypto_shash_set_flags(tfm, CRYPTO_TFM_RES_BAD_KEY_LEN);
return -EINVAL;
}
return __ghash_setkey(key, inkey, keylen);
}
static int num_rounds(struct crypto_aes_ctx *ctx)
{
return 6 + ctx->key_length / 4;
}
static int gcm_setkey(struct crypto_aead *tfm, const u8 *inkey,
unsigned int keylen)
{
struct gcm_aes_ctx *ctx = crypto_aead_ctx(tfm);
u8 key[GHASH_BLOCK_SIZE];
int ret;
ret = crypto_aes_expand_key(&ctx->aes_key, inkey, keylen);
if (ret) {
tfm->base.crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
__aes_arm64_encrypt(ctx->aes_key.key_enc, key, (u8[AES_BLOCK_SIZE]){},
num_rounds(&ctx->aes_key));
return __ghash_setkey(&ctx->ghash_key, key, sizeof(key));
}
static int gcm_setauthsize(struct crypto_aead *tfm, unsigned int authsize)
{
switch (authsize) {
case 4:
case 8:
case 12 ... 16:
break;
default:
return -EINVAL;
}
return 0;
}
static void gcm_update_mac(u64 dg[], const u8 *src, int count, u8 buf[],
int *buf_count, struct gcm_aes_ctx *ctx)
{
if (*buf_count > 0) {
int buf_added = min(count, GHASH_BLOCK_SIZE - *buf_count);
memcpy(&buf[*buf_count], src, buf_added);
*buf_count += buf_added;
src += buf_added;
count -= buf_added;
}
if (count >= GHASH_BLOCK_SIZE || *buf_count == GHASH_BLOCK_SIZE) {
int blocks = count / GHASH_BLOCK_SIZE;
ghash_do_update(blocks, dg, src, &ctx->ghash_key,
*buf_count ? buf : NULL);
src += blocks * GHASH_BLOCK_SIZE;
count %= GHASH_BLOCK_SIZE;
*buf_count = 0;
}
if (count > 0) {
memcpy(buf, src, count);
*buf_count = count;
}
}
static void gcm_calculate_auth_mac(struct aead_request *req, u64 dg[])
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct gcm_aes_ctx *ctx = crypto_aead_ctx(aead);
u8 buf[GHASH_BLOCK_SIZE];
struct scatter_walk walk;
u32 len = req->assoclen;
int buf_count = 0;
scatterwalk_start(&walk, req->src);
do {
u32 n = scatterwalk_clamp(&walk, len);
u8 *p;
if (!n) {
scatterwalk_start(&walk, sg_next(walk.sg));
n = scatterwalk_clamp(&walk, len);
}
p = scatterwalk_map(&walk);
gcm_update_mac(dg, p, n, buf, &buf_count, ctx);
len -= n;
scatterwalk_unmap(p);
scatterwalk_advance(&walk, n);
scatterwalk_done(&walk, 0, len);
} while (len);
if (buf_count) {
memset(&buf[buf_count], 0, GHASH_BLOCK_SIZE - buf_count);
ghash_do_update(1, dg, buf, &ctx->ghash_key, NULL);
}
}
static void gcm_final(struct aead_request *req, struct gcm_aes_ctx *ctx,
u64 dg[], u8 tag[], int cryptlen)
{
u8 mac[AES_BLOCK_SIZE];
u128 lengths;
lengths.a = cpu_to_be64(req->assoclen * 8);
lengths.b = cpu_to_be64(cryptlen * 8);
ghash_do_update(1, dg, (void *)&lengths, &ctx->ghash_key, NULL);
put_unaligned_be64(dg[1], mac);
put_unaligned_be64(dg[0], mac + 8);
crypto_xor(tag, mac, AES_BLOCK_SIZE);
}
static int gcm_encrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct gcm_aes_ctx *ctx = crypto_aead_ctx(aead);
struct skcipher_walk walk;
u8 iv[AES_BLOCK_SIZE];
u8 ks[AES_BLOCK_SIZE];
u8 tag[AES_BLOCK_SIZE];
u64 dg[2] = {};
int err;
if (req->assoclen)
gcm_calculate_auth_mac(req, dg);
memcpy(iv, req->iv, GCM_IV_SIZE);
put_unaligned_be32(1, iv + GCM_IV_SIZE);
if (likely(may_use_simd())) {
kernel_neon_begin();
pmull_gcm_encrypt_block(tag, iv, ctx->aes_key.key_enc,
num_rounds(&ctx->aes_key));
put_unaligned_be32(2, iv + GCM_IV_SIZE);
pmull_gcm_encrypt_block(ks, iv, NULL,
num_rounds(&ctx->aes_key));
put_unaligned_be32(3, iv + GCM_IV_SIZE);
err = skcipher_walk_aead_encrypt(&walk, req, true);
while (walk.nbytes >= AES_BLOCK_SIZE) {
int blocks = walk.nbytes / AES_BLOCK_SIZE;
pmull_gcm_encrypt(blocks, dg, walk.dst.virt.addr,
walk.src.virt.addr, &ctx->ghash_key,
iv, num_rounds(&ctx->aes_key), ks);
err = skcipher_walk_done(&walk,
walk.nbytes % AES_BLOCK_SIZE);
}
kernel_neon_end();
} else {
__aes_arm64_encrypt(ctx->aes_key.key_enc, tag, iv,
num_rounds(&ctx->aes_key));
put_unaligned_be32(2, iv + GCM_IV_SIZE);
err = skcipher_walk_aead_encrypt(&walk, req, true);
while (walk.nbytes >= AES_BLOCK_SIZE) {
int blocks = walk.nbytes / AES_BLOCK_SIZE;
u8 *dst = walk.dst.virt.addr;
u8 *src = walk.src.virt.addr;
do {
__aes_arm64_encrypt(ctx->aes_key.key_enc,
ks, iv,
num_rounds(&ctx->aes_key));
crypto_xor_cpy(dst, src, ks, AES_BLOCK_SIZE);
crypto_inc(iv, AES_BLOCK_SIZE);
dst += AES_BLOCK_SIZE;
src += AES_BLOCK_SIZE;
} while (--blocks > 0);
ghash_do_update(walk.nbytes / AES_BLOCK_SIZE, dg,
walk.dst.virt.addr, &ctx->ghash_key,
NULL);
err = skcipher_walk_done(&walk,
walk.nbytes % AES_BLOCK_SIZE);
}
if (walk.nbytes)
__aes_arm64_encrypt(ctx->aes_key.key_enc, ks, iv,
num_rounds(&ctx->aes_key));
}
if (walk.nbytes) {
u8 buf[GHASH_BLOCK_SIZE];
crypto_xor_cpy(walk.dst.virt.addr, walk.src.virt.addr, ks,
walk.nbytes);
memcpy(buf, walk.dst.virt.addr, walk.nbytes);
memset(buf + walk.nbytes, 0, GHASH_BLOCK_SIZE - walk.nbytes);
ghash_do_update(1, dg, buf, &ctx->ghash_key, NULL);
err = skcipher_walk_done(&walk, 0);
}
if (err)
return err;
gcm_final(req, ctx, dg, tag, req->cryptlen);
scatterwalk_map_and_copy(tag, req->dst, req->assoclen + req->cryptlen,
crypto_aead_authsize(aead), 1);
return 0;
}
static int gcm_decrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct gcm_aes_ctx *ctx = crypto_aead_ctx(aead);
unsigned int authsize = crypto_aead_authsize(aead);
struct skcipher_walk walk;
u8 iv[AES_BLOCK_SIZE];
u8 tag[AES_BLOCK_SIZE];
u8 buf[GHASH_BLOCK_SIZE];
u64 dg[2] = {};
int err;
if (req->assoclen)
gcm_calculate_auth_mac(req, dg);
memcpy(iv, req->iv, GCM_IV_SIZE);
put_unaligned_be32(1, iv + GCM_IV_SIZE);
if (likely(may_use_simd())) {
kernel_neon_begin();
pmull_gcm_encrypt_block(tag, iv, ctx->aes_key.key_enc,
num_rounds(&ctx->aes_key));
put_unaligned_be32(2, iv + GCM_IV_SIZE);
err = skcipher_walk_aead_decrypt(&walk, req, true);
while (walk.nbytes >= AES_BLOCK_SIZE) {
int blocks = walk.nbytes / AES_BLOCK_SIZE;
pmull_gcm_decrypt(blocks, dg, walk.dst.virt.addr,
walk.src.virt.addr, &ctx->ghash_key,
iv, num_rounds(&ctx->aes_key));
err = skcipher_walk_done(&walk,
walk.nbytes % AES_BLOCK_SIZE);
}
if (walk.nbytes)
pmull_gcm_encrypt_block(iv, iv, NULL,
num_rounds(&ctx->aes_key));
kernel_neon_end();
} else {
__aes_arm64_encrypt(ctx->aes_key.key_enc, tag, iv,
num_rounds(&ctx->aes_key));
put_unaligned_be32(2, iv + GCM_IV_SIZE);
err = skcipher_walk_aead_decrypt(&walk, req, true);
while (walk.nbytes >= AES_BLOCK_SIZE) {
int blocks = walk.nbytes / AES_BLOCK_SIZE;
u8 *dst = walk.dst.virt.addr;
u8 *src = walk.src.virt.addr;
ghash_do_update(blocks, dg, walk.src.virt.addr,
&ctx->ghash_key, NULL);
do {
__aes_arm64_encrypt(ctx->aes_key.key_enc,
buf, iv,
num_rounds(&ctx->aes_key));
crypto_xor_cpy(dst, src, buf, AES_BLOCK_SIZE);
crypto_inc(iv, AES_BLOCK_SIZE);
dst += AES_BLOCK_SIZE;
src += AES_BLOCK_SIZE;
} while (--blocks > 0);
err = skcipher_walk_done(&walk,
walk.nbytes % AES_BLOCK_SIZE);
}
if (walk.nbytes)
__aes_arm64_encrypt(ctx->aes_key.key_enc, iv, iv,
num_rounds(&ctx->aes_key));
}
if (walk.nbytes) {
memcpy(buf, walk.src.virt.addr, walk.nbytes);
memset(buf + walk.nbytes, 0, GHASH_BLOCK_SIZE - walk.nbytes);
ghash_do_update(1, dg, buf, &ctx->ghash_key, NULL);
crypto_xor_cpy(walk.dst.virt.addr, walk.src.virt.addr, iv,
walk.nbytes);
err = skcipher_walk_done(&walk, 0);
}
if (err)
return err;
gcm_final(req, ctx, dg, tag, req->cryptlen - authsize);
scatterwalk_map_and_copy(buf, req->src,
req->assoclen + req->cryptlen - authsize,
authsize, 0);
if (crypto_memneq(tag, buf, authsize))
return -EBADMSG;
return 0;
}
static int __init ghash_ce_mod_init(void)
{
int ret;
if (!(elf_hwcap & HWCAP_ASIMD))
return -ENODEV;
if (elf_hwcap & HWCAP_PMULL)
pmull_ghash_update = pmull_ghash_update_p64;
else
pmull_ghash_update = pmull_ghash_update_p8;
ret = crypto_register_shash(&ghash_alg);
if (ret)
return ret;
if (elf_hwcap & HWCAP_PMULL) {
ret = crypto_register_aead(&gcm_aes_alg);
if (ret)
crypto_unregister_shash(&ghash_alg);
}
return ret;
}
static void __exit ghash_ce_mod_exit(void)
{
crypto_unregister_shash(&ghash_alg);
crypto_unregister_aead(&gcm_aes_alg);
}
