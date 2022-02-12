static unsigned int
ipt_snat_target(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
NF_CT_ASSERT(par->hooknum == NF_INET_POST_ROUTING ||
par->hooknum == NF_INET_LOCAL_IN);
ct = nf_ct_get(skb, &ctinfo);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED ||
ctinfo == IP_CT_RELATED_REPLY));
NF_CT_ASSERT(par->out != NULL);
return nf_nat_setup_info(ct, &mr->range[0], NF_NAT_MANIP_SRC);
}
static unsigned int
ipt_dnat_target(struct sk_buff *skb, const struct xt_action_param *par)
{
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
NF_CT_ASSERT(par->hooknum == NF_INET_PRE_ROUTING ||
par->hooknum == NF_INET_LOCAL_OUT);
ct = nf_ct_get(skb, &ctinfo);
NF_CT_ASSERT(ct && (ctinfo == IP_CT_NEW || ctinfo == IP_CT_RELATED));
return nf_nat_setup_info(ct, &mr->range[0], NF_NAT_MANIP_DST);
}
static int ipt_snat_checkentry(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->rangesize != 1) {
pr_info("SNAT: multiple ranges no longer supported\n");
return -EINVAL;
}
return 0;
}
static int ipt_dnat_checkentry(const struct xt_tgchk_param *par)
{
const struct nf_nat_ipv4_multi_range_compat *mr = par->targinfo;
if (mr->rangesize != 1) {
pr_info("DNAT: multiple ranges no longer supported\n");
return -EINVAL;
}
return 0;
}
static unsigned int
alloc_null_binding(struct nf_conn *ct, unsigned int hooknum)
{
struct nf_nat_ipv4_range range;
range.flags = 0;
pr_debug("Allocating NULL binding for %p (%pI4)\n", ct,
HOOK2MANIP(hooknum) == NF_NAT_MANIP_SRC ?
&ct->tuplehash[IP_CT_DIR_REPLY].tuple.dst.u3.ip :
&ct->tuplehash[IP_CT_DIR_REPLY].tuple.src.u3.ip);
return nf_nat_setup_info(ct, &range, HOOK2MANIP(hooknum));
}
int nf_nat_rule_find(struct sk_buff *skb,
unsigned int hooknum,
const struct net_device *in,
const struct net_device *out,
struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
int ret;
ret = ipt_do_table(skb, hooknum, in, out, net->ipv4.nat_table);
if (ret == NF_ACCEPT) {
if (!nf_nat_initialized(ct, HOOK2MANIP(hooknum)))
ret = alloc_null_binding(ct, hooknum);
}
return ret;
}
static int __net_init nf_nat_rule_net_init(struct net *net)
{
struct ipt_replace *repl;
repl = ipt_alloc_initial_table(&nat_table);
if (repl == NULL)
return -ENOMEM;
net->ipv4.nat_table = ipt_register_table(net, &nat_table, repl);
kfree(repl);
if (IS_ERR(net->ipv4.nat_table))
return PTR_ERR(net->ipv4.nat_table);
return 0;
}
static void __net_exit nf_nat_rule_net_exit(struct net *net)
{
ipt_unregister_table(net, net->ipv4.nat_table);
}
int __init nf_nat_rule_init(void)
{
int ret;
ret = register_pernet_subsys(&nf_nat_rule_net_ops);
if (ret != 0)
goto out;
ret = xt_register_target(&ipt_snat_reg);
if (ret != 0)
goto unregister_table;
ret = xt_register_target(&ipt_dnat_reg);
if (ret != 0)
goto unregister_snat;
return ret;
unregister_snat:
xt_unregister_target(&ipt_snat_reg);
unregister_table:
unregister_pernet_subsys(&nf_nat_rule_net_ops);
out:
return ret;
}
void nf_nat_rule_cleanup(void)
{
xt_unregister_target(&ipt_dnat_reg);
xt_unregister_target(&ipt_snat_reg);
unregister_pernet_subsys(&nf_nat_rule_net_ops);
}
