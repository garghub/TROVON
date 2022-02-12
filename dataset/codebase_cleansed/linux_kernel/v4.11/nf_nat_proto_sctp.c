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
sctp_sctphdr_t *hdr;
int hdrsize = 8;
if (skb->len >= hdroff + sizeof(*hdr))
hdrsize = sizeof(*hdr);
if (!skb_make_writable(skb, hdroff + hdrsize))
return false;
hdr = (struct sctphdr *)(skb->data + hdroff);
if (maniptype == NF_NAT_MANIP_SRC) {
hdr->source = tuple->src.u.sctp.port;
} else {
hdr->dest = tuple->dst.u.sctp.port;
}
if (hdrsize < sizeof(*hdr))
return true;
if (skb->ip_summed != CHECKSUM_PARTIAL) {
hdr->checksum = sctp_compute_cksum(skb, hdroff);
skb->ip_summed = CHECKSUM_NONE;
}
return true;
}
