struct net_device *ieee802154_get_dev(struct net *net,
struct ieee802154_addr *addr)
{
struct net_device *dev = NULL;
struct net_device *tmp;
u16 pan_id, short_addr;
switch (addr->addr_type) {
case IEEE802154_ADDR_LONG:
rcu_read_lock();
dev = dev_getbyhwaddr_rcu(net, ARPHRD_IEEE802154, addr->hwaddr);
if (dev)
dev_hold(dev);
rcu_read_unlock();
break;
case IEEE802154_ADDR_SHORT:
if (addr->pan_id == 0xffff ||
addr->short_addr == IEEE802154_ADDR_UNDEF ||
addr->short_addr == 0xffff)
break;
rtnl_lock();
for_each_netdev(net, tmp) {
if (tmp->type != ARPHRD_IEEE802154)
continue;
pan_id = ieee802154_mlme_ops(tmp)->get_pan_id(tmp);
short_addr =
ieee802154_mlme_ops(tmp)->get_short_addr(tmp);
if (pan_id == addr->pan_id &&
short_addr == addr->short_addr) {
dev = tmp;
dev_hold(dev);
break;
}
}
rtnl_unlock();
break;
default:
pr_warning("Unsupported ieee802154 address type: %d\n",
addr->addr_type);
break;
}
return dev;
}
static int ieee802154_sock_release(struct socket *sock)
{
struct sock *sk = sock->sk;
if (sk) {
sock->sk = NULL;
sk->sk_prot->close(sk, 0);
}
return 0;
}
static int ieee802154_sock_sendmsg(struct kiocb *iocb, struct socket *sock,
struct msghdr *msg, size_t len)
{
struct sock *sk = sock->sk;
return sk->sk_prot->sendmsg(iocb, sk, msg, len);
}
static int ieee802154_sock_bind(struct socket *sock, struct sockaddr *uaddr,
int addr_len)
{
struct sock *sk = sock->sk;
if (sk->sk_prot->bind)
return sk->sk_prot->bind(sk, uaddr, addr_len);
return sock_no_bind(sock, uaddr, addr_len);
}
static int ieee802154_sock_connect(struct socket *sock, struct sockaddr *uaddr,
int addr_len, int flags)
{
struct sock *sk = sock->sk;
if (addr_len < sizeof(uaddr->sa_family))
return -EINVAL;
if (uaddr->sa_family == AF_UNSPEC)
return sk->sk_prot->disconnect(sk, flags);
return sk->sk_prot->connect(sk, uaddr, addr_len);
}
static int ieee802154_dev_ioctl(struct sock *sk, struct ifreq __user *arg,
unsigned int cmd)
{
struct ifreq ifr;
int ret = -ENOIOCTLCMD;
struct net_device *dev;
if (copy_from_user(&ifr, arg, sizeof(struct ifreq)))
return -EFAULT;
ifr.ifr_name[IFNAMSIZ-1] = 0;
dev_load(sock_net(sk), ifr.ifr_name);
dev = dev_get_by_name(sock_net(sk), ifr.ifr_name);
if (!dev)
return -ENODEV;
if (dev->type == ARPHRD_IEEE802154 && dev->netdev_ops->ndo_do_ioctl)
ret = dev->netdev_ops->ndo_do_ioctl(dev, &ifr, cmd);
if (!ret && copy_to_user(arg, &ifr, sizeof(struct ifreq)))
ret = -EFAULT;
dev_put(dev);
return ret;
}
static int ieee802154_sock_ioctl(struct socket *sock, unsigned int cmd,
unsigned long arg)
{
struct sock *sk = sock->sk;
switch (cmd) {
case SIOCGSTAMP:
return sock_get_timestamp(sk, (struct timeval __user *)arg);
case SIOCGSTAMPNS:
return sock_get_timestampns(sk, (struct timespec __user *)arg);
case SIOCGIFADDR:
case SIOCSIFADDR:
return ieee802154_dev_ioctl(sk, (struct ifreq __user *)arg,
cmd);
default:
if (!sk->sk_prot->ioctl)
return -ENOIOCTLCMD;
return sk->sk_prot->ioctl(sk, cmd, arg);
}
}
static int ieee802154_create(struct net *net, struct socket *sock,
int protocol, int kern)
{
struct sock *sk;
int rc;
struct proto *proto;
const struct proto_ops *ops;
if (!net_eq(net, &init_net))
return -EAFNOSUPPORT;
switch (sock->type) {
case SOCK_RAW:
proto = &ieee802154_raw_prot;
ops = &ieee802154_raw_ops;
break;
case SOCK_DGRAM:
proto = &ieee802154_dgram_prot;
ops = &ieee802154_dgram_ops;
break;
default:
rc = -ESOCKTNOSUPPORT;
goto out;
}
rc = -ENOMEM;
sk = sk_alloc(net, PF_IEEE802154, GFP_KERNEL, proto);
if (!sk)
goto out;
rc = 0;
sock->ops = ops;
sock_init_data(sock, sk);
sk->sk_family = PF_IEEE802154;
sock_set_flag(sk, SOCK_ZAPPED);
if (sk->sk_prot->hash)
sk->sk_prot->hash(sk);
if (sk->sk_prot->init) {
rc = sk->sk_prot->init(sk);
if (rc)
sk_common_release(sk);
}
out:
return rc;
}
static int ieee802154_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
if (!netif_running(dev))
return -ENODEV;
pr_debug("got frame, type %d, dev %p\n", dev->type, dev);
#ifdef DEBUG
print_hex_dump_bytes("ieee802154_rcv ", DUMP_PREFIX_NONE, skb->data, skb->len);
#endif
if (!net_eq(dev_net(dev), &init_net))
goto drop;
ieee802154_raw_deliver(dev, skb);
if (dev->type != ARPHRD_IEEE802154)
goto drop;
if (skb->pkt_type != PACKET_OTHERHOST)
return ieee802154_dgram_deliver(dev, skb);
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
static int __init af_ieee802154_init(void)
{
int rc = -EINVAL;
rc = proto_register(&ieee802154_raw_prot, 1);
if (rc)
goto out;
rc = proto_register(&ieee802154_dgram_prot, 1);
if (rc)
goto err_dgram;
rc = sock_register(&ieee802154_family_ops);
if (rc)
goto err_sock;
dev_add_pack(&ieee802154_packet_type);
rc = 0;
goto out;
err_sock:
proto_unregister(&ieee802154_dgram_prot);
err_dgram:
proto_unregister(&ieee802154_raw_prot);
out:
return rc;
}
static void __exit af_ieee802154_remove(void)
{
dev_remove_pack(&ieee802154_packet_type);
sock_unregister(PF_IEEE802154);
proto_unregister(&ieee802154_dgram_prot);
proto_unregister(&ieee802154_raw_prot);
}
