static unsigned int smack_ipv6_output(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct sock *sk = skb_to_full_sk(skb);
struct socket_smack *ssp;
struct smack_known *skp;
if (sk && sk->sk_security) {
ssp = sk->sk_security;
skp = ssp->smk_out;
skb->secmark = skp->smk_secid;
}
return NF_ACCEPT;
}
static unsigned int smack_ipv4_output(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct sock *sk = skb_to_full_sk(skb);
struct socket_smack *ssp;
struct smack_known *skp;
if (sk && sk->sk_security) {
ssp = sk->sk_security;
skp = ssp->smk_out;
skb->secmark = skp->smk_secid;
}
return NF_ACCEPT;
}
static int __net_init smack_nf_register(struct net *net)
{
return nf_register_net_hooks(net, smack_nf_ops,
ARRAY_SIZE(smack_nf_ops));
}
static void __net_exit smack_nf_unregister(struct net *net)
{
nf_unregister_net_hooks(net, smack_nf_ops, ARRAY_SIZE(smack_nf_ops));
}
static int __init smack_nf_ip_init(void)
{
if (smack_enabled == 0)
return 0;
printk(KERN_DEBUG "Smack: Registering netfilter hooks\n");
return register_pernet_subsys(&smack_net_ops);
}
