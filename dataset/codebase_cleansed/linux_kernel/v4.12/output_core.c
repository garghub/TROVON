static u32 __ipv6_select_ident(struct net *net, u32 hashrnd,
const struct in6_addr *dst,
const struct in6_addr *src)
{
u32 hash, id;
hash = __ipv6_addr_jhash(dst, hashrnd);
hash = __ipv6_addr_jhash(src, hash);
hash ^= net_hash_mix(net);
id = ip_idents_reserve(hash, 1);
if (unlikely(!id))
id = 1 << 31;
return id;
}
void ipv6_proxy_select_ident(struct net *net, struct sk_buff *skb)
{
static u32 ip6_proxy_idents_hashrnd __read_mostly;
struct in6_addr buf[2];
struct in6_addr *addrs;
u32 id;
addrs = skb_header_pointer(skb,
skb_network_offset(skb) +
offsetof(struct ipv6hdr, saddr),
sizeof(buf), buf);
if (!addrs)
return;
net_get_random_once(&ip6_proxy_idents_hashrnd,
sizeof(ip6_proxy_idents_hashrnd));
id = __ipv6_select_ident(net, ip6_proxy_idents_hashrnd,
&addrs[1], &addrs[0]);
skb_shinfo(skb)->ip6_frag_id = htonl(id);
}
__be32 ipv6_select_ident(struct net *net,
const struct in6_addr *daddr,
const struct in6_addr *saddr)
{
static u32 ip6_idents_hashrnd __read_mostly;
u32 id;
net_get_random_once(&ip6_idents_hashrnd, sizeof(ip6_idents_hashrnd));
id = __ipv6_select_ident(net, ip6_idents_hashrnd, daddr, saddr);
return htonl(id);
}
int ip6_find_1stfragopt(struct sk_buff *skb, u8 **nexthdr)
{
u16 offset = sizeof(struct ipv6hdr);
unsigned int packet_len = skb_tail_pointer(skb) -
skb_network_header(skb);
int found_rhdr = 0;
*nexthdr = &ipv6_hdr(skb)->nexthdr;
while (offset <= packet_len) {
struct ipv6_opt_hdr *exthdr;
switch (**nexthdr) {
case NEXTHDR_HOP:
break;
case NEXTHDR_ROUTING:
found_rhdr = 1;
break;
case NEXTHDR_DEST:
#if IS_ENABLED(CONFIG_IPV6_MIP6)
if (ipv6_find_tlv(skb, offset, IPV6_TLV_HAO) >= 0)
break;
#endif
if (found_rhdr)
return offset;
break;
default:
return offset;
}
if (offset + sizeof(struct ipv6_opt_hdr) > packet_len)
return -EINVAL;
exthdr = (struct ipv6_opt_hdr *)(skb_network_header(skb) +
offset);
offset += ipv6_optlen(exthdr);
*nexthdr = &exthdr->nexthdr;
}
return -EINVAL;
}
int ip6_dst_hoplimit(struct dst_entry *dst)
{
int hoplimit = dst_metric_raw(dst, RTAX_HOPLIMIT);
if (hoplimit == 0) {
struct net_device *dev = dst->dev;
struct inet6_dev *idev;
rcu_read_lock();
idev = __in6_dev_get(dev);
if (idev)
hoplimit = idev->cnf.hop_limit;
else
hoplimit = dev_net(dev)->ipv6.devconf_all->hop_limit;
rcu_read_unlock();
}
return hoplimit;
}
int __ip6_local_out(struct net *net, struct sock *sk, struct sk_buff *skb)
{
int len;
len = skb->len - sizeof(struct ipv6hdr);
if (len > IPV6_MAXPLEN)
len = 0;
ipv6_hdr(skb)->payload_len = htons(len);
IP6CB(skb)->nhoff = offsetof(struct ipv6hdr, nexthdr);
skb = l3mdev_ip6_out(sk, skb);
if (unlikely(!skb))
return 0;
skb->protocol = htons(ETH_P_IPV6);
return nf_hook(NFPROTO_IPV6, NF_INET_LOCAL_OUT,
net, sk, skb, NULL, skb_dst(skb)->dev,
dst_output);
}
int ip6_local_out(struct net *net, struct sock *sk, struct sk_buff *skb)
{
int err;
err = __ip6_local_out(net, sk, skb);
if (likely(err == 1))
err = dst_output(net, sk, skb);
return err;
}
