static void nft_ng_inc_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_ng_inc *priv = nft_expr_priv(expr);
u32 nval, oval;
do {
oval = atomic_read(&priv->counter);
nval = (oval + 1 < priv->modulus) ? oval + 1 : 0;
} while (atomic_cmpxchg(&priv->counter, oval, nval) != oval);
regs->data[priv->dreg] = nval + priv->offset;
}
static int nft_ng_inc_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_ng_inc *priv = nft_expr_priv(expr);
if (tb[NFTA_NG_OFFSET])
priv->offset = ntohl(nla_get_be32(tb[NFTA_NG_OFFSET]));
priv->modulus = ntohl(nla_get_be32(tb[NFTA_NG_MODULUS]));
if (priv->modulus == 0)
return -ERANGE;
if (priv->offset + priv->modulus - 1 < priv->offset)
return -EOVERFLOW;
priv->dreg = nft_parse_register(tb[NFTA_NG_DREG]);
atomic_set(&priv->counter, priv->modulus - 1);
return nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, sizeof(u32));
}
static int nft_ng_dump(struct sk_buff *skb, enum nft_registers dreg,
u32 modulus, enum nft_ng_types type, u32 offset)
{
if (nft_dump_register(skb, NFTA_NG_DREG, dreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_NG_MODULUS, htonl(modulus)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_NG_TYPE, htonl(type)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_NG_OFFSET, htonl(offset)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int nft_ng_inc_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_ng_inc *priv = nft_expr_priv(expr);
return nft_ng_dump(skb, priv->dreg, priv->modulus, NFT_NG_INCREMENTAL,
priv->offset);
}
static void nft_ng_random_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_ng_random *priv = nft_expr_priv(expr);
struct rnd_state *state = this_cpu_ptr(&nft_numgen_prandom_state);
u32 val;
val = reciprocal_scale(prandom_u32_state(state), priv->modulus);
regs->data[priv->dreg] = val + priv->offset;
}
static int nft_ng_random_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_ng_random *priv = nft_expr_priv(expr);
if (tb[NFTA_NG_OFFSET])
priv->offset = ntohl(nla_get_be32(tb[NFTA_NG_OFFSET]));
priv->modulus = ntohl(nla_get_be32(tb[NFTA_NG_MODULUS]));
if (priv->modulus == 0)
return -ERANGE;
if (priv->offset + priv->modulus - 1 < priv->offset)
return -EOVERFLOW;
prandom_init_once(&nft_numgen_prandom_state);
priv->dreg = nft_parse_register(tb[NFTA_NG_DREG]);
return nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, sizeof(u32));
}
static int nft_ng_random_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_ng_random *priv = nft_expr_priv(expr);
return nft_ng_dump(skb, priv->dreg, priv->modulus, NFT_NG_RANDOM,
priv->offset);
}
static const struct nft_expr_ops *
nft_ng_select_ops(const struct nft_ctx *ctx, const struct nlattr * const tb[])
{
u32 type;
if (!tb[NFTA_NG_DREG] ||
!tb[NFTA_NG_MODULUS] ||
!tb[NFTA_NG_TYPE])
return ERR_PTR(-EINVAL);
type = ntohl(nla_get_be32(tb[NFTA_NG_TYPE]));
switch (type) {
case NFT_NG_INCREMENTAL:
return &nft_ng_inc_ops;
case NFT_NG_RANDOM:
return &nft_ng_random_ops;
}
return ERR_PTR(-EINVAL);
}
static int __init nft_ng_module_init(void)
{
return nft_register_expr(&nft_ng_type);
}
static void __exit nft_ng_module_exit(void)
{
nft_unregister_expr(&nft_ng_type);
}
