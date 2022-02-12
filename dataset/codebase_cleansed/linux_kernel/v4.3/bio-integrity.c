struct bio_integrity_payload *bio_integrity_alloc(struct bio *bio,
gfp_t gfp_mask,
unsigned int nr_vecs)
{
struct bio_integrity_payload *bip;
struct bio_set *bs = bio->bi_pool;
unsigned long idx = BIO_POOL_NONE;
unsigned inline_vecs;
if (!bs || !bs->bio_integrity_pool) {
bip = kmalloc(sizeof(struct bio_integrity_payload) +
sizeof(struct bio_vec) * nr_vecs, gfp_mask);
inline_vecs = nr_vecs;
} else {
bip = mempool_alloc(bs->bio_integrity_pool, gfp_mask);
inline_vecs = BIP_INLINE_VECS;
}
if (unlikely(!bip))
return NULL;
memset(bip, 0, sizeof(*bip));
if (nr_vecs > inline_vecs) {
bip->bip_vec = bvec_alloc(gfp_mask, nr_vecs, &idx,
bs->bvec_integrity_pool);
if (!bip->bip_vec)
goto err;
bip->bip_max_vcnt = bvec_nr_vecs(idx);
} else {
bip->bip_vec = bip->bip_inline_vecs;
bip->bip_max_vcnt = inline_vecs;
}
bip->bip_slab = idx;
bip->bip_bio = bio;
bio->bi_integrity = bip;
bio->bi_rw |= REQ_INTEGRITY;
return bip;
err:
mempool_free(bip, bs->bio_integrity_pool);
return NULL;
}
void bio_integrity_free(struct bio *bio)
{
struct bio_integrity_payload *bip = bio_integrity(bio);
struct bio_set *bs = bio->bi_pool;
if (bip->bip_flags & BIP_BLOCK_INTEGRITY)
kfree(page_address(bip->bip_vec->bv_page) +
bip->bip_vec->bv_offset);
if (bs && bs->bio_integrity_pool) {
if (bip->bip_slab != BIO_POOL_NONE)
bvec_free(bs->bvec_integrity_pool, bip->bip_vec,
bip->bip_slab);
mempool_free(bip, bs->bio_integrity_pool);
} else {
kfree(bip);
}
bio->bi_integrity = NULL;
}
int bio_integrity_add_page(struct bio *bio, struct page *page,
unsigned int len, unsigned int offset)
{
struct bio_integrity_payload *bip = bio_integrity(bio);
struct bio_vec *iv;
if (bip->bip_vcnt >= bip->bip_max_vcnt) {
printk(KERN_ERR "%s: bip_vec full\n", __func__);
return 0;
}
iv = bip->bip_vec + bip->bip_vcnt;
if (bip->bip_vcnt &&
bvec_gap_to_prev(bdev_get_queue(bio->bi_bdev),
&bip->bip_vec[bip->bip_vcnt - 1], offset))
return 0;
iv->bv_page = page;
iv->bv_len = len;
iv->bv_offset = offset;
bip->bip_vcnt++;
return len;
}
bool bio_integrity_enabled(struct bio *bio)
{
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
if (!bio_is_rw(bio))
return false;
if (bio_integrity(bio))
return false;
if (bi == NULL)
return false;
if (bio_data_dir(bio) == READ && bi->verify_fn != NULL &&
(bi->flags & BLK_INTEGRITY_VERIFY))
return true;
if (bio_data_dir(bio) == WRITE && bi->generate_fn != NULL &&
(bi->flags & BLK_INTEGRITY_GENERATE))
return true;
return false;
}
static inline unsigned int bio_integrity_intervals(struct blk_integrity *bi,
unsigned int sectors)
{
return sectors >> (ilog2(bi->interval) - 9);
}
static inline unsigned int bio_integrity_bytes(struct blk_integrity *bi,
unsigned int sectors)
{
return bio_integrity_intervals(bi, sectors) * bi->tuple_size;
}
static int bio_integrity_process(struct bio *bio,
integrity_processing_fn *proc_fn)
{
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
struct blk_integrity_iter iter;
struct bvec_iter bviter;
struct bio_vec bv;
struct bio_integrity_payload *bip = bio_integrity(bio);
unsigned int ret = 0;
void *prot_buf = page_address(bip->bip_vec->bv_page) +
bip->bip_vec->bv_offset;
iter.disk_name = bio->bi_bdev->bd_disk->disk_name;
iter.interval = bi->interval;
iter.seed = bip_get_seed(bip);
iter.prot_buf = prot_buf;
bio_for_each_segment(bv, bio, bviter) {
void *kaddr = kmap_atomic(bv.bv_page);
iter.data_buf = kaddr + bv.bv_offset;
iter.data_size = bv.bv_len;
ret = proc_fn(&iter);
if (ret) {
kunmap_atomic(kaddr);
return ret;
}
kunmap_atomic(kaddr);
}
return ret;
}
int bio_integrity_prep(struct bio *bio)
{
struct bio_integrity_payload *bip;
struct blk_integrity *bi;
struct request_queue *q;
void *buf;
unsigned long start, end;
unsigned int len, nr_pages;
unsigned int bytes, offset, i;
unsigned int intervals;
bi = bdev_get_integrity(bio->bi_bdev);
q = bdev_get_queue(bio->bi_bdev);
BUG_ON(bi == NULL);
BUG_ON(bio_integrity(bio));
intervals = bio_integrity_intervals(bi, bio_sectors(bio));
len = intervals * bi->tuple_size;
buf = kmalloc(len, GFP_NOIO | q->bounce_gfp);
if (unlikely(buf == NULL)) {
printk(KERN_ERR "could not allocate integrity buffer\n");
return -ENOMEM;
}
end = (((unsigned long) buf) + len + PAGE_SIZE - 1) >> PAGE_SHIFT;
start = ((unsigned long) buf) >> PAGE_SHIFT;
nr_pages = end - start;
bip = bio_integrity_alloc(bio, GFP_NOIO, nr_pages);
if (unlikely(bip == NULL)) {
printk(KERN_ERR "could not allocate data integrity bioset\n");
kfree(buf);
return -EIO;
}
bip->bip_flags |= BIP_BLOCK_INTEGRITY;
bip->bip_iter.bi_size = len;
bip_set_seed(bip, bio->bi_iter.bi_sector);
if (bi->flags & BLK_INTEGRITY_IP_CHECKSUM)
bip->bip_flags |= BIP_IP_CHECKSUM;
offset = offset_in_page(buf);
for (i = 0 ; i < nr_pages ; i++) {
int ret;
bytes = PAGE_SIZE - offset;
if (len <= 0)
break;
if (bytes > len)
bytes = len;
ret = bio_integrity_add_page(bio, virt_to_page(buf),
bytes, offset);
if (ret == 0)
return 0;
if (ret < bytes)
break;
buf += bytes;
len -= bytes;
offset = 0;
}
if (bio_data_dir(bio) == READ) {
bip->bip_end_io = bio->bi_end_io;
bio->bi_end_io = bio_integrity_endio;
}
if (bio_data_dir(bio) == WRITE)
bio_integrity_process(bio, bi->generate_fn);
return 0;
}
static void bio_integrity_verify_fn(struct work_struct *work)
{
struct bio_integrity_payload *bip =
container_of(work, struct bio_integrity_payload, bip_work);
struct bio *bio = bip->bip_bio;
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
bio->bi_error = bio_integrity_process(bio, bi->verify_fn);
bio->bi_end_io = bip->bip_end_io;
bio_endio(bio);
}
void bio_integrity_endio(struct bio *bio)
{
struct bio_integrity_payload *bip = bio_integrity(bio);
BUG_ON(bip->bip_bio != bio);
if (bio->bi_error) {
bio->bi_end_io = bip->bip_end_io;
bio_endio(bio);
return;
}
INIT_WORK(&bip->bip_work, bio_integrity_verify_fn);
queue_work(kintegrityd_wq, &bip->bip_work);
}
void bio_integrity_advance(struct bio *bio, unsigned int bytes_done)
{
struct bio_integrity_payload *bip = bio_integrity(bio);
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
unsigned bytes = bio_integrity_bytes(bi, bytes_done >> 9);
bvec_iter_advance(bip->bip_vec, &bip->bip_iter, bytes);
}
void bio_integrity_trim(struct bio *bio, unsigned int offset,
unsigned int sectors)
{
struct bio_integrity_payload *bip = bio_integrity(bio);
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
bio_integrity_advance(bio, offset << 9);
bip->bip_iter.bi_size = bio_integrity_bytes(bi, sectors);
}
int bio_integrity_clone(struct bio *bio, struct bio *bio_src,
gfp_t gfp_mask)
{
struct bio_integrity_payload *bip_src = bio_integrity(bio_src);
struct bio_integrity_payload *bip;
BUG_ON(bip_src == NULL);
bip = bio_integrity_alloc(bio, gfp_mask, bip_src->bip_vcnt);
if (bip == NULL)
return -EIO;
memcpy(bip->bip_vec, bip_src->bip_vec,
bip_src->bip_vcnt * sizeof(struct bio_vec));
bip->bip_vcnt = bip_src->bip_vcnt;
bip->bip_iter = bip_src->bip_iter;
return 0;
}
int bioset_integrity_create(struct bio_set *bs, int pool_size)
{
if (bs->bio_integrity_pool)
return 0;
bs->bio_integrity_pool = mempool_create_slab_pool(pool_size, bip_slab);
if (!bs->bio_integrity_pool)
return -1;
bs->bvec_integrity_pool = biovec_create_pool(pool_size);
if (!bs->bvec_integrity_pool) {
mempool_destroy(bs->bio_integrity_pool);
return -1;
}
return 0;
}
void bioset_integrity_free(struct bio_set *bs)
{
if (bs->bio_integrity_pool)
mempool_destroy(bs->bio_integrity_pool);
if (bs->bvec_integrity_pool)
mempool_destroy(bs->bvec_integrity_pool);
}
void __init bio_integrity_init(void)
{
kintegrityd_wq = alloc_workqueue("kintegrityd", WQ_MEM_RECLAIM |
WQ_HIGHPRI | WQ_CPU_INTENSIVE, 1);
if (!kintegrityd_wq)
panic("Failed to create kintegrityd\n");
bip_slab = kmem_cache_create("bio_integrity_payload",
sizeof(struct bio_integrity_payload) +
sizeof(struct bio_vec) * BIP_INLINE_VECS,
0, SLAB_HWCACHE_ALIGN|SLAB_PANIC, NULL);
}
