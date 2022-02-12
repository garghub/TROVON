static int mei_open(struct inode *inode, struct file *file)
{
struct miscdevice *misc = file->private_data;
struct pci_dev *pdev;
struct mei_cl *cl;
struct mei_device *dev;
int err;
err = -ENODEV;
if (!misc->parent)
goto out;
pdev = container_of(misc->parent, struct pci_dev, dev);
dev = pci_get_drvdata(pdev);
if (!dev)
goto out;
mutex_lock(&dev->device_lock);
err = -ENOMEM;
cl = mei_cl_allocate(dev);
if (!cl)
goto out_unlock;
err = -ENODEV;
if (dev->dev_state != MEI_DEV_ENABLED) {
dev_dbg(&dev->pdev->dev, "dev_state != MEI_ENABLED dev_state = %s\n",
mei_dev_state_str(dev->dev_state));
goto out_unlock;
}
err = -EMFILE;
if (dev->open_handle_count >= MEI_MAX_OPEN_HANDLE_COUNT) {
dev_err(&dev->pdev->dev, "open_handle_count exceded %d",
MEI_MAX_OPEN_HANDLE_COUNT);
goto out_unlock;
}
err = mei_cl_link(cl, MEI_HOST_CLIENT_ID_ANY);
if (err)
goto out_unlock;
file->private_data = cl;
mutex_unlock(&dev->device_lock);
return nonseekable_open(inode, file);
out_unlock:
mutex_unlock(&dev->device_lock);
kfree(cl);
out:
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
dev_dbg(&dev->pdev->dev,
"disconnecting client host client = %d, "
"ME client = %d\n",
cl->host_client_id,
cl->me_client_id);
rets = mei_cl_disconnect(cl);
}
mei_cl_flush_queues(cl);
dev_dbg(&dev->pdev->dev, "remove client host client = %d, ME client = %d\n",
cl->host_client_id,
cl->me_client_id);
if (dev->open_handle_count > 0) {
clear_bit(cl->host_client_id, dev->host_clients_map);
dev->open_handle_count--;
}
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
if (cb) {
mei_io_cb_free(cb);
cb = NULL;
}
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
int i;
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
if ((cl->sm_state & MEI_WD_STATE_INDEPENDENCE_MSG_SENT) == 0) {
i = mei_me_cl_by_uuid(dev, &mei_wd_guid);
if (i >= 0) {
struct mei_me_client *me_client = &dev->me_clients[i];
if (cl->me_client_id == me_client->client_id) {
rets = -EBADF;
goto out;
}
}
} else {
cl->sm_state &= ~MEI_WD_STATE_INDEPENDENCE_MSG_SENT;
}
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_read(dev, file, ubuf, length, offset);
goto out;
}
if (cl->read_cb && cl->read_cb->buf_idx > *offset) {
cb = cl->read_cb;
goto copy_buffer;
} else if (cl->read_cb && cl->read_cb->buf_idx > 0 &&
cl->read_cb->buf_idx <= *offset) {
cb = cl->read_cb;
rets = 0;
goto free;
} else if ((!cl->read_cb || !cl->read_cb->buf_idx) && *offset > 0) {
*offset = 0;
rets = 0;
goto out;
}
err = mei_cl_read_start(cl);
if (err && err != -EBUSY) {
dev_dbg(&dev->pdev->dev,
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
(MEI_READ_COMPLETE == cl->reading_state ||
MEI_FILE_INITIALIZING == cl->state ||
MEI_FILE_DISCONNECTED == cl->state ||
MEI_FILE_DISCONNECTING == cl->state))) {
if (signal_pending(current))
return -EINTR;
return -ERESTARTSYS;
}
mutex_lock(&dev->device_lock);
if (MEI_FILE_INITIALIZING == cl->state ||
MEI_FILE_DISCONNECTED == cl->state ||
MEI_FILE_DISCONNECTING == cl->state) {
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
dev_dbg(&dev->pdev->dev, "cb->response_buffer size - %d\n",
cb->response_buffer.size);
dev_dbg(&dev->pdev->dev, "cb->buf_idx - %lu\n", cb->buf_idx);
if (length == 0 || ubuf == NULL || *offset > cb->buf_idx) {
rets = -EMSGSIZE;
goto free;
}
length = min_t(size_t, length, cb->buf_idx - *offset);
if (copy_to_user(ubuf, cb->response_buffer.data + *offset, length)) {
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
dev_dbg(&dev->pdev->dev, "end mei read rets= %d\n", rets);
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_write(struct file *file, const char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *write_cb = NULL;
struct mei_msg_hdr mei_hdr;
struct mei_device *dev;
unsigned long timeout = 0;
int rets;
int i;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto err;
}
i = mei_me_cl_by_id(dev, cl->me_client_id);
if (i < 0) {
rets = -ENODEV;
goto err;
}
if (length > dev->me_clients[i].props.max_msg_length || length <= 0) {
rets = -EMSGSIZE;
goto err;
}
if (cl->state != MEI_FILE_CONNECTED) {
rets = -ENODEV;
dev_err(&dev->pdev->dev, "host client = %d, is not connected to ME client = %d",
cl->host_client_id, cl->me_client_id);
goto err;
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
dev_err(&dev->pdev->dev, "write cb allocation failed\n");
rets = -ENOMEM;
goto err;
}
rets = mei_io_cb_alloc_req_buf(write_cb, length);
if (rets)
goto err;
dev_dbg(&dev->pdev->dev, "cb request size = %zd\n", length);
rets = copy_from_user(write_cb->request_buffer.data, ubuf, length);
if (rets)
goto err;
cl->sm_state = 0;
if (length == 4 &&
((memcmp(mei_wd_state_independence_msg[0],
write_cb->request_buffer.data, 4) == 0) ||
(memcmp(mei_wd_state_independence_msg[1],
write_cb->request_buffer.data, 4) == 0) ||
(memcmp(mei_wd_state_independence_msg[2],
write_cb->request_buffer.data, 4) == 0)))
cl->sm_state |= MEI_WD_STATE_INDEPENDENCE_MSG_SENT;
if (cl == &dev->iamthif_cl) {
rets = mei_amthif_write(dev, write_cb);
if (rets) {
dev_err(&dev->pdev->dev,
"amthif write failed with status = %d\n", rets);
goto err;
}
mutex_unlock(&dev->device_lock);
return length;
}
write_cb->fop_type = MEI_FOP_WRITE;
dev_dbg(&dev->pdev->dev, "host client = %d, ME client = %d\n",
cl->host_client_id, cl->me_client_id);
rets = mei_cl_flow_ctrl_creds(cl);
if (rets < 0)
goto err;
if (rets == 0 || !dev->hbuf_is_ready) {
write_cb->buf_idx = 0;
mei_hdr.msg_complete = 0;
cl->writing_state = MEI_WRITING;
goto out;
}
dev->hbuf_is_ready = false;
if (length > mei_hbuf_max_len(dev)) {
mei_hdr.length = mei_hbuf_max_len(dev);
mei_hdr.msg_complete = 0;
} else {
mei_hdr.length = length;
mei_hdr.msg_complete = 1;
}
mei_hdr.host_addr = cl->host_client_id;
mei_hdr.me_addr = cl->me_client_id;
mei_hdr.reserved = 0;
dev_dbg(&dev->pdev->dev, "write " MEI_HDR_FMT "\n",
MEI_HDR_PRM(&mei_hdr));
if (mei_write_message(dev, &mei_hdr, write_cb->request_buffer.data)) {
rets = -ENODEV;
goto err;
}
cl->writing_state = MEI_WRITING;
write_cb->buf_idx = mei_hdr.length;
out:
if (mei_hdr.msg_complete) {
if (mei_cl_flow_ctrl_reduce(cl)) {
rets = -ENODEV;
goto err;
}
list_add_tail(&write_cb->list, &dev->write_waiting_list.list);
} else {
list_add_tail(&write_cb->list, &dev->write_list.list);
}
mutex_unlock(&dev->device_lock);
return length;
err:
mutex_unlock(&dev->device_lock);
mei_io_cb_free(write_cb);
return rets;
}
static int mei_ioctl_connect_client(struct file *file,
struct mei_connect_client_data *data)
{
struct mei_device *dev;
struct mei_client *client;
struct mei_cl *cl;
int i;
int rets;
cl = file->private_data;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto end;
}
if (cl->state != MEI_FILE_INITIALIZING &&
cl->state != MEI_FILE_DISCONNECTED) {
rets = -EBUSY;
goto end;
}
i = mei_me_cl_by_uuid(dev, &data->in_client_uuid);
if (i >= 0 && !dev->me_clients[i].props.fixed_address) {
cl->me_client_id = dev->me_clients[i].client_id;
cl->state = MEI_FILE_CONNECTING;
}
dev_dbg(&dev->pdev->dev, "Connect to FW Client ID = %d\n",
cl->me_client_id);
dev_dbg(&dev->pdev->dev, "FW Client - Protocol Version = %d\n",
dev->me_clients[i].props.protocol_version);
dev_dbg(&dev->pdev->dev, "FW Client - Max Msg Len = %d\n",
dev->me_clients[i].props.max_msg_length);
if (uuid_le_cmp(data->in_client_uuid, mei_amthif_guid) == 0) {
dev_dbg(&dev->pdev->dev, "FW Client is amthi\n");
if (dev->iamthif_cl.state != MEI_FILE_CONNECTED) {
rets = -ENODEV;
goto end;
}
clear_bit(cl->host_client_id, dev->host_clients_map);
mei_cl_unlink(cl);
kfree(cl);
cl = NULL;
file->private_data = &dev->iamthif_cl;
client = &data->out_client_properties;
client->max_msg_length =
dev->me_clients[i].props.max_msg_length;
client->protocol_version =
dev->me_clients[i].props.protocol_version;
rets = dev->iamthif_cl.status;
goto end;
}
if (cl->state != MEI_FILE_CONNECTING) {
rets = -ENODEV;
goto end;
}
client = &data->out_client_properties;
client->max_msg_length = dev->me_clients[i].props.max_msg_length;
client->protocol_version = dev->me_clients[i].props.protocol_version;
dev_dbg(&dev->pdev->dev, "Can connect?\n");
rets = mei_cl_connect(cl, file);
end:
dev_dbg(&dev->pdev->dev, "free connect cb memory.");
return rets;
}
static long mei_ioctl(struct file *file, unsigned int cmd, unsigned long data)
{
struct mei_device *dev;
struct mei_cl *cl = file->private_data;
struct mei_connect_client_data *connect_data = NULL;
int rets;
if (cmd != IOCTL_MEI_CONNECT_CLIENT)
return -EINVAL;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
dev_dbg(&dev->pdev->dev, "IOCTL cmd = 0x%x", cmd);
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED) {
rets = -ENODEV;
goto out;
}
dev_dbg(&dev->pdev->dev, ": IOCTL_MEI_CONNECT_CLIENT.\n");
connect_data = kzalloc(sizeof(struct mei_connect_client_data),
GFP_KERNEL);
if (!connect_data) {
rets = -ENOMEM;
goto out;
}
dev_dbg(&dev->pdev->dev, "copy connect data from user\n");
if (copy_from_user(connect_data, (char __user *)data,
sizeof(struct mei_connect_client_data))) {
dev_dbg(&dev->pdev->dev, "failed to copy data from userland\n");
rets = -EFAULT;
goto out;
}
rets = mei_ioctl_connect_client(file, connect_data);
if (rets)
goto out;
dev_dbg(&dev->pdev->dev, "copy connect data to user\n");
if (copy_to_user((char __user *)data, connect_data,
sizeof(struct mei_connect_client_data))) {
dev_dbg(&dev->pdev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
goto out;
}
out:
kfree(connect_data);
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
return mask;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->dev_state != MEI_DEV_ENABLED)
goto out;
if (cl == &dev->iamthif_cl) {
mask = mei_amthif_poll(dev, file, wait);
goto out;
}
mutex_unlock(&dev->device_lock);
poll_wait(file, &cl->tx_wait, wait);
mutex_lock(&dev->device_lock);
if (MEI_WRITE_COMPLETE == cl->writing_state)
mask |= (POLLIN | POLLRDNORM);
out:
mutex_unlock(&dev->device_lock);
return mask;
}
int mei_register(struct device *dev)
{
mei_misc_device.parent = dev;
return misc_register(&mei_misc_device);
}
void mei_deregister(void)
{
misc_deregister(&mei_misc_device);
mei_misc_device.parent = NULL;
}
