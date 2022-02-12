static void
udplite_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_ipv4_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_proto_unique_tuple(tuple, range, maniptype, ct,
&udplite_port_rover);
}
static bool
udplite_manip_pkt(struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
const struct iphdr *iph = (struct iphdr *)(skb->data + iphdroff);
struct udphdr *hdr;
unsigned int hdroff = iphdroff + iph->ihl*4;
__be32 oldip, newip;
__be16 *portptr, newport;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
iph = (struct iphdr *)(skb->data + iphdroff);
hdr = (struct udphdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
oldip = iph->saddr;
newip = tuple->src.u3.ip;
newport = tuple->src.u.udp.port;
portptr = &hdr->source;
} else {
oldip = iph->daddr;
newip = tuple->dst.u3.ip;
newport = tuple->dst.u.udp.port;
portptr = &hdr->dest;
}
inet_proto_csum_replace4(&hdr->check, skb, oldip, newip, 1);
inet_proto_csum_replace2(&hdr->check, skb, *portptr, newport, 0);
if (!hdr->check)
hdr->check = CSUM_MANGLED_0;
*portptr = newport;
return true;
}
static int __init nf_nat_proto_udplite_init(void)
{
return nf_nat_protocol_register(&nf_nat_protocol_udplite);
}
static void __exit nf_nat_proto_udplite_fini(void)
{
nf_nat_protocol_unregister(&nf_nat_protocol_udplite);
}
