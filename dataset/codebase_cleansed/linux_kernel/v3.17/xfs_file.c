static inline void
xfs_rw_ilock(
struct xfs_inode *ip,
int type)
{
if (type & XFS_IOLOCK_EXCL)
mutex_lock(&VFS_I(ip)->i_mutex);
xfs_ilock(ip, type);
}
static inline void
xfs_rw_iunlock(
struct xfs_inode *ip,
int type)
{
xfs_iunlock(ip, type);
if (type & XFS_IOLOCK_EXCL)
mutex_unlock(&VFS_I(ip)->i_mutex);
}
static inline void
xfs_rw_ilock_demote(
struct xfs_inode *ip,
int type)
{
xfs_ilock_demote(ip, type);
if (type & XFS_IOLOCK_EXCL)
mutex_unlock(&VFS_I(ip)->i_mutex);
}
int
xfs_iozero(
struct xfs_inode *ip,
loff_t pos,
size_t count)
{
struct page *page;
struct address_space *mapping;
int status;
mapping = VFS_I(ip)->i_mapping;
do {
unsigned offset, bytes;
void *fsdata;
offset = (pos & (PAGE_CACHE_SIZE -1));
bytes = PAGE_CACHE_SIZE - offset;
if (bytes > count)
bytes = count;
status = pagecache_write_begin(NULL, mapping, pos, bytes,
AOP_FLAG_UNINTERRUPTIBLE,
&page, &fsdata);
if (status)
break;
zero_user(page, offset, bytes);
status = pagecache_write_end(NULL, mapping, pos, bytes, bytes,
page, fsdata);
WARN_ON(status <= 0);
pos += bytes;
count -= bytes;
status = 0;
} while (count);
return (-status);
}
STATIC int
xfs_dir_fsync(
struct file *file,
loff_t start,
loff_t end,
int datasync)
{
struct xfs_inode *ip = XFS_I(file->f_mapping->host);
struct xfs_mount *mp = ip->i_mount;
xfs_lsn_t lsn = 0;
trace_xfs_dir_fsync(ip);
xfs_ilock(ip, XFS_ILOCK_SHARED);
if (xfs_ipincount(ip))
lsn = ip->i_itemp->ili_last_lsn;
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (!lsn)
return 0;
return _xfs_log_force_lsn(mp, lsn, XFS_LOG_SYNC, NULL);
}
STATIC int
xfs_file_fsync(
struct file *file,
loff_t start,
loff_t end,
int datasync)
{
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
int error = 0;
int log_flushed = 0;
xfs_lsn_t lsn = 0;
trace_xfs_file_fsync(ip);
error = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (error)
return error;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
xfs_iflags_clear(ip, XFS_ITRUNCATED);
if (mp->m_flags & XFS_MOUNT_BARRIER) {
if (XFS_IS_REALTIME_INODE(ip))
xfs_blkdev_issue_flush(mp->m_rtdev_targp);
else if (mp->m_logdev_targp != mp->m_ddev_targp)
xfs_blkdev_issue_flush(mp->m_ddev_targp);
}
xfs_ilock(ip, XFS_ILOCK_SHARED);
if (xfs_ipincount(ip)) {
if (!datasync ||
(ip->i_itemp->ili_fields & ~XFS_ILOG_TIMESTAMP))
lsn = ip->i_itemp->ili_last_lsn;
}
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (lsn)
error = _xfs_log_force_lsn(mp, lsn, XFS_LOG_SYNC, &log_flushed);
if ((mp->m_flags & XFS_MOUNT_BARRIER) &&
mp->m_logdev_targp == mp->m_ddev_targp &&
!XFS_IS_REALTIME_INODE(ip) &&
!log_flushed)
xfs_blkdev_issue_flush(mp->m_ddev_targp);
return error;
}
STATIC ssize_t
xfs_file_read_iter(
struct kiocb *iocb,
struct iov_iter *to)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
size_t size = iov_iter_count(to);
ssize_t ret = 0;
int ioflags = 0;
xfs_fsize_t n;
loff_t pos = iocb->ki_pos;
XFS_STATS_INC(xs_read_calls);
if (unlikely(file->f_flags & O_DIRECT))
ioflags |= XFS_IO_ISDIRECT;
if (file->f_mode & FMODE_NOCMTIME)
ioflags |= XFS_IO_INVIS;
if (unlikely(ioflags & XFS_IO_ISDIRECT)) {
xfs_buftarg_t *target =
XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp;
if ((pos | size) & target->bt_logical_sectormask) {
if (pos == i_size_read(inode))
return 0;
return -EINVAL;
}
}
n = mp->m_super->s_maxbytes - pos;
if (n <= 0 || size == 0)
return 0;
if (n < size)
size = n;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
xfs_rw_ilock(ip, XFS_IOLOCK_SHARED);
if ((ioflags & XFS_IO_ISDIRECT) && inode->i_mapping->nrpages) {
xfs_rw_iunlock(ip, XFS_IOLOCK_SHARED);
xfs_rw_ilock(ip, XFS_IOLOCK_EXCL);
if (inode->i_mapping->nrpages) {
ret = filemap_write_and_wait_range(
VFS_I(ip)->i_mapping,
pos, pos + size - 1);
if (ret) {
xfs_rw_iunlock(ip, XFS_IOLOCK_EXCL);
return ret;
}
ret = invalidate_inode_pages2_range(VFS_I(ip)->i_mapping,
pos >> PAGE_CACHE_SHIFT,
(pos + size - 1) >> PAGE_CACHE_SHIFT);
WARN_ON_ONCE(ret);
ret = 0;
}
xfs_rw_ilock_demote(ip, XFS_IOLOCK_EXCL);
}
trace_xfs_file_read(ip, size, pos, ioflags);
ret = generic_file_read_iter(iocb, to);
if (ret > 0)
XFS_STATS_ADD(xs_read_bytes, ret);
xfs_rw_iunlock(ip, XFS_IOLOCK_SHARED);
return ret;
}
STATIC ssize_t
xfs_file_splice_read(
struct file *infilp,
loff_t *ppos,
struct pipe_inode_info *pipe,
size_t count,
unsigned int flags)
{
struct xfs_inode *ip = XFS_I(infilp->f_mapping->host);
int ioflags = 0;
ssize_t ret;
XFS_STATS_INC(xs_read_calls);
if (infilp->f_mode & FMODE_NOCMTIME)
ioflags |= XFS_IO_INVIS;
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return -EIO;
xfs_rw_ilock(ip, XFS_IOLOCK_SHARED);
trace_xfs_file_splice_read(ip, count, *ppos, ioflags);
ret = generic_file_splice_read(infilp, ppos, pipe, count, flags);
if (ret > 0)
XFS_STATS_ADD(xs_read_bytes, ret);
xfs_rw_iunlock(ip, XFS_IOLOCK_SHARED);
return ret;
}
STATIC int
xfs_zero_last_block(
struct xfs_inode *ip,
xfs_fsize_t offset,
xfs_fsize_t isize)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t last_fsb = XFS_B_TO_FSBT(mp, isize);
int zero_offset = XFS_B_FSB_OFFSET(mp, isize);
int zero_len;
int nimaps = 1;
int error = 0;
struct xfs_bmbt_irec imap;
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_bmapi_read(ip, last_fsb, 1, &imap, &nimaps, 0);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
return error;
ASSERT(nimaps > 0);
if (imap.br_startblock == HOLESTARTBLOCK)
return 0;
zero_len = mp->m_sb.sb_blocksize - zero_offset;
if (isize + zero_len > offset)
zero_len = offset - isize;
return xfs_iozero(ip, isize, zero_len);
}
int
xfs_zero_eof(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_fsize_t isize)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t start_zero_fsb;
xfs_fileoff_t end_zero_fsb;
xfs_fileoff_t zero_count_fsb;
xfs_fileoff_t last_fsb;
xfs_fileoff_t zero_off;
xfs_fsize_t zero_len;
int nimaps;
int error = 0;
struct xfs_bmbt_irec imap;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(offset > isize);
if (XFS_B_FSB_OFFSET(mp, isize) != 0) {
error = xfs_zero_last_block(ip, offset, isize);
if (error)
return error;
}
last_fsb = isize ? XFS_B_TO_FSBT(mp, isize - 1) : (xfs_fileoff_t)-1;
start_zero_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)isize);
end_zero_fsb = XFS_B_TO_FSBT(mp, offset - 1);
ASSERT((xfs_sfiloff_t)last_fsb < (xfs_sfiloff_t)start_zero_fsb);
if (last_fsb == end_zero_fsb) {
return 0;
}
ASSERT(start_zero_fsb <= end_zero_fsb);
while (start_zero_fsb <= end_zero_fsb) {
nimaps = 1;
zero_count_fsb = end_zero_fsb - start_zero_fsb + 1;
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_bmapi_read(ip, start_zero_fsb, zero_count_fsb,
&imap, &nimaps, 0);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
return error;
ASSERT(nimaps > 0);
if (imap.br_state == XFS_EXT_UNWRITTEN ||
imap.br_startblock == HOLESTARTBLOCK) {
start_zero_fsb = imap.br_startoff + imap.br_blockcount;
ASSERT(start_zero_fsb <= (end_zero_fsb + 1));
continue;
}
zero_off = XFS_FSB_TO_B(mp, start_zero_fsb);
zero_len = XFS_FSB_TO_B(mp, imap.br_blockcount);
if ((zero_off + zero_len) > offset)
zero_len = offset - zero_off;
error = xfs_iozero(ip, zero_off, zero_len);
if (error)
return error;
start_zero_fsb = imap.br_startoff + imap.br_blockcount;
ASSERT(start_zero_fsb <= (end_zero_fsb + 1));
}
return 0;
}
STATIC ssize_t
xfs_file_aio_write_checks(
struct file *file,
loff_t *pos,
size_t *count,
int *iolock)
{
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
int error = 0;
restart:
error = generic_write_checks(file, pos, count, S_ISBLK(inode->i_mode));
if (error)
return error;
if (*pos > i_size_read(inode)) {
if (*iolock == XFS_IOLOCK_SHARED) {
xfs_rw_iunlock(ip, *iolock);
*iolock = XFS_IOLOCK_EXCL;
xfs_rw_ilock(ip, *iolock);
goto restart;
}
error = xfs_zero_eof(ip, *pos, i_size_read(inode));
if (error)
return error;
}
if (likely(!(file->f_mode & FMODE_NOCMTIME))) {
error = file_update_time(file);
if (error)
return error;
}
return file_remove_suid(file);
}
STATIC ssize_t
xfs_file_dio_aio_write(
struct kiocb *iocb,
struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
ssize_t ret = 0;
int unaligned_io = 0;
int iolock;
size_t count = iov_iter_count(from);
loff_t pos = iocb->ki_pos;
struct xfs_buftarg *target = XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp;
if ((pos | count) & target->bt_logical_sectormask)
return -EINVAL;
if ((pos & mp->m_blockmask) || ((pos + count) & mp->m_blockmask))
unaligned_io = 1;
if (unaligned_io || mapping->nrpages)
iolock = XFS_IOLOCK_EXCL;
else
iolock = XFS_IOLOCK_SHARED;
xfs_rw_ilock(ip, iolock);
if (mapping->nrpages && iolock == XFS_IOLOCK_SHARED) {
xfs_rw_iunlock(ip, iolock);
iolock = XFS_IOLOCK_EXCL;
xfs_rw_ilock(ip, iolock);
}
ret = xfs_file_aio_write_checks(file, &pos, &count, &iolock);
if (ret)
goto out;
iov_iter_truncate(from, count);
if (mapping->nrpages) {
ret = filemap_write_and_wait_range(VFS_I(ip)->i_mapping,
pos, pos + count - 1);
if (ret)
goto out;
ret = invalidate_inode_pages2_range(VFS_I(ip)->i_mapping,
pos >> PAGE_CACHE_SHIFT,
(pos + count - 1) >> PAGE_CACHE_SHIFT);
WARN_ON_ONCE(ret);
ret = 0;
}
if (unaligned_io)
inode_dio_wait(inode);
else if (iolock == XFS_IOLOCK_EXCL) {
xfs_rw_ilock_demote(ip, XFS_IOLOCK_EXCL);
iolock = XFS_IOLOCK_SHARED;
}
trace_xfs_file_direct_write(ip, count, iocb->ki_pos, 0);
ret = generic_file_direct_write(iocb, from, pos);
out:
xfs_rw_iunlock(ip, iolock);
ASSERT(ret < 0 || ret == count);
return ret;
}
STATIC ssize_t
xfs_file_buffered_aio_write(
struct kiocb *iocb,
struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct xfs_inode *ip = XFS_I(inode);
ssize_t ret;
int enospc = 0;
int iolock = XFS_IOLOCK_EXCL;
loff_t pos = iocb->ki_pos;
size_t count = iov_iter_count(from);
xfs_rw_ilock(ip, iolock);
ret = xfs_file_aio_write_checks(file, &pos, &count, &iolock);
if (ret)
goto out;
iov_iter_truncate(from, count);
current->backing_dev_info = mapping->backing_dev_info;
write_retry:
trace_xfs_file_buffered_write(ip, count, iocb->ki_pos, 0);
ret = generic_perform_write(file, from, pos);
if (likely(ret >= 0))
iocb->ki_pos = pos + ret;
if (ret == -EDQUOT && !enospc) {
enospc = xfs_inode_free_quota_eofblocks(ip);
if (enospc)
goto write_retry;
} else if (ret == -ENOSPC && !enospc) {
struct xfs_eofblocks eofb = {0};
enospc = 1;
xfs_flush_inodes(ip->i_mount);
eofb.eof_scan_owner = ip->i_ino;
eofb.eof_flags = XFS_EOF_FLAGS_SYNC;
xfs_icache_free_eofblocks(ip->i_mount, &eofb);
goto write_retry;
}
current->backing_dev_info = NULL;
out:
xfs_rw_iunlock(ip, iolock);
return ret;
}
STATIC ssize_t
xfs_file_write_iter(
struct kiocb *iocb,
struct iov_iter *from)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct xfs_inode *ip = XFS_I(inode);
ssize_t ret;
size_t ocount = iov_iter_count(from);
XFS_STATS_INC(xs_write_calls);
if (ocount == 0)
return 0;
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return -EIO;
if (unlikely(file->f_flags & O_DIRECT))
ret = xfs_file_dio_aio_write(iocb, from);
else
ret = xfs_file_buffered_aio_write(iocb, from);
if (ret > 0) {
ssize_t err;
XFS_STATS_ADD(xs_write_bytes, ret);
err = generic_write_sync(file, iocb->ki_pos - ret, ret);
if (err < 0)
ret = err;
}
return ret;
}
STATIC long
xfs_file_fallocate(
struct file *file,
int mode,
loff_t offset,
loff_t len)
{
struct inode *inode = file_inode(file);
struct xfs_inode *ip = XFS_I(inode);
struct xfs_trans *tp;
long error;
loff_t new_size = 0;
if (!S_ISREG(inode->i_mode))
return -EINVAL;
if (mode & ~(FALLOC_FL_KEEP_SIZE | FALLOC_FL_PUNCH_HOLE |
FALLOC_FL_COLLAPSE_RANGE | FALLOC_FL_ZERO_RANGE))
return -EOPNOTSUPP;
xfs_ilock(ip, XFS_IOLOCK_EXCL);
if (mode & FALLOC_FL_PUNCH_HOLE) {
error = xfs_free_file_space(ip, offset, len);
if (error)
goto out_unlock;
} else if (mode & FALLOC_FL_COLLAPSE_RANGE) {
unsigned blksize_mask = (1 << inode->i_blkbits) - 1;
if (offset & blksize_mask || len & blksize_mask) {
error = -EINVAL;
goto out_unlock;
}
if (offset + len >= i_size_read(inode)) {
error = -EINVAL;
goto out_unlock;
}
new_size = i_size_read(inode) - len;
error = xfs_collapse_file_space(ip, offset, len);
if (error)
goto out_unlock;
} else {
if (!(mode & FALLOC_FL_KEEP_SIZE) &&
offset + len > i_size_read(inode)) {
new_size = offset + len;
error = inode_newsize_ok(inode, new_size);
if (error)
goto out_unlock;
}
if (mode & FALLOC_FL_ZERO_RANGE)
error = xfs_zero_file_space(ip, offset, len);
else
error = xfs_alloc_file_space(ip, offset, len,
XFS_BMAPI_PREALLOC);
if (error)
goto out_unlock;
}
tp = xfs_trans_alloc(ip->i_mount, XFS_TRANS_WRITEID);
error = xfs_trans_reserve(tp, &M_RES(ip->i_mount)->tr_writeid, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
goto out_unlock;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
ip->i_d.di_mode &= ~S_ISUID;
if (ip->i_d.di_mode & S_IXGRP)
ip->i_d.di_mode &= ~S_ISGID;
if (!(mode & (FALLOC_FL_PUNCH_HOLE | FALLOC_FL_COLLAPSE_RANGE)))
ip->i_d.di_flags |= XFS_DIFLAG_PREALLOC;
xfs_trans_ichgtime(tp, ip, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (file->f_flags & O_DSYNC)
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp, 0);
if (error)
goto out_unlock;
if (new_size) {
struct iattr iattr;
iattr.ia_valid = ATTR_SIZE;
iattr.ia_size = new_size;
error = xfs_setattr_size(ip, &iattr);
}
out_unlock:
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
STATIC int
xfs_file_open(
struct inode *inode,
struct file *file)
{
if (!(file->f_flags & O_LARGEFILE) && i_size_read(inode) > MAX_NON_LFS)
return -EFBIG;
if (XFS_FORCED_SHUTDOWN(XFS_M(inode->i_sb)))
return -EIO;
return 0;
}
STATIC int
xfs_dir_open(
struct inode *inode,
struct file *file)
{
struct xfs_inode *ip = XFS_I(inode);
int mode;
int error;
error = xfs_file_open(inode, file);
if (error)
return error;
mode = xfs_ilock_data_map_shared(ip);
if (ip->i_d.di_nextents > 0)
xfs_dir3_data_readahead(ip, 0, -1);
xfs_iunlock(ip, mode);
return 0;
}
STATIC int
xfs_file_release(
struct inode *inode,
struct file *filp)
{
return xfs_release(XFS_I(inode));
}
STATIC int
xfs_file_readdir(
struct file *file,
struct dir_context *ctx)
{
struct inode *inode = file_inode(file);
xfs_inode_t *ip = XFS_I(inode);
int error;
size_t bufsize;
bufsize = (size_t)min_t(loff_t, 32768, ip->i_d.di_size);
error = xfs_readdir(ip, ctx, bufsize);
if (error)
return error;
return 0;
}
STATIC int
xfs_file_mmap(
struct file *filp,
struct vm_area_struct *vma)
{
vma->vm_ops = &xfs_file_vm_ops;
file_accessed(filp);
return 0;
}
STATIC int
xfs_vm_page_mkwrite(
struct vm_area_struct *vma,
struct vm_fault *vmf)
{
return block_page_mkwrite(vma, vmf, xfs_get_blocks);
}
STATIC bool
xfs_lookup_buffer_offset(
struct page *page,
loff_t *offset,
unsigned int type)
{
loff_t lastoff = page_offset(page);
bool found = false;
struct buffer_head *bh, *head;
bh = head = page_buffers(page);
do {
if (buffer_unwritten(bh) ||
buffer_uptodate(bh)) {
if (type == DATA_OFF)
found = true;
} else {
if (type == HOLE_OFF)
found = true;
}
if (found) {
*offset = lastoff;
break;
}
lastoff += bh->b_size;
} while ((bh = bh->b_this_page) != head);
return found;
}
STATIC bool
xfs_find_get_desired_pgoff(
struct inode *inode,
struct xfs_bmbt_irec *map,
unsigned int type,
loff_t *offset)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
struct pagevec pvec;
pgoff_t index;
pgoff_t end;
loff_t endoff;
loff_t startoff = *offset;
loff_t lastoff = startoff;
bool found = false;
pagevec_init(&pvec, 0);
index = startoff >> PAGE_CACHE_SHIFT;
endoff = XFS_FSB_TO_B(mp, map->br_startoff + map->br_blockcount);
end = endoff >> PAGE_CACHE_SHIFT;
do {
int want;
unsigned nr_pages;
unsigned int i;
want = min_t(pgoff_t, end - index, PAGEVEC_SIZE);
nr_pages = pagevec_lookup(&pvec, inode->i_mapping, index,
want);
if (nr_pages == 0) {
if (type == DATA_OFF)
break;
ASSERT(type == HOLE_OFF);
if (lastoff == startoff || lastoff < endoff) {
found = true;
*offset = lastoff;
}
break;
}
if (type == HOLE_OFF && lastoff == startoff &&
lastoff < page_offset(pvec.pages[0])) {
found = true;
break;
}
for (i = 0; i < nr_pages; i++) {
struct page *page = pvec.pages[i];
loff_t b_offset;
if (page->index > end) {
if (type == HOLE_OFF && lastoff < endoff) {
*offset = lastoff;
found = true;
}
goto out;
}
lock_page(page);
if (unlikely(page->mapping != inode->i_mapping)) {
unlock_page(page);
continue;
}
if (!page_has_buffers(page)) {
unlock_page(page);
continue;
}
found = xfs_lookup_buffer_offset(page, &b_offset, type);
if (found) {
*offset = max_t(loff_t, startoff, b_offset);
unlock_page(page);
goto out;
}
lastoff = page_offset(page) + PAGE_SIZE;
unlock_page(page);
}
if (nr_pages < want) {
if (type == HOLE_OFF) {
*offset = lastoff;
found = true;
}
break;
}
index = pvec.pages[i - 1]->index + 1;
pagevec_release(&pvec);
} while (index <= end);
out:
pagevec_release(&pvec);
return found;
}
STATIC loff_t
xfs_seek_data(
struct file *file,
loff_t start)
{
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
loff_t uninitialized_var(offset);
xfs_fsize_t isize;
xfs_fileoff_t fsbno;
xfs_filblks_t end;
uint lock;
int error;
lock = xfs_ilock_data_map_shared(ip);
isize = i_size_read(inode);
if (start >= isize) {
error = -ENXIO;
goto out_unlock;
}
fsbno = XFS_B_TO_FSBT(mp, start);
end = XFS_B_TO_FSB(mp, isize);
for (;;) {
struct xfs_bmbt_irec map[2];
int nmap = 2;
unsigned int i;
error = xfs_bmapi_read(ip, fsbno, end - fsbno, map, &nmap,
XFS_BMAPI_ENTIRE);
if (error)
goto out_unlock;
if (nmap == 0) {
error = -ENXIO;
goto out_unlock;
}
for (i = 0; i < nmap; i++) {
offset = max_t(loff_t, start,
XFS_FSB_TO_B(mp, map[i].br_startoff));
if (map[i].br_startblock == DELAYSTARTBLOCK ||
(map[i].br_state == XFS_EXT_NORM &&
!isnullstartblock(map[i].br_startblock)))
goto out;
if (map[i].br_state == XFS_EXT_UNWRITTEN) {
if (xfs_find_get_desired_pgoff(inode, &map[i],
DATA_OFF, &offset))
goto out;
}
}
if (nmap == 1) {
error = -ENXIO;
goto out_unlock;
}
ASSERT(i > 1);
fsbno = map[i - 1].br_startoff + map[i - 1].br_blockcount;
start = XFS_FSB_TO_B(mp, fsbno);
if (start >= isize) {
error = -ENXIO;
goto out_unlock;
}
}
out:
offset = vfs_setpos(file, offset, inode->i_sb->s_maxbytes);
out_unlock:
xfs_iunlock(ip, lock);
if (error)
return error;
return offset;
}
STATIC loff_t
xfs_seek_hole(
struct file *file,
loff_t start)
{
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
loff_t uninitialized_var(offset);
xfs_fsize_t isize;
xfs_fileoff_t fsbno;
xfs_filblks_t end;
uint lock;
int error;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
lock = xfs_ilock_data_map_shared(ip);
isize = i_size_read(inode);
if (start >= isize) {
error = -ENXIO;
goto out_unlock;
}
fsbno = XFS_B_TO_FSBT(mp, start);
end = XFS_B_TO_FSB(mp, isize);
for (;;) {
struct xfs_bmbt_irec map[2];
int nmap = 2;
unsigned int i;
error = xfs_bmapi_read(ip, fsbno, end - fsbno, map, &nmap,
XFS_BMAPI_ENTIRE);
if (error)
goto out_unlock;
if (nmap == 0) {
error = -ENXIO;
goto out_unlock;
}
for (i = 0; i < nmap; i++) {
offset = max_t(loff_t, start,
XFS_FSB_TO_B(mp, map[i].br_startoff));
if (map[i].br_startblock == HOLESTARTBLOCK)
goto out;
if (map[i].br_state == XFS_EXT_UNWRITTEN) {
if (xfs_find_get_desired_pgoff(inode, &map[i],
HOLE_OFF, &offset))
goto out;
}
}
if (nmap == 1) {
offset = isize;
break;
}
ASSERT(i > 1);
fsbno = map[i - 1].br_startoff + map[i - 1].br_blockcount;
start = XFS_FSB_TO_B(mp, fsbno);
if (start >= isize) {
offset = isize;
break;
}
}
out:
offset = min_t(loff_t, offset, isize);
offset = vfs_setpos(file, offset, inode->i_sb->s_maxbytes);
out_unlock:
xfs_iunlock(ip, lock);
if (error)
return error;
return offset;
}
STATIC loff_t
xfs_file_llseek(
struct file *file,
loff_t offset,
int origin)
{
switch (origin) {
case SEEK_END:
case SEEK_CUR:
case SEEK_SET:
return generic_file_llseek(file, offset, origin);
case SEEK_DATA:
return xfs_seek_data(file, offset);
case SEEK_HOLE:
return xfs_seek_hole(file, offset);
default:
return -EINVAL;
}
}
