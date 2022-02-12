static unsigned int nft_nat_do_chain(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state,
struct nf_conn *ct)
{
struct nft_pktinfo pkt;
nft_set_pktinfo_ipv4(&pkt, skb, state);
return nft_do_chain(&pkt, priv);
}
static unsigned int nft_nat_ipv4_fn(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_fn(priv, skb, state, nft_nat_do_chain);
}
static unsigned int nft_nat_ipv4_in(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_in(priv, skb, state, nft_nat_do_chain);
}
static unsigned int nft_nat_ipv4_out(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_out(priv, skb, state, nft_nat_do_chain);
}
static unsigned int nft_nat_ipv4_local_fn(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_local_fn(priv, skb, state, nft_nat_do_chain);
}
static int __init nft_chain_nat_init(void)
{
int err;
err = nft_register_chain_type(&nft_chain_nat_ipv4);
if (err < 0)
return err;
return 0;
}
static void __exit nft_chain_nat_exit(void)
{
nft_unregister_chain_type(&nft_chain_nat_ipv4);
}
