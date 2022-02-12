void mei_amthif_reset_params(struct mei_device *dev)
{
dev->iamthif_canceled = false;
dev->iamthif_state = MEI_IAMTHIF_IDLE;
dev->iamthif_stall_timer = 0;
dev->iamthif_open_count = 0;
}
int mei_amthif_host_init(struct mei_device *dev, struct mei_me_client *me_cl)
{
struct mei_cl *cl = &dev->iamthif_cl;
int ret;
mutex_lock(&dev->device_lock);
if (mei_cl_is_connected(cl)) {
ret = 0;
goto out;
}
dev->iamthif_state = MEI_IAMTHIF_IDLE;
mei_cl_init(cl, dev);
ret = mei_cl_link(cl);
if (ret < 0) {
dev_err(dev->dev, "amthif: failed cl_link %d\n", ret);
goto out;
}
ret = mei_cl_connect(cl, me_cl, NULL);
out:
mutex_unlock(&dev->device_lock);
return ret;
}
static int mei_amthif_read_start(struct mei_cl *cl, const struct file *fp)
{
struct mei_device *dev = cl->dev;
struct mei_cl_cb *cb;
cb = mei_cl_enqueue_ctrl_wr_cb(cl, mei_cl_mtu(cl), MEI_FOP_READ, fp);
if (!cb)
return -ENOMEM;
cl->rx_flow_ctrl_creds++;
dev->iamthif_state = MEI_IAMTHIF_READING;
cl->fp = cb->fp;
return 0;
}
int mei_amthif_run_next_cmd(struct mei_device *dev)
{
struct mei_cl *cl = &dev->iamthif_cl;
struct mei_cl_cb *cb;
int ret;
dev->iamthif_canceled = false;
dev_dbg(dev->dev, "complete amthif cmd_list cb.\n");
cb = list_first_entry_or_null(&dev->amthif_cmd_list.list,
typeof(*cb), list);
if (!cb) {
dev->iamthif_state = MEI_IAMTHIF_IDLE;
cl->fp = NULL;
return 0;
}
list_del_init(&cb->list);
dev->iamthif_state = MEI_IAMTHIF_WRITING;
cl->fp = cb->fp;
ret = mei_cl_write(cl, cb);
if (ret < 0)
return ret;
if (cb->completed)
cb->status = mei_amthif_read_start(cl, cb->fp);
return 0;
}
int mei_amthif_write(struct mei_cl *cl, struct mei_cl_cb *cb)
{
struct mei_device *dev = cl->dev;
list_add_tail(&cb->list, &dev->amthif_cmd_list.list);
if (dev->iamthif_state != MEI_IAMTHIF_IDLE)
return 0;
return mei_amthif_run_next_cmd(dev);
}
unsigned int mei_amthif_poll(struct file *file, poll_table *wait)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb = mei_cl_read_cb(cl, file);
unsigned int mask = 0;
poll_wait(file, &cl->rx_wait, wait);
if (cb)
mask |= POLLIN | POLLRDNORM;
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
dev->iamthif_stall_timer = 0;
return 0;
}
void mei_amthif_complete(struct mei_cl *cl, struct mei_cl_cb *cb)
{
struct mei_device *dev = cl->dev;
dev_dbg(dev->dev, "completing amthif call back.\n");
switch (cb->fop_type) {
case MEI_FOP_WRITE:
if (!cb->status) {
dev->iamthif_stall_timer = MEI_IAMTHIF_STALL_TIMER;
mei_schedule_stall_timer(dev);
mei_io_cb_free(cb);
return;
}
dev->iamthif_state = MEI_IAMTHIF_IDLE;
cl->fp = NULL;
if (!dev->iamthif_canceled) {
list_add_tail(&cb->list, &cl->rd_completed);
wake_up_interruptible(&cl->rx_wait);
} else {
mei_io_cb_free(cb);
}
break;
case MEI_FOP_READ:
if (!dev->iamthif_canceled) {
list_add_tail(&cb->list, &cl->rd_completed);
dev_dbg(dev->dev, "amthif read completed\n");
wake_up_interruptible(&cl->rx_wait);
} else {
mei_io_cb_free(cb);
}
dev->iamthif_stall_timer = 0;
mei_amthif_run_next_cmd(dev);
break;
default:
WARN_ON(1);
}
}
static void mei_clear_list(const struct file *file,
struct list_head *mei_cb_list)
{
struct mei_cl_cb *cb, *next;
list_for_each_entry_safe(cb, next, mei_cb_list, list)
if (file == cb->fp)
mei_io_cb_free(cb);
}
int mei_amthif_release(struct mei_device *dev, struct file *file)
{
struct mei_cl *cl = file->private_data;
if (dev->iamthif_open_count > 0)
dev->iamthif_open_count--;
if (cl->fp == file && dev->iamthif_state != MEI_IAMTHIF_IDLE) {
dev_dbg(dev->dev, "amthif canceled iamthif state %d\n",
dev->iamthif_state);
dev->iamthif_canceled = true;
}
mei_clear_list(file, &dev->amthif_cmd_list.list);
mei_clear_list(file, &cl->rd_completed);
mei_clear_list(file, &dev->ctrl_rd_list.list);
return 0;
}
