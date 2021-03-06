static __be32 get_saddr(__be32 addr)
{
if (ipv4_is_multicast(addr) || ipv4_is_lbcast(addr) ||
ipv4_is_zeronet(addr))
return 0;
return addr;
}
void nft_fib4_eval_type(const struct nft_expr *expr, struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_fib *priv = nft_expr_priv(expr);
u32 *dst = &regs->data[priv->dreg];
const struct net_device *dev = NULL;
const struct iphdr *iph;
__be32 addr;
if (priv->flags & NFTA_FIB_F_IIF)
dev = nft_in(pkt);
else if (priv->flags & NFTA_FIB_F_OIF)
dev = nft_out(pkt);
iph = ip_hdr(pkt->skb);
if (priv->flags & NFTA_FIB_F_DADDR)
addr = iph->daddr;
else
addr = iph->saddr;
*dst = inet_dev_addr_type(nft_net(pkt), dev, addr);
}
static int get_ifindex(const struct net_device *dev)
{
return dev ? dev->ifindex : 0;
}
void nft_fib4_eval(const struct nft_expr *expr, struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_fib *priv = nft_expr_priv(expr);
u32 *dest = &regs->data[priv->dreg];
const struct iphdr *iph;
struct fib_result res;
struct flowi4 fl4 = {
.flowi4_scope = RT_SCOPE_UNIVERSE,
.flowi4_iif = LOOPBACK_IFINDEX,
};
const struct net_device *oif;
struct net_device *found;
#ifdef CONFIG_IP_ROUTE_MULTIPATH
int i;
#endif
if (priv->flags & NFTA_FIB_F_OIF)
oif = nft_out(pkt);
else if (priv->flags & NFTA_FIB_F_IIF)
oif = nft_in(pkt);
else
oif = NULL;
if (nft_hook(pkt) == NF_INET_PRE_ROUTING &&
nft_fib_is_loopback(pkt->skb, nft_in(pkt))) {
nft_fib_store_result(dest, priv->result, pkt,
nft_in(pkt)->ifindex);
return;
}
iph = ip_hdr(pkt->skb);
if (ipv4_is_zeronet(iph->saddr)) {
if (ipv4_is_lbcast(iph->daddr) ||
ipv4_is_local_multicast(iph->daddr)) {
nft_fib_store_result(dest, priv->result, pkt,
get_ifindex(pkt->skb->dev));
return;
}
}
if (priv->flags & NFTA_FIB_F_MARK)
fl4.flowi4_mark = pkt->skb->mark;
fl4.flowi4_tos = iph->tos & DSCP_BITS;
if (priv->flags & NFTA_FIB_F_DADDR) {
fl4.daddr = iph->daddr;
fl4.saddr = get_saddr(iph->saddr);
} else {
fl4.daddr = iph->saddr;
fl4.saddr = get_saddr(iph->daddr);
}
*dest = 0;
if (fib_lookup(nft_net(pkt), &fl4, &res, FIB_LOOKUP_IGNORE_LINKSTATE))
return;
switch (res.type) {
case RTN_UNICAST:
break;
case RTN_LOCAL:
return;
default:
break;
}
if (!oif) {
found = FIB_RES_DEV(res);
goto ok;
}
#ifdef CONFIG_IP_ROUTE_MULTIPATH
for (i = 0; i < res.fi->fib_nhs; i++) {
struct fib_nh *nh = &res.fi->fib_nh[i];
if (nh->nh_dev == oif) {
found = nh->nh_dev;
goto ok;
}
}
return;
#else
found = FIB_RES_DEV(res);
if (found != oif)
return;
#endif
ok:
switch (priv->result) {
case NFT_FIB_RESULT_OIF:
*dest = found->ifindex;
break;
case NFT_FIB_RESULT_OIFNAME:
strncpy((char *)dest, found->name, IFNAMSIZ);
break;
default:
WARN_ON_ONCE(1);
break;
}
}
static const struct nft_expr_ops *
nft_fib4_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
enum nft_fib_result result;
if (!tb[NFTA_FIB_RESULT])
return ERR_PTR(-EINVAL);
result = ntohl(nla_get_be32(tb[NFTA_FIB_RESULT]));
switch (result) {
case NFT_FIB_RESULT_OIF:
return &nft_fib4_ops;
case NFT_FIB_RESULT_OIFNAME:
return &nft_fib4_ops;
case NFT_FIB_RESULT_ADDRTYPE:
return &nft_fib4_type_ops;
default:
return ERR_PTR(-EOPNOTSUPP);
}
}
static int __init nft_fib4_module_init(void)
{
return nft_register_expr(&nft_fib4_type);
}
static void __exit nft_fib4_module_exit(void)
{
nft_unregister_expr(&nft_fib4_type);
}
