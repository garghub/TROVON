bool ipv6_ext_hdr(u8 nexthdr)
{
return (nexthdr == NEXTHDR_HOP) ||
(nexthdr == NEXTHDR_ROUTING) ||
(nexthdr == NEXTHDR_FRAGMENT) ||
(nexthdr == NEXTHDR_AUTH) ||
(nexthdr == NEXTHDR_NONE) ||
(nexthdr == NEXTHDR_DEST);
}
int ipv6_skip_exthdr(const struct sk_buff *skb, int start, u8 *nexthdrp,
__be16 *frag_offp)
{
u8 nexthdr = *nexthdrp;
*frag_offp = 0;
while (ipv6_ext_hdr(nexthdr)) {
struct ipv6_opt_hdr _hdr, *hp;
int hdrlen;
if (nexthdr == NEXTHDR_NONE)
return -1;
hp = skb_header_pointer(skb, start, sizeof(_hdr), &_hdr);
if (!hp)
return -1;
if (nexthdr == NEXTHDR_FRAGMENT) {
__be16 _frag_off, *fp;
fp = skb_header_pointer(skb,
start+offsetof(struct frag_hdr,
frag_off),
sizeof(_frag_off),
&_frag_off);
if (!fp)
return -1;
*frag_offp = *fp;
if (ntohs(*frag_offp) & ~0x7)
break;
hdrlen = 8;
} else if (nexthdr == NEXTHDR_AUTH)
hdrlen = (hp->hdrlen+2)<<2;
else
hdrlen = ipv6_optlen(hp);
nexthdr = hp->nexthdr;
start += hdrlen;
}
*nexthdrp = nexthdr;
return start;
}
int ipv6_find_tlv(const struct sk_buff *skb, int offset, int type)
{
const unsigned char *nh = skb_network_header(skb);
int packet_len = skb_tail_pointer(skb) - skb_network_header(skb);
struct ipv6_opt_hdr *hdr;
int len;
if (offset + 2 > packet_len)
goto bad;
hdr = (struct ipv6_opt_hdr *)(nh + offset);
len = ((hdr->hdrlen + 1) << 3);
if (offset + len > packet_len)
goto bad;
offset += 2;
len -= 2;
while (len > 0) {
int opttype = nh[offset];
int optlen;
if (opttype == type)
return offset;
switch (opttype) {
case IPV6_TLV_PAD1:
optlen = 1;
break;
default:
optlen = nh[offset + 1] + 2;
if (optlen > len)
goto bad;
break;
}
offset += optlen;
len -= optlen;
}
bad:
return -1;
}
int ipv6_find_hdr(const struct sk_buff *skb, unsigned int *offset,
int target, unsigned short *fragoff, int *flags)
{
unsigned int start = skb_network_offset(skb) + sizeof(struct ipv6hdr);
u8 nexthdr = ipv6_hdr(skb)->nexthdr;
unsigned int len;
bool found;
if (fragoff)
*fragoff = 0;
if (*offset) {
struct ipv6hdr _ip6, *ip6;
ip6 = skb_header_pointer(skb, *offset, sizeof(_ip6), &_ip6);
if (!ip6 || (ip6->version != 6)) {
printk(KERN_ERR "IPv6 header not found\n");
return -EBADMSG;
}
start = *offset + sizeof(struct ipv6hdr);
nexthdr = ip6->nexthdr;
}
len = skb->len - start;
do {
struct ipv6_opt_hdr _hdr, *hp;
unsigned int hdrlen;
found = (nexthdr == target);
if ((!ipv6_ext_hdr(nexthdr)) || nexthdr == NEXTHDR_NONE) {
if (target < 0 || found)
break;
return -ENOENT;
}
hp = skb_header_pointer(skb, start, sizeof(_hdr), &_hdr);
if (!hp)
return -EBADMSG;
if (nexthdr == NEXTHDR_ROUTING) {
struct ipv6_rt_hdr _rh, *rh;
rh = skb_header_pointer(skb, start, sizeof(_rh),
&_rh);
if (!rh)
return -EBADMSG;
if (flags && (*flags & IP6_FH_F_SKIP_RH) &&
rh->segments_left == 0)
found = false;
}
if (nexthdr == NEXTHDR_FRAGMENT) {
unsigned short _frag_off;
__be16 *fp;
if (flags)
*flags |= IP6_FH_F_FRAG;
fp = skb_header_pointer(skb,
start+offsetof(struct frag_hdr,
frag_off),
sizeof(_frag_off),
&_frag_off);
if (!fp)
return -EBADMSG;
_frag_off = ntohs(*fp) & ~0x7;
if (_frag_off) {
if (target < 0 &&
((!ipv6_ext_hdr(hp->nexthdr)) ||
hp->nexthdr == NEXTHDR_NONE)) {
if (fragoff)
*fragoff = _frag_off;
return hp->nexthdr;
}
if (!found)
return -ENOENT;
if (fragoff)
*fragoff = _frag_off;
break;
}
hdrlen = 8;
} else if (nexthdr == NEXTHDR_AUTH) {
if (flags && (*flags & IP6_FH_F_AUTH) && (target < 0))
break;
hdrlen = (hp->hdrlen + 2) << 2;
} else
hdrlen = ipv6_optlen(hp);
if (!found) {
nexthdr = hp->nexthdr;
len -= hdrlen;
start += hdrlen;
}
} while (!found);
*offset = start;
return nexthdr;
}
