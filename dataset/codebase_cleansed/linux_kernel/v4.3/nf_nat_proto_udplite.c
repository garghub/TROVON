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
static bool
udplite_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, unsigned int hdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
struct udphdr *hdr;
__be16 *portptr, newport;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
hdr = (struct udphdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
newport = tuple->src.u.udp.port;
portptr = &hdr->source;
} else {
newport = tuple->dst.u.udp.port;
portptr = &hdr->dest;
}
l3proto->csum_update(skb, iphdroff, &hdr->check, tuple, maniptype);
inet_proto_csum_replace2(&hdr->check, skb, *portptr, newport, false);
if (!hdr->check)
hdr->check = CSUM_MANGLED_0;
*portptr = newport;
return true;
}
static int __init nf_nat_proto_udplite_init(void)
{
int err;
err = nf_nat_l4proto_register(NFPROTO_IPV4, &nf_nat_l4proto_udplite);
if (err < 0)
goto err1;
err = nf_nat_l4proto_register(NFPROTO_IPV6, &nf_nat_l4proto_udplite);
if (err < 0)
goto err2;
return 0;
err2:
nf_nat_l4proto_unregister(NFPROTO_IPV4, &nf_nat_l4proto_udplite);
err1:
return err;
}
static void __exit nf_nat_proto_udplite_fini(void)
{
nf_nat_l4proto_unregister(NFPROTO_IPV6, &nf_nat_l4proto_udplite);
nf_nat_l4proto_unregister(NFPROTO_IPV4, &nf_nat_l4proto_udplite);
}
