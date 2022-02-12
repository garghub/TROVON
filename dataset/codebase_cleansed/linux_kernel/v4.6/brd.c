static struct page *brd_lookup_page(struct brd_device *brd, sector_t sector)
{
pgoff_t idx;
struct page *page;
rcu_read_lock();
idx = sector >> PAGE_SECTORS_SHIFT;
page = radix_tree_lookup(&brd->brd_pages, idx);
rcu_read_unlock();
BUG_ON(page && page->index != idx);
return page;
}
static struct page *brd_insert_page(struct brd_device *brd, sector_t sector)
{
pgoff_t idx;
struct page *page;
gfp_t gfp_flags;
page = brd_lookup_page(brd, sector);
if (page)
return page;
gfp_flags = GFP_NOIO | __GFP_ZERO;
#ifndef CONFIG_BLK_DEV_RAM_DAX
gfp_flags |= __GFP_HIGHMEM;
#endif
page = alloc_page(gfp_flags);
if (!page)
return NULL;
if (radix_tree_preload(GFP_NOIO)) {
__free_page(page);
return NULL;
}
spin_lock(&brd->brd_lock);
idx = sector >> PAGE_SECTORS_SHIFT;
page->index = idx;
if (radix_tree_insert(&brd->brd_pages, idx, page)) {
__free_page(page);
page = radix_tree_lookup(&brd->brd_pages, idx);
BUG_ON(!page);
BUG_ON(page->index != idx);
}
spin_unlock(&brd->brd_lock);
radix_tree_preload_end();
return page;
}
static void brd_free_page(struct brd_device *brd, sector_t sector)
{
struct page *page;
pgoff_t idx;
spin_lock(&brd->brd_lock);
idx = sector >> PAGE_SECTORS_SHIFT;
page = radix_tree_delete(&brd->brd_pages, idx);
spin_unlock(&brd->brd_lock);
if (page)
__free_page(page);
}
static void brd_zero_page(struct brd_device *brd, sector_t sector)
{
struct page *page;
page = brd_lookup_page(brd, sector);
if (page)
clear_highpage(page);
}
static void brd_free_pages(struct brd_device *brd)
{
unsigned long pos = 0;
struct page *pages[FREE_BATCH];
int nr_pages;
do {
int i;
nr_pages = radix_tree_gang_lookup(&brd->brd_pages,
(void **)pages, pos, FREE_BATCH);
for (i = 0; i < nr_pages; i++) {
void *ret;
BUG_ON(pages[i]->index < pos);
pos = pages[i]->index;
ret = radix_tree_delete(&brd->brd_pages, pos);
BUG_ON(!ret || ret != pages[i]);
__free_page(pages[i]);
}
pos++;
} while (nr_pages == FREE_BATCH);
}
static int copy_to_brd_setup(struct brd_device *brd, sector_t sector, size_t n)
{
unsigned int offset = (sector & (PAGE_SECTORS-1)) << SECTOR_SHIFT;
size_t copy;
copy = min_t(size_t, n, PAGE_SIZE - offset);
if (!brd_insert_page(brd, sector))
return -ENOSPC;
if (copy < n) {
sector += copy >> SECTOR_SHIFT;
if (!brd_insert_page(brd, sector))
return -ENOSPC;
}
return 0;
}
static void discard_from_brd(struct brd_device *brd,
sector_t sector, size_t n)
{
while (n >= PAGE_SIZE) {
if (0)
brd_free_page(brd, sector);
else
brd_zero_page(brd, sector);
sector += PAGE_SIZE >> SECTOR_SHIFT;
n -= PAGE_SIZE;
}
}
static void copy_to_brd(struct brd_device *brd, const void *src,
sector_t sector, size_t n)
{
struct page *page;
void *dst;
unsigned int offset = (sector & (PAGE_SECTORS-1)) << SECTOR_SHIFT;
size_t copy;
copy = min_t(size_t, n, PAGE_SIZE - offset);
page = brd_lookup_page(brd, sector);
BUG_ON(!page);
dst = kmap_atomic(page);
memcpy(dst + offset, src, copy);
kunmap_atomic(dst);
if (copy < n) {
src += copy;
sector += copy >> SECTOR_SHIFT;
copy = n - copy;
page = brd_lookup_page(brd, sector);
BUG_ON(!page);
dst = kmap_atomic(page);
memcpy(dst, src, copy);
kunmap_atomic(dst);
}
}
static void copy_from_brd(void *dst, struct brd_device *brd,
sector_t sector, size_t n)
{
struct page *page;
void *src;
unsigned int offset = (sector & (PAGE_SECTORS-1)) << SECTOR_SHIFT;
size_t copy;
copy = min_t(size_t, n, PAGE_SIZE - offset);
page = brd_lookup_page(brd, sector);
if (page) {
src = kmap_atomic(page);
memcpy(dst, src + offset, copy);
kunmap_atomic(src);
} else
memset(dst, 0, copy);
if (copy < n) {
dst += copy;
sector += copy >> SECTOR_SHIFT;
copy = n - copy;
page = brd_lookup_page(brd, sector);
if (page) {
src = kmap_atomic(page);
memcpy(dst, src, copy);
kunmap_atomic(src);
} else
memset(dst, 0, copy);
}
}
static int brd_do_bvec(struct brd_device *brd, struct page *page,
unsigned int len, unsigned int off, int rw,
sector_t sector)
{
void *mem;
int err = 0;
if (rw != READ) {
err = copy_to_brd_setup(brd, sector, len);
if (err)
goto out;
}
mem = kmap_atomic(page);
if (rw == READ) {
copy_from_brd(mem + off, brd, sector, len);
flush_dcache_page(page);
} else {
flush_dcache_page(page);
copy_to_brd(brd, mem + off, sector, len);
}
kunmap_atomic(mem);
out:
return err;
}
static blk_qc_t brd_make_request(struct request_queue *q, struct bio *bio)
{
struct block_device *bdev = bio->bi_bdev;
struct brd_device *brd = bdev->bd_disk->private_data;
int rw;
struct bio_vec bvec;
sector_t sector;
struct bvec_iter iter;
sector = bio->bi_iter.bi_sector;
if (bio_end_sector(bio) > get_capacity(bdev->bd_disk))
goto io_error;
if (unlikely(bio->bi_rw & REQ_DISCARD)) {
if (sector & ((PAGE_SIZE >> SECTOR_SHIFT) - 1) ||
bio->bi_iter.bi_size & ~PAGE_MASK)
goto io_error;
discard_from_brd(brd, sector, bio->bi_iter.bi_size);
goto out;
}
rw = bio_rw(bio);
if (rw == READA)
rw = READ;
bio_for_each_segment(bvec, bio, iter) {
unsigned int len = bvec.bv_len;
int err;
err = brd_do_bvec(brd, bvec.bv_page, len,
bvec.bv_offset, rw, sector);
if (err)
goto io_error;
sector += len >> SECTOR_SHIFT;
}
out:
bio_endio(bio);
return BLK_QC_T_NONE;
io_error:
bio_io_error(bio);
return BLK_QC_T_NONE;
}
static int brd_rw_page(struct block_device *bdev, sector_t sector,
struct page *page, int rw)
{
struct brd_device *brd = bdev->bd_disk->private_data;
int err = brd_do_bvec(brd, page, PAGE_SIZE, 0, rw, sector);
page_endio(page, rw & WRITE, err);
return err;
}
static long brd_direct_access(struct block_device *bdev, sector_t sector,
void __pmem **kaddr, pfn_t *pfn)
{
struct brd_device *brd = bdev->bd_disk->private_data;
struct page *page;
if (!brd)
return -ENODEV;
page = brd_insert_page(brd, sector);
if (!page)
return -ENOSPC;
*kaddr = (void __pmem *)page_address(page);
*pfn = page_to_pfn_t(page);
return PAGE_SIZE;
}
static int brd_ioctl(struct block_device *bdev, fmode_t mode,
unsigned int cmd, unsigned long arg)
{
int error;
struct brd_device *brd = bdev->bd_disk->private_data;
if (cmd != BLKFLSBUF)
return -ENOTTY;
mutex_lock(&brd_mutex);
mutex_lock(&bdev->bd_mutex);
error = -EBUSY;
if (bdev->bd_openers <= 1) {
kill_bdev(bdev);
brd_free_pages(brd);
error = 0;
}
mutex_unlock(&bdev->bd_mutex);
mutex_unlock(&brd_mutex);
return error;
}
static int __init ramdisk_size(char *str)
{
rd_size = simple_strtol(str, NULL, 0);
return 1;
}
static struct brd_device *brd_alloc(int i)
{
struct brd_device *brd;
struct gendisk *disk;
brd = kzalloc(sizeof(*brd), GFP_KERNEL);
if (!brd)
goto out;
brd->brd_number = i;
spin_lock_init(&brd->brd_lock);
INIT_RADIX_TREE(&brd->brd_pages, GFP_ATOMIC);
brd->brd_queue = blk_alloc_queue(GFP_KERNEL);
if (!brd->brd_queue)
goto out_free_dev;
blk_queue_make_request(brd->brd_queue, brd_make_request);
blk_queue_max_hw_sectors(brd->brd_queue, 1024);
blk_queue_bounce_limit(brd->brd_queue, BLK_BOUNCE_ANY);
blk_queue_physical_block_size(brd->brd_queue, PAGE_SIZE);
brd->brd_queue->limits.discard_granularity = PAGE_SIZE;
blk_queue_max_discard_sectors(brd->brd_queue, UINT_MAX);
brd->brd_queue->limits.discard_zeroes_data = 1;
queue_flag_set_unlocked(QUEUE_FLAG_DISCARD, brd->brd_queue);
disk = brd->brd_disk = alloc_disk(max_part);
if (!disk)
goto out_free_queue;
disk->major = RAMDISK_MAJOR;
disk->first_minor = i * max_part;
disk->fops = &brd_fops;
disk->private_data = brd;
disk->queue = brd->brd_queue;
disk->flags = GENHD_FL_EXT_DEVT;
sprintf(disk->disk_name, "ram%d", i);
set_capacity(disk, rd_size * 2);
return brd;
out_free_queue:
blk_cleanup_queue(brd->brd_queue);
out_free_dev:
kfree(brd);
out:
return NULL;
}
static void brd_free(struct brd_device *brd)
{
put_disk(brd->brd_disk);
blk_cleanup_queue(brd->brd_queue);
brd_free_pages(brd);
kfree(brd);
}
static struct brd_device *brd_init_one(int i, bool *new)
{
struct brd_device *brd;
*new = false;
list_for_each_entry(brd, &brd_devices, brd_list) {
if (brd->brd_number == i)
goto out;
}
brd = brd_alloc(i);
if (brd) {
add_disk(brd->brd_disk);
list_add_tail(&brd->brd_list, &brd_devices);
}
*new = true;
out:
return brd;
}
static void brd_del_one(struct brd_device *brd)
{
list_del(&brd->brd_list);
del_gendisk(brd->brd_disk);
brd_free(brd);
}
static struct kobject *brd_probe(dev_t dev, int *part, void *data)
{
struct brd_device *brd;
struct kobject *kobj;
bool new;
mutex_lock(&brd_devices_mutex);
brd = brd_init_one(MINOR(dev) / max_part, &new);
kobj = brd ? get_disk(brd->brd_disk) : NULL;
mutex_unlock(&brd_devices_mutex);
if (new)
*part = 0;
return kobj;
}
static int __init brd_init(void)
{
struct brd_device *brd, *next;
int i;
if (register_blkdev(RAMDISK_MAJOR, "ramdisk"))
return -EIO;
if (unlikely(!max_part))
max_part = 1;
for (i = 0; i < rd_nr; i++) {
brd = brd_alloc(i);
if (!brd)
goto out_free;
list_add_tail(&brd->brd_list, &brd_devices);
}
list_for_each_entry(brd, &brd_devices, brd_list)
add_disk(brd->brd_disk);
blk_register_region(MKDEV(RAMDISK_MAJOR, 0), 1UL << MINORBITS,
THIS_MODULE, brd_probe, NULL, NULL);
pr_info("brd: module loaded\n");
return 0;
out_free:
list_for_each_entry_safe(brd, next, &brd_devices, brd_list) {
list_del(&brd->brd_list);
brd_free(brd);
}
unregister_blkdev(RAMDISK_MAJOR, "ramdisk");
pr_info("brd: module NOT loaded !!!\n");
return -ENOMEM;
}
static void __exit brd_exit(void)
{
struct brd_device *brd, *next;
list_for_each_entry_safe(brd, next, &brd_devices, brd_list)
brd_del_one(brd);
blk_unregister_region(MKDEV(RAMDISK_MAJOR, 0), 1UL << MINORBITS);
unregister_blkdev(RAMDISK_MAJOR, "ramdisk");
pr_info("brd: module unloaded\n");
}
