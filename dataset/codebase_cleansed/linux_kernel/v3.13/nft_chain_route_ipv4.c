static unsigned int nf_route_table_hook(const struct nf_hook_ops *ops,
struct sk_buff *skb,
const struct net_device *in,
const struct net_device *out,
int (*okfn)(struct sk_buff *))
{
unsigned int ret;
struct nft_pktinfo pkt;
u32 mark;
__be32 saddr, daddr;
u_int8_t tos;
const struct iphdr *iph;
if (skb->len < sizeof(struct iphdr) ||
ip_hdrlen(skb) < sizeof(struct iphdr))
return NF_ACCEPT;
nft_set_pktinfo_ipv4(&pkt, ops, skb, in, out);
mark = skb->mark;
iph = ip_hdr(skb);
saddr = iph->saddr;
daddr = iph->daddr;
tos = iph->tos;
ret = nft_do_chain_pktinfo(&pkt, ops);
if (ret != NF_DROP && ret != NF_QUEUE) {
iph = ip_hdr(skb);
if (iph->saddr != saddr ||
iph->daddr != daddr ||
skb->mark != mark ||
iph->tos != tos)
if (ip_route_me_harder(skb, RTN_UNSPEC))
ret = NF_DROP;
}
return ret;
}
static int __init nft_chain_route_init(void)
{
return nft_register_chain_type(&nft_chain_route_ipv4);
}
static void __exit nft_chain_route_exit(void)
{
nft_unregister_chain_type(&nft_chain_route_ipv4);
}
