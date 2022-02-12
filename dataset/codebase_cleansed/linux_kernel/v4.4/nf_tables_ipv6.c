static unsigned int nft_do_chain_ipv6(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nft_pktinfo pkt;
if (nft_set_pktinfo_ipv6(&pkt, skb, state) < 0)
return NF_DROP;
return nft_do_chain(&pkt, priv);
}
static unsigned int nft_ipv6_output(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (unlikely(skb->len < sizeof(struct ipv6hdr))) {
if (net_ratelimit())
pr_info("nf_tables_ipv6: ignoring short SOCK_RAW "
"packet\n");
return NF_ACCEPT;
}
return nft_do_chain_ipv6(priv, skb, state);
}
static int nf_tables_ipv6_init_net(struct net *net)
{
net->nft.ipv6 = kmalloc(sizeof(struct nft_af_info), GFP_KERNEL);
if (net->nft.ipv6 == NULL)
return -ENOMEM;
memcpy(net->nft.ipv6, &nft_af_ipv6, sizeof(nft_af_ipv6));
if (nft_register_afinfo(net, net->nft.ipv6) < 0)
goto err;
return 0;
err:
kfree(net->nft.ipv6);
return -ENOMEM;
}
static void nf_tables_ipv6_exit_net(struct net *net)
{
nft_unregister_afinfo(net->nft.ipv6);
kfree(net->nft.ipv6);
}
static int __init nf_tables_ipv6_init(void)
{
int ret;
nft_register_chain_type(&filter_ipv6);
ret = register_pernet_subsys(&nf_tables_ipv6_net_ops);
if (ret < 0)
nft_unregister_chain_type(&filter_ipv6);
return ret;
}
static void __exit nf_tables_ipv6_exit(void)
{
unregister_pernet_subsys(&nf_tables_ipv6_net_ops);
nft_unregister_chain_type(&filter_ipv6);
}
