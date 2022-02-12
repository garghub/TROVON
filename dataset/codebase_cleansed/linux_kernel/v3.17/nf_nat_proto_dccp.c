static void
dccp_unique_tuple(const struct nf_nat_l3proto *l3proto,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_l4proto_unique_tuple(l3proto, tuple, range, maniptype, ct,
&dccp_port_rover);
}
static bool
dccp_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, unsigned int hdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
struct dccp_hdr *hdr;
__be16 *portptr, oldport, newport;
int hdrsize = 8;
if (skb->len >= hdroff + sizeof(struct dccp_hdr))
hdrsize = sizeof(struct dccp_hdr);
if (!skb_make_writable(skb, hdroff + hdrsize))
return false;
hdr = (struct dccp_hdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
newport = tuple->src.u.dccp.port;
portptr = &hdr->dccph_sport;
} else {
newport = tuple->dst.u.dccp.port;
portptr = &hdr->dccph_dport;
}
oldport = *portptr;
*portptr = newport;
if (hdrsize < sizeof(*hdr))
return true;
l3proto->csum_update(skb, iphdroff, &hdr->dccph_checksum,
tuple, maniptype);
inet_proto_csum_replace2(&hdr->dccph_checksum, skb, oldport, newport,
0);
return true;
}
static int __init nf_nat_proto_dccp_init(void)
{
int err;
err = nf_nat_l4proto_register(NFPROTO_IPV4, &nf_nat_l4proto_dccp);
if (err < 0)
goto err1;
err = nf_nat_l4proto_register(NFPROTO_IPV6, &nf_nat_l4proto_dccp);
if (err < 0)
goto err2;
return 0;
err2:
nf_nat_l4proto_unregister(NFPROTO_IPV4, &nf_nat_l4proto_dccp);
err1:
return err;
}
static void __exit nf_nat_proto_dccp_fini(void)
{
nf_nat_l4proto_unregister(NFPROTO_IPV6, &nf_nat_l4proto_dccp);
nf_nat_l4proto_unregister(NFPROTO_IPV4, &nf_nat_l4proto_dccp);
}
