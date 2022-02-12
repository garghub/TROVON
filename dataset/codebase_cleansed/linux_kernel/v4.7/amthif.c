void mei_amthif_reset_params(struct mei_device *dev)
{
dev->iamthif_current_cb = NULL;
dev->iamthif_canceled = false;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
dev->iamthif_stall_timer = 0;
dev->iamthif_open_count = 0;
}
int mei_amthif_host_init(struct mei_device *dev, struct mei_me_client *me_cl)
{
struct mei_cl *cl = &dev->iamthif_cl;
int ret;
if (mei_cl_is_connected(cl))
return 0;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
mei_cl_init(cl, dev);
ret = mei_cl_link(cl);
if (ret < 0) {
dev_err(dev->dev, "amthif: failed cl_link %d\n", ret);
return ret;
}
ret = mei_cl_connect(cl, me_cl, NULL);
return ret;
}
int mei_amthif_read(struct mei_device *dev, struct file *file,
char __user *ubuf, size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb;
int rets;
int wait_ret;
dev_dbg(dev->dev, "checking amthif data\n");
cb = mei_cl_read_cb(cl, file);
if (cb == NULL && file->f_flags & O_NONBLOCK)
return -EAGAIN;
dev_dbg(dev->dev, "waiting for amthif data\n");
while (cb == NULL) {
mutex_unlock(&dev->device_lock);
wait_ret = wait_event_interruptible(cl->rx_wait,
!list_empty(&cl->rd_completed) ||
!mei_cl_is_connected(cl));
mutex_lock(&dev->device_lock);
if (wait_ret)
return -ERESTARTSYS;
if (!mei_cl_is_connected(cl)) {
rets = -EBUSY;
goto out;
}
cb = mei_cl_read_cb(cl, file);
}
if (cb->status) {
rets = cb->status;
dev_dbg(dev->dev, "read operation failed %d\n", rets);
goto free;
}
dev_dbg(dev->dev, "Got amthif data\n");
if (cb->buf_idx >= *offset && length >= (cb->buf_idx - *offset))
list_del_init(&cb->list);
else if (cb->buf_idx <= *offset) {
list_del_init(&cb->list);
rets = 0;
goto free;
}
dev_dbg(dev->dev, "amthif cb->buf.size - %zu cb->buf_idx - %zu\n",
cb->buf.size, cb->buf_idx);
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
static int mei_amthif_read_start(struct mei_cl *cl, const struct file *file)
{
struct mei_device *dev = cl->dev;
struct mei_cl_cb *cb;
int rets;
cb = mei_io_cb_init(cl, MEI_FOP_READ, file);
if (!cb) {
rets = -ENOMEM;
goto err;
}
rets = mei_io_cb_alloc_buf(cb, mei_cl_mtu(cl));
if (rets)
goto err;
list_add_tail(&cb->list, &dev->ctrl_wr_list.list);
dev->iamthif_state = MEI_IAMTHIF_READING;
dev->iamthif_fp = cb->fp;
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
dev->iamthif_fp = cb->fp;
dev->iamthif_canceled = false;
ret = mei_cl_write(cl, cb, false);
if (ret < 0)
return ret;
if (cb->completed)
cb->status = mei_amthif_read_start(cl, cb->fp);
return 0;
}
int mei_amthif_run_next_cmd(struct mei_device *dev)
{
struct mei_cl *cl = &dev->iamthif_cl;
struct mei_cl_cb *cb;
dev->iamthif_canceled = false;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
dev->iamthif_fp = NULL;
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
struct mei_device *dev = cl->dev;
list_add_tail(&cb->list, &dev->amthif_cmd_list.list);
if (dev->iamthif_state > MEI_IAMTHIF_IDLE &&
dev->iamthif_state < MEI_IAMTHIF_READ_COMPLETE)
return 0;
return mei_amthif_run_next_cmd(dev);
}
unsigned int mei_amthif_poll(struct mei_device *dev,
struct file *file, poll_table *wait)
{
unsigned int mask = 0;
poll_wait(file, &dev->iamthif_cl.rx_wait, wait);
if (dev->iamthif_state == MEI_IAMTHIF_READ_COMPLETE &&
dev->iamthif_fp == file) {
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
cb->status = mei_amthif_read_start(cl, cb->fp);
return 0;
}
int mei_amthif_irq_read_msg(struct mei_cl *cl,
struct mei_msg_hdr *mei_hdr,
struct mei_cl_cb *cmpl_list)
{
struct mei_device *dev;
int ret;
dev = cl->dev;
if (dev->iamthif_state != MEI_IAMTHIF_READING) {
mei_irq_discard_msg(dev, mei_hdr);
return 0;
}
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
void mei_amthif_complete(struct mei_cl *cl, struct mei_cl_cb *cb)
{
struct mei_device *dev = cl->dev;
if (cb->fop_type == MEI_FOP_WRITE) {
if (!cb->status) {
dev->iamthif_stall_timer = MEI_IAMTHIF_STALL_TIMER;
mei_io_cb_free(cb);
return;
}
list_add_tail(&cb->list, &cl->rd_completed);
wake_up_interruptible(&cl->rx_wait);
return;
}
if (!dev->iamthif_canceled) {
dev->iamthif_state = MEI_IAMTHIF_READ_COMPLETE;
dev->iamthif_stall_timer = 0;
list_add_tail(&cb->list, &cl->rd_completed);
dev_dbg(dev->dev, "amthif read completed\n");
} else {
mei_amthif_run_next_cmd(dev);
}
dev_dbg(dev->dev, "completing amthif call back.\n");
wake_up_interruptible(&cl->rx_wait);
}
static bool mei_clear_list(struct mei_device *dev,
const struct file *file, struct list_head *mei_cb_list)
{
struct mei_cl *cl = &dev->iamthif_cl;
struct mei_cl_cb *cb, *next;
bool removed = false;
list_for_each_entry_safe(cb, next, mei_cb_list, list) {
if (file == cb->fp) {
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
static bool mei_clear_lists(struct mei_device *dev, const struct file *file)
{
bool removed = false;
struct mei_cl *cl = &dev->iamthif_cl;
mei_clear_list(dev, file, &dev->amthif_cmd_list.list);
if (mei_clear_list(dev, file, &cl->rd_completed))
removed = true;
mei_clear_list(dev, file, &dev->ctrl_rd_list.list);
if (mei_clear_list(dev, file, &dev->ctrl_wr_list.list))
removed = true;
if (mei_clear_list(dev, file, &dev->write_waiting_list.list))
removed = true;
if (mei_clear_list(dev, file, &dev->write_list.list))
removed = true;
if (dev->iamthif_current_cb && !removed) {
if (dev->iamthif_current_cb->fp == file) {
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
if (dev->iamthif_fp == file &&
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
