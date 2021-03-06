static int udp6_ufo_send_check(struct sk_buff *skb)
{
const struct ipv6hdr *ipv6h;
struct udphdr *uh;
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
u8 *mac_start, *prevhdr;
u8 nexthdr;
u8 frag_hdr_sz = sizeof(struct frag_hdr);
int offset;
__wsum csum;
mss = skb_shinfo(skb)->gso_size;
if (unlikely(skb->len <= mss))
goto out;
if (skb_gso_ok(skb, features | NETIF_F_GSO_ROBUST)) {
int type = skb_shinfo(skb)->gso_type;
if (unlikely(type & ~(SKB_GSO_UDP | SKB_GSO_DODGY) ||
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
if ((skb_mac_header(skb) < skb->head + frag_hdr_sz) &&
pskb_expand_head(skb, frag_hdr_sz, 0, GFP_ATOMIC))
goto out;
unfrag_ip6hlen = ip6_find_1stfragopt(skb, &prevhdr);
nexthdr = *prevhdr;
*prevhdr = NEXTHDR_FRAGMENT;
unfrag_len = skb_network_header(skb) - skb_mac_header(skb) +
unfrag_ip6hlen;
mac_start = skb_mac_header(skb);
memmove(mac_start-frag_hdr_sz, mac_start, unfrag_len);
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
