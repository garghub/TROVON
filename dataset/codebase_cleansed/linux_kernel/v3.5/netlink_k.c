static void netlink_rcv_cb(struct sk_buff *skb)
{
struct nlmsghdr *nlh;
struct net_device *dev;
u32 mlen;
void *msg;
int ifindex;
if (skb->len >= NLMSG_SPACE(0)) {
nlh = (struct nlmsghdr *)skb->data;
if (skb->len < nlh->nlmsg_len ||
nlh->nlmsg_len > ND_MAX_MSG_LEN) {
printk(KERN_ERR "Invalid length (%d,%d)\n", skb->len,
nlh->nlmsg_len);
return;
}
memcpy(&ifindex, ND_NLMSG_IFIDX(nlh), ND_IFINDEX_LEN);
msg = ND_NLMSG_DATA(nlh);
mlen = ND_NLMSG_R_LEN(nlh);
if (rcv_cb) {
dev = dev_get_by_index(&init_net, ifindex);
if (dev) {
rcv_cb(dev, nlh->nlmsg_type, msg, mlen);
dev_put(dev);
} else
printk(KERN_ERR "dev_get_by_index(%d) "
"is not found.\n", ifindex);
} else
printk(KERN_ERR "Unregistered Callback\n");
}
}
static void netlink_rcv(struct sk_buff *skb)
{
mutex_lock(&netlink_mutex);
netlink_rcv_cb(skb);
mutex_unlock(&netlink_mutex);
}
struct sock *netlink_init(int unit, void (*cb)(struct net_device *dev, u16 type,
void *msg, int len))
{
struct sock *sock;
#if !defined(DEFINE_MUTEX)
init_MUTEX(&netlink_mutex);
#endif
sock = netlink_kernel_create(&init_net, unit, 0, netlink_rcv, NULL,
THIS_MODULE);
if (sock)
rcv_cb = cb;
return sock;
}
void netlink_exit(struct sock *sock)
{
netlink_kernel_release(sock);
}
int netlink_send(struct sock *sock, int group, u16 type, void *msg, int len)
{
static u32 seq;
struct sk_buff *skb = NULL;
struct nlmsghdr *nlh;
int ret = 0;
if (group > ND_MAX_GROUP) {
printk(KERN_ERR "Group %d is invalied.\n", group);
printk(KERN_ERR "Valid group is 0 ~ %d.\n", ND_MAX_GROUP);
return -EINVAL;
}
skb = alloc_skb(NLMSG_SPACE(len), GFP_ATOMIC);
if (!skb) {
printk(KERN_ERR "netlink_broadcast ret=%d\n", ret);
return -ENOMEM;
}
seq++;
nlh = NLMSG_PUT(skb, 0, seq, type, len);
memcpy(NLMSG_DATA(nlh), msg, len);
NETLINK_CB(skb).pid = 0;
NETLINK_CB(skb).dst_group = 0;
ret = netlink_broadcast(sock, skb, 0, group+1, GFP_ATOMIC);
if (!ret)
return len;
else {
if (ret != -ESRCH) {
printk(KERN_ERR "netlink_broadcast g=%d, t=%d, l=%d, r=%d\n",
group, type, len, ret);
}
ret = 0;
}
nlmsg_failure:
return ret;
}
