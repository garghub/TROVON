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
mutex_lock(&inode->i_mutex);
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
mutex_unlock(&inode->i_mutex);
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
static inline struct fd fdget_pos(int fd)
{
return __to_fd(__fdget_pos(fd));
}
static inline void fdput_pos(struct fd f)
{
if (f.flags & FDPUT_POS_UNLOCK)
mutex_unlock(&f.file->f_pos_lock);
fdput(f);
}
ssize_t vfs_iter_read(struct file *file, struct iov_iter *iter, loff_t *ppos)
{
struct kiocb kiocb;
ssize_t ret;
if (!file->f_op->read_iter)
return -EINVAL;
init_sync_kiocb(&kiocb, file);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = iov_iter_count(iter);
iter->type |= READ;
ret = file->f_op->read_iter(&kiocb, iter);
if (ret == -EIOCBQUEUED)
ret = wait_on_sync_kiocb(&kiocb);
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
kiocb.ki_nbytes = iov_iter_count(iter);
iter->type |= WRITE;
ret = file->f_op->write_iter(&kiocb, iter);
if (ret == -EIOCBQUEUED)
ret = wait_on_sync_kiocb(&kiocb);
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
retval = locks_mandatory_area(
read_write == READ ? FLOCK_VERIFY_READ : FLOCK_VERIFY_WRITE,
inode, file, pos, count);
if (retval < 0)
return retval;
}
retval = security_file_permission(file,
read_write == READ ? MAY_READ : MAY_WRITE);
if (retval)
return retval;
return count > MAX_RW_COUNT ? MAX_RW_COUNT : count;
}
ssize_t do_sync_read(struct file *filp, char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = buf, .iov_len = len };
struct kiocb kiocb;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = len;
ret = filp->f_op->aio_read(&kiocb, &iov, 1, kiocb.ki_pos);
if (-EIOCBQUEUED == ret)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t new_sync_read(struct file *filp, char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = buf, .iov_len = len };
struct kiocb kiocb;
struct iov_iter iter;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = len;
iov_iter_init(&iter, READ, &iov, 1, len);
ret = filp->f_op->read_iter(&kiocb, &iter);
if (-EIOCBQUEUED == ret)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t __vfs_read(struct file *file, char __user *buf, size_t count,
loff_t *pos)
{
ssize_t ret;
if (file->f_op->read)
ret = file->f_op->read(file, buf, count, pos);
else if (file->f_op->aio_read)
ret = do_sync_read(file, buf, count, pos);
else if (file->f_op->read_iter)
ret = new_sync_read(file, buf, count, pos);
else
ret = -EINVAL;
return ret;
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
if (ret >= 0) {
count = ret;
ret = __vfs_read(file, buf, count, pos);
if (ret > 0) {
fsnotify_access(file);
add_rchar(current, ret);
}
inc_syscr(current);
}
return ret;
}
ssize_t do_sync_write(struct file *filp, const char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = (void __user *)buf, .iov_len = len };
struct kiocb kiocb;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = len;
ret = filp->f_op->aio_write(&kiocb, &iov, 1, kiocb.ki_pos);
if (-EIOCBQUEUED == ret)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t new_sync_write(struct file *filp, const char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = (void __user *)buf, .iov_len = len };
struct kiocb kiocb;
struct iov_iter iter;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = len;
iov_iter_init(&iter, WRITE, &iov, 1, len);
ret = filp->f_op->write_iter(&kiocb, &iter);
if (-EIOCBQUEUED == ret)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
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
if (file->f_op->write)
ret = file->f_op->write(file, p, count, pos);
else if (file->f_op->aio_write)
ret = do_sync_write(file, p, count, pos);
else
ret = new_sync_write(file, p, count, pos);
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
if (ret >= 0) {
count = ret;
file_start_write(file);
if (file->f_op->write)
ret = file->f_op->write(file, buf, count, pos);
else if (file->f_op->aio_write)
ret = do_sync_write(file, buf, count, pos);
else
ret = new_sync_write(file, buf, count, pos);
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
static ssize_t do_iter_readv_writev(struct file *filp, int rw, const struct iovec *iov,
unsigned long nr_segs, size_t len, loff_t *ppos, iter_fn_t fn)
{
struct kiocb kiocb;
struct iov_iter iter;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = len;
iov_iter_init(&iter, rw, iov, nr_segs, len);
ret = fn(&kiocb, &iter);
if (ret == -EIOCBQUEUED)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
static ssize_t do_sync_readv_writev(struct file *filp, const struct iovec *iov,
unsigned long nr_segs, size_t len, loff_t *ppos, iov_fn_t fn)
{
struct kiocb kiocb;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_nbytes = len;
ret = fn(&kiocb, iov, nr_segs, kiocb.ki_pos);
if (ret == -EIOCBQUEUED)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
static ssize_t do_loop_readv_writev(struct file *filp, struct iovec *iov,
unsigned long nr_segs, loff_t *ppos, io_fn_t fn)
{
struct iovec *vector = iov;
ssize_t ret = 0;
while (nr_segs > 0) {
void __user *base;
size_t len;
ssize_t nr;
base = vector->iov_base;
len = vector->iov_len;
vector++;
nr_segs--;
nr = fn(filp, base, len, ppos);
if (nr < 0) {
if (!ret)
ret = nr;
break;
}
ret += nr;
if (nr != len)
break;
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
static ssize_t do_readv_writev(int type, struct file *file,
const struct iovec __user * uvector,
unsigned long nr_segs, loff_t *pos)
{
size_t tot_len;
struct iovec iovstack[UIO_FASTIOV];
struct iovec *iov = iovstack;
ssize_t ret;
io_fn_t fn;
iov_fn_t fnv;
iter_fn_t iter_fn;
ret = rw_copy_check_uvector(type, uvector, nr_segs,
ARRAY_SIZE(iovstack), iovstack, &iov);
if (ret <= 0)
goto out;
tot_len = ret;
ret = rw_verify_area(type, file, pos, tot_len);
if (ret < 0)
goto out;
fnv = NULL;
if (type == READ) {
fn = file->f_op->read;
fnv = file->f_op->aio_read;
iter_fn = file->f_op->read_iter;
} else {
fn = (io_fn_t)file->f_op->write;
fnv = file->f_op->aio_write;
iter_fn = file->f_op->write_iter;
file_start_write(file);
}
if (iter_fn)
ret = do_iter_readv_writev(file, type, iov, nr_segs, tot_len,
pos, iter_fn);
else if (fnv)
ret = do_sync_readv_writev(file, iov, nr_segs, tot_len,
pos, fnv);
else
ret = do_loop_readv_writev(file, iov, nr_segs, pos, fn);
if (type != READ)
file_end_write(file);
out:
if (iov != iovstack)
kfree(iov);
if ((ret + (type == READ)) > 0) {
if (type == READ)
fsnotify_access(file);
else
fsnotify_modify(file);
}
return ret;
}
ssize_t vfs_readv(struct file *file, const struct iovec __user *vec,
unsigned long vlen, loff_t *pos)
{
if (!(file->f_mode & FMODE_READ))
return -EBADF;
if (!(file->f_mode & FMODE_CAN_READ))
return -EINVAL;
return do_readv_writev(READ, file, vec, vlen, pos);
}
ssize_t vfs_writev(struct file *file, const struct iovec __user *vec,
unsigned long vlen, loff_t *pos)
{
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if (!(file->f_mode & FMODE_CAN_WRITE))
return -EINVAL;
return do_readv_writev(WRITE, file, vec, vlen, pos);
}
static inline loff_t pos_from_hilo(unsigned long high, unsigned long low)
{
#define HALF_LONG_BITS (BITS_PER_LONG / 2)
return (((loff_t)high << HALF_LONG_BITS) << HALF_LONG_BITS) | low;
}
static ssize_t compat_do_readv_writev(int type, struct file *file,
const struct compat_iovec __user *uvector,
unsigned long nr_segs, loff_t *pos)
{
compat_ssize_t tot_len;
struct iovec iovstack[UIO_FASTIOV];
struct iovec *iov = iovstack;
ssize_t ret;
io_fn_t fn;
iov_fn_t fnv;
iter_fn_t iter_fn;
ret = compat_rw_copy_check_uvector(type, uvector, nr_segs,
UIO_FASTIOV, iovstack, &iov);
if (ret <= 0)
goto out;
tot_len = ret;
ret = rw_verify_area(type, file, pos, tot_len);
if (ret < 0)
goto out;
fnv = NULL;
if (type == READ) {
fn = file->f_op->read;
fnv = file->f_op->aio_read;
iter_fn = file->f_op->read_iter;
} else {
fn = (io_fn_t)file->f_op->write;
fnv = file->f_op->aio_write;
iter_fn = file->f_op->write_iter;
file_start_write(file);
}
if (iter_fn)
ret = do_iter_readv_writev(file, type, iov, nr_segs, tot_len,
pos, iter_fn);
else if (fnv)
ret = do_sync_readv_writev(file, iov, nr_segs, tot_len,
pos, fnv);
else
ret = do_loop_readv_writev(file, iov, nr_segs, pos, fn);
if (type != READ)
file_end_write(file);
out:
if (iov != iovstack)
kfree(iov);
if ((ret + (type == READ)) > 0) {
if (type == READ)
fsnotify_access(file);
else
fsnotify_modify(file);
}
return ret;
}
static size_t compat_readv(struct file *file,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t *pos)
{
ssize_t ret = -EBADF;
if (!(file->f_mode & FMODE_READ))
goto out;
ret = -EINVAL;
if (!(file->f_mode & FMODE_CAN_READ))
goto out;
ret = compat_do_readv_writev(READ, file, vec, vlen, pos);
out:
if (ret > 0)
add_rchar(current, ret);
inc_syscr(current);
return ret;
}
static long __compat_sys_preadv64(unsigned long fd,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t pos)
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
ret = compat_readv(f.file, vec, vlen, &pos);
fdput(f);
return ret;
}
static size_t compat_writev(struct file *file,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t *pos)
{
ssize_t ret = -EBADF;
if (!(file->f_mode & FMODE_WRITE))
goto out;
ret = -EINVAL;
if (!(file->f_mode & FMODE_CAN_WRITE))
goto out;
ret = compat_do_readv_writev(WRITE, file, vec, vlen, pos);
out:
if (ret > 0)
add_wchar(current, ret);
inc_syscw(current);
return ret;
}
static long __compat_sys_pwritev64(unsigned long fd,
const struct compat_iovec __user *vec,
unsigned long vlen, loff_t pos)
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
ret = compat_writev(f.file, vec, vlen, &pos);
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
count = retval;
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
count = retval;
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
