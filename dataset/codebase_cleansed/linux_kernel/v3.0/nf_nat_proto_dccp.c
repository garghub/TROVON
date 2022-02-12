static void
dccp_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_proto_unique_tuple(tuple, range, maniptype, ct,
&dccp_port_rover);
}
static bool
dccp_manip_pkt(struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
const struct iphdr *iph = (const void *)(skb->data + iphdroff);
struct dccp_hdr *hdr;
unsigned int hdroff = iphdroff + iph->ihl * 4;
__be32 oldip, newip;
__be16 *portptr, oldport, newport;
int hdrsize = 8;
if (skb->len >= hdroff + sizeof(struct dccp_hdr))
hdrsize = sizeof(struct dccp_hdr);
if (!skb_make_writable(skb, hdroff + hdrsize))
return false;
iph = (struct iphdr *)(skb->data + iphdroff);
hdr = (struct dccp_hdr *)(skb->data + hdroff);
if (maniptype == IP_NAT_MANIP_SRC) {
oldip = iph->saddr;
newip = tuple->src.u3.ip;
newport = tuple->src.u.dccp.port;
portptr = &hdr->dccph_sport;
} else {
oldip = iph->daddr;
newip = tuple->dst.u3.ip;
newport = tuple->dst.u.dccp.port;
portptr = &hdr->dccph_dport;
}
oldport = *portptr;
*portptr = newport;
if (hdrsize < sizeof(*hdr))
return true;
inet_proto_csum_replace4(&hdr->dccph_checksum, skb, oldip, newip, 1);
inet_proto_csum_replace2(&hdr->dccph_checksum, skb, oldport, newport,
0);
return true;
}
static int __init nf_nat_proto_dccp_init(void)
{
return nf_nat_protocol_register(&nf_nat_protocol_dccp);
}
static void __exit nf_nat_proto_dccp_fini(void)
{
nf_nat_protocol_unregister(&nf_nat_protocol_dccp);
}
