static enum ip6_defrag_users nf_ct6_defrag_user(unsigned int hooknum,
struct sk_buff *skb)
{
u16 zone_id = NF_CT_DEFAULT_ZONE_ID;
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (skb->nfct) {
enum ip_conntrack_info ctinfo;
const struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
zone_id = nf_ct_zone_id(nf_ct_zone(ct), CTINFO2DIR(ctinfo));
}
#endif
if (nf_bridge_in_prerouting(skb))
return IP6_DEFRAG_CONNTRACK_BRIDGE_IN + zone_id;
if (hooknum == NF_INET_PRE_ROUTING)
return IP6_DEFRAG_CONNTRACK_IN + zone_id;
else
return IP6_DEFRAG_CONNTRACK_OUT + zone_id;
}
static unsigned int ipv6_defrag(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct sk_buff *reasm;
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
if (skb->nfct && !nf_ct_is_template((struct nf_conn *)skb->nfct))
return NF_ACCEPT;
#endif
reasm = nf_ct_frag6_gather(state->net, skb,
nf_ct6_defrag_user(state->hook, skb));
if (reasm == NULL)
return NF_STOLEN;
if (reasm == skb)
return NF_ACCEPT;
nf_ct_frag6_consume_orig(reasm);
NF_HOOK_THRESH(NFPROTO_IPV6, state->hook, state->net, state->sk, reasm,
state->in, state->out,
state->okfn, NF_IP6_PRI_CONNTRACK_DEFRAG + 1);
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
