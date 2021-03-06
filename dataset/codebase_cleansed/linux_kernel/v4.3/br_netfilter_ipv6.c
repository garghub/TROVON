static int br_nf_check_hbh_len(struct sk_buff *skb)
{
unsigned char *raw = (u8 *)(ipv6_hdr(skb) + 1);
u32 pkt_len;
const unsigned char *nh = skb_network_header(skb);
int off = raw - nh;
int len = (raw[1] + 1) << 3;
if ((raw + len) - skb->data > skb_headlen(skb))
goto bad;
off += 2;
len -= 2;
while (len > 0) {
int optlen = nh[off + 1] + 2;
switch (nh[off]) {
case IPV6_TLV_PAD1:
optlen = 1;
break;
case IPV6_TLV_PADN:
break;
case IPV6_TLV_JUMBO:
if (nh[off + 1] != 4 || (off & 3) != 2)
goto bad;
pkt_len = ntohl(*(__be32 *)(nh + off + 2));
if (pkt_len <= IPV6_MAXPLEN ||
ipv6_hdr(skb)->payload_len)
goto bad;
if (pkt_len > skb->len - sizeof(struct ipv6hdr))
goto bad;
if (pskb_trim_rcsum(skb,
pkt_len + sizeof(struct ipv6hdr)))
goto bad;
nh = skb_network_header(skb);
break;
default:
if (optlen > len)
goto bad;
break;
}
off += optlen;
len -= optlen;
}
if (len == 0)
return 0;
bad:
return -1;
}
int br_validate_ipv6(struct sk_buff *skb)
{
const struct ipv6hdr *hdr;
struct net_device *dev = skb->dev;
struct inet6_dev *idev = __in6_dev_get(skb->dev);
u32 pkt_len;
u8 ip6h_len = sizeof(struct ipv6hdr);
if (!pskb_may_pull(skb, ip6h_len))
goto inhdr_error;
if (skb->len < ip6h_len)
goto drop;
hdr = ipv6_hdr(skb);
if (hdr->version != 6)
goto inhdr_error;
pkt_len = ntohs(hdr->payload_len);
if (pkt_len || hdr->nexthdr != NEXTHDR_HOP) {
if (pkt_len + ip6h_len > skb->len) {
IP6_INC_STATS_BH(dev_net(dev), idev,
IPSTATS_MIB_INTRUNCATEDPKTS);
goto drop;
}
if (pskb_trim_rcsum(skb, pkt_len + ip6h_len)) {
IP6_INC_STATS_BH(dev_net(dev), idev,
IPSTATS_MIB_INDISCARDS);
goto drop;
}
}
if (hdr->nexthdr == NEXTHDR_HOP && br_nf_check_hbh_len(skb))
goto drop;
memset(IP6CB(skb), 0, sizeof(struct inet6_skb_parm));
return 0;
inhdr_error:
IP6_INC_STATS_BH(dev_net(dev), idev, IPSTATS_MIB_INHDRERRORS);
drop:
return -1;
}
static inline bool
br_nf_ipv6_daddr_was_changed(const struct sk_buff *skb,
const struct nf_bridge_info *nf_bridge)
{
return memcmp(&nf_bridge->ipv6_daddr, &ipv6_hdr(skb)->daddr,
sizeof(ipv6_hdr(skb)->daddr)) != 0;
}
static int br_nf_pre_routing_finish_ipv6(struct sock *sk, struct sk_buff *skb)
{
struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
struct rtable *rt;
struct net_device *dev = skb->dev;
const struct nf_ipv6_ops *v6ops = nf_get_ipv6_ops();
nf_bridge->frag_max_size = IP6CB(skb)->frag_max_size;
if (nf_bridge->pkt_otherhost) {
skb->pkt_type = PACKET_OTHERHOST;
nf_bridge->pkt_otherhost = false;
}
nf_bridge->in_prerouting = 0;
if (br_nf_ipv6_daddr_was_changed(skb, nf_bridge)) {
skb_dst_drop(skb);
v6ops->route_input(skb);
if (skb_dst(skb)->error) {
kfree_skb(skb);
return 0;
}
if (skb_dst(skb)->dev == dev) {
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE, NF_BR_PRE_ROUTING,
sk, skb, skb->dev, NULL,
br_nf_pre_routing_finish_bridge,
1);
return 0;
}
ether_addr_copy(eth_hdr(skb)->h_dest, dev->dev_addr);
skb->pkt_type = PACKET_HOST;
} else {
rt = bridge_parent_rtable(nf_bridge->physindev);
if (!rt) {
kfree_skb(skb);
return 0;
}
skb_dst_set_noref(skb, &rt->dst);
}
skb->dev = nf_bridge->physindev;
nf_bridge_update_protocol(skb);
nf_bridge_push_encap_header(skb);
NF_HOOK_THRESH(NFPROTO_BRIDGE, NF_BR_PRE_ROUTING, sk, skb,
skb->dev, NULL,
br_handle_frame_finish, 1);
return 0;
}
unsigned int br_nf_pre_routing_ipv6(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nf_bridge_info *nf_bridge;
if (br_validate_ipv6(skb))
return NF_DROP;
nf_bridge_put(skb->nf_bridge);
if (!nf_bridge_alloc(skb))
return NF_DROP;
if (!setup_pre_routing(skb))
return NF_DROP;
nf_bridge = nf_bridge_info_get(skb);
nf_bridge->ipv6_daddr = ipv6_hdr(skb)->daddr;
skb->protocol = htons(ETH_P_IPV6);
NF_HOOK(NFPROTO_IPV6, NF_INET_PRE_ROUTING, state->sk, skb,
skb->dev, NULL,
br_nf_pre_routing_finish_ipv6);
return NF_STOLEN;
}
