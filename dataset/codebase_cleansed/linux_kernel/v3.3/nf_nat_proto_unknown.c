static bool unknown_in_range(const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type manip_type,
const union nf_conntrack_man_proto *min,
const union nf_conntrack_man_proto *max)
{
return true;
}
static void unknown_unique_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_nat_ipv4_range *range,
enum nf_nat_manip_type maniptype,
const struct nf_conn *ct)
{
return;
}
static bool
unknown_manip_pkt(struct sk_buff *skb,
unsigned int iphdroff,
const struct nf_conntrack_tuple *tuple,
enum nf_nat_manip_type maniptype)
{
return true;
}
