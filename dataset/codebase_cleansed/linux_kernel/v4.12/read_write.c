static inline int unsigned_offsets(struct file *file)
{
return file->f_mode & FMODE_UNSIGNED_OFFSET;
}
loff_t vfs_setpos(struct file *file, loff_t offset, loff_t maxsize)
{
if (offset < 0 && !unsigned_offsets(file))
return -EINVAL;
if (offset > maxsize)
return -EINVAL;
if (offset != file->f_pos) {
file->f_pos = offset;
file->f_version = 0;
}
return offset;
}
loff_t
generic_file_llseek_size(struct file *file, loff_t offset, int whence,
loff_t maxsize, loff_t eof)
{
switch (whence) {
case SEEK_END:
offset += eof;
break;
case SEEK_CUR:
if (offset == 0)
return file->f_pos;
spin_lock(&file->f_lock);
offset = vfs_setpos(file, file->f_pos + offset, maxsize);
spin_unlock(&file->f_lock);
return offset;
case SEEK_DATA:
if (offset >= eof)
return -ENXIO;
break;
case SEEK_HOLE:
if (offset >= eof)
return -ENXIO;
offset = eof;
break;
}
return vfs_setpos(file, offset, maxsize);
}
loff_t generic_file_llseek(struct file *file, loff_t offset, int whence)
{
struct inode *inode = file->f_mapping->host;
return generic_file_llseek_size(file, offset, whence,
inode->i_sb->s_maxbytes,
i_size_read(inode));
}
loff_t fixed_size_llseek(struct file *file, loff_t offset, int whence, loff_t size)
{
switch (whence) {
case SEEK_SET: case SEEK_CUR: case SEEK_END:
return generic_file_llseek_size(file, offset, whence,
size, size);
default:
return -EINVAL;
}
}
loff_t no_seek_end_llseek(struct file *file, loff_t offset, int whence)
{
switch (whence) {
case SEEK_SET: case SEEK_CUR:
return generic_file_llseek_size(file, offset, whence,
OFFSET_MAX, 0);
default:
return -EINVAL;
}
}
loff_t no_seek_end_llseek_size(struct file *file, loff_t offset, int whence, loff_t size)
{
switch (whence) {
case SEEK_SET: case SEEK_CUR:
return generic_file_llseek_size(file, offset, whence,
size, 0);
default:
return -EINVAL;
}
}
loff_t noop_llseek(struct file *file, loff_t offset, int whence)
{
return file->f_pos;
}
loff_t no_llseek(struct file *file, loff_t offset, int whence)
{
return -ESPIPE;
}
loff_t default_llseek(struct file *file, loff_t offset, int whence)
{
struct inode *inode = file_inode(file);
loff_t retval;
inode_lock(inode);
switch (whence) {
case SEEK_END:
offset += i_size_read(inode);
break;
case SEEK_CUR:
if (offset == 0) {
retval = file->f_pos;
goto out;
}
offset += file->f_pos;
break;
case SEEK_DATA:
if (offset >= inode->i_size) {
retval = -ENXIO;
goto out;
}
break;
case SEEK_HOLE:
if (offset >= inode->i_size) {
retval = -ENXIO;
goto out;
}
offset = inode->i_size;
break;
}
retval = -EINVAL;
if (offset >= 0 || unsigned_offsets(file)) {
if (offset != file->f_pos) {
file->f_pos = offset;
file->f_version = 0;
}
retval = offset;
}
out:
inode_unlock(inode);
return retval;
}
loff_t vfs_llseek(struct file *file, loff_t offset, int whence)
{
loff_t (*fn)(struct file *, loff_t, int);
fn = no_llseek;
if (file->f_mode & FMODE_LSEEK) {
if (file->f_op->llseek)
fn = file->f_op->llseek;
}
return fn(file, offset, whence);
}
ssize_t vfs_iter_read(struct file *file, struct iov_iter *iter, loff_t *ppos)
{
struct kiocb kiocb;
ssize_t ret;
if (!file->f_op->read_iter)
return -EINVAL;
init_sync_kiocb(&kiocb, file);
kiocb.ki_pos = *ppos;
iter->type |= READ;
ret = call_read_iter(file, &kiocb, iter);
BUG_ON(ret == -EIOCBQUEUED);
if (ret > 0)
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t vfs_iter_write(struct file *file, struct iov_iter *iter, loff_t *ppos)
{
struct kiocb kiocb;
ssize_t ret;
if (!file->f_op->write_iter)
return -EINVAL;
init_sync_kiocb(&kiocb, file);
kiocb.ki_pos = *ppos;
iter->type |= WRITE;
ret = call_write_iter(file, &kiocb, iter);
BUG_ON(ret == -EIOCBQUEUED);
if (ret > 0)
*ppos = kiocb.ki_pos;
return ret;
}
int rw_verify_area(int read_write, struct file *file, const loff_t *ppos, size_t count)
{
struct inode *inode;
loff_t pos;
int retval = -EINVAL;
inode = file_inode(file);
if (unlikely((ssize_t) count < 0))
return retval;
pos = *ppos;
if (unlikely(pos < 0)) {
if (!unsigned_offsets(file))
return retval;
if (count >= -pos)
return -EOVERFLOW;
} else if (unlikely((loff_t) (pos + count) < 0)) {
if (!unsigned_offsets(file))
return retval;
}
if (unlikely(inode->i_flctx && mandatory_lock(inode))) {
retval = locks_mandatory_area(inode, file, pos, pos + count - 1,
read_write == READ ? F_RDLCK : F_WRLCK);
if (retval < 0)
return retval;
}
return security_file_permission(file,
read_write == READ ? MAY_READ : MAY_WRITE);
}
static ssize_t new_sync_read(struct file *filp, char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = buf, .iov_len = len };
struct kiocb kiocb;
struct iov_iter iter;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
iov_iter_init(&iter, READ, &iov, 1, len);
ret = call_read_iter(filp, &kiocb, &iter);
BUG_ON(ret == -EIOCBQUEUED);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t __vfs_read(struct file *file, char __user *buf, size_t count,
loff_t *pos)
{
if (file->f_op->read)
return file->f_op->read(file, buf, count, pos);
else if (file->f_op->read_iter)
return new_sync_read(file, buf, count, pos);
else
return -EINVAL;
}
ssize_t vfs_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
ssize_t ret;
if (!(file->f_mode & FMODE_READ))
return -EBADF;
if (!(file->f_mode & FMODE_CAN_READ))
return -EINVAL;
if (unlikely(!access_ok(VERIFY_WRITE, buf, count)))
return -EFAULT;
ret = rw_verify_area(READ, file, pos, count);
if (!ret) {
if (count > MAX_RW_COUNT)
count = MAX_RW_COUNT;
ret = __vfs_read(file, buf, count, pos);
if (ret > 0) {
fsnotify_access(file);
add_rchar(current, ret);
}
inc_syscr(current);
}
return ret;
}
static ssize_t new_sync_write(struct file *filp, const char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = (void __user *)buf, .iov_len = len };
struct kiocb kiocb;
struct iov_iter iter;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
iov_iter_init(&iter, WRITE, &iov, 1, len);
ret = call_write_iter(filp, &kiocb, &iter);
BUG_ON(ret == -EIOCBQUEUED);
if (ret > 0)
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t __vfs_write(struct file *file, const char __user *p, size_t count,
loff_t *pos)
{
if (file->f_op->write)
return file->f_op->write(file, p, count, pos);
else if (file->f_op->write_iter)
return new_sync_write(file, p, count, pos);
else
return -EINVAL;
}
ssize_t __kernel_write(struct file *file, const char *buf, size_t count, loff_t *pos)
{
mm_segment_t old_fs;
const char __user *p;
ssize_t ret;
if (!(file->f_mode & FMODE_CAN_WRITE))
return -EINVAL;
old_fs = get_fs();
set_fs(get_ds());
p = (__force const char __user *)buf;
if (count > MAX_RW_COUNT)
count = MAX_RW_COUNT;
ret = __vfs_write(file, p, count, pos);
set_fs(old_fs);
if (ret > 0) {
fsnotify_modify(file);
add_wchar(current, ret);
}
inc_syscw(current);
return ret;
}
ssize_t vfs_write(struct file *file, const char __user *buf, size_t count, loff_t *pos)
{
ssize_t ret;
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if (!(file->f_mode & FMODE_CAN_WRITE))
return -EINVAL;
if (unlikely(!access_ok(VERIFY_READ, buf, count)))
return -EFAULT;
ret = rw_verify_area(WRITE, file, pos, count);
if (!ret) {
if (count > MAX_RW_COUNT)
count = MAX_RW_COUNT;
file_start_write(file);
ret = __vfs_write(file, buf, count, pos);
if (ret > 0) {
fsnotify_modify(file);
add_wchar(current, ret);
}
inc_syscw(current);
file_end_write(file);
}
return ret;
}
static inline loff_t file_pos_read(struct file *file)
{
return file->f_pos;
}
static inline void file_pos_write(struct file *file, loff_t pos)
{
file->f_pos = pos;
}
unsigned long iov_shorten(struct iovec *iov, unsigned long nr_segs, size_t to)
{
unsigned long seg = 0;
size_t len = 0;
while (seg < nr_segs) {
seg++;
if (len + iov->iov_len >= to) {
iov->iov_len = to - len;
break;
}
len += iov->iov_len;
iov++;
}
return seg;
}
static ssize_t do_iter_readv_writev(struct file *filp, struct iov_iter *iter,
loff_t *ppos, int type, int flags)
{
struct kiocb kiocb;
ssize_t ret;
if (flags & ~(RWF_HIPRI | RWF_DSYNC | RWF_SYNC))
return -EOPNOTSUPP;
init_sync_kiocb(&kiocb, filp);
if (flags & RWF_HIPRI)
kiocb.ki_flags |= IOCB_HIPRI;
if (flags & RWF_DSYNC)
kiocb.ki_flags |= IOCB_DSYNC;
if (flags & RWF_SYNC)
kiocb.ki_flags |= (IOCB_DSYNC | IOCB_SYNC);
kiocb.ki_pos = *ppos;
if (type == READ)
ret = call_read_iter(filp, &kiocb, iter);
else
ret = call_write_iter(filp, &kiocb, iter);
BUG_ON(ret == -EIOCBQUEUED);
*ppos = kiocb.ki_pos;
return ret;
}
static ssize_t do_loop_readv_writev(struct file *filp, struct iov_iter *iter,
loff_t *ppos, int type, int flags)
{
ssize_t ret = 0;
if (flags & ~RWF_HIPRI)
return -EOPNOTSUPP;
while (iov_iter_count(iter)) {
struct iovec iovec = iov_iter_iovec(iter);
ssize_t nr;
if (type == READ) {
nr = filp->f_op->read(filp, iovec.iov_base,
iovec.iov_len, ppos);
} else {
nr = filp->f_op->write(filp, iovec.iov_base,
iovec.iov_len, ppos);
}
if (nr < 0) {
if (!ret)
ret = nr;
break;
}
ret += nr;
if (nr != iovec.iov_len)
break;
iov_iter_advance(iter, nr);
}
return ret;
}
ssize_t rw_copy_check_uvector(int type, const struct iovec __user * uvector,
unsigned long nr_segs, unsigned long fast_segs,
struct iovec *fast_pointer,
struct iovec **ret_pointer)
{
unsigned long seg;
ssize_t ret;
struct iovec *iov = fast_pointer;
if (nr_segs == 0) {
ret = 0;
goto out;
}
if (nr_segs > UIO_MAXIOV) {
ret = -EINVAL;
goto out;
}
if (nr_segs > fast_segs) {
iov = kmalloc(nr_segs*sizeof(struct iovec), GFP_KERNEL);
if (iov == NULL) {
ret = -ENOMEM;
goto out;
}
}
if (copy_from_user(iov, uvector, nr_segs*sizeof(*uvector))) {
ret = -EFAULT;
goto out;
}
ret = 0;
for (seg = 0; seg < nr_segs; seg++) {
void __user *buf = iov[seg].iov_base;
ssize_t len = (ssize_t)iov[seg].iov_len;
if (len < 0) {
ret = -EINVAL;
goto out;
}
if (type >= 0
&& unlikely(!access_ok(vrfy_dir(type), buf, len))) {
ret = -EFAULT;
goto out;
}
if (len > MAX_RW_COUNT - ret) {
len = MAX_RW_COUNT - ret;
iov[seg].iov_len = len;
}
ret += len;
}
out:
*ret_pointer = iov;
return ret;
}
ssize_t compat_rw_copy_check_uvector(int type,
const struct compat_iovec __user *uvector, unsigned long nr_segs,
unsigned long fast_segs, struct iovec *fast_pointer,
struct iovec **ret_pointer)
{
compat_ssize_t tot_len;
struct iovec *iov = *ret_pointer = fast_pointer;
ssize_t ret = 0;
int seg;
if (nr_segs == 0)
goto out;
ret = -EINVAL;
if (nr_segs > UIO_MAXIOV)
goto out;
if (nr_segs > fast_segs) {
ret = -ENOMEM;
iov = kmalloc(nr_segs*sizeof(struct iovec), GFP_KERNEL);
if (iov == NULL)
goto out;
}
*ret_pointer = iov;
ret = -EFAULT;
if (!access_ok(VERIFY_READ, uvector, nr_segs*sizeof(*uvector)))
goto out;
tot_len = 0;
ret = -EINVAL;
for (seg = 0; seg < nr_segs; seg++) {
compat_uptr_t buf;
compat_ssize_t len;
if (__get_user(len, &uvector->iov_len) ||
__get_user(buf, &uvector->iov_base)) {
ret = -EFAULT;
goto out;
}
if (len < 0)
goto out;
if (type >= 0 &&
!access_ok(vrfy_dir(type), compat_ptr(buf), len)) {
ret = -EFAULT;
goto out;
}
if (len > MAX_RW_COUNT - tot_len)
len = MAX_RW_COUNT - tot_len;
tot_len += len;
iov->iov_base = compat_ptr(buf);
iov->iov_len = (compat_size_t) len;
uvector++;
iov++;
}
ret = tot_len;
out:
return ret;
}
static ssize_t __do_readv_writev(int type, struct file *file,
struct iov_iter *iter, loff_t *pos, int flags)
{
size_t tot_len;
ssize_t ret = 0;
tot_len = iov_iter_count(iter);
if (!tot_len)
goto out;
ret = rw_verify_area(type, file, pos, tot_len);
if (ret < 0)
goto out;
if (type != READ)
file_start_write(file);
if ((type == READ && file->f_op->read_iter) ||
(type == WRITE && file->f_op->write_iter))
ret = do_iter_readv_writev(file, iter, pos, type, flags);
else
ret = do_loop_readv_writev(file, iter, pos, type, flags);
if (type != READ)
file_end_write(file);
out:
if ((ret + (type == READ)) > 0) {
if (type == READ)
fsnotify_access(file);
else
fsnotify_modify(file);
}
return ret;
}
static ssize_t do_readv_writev(int type, struct file *file,
const struct iovec __user *uvector,
unsigned long nr_segs, loff_t *pos,
int flags)
{
struct iovec iovstack[UIO_FASTIOV];
struct iovec *iov = iovstack;
struct iov_iter iter;
ssize_t ret;
ret = import_iovec(type, uvector, nr_segs,
ARRAY_SIZE(iovstack), &iov, &iter);
if (ret < 0)
return ret;
ret = __do_readv_writev(type, file, &iter, pos, flags);
kfree(iov);
return ret;
}
ssize_t vfs_readv(struct file *file, const struct iovec __user *vec,
unsigned long vlen, loff_t *pos, int flags)
{
if (!(file->f_mode & FMODE_READ))
return -EBADF;
if (!(file->f_mode & FMODE_CAN_READ))
return -EINVAL;
return do_readv_writev(READ, file, vec, vlen, pos, flags);
}
ssize_t vfs_writev(struct file *file, const struct iovec __user *vec,
unsigned long vlen, loff_t *pos, int flags)
{
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if (!(file->f_mode & FMODE_CAN_WRITE))
return -EINVAL;
return do_readv_writev(WRITE, file, vec, vlen, pos, flags);
}
static ssize_t do_readv(unsigned long fd, const struct iovec __user *vec,
unsigned long vlen, int flags)
{
struct fd f = fdget_pos(fd);
ssize_t ret = -EBADF;
if (f.file) {
loff_t pos = file_pos_read(f.file);
ret = vfs_readv(f.file, vec, vlen, &pos, flags);
if (ret >= 0)
file_pos_write(f.file, pos);
fdput_pos(f);
}
if (ret > 0)
add_rchar(current, ret);
inc_syscr(current);
return ret;
}
static ssize_t do_writev(unsigned long fd, const struct iovec __user *vec,
unsigned long vlen, int flags)
{
struct fd f = fdget_pos(fd);
ssize_t ret = -EBADF;
if (f.file) {
loff_t pos = file_pos_read(f.file);
ret = vfs_writev(f.file, vec, vlen, &pos, flags);
if (ret >= 0)
file_pos_write(f.file, pos);
fdput_pos(f);
}
if (ret > 0)
add_wchar(current, ret);
inc_syscw(current);
return ret;
}
static inline loff_t pos_from_hilo(unsigned long high, unsigned long low)
{
#define HALF_LONG_BITS (BITS_PER_LONG / 2)
return (((loff_t)high << HALF_LONG_BITS) << HALF_LONG_BITS) | low;
}
static ssize_t do_preadv(unsigned long fd, const struct iovec __user *vec,
unsigned long vlen, loff_t pos, int flags)
{
struct fd f;
ssize_t ret = -EBADF;
if (pos < 0)
return -EINVAL;
f = fdget(fd);
if (f.file) {
ret = -ESPIPE;
if (f.file->f_mode & FMODE_PREAD)
ret = vfs_readv(f.file, vec, vlen, &pos, flags);
fdput(f);
}
if (ret > 0)
add_rchar(current, ret);
inc_syscr(current);
return ret;
}
static ssize_t do_pwritev(unsigned long fd, const struct iovec __user *vec,
unsigned long vlen, loff_t pos, int flags)
{
struct fd f;
ssize_t ret = -EBADF;
if (pos < 0)
return -EINVAL;
f = fdget(fd);
if (f.file) {
ret = -ESPIPE;
if (f.file->f_mode & FMODE_PWRITE)
ret = vfs_writev(f.file, vec, vlen, &pos, flags);
fdput(f);
}
if (ret > 0)
add_wchar(current, ret);
inc_syscw(current);
return ret;
}
static ssize_t compat_do_readv_writev(int type, struct file *file,
const struct compat_iovec __user *uvector,
unsigned long nr_segs, loff_t *pos,
int flags)
{
struct iovec iovstack[UIO_FASTIOV];
struct iovec *iov = iovstack;
struct iov_iter iter;
ssize_t ret;
ret = compat_import_iovec(type, uvector, nr_segs,
UIO_FASTIOV, &iov, &iter);
if (ret < 0)
return ret;
ret = __do_readv_writev(type, file, &iter, pos, flags);
kfree(iov);
return ret;
}
static size_t compat_readv(struct file *file,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t *pos, int flags)
{
ssize_t ret = -EBADF;
if (!(file->f_mode & FMODE_READ))
goto out;
ret = -EINVAL;
if (!(file->f_mode & FMODE_CAN_READ))
goto out;
ret = compat_do_readv_writev(READ, file, vec, vlen, pos, flags);
out:
if (ret > 0)
add_rchar(current, ret);
inc_syscr(current);
return ret;
}
static size_t do_compat_readv(compat_ulong_t fd,
const struct compat_iovec __user *vec,
compat_ulong_t vlen, int flags)
{
struct fd f = fdget_pos(fd);
ssize_t ret;
loff_t pos;
if (!f.file)
return -EBADF;
pos = f.file->f_pos;
ret = compat_readv(f.file, vec, vlen, &pos, flags);
if (ret >= 0)
f.file->f_pos = pos;
fdput_pos(f);
return ret;
}
static long do_compat_preadv64(unsigned long fd,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t pos, int flags)
{
struct fd f;
ssize_t ret;
if (pos < 0)
return -EINVAL;
f = fdget(fd);
if (!f.file)
return -EBADF;
ret = -ESPIPE;
if (f.file->f_mode & FMODE_PREAD)
ret = compat_readv(f.file, vec, vlen, &pos, flags);
fdput(f);
return ret;
}
static size_t compat_writev(struct file *file,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t *pos, int flags)
{
ssize_t ret = -EBADF;
if (!(file->f_mode & FMODE_WRITE))
goto out;
ret = -EINVAL;
if (!(file->f_mode & FMODE_CAN_WRITE))
goto out;
ret = compat_do_readv_writev(WRITE, file, vec, vlen, pos, flags);
out:
if (ret > 0)
add_wchar(current, ret);
inc_syscw(current);
return ret;
}
static size_t do_compat_writev(compat_ulong_t fd,
const struct compat_iovec __user* vec,
compat_ulong_t vlen, int flags)
{
struct fd f = fdget_pos(fd);
ssize_t ret;
loff_t pos;
if (!f.file)
return -EBADF;
pos = f.file->f_pos;
ret = compat_writev(f.file, vec, vlen, &pos, flags);
if (ret >= 0)
f.file->f_pos = pos;
fdput_pos(f);
return ret;
}
static long do_compat_pwritev64(unsigned long fd,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t pos, int flags)
{
struct fd f;
ssize_t ret;
if (pos < 0)
return -EINVAL;
f = fdget(fd);
if (!f.file)
return -EBADF;
ret = -ESPIPE;
if (f.file->f_mode & FMODE_PWRITE)
ret = compat_writev(f.file, vec, vlen, &pos, flags);
fdput(f);
return ret;
}
static ssize_t do_sendfile(int out_fd, int in_fd, loff_t *ppos,
size_t count, loff_t max)
{
struct fd in, out;
struct inode *in_inode, *out_inode;
loff_t pos;
loff_t out_pos;
ssize_t retval;
int fl;
retval = -EBADF;
in = fdget(in_fd);
if (!in.file)
goto out;
if (!(in.file->f_mode & FMODE_READ))
goto fput_in;
retval = -ESPIPE;
if (!ppos) {
pos = in.file->f_pos;
} else {
pos = *ppos;
if (!(in.file->f_mode & FMODE_PREAD))
goto fput_in;
}
retval = rw_verify_area(READ, in.file, &pos, count);
if (retval < 0)
goto fput_in;
if (count > MAX_RW_COUNT)
count = MAX_RW_COUNT;
retval = -EBADF;
out = fdget(out_fd);
if (!out.file)
goto fput_in;
if (!(out.file->f_mode & FMODE_WRITE))
goto fput_out;
retval = -EINVAL;
in_inode = file_inode(in.file);
out_inode = file_inode(out.file);
out_pos = out.file->f_pos;
retval = rw_verify_area(WRITE, out.file, &out_pos, count);
if (retval < 0)
goto fput_out;
if (!max)
max = min(in_inode->i_sb->s_maxbytes, out_inode->i_sb->s_maxbytes);
if (unlikely(pos + count > max)) {
retval = -EOVERFLOW;
if (pos >= max)
goto fput_out;
count = max - pos;
}
fl = 0;
#if 0
if (in.file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
file_start_write(out.file);
retval = do_splice_direct(in.file, &pos, out.file, &out_pos, count, fl);
file_end_write(out.file);
if (retval > 0) {
add_rchar(current, retval);
add_wchar(current, retval);
fsnotify_access(in.file);
fsnotify_modify(out.file);
out.file->f_pos = out_pos;
if (ppos)
*ppos = pos;
else
in.file->f_pos = pos;
}
inc_syscr(current);
inc_syscw(current);
if (pos > max)
retval = -EOVERFLOW;
fput_out:
fdput(out);
fput_in:
fdput(in);
out:
return retval;
}
ssize_t vfs_copy_file_range(struct file *file_in, loff_t pos_in,
struct file *file_out, loff_t pos_out,
size_t len, unsigned int flags)
{
struct inode *inode_in = file_inode(file_in);
struct inode *inode_out = file_inode(file_out);
ssize_t ret;
if (flags != 0)
return -EINVAL;
if (S_ISDIR(inode_in->i_mode) || S_ISDIR(inode_out->i_mode))
return -EISDIR;
if (!S_ISREG(inode_in->i_mode) || !S_ISREG(inode_out->i_mode))
return -EINVAL;
ret = rw_verify_area(READ, file_in, &pos_in, len);
if (unlikely(ret))
return ret;
ret = rw_verify_area(WRITE, file_out, &pos_out, len);
if (unlikely(ret))
return ret;
if (!(file_in->f_mode & FMODE_READ) ||
!(file_out->f_mode & FMODE_WRITE) ||
(file_out->f_flags & O_APPEND))
return -EBADF;
if (inode_in->i_sb != inode_out->i_sb)
return -EXDEV;
if (len == 0)
return 0;
file_start_write(file_out);
if (file_in->f_op->clone_file_range) {
ret = file_in->f_op->clone_file_range(file_in, pos_in,
file_out, pos_out, len);
if (ret == 0) {
ret = len;
goto done;
}
}
if (file_out->f_op->copy_file_range) {
ret = file_out->f_op->copy_file_range(file_in, pos_in, file_out,
pos_out, len, flags);
if (ret != -EOPNOTSUPP)
goto done;
}
ret = do_splice_direct(file_in, &pos_in, file_out, &pos_out,
len > MAX_RW_COUNT ? MAX_RW_COUNT : len, 0);
done:
if (ret > 0) {
fsnotify_access(file_in);
add_rchar(current, ret);
fsnotify_modify(file_out);
add_wchar(current, ret);
}
inc_syscr(current);
inc_syscw(current);
file_end_write(file_out);
return ret;
}
static int clone_verify_area(struct file *file, loff_t pos, u64 len, bool write)
{
struct inode *inode = file_inode(file);
if (unlikely(pos < 0))
return -EINVAL;
if (unlikely((loff_t) (pos + len) < 0))
return -EINVAL;
if (unlikely(inode->i_flctx && mandatory_lock(inode))) {
loff_t end = len ? pos + len - 1 : OFFSET_MAX;
int retval;
retval = locks_mandatory_area(inode, file, pos, end,
write ? F_WRLCK : F_RDLCK);
if (retval < 0)
return retval;
}
return security_file_permission(file, write ? MAY_WRITE : MAY_READ);
}
int vfs_clone_file_prep_inodes(struct inode *inode_in, loff_t pos_in,
struct inode *inode_out, loff_t pos_out,
u64 *len, bool is_dedupe)
{
loff_t bs = inode_out->i_sb->s_blocksize;
loff_t blen;
loff_t isize;
bool same_inode = (inode_in == inode_out);
int ret;
if (IS_IMMUTABLE(inode_out))
return -EPERM;
if (IS_SWAPFILE(inode_in) || IS_SWAPFILE(inode_out))
return -ETXTBSY;
if (S_ISDIR(inode_in->i_mode) || S_ISDIR(inode_out->i_mode))
return -EISDIR;
if (!S_ISREG(inode_in->i_mode) || !S_ISREG(inode_out->i_mode))
return -EINVAL;
isize = i_size_read(inode_in);
if (isize == 0)
return 0;
if (*len == 0) {
if (is_dedupe || pos_in == isize)
return 0;
if (pos_in > isize)
return -EINVAL;
*len = isize - pos_in;
}
if (pos_in + *len < pos_in || pos_out + *len < pos_out ||
pos_in + *len > isize)
return -EINVAL;
if (is_dedupe) {
loff_t disize;
disize = i_size_read(inode_out);
if (pos_out >= disize || pos_out + *len > disize)
return -EINVAL;
}
if (pos_in + *len == isize)
blen = ALIGN(isize, bs) - pos_in;
else
blen = *len;
if (!IS_ALIGNED(pos_in, bs) || !IS_ALIGNED(pos_in + blen, bs) ||
!IS_ALIGNED(pos_out, bs) || !IS_ALIGNED(pos_out + blen, bs))
return -EINVAL;
if (same_inode) {
if (pos_out + blen > pos_in && pos_out < pos_in + blen)
return -EINVAL;
}
inode_dio_wait(inode_in);
if (!same_inode)
inode_dio_wait(inode_out);
ret = filemap_write_and_wait_range(inode_in->i_mapping,
pos_in, pos_in + *len - 1);
if (ret)
return ret;
ret = filemap_write_and_wait_range(inode_out->i_mapping,
pos_out, pos_out + *len - 1);
if (ret)
return ret;
if (is_dedupe) {
bool is_same = false;
ret = vfs_dedupe_file_range_compare(inode_in, pos_in,
inode_out, pos_out, *len, &is_same);
if (ret)
return ret;
if (!is_same)
return -EBADE;
}
return 1;
}
int vfs_clone_file_range(struct file *file_in, loff_t pos_in,
struct file *file_out, loff_t pos_out, u64 len)
{
struct inode *inode_in = file_inode(file_in);
struct inode *inode_out = file_inode(file_out);
int ret;
if (S_ISDIR(inode_in->i_mode) || S_ISDIR(inode_out->i_mode))
return -EISDIR;
if (!S_ISREG(inode_in->i_mode) || !S_ISREG(inode_out->i_mode))
return -EINVAL;
if (inode_in->i_sb != inode_out->i_sb)
return -EXDEV;
if (!(file_in->f_mode & FMODE_READ) ||
!(file_out->f_mode & FMODE_WRITE) ||
(file_out->f_flags & O_APPEND))
return -EBADF;
if (!file_in->f_op->clone_file_range)
return -EOPNOTSUPP;
ret = clone_verify_area(file_in, pos_in, len, false);
if (ret)
return ret;
ret = clone_verify_area(file_out, pos_out, len, true);
if (ret)
return ret;
if (pos_in + len > i_size_read(inode_in))
return -EINVAL;
ret = file_in->f_op->clone_file_range(file_in, pos_in,
file_out, pos_out, len);
if (!ret) {
fsnotify_access(file_in);
fsnotify_modify(file_out);
}
return ret;
}
static struct page *vfs_dedupe_get_page(struct inode *inode, loff_t offset)
{
struct address_space *mapping;
struct page *page;
pgoff_t n;
n = offset >> PAGE_SHIFT;
mapping = inode->i_mapping;
page = read_mapping_page(mapping, n, NULL);
if (IS_ERR(page))
return page;
if (!PageUptodate(page)) {
put_page(page);
return ERR_PTR(-EIO);
}
lock_page(page);
return page;
}
int vfs_dedupe_file_range_compare(struct inode *src, loff_t srcoff,
struct inode *dest, loff_t destoff,
loff_t len, bool *is_same)
{
loff_t src_poff;
loff_t dest_poff;
void *src_addr;
void *dest_addr;
struct page *src_page;
struct page *dest_page;
loff_t cmp_len;
bool same;
int error;
error = -EINVAL;
same = true;
while (len) {
src_poff = srcoff & (PAGE_SIZE - 1);
dest_poff = destoff & (PAGE_SIZE - 1);
cmp_len = min(PAGE_SIZE - src_poff,
PAGE_SIZE - dest_poff);
cmp_len = min(cmp_len, len);
if (cmp_len <= 0)
goto out_error;
src_page = vfs_dedupe_get_page(src, srcoff);
if (IS_ERR(src_page)) {
error = PTR_ERR(src_page);
goto out_error;
}
dest_page = vfs_dedupe_get_page(dest, destoff);
if (IS_ERR(dest_page)) {
error = PTR_ERR(dest_page);
unlock_page(src_page);
put_page(src_page);
goto out_error;
}
src_addr = kmap_atomic(src_page);
dest_addr = kmap_atomic(dest_page);
flush_dcache_page(src_page);
flush_dcache_page(dest_page);
if (memcmp(src_addr + src_poff, dest_addr + dest_poff, cmp_len))
same = false;
kunmap_atomic(dest_addr);
kunmap_atomic(src_addr);
unlock_page(dest_page);
unlock_page(src_page);
put_page(dest_page);
put_page(src_page);
if (!same)
break;
srcoff += cmp_len;
destoff += cmp_len;
len -= cmp_len;
}
*is_same = same;
return 0;
out_error:
return error;
}
int vfs_dedupe_file_range(struct file *file, struct file_dedupe_range *same)
{
struct file_dedupe_range_info *info;
struct inode *src = file_inode(file);
u64 off;
u64 len;
int i;
int ret;
bool is_admin = capable(CAP_SYS_ADMIN);
u16 count = same->dest_count;
struct file *dst_file;
loff_t dst_off;
ssize_t deduped;
if (!(file->f_mode & FMODE_READ))
return -EINVAL;
if (same->reserved1 || same->reserved2)
return -EINVAL;
off = same->src_offset;
len = same->src_length;
ret = -EISDIR;
if (S_ISDIR(src->i_mode))
goto out;
ret = -EINVAL;
if (!S_ISREG(src->i_mode))
goto out;
ret = clone_verify_area(file, off, len, false);
if (ret < 0)
goto out;
ret = 0;
if (off + len > i_size_read(src))
return -EINVAL;
for (i = 0; i < count; i++) {
same->info[i].bytes_deduped = 0ULL;
same->info[i].status = FILE_DEDUPE_RANGE_SAME;
}
for (i = 0, info = same->info; i < count; i++, info++) {
struct inode *dst;
struct fd dst_fd = fdget(info->dest_fd);
dst_file = dst_fd.file;
if (!dst_file) {
info->status = -EBADF;
goto next_loop;
}
dst = file_inode(dst_file);
ret = mnt_want_write_file(dst_file);
if (ret) {
info->status = ret;
goto next_loop;
}
dst_off = info->dest_offset;
ret = clone_verify_area(dst_file, dst_off, len, true);
if (ret < 0) {
info->status = ret;
goto next_file;
}
ret = 0;
if (info->reserved) {
info->status = -EINVAL;
} else if (!(is_admin || (dst_file->f_mode & FMODE_WRITE))) {
info->status = -EINVAL;
} else if (file->f_path.mnt != dst_file->f_path.mnt) {
info->status = -EXDEV;
} else if (S_ISDIR(dst->i_mode)) {
info->status = -EISDIR;
} else if (dst_file->f_op->dedupe_file_range == NULL) {
info->status = -EINVAL;
} else {
deduped = dst_file->f_op->dedupe_file_range(file, off,
len, dst_file,
info->dest_offset);
if (deduped == -EBADE)
info->status = FILE_DEDUPE_RANGE_DIFFERS;
else if (deduped < 0)
info->status = deduped;
else
info->bytes_deduped += deduped;
}
next_file:
mnt_drop_write_file(dst_file);
next_loop:
fdput(dst_fd);
if (fatal_signal_pending(current))
goto out;
}
out:
return ret;
}
