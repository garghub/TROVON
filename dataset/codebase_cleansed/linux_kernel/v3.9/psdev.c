static unsigned int coda_psdev_poll(struct file *file, poll_table * wait)
{
struct venus_comm *vcp = (struct venus_comm *) file->private_data;
unsigned int mask = POLLOUT | POLLWRNORM;
poll_wait(file, &vcp->vc_waitq, wait);
mutex_lock(&vcp->vc_mutex);
if (!list_empty(&vcp->vc_pending))
mask |= POLLIN | POLLRDNORM;
mutex_unlock(&vcp->vc_mutex);
return mask;
}
static long coda_psdev_ioctl(struct file * filp, unsigned int cmd, unsigned long arg)
{
unsigned int data;
switch(cmd) {
case CIOC_KERNEL_VERSION:
data = CODA_KERNEL_VERSION;
return put_user(data, (int __user *) arg);
default:
return -ENOTTY;
}
return 0;
}
static ssize_t coda_psdev_write(struct file *file, const char __user *buf,
size_t nbytes, loff_t *off)
{
struct venus_comm *vcp = (struct venus_comm *) file->private_data;
struct upc_req *req = NULL;
struct upc_req *tmp;
struct list_head *lh;
struct coda_in_hdr hdr;
ssize_t retval = 0, count = 0;
int error;
if (copy_from_user(&hdr, buf, 2 * sizeof(u_long)))
return -EFAULT;
if (DOWNCALL(hdr.opcode)) {
union outputArgs *dcbuf;
int size = sizeof(*dcbuf);
if ( nbytes < sizeof(struct coda_out_hdr) ) {
printk("coda_downcall opc %d uniq %d, not enough!\n",
hdr.opcode, hdr.unique);
count = nbytes;
goto out;
}
if ( nbytes > size ) {
printk("Coda: downcall opc %d, uniq %d, too much!",
hdr.opcode, hdr.unique);
nbytes = size;
}
CODA_ALLOC(dcbuf, union outputArgs *, nbytes);
if (copy_from_user(dcbuf, buf, nbytes)) {
CODA_FREE(dcbuf, nbytes);
retval = -EFAULT;
goto out;
}
error = coda_downcall(vcp, hdr.opcode, dcbuf);
CODA_FREE(dcbuf, nbytes);
if (error) {
printk("psdev_write: coda_downcall error: %d\n", error);
retval = error;
goto out;
}
count = nbytes;
goto out;
}
mutex_lock(&vcp->vc_mutex);
list_for_each(lh, &vcp->vc_processing) {
tmp = list_entry(lh, struct upc_req , uc_chain);
if (tmp->uc_unique == hdr.unique) {
req = tmp;
list_del(&req->uc_chain);
break;
}
}
mutex_unlock(&vcp->vc_mutex);
if (!req) {
printk("psdev_write: msg (%d, %d) not found\n",
hdr.opcode, hdr.unique);
retval = -ESRCH;
goto out;
}
if (req->uc_outSize < nbytes) {
printk("psdev_write: too much cnt: %d, cnt: %ld, opc: %d, uniq: %d.\n",
req->uc_outSize, (long)nbytes, hdr.opcode, hdr.unique);
nbytes = req->uc_outSize;
}
if (copy_from_user(req->uc_data, buf, nbytes)) {
req->uc_flags |= CODA_REQ_ABORT;
wake_up(&req->uc_sleep);
retval = -EFAULT;
goto out;
}
req->uc_outSize = nbytes;
req->uc_flags |= CODA_REQ_WRITE;
count = nbytes;
if (req->uc_opcode == CODA_OPEN_BY_FD) {
struct coda_open_by_fd_out *outp =
(struct coda_open_by_fd_out *)req->uc_data;
if (!outp->oh.result)
outp->fh = fget(outp->fd);
}
wake_up(&req->uc_sleep);
out:
return(count ? count : retval);
}
static ssize_t coda_psdev_read(struct file * file, char __user * buf,
size_t nbytes, loff_t *off)
{
DECLARE_WAITQUEUE(wait, current);
struct venus_comm *vcp = (struct venus_comm *) file->private_data;
struct upc_req *req;
ssize_t retval = 0, count = 0;
if (nbytes == 0)
return 0;
mutex_lock(&vcp->vc_mutex);
add_wait_queue(&vcp->vc_waitq, &wait);
set_current_state(TASK_INTERRUPTIBLE);
while (list_empty(&vcp->vc_pending)) {
if (file->f_flags & O_NONBLOCK) {
retval = -EAGAIN;
break;
}
if (signal_pending(current)) {
retval = -ERESTARTSYS;
break;
}
mutex_unlock(&vcp->vc_mutex);
schedule();
mutex_lock(&vcp->vc_mutex);
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&vcp->vc_waitq, &wait);
if (retval)
goto out;
req = list_entry(vcp->vc_pending.next, struct upc_req,uc_chain);
list_del(&req->uc_chain);
count = req->uc_inSize;
if (nbytes < req->uc_inSize) {
printk ("psdev_read: Venus read %ld bytes of %d in message\n",
(long)nbytes, req->uc_inSize);
count = nbytes;
}
if (copy_to_user(buf, req->uc_data, count))
retval = -EFAULT;
if (!(req->uc_flags & CODA_REQ_ASYNC)) {
req->uc_flags |= CODA_REQ_READ;
list_add_tail(&(req->uc_chain), &vcp->vc_processing);
goto out;
}
CODA_FREE(req->uc_data, sizeof(struct coda_in_hdr));
kfree(req);
out:
mutex_unlock(&vcp->vc_mutex);
return (count ? count : retval);
}
static int coda_psdev_open(struct inode * inode, struct file * file)
{
struct venus_comm *vcp;
int idx, err;
if (task_active_pid_ns(current) != &init_pid_ns)
return -EINVAL;
if (current_user_ns() != &init_user_ns)
return -EINVAL;
idx = iminor(inode);
if (idx < 0 || idx >= MAX_CODADEVS)
return -ENODEV;
err = -EBUSY;
vcp = &coda_comms[idx];
mutex_lock(&vcp->vc_mutex);
if (!vcp->vc_inuse) {
vcp->vc_inuse++;
INIT_LIST_HEAD(&vcp->vc_pending);
INIT_LIST_HEAD(&vcp->vc_processing);
init_waitqueue_head(&vcp->vc_waitq);
vcp->vc_sb = NULL;
vcp->vc_seq = 0;
file->private_data = vcp;
err = 0;
}
mutex_unlock(&vcp->vc_mutex);
return err;
}
static int coda_psdev_release(struct inode * inode, struct file * file)
{
struct venus_comm *vcp = (struct venus_comm *) file->private_data;
struct upc_req *req, *tmp;
if (!vcp || !vcp->vc_inuse ) {
printk("psdev_release: Not open.\n");
return -1;
}
mutex_lock(&vcp->vc_mutex);
list_for_each_entry_safe(req, tmp, &vcp->vc_pending, uc_chain) {
list_del(&req->uc_chain);
if (req->uc_flags & CODA_REQ_ASYNC) {
CODA_FREE(req->uc_data, sizeof(struct coda_in_hdr));
kfree(req);
continue;
}
req->uc_flags |= CODA_REQ_ABORT;
wake_up(&req->uc_sleep);
}
list_for_each_entry_safe(req, tmp, &vcp->vc_processing, uc_chain) {
list_del(&req->uc_chain);
req->uc_flags |= CODA_REQ_ABORT;
wake_up(&req->uc_sleep);
}
file->private_data = NULL;
vcp->vc_inuse--;
mutex_unlock(&vcp->vc_mutex);
return 0;
}
static int init_coda_psdev(void)
{
int i, err = 0;
if (register_chrdev(CODA_PSDEV_MAJOR, "coda", &coda_psdev_fops)) {
printk(KERN_ERR "coda_psdev: unable to get major %d\n",
CODA_PSDEV_MAJOR);
return -EIO;
}
coda_psdev_class = class_create(THIS_MODULE, "coda");
if (IS_ERR(coda_psdev_class)) {
err = PTR_ERR(coda_psdev_class);
goto out_chrdev;
}
for (i = 0; i < MAX_CODADEVS; i++) {
mutex_init(&(&coda_comms[i])->vc_mutex);
device_create(coda_psdev_class, NULL,
MKDEV(CODA_PSDEV_MAJOR, i), NULL, "cfs%d", i);
}
coda_sysctl_init();
goto out;
out_chrdev:
unregister_chrdev(CODA_PSDEV_MAJOR, "coda");
out:
return err;
}
static int __init init_coda(void)
{
int status;
int i;
status = coda_init_inodecache();
if (status)
goto out2;
status = init_coda_psdev();
if ( status ) {
printk("Problem (%d) in init_coda_psdev\n", status);
goto out1;
}
status = register_filesystem(&coda_fs_type);
if (status) {
printk("coda: failed to register filesystem!\n");
goto out;
}
return 0;
out:
for (i = 0; i < MAX_CODADEVS; i++)
device_destroy(coda_psdev_class, MKDEV(CODA_PSDEV_MAJOR, i));
class_destroy(coda_psdev_class);
unregister_chrdev(CODA_PSDEV_MAJOR, "coda");
coda_sysctl_clean();
out1:
coda_destroy_inodecache();
out2:
return status;
}
static void __exit exit_coda(void)
{
int err, i;
err = unregister_filesystem(&coda_fs_type);
if ( err != 0 ) {
printk("coda: failed to unregister filesystem\n");
}
for (i = 0; i < MAX_CODADEVS; i++)
device_destroy(coda_psdev_class, MKDEV(CODA_PSDEV_MAJOR, i));
class_destroy(coda_psdev_class);
unregister_chrdev(CODA_PSDEV_MAJOR, "coda");
coda_sysctl_clean();
coda_destroy_inodecache();
}
