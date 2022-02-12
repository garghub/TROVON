static int ipip_err(struct sk_buff *skb, u32 info)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn = net_generic(net, ipip_net_id);
const struct iphdr *iph = (const struct iphdr *)skb->data;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct ip_tunnel *t;
int err = 0;
switch (type) {
case ICMP_DEST_UNREACH:
switch (code) {
case ICMP_SR_FAILED:
goto out;
default:
break;
}
break;
case ICMP_TIME_EXCEEDED:
if (code != ICMP_EXC_TTL)
goto out;
break;
case ICMP_REDIRECT:
break;
default:
goto out;
}
t = ip_tunnel_lookup(itn, skb->dev->ifindex, TUNNEL_NO_KEY,
iph->daddr, iph->saddr, 0);
if (!t) {
err = -ENOENT;
goto out;
}
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, net, info, t->parms.link, 0,
iph->protocol, 0);
goto out;
}
if (type == ICMP_REDIRECT) {
ipv4_redirect(skb, net, t->parms.link, 0, iph->protocol, 0);
goto out;
}
if (t->parms.iph.daddr == 0) {
err = -ENOENT;
goto out;
}
if (t->parms.iph.ttl == 0 && type == ICMP_TIME_EXCEEDED)
goto out;
if (time_before(jiffies, t->err_time + IPTUNNEL_ERR_TIMEO))
t->err_count++;
else
t->err_count = 1;
t->err_time = jiffies;
out:
return err;
}
static int ipip_tunnel_rcv(struct sk_buff *skb, u8 ipproto)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn = net_generic(net, ipip_net_id);
struct metadata_dst *tun_dst = NULL;
struct ip_tunnel *tunnel;
const struct iphdr *iph;
iph = ip_hdr(skb);
tunnel = ip_tunnel_lookup(itn, skb->dev->ifindex, TUNNEL_NO_KEY,
iph->saddr, iph->daddr, 0);
if (tunnel) {
const struct tnl_ptk_info *tpi;
if (tunnel->parms.iph.protocol != ipproto &&
tunnel->parms.iph.protocol != 0)
goto drop;
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
goto drop;
#if IS_ENABLED(CONFIG_MPLS)
if (ipproto == IPPROTO_MPLS)
tpi = &mplsip_tpi;
else
#endif
tpi = &ipip_tpi;
if (iptunnel_pull_header(skb, 0, tpi->proto, false))
goto drop;
if (tunnel->collect_md) {
tun_dst = ip_tun_rx_dst(skb, 0, 0, 0);
if (!tun_dst)
return 0;
}
return ip_tunnel_rcv(tunnel, skb, tpi, tun_dst, log_ecn_error);
}
return -1;
drop:
kfree_skb(skb);
return 0;
}
static int ipip_rcv(struct sk_buff *skb)
{
return ipip_tunnel_rcv(skb, IPPROTO_IPIP);
}
static int mplsip_rcv(struct sk_buff *skb)
{
return ipip_tunnel_rcv(skb, IPPROTO_MPLS);
}
static netdev_tx_t ipip_tunnel_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
const struct iphdr *tiph = &tunnel->parms.iph;
u8 ipproto;
switch (skb->protocol) {
case htons(ETH_P_IP):
ipproto = IPPROTO_IPIP;
break;
#if IS_ENABLED(CONFIG_MPLS)
case htons(ETH_P_MPLS_UC):
ipproto = IPPROTO_MPLS;
break;
#endif
default:
goto tx_error;
}
if (tiph->protocol != ipproto && tiph->protocol != 0)
goto tx_error;
if (iptunnel_handle_offloads(skb, SKB_GSO_IPXIP4))
goto tx_error;
skb_set_inner_ipproto(skb, ipproto);
if (tunnel->collect_md)
ip_md_tunnel_xmit(skb, dev, ipproto);
else
ip_tunnel_xmit(skb, dev, tiph, ipproto);
return NETDEV_TX_OK;
tx_error:
kfree_skb(skb);
dev->stats.tx_errors++;
return NETDEV_TX_OK;
}
static bool ipip_tunnel_ioctl_verify_protocol(u8 ipproto)
{
switch (ipproto) {
case 0:
case IPPROTO_IPIP:
#if IS_ENABLED(CONFIG_MPLS)
case IPPROTO_MPLS:
#endif
return true;
}
return false;
}
static int
ipip_tunnel_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
return -EFAULT;
if (cmd == SIOCADDTUNNEL || cmd == SIOCCHGTUNNEL) {
if (p.iph.version != 4 ||
!ipip_tunnel_ioctl_verify_protocol(p.iph.protocol) ||
p.iph.ihl != 5 || (p.iph.frag_off&htons(~IP_DF)))
return -EINVAL;
}
p.i_key = p.o_key = 0;
p.i_flags = p.o_flags = 0;
err = ip_tunnel_ioctl(dev, &p, cmd);
if (err)
return err;
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof(p)))
return -EFAULT;
return 0;
}
static void ipip_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &ipip_netdev_ops;
dev->type = ARPHRD_TUNNEL;
dev->flags = IFF_NOARP;
dev->addr_len = 4;
dev->features |= NETIF_F_LLTX;
netif_keep_dst(dev);
dev->features |= IPIP_FEATURES;
dev->hw_features |= IPIP_FEATURES;
ip_tunnel_setup(dev, ipip_net_id);
}
static int ipip_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
memcpy(dev->dev_addr, &tunnel->parms.iph.saddr, 4);
memcpy(dev->broadcast, &tunnel->parms.iph.daddr, 4);
tunnel->tun_hlen = 0;
tunnel->hlen = tunnel->tun_hlen + tunnel->encap_hlen;
return ip_tunnel_init(dev);
}
static int ipip_tunnel_validate(struct nlattr *tb[], struct nlattr *data[],
struct netlink_ext_ack *extack)
{
u8 proto;
if (!data || !data[IFLA_IPTUN_PROTO])
return 0;
proto = nla_get_u8(data[IFLA_IPTUN_PROTO]);
if (proto != IPPROTO_IPIP && proto != IPPROTO_MPLS && proto != 0)
return -EINVAL;
return 0;
}
static void ipip_netlink_parms(struct nlattr *data[],
struct ip_tunnel_parm *parms, bool *collect_md,
__u32 *fwmark)
{
memset(parms, 0, sizeof(*parms));
parms->iph.version = 4;
parms->iph.protocol = IPPROTO_IPIP;
parms->iph.ihl = 5;
*collect_md = false;
if (!data)
return;
if (data[IFLA_IPTUN_LINK])
parms->link = nla_get_u32(data[IFLA_IPTUN_LINK]);
if (data[IFLA_IPTUN_LOCAL])
parms->iph.saddr = nla_get_in_addr(data[IFLA_IPTUN_LOCAL]);
if (data[IFLA_IPTUN_REMOTE])
parms->iph.daddr = nla_get_in_addr(data[IFLA_IPTUN_REMOTE]);
if (data[IFLA_IPTUN_TTL]) {
parms->iph.ttl = nla_get_u8(data[IFLA_IPTUN_TTL]);
if (parms->iph.ttl)
parms->iph.frag_off = htons(IP_DF);
}
if (data[IFLA_IPTUN_TOS])
parms->iph.tos = nla_get_u8(data[IFLA_IPTUN_TOS]);
if (data[IFLA_IPTUN_PROTO])
parms->iph.protocol = nla_get_u8(data[IFLA_IPTUN_PROTO]);
if (!data[IFLA_IPTUN_PMTUDISC] || nla_get_u8(data[IFLA_IPTUN_PMTUDISC]))
parms->iph.frag_off = htons(IP_DF);
if (data[IFLA_IPTUN_COLLECT_METADATA])
*collect_md = true;
if (data[IFLA_IPTUN_FWMARK])
*fwmark = nla_get_u32(data[IFLA_IPTUN_FWMARK]);
}
static bool ipip_netlink_encap_parms(struct nlattr *data[],
struct ip_tunnel_encap *ipencap)
{
bool ret = false;
memset(ipencap, 0, sizeof(*ipencap));
if (!data)
return ret;
if (data[IFLA_IPTUN_ENCAP_TYPE]) {
ret = true;
ipencap->type = nla_get_u16(data[IFLA_IPTUN_ENCAP_TYPE]);
}
if (data[IFLA_IPTUN_ENCAP_FLAGS]) {
ret = true;
ipencap->flags = nla_get_u16(data[IFLA_IPTUN_ENCAP_FLAGS]);
}
if (data[IFLA_IPTUN_ENCAP_SPORT]) {
ret = true;
ipencap->sport = nla_get_be16(data[IFLA_IPTUN_ENCAP_SPORT]);
}
if (data[IFLA_IPTUN_ENCAP_DPORT]) {
ret = true;
ipencap->dport = nla_get_be16(data[IFLA_IPTUN_ENCAP_DPORT]);
}
return ret;
}
static int ipip_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[],
struct netlink_ext_ack *extack)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm p;
struct ip_tunnel_encap ipencap;
__u32 fwmark = 0;
if (ipip_netlink_encap_parms(data, &ipencap)) {
int err = ip_tunnel_encap_setup(t, &ipencap);
if (err < 0)
return err;
}
ipip_netlink_parms(data, &p, &t->collect_md, &fwmark);
return ip_tunnel_newlink(dev, tb, &p, fwmark);
}
static int ipip_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[],
struct netlink_ext_ack *extack)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm p;
struct ip_tunnel_encap ipencap;
bool collect_md;
__u32 fwmark = t->fwmark;
if (ipip_netlink_encap_parms(data, &ipencap)) {
int err = ip_tunnel_encap_setup(t, &ipencap);
if (err < 0)
return err;
}
ipip_netlink_parms(data, &p, &collect_md, &fwmark);
if (collect_md)
return -EINVAL;
if (((dev->flags & IFF_POINTOPOINT) && !p.iph.daddr) ||
(!(dev->flags & IFF_POINTOPOINT) && p.iph.daddr))
return -EINVAL;
return ip_tunnel_changelink(dev, tb, &p, fwmark);
}
static size_t ipip_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(0) +
nla_total_size(4) +
0;
}
static int ipip_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct ip_tunnel_parm *parm = &tunnel->parms;
if (nla_put_u32(skb, IFLA_IPTUN_LINK, parm->link) ||
nla_put_in_addr(skb, IFLA_IPTUN_LOCAL, parm->iph.saddr) ||
nla_put_in_addr(skb, IFLA_IPTUN_REMOTE, parm->iph.daddr) ||
nla_put_u8(skb, IFLA_IPTUN_TTL, parm->iph.ttl) ||
nla_put_u8(skb, IFLA_IPTUN_TOS, parm->iph.tos) ||
nla_put_u8(skb, IFLA_IPTUN_PROTO, parm->iph.protocol) ||
nla_put_u8(skb, IFLA_IPTUN_PMTUDISC,
!!(parm->iph.frag_off & htons(IP_DF))) ||
nla_put_u32(skb, IFLA_IPTUN_FWMARK, tunnel->fwmark))
goto nla_put_failure;
if (nla_put_u16(skb, IFLA_IPTUN_ENCAP_TYPE,
tunnel->encap.type) ||
nla_put_be16(skb, IFLA_IPTUN_ENCAP_SPORT,
tunnel->encap.sport) ||
nla_put_be16(skb, IFLA_IPTUN_ENCAP_DPORT,
tunnel->encap.dport) ||
nla_put_u16(skb, IFLA_IPTUN_ENCAP_FLAGS,
tunnel->encap.flags))
goto nla_put_failure;
if (tunnel->collect_md)
if (nla_put_flag(skb, IFLA_IPTUN_COLLECT_METADATA))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int __net_init ipip_init_net(struct net *net)
{
return ip_tunnel_init_net(net, ipip_net_id, &ipip_link_ops, "tunl0");
}
static void __net_exit ipip_exit_net(struct net *net)
{
struct ip_tunnel_net *itn = net_generic(net, ipip_net_id);
ip_tunnel_delete_net(itn, &ipip_link_ops);
}
static int __init ipip_init(void)
{
int err;
pr_info("ipip: IPv4 and MPLS over IPv4 tunneling driver\n");
err = register_pernet_device(&ipip_net_ops);
if (err < 0)
return err;
err = xfrm4_tunnel_register(&ipip_handler, AF_INET);
if (err < 0) {
pr_info("%s: can't register tunnel\n", __func__);
goto xfrm_tunnel_ipip_failed;
}
#if IS_ENABLED(CONFIG_MPLS)
err = xfrm4_tunnel_register(&mplsip_handler, AF_MPLS);
if (err < 0) {
pr_info("%s: can't register tunnel\n", __func__);
goto xfrm_tunnel_mplsip_failed;
}
#endif
err = rtnl_link_register(&ipip_link_ops);
if (err < 0)
goto rtnl_link_failed;
out:
return err;
rtnl_link_failed:
#if IS_ENABLED(CONFIG_MPLS)
xfrm4_tunnel_deregister(&mplsip_handler, AF_INET);
xfrm_tunnel_mplsip_failed:
#endif
xfrm4_tunnel_deregister(&ipip_handler, AF_INET);
xfrm_tunnel_ipip_failed:
unregister_pernet_device(&ipip_net_ops);
goto out;
}
static void __exit ipip_fini(void)
{
rtnl_link_unregister(&ipip_link_ops);
if (xfrm4_tunnel_deregister(&ipip_handler, AF_INET))
pr_info("%s: can't deregister tunnel\n", __func__);
#if IS_ENABLED(CONFIG_MPLS)
if (xfrm4_tunnel_deregister(&mplsip_handler, AF_MPLS))
pr_info("%s: can't deregister tunnel\n", __func__);
#endif
unregister_pernet_device(&ipip_net_ops);
}
