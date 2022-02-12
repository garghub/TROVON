static int nf_tables_bridge_init_net(struct net *net)
{
net->nft.bridge = kmalloc(sizeof(struct nft_af_info), GFP_KERNEL);
if (net->nft.bridge == NULL)
return -ENOMEM;
memcpy(net->nft.bridge, &nft_af_bridge, sizeof(nft_af_bridge));
if (nft_register_afinfo(net, net->nft.bridge) < 0)
goto err;
return 0;
err:
kfree(net->nft.bridge);
return -ENOMEM;
}
static void nf_tables_bridge_exit_net(struct net *net)
{
nft_unregister_afinfo(net->nft.bridge);
kfree(net->nft.bridge);
}
static unsigned int
nft_do_chain_bridge(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nft_pktinfo pkt;
nft_set_pktinfo(&pkt, ops, skb, in, out);
return nft_do_chain_pktinfo(&pkt, ops);
}
static int __init nf_tables_bridge_init(void)
{
int ret;
nft_register_chain_type(&filter_bridge);
ret = register_pernet_subsys(&nf_tables_bridge_net_ops);
if (ret < 0)
nft_unregister_chain_type(&filter_bridge);
return ret;
}
static void __exit nf_tables_bridge_exit(void)
{
unregister_pernet_subsys(&nf_tables_bridge_net_ops);
nft_unregister_chain_type(&filter_bridge);
}
