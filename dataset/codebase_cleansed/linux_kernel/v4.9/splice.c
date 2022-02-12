static int page_cache_pipe_buf_steal(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
struct page *page = buf->page;
struct address_space *mapping;
lock_page(page);
mapping = page_mapping(page);
if (mapping) {
WARN_ON(!PageUptodate(page));
wait_on_page_writeback(page);
if (page_has_private(page) &&
!try_to_release_page(page, GFP_KERNEL))
goto out_unlock;
if (remove_mapping(mapping, page)) {
buf->flags |= PIPE_BUF_FLAG_LRU;
return 0;
}
}
out_unlock:
unlock_page(page);
return 1;
}
static void page_cache_pipe_buf_release(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
put_page(buf->page);
buf->flags &= ~PIPE_BUF_FLAG_LRU;
}
static int page_cache_pipe_buf_confirm(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
struct page *page = buf->page;
int err;
if (!PageUptodate(page)) {
lock_page(page);
if (!page->mapping) {
err = -ENODATA;
goto error;
}
if (!PageUptodate(page)) {
err = -EIO;
goto error;
}
unlock_page(page);
}
return 0;
error:
unlock_page(page);
return err;
}
static int user_page_pipe_buf_steal(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
if (!(buf->flags & PIPE_BUF_FLAG_GIFT))
return 1;
buf->flags |= PIPE_BUF_FLAG_LRU;
return generic_pipe_buf_steal(pipe, buf);
}
static void wakeup_pipe_readers(struct pipe_inode_info *pipe)
{
smp_mb();
if (waitqueue_active(&pipe->wait))
wake_up_interruptible(&pipe->wait);
kill_fasync(&pipe->fasync_readers, SIGIO, POLL_IN);
}
ssize_t splice_to_pipe(struct pipe_inode_info *pipe,
struct splice_pipe_desc *spd)
{
unsigned int spd_pages = spd->nr_pages;
int ret = 0, page_nr = 0;
if (!spd_pages)
return 0;
if (unlikely(!pipe->readers)) {
send_sig(SIGPIPE, current, 0);
ret = -EPIPE;
goto out;
}
while (pipe->nrbufs < pipe->buffers) {
int newbuf = (pipe->curbuf + pipe->nrbufs) & (pipe->buffers - 1);
struct pipe_buffer *buf = pipe->bufs + newbuf;
buf->page = spd->pages[page_nr];
buf->offset = spd->partial[page_nr].offset;
buf->len = spd->partial[page_nr].len;
buf->private = spd->partial[page_nr].private;
buf->ops = spd->ops;
pipe->nrbufs++;
page_nr++;
ret += buf->len;
if (!--spd->nr_pages)
break;
}
if (!ret)
ret = -EAGAIN;
out:
while (page_nr < spd_pages)
spd->spd_release(spd, page_nr++);
return ret;
}
ssize_t add_to_pipe(struct pipe_inode_info *pipe, struct pipe_buffer *buf)
{
int ret;
if (unlikely(!pipe->readers)) {
send_sig(SIGPIPE, current, 0);
ret = -EPIPE;
} else if (pipe->nrbufs == pipe->buffers) {
ret = -EAGAIN;
} else {
int newbuf = (pipe->curbuf + pipe->nrbufs) & (pipe->buffers - 1);
pipe->bufs[newbuf] = *buf;
pipe->nrbufs++;
return buf->len;
}
pipe_buf_release(pipe, buf);
return ret;
}
void spd_release_page(struct splice_pipe_desc *spd, unsigned int i)
{
put_page(spd->pages[i]);
}
int splice_grow_spd(const struct pipe_inode_info *pipe, struct splice_pipe_desc *spd)
{
unsigned int buffers = ACCESS_ONCE(pipe->buffers);
spd->nr_pages_max = buffers;
if (buffers <= PIPE_DEF_BUFFERS)
return 0;
spd->pages = kmalloc(buffers * sizeof(struct page *), GFP_KERNEL);
spd->partial = kmalloc(buffers * sizeof(struct partial_page), GFP_KERNEL);
if (spd->pages && spd->partial)
return 0;
kfree(spd->pages);
kfree(spd->partial);
return -ENOMEM;
}
void splice_shrink_spd(struct splice_pipe_desc *spd)
{
if (spd->nr_pages_max <= PIPE_DEF_BUFFERS)
return;
kfree(spd->pages);
kfree(spd->partial);
}
ssize_t generic_file_splice_read(struct file *in, loff_t *ppos,
struct pipe_inode_info *pipe, size_t len,
unsigned int flags)
{
struct iov_iter to;
struct kiocb kiocb;
int idx, ret;
iov_iter_pipe(&to, ITER_PIPE | READ, pipe, len);
idx = to.idx;
init_sync_kiocb(&kiocb, in);
kiocb.ki_pos = *ppos;
ret = in->f_op->read_iter(&kiocb, &to);
if (ret > 0) {
*ppos = kiocb.ki_pos;
file_accessed(in);
} else if (ret < 0) {
to.idx = idx;
to.iov_offset = 0;
iov_iter_advance(&to, 0);
if (ret == -EFAULT)
ret = -EAGAIN;
}
return ret;
}
static int generic_pipe_buf_nosteal(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
return 1;
}
static ssize_t kernel_readv(struct file *file, const struct kvec *vec,
unsigned long vlen, loff_t offset)
{
mm_segment_t old_fs;
loff_t pos = offset;
ssize_t res;
old_fs = get_fs();
set_fs(get_ds());
res = vfs_readv(file, (const struct iovec __user *)vec, vlen, &pos, 0);
set_fs(old_fs);
return res;
}
ssize_t kernel_write(struct file *file, const char *buf, size_t count,
loff_t pos)
{
mm_segment_t old_fs;
ssize_t res;
old_fs = get_fs();
set_fs(get_ds());
res = vfs_write(file, (__force const char __user *)buf, count, &pos);
set_fs(old_fs);
return res;
}
static ssize_t default_file_splice_read(struct file *in, loff_t *ppos,
struct pipe_inode_info *pipe, size_t len,
unsigned int flags)
{
struct kvec *vec, __vec[PIPE_DEF_BUFFERS];
struct iov_iter to;
struct page **pages;
unsigned int nr_pages;
size_t offset, dummy, copied = 0;
ssize_t res;
int i;
if (pipe->nrbufs == pipe->buffers)
return -EAGAIN;
offset = *ppos & ~PAGE_MASK;
iov_iter_pipe(&to, ITER_PIPE | READ, pipe, len + offset);
res = iov_iter_get_pages_alloc(&to, &pages, len + offset, &dummy);
if (res <= 0)
return -ENOMEM;
BUG_ON(dummy);
nr_pages = DIV_ROUND_UP(res, PAGE_SIZE);
vec = __vec;
if (nr_pages > PIPE_DEF_BUFFERS) {
vec = kmalloc(nr_pages * sizeof(struct kvec), GFP_KERNEL);
if (unlikely(!vec)) {
res = -ENOMEM;
goto out;
}
}
pipe->bufs[to.idx].offset = offset;
pipe->bufs[to.idx].len -= offset;
for (i = 0; i < nr_pages; i++) {
size_t this_len = min_t(size_t, len, PAGE_SIZE - offset);
vec[i].iov_base = page_address(pages[i]) + offset;
vec[i].iov_len = this_len;
len -= this_len;
offset = 0;
}
res = kernel_readv(in, vec, nr_pages, *ppos);
if (res > 0) {
copied = res;
*ppos += res;
}
if (vec != __vec)
kfree(vec);
out:
for (i = 0; i < nr_pages; i++)
put_page(pages[i]);
kvfree(pages);
iov_iter_advance(&to, copied);
return res;
}
static int pipe_to_sendpage(struct pipe_inode_info *pipe,
struct pipe_buffer *buf, struct splice_desc *sd)
{
struct file *file = sd->u.file;
loff_t pos = sd->pos;
int more;
if (!likely(file->f_op->sendpage))
return -EINVAL;
more = (sd->flags & SPLICE_F_MORE) ? MSG_MORE : 0;
if (sd->len < sd->total_len && pipe->nrbufs > 1)
more |= MSG_SENDPAGE_NOTLAST;
return file->f_op->sendpage(file, buf->page, buf->offset,
sd->len, &pos, more);
}
static void wakeup_pipe_writers(struct pipe_inode_info *pipe)
{
smp_mb();
if (waitqueue_active(&pipe->wait))
wake_up_interruptible(&pipe->wait);
kill_fasync(&pipe->fasync_writers, SIGIO, POLL_OUT);
}
static int splice_from_pipe_feed(struct pipe_inode_info *pipe, struct splice_desc *sd,
splice_actor *actor)
{
int ret;
while (pipe->nrbufs) {
struct pipe_buffer *buf = pipe->bufs + pipe->curbuf;
sd->len = buf->len;
if (sd->len > sd->total_len)
sd->len = sd->total_len;
ret = pipe_buf_confirm(pipe, buf);
if (unlikely(ret)) {
if (ret == -ENODATA)
ret = 0;
return ret;
}
ret = actor(pipe, buf, sd);
if (ret <= 0)
return ret;
buf->offset += ret;
buf->len -= ret;
sd->num_spliced += ret;
sd->len -= ret;
sd->pos += ret;
sd->total_len -= ret;
if (!buf->len) {
pipe_buf_release(pipe, buf);
pipe->curbuf = (pipe->curbuf + 1) & (pipe->buffers - 1);
pipe->nrbufs--;
if (pipe->files)
sd->need_wakeup = true;
}
if (!sd->total_len)
return 0;
}
return 1;
}
static int splice_from_pipe_next(struct pipe_inode_info *pipe, struct splice_desc *sd)
{
if (signal_pending(current))
return -ERESTARTSYS;
while (!pipe->nrbufs) {
if (!pipe->writers)
return 0;
if (!pipe->waiting_writers && sd->num_spliced)
return 0;
if (sd->flags & SPLICE_F_NONBLOCK)
return -EAGAIN;
if (signal_pending(current))
return -ERESTARTSYS;
if (sd->need_wakeup) {
wakeup_pipe_writers(pipe);
sd->need_wakeup = false;
}
pipe_wait(pipe);
}
return 1;
}
static void splice_from_pipe_begin(struct splice_desc *sd)
{
sd->num_spliced = 0;
sd->need_wakeup = false;
}
static void splice_from_pipe_end(struct pipe_inode_info *pipe, struct splice_desc *sd)
{
if (sd->need_wakeup)
wakeup_pipe_writers(pipe);
}
ssize_t __splice_from_pipe(struct pipe_inode_info *pipe, struct splice_desc *sd,
splice_actor *actor)
{
int ret;
splice_from_pipe_begin(sd);
do {
cond_resched();
ret = splice_from_pipe_next(pipe, sd);
if (ret > 0)
ret = splice_from_pipe_feed(pipe, sd, actor);
} while (ret > 0);
splice_from_pipe_end(pipe, sd);
return sd->num_spliced ? sd->num_spliced : ret;
}
ssize_t splice_from_pipe(struct pipe_inode_info *pipe, struct file *out,
loff_t *ppos, size_t len, unsigned int flags,
splice_actor *actor)
{
ssize_t ret;
struct splice_desc sd = {
.total_len = len,
.flags = flags,
.pos = *ppos,
.u.file = out,
};
pipe_lock(pipe);
ret = __splice_from_pipe(pipe, &sd, actor);
pipe_unlock(pipe);
return ret;
}
ssize_t
iter_file_splice_write(struct pipe_inode_info *pipe, struct file *out,
loff_t *ppos, size_t len, unsigned int flags)
{
struct splice_desc sd = {
.total_len = len,
.flags = flags,
.pos = *ppos,
.u.file = out,
};
int nbufs = pipe->buffers;
struct bio_vec *array = kcalloc(nbufs, sizeof(struct bio_vec),
GFP_KERNEL);
ssize_t ret;
if (unlikely(!array))
return -ENOMEM;
pipe_lock(pipe);
splice_from_pipe_begin(&sd);
while (sd.total_len) {
struct iov_iter from;
size_t left;
int n, idx;
ret = splice_from_pipe_next(pipe, &sd);
if (ret <= 0)
break;
if (unlikely(nbufs < pipe->buffers)) {
kfree(array);
nbufs = pipe->buffers;
array = kcalloc(nbufs, sizeof(struct bio_vec),
GFP_KERNEL);
if (!array) {
ret = -ENOMEM;
break;
}
}
left = sd.total_len;
for (n = 0, idx = pipe->curbuf; left && n < pipe->nrbufs; n++, idx++) {
struct pipe_buffer *buf = pipe->bufs + idx;
size_t this_len = buf->len;
if (this_len > left)
this_len = left;
if (idx == pipe->buffers - 1)
idx = -1;
ret = pipe_buf_confirm(pipe, buf);
if (unlikely(ret)) {
if (ret == -ENODATA)
ret = 0;
goto done;
}
array[n].bv_page = buf->page;
array[n].bv_len = this_len;
array[n].bv_offset = buf->offset;
left -= this_len;
}
iov_iter_bvec(&from, ITER_BVEC | WRITE, array, n,
sd.total_len - left);
ret = vfs_iter_write(out, &from, &sd.pos);
if (ret <= 0)
break;
sd.num_spliced += ret;
sd.total_len -= ret;
*ppos = sd.pos;
while (ret) {
struct pipe_buffer *buf = pipe->bufs + pipe->curbuf;
if (ret >= buf->len) {
ret -= buf->len;
buf->len = 0;
pipe_buf_release(pipe, buf);
pipe->curbuf = (pipe->curbuf + 1) & (pipe->buffers - 1);
pipe->nrbufs--;
if (pipe->files)
sd.need_wakeup = true;
} else {
buf->offset += ret;
buf->len -= ret;
ret = 0;
}
}
}
done:
kfree(array);
splice_from_pipe_end(pipe, &sd);
pipe_unlock(pipe);
if (sd.num_spliced)
ret = sd.num_spliced;
return ret;
}
static int write_pipe_buf(struct pipe_inode_info *pipe, struct pipe_buffer *buf,
struct splice_desc *sd)
{
int ret;
void *data;
loff_t tmp = sd->pos;
data = kmap(buf->page);
ret = __kernel_write(sd->u.file, data + buf->offset, sd->len, &tmp);
kunmap(buf->page);
return ret;
}
static ssize_t default_file_splice_write(struct pipe_inode_info *pipe,
struct file *out, loff_t *ppos,
size_t len, unsigned int flags)
{
ssize_t ret;
ret = splice_from_pipe(pipe, out, ppos, len, flags, write_pipe_buf);
if (ret > 0)
*ppos += ret;
return ret;
}
ssize_t generic_splice_sendpage(struct pipe_inode_info *pipe, struct file *out,
loff_t *ppos, size_t len, unsigned int flags)
{
return splice_from_pipe(pipe, out, ppos, len, flags, pipe_to_sendpage);
}
static long do_splice_from(struct pipe_inode_info *pipe, struct file *out,
loff_t *ppos, size_t len, unsigned int flags)
{
ssize_t (*splice_write)(struct pipe_inode_info *, struct file *,
loff_t *, size_t, unsigned int);
if (out->f_op->splice_write)
splice_write = out->f_op->splice_write;
else
splice_write = default_file_splice_write;
return splice_write(pipe, out, ppos, len, flags);
}
static long do_splice_to(struct file *in, loff_t *ppos,
struct pipe_inode_info *pipe, size_t len,
unsigned int flags)
{
ssize_t (*splice_read)(struct file *, loff_t *,
struct pipe_inode_info *, size_t, unsigned int);
int ret;
if (unlikely(!(in->f_mode & FMODE_READ)))
return -EBADF;
ret = rw_verify_area(READ, in, ppos, len);
if (unlikely(ret < 0))
return ret;
if (unlikely(len > MAX_RW_COUNT))
len = MAX_RW_COUNT;
if (in->f_op->splice_read)
splice_read = in->f_op->splice_read;
else
splice_read = default_file_splice_read;
return splice_read(in, ppos, pipe, len, flags);
}
ssize_t splice_direct_to_actor(struct file *in, struct splice_desc *sd,
splice_direct_actor *actor)
{
struct pipe_inode_info *pipe;
long ret, bytes;
umode_t i_mode;
size_t len;
int i, flags, more;
i_mode = file_inode(in)->i_mode;
if (unlikely(!S_ISREG(i_mode) && !S_ISBLK(i_mode)))
return -EINVAL;
pipe = current->splice_pipe;
if (unlikely(!pipe)) {
pipe = alloc_pipe_info();
if (!pipe)
return -ENOMEM;
pipe->readers = 1;
current->splice_pipe = pipe;
}
ret = 0;
bytes = 0;
len = sd->total_len;
flags = sd->flags;
sd->flags &= ~SPLICE_F_NONBLOCK;
more = sd->flags & SPLICE_F_MORE;
while (len) {
size_t read_len;
loff_t pos = sd->pos, prev_pos = pos;
ret = do_splice_to(in, &pos, pipe, len, flags);
if (unlikely(ret <= 0))
goto out_release;
read_len = ret;
sd->total_len = read_len;
if (read_len < len)
sd->flags |= SPLICE_F_MORE;
else if (!more)
sd->flags &= ~SPLICE_F_MORE;
ret = actor(pipe, sd);
if (unlikely(ret <= 0)) {
sd->pos = prev_pos;
goto out_release;
}
bytes += ret;
len -= ret;
sd->pos = pos;
if (ret < read_len) {
sd->pos = prev_pos + ret;
goto out_release;
}
}
done:
pipe->nrbufs = pipe->curbuf = 0;
file_accessed(in);
return bytes;
out_release:
for (i = 0; i < pipe->buffers; i++) {
struct pipe_buffer *buf = pipe->bufs + i;
if (buf->ops)
pipe_buf_release(pipe, buf);
}
if (!bytes)
bytes = ret;
goto done;
}
static int direct_splice_actor(struct pipe_inode_info *pipe,
struct splice_desc *sd)
{
struct file *file = sd->u.file;
return do_splice_from(pipe, file, sd->opos, sd->total_len,
sd->flags);
}
long do_splice_direct(struct file *in, loff_t *ppos, struct file *out,
loff_t *opos, size_t len, unsigned int flags)
{
struct splice_desc sd = {
.len = len,
.total_len = len,
.flags = flags,
.pos = *ppos,
.u.file = out,
.opos = opos,
};
long ret;
if (unlikely(!(out->f_mode & FMODE_WRITE)))
return -EBADF;
if (unlikely(out->f_flags & O_APPEND))
return -EINVAL;
ret = rw_verify_area(WRITE, out, opos, len);
if (unlikely(ret < 0))
return ret;
ret = splice_direct_to_actor(in, &sd, direct_splice_actor);
if (ret > 0)
*ppos = sd.pos;
return ret;
}
static int wait_for_space(struct pipe_inode_info *pipe, unsigned flags)
{
while (pipe->nrbufs == pipe->buffers) {
if (flags & SPLICE_F_NONBLOCK)
return -EAGAIN;
if (signal_pending(current))
return -ERESTARTSYS;
pipe->waiting_writers++;
pipe_wait(pipe);
pipe->waiting_writers--;
}
return 0;
}
static long do_splice(struct file *in, loff_t __user *off_in,
struct file *out, loff_t __user *off_out,
size_t len, unsigned int flags)
{
struct pipe_inode_info *ipipe;
struct pipe_inode_info *opipe;
loff_t offset;
long ret;
ipipe = get_pipe_info(in);
opipe = get_pipe_info(out);
if (ipipe && opipe) {
if (off_in || off_out)
return -ESPIPE;
if (!(in->f_mode & FMODE_READ))
return -EBADF;
if (!(out->f_mode & FMODE_WRITE))
return -EBADF;
if (ipipe == opipe)
return -EINVAL;
return splice_pipe_to_pipe(ipipe, opipe, len, flags);
}
if (ipipe) {
if (off_in)
return -ESPIPE;
if (off_out) {
if (!(out->f_mode & FMODE_PWRITE))
return -EINVAL;
if (copy_from_user(&offset, off_out, sizeof(loff_t)))
return -EFAULT;
} else {
offset = out->f_pos;
}
if (unlikely(!(out->f_mode & FMODE_WRITE)))
return -EBADF;
if (unlikely(out->f_flags & O_APPEND))
return -EINVAL;
ret = rw_verify_area(WRITE, out, &offset, len);
if (unlikely(ret < 0))
return ret;
file_start_write(out);
ret = do_splice_from(ipipe, out, &offset, len, flags);
file_end_write(out);
if (!off_out)
out->f_pos = offset;
else if (copy_to_user(off_out, &offset, sizeof(loff_t)))
ret = -EFAULT;
return ret;
}
if (opipe) {
if (off_out)
return -ESPIPE;
if (off_in) {
if (!(in->f_mode & FMODE_PREAD))
return -EINVAL;
if (copy_from_user(&offset, off_in, sizeof(loff_t)))
return -EFAULT;
} else {
offset = in->f_pos;
}
pipe_lock(opipe);
ret = wait_for_space(opipe, flags);
if (!ret)
ret = do_splice_to(in, &offset, opipe, len, flags);
pipe_unlock(opipe);
if (ret > 0)
wakeup_pipe_readers(opipe);
if (!off_in)
in->f_pos = offset;
else if (copy_to_user(off_in, &offset, sizeof(loff_t)))
ret = -EFAULT;
return ret;
}
return -EINVAL;
}
static int iter_to_pipe(struct iov_iter *from,
struct pipe_inode_info *pipe,
unsigned flags)
{
struct pipe_buffer buf = {
.ops = &user_page_pipe_buf_ops,
.flags = flags
};
size_t total = 0;
int ret = 0;
bool failed = false;
while (iov_iter_count(from) && !failed) {
struct page *pages[16];
ssize_t copied;
size_t start;
int n;
copied = iov_iter_get_pages(from, pages, ~0UL, 16, &start);
if (copied <= 0) {
ret = copied;
break;
}
for (n = 0; copied; n++, start = 0) {
int size = min_t(int, copied, PAGE_SIZE - start);
if (!failed) {
buf.page = pages[n];
buf.offset = start;
buf.len = size;
ret = add_to_pipe(pipe, &buf);
if (unlikely(ret < 0)) {
failed = true;
} else {
iov_iter_advance(from, ret);
total += ret;
}
} else {
put_page(pages[n]);
}
copied -= size;
}
}
return total ? total : ret;
}
static int pipe_to_user(struct pipe_inode_info *pipe, struct pipe_buffer *buf,
struct splice_desc *sd)
{
int n = copy_page_to_iter(buf->page, buf->offset, sd->len, sd->u.data);
return n == sd->len ? n : -EFAULT;
}
static long vmsplice_to_user(struct file *file, const struct iovec __user *uiov,
unsigned long nr_segs, unsigned int flags)
{
struct pipe_inode_info *pipe;
struct splice_desc sd;
long ret;
struct iovec iovstack[UIO_FASTIOV];
struct iovec *iov = iovstack;
struct iov_iter iter;
pipe = get_pipe_info(file);
if (!pipe)
return -EBADF;
ret = import_iovec(READ, uiov, nr_segs,
ARRAY_SIZE(iovstack), &iov, &iter);
if (ret < 0)
return ret;
sd.total_len = iov_iter_count(&iter);
sd.len = 0;
sd.flags = flags;
sd.u.data = &iter;
sd.pos = 0;
if (sd.total_len) {
pipe_lock(pipe);
ret = __splice_from_pipe(pipe, &sd, pipe_to_user);
pipe_unlock(pipe);
}
kfree(iov);
return ret;
}
static long vmsplice_to_pipe(struct file *file, const struct iovec __user *uiov,
unsigned long nr_segs, unsigned int flags)
{
struct pipe_inode_info *pipe;
struct iovec iovstack[UIO_FASTIOV];
struct iovec *iov = iovstack;
struct iov_iter from;
long ret;
unsigned buf_flag = 0;
if (flags & SPLICE_F_GIFT)
buf_flag = PIPE_BUF_FLAG_GIFT;
pipe = get_pipe_info(file);
if (!pipe)
return -EBADF;
ret = import_iovec(WRITE, uiov, nr_segs,
ARRAY_SIZE(iovstack), &iov, &from);
if (ret < 0)
return ret;
pipe_lock(pipe);
ret = wait_for_space(pipe, flags);
if (!ret)
ret = iter_to_pipe(&from, pipe, buf_flag);
pipe_unlock(pipe);
if (ret > 0)
wakeup_pipe_readers(pipe);
kfree(iov);
return ret;
}
static int ipipe_prep(struct pipe_inode_info *pipe, unsigned int flags)
{
int ret;
if (pipe->nrbufs)
return 0;
ret = 0;
pipe_lock(pipe);
while (!pipe->nrbufs) {
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
if (!pipe->writers)
break;
if (!pipe->waiting_writers) {
if (flags & SPLICE_F_NONBLOCK) {
ret = -EAGAIN;
break;
}
}
pipe_wait(pipe);
}
pipe_unlock(pipe);
return ret;
}
static int opipe_prep(struct pipe_inode_info *pipe, unsigned int flags)
{
int ret;
if (pipe->nrbufs < pipe->buffers)
return 0;
ret = 0;
pipe_lock(pipe);
while (pipe->nrbufs >= pipe->buffers) {
if (!pipe->readers) {
send_sig(SIGPIPE, current, 0);
ret = -EPIPE;
break;
}
if (flags & SPLICE_F_NONBLOCK) {
ret = -EAGAIN;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
pipe->waiting_writers++;
pipe_wait(pipe);
pipe->waiting_writers--;
}
pipe_unlock(pipe);
return ret;
}
static int splice_pipe_to_pipe(struct pipe_inode_info *ipipe,
struct pipe_inode_info *opipe,
size_t len, unsigned int flags)
{
struct pipe_buffer *ibuf, *obuf;
int ret = 0, nbuf;
bool input_wakeup = false;
retry:
ret = ipipe_prep(ipipe, flags);
if (ret)
return ret;
ret = opipe_prep(opipe, flags);
if (ret)
return ret;
pipe_double_lock(ipipe, opipe);
do {
if (!opipe->readers) {
send_sig(SIGPIPE, current, 0);
if (!ret)
ret = -EPIPE;
break;
}
if (!ipipe->nrbufs && !ipipe->writers)
break;
if (!ipipe->nrbufs || opipe->nrbufs >= opipe->buffers) {
if (ret)
break;
if (flags & SPLICE_F_NONBLOCK) {
ret = -EAGAIN;
break;
}
pipe_unlock(ipipe);
pipe_unlock(opipe);
goto retry;
}
ibuf = ipipe->bufs + ipipe->curbuf;
nbuf = (opipe->curbuf + opipe->nrbufs) & (opipe->buffers - 1);
obuf = opipe->bufs + nbuf;
if (len >= ibuf->len) {
*obuf = *ibuf;
ibuf->ops = NULL;
opipe->nrbufs++;
ipipe->curbuf = (ipipe->curbuf + 1) & (ipipe->buffers - 1);
ipipe->nrbufs--;
input_wakeup = true;
} else {
pipe_buf_get(ipipe, ibuf);
*obuf = *ibuf;
obuf->flags &= ~PIPE_BUF_FLAG_GIFT;
obuf->len = len;
opipe->nrbufs++;
ibuf->offset += obuf->len;
ibuf->len -= obuf->len;
}
ret += obuf->len;
len -= obuf->len;
} while (len);
pipe_unlock(ipipe);
pipe_unlock(opipe);
if (ret > 0)
wakeup_pipe_readers(opipe);
if (input_wakeup)
wakeup_pipe_writers(ipipe);
return ret;
}
static int link_pipe(struct pipe_inode_info *ipipe,
struct pipe_inode_info *opipe,
size_t len, unsigned int flags)
{
struct pipe_buffer *ibuf, *obuf;
int ret = 0, i = 0, nbuf;
pipe_double_lock(ipipe, opipe);
do {
if (!opipe->readers) {
send_sig(SIGPIPE, current, 0);
if (!ret)
ret = -EPIPE;
break;
}
if (i >= ipipe->nrbufs || opipe->nrbufs >= opipe->buffers)
break;
ibuf = ipipe->bufs + ((ipipe->curbuf + i) & (ipipe->buffers-1));
nbuf = (opipe->curbuf + opipe->nrbufs) & (opipe->buffers - 1);
pipe_buf_get(ipipe, ibuf);
obuf = opipe->bufs + nbuf;
*obuf = *ibuf;
obuf->flags &= ~PIPE_BUF_FLAG_GIFT;
if (obuf->len > len)
obuf->len = len;
opipe->nrbufs++;
ret += obuf->len;
len -= obuf->len;
i++;
} while (len);
if (!ret && ipipe->waiting_writers && (flags & SPLICE_F_NONBLOCK))
ret = -EAGAIN;
pipe_unlock(ipipe);
pipe_unlock(opipe);
if (ret > 0)
wakeup_pipe_readers(opipe);
return ret;
}
static long do_tee(struct file *in, struct file *out, size_t len,
unsigned int flags)
{
struct pipe_inode_info *ipipe = get_pipe_info(in);
struct pipe_inode_info *opipe = get_pipe_info(out);
int ret = -EINVAL;
if (ipipe && opipe && ipipe != opipe) {
ret = ipipe_prep(ipipe, flags);
if (!ret) {
ret = opipe_prep(opipe, flags);
if (!ret)
ret = link_pipe(ipipe, opipe, len, flags);
}
}
return ret;
}
