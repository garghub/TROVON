static struct crypto_skcipher *any_tfm(struct crypt_config *cc)
{
return cc->cipher_tfm.tfms[0];
}
static struct crypto_aead *any_tfm_aead(struct crypt_config *cc)
{
return cc->cipher_tfm.tfms_aead[0];
}
static int crypt_iv_plain_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
memset(iv, 0, cc->iv_size);
*(__le32 *)iv = cpu_to_le32(dmreq->iv_sector & 0xffffffff);
return 0;
}
static int crypt_iv_plain64_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
memset(iv, 0, cc->iv_size);
*(__le64 *)iv = cpu_to_le64(dmreq->iv_sector);
return 0;
}
static int crypt_iv_plain64be_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
memset(iv, 0, cc->iv_size);
*(__be64 *)&iv[cc->iv_size - sizeof(u64)] = cpu_to_be64(dmreq->iv_sector);
return 0;
}
static int crypt_iv_essiv_init(struct crypt_config *cc)
{
struct iv_essiv_private *essiv = &cc->iv_gen_private.essiv;
AHASH_REQUEST_ON_STACK(req, essiv->hash_tfm);
struct scatterlist sg;
struct crypto_cipher *essiv_tfm;
int err;
sg_init_one(&sg, cc->key, cc->key_size);
ahash_request_set_tfm(req, essiv->hash_tfm);
ahash_request_set_callback(req, CRYPTO_TFM_REQ_MAY_SLEEP, NULL, NULL);
ahash_request_set_crypt(req, &sg, essiv->salt, cc->key_size);
err = crypto_ahash_digest(req);
ahash_request_zero(req);
if (err)
return err;
essiv_tfm = cc->iv_private;
err = crypto_cipher_setkey(essiv_tfm, essiv->salt,
crypto_ahash_digestsize(essiv->hash_tfm));
if (err)
return err;
return 0;
}
static int crypt_iv_essiv_wipe(struct crypt_config *cc)
{
struct iv_essiv_private *essiv = &cc->iv_gen_private.essiv;
unsigned salt_size = crypto_ahash_digestsize(essiv->hash_tfm);
struct crypto_cipher *essiv_tfm;
int r, err = 0;
memset(essiv->salt, 0, salt_size);
essiv_tfm = cc->iv_private;
r = crypto_cipher_setkey(essiv_tfm, essiv->salt, salt_size);
if (r)
err = r;
return err;
}
static struct crypto_cipher *alloc_essiv_cipher(struct crypt_config *cc,
struct dm_target *ti,
const u8 *salt,
unsigned int saltsize)
{
struct crypto_cipher *essiv_tfm;
int err;
essiv_tfm = crypto_alloc_cipher(cc->cipher, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(essiv_tfm)) {
ti->error = "Error allocating crypto tfm for ESSIV";
return essiv_tfm;
}
if (crypto_cipher_blocksize(essiv_tfm) != cc->iv_size) {
ti->error = "Block size of ESSIV cipher does "
"not match IV size of block cipher";
crypto_free_cipher(essiv_tfm);
return ERR_PTR(-EINVAL);
}
err = crypto_cipher_setkey(essiv_tfm, salt, saltsize);
if (err) {
ti->error = "Failed to set key for ESSIV cipher";
crypto_free_cipher(essiv_tfm);
return ERR_PTR(err);
}
return essiv_tfm;
}
static void crypt_iv_essiv_dtr(struct crypt_config *cc)
{
struct crypto_cipher *essiv_tfm;
struct iv_essiv_private *essiv = &cc->iv_gen_private.essiv;
crypto_free_ahash(essiv->hash_tfm);
essiv->hash_tfm = NULL;
kzfree(essiv->salt);
essiv->salt = NULL;
essiv_tfm = cc->iv_private;
if (essiv_tfm)
crypto_free_cipher(essiv_tfm);
cc->iv_private = NULL;
}
static int crypt_iv_essiv_ctr(struct crypt_config *cc, struct dm_target *ti,
const char *opts)
{
struct crypto_cipher *essiv_tfm = NULL;
struct crypto_ahash *hash_tfm = NULL;
u8 *salt = NULL;
int err;
if (!opts) {
ti->error = "Digest algorithm missing for ESSIV mode";
return -EINVAL;
}
hash_tfm = crypto_alloc_ahash(opts, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(hash_tfm)) {
ti->error = "Error initializing ESSIV hash";
err = PTR_ERR(hash_tfm);
goto bad;
}
salt = kzalloc(crypto_ahash_digestsize(hash_tfm), GFP_KERNEL);
if (!salt) {
ti->error = "Error kmallocing salt storage in ESSIV";
err = -ENOMEM;
goto bad;
}
cc->iv_gen_private.essiv.salt = salt;
cc->iv_gen_private.essiv.hash_tfm = hash_tfm;
essiv_tfm = alloc_essiv_cipher(cc, ti, salt,
crypto_ahash_digestsize(hash_tfm));
if (IS_ERR(essiv_tfm)) {
crypt_iv_essiv_dtr(cc);
return PTR_ERR(essiv_tfm);
}
cc->iv_private = essiv_tfm;
return 0;
bad:
if (hash_tfm && !IS_ERR(hash_tfm))
crypto_free_ahash(hash_tfm);
kfree(salt);
return err;
}
static int crypt_iv_essiv_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
struct crypto_cipher *essiv_tfm = cc->iv_private;
memset(iv, 0, cc->iv_size);
*(__le64 *)iv = cpu_to_le64(dmreq->iv_sector);
crypto_cipher_encrypt_one(essiv_tfm, iv, iv);
return 0;
}
static int crypt_iv_benbi_ctr(struct crypt_config *cc, struct dm_target *ti,
const char *opts)
{
unsigned bs = crypto_skcipher_blocksize(any_tfm(cc));
int log = ilog2(bs);
if (1 << log != bs) {
ti->error = "cypher blocksize is not a power of 2";
return -EINVAL;
}
if (log > 9) {
ti->error = "cypher blocksize is > 512";
return -EINVAL;
}
cc->iv_gen_private.benbi.shift = 9 - log;
return 0;
}
static void crypt_iv_benbi_dtr(struct crypt_config *cc)
{
}
static int crypt_iv_benbi_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
__be64 val;
memset(iv, 0, cc->iv_size - sizeof(u64));
val = cpu_to_be64(((u64)dmreq->iv_sector << cc->iv_gen_private.benbi.shift) + 1);
put_unaligned(val, (__be64 *)(iv + cc->iv_size - sizeof(u64)));
return 0;
}
static int crypt_iv_null_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
memset(iv, 0, cc->iv_size);
return 0;
}
static void crypt_iv_lmk_dtr(struct crypt_config *cc)
{
struct iv_lmk_private *lmk = &cc->iv_gen_private.lmk;
if (lmk->hash_tfm && !IS_ERR(lmk->hash_tfm))
crypto_free_shash(lmk->hash_tfm);
lmk->hash_tfm = NULL;
kzfree(lmk->seed);
lmk->seed = NULL;
}
static int crypt_iv_lmk_ctr(struct crypt_config *cc, struct dm_target *ti,
const char *opts)
{
struct iv_lmk_private *lmk = &cc->iv_gen_private.lmk;
if (cc->sector_size != (1 << SECTOR_SHIFT)) {
ti->error = "Unsupported sector size for LMK";
return -EINVAL;
}
lmk->hash_tfm = crypto_alloc_shash("md5", 0, 0);
if (IS_ERR(lmk->hash_tfm)) {
ti->error = "Error initializing LMK hash";
return PTR_ERR(lmk->hash_tfm);
}
if (cc->key_parts == cc->tfms_count) {
lmk->seed = NULL;
return 0;
}
lmk->seed = kzalloc(LMK_SEED_SIZE, GFP_KERNEL);
if (!lmk->seed) {
crypt_iv_lmk_dtr(cc);
ti->error = "Error kmallocing seed storage in LMK";
return -ENOMEM;
}
return 0;
}
static int crypt_iv_lmk_init(struct crypt_config *cc)
{
struct iv_lmk_private *lmk = &cc->iv_gen_private.lmk;
int subkey_size = cc->key_size / cc->key_parts;
if (lmk->seed)
memcpy(lmk->seed, cc->key + (cc->tfms_count * subkey_size),
crypto_shash_digestsize(lmk->hash_tfm));
return 0;
}
static int crypt_iv_lmk_wipe(struct crypt_config *cc)
{
struct iv_lmk_private *lmk = &cc->iv_gen_private.lmk;
if (lmk->seed)
memset(lmk->seed, 0, LMK_SEED_SIZE);
return 0;
}
static int crypt_iv_lmk_one(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq,
u8 *data)
{
struct iv_lmk_private *lmk = &cc->iv_gen_private.lmk;
SHASH_DESC_ON_STACK(desc, lmk->hash_tfm);
struct md5_state md5state;
__le32 buf[4];
int i, r;
desc->tfm = lmk->hash_tfm;
desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;
r = crypto_shash_init(desc);
if (r)
return r;
if (lmk->seed) {
r = crypto_shash_update(desc, lmk->seed, LMK_SEED_SIZE);
if (r)
return r;
}
r = crypto_shash_update(desc, data + 16, 16 * 31);
if (r)
return r;
buf[0] = cpu_to_le32(dmreq->iv_sector & 0xFFFFFFFF);
buf[1] = cpu_to_le32((((u64)dmreq->iv_sector >> 32) & 0x00FFFFFF) | 0x80000000);
buf[2] = cpu_to_le32(4024);
buf[3] = 0;
r = crypto_shash_update(desc, (u8 *)buf, sizeof(buf));
if (r)
return r;
r = crypto_shash_export(desc, &md5state);
if (r)
return r;
for (i = 0; i < MD5_HASH_WORDS; i++)
__cpu_to_le32s(&md5state.hash[i]);
memcpy(iv, &md5state.hash, cc->iv_size);
return 0;
}
static int crypt_iv_lmk_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
struct scatterlist *sg;
u8 *src;
int r = 0;
if (bio_data_dir(dmreq->ctx->bio_in) == WRITE) {
sg = crypt_get_sg_data(cc, dmreq->sg_in);
src = kmap_atomic(sg_page(sg));
r = crypt_iv_lmk_one(cc, iv, dmreq, src + sg->offset);
kunmap_atomic(src);
} else
memset(iv, 0, cc->iv_size);
return r;
}
static int crypt_iv_lmk_post(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
struct scatterlist *sg;
u8 *dst;
int r;
if (bio_data_dir(dmreq->ctx->bio_in) == WRITE)
return 0;
sg = crypt_get_sg_data(cc, dmreq->sg_out);
dst = kmap_atomic(sg_page(sg));
r = crypt_iv_lmk_one(cc, iv, dmreq, dst + sg->offset);
if (!r)
crypto_xor(dst + sg->offset, iv, cc->iv_size);
kunmap_atomic(dst);
return r;
}
static void crypt_iv_tcw_dtr(struct crypt_config *cc)
{
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
kzfree(tcw->iv_seed);
tcw->iv_seed = NULL;
kzfree(tcw->whitening);
tcw->whitening = NULL;
if (tcw->crc32_tfm && !IS_ERR(tcw->crc32_tfm))
crypto_free_shash(tcw->crc32_tfm);
tcw->crc32_tfm = NULL;
}
static int crypt_iv_tcw_ctr(struct crypt_config *cc, struct dm_target *ti,
const char *opts)
{
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
if (cc->sector_size != (1 << SECTOR_SHIFT)) {
ti->error = "Unsupported sector size for TCW";
return -EINVAL;
}
if (cc->key_size <= (cc->iv_size + TCW_WHITENING_SIZE)) {
ti->error = "Wrong key size for TCW";
return -EINVAL;
}
tcw->crc32_tfm = crypto_alloc_shash("crc32", 0, 0);
if (IS_ERR(tcw->crc32_tfm)) {
ti->error = "Error initializing CRC32 in TCW";
return PTR_ERR(tcw->crc32_tfm);
}
tcw->iv_seed = kzalloc(cc->iv_size, GFP_KERNEL);
tcw->whitening = kzalloc(TCW_WHITENING_SIZE, GFP_KERNEL);
if (!tcw->iv_seed || !tcw->whitening) {
crypt_iv_tcw_dtr(cc);
ti->error = "Error allocating seed storage in TCW";
return -ENOMEM;
}
return 0;
}
static int crypt_iv_tcw_init(struct crypt_config *cc)
{
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
int key_offset = cc->key_size - cc->iv_size - TCW_WHITENING_SIZE;
memcpy(tcw->iv_seed, &cc->key[key_offset], cc->iv_size);
memcpy(tcw->whitening, &cc->key[key_offset + cc->iv_size],
TCW_WHITENING_SIZE);
return 0;
}
static int crypt_iv_tcw_wipe(struct crypt_config *cc)
{
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
memset(tcw->iv_seed, 0, cc->iv_size);
memset(tcw->whitening, 0, TCW_WHITENING_SIZE);
return 0;
}
static int crypt_iv_tcw_whitening(struct crypt_config *cc,
struct dm_crypt_request *dmreq,
u8 *data)
{
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
__le64 sector = cpu_to_le64(dmreq->iv_sector);
u8 buf[TCW_WHITENING_SIZE];
SHASH_DESC_ON_STACK(desc, tcw->crc32_tfm);
int i, r;
memcpy(buf, tcw->whitening, TCW_WHITENING_SIZE);
crypto_xor(buf, (u8 *)&sector, 8);
crypto_xor(&buf[8], (u8 *)&sector, 8);
desc->tfm = tcw->crc32_tfm;
desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;
for (i = 0; i < 4; i++) {
r = crypto_shash_init(desc);
if (r)
goto out;
r = crypto_shash_update(desc, &buf[i * 4], 4);
if (r)
goto out;
r = crypto_shash_final(desc, &buf[i * 4]);
if (r)
goto out;
}
crypto_xor(&buf[0], &buf[12], 4);
crypto_xor(&buf[4], &buf[8], 4);
for (i = 0; i < ((1 << SECTOR_SHIFT) / 8); i++)
crypto_xor(data + i * 8, buf, 8);
out:
memzero_explicit(buf, sizeof(buf));
return r;
}
static int crypt_iv_tcw_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
struct scatterlist *sg;
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
__le64 sector = cpu_to_le64(dmreq->iv_sector);
u8 *src;
int r = 0;
if (bio_data_dir(dmreq->ctx->bio_in) != WRITE) {
sg = crypt_get_sg_data(cc, dmreq->sg_in);
src = kmap_atomic(sg_page(sg));
r = crypt_iv_tcw_whitening(cc, dmreq, src + sg->offset);
kunmap_atomic(src);
}
memcpy(iv, tcw->iv_seed, cc->iv_size);
crypto_xor(iv, (u8 *)&sector, 8);
if (cc->iv_size > 8)
crypto_xor(&iv[8], (u8 *)&sector, cc->iv_size - 8);
return r;
}
static int crypt_iv_tcw_post(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
struct scatterlist *sg;
u8 *dst;
int r;
if (bio_data_dir(dmreq->ctx->bio_in) != WRITE)
return 0;
sg = crypt_get_sg_data(cc, dmreq->sg_out);
dst = kmap_atomic(sg_page(sg));
r = crypt_iv_tcw_whitening(cc, dmreq, dst + sg->offset);
kunmap_atomic(dst);
return r;
}
static int crypt_iv_random_gen(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
get_random_bytes(iv, cc->iv_size);
return 0;
}
static bool crypt_integrity_aead(struct crypt_config *cc)
{
return test_bit(CRYPT_MODE_INTEGRITY_AEAD, &cc->cipher_flags);
}
static bool crypt_integrity_hmac(struct crypt_config *cc)
{
return crypt_integrity_aead(cc) && cc->key_mac_size;
}
static struct scatterlist *crypt_get_sg_data(struct crypt_config *cc,
struct scatterlist *sg)
{
if (unlikely(crypt_integrity_aead(cc)))
return &sg[2];
return sg;
}
static int dm_crypt_integrity_io_alloc(struct dm_crypt_io *io, struct bio *bio)
{
struct bio_integrity_payload *bip;
unsigned int tag_len;
int ret;
if (!bio_sectors(bio) || !io->cc->on_disk_tag_size)
return 0;
bip = bio_integrity_alloc(bio, GFP_NOIO, 1);
if (IS_ERR(bip))
return PTR_ERR(bip);
tag_len = io->cc->on_disk_tag_size * bio_sectors(bio);
bip->bip_iter.bi_size = tag_len;
bip->bip_iter.bi_sector = io->cc->start + io->sector;
bip->bip_flags &= ~BIP_BLOCK_INTEGRITY;
ret = bio_integrity_add_page(bio, virt_to_page(io->integrity_metadata),
tag_len, offset_in_page(io->integrity_metadata));
if (unlikely(ret != tag_len))
return -ENOMEM;
return 0;
}
static int crypt_integrity_ctr(struct crypt_config *cc, struct dm_target *ti)
{
#ifdef CONFIG_BLK_DEV_INTEGRITY
struct blk_integrity *bi = blk_get_integrity(cc->dev->bdev->bd_disk);
if (!bi || strcasecmp(bi->profile->name, "DM-DIF-EXT-TAG")) {
ti->error = "Integrity profile not supported.";
return -EINVAL;
}
if (bi->tag_size != cc->on_disk_tag_size ||
bi->tuple_size != cc->on_disk_tag_size) {
ti->error = "Integrity profile tag size mismatch.";
return -EINVAL;
}
if (1 << bi->interval_exp != cc->sector_size) {
ti->error = "Integrity profile sector size mismatch.";
return -EINVAL;
}
if (crypt_integrity_aead(cc)) {
cc->integrity_tag_size = cc->on_disk_tag_size - cc->integrity_iv_size;
DMINFO("Integrity AEAD, tag size %u, IV size %u.",
cc->integrity_tag_size, cc->integrity_iv_size);
if (crypto_aead_setauthsize(any_tfm_aead(cc), cc->integrity_tag_size)) {
ti->error = "Integrity AEAD auth tag size is not supported.";
return -EINVAL;
}
} else if (cc->integrity_iv_size)
DMINFO("Additional per-sector space %u bytes for IV.",
cc->integrity_iv_size);
if ((cc->integrity_tag_size + cc->integrity_iv_size) != bi->tag_size) {
ti->error = "Not enough space for integrity tag in the profile.";
return -EINVAL;
}
return 0;
#else
ti->error = "Integrity profile not supported.";
return -EINVAL;
#endif
}
static void crypt_convert_init(struct crypt_config *cc,
struct convert_context *ctx,
struct bio *bio_out, struct bio *bio_in,
sector_t sector)
{
ctx->bio_in = bio_in;
ctx->bio_out = bio_out;
if (bio_in)
ctx->iter_in = bio_in->bi_iter;
if (bio_out)
ctx->iter_out = bio_out->bi_iter;
ctx->cc_sector = sector + cc->iv_offset;
init_completion(&ctx->restart);
}
static struct dm_crypt_request *dmreq_of_req(struct crypt_config *cc,
void *req)
{
return (struct dm_crypt_request *)((char *)req + cc->dmreq_start);
}
static void *req_of_dmreq(struct crypt_config *cc, struct dm_crypt_request *dmreq)
{
return (void *)((char *)dmreq - cc->dmreq_start);
}
static u8 *iv_of_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
if (crypt_integrity_aead(cc))
return (u8 *)ALIGN((unsigned long)(dmreq + 1),
crypto_aead_alignmask(any_tfm_aead(cc)) + 1);
else
return (u8 *)ALIGN((unsigned long)(dmreq + 1),
crypto_skcipher_alignmask(any_tfm(cc)) + 1);
}
static u8 *org_iv_of_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
return iv_of_dmreq(cc, dmreq) + cc->iv_size;
}
static uint64_t *org_sector_of_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
u8 *ptr = iv_of_dmreq(cc, dmreq) + cc->iv_size + cc->iv_size;
return (uint64_t*) ptr;
}
static unsigned int *org_tag_of_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
u8 *ptr = iv_of_dmreq(cc, dmreq) + cc->iv_size +
cc->iv_size + sizeof(uint64_t);
return (unsigned int*)ptr;
}
static void *tag_from_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
struct convert_context *ctx = dmreq->ctx;
struct dm_crypt_io *io = container_of(ctx, struct dm_crypt_io, ctx);
return &io->integrity_metadata[*org_tag_of_dmreq(cc, dmreq) *
cc->on_disk_tag_size];
}
static void *iv_tag_from_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
return tag_from_dmreq(cc, dmreq) + cc->integrity_tag_size;
}
static int crypt_convert_block_aead(struct crypt_config *cc,
struct convert_context *ctx,
struct aead_request *req,
unsigned int tag_offset)
{
struct bio_vec bv_in = bio_iter_iovec(ctx->bio_in, ctx->iter_in);
struct bio_vec bv_out = bio_iter_iovec(ctx->bio_out, ctx->iter_out);
struct dm_crypt_request *dmreq;
u8 *iv, *org_iv, *tag_iv, *tag;
uint64_t *sector;
int r = 0;
BUG_ON(cc->integrity_iv_size && cc->integrity_iv_size != cc->iv_size);
if (unlikely(bv_in.bv_offset & (cc->sector_size - 1)))
return -EIO;
dmreq = dmreq_of_req(cc, req);
dmreq->iv_sector = ctx->cc_sector;
if (test_bit(CRYPT_IV_LARGE_SECTORS, &cc->cipher_flags))
dmreq->iv_sector >>= cc->sector_shift;
dmreq->ctx = ctx;
*org_tag_of_dmreq(cc, dmreq) = tag_offset;
sector = org_sector_of_dmreq(cc, dmreq);
*sector = cpu_to_le64(ctx->cc_sector - cc->iv_offset);
iv = iv_of_dmreq(cc, dmreq);
org_iv = org_iv_of_dmreq(cc, dmreq);
tag = tag_from_dmreq(cc, dmreq);
tag_iv = iv_tag_from_dmreq(cc, dmreq);
sg_init_table(dmreq->sg_in, 4);
sg_set_buf(&dmreq->sg_in[0], sector, sizeof(uint64_t));
sg_set_buf(&dmreq->sg_in[1], org_iv, cc->iv_size);
sg_set_page(&dmreq->sg_in[2], bv_in.bv_page, cc->sector_size, bv_in.bv_offset);
sg_set_buf(&dmreq->sg_in[3], tag, cc->integrity_tag_size);
sg_init_table(dmreq->sg_out, 4);
sg_set_buf(&dmreq->sg_out[0], sector, sizeof(uint64_t));
sg_set_buf(&dmreq->sg_out[1], org_iv, cc->iv_size);
sg_set_page(&dmreq->sg_out[2], bv_out.bv_page, cc->sector_size, bv_out.bv_offset);
sg_set_buf(&dmreq->sg_out[3], tag, cc->integrity_tag_size);
if (cc->iv_gen_ops) {
if (cc->integrity_iv_size && bio_data_dir(ctx->bio_in) != WRITE) {
memcpy(org_iv, tag_iv, cc->iv_size);
} else {
r = cc->iv_gen_ops->generator(cc, org_iv, dmreq);
if (r < 0)
return r;
if (cc->integrity_iv_size)
memcpy(tag_iv, org_iv, cc->iv_size);
}
memcpy(iv, org_iv, cc->iv_size);
}
aead_request_set_ad(req, sizeof(uint64_t) + cc->iv_size);
if (bio_data_dir(ctx->bio_in) == WRITE) {
aead_request_set_crypt(req, dmreq->sg_in, dmreq->sg_out,
cc->sector_size, iv);
r = crypto_aead_encrypt(req);
if (cc->integrity_tag_size + cc->integrity_iv_size != cc->on_disk_tag_size)
memset(tag + cc->integrity_tag_size + cc->integrity_iv_size, 0,
cc->on_disk_tag_size - (cc->integrity_tag_size + cc->integrity_iv_size));
} else {
aead_request_set_crypt(req, dmreq->sg_in, dmreq->sg_out,
cc->sector_size + cc->integrity_tag_size, iv);
r = crypto_aead_decrypt(req);
}
if (r == -EBADMSG)
DMERR_LIMIT("INTEGRITY AEAD ERROR, sector %llu",
(unsigned long long)le64_to_cpu(*sector));
if (!r && cc->iv_gen_ops && cc->iv_gen_ops->post)
r = cc->iv_gen_ops->post(cc, org_iv, dmreq);
bio_advance_iter(ctx->bio_in, &ctx->iter_in, cc->sector_size);
bio_advance_iter(ctx->bio_out, &ctx->iter_out, cc->sector_size);
return r;
}
static int crypt_convert_block_skcipher(struct crypt_config *cc,
struct convert_context *ctx,
struct skcipher_request *req,
unsigned int tag_offset)
{
struct bio_vec bv_in = bio_iter_iovec(ctx->bio_in, ctx->iter_in);
struct bio_vec bv_out = bio_iter_iovec(ctx->bio_out, ctx->iter_out);
struct scatterlist *sg_in, *sg_out;
struct dm_crypt_request *dmreq;
u8 *iv, *org_iv, *tag_iv;
uint64_t *sector;
int r = 0;
if (unlikely(bv_in.bv_offset & (cc->sector_size - 1)))
return -EIO;
dmreq = dmreq_of_req(cc, req);
dmreq->iv_sector = ctx->cc_sector;
if (test_bit(CRYPT_IV_LARGE_SECTORS, &cc->cipher_flags))
dmreq->iv_sector >>= cc->sector_shift;
dmreq->ctx = ctx;
*org_tag_of_dmreq(cc, dmreq) = tag_offset;
iv = iv_of_dmreq(cc, dmreq);
org_iv = org_iv_of_dmreq(cc, dmreq);
tag_iv = iv_tag_from_dmreq(cc, dmreq);
sector = org_sector_of_dmreq(cc, dmreq);
*sector = cpu_to_le64(ctx->cc_sector - cc->iv_offset);
sg_in = &dmreq->sg_in[0];
sg_out = &dmreq->sg_out[0];
sg_init_table(sg_in, 1);
sg_set_page(sg_in, bv_in.bv_page, cc->sector_size, bv_in.bv_offset);
sg_init_table(sg_out, 1);
sg_set_page(sg_out, bv_out.bv_page, cc->sector_size, bv_out.bv_offset);
if (cc->iv_gen_ops) {
if (cc->integrity_iv_size && bio_data_dir(ctx->bio_in) != WRITE) {
memcpy(org_iv, tag_iv, cc->integrity_iv_size);
} else {
r = cc->iv_gen_ops->generator(cc, org_iv, dmreq);
if (r < 0)
return r;
if (cc->integrity_iv_size)
memcpy(tag_iv, org_iv, cc->integrity_iv_size);
}
memcpy(iv, org_iv, cc->iv_size);
}
skcipher_request_set_crypt(req, sg_in, sg_out, cc->sector_size, iv);
if (bio_data_dir(ctx->bio_in) == WRITE)
r = crypto_skcipher_encrypt(req);
else
r = crypto_skcipher_decrypt(req);
if (!r && cc->iv_gen_ops && cc->iv_gen_ops->post)
r = cc->iv_gen_ops->post(cc, org_iv, dmreq);
bio_advance_iter(ctx->bio_in, &ctx->iter_in, cc->sector_size);
bio_advance_iter(ctx->bio_out, &ctx->iter_out, cc->sector_size);
return r;
}
static void crypt_alloc_req_skcipher(struct crypt_config *cc,
struct convert_context *ctx)
{
unsigned key_index = ctx->cc_sector & (cc->tfms_count - 1);
if (!ctx->r.req)
ctx->r.req = mempool_alloc(cc->req_pool, GFP_NOIO);
skcipher_request_set_tfm(ctx->r.req, cc->cipher_tfm.tfms[key_index]);
skcipher_request_set_callback(ctx->r.req,
CRYPTO_TFM_REQ_MAY_BACKLOG | CRYPTO_TFM_REQ_MAY_SLEEP,
kcryptd_async_done, dmreq_of_req(cc, ctx->r.req));
}
static void crypt_alloc_req_aead(struct crypt_config *cc,
struct convert_context *ctx)
{
if (!ctx->r.req_aead)
ctx->r.req_aead = mempool_alloc(cc->req_pool, GFP_NOIO);
aead_request_set_tfm(ctx->r.req_aead, cc->cipher_tfm.tfms_aead[0]);
aead_request_set_callback(ctx->r.req_aead,
CRYPTO_TFM_REQ_MAY_BACKLOG | CRYPTO_TFM_REQ_MAY_SLEEP,
kcryptd_async_done, dmreq_of_req(cc, ctx->r.req_aead));
}
static void crypt_alloc_req(struct crypt_config *cc,
struct convert_context *ctx)
{
if (crypt_integrity_aead(cc))
crypt_alloc_req_aead(cc, ctx);
else
crypt_alloc_req_skcipher(cc, ctx);
}
static void crypt_free_req_skcipher(struct crypt_config *cc,
struct skcipher_request *req, struct bio *base_bio)
{
struct dm_crypt_io *io = dm_per_bio_data(base_bio, cc->per_bio_data_size);
if ((struct skcipher_request *)(io + 1) != req)
mempool_free(req, cc->req_pool);
}
static void crypt_free_req_aead(struct crypt_config *cc,
struct aead_request *req, struct bio *base_bio)
{
struct dm_crypt_io *io = dm_per_bio_data(base_bio, cc->per_bio_data_size);
if ((struct aead_request *)(io + 1) != req)
mempool_free(req, cc->req_pool);
}
static void crypt_free_req(struct crypt_config *cc, void *req, struct bio *base_bio)
{
if (crypt_integrity_aead(cc))
crypt_free_req_aead(cc, req, base_bio);
else
crypt_free_req_skcipher(cc, req, base_bio);
}
static blk_status_t crypt_convert(struct crypt_config *cc,
struct convert_context *ctx)
{
unsigned int tag_offset = 0;
unsigned int sector_step = cc->sector_size >> SECTOR_SHIFT;
int r;
atomic_set(&ctx->cc_pending, 1);
while (ctx->iter_in.bi_size && ctx->iter_out.bi_size) {
crypt_alloc_req(cc, ctx);
atomic_inc(&ctx->cc_pending);
if (crypt_integrity_aead(cc))
r = crypt_convert_block_aead(cc, ctx, ctx->r.req_aead, tag_offset);
else
r = crypt_convert_block_skcipher(cc, ctx, ctx->r.req, tag_offset);
switch (r) {
case -EBUSY:
wait_for_completion(&ctx->restart);
reinit_completion(&ctx->restart);
case -EINPROGRESS:
ctx->r.req = NULL;
ctx->cc_sector += sector_step;
tag_offset++;
continue;
case 0:
atomic_dec(&ctx->cc_pending);
ctx->cc_sector += sector_step;
tag_offset++;
cond_resched();
continue;
case -EBADMSG:
atomic_dec(&ctx->cc_pending);
return BLK_STS_PROTECTION;
default:
atomic_dec(&ctx->cc_pending);
return BLK_STS_IOERR;
}
}
return 0;
}
static struct bio *crypt_alloc_buffer(struct dm_crypt_io *io, unsigned size)
{
struct crypt_config *cc = io->cc;
struct bio *clone;
unsigned int nr_iovecs = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
gfp_t gfp_mask = GFP_NOWAIT | __GFP_HIGHMEM;
unsigned i, len, remaining_size;
struct page *page;
retry:
if (unlikely(gfp_mask & __GFP_DIRECT_RECLAIM))
mutex_lock(&cc->bio_alloc_lock);
clone = bio_alloc_bioset(GFP_NOIO, nr_iovecs, cc->bs);
if (!clone)
goto out;
clone_init(io, clone);
remaining_size = size;
for (i = 0; i < nr_iovecs; i++) {
page = mempool_alloc(cc->page_pool, gfp_mask);
if (!page) {
crypt_free_buffer_pages(cc, clone);
bio_put(clone);
gfp_mask |= __GFP_DIRECT_RECLAIM;
goto retry;
}
len = (remaining_size > PAGE_SIZE) ? PAGE_SIZE : remaining_size;
bio_add_page(clone, page, len, 0);
remaining_size -= len;
}
if (dm_crypt_integrity_io_alloc(io, clone)) {
crypt_free_buffer_pages(cc, clone);
bio_put(clone);
clone = NULL;
}
out:
if (unlikely(gfp_mask & __GFP_DIRECT_RECLAIM))
mutex_unlock(&cc->bio_alloc_lock);
return clone;
}
static void crypt_free_buffer_pages(struct crypt_config *cc, struct bio *clone)
{
unsigned int i;
struct bio_vec *bv;
bio_for_each_segment_all(bv, clone, i) {
BUG_ON(!bv->bv_page);
mempool_free(bv->bv_page, cc->page_pool);
bv->bv_page = NULL;
}
}
static void crypt_io_init(struct dm_crypt_io *io, struct crypt_config *cc,
struct bio *bio, sector_t sector)
{
io->cc = cc;
io->base_bio = bio;
io->sector = sector;
io->error = 0;
io->ctx.r.req = NULL;
io->integrity_metadata = NULL;
io->integrity_metadata_from_pool = false;
atomic_set(&io->io_pending, 0);
}
static void crypt_inc_pending(struct dm_crypt_io *io)
{
atomic_inc(&io->io_pending);
}
static void crypt_dec_pending(struct dm_crypt_io *io)
{
struct crypt_config *cc = io->cc;
struct bio *base_bio = io->base_bio;
blk_status_t error = io->error;
if (!atomic_dec_and_test(&io->io_pending))
return;
if (io->ctx.r.req)
crypt_free_req(cc, io->ctx.r.req, base_bio);
if (unlikely(io->integrity_metadata_from_pool))
mempool_free(io->integrity_metadata, io->cc->tag_pool);
else
kfree(io->integrity_metadata);
base_bio->bi_status = error;
bio_endio(base_bio);
}
static void crypt_endio(struct bio *clone)
{
struct dm_crypt_io *io = clone->bi_private;
struct crypt_config *cc = io->cc;
unsigned rw = bio_data_dir(clone);
blk_status_t error;
if (rw == WRITE)
crypt_free_buffer_pages(cc, clone);
error = clone->bi_status;
bio_put(clone);
if (rw == READ && !error) {
kcryptd_queue_crypt(io);
return;
}
if (unlikely(error))
io->error = error;
crypt_dec_pending(io);
}
static void clone_init(struct dm_crypt_io *io, struct bio *clone)
{
struct crypt_config *cc = io->cc;
clone->bi_private = io;
clone->bi_end_io = crypt_endio;
clone->bi_bdev = cc->dev->bdev;
clone->bi_opf = io->base_bio->bi_opf;
}
static int kcryptd_io_read(struct dm_crypt_io *io, gfp_t gfp)
{
struct crypt_config *cc = io->cc;
struct bio *clone;
clone = bio_clone_fast(io->base_bio, gfp, cc->bs);
if (!clone)
return 1;
crypt_inc_pending(io);
clone_init(io, clone);
clone->bi_iter.bi_sector = cc->start + io->sector;
if (dm_crypt_integrity_io_alloc(io, clone)) {
crypt_dec_pending(io);
bio_put(clone);
return 1;
}
generic_make_request(clone);
return 0;
}
static void kcryptd_io_read_work(struct work_struct *work)
{
struct dm_crypt_io *io = container_of(work, struct dm_crypt_io, work);
crypt_inc_pending(io);
if (kcryptd_io_read(io, GFP_NOIO))
io->error = BLK_STS_RESOURCE;
crypt_dec_pending(io);
}
static void kcryptd_queue_read(struct dm_crypt_io *io)
{
struct crypt_config *cc = io->cc;
INIT_WORK(&io->work, kcryptd_io_read_work);
queue_work(cc->io_queue, &io->work);
}
static void kcryptd_io_write(struct dm_crypt_io *io)
{
struct bio *clone = io->ctx.bio_out;
generic_make_request(clone);
}
static int dmcrypt_write(void *data)
{
struct crypt_config *cc = data;
struct dm_crypt_io *io;
while (1) {
struct rb_root write_tree;
struct blk_plug plug;
DECLARE_WAITQUEUE(wait, current);
spin_lock_irq(&cc->write_thread_wait.lock);
continue_locked:
if (!RB_EMPTY_ROOT(&cc->write_tree))
goto pop_from_list;
set_current_state(TASK_INTERRUPTIBLE);
__add_wait_queue(&cc->write_thread_wait, &wait);
spin_unlock_irq(&cc->write_thread_wait.lock);
if (unlikely(kthread_should_stop())) {
set_current_state(TASK_RUNNING);
remove_wait_queue(&cc->write_thread_wait, &wait);
break;
}
schedule();
set_current_state(TASK_RUNNING);
spin_lock_irq(&cc->write_thread_wait.lock);
__remove_wait_queue(&cc->write_thread_wait, &wait);
goto continue_locked;
pop_from_list:
write_tree = cc->write_tree;
cc->write_tree = RB_ROOT;
spin_unlock_irq(&cc->write_thread_wait.lock);
BUG_ON(rb_parent(write_tree.rb_node));
blk_start_plug(&plug);
do {
io = crypt_io_from_node(rb_first(&write_tree));
rb_erase(&io->rb_node, &write_tree);
kcryptd_io_write(io);
} while (!RB_EMPTY_ROOT(&write_tree));
blk_finish_plug(&plug);
}
return 0;
}
static void kcryptd_crypt_write_io_submit(struct dm_crypt_io *io, int async)
{
struct bio *clone = io->ctx.bio_out;
struct crypt_config *cc = io->cc;
unsigned long flags;
sector_t sector;
struct rb_node **rbp, *parent;
if (unlikely(io->error)) {
crypt_free_buffer_pages(cc, clone);
bio_put(clone);
crypt_dec_pending(io);
return;
}
BUG_ON(io->ctx.iter_out.bi_size);
clone->bi_iter.bi_sector = cc->start + io->sector;
if (likely(!async) && test_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags)) {
generic_make_request(clone);
return;
}
spin_lock_irqsave(&cc->write_thread_wait.lock, flags);
rbp = &cc->write_tree.rb_node;
parent = NULL;
sector = io->sector;
while (*rbp) {
parent = *rbp;
if (sector < crypt_io_from_node(parent)->sector)
rbp = &(*rbp)->rb_left;
else
rbp = &(*rbp)->rb_right;
}
rb_link_node(&io->rb_node, parent, rbp);
rb_insert_color(&io->rb_node, &cc->write_tree);
wake_up_locked(&cc->write_thread_wait);
spin_unlock_irqrestore(&cc->write_thread_wait.lock, flags);
}
static void kcryptd_crypt_write_convert(struct dm_crypt_io *io)
{
struct crypt_config *cc = io->cc;
struct bio *clone;
int crypt_finished;
sector_t sector = io->sector;
blk_status_t r;
crypt_inc_pending(io);
crypt_convert_init(cc, &io->ctx, NULL, io->base_bio, sector);
clone = crypt_alloc_buffer(io, io->base_bio->bi_iter.bi_size);
if (unlikely(!clone)) {
io->error = BLK_STS_IOERR;
goto dec;
}
io->ctx.bio_out = clone;
io->ctx.iter_out = clone->bi_iter;
sector += bio_sectors(clone);
crypt_inc_pending(io);
r = crypt_convert(cc, &io->ctx);
if (r)
io->error = r;
crypt_finished = atomic_dec_and_test(&io->ctx.cc_pending);
if (crypt_finished) {
kcryptd_crypt_write_io_submit(io, 0);
io->sector = sector;
}
dec:
crypt_dec_pending(io);
}
static void kcryptd_crypt_read_done(struct dm_crypt_io *io)
{
crypt_dec_pending(io);
}
static void kcryptd_crypt_read_convert(struct dm_crypt_io *io)
{
struct crypt_config *cc = io->cc;
blk_status_t r;
crypt_inc_pending(io);
crypt_convert_init(cc, &io->ctx, io->base_bio, io->base_bio,
io->sector);
r = crypt_convert(cc, &io->ctx);
if (r)
io->error = r;
if (atomic_dec_and_test(&io->ctx.cc_pending))
kcryptd_crypt_read_done(io);
crypt_dec_pending(io);
}
static void kcryptd_async_done(struct crypto_async_request *async_req,
int error)
{
struct dm_crypt_request *dmreq = async_req->data;
struct convert_context *ctx = dmreq->ctx;
struct dm_crypt_io *io = container_of(ctx, struct dm_crypt_io, ctx);
struct crypt_config *cc = io->cc;
if (error == -EINPROGRESS) {
complete(&ctx->restart);
return;
}
if (!error && cc->iv_gen_ops && cc->iv_gen_ops->post)
error = cc->iv_gen_ops->post(cc, org_iv_of_dmreq(cc, dmreq), dmreq);
if (error == -EBADMSG) {
DMERR_LIMIT("INTEGRITY AEAD ERROR, sector %llu",
(unsigned long long)le64_to_cpu(*org_sector_of_dmreq(cc, dmreq)));
io->error = BLK_STS_PROTECTION;
} else if (error < 0)
io->error = BLK_STS_IOERR;
crypt_free_req(cc, req_of_dmreq(cc, dmreq), io->base_bio);
if (!atomic_dec_and_test(&ctx->cc_pending))
return;
if (bio_data_dir(io->base_bio) == READ)
kcryptd_crypt_read_done(io);
else
kcryptd_crypt_write_io_submit(io, 1);
}
static void kcryptd_crypt(struct work_struct *work)
{
struct dm_crypt_io *io = container_of(work, struct dm_crypt_io, work);
if (bio_data_dir(io->base_bio) == READ)
kcryptd_crypt_read_convert(io);
else
kcryptd_crypt_write_convert(io);
}
static void kcryptd_queue_crypt(struct dm_crypt_io *io)
{
struct crypt_config *cc = io->cc;
INIT_WORK(&io->work, kcryptd_crypt);
queue_work(cc->crypt_queue, &io->work);
}
static void crypt_free_tfms_aead(struct crypt_config *cc)
{
if (!cc->cipher_tfm.tfms_aead)
return;
if (cc->cipher_tfm.tfms_aead[0] && !IS_ERR(cc->cipher_tfm.tfms_aead[0])) {
crypto_free_aead(cc->cipher_tfm.tfms_aead[0]);
cc->cipher_tfm.tfms_aead[0] = NULL;
}
kfree(cc->cipher_tfm.tfms_aead);
cc->cipher_tfm.tfms_aead = NULL;
}
static void crypt_free_tfms_skcipher(struct crypt_config *cc)
{
unsigned i;
if (!cc->cipher_tfm.tfms)
return;
for (i = 0; i < cc->tfms_count; i++)
if (cc->cipher_tfm.tfms[i] && !IS_ERR(cc->cipher_tfm.tfms[i])) {
crypto_free_skcipher(cc->cipher_tfm.tfms[i]);
cc->cipher_tfm.tfms[i] = NULL;
}
kfree(cc->cipher_tfm.tfms);
cc->cipher_tfm.tfms = NULL;
}
static void crypt_free_tfms(struct crypt_config *cc)
{
if (crypt_integrity_aead(cc))
crypt_free_tfms_aead(cc);
else
crypt_free_tfms_skcipher(cc);
}
static int crypt_alloc_tfms_skcipher(struct crypt_config *cc, char *ciphermode)
{
unsigned i;
int err;
cc->cipher_tfm.tfms = kzalloc(cc->tfms_count *
sizeof(struct crypto_skcipher *), GFP_KERNEL);
if (!cc->cipher_tfm.tfms)
return -ENOMEM;
for (i = 0; i < cc->tfms_count; i++) {
cc->cipher_tfm.tfms[i] = crypto_alloc_skcipher(ciphermode, 0, 0);
if (IS_ERR(cc->cipher_tfm.tfms[i])) {
err = PTR_ERR(cc->cipher_tfm.tfms[i]);
crypt_free_tfms(cc);
return err;
}
}
return 0;
}
static int crypt_alloc_tfms_aead(struct crypt_config *cc, char *ciphermode)
{
int err;
cc->cipher_tfm.tfms = kmalloc(sizeof(struct crypto_aead *), GFP_KERNEL);
if (!cc->cipher_tfm.tfms)
return -ENOMEM;
cc->cipher_tfm.tfms_aead[0] = crypto_alloc_aead(ciphermode, 0, 0);
if (IS_ERR(cc->cipher_tfm.tfms_aead[0])) {
err = PTR_ERR(cc->cipher_tfm.tfms_aead[0]);
crypt_free_tfms(cc);
return err;
}
return 0;
}
static int crypt_alloc_tfms(struct crypt_config *cc, char *ciphermode)
{
if (crypt_integrity_aead(cc))
return crypt_alloc_tfms_aead(cc, ciphermode);
else
return crypt_alloc_tfms_skcipher(cc, ciphermode);
}
static unsigned crypt_subkey_size(struct crypt_config *cc)
{
return (cc->key_size - cc->key_extra_size) >> ilog2(cc->tfms_count);
}
static unsigned crypt_authenckey_size(struct crypt_config *cc)
{
return crypt_subkey_size(cc) + RTA_SPACE(sizeof(struct crypto_authenc_key_param));
}
static void crypt_copy_authenckey(char *p, const void *key,
unsigned enckeylen, unsigned authkeylen)
{
struct crypto_authenc_key_param *param;
struct rtattr *rta;
rta = (struct rtattr *)p;
param = RTA_DATA(rta);
param->enckeylen = cpu_to_be32(enckeylen);
rta->rta_len = RTA_LENGTH(sizeof(*param));
rta->rta_type = CRYPTO_AUTHENC_KEYA_PARAM;
p += RTA_SPACE(sizeof(*param));
memcpy(p, key + enckeylen, authkeylen);
p += authkeylen;
memcpy(p, key, enckeylen);
}
static int crypt_setkey(struct crypt_config *cc)
{
unsigned subkey_size;
int err = 0, i, r;
subkey_size = crypt_subkey_size(cc);
if (crypt_integrity_hmac(cc))
crypt_copy_authenckey(cc->authenc_key, cc->key,
subkey_size - cc->key_mac_size,
cc->key_mac_size);
for (i = 0; i < cc->tfms_count; i++) {
if (crypt_integrity_hmac(cc))
r = crypto_aead_setkey(cc->cipher_tfm.tfms_aead[i],
cc->authenc_key, crypt_authenckey_size(cc));
else if (crypt_integrity_aead(cc))
r = crypto_aead_setkey(cc->cipher_tfm.tfms_aead[i],
cc->key + (i * subkey_size),
subkey_size);
else
r = crypto_skcipher_setkey(cc->cipher_tfm.tfms[i],
cc->key + (i * subkey_size),
subkey_size);
if (r)
err = r;
}
if (crypt_integrity_hmac(cc))
memzero_explicit(cc->authenc_key, crypt_authenckey_size(cc));
return err;
}
static bool contains_whitespace(const char *str)
{
while (*str)
if (isspace(*str++))
return true;
return false;
}
static int crypt_set_keyring_key(struct crypt_config *cc, const char *key_string)
{
char *new_key_string, *key_desc;
int ret;
struct key *key;
const struct user_key_payload *ukp;
if (contains_whitespace(key_string)) {
DMERR("whitespace chars not allowed in key string");
return -EINVAL;
}
key_desc = strpbrk(key_string, ":");
if (!key_desc || key_desc == key_string || !strlen(key_desc + 1))
return -EINVAL;
if (strncmp(key_string, "logon:", key_desc - key_string + 1) &&
strncmp(key_string, "user:", key_desc - key_string + 1))
return -EINVAL;
new_key_string = kstrdup(key_string, GFP_KERNEL);
if (!new_key_string)
return -ENOMEM;
key = request_key(key_string[0] == 'l' ? &key_type_logon : &key_type_user,
key_desc + 1, NULL);
if (IS_ERR(key)) {
kzfree(new_key_string);
return PTR_ERR(key);
}
down_read(&key->sem);
ukp = user_key_payload_locked(key);
if (!ukp) {
up_read(&key->sem);
key_put(key);
kzfree(new_key_string);
return -EKEYREVOKED;
}
if (cc->key_size != ukp->datalen) {
up_read(&key->sem);
key_put(key);
kzfree(new_key_string);
return -EINVAL;
}
memcpy(cc->key, ukp->data, cc->key_size);
up_read(&key->sem);
key_put(key);
clear_bit(DM_CRYPT_KEY_VALID, &cc->flags);
ret = crypt_setkey(cc);
memset(cc->key, 0, cc->key_size * sizeof(u8));
if (!ret) {
set_bit(DM_CRYPT_KEY_VALID, &cc->flags);
kzfree(cc->key_string);
cc->key_string = new_key_string;
} else
kzfree(new_key_string);
return ret;
}
static int get_key_size(char **key_string)
{
char *colon, dummy;
int ret;
if (*key_string[0] != ':')
return strlen(*key_string) >> 1;
colon = strpbrk(*key_string + 1, ":");
if (!colon)
return -EINVAL;
if (sscanf(*key_string + 1, "%u%c", &ret, &dummy) != 2 || dummy != ':')
return -EINVAL;
*key_string = colon;
return ret;
}
static int crypt_set_keyring_key(struct crypt_config *cc, const char *key_string)
{
return -EINVAL;
}
static int get_key_size(char **key_string)
{
return (*key_string[0] == ':') ? -EINVAL : strlen(*key_string) >> 1;
}
static int crypt_set_key(struct crypt_config *cc, char *key)
{
int r = -EINVAL;
int key_string_len = strlen(key);
if (!cc->key_size && strcmp(key, "-"))
goto out;
if (key[0] == ':') {
r = crypt_set_keyring_key(cc, key + 1);
goto out;
}
clear_bit(DM_CRYPT_KEY_VALID, &cc->flags);
kzfree(cc->key_string);
cc->key_string = NULL;
if (cc->key_size && hex2bin(cc->key, key, cc->key_size) < 0)
goto out;
r = crypt_setkey(cc);
if (!r)
set_bit(DM_CRYPT_KEY_VALID, &cc->flags);
out:
memset(key, '0', key_string_len);
return r;
}
static int crypt_wipe_key(struct crypt_config *cc)
{
int r;
clear_bit(DM_CRYPT_KEY_VALID, &cc->flags);
get_random_bytes(&cc->key, cc->key_size);
kzfree(cc->key_string);
cc->key_string = NULL;
r = crypt_setkey(cc);
memset(&cc->key, 0, cc->key_size * sizeof(u8));
return r;
}
static void crypt_dtr(struct dm_target *ti)
{
struct crypt_config *cc = ti->private;
ti->private = NULL;
if (!cc)
return;
if (cc->write_thread)
kthread_stop(cc->write_thread);
if (cc->io_queue)
destroy_workqueue(cc->io_queue);
if (cc->crypt_queue)
destroy_workqueue(cc->crypt_queue);
crypt_free_tfms(cc);
if (cc->bs)
bioset_free(cc->bs);
mempool_destroy(cc->page_pool);
mempool_destroy(cc->req_pool);
mempool_destroy(cc->tag_pool);
if (cc->iv_gen_ops && cc->iv_gen_ops->dtr)
cc->iv_gen_ops->dtr(cc);
if (cc->dev)
dm_put_device(ti, cc->dev);
kzfree(cc->cipher);
kzfree(cc->cipher_string);
kzfree(cc->key_string);
kzfree(cc->cipher_auth);
kzfree(cc->authenc_key);
kzfree(cc);
}
static int crypt_ctr_ivmode(struct dm_target *ti, const char *ivmode)
{
struct crypt_config *cc = ti->private;
if (crypt_integrity_aead(cc))
cc->iv_size = crypto_aead_ivsize(any_tfm_aead(cc));
else
cc->iv_size = crypto_skcipher_ivsize(any_tfm(cc));
if (cc->iv_size)
cc->iv_size = max(cc->iv_size,
(unsigned int)(sizeof(u64) / sizeof(u8)));
else if (ivmode) {
DMWARN("Selected cipher does not support IVs");
ivmode = NULL;
}
if (ivmode == NULL)
cc->iv_gen_ops = NULL;
else if (strcmp(ivmode, "plain") == 0)
cc->iv_gen_ops = &crypt_iv_plain_ops;
else if (strcmp(ivmode, "plain64") == 0)
cc->iv_gen_ops = &crypt_iv_plain64_ops;
else if (strcmp(ivmode, "plain64be") == 0)
cc->iv_gen_ops = &crypt_iv_plain64be_ops;
else if (strcmp(ivmode, "essiv") == 0)
cc->iv_gen_ops = &crypt_iv_essiv_ops;
else if (strcmp(ivmode, "benbi") == 0)
cc->iv_gen_ops = &crypt_iv_benbi_ops;
else if (strcmp(ivmode, "null") == 0)
cc->iv_gen_ops = &crypt_iv_null_ops;
else if (strcmp(ivmode, "lmk") == 0) {
cc->iv_gen_ops = &crypt_iv_lmk_ops;
if (cc->key_size % cc->key_parts) {
cc->key_parts++;
cc->key_extra_size = cc->key_size / cc->key_parts;
}
} else if (strcmp(ivmode, "tcw") == 0) {
cc->iv_gen_ops = &crypt_iv_tcw_ops;
cc->key_parts += 2;
cc->key_extra_size = cc->iv_size + TCW_WHITENING_SIZE;
} else if (strcmp(ivmode, "random") == 0) {
cc->iv_gen_ops = &crypt_iv_random_ops;
cc->integrity_iv_size = cc->iv_size;
} else {
ti->error = "Invalid IV mode";
return -EINVAL;
}
return 0;
}
static int crypt_ctr_blkdev_cipher(struct crypt_config *cc)
{
const char *alg_name = NULL;
char *start, *end;
if (crypt_integrity_aead(cc)) {
alg_name = crypto_tfm_alg_name(crypto_aead_tfm(any_tfm_aead(cc)));
if (!alg_name)
return -EINVAL;
if (crypt_integrity_hmac(cc)) {
alg_name = strchr(alg_name, ',');
if (!alg_name)
return -EINVAL;
}
alg_name++;
} else {
alg_name = crypto_tfm_alg_name(crypto_skcipher_tfm(any_tfm(cc)));
if (!alg_name)
return -EINVAL;
}
start = strchr(alg_name, '(');
end = strchr(alg_name, ')');
if (!start && !end) {
cc->cipher = kstrdup(alg_name, GFP_KERNEL);
return cc->cipher ? 0 : -ENOMEM;
}
if (!start || !end || ++start >= end)
return -EINVAL;
cc->cipher = kzalloc(end - start + 1, GFP_KERNEL);
if (!cc->cipher)
return -ENOMEM;
strncpy(cc->cipher, start, end - start);
return 0;
}
static int crypt_ctr_auth_cipher(struct crypt_config *cc, char *cipher_api)
{
char *start, *end, *mac_alg = NULL;
struct crypto_ahash *mac;
if (!strstarts(cipher_api, "authenc("))
return 0;
start = strchr(cipher_api, '(');
end = strchr(cipher_api, ',');
if (!start || !end || ++start > end)
return -EINVAL;
mac_alg = kzalloc(end - start + 1, GFP_KERNEL);
if (!mac_alg)
return -ENOMEM;
strncpy(mac_alg, start, end - start);
mac = crypto_alloc_ahash(mac_alg, 0, 0);
kfree(mac_alg);
if (IS_ERR(mac))
return PTR_ERR(mac);
cc->key_mac_size = crypto_ahash_digestsize(mac);
crypto_free_ahash(mac);
cc->authenc_key = kmalloc(crypt_authenckey_size(cc), GFP_KERNEL);
if (!cc->authenc_key)
return -ENOMEM;
return 0;
}
static int crypt_ctr_cipher_new(struct dm_target *ti, char *cipher_in, char *key,
char **ivmode, char **ivopts)
{
struct crypt_config *cc = ti->private;
char *tmp, *cipher_api;
int ret = -EINVAL;
cc->tfms_count = 1;
tmp = &cipher_in[strlen("capi:")];
cipher_api = strsep(&tmp, "-");
*ivmode = strsep(&tmp, ":");
*ivopts = tmp;
if (*ivmode && !strcmp(*ivmode, "lmk"))
cc->tfms_count = 64;
cc->key_parts = cc->tfms_count;
ret = crypt_alloc_tfms(cc, cipher_api);
if (ret < 0) {
ti->error = "Error allocating crypto tfm";
return ret;
}
if (crypt_integrity_aead(cc)) {
ret = crypt_ctr_auth_cipher(cc, cipher_api);
if (ret < 0) {
ti->error = "Invalid AEAD cipher spec";
return -ENOMEM;
}
cc->iv_size = crypto_aead_ivsize(any_tfm_aead(cc));
} else
cc->iv_size = crypto_skcipher_ivsize(any_tfm(cc));
ret = crypt_ctr_blkdev_cipher(cc);
if (ret < 0) {
ti->error = "Cannot allocate cipher string";
return -ENOMEM;
}
return 0;
}
static int crypt_ctr_cipher_old(struct dm_target *ti, char *cipher_in, char *key,
char **ivmode, char **ivopts)
{
struct crypt_config *cc = ti->private;
char *tmp, *cipher, *chainmode, *keycount;
char *cipher_api = NULL;
int ret = -EINVAL;
char dummy;
if (strchr(cipher_in, '(') || crypt_integrity_aead(cc)) {
ti->error = "Bad cipher specification";
return -EINVAL;
}
tmp = cipher_in;
keycount = strsep(&tmp, "-");
cipher = strsep(&keycount, ":");
if (!keycount)
cc->tfms_count = 1;
else if (sscanf(keycount, "%u%c", &cc->tfms_count, &dummy) != 1 ||
!is_power_of_2(cc->tfms_count)) {
ti->error = "Bad cipher key count specification";
return -EINVAL;
}
cc->key_parts = cc->tfms_count;
cc->cipher = kstrdup(cipher, GFP_KERNEL);
if (!cc->cipher)
goto bad_mem;
chainmode = strsep(&tmp, "-");
*ivopts = strsep(&tmp, "-");
*ivmode = strsep(&*ivopts, ":");
if (tmp)
DMWARN("Ignoring unexpected additional cipher options");
if (!chainmode || (!strcmp(chainmode, "plain") && !*ivmode)) {
chainmode = "cbc";
*ivmode = "plain";
}
if (strcmp(chainmode, "ecb") && !*ivmode) {
ti->error = "IV mechanism required";
return -EINVAL;
}
cipher_api = kmalloc(CRYPTO_MAX_ALG_NAME, GFP_KERNEL);
if (!cipher_api)
goto bad_mem;
ret = snprintf(cipher_api, CRYPTO_MAX_ALG_NAME,
"%s(%s)", chainmode, cipher);
if (ret < 0) {
kfree(cipher_api);
goto bad_mem;
}
ret = crypt_alloc_tfms(cc, cipher_api);
if (ret < 0) {
ti->error = "Error allocating crypto tfm";
kfree(cipher_api);
return ret;
}
return 0;
bad_mem:
ti->error = "Cannot allocate cipher strings";
return -ENOMEM;
}
static int crypt_ctr_cipher(struct dm_target *ti, char *cipher_in, char *key)
{
struct crypt_config *cc = ti->private;
char *ivmode = NULL, *ivopts = NULL;
int ret;
cc->cipher_string = kstrdup(cipher_in, GFP_KERNEL);
if (!cc->cipher_string) {
ti->error = "Cannot allocate cipher strings";
return -ENOMEM;
}
if (strstarts(cipher_in, "capi:"))
ret = crypt_ctr_cipher_new(ti, cipher_in, key, &ivmode, &ivopts);
else
ret = crypt_ctr_cipher_old(ti, cipher_in, key, &ivmode, &ivopts);
if (ret)
return ret;
ret = crypt_ctr_ivmode(ti, ivmode);
if (ret < 0)
return ret;
ret = crypt_set_key(cc, key);
if (ret < 0) {
ti->error = "Error decoding and setting key";
return ret;
}
if (cc->iv_gen_ops && cc->iv_gen_ops->ctr) {
ret = cc->iv_gen_ops->ctr(cc, ti, ivopts);
if (ret < 0) {
ti->error = "Error creating IV";
return ret;
}
}
if (cc->iv_gen_ops && cc->iv_gen_ops->init) {
ret = cc->iv_gen_ops->init(cc);
if (ret < 0) {
ti->error = "Error initialising IV";
return ret;
}
}
return ret;
}
static int crypt_ctr_optional(struct dm_target *ti, unsigned int argc, char **argv)
{
struct crypt_config *cc = ti->private;
struct dm_arg_set as;
static struct dm_arg _args[] = {
{0, 6, "Invalid number of feature args"},
};
unsigned int opt_params, val;
const char *opt_string, *sval;
char dummy;
int ret;
as.argc = argc;
as.argv = argv;
ret = dm_read_arg_group(_args, &as, &opt_params, &ti->error);
if (ret)
return ret;
while (opt_params--) {
opt_string = dm_shift_arg(&as);
if (!opt_string) {
ti->error = "Not enough feature arguments";
return -EINVAL;
}
if (!strcasecmp(opt_string, "allow_discards"))
ti->num_discard_bios = 1;
else if (!strcasecmp(opt_string, "same_cpu_crypt"))
set_bit(DM_CRYPT_SAME_CPU, &cc->flags);
else if (!strcasecmp(opt_string, "submit_from_crypt_cpus"))
set_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags);
else if (sscanf(opt_string, "integrity:%u:", &val) == 1) {
if (val == 0 || val > MAX_TAG_SIZE) {
ti->error = "Invalid integrity arguments";
return -EINVAL;
}
cc->on_disk_tag_size = val;
sval = strchr(opt_string + strlen("integrity:"), ':') + 1;
if (!strcasecmp(sval, "aead")) {
set_bit(CRYPT_MODE_INTEGRITY_AEAD, &cc->cipher_flags);
} else if (strcasecmp(sval, "none")) {
ti->error = "Unknown integrity profile";
return -EINVAL;
}
cc->cipher_auth = kstrdup(sval, GFP_KERNEL);
if (!cc->cipher_auth)
return -ENOMEM;
} else if (sscanf(opt_string, "sector_size:%hu%c", &cc->sector_size, &dummy) == 1) {
if (cc->sector_size < (1 << SECTOR_SHIFT) ||
cc->sector_size > 4096 ||
(cc->sector_size & (cc->sector_size - 1))) {
ti->error = "Invalid feature value for sector_size";
return -EINVAL;
}
cc->sector_shift = __ffs(cc->sector_size) - SECTOR_SHIFT;
} else if (!strcasecmp(opt_string, "iv_large_sectors"))
set_bit(CRYPT_IV_LARGE_SECTORS, &cc->cipher_flags);
else {
ti->error = "Invalid feature arguments";
return -EINVAL;
}
}
return 0;
}
static int crypt_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
struct crypt_config *cc;
int key_size;
unsigned int align_mask;
unsigned long long tmpll;
int ret;
size_t iv_size_padding, additional_req_size;
char dummy;
if (argc < 5) {
ti->error = "Not enough arguments";
return -EINVAL;
}
key_size = get_key_size(&argv[1]);
if (key_size < 0) {
ti->error = "Cannot parse key size";
return -EINVAL;
}
cc = kzalloc(sizeof(*cc) + key_size * sizeof(u8), GFP_KERNEL);
if (!cc) {
ti->error = "Cannot allocate encryption context";
return -ENOMEM;
}
cc->key_size = key_size;
cc->sector_size = (1 << SECTOR_SHIFT);
cc->sector_shift = 0;
ti->private = cc;
if (argc > 5) {
ret = crypt_ctr_optional(ti, argc - 5, &argv[5]);
if (ret)
goto bad;
}
ret = crypt_ctr_cipher(ti, argv[0], argv[1]);
if (ret < 0)
goto bad;
if (crypt_integrity_aead(cc)) {
cc->dmreq_start = sizeof(struct aead_request);
cc->dmreq_start += crypto_aead_reqsize(any_tfm_aead(cc));
align_mask = crypto_aead_alignmask(any_tfm_aead(cc));
} else {
cc->dmreq_start = sizeof(struct skcipher_request);
cc->dmreq_start += crypto_skcipher_reqsize(any_tfm(cc));
align_mask = crypto_skcipher_alignmask(any_tfm(cc));
}
cc->dmreq_start = ALIGN(cc->dmreq_start, __alignof__(struct dm_crypt_request));
if (align_mask < CRYPTO_MINALIGN) {
iv_size_padding = -(cc->dmreq_start + sizeof(struct dm_crypt_request))
& align_mask;
} else {
iv_size_padding = align_mask;
}
ret = -ENOMEM;
additional_req_size = sizeof(struct dm_crypt_request) +
iv_size_padding + cc->iv_size +
cc->iv_size +
sizeof(uint64_t) +
sizeof(unsigned int);
cc->req_pool = mempool_create_kmalloc_pool(MIN_IOS, cc->dmreq_start + additional_req_size);
if (!cc->req_pool) {
ti->error = "Cannot allocate crypt request mempool";
goto bad;
}
cc->per_bio_data_size = ti->per_io_data_size =
ALIGN(sizeof(struct dm_crypt_io) + cc->dmreq_start + additional_req_size,
ARCH_KMALLOC_MINALIGN);
cc->page_pool = mempool_create_page_pool(BIO_MAX_PAGES, 0);
if (!cc->page_pool) {
ti->error = "Cannot allocate page mempool";
goto bad;
}
cc->bs = bioset_create(MIN_IOS, 0, (BIOSET_NEED_BVECS |
BIOSET_NEED_RESCUER));
if (!cc->bs) {
ti->error = "Cannot allocate crypt bioset";
goto bad;
}
mutex_init(&cc->bio_alloc_lock);
ret = -EINVAL;
if ((sscanf(argv[2], "%llu%c", &tmpll, &dummy) != 1) ||
(tmpll & ((cc->sector_size >> SECTOR_SHIFT) - 1))) {
ti->error = "Invalid iv_offset sector";
goto bad;
}
cc->iv_offset = tmpll;
ret = dm_get_device(ti, argv[3], dm_table_get_mode(ti->table), &cc->dev);
if (ret) {
ti->error = "Device lookup failed";
goto bad;
}
ret = -EINVAL;
if (sscanf(argv[4], "%llu%c", &tmpll, &dummy) != 1) {
ti->error = "Invalid device sector";
goto bad;
}
cc->start = tmpll;
if (crypt_integrity_aead(cc) || cc->integrity_iv_size) {
ret = crypt_integrity_ctr(cc, ti);
if (ret)
goto bad;
cc->tag_pool_max_sectors = POOL_ENTRY_SIZE / cc->on_disk_tag_size;
if (!cc->tag_pool_max_sectors)
cc->tag_pool_max_sectors = 1;
cc->tag_pool = mempool_create_kmalloc_pool(MIN_IOS,
cc->tag_pool_max_sectors * cc->on_disk_tag_size);
if (!cc->tag_pool) {
ti->error = "Cannot allocate integrity tags mempool";
goto bad;
}
cc->tag_pool_max_sectors <<= cc->sector_shift;
}
ret = -ENOMEM;
cc->io_queue = alloc_workqueue("kcryptd_io", WQ_HIGHPRI | WQ_CPU_INTENSIVE | WQ_MEM_RECLAIM, 1);
if (!cc->io_queue) {
ti->error = "Couldn't create kcryptd io queue";
goto bad;
}
if (test_bit(DM_CRYPT_SAME_CPU, &cc->flags))
cc->crypt_queue = alloc_workqueue("kcryptd", WQ_HIGHPRI | WQ_CPU_INTENSIVE | WQ_MEM_RECLAIM, 1);
else
cc->crypt_queue = alloc_workqueue("kcryptd",
WQ_HIGHPRI | WQ_CPU_INTENSIVE | WQ_MEM_RECLAIM | WQ_UNBOUND,
num_online_cpus());
if (!cc->crypt_queue) {
ti->error = "Couldn't create kcryptd queue";
goto bad;
}
init_waitqueue_head(&cc->write_thread_wait);
cc->write_tree = RB_ROOT;
cc->write_thread = kthread_create(dmcrypt_write, cc, "dmcrypt_write");
if (IS_ERR(cc->write_thread)) {
ret = PTR_ERR(cc->write_thread);
cc->write_thread = NULL;
ti->error = "Couldn't spawn write thread";
goto bad;
}
wake_up_process(cc->write_thread);
ti->num_flush_bios = 1;
return 0;
bad:
crypt_dtr(ti);
return ret;
}
static int crypt_map(struct dm_target *ti, struct bio *bio)
{
struct dm_crypt_io *io;
struct crypt_config *cc = ti->private;
if (unlikely(bio->bi_opf & REQ_PREFLUSH ||
bio_op(bio) == REQ_OP_DISCARD)) {
bio->bi_bdev = cc->dev->bdev;
if (bio_sectors(bio))
bio->bi_iter.bi_sector = cc->start +
dm_target_offset(ti, bio->bi_iter.bi_sector);
return DM_MAPIO_REMAPPED;
}
if (unlikely(bio->bi_iter.bi_size > (BIO_MAX_PAGES << PAGE_SHIFT)) &&
(bio_data_dir(bio) == WRITE || cc->on_disk_tag_size))
dm_accept_partial_bio(bio, ((BIO_MAX_PAGES << PAGE_SHIFT) >> SECTOR_SHIFT));
if (unlikely((bio->bi_iter.bi_sector & ((cc->sector_size >> SECTOR_SHIFT) - 1)) != 0))
return DM_MAPIO_KILL;
if (unlikely(bio->bi_iter.bi_size & (cc->sector_size - 1)))
return DM_MAPIO_KILL;
io = dm_per_bio_data(bio, cc->per_bio_data_size);
crypt_io_init(io, cc, bio, dm_target_offset(ti, bio->bi_iter.bi_sector));
if (cc->on_disk_tag_size) {
unsigned tag_len = cc->on_disk_tag_size * (bio_sectors(bio) >> cc->sector_shift);
if (unlikely(tag_len > KMALLOC_MAX_SIZE) ||
unlikely(!(io->integrity_metadata = kmalloc(tag_len,
GFP_NOIO | __GFP_NORETRY | __GFP_NOMEMALLOC | __GFP_NOWARN)))) {
if (bio_sectors(bio) > cc->tag_pool_max_sectors)
dm_accept_partial_bio(bio, cc->tag_pool_max_sectors);
io->integrity_metadata = mempool_alloc(cc->tag_pool, GFP_NOIO);
io->integrity_metadata_from_pool = true;
}
}
if (crypt_integrity_aead(cc))
io->ctx.r.req_aead = (struct aead_request *)(io + 1);
else
io->ctx.r.req = (struct skcipher_request *)(io + 1);
if (bio_data_dir(io->base_bio) == READ) {
if (kcryptd_io_read(io, GFP_NOWAIT))
kcryptd_queue_read(io);
} else
kcryptd_queue_crypt(io);
return DM_MAPIO_SUBMITTED;
}
static void crypt_status(struct dm_target *ti, status_type_t type,
unsigned status_flags, char *result, unsigned maxlen)
{
struct crypt_config *cc = ti->private;
unsigned i, sz = 0;
int num_feature_args = 0;
switch (type) {
case STATUSTYPE_INFO:
result[0] = '\0';
break;
case STATUSTYPE_TABLE:
DMEMIT("%s ", cc->cipher_string);
if (cc->key_size > 0) {
if (cc->key_string)
DMEMIT(":%u:%s", cc->key_size, cc->key_string);
else
for (i = 0; i < cc->key_size; i++)
DMEMIT("%02x", cc->key[i]);
} else
DMEMIT("-");
DMEMIT(" %llu %s %llu", (unsigned long long)cc->iv_offset,
cc->dev->name, (unsigned long long)cc->start);
num_feature_args += !!ti->num_discard_bios;
num_feature_args += test_bit(DM_CRYPT_SAME_CPU, &cc->flags);
num_feature_args += test_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags);
num_feature_args += cc->sector_size != (1 << SECTOR_SHIFT);
num_feature_args += test_bit(CRYPT_IV_LARGE_SECTORS, &cc->cipher_flags);
if (cc->on_disk_tag_size)
num_feature_args++;
if (num_feature_args) {
DMEMIT(" %d", num_feature_args);
if (ti->num_discard_bios)
DMEMIT(" allow_discards");
if (test_bit(DM_CRYPT_SAME_CPU, &cc->flags))
DMEMIT(" same_cpu_crypt");
if (test_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags))
DMEMIT(" submit_from_crypt_cpus");
if (cc->on_disk_tag_size)
DMEMIT(" integrity:%u:%s", cc->on_disk_tag_size, cc->cipher_auth);
if (cc->sector_size != (1 << SECTOR_SHIFT))
DMEMIT(" sector_size:%d", cc->sector_size);
if (test_bit(CRYPT_IV_LARGE_SECTORS, &cc->cipher_flags))
DMEMIT(" iv_large_sectors");
}
break;
}
}
static void crypt_postsuspend(struct dm_target *ti)
{
struct crypt_config *cc = ti->private;
set_bit(DM_CRYPT_SUSPENDED, &cc->flags);
}
static int crypt_preresume(struct dm_target *ti)
{
struct crypt_config *cc = ti->private;
if (!test_bit(DM_CRYPT_KEY_VALID, &cc->flags)) {
DMERR("aborting resume - crypt key is not set.");
return -EAGAIN;
}
return 0;
}
static void crypt_resume(struct dm_target *ti)
{
struct crypt_config *cc = ti->private;
clear_bit(DM_CRYPT_SUSPENDED, &cc->flags);
}
static int crypt_message(struct dm_target *ti, unsigned argc, char **argv)
{
struct crypt_config *cc = ti->private;
int key_size, ret = -EINVAL;
if (argc < 2)
goto error;
if (!strcasecmp(argv[0], "key")) {
if (!test_bit(DM_CRYPT_SUSPENDED, &cc->flags)) {
DMWARN("not suspended during key manipulation.");
return -EINVAL;
}
if (argc == 3 && !strcasecmp(argv[1], "set")) {
key_size = get_key_size(&argv[2]);
if (key_size < 0 || cc->key_size != key_size) {
memset(argv[2], '0', strlen(argv[2]));
return -EINVAL;
}
ret = crypt_set_key(cc, argv[2]);
if (ret)
return ret;
if (cc->iv_gen_ops && cc->iv_gen_ops->init)
ret = cc->iv_gen_ops->init(cc);
return ret;
}
if (argc == 2 && !strcasecmp(argv[1], "wipe")) {
if (cc->iv_gen_ops && cc->iv_gen_ops->wipe) {
ret = cc->iv_gen_ops->wipe(cc);
if (ret)
return ret;
}
return crypt_wipe_key(cc);
}
}
error:
DMWARN("unrecognised message received.");
return -EINVAL;
}
static int crypt_iterate_devices(struct dm_target *ti,
iterate_devices_callout_fn fn, void *data)
{
struct crypt_config *cc = ti->private;
return fn(ti, cc->dev, cc->start, ti->len, data);
}
static void crypt_io_hints(struct dm_target *ti, struct queue_limits *limits)
{
struct crypt_config *cc = ti->private;
limits->max_segment_size = PAGE_SIZE;
if (cc->sector_size != (1 << SECTOR_SHIFT)) {
limits->logical_block_size = cc->sector_size;
limits->physical_block_size = cc->sector_size;
blk_limits_io_min(limits, cc->sector_size);
}
}
static int __init dm_crypt_init(void)
{
int r;
r = dm_register_target(&crypt_target);
if (r < 0)
DMERR("register failed %d", r);
return r;
}
static void __exit dm_crypt_exit(void)
{
dm_unregister_target(&crypt_target);
}
