bool nf_nat_proto_in_range(const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype,
const union nf_conntrack_man_proto *min,
const union nf_conntrack_man_proto *max)
{
__be16 port;
if (maniptype == NF_NAT_MANIP_SRC)
port = tuple->src.u.all;
else
port = tuple->dst.u.all;
return ntohs(port) >= ntohs(min->all) &&
ntohs(port) <= ntohs(max->all);
}
void nf_nat_proto_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_ipv4_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct,
u_int16_t *rover)
{
unsigned int range_size, min, i;
__be16 *portptr;
u_int16_t off;
if (maniptype == NF_NAT_MANIP_SRC)
portptr = &tuple->src.u.all;
else
portptr = &tuple->dst.u.all;
if (!(range->flags & NF_NAT_RANGE_PROTO_SPECIFIED)) {
if (maniptype == NF_NAT_MANIP_DST)
return;
if (ntohs(*portptr) < 1024) {
if (ntohs(*portptr) < 512) {
min = 1;
range_size = 511 - min + 1;
} else {
min = 600;
range_size = 1023 - min + 1;
}
} else {
min = 1024;
range_size = 65535 - 1024 + 1;
}
} else {
min = ntohs(range->min.all);
range_size = ntohs(range->max.all) - min + 1;
}
if (range->flags & NF_NAT_RANGE_PROTO_RANDOM)
off = secure_ipv4_port_ephemeral(tuple->src.u3.ip, tuple->dst.u3.ip,
maniptype == NF_NAT_MANIP_SRC
? tuple->dst.u.all
: tuple->src.u.all);
else
off = *rover;
for (i = 0; ; ++off) {
*portptr = htons(min + off % range_size);
if (++i != range_size && nf_nat_used_tuple(tuple, ct))
continue;
if (!(range->flags & NF_NAT_RANGE_PROTO_RANDOM))
*rover = off;
return;
}
return;
}
int nf_nat_proto_nlattr_to_range(struct nlattr *tb[],
struct nf_nat_ipv4_range *range)
{
if (tb[CTA_PROTONAT_PORT_MIN]) {
range->min.all = nla_get_be16(tb[CTA_PROTONAT_PORT_MIN]);
range->max.all = range->min.tcp.port;
range->flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
if (tb[CTA_PROTONAT_PORT_MAX]) {
range->max.all = nla_get_be16(tb[CTA_PROTONAT_PORT_MAX]);
range->flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
return 0;
}
