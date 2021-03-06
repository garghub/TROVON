static inline struct tun_sock *tun_sk(struct sock *sk)
{
return container_of(sk, struct tun_sock, sk);
}
static int tun_attach(struct tun_struct *tun, struct file *file)
{
struct tun_file *tfile = file->private_data;
int err;
ASSERT_RTNL();
netif_tx_lock_bh(tun->dev);
err = -EINVAL;
if (tfile->tun)
goto out;
err = -EBUSY;
if (tun->tfile)
goto out;
err = 0;
tfile->tun = tun;
tun->tfile = tfile;
tun->socket.file = file;
netif_carrier_on(tun->dev);
dev_hold(tun->dev);
sock_hold(tun->socket.sk);
atomic_inc(&tfile->count);
out:
netif_tx_unlock_bh(tun->dev);
return err;
}
static void __tun_detach(struct tun_struct *tun)
{
netif_tx_lock_bh(tun->dev);
netif_carrier_off(tun->dev);
tun->tfile = NULL;
tun->socket.file = NULL;
netif_tx_unlock_bh(tun->dev);
skb_queue_purge(&tun->socket.sk->sk_receive_queue);
dev_put(tun->dev);
}
static void tun_detach(struct tun_struct *tun)
{
rtnl_lock();
__tun_detach(tun);
rtnl_unlock();
}
static struct tun_struct *__tun_get(struct tun_file *tfile)
{
struct tun_struct *tun = NULL;
if (atomic_inc_not_zero(&tfile->count))
tun = tfile->tun;
return tun;
}
static struct tun_struct *tun_get(struct file *file)
{
return __tun_get(file->private_data);
}
static void tun_put(struct tun_struct *tun)
{
struct tun_file *tfile = tun->tfile;
if (atomic_dec_and_test(&tfile->count))
tun_detach(tfile->tun);
}
static void addr_hash_set(u32 *mask, const u8 *addr)
{
int n = ether_crc(ETH_ALEN, addr) >> 26;
mask[n >> 5] |= (1 << (n & 31));
}
static unsigned int addr_hash_test(const u32 *mask, const u8 *addr)
{
int n = ether_crc(ETH_ALEN, addr) >> 26;
return mask[n >> 5] & (1 << (n & 31));
}
static int update_filter(struct tap_filter *filter, void __user *arg)
{
struct { u8 u[ETH_ALEN]; } *addr;
struct tun_filter uf;
int err, alen, n, nexact;
if (copy_from_user(&uf, arg, sizeof(uf)))
return -EFAULT;
if (!uf.count) {
filter->count = 0;
return 0;
}
alen = ETH_ALEN * uf.count;
addr = kmalloc(alen, GFP_KERNEL);
if (!addr)
return -ENOMEM;
if (copy_from_user(addr, arg + sizeof(uf), alen)) {
err = -EFAULT;
goto done;
}
filter->count = 0;
wmb();
for (n = 0; n < uf.count && n < FLT_EXACT_COUNT; n++)
memcpy(filter->addr[n], addr[n].u, ETH_ALEN);
nexact = n;
memset(filter->mask, 0, sizeof(filter->mask));
for (; n < uf.count; n++) {
if (!is_multicast_ether_addr(addr[n].u)) {
err = 0;
goto done;
}
addr_hash_set(filter->mask, addr[n].u);
}
if ((uf.flags & TUN_FLT_ALLMULTI))
memset(filter->mask, ~0, sizeof(filter->mask));
wmb();
filter->count = nexact;
err = nexact;
done:
kfree(addr);
return err;
}
static int run_filter(struct tap_filter *filter, const struct sk_buff *skb)
{
struct ethhdr *eh = (struct ethhdr *) skb->data;
int i;
for (i = 0; i < filter->count; i++)
if (!compare_ether_addr(eh->h_dest, filter->addr[i]))
return 1;
if (is_multicast_ether_addr(eh->h_dest))
return addr_hash_test(filter->mask, eh->h_dest);
return 0;
}
static int check_filter(struct tap_filter *filter, const struct sk_buff *skb)
{
if (!filter->count)
return 1;
return run_filter(filter, skb);
}
static void tun_net_uninit(struct net_device *dev)
{
struct tun_struct *tun = netdev_priv(dev);
struct tun_file *tfile = tun->tfile;
if (tfile) {
wake_up_all(&tun->wq.wait);
if (atomic_dec_and_test(&tfile->count))
__tun_detach(tun);
}
}
static void tun_free_netdev(struct net_device *dev)
{
struct tun_struct *tun = netdev_priv(dev);
sock_put(tun->socket.sk);
}
static int tun_net_open(struct net_device *dev)
{
netif_start_queue(dev);
return 0;
}
static int tun_net_close(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
static netdev_tx_t tun_net_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct tun_struct *tun = netdev_priv(dev);
tun_debug(KERN_INFO, tun, "tun_net_xmit %d\n", skb->len);
if (!tun->tfile)
goto drop;
if (!check_filter(&tun->txflt, skb))
goto drop;
if (tun->socket.sk->sk_filter &&
sk_filter(tun->socket.sk, skb))
goto drop;
if (skb_queue_len(&tun->socket.sk->sk_receive_queue) >= dev->tx_queue_len) {
if (!(tun->flags & TUN_ONE_QUEUE)) {
netif_stop_queue(dev);
dev->stats.tx_fifo_errors++;
} else {
goto drop;
}
}
skb_orphan(skb);
skb_queue_tail(&tun->socket.sk->sk_receive_queue, skb);
if (tun->flags & TUN_FASYNC)
kill_fasync(&tun->fasync, SIGIO, POLL_IN);
wake_up_interruptible_poll(&tun->wq.wait, POLLIN |
POLLRDNORM | POLLRDBAND);
return NETDEV_TX_OK;
drop:
dev->stats.tx_dropped++;
kfree_skb(skb);
return NETDEV_TX_OK;
}
static void tun_net_mclist(struct net_device *dev)
{
}
static int
tun_net_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < MIN_MTU || new_mtu + dev->hard_header_len > MAX_MTU)
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
static u32 tun_net_fix_features(struct net_device *dev, u32 features)
{
struct tun_struct *tun = netdev_priv(dev);
return (features & tun->set_features) | (features & ~TUN_USER_FEATURES);
}
static void tun_poll_controller(struct net_device *dev)
{
return;
}
static void tun_net_init(struct net_device *dev)
{
struct tun_struct *tun = netdev_priv(dev);
switch (tun->flags & TUN_TYPE_MASK) {
case TUN_TUN_DEV:
dev->netdev_ops = &tun_netdev_ops;
dev->hard_header_len = 0;
dev->addr_len = 0;
dev->mtu = 1500;
dev->type = ARPHRD_NONE;
dev->flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
dev->tx_queue_len = TUN_READQ_SIZE;
break;
case TUN_TAP_DEV:
dev->netdev_ops = &tap_netdev_ops;
ether_setup(dev);
random_ether_addr(dev->dev_addr);
dev->tx_queue_len = TUN_READQ_SIZE;
break;
}
}
static unsigned int tun_chr_poll(struct file *file, poll_table * wait)
{
struct tun_file *tfile = file->private_data;
struct tun_struct *tun = __tun_get(tfile);
struct sock *sk;
unsigned int mask = 0;
if (!tun)
return POLLERR;
sk = tun->socket.sk;
tun_debug(KERN_INFO, tun, "tun_chr_poll\n");
poll_wait(file, &tun->wq.wait, wait);
if (!skb_queue_empty(&sk->sk_receive_queue))
mask |= POLLIN | POLLRDNORM;
if (sock_writeable(sk) ||
(!test_and_set_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags) &&
sock_writeable(sk)))
mask |= POLLOUT | POLLWRNORM;
if (tun->dev->reg_state != NETREG_REGISTERED)
mask = POLLERR;
tun_put(tun);
return mask;
}
static inline struct sk_buff *tun_alloc_skb(struct tun_struct *tun,
size_t prepad, size_t len,
size_t linear, int noblock)
{
struct sock *sk = tun->socket.sk;
struct sk_buff *skb;
int err;
sock_update_classid(sk);
if (prepad + len < PAGE_SIZE || !linear)
linear = len;
skb = sock_alloc_send_pskb(sk, prepad + linear, len - linear, noblock,
&err);
if (!skb)
return ERR_PTR(err);
skb_reserve(skb, prepad);
skb_put(skb, linear);
skb->data_len = len - linear;
skb->len += len - linear;
return skb;
}
static __inline__ ssize_t tun_get_user(struct tun_struct *tun,
const struct iovec *iv, size_t count,
int noblock)
{
struct tun_pi pi = { 0, cpu_to_be16(ETH_P_IP) };
struct sk_buff *skb;
size_t len = count, align = 0;
struct virtio_net_hdr gso = { 0 };
int offset = 0;
if (!(tun->flags & TUN_NO_PI)) {
if ((len -= sizeof(pi)) > count)
return -EINVAL;
if (memcpy_fromiovecend((void *)&pi, iv, 0, sizeof(pi)))
return -EFAULT;
offset += sizeof(pi);
}
if (tun->flags & TUN_VNET_HDR) {
if ((len -= tun->vnet_hdr_sz) > count)
return -EINVAL;
if (memcpy_fromiovecend((void *)&gso, iv, offset, sizeof(gso)))
return -EFAULT;
if ((gso.flags & VIRTIO_NET_HDR_F_NEEDS_CSUM) &&
gso.csum_start + gso.csum_offset + 2 > gso.hdr_len)
gso.hdr_len = gso.csum_start + gso.csum_offset + 2;
if (gso.hdr_len > len)
return -EINVAL;
offset += tun->vnet_hdr_sz;
}
if ((tun->flags & TUN_TYPE_MASK) == TUN_TAP_DEV) {
align = NET_IP_ALIGN;
if (unlikely(len < ETH_HLEN ||
(gso.hdr_len && gso.hdr_len < ETH_HLEN)))
return -EINVAL;
}
skb = tun_alloc_skb(tun, align, len, gso.hdr_len, noblock);
if (IS_ERR(skb)) {
if (PTR_ERR(skb) != -EAGAIN)
tun->dev->stats.rx_dropped++;
return PTR_ERR(skb);
}
if (skb_copy_datagram_from_iovec(skb, 0, iv, offset, len)) {
tun->dev->stats.rx_dropped++;
kfree_skb(skb);
return -EFAULT;
}
if (gso.flags & VIRTIO_NET_HDR_F_NEEDS_CSUM) {
if (!skb_partial_csum_set(skb, gso.csum_start,
gso.csum_offset)) {
tun->dev->stats.rx_frame_errors++;
kfree_skb(skb);
return -EINVAL;
}
}
switch (tun->flags & TUN_TYPE_MASK) {
case TUN_TUN_DEV:
if (tun->flags & TUN_NO_PI) {
switch (skb->data[0] & 0xf0) {
case 0x40:
pi.proto = htons(ETH_P_IP);
break;
case 0x60:
pi.proto = htons(ETH_P_IPV6);
break;
default:
tun->dev->stats.rx_dropped++;
kfree_skb(skb);
return -EINVAL;
}
}
skb_reset_mac_header(skb);
skb->protocol = pi.proto;
skb->dev = tun->dev;
break;
case TUN_TAP_DEV:
skb->protocol = eth_type_trans(skb, tun->dev);
break;
};
if (gso.gso_type != VIRTIO_NET_HDR_GSO_NONE) {
pr_debug("GSO!\n");
switch (gso.gso_type & ~VIRTIO_NET_HDR_GSO_ECN) {
case VIRTIO_NET_HDR_GSO_TCPV4:
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV4;
break;
case VIRTIO_NET_HDR_GSO_TCPV6:
skb_shinfo(skb)->gso_type = SKB_GSO_TCPV6;
break;
case VIRTIO_NET_HDR_GSO_UDP:
skb_shinfo(skb)->gso_type = SKB_GSO_UDP;
break;
default:
tun->dev->stats.rx_frame_errors++;
kfree_skb(skb);
return -EINVAL;
}
if (gso.gso_type & VIRTIO_NET_HDR_GSO_ECN)
skb_shinfo(skb)->gso_type |= SKB_GSO_TCP_ECN;
skb_shinfo(skb)->gso_size = gso.gso_size;
if (skb_shinfo(skb)->gso_size == 0) {
tun->dev->stats.rx_frame_errors++;
kfree_skb(skb);
return -EINVAL;
}
skb_shinfo(skb)->gso_type |= SKB_GSO_DODGY;
skb_shinfo(skb)->gso_segs = 0;
}
netif_rx_ni(skb);
tun->dev->stats.rx_packets++;
tun->dev->stats.rx_bytes += len;
return count;
}
static ssize_t tun_chr_aio_write(struct kiocb *iocb, const struct iovec *iv,
unsigned long count, loff_t pos)
{
struct file *file = iocb->ki_filp;
struct tun_struct *tun = tun_get(file);
ssize_t result;
if (!tun)
return -EBADFD;
tun_debug(KERN_INFO, tun, "tun_chr_write %ld\n", count);
result = tun_get_user(tun, iv, iov_length(iv, count),
file->f_flags & O_NONBLOCK);
tun_put(tun);
return result;
}
static __inline__ ssize_t tun_put_user(struct tun_struct *tun,
struct sk_buff *skb,
const struct iovec *iv, int len)
{
struct tun_pi pi = { 0, skb->protocol };
ssize_t total = 0;
if (!(tun->flags & TUN_NO_PI)) {
if ((len -= sizeof(pi)) < 0)
return -EINVAL;
if (len < skb->len) {
pi.flags |= TUN_PKT_STRIP;
}
if (memcpy_toiovecend(iv, (void *) &pi, 0, sizeof(pi)))
return -EFAULT;
total += sizeof(pi);
}
if (tun->flags & TUN_VNET_HDR) {
struct virtio_net_hdr gso = { 0 };
if ((len -= tun->vnet_hdr_sz) < 0)
return -EINVAL;
if (skb_is_gso(skb)) {
struct skb_shared_info *sinfo = skb_shinfo(skb);
gso.hdr_len = skb_headlen(skb);
gso.gso_size = sinfo->gso_size;
if (sinfo->gso_type & SKB_GSO_TCPV4)
gso.gso_type = VIRTIO_NET_HDR_GSO_TCPV4;
else if (sinfo->gso_type & SKB_GSO_TCPV6)
gso.gso_type = VIRTIO_NET_HDR_GSO_TCPV6;
else if (sinfo->gso_type & SKB_GSO_UDP)
gso.gso_type = VIRTIO_NET_HDR_GSO_UDP;
else {
pr_err("unexpected GSO type: "
"0x%x, gso_size %d, hdr_len %d\n",
sinfo->gso_type, gso.gso_size,
gso.hdr_len);
print_hex_dump(KERN_ERR, "tun: ",
DUMP_PREFIX_NONE,
16, 1, skb->head,
min((int)gso.hdr_len, 64), true);
WARN_ON_ONCE(1);
return -EINVAL;
}
if (sinfo->gso_type & SKB_GSO_TCP_ECN)
gso.gso_type |= VIRTIO_NET_HDR_GSO_ECN;
} else
gso.gso_type = VIRTIO_NET_HDR_GSO_NONE;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
gso.flags = VIRTIO_NET_HDR_F_NEEDS_CSUM;
gso.csum_start = skb_checksum_start_offset(skb);
gso.csum_offset = skb->csum_offset;
}
if (unlikely(memcpy_toiovecend(iv, (void *)&gso, total,
sizeof(gso))))
return -EFAULT;
total += tun->vnet_hdr_sz;
}
len = min_t(int, skb->len, len);
skb_copy_datagram_const_iovec(skb, 0, iv, total, len);
total += skb->len;
tun->dev->stats.tx_packets++;
tun->dev->stats.tx_bytes += len;
return total;
}
static ssize_t tun_do_read(struct tun_struct *tun,
struct kiocb *iocb, const struct iovec *iv,
ssize_t len, int noblock)
{
DECLARE_WAITQUEUE(wait, current);
struct sk_buff *skb;
ssize_t ret = 0;
tun_debug(KERN_INFO, tun, "tun_chr_read\n");
add_wait_queue(&tun->wq.wait, &wait);
while (len) {
current->state = TASK_INTERRUPTIBLE;
if (!(skb=skb_dequeue(&tun->socket.sk->sk_receive_queue))) {
if (noblock) {
ret = -EAGAIN;
break;
}
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
if (tun->dev->reg_state != NETREG_REGISTERED) {
ret = -EIO;
break;
}
schedule();
continue;
}
netif_wake_queue(tun->dev);
ret = tun_put_user(tun, skb, iv, len);
kfree_skb(skb);
break;
}
current->state = TASK_RUNNING;
remove_wait_queue(&tun->wq.wait, &wait);
return ret;
}
static ssize_t tun_chr_aio_read(struct kiocb *iocb, const struct iovec *iv,
unsigned long count, loff_t pos)
{
struct file *file = iocb->ki_filp;
struct tun_file *tfile = file->private_data;
struct tun_struct *tun = __tun_get(tfile);
ssize_t len, ret;
if (!tun)
return -EBADFD;
len = iov_length(iv, count);
if (len < 0) {
ret = -EINVAL;
goto out;
}
ret = tun_do_read(tun, iocb, iv, len, file->f_flags & O_NONBLOCK);
ret = min_t(ssize_t, ret, len);
out:
tun_put(tun);
return ret;
}
static void tun_setup(struct net_device *dev)
{
struct tun_struct *tun = netdev_priv(dev);
tun->owner = -1;
tun->group = -1;
dev->ethtool_ops = &tun_ethtool_ops;
dev->destructor = tun_free_netdev;
}
static int tun_validate(struct nlattr *tb[], struct nlattr *data[])
{
return -EINVAL;
}
static void tun_sock_write_space(struct sock *sk)
{
struct tun_struct *tun;
wait_queue_head_t *wqueue;
if (!sock_writeable(sk))
return;
if (!test_and_clear_bit(SOCK_ASYNC_NOSPACE, &sk->sk_socket->flags))
return;
wqueue = sk_sleep(sk);
if (wqueue && waitqueue_active(wqueue))
wake_up_interruptible_sync_poll(wqueue, POLLOUT |
POLLWRNORM | POLLWRBAND);
tun = tun_sk(sk)->tun;
kill_fasync(&tun->fasync, SIGIO, POLL_OUT);
}
static void tun_sock_destruct(struct sock *sk)
{
free_netdev(tun_sk(sk)->tun->dev);
}
static int tun_sendmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *m, size_t total_len)
{
struct tun_struct *tun = container_of(sock, struct tun_struct, socket);
return tun_get_user(tun, m->msg_iov, total_len,
m->msg_flags & MSG_DONTWAIT);
}
static int tun_recvmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *m, size_t total_len,
int flags)
{
struct tun_struct *tun = container_of(sock, struct tun_struct, socket);
int ret;
if (flags & ~(MSG_DONTWAIT|MSG_TRUNC))
return -EINVAL;
ret = tun_do_read(tun, iocb, m->msg_iov, total_len,
flags & MSG_DONTWAIT);
if (ret > total_len) {
m->msg_flags |= MSG_TRUNC;
ret = flags & MSG_TRUNC ? ret : total_len;
}
return ret;
}
static int tun_flags(struct tun_struct *tun)
{
int flags = 0;
if (tun->flags & TUN_TUN_DEV)
flags |= IFF_TUN;
else
flags |= IFF_TAP;
if (tun->flags & TUN_NO_PI)
flags |= IFF_NO_PI;
if (tun->flags & TUN_ONE_QUEUE)
flags |= IFF_ONE_QUEUE;
if (tun->flags & TUN_VNET_HDR)
flags |= IFF_VNET_HDR;
return flags;
}
static ssize_t tun_show_flags(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct tun_struct *tun = netdev_priv(to_net_dev(dev));
return sprintf(buf, "0x%x\n", tun_flags(tun));
}
static ssize_t tun_show_owner(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct tun_struct *tun = netdev_priv(to_net_dev(dev));
return sprintf(buf, "%d\n", tun->owner);
}
static ssize_t tun_show_group(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct tun_struct *tun = netdev_priv(to_net_dev(dev));
return sprintf(buf, "%d\n", tun->group);
}
static int tun_set_iff(struct net *net, struct file *file, struct ifreq *ifr)
{
struct sock *sk;
struct tun_struct *tun;
struct net_device *dev;
int err;
dev = __dev_get_by_name(net, ifr->ifr_name);
if (dev) {
const struct cred *cred = current_cred();
if (ifr->ifr_flags & IFF_TUN_EXCL)
return -EBUSY;
if ((ifr->ifr_flags & IFF_TUN) && dev->netdev_ops == &tun_netdev_ops)
tun = netdev_priv(dev);
else if ((ifr->ifr_flags & IFF_TAP) && dev->netdev_ops == &tap_netdev_ops)
tun = netdev_priv(dev);
else
return -EINVAL;
if (((tun->owner != -1 && cred->euid != tun->owner) ||
(tun->group != -1 && !in_egroup_p(tun->group))) &&
!capable(CAP_NET_ADMIN))
return -EPERM;
err = security_tun_dev_attach(tun->socket.sk);
if (err < 0)
return err;
err = tun_attach(tun, file);
if (err < 0)
return err;
}
else {
char *name;
unsigned long flags = 0;
if (!capable(CAP_NET_ADMIN))
return -EPERM;
err = security_tun_dev_create();
if (err < 0)
return err;
if (ifr->ifr_flags & IFF_TUN) {
flags |= TUN_TUN_DEV;
name = "tun%d";
} else if (ifr->ifr_flags & IFF_TAP) {
flags |= TUN_TAP_DEV;
name = "tap%d";
} else
return -EINVAL;
if (*ifr->ifr_name)
name = ifr->ifr_name;
dev = alloc_netdev(sizeof(struct tun_struct), name,
tun_setup);
if (!dev)
return -ENOMEM;
dev_net_set(dev, net);
dev->rtnl_link_ops = &tun_link_ops;
tun = netdev_priv(dev);
tun->dev = dev;
tun->flags = flags;
tun->txflt.count = 0;
tun->vnet_hdr_sz = sizeof(struct virtio_net_hdr);
err = -ENOMEM;
sk = sk_alloc(net, AF_UNSPEC, GFP_KERNEL, &tun_proto);
if (!sk)
goto err_free_dev;
tun->socket.wq = &tun->wq;
init_waitqueue_head(&tun->wq.wait);
tun->socket.ops = &tun_socket_ops;
sock_init_data(&tun->socket, sk);
sk->sk_write_space = tun_sock_write_space;
sk->sk_sndbuf = INT_MAX;
tun_sk(sk)->tun = tun;
security_tun_dev_post_create(sk);
tun_net_init(dev);
dev->hw_features = NETIF_F_SG | NETIF_F_FRAGLIST |
TUN_USER_FEATURES;
dev->features = dev->hw_features;
err = register_netdevice(tun->dev);
if (err < 0)
goto err_free_sk;
if (device_create_file(&tun->dev->dev, &dev_attr_tun_flags) ||
device_create_file(&tun->dev->dev, &dev_attr_owner) ||
device_create_file(&tun->dev->dev, &dev_attr_group))
pr_err("Failed to create tun sysfs files\n");
sk->sk_destruct = tun_sock_destruct;
err = tun_attach(tun, file);
if (err < 0)
goto failed;
}
tun_debug(KERN_INFO, tun, "tun_set_iff\n");
if (ifr->ifr_flags & IFF_NO_PI)
tun->flags |= TUN_NO_PI;
else
tun->flags &= ~TUN_NO_PI;
if (ifr->ifr_flags & IFF_ONE_QUEUE)
tun->flags |= TUN_ONE_QUEUE;
else
tun->flags &= ~TUN_ONE_QUEUE;
if (ifr->ifr_flags & IFF_VNET_HDR)
tun->flags |= TUN_VNET_HDR;
else
tun->flags &= ~TUN_VNET_HDR;
if (netif_running(tun->dev))
netif_wake_queue(tun->dev);
strcpy(ifr->ifr_name, tun->dev->name);
return 0;
err_free_sk:
sock_put(sk);
err_free_dev:
free_netdev(dev);
failed:
return err;
}
static int tun_get_iff(struct net *net, struct tun_struct *tun,
struct ifreq *ifr)
{
tun_debug(KERN_INFO, tun, "tun_get_iff\n");
strcpy(ifr->ifr_name, tun->dev->name);
ifr->ifr_flags = tun_flags(tun);
return 0;
}
static int set_offload(struct tun_struct *tun, unsigned long arg)
{
u32 features = 0;
if (arg & TUN_F_CSUM) {
features |= NETIF_F_HW_CSUM;
arg &= ~TUN_F_CSUM;
if (arg & (TUN_F_TSO4|TUN_F_TSO6)) {
if (arg & TUN_F_TSO_ECN) {
features |= NETIF_F_TSO_ECN;
arg &= ~TUN_F_TSO_ECN;
}
if (arg & TUN_F_TSO4)
features |= NETIF_F_TSO;
if (arg & TUN_F_TSO6)
features |= NETIF_F_TSO6;
arg &= ~(TUN_F_TSO4|TUN_F_TSO6);
}
if (arg & TUN_F_UFO) {
features |= NETIF_F_UFO;
arg &= ~TUN_F_UFO;
}
}
if (arg)
return -EINVAL;
tun->set_features = features;
netdev_update_features(tun->dev);
return 0;
}
static long __tun_chr_ioctl(struct file *file, unsigned int cmd,
unsigned long arg, int ifreq_len)
{
struct tun_file *tfile = file->private_data;
struct tun_struct *tun;
void __user* argp = (void __user*)arg;
struct sock_fprog fprog;
struct ifreq ifr;
int sndbuf;
int vnet_hdr_sz;
int ret;
if (cmd == TUNSETIFF || _IOC_TYPE(cmd) == 0x89)
if (copy_from_user(&ifr, argp, ifreq_len))
return -EFAULT;
if (cmd == TUNGETFEATURES) {
return put_user(IFF_TUN | IFF_TAP | IFF_NO_PI | IFF_ONE_QUEUE |
IFF_VNET_HDR,
(unsigned int __user*)argp);
}
rtnl_lock();
tun = __tun_get(tfile);
if (cmd == TUNSETIFF && !tun) {
ifr.ifr_name[IFNAMSIZ-1] = '\0';
ret = tun_set_iff(tfile->net, file, &ifr);
if (ret)
goto unlock;
if (copy_to_user(argp, &ifr, ifreq_len))
ret = -EFAULT;
goto unlock;
}
ret = -EBADFD;
if (!tun)
goto unlock;
tun_debug(KERN_INFO, tun, "tun_chr_ioctl cmd %d\n", cmd);
ret = 0;
switch (cmd) {
case TUNGETIFF:
ret = tun_get_iff(current->nsproxy->net_ns, tun, &ifr);
if (ret)
break;
if (copy_to_user(argp, &ifr, ifreq_len))
ret = -EFAULT;
break;
case TUNSETNOCSUM:
tun_debug(KERN_INFO, tun, "ignored: set checksum %s\n",
arg ? "disabled" : "enabled");
break;
case TUNSETPERSIST:
if (arg)
tun->flags |= TUN_PERSIST;
else
tun->flags &= ~TUN_PERSIST;
tun_debug(KERN_INFO, tun, "persist %s\n",
arg ? "enabled" : "disabled");
break;
case TUNSETOWNER:
tun->owner = (uid_t) arg;
tun_debug(KERN_INFO, tun, "owner set to %d\n", tun->owner);
break;
case TUNSETGROUP:
tun->group= (gid_t) arg;
tun_debug(KERN_INFO, tun, "group set to %d\n", tun->group);
break;
case TUNSETLINK:
if (tun->dev->flags & IFF_UP) {
tun_debug(KERN_INFO, tun,
"Linktype set failed because interface is up\n");
ret = -EBUSY;
} else {
tun->dev->type = (int) arg;
tun_debug(KERN_INFO, tun, "linktype set to %d\n",
tun->dev->type);
ret = 0;
}
break;
#ifdef TUN_DEBUG
case TUNSETDEBUG:
tun->debug = arg;
break;
#endif
case TUNSETOFFLOAD:
ret = set_offload(tun, arg);
break;
case TUNSETTXFILTER:
ret = -EINVAL;
if ((tun->flags & TUN_TYPE_MASK) != TUN_TAP_DEV)
break;
ret = update_filter(&tun->txflt, (void __user *)arg);
break;
case SIOCGIFHWADDR:
memcpy(ifr.ifr_hwaddr.sa_data, tun->dev->dev_addr, ETH_ALEN);
ifr.ifr_hwaddr.sa_family = tun->dev->type;
if (copy_to_user(argp, &ifr, ifreq_len))
ret = -EFAULT;
break;
case SIOCSIFHWADDR:
tun_debug(KERN_DEBUG, tun, "set hw address: %pM\n",
ifr.ifr_hwaddr.sa_data);
ret = dev_set_mac_address(tun->dev, &ifr.ifr_hwaddr);
break;
case TUNGETSNDBUF:
sndbuf = tun->socket.sk->sk_sndbuf;
if (copy_to_user(argp, &sndbuf, sizeof(sndbuf)))
ret = -EFAULT;
break;
case TUNSETSNDBUF:
if (copy_from_user(&sndbuf, argp, sizeof(sndbuf))) {
ret = -EFAULT;
break;
}
tun->socket.sk->sk_sndbuf = sndbuf;
break;
case TUNGETVNETHDRSZ:
vnet_hdr_sz = tun->vnet_hdr_sz;
if (copy_to_user(argp, &vnet_hdr_sz, sizeof(vnet_hdr_sz)))
ret = -EFAULT;
break;
case TUNSETVNETHDRSZ:
if (copy_from_user(&vnet_hdr_sz, argp, sizeof(vnet_hdr_sz))) {
ret = -EFAULT;
break;
}
if (vnet_hdr_sz < (int)sizeof(struct virtio_net_hdr)) {
ret = -EINVAL;
break;
}
tun->vnet_hdr_sz = vnet_hdr_sz;
break;
case TUNATTACHFILTER:
ret = -EINVAL;
if ((tun->flags & TUN_TYPE_MASK) != TUN_TAP_DEV)
break;
ret = -EFAULT;
if (copy_from_user(&fprog, argp, sizeof(fprog)))
break;
ret = sk_attach_filter(&fprog, tun->socket.sk);
break;
case TUNDETACHFILTER:
ret = -EINVAL;
if ((tun->flags & TUN_TYPE_MASK) != TUN_TAP_DEV)
break;
ret = sk_detach_filter(tun->socket.sk);
break;
default:
ret = -EINVAL;
break;
}
unlock:
rtnl_unlock();
if (tun)
tun_put(tun);
return ret;
}
static long tun_chr_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
return __tun_chr_ioctl(file, cmd, arg, sizeof (struct ifreq));
}
static long tun_chr_compat_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case TUNSETIFF:
case TUNGETIFF:
case TUNSETTXFILTER:
case TUNGETSNDBUF:
case TUNSETSNDBUF:
case SIOCGIFHWADDR:
case SIOCSIFHWADDR:
arg = (unsigned long)compat_ptr(arg);
break;
default:
arg = (compat_ulong_t)arg;
break;
}
return __tun_chr_ioctl(file, cmd, arg, sizeof(struct compat_ifreq));
}
static int tun_chr_fasync(int fd, struct file *file, int on)
{
struct tun_struct *tun = tun_get(file);
int ret;
if (!tun)
return -EBADFD;
tun_debug(KERN_INFO, tun, "tun_chr_fasync %d\n", on);
if ((ret = fasync_helper(fd, file, on, &tun->fasync)) < 0)
goto out;
if (on) {
ret = __f_setown(file, task_pid(current), PIDTYPE_PID, 0);
if (ret)
goto out;
tun->flags |= TUN_FASYNC;
} else
tun->flags &= ~TUN_FASYNC;
ret = 0;
out:
tun_put(tun);
return ret;
}
static int tun_chr_open(struct inode *inode, struct file * file)
{
struct tun_file *tfile;
DBG1(KERN_INFO, "tunX: tun_chr_open\n");
tfile = kmalloc(sizeof(*tfile), GFP_KERNEL);
if (!tfile)
return -ENOMEM;
atomic_set(&tfile->count, 0);
tfile->tun = NULL;
tfile->net = get_net(current->nsproxy->net_ns);
file->private_data = tfile;
return 0;
}
static int tun_chr_close(struct inode *inode, struct file *file)
{
struct tun_file *tfile = file->private_data;
struct tun_struct *tun;
tun = __tun_get(tfile);
if (tun) {
struct net_device *dev = tun->dev;
tun_debug(KERN_INFO, tun, "tun_chr_close\n");
__tun_detach(tun);
if (!(tun->flags & TUN_PERSIST)) {
rtnl_lock();
if (dev->reg_state == NETREG_REGISTERED)
unregister_netdevice(dev);
rtnl_unlock();
}
}
tun = tfile->tun;
if (tun)
sock_put(tun->socket.sk);
put_net(tfile->net);
kfree(tfile);
return 0;
}
static int tun_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
cmd->supported = 0;
cmd->advertising = 0;
ethtool_cmd_speed_set(cmd, SPEED_10);
cmd->duplex = DUPLEX_FULL;
cmd->port = PORT_TP;
cmd->phy_address = 0;
cmd->transceiver = XCVR_INTERNAL;
cmd->autoneg = AUTONEG_DISABLE;
cmd->maxtxpkt = 0;
cmd->maxrxpkt = 0;
return 0;
}
static void tun_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct tun_struct *tun = netdev_priv(dev);
strcpy(info->driver, DRV_NAME);
strcpy(info->version, DRV_VERSION);
strcpy(info->fw_version, "N/A");
switch (tun->flags & TUN_TYPE_MASK) {
case TUN_TUN_DEV:
strcpy(info->bus_info, "tun");
break;
case TUN_TAP_DEV:
strcpy(info->bus_info, "tap");
break;
}
}
static u32 tun_get_msglevel(struct net_device *dev)
{
#ifdef TUN_DEBUG
struct tun_struct *tun = netdev_priv(dev);
return tun->debug;
#else
return -EOPNOTSUPP;
#endif
}
static void tun_set_msglevel(struct net_device *dev, u32 value)
{
#ifdef TUN_DEBUG
struct tun_struct *tun = netdev_priv(dev);
tun->debug = value;
#endif
}
static int __init tun_init(void)
{
int ret = 0;
pr_info("%s, %s\n", DRV_DESCRIPTION, DRV_VERSION);
pr_info("%s\n", DRV_COPYRIGHT);
ret = rtnl_link_register(&tun_link_ops);
if (ret) {
pr_err("Can't register link_ops\n");
goto err_linkops;
}
ret = misc_register(&tun_miscdev);
if (ret) {
pr_err("Can't register misc device %d\n", TUN_MINOR);
goto err_misc;
}
return 0;
err_misc:
rtnl_link_unregister(&tun_link_ops);
err_linkops:
return ret;
}
static void tun_cleanup(void)
{
misc_deregister(&tun_miscdev);
rtnl_link_unregister(&tun_link_ops);
}
struct socket *tun_get_socket(struct file *file)
{
struct tun_struct *tun;
if (file->f_op != &tun_fops)
return ERR_PTR(-EINVAL);
tun = tun_get(file);
if (!tun)
return ERR_PTR(-EBADFD);
tun_put(tun);
return &tun->socket;
}
