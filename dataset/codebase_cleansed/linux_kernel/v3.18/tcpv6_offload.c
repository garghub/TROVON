static struct sk_buff **tcp6_gro_receive(struct sk_buff **head,
struct sk_buff *skb)
{
if (!NAPI_GRO_CB(skb)->flush &&
skb_gro_checksum_validate(skb, IPPROTO_TCP,
ip6_gro_compute_pseudo)) {
NAPI_GRO_CB(skb)->flush = 1;
return NULL;
}
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
struct sk_buff *tcp6_gso_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct tcphdr *th;
if (!pskb_may_pull(skb, sizeof(*th)))
return ERR_PTR(-EINVAL);
if (unlikely(skb->ip_summed != CHECKSUM_PARTIAL)) {
const struct ipv6hdr *ipv6h = ipv6_hdr(skb);
struct tcphdr *th = tcp_hdr(skb);
th->check = 0;
skb->ip_summed = CHECKSUM_PARTIAL;
__tcp_v6_send_check(skb, &ipv6h->saddr, &ipv6h->daddr);
}
return tcp_gso_segment(skb, features);
}
int __init tcpv6_offload_init(void)
{
return inet6_add_offload(&tcpv6_offload, IPPROTO_TCP);
}
