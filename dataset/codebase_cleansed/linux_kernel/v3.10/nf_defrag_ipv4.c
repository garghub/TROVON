static int nf_ct_ipv4_gather_frags(struct sk_buff *skb, u_int32_t user)
{
int err;
skb_orphan(skb);
local_bh_disable();
err = ip_defrag(skb, user);
local_bh_enable();
if (!err)
ip_send_check(ip_hdr(skb));
return err;
}
static enum ip_defrag_users nf_ct_defrag_user(unsigned int hooknum,
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
return IP_DEFRAG_CONNTRACK_BRIDGE_IN + zone;
#endif
if (hooknum == NF_INET_PRE_ROUTING)
return IP_DEFRAG_CONNTRACK_IN + zone;
else
return IP_DEFRAG_CONNTRACK_OUT + zone;
}
static unsigned int ipv4_conntrack_defrag(unsigned int hooknum,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct sock *sk = skb->sk;
struct inet_sock *inet = inet_sk(skb->sk);
if (sk && (sk->sk_family == PF_INET) &&
inet->nodefrag)
return NF_ACCEPT;
#if defined(CONFIG_NF_CONNTRACK) || defined(CONFIG_NF_CONNTRACK_MODULE)
#if !defined(CONFIG_NF_NAT) && !defined(CONFIG_NF_NAT_MODULE)
if (skb->nfct && !nf_ct_is_template((struct nf_conn *)skb->nfct))
return NF_ACCEPT;
#endif
#endif
if (ip_is_fragment(ip_hdr(skb))) {
enum ip_defrag_users user = nf_ct_defrag_user(hooknum, skb);
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
