int
xfs_zero_range(
struct xfs_inode *ip,
xfs_off_t pos,
xfs_off_t count,
bool *did_zero)
{
return iomap_zero_range(VFS_I(ip), pos, count, did_zero, &xfs_iomap_ops);
}
int
xfs_update_prealloc_flags(
struct xfs_inode *ip,
enum xfs_prealloc_flags flags)
{
struct xfs_trans *tp;
int error;
error = xfs_trans_alloc(ip->i_mount, &M_RES(ip->i_mount)->tr_writeid,
0, 0, 0, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
if (!(flags & XFS_PREALLOC_INVISIBLE)) {
VFS_I(ip)->i_mode &= ~S_ISUID;
if (VFS_I(ip)->i_mode & S_IXGRP)
VFS_I(ip)->i_mode &= ~S_ISGID;
xfs_trans_ichgtime(tp, ip, XFS_ICHGTIME_MOD | XFS_ICHGTIME_CHG);
}
if (flags & XFS_PREALLOC_SET)
ip->i_d.di_flags |= XFS_DIFLAG_PREALLOC;
if (flags & XFS_PREALLOC_CLEAR)
ip->i_d.di_flags &= ~XFS_DIFLAG_PREALLOC;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
if (flags & XFS_PREALLOC_SYNC)
xfs_trans_set_sync(tp);
return xfs_trans_commit(tp);
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
error = file_write_and_wait_range(file, start, end);
if (error)
return error;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
xfs_iflags_clear(ip, XFS_ITRUNCATED);
if (XFS_IS_REALTIME_INODE(ip))
xfs_blkdev_issue_flush(mp->m_rtdev_targp);
else if (mp->m_logdev_targp != mp->m_ddev_targp)
xfs_blkdev_issue_flush(mp->m_ddev_targp);
xfs_ilock(ip, XFS_ILOCK_SHARED);
if (xfs_ipincount(ip)) {
if (!datasync ||
(ip->i_itemp->ili_fsync_fields & ~XFS_ILOG_TIMESTAMP))
lsn = ip->i_itemp->ili_last_lsn;
}
if (lsn) {
error = _xfs_log_force_lsn(mp, lsn, XFS_LOG_SYNC, &log_flushed);
ip->i_itemp->ili_fsync_fields = 0;
}
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (!log_flushed && !XFS_IS_REALTIME_INODE(ip) &&
mp->m_logdev_targp == mp->m_ddev_targp)
xfs_blkdev_issue_flush(mp->m_ddev_targp);
return error;
}
STATIC ssize_t
xfs_file_dio_aio_read(
struct kiocb *iocb,
struct iov_iter *to)
{
struct xfs_inode *ip = XFS_I(file_inode(iocb->ki_filp));
size_t count = iov_iter_count(to);
ssize_t ret;
trace_xfs_file_direct_read(ip, count, iocb->ki_pos);
if (!count)
return 0;
file_accessed(iocb->ki_filp);
xfs_ilock(ip, XFS_IOLOCK_SHARED);
ret = iomap_dio_rw(iocb, to, &xfs_iomap_ops, NULL);
xfs_iunlock(ip, XFS_IOLOCK_SHARED);
return ret;
}
static noinline ssize_t
xfs_file_dax_read(
struct kiocb *iocb,
struct iov_iter *to)
{
struct xfs_inode *ip = XFS_I(iocb->ki_filp->f_mapping->host);
size_t count = iov_iter_count(to);
ssize_t ret = 0;
trace_xfs_file_dax_read(ip, count, iocb->ki_pos);
if (!count)
return 0;
if (iocb->ki_flags & IOCB_NOWAIT) {
if (!xfs_ilock_nowait(ip, XFS_IOLOCK_SHARED))
return -EAGAIN;
} else {
xfs_ilock(ip, XFS_IOLOCK_SHARED);
}
ret = dax_iomap_rw(iocb, to, &xfs_iomap_ops);
xfs_iunlock(ip, XFS_IOLOCK_SHARED);
file_accessed(iocb->ki_filp);
return ret;
}
STATIC ssize_t
xfs_file_buffered_aio_read(
struct kiocb *iocb,
struct iov_iter *to)
{
struct xfs_inode *ip = XFS_I(file_inode(iocb->ki_filp));
ssize_t ret;
trace_xfs_file_buffered_read(ip, iov_iter_count(to), iocb->ki_pos);
if (iocb->ki_flags & IOCB_NOWAIT) {
if (!xfs_ilock_nowait(ip, XFS_IOLOCK_SHARED))
return -EAGAIN;
} else {
xfs_ilock(ip, XFS_IOLOCK_SHARED);
}
ret = generic_file_read_iter(iocb, to);
xfs_iunlock(ip, XFS_IOLOCK_SHARED);
return ret;
}
STATIC ssize_t
xfs_file_read_iter(
struct kiocb *iocb,
struct iov_iter *to)
{
struct inode *inode = file_inode(iocb->ki_filp);
struct xfs_mount *mp = XFS_I(inode)->i_mount;
ssize_t ret = 0;
XFS_STATS_INC(mp, xs_read_calls);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
if (IS_DAX(inode))
ret = xfs_file_dax_read(iocb, to);
else if (iocb->ki_flags & IOCB_DIRECT)
ret = xfs_file_dio_aio_read(iocb, to);
else
ret = xfs_file_buffered_aio_read(iocb, to);
if (ret > 0)
XFS_STATS_ADD(mp, xs_read_bytes, ret);
return ret;
}
int
xfs_zero_eof(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_fsize_t isize,
bool *did_zeroing)
{
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
ASSERT(offset > isize);
trace_xfs_zero_eof(ip, isize, offset - isize);
return xfs_zero_range(ip, isize, offset - isize, did_zeroing);
}
STATIC ssize_t
xfs_file_aio_write_checks(
struct kiocb *iocb,
struct iov_iter *from,
int *iolock)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
ssize_t error = 0;
size_t count = iov_iter_count(from);
bool drained_dio = false;
restart:
error = generic_write_checks(iocb, from);
if (error <= 0)
return error;
error = xfs_break_layouts(inode, iolock);
if (error)
return error;
if (*iolock == XFS_IOLOCK_SHARED && !IS_NOSEC(inode)) {
xfs_iunlock(ip, *iolock);
*iolock = XFS_IOLOCK_EXCL;
xfs_ilock(ip, *iolock);
goto restart;
}
spin_lock(&ip->i_flags_lock);
if (iocb->ki_pos > i_size_read(inode)) {
spin_unlock(&ip->i_flags_lock);
if (!drained_dio) {
if (*iolock == XFS_IOLOCK_SHARED) {
xfs_iunlock(ip, *iolock);
*iolock = XFS_IOLOCK_EXCL;
xfs_ilock(ip, *iolock);
iov_iter_reexpand(from, count);
}
inode_dio_wait(inode);
drained_dio = true;
goto restart;
}
error = xfs_zero_eof(ip, iocb->ki_pos, i_size_read(inode), NULL);
if (error)
return error;
} else
spin_unlock(&ip->i_flags_lock);
if (likely(!(file->f_mode & FMODE_NOCMTIME))) {
error = file_update_time(file);
if (error)
return error;
}
if (!IS_NOSEC(inode))
return file_remove_privs(file);
return 0;
}
static int
xfs_dio_write_end_io(
struct kiocb *iocb,
ssize_t size,
unsigned flags)
{
struct inode *inode = file_inode(iocb->ki_filp);
struct xfs_inode *ip = XFS_I(inode);
loff_t offset = iocb->ki_pos;
int error = 0;
trace_xfs_end_io_direct_write(ip, offset, size);
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return -EIO;
if (size <= 0)
return size;
if (flags & IOMAP_DIO_COW) {
error = xfs_reflink_end_cow(ip, offset, size);
if (error)
return error;
}
if (flags & IOMAP_DIO_UNWRITTEN)
return xfs_iomap_write_unwritten(ip, offset, size, true);
spin_lock(&ip->i_flags_lock);
if (offset + size > i_size_read(inode)) {
i_size_write(inode, offset + size);
spin_unlock(&ip->i_flags_lock);
error = xfs_setfilesize(ip, offset, size);
} else {
spin_unlock(&ip->i_flags_lock);
}
return error;
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
struct xfs_buftarg *target = XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp;
if ((iocb->ki_pos | count) & target->bt_logical_sectormask)
return -EINVAL;
if ((iocb->ki_pos & mp->m_blockmask) ||
((iocb->ki_pos + count) & mp->m_blockmask)) {
unaligned_io = 1;
if (xfs_is_reflink_inode(ip)) {
trace_xfs_reflink_bounce_dio_write(ip, iocb->ki_pos, count);
return -EREMCHG;
}
iolock = XFS_IOLOCK_EXCL;
} else {
iolock = XFS_IOLOCK_SHARED;
}
if (iocb->ki_flags & IOCB_NOWAIT) {
if (!xfs_ilock_nowait(ip, iolock))
return -EAGAIN;
} else {
xfs_ilock(ip, iolock);
}
ret = xfs_file_aio_write_checks(iocb, from, &iolock);
if (ret)
goto out;
count = iov_iter_count(from);
if (unaligned_io) {
if (iocb->ki_flags & IOCB_NOWAIT) {
if (atomic_read(&inode->i_dio_count))
return -EAGAIN;
} else {
inode_dio_wait(inode);
}
} else if (iolock == XFS_IOLOCK_EXCL) {
xfs_ilock_demote(ip, XFS_IOLOCK_EXCL);
iolock = XFS_IOLOCK_SHARED;
}
trace_xfs_file_direct_write(ip, count, iocb->ki_pos);
ret = iomap_dio_rw(iocb, from, &xfs_iomap_ops, xfs_dio_write_end_io);
out:
xfs_iunlock(ip, iolock);
ASSERT(ret < 0 || ret == count);
return ret;
}
static noinline ssize_t
xfs_file_dax_write(
struct kiocb *iocb,
struct iov_iter *from)
{
struct inode *inode = iocb->ki_filp->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
int iolock = XFS_IOLOCK_EXCL;
ssize_t ret, error = 0;
size_t count;
loff_t pos;
if (iocb->ki_flags & IOCB_NOWAIT) {
if (!xfs_ilock_nowait(ip, iolock))
return -EAGAIN;
} else {
xfs_ilock(ip, iolock);
}
ret = xfs_file_aio_write_checks(iocb, from, &iolock);
if (ret)
goto out;
pos = iocb->ki_pos;
count = iov_iter_count(from);
trace_xfs_file_dax_write(ip, count, pos);
ret = dax_iomap_rw(iocb, from, &xfs_iomap_ops);
if (ret > 0 && iocb->ki_pos > i_size_read(inode)) {
i_size_write(inode, iocb->ki_pos);
error = xfs_setfilesize(ip, pos, ret);
}
out:
xfs_iunlock(ip, iolock);
return error ? error : ret;
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
int iolock;
if (iocb->ki_flags & IOCB_NOWAIT)
return -EOPNOTSUPP;
write_retry:
iolock = XFS_IOLOCK_EXCL;
xfs_ilock(ip, iolock);
ret = xfs_file_aio_write_checks(iocb, from, &iolock);
if (ret)
goto out;
current->backing_dev_info = inode_to_bdi(inode);
trace_xfs_file_buffered_write(ip, iov_iter_count(from), iocb->ki_pos);
ret = iomap_file_buffered_write(iocb, from, &xfs_iomap_ops);
if (likely(ret >= 0))
iocb->ki_pos += ret;
if (ret == -EDQUOT && !enospc) {
xfs_iunlock(ip, iolock);
enospc = xfs_inode_free_quota_eofblocks(ip);
if (enospc)
goto write_retry;
enospc = xfs_inode_free_quota_cowblocks(ip);
if (enospc)
goto write_retry;
iolock = 0;
} else if (ret == -ENOSPC && !enospc) {
struct xfs_eofblocks eofb = {0};
enospc = 1;
xfs_flush_inodes(ip->i_mount);
xfs_iunlock(ip, iolock);
eofb.eof_flags = XFS_EOF_FLAGS_SYNC;
xfs_icache_free_eofblocks(ip->i_mount, &eofb);
xfs_icache_free_cowblocks(ip->i_mount, &eofb);
goto write_retry;
}
current->backing_dev_info = NULL;
out:
if (iolock)
xfs_iunlock(ip, iolock);
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
XFS_STATS_INC(ip->i_mount, xs_write_calls);
if (ocount == 0)
return 0;
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return -EIO;
if (IS_DAX(inode))
ret = xfs_file_dax_write(iocb, from);
else if (iocb->ki_flags & IOCB_DIRECT) {
ret = xfs_file_dio_aio_write(iocb, from);
if (ret == -EREMCHG)
goto buffered;
} else {
buffered:
ret = xfs_file_buffered_aio_write(iocb, from);
}
if (ret > 0) {
XFS_STATS_ADD(ip->i_mount, xs_write_bytes, ret);
ret = generic_write_sync(iocb, ret);
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
long error;
enum xfs_prealloc_flags flags = 0;
uint iolock = XFS_IOLOCK_EXCL;
loff_t new_size = 0;
bool do_file_insert = false;
if (!S_ISREG(inode->i_mode))
return -EINVAL;
if (mode & ~XFS_FALLOC_FL_SUPPORTED)
return -EOPNOTSUPP;
xfs_ilock(ip, iolock);
error = xfs_break_layouts(inode, &iolock);
if (error)
goto out_unlock;
xfs_ilock(ip, XFS_MMAPLOCK_EXCL);
iolock |= XFS_MMAPLOCK_EXCL;
if (mode & FALLOC_FL_PUNCH_HOLE) {
error = xfs_free_file_space(ip, offset, len);
if (error)
goto out_unlock;
} else if (mode & FALLOC_FL_COLLAPSE_RANGE) {
unsigned int blksize_mask = i_blocksize(inode) - 1;
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
} else if (mode & FALLOC_FL_INSERT_RANGE) {
unsigned int blksize_mask = i_blocksize(inode) - 1;
new_size = i_size_read(inode) + len;
if (offset & blksize_mask || len & blksize_mask) {
error = -EINVAL;
goto out_unlock;
}
if (new_size > inode->i_sb->s_maxbytes) {
error = -EFBIG;
goto out_unlock;
}
if (offset >= i_size_read(inode)) {
error = -EINVAL;
goto out_unlock;
}
do_file_insert = true;
} else {
flags |= XFS_PREALLOC_SET;
if (!(mode & FALLOC_FL_KEEP_SIZE) &&
offset + len > i_size_read(inode)) {
new_size = offset + len;
error = inode_newsize_ok(inode, new_size);
if (error)
goto out_unlock;
}
if (mode & FALLOC_FL_ZERO_RANGE)
error = xfs_zero_file_space(ip, offset, len);
else {
if (mode & FALLOC_FL_UNSHARE_RANGE) {
error = xfs_reflink_unshare(ip, offset, len);
if (error)
goto out_unlock;
}
error = xfs_alloc_file_space(ip, offset, len,
XFS_BMAPI_PREALLOC);
}
if (error)
goto out_unlock;
}
if (file->f_flags & O_DSYNC)
flags |= XFS_PREALLOC_SYNC;
error = xfs_update_prealloc_flags(ip, flags);
if (error)
goto out_unlock;
if (new_size) {
struct iattr iattr;
iattr.ia_valid = ATTR_SIZE;
iattr.ia_size = new_size;
error = xfs_vn_setattr_size(file_dentry(file), &iattr);
if (error)
goto out_unlock;
}
if (do_file_insert)
error = xfs_insert_file_space(ip, offset, len);
out_unlock:
xfs_iunlock(ip, iolock);
return error;
}
STATIC int
xfs_file_clone_range(
struct file *file_in,
loff_t pos_in,
struct file *file_out,
loff_t pos_out,
u64 len)
{
return xfs_reflink_remap_range(file_in, pos_in, file_out, pos_out,
len, false);
}
STATIC ssize_t
xfs_file_dedupe_range(
struct file *src_file,
u64 loff,
u64 len,
struct file *dst_file,
u64 dst_loff)
{
int error;
error = xfs_reflink_remap_range(src_file, loff, dst_file, dst_loff,
len, true);
if (error)
return error;
return len;
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
file->f_mode |= FMODE_NOWAIT;
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
error = xfs_dir3_data_readahead(ip, 0, -1);
xfs_iunlock(ip, mode);
return error;
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
size_t bufsize;
bufsize = (size_t)min_t(loff_t, 32768, ip->i_d.di_size);
return xfs_readdir(NULL, ip, ctx, bufsize);
}
STATIC loff_t
xfs_file_llseek(
struct file *file,
loff_t offset,
int whence)
{
struct inode *inode = file->f_mapping->host;
if (XFS_FORCED_SHUTDOWN(XFS_I(inode)->i_mount))
return -EIO;
switch (whence) {
default:
return generic_file_llseek(file, offset, whence);
case SEEK_HOLE:
offset = iomap_seek_hole(inode, offset, &xfs_iomap_ops);
break;
case SEEK_DATA:
offset = iomap_seek_data(inode, offset, &xfs_iomap_ops);
break;
}
if (offset < 0)
return offset;
return vfs_setpos(file, offset, inode->i_sb->s_maxbytes);
}
static int
__xfs_filemap_fault(
struct vm_fault *vmf,
enum page_entry_size pe_size,
bool write_fault)
{
struct inode *inode = file_inode(vmf->vma->vm_file);
struct xfs_inode *ip = XFS_I(inode);
int ret;
trace_xfs_filemap_fault(ip, pe_size, write_fault);
if (write_fault) {
sb_start_pagefault(inode->i_sb);
file_update_time(vmf->vma->vm_file);
}
xfs_ilock(XFS_I(inode), XFS_MMAPLOCK_SHARED);
if (IS_DAX(inode)) {
ret = dax_iomap_fault(vmf, pe_size, &xfs_iomap_ops);
} else {
if (write_fault)
ret = iomap_page_mkwrite(vmf, &xfs_iomap_ops);
else
ret = filemap_fault(vmf);
}
xfs_iunlock(XFS_I(inode), XFS_MMAPLOCK_SHARED);
if (write_fault)
sb_end_pagefault(inode->i_sb);
return ret;
}
static int
xfs_filemap_fault(
struct vm_fault *vmf)
{
return __xfs_filemap_fault(vmf, PE_SIZE_PTE,
IS_DAX(file_inode(vmf->vma->vm_file)) &&
(vmf->flags & FAULT_FLAG_WRITE));
}
static int
xfs_filemap_huge_fault(
struct vm_fault *vmf,
enum page_entry_size pe_size)
{
if (!IS_DAX(file_inode(vmf->vma->vm_file)))
return VM_FAULT_FALLBACK;
return __xfs_filemap_fault(vmf, pe_size,
(vmf->flags & FAULT_FLAG_WRITE));
}
static int
xfs_filemap_page_mkwrite(
struct vm_fault *vmf)
{
return __xfs_filemap_fault(vmf, PE_SIZE_PTE, true);
}
static int
xfs_filemap_pfn_mkwrite(
struct vm_fault *vmf)
{
struct inode *inode = file_inode(vmf->vma->vm_file);
struct xfs_inode *ip = XFS_I(inode);
int ret = VM_FAULT_NOPAGE;
loff_t size;
trace_xfs_filemap_pfn_mkwrite(ip);
sb_start_pagefault(inode->i_sb);
file_update_time(vmf->vma->vm_file);
xfs_ilock(ip, XFS_MMAPLOCK_SHARED);
size = (i_size_read(inode) + PAGE_SIZE - 1) >> PAGE_SHIFT;
if (vmf->pgoff >= size)
ret = VM_FAULT_SIGBUS;
else if (IS_DAX(inode))
ret = dax_iomap_fault(vmf, PE_SIZE_PTE, &xfs_iomap_ops);
xfs_iunlock(ip, XFS_MMAPLOCK_SHARED);
sb_end_pagefault(inode->i_sb);
return ret;
}
STATIC int
xfs_file_mmap(
struct file *filp,
struct vm_area_struct *vma)
{
file_accessed(filp);
vma->vm_ops = &xfs_file_vm_ops;
if (IS_DAX(file_inode(filp)))
vma->vm_flags |= VM_MIXEDMAP | VM_HUGEPAGE;
return 0;
}
