static int mei_open(struct inode *inode, struct file *file)
{
struct mei_device *dev;
struct mei_cl *cl;
int err;
dev = container_of(inode->i_cdev, struct mei_device, cdev);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
dev_dbg(dev->dev, "dev_state != MEI_ENABLED dev_state = %s\n",
mei_dev_state_str(dev->dev_state));
err = -ENODEV;
goto err_unlock;
}
cl = mei_cl_alloc_linked(dev);
if (IS_ERR(cl)) {
err = PTR_ERR(cl);
goto err_unlock;
}
cl->fp = file;
file->private_data = cl;
mutex_unlock(&dev->device_lock);
return nonseekable_open(inode, file);
err_unlock:
mutex_unlock(&dev->device_lock);
return err;
}
static int mei_release(struct inode *inode, struct file *file)
{
struct mei_cl *cl = file->private_data;
struct mei_device *dev;
int rets;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_release(dev, file);
goto out;
}
rets = mei_cl_disconnect(cl);
mei_cl_flush_queues(cl, file);
cl_dbg(dev, cl, "removing\n");
mei_cl_unlink(cl);
file->private_data = NULL;
kfree(cl);
out:
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_read(struct file *file, char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_device *dev;
struct mei_cl_cb *cb = NULL;
bool nonblock = !!(file->f_flags & O_NONBLOCK);
int rets;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto out;
}
if (length == 0) {
rets = 0;
goto out;
}
if (ubuf == NULL) {
rets = -EMSGSIZE;
goto out;
}
cb = mei_cl_read_cb(cl, file);
if (cb)
goto copy_buffer;
if (*offset > 0)
*offset = 0;
rets = mei_cl_read_start(cl, length, file);
if (rets && rets != -EBUSY) {
cl_dbg(dev, cl, "mei start read failure status = %d\n", rets);
goto out;
}
if (nonblock) {
rets = -EAGAIN;
goto out;
}
if (rets == -EBUSY &&
!mei_cl_enqueue_ctrl_wr_cb(cl, length, MEI_FOP_READ, file)) {
rets = -ENOMEM;
goto out;
}
do {
mutex_unlock(&dev->device_lock);
if (wait_event_interruptible(cl->rx_wait,
(!list_empty(&cl->rd_completed)) ||
(!mei_cl_is_connected(cl)))) {
if (signal_pending(current))
return -EINTR;
return -ERESTARTSYS;
}
mutex_lock(&dev->device_lock);
if (!mei_cl_is_connected(cl)) {
rets = -ENODEV;
goto out;
}
cb = mei_cl_read_cb(cl, file);
} while (!cb);
copy_buffer:
if (cb->status) {
rets = cb->status;
cl_dbg(dev, cl, "read operation failed %d\n", rets);
goto free;
}
cl_dbg(dev, cl, "buf.size = %zu buf.idx = %zu offset = %lld\n",
cb->buf.size, cb->buf_idx, *offset);
if (*offset >= cb->buf_idx) {
rets = 0;
goto free;
}
length = min_t(size_t, length, cb->buf_idx - *offset);
if (copy_to_user(ubuf, cb->buf.data + *offset, length)) {
dev_dbg(dev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
goto free;
}
rets = length;
*offset += length;
if (*offset < cb->buf_idx)
goto out;
free:
mei_io_cb_free(cb);
*offset = 0;
out:
cl_dbg(dev, cl, "end mei read rets = %d\n", rets);
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_write(struct file *file, const char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb;
struct mei_device *dev;
int rets;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto out;
}
if (!mei_cl_is_connected(cl)) {
cl_err(dev, cl, "is not connected");
rets = -ENODEV;
goto out;
}
if (!mei_me_cl_is_active(cl->me_cl)) {
rets = -ENOTTY;
goto out;
}
if (length > mei_cl_mtu(cl)) {
rets = -EFBIG;
goto out;
}
if (length == 0) {
rets = 0;
goto out;
}
*offset = 0;
cb = mei_cl_alloc_cb(cl, length, MEI_FOP_WRITE, file);
if (!cb) {
rets = -ENOMEM;
goto out;
}
rets = copy_from_user(cb->buf.data, ubuf, length);
if (rets) {
dev_dbg(dev->dev, "failed to copy data from userland\n");
rets = -EFAULT;
mei_io_cb_free(cb);
goto out;
}
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_write(cl, cb);
if (!rets)
rets = length;
goto out;
}
rets = mei_cl_write(cl, cb, false);
out:
mutex_unlock(&dev->device_lock);
return rets;
}
static int mei_ioctl_connect_client(struct file *file,
struct mei_connect_client_data *data)
{
struct mei_device *dev;
struct mei_client *client;
struct mei_me_client *me_cl;
struct mei_cl *cl;
int rets;
cl = file->private_data;
dev = cl->dev;
if (dev->dev_state != MEI_DEV_ENABLED)
return -ENODEV;
if (cl->state != MEI_FILE_INITIALIZING &&
cl->state != MEI_FILE_DISCONNECTED)
return -EBUSY;
me_cl = mei_me_cl_by_uuid(dev, &data->in_client_uuid);
if (!me_cl) {
dev_dbg(dev->dev, "Cannot connect to FW Client UUID = %pUl\n",
&data->in_client_uuid);
rets = -ENOTTY;
goto end;
}
if (me_cl->props.fixed_address) {
bool forbidden = dev->override_fixed_address ?
!dev->allow_fixed_address : !dev->hbm_f_fa_supported;
if (forbidden) {
dev_dbg(dev->dev, "Connection forbidden to FW Client UUID = %pUl\n",
&data->in_client_uuid);
rets = -ENOTTY;
goto end;
}
}
dev_dbg(dev->dev, "Connect to FW Client ID = %d\n",
me_cl->client_id);
dev_dbg(dev->dev, "FW Client - Protocol Version = %d\n",
me_cl->props.protocol_version);
dev_dbg(dev->dev, "FW Client - Max Msg Len = %d\n",
me_cl->props.max_msg_length);
if (uuid_le_cmp(data->in_client_uuid, mei_amthif_guid) == 0) {
dev_dbg(dev->dev, "FW Client is amthi\n");
if (!mei_cl_is_connected(&dev->iamthif_cl)) {
rets = -ENODEV;
goto end;
}
mei_cl_unlink(cl);
kfree(cl);
cl = NULL;
dev->iamthif_open_count++;
file->private_data = &dev->iamthif_cl;
client = &data->out_client_properties;
client->max_msg_length = me_cl->props.max_msg_length;
client->protocol_version = me_cl->props.protocol_version;
rets = dev->iamthif_cl.status;
goto end;
}
client = &data->out_client_properties;
client->max_msg_length = me_cl->props.max_msg_length;
client->protocol_version = me_cl->props.protocol_version;
dev_dbg(dev->dev, "Can connect?\n");
rets = mei_cl_connect(cl, me_cl, file);
end:
mei_me_cl_put(me_cl);
return rets;
}
static int mei_ioctl_client_notify_request(const struct file *file, u32 request)
{
struct mei_cl *cl = file->private_data;
if (request != MEI_HBM_NOTIFICATION_START &&
request != MEI_HBM_NOTIFICATION_STOP)
return -EINVAL;
return mei_cl_notify_request(cl, file, (u8)request);
}
static int mei_ioctl_client_notify_get(const struct file *file, u32 *notify_get)
{
struct mei_cl *cl = file->private_data;
bool notify_ev;
bool block = (file->f_flags & O_NONBLOCK) == 0;
int rets;
rets = mei_cl_notify_get(cl, block, &notify_ev);
if (rets)
return rets;
*notify_get = notify_ev ? 1 : 0;
return 0;
}
static long mei_ioctl(struct file *file, unsigned int cmd, unsigned long data)
{
struct mei_device *dev;
struct mei_cl *cl = file->private_data;
struct mei_connect_client_data connect_data;
u32 notify_get, notify_req;
int rets;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
dev_dbg(dev->dev, "IOCTL cmd = 0x%x", cmd);
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto out;
}
switch (cmd) {
case IOCTL_MEI_CONNECT_CLIENT:
dev_dbg(dev->dev, ": IOCTL_MEI_CONNECT_CLIENT.\n");
if (copy_from_user(&connect_data, (char __user *)data,
sizeof(struct mei_connect_client_data))) {
dev_dbg(dev->dev, "failed to copy data from userland\n");
rets = -EFAULT;
goto out;
}
rets = mei_ioctl_connect_client(file, &connect_data);
if (rets)
goto out;
if (copy_to_user((char __user *)data, &connect_data,
sizeof(struct mei_connect_client_data))) {
dev_dbg(dev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
goto out;
}
break;
case IOCTL_MEI_NOTIFY_SET:
dev_dbg(dev->dev, ": IOCTL_MEI_NOTIFY_SET.\n");
if (copy_from_user(&notify_req,
(char __user *)data, sizeof(notify_req))) {
dev_dbg(dev->dev, "failed to copy data from userland\n");
rets = -EFAULT;
goto out;
}
rets = mei_ioctl_client_notify_request(file, notify_req);
break;
case IOCTL_MEI_NOTIFY_GET:
dev_dbg(dev->dev, ": IOCTL_MEI_NOTIFY_GET.\n");
rets = mei_ioctl_client_notify_get(file, &notify_get);
if (rets)
goto out;
dev_dbg(dev->dev, "copy connect data to user\n");
if (copy_to_user((char __user *)data,
&notify_get, sizeof(notify_get))) {
dev_dbg(dev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
goto out;
}
break;
default:
dev_err(dev->dev, ": unsupported ioctl %d.\n", cmd);
rets = -ENOIOCTLCMD;
}
out:
mutex_unlock(&dev->device_lock);
return rets;
}
static long mei_compat_ioctl(struct file *file,
unsigned int cmd, unsigned long data)
{
return mei_ioctl(file, cmd, (unsigned long)compat_ptr(data));
}
static unsigned int mei_poll(struct file *file, poll_table *wait)
{
unsigned long req_events = poll_requested_events(wait);
struct mei_cl *cl = file->private_data;
struct mei_device *dev;
unsigned int mask = 0;
bool notify_en;
if (WARN_ON(!cl || !cl->dev))
return POLLERR;
dev = cl->dev;
mutex_lock(&dev->device_lock);
notify_en = cl->notify_en && (req_events & POLLPRI);
if (dev->dev_state != MEI_DEV_ENABLED ||
!mei_cl_is_connected(cl)) {
mask = POLLERR;
goto out;
}
if (notify_en) {
poll_wait(file, &cl->ev_wait, wait);
if (cl->notify_ev)
mask |= POLLPRI;
}
if (cl == &dev->iamthif_cl) {
mask |= mei_amthif_poll(file, wait);
goto out;
}
if (req_events & (POLLIN | POLLRDNORM)) {
poll_wait(file, &cl->rx_wait, wait);
if (!list_empty(&cl->rd_completed))
mask |= POLLIN | POLLRDNORM;
else
mei_cl_read_start(cl, mei_cl_mtu(cl), file);
}
out:
mutex_unlock(&dev->device_lock);
return mask;
}
static int mei_fasync(int fd, struct file *file, int band)
{
struct mei_cl *cl = file->private_data;
if (!mei_cl_is_connected(cl))
return -ENODEV;
return fasync_helper(fd, file, band, &cl->ev_async);
}
static ssize_t fw_status_show(struct device *device,
struct device_attribute *attr, char *buf)
{
struct mei_device *dev = dev_get_drvdata(device);
struct mei_fw_status fw_status;
int err, i;
ssize_t cnt = 0;
mutex_lock(&dev->device_lock);
err = mei_fw_status(dev, &fw_status);
mutex_unlock(&dev->device_lock);
if (err) {
dev_err(device, "read fw_status error = %d\n", err);
return err;
}
for (i = 0; i < fw_status.count; i++)
cnt += scnprintf(buf + cnt, PAGE_SIZE - cnt, "%08X\n",
fw_status.status[i]);
return cnt;
}
static int mei_minor_get(struct mei_device *dev)
{
int ret;
mutex_lock(&mei_minor_lock);
ret = idr_alloc(&mei_idr, dev, 0, MEI_MAX_DEVS, GFP_KERNEL);
if (ret >= 0)
dev->minor = ret;
else if (ret == -ENOSPC)
dev_err(dev->dev, "too many mei devices\n");
mutex_unlock(&mei_minor_lock);
return ret;
}
static void mei_minor_free(struct mei_device *dev)
{
mutex_lock(&mei_minor_lock);
idr_remove(&mei_idr, dev->minor);
mutex_unlock(&mei_minor_lock);
}
int mei_register(struct mei_device *dev, struct device *parent)
{
struct device *clsdev;
int ret, devno;
ret = mei_minor_get(dev);
if (ret < 0)
return ret;
devno = MKDEV(MAJOR(mei_devt), dev->minor);
cdev_init(&dev->cdev, &mei_fops);
dev->cdev.owner = parent->driver->owner;
ret = cdev_add(&dev->cdev, devno, 1);
if (ret) {
dev_err(parent, "unable to add device %d:%d\n",
MAJOR(mei_devt), dev->minor);
goto err_dev_add;
}
clsdev = device_create_with_groups(mei_class, parent, devno,
dev, mei_groups,
"mei%d", dev->minor);
if (IS_ERR(clsdev)) {
dev_err(parent, "unable to create device %d:%d\n",
MAJOR(mei_devt), dev->minor);
ret = PTR_ERR(clsdev);
goto err_dev_create;
}
ret = mei_dbgfs_register(dev, dev_name(clsdev));
if (ret) {
dev_err(clsdev, "cannot register debugfs ret = %d\n", ret);
goto err_dev_dbgfs;
}
return 0;
err_dev_dbgfs:
device_destroy(mei_class, devno);
err_dev_create:
cdev_del(&dev->cdev);
err_dev_add:
mei_minor_free(dev);
return ret;
}
void mei_deregister(struct mei_device *dev)
{
int devno;
devno = dev->cdev.dev;
cdev_del(&dev->cdev);
mei_dbgfs_deregister(dev);
device_destroy(mei_class, devno);
mei_minor_free(dev);
}
static int __init mei_init(void)
{
int ret;
mei_class = class_create(THIS_MODULE, "mei");
if (IS_ERR(mei_class)) {
pr_err("couldn't create class\n");
ret = PTR_ERR(mei_class);
goto err;
}
ret = alloc_chrdev_region(&mei_devt, 0, MEI_MAX_DEVS, "mei");
if (ret < 0) {
pr_err("unable to allocate char dev region\n");
goto err_class;
}
ret = mei_cl_bus_init();
if (ret < 0) {
pr_err("unable to initialize bus\n");
goto err_chrdev;
}
return 0;
err_chrdev:
unregister_chrdev_region(mei_devt, MEI_MAX_DEVS);
err_class:
class_destroy(mei_class);
err:
return ret;
}
static void __exit mei_exit(void)
{
unregister_chrdev_region(mei_devt, MEI_MAX_DEVS);
class_destroy(mei_class);
mei_cl_bus_exit();
}
