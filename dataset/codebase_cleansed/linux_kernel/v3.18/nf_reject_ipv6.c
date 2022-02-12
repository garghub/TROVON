const struct tcphdr *nf_reject_ip6_tcphdr_get(struct sk_buff *oldskb,
struct tcphdr *otcph,
unsigned int *otcplen, int hook)
{
const struct ipv6hdr *oip6h = ipv6_hdr(oldskb);
u8 proto;
__be16 frag_off;
int tcphoff;
proto = oip6h->nexthdr;
tcphoff = ipv6_skip_exthdr(oldskb, ((u8*)(oip6h+1) - oldskb->data),
&proto, &frag_off);
if ((tcphoff < 0) || (tcphoff > oldskb->len)) {
pr_debug("Cannot get TCP header.\n");
return NULL;
}
*otcplen = oldskb->len - tcphoff;
if (proto != IPPROTO_TCP || *otcplen < sizeof(struct tcphdr)) {
pr_debug("proto(%d) != IPPROTO_TCP or too short (len = %d)\n",
proto, *otcplen);
return NULL;
}
otcph = skb_header_pointer(oldskb, tcphoff, sizeof(struct tcphdr),
otcph);
if (otcph == NULL)
return NULL;
if (otcph->rst) {
pr_debug("RST is set\n");
return NULL;
}
if (nf_ip6_checksum(oldskb, hook, tcphoff, IPPROTO_TCP)) {
pr_debug("TCP checksum is invalid\n");
return NULL;
}
return otcph;
}
struct ipv6hdr *nf_reject_ip6hdr_put(struct sk_buff *nskb,
const struct sk_buff *oldskb,
__be16 protocol, int hoplimit)
{
struct ipv6hdr *ip6h;
const struct ipv6hdr *oip6h = ipv6_hdr(oldskb);
#define DEFAULT_TOS_VALUE 0x0U
const __u8 tclass = DEFAULT_TOS_VALUE;
skb_put(nskb, sizeof(struct ipv6hdr));
skb_reset_network_header(nskb);
ip6h = ipv6_hdr(nskb);
ip6_flow_hdr(ip6h, tclass, 0);
ip6h->hop_limit = hoplimit;
ip6h->nexthdr = protocol;
ip6h->saddr = oip6h->daddr;
ip6h->daddr = oip6h->saddr;
nskb->protocol = htons(ETH_P_IPV6);
return ip6h;
}
void nf_reject_ip6_tcphdr_put(struct sk_buff *nskb,
const struct sk_buff *oldskb,
const struct tcphdr *oth, unsigned int otcplen)
{
struct tcphdr *tcph;
int needs_ack;
skb_reset_transport_header(nskb);
tcph = (struct tcphdr *)skb_put(nskb, sizeof(struct tcphdr));
tcph->doff = sizeof(struct tcphdr)/4;
tcph->source = oth->dest;
tcph->dest = oth->source;
if (oth->ack) {
needs_ack = 0;
tcph->seq = oth->ack_seq;
tcph->ack_seq = 0;
} else {
needs_ack = 1;
tcph->ack_seq = htonl(ntohl(oth->seq) + oth->syn + oth->fin +
otcplen - (oth->doff<<2));
tcph->seq = 0;
}
((u_int8_t *)tcph)[13] = 0;
tcph->rst = 1;
tcph->ack = needs_ack;
tcph->window = 0;
tcph->urg_ptr = 0;
tcph->check = 0;
tcph->check = csum_ipv6_magic(&ipv6_hdr(nskb)->saddr,
&ipv6_hdr(nskb)->daddr,
sizeof(struct tcphdr), IPPROTO_TCP,
csum_partial(tcph,
sizeof(struct tcphdr), 0));
}
void nf_send_reset6(struct net *net, struct sk_buff *oldskb, int hook)
{
struct sk_buff *nskb;
struct tcphdr _otcph;
const struct tcphdr *otcph;
unsigned int otcplen, hh_len;
const struct ipv6hdr *oip6h = ipv6_hdr(oldskb);
struct ipv6hdr *ip6h;
struct dst_entry *dst = NULL;
struct flowi6 fl6;
if ((!(ipv6_addr_type(&oip6h->saddr) & IPV6_ADDR_UNICAST)) ||
(!(ipv6_addr_type(&oip6h->daddr) & IPV6_ADDR_UNICAST))) {
pr_debug("addr is not unicast.\n");
return;
}
otcph = nf_reject_ip6_tcphdr_get(oldskb, &_otcph, &otcplen, hook);
if (!otcph)
return;
memset(&fl6, 0, sizeof(fl6));
fl6.flowi6_proto = IPPROTO_TCP;
fl6.saddr = oip6h->daddr;
fl6.daddr = oip6h->saddr;
fl6.fl6_sport = otcph->dest;
fl6.fl6_dport = otcph->source;
security_skb_classify_flow(oldskb, flowi6_to_flowi(&fl6));
dst = ip6_route_output(net, NULL, &fl6);
if (dst == NULL || dst->error) {
dst_release(dst);
return;
}
dst = xfrm_lookup(net, dst, flowi6_to_flowi(&fl6), NULL, 0);
if (IS_ERR(dst))
return;
hh_len = (dst->dev->hard_header_len + 15)&~15;
nskb = alloc_skb(hh_len + 15 + dst->header_len + sizeof(struct ipv6hdr)
+ sizeof(struct tcphdr) + dst->trailer_len,
GFP_ATOMIC);
if (!nskb) {
net_dbg_ratelimited("cannot alloc skb\n");
dst_release(dst);
return;
}
skb_dst_set(nskb, dst);
skb_reserve(nskb, hh_len + dst->header_len);
ip6h = nf_reject_ip6hdr_put(nskb, oldskb, IPPROTO_TCP,
ip6_dst_hoplimit(dst));
nf_reject_ip6_tcphdr_put(nskb, oldskb, otcph, otcplen);
nf_ct_attach(nskb, oldskb);
#if IS_ENABLED(CONFIG_BRIDGE_NETFILTER)
if (oldskb->nf_bridge) {
struct ethhdr *oeth = eth_hdr(oldskb);
nskb->dev = oldskb->nf_bridge->physindev;
nskb->protocol = htons(ETH_P_IPV6);
ip6h->payload_len = htons(sizeof(struct tcphdr));
if (dev_hard_header(nskb, nskb->dev, ntohs(nskb->protocol),
oeth->h_source, oeth->h_dest, nskb->len) < 0)
return;
dev_queue_xmit(nskb);
} else
#endif
ip6_local_out(nskb);
}
