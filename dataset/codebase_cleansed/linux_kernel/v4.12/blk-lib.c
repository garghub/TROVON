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
unsigned int op;
int alignment;
sector_t bs_mask;
if (!q)
return -ENXIO;
if (flags & BLKDEV_DISCARD_SECURE) {
if (!blk_queue_secure_erase(q))
return -EOPNOTSUPP;
op = REQ_OP_SECURE_ERASE;
} else {
if (!blk_queue_discard(q))
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
bio = next_bio(bio, 0, gfp_mask);
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
if (ret == -EOPNOTSUPP)
ret = 0;
bio_put(bio);
}
blk_finish_plug(&plug);
return ret;
}
static int __blkdev_issue_write_same(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, struct page *page,
struct bio **biop)
{
struct request_queue *q = bdev_get_queue(bdev);
unsigned int max_write_same_sectors;
struct bio *bio = *biop;
sector_t bs_mask;
if (!q)
return -ENXIO;
bs_mask = (bdev_logical_block_size(bdev) >> 9) - 1;
if ((sector | nr_sects) & bs_mask)
return -EINVAL;
if (!bdev_write_same(bdev))
return -EOPNOTSUPP;
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
cond_resched();
}
*biop = bio;
return 0;
}
int blkdev_issue_write_same(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask,
struct page *page)
{
struct bio *bio = NULL;
struct blk_plug plug;
int ret;
blk_start_plug(&plug);
ret = __blkdev_issue_write_same(bdev, sector, nr_sects, gfp_mask, page,
&bio);
if (ret == 0 && bio) {
ret = submit_bio_wait(bio);
bio_put(bio);
}
blk_finish_plug(&plug);
return ret;
}
static int __blkdev_issue_write_zeroes(struct block_device *bdev,
sector_t sector, sector_t nr_sects, gfp_t gfp_mask,
struct bio **biop, unsigned flags)
{
struct bio *bio = *biop;
unsigned int max_write_zeroes_sectors;
struct request_queue *q = bdev_get_queue(bdev);
if (!q)
return -ENXIO;
max_write_zeroes_sectors = bdev_write_zeroes_sectors(bdev);
if (max_write_zeroes_sectors == 0)
return -EOPNOTSUPP;
while (nr_sects) {
bio = next_bio(bio, 0, gfp_mask);
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = bdev;
bio->bi_opf = REQ_OP_WRITE_ZEROES;
if (flags & BLKDEV_ZERO_NOUNMAP)
bio->bi_opf |= REQ_NOUNMAP;
if (nr_sects > max_write_zeroes_sectors) {
bio->bi_iter.bi_size = max_write_zeroes_sectors << 9;
nr_sects -= max_write_zeroes_sectors;
sector += max_write_zeroes_sectors;
} else {
bio->bi_iter.bi_size = nr_sects << 9;
nr_sects = 0;
}
cond_resched();
}
*biop = bio;
return 0;
}
int __blkdev_issue_zeroout(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, struct bio **biop,
unsigned flags)
{
int ret;
int bi_size = 0;
struct bio *bio = *biop;
unsigned int sz;
sector_t bs_mask;
bs_mask = (bdev_logical_block_size(bdev) >> 9) - 1;
if ((sector | nr_sects) & bs_mask)
return -EINVAL;
ret = __blkdev_issue_write_zeroes(bdev, sector, nr_sects, gfp_mask,
biop, flags);
if (ret != -EOPNOTSUPP || (flags & BLKDEV_ZERO_NOFALLBACK))
goto out;
ret = 0;
while (nr_sects != 0) {
bio = next_bio(bio, min(nr_sects, (sector_t)BIO_MAX_PAGES),
gfp_mask);
bio->bi_iter.bi_sector = sector;
bio->bi_bdev = bdev;
bio_set_op_attrs(bio, REQ_OP_WRITE, 0);
while (nr_sects != 0) {
sz = min((sector_t) PAGE_SIZE >> 9 , nr_sects);
bi_size = bio_add_page(bio, ZERO_PAGE(0), sz << 9, 0);
nr_sects -= bi_size >> 9;
sector += bi_size >> 9;
if (bi_size < (sz << 9))
break;
}
cond_resched();
}
*biop = bio;
out:
return ret;
}
int blkdev_issue_zeroout(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, unsigned flags)
{
int ret;
struct bio *bio = NULL;
struct blk_plug plug;
blk_start_plug(&plug);
ret = __blkdev_issue_zeroout(bdev, sector, nr_sects, gfp_mask,
&bio, flags);
if (ret == 0 && bio) {
ret = submit_bio_wait(bio);
bio_put(bio);
}
blk_finish_plug(&plug);
return ret;
}
