static int tcp_v6_gso_send_check(struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
struct tcphdr *th;
if (!pskb_may_pull(skb, sizeof(*th)))
return -EINVAL;
ipv6h = ipv6_hdr(skb);
th = tcp_hdr(skb);
th->check = 0;
skb->ip_summed = CHECKSUM_PARTIAL;
__tcp_v6_send_check(skb, &ipv6h->saddr, &ipv6h->daddr);
return 0;
}
static struct sk_buff **tcp6_gro_receive(struct sk_buff **head,
struct sk_buff *skb)
{
const struct ipv6hdr *iph = skb_gro_network_header(skb);
__wsum wsum;
if (NAPI_GRO_CB(skb)->flush)
goto skip_csum;
wsum = NAPI_GRO_CB(skb)->csum;
switch (skb->ip_summed) {
case CHECKSUM_NONE:
wsum = skb_checksum(skb, skb_gro_offset(skb), skb_gro_len(skb),
wsum);
case CHECKSUM_COMPLETE:
if (!tcp_v6_check(skb_gro_len(skb), &iph->saddr, &iph->daddr,
wsum)) {
skb->ip_summed = CHECKSUM_UNNECESSARY;
break;
}
NAPI_GRO_CB(skb)->flush = 1;
return NULL;
}
skip_csum:
return tcp_gro_receive(head, skb);
}
static int tcp6_gro_complete(struct sk_buff *skb, int thoff)
{
const struct ipv6hdr *iph = ipv6_hdr(skb);
struct tcphdr *th = tcp_hdr(skb);
th->check = ~tcp_v6_check(skb->len - thoff, &iph->saddr,
&iph->daddr, 0);
skb_shinfo(skb)->gso_type |= SKB_GSO_TCPV6;
return tcp_gro_complete(skb);
}
int __init tcpv6_offload_init(void)
{
return inet6_add_offload(&tcpv6_offload, IPPROTO_TCP);
}
