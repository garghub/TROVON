static unsigned int nf_route_table_hook(void *priv,
struct sk_buff *skb,
const struct nf_hook_state *state)
{
unsigned int ret;
struct nft_pktinfo pkt;
struct in6_addr saddr, daddr;
u_int8_t hop_limit;
u32 mark, flowlabel;
int err;
if (nft_set_pktinfo_ipv6(&pkt, skb, state) < 0)
return NF_DROP;
memcpy(&saddr, &ipv6_hdr(skb)->saddr, sizeof(saddr));
memcpy(&daddr, &ipv6_hdr(skb)->daddr, sizeof(daddr));
mark = skb->mark;
hop_limit = ipv6_hdr(skb)->hop_limit;
flowlabel = *((u32 *)ipv6_hdr(skb));
ret = nft_do_chain(&pkt, priv);
if (ret != NF_DROP && ret != NF_STOLEN &&
(memcmp(&ipv6_hdr(skb)->saddr, &saddr, sizeof(saddr)) ||
memcmp(&ipv6_hdr(skb)->daddr, &daddr, sizeof(daddr)) ||
skb->mark != mark ||
ipv6_hdr(skb)->hop_limit != hop_limit ||
flowlabel != *((u_int32_t *)ipv6_hdr(skb)))) {
err = ip6_route_me_harder(state->net, skb);
if (err < 0)
ret = NF_DROP_ERR(err);
}
return ret;
}
static int __init nft_chain_route_init(void)
{
return nft_register_chain_type(&nft_chain_route_ipv6);
}
static void __exit nft_chain_route_exit(void)
{
nft_unregister_chain_type(&nft_chain_route_ipv6);
}
