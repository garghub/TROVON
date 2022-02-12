int cn_netlink_send(struct cn_msg *msg, u32 __group, gfp_t gfp_mask)
{
struct cn_callback_entry *__cbq;
unsigned int size;
struct sk_buff *skb;
struct nlmsghdr *nlh;
struct cn_msg *data;
struct cn_dev *dev = &cdev;
u32 group = 0;
int found = 0;
if (!__group) {
spin_lock_bh(&dev->cbdev->queue_lock);
list_for_each_entry(__cbq, &dev->cbdev->queue_list,
callback_entry) {
if (cn_cb_equal(&__cbq->id.id, &msg->id)) {
found = 1;
group = __cbq->group;
break;
}
}
spin_unlock_bh(&dev->cbdev->queue_lock);
if (!found)
return -ENODEV;
} else {
group = __group;
}
if (!netlink_has_listeners(dev->nls, group))
return -ESRCH;
size = NLMSG_SPACE(sizeof(*msg) + msg->len);
skb = alloc_skb(size, gfp_mask);
if (!skb)
return -ENOMEM;
nlh = nlmsg_put(skb, 0, msg->seq, NLMSG_DONE, size - sizeof(*nlh), 0);
if (!nlh) {
kfree_skb(skb);
return -EMSGSIZE;
}
data = nlmsg_data(nlh);
memcpy(data, msg, sizeof(*data) + msg->len);
NETLINK_CB(skb).dst_group = group;
return netlink_broadcast(dev->nls, skb, 0, group, gfp_mask);
}
static int cn_call_callback(struct sk_buff *skb)
{
struct cn_callback_entry *i, *cbq = NULL;
struct cn_dev *dev = &cdev;
struct cn_msg *msg = NLMSG_DATA(nlmsg_hdr(skb));
struct netlink_skb_parms *nsp = &NETLINK_CB(skb);
int err = -ENODEV;
spin_lock_bh(&dev->cbdev->queue_lock);
list_for_each_entry(i, &dev->cbdev->queue_list, callback_entry) {
if (cn_cb_equal(&i->id.id, &msg->id)) {
atomic_inc(&i->refcnt);
cbq = i;
break;
}
}
spin_unlock_bh(&dev->cbdev->queue_lock);
if (cbq != NULL) {
err = 0;
cbq->callback(msg, nsp);
kfree_skb(skb);
cn_queue_release_callback(cbq);
err = 0;
}
return err;
}
static void cn_rx_skb(struct sk_buff *__skb)
{
struct nlmsghdr *nlh;
int err;
struct sk_buff *skb;
skb = skb_get(__skb);
if (skb->len >= NLMSG_SPACE(0)) {
nlh = nlmsg_hdr(skb);
if (nlh->nlmsg_len < sizeof(struct cn_msg) ||
skb->len < nlh->nlmsg_len ||
nlh->nlmsg_len > CONNECTOR_MAX_MSG_SIZE) {
kfree_skb(skb);
return;
}
err = cn_call_callback(skb);
if (err < 0)
kfree_skb(skb);
}
}
int cn_add_callback(struct cb_id *id, const char *name,
void (*callback)(struct cn_msg *,
struct netlink_skb_parms *))
{
int err;
struct cn_dev *dev = &cdev;
if (!cn_already_initialized)
return -EAGAIN;
err = cn_queue_add_callback(dev->cbdev, name, id, callback);
if (err)
return err;
return 0;
}
void cn_del_callback(struct cb_id *id)
{
struct cn_dev *dev = &cdev;
cn_queue_del_callback(dev->cbdev, id);
}
static int cn_proc_show(struct seq_file *m, void *v)
{
struct cn_queue_dev *dev = cdev.cbdev;
struct cn_callback_entry *cbq;
seq_printf(m, "Name ID\n");
spin_lock_bh(&dev->queue_lock);
list_for_each_entry(cbq, &dev->queue_list, callback_entry) {
seq_printf(m, "%-15s %u:%u\n",
cbq->id.name,
cbq->id.id.idx,
cbq->id.id.val);
}
spin_unlock_bh(&dev->queue_lock);
return 0;
}
static int cn_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, cn_proc_show, NULL);
}
static int __devinit cn_init(void)
{
struct cn_dev *dev = &cdev;
struct netlink_kernel_cfg cfg = {
.groups = CN_NETLINK_USERS + 0xf,
.input = dev->input,
};
dev->nls = netlink_kernel_create(&init_net, NETLINK_CONNECTOR,
THIS_MODULE, &cfg);
if (!dev->nls)
return -EIO;
dev->cbdev = cn_queue_alloc_dev("cqueue", dev->nls);
if (!dev->cbdev) {
netlink_kernel_release(dev->nls);
return -EINVAL;
}
cn_already_initialized = 1;
proc_net_fops_create(&init_net, "connector", S_IRUGO, &cn_file_ops);
return 0;
}
static void __devexit cn_fini(void)
{
struct cn_dev *dev = &cdev;
cn_already_initialized = 0;
proc_net_remove(&init_net, "connector");
cn_queue_free_dev(dev->cbdev);
netlink_kernel_release(dev->nls);
}
