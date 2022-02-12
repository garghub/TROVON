static __sum16 check_checksum(struct sk_buff *skb)
{
__sum16 csum = 0;
switch (skb->ip_summed) {
case CHECKSUM_COMPLETE:
csum = csum_fold(skb->csum);
if (!csum)
break;
case CHECKSUM_NONE:
skb->csum = 0;
csum = __skb_checksum_complete(skb);
skb->ip_summed = CHECKSUM_COMPLETE;
break;
}
return csum;
}
static int ip_gre_calc_hlen(__be16 o_flags)
{
int addend = 4;
if (o_flags&TUNNEL_CSUM)
addend += 4;
if (o_flags&TUNNEL_KEY)
addend += 4;
if (o_flags&TUNNEL_SEQ)
addend += 4;
return addend;
}
static int parse_gre_header(struct sk_buff *skb, struct tnl_ptk_info *tpi,
bool *csum_err, int *hdr_len)
{
unsigned int ip_hlen = ip_hdrlen(skb);
const struct gre_base_hdr *greh;
__be32 *options;
if (unlikely(!pskb_may_pull(skb, sizeof(struct gre_base_hdr))))
return -EINVAL;
greh = (struct gre_base_hdr *)(skb_network_header(skb) + ip_hlen);
if (unlikely(greh->flags & (GRE_VERSION | GRE_ROUTING)))
return -EINVAL;
tpi->flags = gre_flags_to_tnl_flags(greh->flags);
*hdr_len = ip_gre_calc_hlen(tpi->flags);
if (!pskb_may_pull(skb, *hdr_len))
return -EINVAL;
greh = (struct gre_base_hdr *)(skb_network_header(skb) + ip_hlen);
tpi->proto = greh->protocol;
options = (__be32 *)(greh + 1);
if (greh->flags & GRE_CSUM) {
if (check_checksum(skb)) {
*csum_err = true;
return -EINVAL;
}
options++;
}
if (greh->flags & GRE_KEY) {
tpi->key = *options;
options++;
} else
tpi->key = 0;
if (unlikely(greh->flags & GRE_SEQ)) {
tpi->seq = *options;
options++;
} else
tpi->seq = 0;
if (greh->flags == 0 && tpi->proto == htons(ETH_P_WCCP)) {
tpi->proto = htons(ETH_P_IP);
if ((*(u8 *)options & 0xF0) != 0x40) {
*hdr_len += 4;
if (!pskb_may_pull(skb, *hdr_len))
return -EINVAL;
}
}
return 0;
}
static void ipgre_err(struct sk_buff *skb, u32 info)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn;
const struct iphdr *iph;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct ip_tunnel *t;
struct tnl_ptk_info tpi;
int hdr_len;
bool csum_err = false;
if (parse_gre_header(skb, &tpi, &csum_err, &hdr_len)) {
if (!csum_err)
return;
}
switch (type) {
default:
case ICMP_PARAMETERPROB:
return;
case ICMP_DEST_UNREACH:
switch (code) {
case ICMP_SR_FAILED:
case ICMP_PORT_UNREACH:
return;
default:
break;
}
break;
case ICMP_TIME_EXCEEDED:
if (code != ICMP_EXC_TTL)
return;
break;
case ICMP_REDIRECT:
break;
}
if (tpi.proto == htons(ETH_P_TEB))
itn = net_generic(net, gre_tap_net_id);
else
itn = net_generic(net, ipgre_net_id);
iph = (const struct iphdr *)skb->data;
t = ip_tunnel_lookup(itn, skb->dev->ifindex, tpi.flags,
iph->daddr, iph->saddr, tpi.key);
if (t == NULL)
return;
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, dev_net(skb->dev), info,
t->parms.link, 0, IPPROTO_GRE, 0);
return;
}
if (type == ICMP_REDIRECT) {
ipv4_redirect(skb, dev_net(skb->dev), t->parms.link, 0,
IPPROTO_GRE, 0);
return;
}
if (t->parms.iph.daddr == 0 ||
ipv4_is_multicast(t->parms.iph.daddr))
return;
if (t->parms.iph.ttl == 0 && type == ICMP_TIME_EXCEEDED)
return;
if (time_before(jiffies, t->err_time + IPTUNNEL_ERR_TIMEO))
t->err_count++;
else
t->err_count = 1;
t->err_time = jiffies;
}
static int ipgre_rcv(struct sk_buff *skb)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn;
const struct iphdr *iph;
struct ip_tunnel *tunnel;
struct tnl_ptk_info tpi;
int hdr_len;
bool csum_err = false;
if (parse_gre_header(skb, &tpi, &csum_err, &hdr_len) < 0)
goto drop;
if (tpi.proto == htons(ETH_P_TEB))
itn = net_generic(net, gre_tap_net_id);
else
itn = net_generic(net, ipgre_net_id);
iph = ip_hdr(skb);
tunnel = ip_tunnel_lookup(itn, skb->dev->ifindex, tpi.flags,
iph->saddr, iph->daddr, tpi.key);
if (tunnel) {
ip_tunnel_rcv(tunnel, skb, &tpi, log_ecn_error);
return 0;
}
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static struct sk_buff *handle_offloads(struct ip_tunnel *tunnel, struct sk_buff *skb)
{
int err;
if (skb_is_gso(skb)) {
err = skb_unclone(skb, GFP_ATOMIC);
if (unlikely(err))
goto error;
skb_shinfo(skb)->gso_type |= SKB_GSO_GRE;
return skb;
} else if (skb->ip_summed == CHECKSUM_PARTIAL &&
tunnel->parms.o_flags&TUNNEL_CSUM) {
err = skb_checksum_help(skb);
if (unlikely(err))
goto error;
} else if (skb->ip_summed != CHECKSUM_PARTIAL)
skb->ip_summed = CHECKSUM_NONE;
return skb;
error:
kfree_skb(skb);
return ERR_PTR(err);
}
static struct sk_buff *gre_build_header(struct sk_buff *skb,
const struct tnl_ptk_info *tpi,
int hdr_len)
{
struct gre_base_hdr *greh;
skb_push(skb, hdr_len);
greh = (struct gre_base_hdr *)skb->data;
greh->flags = tnl_flags_to_gre_flags(tpi->flags);
greh->protocol = tpi->proto;
if (tpi->flags&(TUNNEL_KEY|TUNNEL_CSUM|TUNNEL_SEQ)) {
__be32 *ptr = (__be32 *)(((u8 *)greh) + hdr_len - 4);
if (tpi->flags&TUNNEL_SEQ) {
*ptr = tpi->seq;
ptr--;
}
if (tpi->flags&TUNNEL_KEY) {
*ptr = tpi->key;
ptr--;
}
if (tpi->flags&TUNNEL_CSUM &&
!(skb_shinfo(skb)->gso_type & SKB_GSO_GRE)) {
*(__sum16 *)ptr = 0;
*(__sum16 *)ptr = csum_fold(skb_checksum(skb, 0,
skb->len, 0));
}
}
return skb;
}
static void __gre_xmit(struct sk_buff *skb, struct net_device *dev,
const struct iphdr *tnl_params,
__be16 proto)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct tnl_ptk_info tpi;
if (likely(!skb->encapsulation)) {
skb_reset_inner_headers(skb);
skb->encapsulation = 1;
}
tpi.flags = tunnel->parms.o_flags;
tpi.proto = proto;
tpi.key = tunnel->parms.o_key;
if (tunnel->parms.o_flags & TUNNEL_SEQ)
tunnel->o_seqno++;
tpi.seq = htonl(tunnel->o_seqno);
skb = gre_build_header(skb, &tpi, tunnel->hlen);
if (unlikely(!skb)) {
dev->stats.tx_dropped++;
return;
}
ip_tunnel_xmit(skb, dev, tnl_params);
}
static netdev_tx_t ipgre_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
const struct iphdr *tnl_params;
skb = handle_offloads(tunnel, skb);
if (IS_ERR(skb))
goto out;
if (dev->header_ops) {
if (skb_cow_head(skb, dev->needed_headroom -
(tunnel->hlen + sizeof(struct iphdr))))
goto free_skb;
tnl_params = (const struct iphdr *)skb->data;
skb_pull(skb, tunnel->hlen + sizeof(struct iphdr));
} else {
if (skb_cow_head(skb, dev->needed_headroom))
goto free_skb;
tnl_params = &tunnel->parms.iph;
}
__gre_xmit(skb, dev, tnl_params, skb->protocol);
return NETDEV_TX_OK;
free_skb:
dev_kfree_skb(skb);
out:
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static netdev_tx_t gre_tap_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
skb = handle_offloads(tunnel, skb);
if (IS_ERR(skb))
goto out;
if (skb_cow_head(skb, dev->needed_headroom))
goto free_skb;
__gre_xmit(skb, dev, &tunnel->parms.iph, htons(ETH_P_TEB));
return NETDEV_TX_OK;
free_skb:
dev_kfree_skb(skb);
out:
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static int ipgre_tunnel_ioctl(struct net_device *dev,
struct ifreq *ifr, int cmd)
{
int err = 0;
struct ip_tunnel_parm p;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
return -EFAULT;
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_GRE ||
p.iph.ihl != 5 || (p.iph.frag_off&htons(~IP_DF)) ||
((p.i_flags|p.o_flags)&(GRE_VERSION|GRE_ROUTING))) {
return -EINVAL;
}
p.i_flags = gre_flags_to_tnl_flags(p.i_flags);
p.o_flags = gre_flags_to_tnl_flags(p.o_flags);
err = ip_tunnel_ioctl(dev, &p, cmd);
if (err)
return err;
p.i_flags = tnl_flags_to_gre_flags(p.i_flags);
p.o_flags = tnl_flags_to_gre_flags(p.o_flags);
if (copy_to_user(ifr->ifr_ifru.ifru_data, &p, sizeof(p)))
return -EFAULT;
return 0;
}
static int ipgre_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned int len)
{
struct ip_tunnel *t = netdev_priv(dev);
struct iphdr *iph;
struct gre_base_hdr *greh;
iph = (struct iphdr *)skb_push(skb, t->hlen + sizeof(*iph));
greh = (struct gre_base_hdr *)(iph+1);
greh->flags = tnl_flags_to_gre_flags(t->parms.o_flags);
greh->protocol = htons(type);
memcpy(iph, &t->parms.iph, sizeof(struct iphdr));
if (saddr)
memcpy(&iph->saddr, saddr, 4);
if (daddr)
memcpy(&iph->daddr, daddr, 4);
if (iph->daddr)
return t->hlen;
return -(t->hlen + sizeof(*iph));
}
static int ipgre_header_parse(const struct sk_buff *skb, unsigned char *haddr)
{
const struct iphdr *iph = (const struct iphdr *) skb_mac_header(skb);
memcpy(haddr, &iph->saddr, 4);
return 4;
}
static int ipgre_open(struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
if (ipv4_is_multicast(t->parms.iph.daddr)) {
struct flowi4 fl4;
struct rtable *rt;
rt = ip_route_output_gre(dev_net(dev), &fl4,
t->parms.iph.daddr,
t->parms.iph.saddr,
t->parms.o_key,
RT_TOS(t->parms.iph.tos),
t->parms.link);
if (IS_ERR(rt))
return -EADDRNOTAVAIL;
dev = rt->dst.dev;
ip_rt_put(rt);
if (__in_dev_get_rtnl(dev) == NULL)
return -EADDRNOTAVAIL;
t->mlink = dev->ifindex;
ip_mc_inc_group(__in_dev_get_rtnl(dev), t->parms.iph.daddr);
}
return 0;
}
static int ipgre_close(struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
if (ipv4_is_multicast(t->parms.iph.daddr) && t->mlink) {
struct in_device *in_dev;
in_dev = inetdev_by_index(dev_net(dev), t->mlink);
if (in_dev)
ip_mc_dec_group(in_dev, t->parms.iph.daddr);
}
return 0;
}
static void ipgre_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &ipgre_netdev_ops;
ip_tunnel_setup(dev, ipgre_net_id);
}
static void __gre_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel;
tunnel = netdev_priv(dev);
tunnel->hlen = ip_gre_calc_hlen(tunnel->parms.o_flags);
tunnel->parms.iph.protocol = IPPROTO_GRE;
dev->needed_headroom = LL_MAX_HEADER + sizeof(struct iphdr) + 4;
dev->mtu = ETH_DATA_LEN - sizeof(struct iphdr) - 4;
dev->features |= NETIF_F_NETNS_LOCAL | GRE_FEATURES;
dev->hw_features |= GRE_FEATURES;
if (!(tunnel->parms.o_flags & TUNNEL_SEQ)) {
dev->features |= NETIF_F_GSO_SOFTWARE;
dev->hw_features |= NETIF_F_GSO_SOFTWARE;
dev->features |= NETIF_F_LLTX;
}
}
static int ipgre_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
struct iphdr *iph = &tunnel->parms.iph;
__gre_tunnel_init(dev);
memcpy(dev->dev_addr, &iph->saddr, 4);
memcpy(dev->broadcast, &iph->daddr, 4);
dev->type = ARPHRD_IPGRE;
dev->flags = IFF_NOARP;
dev->priv_flags &= ~IFF_XMIT_DST_RELEASE;
dev->addr_len = 4;
if (iph->daddr) {
#ifdef CONFIG_NET_IPGRE_BROADCAST
if (ipv4_is_multicast(iph->daddr)) {
if (!iph->saddr)
return -EINVAL;
dev->flags = IFF_BROADCAST;
dev->header_ops = &ipgre_header_ops;
}
#endif
} else
dev->header_ops = &ipgre_header_ops;
return ip_tunnel_init(dev);
}
static int __net_init ipgre_init_net(struct net *net)
{
return ip_tunnel_init_net(net, ipgre_net_id, &ipgre_link_ops, NULL);
}
static void __net_exit ipgre_exit_net(struct net *net)
{
struct ip_tunnel_net *itn = net_generic(net, ipgre_net_id);
ip_tunnel_delete_net(itn);
}
static int ipgre_tunnel_validate(struct nlattr *tb[], struct nlattr *data[])
{
__be16 flags;
if (!data)
return 0;
flags = 0;
if (data[IFLA_GRE_IFLAGS])
flags |= nla_get_be16(data[IFLA_GRE_IFLAGS]);
if (data[IFLA_GRE_OFLAGS])
flags |= nla_get_be16(data[IFLA_GRE_OFLAGS]);
if (flags & (GRE_VERSION|GRE_ROUTING))
return -EINVAL;
return 0;
}
static int ipgre_tap_validate(struct nlattr *tb[], struct nlattr *data[])
{
__be32 daddr;
if (tb[IFLA_ADDRESS]) {
if (nla_len(tb[IFLA_ADDRESS]) != ETH_ALEN)
return -EINVAL;
if (!is_valid_ether_addr(nla_data(tb[IFLA_ADDRESS])))
return -EADDRNOTAVAIL;
}
if (!data)
goto out;
if (data[IFLA_GRE_REMOTE]) {
memcpy(&daddr, nla_data(data[IFLA_GRE_REMOTE]), 4);
if (!daddr)
return -EINVAL;
}
out:
return ipgre_tunnel_validate(tb, data);
}
static void ipgre_netlink_parms(struct nlattr *data[], struct nlattr *tb[],
struct ip_tunnel_parm *parms)
{
memset(parms, 0, sizeof(*parms));
parms->iph.protocol = IPPROTO_GRE;
if (!data)
return;
if (data[IFLA_GRE_LINK])
parms->link = nla_get_u32(data[IFLA_GRE_LINK]);
if (data[IFLA_GRE_IFLAGS])
parms->i_flags = gre_flags_to_tnl_flags(nla_get_be16(data[IFLA_GRE_IFLAGS]));
if (data[IFLA_GRE_OFLAGS])
parms->o_flags = gre_flags_to_tnl_flags(nla_get_be16(data[IFLA_GRE_OFLAGS]));
if (data[IFLA_GRE_IKEY])
parms->i_key = nla_get_be32(data[IFLA_GRE_IKEY]);
if (data[IFLA_GRE_OKEY])
parms->o_key = nla_get_be32(data[IFLA_GRE_OKEY]);
if (data[IFLA_GRE_LOCAL])
parms->iph.saddr = nla_get_be32(data[IFLA_GRE_LOCAL]);
if (data[IFLA_GRE_REMOTE])
parms->iph.daddr = nla_get_be32(data[IFLA_GRE_REMOTE]);
if (data[IFLA_GRE_TTL])
parms->iph.ttl = nla_get_u8(data[IFLA_GRE_TTL]);
if (data[IFLA_GRE_TOS])
parms->iph.tos = nla_get_u8(data[IFLA_GRE_TOS]);
if (!data[IFLA_GRE_PMTUDISC] || nla_get_u8(data[IFLA_GRE_PMTUDISC]))
parms->iph.frag_off = htons(IP_DF);
}
static int gre_tap_init(struct net_device *dev)
{
__gre_tunnel_init(dev);
return ip_tunnel_init(dev);
}
static void ipgre_tap_setup(struct net_device *dev)
{
ether_setup(dev);
dev->netdev_ops = &gre_tap_netdev_ops;
ip_tunnel_setup(dev, gre_tap_net_id);
}
static int ipgre_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct ip_tunnel_parm p;
ipgre_netlink_parms(data, tb, &p);
return ip_tunnel_newlink(dev, tb, &p);
}
static int ipgre_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel_parm p;
ipgre_netlink_parms(data, tb, &p);
return ip_tunnel_changelink(dev, tb, &p);
}
static size_t ipgre_get_size(const struct net_device *dev)
{
return
nla_total_size(4) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(4) +
nla_total_size(1) +
nla_total_size(1) +
nla_total_size(1) +
0;
}
static int ipgre_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm *p = &t->parms;
if (nla_put_u32(skb, IFLA_GRE_LINK, p->link) ||
nla_put_be16(skb, IFLA_GRE_IFLAGS, tnl_flags_to_gre_flags(p->i_flags)) ||
nla_put_be16(skb, IFLA_GRE_OFLAGS, tnl_flags_to_gre_flags(p->o_flags)) ||
nla_put_be32(skb, IFLA_GRE_IKEY, p->i_key) ||
nla_put_be32(skb, IFLA_GRE_OKEY, p->o_key) ||
nla_put_be32(skb, IFLA_GRE_LOCAL, p->iph.saddr) ||
nla_put_be32(skb, IFLA_GRE_REMOTE, p->iph.daddr) ||
nla_put_u8(skb, IFLA_GRE_TTL, p->iph.ttl) ||
nla_put_u8(skb, IFLA_GRE_TOS, p->iph.tos) ||
nla_put_u8(skb, IFLA_GRE_PMTUDISC,
!!(p->iph.frag_off & htons(IP_DF))))
goto nla_put_failure;
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int __net_init ipgre_tap_init_net(struct net *net)
{
return ip_tunnel_init_net(net, gre_tap_net_id, &ipgre_tap_ops, NULL);
}
static void __net_exit ipgre_tap_exit_net(struct net *net)
{
struct ip_tunnel_net *itn = net_generic(net, gre_tap_net_id);
ip_tunnel_delete_net(itn);
}
static int __init ipgre_init(void)
{
int err;
pr_info("GRE over IPv4 tunneling driver\n");
err = register_pernet_device(&ipgre_net_ops);
if (err < 0)
return err;
err = register_pernet_device(&ipgre_tap_net_ops);
if (err < 0)
goto pnet_tap_faied;
err = gre_add_protocol(&ipgre_protocol, GREPROTO_CISCO);
if (err < 0) {
pr_info("%s: can't add protocol\n", __func__);
goto add_proto_failed;
}
err = rtnl_link_register(&ipgre_link_ops);
if (err < 0)
goto rtnl_link_failed;
err = rtnl_link_register(&ipgre_tap_ops);
if (err < 0)
goto tap_ops_failed;
return 0;
tap_ops_failed:
rtnl_link_unregister(&ipgre_link_ops);
rtnl_link_failed:
gre_del_protocol(&ipgre_protocol, GREPROTO_CISCO);
add_proto_failed:
unregister_pernet_device(&ipgre_tap_net_ops);
pnet_tap_faied:
unregister_pernet_device(&ipgre_net_ops);
return err;
}
static void __exit ipgre_fini(void)
{
rtnl_link_unregister(&ipgre_tap_ops);
rtnl_link_unregister(&ipgre_link_ops);
if (gre_del_protocol(&ipgre_protocol, GREPROTO_CISCO) < 0)
pr_info("%s: can't remove protocol\n", __func__);
unregister_pernet_device(&ipgre_tap_net_ops);
unregister_pernet_device(&ipgre_net_ops);
}
