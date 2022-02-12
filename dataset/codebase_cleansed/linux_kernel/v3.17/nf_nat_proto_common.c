bool nf_nat_l4proto_in_range(const struct nf_conntrack_tuple *tuple,
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
void nf_nat_l4proto_unique_tuple(const struct nf_nat_l3proto *l3proto,
struct nf_conntrack_tuple *tuple,
const struct nf_nat_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct,
u16 *rover)
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
min = ntohs(range->min_proto.all);
range_size = ntohs(range->max_proto.all) - min + 1;
}
if (range->flags & NF_NAT_RANGE_PROTO_RANDOM) {
off = l3proto->secure_port(tuple, maniptype == NF_NAT_MANIP_SRC
? tuple->dst.u.all
: tuple->src.u.all);
} else if (range->flags & NF_NAT_RANGE_PROTO_RANDOM_FULLY) {
off = prandom_u32();
} else {
off = *rover;
}
for (i = 0; ; ++off) {
*portptr = htons(min + off % range_size);
if (++i != range_size && nf_nat_used_tuple(tuple, ct))
continue;
if (!(range->flags & NF_NAT_RANGE_PROTO_RANDOM_ALL))
*rover = off;
return;
}
}
int nf_nat_l4proto_nlattr_to_range(struct nlattr *tb[],
struct nf_nat_range *range)
{
if (tb[CTA_PROTONAT_PORT_MIN]) {
range->min_proto.all = nla_get_be16(tb[CTA_PROTONAT_PORT_MIN]);
range->max_proto.all = range->min_proto.all;
range->flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
if (tb[CTA_PROTONAT_PORT_MAX]) {
range->max_proto.all = nla_get_be16(tb[CTA_PROTONAT_PORT_MAX]);
range->flags |= NF_NAT_RANGE_PROTO_SPECIFIED;
}
return 0;
}
