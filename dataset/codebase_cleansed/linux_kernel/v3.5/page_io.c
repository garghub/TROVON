static struct bio *get_swap_bio(gfp_t gfp_flags,
struct page *page, bio_end_io_t end_io)
{
struct bio *bio;
bio = bio_alloc(gfp_flags, 1);
if (bio) {
bio->bi_sector = map_swap_page(page, &bio->bi_bdev);
bio->bi_sector <<= PAGE_SHIFT - 9;
bio->bi_io_vec[0].bv_page = page;
bio->bi_io_vec[0].bv_len = PAGE_SIZE;
bio->bi_io_vec[0].bv_offset = 0;
bio->bi_vcnt = 1;
bio->bi_idx = 0;
bio->bi_size = PAGE_SIZE;
bio->bi_end_io = end_io;
}
return bio;
}
static void end_swap_bio_write(struct bio *bio, int err)
{
const int uptodate = test_bit(BIO_UPTODATE, &bio->bi_flags);
struct page *page = bio->bi_io_vec[0].bv_page;
if (!uptodate) {
SetPageError(page);
set_page_dirty(page);
printk(KERN_ALERT "Write-error on swap-device (%u:%u:%Lu)\n",
imajor(bio->bi_bdev->bd_inode),
iminor(bio->bi_bdev->bd_inode),
(unsigned long long)bio->bi_sector);
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
(unsigned long long)bio->bi_sector);
} else {
SetPageUptodate(page);
}
unlock_page(page);
bio_put(bio);
}
int swap_writepage(struct page *page, struct writeback_control *wbc)
{
struct bio *bio;
int ret = 0, rw = WRITE;
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
bio = get_swap_bio(GFP_NOIO, page, end_swap_bio_write);
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
VM_BUG_ON(!PageLocked(page));
VM_BUG_ON(PageUptodate(page));
if (frontswap_load(page) == 0) {
SetPageUptodate(page);
unlock_page(page);
goto out;
}
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
