static inline unsigned dio_pages_present(struct dio *dio)
{
return dio->tail - dio->head;
}
static int dio_refill_pages(struct dio *dio)
{
int ret;
int nr_pages;
nr_pages = min(dio->total_pages - dio->curr_page, DIO_PAGES);
ret = get_user_pages_fast(
dio->curr_user_address,
nr_pages,
dio->rw == READ,
&dio->pages[0]);
if (ret < 0 && dio->blocks_available && (dio->rw & WRITE)) {
struct page *page = ZERO_PAGE(0);
if (dio->page_errors == 0)
dio->page_errors = ret;
page_cache_get(page);
dio->pages[0] = page;
dio->head = 0;
dio->tail = 1;
ret = 0;
goto out;
}
if (ret >= 0) {
dio->curr_user_address += ret * PAGE_SIZE;
dio->curr_page += ret;
dio->head = 0;
dio->tail = ret;
ret = 0;
}
out:
return ret;
}
static struct page *dio_get_page(struct dio *dio)
{
if (dio_pages_present(dio) == 0) {
int ret;
ret = dio_refill_pages(dio);
if (ret)
return ERR_PTR(ret);
BUG_ON(dio_pages_present(dio) == 0);
}
return dio->pages[dio->head++];
}
static ssize_t dio_complete(struct dio *dio, loff_t offset, ssize_t ret, bool is_async)
{
ssize_t transferred = 0;
if (ret == -EIOCBQUEUED)
ret = 0;
if (dio->result) {
transferred = dio->result;
if ((dio->rw == READ) && ((offset + transferred) > dio->i_size))
transferred = dio->i_size - offset;
}
if (ret == 0)
ret = dio->page_errors;
if (ret == 0)
ret = dio->io_error;
if (ret == 0)
ret = transferred;
if (dio->end_io && dio->result) {
dio->end_io(dio->iocb, offset, transferred,
dio->map_bh.b_private, ret, is_async);
} else if (is_async) {
aio_complete(dio->iocb, ret, 0);
}
if (dio->flags & DIO_LOCKING)
up_read_non_owner(&dio->inode->i_alloc_sem);
return ret;
}
static void dio_bio_end_aio(struct bio *bio, int error)
{
struct dio *dio = bio->bi_private;
unsigned long remaining;
unsigned long flags;
dio_bio_complete(dio, bio);
spin_lock_irqsave(&dio->bio_lock, flags);
remaining = --dio->refcount;
if (remaining == 1 && dio->waiter)
wake_up_process(dio->waiter);
spin_unlock_irqrestore(&dio->bio_lock, flags);
if (remaining == 0) {
dio_complete(dio, dio->iocb->ki_pos, 0, true);
kfree(dio);
}
}
static void dio_bio_end_io(struct bio *bio, int error)
{
struct dio *dio = bio->bi_private;
unsigned long flags;
spin_lock_irqsave(&dio->bio_lock, flags);
bio->bi_private = dio->bio_list;
dio->bio_list = bio;
if (--dio->refcount == 1 && dio->waiter)
wake_up_process(dio->waiter);
spin_unlock_irqrestore(&dio->bio_lock, flags);
}
void dio_end_io(struct bio *bio, int error)
{
struct dio *dio = bio->bi_private;
if (dio->is_async)
dio_bio_end_aio(bio, error);
else
dio_bio_end_io(bio, error);
}
static void
dio_bio_alloc(struct dio *dio, struct block_device *bdev,
sector_t first_sector, int nr_vecs)
{
struct bio *bio;
bio = bio_alloc(GFP_KERNEL, nr_vecs);
bio->bi_bdev = bdev;
bio->bi_sector = first_sector;
if (dio->is_async)
bio->bi_end_io = dio_bio_end_aio;
else
bio->bi_end_io = dio_bio_end_io;
dio->bio = bio;
dio->logical_offset_in_bio = dio->cur_page_fs_offset;
}
static void dio_bio_submit(struct dio *dio)
{
struct bio *bio = dio->bio;
unsigned long flags;
bio->bi_private = dio;
spin_lock_irqsave(&dio->bio_lock, flags);
dio->refcount++;
spin_unlock_irqrestore(&dio->bio_lock, flags);
if (dio->is_async && dio->rw == READ)
bio_set_pages_dirty(bio);
if (dio->submit_io)
dio->submit_io(dio->rw, bio, dio->inode,
dio->logical_offset_in_bio);
else
submit_bio(dio->rw, bio);
dio->bio = NULL;
dio->boundary = 0;
dio->logical_offset_in_bio = 0;
}
static void dio_cleanup(struct dio *dio)
{
while (dio_pages_present(dio))
page_cache_release(dio_get_page(dio));
}
static struct bio *dio_await_one(struct dio *dio)
{
unsigned long flags;
struct bio *bio = NULL;
spin_lock_irqsave(&dio->bio_lock, flags);
while (dio->refcount > 1 && dio->bio_list == NULL) {
__set_current_state(TASK_UNINTERRUPTIBLE);
dio->waiter = current;
spin_unlock_irqrestore(&dio->bio_lock, flags);
io_schedule();
spin_lock_irqsave(&dio->bio_lock, flags);
dio->waiter = NULL;
}
if (dio->bio_list) {
bio = dio->bio_list;
dio->bio_list = bio->bi_private;
}
spin_unlock_irqrestore(&dio->bio_lock, flags);
return bio;
}
static int dio_bio_complete(struct dio *dio, struct bio *bio)
{
const int uptodate = test_bit(BIO_UPTODATE, &bio->bi_flags);
struct bio_vec *bvec = bio->bi_io_vec;
int page_no;
if (!uptodate)
dio->io_error = -EIO;
if (dio->is_async && dio->rw == READ) {
bio_check_pages_dirty(bio);
} else {
for (page_no = 0; page_no < bio->bi_vcnt; page_no++) {
struct page *page = bvec[page_no].bv_page;
if (dio->rw == READ && !PageCompound(page))
set_page_dirty_lock(page);
page_cache_release(page);
}
bio_put(bio);
}
return uptodate ? 0 : -EIO;
}
static void dio_await_completion(struct dio *dio)
{
struct bio *bio;
do {
bio = dio_await_one(dio);
if (bio)
dio_bio_complete(dio, bio);
} while (bio);
}
static int dio_bio_reap(struct dio *dio)
{
int ret = 0;
if (dio->reap_counter++ >= 64) {
while (dio->bio_list) {
unsigned long flags;
struct bio *bio;
int ret2;
spin_lock_irqsave(&dio->bio_lock, flags);
bio = dio->bio_list;
dio->bio_list = bio->bi_private;
spin_unlock_irqrestore(&dio->bio_lock, flags);
ret2 = dio_bio_complete(dio, bio);
if (ret == 0)
ret = ret2;
}
dio->reap_counter = 0;
}
return ret;
}
static int get_more_blocks(struct dio *dio)
{
int ret;
struct buffer_head *map_bh = &dio->map_bh;
sector_t fs_startblk;
unsigned long fs_count;
unsigned long dio_count;
unsigned long blkmask;
int create;
ret = dio->page_errors;
if (ret == 0) {
BUG_ON(dio->block_in_file >= dio->final_block_in_request);
fs_startblk = dio->block_in_file >> dio->blkfactor;
dio_count = dio->final_block_in_request - dio->block_in_file;
fs_count = dio_count >> dio->blkfactor;
blkmask = (1 << dio->blkfactor) - 1;
if (dio_count & blkmask)
fs_count++;
map_bh->b_state = 0;
map_bh->b_size = fs_count << dio->inode->i_blkbits;
create = dio->rw & WRITE;
if (dio->flags & DIO_SKIP_HOLES) {
if (dio->block_in_file < (i_size_read(dio->inode) >>
dio->blkbits))
create = 0;
}
ret = (*dio->get_block)(dio->inode, fs_startblk,
map_bh, create);
}
return ret;
}
static int dio_new_bio(struct dio *dio, sector_t start_sector)
{
sector_t sector;
int ret, nr_pages;
ret = dio_bio_reap(dio);
if (ret)
goto out;
sector = start_sector << (dio->blkbits - 9);
nr_pages = min(dio->pages_in_io, bio_get_nr_vecs(dio->map_bh.b_bdev));
nr_pages = min(nr_pages, BIO_MAX_PAGES);
BUG_ON(nr_pages <= 0);
dio_bio_alloc(dio, dio->map_bh.b_bdev, sector, nr_pages);
dio->boundary = 0;
out:
return ret;
}
static int dio_bio_add_page(struct dio *dio)
{
int ret;
ret = bio_add_page(dio->bio, dio->cur_page,
dio->cur_page_len, dio->cur_page_offset);
if (ret == dio->cur_page_len) {
if ((dio->cur_page_len + dio->cur_page_offset) == PAGE_SIZE)
dio->pages_in_io--;
page_cache_get(dio->cur_page);
dio->final_block_in_bio = dio->cur_page_block +
(dio->cur_page_len >> dio->blkbits);
ret = 0;
} else {
ret = 1;
}
return ret;
}
static int dio_send_cur_page(struct dio *dio)
{
int ret = 0;
if (dio->bio) {
loff_t cur_offset = dio->cur_page_fs_offset;
loff_t bio_next_offset = dio->logical_offset_in_bio +
dio->bio->bi_size;
if (dio->final_block_in_bio != dio->cur_page_block ||
cur_offset != bio_next_offset)
dio_bio_submit(dio);
else if (dio->boundary)
dio_bio_submit(dio);
}
if (dio->bio == NULL) {
ret = dio_new_bio(dio, dio->cur_page_block);
if (ret)
goto out;
}
if (dio_bio_add_page(dio) != 0) {
dio_bio_submit(dio);
ret = dio_new_bio(dio, dio->cur_page_block);
if (ret == 0) {
ret = dio_bio_add_page(dio);
BUG_ON(ret != 0);
}
}
out:
return ret;
}
static int
submit_page_section(struct dio *dio, struct page *page,
unsigned offset, unsigned len, sector_t blocknr)
{
int ret = 0;
if (dio->rw & WRITE) {
task_io_account_write(len);
}
if ( (dio->cur_page == page) &&
(dio->cur_page_offset + dio->cur_page_len == offset) &&
(dio->cur_page_block +
(dio->cur_page_len >> dio->blkbits) == blocknr)) {
dio->cur_page_len += len;
if (dio->boundary) {
ret = dio_send_cur_page(dio);
page_cache_release(dio->cur_page);
dio->cur_page = NULL;
}
goto out;
}
if (dio->cur_page) {
ret = dio_send_cur_page(dio);
page_cache_release(dio->cur_page);
dio->cur_page = NULL;
if (ret)
goto out;
}
page_cache_get(page);
dio->cur_page = page;
dio->cur_page_offset = offset;
dio->cur_page_len = len;
dio->cur_page_block = blocknr;
dio->cur_page_fs_offset = dio->block_in_file << dio->blkbits;
out:
return ret;
}
static void clean_blockdev_aliases(struct dio *dio)
{
unsigned i;
unsigned nblocks;
nblocks = dio->map_bh.b_size >> dio->inode->i_blkbits;
for (i = 0; i < nblocks; i++) {
unmap_underlying_metadata(dio->map_bh.b_bdev,
dio->map_bh.b_blocknr + i);
}
}
static void dio_zero_block(struct dio *dio, int end)
{
unsigned dio_blocks_per_fs_block;
unsigned this_chunk_blocks;
unsigned this_chunk_bytes;
struct page *page;
dio->start_zero_done = 1;
if (!dio->blkfactor || !buffer_new(&dio->map_bh))
return;
dio_blocks_per_fs_block = 1 << dio->blkfactor;
this_chunk_blocks = dio->block_in_file & (dio_blocks_per_fs_block - 1);
if (!this_chunk_blocks)
return;
if (end)
this_chunk_blocks = dio_blocks_per_fs_block - this_chunk_blocks;
this_chunk_bytes = this_chunk_blocks << dio->blkbits;
page = ZERO_PAGE(0);
if (submit_page_section(dio, page, 0, this_chunk_bytes,
dio->next_block_for_io))
return;
dio->next_block_for_io += this_chunk_blocks;
}
static int do_direct_IO(struct dio *dio)
{
const unsigned blkbits = dio->blkbits;
const unsigned blocks_per_page = PAGE_SIZE >> blkbits;
struct page *page;
unsigned block_in_page;
struct buffer_head *map_bh = &dio->map_bh;
int ret = 0;
block_in_page = dio->first_block_in_page;
while (dio->block_in_file < dio->final_block_in_request) {
page = dio_get_page(dio);
if (IS_ERR(page)) {
ret = PTR_ERR(page);
goto out;
}
while (block_in_page < blocks_per_page) {
unsigned offset_in_page = block_in_page << blkbits;
unsigned this_chunk_bytes;
unsigned this_chunk_blocks;
unsigned u;
if (dio->blocks_available == 0) {
unsigned long blkmask;
unsigned long dio_remainder;
ret = get_more_blocks(dio);
if (ret) {
page_cache_release(page);
goto out;
}
if (!buffer_mapped(map_bh))
goto do_holes;
dio->blocks_available =
map_bh->b_size >> dio->blkbits;
dio->next_block_for_io =
map_bh->b_blocknr << dio->blkfactor;
if (buffer_new(map_bh))
clean_blockdev_aliases(dio);
if (!dio->blkfactor)
goto do_holes;
blkmask = (1 << dio->blkfactor) - 1;
dio_remainder = (dio->block_in_file & blkmask);
if (!buffer_new(map_bh))
dio->next_block_for_io += dio_remainder;
dio->blocks_available -= dio_remainder;
}
do_holes:
if (!buffer_mapped(map_bh)) {
loff_t i_size_aligned;
if (dio->rw & WRITE) {
page_cache_release(page);
return -ENOTBLK;
}
i_size_aligned = ALIGN(i_size_read(dio->inode),
1 << blkbits);
if (dio->block_in_file >=
i_size_aligned >> blkbits) {
page_cache_release(page);
goto out;
}
zero_user(page, block_in_page << blkbits,
1 << blkbits);
dio->block_in_file++;
block_in_page++;
goto next_block;
}
if (unlikely(dio->blkfactor && !dio->start_zero_done))
dio_zero_block(dio, 0);
this_chunk_blocks = dio->blocks_available;
u = (PAGE_SIZE - offset_in_page) >> blkbits;
if (this_chunk_blocks > u)
this_chunk_blocks = u;
u = dio->final_block_in_request - dio->block_in_file;
if (this_chunk_blocks > u)
this_chunk_blocks = u;
this_chunk_bytes = this_chunk_blocks << blkbits;
BUG_ON(this_chunk_bytes == 0);
dio->boundary = buffer_boundary(map_bh);
ret = submit_page_section(dio, page, offset_in_page,
this_chunk_bytes, dio->next_block_for_io);
if (ret) {
page_cache_release(page);
goto out;
}
dio->next_block_for_io += this_chunk_blocks;
dio->block_in_file += this_chunk_blocks;
block_in_page += this_chunk_blocks;
dio->blocks_available -= this_chunk_blocks;
next_block:
BUG_ON(dio->block_in_file > dio->final_block_in_request);
if (dio->block_in_file == dio->final_block_in_request)
break;
}
page_cache_release(page);
block_in_page = 0;
}
out:
return ret;
}
static ssize_t
direct_io_worker(int rw, struct kiocb *iocb, struct inode *inode,
const struct iovec *iov, loff_t offset, unsigned long nr_segs,
unsigned blkbits, get_block_t get_block, dio_iodone_t end_io,
dio_submit_t submit_io, struct dio *dio)
{
unsigned long user_addr;
unsigned long flags;
int seg;
ssize_t ret = 0;
ssize_t ret2;
size_t bytes;
dio->inode = inode;
dio->rw = rw;
dio->blkbits = blkbits;
dio->blkfactor = inode->i_blkbits - blkbits;
dio->block_in_file = offset >> blkbits;
dio->get_block = get_block;
dio->end_io = end_io;
dio->submit_io = submit_io;
dio->final_block_in_bio = -1;
dio->next_block_for_io = -1;
dio->iocb = iocb;
dio->i_size = i_size_read(inode);
spin_lock_init(&dio->bio_lock);
dio->refcount = 1;
if (unlikely(dio->blkfactor))
dio->pages_in_io = 2;
for (seg = 0; seg < nr_segs; seg++) {
user_addr = (unsigned long)iov[seg].iov_base;
dio->pages_in_io +=
((user_addr+iov[seg].iov_len +PAGE_SIZE-1)/PAGE_SIZE
- user_addr/PAGE_SIZE);
}
for (seg = 0; seg < nr_segs; seg++) {
user_addr = (unsigned long)iov[seg].iov_base;
dio->size += bytes = iov[seg].iov_len;
dio->first_block_in_page = (user_addr & ~PAGE_MASK) >> blkbits;
dio->final_block_in_request = dio->block_in_file +
(bytes >> blkbits);
dio->head = 0;
dio->tail = 0;
dio->curr_page = 0;
dio->total_pages = 0;
if (user_addr & (PAGE_SIZE-1)) {
dio->total_pages++;
bytes -= PAGE_SIZE - (user_addr & (PAGE_SIZE - 1));
}
dio->total_pages += (bytes + PAGE_SIZE - 1) / PAGE_SIZE;
dio->curr_user_address = user_addr;
ret = do_direct_IO(dio);
dio->result += iov[seg].iov_len -
((dio->final_block_in_request - dio->block_in_file) <<
blkbits);
if (ret) {
dio_cleanup(dio);
break;
}
}
if (ret == -ENOTBLK) {
ret = 0;
}
dio_zero_block(dio, 1);
if (dio->cur_page) {
ret2 = dio_send_cur_page(dio);
if (ret == 0)
ret = ret2;
page_cache_release(dio->cur_page);
dio->cur_page = NULL;
}
if (dio->bio)
dio_bio_submit(dio);
dio_cleanup(dio);
if (rw == READ && (dio->flags & DIO_LOCKING))
mutex_unlock(&dio->inode->i_mutex);
BUG_ON(ret == -EIOCBQUEUED);
if (dio->is_async && ret == 0 && dio->result &&
((rw & READ) || (dio->result == dio->size)))
ret = -EIOCBQUEUED;
if (ret != -EIOCBQUEUED)
dio_await_completion(dio);
spin_lock_irqsave(&dio->bio_lock, flags);
ret2 = --dio->refcount;
spin_unlock_irqrestore(&dio->bio_lock, flags);
if (ret2 == 0) {
ret = dio_complete(dio, offset, ret, false);
kfree(dio);
} else
BUG_ON(ret != -EIOCBQUEUED);
return ret;
}
ssize_t
__blockdev_direct_IO(int rw, struct kiocb *iocb, struct inode *inode,
struct block_device *bdev, const struct iovec *iov, loff_t offset,
unsigned long nr_segs, get_block_t get_block, dio_iodone_t end_io,
dio_submit_t submit_io, int flags)
{
int seg;
size_t size;
unsigned long addr;
unsigned blkbits = inode->i_blkbits;
unsigned bdev_blkbits = 0;
unsigned blocksize_mask = (1 << blkbits) - 1;
ssize_t retval = -EINVAL;
loff_t end = offset;
struct dio *dio;
if (rw & WRITE)
rw = WRITE_ODIRECT;
if (bdev)
bdev_blkbits = blksize_bits(bdev_logical_block_size(bdev));
if (offset & blocksize_mask) {
if (bdev)
blkbits = bdev_blkbits;
blocksize_mask = (1 << blkbits) - 1;
if (offset & blocksize_mask)
goto out;
}
for (seg = 0; seg < nr_segs; seg++) {
addr = (unsigned long)iov[seg].iov_base;
size = iov[seg].iov_len;
end += size;
if ((addr & blocksize_mask) || (size & blocksize_mask)) {
if (bdev)
blkbits = bdev_blkbits;
blocksize_mask = (1 << blkbits) - 1;
if ((addr & blocksize_mask) || (size & blocksize_mask))
goto out;
}
}
dio = kmalloc(sizeof(*dio), GFP_KERNEL);
retval = -ENOMEM;
if (!dio)
goto out;
memset(dio, 0, offsetof(struct dio, pages));
dio->flags = flags;
if (dio->flags & DIO_LOCKING) {
if (rw == READ && end > offset) {
struct address_space *mapping =
iocb->ki_filp->f_mapping;
mutex_lock(&inode->i_mutex);
retval = filemap_write_and_wait_range(mapping, offset,
end - 1);
if (retval) {
mutex_unlock(&inode->i_mutex);
kfree(dio);
goto out;
}
}
down_read_non_owner(&inode->i_alloc_sem);
}
dio->is_async = !is_sync_kiocb(iocb) && !((rw & WRITE) &&
(end > i_size_read(inode)));
retval = direct_io_worker(rw, iocb, inode, iov, offset,
nr_segs, blkbits, get_block, end_io,
submit_io, dio);
out:
return retval;
}
