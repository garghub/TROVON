static void nft_meta_eval(const struct nft_expr *expr,
struct nft_data *nfres,
struct nft_data *data,
const struct nft_pktinfo *pkt)
{
const struct nft_meta *meta = nft_expr_priv(expr);
struct sk_buff *skb = pkt->skb;
u32 val = data->data[0];
switch (meta->key) {
case NFT_META_MARK:
skb->mark = val;
break;
case NFT_META_PRIORITY:
skb->priority = val;
break;
case NFT_META_NFTRACE:
skb->nf_trace = val;
break;
#ifdef CONFIG_NETWORK_SECMARK
case NFT_META_SECMARK:
skb->secmark = val;
break;
#endif
default:
WARN_ON(1);
}
}
static int nft_meta_init(const struct nft_expr *expr, struct nlattr *tb[])
{
struct nft_meta *meta = nft_expr_priv(expr);
if (tb[NFTA_META_KEY] == NULL)
return -EINVAL;
meta->key = ntohl(nla_get_be32(tb[NFTA_META_KEY]));
switch (meta->key) {
case NFT_META_MARK:
case NFT_META_PRIORITY:
case NFT_META_NFTRACE:
#ifdef CONFIG_NETWORK_SECMARK
case NFT_META_SECMARK:
#endif
break;
default:
return -EINVAL;
}
return 0;
}
static int nft_meta_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
struct nft_meta *meta = nft_expr_priv(expr);
NLA_PUT_BE32(skb, NFTA_META_KEY, htonl(meta->key));
return 0;
nla_put_failure:
return -1;
}
static int __init nft_meta_target_init(void)
{
return nft_register_expr(&meta_target);
}
static void __exit nft_meta_target_exit(void)
{
nft_unregister_expr(&meta_target);
}
