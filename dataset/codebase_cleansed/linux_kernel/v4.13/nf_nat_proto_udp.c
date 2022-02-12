static void
udp_unique_tuple(const struct nf_nat_l3proto *l3proto,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_l4proto_unique_tuple(l3proto, tuple, range, maniptype, ct,
&udp_port_rover);
}
static void
__udp_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, struct udphdr *hdr,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype, bool do_csum)
{
__be16 *portptr, newport;
if (maniptype == NF_NAT_MANIP_SRC) {
newport = tuple->src.u.udp.port;
portptr = &hdr->source;
} else {
newport = tuple->dst.u.udp.port;
portptr = &hdr->dest;
}
if (do_csum) {
l3proto->csum_update(skb, iphdroff, &hdr->check,
tuple, maniptype);
inet_proto_csum_replace2(&hdr->check, skb, *portptr, newport,
false);
if (!hdr->check)
hdr->check = CSUM_MANGLED_0;
}
*portptr = newport;
}
static bool udp_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, unsigned int hdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
struct udphdr *hdr;
bool do_csum;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
hdr = (struct udphdr *)(skb->data + hdroff);
do_csum = hdr->check || skb->ip_summed == CHECKSUM_PARTIAL;
__udp_manip_pkt(skb, l3proto, iphdroff, hdr, tuple, maniptype, do_csum);
return true;
}
static bool udplite_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, unsigned int hdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
struct udphdr *hdr;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
hdr = (struct udphdr *)(skb->data + hdroff);
__udp_manip_pkt(skb, l3proto, iphdroff, hdr, tuple, maniptype, true);
return true;
}
static void
udplite_unique_tuple(const struct nf_nat_l3proto *l3proto,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_l4proto_unique_tuple(l3proto, tuple, range, maniptype, ct,
&udplite_port_rover);
}
