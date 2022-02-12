static unsigned int
nft_do_chain_arp(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nft_pktinfo pkt;
nft_set_pktinfo(&pkt, skb, state);
return nft_do_chain(&pkt, priv);
}
static int nf_tables_arp_init_net(struct net *net)
{
net->nft.arp = kmalloc(sizeof(struct nft_af_info), GFP_KERNEL);
if (net->nft.arp== NULL)
return -ENOMEM;
memcpy(net->nft.arp, &nft_af_arp, sizeof(nft_af_arp));
if (nft_register_afinfo(net, net->nft.arp) < 0)
goto err;
return 0;
err:
kfree(net->nft.arp);
return -ENOMEM;
}
static void nf_tables_arp_exit_net(struct net *net)
{
nft_unregister_afinfo(net, net->nft.arp);
kfree(net->nft.arp);
}
static int __init nf_tables_arp_init(void)
{
int ret;
nft_register_chain_type(&filter_arp);
ret = register_pernet_subsys(&nf_tables_arp_net_ops);
if (ret < 0)
nft_unregister_chain_type(&filter_arp);
return ret;
}
static void __exit nf_tables_arp_exit(void)
{
unregister_pernet_subsys(&nf_tables_arp_net_ops);
nft_unregister_chain_type(&filter_arp);
}
