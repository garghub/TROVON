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
for (bh = ioend->io_buffer_head; bh; bh = next) {
next = bh->b_private;
bh->b_end_io(bh, !ioend->io_error);
}
mempool_free(ioend, xfs_ioend_pool);
}
static inline bool xfs_ioend_is_append(struct xfs_ioend *ioend)
{
return ioend->io_offset + ioend->io_size >
XFS_I(ioend->io_inode)->i_d.di_size;
}
STATIC int
xfs_setfilesize_trans_alloc(
struct xfs_ioend *ioend)
{
struct xfs_mount *mp = XFS_I(ioend->io_inode)->i_mount;
struct xfs_trans *tp;
int error;
tp = xfs_trans_alloc(mp, XFS_TRANS_FSYNC_TS);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_fsyncts, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return error;
}
ioend->io_append_trans = tp;
rwsem_release(&ioend->io_inode->i_sb->s_writers.lock_map[SB_FREEZE_FS-1],
1, _THIS_IP_);
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
return 0;
}
STATIC int
xfs_setfilesize(
struct xfs_ioend *ioend)
{
struct xfs_inode *ip = XFS_I(ioend->io_inode);
struct xfs_trans *tp = ioend->io_append_trans;
xfs_fsize_t isize;
current_set_flags_nested(&tp->t_pflags, PF_FSTRANS);
rwsem_acquire_read(&VFS_I(ip)->i_sb->s_writers.lock_map[SB_FREEZE_FS-1],
0, 1, _THIS_IP_);
xfs_ilock(ip, XFS_ILOCK_EXCL);
isize = xfs_new_eof(ip, ioend->io_offset + ioend->io_size);
if (!isize) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
xfs_trans_cancel(tp, 0);
return 0;
}
trace_xfs_setfilesize(ip, ioend->io_offset, ioend->io_size);
ip->i_d.di_size = isize;
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
return xfs_trans_commit(tp, 0);
}
STATIC void
xfs_finish_ioend(
struct xfs_ioend *ioend)
{
if (atomic_dec_and_test(&ioend->io_remaining)) {
struct xfs_mount *mp = XFS_I(ioend->io_inode)->i_mount;
if (ioend->io_type == XFS_IO_UNWRITTEN)
queue_work(mp->m_unwritten_workqueue, &ioend->io_work);
else if (ioend->io_append_trans ||
(ioend->io_isdirect && xfs_ioend_is_append(ioend)))
queue_work(mp->m_data_workqueue, &ioend->io_work);
else
xfs_destroy_ioend(ioend);
}
}
STATIC void
xfs_end_io(
struct work_struct *work)
{
xfs_ioend_t *ioend = container_of(work, xfs_ioend_t, io_work);
struct xfs_inode *ip = XFS_I(ioend->io_inode);
int error = 0;
if (XFS_FORCED_SHUTDOWN(ip->i_mount)) {
ioend->io_error = -EIO;
goto done;
}
if (ioend->io_error)
goto done;
if (ioend->io_type == XFS_IO_UNWRITTEN) {
error = xfs_iomap_write_unwritten(ip, ioend->io_offset,
ioend->io_size);
} else if (ioend->io_isdirect && xfs_ioend_is_append(ioend)) {
error = xfs_setfilesize_trans_alloc(ioend);
if (error)
goto done;
error = xfs_setfilesize(ioend);
} else if (ioend->io_append_trans) {
error = xfs_setfilesize(ioend);
} else {
ASSERT(!xfs_ioend_is_append(ioend));
}
done:
if (error)
ioend->io_error = error;
xfs_destroy_ioend(ioend);
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
ioend->io_isdirect = 0;
ioend->io_error = 0;
ioend->io_list = NULL;
ioend->io_type = type;
ioend->io_inode = inode;
ioend->io_buffer_head = NULL;
ioend->io_buffer_tail = NULL;
ioend->io_offset = 0;
ioend->io_size = 0;
ioend->io_append_trans = NULL;
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
return -EIO;
if (type == XFS_IO_UNWRITTEN)
bmapi_flags |= XFS_BMAPI_IGSTATE;
if (!xfs_ilock_nowait(ip, XFS_ILOCK_SHARED)) {
if (nonblocking)
return -EAGAIN;
xfs_ilock(ip, XFS_ILOCK_SHARED);
}
ASSERT(ip->i_d.di_format != XFS_DINODE_FMT_BTREE ||
(ip->i_df.if_flags & XFS_IFEXTENTS));
ASSERT(offset <= mp->m_super->s_maxbytes);
if (offset + count > mp->m_super->s_maxbytes)
count = mp->m_super->s_maxbytes - offset;
end_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + count);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
error = xfs_bmapi_read(ip, offset_fsb, end_fsb - offset_fsb,
imap, &nimaps, bmapi_flags);
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (error)
return error;
if (type == XFS_IO_DELALLOC &&
(!nimaps || isnullstartblock(imap->br_startblock))) {
error = xfs_iomap_write_allocate(ip, offset, imap);
if (!error)
trace_xfs_map_blocks_alloc(ip, offset, count, type, imap);
return error;
}
#ifdef DEBUG
if (type == XFS_IO_UNWRITTEN) {
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
submit_bio(wbc->sync_mode == WB_SYNC_ALL ? WRITE_SYNC : WRITE, bio);
}
STATIC struct bio *
xfs_alloc_ioend_bio(
struct buffer_head *bh)
{
int nvecs = bio_get_nr_vecs(bh->b_bdev);
struct bio *bio = bio_alloc(GFP_NOIO, nvecs);
ASSERT(bio->bi_private == NULL);
bio->bi_iter.bi_sector = bh->b_blocknr * (bh->b_size >> 9);
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
static inline int xfs_bio_add_buffer(struct bio *bio, struct buffer_head *bh)
{
return bio_add_page(bio, bh->b_page, bh->b_size, bh_offset(bh));
}
STATIC void
xfs_submit_ioend(
struct writeback_control *wbc,
xfs_ioend_t *ioend,
int fail)
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
if (fail) {
ioend->io_error = fail;
xfs_finish_ioend(ioend);
continue;
}
for (bh = ioend->io_buffer_head; bh; bh = bh->b_private) {
if (!bio) {
retry:
bio = xfs_alloc_ioend_bio(bh);
} else if (bh->b_blocknr != lastblock + 1) {
xfs_submit_ioend_bio(wbc, ioend, bio);
goto retry;
}
if (xfs_bio_add_buffer(bio, bh) != bh->b_size) {
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
STATIC bool
xfs_check_page_type(
struct page *page,
unsigned int type,
bool check_all_buffers)
{
struct buffer_head *bh;
struct buffer_head *head;
if (PageWriteback(page))
return false;
if (!page->mapping)
return false;
if (!page_has_buffers(page))
return false;
bh = head = page_buffers(page);
do {
if (buffer_unwritten(bh)) {
if (type == XFS_IO_UNWRITTEN)
return true;
} else if (buffer_delay(bh)) {
if (type == XFS_IO_DELALLOC)
return true;
} else if (buffer_dirty(bh) && buffer_mapped(bh)) {
if (type == XFS_IO_OVERWRITE)
return true;
}
if (!check_all_buffers)
break;
} while ((bh = bh->b_this_page) != head);
return false;
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
if (!xfs_check_page_type(page, (*ioendp)->io_type, false))
goto fail_unlock_page;
end_offset = min_t(unsigned long long,
(xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT,
i_size_read(inode));
if (!xfs_imap_valid(inode, imap, end_offset))
goto fail_unlock_page;
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
break;
}
if (buffer_unwritten(bh) || buffer_delay(bh) ||
buffer_mapped(bh)) {
if (buffer_unwritten(bh))
type = XFS_IO_UNWRITTEN;
else if (buffer_delay(bh))
type = XFS_IO_DELALLOC;
else
type = XFS_IO_OVERWRITE;
ASSERT(xfs_imap_valid(inode, imap, offset));
lock_buffer(bh);
if (type != XFS_IO_OVERWRITE)
xfs_map_at_offset(inode, bh, imap, offset);
xfs_add_to_ioend(inode, bh, offset, type,
ioendp, done);
page_dirty--;
count++;
} else {
done = 1;
break;
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
unsigned int offset,
unsigned int length)
{
trace_xfs_invalidatepage(page->mapping->host, page, offset,
length);
block_invalidatepage(page, offset, length);
}
STATIC void
xfs_aops_discard_page(
struct page *page)
{
struct inode *inode = page->mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct buffer_head *bh, *head;
loff_t offset = page_offset(page);
if (!xfs_check_page_type(page, XFS_IO_DELALLOC, true))
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
xfs_vm_invalidatepage(page, 0, PAGE_CACHE_SIZE);
return;
}
STATIC int
xfs_vm_writepage(
struct page *page,
struct writeback_control *wbc)
{
struct inode *inode = page->mapping->host;
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
trace_xfs_writepage(inode, page, 0, 0);
ASSERT(page_has_buffers(page));
if (WARN_ON_ONCE((current->flags & (PF_MEMALLOC|PF_KSWAPD)) ==
PF_MEMALLOC))
goto redirty;
if (WARN_ON_ONCE(current->flags & PF_FSTRANS))
goto redirty;
offset = i_size_read(inode);
end_index = offset >> PAGE_CACHE_SHIFT;
last_index = (offset - 1) >> PAGE_CACHE_SHIFT;
if (page->index < end_index)
end_offset = (xfs_off_t)(page->index + 1) << PAGE_CACHE_SHIFT;
else {
unsigned offset_into_page = offset & (PAGE_CACHE_SIZE - 1);
if (page->index > end_index ||
(page->index == end_index && offset_into_page == 0))
goto redirty;
zero_user_segment(page, offset_into_page, PAGE_CACHE_SIZE);
end_offset = offset;
}
len = 1 << inode->i_blkbits;
bh = head = page_buffers(page);
offset = page_offset(page);
type = XFS_IO_OVERWRITE;
if (wbc->sync_mode == WB_SYNC_NONE)
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
if (type != XFS_IO_UNWRITTEN) {
type = XFS_IO_UNWRITTEN;
imap_valid = 0;
}
} else if (buffer_delay(bh)) {
if (type != XFS_IO_DELALLOC) {
type = XFS_IO_DELALLOC;
imap_valid = 0;
}
} else if (buffer_uptodate(bh)) {
if (type != XFS_IO_OVERWRITE) {
type = XFS_IO_OVERWRITE;
imap_valid = 0;
}
} else {
if (PageUptodate(page))
ASSERT(buffer_mapped(bh));
imap_valid = 0;
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
if (type != XFS_IO_OVERWRITE)
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
if (!ioend)
return 0;
ASSERT(iohead);
if (imap_valid) {
xfs_off_t end_index;
end_index = imap.br_startoff + imap.br_blockcount;
end_index <<= inode->i_blkbits;
end_index = (end_index - 1) >> PAGE_CACHE_SHIFT;
if (end_index > last_index)
end_index = last_index;
xfs_cluster_write(inode, page->index + 1, &imap, &ioend,
wbc, end_index);
}
err = 0;
if (ioend->io_type != XFS_IO_UNWRITTEN && xfs_ioend_is_append(ioend))
err = xfs_setfilesize_trans_alloc(ioend);
xfs_submit_ioend(wbc, iohead, err);
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
trace_xfs_releasepage(page->mapping->host, page, 0, 0);
xfs_count_page_state(page, &delalloc, &unwritten);
if (WARN_ON_ONCE(delalloc))
return 0;
if (WARN_ON_ONCE(unwritten))
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
return -EIO;
offset = (xfs_off_t)iblock << inode->i_blkbits;
ASSERT(bh_result->b_size >= (1 << inode->i_blkbits));
size = bh_result->b_size;
if (!create && direct && offset >= i_size_read(inode))
return 0;
if (create && !direct) {
lockmode = XFS_ILOCK_EXCL;
xfs_ilock(ip, lockmode);
} else {
lockmode = xfs_ilock_data_map_shared(ip);
}
ASSERT(offset <= mp->m_super->s_maxbytes);
if (offset + size > mp->m_super->s_maxbytes)
size = mp->m_super->s_maxbytes - offset;
end_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + size);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
error = xfs_bmapi_read(ip, offset_fsb, end_fsb - offset_fsb,
&imap, &nimaps, XFS_BMAPI_ENTIRE);
if (error)
goto out_unlock;
if (create &&
(!nimaps ||
(imap.br_startblock == HOLESTARTBLOCK ||
imap.br_startblock == DELAYSTARTBLOCK))) {
if (direct || xfs_get_extsz_hint(ip)) {
xfs_iunlock(ip, lockmode);
error = xfs_iomap_write_direct(ip, offset, size,
&imap, nimaps);
if (error)
return error;
new = 1;
} else {
if (nimaps && imap.br_startblock == HOLESTARTBLOCK)
new = 1;
error = xfs_iomap_write_delay(ip, offset, size, &imap);
if (error)
goto out_unlock;
xfs_iunlock(ip, lockmode);
}
trace_xfs_get_blocks_alloc(ip, offset, size, 0, &imap);
} else if (nimaps) {
trace_xfs_get_blocks_found(ip, offset, size, 0, &imap);
xfs_iunlock(ip, lockmode);
} else {
trace_xfs_get_blocks_notfound(ip, offset, size);
goto out_unlock;
}
if (imap.br_startblock != HOLESTARTBLOCK &&
imap.br_startblock != DELAYSTARTBLOCK) {
if (create || !ISUNWRITTEN(&imap))
xfs_map_buffer(inode, bh_result, &imap, offset);
if (create && ISUNWRITTEN(&imap)) {
if (direct) {
bh_result->b_private = inode;
set_buffer_defer_completion(bh_result);
}
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
if (offset < i_size_read(inode) &&
offset + mapping_size >= i_size_read(inode)) {
mapping_size = roundup_64(i_size_read(inode) - offset,
1 << inode->i_blkbits);
}
if (mapping_size > LONG_MAX)
mapping_size = LONG_MAX;
bh_result->b_size = mapping_size;
}
return 0;
out_unlock:
xfs_iunlock(ip, lockmode);
return error;
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
void *private)
{
struct xfs_ioend *ioend = iocb->private;
if (offset + size > i_size_read(ioend->io_inode))
i_size_write(ioend->io_inode, offset + size);
iocb->private = NULL;
ioend->io_offset = offset;
ioend->io_size = size;
if (private && size > 0)
ioend->io_type = XFS_IO_UNWRITTEN;
xfs_finish_ioend_sync(ioend);
}
STATIC ssize_t
xfs_vm_direct_IO(
int rw,
struct kiocb *iocb,
struct iov_iter *iter,
loff_t offset)
{
struct inode *inode = iocb->ki_filp->f_mapping->host;
struct block_device *bdev = xfs_find_bdev_for_inode(inode);
struct xfs_ioend *ioend = NULL;
ssize_t ret;
if (rw & WRITE) {
size_t size = iov_iter_count(iter);
iocb->private = ioend = xfs_alloc_ioend(inode, XFS_IO_DIRECT);
if (offset + size > XFS_I(inode)->i_d.di_size)
ioend->io_isdirect = 1;
ret = __blockdev_direct_IO(rw, iocb, inode, bdev, iter,
offset, xfs_get_blocks_direct,
xfs_end_io_direct_write, NULL,
DIO_ASYNC_EXTEND);
if (ret != -EIOCBQUEUED && iocb->private)
goto out_destroy_ioend;
} else {
ret = __blockdev_direct_IO(rw, iocb, inode, bdev, iter,
offset, xfs_get_blocks_direct,
NULL, NULL, 0);
}
return ret;
out_destroy_ioend:
xfs_destroy_ioend(ioend);
return ret;
}
STATIC void
xfs_vm_kill_delalloc_range(
struct inode *inode,
loff_t start,
loff_t end)
{
struct xfs_inode *ip = XFS_I(inode);
xfs_fileoff_t start_fsb;
xfs_fileoff_t end_fsb;
int error;
start_fsb = XFS_B_TO_FSB(ip->i_mount, start);
end_fsb = XFS_B_TO_FSB(ip->i_mount, end);
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
STATIC void
xfs_vm_write_failed(
struct inode *inode,
struct page *page,
loff_t pos,
unsigned len)
{
loff_t block_offset;
loff_t block_start;
loff_t block_end;
loff_t from = pos & (PAGE_CACHE_SIZE - 1);
loff_t to = from + len;
struct buffer_head *bh, *head;
block_offset = (pos >> PAGE_CACHE_SHIFT) << PAGE_CACHE_SHIFT;
ASSERT(block_offset + from == pos);
head = page_buffers(page);
block_start = 0;
for (bh = head; bh != head || !block_start;
bh = bh->b_this_page, block_start = block_end,
block_offset += bh->b_size) {
block_end = block_start + bh->b_size;
if (block_end <= from)
continue;
if (block_start >= to)
break;
if (!buffer_delay(bh))
continue;
if (!buffer_new(bh) && block_offset < i_size_read(inode))
continue;
xfs_vm_kill_delalloc_range(inode, block_offset,
block_offset + bh->b_size);
clear_buffer_delay(bh);
clear_buffer_uptodate(bh);
clear_buffer_mapped(bh);
clear_buffer_new(bh);
clear_buffer_dirty(bh);
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
pgoff_t index = pos >> PAGE_CACHE_SHIFT;
struct page *page;
int status;
ASSERT(len <= PAGE_CACHE_SIZE);
page = grab_cache_page_write_begin(mapping, index, flags);
if (!page)
return -ENOMEM;
status = __block_write_begin(page, pos, len, xfs_get_blocks);
if (unlikely(status)) {
struct inode *inode = mapping->host;
size_t isize = i_size_read(inode);
xfs_vm_write_failed(inode, page, pos, len);
unlock_page(page);
if (pos + len > isize) {
ssize_t start = max_t(ssize_t, pos, isize);
truncate_pagecache_range(inode, start, pos + len);
}
page_cache_release(page);
page = NULL;
}
*pagep = page;
return status;
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
ASSERT(len <= PAGE_CACHE_SIZE);
ret = generic_write_end(file, mapping, pos, len, copied, page, fsdata);
if (unlikely(ret < len)) {
struct inode *inode = mapping->host;
size_t isize = i_size_read(inode);
loff_t to = pos + len;
if (to > isize) {
if (pos > isize)
isize = pos;
xfs_vm_kill_delalloc_range(inode, isize, to);
truncate_pagecache_range(inode, isize, to);
}
}
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
filemap_write_and_wait(mapping);
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
STATIC int
xfs_vm_set_page_dirty(
struct page *page)
{
struct address_space *mapping = page->mapping;
struct inode *inode = mapping->host;
loff_t end_offset;
loff_t offset;
int newly_dirty;
if (unlikely(!mapping))
return !TestSetPageDirty(page);
end_offset = i_size_read(inode);
offset = page_offset(page);
spin_lock(&mapping->private_lock);
if (page_has_buffers(page)) {
struct buffer_head *head = page_buffers(page);
struct buffer_head *bh = head;
do {
if (offset < end_offset)
set_buffer_dirty(bh);
bh = bh->b_this_page;
offset += 1 << inode->i_blkbits;
} while (bh != head);
}
newly_dirty = !TestSetPageDirty(page);
spin_unlock(&mapping->private_lock);
if (newly_dirty) {
unsigned long flags;
spin_lock_irqsave(&mapping->tree_lock, flags);
if (page->mapping) {
WARN_ON_ONCE(!PageUptodate(page));
account_page_dirtied(page, mapping);
radix_tree_tag_set(&mapping->page_tree,
page_index(page), PAGECACHE_TAG_DIRTY);
}
spin_unlock_irqrestore(&mapping->tree_lock, flags);
__mark_inode_dirty(mapping->host, I_DIRTY_PAGES);
}
return newly_dirty;
}
