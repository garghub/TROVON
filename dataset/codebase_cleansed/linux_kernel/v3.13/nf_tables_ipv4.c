static unsigned int nft_ipv4_output(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nft_pktinfo pkt;
if (unlikely(skb->len < sizeof(struct iphdr) ||
ip_hdr(skb)->ihl < sizeof(struct iphdr) / 4)) {
if (net_ratelimit())
pr_info("nf_tables_ipv4: ignoring short SOCK_RAW "
"packet\n");
return NF_ACCEPT;
}
nft_set_pktinfo_ipv4(&pkt, ops, skb, in, out);
return nft_do_chain_pktinfo(&pkt, ops);
}
static int nf_tables_ipv4_init_net(struct net *net)
{
net->nft.ipv4 = kmalloc(sizeof(struct nft_af_info), GFP_KERNEL);
if (net->nft.ipv4 == NULL)
return -ENOMEM;
memcpy(net->nft.ipv4, &nft_af_ipv4, sizeof(nft_af_ipv4));
if (nft_register_afinfo(net, net->nft.ipv4) < 0)
goto err;
return 0;
err:
kfree(net->nft.ipv4);
return -ENOMEM;
}
static void nf_tables_ipv4_exit_net(struct net *net)
{
nft_unregister_afinfo(net->nft.ipv4);
kfree(net->nft.ipv4);
}
static unsigned int
nft_do_chain_ipv4(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
struct nft_pktinfo pkt;
nft_set_pktinfo_ipv4(&pkt, ops, skb, in, out);
return nft_do_chain_pktinfo(&pkt, ops);
}
static int __init nf_tables_ipv4_init(void)
{
nft_register_chain_type(&filter_ipv4);
return register_pernet_subsys(&nf_tables_ipv4_net_ops);
}
static void __exit nf_tables_ipv4_exit(void)
{
unregister_pernet_subsys(&nf_tables_ipv4_net_ops);
nft_unregister_chain_type(&filter_ipv4);
}
