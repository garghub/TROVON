static int udp4_ufo_send_check(struct sk_buff *skb)
{
if (!pskb_may_pull(skb, sizeof(struct udphdr)))
return -EINVAL;
if (likely(!skb->encapsulation)) {
const struct iphdr *iph;
struct udphdr *uh;
iph = ip_hdr(skb);
uh = udp_hdr(skb);
uh->check = ~csum_tcpudp_magic(iph->saddr, iph->daddr, skb->len,
IPPROTO_UDP, 0);
skb->csum_start = skb_transport_header(skb) - skb->head;
skb->csum_offset = offsetof(struct udphdr, check);
skb->ip_summed = CHECKSUM_PARTIAL;
}
return 0;
}
static struct sk_buff *udp4_ufo_fragment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
unsigned int mss;
mss = skb_shinfo(skb)->gso_size;
if (unlikely(skb->len <= mss))
goto out;
if (skb_gso_ok(skb, features | NETIF_F_GSO_ROBUST)) {
int type = skb_shinfo(skb)->gso_type;
if (unlikely(type & ~(SKB_GSO_UDP | SKB_GSO_DODGY |
SKB_GSO_UDP_TUNNEL |
SKB_GSO_GRE | SKB_GSO_MPLS) ||
!(type & (SKB_GSO_UDP))))
goto out;
skb_shinfo(skb)->gso_segs = DIV_ROUND_UP(skb->len, mss);
segs = NULL;
goto out;
}
if (skb->encapsulation && skb_shinfo(skb)->gso_type & SKB_GSO_UDP_TUNNEL)
segs = skb_udp_tunnel_segment(skb, features);
else {
int offset;
__wsum csum;
offset = skb_checksum_start_offset(skb);
csum = skb_checksum(skb, offset, skb->len - offset, 0);
offset += skb->csum_offset;
*(__sum16 *)(skb->data + offset) = csum_fold(csum);
skb->ip_summed = CHECKSUM_NONE;
segs = skb_segment(skb, features);
}
out:
return segs;
}
int __init udpv4_offload_init(void)
{
return inet_add_offload(&udpv4_offload, IPPROTO_UDP);
}
