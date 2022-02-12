static bool nf_generic_should_process(u8 proto)
{
switch (proto) {
#ifdef CONFIG_NF_CT_PROTO_SCTP_MODULE
case IPPROTO_SCTP:
return false;
#endif
#ifdef CONFIG_NF_CT_PROTO_DCCP_MODULE
case IPPROTO_DCCP:
return false;
#endif
#ifdef CONFIG_NF_CT_PROTO_GRE_MODULE
case IPPROTO_GRE:
return false;
#endif
#ifdef CONFIG_NF_CT_PROTO_UDPLITE_MODULE
case IPPROTO_UDPLITE:
return false;
#endif
default:
return true;
}
}
static inline struct nf_generic_net *generic_pernet(struct net *net)
{
return &net->ct.nf_ct_proto.generic;
}
static bool generic_pkt_to_tuple(const struct sk_buff *skb,
unsigned int dataoff,
struct net *net, struct nf_conntrack_tuple *tuple)
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
static void generic_print_tuple(struct seq_file *s,
const struct nf_conntrack_tuple *tuple)
{
}
static unsigned int *generic_get_timeouts(struct net *net)
{
return &(generic_pernet(net)->timeout);
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
bool ret;
ret = nf_generic_should_process(nf_ct_protonum(ct));
if (!ret)
pr_warn_once("conntrack: generic helper won't handle protocol %d. Please consider loading the specific helper module.\n",
nf_ct_protonum(ct));
return ret;
}
static int generic_timeout_nlattr_to_obj(struct nlattr *tb[],
struct net *net, void *data)
{
unsigned int *timeout = data;
struct nf_generic_net *gn = generic_pernet(net);
if (tb[CTA_TIMEOUT_GENERIC_TIMEOUT])
*timeout =
ntohl(nla_get_be32(tb[CTA_TIMEOUT_GENERIC_TIMEOUT])) * HZ;
else {
*timeout = gn->timeout;
}
return 0;
}
static int
generic_timeout_obj_to_nlattr(struct sk_buff *skb, const void *data)
{
const unsigned int *timeout = data;
if (nla_put_be32(skb, CTA_TIMEOUT_GENERIC_TIMEOUT, htonl(*timeout / HZ)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -ENOSPC;
}
static int generic_kmemdup_sysctl_table(struct nf_proto_net *pn,
struct nf_generic_net *gn)
{
#ifdef CONFIG_SYSCTL
pn->ctl_table = kmemdup(generic_sysctl_table,
sizeof(generic_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_table)
return -ENOMEM;
pn->ctl_table[0].data = &gn->timeout;
#endif
return 0;
}
static int generic_kmemdup_compat_sysctl_table(struct nf_proto_net *pn,
struct nf_generic_net *gn)
{
#ifdef CONFIG_SYSCTL
#ifdef CONFIG_NF_CONNTRACK_PROC_COMPAT
pn->ctl_compat_table = kmemdup(generic_compat_sysctl_table,
sizeof(generic_compat_sysctl_table),
GFP_KERNEL);
if (!pn->ctl_compat_table)
return -ENOMEM;
pn->ctl_compat_table[0].data = &gn->timeout;
#endif
#endif
return 0;
}
static int generic_init_net(struct net *net, u_int16_t proto)
{
int ret;
struct nf_generic_net *gn = generic_pernet(net);
struct nf_proto_net *pn = &gn->pn;
gn->timeout = nf_ct_generic_timeout;
ret = generic_kmemdup_compat_sysctl_table(pn, gn);
if (ret < 0)
return ret;
ret = generic_kmemdup_sysctl_table(pn, gn);
if (ret < 0)
nf_ct_kfree_compat_sysctl_table(pn);
return ret;
}
static struct nf_proto_net *generic_get_net_proto(struct net *net)
{
return &net->ct.nf_ct_proto.generic.pn;
}
