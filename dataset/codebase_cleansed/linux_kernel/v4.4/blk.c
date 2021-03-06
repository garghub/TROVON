static u32 nd_blk_meta_size(struct nd_blk_device *blk_dev)
{
return blk_dev->nsblk->lbasize - blk_dev->sector_size;
}
static resource_size_t to_dev_offset(struct nd_namespace_blk *nsblk,
resource_size_t ns_offset, unsigned int len)
{
int i;
for (i = 0; i < nsblk->num_resources; i++) {
if (ns_offset < resource_size(nsblk->res[i])) {
if (ns_offset + len > resource_size(nsblk->res[i])) {
dev_WARN_ONCE(&nsblk->common.dev, 1,
"illegal request\n");
return SIZE_MAX;
}
return nsblk->res[i]->start + ns_offset;
}
ns_offset -= resource_size(nsblk->res[i]);
}
dev_WARN_ONCE(&nsblk->common.dev, 1, "request out of range\n");
return SIZE_MAX;
}
static int nd_blk_rw_integrity(struct nd_blk_device *blk_dev,
struct bio_integrity_payload *bip, u64 lba,
int rw)
{
unsigned int len = nd_blk_meta_size(blk_dev);
resource_size_t dev_offset, ns_offset;
struct nd_namespace_blk *nsblk;
struct nd_blk_region *ndbr;
int err = 0;
nsblk = blk_dev->nsblk;
ndbr = blk_dev->ndbr;
ns_offset = lba * blk_dev->internal_lbasize + blk_dev->sector_size;
dev_offset = to_dev_offset(nsblk, ns_offset, len);
if (dev_offset == SIZE_MAX)
return -EIO;
while (len) {
unsigned int cur_len;
struct bio_vec bv;
void *iobuf;
bv = bvec_iter_bvec(bip->bip_vec, bip->bip_iter);
cur_len = min(len, bv.bv_len);
iobuf = kmap_atomic(bv.bv_page);
err = ndbr->do_io(ndbr, dev_offset, iobuf + bv.bv_offset,
cur_len, rw);
kunmap_atomic(iobuf);
if (err)
return err;
len -= cur_len;
dev_offset += cur_len;
bvec_iter_advance(bip->bip_vec, &bip->bip_iter, cur_len);
}
return err;
}
static int nd_blk_rw_integrity(struct nd_blk_device *blk_dev,
struct bio_integrity_payload *bip, u64 lba,
int rw)
{
return 0;
}
static int nd_blk_do_bvec(struct nd_blk_device *blk_dev,
struct bio_integrity_payload *bip, struct page *page,
unsigned int len, unsigned int off, int rw,
sector_t sector)
{
struct nd_blk_region *ndbr = blk_dev->ndbr;
resource_size_t dev_offset, ns_offset;
int err = 0;
void *iobuf;
u64 lba;
while (len) {
unsigned int cur_len;
cur_len = bip ? min(len, blk_dev->sector_size) : len;
lba = div_u64(sector << SECTOR_SHIFT, blk_dev->sector_size);
ns_offset = lba * blk_dev->internal_lbasize;
dev_offset = to_dev_offset(blk_dev->nsblk, ns_offset, cur_len);
if (dev_offset == SIZE_MAX)
return -EIO;
iobuf = kmap_atomic(page);
err = ndbr->do_io(ndbr, dev_offset, iobuf + off, cur_len, rw);
kunmap_atomic(iobuf);
if (err)
return err;
if (bip) {
err = nd_blk_rw_integrity(blk_dev, bip, lba, rw);
if (err)
return err;
}
len -= cur_len;
off += cur_len;
sector += blk_dev->sector_size >> SECTOR_SHIFT;
}
return err;
}
static blk_qc_t nd_blk_make_request(struct request_queue *q, struct bio *bio)
{
struct block_device *bdev = bio->bi_bdev;
struct gendisk *disk = bdev->bd_disk;
struct bio_integrity_payload *bip;
struct nd_blk_device *blk_dev;
struct bvec_iter iter;
unsigned long start;
struct bio_vec bvec;
int err = 0, rw;
bool do_acct;
if (bio_integrity_enabled(bio) && bio_integrity_prep(bio)) {
bio->bi_error = -EIO;
goto out;
}
bip = bio_integrity(bio);
blk_dev = disk->private_data;
rw = bio_data_dir(bio);
do_acct = nd_iostat_start(bio, &start);
bio_for_each_segment(bvec, bio, iter) {
unsigned int len = bvec.bv_len;
BUG_ON(len > PAGE_SIZE);
err = nd_blk_do_bvec(blk_dev, bip, bvec.bv_page, len,
bvec.bv_offset, rw, iter.bi_sector);
if (err) {
dev_info(&blk_dev->nsblk->common.dev,
"io error in %s sector %lld, len %d,\n",
(rw == READ) ? "READ" : "WRITE",
(unsigned long long) iter.bi_sector, len);
bio->bi_error = err;
break;
}
}
if (do_acct)
nd_iostat_end(bio, start);
out:
bio_endio(bio);
return BLK_QC_T_NONE;
}
static int nd_blk_rw_bytes(struct nd_namespace_common *ndns,
resource_size_t offset, void *iobuf, size_t n, int rw)
{
struct nd_blk_device *blk_dev = dev_get_drvdata(ndns->claim);
struct nd_namespace_blk *nsblk = blk_dev->nsblk;
struct nd_blk_region *ndbr = blk_dev->ndbr;
resource_size_t dev_offset;
dev_offset = to_dev_offset(nsblk, offset, n);
if (unlikely(offset + n > blk_dev->disk_size)) {
dev_WARN_ONCE(&ndns->dev, 1, "request out of range\n");
return -EFAULT;
}
if (dev_offset == SIZE_MAX)
return -EIO;
return ndbr->do_io(ndbr, dev_offset, iobuf, n, rw);
}
static int nd_blk_attach_disk(struct nd_namespace_common *ndns,
struct nd_blk_device *blk_dev)
{
resource_size_t available_disk_size;
struct gendisk *disk;
u64 internal_nlba;
internal_nlba = div_u64(blk_dev->disk_size, blk_dev->internal_lbasize);
available_disk_size = internal_nlba * blk_dev->sector_size;
blk_dev->queue = blk_alloc_queue(GFP_KERNEL);
if (!blk_dev->queue)
return -ENOMEM;
blk_queue_make_request(blk_dev->queue, nd_blk_make_request);
blk_queue_max_hw_sectors(blk_dev->queue, UINT_MAX);
blk_queue_bounce_limit(blk_dev->queue, BLK_BOUNCE_ANY);
blk_queue_logical_block_size(blk_dev->queue, blk_dev->sector_size);
queue_flag_set_unlocked(QUEUE_FLAG_NONROT, blk_dev->queue);
disk = blk_dev->disk = alloc_disk(0);
if (!disk) {
blk_cleanup_queue(blk_dev->queue);
return -ENOMEM;
}
disk->driverfs_dev = &ndns->dev;
disk->major = nd_blk_major;
disk->first_minor = 0;
disk->fops = &nd_blk_fops;
disk->private_data = blk_dev;
disk->queue = blk_dev->queue;
disk->flags = GENHD_FL_EXT_DEVT;
nvdimm_namespace_disk_name(ndns, disk->disk_name);
set_capacity(disk, 0);
add_disk(disk);
if (nd_blk_meta_size(blk_dev)) {
int rc = nd_integrity_init(disk, nd_blk_meta_size(blk_dev));
if (rc) {
del_gendisk(disk);
put_disk(disk);
blk_cleanup_queue(blk_dev->queue);
return rc;
}
}
set_capacity(disk, available_disk_size >> SECTOR_SHIFT);
revalidate_disk(disk);
return 0;
}
static int nd_blk_probe(struct device *dev)
{
struct nd_namespace_common *ndns;
struct nd_namespace_blk *nsblk;
struct nd_blk_device *blk_dev;
int rc;
ndns = nvdimm_namespace_common_probe(dev);
if (IS_ERR(ndns))
return PTR_ERR(ndns);
blk_dev = kzalloc(sizeof(*blk_dev), GFP_KERNEL);
if (!blk_dev)
return -ENOMEM;
nsblk = to_nd_namespace_blk(&ndns->dev);
blk_dev->disk_size = nvdimm_namespace_capacity(ndns);
blk_dev->ndbr = to_nd_blk_region(dev->parent);
blk_dev->nsblk = to_nd_namespace_blk(&ndns->dev);
blk_dev->internal_lbasize = roundup(nsblk->lbasize,
INT_LBASIZE_ALIGNMENT);
blk_dev->sector_size = ((nsblk->lbasize >= 4096) ? 4096 : 512);
dev_set_drvdata(dev, blk_dev);
ndns->rw_bytes = nd_blk_rw_bytes;
if (is_nd_btt(dev))
rc = nvdimm_namespace_attach_btt(ndns);
else if (nd_btt_probe(ndns, blk_dev) == 0) {
rc = -ENXIO;
} else
rc = nd_blk_attach_disk(ndns, blk_dev);
if (rc)
kfree(blk_dev);
return rc;
}
static void nd_blk_detach_disk(struct nd_blk_device *blk_dev)
{
del_gendisk(blk_dev->disk);
put_disk(blk_dev->disk);
blk_cleanup_queue(blk_dev->queue);
}
static int nd_blk_remove(struct device *dev)
{
struct nd_blk_device *blk_dev = dev_get_drvdata(dev);
if (is_nd_btt(dev))
nvdimm_namespace_detach_btt(to_nd_btt(dev)->ndns);
else
nd_blk_detach_disk(blk_dev);
kfree(blk_dev);
return 0;
}
static int __init nd_blk_init(void)
{
int rc;
rc = register_blkdev(0, "nd_blk");
if (rc < 0)
return rc;
nd_blk_major = rc;
rc = nd_driver_register(&nd_blk_driver);
if (rc < 0)
unregister_blkdev(nd_blk_major, "nd_blk");
return rc;
}
static void __exit nd_blk_exit(void)
{
driver_unregister(&nd_blk_driver.drv);
unregister_blkdev(nd_blk_major, "nd_blk");
}
