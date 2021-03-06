static void ipgre_err(struct sk_buff *skb, u32 info,
const struct tnl_ptk_info *tpi)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn;
const struct iphdr *iph;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
unsigned int data_len = 0;
struct ip_tunnel *t;
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
data_len = icmp_hdr(skb)->un.reserved[1] * 4;
break;
case ICMP_REDIRECT:
break;
}
if (tpi->proto == htons(ETH_P_TEB))
itn = net_generic(net, gre_tap_net_id);
else
itn = net_generic(net, ipgre_net_id);
iph = (const struct iphdr *)(icmp_hdr(skb) + 1);
t = ip_tunnel_lookup(itn, skb->dev->ifindex, tpi->flags,
iph->daddr, iph->saddr, tpi->key);
if (!t)
return;
#if IS_ENABLED(CONFIG_IPV6)
if (tpi->proto == htons(ETH_P_IPV6) &&
!ip6_err_gen_icmpv6_unreach(skb, iph->ihl * 4 + tpi->hdr_len,
type, data_len))
return;
#endif
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
static void gre_err(struct sk_buff *skb, u32 info)
{
const struct iphdr *iph = (struct iphdr *)skb->data;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct tnl_ptk_info tpi;
bool csum_err = false;
if (gre_parse_header(skb, &tpi, &csum_err, htons(ETH_P_IP),
iph->ihl * 4) < 0) {
if (!csum_err)
return;
}
if (type == ICMP_DEST_UNREACH && code == ICMP_FRAG_NEEDED) {
ipv4_update_pmtu(skb, dev_net(skb->dev), info,
skb->dev->ifindex, 0, IPPROTO_GRE, 0);
return;
}
if (type == ICMP_REDIRECT) {
ipv4_redirect(skb, dev_net(skb->dev), skb->dev->ifindex, 0,
IPPROTO_GRE, 0);
return;
}
ipgre_err(skb, info, &tpi);
}
static __be64 key_to_tunnel_id(__be32 key)
{
#ifdef __BIG_ENDIAN
return (__force __be64)((__force u32)key);
#else
return (__force __be64)((__force u64)key << 32);
#endif
}
static __be32 tunnel_id_to_key(__be64 x)
{
#ifdef __BIG_ENDIAN
return (__force __be32)x;
#else
return (__force __be32)((__force u64)x >> 32);
#endif
}
static int __ipgre_rcv(struct sk_buff *skb, const struct tnl_ptk_info *tpi,
struct ip_tunnel_net *itn, int hdr_len, bool raw_proto)
{
struct metadata_dst *tun_dst = NULL;
const struct iphdr *iph;
struct ip_tunnel *tunnel;
iph = ip_hdr(skb);
tunnel = ip_tunnel_lookup(itn, skb->dev->ifindex, tpi->flags,
iph->saddr, iph->daddr, tpi->key);
if (tunnel) {
if (__iptunnel_pull_header(skb, hdr_len, tpi->proto,
raw_proto, false) < 0)
goto drop;
if (tunnel->dev->type != ARPHRD_NONE)
skb_pop_mac_header(skb);
else
skb_reset_mac_header(skb);
if (tunnel->collect_md) {
__be16 flags;
__be64 tun_id;
flags = tpi->flags & (TUNNEL_CSUM | TUNNEL_KEY);
tun_id = key_to_tunnel_id(tpi->key);
tun_dst = ip_tun_rx_dst(skb, flags, tun_id, 0);
if (!tun_dst)
return PACKET_REJECT;
}
ip_tunnel_rcv(tunnel, skb, tpi, tun_dst, log_ecn_error);
return PACKET_RCVD;
}
return PACKET_NEXT;
drop:
kfree_skb(skb);
return PACKET_RCVD;
}
static int ipgre_rcv(struct sk_buff *skb, const struct tnl_ptk_info *tpi,
int hdr_len)
{
struct net *net = dev_net(skb->dev);
struct ip_tunnel_net *itn;
int res;
if (tpi->proto == htons(ETH_P_TEB))
itn = net_generic(net, gre_tap_net_id);
else
itn = net_generic(net, ipgre_net_id);
res = __ipgre_rcv(skb, tpi, itn, hdr_len, false);
if (res == PACKET_NEXT && tpi->proto == htons(ETH_P_TEB)) {
itn = net_generic(net, ipgre_net_id);
res = __ipgre_rcv(skb, tpi, itn, hdr_len, true);
}
return res;
}
static int gre_rcv(struct sk_buff *skb)
{
struct tnl_ptk_info tpi;
bool csum_err = false;
int hdr_len;
#ifdef CONFIG_NET_IPGRE_BROADCAST
if (ipv4_is_multicast(ip_hdr(skb)->daddr)) {
if (rt_is_output_route(skb_rtable(skb)))
goto drop;
}
#endif
hdr_len = gre_parse_header(skb, &tpi, &csum_err, htons(ETH_P_IP), 0);
if (hdr_len < 0)
goto drop;
if (ipgre_rcv(skb, &tpi, hdr_len) == PACKET_RCVD)
return 0;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static void __gre_xmit(struct sk_buff *skb, struct net_device *dev,
const struct iphdr *tnl_params,
__be16 proto)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
if (tunnel->parms.o_flags & TUNNEL_SEQ)
tunnel->o_seqno++;
gre_build_header(skb, tunnel->tun_hlen,
tunnel->parms.o_flags, proto, tunnel->parms.o_key,
htonl(tunnel->o_seqno));
ip_tunnel_xmit(skb, dev, tnl_params, tnl_params->protocol);
}
static int gre_handle_offloads(struct sk_buff *skb, bool csum)
{
return iptunnel_handle_offloads(skb, csum ? SKB_GSO_GRE_CSUM : SKB_GSO_GRE);
}
static struct rtable *gre_get_rt(struct sk_buff *skb,
struct net_device *dev,
struct flowi4 *fl,
const struct ip_tunnel_key *key)
{
struct net *net = dev_net(dev);
memset(fl, 0, sizeof(*fl));
fl->daddr = key->u.ipv4.dst;
fl->saddr = key->u.ipv4.src;
fl->flowi4_tos = RT_TOS(key->tos);
fl->flowi4_mark = skb->mark;
fl->flowi4_proto = IPPROTO_GRE;
return ip_route_output_key(net, fl);
}
static void gre_fb_xmit(struct sk_buff *skb, struct net_device *dev,
__be16 proto)
{
struct ip_tunnel_info *tun_info;
const struct ip_tunnel_key *key;
struct rtable *rt = NULL;
struct flowi4 fl;
int min_headroom;
int tunnel_hlen;
__be16 df, flags;
bool use_cache;
int err;
tun_info = skb_tunnel_info(skb);
if (unlikely(!tun_info || !(tun_info->mode & IP_TUNNEL_INFO_TX) ||
ip_tunnel_info_af(tun_info) != AF_INET))
goto err_free_skb;
key = &tun_info->key;
use_cache = ip_tunnel_dst_cache_usable(skb, tun_info);
if (use_cache)
rt = dst_cache_get_ip4(&tun_info->dst_cache, &fl.saddr);
if (!rt) {
rt = gre_get_rt(skb, dev, &fl, key);
if (IS_ERR(rt))
goto err_free_skb;
if (use_cache)
dst_cache_set_ip4(&tun_info->dst_cache, &rt->dst,
fl.saddr);
}
tunnel_hlen = gre_calc_hlen(key->tun_flags);
min_headroom = LL_RESERVED_SPACE(rt->dst.dev) + rt->dst.header_len
+ tunnel_hlen + sizeof(struct iphdr);
if (skb_headroom(skb) < min_headroom || skb_header_cloned(skb)) {
int head_delta = SKB_DATA_ALIGN(min_headroom -
skb_headroom(skb) +
16);
err = pskb_expand_head(skb, max_t(int, head_delta, 0),
0, GFP_ATOMIC);
if (unlikely(err))
goto err_free_rt;
}
if (gre_handle_offloads(skb, !!(tun_info->key.tun_flags & TUNNEL_CSUM)))
goto err_free_rt;
flags = tun_info->key.tun_flags & (TUNNEL_CSUM | TUNNEL_KEY);
gre_build_header(skb, tunnel_hlen, flags, proto,
tunnel_id_to_key(tun_info->key.tun_id), 0);
df = key->tun_flags & TUNNEL_DONT_FRAGMENT ? htons(IP_DF) : 0;
iptunnel_xmit(skb->sk, rt, skb, fl.saddr, key->u.ipv4.dst, IPPROTO_GRE,
key->tos, key->ttl, df, false);
return;
err_free_rt:
ip_rt_put(rt);
err_free_skb:
kfree_skb(skb);
dev->stats.tx_dropped++;
}
static int gre_fill_metadata_dst(struct net_device *dev, struct sk_buff *skb)
{
struct ip_tunnel_info *info = skb_tunnel_info(skb);
struct rtable *rt;
struct flowi4 fl4;
if (ip_tunnel_info_af(info) != AF_INET)
return -EINVAL;
rt = gre_get_rt(skb, dev, &fl4, &info->key);
if (IS_ERR(rt))
return PTR_ERR(rt);
ip_rt_put(rt);
info->key.u.ipv4.src = fl4.saddr;
return 0;
}
static netdev_tx_t ipgre_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
const struct iphdr *tnl_params;
if (tunnel->collect_md) {
gre_fb_xmit(skb, dev, skb->protocol);
return NETDEV_TX_OK;
}
if (dev->header_ops) {
if (skb_cow_head(skb, dev->needed_headroom -
(tunnel->hlen + sizeof(struct iphdr))))
goto free_skb;
tnl_params = (const struct iphdr *)skb->data;
skb_pull(skb, tunnel->hlen + sizeof(struct iphdr));
skb_reset_mac_header(skb);
} else {
if (skb_cow_head(skb, dev->needed_headroom))
goto free_skb;
tnl_params = &tunnel->parms.iph;
}
if (gre_handle_offloads(skb, !!(tunnel->parms.o_flags & TUNNEL_CSUM)))
goto free_skb;
__gre_xmit(skb, dev, tnl_params, skb->protocol);
return NETDEV_TX_OK;
free_skb:
kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static netdev_tx_t gre_tap_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ip_tunnel *tunnel = netdev_priv(dev);
if (tunnel->collect_md) {
gre_fb_xmit(skb, dev, htons(ETH_P_TEB));
return NETDEV_TX_OK;
}
if (gre_handle_offloads(skb, !!(tunnel->parms.o_flags & TUNNEL_CSUM)))
goto free_skb;
if (skb_cow_head(skb, dev->needed_headroom))
goto free_skb;
__gre_xmit(skb, dev, &tunnel->parms.iph, htons(ETH_P_TEB));
return NETDEV_TX_OK;
free_skb:
kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static int ipgre_tunnel_ioctl(struct net_device *dev,
struct ifreq *ifr, int cmd)
{
int err;
struct ip_tunnel_parm p;
if (copy_from_user(&p, ifr->ifr_ifru.ifru_data, sizeof(p)))
return -EFAULT;
if (cmd == SIOCADDTUNNEL || cmd == SIOCCHGTUNNEL) {
if (p.iph.version != 4 || p.iph.protocol != IPPROTO_GRE ||
p.iph.ihl != 5 || (p.iph.frag_off&htons(~IP_DF)) ||
((p.i_flags|p.o_flags)&(GRE_VERSION|GRE_ROUTING)))
return -EINVAL;
}
p.i_flags = gre_flags_to_tnl_flags(p.i_flags);
p.o_flags = gre_flags_to_tnl_flags(p.o_flags);
err = ip_tunnel_ioctl(dev, &p, cmd);
if (err)
return err;
p.i_flags = gre_tnl_flags_to_gre_flags(p.i_flags);
p.o_flags = gre_tnl_flags_to_gre_flags(p.o_flags);
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
greh->flags = gre_tnl_flags_to_gre_flags(t->parms.o_flags);
greh->protocol = htons(type);
memcpy(iph, &t->parms.iph, sizeof(struct iphdr));
if (saddr)
memcpy(&iph->saddr, saddr, 4);
if (daddr)
memcpy(&iph->daddr, daddr, 4);
if (iph->daddr)
return t->hlen + sizeof(*iph);
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
rt = ip_route_output_gre(t->net, &fl4,
t->parms.iph.daddr,
t->parms.iph.saddr,
t->parms.o_key,
RT_TOS(t->parms.iph.tos),
t->parms.link);
if (IS_ERR(rt))
return -EADDRNOTAVAIL;
dev = rt->dst.dev;
ip_rt_put(rt);
if (!__in_dev_get_rtnl(dev))
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
in_dev = inetdev_by_index(t->net, t->mlink);
if (in_dev)
ip_mc_dec_group(in_dev, t->parms.iph.daddr);
}
return 0;
}
static void ipgre_tunnel_setup(struct net_device *dev)
{
dev->netdev_ops = &ipgre_netdev_ops;
dev->type = ARPHRD_IPGRE;
ip_tunnel_setup(dev, ipgre_net_id);
}
static void __gre_tunnel_init(struct net_device *dev)
{
struct ip_tunnel *tunnel;
int t_hlen;
tunnel = netdev_priv(dev);
tunnel->tun_hlen = gre_calc_hlen(tunnel->parms.o_flags);
tunnel->parms.iph.protocol = IPPROTO_GRE;
tunnel->hlen = tunnel->tun_hlen + tunnel->encap_hlen;
t_hlen = tunnel->hlen + sizeof(struct iphdr);
dev->needed_headroom = LL_MAX_HEADER + t_hlen + 4;
dev->mtu = ETH_DATA_LEN - t_hlen - 4;
dev->features |= GRE_FEATURES;
dev->hw_features |= GRE_FEATURES;
if (!(tunnel->parms.o_flags & TUNNEL_SEQ)) {
if (!(tunnel->parms.o_flags & TUNNEL_CSUM) ||
(tunnel->encap.type == TUNNEL_ENCAP_NONE)) {
dev->features |= NETIF_F_GSO_SOFTWARE;
dev->hw_features |= NETIF_F_GSO_SOFTWARE;
}
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
dev->flags = IFF_NOARP;
netif_keep_dst(dev);
dev->addr_len = 4;
if (iph->daddr && !tunnel->collect_md) {
#ifdef CONFIG_NET_IPGRE_BROADCAST
if (ipv4_is_multicast(iph->daddr)) {
if (!iph->saddr)
return -EINVAL;
dev->flags = IFF_BROADCAST;
dev->header_ops = &ipgre_header_ops;
}
#endif
} else if (!tunnel->collect_md) {
dev->header_ops = &ipgre_header_ops;
}
return ip_tunnel_init(dev);
}
static int __net_init ipgre_init_net(struct net *net)
{
return ip_tunnel_init_net(net, ipgre_net_id, &ipgre_link_ops, NULL);
}
static void __net_exit ipgre_exit_net(struct net *net)
{
struct ip_tunnel_net *itn = net_generic(net, ipgre_net_id);
ip_tunnel_delete_net(itn, &ipgre_link_ops);
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
if (data[IFLA_GRE_COLLECT_METADATA] &&
data[IFLA_GRE_ENCAP_TYPE] &&
nla_get_u16(data[IFLA_GRE_ENCAP_TYPE]) != TUNNEL_ENCAP_NONE)
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
static int ipgre_netlink_parms(struct net_device *dev,
struct nlattr *data[],
struct nlattr *tb[],
struct ip_tunnel_parm *parms)
{
struct ip_tunnel *t = netdev_priv(dev);
memset(parms, 0, sizeof(*parms));
parms->iph.protocol = IPPROTO_GRE;
if (!data)
return 0;
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
parms->iph.saddr = nla_get_in_addr(data[IFLA_GRE_LOCAL]);
if (data[IFLA_GRE_REMOTE])
parms->iph.daddr = nla_get_in_addr(data[IFLA_GRE_REMOTE]);
if (data[IFLA_GRE_TTL])
parms->iph.ttl = nla_get_u8(data[IFLA_GRE_TTL]);
if (data[IFLA_GRE_TOS])
parms->iph.tos = nla_get_u8(data[IFLA_GRE_TOS]);
if (!data[IFLA_GRE_PMTUDISC] || nla_get_u8(data[IFLA_GRE_PMTUDISC])) {
if (t->ignore_df)
return -EINVAL;
parms->iph.frag_off = htons(IP_DF);
}
if (data[IFLA_GRE_COLLECT_METADATA]) {
t->collect_md = true;
if (dev->type == ARPHRD_IPGRE)
dev->type = ARPHRD_NONE;
}
if (data[IFLA_GRE_IGNORE_DF]) {
if (nla_get_u8(data[IFLA_GRE_IGNORE_DF])
&& (parms->iph.frag_off & htons(IP_DF)))
return -EINVAL;
t->ignore_df = !!nla_get_u8(data[IFLA_GRE_IGNORE_DF]);
}
return 0;
}
static bool ipgre_netlink_encap_parms(struct nlattr *data[],
struct ip_tunnel_encap *ipencap)
{
bool ret = false;
memset(ipencap, 0, sizeof(*ipencap));
if (!data)
return ret;
if (data[IFLA_GRE_ENCAP_TYPE]) {
ret = true;
ipencap->type = nla_get_u16(data[IFLA_GRE_ENCAP_TYPE]);
}
if (data[IFLA_GRE_ENCAP_FLAGS]) {
ret = true;
ipencap->flags = nla_get_u16(data[IFLA_GRE_ENCAP_FLAGS]);
}
if (data[IFLA_GRE_ENCAP_SPORT]) {
ret = true;
ipencap->sport = nla_get_be16(data[IFLA_GRE_ENCAP_SPORT]);
}
if (data[IFLA_GRE_ENCAP_DPORT]) {
ret = true;
ipencap->dport = nla_get_be16(data[IFLA_GRE_ENCAP_DPORT]);
}
return ret;
}
static int gre_tap_init(struct net_device *dev)
{
__gre_tunnel_init(dev);
dev->priv_flags |= IFF_LIVE_ADDR_CHANGE;
return ip_tunnel_init(dev);
}
static void ipgre_tap_setup(struct net_device *dev)
{
ether_setup(dev);
dev->netdev_ops = &gre_tap_netdev_ops;
dev->priv_flags &= ~IFF_TX_SKB_SHARING;
dev->priv_flags |= IFF_LIVE_ADDR_CHANGE;
ip_tunnel_setup(dev, gre_tap_net_id);
}
static int ipgre_newlink(struct net *src_net, struct net_device *dev,
struct nlattr *tb[], struct nlattr *data[])
{
struct ip_tunnel_parm p;
struct ip_tunnel_encap ipencap;
int err;
if (ipgre_netlink_encap_parms(data, &ipencap)) {
struct ip_tunnel *t = netdev_priv(dev);
err = ip_tunnel_encap_setup(t, &ipencap);
if (err < 0)
return err;
}
err = ipgre_netlink_parms(dev, data, tb, &p);
if (err < 0)
return err;
return ip_tunnel_newlink(dev, tb, &p);
}
static int ipgre_changelink(struct net_device *dev, struct nlattr *tb[],
struct nlattr *data[])
{
struct ip_tunnel_parm p;
struct ip_tunnel_encap ipencap;
int err;
if (ipgre_netlink_encap_parms(data, &ipencap)) {
struct ip_tunnel *t = netdev_priv(dev);
err = ip_tunnel_encap_setup(t, &ipencap);
if (err < 0)
return err;
}
err = ipgre_netlink_parms(dev, data, tb, &p);
if (err < 0)
return err;
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
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(2) +
nla_total_size(0) +
nla_total_size(1) +
0;
}
static int ipgre_fill_info(struct sk_buff *skb, const struct net_device *dev)
{
struct ip_tunnel *t = netdev_priv(dev);
struct ip_tunnel_parm *p = &t->parms;
if (nla_put_u32(skb, IFLA_GRE_LINK, p->link) ||
nla_put_be16(skb, IFLA_GRE_IFLAGS,
gre_tnl_flags_to_gre_flags(p->i_flags)) ||
nla_put_be16(skb, IFLA_GRE_OFLAGS,
gre_tnl_flags_to_gre_flags(p->o_flags)) ||
nla_put_be32(skb, IFLA_GRE_IKEY, p->i_key) ||
nla_put_be32(skb, IFLA_GRE_OKEY, p->o_key) ||
nla_put_in_addr(skb, IFLA_GRE_LOCAL, p->iph.saddr) ||
nla_put_in_addr(skb, IFLA_GRE_REMOTE, p->iph.daddr) ||
nla_put_u8(skb, IFLA_GRE_TTL, p->iph.ttl) ||
nla_put_u8(skb, IFLA_GRE_TOS, p->iph.tos) ||
nla_put_u8(skb, IFLA_GRE_PMTUDISC,
!!(p->iph.frag_off & htons(IP_DF))))
goto nla_put_failure;
if (nla_put_u16(skb, IFLA_GRE_ENCAP_TYPE,
t->encap.type) ||
nla_put_be16(skb, IFLA_GRE_ENCAP_SPORT,
t->encap.sport) ||
nla_put_be16(skb, IFLA_GRE_ENCAP_DPORT,
t->encap.dport) ||
nla_put_u16(skb, IFLA_GRE_ENCAP_FLAGS,
t->encap.flags))
goto nla_put_failure;
if (nla_put_u8(skb, IFLA_GRE_IGNORE_DF, t->ignore_df))
goto nla_put_failure;
if (t->collect_md) {
if (nla_put_flag(skb, IFLA_GRE_COLLECT_METADATA))
goto nla_put_failure;
}
return 0;
nla_put_failure:
return -EMSGSIZE;
}
struct net_device *gretap_fb_dev_create(struct net *net, const char *name,
u8 name_assign_type)
{
struct nlattr *tb[IFLA_MAX + 1];
struct net_device *dev;
LIST_HEAD(list_kill);
struct ip_tunnel *t;
int err;
memset(&tb, 0, sizeof(tb));
dev = rtnl_create_link(net, name, name_assign_type,
&ipgre_tap_ops, tb);
if (IS_ERR(dev))
return dev;
t = netdev_priv(dev);
t->collect_md = true;
err = ipgre_newlink(net, dev, tb, NULL);
if (err < 0) {
free_netdev(dev);
return ERR_PTR(err);
}
err = __ip_tunnel_change_mtu(dev, IP_MAX_MTU, false);
if (err)
goto out;
err = rtnl_configure_link(dev, NULL);
if (err < 0)
goto out;
return dev;
out:
ip_tunnel_dellink(dev, &list_kill);
unregister_netdevice_many(&list_kill);
return ERR_PTR(err);
}
static int __net_init ipgre_tap_init_net(struct net *net)
{
return ip_tunnel_init_net(net, gre_tap_net_id, &ipgre_tap_ops, "gretap0");
}
static void __net_exit ipgre_tap_exit_net(struct net *net)
{
struct ip_tunnel_net *itn = net_generic(net, gre_tap_net_id);
ip_tunnel_delete_net(itn, &ipgre_tap_ops);
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
gre_del_protocol(&ipgre_protocol, GREPROTO_CISCO);
unregister_pernet_device(&ipgre_tap_net_ops);
unregister_pernet_device(&ipgre_net_ops);
}
