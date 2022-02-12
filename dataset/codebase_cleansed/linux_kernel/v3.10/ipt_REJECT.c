static void send_reset(struct sk_buff *oldskb, int hook)
{
struct sk_buff *nskb;
const struct iphdr *oiph;
struct iphdr *niph;
const struct tcphdr *oth;
struct tcphdr _otcph, *tcph;
if (ip_hdr(oldskb)->frag_off & htons(IP_OFFSET))
return;
oth = skb_header_pointer(oldskb, ip_hdrlen(oldskb),
sizeof(_otcph), &_otcph);
if (oth == NULL)
return;
if (oth->rst)
return;
if (skb_rtable(oldskb)->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST))
return;
if (nf_ip_checksum(oldskb, hook, ip_hdrlen(oldskb), IPPROTO_TCP))
return;
oiph = ip_hdr(oldskb);
nskb = alloc_skb(sizeof(struct iphdr) + sizeof(struct tcphdr) +
LL_MAX_HEADER, GFP_ATOMIC);
if (!nskb)
return;
skb_reserve(nskb, LL_MAX_HEADER);
skb_reset_network_header(nskb);
niph = (struct iphdr *)skb_put(nskb, sizeof(struct iphdr));
niph->version = 4;
niph->ihl = sizeof(struct iphdr) / 4;
niph->tos = 0;
niph->id = 0;
niph->frag_off = htons(IP_DF);
niph->protocol = IPPROTO_TCP;
niph->check = 0;
niph->saddr = oiph->daddr;
niph->daddr = oiph->saddr;
skb_reset_transport_header(nskb);
tcph = (struct tcphdr *)skb_put(nskb, sizeof(struct tcphdr));
memset(tcph, 0, sizeof(*tcph));
tcph->source = oth->dest;
tcph->dest = oth->source;
tcph->doff = sizeof(struct tcphdr) / 4;
if (oth->ack)
tcph->seq = oth->ack_seq;
else {
tcph->ack_seq = htonl(ntohl(oth->seq) + oth->syn + oth->fin +
oldskb->len - ip_hdrlen(oldskb) -
(oth->doff << 2));
tcph->ack = 1;
}
tcph->rst = 1;
tcph->check = ~tcp_v4_check(sizeof(struct tcphdr), niph->saddr,
niph->daddr, 0);
nskb->ip_summed = CHECKSUM_PARTIAL;
nskb->csum_start = (unsigned char *)tcph - nskb->head;
nskb->csum_offset = offsetof(struct tcphdr, check);
skb_dst_set_noref(nskb, skb_dst(oldskb));
nskb->protocol = htons(ETH_P_IP);
if (ip_route_me_harder(nskb, RTN_UNSPEC))
goto free_nskb;
niph->ttl = ip4_dst_hoplimit(skb_dst(nskb));
if (nskb->len > dst_mtu(skb_dst(nskb)))
goto free_nskb;
nf_ct_attach(nskb, oldskb);
ip_local_out(nskb);
return;
free_nskb:
kfree_skb(nskb);
}
static inline void send_unreach(struct sk_buff *skb_in, int code)
{
icmp_send(skb_in, ICMP_DEST_UNREACH, code, 0);
}
static unsigned int
reject_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ipt_reject_info *reject = par->targinfo;
switch (reject->with) {
case IPT_ICMP_NET_UNREACHABLE:
send_unreach(skb, ICMP_NET_UNREACH);
break;
case IPT_ICMP_HOST_UNREACHABLE:
send_unreach(skb, ICMP_HOST_UNREACH);
break;
case IPT_ICMP_PROT_UNREACHABLE:
send_unreach(skb, ICMP_PROT_UNREACH);
break;
case IPT_ICMP_PORT_UNREACHABLE:
send_unreach(skb, ICMP_PORT_UNREACH);
break;
case IPT_ICMP_NET_PROHIBITED:
send_unreach(skb, ICMP_NET_ANO);
break;
case IPT_ICMP_HOST_PROHIBITED:
send_unreach(skb, ICMP_HOST_ANO);
break;
case IPT_ICMP_ADMIN_PROHIBITED:
send_unreach(skb, ICMP_PKT_FILTERED);
break;
case IPT_TCP_RESET:
send_reset(skb, par->hooknum);
case IPT_ICMP_ECHOREPLY:
break;
}
return NF_DROP;
}
static int reject_tg_check(const struct xt_tgchk_param *par)
{
const struct ipt_reject_info *rejinfo = par->targinfo;
const struct ipt_entry *e = par->entryinfo;
if (rejinfo->with == IPT_ICMP_ECHOREPLY) {
pr_info("ECHOREPLY no longer supported.\n");
return -EINVAL;
} else if (rejinfo->with == IPT_TCP_RESET) {
if (e->ip.proto != IPPROTO_TCP ||
(e->ip.invflags & XT_INV_PROTO)) {
pr_info("TCP_RESET invalid for non-tcp\n");
return -EINVAL;
}
}
return 0;
}
static int __init reject_tg_init(void)
{
return xt_register_target(&reject_tg_reg);
}
static void __exit reject_tg_exit(void)
{
xt_unregister_target(&reject_tg_reg);
}
