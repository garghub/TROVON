static void nft_reject_br_push_etherhdr(struct sk_buff *oldskb,
struct sk_buff *nskb)
{
struct ethhdr *eth;
eth = (struct ethhdr *)skb_push(nskb, ETH_HLEN);
skb_reset_mac_header(nskb);
ether_addr_copy(eth->h_source, eth_hdr(oldskb)->h_dest);
ether_addr_copy(eth->h_dest, eth_hdr(oldskb)->h_source);
eth->h_proto = eth_hdr(oldskb)->h_proto;
skb_pull(nskb, ETH_HLEN);
}
static void nft_reject_br_send_v4_tcp_reset(struct net *net,
struct sk_buff *oldskb,
const struct net_device *dev,
int hook)
{
struct sk_buff *nskb;
struct iphdr *niph;
const struct tcphdr *oth;
struct tcphdr _oth;
if (!nft_bridge_iphdr_validate(oldskb))
return;
oth = nf_reject_ip_tcphdr_get(oldskb, &_oth, hook);
if (!oth)
return;
nskb = alloc_skb(sizeof(struct iphdr) + sizeof(struct tcphdr) +
LL_MAX_HEADER, GFP_ATOMIC);
if (!nskb)
return;
skb_reserve(nskb, LL_MAX_HEADER);
niph = nf_reject_iphdr_put(nskb, oldskb, IPPROTO_TCP,
net->ipv4.sysctl_ip_default_ttl);
nf_reject_ip_tcphdr_put(nskb, oldskb, oth);
niph->ttl = net->ipv4.sysctl_ip_default_ttl;
niph->tot_len = htons(nskb->len);
ip_send_check(niph);
nft_reject_br_push_etherhdr(oldskb, nskb);
br_deliver(br_port_get_rcu(dev), nskb);
}
static void nft_reject_br_send_v4_unreach(struct net *net,
struct sk_buff *oldskb,
const struct net_device *dev,
int hook, u8 code)
{
struct sk_buff *nskb;
struct iphdr *niph;
struct icmphdr *icmph;
unsigned int len;
void *payload;
__wsum csum;
u8 proto;
if (oldskb->csum_bad || !nft_bridge_iphdr_validate(oldskb))
return;
if (ip_hdr(oldskb)->frag_off & htons(IP_OFFSET))
return;
len = min_t(unsigned int, 536, oldskb->len);
if (!pskb_may_pull(oldskb, len))
return;
if (pskb_trim_rcsum(oldskb, ntohs(ip_hdr(oldskb)->tot_len)))
return;
if (ip_hdr(oldskb)->protocol == IPPROTO_TCP ||
ip_hdr(oldskb)->protocol == IPPROTO_UDP)
proto = ip_hdr(oldskb)->protocol;
else
proto = 0;
if (!skb_csum_unnecessary(oldskb) &&
nf_ip_checksum(oldskb, hook, ip_hdrlen(oldskb), proto))
return;
nskb = alloc_skb(sizeof(struct iphdr) + sizeof(struct icmphdr) +
LL_MAX_HEADER + len, GFP_ATOMIC);
if (!nskb)
return;
skb_reserve(nskb, LL_MAX_HEADER);
niph = nf_reject_iphdr_put(nskb, oldskb, IPPROTO_ICMP,
net->ipv4.sysctl_ip_default_ttl);
skb_reset_transport_header(nskb);
icmph = (struct icmphdr *)skb_put(nskb, sizeof(struct icmphdr));
memset(icmph, 0, sizeof(*icmph));
icmph->type = ICMP_DEST_UNREACH;
icmph->code = code;
payload = skb_put(nskb, len);
memcpy(payload, skb_network_header(oldskb), len);
csum = csum_partial((void *)icmph, len + sizeof(struct icmphdr), 0);
icmph->checksum = csum_fold(csum);
niph->tot_len = htons(nskb->len);
ip_send_check(niph);
nft_reject_br_push_etherhdr(oldskb, nskb);
br_deliver(br_port_get_rcu(dev), nskb);
}
static void nft_reject_br_send_v6_tcp_reset(struct net *net,
struct sk_buff *oldskb,
const struct net_device *dev,
int hook)
{
struct sk_buff *nskb;
const struct tcphdr *oth;
struct tcphdr _oth;
unsigned int otcplen;
struct ipv6hdr *nip6h;
if (!nft_bridge_ip6hdr_validate(oldskb))
return;
oth = nf_reject_ip6_tcphdr_get(oldskb, &_oth, &otcplen, hook);
if (!oth)
return;
nskb = alloc_skb(sizeof(struct ipv6hdr) + sizeof(struct tcphdr) +
LL_MAX_HEADER, GFP_ATOMIC);
if (!nskb)
return;
skb_reserve(nskb, LL_MAX_HEADER);
nip6h = nf_reject_ip6hdr_put(nskb, oldskb, IPPROTO_TCP,
net->ipv6.devconf_all->hop_limit);
nf_reject_ip6_tcphdr_put(nskb, oldskb, oth, otcplen);
nip6h->payload_len = htons(nskb->len - sizeof(struct ipv6hdr));
nft_reject_br_push_etherhdr(oldskb, nskb);
br_deliver(br_port_get_rcu(dev), nskb);
}
static bool reject6_br_csum_ok(struct sk_buff *skb, int hook)
{
const struct ipv6hdr *ip6h = ipv6_hdr(skb);
int thoff;
__be16 fo;
u8 proto = ip6h->nexthdr;
if (skb->csum_bad)
return false;
if (skb_csum_unnecessary(skb))
return true;
if (ip6h->payload_len &&
pskb_trim_rcsum(skb, ntohs(ip6h->payload_len) + sizeof(*ip6h)))
return false;
thoff = ipv6_skip_exthdr(skb, ((u8*)(ip6h+1) - skb->data), &proto, &fo);
if (thoff < 0 || thoff >= skb->len || (fo & htons(~0x7)) != 0)
return false;
return nf_ip6_checksum(skb, hook, thoff, proto) == 0;
}
static void nft_reject_br_send_v6_unreach(struct net *net,
struct sk_buff *oldskb,
const struct net_device *dev,
int hook, u8 code)
{
struct sk_buff *nskb;
struct ipv6hdr *nip6h;
struct icmp6hdr *icmp6h;
unsigned int len;
void *payload;
if (!nft_bridge_ip6hdr_validate(oldskb))
return;
len = min_t(unsigned int, 1220, oldskb->len);
if (!pskb_may_pull(oldskb, len))
return;
if (!reject6_br_csum_ok(oldskb, hook))
return;
nskb = alloc_skb(sizeof(struct iphdr) + sizeof(struct icmp6hdr) +
LL_MAX_HEADER + len, GFP_ATOMIC);
if (!nskb)
return;
skb_reserve(nskb, LL_MAX_HEADER);
nip6h = nf_reject_ip6hdr_put(nskb, oldskb, IPPROTO_ICMPV6,
net->ipv6.devconf_all->hop_limit);
skb_reset_transport_header(nskb);
icmp6h = (struct icmp6hdr *)skb_put(nskb, sizeof(struct icmp6hdr));
memset(icmp6h, 0, sizeof(*icmp6h));
icmp6h->icmp6_type = ICMPV6_DEST_UNREACH;
icmp6h->icmp6_code = code;
payload = skb_put(nskb, len);
memcpy(payload, skb_network_header(oldskb), len);
nip6h->payload_len = htons(nskb->len - sizeof(struct ipv6hdr));
icmp6h->icmp6_cksum =
csum_ipv6_magic(&nip6h->saddr, &nip6h->daddr,
nskb->len - sizeof(struct ipv6hdr),
IPPROTO_ICMPV6,
csum_partial(icmp6h,
nskb->len - sizeof(struct ipv6hdr),
0));
nft_reject_br_push_etherhdr(oldskb, nskb);
br_deliver(br_port_get_rcu(dev), nskb);
}
static void nft_reject_bridge_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_reject *priv = nft_expr_priv(expr);
const unsigned char *dest = eth_hdr(pkt->skb)->h_dest;
if (is_broadcast_ether_addr(dest) ||
is_multicast_ether_addr(dest))
goto out;
switch (eth_hdr(pkt->skb)->h_proto) {
case htons(ETH_P_IP):
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nft_reject_br_send_v4_unreach(pkt->net, pkt->skb,
pkt->in, pkt->hook,
priv->icmp_code);
break;
case NFT_REJECT_TCP_RST:
nft_reject_br_send_v4_tcp_reset(pkt->net, pkt->skb,
pkt->in, pkt->hook);
break;
case NFT_REJECT_ICMPX_UNREACH:
nft_reject_br_send_v4_unreach(pkt->net, pkt->skb,
pkt->in, pkt->hook,
nft_reject_icmp_code(priv->icmp_code));
break;
}
break;
case htons(ETH_P_IPV6):
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nft_reject_br_send_v6_unreach(pkt->net, pkt->skb,
pkt->in, pkt->hook,
priv->icmp_code);
break;
case NFT_REJECT_TCP_RST:
nft_reject_br_send_v6_tcp_reset(pkt->net, pkt->skb,
pkt->in, pkt->hook);
break;
case NFT_REJECT_ICMPX_UNREACH:
nft_reject_br_send_v6_unreach(pkt->net, pkt->skb,
pkt->in, pkt->hook,
nft_reject_icmpv6_code(priv->icmp_code));
break;
}
break;
default:
break;
}
out:
regs->verdict.code = NF_DROP;
}
static int nft_reject_bridge_validate(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nft_data **data)
{
return nft_chain_validate_hooks(ctx->chain, (1 << NF_BR_PRE_ROUTING) |
(1 << NF_BR_LOCAL_IN));
}
static int nft_reject_bridge_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_reject *priv = nft_expr_priv(expr);
int icmp_code, err;
err = nft_reject_bridge_validate(ctx, expr, NULL);
if (err < 0)
return err;
if (tb[NFTA_REJECT_TYPE] == NULL)
return -EINVAL;
priv->type = ntohl(nla_get_be32(tb[NFTA_REJECT_TYPE]));
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
case NFT_REJECT_ICMPX_UNREACH:
if (tb[NFTA_REJECT_ICMP_CODE] == NULL)
return -EINVAL;
icmp_code = nla_get_u8(tb[NFTA_REJECT_ICMP_CODE]);
if (priv->type == NFT_REJECT_ICMPX_UNREACH &&
icmp_code > NFT_REJECT_ICMPX_MAX)
return -EINVAL;
priv->icmp_code = icmp_code;
break;
case NFT_REJECT_TCP_RST:
break;
default:
return -EINVAL;
}
return 0;
}
static int nft_reject_bridge_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_reject *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_REJECT_TYPE, htonl(priv->type)))
goto nla_put_failure;
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
case NFT_REJECT_ICMPX_UNREACH:
if (nla_put_u8(skb, NFTA_REJECT_ICMP_CODE, priv->icmp_code))
goto nla_put_failure;
break;
default:
break;
}
return 0;
nla_put_failure:
return -1;
}
static int __init nft_reject_bridge_module_init(void)
{
return nft_register_expr(&nft_reject_bridge_type);
}
static void __exit nft_reject_bridge_module_exit(void)
{
nft_unregister_expr(&nft_reject_bridge_type);
}
