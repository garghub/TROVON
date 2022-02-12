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
static int packet(struct nf_conn *ct,
const struct sk_buff *skb,
unsigned int dataoff,
enum ip_conntrack_info ctinfo,
u_int8_t pf,
unsigned int hooknum)
{
nf_ct_refresh_acct(ct, ctinfo, skb, nf_ct_generic_timeout);
return NF_ACCEPT;
}
static bool new(struct nf_conn *ct, const struct sk_buff *skb,
unsigned int dataoff)
{
return true;
}
