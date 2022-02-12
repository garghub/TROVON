struct bio_integrity_payload *bio_integrity_alloc(struct bio *bio,
gfp_t gfp_mask,
unsigned int nr_vecs)
{
struct bio_integrity_payload *bip;
struct bio_set *bs = bio->bi_pool;
unsigned long idx = BIO_POOL_NONE;
unsigned inline_vecs;
if (!bs) {
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
} else {
bip->bip_vec = bip->bip_inline_vecs;
}
bip->bip_slab = idx;
bip->bip_bio = bio;
bio->bi_integrity = bip;
return bip;
err:
mempool_free(bip, bs->bio_integrity_pool);
return NULL;
}
void bio_integrity_free(struct bio *bio)
{
struct bio_integrity_payload *bip = bio->bi_integrity;
struct bio_set *bs = bio->bi_pool;
if (bip->bip_owns_buf)
kfree(bip->bip_buf);
if (bs) {
if (bip->bip_slab != BIO_POOL_NONE)
bvec_free(bs->bvec_integrity_pool, bip->bip_vec,
bip->bip_slab);
mempool_free(bip, bs->bio_integrity_pool);
} else {
kfree(bip);
}
bio->bi_integrity = NULL;
}
static inline unsigned int bip_integrity_vecs(struct bio_integrity_payload *bip)
{
if (bip->bip_slab == BIO_POOL_NONE)
return BIP_INLINE_VECS;
return bvec_nr_vecs(bip->bip_slab);
}
int bio_integrity_add_page(struct bio *bio, struct page *page,
unsigned int len, unsigned int offset)
{
struct bio_integrity_payload *bip = bio->bi_integrity;
struct bio_vec *iv;
if (bip->bip_vcnt >= bip_integrity_vecs(bip)) {
printk(KERN_ERR "%s: bip_vec full\n", __func__);
return 0;
}
iv = bip->bip_vec + bip->bip_vcnt;
iv->bv_page = page;
iv->bv_len = len;
iv->bv_offset = offset;
bip->bip_vcnt++;
return len;
}
static int bdev_integrity_enabled(struct block_device *bdev, int rw)
{
struct blk_integrity *bi = bdev_get_integrity(bdev);
if (bi == NULL)
return 0;
if (rw == READ && bi->verify_fn != NULL &&
(bi->flags & INTEGRITY_FLAG_READ))
return 1;
if (rw == WRITE && bi->generate_fn != NULL &&
(bi->flags & INTEGRITY_FLAG_WRITE))
return 1;
return 0;
}
int bio_integrity_enabled(struct bio *bio)
{
if (!bio_is_rw(bio))
return 0;
if (bio_integrity(bio))
return 0;
return bdev_integrity_enabled(bio->bi_bdev, bio_data_dir(bio));
}
static inline unsigned int bio_integrity_hw_sectors(struct blk_integrity *bi,
unsigned int sectors)
{
if (bi->sector_size == 4096)
return sectors >>= 3;
return sectors;
}
static inline unsigned int bio_integrity_bytes(struct blk_integrity *bi,
unsigned int sectors)
{
return bio_integrity_hw_sectors(bi, sectors) * bi->tuple_size;
}
unsigned int bio_integrity_tag_size(struct bio *bio)
{
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
BUG_ON(bio->bi_iter.bi_size == 0);
return bi->tag_size * (bio->bi_iter.bi_size / bi->sector_size);
}
static int bio_integrity_tag(struct bio *bio, void *tag_buf, unsigned int len,
int set)
{
struct bio_integrity_payload *bip = bio->bi_integrity;
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
unsigned int nr_sectors;
BUG_ON(bip->bip_buf == NULL);
if (bi->tag_size == 0)
return -1;
nr_sectors = bio_integrity_hw_sectors(bi,
DIV_ROUND_UP(len, bi->tag_size));
if (nr_sectors * bi->tuple_size > bip->bip_iter.bi_size) {
printk(KERN_ERR "%s: tag too big for bio: %u > %u\n", __func__,
nr_sectors * bi->tuple_size, bip->bip_iter.bi_size);
return -1;
}
if (set)
bi->set_tag_fn(bip->bip_buf, tag_buf, nr_sectors);
else
bi->get_tag_fn(bip->bip_buf, tag_buf, nr_sectors);
return 0;
}
int bio_integrity_set_tag(struct bio *bio, void *tag_buf, unsigned int len)
{
BUG_ON(bio_data_dir(bio) != WRITE);
return bio_integrity_tag(bio, tag_buf, len, 1);
}
int bio_integrity_get_tag(struct bio *bio, void *tag_buf, unsigned int len)
{
BUG_ON(bio_data_dir(bio) != READ);
return bio_integrity_tag(bio, tag_buf, len, 0);
}
static int bio_integrity_generate_verify(struct bio *bio, int operate)
{
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
struct blk_integrity_exchg bix;
struct bio_vec *bv;
sector_t sector;
unsigned int sectors, ret = 0, i;
void *prot_buf = bio->bi_integrity->bip_buf;
if (operate)
sector = bio->bi_iter.bi_sector;
else
sector = bio->bi_integrity->bip_iter.bi_sector;
bix.disk_name = bio->bi_bdev->bd_disk->disk_name;
bix.sector_size = bi->sector_size;
bio_for_each_segment_all(bv, bio, i) {
void *kaddr = kmap_atomic(bv->bv_page);
bix.data_buf = kaddr + bv->bv_offset;
bix.data_size = bv->bv_len;
bix.prot_buf = prot_buf;
bix.sector = sector;
if (operate)
bi->generate_fn(&bix);
else {
ret = bi->verify_fn(&bix);
if (ret) {
kunmap_atomic(kaddr);
return ret;
}
}
sectors = bv->bv_len / bi->sector_size;
sector += sectors;
prot_buf += sectors * bi->tuple_size;
kunmap_atomic(kaddr);
}
return ret;
}
static void bio_integrity_generate(struct bio *bio)
{
bio_integrity_generate_verify(bio, 1);
}
static inline unsigned short blk_integrity_tuple_size(struct blk_integrity *bi)
{
if (bi)
return bi->tuple_size;
return 0;
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
unsigned int sectors;
bi = bdev_get_integrity(bio->bi_bdev);
q = bdev_get_queue(bio->bi_bdev);
BUG_ON(bi == NULL);
BUG_ON(bio_integrity(bio));
sectors = bio_integrity_hw_sectors(bi, bio_sectors(bio));
len = sectors * blk_integrity_tuple_size(bi);
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
bip->bip_owns_buf = 1;
bip->bip_buf = buf;
bip->bip_iter.bi_size = len;
bip->bip_iter.bi_sector = bio->bi_iter.bi_sector;
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
bio_integrity_generate(bio);
return 0;
}
static int bio_integrity_verify(struct bio *bio)
{
return bio_integrity_generate_verify(bio, 0);
}
static void bio_integrity_verify_fn(struct work_struct *work)
{
struct bio_integrity_payload *bip =
container_of(work, struct bio_integrity_payload, bip_work);
struct bio *bio = bip->bip_bio;
int error;
error = bio_integrity_verify(bio);
bio->bi_end_io = bip->bip_end_io;
bio_endio_nodec(bio, error);
}
void bio_integrity_endio(struct bio *bio, int error)
{
struct bio_integrity_payload *bip = bio->bi_integrity;
BUG_ON(bip->bip_bio != bio);
if (error) {
bio->bi_end_io = bip->bip_end_io;
bio_endio(bio, error);
return;
}
INIT_WORK(&bip->bip_work, bio_integrity_verify_fn);
queue_work(kintegrityd_wq, &bip->bip_work);
}
void bio_integrity_advance(struct bio *bio, unsigned int bytes_done)
{
struct bio_integrity_payload *bip = bio->bi_integrity;
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
unsigned bytes = bio_integrity_bytes(bi, bytes_done >> 9);
bvec_iter_advance(bip->bip_vec, &bip->bip_iter, bytes);
}
void bio_integrity_trim(struct bio *bio, unsigned int offset,
unsigned int sectors)
{
struct bio_integrity_payload *bip = bio->bi_integrity;
struct blk_integrity *bi = bdev_get_integrity(bio->bi_bdev);
bio_integrity_advance(bio, offset << 9);
bip->bip_iter.bi_size = bio_integrity_bytes(bi, sectors);
}
int bio_integrity_clone(struct bio *bio, struct bio *bio_src,
gfp_t gfp_mask)
{
struct bio_integrity_payload *bip_src = bio_src->bi_integrity;
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
if (!bip_slab)
panic("Failed to create slab\n");
}
