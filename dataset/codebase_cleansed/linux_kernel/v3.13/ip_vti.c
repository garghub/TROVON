static int vti_rcv(struct sk_buff *skb)
{
struct ip_tunnel *tunnel;
const struct iphdr *iph = ip_hdr(skb);
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn = net_generic(net, vti_net_id);
tunnel = ip_tunnel_lookup(itn, skb->dev->ifindex, TUNNEL_NO_KEY,
iph->saddr, iph->daddr, 0);
if (tunnel != NULL) {
struct pcpu_tstats *tstats;
u32 oldmark = skb->mark;
int ret;
skb->mark = be32_to_cpu(tunnel->parms.o_key);
ret = xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb);
skb->mark = oldmark;
if (!ret)
return -1;
tstats = this_cpu_ptr(tunnel->dev->tstats);
u64_stats_update_begin(&tstats->syncp);
tstats->rx_packets++;
tstats->rx_bytes += skb->len;
u64_stats_update_end(&tstats->syncp);
secpath_reset(skb);
skb->dev = tunnel->dev;
return 1;
}
return -1;
}
static netdev_tx_t vti_tunnel_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *tiph = &tunnel->parms.iph;
u8 tos;
struct rtable *rt;
struct net_device *tdev;
struct iphdr *old_iph = ip_hdr(skb);
__be32 dst = tiph->daddr;
struct flowi4 fl4;
int err;
if (skb->protocol != htons(ETH_P_IP))
goto tx_error;
tos = old_iph->tos;
memset(&fl4, 0, sizeof(fl4));
flowi4_init_output(&fl4, tunnel->parms.link,
be32_to_cpu(tunnel->parms.o_key), RT_TOS(tos),
RT_SCOPE_UNIVERSE,
IPPROTO_IPIP, 0,
dst, tiph->saddr, 0, 0);
rt = ip_route_output_key(dev_net(dev), &fl4);
if (IS_ERR(rt)) {
dev->stats.tx_carrier_errors++;
goto tx_error_icmp;
}
if (!rt->dst.xfrm ||
rt->dst.xfrm->props.mode != XFRM_MODE_TUNNEL) {
dev->stats.tx_carrier_errors++;
ip_rt_put(rt);
goto tx_error_icmp;
}
tdev = rt->dst.dev;
if (tdev == dev) {
ip_rt_put(rt);
dev->stats.collisions++;
goto tx_error;
}
if (tunnel->err_count > 0) {
if (time_before(jiffies,
tunnel->err_time + IPTUNNEL_ERR_TIMEO)) {
tunnel->err_count--;
dst_link_failure(skb);
} else
tunnel->err_count = 0;
}
memset(IPCB(skb), 0, sizeof(*IPCB(skb)));
skb_dst_drop(skb);
skb_dst_set(skb, &rt->dst);
nf_reset(skb);
skb->dev = skb_dst(skb)->dev;
err = dst_output(skb);
if (net_xmit_eval(err) == 0)
err = skb->len;
iptunnel_xmit_stats(err, &dev->stats, dev->tstats);
return NETDEV_TX_OK;
tx_error_icmp:
dst_link_failure(skb);
tx_error:
dev->stats.tx_errors++;
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int
vti_tunnel_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
return -EFAULT;
if (cmd == SIOCADDTUNNEL || cmd == SIOCCHGTUNNEL) {
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_IPIP ||
p.iph.ihl != 5)
return -EINVAL;
}
err = ip_tunnel_ioctl(dev, &p, cmd);
if (err)
return err;
if (cmd != SIOCDELTUNNEL) {
p.i_flags |= GRE_KEY | VTI_ISVTI;
p.o_flags |= GRE_KEY;
}
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof(p)))
return -EFAULT;
return 0;
}
static void vti_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &vti_netdev_ops;
ip_tunnel_setup(dev, vti_net_id);
}
static int vti_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *iph = &tunnel->parms.iph;
memcpy(dev->dev_addr, &iph->saddr, 4);
memcpy(dev->broadcast, &iph->daddr, 4);
dev->type = ARPHRD_TUNNEL;
dev->hard_header_len = LL_MAX_HEADER + sizeof(struct iphdr);
dev->mtu = ETH_DATA_LEN;
dev->flags = IFF_NOARP;
dev->iflink = 0;
dev->addr_len = 4;
dev->features |= NETIF_F_NETNS_LOCAL;
dev->features |= NETIF_F_LLTX;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
return ip_tunnel_init(dev);
}
static void __net_init vti_fb_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *iph = &tunnel->parms.iph;
iph->version = 4;
iph->protocol = IPPROTO_IPIP;
iph->ihl = 5;
}
static int __net_init vti_init_net(struct net *net)
{
int err;
struct ip_tunnel_net *itn;
err = ip_tunnel_init_net(net, vti_net_id, &vti_link_ops, "ip_vti0");
if (err)
return err;
itn = net_generic(net, vti_net_id);
vti_fb_tunnel_init(itn->fb_tunnel_dev);
return 0;
}
static void __net_exit vti_exit_net(struct net *net)
{
struct ip_tunnel_net *itn = net_generic(net, vti_net_id);
ip_tunnel_delete_net(itn, &vti_link_ops);
}
static int vti_tunnel_validate(struct nlattr *tb[], struct nlattr *data[])
{
return 0;
}
static void vti_netlink_parms(struct nlattr *data[],
struct ip_tunnel_parm *parms)
{
memset(parms, 0, sizeof(*parms));
parms->iph.protocol = IPPROTO_IPIP;
if (!data)
return;
if (data[IFLA_VTI_LINK])
parms->link = nla_get_u32(data[IFLA_VTI_LINK]);
if (data[IFLA_VTI_IKEY])
parms->i_key = nla_get_be32(data[IFLA_VTI_IKEY]);
if (data[IFLA_VTI_OKEY])
parms->o_key = nla_get_be32(data[IFLA_VTI_OKEY]);
if (data[IFLA_VTI_LOCAL])
parms->iph.saddr = nla_get_be32(data[IFLA_VTI_LOCAL]);
if (data[IFLA_VTI_REMOTE])
parms->iph.daddr = nla_get_be32(data[IFLA_VTI_REMOTE]);
}
static int vti_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct ip_tunnel_parm parms;
vti_netlink_parms(data, &parms);
return ip_tunnel_newlink(dev, tb, &parms);
}
static int vti_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel_parm p;
vti_netlink_parms(data, &p);
return ip_tunnel_changelink(dev, tb, &p);
}
static size_t vti_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
0;
}
static int vti_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm *p = &t->parms;
nla_put_u32(skb, IFLA_VTI_LINK, p->link);
nla_put_be32(skb, IFLA_VTI_IKEY, p->i_key);
nla_put_be32(skb, IFLA_VTI_OKEY, p->o_key);
nla_put_be32(skb, IFLA_VTI_LOCAL, p->iph.saddr);
nla_put_be32(skb, IFLA_VTI_REMOTE, p->iph.daddr);
return 0;
}
static int __init vti_init(void)
{
int err;
pr_info("IPv4 over IPSec tunneling driver\n");
err = register_pernet_device(&vti_net_ops);
if (err < 0)
return err;
err = xfrm4_mode_tunnel_input_register(&vti_handler);
if (err < 0) {
unregister_pernet_device(&vti_net_ops);
pr_info("vti init: can't register tunnel\n");
}
err = rtnl_link_register(&vti_link_ops);
if (err < 0)
goto rtnl_link_failed;
return err;
rtnl_link_failed:
xfrm4_mode_tunnel_input_deregister(&vti_handler);
unregister_pernet_device(&vti_net_ops);
return err;
}
static void __exit vti_fini(void)
{
rtnl_link_unregister(&vti_link_ops);
if (xfrm4_mode_tunnel_input_deregister(&vti_handler))
pr_info("vti close: can't deregister tunnel\n");
unregister_pernet_device(&vti_net_ops);
}
