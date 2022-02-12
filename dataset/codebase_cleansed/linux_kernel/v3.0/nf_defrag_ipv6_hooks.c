static enum ip6_defrag_users nf_ct6_defrag_user(unsigned int hooknum,
struct sk_buff *skb)
{
u16 zone = NF_CT_DEFAULT_ZONE;
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
if (skb->nfct)
zone = nf_ct_zone((struct nf_conn *)skb->nfct);
#endif
#ifdef CONFIG_BRIDGE_NETFILTER
if (skb->nf_bridge &&
skb->nf_bridge->mask & BRNF_NF_BRIDGE_PREROUTING)
return IP6_DEFRAG_CONNTRACK_BRIDGE_IN + zone;
#endif
if (hooknum == NF_INET_PRE_ROUTING)
return IP6_DEFRAG_CONNTRACK_IN + zone;
else
return IP6_DEFRAG_CONNTRACK_OUT + zone;
}
static unsigned int ipv6_defrag(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct sk_buff *reasm;
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
if (skb->nfct && !nf_ct_is_template((struct nf_conn *)skb->nfct))
return NF_ACCEPT;
#endif
reasm = nf_ct_frag6_gather(skb, nf_ct6_defrag_user(hooknum, skb));
if (reasm == NULL)
return NF_STOLEN;
if (reasm == skb)
return NF_ACCEPT;
nf_ct_frag6_output(hooknum, reasm, (struct net_device *)in,
(struct net_device *)out, okfn);
return NF_STOLEN;
}
static int __init nf_defrag_init(void)
{
int ret = 0;
ret = nf_ct_frag6_init();
if (ret < 0) {
pr_err("nf_defrag_ipv6: can't initialize frag6.\n");
return ret;
}
ret = nf_register_hooks(ipv6_defrag_ops, ARRAY_SIZE(ipv6_defrag_ops));
if (ret < 0) {
pr_err("nf_defrag_ipv6: can't register hooks\n");
goto cleanup_frag6;
}
return ret;
cleanup_frag6:
nf_ct_frag6_cleanup();
return ret;
}
static void __exit nf_defrag_fini(void)
{
nf_unregister_hooks(ipv6_defrag_ops, ARRAY_SIZE(ipv6_defrag_ops));
nf_ct_frag6_cleanup();
}
void nf_defrag_ipv6_enable(void)
{
}
