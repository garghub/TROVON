int xfrm4_extract_input(struct xfrm_state *x, struct sk_buff *skb)
{
return xfrm4_extract_header(skb);
}
static inline int xfrm4_rcv_encap_finish(struct sock *sk, struct sk_buff *skb)
{
if (!skb_dst(skb)) {
const struct iphdr *iph = ip_hdr(skb);
if (ip_route_input_noref(skb, iph->daddr, iph->saddr,
iph->tos, skb->dev))
goto drop;
}
return dst_input(skb);
drop:
kfree_skb(skb);
return NET_RX_DROP;
}
int xfrm4_transport_finish(struct sk_buff *skb, int async)
{
struct iphdr *iph = ip_hdr(skb);
iph->protocol = XFRM_MODE_SKB_CB(skb)->protocol;
#ifndef CONFIG_NETFILTER
if (!async)
return -iph->protocol;
#endif
__skb_push(skb, skb->data - skb_network_header(skb));
iph->tot_len = htons(skb->len);
ip_send_check(iph);
NF_HOOK(NFPROTO_IPV4, NF_INET_PRE_ROUTING, NULL, skb,
skb->dev, NULL,
xfrm4_rcv_encap_finish);
return 0;
}
int xfrm4_udp_encap_rcv(struct sock *sk, struct sk_buff *skb)
{
struct udp_sock *up = udp_sk(sk);
struct udphdr *uh;
struct iphdr *iph;
int iphlen, len;
__u8 *udpdata;
__be32 *udpdata32;
__u16 encap_type = up->encap_type;
if (!encap_type)
return 1;
len = skb->len - sizeof(struct udphdr);
if (!pskb_may_pull(skb, sizeof(struct udphdr) + min(len, 8)))
return 1;
uh = udp_hdr(skb);
udpdata = (__u8 *)uh + sizeof(struct udphdr);
udpdata32 = (__be32 *)udpdata;
switch (encap_type) {
default:
case UDP_ENCAP_ESPINUDP:
if (len == 1 && udpdata[0] == 0xff) {
goto drop;
} else if (len > sizeof(struct ip_esp_hdr) && udpdata32[0] != 0) {
len = sizeof(struct udphdr);
} else
return 1;
break;
case UDP_ENCAP_ESPINUDP_NON_IKE:
if (len == 1 && udpdata[0] == 0xff) {
goto drop;
} else if (len > 2 * sizeof(u32) + sizeof(struct ip_esp_hdr) &&
udpdata32[0] == 0 && udpdata32[1] == 0) {
len = sizeof(struct udphdr) + 2 * sizeof(u32);
} else
return 1;
break;
}
if (skb_unclone(skb, GFP_ATOMIC))
goto drop;
iph = ip_hdr(skb);
iphlen = iph->ihl << 2;
iph->tot_len = htons(ntohs(iph->tot_len) - len);
if (skb->len < iphlen + len) {
goto drop;
}
__skb_pull(skb, len);
skb_reset_transport_header(skb);
return xfrm4_rcv_encap(skb, IPPROTO_ESP, 0, encap_type);
drop:
kfree_skb(skb);
return 0;
}
int xfrm4_rcv(struct sk_buff *skb)
{
return xfrm4_rcv_spi(skb, ip_hdr(skb)->protocol, 0);
}
