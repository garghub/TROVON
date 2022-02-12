void mei_amthif_reset_params(struct mei_device *dev)
{
dev->iamthif_current_cb = NULL;
dev->iamthif_canceled = false;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
dev->iamthif_timer = 0;
dev->iamthif_stall_timer = 0;
dev->iamthif_open_count = 0;
}
int mei_amthif_host_init(struct mei_device *dev)
{
struct mei_cl *cl = &dev->iamthif_cl;
struct mei_me_client *me_cl;
int ret;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
mei_cl_init(cl, dev);
me_cl = mei_me_cl_by_uuid(dev, &mei_amthif_guid);
if (!me_cl) {
dev_info(dev->dev, "amthif: failed to find the client");
return -ENOTTY;
}
cl->me_client_id = me_cl->client_id;
cl->cl_uuid = me_cl->props.protocol_name;
dev->iamthif_mtu = me_cl->props.max_msg_length;
dev_dbg(dev->dev, "IAMTHIF_MTU = %d\n", dev->iamthif_mtu);
ret = mei_cl_link(cl, MEI_IAMTHIF_HOST_CLIENT_ID);
if (ret < 0) {
dev_err(dev->dev, "amthif: failed cl_link %d\n", ret);
goto out;
}
ret = mei_cl_connect(cl, NULL);
dev->iamthif_state = MEI_IAMTHIF_IDLE;
out:
mei_me_cl_put(me_cl);
return ret;
}
struct mei_cl_cb *mei_amthif_find_read_list_entry(struct mei_device *dev,
struct file *file)
{
struct mei_cl_cb *cb;
list_for_each_entry(cb, &dev->amthif_rd_complete_list.list, list)
if (cb->file_object == file)
return cb;
return NULL;
}
int mei_amthif_read(struct mei_device *dev, struct file *file,
char __user *ubuf, size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb;
unsigned long timeout;
int rets;
int wait_ret;
if (!cl) {
dev_err(dev->dev, "bad file ext.\n");
return -ETIME;
}
dev_dbg(dev->dev, "checking amthif data\n");
cb = mei_amthif_find_read_list_entry(dev, file);
if (cb == NULL && file->f_flags & O_NONBLOCK)
return -EAGAIN;
dev_dbg(dev->dev, "waiting for amthif data\n");
while (cb == NULL) {
mutex_unlock(&dev->device_lock);
wait_ret = wait_event_interruptible(dev->iamthif_cl.wait,
(cb = mei_amthif_find_read_list_entry(dev, file)));
mutex_lock(&dev->device_lock);
if (wait_ret)
return -ERESTARTSYS;
dev_dbg(dev->dev, "woke up from sleep\n");
}
if (cb->status) {
rets = cb->status;
dev_dbg(dev->dev, "read operation failed %d\n", rets);
goto free;
}
dev_dbg(dev->dev, "Got amthif data\n");
dev->iamthif_timer = 0;
timeout = cb->read_time +
mei_secs_to_jiffies(MEI_IAMTHIF_READ_TIMER);
dev_dbg(dev->dev, "amthif timeout = %lud\n",
timeout);
if (time_after(jiffies, timeout)) {
dev_dbg(dev->dev, "amthif Time out\n");
list_del_init(&cb->list);
rets = -ETIME;
goto free;
}
if (cb->buf_idx >= *offset && length >= (cb->buf_idx - *offset))
list_del_init(&cb->list);
else if (cb->buf_idx > 0 && cb->buf_idx <= *offset) {
list_del_init(&cb->list);
rets = 0;
goto free;
}
dev_dbg(dev->dev, "amthif cb->buf size - %d\n",
cb->buf.size);
dev_dbg(dev->dev, "amthif cb->buf_idx - %lu\n", cb->buf_idx);
length = min_t(size_t, length, (cb->buf_idx - *offset));
if (copy_to_user(ubuf, cb->buf.data + *offset, length)) {
dev_dbg(dev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
} else {
rets = length;
if ((*offset + length) < cb->buf_idx) {
*offset += length;
goto out;
}
}
free:
dev_dbg(dev->dev, "free amthif cb memory.\n");
*offset = 0;
mei_io_cb_free(cb);
out:
return rets;
}
static int mei_amthif_read_start(struct mei_cl *cl, struct file *file)
{
struct mei_device *dev = cl->dev;
struct mei_cl_cb *cb;
size_t length = dev->iamthif_mtu;
int rets;
cb = mei_io_cb_init(cl, MEI_FOP_READ, file);
if (!cb) {
rets = -ENOMEM;
goto err;
}
rets = mei_io_cb_alloc_buf(cb, length);
if (rets)
goto err;
list_add_tail(&cb->list, &dev->ctrl_wr_list.list);
dev->iamthif_state = MEI_IAMTHIF_READING;
dev->iamthif_file_object = cb->file_object;
dev->iamthif_current_cb = cb;
return 0;
err:
mei_io_cb_free(cb);
return rets;
}
static int mei_amthif_send_cmd(struct mei_cl *cl, struct mei_cl_cb *cb)
{
struct mei_device *dev;
int ret;
if (!cl->dev || !cb)
return -ENODEV;
dev = cl->dev;
dev->iamthif_state = MEI_IAMTHIF_WRITING;
dev->iamthif_current_cb = cb;
dev->iamthif_file_object = cb->file_object;
dev->iamthif_canceled = false;
ret = mei_cl_write(cl, cb, false);
if (ret < 0)
return ret;
if (cb->completed)
cb->status = mei_amthif_read_start(cl, cb->file_object);
return 0;
}
int mei_amthif_run_next_cmd(struct mei_device *dev)
{
struct mei_cl *cl = &dev->iamthif_cl;
struct mei_cl_cb *cb;
dev->iamthif_canceled = false;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
dev->iamthif_timer = 0;
dev->iamthif_file_object = NULL;
dev_dbg(dev->dev, "complete amthif cmd_list cb.\n");
cb = list_first_entry_or_null(&dev->amthif_cmd_list.list,
typeof(*cb), list);
if (!cb)
return 0;
list_del_init(&cb->list);
return mei_amthif_send_cmd(cl, cb);
}
int mei_amthif_write(struct mei_cl *cl, struct mei_cl_cb *cb)
{
struct mei_device *dev;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
if (WARN_ON(!cb))
return -EINVAL;
dev = cl->dev;
list_add_tail(&cb->list, &dev->amthif_cmd_list.list);
return mei_amthif_run_next_cmd(dev);
}
unsigned int mei_amthif_poll(struct mei_device *dev,
struct file *file, poll_table *wait)
{
unsigned int mask = 0;
poll_wait(file, &dev->iamthif_cl.wait, wait);
if (dev->iamthif_state == MEI_IAMTHIF_READ_COMPLETE &&
dev->iamthif_file_object == file) {
mask |= POLLIN | POLLRDNORM;
mei_amthif_run_next_cmd(dev);
}
return mask;
}
int mei_amthif_irq_write(struct mei_cl *cl, struct mei_cl_cb *cb,
struct mei_cl_cb *cmpl_list)
{
int ret;
ret = mei_cl_irq_write(cl, cb, cmpl_list);
if (ret)
return ret;
if (cb->completed)
cb->status = mei_amthif_read_start(cl, cb->file_object);
return 0;
}
int mei_amthif_irq_read_msg(struct mei_cl *cl,
struct mei_msg_hdr *mei_hdr,
struct mei_cl_cb *cmpl_list)
{
struct mei_device *dev;
int ret;
dev = cl->dev;
if (dev->iamthif_state != MEI_IAMTHIF_READING)
return 0;
ret = mei_cl_irq_read_msg(cl, mei_hdr, cmpl_list);
if (ret)
return ret;
if (!mei_hdr->msg_complete)
return 0;
dev_dbg(dev->dev, "completed amthif read.\n ");
dev->iamthif_current_cb = NULL;
dev->iamthif_stall_timer = 0;
return 0;
}
void mei_amthif_complete(struct mei_device *dev, struct mei_cl_cb *cb)
{
if (cb->fop_type == MEI_FOP_WRITE) {
if (!cb->status) {
dev->iamthif_stall_timer = MEI_IAMTHIF_STALL_TIMER;
mei_io_cb_free(cb);
return;
}
list_add_tail(&cb->list, &dev->amthif_rd_complete_list.list);
wake_up_interruptible(&dev->iamthif_cl.wait);
return;
}
if (dev->iamthif_canceled != 1) {
dev->iamthif_state = MEI_IAMTHIF_READ_COMPLETE;
dev->iamthif_stall_timer = 0;
list_add_tail(&cb->list, &dev->amthif_rd_complete_list.list);
dev_dbg(dev->dev, "amthif read completed\n");
dev->iamthif_timer = jiffies;
dev_dbg(dev->dev, "dev->iamthif_timer = %ld\n",
dev->iamthif_timer);
} else {
mei_amthif_run_next_cmd(dev);
}
dev_dbg(dev->dev, "completing amthif call back.\n");
wake_up_interruptible(&dev->iamthif_cl.wait);
}
static bool mei_clear_list(struct mei_device *dev,
const struct file *file, struct list_head *mei_cb_list)
{
struct mei_cl *cl = &dev->iamthif_cl;
struct mei_cl_cb *cb, *next;
bool removed = false;
list_for_each_entry_safe(cb, next, mei_cb_list, list) {
if (file == cb->file_object) {
if (dev->iamthif_current_cb == cb) {
dev->iamthif_current_cb = NULL;
mei_hbm_cl_flow_control_req(dev, cl);
}
mei_io_cb_free(cb);
removed = true;
}
}
return removed;
}
static bool mei_clear_lists(struct mei_device *dev, struct file *file)
{
bool removed = false;
mei_clear_list(dev, file, &dev->amthif_cmd_list.list);
if (mei_clear_list(dev, file, &dev->amthif_rd_complete_list.list))
removed = true;
mei_clear_list(dev, file, &dev->ctrl_rd_list.list);
if (mei_clear_list(dev, file, &dev->ctrl_wr_list.list))
removed = true;
if (mei_clear_list(dev, file, &dev->write_waiting_list.list))
removed = true;
if (mei_clear_list(dev, file, &dev->write_list.list))
removed = true;
if (dev->iamthif_current_cb && !removed) {
if (dev->iamthif_current_cb->file_object == file) {
mei_io_cb_free(dev->iamthif_current_cb);
dev->iamthif_current_cb = NULL;
removed = true;
}
}
return removed;
}
int mei_amthif_release(struct mei_device *dev, struct file *file)
{
if (dev->iamthif_open_count > 0)
dev->iamthif_open_count--;
if (dev->iamthif_file_object == file &&
dev->iamthif_state != MEI_IAMTHIF_IDLE) {
dev_dbg(dev->dev, "amthif canceled iamthif state %d\n",
dev->iamthif_state);
dev->iamthif_canceled = true;
if (dev->iamthif_state == MEI_IAMTHIF_READ_COMPLETE) {
dev_dbg(dev->dev, "run next amthif iamthif cb\n");
mei_amthif_run_next_cmd(dev);
}
}
if (mei_clear_lists(dev, file))
dev->iamthif_state = MEI_IAMTHIF_IDLE;
return 0;
}
