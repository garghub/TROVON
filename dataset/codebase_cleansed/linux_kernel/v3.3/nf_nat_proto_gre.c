static void
gre_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_ipv4_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
static u_int16_t key;
__be16 *keyptr;
unsigned int min, i, range_size;
if (!ct->master)
return;
if (maniptype == NF_NAT_MANIP_SRC)
keyptr = &tuple->src.u.gre.key;
else
keyptr = &tuple->dst.u.gre.key;
if (!(range->flags & NF_NAT_RANGE_PROTO_SPECIFIED)) {
pr_debug("%p: NATing GRE PPTP\n", ct);
min = 1;
range_size = 0xffff;
} else {
min = ntohs(range->min.gre.key);
range_size = ntohs(range->max.gre.key) - min + 1;
}
pr_debug("min = %u, range_size = %u\n", min, range_size);
for (i = 0; ; ++key) {
*keyptr = htons(min + key % range_size);
if (++i == range_size || !nf_nat_used_tuple(tuple, ct))
return;
}
pr_debug("%p: no NAT mapping\n", ct);
return;
}
static bool
gre_manip_pkt(struct sk_buff *skb, unsigned int iphdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
const struct gre_hdr *greh;
struct gre_hdr_pptp *pgreh;
const struct iphdr *iph = (struct iphdr *)(skb->data + iphdroff);
unsigned int hdroff = iphdroff + iph->ihl * 4;
if (!skb_make_writable(skb, hdroff + sizeof(*pgreh) - 8))
return false;
greh = (void *)skb->data + hdroff;
pgreh = (struct gre_hdr_pptp *)greh;
if (maniptype != NF_NAT_MANIP_DST)
return true;
switch (greh->version) {
case GRE_VERSION_1701:
break;
case GRE_VERSION_PPTP:
pr_debug("call_id -> 0x%04x\n", ntohs(tuple->dst.u.gre.key));
pgreh->call_id = tuple->dst.u.gre.key;
break;
default:
pr_debug("can't nat unknown GRE version\n");
return false;
}
return true;
}
static int __init nf_nat_proto_gre_init(void)
{
return nf_nat_protocol_register(&gre);
}
static void __exit nf_nat_proto_gre_fini(void)
{
nf_nat_protocol_unregister(&gre);
}
void nf_nat_need_gre(void)
{
return;
}
