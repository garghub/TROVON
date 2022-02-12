static void nft_hash_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_hash *priv = nft_expr_priv(expr);
const void *data = &regs->data[priv->sreg];
u32 h;
h = reciprocal_scale(jhash(data, priv->len, priv->seed), priv->modulus);
regs->data[priv->dreg] = h + priv->offset;
}
static int nft_hash_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_hash *priv = nft_expr_priv(expr);
u32 len;
int err;
if (!tb[NFTA_HASH_SREG] ||
!tb[NFTA_HASH_DREG] ||
!tb[NFTA_HASH_LEN] ||
!tb[NFTA_HASH_MODULUS])
return -EINVAL;
if (tb[NFTA_HASH_OFFSET])
priv->offset = ntohl(nla_get_be32(tb[NFTA_HASH_OFFSET]));
priv->sreg = nft_parse_register(tb[NFTA_HASH_SREG]);
priv->dreg = nft_parse_register(tb[NFTA_HASH_DREG]);
err = nft_parse_u32_check(tb[NFTA_HASH_LEN], U8_MAX, &len);
if (err < 0)
return err;
if (len == 0)
return -ERANGE;
priv->len = len;
priv->modulus = ntohl(nla_get_be32(tb[NFTA_HASH_MODULUS]));
if (priv->modulus <= 1)
return -ERANGE;
if (priv->offset + priv->modulus - 1 < priv->offset)
return -EOVERFLOW;
if (tb[NFTA_HASH_SEED]) {
priv->seed = ntohl(nla_get_be32(tb[NFTA_HASH_SEED]));
} else {
priv->autogen_seed = true;
get_random_bytes(&priv->seed, sizeof(priv->seed));
}
return nft_validate_register_load(priv->sreg, len) &&
nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, sizeof(u32));
}
static int nft_hash_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_hash *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_HASH_SREG, priv->sreg))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_HASH_DREG, priv->dreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_HASH_LEN, htonl(priv->len)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_HASH_MODULUS, htonl(priv->modulus)))
goto nla_put_failure;
if (!priv->autogen_seed &&
nla_put_be32(skb, NFTA_HASH_SEED, htonl(priv->seed)))
goto nla_put_failure;
if (priv->offset != 0)
if (nla_put_be32(skb, NFTA_HASH_OFFSET, htonl(priv->offset)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_hash_module_init(void)
{
return nft_register_expr(&nft_hash_type);
}
static void __exit nft_hash_module_exit(void)
{
nft_unregister_expr(&nft_hash_type);
}
