static ssize_t vtpm_proxy_fops_read(struct file *filp, char __user *buf,
size_t count, loff_t *off)
{
struct proxy_dev *proxy_dev = filp->private_data;
size_t len;
int sig, rc;
sig = wait_event_interruptible(proxy_dev->wq,
proxy_dev->req_len != 0 ||
!(proxy_dev->state & STATE_OPENED_FLAG));
if (sig)
return -EINTR;
mutex_lock(&proxy_dev->buf_lock);
if (!(proxy_dev->state & STATE_OPENED_FLAG)) {
mutex_unlock(&proxy_dev->buf_lock);
return -EPIPE;
}
len = proxy_dev->req_len;
if (count < len) {
mutex_unlock(&proxy_dev->buf_lock);
pr_debug("Invalid size in recv: count=%zd, req_len=%zd\n",
count, len);
return -EIO;
}
rc = copy_to_user(buf, proxy_dev->buffer, len);
memset(proxy_dev->buffer, 0, len);
proxy_dev->req_len = 0;
if (!rc)
proxy_dev->state |= STATE_WAIT_RESPONSE_FLAG;
mutex_unlock(&proxy_dev->buf_lock);
if (rc)
return -EFAULT;
return len;
}
static ssize_t vtpm_proxy_fops_write(struct file *filp, const char __user *buf,
size_t count, loff_t *off)
{
struct proxy_dev *proxy_dev = filp->private_data;
mutex_lock(&proxy_dev->buf_lock);
if (!(proxy_dev->state & STATE_OPENED_FLAG)) {
mutex_unlock(&proxy_dev->buf_lock);
return -EPIPE;
}
if (count > sizeof(proxy_dev->buffer) ||
!(proxy_dev->state & STATE_WAIT_RESPONSE_FLAG)) {
mutex_unlock(&proxy_dev->buf_lock);
return -EIO;
}
proxy_dev->state &= ~STATE_WAIT_RESPONSE_FLAG;
proxy_dev->req_len = 0;
if (copy_from_user(proxy_dev->buffer, buf, count)) {
mutex_unlock(&proxy_dev->buf_lock);
return -EFAULT;
}
proxy_dev->resp_len = count;
mutex_unlock(&proxy_dev->buf_lock);
wake_up_interruptible(&proxy_dev->wq);
return count;
}
static unsigned int vtpm_proxy_fops_poll(struct file *filp, poll_table *wait)
{
struct proxy_dev *proxy_dev = filp->private_data;
unsigned ret;
poll_wait(filp, &proxy_dev->wq, wait);
ret = POLLOUT;
mutex_lock(&proxy_dev->buf_lock);
if (proxy_dev->req_len)
ret |= POLLIN | POLLRDNORM;
if (!(proxy_dev->state & STATE_OPENED_FLAG))
ret |= POLLHUP;
mutex_unlock(&proxy_dev->buf_lock);
return ret;
}
static void vtpm_proxy_fops_open(struct file *filp)
{
struct proxy_dev *proxy_dev = filp->private_data;
proxy_dev->state |= STATE_OPENED_FLAG;
}
static void vtpm_proxy_fops_undo_open(struct proxy_dev *proxy_dev)
{
mutex_lock(&proxy_dev->buf_lock);
proxy_dev->state &= ~STATE_OPENED_FLAG;
mutex_unlock(&proxy_dev->buf_lock);
wake_up_interruptible(&proxy_dev->wq);
}
static int vtpm_proxy_fops_release(struct inode *inode, struct file *filp)
{
struct proxy_dev *proxy_dev = filp->private_data;
filp->private_data = NULL;
vtpm_proxy_delete_device(proxy_dev);
return 0;
}
static int vtpm_proxy_tpm_op_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct proxy_dev *proxy_dev = dev_get_drvdata(&chip->dev);
size_t len;
mutex_lock(&proxy_dev->buf_lock);
if (!(proxy_dev->state & STATE_OPENED_FLAG)) {
mutex_unlock(&proxy_dev->buf_lock);
return -EPIPE;
}
len = proxy_dev->resp_len;
if (count < len) {
dev_err(&chip->dev,
"Invalid size in recv: count=%zd, resp_len=%zd\n",
count, len);
len = -EIO;
goto out;
}
memcpy(buf, proxy_dev->buffer, len);
proxy_dev->resp_len = 0;
out:
mutex_unlock(&proxy_dev->buf_lock);
return len;
}
static int vtpm_proxy_tpm_op_send(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct proxy_dev *proxy_dev = dev_get_drvdata(&chip->dev);
int rc = 0;
if (count > sizeof(proxy_dev->buffer)) {
dev_err(&chip->dev,
"Invalid size in send: count=%zd, buffer size=%zd\n",
count, sizeof(proxy_dev->buffer));
return -EIO;
}
mutex_lock(&proxy_dev->buf_lock);
if (!(proxy_dev->state & STATE_OPENED_FLAG)) {
mutex_unlock(&proxy_dev->buf_lock);
return -EPIPE;
}
proxy_dev->resp_len = 0;
proxy_dev->req_len = count;
memcpy(proxy_dev->buffer, buf, count);
proxy_dev->state &= ~STATE_WAIT_RESPONSE_FLAG;
mutex_unlock(&proxy_dev->buf_lock);
wake_up_interruptible(&proxy_dev->wq);
return rc;
}
static void vtpm_proxy_tpm_op_cancel(struct tpm_chip *chip)
{
}
static u8 vtpm_proxy_tpm_op_status(struct tpm_chip *chip)
{
struct proxy_dev *proxy_dev = dev_get_drvdata(&chip->dev);
if (proxy_dev->resp_len)
return VTPM_PROXY_REQ_COMPLETE_FLAG;
return 0;
}
static bool vtpm_proxy_tpm_req_canceled(struct tpm_chip *chip, u8 status)
{
struct proxy_dev *proxy_dev = dev_get_drvdata(&chip->dev);
bool ret;
mutex_lock(&proxy_dev->buf_lock);
ret = !(proxy_dev->state & STATE_OPENED_FLAG);
mutex_unlock(&proxy_dev->buf_lock);
return ret;
}
static void vtpm_proxy_work(struct work_struct *work)
{
struct proxy_dev *proxy_dev = container_of(work, struct proxy_dev,
work);
int rc;
rc = tpm_chip_register(proxy_dev->chip);
if (rc)
vtpm_proxy_fops_undo_open(proxy_dev);
else
proxy_dev->state |= STATE_REGISTERED_FLAG;
}
static void vtpm_proxy_work_stop(struct proxy_dev *proxy_dev)
{
vtpm_proxy_fops_undo_open(proxy_dev);
flush_work(&proxy_dev->work);
}
static inline void vtpm_proxy_work_start(struct proxy_dev *proxy_dev)
{
queue_work(workqueue, &proxy_dev->work);
}
static struct proxy_dev *vtpm_proxy_create_proxy_dev(void)
{
struct proxy_dev *proxy_dev;
struct tpm_chip *chip;
int err;
proxy_dev = kzalloc(sizeof(*proxy_dev), GFP_KERNEL);
if (proxy_dev == NULL)
return ERR_PTR(-ENOMEM);
init_waitqueue_head(&proxy_dev->wq);
mutex_init(&proxy_dev->buf_lock);
INIT_WORK(&proxy_dev->work, vtpm_proxy_work);
chip = tpm_chip_alloc(NULL, &vtpm_proxy_tpm_ops);
if (IS_ERR(chip)) {
err = PTR_ERR(chip);
goto err_proxy_dev_free;
}
dev_set_drvdata(&chip->dev, proxy_dev);
proxy_dev->chip = chip;
return proxy_dev;
err_proxy_dev_free:
kfree(proxy_dev);
return ERR_PTR(err);
}
static inline void vtpm_proxy_delete_proxy_dev(struct proxy_dev *proxy_dev)
{
put_device(&proxy_dev->chip->dev);
kfree(proxy_dev);
}
static struct file *vtpm_proxy_create_device(
struct vtpm_proxy_new_dev *vtpm_new_dev)
{
struct proxy_dev *proxy_dev;
int rc, fd;
struct file *file;
if (vtpm_new_dev->flags & ~VTPM_PROXY_FLAGS_ALL)
return ERR_PTR(-EOPNOTSUPP);
proxy_dev = vtpm_proxy_create_proxy_dev();
if (IS_ERR(proxy_dev))
return ERR_CAST(proxy_dev);
proxy_dev->flags = vtpm_new_dev->flags;
fd = get_unused_fd_flags(O_RDWR);
if (fd < 0) {
rc = fd;
goto err_delete_proxy_dev;
}
file = anon_inode_getfile("[vtpms]", &vtpm_proxy_fops, proxy_dev,
O_RDWR);
if (IS_ERR(file)) {
rc = PTR_ERR(file);
goto err_put_unused_fd;
}
vtpm_proxy_fops_open(file);
if (proxy_dev->flags & VTPM_PROXY_FLAG_TPM2)
proxy_dev->chip->flags |= TPM_CHIP_FLAG_TPM2;
vtpm_proxy_work_start(proxy_dev);
vtpm_new_dev->fd = fd;
vtpm_new_dev->major = MAJOR(proxy_dev->chip->dev.devt);
vtpm_new_dev->minor = MINOR(proxy_dev->chip->dev.devt);
vtpm_new_dev->tpm_num = proxy_dev->chip->dev_num;
return file;
err_put_unused_fd:
put_unused_fd(fd);
err_delete_proxy_dev:
vtpm_proxy_delete_proxy_dev(proxy_dev);
return ERR_PTR(rc);
}
static void vtpm_proxy_delete_device(struct proxy_dev *proxy_dev)
{
vtpm_proxy_work_stop(proxy_dev);
vtpm_proxy_fops_undo_open(proxy_dev);
if (proxy_dev->state & STATE_REGISTERED_FLAG)
tpm_chip_unregister(proxy_dev->chip);
vtpm_proxy_delete_proxy_dev(proxy_dev);
}
static long vtpmx_ioc_new_dev(struct file *file, unsigned int ioctl,
unsigned long arg)
{
void __user *argp = (void __user *)arg;
struct vtpm_proxy_new_dev __user *vtpm_new_dev_p;
struct vtpm_proxy_new_dev vtpm_new_dev;
struct file *vtpm_file;
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
vtpm_new_dev_p = argp;
if (copy_from_user(&vtpm_new_dev, vtpm_new_dev_p,
sizeof(vtpm_new_dev)))
return -EFAULT;
vtpm_file = vtpm_proxy_create_device(&vtpm_new_dev);
if (IS_ERR(vtpm_file))
return PTR_ERR(vtpm_file);
if (copy_to_user(vtpm_new_dev_p, &vtpm_new_dev,
sizeof(vtpm_new_dev))) {
put_unused_fd(vtpm_new_dev.fd);
fput(vtpm_file);
return -EFAULT;
}
fd_install(vtpm_new_dev.fd, vtpm_file);
return 0;
}
static long vtpmx_fops_ioctl(struct file *f, unsigned int ioctl,
unsigned long arg)
{
switch (ioctl) {
case VTPM_PROXY_IOC_NEW_DEV:
return vtpmx_ioc_new_dev(f, ioctl, arg);
default:
return -ENOIOCTLCMD;
}
}
static long vtpmx_fops_compat_ioctl(struct file *f, unsigned int ioctl,
unsigned long arg)
{
return vtpmx_fops_ioctl(f, ioctl, (unsigned long)compat_ptr(arg));
}
static int vtpmx_init(void)
{
return misc_register(&vtpmx_miscdev);
}
static void vtpmx_cleanup(void)
{
misc_deregister(&vtpmx_miscdev);
}
static int __init vtpm_module_init(void)
{
int rc;
rc = vtpmx_init();
if (rc) {
pr_err("couldn't create vtpmx device\n");
return rc;
}
workqueue = create_workqueue("tpm-vtpm");
if (!workqueue) {
pr_err("couldn't create workqueue\n");
rc = -ENOMEM;
goto err_vtpmx_cleanup;
}
return 0;
err_vtpmx_cleanup:
vtpmx_cleanup();
return rc;
}
static void __exit vtpm_module_exit(void)
{
destroy_workqueue(workqueue);
vtpmx_cleanup();
}
