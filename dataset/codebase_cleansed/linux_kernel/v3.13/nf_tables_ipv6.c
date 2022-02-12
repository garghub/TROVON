static unsigned int nft_ipv6_output(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nft_pktinfo pkt;
if (unlikely(skb->len < sizeof(struct ipv6hdr))) {
if (net_ratelimit())
pr_info("nf_tables_ipv6: ignoring short SOCK_RAW "
"packet\n");
return NF_ACCEPT;
}
if (nft_set_pktinfo_ipv6(&pkt, ops, skb, in, out) < 0)
return NF_DROP;
return nft_do_chain_pktinfo(&pkt, ops);
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
static unsigned int
nft_do_chain_ipv6(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nft_pktinfo pkt;
if (nft_set_pktinfo_ipv6(&pkt, ops, skb, in, out) < 0)
return NF_DROP;
return nft_do_chain_pktinfo(&pkt, ops);
}
static int __init nf_tables_ipv6_init(void)
{
nft_register_chain_type(&filter_ipv6);
return register_pernet_subsys(&nf_tables_ipv6_net_ops);
}
static void __exit nf_tables_ipv6_exit(void)
{
unregister_pernet_subsys(&nf_tables_ipv6_net_ops);
nft_unregister_chain_type(&filter_ipv6);
}
