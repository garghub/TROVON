static int nf_ct_ipv4_gather_frags(struct sk_buff *skb, u_int32_t user)
{
int err;
skb_orphan(skb);
local_bh_disable();
err = ip_defrag(skb, user);
local_bh_enable();
if (!err) {
ip_send_check(ip_hdr(skb));
skb->ignore_df = 1;
}
return err;
}
static enum ip_defrag_users nf_ct_defrag_user(unsigned int hooknum,
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
return IP_DEFRAG_CONNTRACK_BRIDGE_IN + zone_id;
if (hooknum == NF_INET_PRE_ROUTING)
return IP_DEFRAG_CONNTRACK_IN + zone_id;
else
return IP_DEFRAG_CONNTRACK_OUT + zone_id;
}
static unsigned int ipv4_conntrack_defrag(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct sock *sk = skb->sk;
struct inet_sock *inet = inet_sk(skb->sk);
if (sk && (sk->sk_family == PF_INET) &&
inet->nodefrag)
return NF_ACCEPT;
#if IS_ENABLED(CONFIG_NF_CONNTRACK)
#if !IS_ENABLED(CONFIG_NF_NAT)
if (skb->nfct && !nf_ct_is_template((struct nf_conn *)skb->nfct))
return NF_ACCEPT;
#endif
#endif
if (ip_is_fragment(ip_hdr(skb))) {
enum ip_defrag_users user =
nf_ct_defrag_user(ops->hooknum, skb);
if (nf_ct_ipv4_gather_frags(skb, user))
return NF_STOLEN;
}
return NF_ACCEPT;
}
static int __init nf_defrag_init(void)
{
return nf_register_hooks(ipv4_defrag_ops, ARRAY_SIZE(ipv4_defrag_ops));
}
static void __exit nf_defrag_fini(void)
{
nf_unregister_hooks(ipv4_defrag_ops, ARRAY_SIZE(ipv4_defrag_ops));
}
void nf_defrag_ipv4_enable(void)
{
}
