static void
tcp_unique_tuple(const struct nf_nat_l3proto *l3proto,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_l4proto_unique_tuple(l3proto, tuple, range, maniptype, ct,
&tcp_port_rover);
}
static bool
tcp_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, unsigned int hdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
struct tcphdr *hdr;
__be16 *portptr, newport, oldport;
int hdrsize = 8;
if (skb->len >= hdroff + sizeof(struct tcphdr))
hdrsize = sizeof(struct tcphdr);
if (!skb_make_writable(skb, hdroff + hdrsize))
return false;
hdr = (struct tcphdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
newport = tuple->src.u.tcp.port;
portptr = &hdr->source;
} else {
newport = tuple->dst.u.tcp.port;
portptr = &hdr->dest;
}
oldport = *portptr;
*portptr = newport;
if (hdrsize < sizeof(*hdr))
return true;
l3proto->csum_update(skb, iphdroff, &hdr->check, tuple, maniptype);
inet_proto_csum_replace2(&hdr->check, skb, oldport, newport, 0);
return true;
}
