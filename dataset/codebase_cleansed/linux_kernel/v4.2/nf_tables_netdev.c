static inline void
nft_netdev_set_pktinfo_ipv4(struct nft_pktinfo *pkt,
const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct iphdr *iph, _iph;
u32 len, thoff;
nft_set_pktinfo(pkt, ops, skb, state);
iph = skb_header_pointer(skb, skb_network_offset(skb), sizeof(*iph),
&_iph);
if (!iph)
return;
iph = ip_hdr(skb);
if (iph->ihl < 5 || iph->version != 4)
return;
len = ntohs(iph->tot_len);
thoff = iph->ihl * 4;
if (skb->len < len)
return;
else if (len < thoff)
return;
pkt->tprot = iph->protocol;
pkt->xt.thoff = thoff;
pkt->xt.fragoff = ntohs(iph->frag_off) & IP_OFFSET;
}
static inline void
__nft_netdev_set_pktinfo_ipv6(struct nft_pktinfo *pkt,
const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
#if IS_ENABLED(CONFIG_IPV6)
struct ipv6hdr *ip6h, _ip6h;
unsigned int thoff = 0;
unsigned short frag_off;
int protohdr;
u32 pkt_len;
ip6h = skb_header_pointer(skb, skb_network_offset(skb), sizeof(*ip6h),
&_ip6h);
if (!ip6h)
return;
if (ip6h->version != 6)
return;
pkt_len = ntohs(ip6h->payload_len);
if (pkt_len + sizeof(*ip6h) > skb->len)
return;
protohdr = ipv6_find_hdr(pkt->skb, &thoff, -1, &frag_off, NULL);
if (protohdr < 0)
return;
pkt->tprot = protohdr;
pkt->xt.thoff = thoff;
pkt->xt.fragoff = frag_off;
#endif
}
static inline void nft_netdev_set_pktinfo_ipv6(struct nft_pktinfo *pkt,
const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
nft_set_pktinfo(pkt, ops, skb, state);
__nft_netdev_set_pktinfo_ipv6(pkt, ops, skb, state);
}
static unsigned int
nft_do_chain_netdev(const struct nf_hook_ops *ops, struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nft_pktinfo pkt;
switch (eth_hdr(skb)->h_proto) {
case htons(ETH_P_IP):
nft_netdev_set_pktinfo_ipv4(&pkt, ops, skb, state);
break;
case htons(ETH_P_IPV6):
nft_netdev_set_pktinfo_ipv6(&pkt, ops, skb, state);
break;
default:
nft_set_pktinfo(&pkt, ops, skb, state);
break;
}
return nft_do_chain(&pkt, ops);
}
static int nf_tables_netdev_init_net(struct net *net)
{
net->nft.netdev = kmalloc(sizeof(struct nft_af_info), GFP_KERNEL);
if (net->nft.netdev == NULL)
return -ENOMEM;
memcpy(net->nft.netdev, &nft_af_netdev, sizeof(nft_af_netdev));
if (nft_register_afinfo(net, net->nft.netdev) < 0)
goto err;
return 0;
err:
kfree(net->nft.netdev);
return -ENOMEM;
}
static void nf_tables_netdev_exit_net(struct net *net)
{
nft_unregister_afinfo(net->nft.netdev);
kfree(net->nft.netdev);
}
static void nft_netdev_event(unsigned long event, struct nft_af_info *afi,
struct net_device *dev, struct nft_table *table,
struct nft_base_chain *basechain)
{
switch (event) {
case NETDEV_REGISTER:
if (strcmp(basechain->dev_name, dev->name) != 0)
return;
BUG_ON(!(basechain->flags & NFT_BASECHAIN_DISABLED));
dev_hold(dev);
basechain->ops[0].dev = dev;
basechain->flags &= ~NFT_BASECHAIN_DISABLED;
if (!(table->flags & NFT_TABLE_F_DORMANT))
nft_register_basechain(basechain, afi->nops);
break;
case NETDEV_UNREGISTER:
if (strcmp(basechain->dev_name, dev->name) != 0)
return;
BUG_ON(basechain->flags & NFT_BASECHAIN_DISABLED);
if (!(table->flags & NFT_TABLE_F_DORMANT))
nft_unregister_basechain(basechain, afi->nops);
dev_put(basechain->ops[0].dev);
basechain->ops[0].dev = NULL;
basechain->flags |= NFT_BASECHAIN_DISABLED;
break;
case NETDEV_CHANGENAME:
if (dev->ifindex != basechain->ops[0].dev->ifindex)
return;
strncpy(basechain->dev_name, dev->name, IFNAMSIZ);
break;
}
}
static int nf_tables_netdev_event(struct notifier_block *this,
unsigned long event, void *ptr)
{
struct net_device *dev = netdev_notifier_info_to_dev(ptr);
struct nft_af_info *afi;
struct nft_table *table;
struct nft_chain *chain;
nfnl_lock(NFNL_SUBSYS_NFTABLES);
list_for_each_entry(afi, &dev_net(dev)->nft.af_info, list) {
if (afi->family != NFPROTO_NETDEV)
continue;
list_for_each_entry(table, &afi->tables, list) {
list_for_each_entry(chain, &table->chains, list) {
if (!(chain->flags & NFT_BASE_CHAIN))
continue;
nft_netdev_event(event, afi, dev, table,
nft_base_chain(chain));
}
}
}
nfnl_unlock(NFNL_SUBSYS_NFTABLES);
return NOTIFY_DONE;
}
static int __init nf_tables_netdev_init(void)
{
int ret;
nft_register_chain_type(&nft_filter_chain_netdev);
ret = register_pernet_subsys(&nf_tables_netdev_net_ops);
if (ret < 0)
nft_unregister_chain_type(&nft_filter_chain_netdev);
register_netdevice_notifier(&nf_tables_netdev_notifier);
return ret;
}
static void __exit nf_tables_netdev_exit(void)
{
unregister_netdevice_notifier(&nf_tables_netdev_notifier);
unregister_pernet_subsys(&nf_tables_netdev_net_ops);
nft_unregister_chain_type(&nft_filter_chain_netdev);
}
