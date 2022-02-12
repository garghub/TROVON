static int num_rounds(struct crypto_aes_ctx *ctx)
{
return 6 + ctx->key_length / 4;
}
static int ccm_setkey(struct crypto_aead *tfm, const u8 *in_key,
unsigned int key_len)
{
struct crypto_aes_ctx *ctx = crypto_aead_ctx(tfm);
int ret;
ret = ce_aes_expandkey(ctx, in_key, key_len);
if (!ret)
return 0;
tfm->base.crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
static int ccm_setauthsize(struct crypto_aead *tfm, unsigned int authsize)
{
if ((authsize & 1) || authsize < 4)
return -EINVAL;
return 0;
}
static int ccm_init_mac(struct aead_request *req, u8 maciv[], u32 msglen)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
__be32 *n = (__be32 *)&maciv[AES_BLOCK_SIZE - 8];
u32 l = req->iv[0] + 1;
if (l < 2 || l > 8)
return -EINVAL;
if (l < 4 && msglen >> (8 * l))
return -EOVERFLOW;
n[0] = 0;
n[1] = cpu_to_be32(msglen);
memcpy(maciv, req->iv, AES_BLOCK_SIZE - l);
maciv[0] |= (crypto_aead_authsize(aead) - 2) << 2;
if (req->assoclen)
maciv[0] |= 0x40;
memset(&req->iv[AES_BLOCK_SIZE - l], 0, l);
return 0;
}
static void ccm_calculate_auth_mac(struct aead_request *req, u8 mac[])
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_aead_ctx(aead);
struct __packed { __be16 l; __be32 h; u16 len; } ltag;
struct scatter_walk walk;
u32 len = req->assoclen;
u32 macp = 0;
if (len < 0xff00) {
ltag.l = cpu_to_be16(len);
ltag.len = 2;
} else {
ltag.l = cpu_to_be16(0xfffe);
put_unaligned_be32(len, &ltag.h);
ltag.len = 6;
}
ce_aes_ccm_auth_data(mac, (u8 *)&ltag, ltag.len, &macp, ctx->key_enc,
num_rounds(ctx));
scatterwalk_start(&walk, req->src);
do {
u32 n = scatterwalk_clamp(&walk, len);
u8 *p;
if (!n) {
scatterwalk_start(&walk, sg_next(walk.sg));
n = scatterwalk_clamp(&walk, len);
}
p = scatterwalk_map(&walk);
ce_aes_ccm_auth_data(mac, p, n, &macp, ctx->key_enc,
num_rounds(ctx));
len -= n;
scatterwalk_unmap(p);
scatterwalk_advance(&walk, n);
scatterwalk_done(&walk, 0, len);
} while (len);
}
static int ccm_encrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_aead_ctx(aead);
struct skcipher_walk walk;
u8 __aligned(8) mac[AES_BLOCK_SIZE];
u8 buf[AES_BLOCK_SIZE];
u32 len = req->cryptlen;
int err;
err = ccm_init_mac(req, mac, len);
if (err)
return err;
kernel_neon_begin_partial(6);
if (req->assoclen)
ccm_calculate_auth_mac(req, mac);
memcpy(buf, req->iv, AES_BLOCK_SIZE);
err = skcipher_walk_aead_encrypt(&walk, req, true);
while (walk.nbytes) {
u32 tail = walk.nbytes % AES_BLOCK_SIZE;
if (walk.nbytes == walk.total)
tail = 0;
ce_aes_ccm_encrypt(walk.dst.virt.addr, walk.src.virt.addr,
walk.nbytes - tail, ctx->key_enc,
num_rounds(ctx), mac, walk.iv);
err = skcipher_walk_done(&walk, tail);
}
if (!err)
ce_aes_ccm_final(mac, buf, ctx->key_enc, num_rounds(ctx));
kernel_neon_end();
if (err)
return err;
scatterwalk_map_and_copy(mac, req->dst, req->assoclen + req->cryptlen,
crypto_aead_authsize(aead), 1);
return 0;
}
static int ccm_decrypt(struct aead_request *req)
{
struct crypto_aead *aead = crypto_aead_reqtfm(req);
struct crypto_aes_ctx *ctx = crypto_aead_ctx(aead);
unsigned int authsize = crypto_aead_authsize(aead);
struct skcipher_walk walk;
u8 __aligned(8) mac[AES_BLOCK_SIZE];
u8 buf[AES_BLOCK_SIZE];
u32 len = req->cryptlen - authsize;
int err;
err = ccm_init_mac(req, mac, len);
if (err)
return err;
kernel_neon_begin_partial(6);
if (req->assoclen)
ccm_calculate_auth_mac(req, mac);
memcpy(buf, req->iv, AES_BLOCK_SIZE);
err = skcipher_walk_aead_decrypt(&walk, req, true);
while (walk.nbytes) {
u32 tail = walk.nbytes % AES_BLOCK_SIZE;
if (walk.nbytes == walk.total)
tail = 0;
ce_aes_ccm_decrypt(walk.dst.virt.addr, walk.src.virt.addr,
walk.nbytes - tail, ctx->key_enc,
num_rounds(ctx), mac, walk.iv);
err = skcipher_walk_done(&walk, tail);
}
if (!err)
ce_aes_ccm_final(mac, buf, ctx->key_enc, num_rounds(ctx));
kernel_neon_end();
if (err)
return err;
scatterwalk_map_and_copy(buf, req->src,
req->assoclen + req->cryptlen - authsize,
authsize, 0);
if (crypto_memneq(mac, buf, authsize))
return -EBADMSG;
return 0;
}
static int __init aes_mod_init(void)
{
if (!(elf_hwcap & HWCAP_AES))
return -ENODEV;
return crypto_register_aead(&ccm_aes_alg);
}
static void __exit aes_mod_exit(void)
{
crypto_unregister_aead(&ccm_aes_alg);
}
