static void relay_file_mmap_close(struct vm_area_struct *vma)
{
struct rchan_buf *buf = vma->vm_private_data;
buf->chan->cb->buf_unmapped(buf, vma->vm_file);
}
static int relay_buf_fault(struct vm_fault *vmf)
{
struct page *page;
struct rchan_buf *buf = vmf->vma->vm_private_data;
pgoff_t pgoff = vmf->pgoff;
if (!buf)
return VM_FAULT_OOM;
page = vmalloc_to_page(buf->start + (pgoff << PAGE_SHIFT));
if (!page)
return VM_FAULT_SIGBUS;
get_page(page);
vmf->page = page;
return 0;
}
static struct page **relay_alloc_page_array(unsigned int n_pages)
{
const size_t pa_size = n_pages * sizeof(struct page *);
if (pa_size > PAGE_SIZE)
return vzalloc(pa_size);
return kzalloc(pa_size, GFP_KERNEL);
}
static void relay_free_page_array(struct page **array)
{
kvfree(array);
}
static int relay_mmap_buf(struct rchan_buf *buf, struct vm_area_struct *vma)
{
unsigned long length = vma->vm_end - vma->vm_start;
struct file *filp = vma->vm_file;
if (!buf)
return -EBADF;
if (length != (unsigned long)buf->chan->alloc_size)
return -EINVAL;
vma->vm_ops = &relay_file_mmap_ops;
vma->vm_flags |= VM_DONTEXPAND;
vma->vm_private_data = buf;
buf->chan->cb->buf_mapped(buf, filp);
return 0;
}
static void *relay_alloc_buf(struct rchan_buf *buf, size_t *size)
{
void *mem;
unsigned int i, j, n_pages;
*size = PAGE_ALIGN(*size);
n_pages = *size >> PAGE_SHIFT;
buf->page_array = relay_alloc_page_array(n_pages);
if (!buf->page_array)
return NULL;
for (i = 0; i < n_pages; i++) {
buf->page_array[i] = alloc_page(GFP_KERNEL);
if (unlikely(!buf->page_array[i]))
goto depopulate;
set_page_private(buf->page_array[i], (unsigned long)buf);
}
mem = vmap(buf->page_array, n_pages, VM_MAP, PAGE_KERNEL);
if (!mem)
goto depopulate;
memset(mem, 0, *size);
buf->page_count = n_pages;
return mem;
depopulate:
for (j = 0; j < i; j++)
__free_page(buf->page_array[j]);
relay_free_page_array(buf->page_array);
return NULL;
}
static struct rchan_buf *relay_create_buf(struct rchan *chan)
{
struct rchan_buf *buf;
if (chan->n_subbufs > UINT_MAX / sizeof(size_t *))
return NULL;
buf = kzalloc(sizeof(struct rchan_buf), GFP_KERNEL);
if (!buf)
return NULL;
buf->padding = kmalloc(chan->n_subbufs * sizeof(size_t *), GFP_KERNEL);
if (!buf->padding)
goto free_buf;
buf->start = relay_alloc_buf(buf, &chan->alloc_size);
if (!buf->start)
goto free_buf;
buf->chan = chan;
kref_get(&buf->chan->kref);
return buf;
free_buf:
kfree(buf->padding);
kfree(buf);
return NULL;
}
static void relay_destroy_channel(struct kref *kref)
{
struct rchan *chan = container_of(kref, struct rchan, kref);
kfree(chan);
}
static void relay_destroy_buf(struct rchan_buf *buf)
{
struct rchan *chan = buf->chan;
unsigned int i;
if (likely(buf->start)) {
vunmap(buf->start);
for (i = 0; i < buf->page_count; i++)
__free_page(buf->page_array[i]);
relay_free_page_array(buf->page_array);
}
*per_cpu_ptr(chan->buf, buf->cpu) = NULL;
kfree(buf->padding);
kfree(buf);
kref_put(&chan->kref, relay_destroy_channel);
}
static void relay_remove_buf(struct kref *kref)
{
struct rchan_buf *buf = container_of(kref, struct rchan_buf, kref);
relay_destroy_buf(buf);
}
static int relay_buf_empty(struct rchan_buf *buf)
{
return (buf->subbufs_produced - buf->subbufs_consumed) ? 0 : 1;
}
int relay_buf_full(struct rchan_buf *buf)
{
size_t ready = buf->subbufs_produced - buf->subbufs_consumed;
return (ready >= buf->chan->n_subbufs) ? 1 : 0;
}
static int subbuf_start_default_callback (struct rchan_buf *buf,
void *subbuf,
void *prev_subbuf,
size_t prev_padding)
{
if (relay_buf_full(buf))
return 0;
return 1;
}
static void buf_mapped_default_callback(struct rchan_buf *buf,
struct file *filp)
{
}
static void buf_unmapped_default_callback(struct rchan_buf *buf,
struct file *filp)
{
}
static struct dentry *create_buf_file_default_callback(const char *filename,
struct dentry *parent,
umode_t mode,
struct rchan_buf *buf,
int *is_global)
{
return NULL;
}
static int remove_buf_file_default_callback(struct dentry *dentry)
{
return -EINVAL;
}
static void wakeup_readers(struct irq_work *work)
{
struct rchan_buf *buf;
buf = container_of(work, struct rchan_buf, wakeup_work);
wake_up_interruptible(&buf->read_wait);
}
static void __relay_reset(struct rchan_buf *buf, unsigned int init)
{
size_t i;
if (init) {
init_waitqueue_head(&buf->read_wait);
kref_init(&buf->kref);
init_irq_work(&buf->wakeup_work, wakeup_readers);
} else {
irq_work_sync(&buf->wakeup_work);
}
buf->subbufs_produced = 0;
buf->subbufs_consumed = 0;
buf->bytes_consumed = 0;
buf->finalized = 0;
buf->data = buf->start;
buf->offset = 0;
for (i = 0; i < buf->chan->n_subbufs; i++)
buf->padding[i] = 0;
buf->chan->cb->subbuf_start(buf, buf->data, NULL, 0);
}
void relay_reset(struct rchan *chan)
{
struct rchan_buf *buf;
unsigned int i;
if (!chan)
return;
if (chan->is_global && (buf = *per_cpu_ptr(chan->buf, 0))) {
__relay_reset(buf, 0);
return;
}
mutex_lock(&relay_channels_mutex);
for_each_possible_cpu(i)
if ((buf = *per_cpu_ptr(chan->buf, i)))
__relay_reset(buf, 0);
mutex_unlock(&relay_channels_mutex);
}
static inline void relay_set_buf_dentry(struct rchan_buf *buf,
struct dentry *dentry)
{
buf->dentry = dentry;
d_inode(buf->dentry)->i_size = buf->early_bytes;
}
static struct dentry *relay_create_buf_file(struct rchan *chan,
struct rchan_buf *buf,
unsigned int cpu)
{
struct dentry *dentry;
char *tmpname;
tmpname = kzalloc(NAME_MAX + 1, GFP_KERNEL);
if (!tmpname)
return NULL;
snprintf(tmpname, NAME_MAX, "%s%d", chan->base_filename, cpu);
dentry = chan->cb->create_buf_file(tmpname, chan->parent,
S_IRUSR, buf,
&chan->is_global);
kfree(tmpname);
return dentry;
}
static struct rchan_buf *relay_open_buf(struct rchan *chan, unsigned int cpu)
{
struct rchan_buf *buf = NULL;
struct dentry *dentry;
if (chan->is_global)
return *per_cpu_ptr(chan->buf, 0);
buf = relay_create_buf(chan);
if (!buf)
return NULL;
if (chan->has_base_filename) {
dentry = relay_create_buf_file(chan, buf, cpu);
if (!dentry)
goto free_buf;
relay_set_buf_dentry(buf, dentry);
} else {
dentry = chan->cb->create_buf_file(NULL, NULL,
S_IRUSR, buf,
&chan->is_global);
if (WARN_ON(dentry))
goto free_buf;
}
buf->cpu = cpu;
__relay_reset(buf, 1);
if(chan->is_global) {
*per_cpu_ptr(chan->buf, 0) = buf;
buf->cpu = 0;
}
return buf;
free_buf:
relay_destroy_buf(buf);
return NULL;
}
static void relay_close_buf(struct rchan_buf *buf)
{
buf->finalized = 1;
irq_work_sync(&buf->wakeup_work);
buf->chan->cb->remove_buf_file(buf->dentry);
kref_put(&buf->kref, relay_remove_buf);
}
static void setup_callbacks(struct rchan *chan,
struct rchan_callbacks *cb)
{
if (!cb) {
chan->cb = &default_channel_callbacks;
return;
}
if (!cb->subbuf_start)
cb->subbuf_start = subbuf_start_default_callback;
if (!cb->buf_mapped)
cb->buf_mapped = buf_mapped_default_callback;
if (!cb->buf_unmapped)
cb->buf_unmapped = buf_unmapped_default_callback;
if (!cb->create_buf_file)
cb->create_buf_file = create_buf_file_default_callback;
if (!cb->remove_buf_file)
cb->remove_buf_file = remove_buf_file_default_callback;
chan->cb = cb;
}
int relay_prepare_cpu(unsigned int cpu)
{
struct rchan *chan;
struct rchan_buf *buf;
mutex_lock(&relay_channels_mutex);
list_for_each_entry(chan, &relay_channels, list) {
if ((buf = *per_cpu_ptr(chan->buf, cpu)))
continue;
buf = relay_open_buf(chan, cpu);
if (!buf) {
pr_err("relay: cpu %d buffer creation failed\n", cpu);
mutex_unlock(&relay_channels_mutex);
return -ENOMEM;
}
*per_cpu_ptr(chan->buf, cpu) = buf;
}
mutex_unlock(&relay_channels_mutex);
return 0;
}
struct rchan *relay_open(const char *base_filename,
struct dentry *parent,
size_t subbuf_size,
size_t n_subbufs,
struct rchan_callbacks *cb,
void *private_data)
{
unsigned int i;
struct rchan *chan;
struct rchan_buf *buf;
if (!(subbuf_size && n_subbufs))
return NULL;
if (subbuf_size > UINT_MAX / n_subbufs)
return NULL;
chan = kzalloc(sizeof(struct rchan), GFP_KERNEL);
if (!chan)
return NULL;
chan->buf = alloc_percpu(struct rchan_buf *);
chan->version = RELAYFS_CHANNEL_VERSION;
chan->n_subbufs = n_subbufs;
chan->subbuf_size = subbuf_size;
chan->alloc_size = PAGE_ALIGN(subbuf_size * n_subbufs);
chan->parent = parent;
chan->private_data = private_data;
if (base_filename) {
chan->has_base_filename = 1;
strlcpy(chan->base_filename, base_filename, NAME_MAX);
}
setup_callbacks(chan, cb);
kref_init(&chan->kref);
mutex_lock(&relay_channels_mutex);
for_each_online_cpu(i) {
buf = relay_open_buf(chan, i);
if (!buf)
goto free_bufs;
*per_cpu_ptr(chan->buf, i) = buf;
}
list_add(&chan->list, &relay_channels);
mutex_unlock(&relay_channels_mutex);
return chan;
free_bufs:
for_each_possible_cpu(i) {
if ((buf = *per_cpu_ptr(chan->buf, i)))
relay_close_buf(buf);
}
kref_put(&chan->kref, relay_destroy_channel);
mutex_unlock(&relay_channels_mutex);
kfree(chan);
return NULL;
}
static void __relay_set_buf_dentry(void *info)
{
struct rchan_percpu_buf_dispatcher *p = info;
relay_set_buf_dentry(p->buf, p->dentry);
}
int relay_late_setup_files(struct rchan *chan,
const char *base_filename,
struct dentry *parent)
{
int err = 0;
unsigned int i, curr_cpu;
unsigned long flags;
struct dentry *dentry;
struct rchan_buf *buf;
struct rchan_percpu_buf_dispatcher disp;
if (!chan || !base_filename)
return -EINVAL;
strlcpy(chan->base_filename, base_filename, NAME_MAX);
mutex_lock(&relay_channels_mutex);
if (unlikely(chan->has_base_filename)) {
mutex_unlock(&relay_channels_mutex);
return -EEXIST;
}
chan->has_base_filename = 1;
chan->parent = parent;
if (chan->is_global) {
err = -EINVAL;
buf = *per_cpu_ptr(chan->buf, 0);
if (!WARN_ON_ONCE(!buf)) {
dentry = relay_create_buf_file(chan, buf, 0);
if (dentry && !WARN_ON_ONCE(!chan->is_global)) {
relay_set_buf_dentry(buf, dentry);
err = 0;
}
}
mutex_unlock(&relay_channels_mutex);
return err;
}
curr_cpu = get_cpu();
for_each_online_cpu(i) {
buf = *per_cpu_ptr(chan->buf, i);
if (unlikely(!buf)) {
WARN_ONCE(1, KERN_ERR "CPU has no buffer!\n");
err = -EINVAL;
break;
}
dentry = relay_create_buf_file(chan, buf, i);
if (unlikely(!dentry)) {
err = -EINVAL;
break;
}
if (curr_cpu == i) {
local_irq_save(flags);
relay_set_buf_dentry(buf, dentry);
local_irq_restore(flags);
} else {
disp.buf = buf;
disp.dentry = dentry;
smp_mb();
err = smp_call_function_single(i,
__relay_set_buf_dentry,
&disp, 1);
}
if (unlikely(err))
break;
}
put_cpu();
mutex_unlock(&relay_channels_mutex);
return err;
}
size_t relay_switch_subbuf(struct rchan_buf *buf, size_t length)
{
void *old, *new;
size_t old_subbuf, new_subbuf;
if (unlikely(length > buf->chan->subbuf_size))
goto toobig;
if (buf->offset != buf->chan->subbuf_size + 1) {
buf->prev_padding = buf->chan->subbuf_size - buf->offset;
old_subbuf = buf->subbufs_produced % buf->chan->n_subbufs;
buf->padding[old_subbuf] = buf->prev_padding;
buf->subbufs_produced++;
if (buf->dentry)
d_inode(buf->dentry)->i_size +=
buf->chan->subbuf_size -
buf->padding[old_subbuf];
else
buf->early_bytes += buf->chan->subbuf_size -
buf->padding[old_subbuf];
smp_mb();
if (waitqueue_active(&buf->read_wait)) {
irq_work_queue(&buf->wakeup_work);
}
}
old = buf->data;
new_subbuf = buf->subbufs_produced % buf->chan->n_subbufs;
new = buf->start + new_subbuf * buf->chan->subbuf_size;
buf->offset = 0;
if (!buf->chan->cb->subbuf_start(buf, new, old, buf->prev_padding)) {
buf->offset = buf->chan->subbuf_size + 1;
return 0;
}
buf->data = new;
buf->padding[new_subbuf] = 0;
if (unlikely(length + buf->offset > buf->chan->subbuf_size))
goto toobig;
return length;
toobig:
buf->chan->last_toobig = length;
return 0;
}
void relay_subbufs_consumed(struct rchan *chan,
unsigned int cpu,
size_t subbufs_consumed)
{
struct rchan_buf *buf;
if (!chan || cpu >= NR_CPUS)
return;
buf = *per_cpu_ptr(chan->buf, cpu);
if (!buf || subbufs_consumed > chan->n_subbufs)
return;
if (subbufs_consumed > buf->subbufs_produced - buf->subbufs_consumed)
buf->subbufs_consumed = buf->subbufs_produced;
else
buf->subbufs_consumed += subbufs_consumed;
}
void relay_close(struct rchan *chan)
{
struct rchan_buf *buf;
unsigned int i;
if (!chan)
return;
mutex_lock(&relay_channels_mutex);
if (chan->is_global && (buf = *per_cpu_ptr(chan->buf, 0)))
relay_close_buf(buf);
else
for_each_possible_cpu(i)
if ((buf = *per_cpu_ptr(chan->buf, i)))
relay_close_buf(buf);
if (chan->last_toobig)
printk(KERN_WARNING "relay: one or more items not logged "
"[item size (%zd) > sub-buffer size (%zd)]\n",
chan->last_toobig, chan->subbuf_size);
list_del(&chan->list);
kref_put(&chan->kref, relay_destroy_channel);
mutex_unlock(&relay_channels_mutex);
}
void relay_flush(struct rchan *chan)
{
struct rchan_buf *buf;
unsigned int i;
if (!chan)
return;
if (chan->is_global && (buf = *per_cpu_ptr(chan->buf, 0))) {
relay_switch_subbuf(buf, 0);
return;
}
mutex_lock(&relay_channels_mutex);
for_each_possible_cpu(i)
if ((buf = *per_cpu_ptr(chan->buf, i)))
relay_switch_subbuf(buf, 0);
mutex_unlock(&relay_channels_mutex);
}
static int relay_file_open(struct inode *inode, struct file *filp)
{
struct rchan_buf *buf = inode->i_private;
kref_get(&buf->kref);
filp->private_data = buf;
return nonseekable_open(inode, filp);
}
static int relay_file_mmap(struct file *filp, struct vm_area_struct *vma)
{
struct rchan_buf *buf = filp->private_data;
return relay_mmap_buf(buf, vma);
}
static unsigned int relay_file_poll(struct file *filp, poll_table *wait)
{
unsigned int mask = 0;
struct rchan_buf *buf = filp->private_data;
if (buf->finalized)
return POLLERR;
if (filp->f_mode & FMODE_READ) {
poll_wait(filp, &buf->read_wait, wait);
if (!relay_buf_empty(buf))
mask |= POLLIN | POLLRDNORM;
}
return mask;
}
static int relay_file_release(struct inode *inode, struct file *filp)
{
struct rchan_buf *buf = filp->private_data;
kref_put(&buf->kref, relay_remove_buf);
return 0;
}
static void relay_file_read_consume(struct rchan_buf *buf,
size_t read_pos,
size_t bytes_consumed)
{
size_t subbuf_size = buf->chan->subbuf_size;
size_t n_subbufs = buf->chan->n_subbufs;
size_t read_subbuf;
if (buf->subbufs_produced == buf->subbufs_consumed &&
buf->offset == buf->bytes_consumed)
return;
if (buf->bytes_consumed + bytes_consumed > subbuf_size) {
relay_subbufs_consumed(buf->chan, buf->cpu, 1);
buf->bytes_consumed = 0;
}
buf->bytes_consumed += bytes_consumed;
if (!read_pos)
read_subbuf = buf->subbufs_consumed % n_subbufs;
else
read_subbuf = read_pos / buf->chan->subbuf_size;
if (buf->bytes_consumed + buf->padding[read_subbuf] == subbuf_size) {
if ((read_subbuf == buf->subbufs_produced % n_subbufs) &&
(buf->offset == subbuf_size))
return;
relay_subbufs_consumed(buf->chan, buf->cpu, 1);
buf->bytes_consumed = 0;
}
}
static int relay_file_read_avail(struct rchan_buf *buf, size_t read_pos)
{
size_t subbuf_size = buf->chan->subbuf_size;
size_t n_subbufs = buf->chan->n_subbufs;
size_t produced = buf->subbufs_produced;
size_t consumed = buf->subbufs_consumed;
relay_file_read_consume(buf, read_pos, 0);
consumed = buf->subbufs_consumed;
if (unlikely(buf->offset > subbuf_size)) {
if (produced == consumed)
return 0;
return 1;
}
if (unlikely(produced - consumed >= n_subbufs)) {
consumed = produced - n_subbufs + 1;
buf->subbufs_consumed = consumed;
buf->bytes_consumed = 0;
}
produced = (produced % n_subbufs) * subbuf_size + buf->offset;
consumed = (consumed % n_subbufs) * subbuf_size + buf->bytes_consumed;
if (consumed > produced)
produced += n_subbufs * subbuf_size;
if (consumed == produced) {
if (buf->offset == subbuf_size &&
buf->subbufs_produced > buf->subbufs_consumed)
return 1;
return 0;
}
return 1;
}
static size_t relay_file_read_subbuf_avail(size_t read_pos,
struct rchan_buf *buf)
{
size_t padding, avail = 0;
size_t read_subbuf, read_offset, write_subbuf, write_offset;
size_t subbuf_size = buf->chan->subbuf_size;
write_subbuf = (buf->data - buf->start) / subbuf_size;
write_offset = buf->offset > subbuf_size ? subbuf_size : buf->offset;
read_subbuf = read_pos / subbuf_size;
read_offset = read_pos % subbuf_size;
padding = buf->padding[read_subbuf];
if (read_subbuf == write_subbuf) {
if (read_offset + padding < write_offset)
avail = write_offset - (read_offset + padding);
} else
avail = (subbuf_size - padding) - read_offset;
return avail;
}
static size_t relay_file_read_start_pos(size_t read_pos,
struct rchan_buf *buf)
{
size_t read_subbuf, padding, padding_start, padding_end;
size_t subbuf_size = buf->chan->subbuf_size;
size_t n_subbufs = buf->chan->n_subbufs;
size_t consumed = buf->subbufs_consumed % n_subbufs;
if (!read_pos)
read_pos = consumed * subbuf_size + buf->bytes_consumed;
read_subbuf = read_pos / subbuf_size;
padding = buf->padding[read_subbuf];
padding_start = (read_subbuf + 1) * subbuf_size - padding;
padding_end = (read_subbuf + 1) * subbuf_size;
if (read_pos >= padding_start && read_pos < padding_end) {
read_subbuf = (read_subbuf + 1) % n_subbufs;
read_pos = read_subbuf * subbuf_size;
}
return read_pos;
}
static size_t relay_file_read_end_pos(struct rchan_buf *buf,
size_t read_pos,
size_t count)
{
size_t read_subbuf, padding, end_pos;
size_t subbuf_size = buf->chan->subbuf_size;
size_t n_subbufs = buf->chan->n_subbufs;
read_subbuf = read_pos / subbuf_size;
padding = buf->padding[read_subbuf];
if (read_pos % subbuf_size + count + padding == subbuf_size)
end_pos = (read_subbuf + 1) * subbuf_size;
else
end_pos = read_pos + count;
if (end_pos >= subbuf_size * n_subbufs)
end_pos = 0;
return end_pos;
}
static ssize_t relay_file_read(struct file *filp,
char __user *buffer,
size_t count,
loff_t *ppos)
{
struct rchan_buf *buf = filp->private_data;
size_t read_start, avail;
size_t written = 0;
int ret;
if (!count)
return 0;
inode_lock(file_inode(filp));
do {
void *from;
if (!relay_file_read_avail(buf, *ppos))
break;
read_start = relay_file_read_start_pos(*ppos, buf);
avail = relay_file_read_subbuf_avail(read_start, buf);
if (!avail)
break;
avail = min(count, avail);
from = buf->start + read_start;
ret = avail;
if (copy_to_user(buffer, from, avail))
break;
buffer += ret;
written += ret;
count -= ret;
relay_file_read_consume(buf, read_start, ret);
*ppos = relay_file_read_end_pos(buf, read_start, ret);
} while (count);
inode_unlock(file_inode(filp));
return written;
}
static void relay_consume_bytes(struct rchan_buf *rbuf, int bytes_consumed)
{
rbuf->bytes_consumed += bytes_consumed;
if (rbuf->bytes_consumed >= rbuf->chan->subbuf_size) {
relay_subbufs_consumed(rbuf->chan, rbuf->cpu, 1);
rbuf->bytes_consumed %= rbuf->chan->subbuf_size;
}
}
static void relay_pipe_buf_release(struct pipe_inode_info *pipe,
struct pipe_buffer *buf)
{
struct rchan_buf *rbuf;
rbuf = (struct rchan_buf *)page_private(buf->page);
relay_consume_bytes(rbuf, buf->private);
}
static void relay_page_release(struct splice_pipe_desc *spd, unsigned int i)
{
}
static ssize_t subbuf_splice_actor(struct file *in,
loff_t *ppos,
struct pipe_inode_info *pipe,
size_t len,
unsigned int flags,
int *nonpad_ret)
{
unsigned int pidx, poff, total_len, subbuf_pages, nr_pages;
struct rchan_buf *rbuf = in->private_data;
unsigned int subbuf_size = rbuf->chan->subbuf_size;
uint64_t pos = (uint64_t) *ppos;
uint32_t alloc_size = (uint32_t) rbuf->chan->alloc_size;
size_t read_start = (size_t) do_div(pos, alloc_size);
size_t read_subbuf = read_start / subbuf_size;
size_t padding = rbuf->padding[read_subbuf];
size_t nonpad_end = read_subbuf * subbuf_size + subbuf_size - padding;
struct page *pages[PIPE_DEF_BUFFERS];
struct partial_page partial[PIPE_DEF_BUFFERS];
struct splice_pipe_desc spd = {
.pages = pages,
.nr_pages = 0,
.nr_pages_max = PIPE_DEF_BUFFERS,
.partial = partial,
.flags = flags,
.ops = &relay_pipe_buf_ops,
.spd_release = relay_page_release,
};
ssize_t ret;
if (rbuf->subbufs_produced == rbuf->subbufs_consumed)
return 0;
if (splice_grow_spd(pipe, &spd))
return -ENOMEM;
if (len > (subbuf_size - read_start % subbuf_size))
len = subbuf_size - read_start % subbuf_size;
subbuf_pages = rbuf->chan->alloc_size >> PAGE_SHIFT;
pidx = (read_start / PAGE_SIZE) % subbuf_pages;
poff = read_start & ~PAGE_MASK;
nr_pages = min_t(unsigned int, subbuf_pages, spd.nr_pages_max);
for (total_len = 0; spd.nr_pages < nr_pages; spd.nr_pages++) {
unsigned int this_len, this_end, private;
unsigned int cur_pos = read_start + total_len;
if (!len)
break;
this_len = min_t(unsigned long, len, PAGE_SIZE - poff);
private = this_len;
spd.pages[spd.nr_pages] = rbuf->page_array[pidx];
spd.partial[spd.nr_pages].offset = poff;
this_end = cur_pos + this_len;
if (this_end >= nonpad_end) {
this_len = nonpad_end - cur_pos;
private = this_len + padding;
}
spd.partial[spd.nr_pages].len = this_len;
spd.partial[spd.nr_pages].private = private;
len -= this_len;
total_len += this_len;
poff = 0;
pidx = (pidx + 1) % subbuf_pages;
if (this_end >= nonpad_end) {
spd.nr_pages++;
break;
}
}
ret = 0;
if (!spd.nr_pages)
goto out;
ret = *nonpad_ret = splice_to_pipe(pipe, &spd);
if (ret < 0 || ret < total_len)
goto out;
if (read_start + ret == nonpad_end)
ret += padding;
out:
splice_shrink_spd(&spd);
return ret;
}
static ssize_t relay_file_splice_read(struct file *in,
loff_t *ppos,
struct pipe_inode_info *pipe,
size_t len,
unsigned int flags)
{
ssize_t spliced;
int ret;
int nonpad_ret = 0;
ret = 0;
spliced = 0;
while (len && !spliced) {
ret = subbuf_splice_actor(in, ppos, pipe, len, flags, &nonpad_ret);
if (ret < 0)
break;
else if (!ret) {
if (flags & SPLICE_F_NONBLOCK)
ret = -EAGAIN;
break;
}
*ppos += ret;
if (ret > len)
len = 0;
else
len -= ret;
spliced += nonpad_ret;
nonpad_ret = 0;
}
if (spliced)
return spliced;
return ret;
}
