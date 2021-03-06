static int get_slot(struct macvlan_dev *vlan, struct macvtap_queue *q)
{
int i;
for (i = 0; i < MAX_MACVTAP_QUEUES; i++) {
if (rcu_dereference(vlan->taps[i]) == q)
return i;
}
BUG_ON(1);
}
static int macvtap_set_queue(struct net_device *dev, struct file *file,
struct macvtap_queue *q)
{
struct macvlan_dev *vlan = netdev_priv(dev);
int index;
int err = -EBUSY;
spin_lock(&macvtap_lock);
if (vlan->numvtaps == MAX_MACVTAP_QUEUES)
goto out;
err = 0;
index = get_slot(vlan, NULL);
rcu_assign_pointer(q->vlan, vlan);
rcu_assign_pointer(vlan->taps[index], q);
sock_hold(&q->sk);
q->file = file;
file->private_data = q;
vlan->numvtaps++;
out:
spin_unlock(&macvtap_lock);
return err;
}
static void macvtap_put_queue(struct macvtap_queue *q)
{
struct macvlan_dev *vlan;
spin_lock(&macvtap_lock);
vlan = rcu_dereference_protected(q->vlan,
lockdep_is_held(&macvtap_lock));
if (vlan) {
int index = get_slot(vlan, q);
RCU_INIT_POINTER(vlan->taps[index], NULL);
RCU_INIT_POINTER(q->vlan, NULL);
sock_put(&q->sk);
--vlan->numvtaps;
}
spin_unlock(&macvtap_lock);
synchronize_rcu();
sock_put(&q->sk);
}
static struct macvtap_queue *macvtap_get_queue(struct net_device *dev,
struct sk_buff *skb)
{
struct macvlan_dev *vlan = netdev_priv(dev);
struct macvtap_queue *tap = NULL;
int numvtaps = vlan->numvtaps;
__u32 rxq;
if (!numvtaps)
goto out;
rxq = skb_get_rxhash(skb);
if (rxq) {
tap = rcu_dereference(vlan->taps[rxq % numvtaps]);
if (tap)
goto out;
}
if (likely(skb_rx_queue_recorded(skb))) {
rxq = skb_get_rx_queue(skb);
while (unlikely(rxq >= numvtaps))
rxq -= numvtaps;
tap = rcu_dereference(vlan->taps[rxq]);
if (tap)
goto out;
}
for (rxq = 0; rxq < MAX_MACVTAP_QUEUES; rxq++) {
tap = rcu_dereference(vlan->taps[rxq]);
if (tap)
break;
}
out:
return tap;
}
static void macvtap_del_queues(struct net_device *dev)
{
struct macvlan_dev *vlan = netdev_priv(dev);
struct macvtap_queue *q, *qlist[MAX_MACVTAP_QUEUES];
int i, j = 0;
spin_lock(&macvtap_lock);
for (i = 0; i < MAX_MACVTAP_QUEUES && vlan->numvtaps; i++) {
q = rcu_dereference_protected(vlan->taps[i],
lockdep_is_held(&macvtap_lock));
if (q) {
qlist[j++] = q;
RCU_INIT_POINTER(vlan->taps[i], NULL);
RCU_INIT_POINTER(q->vlan, NULL);
vlan->numvtaps--;
}
}
BUG_ON(vlan->numvtaps != 0);
vlan->numvtaps = MAX_MACVTAP_QUEUES;
spin_unlock(&macvtap_lock);
synchronize_rcu();
for (--j; j >= 0; j--)
sock_put(&qlist[j]->sk);
}
static int macvtap_forward(struct net_device *dev, struct sk_buff *skb)
{
struct macvtap_queue *q = macvtap_get_queue(dev, skb);
if (!q)
goto drop;
if (skb_queue_len(&q->sk.sk_receive_queue) >= dev->tx_queue_len)
goto drop;
skb_queue_tail(&q->sk.sk_receive_queue, skb);
wake_up_interruptible_poll(sk_sleep(&q->sk), POLLIN | POLLRDNORM | POLLRDBAND);
return NET_RX_SUCCESS;
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static int macvtap_receive(struct sk_buff *skb)
{
skb_push(skb, ETH_HLEN);
return macvtap_forward(skb->dev, skb);
}
static int macvtap_get_minor(struct macvlan_dev *vlan)
{
int retval = -ENOMEM;
int id;
mutex_lock(&minor_lock);
if (idr_pre_get(&minor_idr, GFP_KERNEL) == 0)
goto exit;
retval = idr_get_new_above(&minor_idr, vlan, 1, &id);
if (retval < 0) {
if (retval == -EAGAIN)
retval = -ENOMEM;
goto exit;
}
if (id < MACVTAP_NUM_DEVS) {
vlan->minor = id;
} else {
printk(KERN_ERR "too many macvtap devices\n");
retval = -EINVAL;
idr_remove(&minor_idr, id);
}
exit:
mutex_unlock(&minor_lock);
return retval;
}
static void macvtap_free_minor(struct macvlan_dev *vlan)
{
mutex_lock(&minor_lock);
if (vlan->minor) {
idr_remove(&minor_idr, vlan->minor);
vlan->minor = 0;
}
mutex_unlock(&minor_lock);
}
static struct net_device *dev_get_by_macvtap_minor(int minor)
{
struct net_device *dev = NULL;
struct macvlan_dev *vlan;
mutex_lock(&minor_lock);
vlan = idr_find(&minor_idr, minor);
if (vlan) {
dev = vlan->dev;
dev_hold(dev);
}
mutex_unlock(&minor_lock);
return dev;
}
static int macvtap_newlink(struct net *src_net,
struct net_device *dev,
struct nlattr *tb[],
struct nlattr *data[])
{
return macvlan_common_newlink(src_net, dev, tb, data,
macvtap_receive, macvtap_forward);
}
static void macvtap_dellink(struct net_device *dev,
struct list_head *head)
{
macvtap_del_queues(dev);
macvlan_dellink(dev, head);
}
static void macvtap_setup(struct net_device *dev)
{
macvlan_common_setup(dev);
dev->tx_queue_len = TUN_READQ_SIZE;
}
static void macvtap_sock_write_space(struct sock *sk)
{
wait_queue_head_t *wqueue;
if (!sock_writeable(sk) ||
!test_and_clear_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags))
return;
wqueue = sk_sleep(sk);
if (wqueue && waitqueue_active(wqueue))
wake_up_interruptible_poll(wqueue, POLLOUT | POLLWRNORM | POLLWRBAND);
}
static void macvtap_sock_destruct(struct sock *sk)
{
skb_queue_purge(&sk->sk_receive_queue);
}
static int macvtap_open(struct inode *inode, struct file *file)
{
struct net *net = current->nsproxy->net_ns;
struct net_device *dev = dev_get_by_macvtap_minor(iminor(inode));
struct macvtap_queue *q;
int err;
err = -ENODEV;
if (!dev)
goto out;
err = -ENOMEM;
q = (struct macvtap_queue *)sk_alloc(net, AF_UNSPEC, GFP_KERNEL,
&macvtap_proto);
if (!q)
goto out;
q->sock.wq = &q->wq;
init_waitqueue_head(&q->wq.wait);
q->sock.type = SOCK_RAW;
q->sock.state = SS_CONNECTED;
q->sock.file = file;
q->sock.ops = &macvtap_socket_ops;
sock_init_data(&q->sock, &q->sk);
q->sk.sk_write_space = macvtap_sock_write_space;
q->sk.sk_destruct = macvtap_sock_destruct;
q->flags = IFF_VNET_HDR | IFF_NO_PI | IFF_TAP;
q->vnet_hdr_sz = sizeof(struct virtio_net_hdr);
if ((dev->features & NETIF_F_HIGHDMA) && (dev->features & NETIF_F_SG))
sock_set_flag(&q->sk, SOCK_ZEROCOPY);
err = macvtap_set_queue(dev, file, q);
if (err)
sock_put(&q->sk);
out:
if (dev)
dev_put(dev);
return err;
}
static int macvtap_release(struct inode *inode, struct file *file)
{
struct macvtap_queue *q = file->private_data;
macvtap_put_queue(q);
return 0;
}
static unsigned int macvtap_poll(struct file *file, poll_table * wait)
{
struct macvtap_queue *q = file->private_data;
unsigned int mask = POLLERR;
if (!q)
goto out;
mask = 0;
poll_wait(file, &q->wq.wait, wait);
if (!skb_queue_empty(&q->sk.sk_receive_queue))
mask |= POLLIN | POLLRDNORM;
if (sock_writeable(&q->sk) ||
(!test_and_set_bit(SOCK_ASYNC_NOSPACE, &q->sock.flags) &&
sock_writeable(&q->sk)))
mask |= POLLOUT | POLLWRNORM;
out:
return mask;
}
static inline struct sk_buff *macvtap_alloc_skb(struct sock *sk, size_t prepad,
size_t len, size_t linear,
int noblock, int *err)
{
struct sk_buff *skb;
if (prepad + len < PAGE_SIZE || !linear)
linear = len;
skb = sock_alloc_send_pskb(sk, prepad + linear, len - linear, noblock,
err);
if (!skb)
return NULL;
skb_reserve(skb, prepad);
skb_put(skb, linear);
skb->data_len = len - linear;
skb->len += len - linear;
return skb;
}
static int zerocopy_sg_from_iovec(struct sk_buff *skb, const struct iovec *from,
int offset, size_t count)
{
int len = iov_length(from, count) - offset;
int copy = skb_headlen(skb);
int size, offset1 = 0;
int i = 0;
while (count && (offset >= from->iov_len)) {
offset -= from->iov_len;
++from;
--count;
}
while (count && (copy > 0)) {
size = min_t(unsigned int, copy, from->iov_len - offset);
if (copy_from_user(skb->data + offset1, from->iov_base + offset,
size))
return -EFAULT;
if (copy > size) {
++from;
--count;
}
copy -= size;
offset1 += size;
offset = 0;
}
if (len == offset1)
return 0;
while (count--) {
struct page *page[MAX_SKB_FRAGS];
int num_pages;
unsigned long base;
len = from->iov_len - offset1;
if (!len) {
offset1 = 0;
++from;
continue;
}
base = (unsigned long)from->iov_base + offset1;
size = ((base & ~PAGE_MASK) + len + ~PAGE_MASK) >> PAGE_SHIFT;
num_pages = get_user_pages_fast(base, size, 0, &page[i]);
if ((num_pages != size) ||
(num_pages > MAX_SKB_FRAGS - skb_shinfo(skb)->nr_frags))
return -EFAULT;
skb->data_len += len;
skb->len += len;
skb->truesize += len;
atomic_add(len, &skb->sk->sk_wmem_alloc);
while (len) {
int off = base & ~PAGE_MASK;
int size = min_t(int, len, PAGE_SIZE - off);
__skb_fill_page_desc(skb, i, page[i], off, size);
skb_shinfo(skb)->nr_frags++;
base += size;
len -= size;
i++;
}
offset1 = 0;
++from;
}
return 0;
}
static int macvtap_skb_from_vnet_hdr(struct sk_buff *skb,
struct virtio_net_hdr *vnet_hdr)
{
unsigned short gso_type = 0;
if (vnet_hdr->gso_type != VIRTIO_NET_HDR_GSO_NONE) {
switch (vnet_hdr->gso_type & ~VIRTIO_NET_HDR_GSO_ECN) {
case VIRTIO_NET_HDR_GSO_TCPV4:
gso_type = SKB_GSO_TCPV4;
break;
case VIRTIO_NET_HDR_GSO_TCPV6:
gso_type = SKB_GSO_TCPV6;
break;
case VIRTIO_NET_HDR_GSO_UDP:
gso_type = SKB_GSO_UDP;
break;
default:
return -EINVAL;
}
if (vnet_hdr->gso_type & VIRTIO_NET_HDR_GSO_ECN)
gso_type |= SKB_GSO_TCP_ECN;
if (vnet_hdr->gso_size == 0)
return -EINVAL;
}
if (vnet_hdr->flags & VIRTIO_NET_HDR_F_NEEDS_CSUM) {
if (!skb_partial_csum_set(skb, vnet_hdr->csum_start,
vnet_hdr->csum_offset))
return -EINVAL;
}
if (vnet_hdr->gso_type != VIRTIO_NET_HDR_GSO_NONE) {
skb_shinfo(skb)->gso_size = vnet_hdr->gso_size;
skb_shinfo(skb)->gso_type = gso_type;
skb_shinfo(skb)->gso_type |= SKB_GSO_DODGY;
skb_shinfo(skb)->gso_segs = 0;
}
return 0;
}
static int macvtap_skb_to_vnet_hdr(const struct sk_buff *skb,
struct virtio_net_hdr *vnet_hdr)
{
memset(vnet_hdr, 0, sizeof(*vnet_hdr));
if (skb_is_gso(skb)) {
struct skb_shared_info *sinfo = skb_shinfo(skb);
vnet_hdr->hdr_len = skb_headlen(skb);
vnet_hdr->gso_size = sinfo->gso_size;
if (sinfo->gso_type & SKB_GSO_TCPV4)
vnet_hdr->gso_type = VIRTIO_NET_HDR_GSO_TCPV4;
else if (sinfo->gso_type & SKB_GSO_TCPV6)
vnet_hdr->gso_type = VIRTIO_NET_HDR_GSO_TCPV6;
else if (sinfo->gso_type & SKB_GSO_UDP)
vnet_hdr->gso_type = VIRTIO_NET_HDR_GSO_UDP;
else
BUG();
if (sinfo->gso_type & SKB_GSO_TCP_ECN)
vnet_hdr->gso_type |= VIRTIO_NET_HDR_GSO_ECN;
} else
vnet_hdr->gso_type = VIRTIO_NET_HDR_GSO_NONE;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
vnet_hdr->flags = VIRTIO_NET_HDR_F_NEEDS_CSUM;
vnet_hdr->csum_start = skb_checksum_start_offset(skb);
vnet_hdr->csum_offset = skb->csum_offset;
} else if (skb->ip_summed == CHECKSUM_UNNECESSARY) {
vnet_hdr->flags = VIRTIO_NET_HDR_F_DATA_VALID;
}
return 0;
}
static ssize_t macvtap_get_user(struct macvtap_queue *q, struct msghdr *m,
const struct iovec *iv, unsigned long total_len,
size_t count, int noblock)
{
struct sk_buff *skb;
struct macvlan_dev *vlan;
unsigned long len = total_len;
int err;
struct virtio_net_hdr vnet_hdr = { 0 };
int vnet_hdr_len = 0;
int copylen;
bool zerocopy = false;
if (q->flags & IFF_VNET_HDR) {
vnet_hdr_len = q->vnet_hdr_sz;
err = -EINVAL;
if (len < vnet_hdr_len)
goto err;
len -= vnet_hdr_len;
err = memcpy_fromiovecend((void *)&vnet_hdr, iv, 0,
sizeof(vnet_hdr));
if (err < 0)
goto err;
if ((vnet_hdr.flags & VIRTIO_NET_HDR_F_NEEDS_CSUM) &&
vnet_hdr.csum_start + vnet_hdr.csum_offset + 2 >
vnet_hdr.hdr_len)
vnet_hdr.hdr_len = vnet_hdr.csum_start +
vnet_hdr.csum_offset + 2;
err = -EINVAL;
if (vnet_hdr.hdr_len > len)
goto err;
}
err = -EINVAL;
if (unlikely(len < ETH_HLEN))
goto err;
if (m && m->msg_control && sock_flag(&q->sk, SOCK_ZEROCOPY))
zerocopy = true;
if (zerocopy) {
copylen = vnet_hdr.hdr_len;
if (!copylen)
copylen = GOODCOPY_LEN;
} else
copylen = len;
skb = macvtap_alloc_skb(&q->sk, NET_IP_ALIGN, copylen,
vnet_hdr.hdr_len, noblock, &err);
if (!skb)
goto err;
if (zerocopy) {
err = zerocopy_sg_from_iovec(skb, iv, vnet_hdr_len, count);
skb_shinfo(skb)->tx_flags |= SKBTX_DEV_ZEROCOPY;
} else
err = skb_copy_datagram_from_iovec(skb, 0, iv, vnet_hdr_len,
len);
if (err)
goto err_kfree;
skb_set_network_header(skb, ETH_HLEN);
skb_reset_mac_header(skb);
skb->protocol = eth_hdr(skb)->h_proto;
if (vnet_hdr_len) {
err = macvtap_skb_from_vnet_hdr(skb, &vnet_hdr);
if (err)
goto err_kfree;
}
rcu_read_lock_bh();
vlan = rcu_dereference_bh(q->vlan);
if (zerocopy)
skb_shinfo(skb)->destructor_arg = m->msg_control;
if (vlan)
macvlan_start_xmit(skb, vlan->dev);
else
kfree_skb(skb);
rcu_read_unlock_bh();
return total_len;
err_kfree:
kfree_skb(skb);
err:
rcu_read_lock_bh();
vlan = rcu_dereference_bh(q->vlan);
if (vlan)
vlan->dev->stats.tx_dropped++;
rcu_read_unlock_bh();
return err;
}
static ssize_t macvtap_aio_write(struct kiocb *iocb, const struct iovec *iv,
unsigned long count, loff_t pos)
{
struct file *file = iocb->ki_filp;
ssize_t result = -ENOLINK;
struct macvtap_queue *q = file->private_data;
result = macvtap_get_user(q, NULL, iv, iov_length(iv, count), count,
file->f_flags & O_NONBLOCK);
return result;
}
static ssize_t macvtap_put_user(struct macvtap_queue *q,
const struct sk_buff *skb,
const struct iovec *iv, int len)
{
struct macvlan_dev *vlan;
int ret;
int vnet_hdr_len = 0;
if (q->flags & IFF_VNET_HDR) {
struct virtio_net_hdr vnet_hdr;
vnet_hdr_len = q->vnet_hdr_sz;
if ((len -= vnet_hdr_len) < 0)
return -EINVAL;
ret = macvtap_skb_to_vnet_hdr(skb, &vnet_hdr);
if (ret)
return ret;
if (memcpy_toiovecend(iv, (void *)&vnet_hdr, 0, sizeof(vnet_hdr)))
return -EFAULT;
}
len = min_t(int, skb->len, len);
ret = skb_copy_datagram_const_iovec(skb, 0, iv, vnet_hdr_len, len);
rcu_read_lock_bh();
vlan = rcu_dereference_bh(q->vlan);
if (vlan)
macvlan_count_rx(vlan, len, ret == 0, 0);
rcu_read_unlock_bh();
return ret ? ret : (len + vnet_hdr_len);
}
static ssize_t macvtap_do_read(struct macvtap_queue *q, struct kiocb *iocb,
const struct iovec *iv, unsigned long len,
int noblock)
{
DECLARE_WAITQUEUE(wait, current);
struct sk_buff *skb;
ssize_t ret = 0;
add_wait_queue(sk_sleep(&q->sk), &wait);
while (len) {
current->state = TASK_INTERRUPTIBLE;
skb = skb_dequeue(&q->sk.sk_receive_queue);
if (!skb) {
if (noblock) {
ret = -EAGAIN;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
schedule();
continue;
}
ret = macvtap_put_user(q, skb, iv, len);
kfree_skb(skb);
break;
}
current->state = TASK_RUNNING;
remove_wait_queue(sk_sleep(&q->sk), &wait);
return ret;
}
static ssize_t macvtap_aio_read(struct kiocb *iocb, const struct iovec *iv,
unsigned long count, loff_t pos)
{
struct file *file = iocb->ki_filp;
struct macvtap_queue *q = file->private_data;
ssize_t len, ret = 0;
len = iov_length(iv, count);
if (len < 0) {
ret = -EINVAL;
goto out;
}
ret = macvtap_do_read(q, iocb, iv, len, file->f_flags & O_NONBLOCK);
ret = min_t(ssize_t, ret, len);
out:
return ret;
}
static long macvtap_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct macvtap_queue *q = file->private_data;
struct macvlan_dev *vlan;
void __user *argp = (void __user *)arg;
struct ifreq __user *ifr = argp;
unsigned int __user *up = argp;
unsigned int u;
int __user *sp = argp;
int s;
int ret;
switch (cmd) {
case TUNSETIFF:
if (get_user(u, &ifr->ifr_flags))
return -EFAULT;
ret = 0;
if ((u & ~IFF_VNET_HDR) != (IFF_NO_PI | IFF_TAP))
ret = -EINVAL;
else
q->flags = u;
return ret;
case TUNGETIFF:
rcu_read_lock_bh();
vlan = rcu_dereference_bh(q->vlan);
if (vlan)
dev_hold(vlan->dev);
rcu_read_unlock_bh();
if (!vlan)
return -ENOLINK;
ret = 0;
if (copy_to_user(&ifr->ifr_name, vlan->dev->name, IFNAMSIZ) ||
put_user(q->flags, &ifr->ifr_flags))
ret = -EFAULT;
dev_put(vlan->dev);
return ret;
case TUNGETFEATURES:
if (put_user(IFF_TAP | IFF_NO_PI | IFF_VNET_HDR, up))
return -EFAULT;
return 0;
case TUNSETSNDBUF:
if (get_user(u, up))
return -EFAULT;
q->sk.sk_sndbuf = u;
return 0;
case TUNGETVNETHDRSZ:
s = q->vnet_hdr_sz;
if (put_user(s, sp))
return -EFAULT;
return 0;
case TUNSETVNETHDRSZ:
if (get_user(s, sp))
return -EFAULT;
if (s < (int)sizeof(struct virtio_net_hdr))
return -EINVAL;
q->vnet_hdr_sz = s;
return 0;
case TUNSETOFFLOAD:
if (arg & ~(TUN_F_CSUM | TUN_F_TSO4 | TUN_F_TSO6 |
TUN_F_TSO_ECN | TUN_F_UFO))
return -EINVAL;
if (!(q->flags & IFF_VNET_HDR))
return -EINVAL;
return 0;
default:
return -EINVAL;
}
}
static long macvtap_compat_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
return macvtap_ioctl(file, cmd, (unsigned long)compat_ptr(arg));
}
static int macvtap_sendmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *m, size_t total_len)
{
struct macvtap_queue *q = container_of(sock, struct macvtap_queue, sock);
return macvtap_get_user(q, m, m->msg_iov, total_len, m->msg_iovlen,
m->msg_flags & MSG_DONTWAIT);
}
static int macvtap_recvmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *m, size_t total_len,
int flags)
{
struct macvtap_queue *q = container_of(sock, struct macvtap_queue, sock);
int ret;
if (flags & ~(MSG_DONTWAIT|MSG_TRUNC))
return -EINVAL;
ret = macvtap_do_read(q, iocb, m->msg_iov, total_len,
flags & MSG_DONTWAIT);
if (ret > total_len) {
m->msg_flags |= MSG_TRUNC;
ret = flags & MSG_TRUNC ? ret : total_len;
}
return ret;
}
struct socket *macvtap_get_socket(struct file *file)
{
struct macvtap_queue *q;
if (file->f_op != &macvtap_fops)
return ERR_PTR(-EINVAL);
q = file->private_data;
if (!q)
return ERR_PTR(-EBADFD);
return &q->sock;
}
static int macvtap_device_event(struct notifier_block *unused,
unsigned long event, void *ptr)
{
struct net_device *dev = ptr;
struct macvlan_dev *vlan;
struct device *classdev;
dev_t devt;
int err;
if (dev->rtnl_link_ops != &macvtap_link_ops)
return NOTIFY_DONE;
vlan = netdev_priv(dev);
switch (event) {
case NETDEV_REGISTER:
err = macvtap_get_minor(vlan);
if (err)
return notifier_from_errno(err);
devt = MKDEV(MAJOR(macvtap_major), vlan->minor);
classdev = device_create(macvtap_class, &dev->dev, devt,
dev, "tap%d", dev->ifindex);
if (IS_ERR(classdev)) {
macvtap_free_minor(vlan);
return notifier_from_errno(PTR_ERR(classdev));
}
break;
case NETDEV_UNREGISTER:
devt = MKDEV(MAJOR(macvtap_major), vlan->minor);
device_destroy(macvtap_class, devt);
macvtap_free_minor(vlan);
break;
}
return NOTIFY_DONE;
}
static int macvtap_init(void)
{
int err;
err = alloc_chrdev_region(&macvtap_major, 0,
MACVTAP_NUM_DEVS, "macvtap");
if (err)
goto out1;
cdev_init(&macvtap_cdev, &macvtap_fops);
err = cdev_add(&macvtap_cdev, macvtap_major, MACVTAP_NUM_DEVS);
if (err)
goto out2;
macvtap_class = class_create(THIS_MODULE, "macvtap");
if (IS_ERR(macvtap_class)) {
err = PTR_ERR(macvtap_class);
goto out3;
}
err = register_netdevice_notifier(&macvtap_notifier_block);
if (err)
goto out4;
err = macvlan_link_register(&macvtap_link_ops);
if (err)
goto out5;
return 0;
out5:
unregister_netdevice_notifier(&macvtap_notifier_block);
out4:
class_unregister(macvtap_class);
out3:
cdev_del(&macvtap_cdev);
out2:
unregister_chrdev_region(macvtap_major, MACVTAP_NUM_DEVS);
out1:
return err;
}
static void macvtap_exit(void)
{
rtnl_link_unregister(&macvtap_link_ops);
unregister_netdevice_notifier(&macvtap_notifier_block);
class_unregister(macvtap_class);
cdev_del(&macvtap_cdev);
unregister_chrdev_region(macvtap_major, MACVTAP_NUM_DEVS);
}
