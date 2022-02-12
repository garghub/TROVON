static void nft_bitwise_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_bitwise *priv = nft_expr_priv(expr);
const u32 *src = &regs->data[priv->sreg];
u32 *dst = &regs->data[priv->dreg];
unsigned int i;
for (i = 0; i < DIV_ROUND_UP(priv->len, 4); i++)
dst[i] = (src[i] & priv->mask.data[i]) ^ priv->xor.data[i];
}
static int nft_bitwise_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_bitwise *priv = nft_expr_priv(expr);
struct nft_data_desc d1, d2;
int err;
if (tb[NFTA_BITWISE_SREG] == NULL ||
tb[NFTA_BITWISE_DREG] == NULL ||
tb[NFTA_BITWISE_LEN] == NULL ||
tb[NFTA_BITWISE_MASK] == NULL ||
tb[NFTA_BITWISE_XOR] == NULL)
return -EINVAL;
priv->len = ntohl(nla_get_be32(tb[NFTA_BITWISE_LEN]));
priv->sreg = nft_parse_register(tb[NFTA_BITWISE_SREG]);
err = nft_validate_register_load(priv->sreg, priv->len);
if (err < 0)
return err;
priv->dreg = nft_parse_register(tb[NFTA_BITWISE_DREG]);
err = nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, priv->len);
if (err < 0)
return err;
err = nft_data_init(NULL, &priv->mask, sizeof(priv->mask), &d1,
tb[NFTA_BITWISE_MASK]);
if (err < 0)
return err;
if (d1.len != priv->len)
return -EINVAL;
err = nft_data_init(NULL, &priv->xor, sizeof(priv->xor), &d2,
tb[NFTA_BITWISE_XOR]);
if (err < 0)
return err;
if (d2.len != priv->len)
return -EINVAL;
return 0;
}
static int nft_bitwise_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_bitwise *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_BITWISE_SREG, priv->sreg))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_BITWISE_DREG, priv->dreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_BITWISE_LEN, htonl(priv->len)))
goto nla_put_failure;
if (nft_data_dump(skb, NFTA_BITWISE_MASK, &priv->mask,
NFT_DATA_VALUE, priv->len) < 0)
goto nla_put_failure;
if (nft_data_dump(skb, NFTA_BITWISE_XOR, &priv->xor,
NFT_DATA_VALUE, priv->len) < 0)
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
int __init nft_bitwise_module_init(void)
{
return nft_register_expr(&nft_bitwise_type);
}
void nft_bitwise_module_exit(void)
{
nft_unregister_expr(&nft_bitwise_type);
}
