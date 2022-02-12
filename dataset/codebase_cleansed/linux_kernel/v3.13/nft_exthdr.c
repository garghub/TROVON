static void nft_exthdr_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
struct nft_exthdr *priv = nft_expr_priv(expr);
struct nft_data *dest = &data[priv->dreg];
unsigned int offset = 0;
int err;
err = ipv6_find_hdr(pkt->skb, &offset, priv->type, NULL, NULL);
if (err < 0)
goto err;
offset += priv->offset;
if (skb_copy_bits(pkt->skb, offset, dest->data, priv->len) < 0)
goto err;
return;
err:
data[NFT_REG_VERDICT].verdict = NFT_BREAK;
}
static int nft_exthdr_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_exthdr *priv = nft_expr_priv(expr);
int err;
if (tb[NFTA_EXTHDR_DREG] == NULL ||
tb[NFTA_EXTHDR_TYPE] == NULL ||
tb[NFTA_EXTHDR_OFFSET] == NULL ||
tb[NFTA_EXTHDR_LEN] == NULL)
return -EINVAL;
priv->type = nla_get_u8(tb[NFTA_EXTHDR_TYPE]);
priv->offset = ntohl(nla_get_be32(tb[NFTA_EXTHDR_OFFSET]));
priv->len = ntohl(nla_get_be32(tb[NFTA_EXTHDR_LEN]));
if (priv->len == 0 ||
priv->len > FIELD_SIZEOF(struct nft_data, data))
return -EINVAL;
priv->dreg = ntohl(nla_get_be32(tb[NFTA_EXTHDR_DREG]));
err = nft_validate_output_register(priv->dreg);
if (err < 0)
return err;
return nft_validate_data_load(ctx, priv->dreg, NULL, NFT_DATA_VALUE);
}
static int nft_exthdr_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_exthdr *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_EXTHDR_DREG, htonl(priv->dreg)))
goto nla_put_failure;
if (nla_put_u8(skb, NFTA_EXTHDR_TYPE, priv->type))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_EXTHDR_OFFSET, htonl(priv->offset)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_EXTHDR_LEN, htonl(priv->len)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_exthdr_module_init(void)
{
return nft_register_expr(&nft_exthdr_type);
}
static void __exit nft_exthdr_module_exit(void)
{
nft_unregister_expr(&nft_exthdr_type);
}
