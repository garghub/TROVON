static struct ffs_function *ffs_func_from_usb(struct usb_function *f)
{
return container_of(f, struct ffs_function, function);
}
static inline enum ffs_setup_state
ffs_setup_state_clear_cancelled(struct ffs_data *ffs)
{
return (enum ffs_setup_state)
cmpxchg(&ffs->setup_state, FFS_SETUP_CANCELLED, FFS_NO_SETUP);
}
static void ffs_ep0_complete(struct usb_ep *ep, struct usb_request *req)
{
struct ffs_data *ffs = req->context;
complete_all(&ffs->ep0req_completion);
}
static int __ffs_ep0_queue_wait(struct ffs_data *ffs, char *data, size_t len)
{
struct usb_request *req = ffs->ep0req;
int ret;
req->zero = len < le16_to_cpu(ffs->ev.setup.wLength);
spin_unlock_irq(&ffs->ev.waitq.lock);
req->buf = data;
req->length = len;
if (req->buf == NULL)
req->buf = (void *)0xDEADBABE;
reinit_completion(&ffs->ep0req_completion);
ret = usb_ep_queue(ffs->gadget->ep0, req, GFP_ATOMIC);
if (unlikely(ret < 0))
return ret;
ret = wait_for_completion_interruptible(&ffs->ep0req_completion);
if (unlikely(ret)) {
usb_ep_dequeue(ffs->gadget->ep0, req);
return -EINTR;
}
ffs->setup_state = FFS_NO_SETUP;
return req->status ? req->status : req->actual;
}
static int __ffs_ep0_stall(struct ffs_data *ffs)
{
if (ffs->ev.can_stall) {
pr_vdebug("ep0 stall\n");
usb_ep_set_halt(ffs->gadget->ep0);
ffs->setup_state = FFS_NO_SETUP;
return -EL2HLT;
} else {
pr_debug("bogus ep0 stall!\n");
return -ESRCH;
}
}
static ssize_t ffs_ep0_write(struct file *file, const char __user *buf,
size_t len, loff_t *ptr)
{
struct ffs_data *ffs = file->private_data;
ssize_t ret;
char *data;
ENTER();
if (ffs_setup_state_clear_cancelled(ffs) == FFS_SETUP_CANCELLED)
return -EIDRM;
ret = ffs_mutex_lock(&ffs->mutex, file->f_flags & O_NONBLOCK);
if (unlikely(ret < 0))
return ret;
switch (ffs->state) {
case FFS_READ_DESCRIPTORS:
case FFS_READ_STRINGS:
if (unlikely(len < 16)) {
ret = -EINVAL;
break;
}
data = ffs_prepare_buffer(buf, len);
if (IS_ERR(data)) {
ret = PTR_ERR(data);
break;
}
if (ffs->state == FFS_READ_DESCRIPTORS) {
pr_info("read descriptors\n");
ret = __ffs_data_got_descs(ffs, data, len);
if (unlikely(ret < 0))
break;
ffs->state = FFS_READ_STRINGS;
ret = len;
} else {
pr_info("read strings\n");
ret = __ffs_data_got_strings(ffs, data, len);
if (unlikely(ret < 0))
break;
ret = ffs_epfiles_create(ffs);
if (unlikely(ret)) {
ffs->state = FFS_CLOSING;
break;
}
ffs->state = FFS_ACTIVE;
mutex_unlock(&ffs->mutex);
ret = ffs_ready(ffs);
if (unlikely(ret < 0)) {
ffs->state = FFS_CLOSING;
return ret;
}
set_bit(FFS_FL_CALL_CLOSED_CALLBACK, &ffs->flags);
return len;
}
break;
case FFS_ACTIVE:
data = NULL;
spin_lock_irq(&ffs->ev.waitq.lock);
switch (ffs_setup_state_clear_cancelled(ffs)) {
case FFS_SETUP_CANCELLED:
ret = -EIDRM;
goto done_spin;
case FFS_NO_SETUP:
ret = -ESRCH;
goto done_spin;
case FFS_SETUP_PENDING:
break;
}
if (!(ffs->ev.setup.bRequestType & USB_DIR_IN)) {
spin_unlock_irq(&ffs->ev.waitq.lock);
ret = __ffs_ep0_stall(ffs);
break;
}
len = min(len, (size_t)le16_to_cpu(ffs->ev.setup.wLength));
spin_unlock_irq(&ffs->ev.waitq.lock);
data = ffs_prepare_buffer(buf, len);
if (IS_ERR(data)) {
ret = PTR_ERR(data);
break;
}
spin_lock_irq(&ffs->ev.waitq.lock);
if (ffs_setup_state_clear_cancelled(ffs) ==
FFS_SETUP_CANCELLED) {
ret = -EIDRM;
done_spin:
spin_unlock_irq(&ffs->ev.waitq.lock);
} else {
ret = __ffs_ep0_queue_wait(ffs, data, len);
}
kfree(data);
break;
default:
ret = -EBADFD;
break;
}
mutex_unlock(&ffs->mutex);
return ret;
}
static ssize_t __ffs_ep0_read_events(struct ffs_data *ffs, char __user *buf,
size_t n)
{
struct usb_functionfs_event events[n];
unsigned i = 0;
memset(events, 0, sizeof events);
do {
events[i].type = ffs->ev.types[i];
if (events[i].type == FUNCTIONFS_SETUP) {
events[i].u.setup = ffs->ev.setup;
ffs->setup_state = FFS_SETUP_PENDING;
}
} while (++i < n);
if (n < ffs->ev.count) {
ffs->ev.count -= n;
memmove(ffs->ev.types, ffs->ev.types + n,
ffs->ev.count * sizeof *ffs->ev.types);
} else {
ffs->ev.count = 0;
}
spin_unlock_irq(&ffs->ev.waitq.lock);
mutex_unlock(&ffs->mutex);
return unlikely(__copy_to_user(buf, events, sizeof events))
? -EFAULT : sizeof events;
}
static ssize_t ffs_ep0_read(struct file *file, char __user *buf,
size_t len, loff_t *ptr)
{
struct ffs_data *ffs = file->private_data;
char *data = NULL;
size_t n;
int ret;
ENTER();
if (ffs_setup_state_clear_cancelled(ffs) == FFS_SETUP_CANCELLED)
return -EIDRM;
ret = ffs_mutex_lock(&ffs->mutex, file->f_flags & O_NONBLOCK);
if (unlikely(ret < 0))
return ret;
if (ffs->state != FFS_ACTIVE) {
ret = -EBADFD;
goto done_mutex;
}
spin_lock_irq(&ffs->ev.waitq.lock);
switch (ffs_setup_state_clear_cancelled(ffs)) {
case FFS_SETUP_CANCELLED:
ret = -EIDRM;
break;
case FFS_NO_SETUP:
n = len / sizeof(struct usb_functionfs_event);
if (unlikely(!n)) {
ret = -EINVAL;
break;
}
if ((file->f_flags & O_NONBLOCK) && !ffs->ev.count) {
ret = -EAGAIN;
break;
}
if (wait_event_interruptible_exclusive_locked_irq(ffs->ev.waitq,
ffs->ev.count)) {
ret = -EINTR;
break;
}
return __ffs_ep0_read_events(ffs, buf,
min(n, (size_t)ffs->ev.count));
case FFS_SETUP_PENDING:
if (ffs->ev.setup.bRequestType & USB_DIR_IN) {
spin_unlock_irq(&ffs->ev.waitq.lock);
ret = __ffs_ep0_stall(ffs);
goto done_mutex;
}
len = min(len, (size_t)le16_to_cpu(ffs->ev.setup.wLength));
spin_unlock_irq(&ffs->ev.waitq.lock);
if (likely(len)) {
data = kmalloc(len, GFP_KERNEL);
if (unlikely(!data)) {
ret = -ENOMEM;
goto done_mutex;
}
}
spin_lock_irq(&ffs->ev.waitq.lock);
if (ffs_setup_state_clear_cancelled(ffs) ==
FFS_SETUP_CANCELLED) {
ret = -EIDRM;
break;
}
ret = __ffs_ep0_queue_wait(ffs, data, len);
if (likely(ret > 0) && unlikely(__copy_to_user(buf, data, len)))
ret = -EFAULT;
goto done_mutex;
default:
ret = -EBADFD;
break;
}
spin_unlock_irq(&ffs->ev.waitq.lock);
done_mutex:
mutex_unlock(&ffs->mutex);
kfree(data);
return ret;
}
static int ffs_ep0_open(struct inode *inode, struct file *file)
{
struct ffs_data *ffs = inode->i_private;
ENTER();
if (unlikely(ffs->state == FFS_CLOSING))
return -EBUSY;
file->private_data = ffs;
ffs_data_opened(ffs);
return 0;
}
static int ffs_ep0_release(struct inode *inode, struct file *file)
{
struct ffs_data *ffs = file->private_data;
ENTER();
ffs_data_closed(ffs);
return 0;
}
static long ffs_ep0_ioctl(struct file *file, unsigned code, unsigned long value)
{
struct ffs_data *ffs = file->private_data;
struct usb_gadget *gadget = ffs->gadget;
long ret;
ENTER();
if (code == FUNCTIONFS_INTERFACE_REVMAP) {
struct ffs_function *func = ffs->func;
ret = func ? ffs_func_revmap_intf(func, value) : -ENODEV;
} else if (gadget && gadget->ops->ioctl) {
ret = gadget->ops->ioctl(gadget, code, value);
} else {
ret = -ENOTTY;
}
return ret;
}
static unsigned int ffs_ep0_poll(struct file *file, poll_table *wait)
{
struct ffs_data *ffs = file->private_data;
unsigned int mask = POLLWRNORM;
int ret;
poll_wait(file, &ffs->ev.waitq, wait);
ret = ffs_mutex_lock(&ffs->mutex, file->f_flags & O_NONBLOCK);
if (unlikely(ret < 0))
return mask;
switch (ffs->state) {
case FFS_READ_DESCRIPTORS:
case FFS_READ_STRINGS:
mask |= POLLOUT;
break;
case FFS_ACTIVE:
switch (ffs->setup_state) {
case FFS_NO_SETUP:
if (ffs->ev.count)
mask |= POLLIN;
break;
case FFS_SETUP_PENDING:
case FFS_SETUP_CANCELLED:
mask |= (POLLIN | POLLOUT);
break;
}
case FFS_CLOSING:
break;
}
mutex_unlock(&ffs->mutex);
return mask;
}
static void ffs_epfile_io_complete(struct usb_ep *_ep, struct usb_request *req)
{
ENTER();
if (likely(req->context)) {
struct ffs_ep *ep = _ep->driver_data;
ep->status = req->status ? req->status : req->actual;
complete(req->context);
}
}
static void ffs_user_copy_worker(struct work_struct *work)
{
struct ffs_io_data *io_data = container_of(work, struct ffs_io_data,
work);
int ret = io_data->req->status ? io_data->req->status :
io_data->req->actual;
if (io_data->read && ret > 0) {
int i;
size_t pos = 0;
use_mm(io_data->mm);
for (i = 0; i < io_data->nr_segs; i++) {
if (unlikely(copy_to_user(io_data->iovec[i].iov_base,
&io_data->buf[pos],
io_data->iovec[i].iov_len))) {
ret = -EFAULT;
break;
}
pos += io_data->iovec[i].iov_len;
}
unuse_mm(io_data->mm);
}
aio_complete(io_data->kiocb, ret, ret);
usb_ep_free_request(io_data->ep, io_data->req);
io_data->kiocb->private = NULL;
if (io_data->read)
kfree(io_data->iovec);
kfree(io_data->buf);
kfree(io_data);
}
static void ffs_epfile_async_io_complete(struct usb_ep *_ep,
struct usb_request *req)
{
struct ffs_io_data *io_data = req->context;
ENTER();
INIT_WORK(&io_data->work, ffs_user_copy_worker);
schedule_work(&io_data->work);
}
static ssize_t ffs_epfile_io(struct file *file, struct ffs_io_data *io_data)
{
struct ffs_epfile *epfile = file->private_data;
struct ffs_ep *ep;
char *data = NULL;
ssize_t ret, data_len;
int halt;
if (WARN_ON(epfile->ffs->state != FFS_ACTIVE)) {
ret = -ENODEV;
goto error;
}
ep = epfile->ep;
if (!ep) {
if (file->f_flags & O_NONBLOCK) {
ret = -EAGAIN;
goto error;
}
ret = wait_event_interruptible(epfile->wait, (ep = epfile->ep));
if (ret) {
ret = -EINTR;
goto error;
}
}
halt = (!io_data->read == !epfile->in);
if (halt && epfile->isoc) {
ret = -EINVAL;
goto error;
}
if (!halt) {
struct usb_gadget *gadget = epfile->ffs->gadget;
spin_lock_irq(&epfile->ffs->eps_lock);
if (epfile->ep != ep) {
spin_unlock_irq(&epfile->ffs->eps_lock);
return -ESHUTDOWN;
}
data_len = io_data->read ?
usb_ep_align_maybe(gadget, ep->ep, io_data->len) :
io_data->len;
spin_unlock_irq(&epfile->ffs->eps_lock);
data = kmalloc(data_len, GFP_KERNEL);
if (unlikely(!data))
return -ENOMEM;
if (io_data->aio && !io_data->read) {
int i;
size_t pos = 0;
for (i = 0; i < io_data->nr_segs; i++) {
if (unlikely(copy_from_user(&data[pos],
io_data->iovec[i].iov_base,
io_data->iovec[i].iov_len))) {
ret = -EFAULT;
goto error;
}
pos += io_data->iovec[i].iov_len;
}
} else {
if (!io_data->read &&
unlikely(__copy_from_user(data, io_data->buf,
io_data->len))) {
ret = -EFAULT;
goto error;
}
}
}
ret = ffs_mutex_lock(&epfile->mutex, file->f_flags & O_NONBLOCK);
if (unlikely(ret))
goto error;
spin_lock_irq(&epfile->ffs->eps_lock);
if (epfile->ep != ep) {
ret = -ESHUTDOWN;
spin_unlock_irq(&epfile->ffs->eps_lock);
} else if (halt) {
if (likely(epfile->ep == ep) && !WARN_ON(!ep->ep))
usb_ep_set_halt(ep->ep);
spin_unlock_irq(&epfile->ffs->eps_lock);
ret = -EBADMSG;
} else {
struct usb_request *req;
if (io_data->aio) {
req = usb_ep_alloc_request(ep->ep, GFP_KERNEL);
if (unlikely(!req))
goto error_lock;
req->buf = data;
req->length = io_data->len;
io_data->buf = data;
io_data->ep = ep->ep;
io_data->req = req;
req->context = io_data;
req->complete = ffs_epfile_async_io_complete;
ret = usb_ep_queue(ep->ep, req, GFP_ATOMIC);
if (unlikely(ret)) {
usb_ep_free_request(ep->ep, req);
goto error_lock;
}
ret = -EIOCBQUEUED;
spin_unlock_irq(&epfile->ffs->eps_lock);
} else {
DECLARE_COMPLETION_ONSTACK(done);
req = ep->req;
req->buf = data;
req->length = io_data->len;
req->context = &done;
req->complete = ffs_epfile_io_complete;
ret = usb_ep_queue(ep->ep, req, GFP_ATOMIC);
spin_unlock_irq(&epfile->ffs->eps_lock);
if (unlikely(ret < 0)) {
} else if (unlikely(
wait_for_completion_interruptible(&done))) {
ret = -EINTR;
usb_ep_dequeue(ep->ep, req);
} else {
ret = ep->status;
if (io_data->read && ret > 0) {
ret = min_t(size_t, ret, io_data->len);
if (unlikely(copy_to_user(io_data->buf,
data, ret)))
ret = -EFAULT;
}
}
kfree(data);
}
}
mutex_unlock(&epfile->mutex);
return ret;
error_lock:
spin_unlock_irq(&epfile->ffs->eps_lock);
mutex_unlock(&epfile->mutex);
error:
kfree(data);
return ret;
}
static ssize_t
ffs_epfile_write(struct file *file, const char __user *buf, size_t len,
loff_t *ptr)
{
struct ffs_io_data io_data;
ENTER();
io_data.aio = false;
io_data.read = false;
io_data.buf = (char * __user)buf;
io_data.len = len;
return ffs_epfile_io(file, &io_data);
}
static ssize_t
ffs_epfile_read(struct file *file, char __user *buf, size_t len, loff_t *ptr)
{
struct ffs_io_data io_data;
ENTER();
io_data.aio = false;
io_data.read = true;
io_data.buf = buf;
io_data.len = len;
return ffs_epfile_io(file, &io_data);
}
static int
ffs_epfile_open(struct inode *inode, struct file *file)
{
struct ffs_epfile *epfile = inode->i_private;
ENTER();
if (WARN_ON(epfile->ffs->state != FFS_ACTIVE))
return -ENODEV;
file->private_data = epfile;
ffs_data_opened(epfile->ffs);
return 0;
}
static int ffs_aio_cancel(struct kiocb *kiocb)
{
struct ffs_io_data *io_data = kiocb->private;
struct ffs_epfile *epfile = kiocb->ki_filp->private_data;
int value;
ENTER();
spin_lock_irq(&epfile->ffs->eps_lock);
if (likely(io_data && io_data->ep && io_data->req))
value = usb_ep_dequeue(io_data->ep, io_data->req);
else
value = -EINVAL;
spin_unlock_irq(&epfile->ffs->eps_lock);
return value;
}
static ssize_t ffs_epfile_aio_write(struct kiocb *kiocb,
const struct iovec *iovec,
unsigned long nr_segs, loff_t loff)
{
struct ffs_io_data *io_data;
ENTER();
io_data = kmalloc(sizeof(*io_data), GFP_KERNEL);
if (unlikely(!io_data))
return -ENOMEM;
io_data->aio = true;
io_data->read = false;
io_data->kiocb = kiocb;
io_data->iovec = iovec;
io_data->nr_segs = nr_segs;
io_data->len = kiocb->ki_nbytes;
io_data->mm = current->mm;
kiocb->private = io_data;
kiocb_set_cancel_fn(kiocb, ffs_aio_cancel);
return ffs_epfile_io(kiocb->ki_filp, io_data);
}
static ssize_t ffs_epfile_aio_read(struct kiocb *kiocb,
const struct iovec *iovec,
unsigned long nr_segs, loff_t loff)
{
struct ffs_io_data *io_data;
struct iovec *iovec_copy;
ENTER();
iovec_copy = kmalloc_array(nr_segs, sizeof(*iovec_copy), GFP_KERNEL);
if (unlikely(!iovec_copy))
return -ENOMEM;
memcpy(iovec_copy, iovec, sizeof(struct iovec)*nr_segs);
io_data = kmalloc(sizeof(*io_data), GFP_KERNEL);
if (unlikely(!io_data)) {
kfree(iovec_copy);
return -ENOMEM;
}
io_data->aio = true;
io_data->read = true;
io_data->kiocb = kiocb;
io_data->iovec = iovec_copy;
io_data->nr_segs = nr_segs;
io_data->len = kiocb->ki_nbytes;
io_data->mm = current->mm;
kiocb->private = io_data;
kiocb_set_cancel_fn(kiocb, ffs_aio_cancel);
return ffs_epfile_io(kiocb->ki_filp, io_data);
}
static int
ffs_epfile_release(struct inode *inode, struct file *file)
{
struct ffs_epfile *epfile = inode->i_private;
ENTER();
ffs_data_closed(epfile->ffs);
return 0;
}
static long ffs_epfile_ioctl(struct file *file, unsigned code,
unsigned long value)
{
struct ffs_epfile *epfile = file->private_data;
int ret;
ENTER();
if (WARN_ON(epfile->ffs->state != FFS_ACTIVE))
return -ENODEV;
spin_lock_irq(&epfile->ffs->eps_lock);
if (likely(epfile->ep)) {
switch (code) {
case FUNCTIONFS_FIFO_STATUS:
ret = usb_ep_fifo_status(epfile->ep->ep);
break;
case FUNCTIONFS_FIFO_FLUSH:
usb_ep_fifo_flush(epfile->ep->ep);
ret = 0;
break;
case FUNCTIONFS_CLEAR_HALT:
ret = usb_ep_clear_halt(epfile->ep->ep);
break;
case FUNCTIONFS_ENDPOINT_REVMAP:
ret = epfile->ep->num;
break;
default:
ret = -ENOTTY;
}
} else {
ret = -ENODEV;
}
spin_unlock_irq(&epfile->ffs->eps_lock);
return ret;
}
static struct inode *__must_check
ffs_sb_make_inode(struct super_block *sb, void *data,
const struct file_operations *fops,
const struct inode_operations *iops,
struct ffs_file_perms *perms)
{
struct inode *inode;
ENTER();
inode = new_inode(sb);
if (likely(inode)) {
struct timespec current_time = CURRENT_TIME;
inode->i_ino = get_next_ino();
inode->i_mode = perms->mode;
inode->i_uid = perms->uid;
inode->i_gid = perms->gid;
inode->i_atime = current_time;
inode->i_mtime = current_time;
inode->i_ctime = current_time;
inode->i_private = data;
if (fops)
inode->i_fop = fops;
if (iops)
inode->i_op = iops;
}
return inode;
}
static struct inode *ffs_sb_create_file(struct super_block *sb,
const char *name, void *data,
const struct file_operations *fops,
struct dentry **dentry_p)
{
struct ffs_data *ffs = sb->s_fs_info;
struct dentry *dentry;
struct inode *inode;
ENTER();
dentry = d_alloc_name(sb->s_root, name);
if (unlikely(!dentry))
return NULL;
inode = ffs_sb_make_inode(sb, data, fops, NULL, &ffs->file_perms);
if (unlikely(!inode)) {
dput(dentry);
return NULL;
}
d_add(dentry, inode);
if (dentry_p)
*dentry_p = dentry;
return inode;
}
static int ffs_sb_fill(struct super_block *sb, void *_data, int silent)
{
struct ffs_sb_fill_data *data = _data;
struct inode *inode;
struct ffs_data *ffs = data->ffs_data;
ENTER();
ffs->sb = sb;
data->ffs_data = NULL;
sb->s_fs_info = ffs;
sb->s_blocksize = PAGE_CACHE_SIZE;
sb->s_blocksize_bits = PAGE_CACHE_SHIFT;
sb->s_magic = FUNCTIONFS_MAGIC;
sb->s_op = &ffs_sb_operations;
sb->s_time_gran = 1;
data->perms.mode = data->root_mode;
inode = ffs_sb_make_inode(sb, NULL,
&simple_dir_operations,
&simple_dir_inode_operations,
&data->perms);
sb->s_root = d_make_root(inode);
if (unlikely(!sb->s_root))
return -ENOMEM;
if (unlikely(!ffs_sb_create_file(sb, "ep0", ffs,
&ffs_ep0_operations, NULL)))
return -ENOMEM;
return 0;
}
static int ffs_fs_parse_opts(struct ffs_sb_fill_data *data, char *opts)
{
ENTER();
if (!opts || !*opts)
return 0;
for (;;) {
unsigned long value;
char *eq, *comma;
comma = strchr(opts, ',');
if (comma)
*comma = 0;
eq = strchr(opts, '=');
if (unlikely(!eq)) {
pr_err("'=' missing in %s\n", opts);
return -EINVAL;
}
*eq = 0;
if (kstrtoul(eq + 1, 0, &value)) {
pr_err("%s: invalid value: %s\n", opts, eq + 1);
return -EINVAL;
}
switch (eq - opts) {
case 5:
if (!memcmp(opts, "rmode", 5))
data->root_mode = (value & 0555) | S_IFDIR;
else if (!memcmp(opts, "fmode", 5))
data->perms.mode = (value & 0666) | S_IFREG;
else
goto invalid;
break;
case 4:
if (!memcmp(opts, "mode", 4)) {
data->root_mode = (value & 0555) | S_IFDIR;
data->perms.mode = (value & 0666) | S_IFREG;
} else {
goto invalid;
}
break;
case 3:
if (!memcmp(opts, "uid", 3)) {
data->perms.uid = make_kuid(current_user_ns(), value);
if (!uid_valid(data->perms.uid)) {
pr_err("%s: unmapped value: %lu\n", opts, value);
return -EINVAL;
}
} else if (!memcmp(opts, "gid", 3)) {
data->perms.gid = make_kgid(current_user_ns(), value);
if (!gid_valid(data->perms.gid)) {
pr_err("%s: unmapped value: %lu\n", opts, value);
return -EINVAL;
}
} else {
goto invalid;
}
break;
default:
invalid:
pr_err("%s: invalid option\n", opts);
return -EINVAL;
}
if (!comma)
break;
opts = comma + 1;
}
return 0;
}
static struct dentry *
ffs_fs_mount(struct file_system_type *t, int flags,
const char *dev_name, void *opts)
{
struct ffs_sb_fill_data data = {
.perms = {
.mode = S_IFREG | 0600,
.uid = GLOBAL_ROOT_UID,
.gid = GLOBAL_ROOT_GID,
},
.root_mode = S_IFDIR | 0500,
};
struct dentry *rv;
int ret;
void *ffs_dev;
struct ffs_data *ffs;
ENTER();
ret = ffs_fs_parse_opts(&data, opts);
if (unlikely(ret < 0))
return ERR_PTR(ret);
ffs = ffs_data_new();
if (unlikely(!ffs))
return ERR_PTR(-ENOMEM);
ffs->file_perms = data.perms;
ffs->dev_name = kstrdup(dev_name, GFP_KERNEL);
if (unlikely(!ffs->dev_name)) {
ffs_data_put(ffs);
return ERR_PTR(-ENOMEM);
}
ffs_dev = ffs_acquire_dev(dev_name);
if (IS_ERR(ffs_dev)) {
ffs_data_put(ffs);
return ERR_CAST(ffs_dev);
}
ffs->private_data = ffs_dev;
data.ffs_data = ffs;
rv = mount_nodev(t, flags, &data, ffs_sb_fill);
if (IS_ERR(rv) && data.ffs_data) {
ffs_release_dev(data.ffs_data);
ffs_data_put(data.ffs_data);
}
return rv;
}
static void
ffs_fs_kill_sb(struct super_block *sb)
{
ENTER();
kill_litter_super(sb);
if (sb->s_fs_info) {
ffs_release_dev(sb->s_fs_info);
ffs_data_put(sb->s_fs_info);
}
}
static int functionfs_init(void)
{
int ret;
ENTER();
ret = register_filesystem(&ffs_fs_type);
if (likely(!ret))
pr_info("file system registered\n");
else
pr_err("failed registering file system (%d)\n", ret);
return ret;
}
static void functionfs_cleanup(void)
{
ENTER();
pr_info("unloading\n");
unregister_filesystem(&ffs_fs_type);
}
static void ffs_data_get(struct ffs_data *ffs)
{
ENTER();
atomic_inc(&ffs->ref);
}
static void ffs_data_opened(struct ffs_data *ffs)
{
ENTER();
atomic_inc(&ffs->ref);
atomic_inc(&ffs->opened);
}
static void ffs_data_put(struct ffs_data *ffs)
{
ENTER();
if (unlikely(atomic_dec_and_test(&ffs->ref))) {
pr_info("%s(): freeing\n", __func__);
ffs_data_clear(ffs);
BUG_ON(waitqueue_active(&ffs->ev.waitq) ||
waitqueue_active(&ffs->ep0req_completion.wait));
kfree(ffs->dev_name);
kfree(ffs);
}
}
static void ffs_data_closed(struct ffs_data *ffs)
{
ENTER();
if (atomic_dec_and_test(&ffs->opened)) {
ffs->state = FFS_CLOSING;
ffs_data_reset(ffs);
}
ffs_data_put(ffs);
}
static struct ffs_data *ffs_data_new(void)
{
struct ffs_data *ffs = kzalloc(sizeof *ffs, GFP_KERNEL);
if (unlikely(!ffs))
return NULL;
ENTER();
atomic_set(&ffs->ref, 1);
atomic_set(&ffs->opened, 0);
ffs->state = FFS_READ_DESCRIPTORS;
mutex_init(&ffs->mutex);
spin_lock_init(&ffs->eps_lock);
init_waitqueue_head(&ffs->ev.waitq);
init_completion(&ffs->ep0req_completion);
ffs->ev.can_stall = 1;
return ffs;
}
static void ffs_data_clear(struct ffs_data *ffs)
{
ENTER();
if (test_and_clear_bit(FFS_FL_CALL_CLOSED_CALLBACK, &ffs->flags))
ffs_closed(ffs);
BUG_ON(ffs->gadget);
if (ffs->epfiles)
ffs_epfiles_destroy(ffs->epfiles, ffs->eps_count);
kfree(ffs->raw_descs_data);
kfree(ffs->raw_strings);
kfree(ffs->stringtabs);
}
static void ffs_data_reset(struct ffs_data *ffs)
{
ENTER();
ffs_data_clear(ffs);
ffs->epfiles = NULL;
ffs->raw_descs_data = NULL;
ffs->raw_descs = NULL;
ffs->raw_strings = NULL;
ffs->stringtabs = NULL;
ffs->raw_descs_length = 0;
ffs->fs_descs_count = 0;
ffs->hs_descs_count = 0;
ffs->ss_descs_count = 0;
ffs->strings_count = 0;
ffs->interfaces_count = 0;
ffs->eps_count = 0;
ffs->ev.count = 0;
ffs->state = FFS_READ_DESCRIPTORS;
ffs->setup_state = FFS_NO_SETUP;
ffs->flags = 0;
}
static int functionfs_bind(struct ffs_data *ffs, struct usb_composite_dev *cdev)
{
struct usb_gadget_strings **lang;
int first_id;
ENTER();
if (WARN_ON(ffs->state != FFS_ACTIVE
|| test_and_set_bit(FFS_FL_BOUND, &ffs->flags)))
return -EBADFD;
first_id = usb_string_ids_n(cdev, ffs->strings_count);
if (unlikely(first_id < 0))
return first_id;
ffs->ep0req = usb_ep_alloc_request(cdev->gadget->ep0, GFP_KERNEL);
if (unlikely(!ffs->ep0req))
return -ENOMEM;
ffs->ep0req->complete = ffs_ep0_complete;
ffs->ep0req->context = ffs;
lang = ffs->stringtabs;
for (lang = ffs->stringtabs; *lang; ++lang) {
struct usb_string *str = (*lang)->strings;
int id = first_id;
for (; str->s; ++id, ++str)
str->id = id;
}
ffs->gadget = cdev->gadget;
ffs_data_get(ffs);
return 0;
}
static void functionfs_unbind(struct ffs_data *ffs)
{
ENTER();
if (!WARN_ON(!ffs->gadget)) {
usb_ep_free_request(ffs->gadget->ep0, ffs->ep0req);
ffs->ep0req = NULL;
ffs->gadget = NULL;
clear_bit(FFS_FL_BOUND, &ffs->flags);
ffs_data_put(ffs);
}
}
static int ffs_epfiles_create(struct ffs_data *ffs)
{
struct ffs_epfile *epfile, *epfiles;
unsigned i, count;
ENTER();
count = ffs->eps_count;
epfiles = kcalloc(count, sizeof(*epfiles), GFP_KERNEL);
if (!epfiles)
return -ENOMEM;
epfile = epfiles;
for (i = 1; i <= count; ++i, ++epfile) {
epfile->ffs = ffs;
mutex_init(&epfile->mutex);
init_waitqueue_head(&epfile->wait);
sprintf(epfiles->name, "ep%u", i);
if (!unlikely(ffs_sb_create_file(ffs->sb, epfiles->name, epfile,
&ffs_epfile_operations,
&epfile->dentry))) {
ffs_epfiles_destroy(epfiles, i - 1);
return -ENOMEM;
}
}
ffs->epfiles = epfiles;
return 0;
}
static void ffs_epfiles_destroy(struct ffs_epfile *epfiles, unsigned count)
{
struct ffs_epfile *epfile = epfiles;
ENTER();
for (; count; --count, ++epfile) {
BUG_ON(mutex_is_locked(&epfile->mutex) ||
waitqueue_active(&epfile->wait));
if (epfile->dentry) {
d_delete(epfile->dentry);
dput(epfile->dentry);
epfile->dentry = NULL;
}
}
kfree(epfiles);
}
static void ffs_func_eps_disable(struct ffs_function *func)
{
struct ffs_ep *ep = func->eps;
struct ffs_epfile *epfile = func->ffs->epfiles;
unsigned count = func->ffs->eps_count;
unsigned long flags;
spin_lock_irqsave(&func->ffs->eps_lock, flags);
do {
if (likely(ep->ep))
usb_ep_disable(ep->ep);
epfile->ep = NULL;
++ep;
++epfile;
} while (--count);
spin_unlock_irqrestore(&func->ffs->eps_lock, flags);
}
static int ffs_func_eps_enable(struct ffs_function *func)
{
struct ffs_data *ffs = func->ffs;
struct ffs_ep *ep = func->eps;
struct ffs_epfile *epfile = ffs->epfiles;
unsigned count = ffs->eps_count;
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&func->ffs->eps_lock, flags);
do {
struct usb_endpoint_descriptor *ds;
int desc_idx;
if (ffs->gadget->speed == USB_SPEED_SUPER)
desc_idx = 2;
else if (ffs->gadget->speed == USB_SPEED_HIGH)
desc_idx = 1;
else
desc_idx = 0;
do {
ds = ep->descs[desc_idx];
} while (!ds && --desc_idx >= 0);
if (!ds) {
ret = -EINVAL;
break;
}
ep->ep->driver_data = ep;
ep->ep->desc = ds;
ret = usb_ep_enable(ep->ep);
if (likely(!ret)) {
epfile->ep = ep;
epfile->in = usb_endpoint_dir_in(ds);
epfile->isoc = usb_endpoint_xfer_isoc(ds);
} else {
break;
}
wake_up(&epfile->wait);
++ep;
++epfile;
} while (--count);
spin_unlock_irqrestore(&func->ffs->eps_lock, flags);
return ret;
}
static int __must_check ffs_do_desc(char *data, unsigned len,
ffs_entity_callback entity, void *priv)
{
struct usb_descriptor_header *_ds = (void *)data;
u8 length;
int ret;
ENTER();
if (len < 2) {
pr_vdebug("descriptor too short\n");
return -EINVAL;
}
length = _ds->bLength;
if (len < length) {
pr_vdebug("descriptor longer then available data\n");
return -EINVAL;
}
#define __entity_check_INTERFACE(val) 1
#define __entity_check_STRING(val) (val)
#define __entity_check_ENDPOINT(val) ((val) & USB_ENDPOINT_NUMBER_MASK)
#define __entity(type, val) do { \
pr_vdebug("entity " #type "(%02x)\n", (val)); \
if (unlikely(!__entity_check_ ##type(val))) { \
pr_vdebug("invalid entity's value\n"); \
return -EINVAL; \
} \
ret = entity(FFS_ ##type, &val, _ds, priv); \
if (unlikely(ret < 0)) { \
pr_debug("entity " #type "(%02x); ret = %d\n", \
(val), ret); \
return ret; \
} \
} while (0)
switch (_ds->bDescriptorType) {
case USB_DT_DEVICE:
case USB_DT_CONFIG:
case USB_DT_STRING:
case USB_DT_DEVICE_QUALIFIER:
pr_vdebug("descriptor reserved for gadget: %d\n",
_ds->bDescriptorType);
return -EINVAL;
case USB_DT_INTERFACE: {
struct usb_interface_descriptor *ds = (void *)_ds;
pr_vdebug("interface descriptor\n");
if (length != sizeof *ds)
goto inv_length;
__entity(INTERFACE, ds->bInterfaceNumber);
if (ds->iInterface)
__entity(STRING, ds->iInterface);
}
break;
case USB_DT_ENDPOINT: {
struct usb_endpoint_descriptor *ds = (void *)_ds;
pr_vdebug("endpoint descriptor\n");
if (length != USB_DT_ENDPOINT_SIZE &&
length != USB_DT_ENDPOINT_AUDIO_SIZE)
goto inv_length;
__entity(ENDPOINT, ds->bEndpointAddress);
}
break;
case HID_DT_HID:
pr_vdebug("hid descriptor\n");
if (length != sizeof(struct hid_descriptor))
goto inv_length;
break;
case USB_DT_OTG:
if (length != sizeof(struct usb_otg_descriptor))
goto inv_length;
break;
case USB_DT_INTERFACE_ASSOCIATION: {
struct usb_interface_assoc_descriptor *ds = (void *)_ds;
pr_vdebug("interface association descriptor\n");
if (length != sizeof *ds)
goto inv_length;
if (ds->iFunction)
__entity(STRING, ds->iFunction);
}
break;
case USB_DT_SS_ENDPOINT_COMP:
pr_vdebug("EP SS companion descriptor\n");
if (length != sizeof(struct usb_ss_ep_comp_descriptor))
goto inv_length;
break;
case USB_DT_OTHER_SPEED_CONFIG:
case USB_DT_INTERFACE_POWER:
case USB_DT_DEBUG:
case USB_DT_SECURITY:
case USB_DT_CS_RADIO_CONTROL:
pr_vdebug("unimplemented descriptor: %d\n", _ds->bDescriptorType);
return -EINVAL;
default:
pr_vdebug("unknown descriptor: %d\n", _ds->bDescriptorType);
return -EINVAL;
inv_length:
pr_vdebug("invalid length: %d (descriptor %d)\n",
_ds->bLength, _ds->bDescriptorType);
return -EINVAL;
}
#undef __entity
#undef __entity_check_DESCRIPTOR
#undef __entity_check_INTERFACE
#undef __entity_check_STRING
#undef __entity_check_ENDPOINT
return length;
}
static int __must_check ffs_do_descs(unsigned count, char *data, unsigned len,
ffs_entity_callback entity, void *priv)
{
const unsigned _len = len;
unsigned long num = 0;
ENTER();
for (;;) {
int ret;
if (num == count)
data = NULL;
ret = entity(FFS_DESCRIPTOR, (u8 *)num, (void *)data, priv);
if (unlikely(ret < 0)) {
pr_debug("entity DESCRIPTOR(%02lx); ret = %d\n",
num, ret);
return ret;
}
if (!data)
return _len - len;
ret = ffs_do_desc(data, len, entity, priv);
if (unlikely(ret < 0)) {
pr_debug("%s returns %d\n", __func__, ret);
return ret;
}
len -= ret;
data += ret;
++num;
}
}
static int __ffs_data_do_entity(enum ffs_entity_type type,
u8 *valuep, struct usb_descriptor_header *desc,
void *priv)
{
struct ffs_data *ffs = priv;
ENTER();
switch (type) {
case FFS_DESCRIPTOR:
break;
case FFS_INTERFACE:
if (*valuep >= ffs->interfaces_count)
ffs->interfaces_count = *valuep + 1;
break;
case FFS_STRING:
if (*valuep > ffs->strings_count)
ffs->strings_count = *valuep;
break;
case FFS_ENDPOINT:
if ((*valuep & USB_ENDPOINT_NUMBER_MASK) > ffs->eps_count)
ffs->eps_count = (*valuep & USB_ENDPOINT_NUMBER_MASK);
break;
}
return 0;
}
static int __ffs_data_got_descs(struct ffs_data *ffs,
char *const _data, size_t len)
{
char *data = _data, *raw_descs;
unsigned counts[3], flags;
int ret = -EINVAL, i;
ENTER();
if (get_unaligned_le32(data + 4) != len)
goto error;
switch (get_unaligned_le32(data)) {
case FUNCTIONFS_DESCRIPTORS_MAGIC:
flags = FUNCTIONFS_HAS_FS_DESC | FUNCTIONFS_HAS_HS_DESC;
data += 8;
len -= 8;
break;
case FUNCTIONFS_DESCRIPTORS_MAGIC_V2:
flags = get_unaligned_le32(data + 8);
if (flags & ~(FUNCTIONFS_HAS_FS_DESC |
FUNCTIONFS_HAS_HS_DESC |
FUNCTIONFS_HAS_SS_DESC)) {
ret = -ENOSYS;
goto error;
}
data += 12;
len -= 12;
break;
default:
goto error;
}
for (i = 0; i < 3; ++i) {
if (!(flags & (1 << i))) {
counts[i] = 0;
} else if (len < 4) {
goto error;
} else {
counts[i] = get_unaligned_le32(data);
data += 4;
len -= 4;
}
}
raw_descs = data;
for (i = 0; i < 3; ++i) {
if (!counts[i])
continue;
ret = ffs_do_descs(counts[i], data, len,
__ffs_data_do_entity, ffs);
if (ret < 0)
goto error;
data += ret;
len -= ret;
}
if (raw_descs == data || len) {
ret = -EINVAL;
goto error;
}
ffs->raw_descs_data = _data;
ffs->raw_descs = raw_descs;
ffs->raw_descs_length = data - raw_descs;
ffs->fs_descs_count = counts[0];
ffs->hs_descs_count = counts[1];
ffs->ss_descs_count = counts[2];
return 0;
error:
kfree(_data);
return ret;
}
static int __ffs_data_got_strings(struct ffs_data *ffs,
char *const _data, size_t len)
{
u32 str_count, needed_count, lang_count;
struct usb_gadget_strings **stringtabs, *t;
struct usb_string *strings, *s;
const char *data = _data;
ENTER();
if (unlikely(get_unaligned_le32(data) != FUNCTIONFS_STRINGS_MAGIC ||
get_unaligned_le32(data + 4) != len))
goto error;
str_count = get_unaligned_le32(data + 8);
lang_count = get_unaligned_le32(data + 12);
if (unlikely(!str_count != !lang_count))
goto error;
needed_count = ffs->strings_count;
if (unlikely(str_count < needed_count))
goto error;
if (!needed_count) {
kfree(_data);
return 0;
}
{
unsigned i = 0;
vla_group(d);
vla_item(d, struct usb_gadget_strings *, stringtabs,
lang_count + 1);
vla_item(d, struct usb_gadget_strings, stringtab, lang_count);
vla_item(d, struct usb_string, strings,
lang_count*(needed_count+1));
char *vlabuf = kmalloc(vla_group_size(d), GFP_KERNEL);
if (unlikely(!vlabuf)) {
kfree(_data);
return -ENOMEM;
}
stringtabs = vla_ptr(vlabuf, d, stringtabs);
t = vla_ptr(vlabuf, d, stringtab);
i = lang_count;
do {
*stringtabs++ = t++;
} while (--i);
*stringtabs = NULL;
stringtabs = vla_ptr(vlabuf, d, stringtabs);
t = vla_ptr(vlabuf, d, stringtab);
s = vla_ptr(vlabuf, d, strings);
strings = s;
}
data += 16;
len -= 16;
do {
unsigned needed = needed_count;
if (unlikely(len < 3))
goto error_free;
t->language = get_unaligned_le16(data);
t->strings = s;
++t;
data += 2;
len -= 2;
do {
size_t length = strnlen(data, len);
if (unlikely(length == len))
goto error_free;
if (likely(needed)) {
s->s = data;
--needed;
++s;
}
data += length + 1;
len -= length + 1;
} while (--str_count);
s->id = 0;
s->s = NULL;
++s;
} while (--lang_count);
if (unlikely(len))
goto error_free;
ffs->stringtabs = stringtabs;
ffs->raw_strings = _data;
return 0;
error_free:
kfree(stringtabs);
error:
kfree(_data);
return -EINVAL;
}
static void __ffs_event_add(struct ffs_data *ffs,
enum usb_functionfs_event_type type)
{
enum usb_functionfs_event_type rem_type1, rem_type2 = type;
int neg = 0;
if (ffs->setup_state == FFS_SETUP_PENDING)
ffs->setup_state = FFS_SETUP_CANCELLED;
switch (type) {
case FUNCTIONFS_RESUME:
rem_type2 = FUNCTIONFS_SUSPEND;
case FUNCTIONFS_SUSPEND:
case FUNCTIONFS_SETUP:
rem_type1 = type;
break;
case FUNCTIONFS_BIND:
case FUNCTIONFS_UNBIND:
case FUNCTIONFS_DISABLE:
case FUNCTIONFS_ENABLE:
rem_type1 = FUNCTIONFS_SUSPEND;
rem_type2 = FUNCTIONFS_RESUME;
neg = 1;
break;
default:
BUG();
}
{
u8 *ev = ffs->ev.types, *out = ev;
unsigned n = ffs->ev.count;
for (; n; --n, ++ev)
if ((*ev == rem_type1 || *ev == rem_type2) == neg)
*out++ = *ev;
else
pr_vdebug("purging event %d\n", *ev);
ffs->ev.count = out - ffs->ev.types;
}
pr_vdebug("adding event %d\n", type);
ffs->ev.types[ffs->ev.count++] = type;
wake_up_locked(&ffs->ev.waitq);
}
static void ffs_event_add(struct ffs_data *ffs,
enum usb_functionfs_event_type type)
{
unsigned long flags;
spin_lock_irqsave(&ffs->ev.waitq.lock, flags);
__ffs_event_add(ffs, type);
spin_unlock_irqrestore(&ffs->ev.waitq.lock, flags);
}
static int __ffs_func_bind_do_descs(enum ffs_entity_type type, u8 *valuep,
struct usb_descriptor_header *desc,
void *priv)
{
struct usb_endpoint_descriptor *ds = (void *)desc;
struct ffs_function *func = priv;
struct ffs_ep *ffs_ep;
unsigned ep_desc_id, idx;
static const char *speed_names[] = { "full", "high", "super" };
if (type != FFS_DESCRIPTOR)
return 0;
if (func->function.ss_descriptors) {
ep_desc_id = 2;
func->function.ss_descriptors[(long)valuep] = desc;
} else if (func->function.hs_descriptors) {
ep_desc_id = 1;
func->function.hs_descriptors[(long)valuep] = desc;
} else {
ep_desc_id = 0;
func->function.fs_descriptors[(long)valuep] = desc;
}
if (!desc || desc->bDescriptorType != USB_DT_ENDPOINT)
return 0;
idx = (ds->bEndpointAddress & USB_ENDPOINT_NUMBER_MASK) - 1;
ffs_ep = func->eps + idx;
if (unlikely(ffs_ep->descs[ep_desc_id])) {
pr_err("two %sspeed descriptors for EP %d\n",
speed_names[ep_desc_id],
ds->bEndpointAddress & USB_ENDPOINT_NUMBER_MASK);
return -EINVAL;
}
ffs_ep->descs[ep_desc_id] = ds;
ffs_dump_mem(": Original ep desc", ds, ds->bLength);
if (ffs_ep->ep) {
ds->bEndpointAddress = ffs_ep->descs[0]->bEndpointAddress;
if (!ds->wMaxPacketSize)
ds->wMaxPacketSize = ffs_ep->descs[0]->wMaxPacketSize;
} else {
struct usb_request *req;
struct usb_ep *ep;
pr_vdebug("autoconfig\n");
ep = usb_ep_autoconfig(func->gadget, ds);
if (unlikely(!ep))
return -ENOTSUPP;
ep->driver_data = func->eps + idx;
req = usb_ep_alloc_request(ep, GFP_KERNEL);
if (unlikely(!req))
return -ENOMEM;
ffs_ep->ep = ep;
ffs_ep->req = req;
func->eps_revmap[ds->bEndpointAddress &
USB_ENDPOINT_NUMBER_MASK] = idx + 1;
}
ffs_dump_mem(": Rewritten ep desc", ds, ds->bLength);
return 0;
}
static int __ffs_func_bind_do_nums(enum ffs_entity_type type, u8 *valuep,
struct usb_descriptor_header *desc,
void *priv)
{
struct ffs_function *func = priv;
unsigned idx;
u8 newValue;
switch (type) {
default:
case FFS_DESCRIPTOR:
return 0;
case FFS_INTERFACE:
idx = *valuep;
if (func->interfaces_nums[idx] < 0) {
int id = usb_interface_id(func->conf, &func->function);
if (unlikely(id < 0))
return id;
func->interfaces_nums[idx] = id;
}
newValue = func->interfaces_nums[idx];
break;
case FFS_STRING:
newValue = func->ffs->stringtabs[0]->strings[*valuep - 1].id;
break;
case FFS_ENDPOINT:
if (desc->bDescriptorType == USB_DT_ENDPOINT)
return 0;
idx = (*valuep & USB_ENDPOINT_NUMBER_MASK) - 1;
if (unlikely(!func->eps[idx].ep))
return -EINVAL;
{
struct usb_endpoint_descriptor **descs;
descs = func->eps[idx].descs;
newValue = descs[descs[0] ? 0 : 1]->bEndpointAddress;
}
break;
}
pr_vdebug("%02x -> %02x\n", *valuep, newValue);
*valuep = newValue;
return 0;
}
static inline struct f_fs_opts *ffs_do_functionfs_bind(struct usb_function *f,
struct usb_configuration *c)
{
struct ffs_function *func = ffs_func_from_usb(f);
struct f_fs_opts *ffs_opts =
container_of(f->fi, struct f_fs_opts, func_inst);
int ret;
ENTER();
if (!ffs_opts->no_configfs)
ffs_dev_lock();
ret = ffs_opts->dev->desc_ready ? 0 : -ENODEV;
func->ffs = ffs_opts->dev->ffs_data;
if (!ffs_opts->no_configfs)
ffs_dev_unlock();
if (ret)
return ERR_PTR(ret);
func->conf = c;
func->gadget = c->cdev->gadget;
ffs_data_get(func->ffs);
if (!ffs_opts->refcnt) {
ret = functionfs_bind(func->ffs, c->cdev);
if (ret)
return ERR_PTR(ret);
}
ffs_opts->refcnt++;
func->function.strings = func->ffs->stringtabs;
return ffs_opts;
}
static int _ffs_func_bind(struct usb_configuration *c,
struct usb_function *f)
{
struct ffs_function *func = ffs_func_from_usb(f);
struct ffs_data *ffs = func->ffs;
const int full = !!func->ffs->fs_descs_count;
const int high = gadget_is_dualspeed(func->gadget) &&
func->ffs->hs_descs_count;
const int super = gadget_is_superspeed(func->gadget) &&
func->ffs->ss_descs_count;
int fs_len, hs_len, ret;
vla_group(d);
vla_item_with_sz(d, struct ffs_ep, eps, ffs->eps_count);
vla_item_with_sz(d, struct usb_descriptor_header *, fs_descs,
full ? ffs->fs_descs_count + 1 : 0);
vla_item_with_sz(d, struct usb_descriptor_header *, hs_descs,
high ? ffs->hs_descs_count + 1 : 0);
vla_item_with_sz(d, struct usb_descriptor_header *, ss_descs,
super ? ffs->ss_descs_count + 1 : 0);
vla_item_with_sz(d, short, inums, ffs->interfaces_count);
vla_item_with_sz(d, char, raw_descs, ffs->raw_descs_length);
char *vlabuf;
ENTER();
if (unlikely(!(full | high | super)))
return -ENOTSUPP;
vlabuf = kmalloc(vla_group_size(d), GFP_KERNEL);
if (unlikely(!vlabuf))
return -ENOMEM;
memset(vla_ptr(vlabuf, d, eps), 0, d_eps__sz);
memcpy(vla_ptr(vlabuf, d, raw_descs), ffs->raw_descs,
ffs->raw_descs_length);
memset(vla_ptr(vlabuf, d, inums), 0xff, d_inums__sz);
for (ret = ffs->eps_count; ret; --ret) {
struct ffs_ep *ptr;
ptr = vla_ptr(vlabuf, d, eps);
ptr[ret].num = -1;
}
func->eps = vla_ptr(vlabuf, d, eps);
func->interfaces_nums = vla_ptr(vlabuf, d, inums);
if (likely(full)) {
func->function.fs_descriptors = vla_ptr(vlabuf, d, fs_descs);
fs_len = ffs_do_descs(ffs->fs_descs_count,
vla_ptr(vlabuf, d, raw_descs),
d_raw_descs__sz,
__ffs_func_bind_do_descs, func);
if (unlikely(fs_len < 0)) {
ret = fs_len;
goto error;
}
} else {
fs_len = 0;
}
if (likely(high)) {
func->function.hs_descriptors = vla_ptr(vlabuf, d, hs_descs);
hs_len = ffs_do_descs(ffs->hs_descs_count,
vla_ptr(vlabuf, d, raw_descs) + fs_len,
d_raw_descs__sz - fs_len,
__ffs_func_bind_do_descs, func);
if (unlikely(hs_len < 0)) {
ret = hs_len;
goto error;
}
} else {
hs_len = 0;
}
if (likely(super)) {
func->function.ss_descriptors = vla_ptr(vlabuf, d, ss_descs);
ret = ffs_do_descs(ffs->ss_descs_count,
vla_ptr(vlabuf, d, raw_descs) + fs_len + hs_len,
d_raw_descs__sz - fs_len - hs_len,
__ffs_func_bind_do_descs, func);
if (unlikely(ret < 0))
goto error;
}
ret = ffs_do_descs(ffs->fs_descs_count +
(high ? ffs->hs_descs_count : 0) +
(super ? ffs->ss_descs_count : 0),
vla_ptr(vlabuf, d, raw_descs), d_raw_descs__sz,
__ffs_func_bind_do_nums, func);
if (unlikely(ret < 0))
goto error;
ffs_event_add(ffs, FUNCTIONFS_BIND);
return 0;
error:
return ret;
}
static int ffs_func_bind(struct usb_configuration *c,
struct usb_function *f)
{
struct f_fs_opts *ffs_opts = ffs_do_functionfs_bind(f, c);
if (IS_ERR(ffs_opts))
return PTR_ERR(ffs_opts);
return _ffs_func_bind(c, f);
}
static int ffs_func_set_alt(struct usb_function *f,
unsigned interface, unsigned alt)
{
struct ffs_function *func = ffs_func_from_usb(f);
struct ffs_data *ffs = func->ffs;
int ret = 0, intf;
if (alt != (unsigned)-1) {
intf = ffs_func_revmap_intf(func, interface);
if (unlikely(intf < 0))
return intf;
}
if (ffs->func)
ffs_func_eps_disable(ffs->func);
if (ffs->state != FFS_ACTIVE)
return -ENODEV;
if (alt == (unsigned)-1) {
ffs->func = NULL;
ffs_event_add(ffs, FUNCTIONFS_DISABLE);
return 0;
}
ffs->func = func;
ret = ffs_func_eps_enable(func);
if (likely(ret >= 0))
ffs_event_add(ffs, FUNCTIONFS_ENABLE);
return ret;
}
static void ffs_func_disable(struct usb_function *f)
{
ffs_func_set_alt(f, 0, (unsigned)-1);
}
static int ffs_func_setup(struct usb_function *f,
const struct usb_ctrlrequest *creq)
{
struct ffs_function *func = ffs_func_from_usb(f);
struct ffs_data *ffs = func->ffs;
unsigned long flags;
int ret;
ENTER();
pr_vdebug("creq->bRequestType = %02x\n", creq->bRequestType);
pr_vdebug("creq->bRequest = %02x\n", creq->bRequest);
pr_vdebug("creq->wValue = %04x\n", le16_to_cpu(creq->wValue));
pr_vdebug("creq->wIndex = %04x\n", le16_to_cpu(creq->wIndex));
pr_vdebug("creq->wLength = %04x\n", le16_to_cpu(creq->wLength));
if (ffs->state != FFS_ACTIVE)
return -ENODEV;
switch (creq->bRequestType & USB_RECIP_MASK) {
case USB_RECIP_INTERFACE:
ret = ffs_func_revmap_intf(func, le16_to_cpu(creq->wIndex));
if (unlikely(ret < 0))
return ret;
break;
case USB_RECIP_ENDPOINT:
ret = ffs_func_revmap_ep(func, le16_to_cpu(creq->wIndex));
if (unlikely(ret < 0))
return ret;
break;
default:
return -EOPNOTSUPP;
}
spin_lock_irqsave(&ffs->ev.waitq.lock, flags);
ffs->ev.setup = *creq;
ffs->ev.setup.wIndex = cpu_to_le16(ret);
__ffs_event_add(ffs, FUNCTIONFS_SETUP);
spin_unlock_irqrestore(&ffs->ev.waitq.lock, flags);
return 0;
}
static void ffs_func_suspend(struct usb_function *f)
{
ENTER();
ffs_event_add(ffs_func_from_usb(f)->ffs, FUNCTIONFS_SUSPEND);
}
static void ffs_func_resume(struct usb_function *f)
{
ENTER();
ffs_event_add(ffs_func_from_usb(f)->ffs, FUNCTIONFS_RESUME);
}
static int ffs_func_revmap_ep(struct ffs_function *func, u8 num)
{
num = func->eps_revmap[num & USB_ENDPOINT_NUMBER_MASK];
return num ? num : -EDOM;
}
static int ffs_func_revmap_intf(struct ffs_function *func, u8 intf)
{
short *nums = func->interfaces_nums;
unsigned count = func->ffs->interfaces_count;
for (; count; --count, ++nums) {
if (*nums >= 0 && *nums == intf)
return nums - func->interfaces_nums;
}
return -EDOM;
}
static struct ffs_dev *_ffs_do_find_dev(const char *name)
{
struct ffs_dev *dev;
list_for_each_entry(dev, &ffs_devices, entry) {
if (!dev->name || !name)
continue;
if (strcmp(dev->name, name) == 0)
return dev;
}
return NULL;
}
static struct ffs_dev *_ffs_get_single_dev(void)
{
struct ffs_dev *dev;
if (list_is_singular(&ffs_devices)) {
dev = list_first_entry(&ffs_devices, struct ffs_dev, entry);
if (dev->single)
return dev;
}
return NULL;
}
static struct ffs_dev *_ffs_find_dev(const char *name)
{
struct ffs_dev *dev;
dev = _ffs_get_single_dev();
if (dev)
return dev;
return _ffs_do_find_dev(name);
}
static inline struct f_fs_opts *to_ffs_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_fs_opts,
func_inst.group);
}
static void ffs_attr_release(struct config_item *item)
{
struct f_fs_opts *opts = to_ffs_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static void ffs_free_inst(struct usb_function_instance *f)
{
struct f_fs_opts *opts;
opts = to_f_fs_opts(f);
ffs_dev_lock();
_ffs_free_dev(opts->dev);
ffs_dev_unlock();
kfree(opts);
}
static int ffs_set_inst_name(struct usb_function_instance *fi, const char *name)
{
struct f_fs_opts *opts;
char *ptr;
const char *tmp;
int name_len, ret;
name_len = strlen(name) + 1;
if (name_len > MAX_INST_NAME_LEN)
return -ENAMETOOLONG;
ptr = kstrndup(name, name_len, GFP_KERNEL);
if (!ptr)
return -ENOMEM;
opts = to_f_fs_opts(fi);
tmp = NULL;
ffs_dev_lock();
tmp = opts->dev->name_allocated ? opts->dev->name : NULL;
ret = _ffs_name_dev(opts->dev, ptr);
if (ret) {
kfree(ptr);
ffs_dev_unlock();
return ret;
}
opts->dev->name_allocated = true;
ffs_dev_unlock();
kfree(tmp);
return 0;
}
static struct usb_function_instance *ffs_alloc_inst(void)
{
struct f_fs_opts *opts;
struct ffs_dev *dev;
opts = kzalloc(sizeof(*opts), GFP_KERNEL);
if (!opts)
return ERR_PTR(-ENOMEM);
opts->func_inst.set_inst_name = ffs_set_inst_name;
opts->func_inst.free_func_inst = ffs_free_inst;
ffs_dev_lock();
dev = _ffs_alloc_dev();
ffs_dev_unlock();
if (IS_ERR(dev)) {
kfree(opts);
return ERR_CAST(dev);
}
opts->dev = dev;
dev->opts = opts;
config_group_init_type_name(&opts->func_inst.group, "",
&ffs_func_type);
return &opts->func_inst;
}
static void ffs_free(struct usb_function *f)
{
kfree(ffs_func_from_usb(f));
}
static void ffs_func_unbind(struct usb_configuration *c,
struct usb_function *f)
{
struct ffs_function *func = ffs_func_from_usb(f);
struct ffs_data *ffs = func->ffs;
struct f_fs_opts *opts =
container_of(f->fi, struct f_fs_opts, func_inst);
struct ffs_ep *ep = func->eps;
unsigned count = ffs->eps_count;
unsigned long flags;
ENTER();
if (ffs->func == func) {
ffs_func_eps_disable(func);
ffs->func = NULL;
}
if (!--opts->refcnt)
functionfs_unbind(ffs);
spin_lock_irqsave(&func->ffs->eps_lock, flags);
do {
if (ep->ep && ep->req)
usb_ep_free_request(ep->ep, ep->req);
ep->req = NULL;
++ep;
} while (--count);
spin_unlock_irqrestore(&func->ffs->eps_lock, flags);
kfree(func->eps);
func->eps = NULL;
func->function.fs_descriptors = NULL;
func->function.hs_descriptors = NULL;
func->function.ss_descriptors = NULL;
func->interfaces_nums = NULL;
ffs_event_add(ffs, FUNCTIONFS_UNBIND);
}
static struct usb_function *ffs_alloc(struct usb_function_instance *fi)
{
struct ffs_function *func;
ENTER();
func = kzalloc(sizeof(*func), GFP_KERNEL);
if (unlikely(!func))
return ERR_PTR(-ENOMEM);
func->function.name = "Function FS Gadget";
func->function.bind = ffs_func_bind;
func->function.unbind = ffs_func_unbind;
func->function.set_alt = ffs_func_set_alt;
func->function.disable = ffs_func_disable;
func->function.setup = ffs_func_setup;
func->function.suspend = ffs_func_suspend;
func->function.resume = ffs_func_resume;
func->function.free_func = ffs_free;
return &func->function;
}
static struct ffs_dev *_ffs_alloc_dev(void)
{
struct ffs_dev *dev;
int ret;
if (_ffs_get_single_dev())
return ERR_PTR(-EBUSY);
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return ERR_PTR(-ENOMEM);
if (list_empty(&ffs_devices)) {
ret = functionfs_init();
if (ret) {
kfree(dev);
return ERR_PTR(ret);
}
}
list_add(&dev->entry, &ffs_devices);
return dev;
}
static int _ffs_name_dev(struct ffs_dev *dev, const char *name)
{
struct ffs_dev *existing;
existing = _ffs_do_find_dev(name);
if (existing)
return -EBUSY;
dev->name = name;
return 0;
}
int ffs_name_dev(struct ffs_dev *dev, const char *name)
{
int ret;
ffs_dev_lock();
ret = _ffs_name_dev(dev, name);
ffs_dev_unlock();
return ret;
}
int ffs_single_dev(struct ffs_dev *dev)
{
int ret;
ret = 0;
ffs_dev_lock();
if (!list_is_singular(&ffs_devices))
ret = -EBUSY;
else
dev->single = true;
ffs_dev_unlock();
return ret;
}
static void _ffs_free_dev(struct ffs_dev *dev)
{
list_del(&dev->entry);
if (dev->name_allocated)
kfree(dev->name);
kfree(dev);
if (list_empty(&ffs_devices))
functionfs_cleanup();
}
static void *ffs_acquire_dev(const char *dev_name)
{
struct ffs_dev *ffs_dev;
ENTER();
ffs_dev_lock();
ffs_dev = _ffs_find_dev(dev_name);
if (!ffs_dev)
ffs_dev = ERR_PTR(-ENODEV);
else if (ffs_dev->mounted)
ffs_dev = ERR_PTR(-EBUSY);
else if (ffs_dev->ffs_acquire_dev_callback &&
ffs_dev->ffs_acquire_dev_callback(ffs_dev))
ffs_dev = ERR_PTR(-ENODEV);
else
ffs_dev->mounted = true;
ffs_dev_unlock();
return ffs_dev;
}
static void ffs_release_dev(struct ffs_data *ffs_data)
{
struct ffs_dev *ffs_dev;
ENTER();
ffs_dev_lock();
ffs_dev = ffs_data->private_data;
if (ffs_dev) {
ffs_dev->mounted = false;
if (ffs_dev->ffs_release_dev_callback)
ffs_dev->ffs_release_dev_callback(ffs_dev);
}
ffs_dev_unlock();
}
static int ffs_ready(struct ffs_data *ffs)
{
struct ffs_dev *ffs_obj;
int ret = 0;
ENTER();
ffs_dev_lock();
ffs_obj = ffs->private_data;
if (!ffs_obj) {
ret = -EINVAL;
goto done;
}
if (WARN_ON(ffs_obj->desc_ready)) {
ret = -EBUSY;
goto done;
}
ffs_obj->desc_ready = true;
ffs_obj->ffs_data = ffs;
if (ffs_obj->ffs_ready_callback)
ret = ffs_obj->ffs_ready_callback(ffs);
done:
ffs_dev_unlock();
return ret;
}
static void ffs_closed(struct ffs_data *ffs)
{
struct ffs_dev *ffs_obj;
ENTER();
ffs_dev_lock();
ffs_obj = ffs->private_data;
if (!ffs_obj)
goto done;
ffs_obj->desc_ready = false;
if (ffs_obj->ffs_closed_callback)
ffs_obj->ffs_closed_callback(ffs);
if (!ffs_obj->opts || ffs_obj->opts->no_configfs
|| !ffs_obj->opts->func_inst.group.cg_item.ci_parent)
goto done;
unregister_gadget_item(ffs_obj->opts->
func_inst.group.cg_item.ci_parent->ci_parent);
done:
ffs_dev_unlock();
}
static int ffs_mutex_lock(struct mutex *mutex, unsigned nonblock)
{
return nonblock
? likely(mutex_trylock(mutex)) ? 0 : -EAGAIN
: mutex_lock_interruptible(mutex);
}
static char *ffs_prepare_buffer(const char __user *buf, size_t len)
{
char *data;
if (unlikely(!len))
return NULL;
data = kmalloc(len, GFP_KERNEL);
if (unlikely(!data))
return ERR_PTR(-ENOMEM);
if (unlikely(__copy_from_user(data, buf, len))) {
kfree(data);
return ERR_PTR(-EFAULT);
}
pr_vdebug("Buffer from user space:\n");
ffs_dump_mem("", data, len);
return data;
}
