int nft_bridge_iphdr_validate(struct sk_buff *skb)
{
struct iphdr *iph;
u32 len;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
return 0;
iph = ip_hdr(skb);
if (iph->ihl < 5 || iph->version != 4)
return 0;
len = ntohs(iph->tot_len);
if (skb->len < len)
return 0;
else if (len < (iph->ihl*4))
return 0;
if (!pskb_may_pull(skb, iph->ihl*4))
return 0;
return 1;
}
int nft_bridge_ip6hdr_validate(struct sk_buff *skb)
{
struct ipv6hdr *hdr;
u32 pkt_len;
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
return 0;
hdr = ipv6_hdr(skb);
if (hdr->version != 6)
return 0;
pkt_len = ntohs(hdr->payload_len);
if (pkt_len + sizeof(struct ipv6hdr) > skb->len)
return 0;
return 1;
}
static inline void nft_bridge_set_pktinfo_ipv4(struct nft_pktinfo *pkt,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
if (nft_bridge_iphdr_validate(skb))
nft_set_pktinfo_ipv4(pkt, skb, state);
else
nft_set_pktinfo(pkt, skb, state);
}
static inline void nft_bridge_set_pktinfo_ipv6(struct nft_pktinfo *pkt,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
#if IS_ENABLED(CONFIG_IPV6)
if (nft_bridge_ip6hdr_validate(skb) &&
nft_set_pktinfo_ipv6(pkt, skb, state) == 0)
return;
#endif
nft_set_pktinfo(pkt, skb, state);
}
static unsigned int
nft_do_chain_bridge(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
struct nft_pktinfo pkt;
switch (eth_hdr(skb)->h_proto) {
case htons(ETH_P_IP):
nft_bridge_set_pktinfo_ipv4(&pkt, skb, state);
break;
case htons(ETH_P_IPV6):
nft_bridge_set_pktinfo_ipv6(&pkt, skb, state);
break;
default:
nft_set_pktinfo(&pkt, skb, state);
break;
}
return nft_do_chain(&pkt, priv);
}
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
nft_unregister_afinfo(net, net->nft.bridge);
kfree(net->nft.bridge);
}
static void nf_br_saveroute(const struct sk_buff *skb,
struct nf_queue_entry *entry)
{
}
static int nf_br_reroute(struct net *net, struct sk_buff *skb,
const struct nf_queue_entry *entry)
{
return 0;
}
static __sum16 nf_br_checksum(struct sk_buff *skb, unsigned int hook,
unsigned int dataoff, u_int8_t protocol)
{
return 0;
}
static __sum16 nf_br_checksum_partial(struct sk_buff *skb, unsigned int hook,
unsigned int dataoff, unsigned int len,
u_int8_t protocol)
{
return 0;
}
static int nf_br_route(struct net *net, struct dst_entry **dst,
struct flowi *fl, bool strict __always_unused)
{
return 0;
}
static int __init nf_tables_bridge_init(void)
{
int ret;
nf_register_afinfo(&nf_br_afinfo);
nft_register_chain_type(&filter_bridge);
ret = register_pernet_subsys(&nf_tables_bridge_net_ops);
if (ret < 0) {
nft_unregister_chain_type(&filter_bridge);
nf_unregister_afinfo(&nf_br_afinfo);
}
return ret;
}
static void __exit nf_tables_bridge_exit(void)
{
unregister_pernet_subsys(&nf_tables_bridge_net_ops);
nft_unregister_chain_type(&filter_bridge);
nf_unregister_afinfo(&nf_br_afinfo);
}
