static int snmp_conntrack_help(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
typeof(nf_nat_snmp_hook) nf_nat_snmp;
nf_conntrack_broadcast_help(skb, protoff, ct, ctinfo, timeout);
nf_nat_snmp = rcu_dereference(nf_nat_snmp_hook);
if (nf_nat_snmp && ct->status & IPS_NAT_MASK)
return nf_nat_snmp(skb, protoff, ct, ctinfo);
return NF_ACCEPT;
}
static int __init nf_conntrack_snmp_init(void)
{
exp_policy.timeout = timeout;
return nf_conntrack_helper_register(&helper);
}
static void __exit nf_conntrack_snmp_fini(void)
{
nf_conntrack_helper_unregister(&helper);
}
