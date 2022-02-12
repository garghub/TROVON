static unsigned int nft_nat_do_chain(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state,
struct nf_conn *ct)
{
struct nft_pktinfo pkt;
nft_set_pktinfo_ipv4(&pkt, ops, skb, state);
return nft_do_chain(&pkt, ops);
}
static unsigned int nft_nat_ipv4_fn(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_fn(ops, skb, state, nft_nat_do_chain);
}
static unsigned int nft_nat_ipv4_in(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_in(ops, skb, state, nft_nat_do_chain);
}
static unsigned int nft_nat_ipv4_out(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_out(ops, skb, state, nft_nat_do_chain);
}
static unsigned int nft_nat_ipv4_local_fn(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
return nf_nat_ipv4_local_fn(ops, skb, state, nft_nat_do_chain);
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
