__sum16 csum_ipv6_magic(const struct in6_addr *saddr,
const struct in6_addr *daddr,
__u32 len, unsigned short proto,
__wsum csum)
{
int carry;
__u32 ulen;
__u32 uproto;
__u32 sum = (__force u32)csum;
sum += (__force u32)saddr->s6_addr32[0];
carry = (sum < (__force u32)saddr->s6_addr32[0]);
sum += carry;
sum += (__force u32)saddr->s6_addr32[1];
carry = (sum < (__force u32)saddr->s6_addr32[1]);
sum += carry;
sum += (__force u32)saddr->s6_addr32[2];
carry = (sum < (__force u32)saddr->s6_addr32[2]);
sum += carry;
sum += (__force u32)saddr->s6_addr32[3];
carry = (sum < (__force u32)saddr->s6_addr32[3]);
sum += carry;
sum += (__force u32)daddr->s6_addr32[0];
carry = (sum < (__force u32)daddr->s6_addr32[0]);
sum += carry;
sum += (__force u32)daddr->s6_addr32[1];
carry = (sum < (__force u32)daddr->s6_addr32[1]);
sum += carry;
sum += (__force u32)daddr->s6_addr32[2];
carry = (sum < (__force u32)daddr->s6_addr32[2]);
sum += carry;
sum += (__force u32)daddr->s6_addr32[3];
carry = (sum < (__force u32)daddr->s6_addr32[3]);
sum += carry;
ulen = (__force u32)htonl((__u32) len);
sum += ulen;
carry = (sum < ulen);
sum += carry;
uproto = (__force u32)htonl(proto);
sum += uproto;
carry = (sum < uproto);
sum += carry;
return csum_fold((__force __wsum)sum);
}
int udp6_csum_init(struct sk_buff *skb, struct udphdr *uh, int proto)
{
int err;
UDP_SKB_CB(skb)->partial_cov = 0;
UDP_SKB_CB(skb)->cscov = skb->len;
if (proto == IPPROTO_UDPLITE) {
err = udplite_checksum_init(skb, uh);
if (err)
return err;
}
if (uh->check == 0) {
LIMIT_NETDEBUG(KERN_INFO "IPv6: udp checksum is 0\n");
return 1;
}
if (skb->ip_summed == CHECKSUM_COMPLETE &&
!csum_ipv6_magic(&ipv6_hdr(skb)->saddr, &ipv6_hdr(skb)->daddr,
skb->len, proto, skb->csum))
skb->ip_summed = CHECKSUM_UNNECESSARY;
if (!skb_csum_unnecessary(skb))
skb->csum = ~csum_unfold(csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
skb->len, proto, 0));
return 0;
}
