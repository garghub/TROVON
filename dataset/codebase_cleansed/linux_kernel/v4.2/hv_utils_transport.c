static void hvt_reset(struct hvutil_transport *hvt)
{
mutex_lock(&hvt->outmsg_lock);
kfree(hvt->outmsg);
hvt->outmsg = NULL;
hvt->outmsg_len = 0;
mutex_unlock(&hvt->outmsg_lock);
if (hvt->on_reset)
hvt->on_reset();
}
static ssize_t hvt_op_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct hvutil_transport *hvt;
int ret;
hvt = container_of(file->f_op, struct hvutil_transport, fops);
if (wait_event_interruptible(hvt->outmsg_q, hvt->outmsg_len > 0))
return -EINTR;
mutex_lock(&hvt->outmsg_lock);
if (!hvt->outmsg) {
ret = -EAGAIN;
goto out_unlock;
}
if (count < hvt->outmsg_len) {
ret = -EINVAL;
goto out_unlock;
}
if (!copy_to_user(buf, hvt->outmsg, hvt->outmsg_len))
ret = hvt->outmsg_len;
else
ret = -EFAULT;
kfree(hvt->outmsg);
hvt->outmsg = NULL;
hvt->outmsg_len = 0;
out_unlock:
mutex_unlock(&hvt->outmsg_lock);
return ret;
}
static ssize_t hvt_op_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct hvutil_transport *hvt;
u8 *inmsg;
hvt = container_of(file->f_op, struct hvutil_transport, fops);
inmsg = kzalloc(count, GFP_KERNEL);
if (copy_from_user(inmsg, buf, count)) {
kfree(inmsg);
return -EFAULT;
}
if (hvt->on_msg(inmsg, count))
return -EFAULT;
kfree(inmsg);
return count;
}
static unsigned int hvt_op_poll(struct file *file, poll_table *wait)
{
struct hvutil_transport *hvt;
hvt = container_of(file->f_op, struct hvutil_transport, fops);
poll_wait(file, &hvt->outmsg_q, wait);
if (hvt->outmsg_len > 0)
return POLLIN | POLLRDNORM;
return 0;
}
static int hvt_op_open(struct inode *inode, struct file *file)
{
struct hvutil_transport *hvt;
hvt = container_of(file->f_op, struct hvutil_transport, fops);
if (hvt->mode == HVUTIL_TRANSPORT_INIT)
hvt->mode = HVUTIL_TRANSPORT_CHARDEV;
else if (hvt->mode == HVUTIL_TRANSPORT_NETLINK) {
hvt_reset(hvt);
hvt->mode = HVUTIL_TRANSPORT_CHARDEV;
} else
return -EBUSY;
return 0;
}
static int hvt_op_release(struct inode *inode, struct file *file)
{
struct hvutil_transport *hvt;
hvt = container_of(file->f_op, struct hvutil_transport, fops);
hvt->mode = HVUTIL_TRANSPORT_INIT;
hvt_reset(hvt);
return 0;
}
static void hvt_cn_callback(struct cn_msg *msg, struct netlink_skb_parms *nsp)
{
struct hvutil_transport *hvt, *hvt_found = NULL;
spin_lock(&hvt_list_lock);
list_for_each_entry(hvt, &hvt_list, list) {
if (hvt->cn_id.idx == msg->id.idx &&
hvt->cn_id.val == msg->id.val) {
hvt_found = hvt;
break;
}
}
spin_unlock(&hvt_list_lock);
if (!hvt_found) {
pr_warn("hvt_cn_callback: spurious message received!\n");
return;
}
if (hvt->mode == HVUTIL_TRANSPORT_INIT)
hvt->mode = HVUTIL_TRANSPORT_NETLINK;
if (hvt->mode == HVUTIL_TRANSPORT_NETLINK)
hvt_found->on_msg(msg->data, msg->len);
else
pr_warn("hvt_cn_callback: unexpected netlink message!\n");
}
int hvutil_transport_send(struct hvutil_transport *hvt, void *msg, int len)
{
struct cn_msg *cn_msg;
int ret = 0;
if (hvt->mode == HVUTIL_TRANSPORT_INIT) {
return -EINVAL;
} else if (hvt->mode == HVUTIL_TRANSPORT_NETLINK) {
cn_msg = kzalloc(sizeof(*cn_msg) + len, GFP_ATOMIC);
if (!msg)
return -ENOMEM;
cn_msg->id.idx = hvt->cn_id.idx;
cn_msg->id.val = hvt->cn_id.val;
cn_msg->len = len;
memcpy(cn_msg->data, msg, len);
ret = cn_netlink_send(cn_msg, 0, 0, GFP_ATOMIC);
kfree(cn_msg);
return ret;
}
mutex_lock(&hvt->outmsg_lock);
if (hvt->outmsg) {
ret = -EFAULT;
goto out_unlock;
}
hvt->outmsg = kzalloc(len, GFP_KERNEL);
memcpy(hvt->outmsg, msg, len);
hvt->outmsg_len = len;
wake_up_interruptible(&hvt->outmsg_q);
out_unlock:
mutex_unlock(&hvt->outmsg_lock);
return ret;
}
struct hvutil_transport *hvutil_transport_init(const char *name,
u32 cn_idx, u32 cn_val,
int (*on_msg)(void *, int),
void (*on_reset)(void))
{
struct hvutil_transport *hvt;
hvt = kzalloc(sizeof(*hvt), GFP_KERNEL);
if (!hvt)
return NULL;
hvt->cn_id.idx = cn_idx;
hvt->cn_id.val = cn_val;
hvt->mdev.minor = MISC_DYNAMIC_MINOR;
hvt->mdev.name = name;
hvt->fops.owner = THIS_MODULE;
hvt->fops.read = hvt_op_read;
hvt->fops.write = hvt_op_write;
hvt->fops.poll = hvt_op_poll;
hvt->fops.open = hvt_op_open;
hvt->fops.release = hvt_op_release;
hvt->mdev.fops = &hvt->fops;
init_waitqueue_head(&hvt->outmsg_q);
mutex_init(&hvt->outmsg_lock);
spin_lock(&hvt_list_lock);
list_add(&hvt->list, &hvt_list);
spin_unlock(&hvt_list_lock);
hvt->on_msg = on_msg;
hvt->on_reset = on_reset;
if (misc_register(&hvt->mdev))
goto err_free_hvt;
if (hvt->cn_id.idx > 0 && hvt->cn_id.val > 0 &&
cn_add_callback(&hvt->cn_id, name, hvt_cn_callback))
goto err_free_hvt;
return hvt;
err_free_hvt:
kfree(hvt);
return NULL;
}
void hvutil_transport_destroy(struct hvutil_transport *hvt)
{
spin_lock(&hvt_list_lock);
list_del(&hvt->list);
spin_unlock(&hvt_list_lock);
if (hvt->cn_id.idx > 0 && hvt->cn_id.val > 0)
cn_del_callback(&hvt->cn_id);
misc_deregister(&hvt->mdev);
kfree(hvt->outmsg);
kfree(hvt);
}
