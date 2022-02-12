static int mei_open(struct inode *inode, struct file *file)
{
struct mei_device *dev;
struct mei_cl *cl;
int err;
dev = container_of(inode->i_cdev, struct mei_device, cdev);
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
cl = NULL;
err = -ENODEV;
if (dev->dev_state != MEI_DEV_ENABLED) {
dev_dbg(dev->dev, "dev_state != MEI_ENABLED dev_state = %s\n",
mei_dev_state_str(dev->dev_state));
goto err_unlock;
}
err = -ENOMEM;
cl = mei_cl_allocate(dev);
if (!cl)
goto err_unlock;
err = mei_cl_link(cl, MEI_HOST_CLIENT_ID_ANY);
if (err)
goto err_unlock;
file->private_data = cl;
mutex_unlock(&dev->device_lock);
return nonseekable_open(inode, file);
err_unlock:
mutex_unlock(&dev->device_lock);
kfree(cl);
return err;
}
static int mei_release(struct inode *inode, struct file *file)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb;
struct mei_device *dev;
int rets = 0;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_release(dev, file);
goto out;
}
if (cl->state == MEI_FILE_CONNECTED) {
cl->state = MEI_FILE_DISCONNECTING;
cl_dbg(dev, cl, "disconnecting\n");
rets = mei_cl_disconnect(cl);
}
mei_cl_flush_queues(cl);
cl_dbg(dev, cl, "removing\n");
mei_cl_unlink(cl);
cb = NULL;
if (cl->read_cb) {
cb = mei_cl_find_read_cb(cl);
if (cb)
list_del(&cb->list);
cb = cl->read_cb;
cl->read_cb = NULL;
}
file->private_data = NULL;
mei_io_cb_free(cb);
kfree(cl);
out:
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_read(struct file *file, char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb_pos = NULL;
struct mei_cl_cb *cb = NULL;
struct mei_device *dev;
int rets;
int err;
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
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_read(dev, file, ubuf, length, offset);
goto out;
}
if (cl->read_cb) {
cb = cl->read_cb;
if (cb->buf_idx > *offset)
goto copy_buffer;
if (cb->buf_idx > 0 && cb->buf_idx <= *offset) {
rets = 0;
goto free;
}
if (cb->buf_idx == 0 && *offset > 0)
*offset = 0;
} else if (*offset > 0) {
*offset = 0;
}
err = mei_cl_read_start(cl, length);
if (err && err != -EBUSY) {
dev_dbg(dev->dev,
"mei start read failure with status = %d\n", err);
rets = err;
goto out;
}
if (MEI_READ_COMPLETE != cl->reading_state &&
!waitqueue_active(&cl->rx_wait)) {
if (file->f_flags & O_NONBLOCK) {
rets = -EAGAIN;
goto out;
}
mutex_unlock(&dev->device_lock);
if (wait_event_interruptible(cl->rx_wait,
MEI_READ_COMPLETE == cl->reading_state ||
mei_cl_is_transitioning(cl))) {
if (signal_pending(current))
return -EINTR;
return -ERESTARTSYS;
}
mutex_lock(&dev->device_lock);
if (mei_cl_is_transitioning(cl)) {
rets = -EBUSY;
goto out;
}
}
cb = cl->read_cb;
if (!cb) {
rets = -ENODEV;
goto out;
}
if (cl->reading_state != MEI_READ_COMPLETE) {
rets = 0;
goto out;
}
copy_buffer:
dev_dbg(dev->dev, "buf.size = %d buf.idx= %ld\n",
cb->response_buffer.size, cb->buf_idx);
if (length == 0 || ubuf == NULL || *offset > cb->buf_idx) {
rets = -EMSGSIZE;
goto free;
}
length = min_t(size_t, length, cb->buf_idx - *offset);
if (copy_to_user(ubuf, cb->response_buffer.data + *offset, length)) {
dev_dbg(dev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
goto free;
}
rets = length;
*offset += length;
if ((unsigned long)*offset < cb->buf_idx)
goto out;
free:
cb_pos = mei_cl_find_read_cb(cl);
if (cb_pos)
list_del(&cb_pos->list);
mei_io_cb_free(cb);
cl->reading_state = MEI_IDLE;
cl->read_cb = NULL;
out:
dev_dbg(dev->dev, "end mei read rets= %d\n", rets);
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_write(struct file *file, const char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_me_client *me_cl = NULL;
struct mei_cl_cb *write_cb = NULL;
struct mei_device *dev;
unsigned long timeout = 0;
int rets;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto out;
}
me_cl = mei_me_cl_by_uuid_id(dev, &cl->cl_uuid, cl->me_client_id);
if (!me_cl) {
rets = -ENOTTY;
goto out;
}
if (length == 0) {
rets = 0;
goto out;
}
if (length > me_cl->props.max_msg_length) {
rets = -EFBIG;
goto out;
}
if (cl->state != MEI_FILE_CONNECTED) {
dev_err(dev->dev, "host client = %d, is not connected to ME client = %d",
cl->host_client_id, cl->me_client_id);
rets = -ENODEV;
goto out;
}
if (cl == &dev->iamthif_cl) {
write_cb = mei_amthif_find_read_list_entry(dev, file);
if (write_cb) {
timeout = write_cb->read_time +
mei_secs_to_jiffies(MEI_IAMTHIF_READ_TIMER);
if (time_after(jiffies, timeout) ||
cl->reading_state == MEI_READ_COMPLETE) {
*offset = 0;
list_del(&write_cb->list);
mei_io_cb_free(write_cb);
write_cb = NULL;
}
}
}
if (cl->reading_state == MEI_READ_COMPLETE) {
*offset = 0;
write_cb = mei_cl_find_read_cb(cl);
if (write_cb) {
list_del(&write_cb->list);
mei_io_cb_free(write_cb);
write_cb = NULL;
cl->reading_state = MEI_IDLE;
cl->read_cb = NULL;
}
} else if (cl->reading_state == MEI_IDLE)
*offset = 0;
write_cb = mei_io_cb_init(cl, file);
if (!write_cb) {
rets = -ENOMEM;
goto out;
}
rets = mei_io_cb_alloc_req_buf(write_cb, length);
if (rets)
goto out;
rets = copy_from_user(write_cb->request_buffer.data, ubuf, length);
if (rets) {
dev_dbg(dev->dev, "failed to copy data from userland\n");
rets = -EFAULT;
goto out;
}
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_write(dev, write_cb);
if (rets) {
dev_err(dev->dev,
"amthif write failed with status = %d\n", rets);
goto out;
}
mei_me_cl_put(me_cl);
mutex_unlock(&dev->device_lock);
return length;
}
rets = mei_cl_write(cl, write_cb, false);
out:
mei_me_cl_put(me_cl);
mutex_unlock(&dev->device_lock);
if (rets < 0)
mei_io_cb_free(write_cb);
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
if (!me_cl || me_cl->props.fixed_address) {
dev_dbg(dev->dev, "Cannot connect to FW Client UUID = %pUl\n",
&data->in_client_uuid);
return -ENOTTY;
}
cl->me_client_id = me_cl->client_id;
cl->cl_uuid = me_cl->props.protocol_name;
dev_dbg(dev->dev, "Connect to FW Client ID = %d\n",
cl->me_client_id);
dev_dbg(dev->dev, "FW Client - Protocol Version = %d\n",
me_cl->props.protocol_version);
dev_dbg(dev->dev, "FW Client - Max Msg Len = %d\n",
me_cl->props.max_msg_length);
if (uuid_le_cmp(data->in_client_uuid, mei_amthif_guid) == 0) {
dev_dbg(dev->dev, "FW Client is amthi\n");
if (dev->iamthif_cl.state != MEI_FILE_CONNECTED) {
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
rets = mei_cl_connect(cl, file);
end:
mei_me_cl_put(me_cl);
return rets;
}
static long mei_ioctl(struct file *file, unsigned int cmd, unsigned long data)
{
struct mei_device *dev;
struct mei_cl *cl = file->private_data;
struct mei_connect_client_data connect_data;
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
struct mei_cl *cl = file->private_data;
struct mei_device *dev;
unsigned int mask = 0;
if (WARN_ON(!cl || !cl->dev))
return POLLERR;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (!mei_cl_is_connected(cl)) {
mask = POLLERR;
goto out;
}
mutex_unlock(&dev->device_lock);
if (cl == &dev->iamthif_cl)
return mei_amthif_poll(dev, file, wait);
poll_wait(file, &cl->tx_wait, wait);
mutex_lock(&dev->device_lock);
if (!mei_cl_is_connected(cl)) {
mask = POLLERR;
goto out;
}
mask |= (POLLIN | POLLRDNORM);
out:
mutex_unlock(&dev->device_lock);
return mask;
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
dev->cdev.owner = mei_fops.owner;
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
