static bool
icmp_in_range(const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype,
const union nf_conntrack_man_proto *min,
const union nf_conntrack_man_proto *max)
{
return ntohs(tuple->src.u.icmp.id) >= ntohs(min->icmp.id) &&
ntohs(tuple->src.u.icmp.id) <= ntohs(max->icmp.id);
}
static void
icmp_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_ipv4_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
static u_int16_t id;
unsigned int range_size;
unsigned int i;
range_size = ntohs(range->max.icmp.id) - ntohs(range->min.icmp.id) + 1;
if (!(range->flags & NF_NAT_RANGE_PROTO_SPECIFIED))
range_size = 0xFFFF;
for (i = 0; ; ++id) {
tuple->src.u.icmp.id = htons(ntohs(range->min.icmp.id) +
(id % range_size));
if (++i == range_size || !nf_nat_used_tuple(tuple, ct))
return;
}
return;
}
static bool
icmp_manip_pkt(struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
const struct iphdr *iph = (struct iphdr *)(skb->data + iphdroff);
struct icmphdr *hdr;
unsigned int hdroff = iphdroff + iph->ihl*4;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
hdr = (struct icmphdr *)(skb->data + hdroff);
inet_proto_csum_replace2(&hdr->checksum, skb,
hdr->un.echo.id, tuple->src.u.icmp.id, 0);
hdr->un.echo.id = tuple->src.u.icmp.id;
return true;
}
