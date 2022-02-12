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
static int __init smack_nf_ip_init(void)
{
int err;
if (smack_enabled == 0)
return 0;
printk(KERN_DEBUG "Smack: Registering netfilter hooks\n");
err = nf_register_hooks(smack_nf_ops, ARRAY_SIZE(smack_nf_ops));
if (err)
pr_info("Smack: nf_register_hooks: error %d\n", err);
return 0;
}
