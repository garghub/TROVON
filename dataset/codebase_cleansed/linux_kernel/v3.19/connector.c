int cn_netlink_send_mult(struct cn_msg *msg, u16 len, u32 portid, u32 __group,
gfp_t gfp_mask)
{
struct cn_callback_entry *__cbq;
unsigned int size;
struct sk_buff *skb;
struct nlmsghdr *nlh;
struct cn_msg *data;
struct cn_dev *dev = &cdev;
u32 group = 0;
int found = 0;
if (portid || __group) {
group = __group;
} else {
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
}
if (!portid && !netlink_has_listeners(dev->nls, group))
return -ESRCH;
size = sizeof(*msg) + len;
skb = nlmsg_new(size, gfp_mask);
if (!skb)
return -ENOMEM;
nlh = nlmsg_put(skb, 0, msg->seq, NLMSG_DONE, size, 0);
if (!nlh) {
kfree_skb(skb);
return -EMSGSIZE;
}
data = nlmsg_data(nlh);
memcpy(data, msg, size);
NETLINK_CB(skb).dst_group = group;
if (group)
return netlink_broadcast(dev->nls, skb, portid, group,
gfp_mask);
return netlink_unicast(dev->nls, skb, portid, !(gfp_mask&__GFP_WAIT));
}
int cn_netlink_send(struct cn_msg *msg, u32 portid, u32 __group,
gfp_t gfp_mask)
{
return cn_netlink_send_mult(msg, msg->len, portid, __group, gfp_mask);
}
static int cn_call_callback(struct sk_buff *skb)
{
struct nlmsghdr *nlh;
struct cn_callback_entry *i, *cbq = NULL;
struct cn_dev *dev = &cdev;
struct cn_msg *msg = nlmsg_data(nlmsg_hdr(skb));
struct netlink_skb_parms *nsp = &NETLINK_CB(skb);
int err = -ENODEV;
nlh = nlmsg_hdr(skb);
if (nlh->nlmsg_len < NLMSG_HDRLEN + sizeof(struct cn_msg) + msg->len)
return -EINVAL;
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
struct sk_buff *skb;
int len, err;
skb = skb_get(__skb);
if (skb->len >= NLMSG_HDRLEN) {
nlh = nlmsg_hdr(skb);
len = nlmsg_len(nlh);
if (len < (int)sizeof(struct cn_msg) ||
skb->len < nlh->nlmsg_len ||
len > CONNECTOR_MAX_MSG_SIZE) {
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
static int cn_init(void)
{
struct cn_dev *dev = &cdev;
struct netlink_kernel_cfg cfg = {
.groups = CN_NETLINK_USERS + 0xf,
.input = dev->input,
};
dev->nls = netlink_kernel_create(&init_net, NETLINK_CONNECTOR, &cfg);
if (!dev->nls)
return -EIO;
dev->cbdev = cn_queue_alloc_dev("cqueue", dev->nls);
if (!dev->cbdev) {
netlink_kernel_release(dev->nls);
return -EINVAL;
}
cn_already_initialized = 1;
proc_create("connector", S_IRUGO, init_net.proc_net, &cn_file_ops);
return 0;
}
static void cn_fini(void)
{
struct cn_dev *dev = &cdev;
cn_already_initialized = 0;
remove_proc_entry("connector", init_net.proc_net);
cn_queue_free_dev(dev->cbdev);
netlink_kernel_release(dev->nls);
}
