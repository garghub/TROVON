static struct crypto_ablkcipher *any_tfm(struct crypt_config *cc)
{
return cc->tfms[0];
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
static int crypt_iv_essiv_init(struct crypt_config *cc)
{
struct iv_essiv_private *essiv = &cc->iv_gen_private.essiv;
struct hash_desc desc;
struct scatterlist sg;
struct crypto_cipher *essiv_tfm;
int err;
sg_init_one(&sg, cc->key, cc->key_size);
desc.tfm = essiv->hash_tfm;
desc.flags = CRYPTO_TFM_REQ_MAY_SLEEP;
err = crypto_hash_digest(&desc, &sg, cc->key_size, essiv->salt);
if (err)
return err;
essiv_tfm = cc->iv_private;
err = crypto_cipher_setkey(essiv_tfm, essiv->salt,
crypto_hash_digestsize(essiv->hash_tfm));
if (err)
return err;
return 0;
}
static int crypt_iv_essiv_wipe(struct crypt_config *cc)
{
struct iv_essiv_private *essiv = &cc->iv_gen_private.essiv;
unsigned salt_size = crypto_hash_digestsize(essiv->hash_tfm);
struct crypto_cipher *essiv_tfm;
int r, err = 0;
memset(essiv->salt, 0, salt_size);
essiv_tfm = cc->iv_private;
r = crypto_cipher_setkey(essiv_tfm, essiv->salt, salt_size);
if (r)
err = r;
return err;
}
static struct crypto_cipher *setup_essiv_cpu(struct crypt_config *cc,
struct dm_target *ti,
u8 *salt, unsigned saltsize)
{
struct crypto_cipher *essiv_tfm;
int err;
essiv_tfm = crypto_alloc_cipher(cc->cipher, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(essiv_tfm)) {
ti->error = "Error allocating crypto tfm for ESSIV";
return essiv_tfm;
}
if (crypto_cipher_blocksize(essiv_tfm) !=
crypto_ablkcipher_ivsize(any_tfm(cc))) {
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
crypto_free_hash(essiv->hash_tfm);
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
struct crypto_hash *hash_tfm = NULL;
u8 *salt = NULL;
int err;
if (!opts) {
ti->error = "Digest algorithm missing for ESSIV mode";
return -EINVAL;
}
hash_tfm = crypto_alloc_hash(opts, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(hash_tfm)) {
ti->error = "Error initializing ESSIV hash";
err = PTR_ERR(hash_tfm);
goto bad;
}
salt = kzalloc(crypto_hash_digestsize(hash_tfm), GFP_KERNEL);
if (!salt) {
ti->error = "Error kmallocing salt storage in ESSIV";
err = -ENOMEM;
goto bad;
}
cc->iv_gen_private.essiv.salt = salt;
cc->iv_gen_private.essiv.hash_tfm = hash_tfm;
essiv_tfm = setup_essiv_cpu(cc, ti, salt,
crypto_hash_digestsize(hash_tfm));
if (IS_ERR(essiv_tfm)) {
crypt_iv_essiv_dtr(cc);
return PTR_ERR(essiv_tfm);
}
cc->iv_private = essiv_tfm;
return 0;
bad:
if (hash_tfm && !IS_ERR(hash_tfm))
crypto_free_hash(hash_tfm);
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
unsigned bs = crypto_ablkcipher_blocksize(any_tfm(cc));
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
u8 *src;
int r = 0;
if (bio_data_dir(dmreq->ctx->bio_in) == WRITE) {
src = kmap_atomic(sg_page(&dmreq->sg_in));
r = crypt_iv_lmk_one(cc, iv, dmreq, src + dmreq->sg_in.offset);
kunmap_atomic(src);
} else
memset(iv, 0, cc->iv_size);
return r;
}
static int crypt_iv_lmk_post(struct crypt_config *cc, u8 *iv,
struct dm_crypt_request *dmreq)
{
u8 *dst;
int r;
if (bio_data_dir(dmreq->ctx->bio_in) == WRITE)
return 0;
dst = kmap_atomic(sg_page(&dmreq->sg_out));
r = crypt_iv_lmk_one(cc, iv, dmreq, dst + dmreq->sg_out.offset);
if (!r)
crypto_xor(dst + dmreq->sg_out.offset, iv, cc->iv_size);
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
u64 sector = cpu_to_le64((u64)dmreq->iv_sector);
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
struct iv_tcw_private *tcw = &cc->iv_gen_private.tcw;
u64 sector = cpu_to_le64((u64)dmreq->iv_sector);
u8 *src;
int r = 0;
if (bio_data_dir(dmreq->ctx->bio_in) != WRITE) {
src = kmap_atomic(sg_page(&dmreq->sg_in));
r = crypt_iv_tcw_whitening(cc, dmreq, src + dmreq->sg_in.offset);
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
u8 *dst;
int r;
if (bio_data_dir(dmreq->ctx->bio_in) != WRITE)
return 0;
dst = kmap_atomic(sg_page(&dmreq->sg_out));
r = crypt_iv_tcw_whitening(cc, dmreq, dst + dmreq->sg_out.offset);
kunmap_atomic(dst);
return r;
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
struct ablkcipher_request *req)
{
return (struct dm_crypt_request *)((char *)req + cc->dmreq_start);
}
static struct ablkcipher_request *req_of_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
return (struct ablkcipher_request *)((char *)dmreq - cc->dmreq_start);
}
static u8 *iv_of_dmreq(struct crypt_config *cc,
struct dm_crypt_request *dmreq)
{
return (u8 *)ALIGN((unsigned long)(dmreq + 1),
crypto_ablkcipher_alignmask(any_tfm(cc)) + 1);
}
static int crypt_convert_block(struct crypt_config *cc,
struct convert_context *ctx,
struct ablkcipher_request *req)
{
struct bio_vec bv_in = bio_iter_iovec(ctx->bio_in, ctx->iter_in);
struct bio_vec bv_out = bio_iter_iovec(ctx->bio_out, ctx->iter_out);
struct dm_crypt_request *dmreq;
u8 *iv;
int r;
dmreq = dmreq_of_req(cc, req);
iv = iv_of_dmreq(cc, dmreq);
dmreq->iv_sector = ctx->cc_sector;
dmreq->ctx = ctx;
sg_init_table(&dmreq->sg_in, 1);
sg_set_page(&dmreq->sg_in, bv_in.bv_page, 1 << SECTOR_SHIFT,
bv_in.bv_offset);
sg_init_table(&dmreq->sg_out, 1);
sg_set_page(&dmreq->sg_out, bv_out.bv_page, 1 << SECTOR_SHIFT,
bv_out.bv_offset);
bio_advance_iter(ctx->bio_in, &ctx->iter_in, 1 << SECTOR_SHIFT);
bio_advance_iter(ctx->bio_out, &ctx->iter_out, 1 << SECTOR_SHIFT);
if (cc->iv_gen_ops) {
r = cc->iv_gen_ops->generator(cc, iv, dmreq);
if (r < 0)
return r;
}
ablkcipher_request_set_crypt(req, &dmreq->sg_in, &dmreq->sg_out,
1 << SECTOR_SHIFT, iv);
if (bio_data_dir(ctx->bio_in) == WRITE)
r = crypto_ablkcipher_encrypt(req);
else
r = crypto_ablkcipher_decrypt(req);
if (!r && cc->iv_gen_ops && cc->iv_gen_ops->post)
r = cc->iv_gen_ops->post(cc, iv, dmreq);
return r;
}
static void crypt_alloc_req(struct crypt_config *cc,
struct convert_context *ctx)
{
unsigned key_index = ctx->cc_sector & (cc->tfms_count - 1);
if (!ctx->req)
ctx->req = mempool_alloc(cc->req_pool, GFP_NOIO);
ablkcipher_request_set_tfm(ctx->req, cc->tfms[key_index]);
ablkcipher_request_set_callback(ctx->req,
CRYPTO_TFM_REQ_MAY_BACKLOG | CRYPTO_TFM_REQ_MAY_SLEEP,
kcryptd_async_done, dmreq_of_req(cc, ctx->req));
}
static void crypt_free_req(struct crypt_config *cc,
struct ablkcipher_request *req, struct bio *base_bio)
{
struct dm_crypt_io *io = dm_per_bio_data(base_bio, cc->per_bio_data_size);
if ((struct ablkcipher_request *)(io + 1) != req)
mempool_free(req, cc->req_pool);
}
static int crypt_convert(struct crypt_config *cc,
struct convert_context *ctx)
{
int r;
atomic_set(&ctx->cc_pending, 1);
while (ctx->iter_in.bi_size && ctx->iter_out.bi_size) {
crypt_alloc_req(cc, ctx);
atomic_inc(&ctx->cc_pending);
r = crypt_convert_block(cc, ctx, ctx->req);
switch (r) {
case -EBUSY:
wait_for_completion(&ctx->restart);
reinit_completion(&ctx->restart);
case -EINPROGRESS:
ctx->req = NULL;
ctx->cc_sector++;
continue;
case 0:
atomic_dec(&ctx->cc_pending);
ctx->cc_sector++;
cond_resched();
continue;
default:
atomic_dec(&ctx->cc_pending);
return r;
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
struct bio_vec *bvec;
retry:
if (unlikely(gfp_mask & __GFP_WAIT))
mutex_lock(&cc->bio_alloc_lock);
clone = bio_alloc_bioset(GFP_NOIO, nr_iovecs, cc->bs);
if (!clone)
goto return_clone;
clone_init(io, clone);
remaining_size = size;
for (i = 0; i < nr_iovecs; i++) {
page = mempool_alloc(cc->page_pool, gfp_mask);
if (!page) {
crypt_free_buffer_pages(cc, clone);
bio_put(clone);
gfp_mask |= __GFP_WAIT;
goto retry;
}
len = (remaining_size > PAGE_SIZE) ? PAGE_SIZE : remaining_size;
bvec = &clone->bi_io_vec[clone->bi_vcnt++];
bvec->bv_page = page;
bvec->bv_len = len;
bvec->bv_offset = 0;
clone->bi_iter.bi_size += len;
remaining_size -= len;
}
return_clone:
if (unlikely(gfp_mask & __GFP_WAIT))
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
io->ctx.req = NULL;
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
int error = io->error;
if (!atomic_dec_and_test(&io->io_pending))
return;
if (io->ctx.req)
crypt_free_req(cc, io->ctx.req, base_bio);
base_bio->bi_error = error;
bio_endio(base_bio);
}
static void crypt_endio(struct bio *clone)
{
struct dm_crypt_io *io = clone->bi_private;
struct crypt_config *cc = io->cc;
unsigned rw = bio_data_dir(clone);
int error;
if (rw == WRITE)
crypt_free_buffer_pages(cc, clone);
error = clone->bi_error;
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
clone->bi_rw = io->base_bio->bi_rw;
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
generic_make_request(clone);
return 0;
}
static void kcryptd_io_read_work(struct work_struct *work)
{
struct dm_crypt_io *io = container_of(work, struct dm_crypt_io, work);
crypt_inc_pending(io);
if (kcryptd_io_read(io, GFP_NOIO))
io->error = -ENOMEM;
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
__set_current_state(TASK_INTERRUPTIBLE);
__add_wait_queue(&cc->write_thread_wait, &wait);
spin_unlock_irq(&cc->write_thread_wait.lock);
if (unlikely(kthread_should_stop())) {
set_task_state(current, TASK_RUNNING);
remove_wait_queue(&cc->write_thread_wait, &wait);
break;
}
schedule();
set_task_state(current, TASK_RUNNING);
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
if (unlikely(io->error < 0)) {
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
int r;
crypt_inc_pending(io);
crypt_convert_init(cc, &io->ctx, NULL, io->base_bio, sector);
clone = crypt_alloc_buffer(io, io->base_bio->bi_iter.bi_size);
if (unlikely(!clone)) {
io->error = -EIO;
goto dec;
}
io->ctx.bio_out = clone;
io->ctx.iter_out = clone->bi_iter;
sector += bio_sectors(clone);
crypt_inc_pending(io);
r = crypt_convert(cc, &io->ctx);
if (r)
io->error = -EIO;
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
int r = 0;
crypt_inc_pending(io);
crypt_convert_init(cc, &io->ctx, io->base_bio, io->base_bio,
io->sector);
r = crypt_convert(cc, &io->ctx);
if (r < 0)
io->error = -EIO;
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
error = cc->iv_gen_ops->post(cc, iv_of_dmreq(cc, dmreq), dmreq);
if (error < 0)
io->error = -EIO;
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
static int crypt_decode_key(u8 *key, char *hex, unsigned int size)
{
char buffer[3];
unsigned int i;
buffer[2] = '\0';
for (i = 0; i < size; i++) {
buffer[0] = *hex++;
buffer[1] = *hex++;
if (kstrtou8(buffer, 16, &key[i]))
return -EINVAL;
}
if (*hex != '\0')
return -EINVAL;
return 0;
}
static void crypt_free_tfms(struct crypt_config *cc)
{
unsigned i;
if (!cc->tfms)
return;
for (i = 0; i < cc->tfms_count; i++)
if (cc->tfms[i] && !IS_ERR(cc->tfms[i])) {
crypto_free_ablkcipher(cc->tfms[i]);
cc->tfms[i] = NULL;
}
kfree(cc->tfms);
cc->tfms = NULL;
}
static int crypt_alloc_tfms(struct crypt_config *cc, char *ciphermode)
{
unsigned i;
int err;
cc->tfms = kmalloc(cc->tfms_count * sizeof(struct crypto_ablkcipher *),
GFP_KERNEL);
if (!cc->tfms)
return -ENOMEM;
for (i = 0; i < cc->tfms_count; i++) {
cc->tfms[i] = crypto_alloc_ablkcipher(ciphermode, 0, 0);
if (IS_ERR(cc->tfms[i])) {
err = PTR_ERR(cc->tfms[i]);
crypt_free_tfms(cc);
return err;
}
}
return 0;
}
static int crypt_setkey_allcpus(struct crypt_config *cc)
{
unsigned subkey_size;
int err = 0, i, r;
subkey_size = (cc->key_size - cc->key_extra_size) >> ilog2(cc->tfms_count);
for (i = 0; i < cc->tfms_count; i++) {
r = crypto_ablkcipher_setkey(cc->tfms[i],
cc->key + (i * subkey_size),
subkey_size);
if (r)
err = r;
}
return err;
}
static int crypt_set_key(struct crypt_config *cc, char *key)
{
int r = -EINVAL;
int key_string_len = strlen(key);
if (cc->key_size != (key_string_len >> 1))
goto out;
if (!cc->key_size && strcmp(key, "-"))
goto out;
if (cc->key_size && crypt_decode_key(cc->key, key, cc->key_size) < 0)
goto out;
set_bit(DM_CRYPT_KEY_VALID, &cc->flags);
r = crypt_setkey_allcpus(cc);
out:
memset(key, '0', key_string_len);
return r;
}
static int crypt_wipe_key(struct crypt_config *cc)
{
clear_bit(DM_CRYPT_KEY_VALID, &cc->flags);
memset(&cc->key, 0, cc->key_size * sizeof(u8));
return crypt_setkey_allcpus(cc);
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
if (cc->page_pool)
mempool_destroy(cc->page_pool);
if (cc->req_pool)
mempool_destroy(cc->req_pool);
if (cc->iv_gen_ops && cc->iv_gen_ops->dtr)
cc->iv_gen_ops->dtr(cc);
if (cc->dev)
dm_put_device(ti, cc->dev);
kzfree(cc->cipher);
kzfree(cc->cipher_string);
kzfree(cc);
}
static int crypt_ctr_cipher(struct dm_target *ti,
char *cipher_in, char *key)
{
struct crypt_config *cc = ti->private;
char *tmp, *cipher, *chainmode, *ivmode, *ivopts, *keycount;
char *cipher_api = NULL;
int ret = -EINVAL;
char dummy;
if (strchr(cipher_in, '(')) {
ti->error = "Bad cipher specification";
return -EINVAL;
}
cc->cipher_string = kstrdup(cipher_in, GFP_KERNEL);
if (!cc->cipher_string)
goto bad_mem;
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
cc->key_extra_size = 0;
cc->cipher = kstrdup(cipher, GFP_KERNEL);
if (!cc->cipher)
goto bad_mem;
chainmode = strsep(&tmp, "-");
ivopts = strsep(&tmp, "-");
ivmode = strsep(&ivopts, ":");
if (tmp)
DMWARN("Ignoring unexpected additional cipher options");
if (!chainmode || (!strcmp(chainmode, "plain") && !ivmode)) {
chainmode = "cbc";
ivmode = "plain";
}
if (strcmp(chainmode, "ecb") && !ivmode) {
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
goto bad;
}
cc->iv_size = crypto_ablkcipher_ivsize(any_tfm(cc));
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
} else {
ret = -EINVAL;
ti->error = "Invalid IV mode";
goto bad;
}
ret = crypt_set_key(cc, key);
if (ret < 0) {
ti->error = "Error decoding and setting key";
goto bad;
}
if (cc->iv_gen_ops && cc->iv_gen_ops->ctr) {
ret = cc->iv_gen_ops->ctr(cc, ti, ivopts);
if (ret < 0) {
ti->error = "Error creating IV";
goto bad;
}
}
if (cc->iv_gen_ops && cc->iv_gen_ops->init) {
ret = cc->iv_gen_ops->init(cc);
if (ret < 0) {
ti->error = "Error initialising IV";
goto bad;
}
}
ret = 0;
bad:
kfree(cipher_api);
return ret;
bad_mem:
ti->error = "Cannot allocate cipher strings";
return -ENOMEM;
}
static int crypt_ctr(struct dm_target *ti, unsigned int argc, char **argv)
{
struct crypt_config *cc;
unsigned int key_size, opt_params;
unsigned long long tmpll;
int ret;
size_t iv_size_padding;
struct dm_arg_set as;
const char *opt_string;
char dummy;
static struct dm_arg _args[] = {
{0, 3, "Invalid number of feature args"},
};
if (argc < 5) {
ti->error = "Not enough arguments";
return -EINVAL;
}
key_size = strlen(argv[1]) >> 1;
cc = kzalloc(sizeof(*cc) + key_size * sizeof(u8), GFP_KERNEL);
if (!cc) {
ti->error = "Cannot allocate encryption context";
return -ENOMEM;
}
cc->key_size = key_size;
ti->private = cc;
ret = crypt_ctr_cipher(ti, argv[0], argv[1]);
if (ret < 0)
goto bad;
cc->dmreq_start = sizeof(struct ablkcipher_request);
cc->dmreq_start += crypto_ablkcipher_reqsize(any_tfm(cc));
cc->dmreq_start = ALIGN(cc->dmreq_start, __alignof__(struct dm_crypt_request));
if (crypto_ablkcipher_alignmask(any_tfm(cc)) < CRYPTO_MINALIGN) {
iv_size_padding = -(cc->dmreq_start + sizeof(struct dm_crypt_request))
& crypto_ablkcipher_alignmask(any_tfm(cc));
} else {
iv_size_padding = crypto_ablkcipher_alignmask(any_tfm(cc));
}
ret = -ENOMEM;
cc->req_pool = mempool_create_kmalloc_pool(MIN_IOS, cc->dmreq_start +
sizeof(struct dm_crypt_request) + iv_size_padding + cc->iv_size);
if (!cc->req_pool) {
ti->error = "Cannot allocate crypt request mempool";
goto bad;
}
cc->per_bio_data_size = ti->per_bio_data_size =
ALIGN(sizeof(struct dm_crypt_io) + cc->dmreq_start +
sizeof(struct dm_crypt_request) + iv_size_padding + cc->iv_size,
ARCH_KMALLOC_MINALIGN);
cc->page_pool = mempool_create_page_pool(BIO_MAX_PAGES, 0);
if (!cc->page_pool) {
ti->error = "Cannot allocate page mempool";
goto bad;
}
cc->bs = bioset_create(MIN_IOS, 0);
if (!cc->bs) {
ti->error = "Cannot allocate crypt bioset";
goto bad;
}
mutex_init(&cc->bio_alloc_lock);
ret = -EINVAL;
if (sscanf(argv[2], "%llu%c", &tmpll, &dummy) != 1) {
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
argv += 5;
argc -= 5;
if (argc) {
as.argc = argc;
as.argv = argv;
ret = dm_read_arg_group(_args, &as, &opt_params, &ti->error);
if (ret)
goto bad;
ret = -EINVAL;
while (opt_params--) {
opt_string = dm_shift_arg(&as);
if (!opt_string) {
ti->error = "Not enough feature arguments";
goto bad;
}
if (!strcasecmp(opt_string, "allow_discards"))
ti->num_discard_bios = 1;
else if (!strcasecmp(opt_string, "same_cpu_crypt"))
set_bit(DM_CRYPT_SAME_CPU, &cc->flags);
else if (!strcasecmp(opt_string, "submit_from_crypt_cpus"))
set_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags);
else {
ti->error = "Invalid feature arguments";
goto bad;
}
}
}
ret = -ENOMEM;
cc->io_queue = alloc_workqueue("kcryptd_io", WQ_MEM_RECLAIM, 1);
if (!cc->io_queue) {
ti->error = "Couldn't create kcryptd io queue";
goto bad;
}
if (test_bit(DM_CRYPT_SAME_CPU, &cc->flags))
cc->crypt_queue = alloc_workqueue("kcryptd", WQ_CPU_INTENSIVE | WQ_MEM_RECLAIM, 1);
else
cc->crypt_queue = alloc_workqueue("kcryptd", WQ_CPU_INTENSIVE | WQ_MEM_RECLAIM | WQ_UNBOUND,
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
ti->discard_zeroes_data_unsupported = true;
return 0;
bad:
crypt_dtr(ti);
return ret;
}
static int crypt_map(struct dm_target *ti, struct bio *bio)
{
struct dm_crypt_io *io;
struct crypt_config *cc = ti->private;
if (unlikely(bio->bi_rw & (REQ_FLUSH | REQ_DISCARD))) {
bio->bi_bdev = cc->dev->bdev;
if (bio_sectors(bio))
bio->bi_iter.bi_sector = cc->start +
dm_target_offset(ti, bio->bi_iter.bi_sector);
return DM_MAPIO_REMAPPED;
}
io = dm_per_bio_data(bio, cc->per_bio_data_size);
crypt_io_init(io, cc, bio, dm_target_offset(ti, bio->bi_iter.bi_sector));
io->ctx.req = (struct ablkcipher_request *)(io + 1);
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
if (cc->key_size > 0)
for (i = 0; i < cc->key_size; i++)
DMEMIT("%02x", cc->key[i]);
else
DMEMIT("-");
DMEMIT(" %llu %s %llu", (unsigned long long)cc->iv_offset,
cc->dev->name, (unsigned long long)cc->start);
num_feature_args += !!ti->num_discard_bios;
num_feature_args += test_bit(DM_CRYPT_SAME_CPU, &cc->flags);
num_feature_args += test_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags);
if (num_feature_args) {
DMEMIT(" %d", num_feature_args);
if (ti->num_discard_bios)
DMEMIT(" allow_discards");
if (test_bit(DM_CRYPT_SAME_CPU, &cc->flags))
DMEMIT(" same_cpu_crypt");
if (test_bit(DM_CRYPT_NO_OFFLOAD, &cc->flags))
DMEMIT(" submit_from_crypt_cpus");
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
int ret = -EINVAL;
if (argc < 2)
goto error;
if (!strcasecmp(argv[0], "key")) {
if (!test_bit(DM_CRYPT_SUSPENDED, &cc->flags)) {
DMWARN("not suspended during key manipulation.");
return -EINVAL;
}
if (argc == 3 && !strcasecmp(argv[1], "set")) {
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
limits->max_segment_size = PAGE_SIZE;
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
