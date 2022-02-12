static int ipip_err(struct sk_buff *skb, u32 info)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn = net_generic(net, ipip_net_id);
const struct iphdr *iph = (const struct iphdr *)skb->data;
struct ip_tunnel *t;
int err;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
err = -ENOENT;
t = ip_tunnel_lookup(itn, skb->dev->ifindex, TUNNEL_NO_KEY,
iph->daddr, iph->saddr, 0);
if (!t)
goto out;
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, dev_net(skb->dev), info,
t->parms.link, 0, IPPROTO_IPIP, 0);
err = 0;
goto out;
}
if (type == ICMP_REDIRECT) {
ipv4_redirect(skb, dev_net(skb->dev), t->parms.link, 0,
IPPROTO_IPIP, 0);
err = 0;
goto out;
}
if (t->parms.iph.daddr == 0)
goto out;
err = 0;
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
static int ipip_rcv(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn = net_generic(net, ipip_net_id);
struct ip_tunnel *tunnel;
const struct iphdr *iph;
iph = ip_hdr(skb);
tunnel = ip_tunnel_lookup(itn, skb->dev->ifindex, TUNNEL_NO_KEY,
iph->saddr, iph->daddr, 0);
if (tunnel) {
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
goto drop;
if (iptunnel_pull_header(skb, 0, tpi.proto))
goto drop;
return ip_tunnel_rcv(tunnel, skb, &tpi, NULL, log_ecn_error);
}
return -1;
drop:
kfree_skb(skb);
return 0;
}
static netdev_tx_t ipip_tunnel_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
const struct iphdr *tiph = &tunnel->parms.iph;
if (unlikely(skb->protocol != htons(ETH_P_IP)))
goto tx_error;
skb = iptunnel_handle_offloads(skb, false, SKB_GSO_IPIP);
if (IS_ERR(skb))
goto out;
skb_set_inner_ipproto(skb, IPPROTO_IPIP);
ip_tunnel_xmit(skb, dev, tiph, tiph->protocol);
return NETDEV_TX_OK;
tx_error:
kfree_skb(skb);
out:
dev->stats.tx_errors++;
return NETDEV_TX_OK;
}
static int
ipip_tunnel_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
return -EFAULT;
if (cmd == SIOCADDTUNNEL || cmd == SIOCCHGTUNNEL) {
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_IPIP ||
p.iph.ihl != 5 || (p.iph.frag_off&htons(~IP_DF)))
return -EINVAL;
}
p.i_key = p.o_key = 0;
p.i_flags = p.o_flags = 0;
if (p.iph.ttl)
p.iph.frag_off |= htons(IP_DF);
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
tunnel->parms.iph.protocol = IPPROTO_IPIP;
return ip_tunnel_init(dev);
}
static void ipip_netlink_parms(struct nlattr *data[],
struct ip_tunnel_parm *parms)
{
memset(parms, 0, sizeof(*parms));
parms->iph.version = 4;
parms->iph.protocol = IPPROTO_IPIP;
parms->iph.ihl = 5;
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
if (!data[IFLA_IPTUN_PMTUDISC] || nla_get_u8(data[IFLA_IPTUN_PMTUDISC]))
parms->iph.frag_off = htons(IP_DF);
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
struct nlattr *tb[], struct nlattr *data[])
{
struct ip_tunnel_parm p;
struct ip_tunnel_encap ipencap;
if (ipip_netlink_encap_parms(data, &ipencap)) {
struct ip_tunnel *t = netdev_priv(dev);
int err = ip_tunnel_encap_setup(t, &ipencap);
if (err < 0)
return err;
}
ipip_netlink_parms(data, &p);
return ip_tunnel_newlink(dev, tb, &p);
}
static int ipip_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel_parm p;
struct ip_tunnel_encap ipencap;
if (ipip_netlink_encap_parms(data, &ipencap)) {
struct ip_tunnel *t = netdev_priv(dev);
int err = ip_tunnel_encap_setup(t, &ipencap);
if (err < 0)
return err;
}
ipip_netlink_parms(data, &p);
if (((dev->flags & IFF_POINTOPOINT) && !p.iph.daddr) ||
(!(dev->flags & IFF_POINTOPOINT) && p.iph.daddr))
return -EINVAL;
return ip_tunnel_changelink(dev, tb, &p);
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
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2) +
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
nla_put_u8(skb, IFLA_IPTUN_PMTUDISC,
!!(parm->iph.frag_off & htons(IP_DF))))
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
pr_info("ipip: IPv4 over IPv4 tunneling driver\n");
err = register_pernet_device(&ipip_net_ops);
if (err < 0)
return err;
err = xfrm4_tunnel_register(&ipip_handler, AF_INET);
if (err < 0) {
pr_info("%s: can't register tunnel\n", __func__);
goto xfrm_tunnel_failed;
}
err = rtnl_link_register(&ipip_link_ops);
if (err < 0)
goto rtnl_link_failed;
out:
return err;
rtnl_link_failed:
xfrm4_tunnel_deregister(&ipip_handler, AF_INET);
xfrm_tunnel_failed:
unregister_pernet_device(&ipip_net_ops);
goto out;
}
static void __exit ipip_fini(void)
{
rtnl_link_unregister(&ipip_link_ops);
if (xfrm4_tunnel_deregister(&ipip_handler, AF_INET))
pr_info("%s: can't deregister tunnel\n", __func__);
unregister_pernet_device(&ipip_net_ops);
}
