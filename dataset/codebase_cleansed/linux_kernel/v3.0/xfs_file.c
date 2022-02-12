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
STATIC int
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
xfs_file_fsync(
struct file *file,
int datasync)
{
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error = 0;
int log_flushed = 0;
trace_xfs_file_fsync(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return -XFS_ERROR(EIO);
xfs_iflags_clear(ip, XFS_ITRUNCATED);
xfs_ioend_wait(ip);
if (mp->m_flags & XFS_MOUNT_BARRIER) {
if (XFS_IS_REALTIME_INODE(ip))
xfs_blkdev_issue_flush(mp->m_rtdev_targp);
else if (mp->m_logdev_targp != mp->m_ddev_targp)
xfs_blkdev_issue_flush(mp->m_ddev_targp);
}
xfs_ilock(ip, XFS_ILOCK_SHARED);
if (((inode->i_state & I_DIRTY_DATASYNC) ||
((inode->i_state & I_DIRTY_SYNC) && !datasync)) &&
ip->i_update_core) {
xfs_iunlock(ip, XFS_ILOCK_SHARED);
tp = xfs_trans_alloc(mp, XFS_TRANS_FSYNC_TS);
error = xfs_trans_reserve(tp, 0,
XFS_FSYNC_TS_LOG_RES(mp), 0, 0, 0);
if (error) {
xfs_trans_cancel(tp, 0);
return -error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
xfs_trans_set_sync(tp);
error = _xfs_trans_commit(tp, 0, &log_flushed);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
} else {
if (xfs_ipincount(ip)) {
error = _xfs_log_force_lsn(mp,
ip->i_itemp->ili_last_lsn,
XFS_LOG_SYNC, &log_flushed);
}
xfs_iunlock(ip, XFS_ILOCK_SHARED);
}
if ((mp->m_flags & XFS_MOUNT_BARRIER) &&
mp->m_logdev_targp == mp->m_ddev_targp &&
!XFS_IS_REALTIME_INODE(ip) &&
!log_flushed)
xfs_blkdev_issue_flush(mp->m_ddev_targp);
return -error;
}
STATIC ssize_t
xfs_file_aio_read(
struct kiocb *iocb,
const struct iovec *iovp,
unsigned long nr_segs,
loff_t pos)
{
struct file *file = iocb->ki_filp;
struct inode *inode = file->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
size_t size = 0;
ssize_t ret = 0;
int ioflags = 0;
xfs_fsize_t n;
unsigned long seg;
XFS_STATS_INC(xs_read_calls);
BUG_ON(iocb->ki_pos != pos);
if (unlikely(file->f_flags & O_DIRECT))
ioflags |= IO_ISDIRECT;
if (file->f_mode & FMODE_NOCMTIME)
ioflags |= IO_INVIS;
for (seg = 0; seg < nr_segs; seg++) {
const struct iovec *iv = &iovp[seg];
size += iv->iov_len;
if (unlikely((ssize_t)(size|iv->iov_len) < 0))
return XFS_ERROR(-EINVAL);
}
if (unlikely(ioflags & IO_ISDIRECT)) {
xfs_buftarg_t *target =
XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp;
if ((iocb->ki_pos & target->bt_smask) ||
(size & target->bt_smask)) {
if (iocb->ki_pos == ip->i_size)
return 0;
return -XFS_ERROR(EINVAL);
}
}
n = XFS_MAXIOFFSET(mp) - iocb->ki_pos;
if (n <= 0 || size == 0)
return 0;
if (n < size)
size = n;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
if (unlikely(ioflags & IO_ISDIRECT)) {
xfs_rw_ilock(ip, XFS_IOLOCK_EXCL);
if (inode->i_mapping->nrpages) {
ret = -xfs_flushinval_pages(ip,
(iocb->ki_pos & PAGE_CACHE_MASK),
-1, FI_REMAPF_LOCKED);
if (ret) {
xfs_rw_iunlock(ip, XFS_IOLOCK_EXCL);
return ret;
}
}
xfs_rw_ilock_demote(ip, XFS_IOLOCK_EXCL);
} else
xfs_rw_ilock(ip, XFS_IOLOCK_SHARED);
trace_xfs_file_read(ip, size, iocb->ki_pos, ioflags);
ret = generic_file_aio_read(iocb, iovp, nr_segs, iocb->ki_pos);
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
ioflags |= IO_INVIS;
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
STATIC void
xfs_aio_write_isize_update(
struct inode *inode,
loff_t *ppos,
ssize_t bytes_written)
{
struct xfs_inode *ip = XFS_I(inode);
xfs_fsize_t isize = i_size_read(inode);
if (bytes_written > 0)
XFS_STATS_ADD(xs_write_bytes, bytes_written);
if (unlikely(bytes_written < 0 && bytes_written != -EFAULT &&
*ppos > isize))
*ppos = isize;
if (*ppos > ip->i_size) {
xfs_rw_ilock(ip, XFS_ILOCK_EXCL);
if (*ppos > ip->i_size)
ip->i_size = *ppos;
xfs_rw_iunlock(ip, XFS_ILOCK_EXCL);
}
}
STATIC void
xfs_aio_write_newsize_update(
struct xfs_inode *ip)
{
if (ip->i_new_size) {
xfs_rw_ilock(ip, XFS_ILOCK_EXCL);
ip->i_new_size = 0;
if (ip->i_d.di_size > ip->i_size)
ip->i_d.di_size = ip->i_size;
xfs_rw_iunlock(ip, XFS_ILOCK_EXCL);
}
}
STATIC ssize_t
xfs_file_splice_write(
struct pipe_inode_info *pipe,
struct file *outfilp,
loff_t *ppos,
size_t count,
unsigned int flags)
{
struct inode *inode = outfilp->f_mapping->host;
struct xfs_inode *ip = XFS_I(inode);
xfs_fsize_t new_size;
int ioflags = 0;
ssize_t ret;
XFS_STATS_INC(xs_write_calls);
if (outfilp->f_mode & FMODE_NOCMTIME)
ioflags |= IO_INVIS;
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return -EIO;
xfs_ilock(ip, XFS_IOLOCK_EXCL);
new_size = *ppos + count;
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (new_size > ip->i_size)
ip->i_new_size = new_size;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
trace_xfs_file_splice_write(ip, count, *ppos, ioflags);
ret = generic_file_splice_write(pipe, outfilp, ppos, count, flags);
xfs_aio_write_isize_update(inode, ppos, ret);
xfs_aio_write_newsize_update(ip);
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return ret;
}
STATIC int
xfs_zero_last_block(
xfs_inode_t *ip,
xfs_fsize_t offset,
xfs_fsize_t isize)
{
xfs_fileoff_t last_fsb;
xfs_mount_t *mp = ip->i_mount;
int nimaps;
int zero_offset;
int zero_len;
int error = 0;
xfs_bmbt_irec_t imap;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
zero_offset = XFS_B_FSB_OFFSET(mp, isize);
if (zero_offset == 0) {
return 0;
}
last_fsb = XFS_B_TO_FSBT(mp, isize);
nimaps = 1;
error = xfs_bmapi(NULL, ip, last_fsb, 1, 0, NULL, 0, &imap,
&nimaps, NULL);
if (error) {
return error;
}
ASSERT(nimaps > 0);
if (imap.br_startblock == HOLESTARTBLOCK) {
return 0;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
zero_len = mp->m_sb.sb_blocksize - zero_offset;
if (isize + zero_len > offset)
zero_len = offset - isize;
error = xfs_iozero(ip, isize, zero_len);
xfs_ilock(ip, XFS_ILOCK_EXCL);
ASSERT(error >= 0);
return error;
}
int
xfs_zero_eof(
xfs_inode_t *ip,
xfs_off_t offset,
xfs_fsize_t isize)
{
xfs_mount_t *mp = ip->i_mount;
xfs_fileoff_t start_zero_fsb;
xfs_fileoff_t end_zero_fsb;
xfs_fileoff_t zero_count_fsb;
xfs_fileoff_t last_fsb;
xfs_fileoff_t zero_off;
xfs_fsize_t zero_len;
int nimaps;
int error = 0;
xfs_bmbt_irec_t imap;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_IOLOCK_EXCL));
ASSERT(offset > isize);
error = xfs_zero_last_block(ip, offset, isize);
if (error) {
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_IOLOCK_EXCL));
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
error = xfs_bmapi(NULL, ip, start_zero_fsb, zero_count_fsb,
0, NULL, 0, &imap, &nimaps, NULL);
if (error) {
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_IOLOCK_EXCL));
return error;
}
ASSERT(nimaps > 0);
if (imap.br_state == XFS_EXT_UNWRITTEN ||
imap.br_startblock == HOLESTARTBLOCK) {
start_zero_fsb = imap.br_startoff + imap.br_blockcount;
ASSERT(start_zero_fsb <= (end_zero_fsb + 1));
continue;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
zero_off = XFS_FSB_TO_B(mp, start_zero_fsb);
zero_len = XFS_FSB_TO_B(mp, imap.br_blockcount);
if ((zero_off + zero_len) > offset)
zero_len = offset - zero_off;
error = xfs_iozero(ip, zero_off, zero_len);
if (error) {
goto out_lock;
}
start_zero_fsb = imap.br_startoff + imap.br_blockcount;
ASSERT(start_zero_fsb <= (end_zero_fsb + 1));
xfs_ilock(ip, XFS_ILOCK_EXCL);
}
return 0;
out_lock:
xfs_ilock(ip, XFS_ILOCK_EXCL);
ASSERT(error >= 0);
return error;
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
xfs_fsize_t new_size;
int error = 0;
error = generic_write_checks(file, pos, count, S_ISBLK(inode->i_mode));
if (error) {
xfs_rw_iunlock(ip, XFS_ILOCK_EXCL | *iolock);
*iolock = 0;
return error;
}
new_size = *pos + *count;
if (new_size > ip->i_size)
ip->i_new_size = new_size;
if (likely(!(file->f_mode & FMODE_NOCMTIME)))
file_update_time(file);
if (*pos > ip->i_size)
error = -xfs_zero_eof(ip, *pos, ip->i_size);
xfs_rw_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
return error;
return file_remove_suid(file);
}
STATIC ssize_t
xfs_file_dio_aio_write(
struct kiocb *iocb,
const struct iovec *iovp,
unsigned long nr_segs,
loff_t pos,
size_t ocount,
int *iolock)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
ssize_t ret = 0;
size_t count = ocount;
int unaligned_io = 0;
struct xfs_buftarg *target = XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp;
*iolock = 0;
if ((pos & target->bt_smask) || (count & target->bt_smask))
return -XFS_ERROR(EINVAL);
if ((pos & mp->m_blockmask) || ((pos + count) & mp->m_blockmask))
unaligned_io = 1;
if (unaligned_io || mapping->nrpages || pos > ip->i_size)
*iolock = XFS_IOLOCK_EXCL;
else
*iolock = XFS_IOLOCK_SHARED;
xfs_rw_ilock(ip, XFS_ILOCK_EXCL | *iolock);
ret = xfs_file_aio_write_checks(file, &pos, &count, iolock);
if (ret)
return ret;
if (mapping->nrpages) {
WARN_ON(*iolock != XFS_IOLOCK_EXCL);
ret = -xfs_flushinval_pages(ip, (pos & PAGE_CACHE_MASK), -1,
FI_REMAPF_LOCKED);
if (ret)
return ret;
}
if (unaligned_io)
xfs_ioend_wait(ip);
else if (*iolock == XFS_IOLOCK_EXCL) {
xfs_rw_ilock_demote(ip, XFS_IOLOCK_EXCL);
*iolock = XFS_IOLOCK_SHARED;
}
trace_xfs_file_direct_write(ip, count, iocb->ki_pos, 0);
ret = generic_file_direct_write(iocb, iovp,
&nr_segs, pos, &iocb->ki_pos, count, ocount);
ASSERT(ret < 0 || ret == count);
return ret;
}
STATIC ssize_t
xfs_file_buffered_aio_write(
struct kiocb *iocb,
const struct iovec *iovp,
unsigned long nr_segs,
loff_t pos,
size_t ocount,
int *iolock)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct xfs_inode *ip = XFS_I(inode);
ssize_t ret;
int enospc = 0;
size_t count = ocount;
*iolock = XFS_IOLOCK_EXCL;
xfs_rw_ilock(ip, XFS_ILOCK_EXCL | *iolock);
ret = xfs_file_aio_write_checks(file, &pos, &count, iolock);
if (ret)
return ret;
current->backing_dev_info = mapping->backing_dev_info;
write_retry:
trace_xfs_file_buffered_write(ip, count, iocb->ki_pos, 0);
ret = generic_file_buffered_write(iocb, iovp, nr_segs,
pos, &iocb->ki_pos, count, ret);
if (ret == -ENOSPC && !enospc) {
ret = -xfs_flush_pages(ip, 0, -1, 0, FI_NONE);
if (ret)
return ret;
enospc = 1;
goto write_retry;
}
current->backing_dev_info = NULL;
return ret;
}
STATIC ssize_t
xfs_file_aio_write(
struct kiocb *iocb,
const struct iovec *iovp,
unsigned long nr_segs,
loff_t pos)
{
struct file *file = iocb->ki_filp;
struct address_space *mapping = file->f_mapping;
struct inode *inode = mapping->host;
struct xfs_inode *ip = XFS_I(inode);
ssize_t ret;
int iolock;
size_t ocount = 0;
XFS_STATS_INC(xs_write_calls);
BUG_ON(iocb->ki_pos != pos);
ret = generic_segment_checks(iovp, &nr_segs, &ocount, VERIFY_READ);
if (ret)
return ret;
if (ocount == 0)
return 0;
xfs_wait_for_freeze(ip->i_mount, SB_FREEZE_WRITE);
if (XFS_FORCED_SHUTDOWN(ip->i_mount))
return -EIO;
if (unlikely(file->f_flags & O_DIRECT))
ret = xfs_file_dio_aio_write(iocb, iovp, nr_segs, pos,
ocount, &iolock);
else
ret = xfs_file_buffered_aio_write(iocb, iovp, nr_segs, pos,
ocount, &iolock);
xfs_aio_write_isize_update(inode, &iocb->ki_pos, ret);
if (ret <= 0)
goto out_unlock;
if ((file->f_flags & O_DSYNC) || IS_SYNC(inode)) {
loff_t end = pos + ret - 1;
int error, error2;
xfs_rw_iunlock(ip, iolock);
error = filemap_write_and_wait_range(mapping, pos, end);
xfs_rw_ilock(ip, iolock);
error2 = -xfs_file_fsync(file,
(file->f_flags & __O_SYNC) ? 0 : 1);
if (error)
ret = error;
else if (error2)
ret = error2;
}
out_unlock:
xfs_aio_write_newsize_update(ip);
xfs_rw_iunlock(ip, iolock);
return ret;
}
STATIC long
xfs_file_fallocate(
struct file *file,
int mode,
loff_t offset,
loff_t len)
{
struct inode *inode = file->f_path.dentry->d_inode;
long error;
loff_t new_size = 0;
xfs_flock64_t bf;
xfs_inode_t *ip = XFS_I(inode);
int cmd = XFS_IOC_RESVSP;
int attr_flags = XFS_ATTR_NOLOCK;
if (mode & ~(FALLOC_FL_KEEP_SIZE | FALLOC_FL_PUNCH_HOLE))
return -EOPNOTSUPP;
bf.l_whence = 0;
bf.l_start = offset;
bf.l_len = len;
xfs_ilock(ip, XFS_IOLOCK_EXCL);
if (mode & FALLOC_FL_PUNCH_HOLE)
cmd = XFS_IOC_UNRESVSP;
if (!(mode & FALLOC_FL_KEEP_SIZE) &&
offset + len > i_size_read(inode)) {
new_size = offset + len;
error = inode_newsize_ok(inode, new_size);
if (error)
goto out_unlock;
}
if (file->f_flags & O_DSYNC)
attr_flags |= XFS_ATTR_SYNC;
error = -xfs_change_file_space(ip, cmd, &bf, 0, attr_flags);
if (error)
goto out_unlock;
if (new_size) {
struct iattr iattr;
iattr.ia_valid = ATTR_SIZE;
iattr.ia_size = new_size;
error = -xfs_setattr(ip, &iattr, XFS_ATTR_NOLOCK);
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
mode = xfs_ilock_map_shared(ip);
if (ip->i_d.di_nextents > 0)
xfs_da_reada_buf(NULL, ip, 0, XFS_DATA_FORK);
xfs_iunlock(ip, mode);
return 0;
}
STATIC int
xfs_file_release(
struct inode *inode,
struct file *filp)
{
return -xfs_release(XFS_I(inode));
}
STATIC int
xfs_file_readdir(
struct file *filp,
void *dirent,
filldir_t filldir)
{
struct inode *inode = filp->f_path.dentry->d_inode;
xfs_inode_t *ip = XFS_I(inode);
int error;
size_t bufsize;
bufsize = (size_t)min_t(loff_t, 32768, ip->i_d.di_size);
error = xfs_readdir(ip, dirent, bufsize,
(xfs_off_t *)&filp->f_pos, filldir);
if (error)
return -error;
return 0;
}
STATIC int
xfs_file_mmap(
struct file *filp,
struct vm_area_struct *vma)
{
vma->vm_ops = &xfs_file_vm_ops;
vma->vm_flags |= VM_CAN_NONLINEAR;
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
