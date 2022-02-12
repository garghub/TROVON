static void
sctp_unique_tuple(const struct nf_nat_l3proto *l3proto,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_l4proto_unique_tuple(l3proto, tuple, range, maniptype, ct,
&nf_sctp_port_rover);
}
static bool
sctp_manip_pkt(struct sk_buff *skb,
const struct nf_nat_l3proto *l3proto,
unsigned int iphdroff, unsigned int hdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
struct sk_buff *frag;
sctp_sctphdr_t *hdr;
__be32 crc32;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
hdr = (struct sctphdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
hdr->source = tuple->src.u.sctp.port;
} else {
hdr->dest = tuple->dst.u.sctp.port;
}
crc32 = sctp_start_cksum((u8 *)hdr, skb_headlen(skb) - hdroff);
skb_walk_frags(skb, frag)
crc32 = sctp_update_cksum((u8 *)frag->data, skb_headlen(frag),
crc32);
crc32 = sctp_end_cksum(crc32);
hdr->checksum = crc32;
return true;
}
static int __init nf_nat_proto_sctp_init(void)
{
int err;
err = nf_nat_l4proto_register(NFPROTO_IPV4, &nf_nat_l4proto_sctp);
if (err < 0)
goto err1;
err = nf_nat_l4proto_register(NFPROTO_IPV6, &nf_nat_l4proto_sctp);
if (err < 0)
goto err2;
return 0;
err2:
nf_nat_l4proto_unregister(NFPROTO_IPV4, &nf_nat_l4proto_sctp);
err1:
return err;
}
static void __exit nf_nat_proto_sctp_exit(void)
{
nf_nat_l4proto_unregister(NFPROTO_IPV6, &nf_nat_l4proto_sctp);
nf_nat_l4proto_unregister(NFPROTO_IPV4, &nf_nat_l4proto_sctp);
}
