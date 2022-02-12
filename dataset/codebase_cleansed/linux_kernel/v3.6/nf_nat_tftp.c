static unsigned int help(struct sk_buff *skb,
enum ip_conntrack_info ctinfo,
struct nf_conntrack_expect *exp)
{
const struct nf_conn *ct = exp->master;
exp->saved_proto.udp.port
= ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple.src.u.udp.port;
exp->dir = IP_CT_DIR_REPLY;
exp->expectfn = nf_nat_follow_master;
if (nf_ct_expect_related(exp) != 0)
return NF_DROP;
return NF_ACCEPT;
}
static void __exit nf_nat_tftp_fini(void)
{
RCU_INIT_POINTER(nf_nat_tftp_hook, NULL);
synchronize_rcu();
}
static int __init nf_nat_tftp_init(void)
{
BUG_ON(nf_nat_tftp_hook != NULL);
RCU_INIT_POINTER(nf_nat_tftp_hook, help);
return 0;
}
