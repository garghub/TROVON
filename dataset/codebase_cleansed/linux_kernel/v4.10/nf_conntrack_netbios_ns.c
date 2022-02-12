static int netbios_ns_help(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
return nf_conntrack_broadcast_help(skb, protoff, ct, ctinfo, timeout);
}
static int __init nf_conntrack_netbios_ns_init(void)
{
exp_policy.timeout = timeout;
return nf_conntrack_helper_register(&helper);
}
static void __exit nf_conntrack_netbios_ns_fini(void)
{
nf_conntrack_helper_unregister(&helper);
}
