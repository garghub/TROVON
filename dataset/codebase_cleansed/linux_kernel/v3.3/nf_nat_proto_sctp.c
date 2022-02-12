static void
sctp_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_ipv4_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
nf_nat_proto_unique_tuple(tuple, range, maniptype, ct,
&nf_sctp_port_rover);
}
static bool
sctp_manip_pkt(struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
const struct iphdr *iph = (struct iphdr *)(skb->data + iphdroff);
struct sk_buff *frag;
sctp_sctphdr_t *hdr;
unsigned int hdroff = iphdroff + iph->ihl*4;
__be32 oldip, newip;
__be32 crc32;
if (!skb_make_writable(skb, hdroff + sizeof(*hdr)))
return false;
iph = (struct iphdr *)(skb->data + iphdroff);
hdr = (struct sctphdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
oldip = iph->saddr;
newip = tuple->src.u3.ip;
hdr->source = tuple->src.u.sctp.port;
} else {
oldip = iph->daddr;
newip = tuple->dst.u3.ip;
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
return nf_nat_protocol_register(&nf_nat_protocol_sctp);
}
static void __exit nf_nat_proto_sctp_exit(void)
{
nf_nat_protocol_unregister(&nf_nat_protocol_sctp);
}
