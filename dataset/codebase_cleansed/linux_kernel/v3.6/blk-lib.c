static void bio_batch_end_io(struct bio *bio, int err)
{
struct bio_batch *bb = bio->bi_private;
if (err && (err != -EOPNOTSUPP))
clear_bit(BIO_UPTODATE, &bb->flags);
if (atomic_dec_and_test(&bb->done))
complete(bb->wait);
bio_put(bio);
}
int blkdev_issue_discard(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask, unsigned long flags)
{
DECLARE_COMPLETION_ONSTACK(wait);
struct request_queue *q = bdev_get_queue(bdev);
int type = REQ_WRITE | REQ_DISCARD;
unsigned int max_discard_sectors;
unsigned int granularity, alignment, mask;
struct bio_batch bb;
struct bio *bio;
int ret = 0;
if (!q)
return -ENXIO;
if (!blk_queue_discard(q))
return -EOPNOTSUPP;
granularity = max(q->limits.discard_granularity >> 9, 1U);
mask = granularity - 1;
alignment = (bdev_discard_alignment(bdev) >> 9) & mask;
max_discard_sectors = min(q->limits.max_discard_sectors, UINT_MAX >> 9);
max_discard_sectors = round_down(max_discard_sectors, granularity);
if (unlikely(!max_discard_sectors)) {
return -EOPNOTSUPP;
}
if (flags & BLKDEV_DISCARD_SECURE) {
if (!blk_queue_secdiscard(q))
return -EOPNOTSUPP;
type |= REQ_SECURE;
}
atomic_set(&bb.done, 1);
bb.flags = 1 << BIO_UPTODATE;
bb.wait = &wait;
while (nr_sects) {
unsigned int req_sects;
sector_t end_sect;
bio = bio_alloc(gfp_mask, 1);
if (!bio) {
ret = -ENOMEM;
break;
}
req_sects = min_t(sector_t, nr_sects, max_discard_sectors);
end_sect = sector + req_sects;
if (req_sects < nr_sects && (end_sect & mask) != alignment) {
end_sect =
round_down(end_sect - alignment, granularity)
+ alignment;
req_sects = end_sect - sector;
}
bio->bi_sector = sector;
bio->bi_end_io = bio_batch_end_io;
bio->bi_bdev = bdev;
bio->bi_private = &bb;
bio->bi_size = req_sects << 9;
nr_sects -= req_sects;
sector = end_sect;
atomic_inc(&bb.done);
submit_bio(type, bio);
}
if (!atomic_dec_and_test(&bb.done))
wait_for_completion(&wait);
if (!test_bit(BIO_UPTODATE, &bb.flags))
ret = -EIO;
return ret;
}
int blkdev_issue_zeroout(struct block_device *bdev, sector_t sector,
sector_t nr_sects, gfp_t gfp_mask)
{
int ret;
struct bio *bio;
struct bio_batch bb;
unsigned int sz;
DECLARE_COMPLETION_ONSTACK(wait);
atomic_set(&bb.done, 1);
bb.flags = 1 << BIO_UPTODATE;
bb.wait = &wait;
ret = 0;
while (nr_sects != 0) {
bio = bio_alloc(gfp_mask,
min(nr_sects, (sector_t)BIO_MAX_PAGES));
if (!bio) {
ret = -ENOMEM;
break;
}
bio->bi_sector = sector;
bio->bi_bdev = bdev;
bio->bi_end_io = bio_batch_end_io;
bio->bi_private = &bb;
while (nr_sects != 0) {
sz = min((sector_t) PAGE_SIZE >> 9 , nr_sects);
ret = bio_add_page(bio, ZERO_PAGE(0), sz << 9, 0);
nr_sects -= ret >> 9;
sector += ret >> 9;
if (ret < (sz << 9))
break;
}
ret = 0;
atomic_inc(&bb.done);
submit_bio(WRITE, bio);
}
if (!atomic_dec_and_test(&bb.done))
wait_for_completion(&wait);
if (!test_bit(BIO_UPTODATE, &bb.flags))
ret = -EIO;
return ret;
}
