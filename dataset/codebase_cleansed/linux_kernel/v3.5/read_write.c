static inline int unsigned_offsets(struct file *file)
{
return file->f_mode & FMODE_UNSIGNED_OFFSET;
}
static loff_t lseek_execute(struct file *file, struct inode *inode,
loff_t offset, loff_t maxsize)
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
generic_file_llseek_size(struct file *file, loff_t offset, int origin,
loff_t maxsize)
{
struct inode *inode = file->f_mapping->host;
switch (origin) {
case SEEK_END:
offset += i_size_read(inode);
break;
case SEEK_CUR:
if (offset == 0)
return file->f_pos;
spin_lock(&file->f_lock);
offset = lseek_execute(file, inode, file->f_pos + offset,
maxsize);
spin_unlock(&file->f_lock);
return offset;
case SEEK_DATA:
if (offset >= i_size_read(inode))
return -ENXIO;
break;
case SEEK_HOLE:
if (offset >= i_size_read(inode))
return -ENXIO;
offset = i_size_read(inode);
break;
}
return lseek_execute(file, inode, offset, maxsize);
}
loff_t generic_file_llseek(struct file *file, loff_t offset, int origin)
{
struct inode *inode = file->f_mapping->host;
return generic_file_llseek_size(file, offset, origin,
inode->i_sb->s_maxbytes);
}
loff_t noop_llseek(struct file *file, loff_t offset, int origin)
{
return file->f_pos;
}
loff_t no_llseek(struct file *file, loff_t offset, int origin)
{
return -ESPIPE;
}
loff_t default_llseek(struct file *file, loff_t offset, int origin)
{
struct inode *inode = file->f_path.dentry->d_inode;
loff_t retval;
mutex_lock(&inode->i_mutex);
switch (origin) {
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
loff_t vfs_llseek(struct file *file, loff_t offset, int origin)
{
loff_t (*fn)(struct file *, loff_t, int);
fn = no_llseek;
if (file->f_mode & FMODE_LSEEK) {
if (file->f_op && file->f_op->llseek)
fn = file->f_op->llseek;
}
return fn(file, offset, origin);
}
int rw_verify_area(int read_write, struct file *file, loff_t *ppos, size_t count)
{
struct inode *inode;
loff_t pos;
int retval = -EINVAL;
inode = file->f_path.dentry->d_inode;
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
if (unlikely(inode->i_flock && mandatory_lock(inode))) {
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
static void wait_on_retry_sync_kiocb(struct kiocb *iocb)
{
set_current_state(TASK_UNINTERRUPTIBLE);
if (!kiocbIsKicked(iocb))
schedule();
else
kiocbClearKicked(iocb);
__set_current_state(TASK_RUNNING);
}
ssize_t do_sync_read(struct file *filp, char __user *buf, size_t len, loff_t *ppos)
{
struct iovec iov = { .iov_base = buf, .iov_len = len };
struct kiocb kiocb;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_left = len;
kiocb.ki_nbytes = len;
for (;;) {
ret = filp->f_op->aio_read(&kiocb, &iov, 1, kiocb.ki_pos);
if (ret != -EIOCBRETRY)
break;
wait_on_retry_sync_kiocb(&kiocb);
}
if (-EIOCBQUEUED == ret)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t vfs_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
ssize_t ret;
if (!(file->f_mode & FMODE_READ))
return -EBADF;
if (!file->f_op || (!file->f_op->read && !file->f_op->aio_read))
return -EINVAL;
if (unlikely(!access_ok(VERIFY_WRITE, buf, count)))
return -EFAULT;
ret = rw_verify_area(READ, file, pos, count);
if (ret >= 0) {
count = ret;
if (file->f_op->read)
ret = file->f_op->read(file, buf, count, pos);
else
ret = do_sync_read(file, buf, count, pos);
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
kiocb.ki_left = len;
kiocb.ki_nbytes = len;
for (;;) {
ret = filp->f_op->aio_write(&kiocb, &iov, 1, kiocb.ki_pos);
if (ret != -EIOCBRETRY)
break;
wait_on_retry_sync_kiocb(&kiocb);
}
if (-EIOCBQUEUED == ret)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t vfs_write(struct file *file, const char __user *buf, size_t count, loff_t *pos)
{
ssize_t ret;
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if (!file->f_op || (!file->f_op->write && !file->f_op->aio_write))
return -EINVAL;
if (unlikely(!access_ok(VERIFY_READ, buf, count)))
return -EFAULT;
ret = rw_verify_area(WRITE, file, pos, count);
if (ret >= 0) {
count = ret;
if (file->f_op->write)
ret = file->f_op->write(file, buf, count, pos);
else
ret = do_sync_write(file, buf, count, pos);
if (ret > 0) {
fsnotify_modify(file);
add_wchar(current, ret);
}
inc_syscw(current);
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
SYSCALL_DEFINE(pread64)(unsigned int fd, char __user *buf,
size_t count, loff_t pos)
{
struct file *file;
ssize_t ret = -EBADF;
int fput_needed;
if (pos < 0)
return -EINVAL;
file = fget_light(fd, &fput_needed);
if (file) {
ret = -ESPIPE;
if (file->f_mode & FMODE_PREAD)
ret = vfs_read(file, buf, count, &pos);
fput_light(file, fput_needed);
}
return ret;
}
asmlinkage long SyS_pread64(long fd, long buf, long count, loff_t pos)
{
return SYSC_pread64((unsigned int) fd, (char __user *) buf,
(size_t) count, pos);
}
SYSCALL_DEFINE(pwrite64)(unsigned int fd, const char __user *buf,
size_t count, loff_t pos)
{
struct file *file;
ssize_t ret = -EBADF;
int fput_needed;
if (pos < 0)
return -EINVAL;
file = fget_light(fd, &fput_needed);
if (file) {
ret = -ESPIPE;
if (file->f_mode & FMODE_PWRITE)
ret = vfs_write(file, buf, count, &pos);
fput_light(file, fput_needed);
}
return ret;
}
asmlinkage long SyS_pwrite64(long fd, long buf, long count, loff_t pos)
{
return SYSC_pwrite64((unsigned int) fd, (const char __user *) buf,
(size_t) count, pos);
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
ssize_t do_sync_readv_writev(struct file *filp, const struct iovec *iov,
unsigned long nr_segs, size_t len, loff_t *ppos, iov_fn_t fn)
{
struct kiocb kiocb;
ssize_t ret;
init_sync_kiocb(&kiocb, filp);
kiocb.ki_pos = *ppos;
kiocb.ki_left = len;
kiocb.ki_nbytes = len;
for (;;) {
ret = fn(&kiocb, iov, nr_segs, kiocb.ki_pos);
if (ret != -EIOCBRETRY)
break;
wait_on_retry_sync_kiocb(&kiocb);
}
if (ret == -EIOCBQUEUED)
ret = wait_on_sync_kiocb(&kiocb);
*ppos = kiocb.ki_pos;
return ret;
}
ssize_t do_loop_readv_writev(struct file *filp, struct iovec *iov,
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
if (!file->f_op) {
ret = -EINVAL;
goto out;
}
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
} else {
fn = (io_fn_t)file->f_op->write;
fnv = file->f_op->aio_write;
}
if (fnv)
ret = do_sync_readv_writev(file, iov, nr_segs, tot_len,
pos, fnv);
else
ret = do_loop_readv_writev(file, iov, nr_segs, pos, fn);
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
if (!file->f_op || (!file->f_op->aio_read && !file->f_op->read))
return -EINVAL;
return do_readv_writev(READ, file, vec, vlen, pos);
}
ssize_t vfs_writev(struct file *file, const struct iovec __user *vec,
unsigned long vlen, loff_t *pos)
{
if (!(file->f_mode & FMODE_WRITE))
return -EBADF;
if (!file->f_op || (!file->f_op->aio_write && !file->f_op->write))
return -EINVAL;
return do_readv_writev(WRITE, file, vec, vlen, pos);
}
static inline loff_t pos_from_hilo(unsigned long high, unsigned long low)
{
#define HALF_LONG_BITS (BITS_PER_LONG / 2)
return (((loff_t)high << HALF_LONG_BITS) << HALF_LONG_BITS) | low;
}
static ssize_t do_sendfile(int out_fd, int in_fd, loff_t *ppos,
size_t count, loff_t max)
{
struct file * in_file, * out_file;
struct inode * in_inode, * out_inode;
loff_t pos;
ssize_t retval;
int fput_needed_in, fput_needed_out, fl;
retval = -EBADF;
in_file = fget_light(in_fd, &fput_needed_in);
if (!in_file)
goto out;
if (!(in_file->f_mode & FMODE_READ))
goto fput_in;
retval = -ESPIPE;
if (!ppos)
ppos = &in_file->f_pos;
else
if (!(in_file->f_mode & FMODE_PREAD))
goto fput_in;
retval = rw_verify_area(READ, in_file, ppos, count);
if (retval < 0)
goto fput_in;
count = retval;
retval = -EBADF;
out_file = fget_light(out_fd, &fput_needed_out);
if (!out_file)
goto fput_in;
if (!(out_file->f_mode & FMODE_WRITE))
goto fput_out;
retval = -EINVAL;
in_inode = in_file->f_path.dentry->d_inode;
out_inode = out_file->f_path.dentry->d_inode;
retval = rw_verify_area(WRITE, out_file, &out_file->f_pos, count);
if (retval < 0)
goto fput_out;
count = retval;
if (!max)
max = min(in_inode->i_sb->s_maxbytes, out_inode->i_sb->s_maxbytes);
pos = *ppos;
if (unlikely(pos + count > max)) {
retval = -EOVERFLOW;
if (pos >= max)
goto fput_out;
count = max - pos;
}
fl = 0;
#if 0
if (in_file->f_flags & O_NONBLOCK)
fl = SPLICE_F_NONBLOCK;
#endif
retval = do_splice_direct(in_file, ppos, out_file, count, fl);
if (retval > 0) {
add_rchar(current, retval);
add_wchar(current, retval);
}
inc_syscr(current);
inc_syscw(current);
if (*ppos > max)
retval = -EOVERFLOW;
fput_out:
fput_light(out_file, fput_needed_out);
fput_in:
fput_light(in_file, fput_needed_in);
out:
return retval;
}
