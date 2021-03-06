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
static int nft_reject_iphdr_validate(struct sk_buff *oldskb)
{
struct iphdr *iph;
u32 len;
if (!pskb_may_pull(oldskb, sizeof(struct iphdr)))
return 0;
iph = ip_hdr(oldskb);
if (iph->ihl < 5 || iph->version != 4)
return 0;
len = ntohs(iph->tot_len);
if (oldskb->len < len)
return 0;
else if (len < (iph->ihl*4))
return 0;
if (!pskb_may_pull(oldskb, iph->ihl*4))
return 0;
return 1;
}
static void nft_reject_br_send_v4_tcp_reset(struct sk_buff *oldskb, int hook)
{
struct sk_buff *nskb;
struct iphdr *niph;
const struct tcphdr *oth;
struct tcphdr _oth;
if (!nft_reject_iphdr_validate(oldskb))
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
sysctl_ip_default_ttl);
nf_reject_ip_tcphdr_put(nskb, oldskb, oth);
niph->ttl = sysctl_ip_default_ttl;
niph->tot_len = htons(nskb->len);
ip_send_check(niph);
nft_reject_br_push_etherhdr(oldskb, nskb);
br_deliver(br_port_get_rcu(oldskb->dev), nskb);
}
static void nft_reject_br_send_v4_unreach(struct sk_buff *oldskb, int hook,
u8 code)
{
struct sk_buff *nskb;
struct iphdr *niph;
struct icmphdr *icmph;
unsigned int len;
void *payload;
__wsum csum;
if (!nft_reject_iphdr_validate(oldskb))
return;
if (ip_hdr(oldskb)->frag_off & htons(IP_OFFSET))
return;
len = min_t(unsigned int, 536, oldskb->len);
if (!pskb_may_pull(oldskb, len))
return;
if (nf_ip_checksum(oldskb, hook, ip_hdrlen(oldskb), 0))
return;
nskb = alloc_skb(sizeof(struct iphdr) + sizeof(struct icmphdr) +
LL_MAX_HEADER + len, GFP_ATOMIC);
if (!nskb)
return;
skb_reserve(nskb, LL_MAX_HEADER);
niph = nf_reject_iphdr_put(nskb, oldskb, IPPROTO_ICMP,
sysctl_ip_default_ttl);
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
br_deliver(br_port_get_rcu(oldskb->dev), nskb);
}
static int nft_reject_ip6hdr_validate(struct sk_buff *oldskb)
{
struct ipv6hdr *hdr;
u32 pkt_len;
if (!pskb_may_pull(oldskb, sizeof(struct ipv6hdr)))
return 0;
hdr = ipv6_hdr(oldskb);
if (hdr->version != 6)
return 0;
pkt_len = ntohs(hdr->payload_len);
if (pkt_len + sizeof(struct ipv6hdr) > oldskb->len)
return 0;
return 1;
}
static void nft_reject_br_send_v6_tcp_reset(struct net *net,
struct sk_buff *oldskb, int hook)
{
struct sk_buff *nskb;
const struct tcphdr *oth;
struct tcphdr _oth;
unsigned int otcplen;
struct ipv6hdr *nip6h;
if (!nft_reject_ip6hdr_validate(oldskb))
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
br_deliver(br_port_get_rcu(oldskb->dev), nskb);
}
static void nft_reject_br_send_v6_unreach(struct net *net,
struct sk_buff *oldskb, int hook,
u8 code)
{
struct sk_buff *nskb;
struct ipv6hdr *nip6h;
struct icmp6hdr *icmp6h;
unsigned int len;
void *payload;
if (!nft_reject_ip6hdr_validate(oldskb))
return;
len = min_t(unsigned int, 1220, oldskb->len);
if (!pskb_may_pull(oldskb, len))
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
br_deliver(br_port_get_rcu(oldskb->dev), nskb);
}
static void nft_reject_bridge_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_reject *priv = nft_expr_priv(expr);
struct net *net = dev_net((pkt->in != NULL) ? pkt->in : pkt->out);
const unsigned char *dest = eth_hdr(pkt->skb)->h_dest;
if (is_broadcast_ether_addr(dest) ||
is_multicast_ether_addr(dest))
goto out;
switch (eth_hdr(pkt->skb)->h_proto) {
case htons(ETH_P_IP):
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nft_reject_br_send_v4_unreach(pkt->skb,
pkt->ops->hooknum,
priv->icmp_code);
break;
case NFT_REJECT_TCP_RST:
nft_reject_br_send_v4_tcp_reset(pkt->skb,
pkt->ops->hooknum);
break;
case NFT_REJECT_ICMPX_UNREACH:
nft_reject_br_send_v4_unreach(pkt->skb,
pkt->ops->hooknum,
nft_reject_icmp_code(priv->icmp_code));
break;
}
break;
case htons(ETH_P_IPV6):
switch (priv->type) {
case NFT_REJECT_ICMP_UNREACH:
nft_reject_br_send_v6_unreach(net, pkt->skb,
pkt->ops->hooknum,
priv->icmp_code);
break;
case NFT_REJECT_TCP_RST:
nft_reject_br_send_v6_tcp_reset(net, pkt->skb,
pkt->ops->hooknum);
break;
case NFT_REJECT_ICMPX_UNREACH:
nft_reject_br_send_v6_unreach(net, pkt->skb,
pkt->ops->hooknum,
nft_reject_icmpv6_code(priv->icmp_code));
break;
}
break;
default:
break;
}
out:
data[NFT_REG_VERDICT].verdict = NF_DROP;
}
static int nft_reject_bridge_validate_hooks(const struct nft_chain *chain)
{
struct nft_base_chain *basechain;
if (chain->flags & NFT_BASE_CHAIN) {
basechain = nft_base_chain(chain);
switch (basechain->ops[0].hooknum) {
case NF_BR_PRE_ROUTING:
case NF_BR_LOCAL_IN:
break;
default:
return -EOPNOTSUPP;
}
}
return 0;
}
static int nft_reject_bridge_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_reject *priv = nft_expr_priv(expr);
int icmp_code, err;
err = nft_reject_bridge_validate_hooks(ctx->chain);
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
}
return 0;
nla_put_failure:
return -1;
}
static int nft_reject_bridge_validate(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nft_data **data)
{
return nft_reject_bridge_validate_hooks(ctx->chain);
}
static int __init nft_reject_bridge_module_init(void)
{
return nft_register_expr(&nft_reject_bridge_type);
}
static void __exit nft_reject_bridge_module_exit(void)
{
nft_unregister_expr(&nft_reject_bridge_type);
}
