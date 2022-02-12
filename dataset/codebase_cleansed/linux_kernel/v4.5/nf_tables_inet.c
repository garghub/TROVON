static void nft_inet_hook_ops_init(struct nf_hook_ops *ops, unsigned int n)
{
struct nft_af_info *afi;
if (n == 1)
afi = &nft_af_ipv4;
else
afi = &nft_af_ipv6;
ops->pf = afi->family;
if (afi->hooks[ops->hooknum])
ops->hook = afi->hooks[ops->hooknum];
}
static int __net_init nf_tables_inet_init_net(struct net *net)
{
net->nft.inet = kmalloc(sizeof(struct nft_af_info), GFP_KERNEL);
if (net->nft.inet == NULL)
return -ENOMEM;
memcpy(net->nft.inet, &nft_af_inet, sizeof(nft_af_inet));
if (nft_register_afinfo(net, net->nft.inet) < 0)
goto err;
return 0;
err:
kfree(net->nft.inet);
return -ENOMEM;
}
static void __net_exit nf_tables_inet_exit_net(struct net *net)
{
nft_unregister_afinfo(net, net->nft.inet);
kfree(net->nft.inet);
}
static int __init nf_tables_inet_init(void)
{
int ret;
nft_register_chain_type(&filter_inet);
ret = register_pernet_subsys(&nf_tables_inet_net_ops);
if (ret < 0)
nft_unregister_chain_type(&filter_inet);
return ret;
}
static void __exit nf_tables_inet_exit(void)
{
unregister_pernet_subsys(&nf_tables_inet_net_ops);
nft_unregister_chain_type(&filter_inet);
}
