static void nf_nat_ipv6_decode_session(struct sk_buff *skb,
const struct nf_conn *ct,
enum ip_conntrack_dir dir,
unsigned long statusbit,
struct flowi *fl)
{
const struct nf_conntrack_tuple *t = &ct->tuplehash[dir].tuple;
struct flowi6 *fl6 = &fl->u.ip6;
if (ct->status & statusbit) {
fl6->daddr = t->dst.u3.in6;
if (t->dst.protonum == IPPROTO_TCP ||
t->dst.protonum == IPPROTO_UDP ||
t->dst.protonum == IPPROTO_UDPLITE ||
t->dst.protonum == IPPROTO_DCCP ||
t->dst.protonum == IPPROTO_SCTP)
fl6->fl6_dport = t->dst.u.all;
}
statusbit ^= IPS_NAT_MASK;
if (ct->status & statusbit) {
fl6->saddr = t->src.u3.in6;
if (t->dst.protonum == IPPROTO_TCP ||
t->dst.protonum == IPPROTO_UDP ||
t->dst.protonum == IPPROTO_UDPLITE ||
t->dst.protonum == IPPROTO_DCCP ||
t->dst.protonum == IPPROTO_SCTP)
fl6->fl6_sport = t->src.u.all;
}
}
static bool nf_nat_ipv6_in_range(const struct nf_conntrack_tuple *t,
const struct nf_nat_range *range)
{
return ipv6_addr_cmp(&t->src.u3.in6, &range->min_addr.in6) >= 0 &&
ipv6_addr_cmp(&t->src.u3.in6, &range->max_addr.in6) <= 0;
}
static u32 nf_nat_ipv6_secure_port(const struct nf_conntrack_tuple *t,
__be16 dport)
{
return secure_ipv6_port_ephemeral(t->src.u3.ip6, t->dst.u3.ip6, dport);
}
static bool nf_nat_ipv6_manip_pkt(struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_nat_l4proto *l4proto,
const struct nf_conntrack_tuple *target,
enum nf_nat_manip_type maniptype)
{
struct ipv6hdr *ipv6h;
__be16 frag_off;
int hdroff;
u8 nexthdr;
if (!skb_make_writable(skb, iphdroff + sizeof(*ipv6h)))
return false;
ipv6h = (void *)skb->data + iphdroff;
nexthdr = ipv6h->nexthdr;
hdroff = ipv6_skip_exthdr(skb, iphdroff + sizeof(*ipv6h),
&nexthdr, &frag_off);
if (hdroff < 0)
goto manip_addr;
if ((frag_off & htons(~0x7)) == 0 &&
!l4proto->manip_pkt(skb, &nf_nat_l3proto_ipv6, iphdroff, hdroff,
target, maniptype))
return false;
manip_addr:
if (maniptype == NF_NAT_MANIP_SRC)
ipv6h->saddr = target->src.u3.in6;
else
ipv6h->daddr = target->dst.u3.in6;
return true;
}
static void nf_nat_ipv6_csum_update(struct sk_buff *skb,
unsigned int iphdroff, __sum16 *check,
const struct nf_conntrack_tuple *t,
enum nf_nat_manip_type maniptype)
{
const struct ipv6hdr *ipv6h = (struct ipv6hdr *)(skb->data + iphdroff);
const struct in6_addr *oldip, *newip;
if (maniptype == NF_NAT_MANIP_SRC) {
oldip = &ipv6h->saddr;
newip = &t->src.u3.in6;
} else {
oldip = &ipv6h->daddr;
newip = &t->dst.u3.in6;
}
inet_proto_csum_replace16(check, skb, oldip->s6_addr32,
newip->s6_addr32, true);
}
static void nf_nat_ipv6_csum_recalc(struct sk_buff *skb,
u8 proto, void *data, __sum16 *check,
int datalen, int oldlen)
{
if (skb->ip_summed != CHECKSUM_PARTIAL) {
const struct ipv6hdr *ipv6h = ipv6_hdr(skb);
skb->ip_summed = CHECKSUM_PARTIAL;
skb->csum_start = skb_headroom(skb) + skb_network_offset(skb) +
(data - (void *)skb->data);
skb->csum_offset = (void *)check - data;
*check = ~csum_ipv6_magic(&ipv6h->saddr, &ipv6h->daddr,
datalen, proto, 0);
} else
inet_proto_csum_replace2(check, skb,
htons(oldlen), htons(datalen), true);
}
static int nf_nat_ipv6_nlattr_to_range(struct nlattr *tb[],
struct nf_nat_range *range)
{
if (tb[CTA_NAT_V6_MINIP]) {
nla_memcpy(&range->min_addr.ip6, tb[CTA_NAT_V6_MINIP],
sizeof(struct in6_addr));
range->flags |= NF_NAT_RANGE_MAP_IPS;
}
if (tb[CTA_NAT_V6_MAXIP])
nla_memcpy(&range->max_addr.ip6, tb[CTA_NAT_V6_MAXIP],
sizeof(struct in6_addr));
else
range->max_addr = range->min_addr;
return 0;
}
int nf_nat_icmpv6_reply_translation(struct sk_buff *skb,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo,
unsigned int hooknum,
unsigned int hdrlen)
{
struct {
struct icmp6hdr icmp6;
struct ipv6hdr ip6;
} *inside;
enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
enum nf_nat_manip_type manip = HOOK2MANIP(hooknum);
const struct nf_nat_l4proto *l4proto;
struct nf_conntrack_tuple target;
unsigned long statusbit;
WARN_ON(ctinfo != IP_CT_RELATED && ctinfo != IP_CT_RELATED_REPLY);
if (!skb_make_writable(skb, hdrlen + sizeof(*inside)))
return 0;
if (nf_ip6_checksum(skb, hooknum, hdrlen, IPPROTO_ICMPV6))
return 0;
inside = (void *)skb->data + hdrlen;
if (inside->icmp6.icmp6_type == NDISC_REDIRECT) {
if ((ct->status & IPS_NAT_DONE_MASK) != IPS_NAT_DONE_MASK)
return 0;
if (ct->status & IPS_NAT_MASK)
return 0;
}
if (manip == NF_NAT_MANIP_SRC)
statusbit = IPS_SRC_NAT;
else
statusbit = IPS_DST_NAT;
if (dir == IP_CT_DIR_REPLY)
statusbit ^= IPS_NAT_MASK;
if (!(ct->status & statusbit))
return 1;
l4proto = __nf_nat_l4proto_find(NFPROTO_IPV6, inside->ip6.nexthdr);
if (!nf_nat_ipv6_manip_pkt(skb, hdrlen + sizeof(inside->icmp6),
l4proto, &ct->tuplehash[!dir].tuple, !manip))
return 0;
if (skb->ip_summed != CHECKSUM_PARTIAL) {
struct ipv6hdr *ipv6h = ipv6_hdr(skb);
inside = (void *)skb->data + hdrlen;
inside->icmp6.icmp6_cksum = 0;
inside->icmp6.icmp6_cksum =
csum_ipv6_magic(&ipv6h->saddr, &ipv6h->daddr,
skb->len - hdrlen, IPPROTO_ICMPV6,
skb_checksum(skb, hdrlen,
skb->len - hdrlen, 0));
}
nf_ct_invert_tuplepr(&target, &ct->tuplehash[!dir].tuple);
l4proto = __nf_nat_l4proto_find(NFPROTO_IPV6, IPPROTO_ICMPV6);
if (!nf_nat_ipv6_manip_pkt(skb, 0, l4proto, &target, manip))
return 0;
return 1;
}
static int __init nf_nat_l3proto_ipv6_init(void)
{
int err;
err = nf_nat_l4proto_register(NFPROTO_IPV6, &nf_nat_l4proto_icmpv6);
if (err < 0)
goto err1;
err = nf_nat_l3proto_register(&nf_nat_l3proto_ipv6);
if (err < 0)
goto err2;
return err;
err2:
nf_nat_l4proto_unregister(NFPROTO_IPV6, &nf_nat_l4proto_icmpv6);
err1:
return err;
}
static void __exit nf_nat_l3proto_ipv6_exit(void)
{
nf_nat_l3proto_unregister(&nf_nat_l3proto_ipv6);
nf_nat_l4proto_unregister(NFPROTO_IPV6, &nf_nat_l4proto_icmpv6);
}
