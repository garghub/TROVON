static struct bio *get_swap_bio(gfp_t gfp_flags,
struct page *page, bio_end_io_t end_io)
{
struct bio *bio;
bio = bio_alloc(gfp_flags, 1);
if (bio) {
bio->bi_iter.bi_sector = map_swap_page(page, &bio->bi_bdev);
bio->bi_iter.bi_sector <<= PAGE_SHIFT - 9;
bio->bi_io_vec[0].bv_page = page;
bio->bi_io_vec[0].bv_len = PAGE_SIZE;
bio->bi_io_vec[0].bv_offset = 0;
bio->bi_vcnt = 1;
bio->bi_iter.bi_size = PAGE_SIZE;
bio->bi_end_io = end_io;
}
return bio;
}
void end_swap_bio_write(struct bio *bio, int err)
{
const int uptodate = test_bit(BIO_UPTODATE, &bio->bi_flags);
struct page *page = bio->bi_io_vec[0].bv_page;
if (!uptodate) {
SetPageError(page);
set_page_dirty(page);
printk(KERN_ALERT "Write-error on swap-device (%u:%u:%Lu)\n",
imajor(bio->bi_bdev->bd_inode),
iminor(bio->bi_bdev->bd_inode),
(unsigned long long)bio->bi_iter.bi_sector);
ClearPageReclaim(page);
}
end_page_writeback(page);
bio_put(bio);
}
void end_swap_bio_read(struct bio *bio, int err)
{
const int uptodate = test_bit(BIO_UPTODATE, &bio->bi_flags);
struct page *page = bio->bi_io_vec[0].bv_page;
if (!uptodate) {
SetPageError(page);
ClearPageUptodate(page);
printk(KERN_ALERT "Read-error on swap-device (%u:%u:%Lu)\n",
imajor(bio->bi_bdev->bd_inode),
iminor(bio->bi_bdev->bd_inode),
(unsigned long long)bio->bi_iter.bi_sector);
goto out;
}
SetPageUptodate(page);
if (likely(PageSwapCache(page))) {
struct swap_info_struct *sis;
sis = page_swap_info(page);
if (sis->flags & SWP_BLKDEV) {
struct gendisk *disk = sis->bdev->bd_disk;
if (disk->fops->swap_slot_free_notify) {
swp_entry_t entry;
unsigned long offset;
entry.val = page_private(page);
offset = swp_offset(entry);
SetPageDirty(page);
disk->fops->swap_slot_free_notify(sis->bdev,
offset);
}
}
}
out:
unlock_page(page);
bio_put(bio);
}
int generic_swapfile_activate(struct swap_info_struct *sis,
struct file *swap_file,
sector_t *span)
{
struct address_space *mapping = swap_file->f_mapping;
struct inode *inode = mapping->host;
unsigned blocks_per_page;
unsigned long page_no;
unsigned blkbits;
sector_t probe_block;
sector_t last_block;
sector_t lowest_block = -1;
sector_t highest_block = 0;
int nr_extents = 0;
int ret;
blkbits = inode->i_blkbits;
blocks_per_page = PAGE_SIZE >> blkbits;
probe_block = 0;
page_no = 0;
last_block = i_size_read(inode) >> blkbits;
while ((probe_block + blocks_per_page) <= last_block &&
page_no < sis->max) {
unsigned block_in_page;
sector_t first_block;
first_block = bmap(inode, probe_block);
if (first_block == 0)
goto bad_bmap;
if (first_block & (blocks_per_page - 1)) {
probe_block++;
goto reprobe;
}
for (block_in_page = 1; block_in_page < blocks_per_page;
block_in_page++) {
sector_t block;
block = bmap(inode, probe_block + block_in_page);
if (block == 0)
goto bad_bmap;
if (block != first_block + block_in_page) {
probe_block++;
goto reprobe;
}
}
first_block >>= (PAGE_SHIFT - blkbits);
if (page_no) {
if (first_block < lowest_block)
lowest_block = first_block;
if (first_block > highest_block)
highest_block = first_block;
}
ret = add_swap_extent(sis, page_no, 1, first_block);
if (ret < 0)
goto out;
nr_extents += ret;
page_no++;
probe_block += blocks_per_page;
reprobe:
continue;
}
ret = nr_extents;
*span = 1 + highest_block - lowest_block;
if (page_no == 0)
page_no = 1;
sis->max = page_no;
sis->pages = page_no - 1;
sis->highest_bit = page_no - 1;
out:
return ret;
bad_bmap:
printk(KERN_ERR "swapon: swapfile has holes\n");
ret = -EINVAL;
goto out;
}
int swap_writepage(struct page *page, struct writeback_control *wbc)
{
int ret = 0;
if (try_to_free_swap(page)) {
unlock_page(page);
goto out;
}
if (frontswap_store(page) == 0) {
set_page_writeback(page);
unlock_page(page);
end_page_writeback(page);
goto out;
}
ret = __swap_writepage(page, wbc, end_swap_bio_write);
out:
return ret;
}
static sector_t swap_page_sector(struct page *page)
{
return (sector_t)__page_file_index(page) << (PAGE_CACHE_SHIFT - 9);
}
int __swap_writepage(struct page *page, struct writeback_control *wbc,
void (*end_write_func)(struct bio *, int))
{
struct bio *bio;
int ret, rw = WRITE;
struct swap_info_struct *sis = page_swap_info(page);
if (sis->flags & SWP_FILE) {
struct kiocb kiocb;
struct file *swap_file = sis->swap_file;
struct address_space *mapping = swap_file->f_mapping;
struct bio_vec bv = {
.bv_page = page,
.bv_len = PAGE_SIZE,
.bv_offset = 0
};
struct iov_iter from = {
.type = ITER_BVEC | WRITE,
.count = PAGE_SIZE,
.iov_offset = 0,
.nr_segs = 1,
};
from.bvec = &bv;
init_sync_kiocb(&kiocb, swap_file);
kiocb.ki_pos = page_file_offset(page);
kiocb.ki_nbytes = PAGE_SIZE;
set_page_writeback(page);
unlock_page(page);
ret = mapping->a_ops->direct_IO(ITER_BVEC | WRITE,
&kiocb, &from,
kiocb.ki_pos);
if (ret == PAGE_SIZE) {
count_vm_event(PSWPOUT);
ret = 0;
} else {
set_page_dirty(page);
ClearPageReclaim(page);
pr_err_ratelimited("Write error on dio swapfile (%Lu)\n",
page_file_offset(page));
}
end_page_writeback(page);
return ret;
}
ret = bdev_write_page(sis->bdev, swap_page_sector(page), page, wbc);
if (!ret) {
count_vm_event(PSWPOUT);
return 0;
}
ret = 0;
bio = get_swap_bio(GFP_NOIO, page, end_write_func);
if (bio == NULL) {
set_page_dirty(page);
unlock_page(page);
ret = -ENOMEM;
goto out;
}
if (wbc->sync_mode == WB_SYNC_ALL)
rw |= REQ_SYNC;
count_vm_event(PSWPOUT);
set_page_writeback(page);
unlock_page(page);
submit_bio(rw, bio);
out:
return ret;
}
int swap_readpage(struct page *page)
{
struct bio *bio;
int ret = 0;
struct swap_info_struct *sis = page_swap_info(page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(PageUptodate(page), page);
if (frontswap_load(page) == 0) {
SetPageUptodate(page);
unlock_page(page);
goto out;
}
if (sis->flags & SWP_FILE) {
struct file *swap_file = sis->swap_file;
struct address_space *mapping = swap_file->f_mapping;
ret = mapping->a_ops->readpage(swap_file, page);
if (!ret)
count_vm_event(PSWPIN);
return ret;
}
ret = bdev_read_page(sis->bdev, swap_page_sector(page), page);
if (!ret) {
count_vm_event(PSWPIN);
return 0;
}
ret = 0;
bio = get_swap_bio(GFP_KERNEL, page, end_swap_bio_read);
if (bio == NULL) {
unlock_page(page);
ret = -ENOMEM;
goto out;
}
count_vm_event(PSWPIN);
submit_bio(READ, bio);
out:
return ret;
}
int swap_set_page_dirty(struct page *page)
{
struct swap_info_struct *sis = page_swap_info(page);
if (sis->flags & SWP_FILE) {
struct address_space *mapping = sis->swap_file->f_mapping;
return mapping->a_ops->set_page_dirty(page);
} else {
return __set_page_dirty_no_writeback(page);
}
}
