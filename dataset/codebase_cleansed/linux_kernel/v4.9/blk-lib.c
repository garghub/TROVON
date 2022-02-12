static struct bio *next_bio(struct bio *bio, unsigned int nr_pages,
gfp_t gfp)
{
struct bio *new = bio_alloc(gfp, nr_pages);
if (bio) {
bio_chain(bio, new);
submit_bio(bio);
}
return new;
}
int __blkdev_issue_discard(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, int flags,
struct bio **biop)
{
struct request_queue *q = bdev_get_queue(bdev);
struct bio *bio = *biop;
unsigned int granularity;
enum req_op op;
int alignment;
sector_t bs_mask;
if (!q)
return -ENXIO;
if (flags & BLKDEV_DISCARD_SECURE) {
if (flags & BLKDEV_DISCARD_ZERO)
return -EOPNOTSUPP;
if (!blk_queue_secure_erase(q))
return -EOPNOTSUPP;
op = REQ_OP_SECURE_ERASE;
} else {
if (!blk_queue_discard(q))
return -EOPNOTSUPP;
if ((flags & BLKDEV_DISCARD_ZERO) &&
!q->limits.discard_zeroes_data)
return -EOPNOTSUPP;
op = REQ_OP_DISCARD;
}
bs_mask = (bdev_logical_block_size(bdev) >> 9) - 1;
if ((sector | nr_sects) & bs_mask)
return -EINVAL;
granularity = max(q->limits.discard_granularity >> 9, 1U);
alignment = (bdev_discard_alignment(bdev) >> 9) % granularity;
while (nr_sects) {
unsigned int req_sects;
sector_t end_sect, tmp;
req_sects = min_t(sector_t, nr_sects, UINT_MAX >> 9);
end_sect = sector + req_sects;
tmp = end_sect;
if (req_sects < nr_sects &&
sector_div(tmp, granularity) != alignment) {
end_sect = end_sect - alignment;
sector_div(end_sect, granularity);
end_sect = end_sect * granularity + alignment;
req_sects = end_sect - sector;
}
bio = next_bio(bio, 1, gfp_mask);
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = bdev;
bio_set_op_attrs(bio, op, 0);
bio->bi_iter.bi_size = req_sects << 9;
nr_sects -= req_sects;
sector = end_sect;
cond_resched();
}
*biop = bio;
return 0;
}
int blkdev_issue_discard(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, unsigned long flags)
{
struct bio *bio = NULL;
struct blk_plug plug;
int ret;
blk_start_plug(&plug);
ret = __blkdev_issue_discard(bdev, sector, nr_sects, gfp_mask, flags,
&bio);
if (!ret && bio) {
ret = submit_bio_wait(bio);
if (ret == -EOPNOTSUPP && !(flags & BLKDEV_DISCARD_ZERO))
ret = 0;
bio_put(bio);
}
blk_finish_plug(&plug);
return ret;
}
int blkdev_issue_write_same(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask,
struct page *page)
{
struct request_queue *q = bdev_get_queue(bdev);
unsigned int max_write_same_sectors;
struct bio *bio = NULL;
int ret = 0;
sector_t bs_mask;
if (!q)
return -ENXIO;
bs_mask = (bdev_logical_block_size(bdev) >> 9) - 1;
if ((sector | nr_sects) & bs_mask)
return -EINVAL;
max_write_same_sectors = UINT_MAX >> 9;
while (nr_sects) {
bio = next_bio(bio, 1, gfp_mask);
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = bdev;
bio->bi_vcnt = 1;
bio->bi_io_vec->bv_page = page;
bio->bi_io_vec->bv_offset = 0;
bio->bi_io_vec->bv_len = bdev_logical_block_size(bdev);
bio_set_op_attrs(bio, REQ_OP_WRITE_SAME, 0);
if (nr_sects > max_write_same_sectors) {
bio->bi_iter.bi_size = max_write_same_sectors << 9;
nr_sects -= max_write_same_sectors;
sector += max_write_same_sectors;
} else {
bio->bi_iter.bi_size = nr_sects << 9;
nr_sects = 0;
}
}
if (bio) {
ret = submit_bio_wait(bio);
bio_put(bio);
}
return ret;
}
static int __blkdev_issue_zeroout(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask)
{
int ret;
struct bio *bio = NULL;
unsigned int sz;
sector_t bs_mask;
bs_mask = (bdev_logical_block_size(bdev) >> 9) - 1;
if ((sector | nr_sects) & bs_mask)
return -EINVAL;
while (nr_sects != 0) {
bio = next_bio(bio, min(nr_sects, (sector_t)BIO_MAX_PAGES),
gfp_mask);
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = bdev;
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
while (nr_sects != 0) {
sz = min((sector_t) PAGE_SIZE >> 9 , nr_sects);
ret = bio_add_page(bio, ZERO_PAGE(0), sz << 9, 0);
nr_sects -= ret >> 9;
sector += ret >> 9;
if (ret < (sz << 9))
break;
}
}
if (bio) {
ret = submit_bio_wait(bio);
bio_put(bio);
return ret;
}
return 0;
}
int blkdev_issue_zeroout(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, bool discard)
{
if (discard) {
if (!blkdev_issue_discard(bdev, sector, nr_sects, gfp_mask,
BLKDEV_DISCARD_ZERO))
return 0;
}
if (bdev_write_same(bdev) &&
blkdev_issue_write_same(bdev, sector, nr_sects, gfp_mask,
ZERO_PAGE(0)) == 0)
return 0;
return __blkdev_issue_zeroout(bdev, sector, nr_sects, gfp_mask);
}
