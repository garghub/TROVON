static inline unsigned dio_pages_present(struct dio_submit *sdio)
{
return sdio->tail - sdio->head;
}
static inline int dio_refill_pages(struct dio *dio, struct dio_submit *sdio)
{
ssize_t ret;
ret = iov_iter_get_pages(sdio->iter, dio->pages, LONG_MAX, DIO_PAGES,
&sdio->from);
if (ret < 0 && sdio->blocks_available && (dio->rw & WRITE)) {
struct page *page = ZERO_PAGE(0);
if (dio->page_errors == 0)
dio->page_errors = ret;
get_page(page);
dio->pages[0] = page;
sdio->head = 0;
sdio->tail = 1;
sdio->from = 0;
sdio->to = PAGE_SIZE;
return 0;
}
if (ret >= 0) {
iov_iter_advance(sdio->iter, ret);
ret += sdio->from;
sdio->head = 0;
sdio->tail = (ret + PAGE_SIZE - 1) / PAGE_SIZE;
sdio->to = ((ret - 1) & (PAGE_SIZE - 1)) + 1;
return 0;
}
return ret;
}
static inline struct page *dio_get_page(struct dio *dio,
struct dio_submit *sdio)
{
if (dio_pages_present(sdio) == 0) {
int ret;
ret = dio_refill_pages(dio, sdio);
if (ret)
return ERR_PTR(ret);
BUG_ON(dio_pages_present(sdio) == 0);
}
return dio->pages[sdio->head];
}
static ssize_t dio_complete(struct dio *dio, ssize_t ret, bool is_async)
{
loff_t offset = dio->iocb->ki_pos;
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
if (dio->end_io) {
int err;
err = dio->end_io(dio->iocb, offset, ret, dio->private);
if (err)
ret = err;
}
if (!(dio->flags & DIO_SKIP_DIO_COUNT))
inode_dio_end(dio->inode);
if (is_async) {
dio->iocb->ki_pos += transferred;
if (dio->rw & WRITE)
ret = generic_write_sync(dio->iocb, transferred);
dio->iocb->ki_complete(dio->iocb, ret, 0);
}
kmem_cache_free(dio_cache, dio);
return ret;
}
static void dio_aio_complete_work(struct work_struct *work)
{
struct dio *dio = container_of(work, struct dio, complete_work);
dio_complete(dio, 0, true);
}
static void dio_bio_end_aio(struct bio *bio)
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
if (dio->result && dio->defer_completion) {
INIT_WORK(&dio->complete_work, dio_aio_complete_work);
queue_work(dio->inode->i_sb->s_dio_done_wq,
&dio->complete_work);
} else {
dio_complete(dio, 0, true);
}
}
}
static void dio_bio_end_io(struct bio *bio)
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
dio_bio_end_aio(bio);
else
dio_bio_end_io(bio);
}
static inline void
dio_bio_alloc(struct dio *dio, struct dio_submit *sdio,
struct block_device *bdev,
sector_t first_sector, int nr_vecs)
{
struct bio *bio;
bio = bio_alloc(GFP_KERNEL, nr_vecs);
bio->bi_bdev = bdev;
bio->bi_iter.bi_sector = first_sector;
if (dio->is_async)
bio->bi_end_io = dio_bio_end_aio;
else
bio->bi_end_io = dio_bio_end_io;
sdio->bio = bio;
sdio->logical_offset_in_bio = sdio->cur_page_fs_offset;
}
static inline void dio_bio_submit(struct dio *dio, struct dio_submit *sdio)
{
struct bio *bio = sdio->bio;
unsigned long flags;
bio->bi_private = dio;
spin_lock_irqsave(&dio->bio_lock, flags);
dio->refcount++;
spin_unlock_irqrestore(&dio->bio_lock, flags);
if (dio->is_async && dio->rw == READ && dio->should_dirty)
bio_set_pages_dirty(bio);
dio->bio_bdev = bio->bi_bdev;
if (sdio->submit_io) {
sdio->submit_io(dio->rw, bio, dio->inode,
sdio->logical_offset_in_bio);
dio->bio_cookie = BLK_QC_T_NONE;
} else
dio->bio_cookie = submit_bio(dio->rw, bio);
sdio->bio = NULL;
sdio->boundary = 0;
sdio->logical_offset_in_bio = 0;
}
static inline void dio_cleanup(struct dio *dio, struct dio_submit *sdio)
{
while (sdio->head < sdio->tail)
put_page(dio->pages[sdio->head++]);
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
if (!(dio->iocb->ki_flags & IOCB_HIPRI) ||
!blk_poll(bdev_get_queue(dio->bio_bdev), dio->bio_cookie))
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
struct bio_vec *bvec;
unsigned i;
int err;
if (bio->bi_error)
dio->io_error = -EIO;
if (dio->is_async && dio->rw == READ && dio->should_dirty) {
err = bio->bi_error;
bio_check_pages_dirty(bio);
} else {
bio_for_each_segment_all(bvec, bio, i) {
struct page *page = bvec->bv_page;
if (dio->rw == READ && !PageCompound(page) &&
dio->should_dirty)
set_page_dirty_lock(page);
put_page(page);
}
err = bio->bi_error;
bio_put(bio);
}
return err;
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
static inline int dio_bio_reap(struct dio *dio, struct dio_submit *sdio)
{
int ret = 0;
if (sdio->reap_counter++ >= 64) {
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
sdio->reap_counter = 0;
}
return ret;
}
static int sb_init_dio_done_wq(struct super_block *sb)
{
struct workqueue_struct *old;
struct workqueue_struct *wq = alloc_workqueue("dio/%s",
WQ_MEM_RECLAIM, 0,
sb->s_id);
if (!wq)
return -ENOMEM;
old = cmpxchg(&sb->s_dio_done_wq, NULL, wq);
if (old)
destroy_workqueue(wq);
return 0;
}
static int dio_set_defer_completion(struct dio *dio)
{
struct super_block *sb = dio->inode->i_sb;
if (dio->defer_completion)
return 0;
dio->defer_completion = true;
if (!sb->s_dio_done_wq)
return sb_init_dio_done_wq(sb);
return 0;
}
static int get_more_blocks(struct dio *dio, struct dio_submit *sdio,
struct buffer_head *map_bh)
{
int ret;
sector_t fs_startblk;
sector_t fs_endblk;
unsigned long fs_count;
int create;
unsigned int i_blkbits = sdio->blkbits + sdio->blkfactor;
ret = dio->page_errors;
if (ret == 0) {
BUG_ON(sdio->block_in_file >= sdio->final_block_in_request);
fs_startblk = sdio->block_in_file >> sdio->blkfactor;
fs_endblk = (sdio->final_block_in_request - 1) >>
sdio->blkfactor;
fs_count = fs_endblk - fs_startblk + 1;
map_bh->b_state = 0;
map_bh->b_size = fs_count << i_blkbits;
create = dio->rw & WRITE;
if (dio->flags & DIO_SKIP_HOLES) {
if (fs_startblk <= ((i_size_read(dio->inode) - 1) >>
i_blkbits))
create = 0;
}
ret = (*sdio->get_block)(dio->inode, fs_startblk,
map_bh, create);
dio->private = map_bh->b_private;
if (ret == 0 && buffer_defer_completion(map_bh))
ret = dio_set_defer_completion(dio);
}
return ret;
}
static inline int dio_new_bio(struct dio *dio, struct dio_submit *sdio,
sector_t start_sector, struct buffer_head *map_bh)
{
sector_t sector;
int ret, nr_pages;
ret = dio_bio_reap(dio, sdio);
if (ret)
goto out;
sector = start_sector << (sdio->blkbits - 9);
nr_pages = min(sdio->pages_in_io, BIO_MAX_PAGES);
BUG_ON(nr_pages <= 0);
dio_bio_alloc(dio, sdio, map_bh->b_bdev, sector, nr_pages);
sdio->boundary = 0;
out:
return ret;
}
static inline int dio_bio_add_page(struct dio_submit *sdio)
{
int ret;
ret = bio_add_page(sdio->bio, sdio->cur_page,
sdio->cur_page_len, sdio->cur_page_offset);
if (ret == sdio->cur_page_len) {
if ((sdio->cur_page_len + sdio->cur_page_offset) == PAGE_SIZE)
sdio->pages_in_io--;
get_page(sdio->cur_page);
sdio->final_block_in_bio = sdio->cur_page_block +
(sdio->cur_page_len >> sdio->blkbits);
ret = 0;
} else {
ret = 1;
}
return ret;
}
static inline int dio_send_cur_page(struct dio *dio, struct dio_submit *sdio,
struct buffer_head *map_bh)
{
int ret = 0;
if (sdio->bio) {
loff_t cur_offset = sdio->cur_page_fs_offset;
loff_t bio_next_offset = sdio->logical_offset_in_bio +
sdio->bio->bi_iter.bi_size;
if (sdio->final_block_in_bio != sdio->cur_page_block ||
cur_offset != bio_next_offset)
dio_bio_submit(dio, sdio);
}
if (sdio->bio == NULL) {
ret = dio_new_bio(dio, sdio, sdio->cur_page_block, map_bh);
if (ret)
goto out;
}
if (dio_bio_add_page(sdio) != 0) {
dio_bio_submit(dio, sdio);
ret = dio_new_bio(dio, sdio, sdio->cur_page_block, map_bh);
if (ret == 0) {
ret = dio_bio_add_page(sdio);
BUG_ON(ret != 0);
}
}
out:
return ret;
}
static inline int
submit_page_section(struct dio *dio, struct dio_submit *sdio, struct page *page,
unsigned offset, unsigned len, sector_t blocknr,
struct buffer_head *map_bh)
{
int ret = 0;
if (dio->rw & WRITE) {
task_io_account_write(len);
}
if (sdio->cur_page == page &&
sdio->cur_page_offset + sdio->cur_page_len == offset &&
sdio->cur_page_block +
(sdio->cur_page_len >> sdio->blkbits) == blocknr) {
sdio->cur_page_len += len;
goto out;
}
if (sdio->cur_page) {
ret = dio_send_cur_page(dio, sdio, map_bh);
put_page(sdio->cur_page);
sdio->cur_page = NULL;
if (ret)
return ret;
}
get_page(page);
sdio->cur_page = page;
sdio->cur_page_offset = offset;
sdio->cur_page_len = len;
sdio->cur_page_block = blocknr;
sdio->cur_page_fs_offset = sdio->block_in_file << sdio->blkbits;
out:
if (sdio->boundary) {
ret = dio_send_cur_page(dio, sdio, map_bh);
dio_bio_submit(dio, sdio);
put_page(sdio->cur_page);
sdio->cur_page = NULL;
}
return ret;
}
static void clean_blockdev_aliases(struct dio *dio, struct buffer_head *map_bh)
{
unsigned i;
unsigned nblocks;
nblocks = map_bh->b_size >> dio->inode->i_blkbits;
for (i = 0; i < nblocks; i++) {
unmap_underlying_metadata(map_bh->b_bdev,
map_bh->b_blocknr + i);
}
}
static inline void dio_zero_block(struct dio *dio, struct dio_submit *sdio,
int end, struct buffer_head *map_bh)
{
unsigned dio_blocks_per_fs_block;
unsigned this_chunk_blocks;
unsigned this_chunk_bytes;
struct page *page;
sdio->start_zero_done = 1;
if (!sdio->blkfactor || !buffer_new(map_bh))
return;
dio_blocks_per_fs_block = 1 << sdio->blkfactor;
this_chunk_blocks = sdio->block_in_file & (dio_blocks_per_fs_block - 1);
if (!this_chunk_blocks)
return;
if (end)
this_chunk_blocks = dio_blocks_per_fs_block - this_chunk_blocks;
this_chunk_bytes = this_chunk_blocks << sdio->blkbits;
page = ZERO_PAGE(0);
if (submit_page_section(dio, sdio, page, 0, this_chunk_bytes,
sdio->next_block_for_io, map_bh))
return;
sdio->next_block_for_io += this_chunk_blocks;
}
static int do_direct_IO(struct dio *dio, struct dio_submit *sdio,
struct buffer_head *map_bh)
{
const unsigned blkbits = sdio->blkbits;
int ret = 0;
while (sdio->block_in_file < sdio->final_block_in_request) {
struct page *page;
size_t from, to;
page = dio_get_page(dio, sdio);
if (IS_ERR(page)) {
ret = PTR_ERR(page);
goto out;
}
from = sdio->head ? 0 : sdio->from;
to = (sdio->head == sdio->tail - 1) ? sdio->to : PAGE_SIZE;
sdio->head++;
while (from < to) {
unsigned this_chunk_bytes;
unsigned this_chunk_blocks;
unsigned u;
if (sdio->blocks_available == 0) {
unsigned long blkmask;
unsigned long dio_remainder;
ret = get_more_blocks(dio, sdio, map_bh);
if (ret) {
put_page(page);
goto out;
}
if (!buffer_mapped(map_bh))
goto do_holes;
sdio->blocks_available =
map_bh->b_size >> sdio->blkbits;
sdio->next_block_for_io =
map_bh->b_blocknr << sdio->blkfactor;
if (buffer_new(map_bh))
clean_blockdev_aliases(dio, map_bh);
if (!sdio->blkfactor)
goto do_holes;
blkmask = (1 << sdio->blkfactor) - 1;
dio_remainder = (sdio->block_in_file & blkmask);
if (!buffer_new(map_bh))
sdio->next_block_for_io += dio_remainder;
sdio->blocks_available -= dio_remainder;
}
do_holes:
if (!buffer_mapped(map_bh)) {
loff_t i_size_aligned;
if (dio->rw & WRITE) {
put_page(page);
return -ENOTBLK;
}
i_size_aligned = ALIGN(i_size_read(dio->inode),
1 << blkbits);
if (sdio->block_in_file >=
i_size_aligned >> blkbits) {
put_page(page);
goto out;
}
zero_user(page, from, 1 << blkbits);
sdio->block_in_file++;
from += 1 << blkbits;
dio->result += 1 << blkbits;
goto next_block;
}
if (unlikely(sdio->blkfactor && !sdio->start_zero_done))
dio_zero_block(dio, sdio, 0, map_bh);
this_chunk_blocks = sdio->blocks_available;
u = (to - from) >> blkbits;
if (this_chunk_blocks > u)
this_chunk_blocks = u;
u = sdio->final_block_in_request - sdio->block_in_file;
if (this_chunk_blocks > u)
this_chunk_blocks = u;
this_chunk_bytes = this_chunk_blocks << blkbits;
BUG_ON(this_chunk_bytes == 0);
if (this_chunk_blocks == sdio->blocks_available)
sdio->boundary = buffer_boundary(map_bh);
ret = submit_page_section(dio, sdio, page,
from,
this_chunk_bytes,
sdio->next_block_for_io,
map_bh);
if (ret) {
put_page(page);
goto out;
}
sdio->next_block_for_io += this_chunk_blocks;
sdio->block_in_file += this_chunk_blocks;
from += this_chunk_bytes;
dio->result += this_chunk_bytes;
sdio->blocks_available -= this_chunk_blocks;
next_block:
BUG_ON(sdio->block_in_file > sdio->final_block_in_request);
if (sdio->block_in_file == sdio->final_block_in_request)
break;
}
put_page(page);
}
out:
return ret;
}
static inline int drop_refcount(struct dio *dio)
{
int ret2;
unsigned long flags;
spin_lock_irqsave(&dio->bio_lock, flags);
ret2 = --dio->refcount;
spin_unlock_irqrestore(&dio->bio_lock, flags);
return ret2;
}
static inline ssize_t
do_blockdev_direct_IO(struct kiocb *iocb, struct inode *inode,
struct block_device *bdev, struct iov_iter *iter,
get_block_t get_block, dio_iodone_t end_io,
dio_submit_t submit_io, int flags)
{
unsigned i_blkbits = ACCESS_ONCE(inode->i_blkbits);
unsigned blkbits = i_blkbits;
unsigned blocksize_mask = (1 << blkbits) - 1;
ssize_t retval = -EINVAL;
size_t count = iov_iter_count(iter);
loff_t offset = iocb->ki_pos;
loff_t end = offset + count;
struct dio *dio;
struct dio_submit sdio = { 0, };
struct buffer_head map_bh = { 0, };
struct blk_plug plug;
unsigned long align = offset | iov_iter_alignment(iter);
if (align & blocksize_mask) {
if (bdev)
blkbits = blksize_bits(bdev_logical_block_size(bdev));
blocksize_mask = (1 << blkbits) - 1;
if (align & blocksize_mask)
goto out;
}
if (iov_iter_rw(iter) == READ && !iov_iter_count(iter))
return 0;
dio = kmem_cache_alloc(dio_cache, GFP_KERNEL);
retval = -ENOMEM;
if (!dio)
goto out;
memset(dio, 0, offsetof(struct dio, pages));
dio->flags = flags;
if (dio->flags & DIO_LOCKING) {
if (iov_iter_rw(iter) == READ) {
struct address_space *mapping =
iocb->ki_filp->f_mapping;
inode_lock(inode);
retval = filemap_write_and_wait_range(mapping, offset,
end - 1);
if (retval) {
inode_unlock(inode);
kmem_cache_free(dio_cache, dio);
goto out;
}
}
}
dio->i_size = i_size_read(inode);
if (iov_iter_rw(iter) == READ && offset >= dio->i_size) {
if (dio->flags & DIO_LOCKING)
inode_unlock(inode);
kmem_cache_free(dio_cache, dio);
retval = 0;
goto out;
}
if (is_sync_kiocb(iocb))
dio->is_async = false;
else if (!(dio->flags & DIO_ASYNC_EXTEND) &&
iov_iter_rw(iter) == WRITE && end > i_size_read(inode))
dio->is_async = false;
else
dio->is_async = true;
dio->inode = inode;
dio->rw = iov_iter_rw(iter) == WRITE ? WRITE_ODIRECT : READ;
if (dio->is_async && iov_iter_rw(iter) == WRITE &&
((iocb->ki_filp->f_flags & O_DSYNC) ||
IS_SYNC(iocb->ki_filp->f_mapping->host))) {
retval = dio_set_defer_completion(dio);
if (retval) {
kmem_cache_free(dio_cache, dio);
goto out;
}
}
if (!(dio->flags & DIO_SKIP_DIO_COUNT))
inode_dio_begin(inode);
retval = 0;
sdio.blkbits = blkbits;
sdio.blkfactor = i_blkbits - blkbits;
sdio.block_in_file = offset >> blkbits;
sdio.get_block = get_block;
dio->end_io = end_io;
sdio.submit_io = submit_io;
sdio.final_block_in_bio = -1;
sdio.next_block_for_io = -1;
dio->iocb = iocb;
spin_lock_init(&dio->bio_lock);
dio->refcount = 1;
dio->should_dirty = (iter->type == ITER_IOVEC);
sdio.iter = iter;
sdio.final_block_in_request =
(offset + iov_iter_count(iter)) >> blkbits;
if (unlikely(sdio.blkfactor))
sdio.pages_in_io = 2;
sdio.pages_in_io += iov_iter_npages(iter, INT_MAX);
blk_start_plug(&plug);
retval = do_direct_IO(dio, &sdio, &map_bh);
if (retval)
dio_cleanup(dio, &sdio);
if (retval == -ENOTBLK) {
retval = 0;
}
dio_zero_block(dio, &sdio, 1, &map_bh);
if (sdio.cur_page) {
ssize_t ret2;
ret2 = dio_send_cur_page(dio, &sdio, &map_bh);
if (retval == 0)
retval = ret2;
put_page(sdio.cur_page);
sdio.cur_page = NULL;
}
if (sdio.bio)
dio_bio_submit(dio, &sdio);
blk_finish_plug(&plug);
dio_cleanup(dio, &sdio);
if (iov_iter_rw(iter) == READ && (dio->flags & DIO_LOCKING))
inode_unlock(dio->inode);
BUG_ON(retval == -EIOCBQUEUED);
if (dio->is_async && retval == 0 && dio->result &&
(iov_iter_rw(iter) == READ || dio->result == count))
retval = -EIOCBQUEUED;
else
dio_await_completion(dio);
if (drop_refcount(dio) == 0) {
retval = dio_complete(dio, retval, false);
} else
BUG_ON(retval != -EIOCBQUEUED);
out:
return retval;
}
ssize_t __blockdev_direct_IO(struct kiocb *iocb, struct inode *inode,
struct block_device *bdev, struct iov_iter *iter,
get_block_t get_block,
dio_iodone_t end_io, dio_submit_t submit_io,
int flags)
{
prefetch(&bdev->bd_disk->part_tbl);
prefetch(bdev->bd_queue);
prefetch((char *)bdev->bd_queue + SMP_CACHE_BYTES);
return do_blockdev_direct_IO(iocb, inode, bdev, iter, get_block,
end_io, submit_io, flags);
}
static __init int dio_init(void)
{
dio_cache = KMEM_CACHE(dio, SLAB_PANIC);
return 0;
}
