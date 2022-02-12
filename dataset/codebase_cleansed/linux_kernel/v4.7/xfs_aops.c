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
struct block_device *
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
static void
xfs_finish_page_writeback(
struct inode *inode,
struct bio_vec *bvec,
int error)
{
unsigned int end = bvec->bv_offset + bvec->bv_len - 1;
struct buffer_head *head, *bh;
unsigned int off = 0;
ASSERT(bvec->bv_offset < PAGE_SIZE);
ASSERT((bvec->bv_offset & ((1 << inode->i_blkbits) - 1)) == 0);
ASSERT(end < PAGE_SIZE);
ASSERT((bvec->bv_len & ((1 << inode->i_blkbits) - 1)) == 0);
bh = head = page_buffers(bvec->bv_page);
do {
if (off < bvec->bv_offset)
goto next_bh;
if (off > end)
break;
bh->b_end_io(bh, !error);
next_bh:
off += bh->b_size;
} while ((bh = bh->b_this_page) != head);
}
STATIC void
xfs_destroy_ioend(
struct xfs_ioend *ioend,
int error)
{
struct inode *inode = ioend->io_inode;
struct bio *last = ioend->io_bio;
struct bio *bio, *next;
for (bio = &ioend->io_inline_bio; bio; bio = next) {
struct bio_vec *bvec;
int i;
if (bio == last)
next = NULL;
else
next = bio->bi_private;
bio_for_each_segment_all(bvec, bio, i)
xfs_finish_page_writeback(inode, bvec, error);
bio_put(bio);
}
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
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_fsyncts, 0, 0, 0, &tp);
if (error)
return error;
ioend->io_append_trans = tp;
__sb_writers_release(ioend->io_inode->i_sb, SB_FREEZE_FS);
current_restore_flags_nested(&tp->t_pflags, PF_FSTRANS);
return 0;
}
STATIC int
xfs_setfilesize(
struct xfs_inode *ip,
struct xfs_trans *tp,
xfs_off_t offset,
size_t size)
{
xfs_fsize_t isize;
xfs_ilock(ip, XFS_ILOCK_EXCL);
isize = xfs_new_eof(ip, offset + size);
if (!isize) {
xfs_iunlock(ip, XFS_ILOCK_EXCL);
xfs_trans_cancel(tp);
return 0;
}
trace_xfs_setfilesize(ip, offset, size);
ip->i_d.di_size = isize;
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
return xfs_trans_commit(tp);
}
STATIC int
xfs_setfilesize_ioend(
struct xfs_ioend *ioend,
int error)
{
struct xfs_inode *ip = XFS_I(ioend->io_inode);
struct xfs_trans *tp = ioend->io_append_trans;
current_set_flags_nested(&tp->t_pflags, PF_FSTRANS);
__sb_writers_acquired(VFS_I(ip)->i_sb, SB_FREEZE_FS);
if (error) {
xfs_trans_cancel(tp);
return error;
}
return xfs_setfilesize(ip, tp, ioend->io_offset, ioend->io_size);
}
STATIC void
xfs_end_io(
struct work_struct *work)
{
struct xfs_ioend *ioend =
container_of(work, struct xfs_ioend, io_work);
struct xfs_inode *ip = XFS_I(ioend->io_inode);
int error = ioend->io_bio->bi_error;
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
error = -EIO;
if (ioend->io_type == XFS_IO_UNWRITTEN) {
if (error)
goto done;
error = xfs_iomap_write_unwritten(ip, ioend->io_offset,
ioend->io_size);
} else if (ioend->io_append_trans) {
error = xfs_setfilesize_ioend(ioend, error);
} else {
ASSERT(!xfs_ioend_is_append(ioend));
}
done:
xfs_destroy_ioend(ioend, error);
}
STATIC void
xfs_end_bio(
struct bio *bio)
{
struct xfs_ioend *ioend = bio->bi_private;
struct xfs_mount *mp = XFS_I(ioend->io_inode)->i_mount;
if (ioend->io_type == XFS_IO_UNWRITTEN)
queue_work(mp->m_unwritten_workqueue, &ioend->io_work);
else if (ioend->io_append_trans)
queue_work(mp->m_data_workqueue, &ioend->io_work);
else
xfs_destroy_ioend(ioend, bio->bi_error);
}
STATIC int
xfs_map_blocks(
struct inode *inode,
loff_t offset,
struct xfs_bmbt_irec *imap,
int type)
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
xfs_ilock(ip, XFS_ILOCK_SHARED);
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
STATIC bool
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
int clear_dirty)
{
ASSERT(PageLocked(page));
ASSERT(!PageWriteback(page));
if (clear_dirty) {
clear_page_dirty_for_io(page);
set_page_writeback(page);
} else
set_page_writeback_keepwrite(page);
unlock_page(page);
}
static inline int xfs_bio_add_buffer(struct bio *bio, struct buffer_head *bh)
{
return bio_add_page(bio, bh->b_page, bh->b_size, bh_offset(bh));
}
STATIC int
xfs_submit_ioend(
struct writeback_control *wbc,
struct xfs_ioend *ioend,
int status)
{
if (!status &&
ioend->io_type != XFS_IO_UNWRITTEN &&
xfs_ioend_is_append(ioend) &&
!ioend->io_append_trans)
status = xfs_setfilesize_trans_alloc(ioend);
ioend->io_bio->bi_private = ioend;
ioend->io_bio->bi_end_io = xfs_end_bio;
if (status) {
ioend->io_bio->bi_error = status;
bio_endio(ioend->io_bio);
return status;
}
submit_bio(wbc->sync_mode == WB_SYNC_ALL ? WRITE_SYNC : WRITE,
ioend->io_bio);
return 0;
}
static void
xfs_init_bio_from_bh(
struct bio *bio,
struct buffer_head *bh)
{
bio->bi_iter.bi_sector = bh->b_blocknr * (bh->b_size >> 9);
bio->bi_bdev = bh->b_bdev;
}
static struct xfs_ioend *
xfs_alloc_ioend(
struct inode *inode,
unsigned int type,
xfs_off_t offset,
struct buffer_head *bh)
{
struct xfs_ioend *ioend;
struct bio *bio;
bio = bio_alloc_bioset(GFP_NOFS, BIO_MAX_PAGES, xfs_ioend_bioset);
xfs_init_bio_from_bh(bio, bh);
ioend = container_of(bio, struct xfs_ioend, io_inline_bio);
INIT_LIST_HEAD(&ioend->io_list);
ioend->io_type = type;
ioend->io_inode = inode;
ioend->io_size = 0;
ioend->io_offset = offset;
INIT_WORK(&ioend->io_work, xfs_end_io);
ioend->io_append_trans = NULL;
ioend->io_bio = bio;
return ioend;
}
static void
xfs_chain_bio(
struct xfs_ioend *ioend,
struct writeback_control *wbc,
struct buffer_head *bh)
{
struct bio *new;
new = bio_alloc(GFP_NOFS, BIO_MAX_PAGES);
xfs_init_bio_from_bh(new, bh);
bio_chain(ioend->io_bio, new);
bio_get(ioend->io_bio);
submit_bio(wbc->sync_mode == WB_SYNC_ALL ? WRITE_SYNC : WRITE,
ioend->io_bio);
ioend->io_bio = new;
}
STATIC void
xfs_add_to_ioend(
struct inode *inode,
struct buffer_head *bh,
xfs_off_t offset,
struct xfs_writepage_ctx *wpc,
struct writeback_control *wbc,
struct list_head *iolist)
{
if (!wpc->ioend || wpc->io_type != wpc->ioend->io_type ||
bh->b_blocknr != wpc->last_block + 1 ||
offset != wpc->ioend->io_offset + wpc->ioend->io_size) {
if (wpc->ioend)
list_add(&wpc->ioend->io_list, iolist);
wpc->ioend = xfs_alloc_ioend(inode, wpc->io_type, offset, bh);
}
while (xfs_bio_add_buffer(wpc->ioend->io_bio, bh) != bh->b_size)
xfs_chain_bio(wpc->ioend, wbc, bh);
wpc->ioend->io_size += bh->b_size;
wpc->last_block = bh->b_blocknr;
xfs_start_buffer_writeback(bh);
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
xfs_vm_invalidatepage(page, 0, PAGE_SIZE);
return;
}
static int
xfs_writepage_map(
struct xfs_writepage_ctx *wpc,
struct writeback_control *wbc,
struct inode *inode,
struct page *page,
loff_t offset,
__uint64_t end_offset)
{
LIST_HEAD(submit_list);
struct xfs_ioend *ioend, *next;
struct buffer_head *bh, *head;
ssize_t len = 1 << inode->i_blkbits;
int error = 0;
int count = 0;
int uptodate = 1;
bh = head = page_buffers(page);
offset = page_offset(page);
do {
if (offset >= end_offset)
break;
if (!buffer_uptodate(bh))
uptodate = 0;
if (!buffer_mapped(bh) && buffer_uptodate(bh)) {
wpc->imap_valid = false;
continue;
}
if (buffer_unwritten(bh)) {
if (wpc->io_type != XFS_IO_UNWRITTEN) {
wpc->io_type = XFS_IO_UNWRITTEN;
wpc->imap_valid = false;
}
} else if (buffer_delay(bh)) {
if (wpc->io_type != XFS_IO_DELALLOC) {
wpc->io_type = XFS_IO_DELALLOC;
wpc->imap_valid = false;
}
} else if (buffer_uptodate(bh)) {
if (wpc->io_type != XFS_IO_OVERWRITE) {
wpc->io_type = XFS_IO_OVERWRITE;
wpc->imap_valid = false;
}
} else {
if (PageUptodate(page))
ASSERT(buffer_mapped(bh));
wpc->imap_valid = false;
continue;
}
if (wpc->imap_valid)
wpc->imap_valid = xfs_imap_valid(inode, &wpc->imap,
offset);
if (!wpc->imap_valid) {
error = xfs_map_blocks(inode, offset, &wpc->imap,
wpc->io_type);
if (error)
goto out;
wpc->imap_valid = xfs_imap_valid(inode, &wpc->imap,
offset);
}
if (wpc->imap_valid) {
lock_buffer(bh);
if (wpc->io_type != XFS_IO_OVERWRITE)
xfs_map_at_offset(inode, bh, &wpc->imap, offset);
xfs_add_to_ioend(inode, bh, offset, wpc, wbc, &submit_list);
count++;
}
} while (offset += len, ((bh = bh->b_this_page) != head));
if (uptodate && bh == head)
SetPageUptodate(page);
ASSERT(wpc->ioend || list_empty(&submit_list));
out:
if (count) {
xfs_start_page_writeback(page, !error);
list_for_each_entry_safe(ioend, next, &submit_list, io_list) {
int error2;
list_del_init(&ioend->io_list);
error2 = xfs_submit_ioend(wbc, ioend, error);
if (error2 && !error)
error = error2;
}
} else if (error) {
xfs_aops_discard_page(page);
ClearPageUptodate(page);
unlock_page(page);
} else {
xfs_start_page_writeback(page, 1);
end_page_writeback(page);
}
mapping_set_error(page->mapping, error);
return error;
}
STATIC int
xfs_do_writepage(
struct page *page,
struct writeback_control *wbc,
void *data)
{
struct xfs_writepage_ctx *wpc = data;
struct inode *inode = page->mapping->host;
loff_t offset;
__uint64_t end_offset;
pgoff_t end_index;
trace_xfs_writepage(inode, page, 0, 0);
ASSERT(page_has_buffers(page));
if (WARN_ON_ONCE((current->flags & (PF_MEMALLOC|PF_KSWAPD)) ==
PF_MEMALLOC))
goto redirty;
if (WARN_ON_ONCE(current->flags & PF_FSTRANS))
goto redirty;
offset = i_size_read(inode);
end_index = offset >> PAGE_SHIFT;
if (page->index < end_index)
end_offset = (xfs_off_t)(page->index + 1) << PAGE_SHIFT;
else {
unsigned offset_into_page = offset & (PAGE_SIZE - 1);
if (page->index > end_index ||
(page->index == end_index && offset_into_page == 0))
goto redirty;
zero_user_segment(page, offset_into_page, PAGE_SIZE);
end_offset = offset;
}
return xfs_writepage_map(wpc, wbc, inode, page, offset, end_offset);
redirty:
redirty_page_for_writepage(wbc, page);
unlock_page(page);
return 0;
}
STATIC int
xfs_vm_writepage(
struct page *page,
struct writeback_control *wbc)
{
struct xfs_writepage_ctx wpc = {
.io_type = XFS_IO_INVALID,
};
int ret;
ret = xfs_do_writepage(page, wbc, &wpc);
if (wpc.ioend)
ret = xfs_submit_ioend(wbc, wpc.ioend, ret);
return ret;
}
STATIC int
xfs_vm_writepages(
struct address_space *mapping,
struct writeback_control *wbc)
{
struct xfs_writepage_ctx wpc = {
.io_type = XFS_IO_INVALID,
};
int ret;
xfs_iflags_clear(XFS_I(mapping->host), XFS_ITRUNCATED);
if (dax_mapping(mapping))
return dax_writeback_mapping_range(mapping,
xfs_find_bdev_for_inode(mapping->host), wbc);
ret = write_cache_pages(mapping, wbc, xfs_do_writepage, &wpc);
if (wpc.ioend)
ret = xfs_submit_ioend(wbc, wpc.ioend, ret);
return ret;
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
static void
xfs_map_direct(
struct inode *inode,
struct buffer_head *bh_result,
struct xfs_bmbt_irec *imap,
xfs_off_t offset)
{
uintptr_t *flags = (uintptr_t *)&bh_result->b_private;
xfs_off_t size = bh_result->b_size;
trace_xfs_get_blocks_map_direct(XFS_I(inode), offset, size,
ISUNWRITTEN(imap) ? XFS_IO_UNWRITTEN : XFS_IO_OVERWRITE, imap);
if (ISUNWRITTEN(imap)) {
*flags |= XFS_DIO_FLAG_UNWRITTEN;
set_buffer_defer_completion(bh_result);
} else if (offset + size > i_size_read(inode) || offset + size < 0) {
*flags |= XFS_DIO_FLAG_APPEND;
set_buffer_defer_completion(bh_result);
}
}
static void
xfs_map_trim_size(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
struct xfs_bmbt_irec *imap,
xfs_off_t offset,
ssize_t size)
{
xfs_off_t mapping_size;
mapping_size = imap->br_startoff + imap->br_blockcount - iblock;
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
STATIC int
__xfs_get_blocks(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
int create,
bool direct,
bool dax_fault)
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
imap.br_startblock == DELAYSTARTBLOCK) ||
(IS_DAX(inode) && ISUNWRITTEN(&imap)))) {
if (direct || xfs_get_extsz_hint(ip)) {
if (lockmode == XFS_ILOCK_EXCL)
xfs_ilock_demote(ip, lockmode);
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
trace_xfs_get_blocks_alloc(ip, offset, size,
ISUNWRITTEN(&imap) ? XFS_IO_UNWRITTEN
: XFS_IO_DELALLOC, &imap);
} else if (nimaps) {
trace_xfs_get_blocks_found(ip, offset, size,
ISUNWRITTEN(&imap) ? XFS_IO_UNWRITTEN
: XFS_IO_OVERWRITE, &imap);
xfs_iunlock(ip, lockmode);
} else {
trace_xfs_get_blocks_notfound(ip, offset, size);
goto out_unlock;
}
if (IS_DAX(inode) && create) {
ASSERT(!ISUNWRITTEN(&imap));
new = 0;
}
if (direct || size > (1 << inode->i_blkbits))
xfs_map_trim_size(inode, iblock, bh_result,
&imap, offset, size);
if (imap.br_startblock != HOLESTARTBLOCK &&
imap.br_startblock != DELAYSTARTBLOCK &&
(create || !ISUNWRITTEN(&imap))) {
xfs_map_buffer(inode, bh_result, &imap, offset);
if (ISUNWRITTEN(&imap))
set_buffer_unwritten(bh_result);
if (create && direct) {
if (dax_fault)
ASSERT(!ISUNWRITTEN(&imap));
else
xfs_map_direct(inode, bh_result, &imap, offset);
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
return __xfs_get_blocks(inode, iblock, bh_result, create, false, false);
}
int
xfs_get_blocks_direct(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
int create)
{
return __xfs_get_blocks(inode, iblock, bh_result, create, true, false);
}
int
xfs_get_blocks_dax_fault(
struct inode *inode,
sector_t iblock,
struct buffer_head *bh_result,
int create)
{
return __xfs_get_blocks(inode, iblock, bh_result, create, true, true);
}
STATIC int
xfs_end_io_direct_write(
struct kiocb *iocb,
loff_t offset,
ssize_t size,
void *private)
{
struct inode *inode = file_inode(iocb->ki_filp);
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
uintptr_t flags = (uintptr_t)private;
int error = 0;
trace_xfs_end_io_direct_write(ip, offset, size);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
if (size <= 0)
return size;
if (flags == 0) {
ASSERT(offset + size <= i_size_read(inode));
return 0;
}
spin_lock(&ip->i_flags_lock);
if (offset + size > i_size_read(inode))
i_size_write(inode, offset + size);
spin_unlock(&ip->i_flags_lock);
if (flags & XFS_DIO_FLAG_UNWRITTEN) {
trace_xfs_end_io_direct_write_unwritten(ip, offset, size);
error = xfs_iomap_write_unwritten(ip, offset, size);
} else if (flags & XFS_DIO_FLAG_APPEND) {
struct xfs_trans *tp;
trace_xfs_end_io_direct_write_append(ip, offset, size);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_fsyncts, 0, 0, 0,
&tp);
if (!error)
error = xfs_setfilesize(ip, tp, offset, size);
}
return error;
}
STATIC ssize_t
xfs_vm_direct_IO(
struct kiocb *iocb,
struct iov_iter *iter)
{
struct inode *inode = iocb->ki_filp->f_mapping->host;
dio_iodone_t *endio = NULL;
int flags = 0;
struct block_device *bdev;
if (iov_iter_rw(iter) == WRITE) {
endio = xfs_end_io_direct_write;
flags = DIO_ASYNC_EXTEND;
}
if (IS_DAX(inode)) {
return dax_do_io(iocb, inode, iter,
xfs_get_blocks_direct, endio, 0);
}
bdev = xfs_find_bdev_for_inode(inode);
return __blockdev_direct_IO(iocb, inode, bdev, iter,
xfs_get_blocks_direct, endio, NULL, flags);
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
loff_t from = pos & (PAGE_SIZE - 1);
loff_t to = from + len;
struct buffer_head *bh, *head;
struct xfs_mount *mp = XFS_I(inode)->i_mount;
block_offset = (pos >> PAGE_SHIFT) << PAGE_SHIFT;
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
if (!buffer_delay(bh) && !buffer_unwritten(bh))
continue;
if (!xfs_mp_fail_writes(mp) && !buffer_new(bh) &&
block_offset < i_size_read(inode))
continue;
if (buffer_delay(bh))
xfs_vm_kill_delalloc_range(inode, block_offset,
block_offset + bh->b_size);
clear_buffer_delay(bh);
clear_buffer_uptodate(bh);
clear_buffer_mapped(bh);
clear_buffer_new(bh);
clear_buffer_dirty(bh);
clear_buffer_unwritten(bh);
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
pgoff_t index = pos >> PAGE_SHIFT;
struct page *page;
int status;
struct xfs_mount *mp = XFS_I(mapping->host)->i_mount;
ASSERT(len <= PAGE_SIZE);
page = grab_cache_page_write_begin(mapping, index, flags);
if (!page)
return -ENOMEM;
status = __block_write_begin(page, pos, len, xfs_get_blocks);
if (xfs_mp_fail_writes(mp))
status = -EIO;
if (unlikely(status)) {
struct inode *inode = mapping->host;
size_t isize = i_size_read(inode);
xfs_vm_write_failed(inode, page, pos, len);
unlock_page(page);
if (xfs_mp_fail_writes(mp))
isize = 0;
if (pos + len > isize) {
ssize_t start = max_t(ssize_t, pos, isize);
truncate_pagecache_range(inode, start, pos + len);
}
put_page(page);
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
ASSERT(len <= PAGE_SIZE);
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
trace_xfs_vm_readpage(page->mapping->host, 1);
return mpage_readpage(page, xfs_get_blocks);
}
STATIC int
xfs_vm_readpages(
struct file *unused,
struct address_space *mapping,
struct list_head *pages,
unsigned nr_pages)
{
trace_xfs_vm_readpages(mapping->host, nr_pages);
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
lock_page_memcg(page);
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
}
unlock_page_memcg(page);
if (newly_dirty)
__mark_inode_dirty(mapping->host, I_DIRTY_PAGES);
return newly_dirty;
}
