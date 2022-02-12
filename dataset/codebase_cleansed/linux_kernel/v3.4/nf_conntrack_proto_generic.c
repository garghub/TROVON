static bool generic_pkt_to_tuple(const struct sk_buff *skb,
unsigned int dataoff,
struct nf_conntrack_tuple *tuple)
{
tuple->src.u.all = 0;
tuple->dst.u.all = 0;
return true;
}
static bool generic_invert_tuple(struct nf_conntrack_tuple *tuple,
const struct nf_conntrack_tuple *orig)
{
tuple->src.u.all = 0;
tuple->dst.u.all = 0;
return true;
}
static int generic_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
return 0;
}
static unsigned int *generic_get_timeouts(struct net *net)
{
return &nf_ct_generic_timeout;
}
static int generic_packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum,
unsigned int *timeout)
{
nf_ct_refresh_acct(ct, ctinfo, skb, *timeout);
return NF_ACCEPT;
}
static bool generic_new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff, unsigned int *timeouts)
{
return true;
}
static int generic_timeout_nlattr_to_obj(struct nlattr *tb[], void *data)
{
unsigned int *timeout = data;
if (tb[CTA_TIMEOUT_GENERIC_TIMEOUT])
*timeout =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_GENERIC_TIMEOUT])) * HZ;
else {
*timeout = nf_ct_generic_timeout;
}
return 0;
}
static int
generic_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeout = data;
NLA_PUT_BE32(skb, CTA_TIMEOUT_GENERIC_TIMEOUT, htonl(*timeout / HZ));
return 0;
nla_put_failure:
return -ENOSPC;
}
