static int udp6_ufo_send_check(struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
struct udphdr *uh;
if (skb->encapsulation)
return -EINVAL;
if (!pskb_may_pull(skb, sizeof(*uh)))
return -EINVAL;
ipv6h = ipv6_hdr(skb);
uh = udp_hdr(skb);
uh->check = ~csum_ipv6_magic(&ipv6h->saddr, &ipv6h->daddr, skb->len,
IPPROTO_UDP, 0);
skb->csum_start = skb_transport_header(skb) - skb->head;
skb->csum_offset = offsetof(struct udphdr, check);
skb->ip_summed = CHECKSUM_PARTIAL;
return 0;
}
static struct sk_buff *udp6_ufo_fragment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
unsigned int mss;
unsigned int unfrag_ip6hlen, unfrag_len;
struct frag_hdr *fptr;
u8 *packet_start, *prevhdr;
u8 nexthdr;
u8 frag_hdr_sz = sizeof(struct frag_hdr);
int offset;
__wsum csum;
int tnl_hlen;
mss = skb_shinfo(skb)->gso_size;
if (unlikely(skb->len <= mss))
goto out;
if (skb_gso_ok(skb, features | NETIF_F_GSO_ROBUST)) {
int type = skb_shinfo(skb)->gso_type;
if (unlikely(type & ~(SKB_GSO_UDP |
SKB_GSO_DODGY |
SKB_GSO_UDP_TUNNEL |
SKB_GSO_GRE) ||
!(type & (SKB_GSO_UDP))))
goto out;
skb_shinfo(skb)->gso_segs = DIV_ROUND_UP(skb->len, mss);
segs = NULL;
goto out;
}
offset = skb_checksum_start_offset(skb);
csum = skb_checksum(skb, offset, skb->len - offset, 0);
offset += skb->csum_offset;
*(__sum16 *)(skb->data + offset) = csum_fold(csum);
skb->ip_summed = CHECKSUM_NONE;
tnl_hlen = skb_tnl_header_len(skb);
if (skb_headroom(skb) < (tnl_hlen + frag_hdr_sz)) {
if (gso_pskb_expand_head(skb, tnl_hlen + frag_hdr_sz))
goto out;
}
unfrag_ip6hlen = ip6_find_1stfragopt(skb, &prevhdr);
nexthdr = *prevhdr;
*prevhdr = NEXTHDR_FRAGMENT;
unfrag_len = (skb_network_header(skb) - skb_mac_header(skb)) +
unfrag_ip6hlen + tnl_hlen;
packet_start = (u8 *) skb->head + SKB_GSO_CB(skb)->mac_offset;
memmove(packet_start-frag_hdr_sz, packet_start, unfrag_len);
SKB_GSO_CB(skb)->mac_offset -= frag_hdr_sz;
skb->mac_header -= frag_hdr_sz;
skb->network_header -= frag_hdr_sz;
fptr = (struct frag_hdr *)(skb_network_header(skb) + unfrag_ip6hlen);
fptr->nexthdr = nexthdr;
fptr->reserved = 0;
ipv6_select_ident(fptr, (struct rt6_info *)skb_dst(skb));
segs = skb_segment(skb, features);
out:
return segs;
}
int __init udp_offload_init(void)
{
return inet6_add_offload(&udpv6_offload, IPPROTO_UDP);
}
