void __init
xfs_ioend_init(void)
{
int i;
for (i = 0; i < NVSYNC; i++)
init_waitqueue_head(&xfs_ioend_wq[i]);
}
void
xfs_ioend_wait(
xfs_inode_t *ip)
{
wait_queue_head_t *wq = to_ioend_wq(ip);
wait_event(*wq, (atomic_read(&ip->i_iocount) == 0));
}
STATIC void
xfs_ioend_wake(
xfs_inode_t *ip)
{
if (atomic_dec_and_test(&ip->i_iocount))
wake_up(to_ioend_wq(ip));
}
void
xfs_count_page_state(
struct page *page,
int *delalloc,
int *unwritten)
{
struct buffer_head *bh, *head;
*delalloc = *unwritten = 0;
bh = head = page_buffers(page);
do {
if (buffer_unwritten(bh))
(*unwritten) = 1;
else if (buffer_delay(bh))
(*delalloc) = 1;
} while ((bh = bh->b_this_page) != head);
}
STATIC struct block_device *
xfs_find_bdev_for_inode(
struct inode *inode)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
if (XFS_IS_REALTIME_INODE(ip))
return mp->m_rtdev_targp->bt_bdev;
else
return mp->m_ddev_targp->bt_bdev;
}
STATIC void
xfs_destroy_ioend(
xfs_ioend_t *ioend)
{
struct buffer_head *bh, *next;
struct xfs_inode *ip = XFS_I(ioend->io_inode);
for (bh = ioend->io_buffer_head; bh; bh = next) {
next = bh->b_private;
bh->b_end_io(bh, !ioend->io_error);
}
if (unlikely(ioend->io_error == -ENODEV)) {
xfs_do_force_shutdown(ip->i_mount, SHUTDOWN_DEVICE_REQ,
__FILE__, __LINE__);
}
xfs_ioend_wake(ip);
mempool_free(ioend, xfs_ioend_pool);
}
STATIC xfs_fsize_t
xfs_ioend_new_eof(
xfs_ioend_t *ioend)
{
xfs_inode_t *ip = XFS_I(ioend->io_inode);
xfs_fsize_t isize;
xfs_fsize_t bsize;
bsize = ioend->io_offset + ioend->io_size;
isize = MAX(ip->i_size, ip->i_new_size);
isize = MIN(isize, bsize);
return isize > ip->i_d.di_size ? isize : 0;
}
STATIC int
xfs_setfilesize(
xfs_ioend_t *ioend)
{
xfs_inode_t *ip = XFS_I(ioend->io_inode);
xfs_fsize_t isize;
if (unlikely(ioend->io_error))
return 0;
if (!xfs_ilock_nowait(ip, XFS_ILOCK_EXCL))
return EAGAIN;
isize = xfs_ioend_new_eof(ioend);
if (isize) {
ip->i_d.di_size = isize;
xfs_mark_inode_dirty(ip);
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
}
STATIC void
xfs_finish_ioend(
struct xfs_ioend *ioend)
{
if (atomic_dec_and_test(&ioend->io_remaining)) {
if (ioend->io_type == IO_UNWRITTEN)
queue_work(xfsconvertd_workqueue, &ioend->io_work);
else
queue_work(xfsdatad_workqueue, &ioend->io_work);
}
}
STATIC void
xfs_end_io(
struct work_struct *work)
{
xfs_ioend_t *ioend = container_of(work, xfs_ioend_t, io_work);
struct xfs_inode *ip = XFS_I(ioend->io_inode);
int error = 0;
if (ioend->io_type == IO_UNWRITTEN &&
likely(!ioend->io_error && !XFS_FORCED_SHUTDOWN(ip->i_mount))) {
error = xfs_iomap_write_unwritten(ip, ioend->io_offset,
ioend->io_size);
if (error)
ioend->io_error = error;
}
error = xfs_setfilesize(ioend);
ASSERT(!error || error == EAGAIN);
if (error == EAGAIN) {
atomic_inc(&ioend->io_remaining);
xfs_finish_ioend(ioend);
delay(1);
} else {
if (ioend->io_iocb)
aio_complete(ioend->io_iocb, ioend->io_result, 0);
xfs_destroy_ioend(ioend);
}
}
STATIC void
xfs_finish_ioend_sync(
struct xfs_ioend *ioend)
{
if (atomic_dec_and_test(&ioend->io_remaining))
xfs_end_io(&ioend->io_work);
}
STATIC xfs_ioend_t *
xfs_alloc_ioend(
struct inode *inode,
unsigned int type)
{
xfs_ioend_t *ioend;
ioend = mempool_alloc(xfs_ioend_pool, GFP_NOFS);
atomic_set(&ioend->io_remaining, 1);
ioend->io_error = 0;
ioend->io_list = NULL;
ioend->io_type = type;
ioend->io_inode = inode;
ioend->io_buffer_head = NULL;
ioend->io_buffer_tail = NULL;
atomic_inc(&XFS_I(ioend->io_inode)->i_iocount);
ioend->io_offset = 0;
ioend->io_size = 0;
ioend->io_iocb = NULL;
ioend->io_result = 0;
INIT_WORK(&ioend->io_work, xfs_end_io);
return ioend;
}
STATIC int
xfs_map_blocks(
struct inode *inode,
loff_t offset,
struct xfs_bmbt_irec *imap,
int type,
int nonblocking)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
ssize_t count = 1 << inode->i_blkbits;
xfs_fileoff_t offset_fsb, end_fsb;
int error = 0;
int bmapi_flags = XFS_BMAPI_ENTIRE;
int nimaps = 1;
if (XFS_FORCED_SHUTDOWN(mp))
return -XFS_ERROR(EIO);
if (type == IO_UNWRITTEN)
bmapi_flags |= XFS_BMAPI_IGSTATE;
if (!xfs_ilock_nowait(ip, XFS_ILOCK_SHARED)) {
if (nonblocking)
return -XFS_ERROR(EAGAIN);
xfs_ilock(ip, XFS_ILOCK_SHARED);
}
ASSERT(ip->i_d.di_format != XFS_DINODE_FMT_BTREE ||
(ip->i_df.if_flags & XFS_IFEXTENTS));
ASSERT(offset <= mp->m_maxioffset);
if (offset + count > mp->m_maxioffset)
count = mp->m_maxioffset - offset;
end_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + count);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
error = xfs_bmapi(NULL, ip, offset_fsb, end_fsb - offset_fsb,
bmapi_flags, NULL, 0, imap, &nimaps, NULL);
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (error)
return -XFS_ERROR(error);
if (type == IO_DELALLOC &&
(!nimaps || isnullstartblock(imap->br_startblock))) {
error = xfs_iomap_write_allocate(ip, offset, count, imap);
if (!error)
trace_xfs_map_blocks_alloc(ip, offset, count, type, imap);
return -XFS_ERROR(error);
}
#ifdef DEBUG
if (type == IO_UNWRITTEN) {
ASSERT(nimaps);
ASSERT(imap->br_startblock != HOLESTARTBLOCK);
ASSERT(imap->br_startblock != DELAYSTARTBLOCK);
}
#endif
if (nimaps)
trace_xfs_map_blocks_found(ip, offset, count, type, imap);
return 0;
}
STATIC int
xfs_imap_valid(
struct inode *inode,
struct xfs_bmbt_irec *imap,
xfs_off_t offset)
{
offset >>= inode->i_blkbits;
return offset >= imap->br_startoff &&
offset < imap->br_startoff + imap->br_blockcount;
}
STATIC void
xfs_end_bio(
struct bio *bio,
int error)
{
xfs_ioend_t *ioend = bio->bi_private;
ASSERT(atomic_read(&bio->bi_cnt) >= 1);
ioend->io_error = test_bit(BIO_UPTODATE, &bio->bi_flags) ? 0 : error;
bio->bi_private = NULL;
bio->bi_end_io = NULL;
bio_put(bio);
xfs_finish_ioend(ioend);
}
STATIC void
xfs_submit_ioend_bio(
struct writeback_control *wbc,
xfs_ioend_t *ioend,
struct bio *bio)
{
atomic_inc(&ioend->io_remaining);
bio->bi_private = ioend;
bio->bi_end_io = xfs_end_bio;
if (xfs_ioend_new_eof(ioend))
xfs_mark_inode_dirty(XFS_I(ioend->io_inode));
submit_bio(wbc->sync_mode == WB_SYNC_ALL ? WRITE_SYNC : WRITE, bio);
}
STATIC struct bio *
xfs_alloc_ioend_bio(
struct buffer_head *bh)
{
int nvecs = bio_get_nr_vecs(bh->b_bdev);
struct bio *bio = bio_alloc(GFP_NOIO, nvecs);
ASSERT(bio->bi_private == NULL);
bio->bi_sector = bh->b_blocknr * (bh->b_size >> 9);
bio->bi_bdev = bh->b_bdev;
return bio;
}
STATIC void
xfs_start_buffer_writeback(
struct buffer_head *bh)
{
ASSERT(buffer_mapped(bh));
ASSERT(buffer_locked(bh));
ASSERT(!buffer_delay(bh));
ASSERT(!buffer_unwritten(bh));
mark_buffer_async_write(bh);
set_buffer_uptodate(bh);
clear_buffer_dirty(bh);
}
STATIC void
xfs_start_page_writeback(
struct page *page,
int clear_dirty,
int buffers)
{
ASSERT(PageLocked(page));
ASSERT(!PageWriteback(page));
if (clear_dirty)
clear_page_dirty_for_io(page);
set_page_writeback(page);
unlock_page(page);
if (!buffers)
end_page_writeback(page);
}
static inline int bio_add_buffer(struct bio *bio, struct buffer_head *bh)
{
return bio_add_page(bio, bh->b_page, bh->b_size, bh_offset(bh));
}
STATIC void
xfs_submit_ioend(
struct writeback_control *wbc,
xfs_ioend_t *ioend)
{
xfs_ioend_t *head = ioend;
xfs_ioend_t *next;
struct buffer_head *bh;
struct bio *bio;
sector_t lastblock = 0;
do {
next = ioend->io_list;
for (bh = ioend->io_buffer_head; bh; bh = bh->b_private)
xfs_start_buffer_writeback(bh);
} while ((ioend = next) != NULL);
ioend = head;
do {
next = ioend->io_list;
bio = NULL;
for (bh = ioend->io_buffer_head; bh; bh = bh->b_private) {
if (!bio) {
retry:
bio = xfs_alloc_ioend_bio(bh);
} else if (bh->b_blocknr != lastblock + 1) {
xfs_submit_ioend_bio(wbc, ioend, bio);
goto retry;
}
if (bio_add_buffer(bio, bh) != bh->b_size) {
xfs_submit_ioend_bio(wbc, ioend, bio);
goto retry;
}
lastblock = bh->b_blocknr;
}
if (bio)
xfs_submit_ioend_bio(wbc, ioend, bio);
xfs_finish_ioend(ioend);
} while ((ioend = next) != NULL);
}
STATIC void
xfs_cancel_ioend(
xfs_ioend_t *ioend)
{
xfs_ioend_t *next;
struct buffer_head *bh, *next_bh;
do {
next = ioend->io_list;
bh = ioend->io_buffer_head;
do {
next_bh = bh->b_private;
clear_buffer_async_write(bh);
unlock_buffer(bh);
} while ((bh = next_bh) != NULL);
xfs_ioend_wake(XFS_I(ioend->io_inode));
mempool_free(ioend, xfs_ioend_pool);
} while ((ioend = next) != NULL);
}
STATIC void
xfs_add_to_ioend(
struct inode *inode,
struct buffer_head *bh,
xfs_off_t offset,
unsigned int type,
xfs_ioend_t **result,
int need_ioend)
{
xfs_ioend_t *ioend = *result;
if (!ioend || need_ioend || type != ioend->io_type) {
xfs_ioend_t *previous = *result;
ioend = xfs_alloc_ioend(inode, type);
ioend->io_offset = offset;
ioend->io_buffer_head = bh;
ioend->io_buffer_tail = bh;
if (previous)
previous->io_list = ioend;
*result = ioend;
} else {
ioend->io_buffer_tail->b_private = bh;
ioend->io_buffer_tail = bh;
}
bh->b_private = NULL;
ioend->io_size += bh->b_size;
}
STATIC void
xfs_map_buffer(
struct inode *inode,
struct buffer_head *bh,
struct xfs_bmbt_irec *imap,
xfs_off_t offset)
{
sector_t bn;
struct xfs_mount *m = XFS_I(inode)->i_mount;
xfs_off_t iomap_offset = XFS_FSB_TO_B(m, imap->br_startoff);
xfs_daddr_t iomap_bn = xfs_fsb_to_db(XFS_I(inode), imap->br_startblock);
ASSERT(imap->br_startblock != HOLESTARTBLOCK);
ASSERT(imap->br_startblock != DELAYSTARTBLOCK);
bn = (iomap_bn >> (inode->i_blkbits - BBSHIFT)) +
((offset - iomap_offset) >> inode->i_blkbits);
ASSERT(bn || XFS_IS_REALTIME_INODE(XFS_I(inode)));
bh->b_blocknr = bn;
set_buffer_mapped(bh);
}
STATIC void
xfs_map_at_offset(
struct inode *inode,
struct buffer_head *bh,
struct xfs_bmbt_irec *imap,
xfs_off_t offset)
{
ASSERT(imap->br_startblock != HOLESTARTBLOCK);
ASSERT(imap->br_startblock != DELAYSTARTBLOCK);
xfs_map_buffer(inode, bh, imap, offset);
set_buffer_mapped(bh);
clear_buffer_delay(bh);
clear_buffer_unwritten(bh);
}
STATIC int
xfs_is_delayed_page(
struct page *page,
unsigned int type)
{
if (PageWriteback(page))
return 0;
if (page->mapping && page_has_buffers(page)) {
struct buffer_head *bh, *head;
int acceptable = 0;
bh = head = page_buffers(page);
do {
if (buffer_unwritten(bh))
acceptable = (type == IO_UNWRITTEN);
else if (buffer_delay(bh))
acceptable = (type == IO_DELALLOC);
else if (buffer_dirty(bh) && buffer_mapped(bh))
acceptable = (type == IO_OVERWRITE);
else
break;
} while ((bh = bh->b_this_page) != head);
if (acceptable)
return 1;
}
return 0;
}
STATIC int
xfs_convert_page(
struct inode *inode,
struct page *page,
loff_t tindex,
struct xfs_bmbt_irec *imap,
xfs_ioend_t **ioendp,
struct writeback_control *wbc)
{
struct buffer_head *bh, *head;
xfs_off_t end_offset;
unsigned long p_offset;
unsigned int type;
int len, page_dirty;
int count = 0, done = 0, uptodate = 1;
xfs_off_t offset = page_offset(page);
if (page->index != tindex)
goto fail;
if (!trylock_page(page))
goto fail;
if (PageWriteback(page))
goto fail_unlock_page;
if (page->mapping != inode->i_mapping)
goto fail_unlock_page;
if (!xfs_is_delayed_page(page, (*ioendp)->io_type))
goto fail_unlock_page;
end_offset = min_t(unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode));
len = 1 << inode->i_blkbits;
p_offset = min_t(unsigned long, end_offset & (PAGE_CACHE_SIZE - 1),
PAGE_CACHE_SIZE);
p_offset = p_offset ? roundup(p_offset, len) : PAGE_CACHE_SIZE;
page_dirty = p_offset / len;
bh = head = page_buffers(page);
do {
if (offset >= end_offset)
break;
if (!buffer_uptodate(bh))
uptodate = 0;
if (!(PageUptodate(page) || buffer_uptodate(bh))) {
done = 1;
continue;
}
if (buffer_unwritten(bh) || buffer_delay(bh) ||
buffer_mapped(bh)) {
if (buffer_unwritten(bh))
type = IO_UNWRITTEN;
else if (buffer_delay(bh))
type = IO_DELALLOC;
else
type = IO_OVERWRITE;
if (!xfs_imap_valid(inode, imap, offset)) {
done = 1;
continue;
}
lock_buffer(bh);
if (type != IO_OVERWRITE)
xfs_map_at_offset(inode, bh, imap, offset);
xfs_add_to_ioend(inode, bh, offset, type,
ioendp, done);
page_dirty--;
count++;
} else {
done = 1;
}
} while (offset += len, (bh = bh->b_this_page) != head);
if (uptodate && bh == head)
SetPageUptodate(page);
if (count) {
if (--wbc->nr_to_write <= 0 &&
wbc->sync_mode == WB_SYNC_NONE)
done = 1;
}
xfs_start_page_writeback(page, !page_dirty, count);
return done;
fail_unlock_page:
unlock_page(page);
fail:
return 1;
}
STATIC void
xfs_cluster_write(
struct inode *inode,
pgoff_t tindex,
struct xfs_bmbt_irec *imap,
xfs_ioend_t **ioendp,
struct writeback_control *wbc,
pgoff_t tlast)
{
struct pagevec pvec;
int done = 0, i;
pagevec_init(&pvec, 0);
while (!done && tindex <= tlast) {
unsigned len = min_t(pgoff_t, PAGEVEC_SIZE, tlast - tindex + 1);
if (!pagevec_lookup(&pvec, inode->i_mapping, tindex, len))
break;
for (i = 0; i < pagevec_count(&pvec); i++) {
done = xfs_convert_page(inode, pvec.pages[i], tindex++,
imap, ioendp, wbc);
if (done)
break;
}
pagevec_release(&pvec);
cond_resched();
}
}
STATIC void
xfs_vm_invalidatepage(
struct page *page,
unsigned long offset)
{
trace_xfs_invalidatepage(page->mapping->host, page, offset);
block_invalidatepage(page, offset);
}
STATIC void
xfs_aops_discard_page(
struct page *page)
{
struct inode *inode = page->mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct buffer_head *bh, *head;
loff_t offset = page_offset(page);
if (!xfs_is_delayed_page(page, IO_DELALLOC))
goto out_invalidate;
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
goto out_invalidate;
xfs_alert(ip->i_mount,
"page discard on page %p, inode 0x%llx, offset %llu.",
page, ip->i_ino, offset);
xfs_ilock(ip, XFS_ILOCK_EXCL);
bh = head = page_buffers(page);
do {
int error;
xfs_fileoff_t start_fsb;
if (!buffer_delay(bh))
goto next_buffer;
start_fsb = XFS_B_TO_FSBT(ip->i_mount, offset);
error = xfs_bmap_punch_delalloc_range(ip, start_fsb, 1);
if (error) {
if (!XFS_FORCED_SHUTDOWN(ip->i_mount)) {
xfs_alert(ip->i_mount,
"page discard unable to remove delalloc mapping.");
}
break;
}
next_buffer:
offset += 1 << inode->i_blkbits;
} while ((bh = bh->b_this_page) != head);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out_invalidate:
xfs_vm_invalidatepage(page, 0);
return;
}
STATIC int
xfs_vm_writepage(
struct page *page,
struct writeback_control *wbc)
{
struct inode *inode = page->mapping->host;
int delalloc, unwritten;
struct buffer_head *bh, *head;
struct xfs_bmbt_irec imap;
xfs_ioend_t *ioend = NULL, *iohead = NULL;
loff_t offset;
unsigned int type;
__uint64_t end_offset;
pgoff_t end_index, last_index;
ssize_t len;
int err, imap_valid = 0, uptodate = 1;
int count = 0;
int nonblocking = 0;
trace_xfs_writepage(inode, page, 0);
ASSERT(page_has_buffers(page));
if ((current->flags & (PF_MEMALLOC|PF_KSWAPD)) == PF_MEMALLOC)
goto redirty;
xfs_count_page_state(page, &delalloc, &unwritten);
if ((current->flags & PF_FSTRANS) && (delalloc || unwritten))
goto redirty;
offset = i_size_read(inode);
end_index = offset >> PAGE_CACHE_SHIFT;
last_index = (offset - 1) >> PAGE_CACHE_SHIFT;
if (page->index >= end_index) {
if ((page->index >= end_index + 1) ||
!(i_size_read(inode) & (PAGE_CACHE_SIZE - 1))) {
unlock_page(page);
return 0;
}
}
end_offset = min_t(unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
offset);
len = 1 << inode->i_blkbits;
bh = head = page_buffers(page);
offset = page_offset(page);
type = IO_OVERWRITE;
if (wbc->sync_mode == WB_SYNC_NONE && wbc->nonblocking)
nonblocking = 1;
do {
int new_ioend = 0;
if (offset >= end_offset)
break;
if (!buffer_uptodate(bh))
uptodate = 0;
if (!buffer_mapped(bh) && buffer_uptodate(bh)) {
imap_valid = 0;
continue;
}
if (buffer_unwritten(bh)) {
if (type != IO_UNWRITTEN) {
type = IO_UNWRITTEN;
imap_valid = 0;
}
} else if (buffer_delay(bh)) {
if (type != IO_DELALLOC) {
type = IO_DELALLOC;
imap_valid = 0;
}
} else if (buffer_uptodate(bh)) {
if (type != IO_OVERWRITE) {
type = IO_OVERWRITE;
imap_valid = 0;
}
} else {
if (PageUptodate(page)) {
ASSERT(buffer_mapped(bh));
imap_valid = 0;
}
continue;
}
if (imap_valid)
imap_valid = xfs_imap_valid(inode, &imap, offset);
if (!imap_valid) {
new_ioend = 1;
err = xfs_map_blocks(inode, offset, &imap, type,
nonblocking);
if (err)
goto error;
imap_valid = xfs_imap_valid(inode, &imap, offset);
}
if (imap_valid) {
lock_buffer(bh);
if (type != IO_OVERWRITE)
xfs_map_at_offset(inode, bh, &imap, offset);
xfs_add_to_ioend(inode, bh, offset, type, &ioend,
new_ioend);
count++;
}
if (!iohead)
iohead = ioend;
} while (offset += len, ((bh = bh->b_this_page) != head));
if (uptodate && bh == head)
SetPageUptodate(page);
xfs_start_page_writeback(page, 1, count);
if (ioend && imap_valid) {
xfs_off_t end_index;
end_index = imap.br_startoff + imap.br_blockcount;
end_index <<= inode->i_blkbits;
end_index = (end_index - 1) >> PAGE_CACHE_SHIFT;
if (end_index > last_index)
end_index = last_index;
xfs_cluster_write(inode, page->index + 1, &imap, &ioend,
wbc, end_index);
}
if (iohead)
xfs_submit_ioend(wbc, iohead);
return 0;
error:
if (iohead)
xfs_cancel_ioend(iohead);
if (err == -EAGAIN)
goto redirty;
xfs_aops_discard_page(page);
ClearPageUptodate(page);
unlock_page(page);
return err;
redirty:
redirty_page_for_writepage(wbc, page);
unlock_page(page);
return 0;
}
STATIC int
xfs_vm_writepages(
struct address_space *mapping,
struct writeback_control *wbc)
{
xfs_iflags_clear(XFS_I(mapping->host), XFS_ITRUNCATED);
return generic_writepages(mapping, wbc);
}
STATIC int
xfs_vm_releasepage(
struct page *page,
gfp_t gfp_mask)
{
int delalloc, unwritten;
trace_xfs_releasepage(page->mapping->host, page, 0);
xfs_count_page_state(page, &delalloc, &unwritten);
if (WARN_ON(delalloc))
return 0;
if (WARN_ON(unwritten))
return 0;
return try_to_free_buffers(page);
}
STATIC int
__xfs_get_blocks(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
int create,
int direct)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t offset_fsb, end_fsb;
int error = 0;
int lockmode = 0;
struct xfs_bmbt_irec imap;
int nimaps = 1;
xfs_off_t offset;
ssize_t size;
int new = 0;
if (XFS_FORCED_SHUTDOWN(mp))
return -XFS_ERROR(EIO);
offset = (xfs_off_t)iblock << inode->i_blkbits;
ASSERT(bh_result->b_size >= (1 << inode->i_blkbits));
size = bh_result->b_size;
if (!create && direct && offset >= i_size_read(inode))
return 0;
if (create) {
lockmode = XFS_ILOCK_EXCL;
xfs_ilock(ip, lockmode);
} else {
lockmode = xfs_ilock_map_shared(ip);
}
ASSERT(offset <= mp->m_maxioffset);
if (offset + size > mp->m_maxioffset)
size = mp->m_maxioffset - offset;
end_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + size);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
error = xfs_bmapi(NULL, ip, offset_fsb, end_fsb - offset_fsb,
XFS_BMAPI_ENTIRE, NULL, 0, &imap, &nimaps, NULL);
if (error)
goto out_unlock;
if (create &&
(!nimaps ||
(imap.br_startblock == HOLESTARTBLOCK ||
imap.br_startblock == DELAYSTARTBLOCK))) {
if (direct) {
error = xfs_iomap_write_direct(ip, offset, size,
&imap, nimaps);
} else {
error = xfs_iomap_write_delay(ip, offset, size, &imap);
}
if (error)
goto out_unlock;
trace_xfs_get_blocks_alloc(ip, offset, size, 0, &imap);
} else if (nimaps) {
trace_xfs_get_blocks_found(ip, offset, size, 0, &imap);
} else {
trace_xfs_get_blocks_notfound(ip, offset, size);
goto out_unlock;
}
xfs_iunlock(ip, lockmode);
if (imap.br_startblock != HOLESTARTBLOCK &&
imap.br_startblock != DELAYSTARTBLOCK) {
if (create || !ISUNWRITTEN(&imap))
xfs_map_buffer(inode, bh_result, &imap, offset);
if (create && ISUNWRITTEN(&imap)) {
if (direct)
bh_result->b_private = inode;
set_buffer_unwritten(bh_result);
}
}
bh_result->b_bdev = xfs_find_bdev_for_inode(inode);
if (create &&
((!buffer_mapped(bh_result) && !buffer_uptodate(bh_result)) ||
(offset >= i_size_read(inode)) ||
(new || ISUNWRITTEN(&imap))))
set_buffer_new(bh_result);
if (imap.br_startblock == DELAYSTARTBLOCK) {
BUG_ON(direct);
if (create) {
set_buffer_uptodate(bh_result);
set_buffer_mapped(bh_result);
set_buffer_delay(bh_result);
}
}
if (direct || size > (1 << inode->i_blkbits)) {
xfs_off_t mapping_size;
mapping_size = imap.br_startoff + imap.br_blockcount - iblock;
mapping_size <<= inode->i_blkbits;
ASSERT(mapping_size > 0);
if (mapping_size > size)
mapping_size = size;
if (mapping_size > LONG_MAX)
mapping_size = LONG_MAX;
bh_result->b_size = mapping_size;
}
return 0;
out_unlock:
xfs_iunlock(ip, lockmode);
return -error;
}
int
xfs_get_blocks(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
int create)
{
return __xfs_get_blocks(inode, iblock, bh_result, create, 0);
}
STATIC int
xfs_get_blocks_direct(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
int create)
{
return __xfs_get_blocks(inode, iblock, bh_result, create, 1);
}
STATIC void
xfs_end_io_direct_write(
struct kiocb *iocb,
loff_t offset,
ssize_t size,
void *private,
int ret,
bool is_async)
{
struct xfs_ioend *ioend = iocb->private;
iocb->private = NULL;
ioend->io_offset = offset;
ioend->io_size = size;
if (private && size > 0)
ioend->io_type = IO_UNWRITTEN;
if (is_async) {
if (ioend->io_type == IO_UNWRITTEN) {
ioend->io_iocb = iocb;
ioend->io_result = ret;
} else {
aio_complete(iocb, ret, 0);
}
xfs_finish_ioend(ioend);
} else {
xfs_finish_ioend_sync(ioend);
}
}
STATIC ssize_t
xfs_vm_direct_IO(
int rw,
struct kiocb *iocb,
const struct iovec *iov,
loff_t offset,
unsigned long nr_segs)
{
struct inode *inode = iocb->ki_filp->f_mapping->host;
struct block_device *bdev = xfs_find_bdev_for_inode(inode);
ssize_t ret;
if (rw & WRITE) {
iocb->private = xfs_alloc_ioend(inode, IO_DIRECT);
ret = __blockdev_direct_IO(rw, iocb, inode, bdev, iov,
offset, nr_segs,
xfs_get_blocks_direct,
xfs_end_io_direct_write, NULL, 0);
if (ret != -EIOCBQUEUED && iocb->private)
xfs_destroy_ioend(iocb->private);
} else {
ret = __blockdev_direct_IO(rw, iocb, inode, bdev, iov,
offset, nr_segs,
xfs_get_blocks_direct,
NULL, NULL, 0);
}
return ret;
}
STATIC void
xfs_vm_write_failed(
struct address_space *mapping,
loff_t to)
{
struct inode *inode = mapping->host;
if (to > inode->i_size) {
struct xfs_inode *ip = XFS_I(inode);
xfs_fileoff_t start_fsb;
xfs_fileoff_t end_fsb;
int error;
truncate_pagecache(inode, to, inode->i_size);
start_fsb = XFS_B_TO_FSB(ip->i_mount, inode->i_size) + 1;
end_fsb = XFS_B_TO_FSB(ip->i_mount, to);
if (end_fsb <= start_fsb)
return;
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_bmap_punch_delalloc_range(ip, start_fsb,
end_fsb - start_fsb);
if (error) {
if (!XFS_FORCED_SHUTDOWN(ip->i_mount)) {
xfs_alert(ip->i_mount,
"xfs_vm_write_failed: unable to clean up ino %lld",
ip->i_ino);
}
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
}
STATIC int
xfs_vm_write_begin(
struct file *file,
struct address_space *mapping,
loff_t pos,
unsigned len,
unsigned flags,
struct page **pagep,
void **fsdata)
{
int ret;
ret = block_write_begin(mapping, pos, len, flags | AOP_FLAG_NOFS,
pagep, xfs_get_blocks);
if (unlikely(ret))
xfs_vm_write_failed(mapping, pos + len);
return ret;
}
STATIC int
xfs_vm_write_end(
struct file *file,
struct address_space *mapping,
loff_t pos,
unsigned len,
unsigned copied,
struct page *page,
void *fsdata)
{
int ret;
ret = generic_write_end(file, mapping, pos, len, copied, page, fsdata);
if (unlikely(ret < len))
xfs_vm_write_failed(mapping, pos + len);
return ret;
}
STATIC sector_t
xfs_vm_bmap(
struct address_space *mapping,
sector_t block)
{
struct inode *inode = (struct inode *)mapping->host;
struct xfs_inode *ip = XFS_I(inode);
trace_xfs_vm_bmap(XFS_I(inode));
xfs_ilock(ip, XFS_IOLOCK_SHARED);
xfs_flush_pages(ip, (xfs_off_t)0, -1, 0, FI_REMAPF);
xfs_iunlock(ip, XFS_IOLOCK_SHARED);
return generic_block_bmap(mapping, block, xfs_get_blocks);
}
STATIC int
xfs_vm_readpage(
struct file *unused,
struct page *page)
{
return mpage_readpage(page, xfs_get_blocks);
}
STATIC int
xfs_vm_readpages(
struct file *unused,
struct address_space *mapping,
struct list_head *pages,
unsigned nr_pages)
{
return mpage_readpages(mapping, pages, nr_pages, xfs_get_blocks);
}
