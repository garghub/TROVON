int mei_me_cl_by_id(struct mei_device *dev, u8 client_id)
{
int i;
for (i = 0; i < dev->me_clients_num; i++)
if (dev->me_clients[i].client_id == client_id)
break;
if (WARN_ON(dev->me_clients[i].client_id != client_id))
return -ENOENT;
if (i == dev->me_clients_num)
return -ENOENT;
return i;
}
int mei_ioctl_connect_client(struct file *file,
struct mei_connect_client_data *data)
{
struct mei_device *dev;
struct mei_cl_cb *cb;
struct mei_client *client;
struct mei_cl *cl;
struct mei_cl *cl_pos = NULL;
struct mei_cl *cl_next = NULL;
long timeout = CONNECT_TIMEOUT;
int i;
int err;
int rets;
cl = file->private_data;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
dev_dbg(&dev->pdev->dev, "mei_ioctl_connect_client() Entry\n");
cb = kzalloc(sizeof(struct mei_cl_cb), GFP_KERNEL);
if (!cb) {
rets = -ENOMEM;
goto end;
}
INIT_LIST_HEAD(&cb->cb_list);
cb->major_file_operations = MEI_IOCTL;
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
if (uuid_le_cmp(data->in_client_uuid, mei_amthi_guid) == 0) {
dev_dbg(&dev->pdev->dev, "FW Client is amthi\n");
if (dev->iamthif_cl.state != MEI_FILE_CONNECTED) {
rets = -ENODEV;
goto end;
}
clear_bit(cl->host_client_id, dev->host_clients_map);
list_for_each_entry_safe(cl_pos, cl_next,
&dev->file_list, link) {
if (mei_cl_cmp_id(cl, cl_pos)) {
dev_dbg(&dev->pdev->dev,
"remove file private data node host"
" client = %d, ME client = %d.\n",
cl_pos->host_client_id,
cl_pos->me_client_id);
list_del(&cl_pos->link);
}
}
dev_dbg(&dev->pdev->dev, "free file private data memory.\n");
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
if (dev->mei_host_buffer_is_empty
&& !mei_other_client_is_connecting(dev, cl)) {
dev_dbg(&dev->pdev->dev, "Sending Connect Message\n");
dev->mei_host_buffer_is_empty = false;
if (mei_connect(dev, cl)) {
dev_dbg(&dev->pdev->dev, "Sending connect message - failed\n");
rets = -ENODEV;
goto end;
} else {
dev_dbg(&dev->pdev->dev, "Sending connect message - succeeded\n");
cl->timer_count = MEI_CONNECT_TIMEOUT;
cb->file_private = cl;
list_add_tail(&cb->cb_list,
&dev->ctrl_rd_list.mei_cb.
cb_list);
}
} else {
dev_dbg(&dev->pdev->dev, "Queuing the connect request due to device busy\n");
cb->file_private = cl;
dev_dbg(&dev->pdev->dev, "add connect cb to control write list.\n");
list_add_tail(&cb->cb_list,
&dev->ctrl_wr_list.mei_cb.cb_list);
}
mutex_unlock(&dev->device_lock);
err = wait_event_timeout(dev->wait_recvd_msg,
(MEI_FILE_CONNECTED == cl->state ||
MEI_FILE_DISCONNECTED == cl->state),
timeout * HZ);
mutex_lock(&dev->device_lock);
if (MEI_FILE_CONNECTED == cl->state) {
dev_dbg(&dev->pdev->dev, "successfully connected to FW client.\n");
rets = cl->status;
goto end;
} else {
dev_dbg(&dev->pdev->dev, "failed to connect to FW client.cl->state = %d.\n",
cl->state);
if (!err) {
dev_dbg(&dev->pdev->dev,
"wait_event_interruptible_timeout failed on client"
" connect message fw response message.\n");
}
rets = -EFAULT;
mei_io_list_flush(&dev->ctrl_rd_list, cl);
mei_io_list_flush(&dev->ctrl_wr_list, cl);
goto end;
}
rets = 0;
end:
dev_dbg(&dev->pdev->dev, "free connect cb memory.");
kfree(cb);
return rets;
}
struct mei_cl_cb *find_amthi_read_list_entry(
struct mei_device *dev,
struct file *file)
{
struct mei_cl *cl_temp;
struct mei_cl_cb *pos = NULL;
struct mei_cl_cb *next = NULL;
list_for_each_entry_safe(pos, next,
&dev->amthi_read_complete_list.mei_cb.cb_list, cb_list) {
cl_temp = (struct mei_cl *)pos->file_private;
if (cl_temp && cl_temp == &dev->iamthif_cl &&
pos->file_object == file)
return pos;
}
return NULL;
}
int amthi_read(struct mei_device *dev, struct file *file,
char __user *ubuf, size_t length, loff_t *offset)
{
int rets;
int wait_ret;
struct mei_cl_cb *cb = NULL;
struct mei_cl *cl = file->private_data;
unsigned long timeout;
int i;
if (!cl || cl != &dev->iamthif_cl) {
dev_dbg(&dev->pdev->dev, "bad file ext.\n");
return -ETIMEDOUT;
}
i = mei_me_cl_by_id(dev, dev->iamthif_cl.me_client_id);
if (i < 0) {
dev_dbg(&dev->pdev->dev, "amthi client not found.\n");
return -ENODEV;
}
dev_dbg(&dev->pdev->dev, "checking amthi data\n");
cb = find_amthi_read_list_entry(dev, file);
if (cb == NULL && file->f_flags & O_NONBLOCK)
return -EAGAIN;
dev_dbg(&dev->pdev->dev, "waiting for amthi data\n");
while (cb == NULL) {
mutex_unlock(&dev->device_lock);
wait_ret = wait_event_interruptible(dev->iamthif_cl.wait,
(cb = find_amthi_read_list_entry(dev, file)));
if (wait_ret)
return -ERESTARTSYS;
dev_dbg(&dev->pdev->dev, "woke up from sleep\n");
mutex_lock(&dev->device_lock);
}
dev_dbg(&dev->pdev->dev, "Got amthi data\n");
dev->iamthif_timer = 0;
if (cb) {
timeout = cb->read_time + msecs_to_jiffies(IAMTHIF_READ_TIMER);
dev_dbg(&dev->pdev->dev, "amthi timeout = %lud\n",
timeout);
if (time_after(jiffies, timeout)) {
dev_dbg(&dev->pdev->dev, "amthi Time out\n");
list_del(&cb->cb_list);
rets = -ETIMEDOUT;
goto free;
}
}
if (cb->information >= *offset && length >= (cb->information - *offset))
list_del(&cb->cb_list);
else if (cb->information > 0 && cb->information <= *offset) {
list_del(&cb->cb_list);
rets = 0;
goto free;
}
dev_dbg(&dev->pdev->dev, "amthi cb->response_buffer size - %d\n",
cb->response_buffer.size);
dev_dbg(&dev->pdev->dev, "amthi cb->information - %lu\n",
cb->information);
length = min_t(size_t, length, (cb->information - *offset));
if (copy_to_user(ubuf, cb->response_buffer.data + *offset, length))
rets = -EFAULT;
else {
rets = length;
if ((*offset + length) < cb->information) {
*offset += length;
goto out;
}
}
free:
dev_dbg(&dev->pdev->dev, "free amthi cb memory.\n");
*offset = 0;
mei_free_cb_private(cb);
out:
return rets;
}
int mei_start_read(struct mei_device *dev, struct mei_cl *cl)
{
struct mei_cl_cb *cb;
int rets = 0;
int i;
if (cl->state != MEI_FILE_CONNECTED)
return -ENODEV;
if (dev->dev_state != MEI_DEV_ENABLED)
return -ENODEV;
dev_dbg(&dev->pdev->dev, "check if read is pending.\n");
if (cl->read_pending || cl->read_cb) {
dev_dbg(&dev->pdev->dev, "read is pending.\n");
return -EBUSY;
}
cb = kzalloc(sizeof(struct mei_cl_cb), GFP_KERNEL);
if (!cb)
return -ENOMEM;
dev_dbg(&dev->pdev->dev, "allocation call back successful. host client = %d, ME client = %d\n",
cl->host_client_id, cl->me_client_id);
i = mei_me_cl_by_id(dev, cl->me_client_id);
if (i < 0) {
rets = -ENODEV;
goto unlock;
}
cb->response_buffer.size = dev->me_clients[i].props.max_msg_length;
cb->response_buffer.data =
kmalloc(cb->response_buffer.size, GFP_KERNEL);
if (!cb->response_buffer.data) {
rets = -ENOMEM;
goto unlock;
}
dev_dbg(&dev->pdev->dev, "allocation call back data success.\n");
cb->major_file_operations = MEI_READ;
cb->information = 0;
cb->file_private = (void *) cl;
cl->read_cb = cb;
if (dev->mei_host_buffer_is_empty) {
dev->mei_host_buffer_is_empty = false;
if (mei_send_flow_control(dev, cl)) {
rets = -ENODEV;
goto unlock;
}
list_add_tail(&cb->cb_list, &dev->read_list.mei_cb.cb_list);
} else {
list_add_tail(&cb->cb_list, &dev->ctrl_wr_list.mei_cb.cb_list);
}
return rets;
unlock:
mei_free_cb_private(cb);
return rets;
}
int amthi_write(struct mei_device *dev, struct mei_cl_cb *cb)
{
struct mei_msg_hdr mei_hdr;
int ret;
if (!dev || !cb)
return -ENODEV;
dev_dbg(&dev->pdev->dev, "write data to amthi client.\n");
dev->iamthif_state = MEI_IAMTHIF_WRITING;
dev->iamthif_current_cb = cb;
dev->iamthif_file_object = cb->file_object;
dev->iamthif_canceled = false;
dev->iamthif_ioctl = true;
dev->iamthif_msg_buf_size = cb->request_buffer.size;
memcpy(dev->iamthif_msg_buf, cb->request_buffer.data,
cb->request_buffer.size);
ret = mei_flow_ctrl_creds(dev, &dev->iamthif_cl);
if (ret < 0)
return ret;
if (ret && dev->mei_host_buffer_is_empty) {
ret = 0;
dev->mei_host_buffer_is_empty = false;
if (cb->request_buffer.size > mei_hbuf_max_data(dev)) {
mei_hdr.length = mei_hbuf_max_data(dev);
mei_hdr.msg_complete = 0;
} else {
mei_hdr.length = cb->request_buffer.size;
mei_hdr.msg_complete = 1;
}
mei_hdr.host_addr = dev->iamthif_cl.host_client_id;
mei_hdr.me_addr = dev->iamthif_cl.me_client_id;
mei_hdr.reserved = 0;
dev->iamthif_msg_buf_index += mei_hdr.length;
if (mei_write_message(dev, &mei_hdr,
(unsigned char *)(dev->iamthif_msg_buf),
mei_hdr.length))
return -ENODEV;
if (mei_hdr.msg_complete) {
if (mei_flow_ctrl_reduce(dev, &dev->iamthif_cl))
return -ENODEV;
dev->iamthif_flow_control_pending = true;
dev->iamthif_state = MEI_IAMTHIF_FLOW_CONTROL;
dev_dbg(&dev->pdev->dev, "add amthi cb to write waiting list\n");
dev->iamthif_current_cb = cb;
dev->iamthif_file_object = cb->file_object;
list_add_tail(&cb->cb_list,
&dev->write_waiting_list.mei_cb.cb_list);
} else {
dev_dbg(&dev->pdev->dev, "message does not complete, "
"so add amthi cb to write list.\n");
list_add_tail(&cb->cb_list,
&dev->write_list.mei_cb.cb_list);
}
} else {
if (!(dev->mei_host_buffer_is_empty))
dev_dbg(&dev->pdev->dev, "host buffer is not empty");
dev_dbg(&dev->pdev->dev, "No flow control credentials, "
"so add iamthif cb to write list.\n");
list_add_tail(&cb->cb_list, &dev->write_list.mei_cb.cb_list);
}
return 0;
}
void mei_run_next_iamthif_cmd(struct mei_device *dev)
{
struct mei_cl *cl_tmp;
struct mei_cl_cb *pos = NULL;
struct mei_cl_cb *next = NULL;
int status;
if (!dev)
return;
dev->iamthif_msg_buf_size = 0;
dev->iamthif_msg_buf_index = 0;
dev->iamthif_canceled = false;
dev->iamthif_ioctl = true;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
dev->iamthif_timer = 0;
dev->iamthif_file_object = NULL;
dev_dbg(&dev->pdev->dev, "complete amthi cmd_list cb.\n");
list_for_each_entry_safe(pos, next,
&dev->amthi_cmd_list.mei_cb.cb_list, cb_list) {
list_del(&pos->cb_list);
cl_tmp = (struct mei_cl *)pos->file_private;
if (cl_tmp && cl_tmp == &dev->iamthif_cl) {
status = amthi_write(dev, pos);
if (status) {
dev_dbg(&dev->pdev->dev,
"amthi write failed status = %d\n",
status);
return;
}
break;
}
}
}
void mei_free_cb_private(struct mei_cl_cb *cb)
{
if (cb == NULL)
return;
kfree(cb->request_buffer.data);
kfree(cb->response_buffer.data);
kfree(cb);
}
