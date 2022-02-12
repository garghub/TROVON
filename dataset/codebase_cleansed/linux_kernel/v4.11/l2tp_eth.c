static inline struct l2tp_eth_net *l2tp_eth_pernet(struct net *net)
{
return net_generic(net, l2tp_eth_net_id);
}
static int l2tp_eth_dev_init(struct net_device *dev)
{
struct l2tp_eth *priv = netdev_priv(dev);
priv->dev = dev;
eth_hw_addr_random(dev);
eth_broadcast_addr(dev->broadcast);
netdev_lockdep_set_classes(dev);
return 0;
}
static void l2tp_eth_dev_uninit(struct net_device *dev)
{
struct l2tp_eth *priv = netdev_priv(dev);
struct l2tp_eth_net *pn = l2tp_eth_pernet(dev_net(dev));
spin_lock(&pn->l2tp_eth_lock);
list_del_init(&priv->list);
spin_unlock(&pn->l2tp_eth_lock);
dev_put(dev);
}
static int l2tp_eth_dev_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct l2tp_eth *priv = netdev_priv(dev);
struct l2tp_session *session = priv->session;
unsigned int len = skb->len;
int ret = l2tp_xmit_skb(session, skb, session->hdr_len);
if (likely(ret == NET_XMIT_SUCCESS)) {
atomic_long_add(len, &priv->tx_bytes);
atomic_long_inc(&priv->tx_packets);
} else {
atomic_long_inc(&priv->tx_dropped);
}
return NETDEV_TX_OK;
}
static void l2tp_eth_get_stats64(struct net_device *dev,
struct rtnl_link_stats64 *stats)
{
struct l2tp_eth *priv = netdev_priv(dev);
stats->tx_bytes = atomic_long_read(&priv->tx_bytes);
stats->tx_packets = atomic_long_read(&priv->tx_packets);
stats->tx_dropped = atomic_long_read(&priv->tx_dropped);
stats->rx_bytes = atomic_long_read(&priv->rx_bytes);
stats->rx_packets = atomic_long_read(&priv->rx_packets);
stats->rx_errors = atomic_long_read(&priv->rx_errors);
}
static void l2tp_eth_dev_setup(struct net_device *dev)
{
ether_setup(dev);
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
dev->features |= NETIF_F_LLTX;
dev->netdev_ops = &l2tp_eth_netdev_ops;
dev->destructor = free_netdev;
}
static void l2tp_eth_dev_recv(struct l2tp_session *session, struct sk_buff *skb, int data_len)
{
struct l2tp_eth_sess *spriv = l2tp_session_priv(session);
struct net_device *dev = spriv->dev;
struct l2tp_eth *priv = netdev_priv(dev);
if (session->debug & L2TP_MSG_DATA) {
unsigned int length;
length = min(32u, skb->len);
if (!pskb_may_pull(skb, length))
goto error;
pr_debug("%s: eth recv\n", session->name);
print_hex_dump_bytes("", DUMP_PREFIX_OFFSET, skb->data, length);
}
if (!pskb_may_pull(skb, ETH_HLEN))
goto error;
secpath_reset(skb);
skb->ip_summed = CHECKSUM_NONE;
skb_dst_drop(skb);
nf_reset(skb);
if (dev_forward_skb(dev, skb) == NET_RX_SUCCESS) {
atomic_long_inc(&priv->rx_packets);
atomic_long_add(data_len, &priv->rx_bytes);
} else {
atomic_long_inc(&priv->rx_errors);
}
return;
error:
atomic_long_inc(&priv->rx_errors);
kfree_skb(skb);
}
static void l2tp_eth_delete(struct l2tp_session *session)
{
struct l2tp_eth_sess *spriv;
struct net_device *dev;
if (session) {
spriv = l2tp_session_priv(session);
dev = spriv->dev;
if (dev) {
unregister_netdev(dev);
spriv->dev = NULL;
module_put(THIS_MODULE);
}
}
}
static void l2tp_eth_show(struct seq_file *m, void *arg)
{
struct l2tp_session *session = arg;
struct l2tp_eth_sess *spriv = l2tp_session_priv(session);
struct net_device *dev = spriv->dev;
seq_printf(m, " interface %s\n", dev->name);
}
static int l2tp_eth_create(struct net *net, u32 tunnel_id, u32 session_id, u32 peer_session_id, struct l2tp_session_cfg *cfg)
{
struct net_device *dev;
char name[IFNAMSIZ];
struct l2tp_tunnel *tunnel;
struct l2tp_session *session;
struct l2tp_eth *priv;
struct l2tp_eth_sess *spriv;
int rc;
struct l2tp_eth_net *pn;
tunnel = l2tp_tunnel_find(net, tunnel_id);
if (!tunnel) {
rc = -ENODEV;
goto out;
}
if (cfg->ifname) {
dev = dev_get_by_name(net, cfg->ifname);
if (dev) {
dev_put(dev);
rc = -EEXIST;
goto out;
}
strlcpy(name, cfg->ifname, IFNAMSIZ);
} else
strcpy(name, L2TP_ETH_DEV_NAME);
session = l2tp_session_create(sizeof(*spriv), tunnel, session_id,
peer_session_id, cfg);
if (IS_ERR(session)) {
rc = PTR_ERR(session);
goto out;
}
dev = alloc_netdev(sizeof(*priv), name, NET_NAME_UNKNOWN,
l2tp_eth_dev_setup);
if (!dev) {
rc = -ENOMEM;
goto out_del_session;
}
dev_net_set(dev, net);
if (session->mtu == 0)
session->mtu = dev->mtu - session->hdr_len;
dev->mtu = session->mtu;
dev->needed_headroom += session->hdr_len;
dev->min_mtu = 0;
dev->max_mtu = ETH_MAX_MTU;
priv = netdev_priv(dev);
priv->dev = dev;
priv->session = session;
INIT_LIST_HEAD(&priv->list);
priv->tunnel_sock = tunnel->sock;
session->recv_skb = l2tp_eth_dev_recv;
session->session_close = l2tp_eth_delete;
#if IS_ENABLED(CONFIG_L2TP_DEBUGFS)
session->show = l2tp_eth_show;
#endif
spriv = l2tp_session_priv(session);
spriv->dev = dev;
rc = register_netdev(dev);
if (rc < 0)
goto out_del_dev;
__module_get(THIS_MODULE);
strlcpy(session->ifname, dev->name, IFNAMSIZ);
dev_hold(dev);
pn = l2tp_eth_pernet(dev_net(dev));
spin_lock(&pn->l2tp_eth_lock);
list_add(&priv->list, &pn->l2tp_eth_dev_list);
spin_unlock(&pn->l2tp_eth_lock);
return 0;
out_del_dev:
free_netdev(dev);
spriv->dev = NULL;
out_del_session:
l2tp_session_delete(session);
out:
return rc;
}
static __net_init int l2tp_eth_init_net(struct net *net)
{
struct l2tp_eth_net *pn = net_generic(net, l2tp_eth_net_id);
INIT_LIST_HEAD(&pn->l2tp_eth_dev_list);
spin_lock_init(&pn->l2tp_eth_lock);
return 0;
}
static int __init l2tp_eth_init(void)
{
int err = 0;
err = l2tp_nl_register_ops(L2TP_PWTYPE_ETH, &l2tp_eth_nl_cmd_ops);
if (err)
goto out;
err = register_pernet_device(&l2tp_eth_net_ops);
if (err)
goto out_unreg;
pr_info("L2TP ethernet pseudowire support (L2TPv3)\n");
return 0;
out_unreg:
l2tp_nl_unregister_ops(L2TP_PWTYPE_ETH);
out:
return err;
}
static void __exit l2tp_eth_exit(void)
{
unregister_pernet_device(&l2tp_eth_net_ops);
l2tp_nl_unregister_ops(L2TP_PWTYPE_ETH);
}
