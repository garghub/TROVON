static void send_reset(struct net *net, struct sk_buff *oldskb, int hook)
{
struct sk_buff *nskb;
struct tcphdr otcph, *tcph;
unsigned int otcplen, hh_len;
int tcphoff, needs_ack;
const struct ipv6hdr *oip6h = ipv6_hdr(oldskb);
struct ipv6hdr *ip6h;
#define DEFAULT_TOS_VALUE 0x0U
const __u8 tclass = DEFAULT_TOS_VALUE;
struct dst_entry *dst = NULL;
u8 proto;
__be16 frag_off;
struct flowi6 fl6;
if ((!(ipv6_addr_type(&oip6h->saddr) & IPV6_ADDR_UNICAST)) ||
(!(ipv6_addr_type(&oip6h->daddr) & IPV6_ADDR_UNICAST))) {
pr_debug("addr is not unicast.\n");
return;
}
proto = oip6h->nexthdr;
tcphoff = ipv6_skip_exthdr(oldskb, ((u8*)(oip6h+1) - oldskb->data), &proto, &frag_off);
if ((tcphoff < 0) || (tcphoff > oldskb->len)) {
pr_debug("Cannot get TCP header.\n");
return;
}
otcplen = oldskb->len - tcphoff;
if (proto != IPPROTO_TCP || otcplen < sizeof(struct tcphdr)) {
pr_debug("proto(%d) != IPPROTO_TCP, "
"or too short. otcplen = %d\n",
proto, otcplen);
return;
}
if (skb_copy_bits(oldskb, tcphoff, &otcph, sizeof(struct tcphdr)))
BUG();
if (otcph.rst) {
pr_debug("RST is set\n");
return;
}
if (nf_ip6_checksum(oldskb, hook, tcphoff, IPPROTO_TCP)) {
pr_debug("TCP checksum is invalid\n");
return;
}
memset(&fl6, 0, sizeof(fl6));
fl6.flowi6_proto = IPPROTO_TCP;
fl6.saddr = oip6h->daddr;
fl6.daddr = oip6h->saddr;
fl6.fl6_sport = otcph.dest;
fl6.fl6_dport = otcph.source;
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
skb_put(nskb, sizeof(struct ipv6hdr));
skb_reset_network_header(nskb);
ip6h = ipv6_hdr(nskb);
ip6_flow_hdr(ip6h, tclass, 0);
ip6h->hop_limit = ip6_dst_hoplimit(dst);
ip6h->nexthdr = IPPROTO_TCP;
ip6h->saddr = oip6h->daddr;
ip6h->daddr = oip6h->saddr;
skb_reset_transport_header(nskb);
tcph = (struct tcphdr *)skb_put(nskb, sizeof(struct tcphdr));
tcph->doff = sizeof(struct tcphdr)/4;
tcph->source = otcph.dest;
tcph->dest = otcph.source;
if (otcph.ack) {
needs_ack = 0;
tcph->seq = otcph.ack_seq;
tcph->ack_seq = 0;
} else {
needs_ack = 1;
tcph->ack_seq = htonl(ntohl(otcph.seq) + otcph.syn + otcph.fin
+ otcplen - (otcph.doff<<2));
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
nf_ct_attach(nskb, oldskb);
#ifdef CONFIG_BRIDGE_NETFILTER
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
static inline void
send_unreach(struct net *net, struct sk_buff *skb_in, unsigned char code,
unsigned int hooknum)
{
if (hooknum == NF_INET_LOCAL_OUT && skb_in->dev == NULL)
skb_in->dev = net->loopback_dev;
icmpv6_send(skb_in, ICMPV6_DEST_UNREACH, code, 0);
}
static unsigned int
reject_tg6(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ip6t_reject_info *reject = par->targinfo;
struct net *net = dev_net((par->in != NULL) ? par->in : par->out);
pr_debug("%s: medium point\n", __func__);
switch (reject->with) {
case IP6T_ICMP6_NO_ROUTE:
send_unreach(net, skb, ICMPV6_NOROUTE, par->hooknum);
break;
case IP6T_ICMP6_ADM_PROHIBITED:
send_unreach(net, skb, ICMPV6_ADM_PROHIBITED, par->hooknum);
break;
case IP6T_ICMP6_NOT_NEIGHBOUR:
send_unreach(net, skb, ICMPV6_NOT_NEIGHBOUR, par->hooknum);
break;
case IP6T_ICMP6_ADDR_UNREACH:
send_unreach(net, skb, ICMPV6_ADDR_UNREACH, par->hooknum);
break;
case IP6T_ICMP6_PORT_UNREACH:
send_unreach(net, skb, ICMPV6_PORT_UNREACH, par->hooknum);
break;
case IP6T_ICMP6_ECHOREPLY:
break;
case IP6T_TCP_RESET:
send_reset(net, skb, par->hooknum);
break;
default:
net_info_ratelimited("case %u not handled yet\n", reject->with);
break;
}
return NF_DROP;
}
static int reject_tg6_check(const struct xt_tgchk_param *par)
{
const struct ip6t_reject_info *rejinfo = par->targinfo;
const struct ip6t_entry *e = par->entryinfo;
if (rejinfo->with == IP6T_ICMP6_ECHOREPLY) {
pr_info("ECHOREPLY is not supported.\n");
return -EINVAL;
} else if (rejinfo->with == IP6T_TCP_RESET) {
if (e->ipv6.proto != IPPROTO_TCP ||
(e->ipv6.invflags & XT_INV_PROTO)) {
pr_info("TCP_RESET illegal for non-tcp\n");
return -EINVAL;
}
}
return 0;
}
static int __init reject_tg6_init(void)
{
return xt_register_target(&reject_tg6_reg);
}
static void __exit reject_tg6_exit(void)
{
xt_unregister_target(&reject_tg6_reg);
}
