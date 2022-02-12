static inline bool nft_limit_eval(struct nft_limit *limit, u64 cost)
{
u64 now, tokens;
s64 delta;
spin_lock_bh(&limit_lock);
now = ktime_get_ns();
tokens = limit->tokens + now - limit->last;
if (tokens > limit->tokens_max)
tokens = limit->tokens_max;
limit->last = now;
delta = tokens - cost;
if (delta >= 0) {
limit->tokens = delta;
spin_unlock_bh(&limit_lock);
return false;
}
limit->tokens = tokens;
spin_unlock_bh(&limit_lock);
return true;
}
static int nft_limit_init(struct nft_limit *limit,
const struct nlattr * const tb[])
{
u64 unit;
if (tb[NFTA_LIMIT_RATE] == NULL ||
tb[NFTA_LIMIT_UNIT] == NULL)
return -EINVAL;
limit->rate = be64_to_cpu(nla_get_be64(tb[NFTA_LIMIT_RATE]));
unit = be64_to_cpu(nla_get_be64(tb[NFTA_LIMIT_UNIT]));
limit->nsecs = unit * NSEC_PER_SEC;
if (limit->rate == 0 || limit->nsecs < unit)
return -EOVERFLOW;
limit->tokens = limit->tokens_max = limit->nsecs;
if (tb[NFTA_LIMIT_BURST]) {
u64 rate;
limit->burst = ntohl(nla_get_be32(tb[NFTA_LIMIT_BURST]));
rate = limit->rate + limit->burst;
if (rate < limit->rate)
return -EOVERFLOW;
limit->rate = rate;
}
limit->last = ktime_get_ns();
return 0;
}
static int nft_limit_dump(struct sk_buff *skb, const struct nft_limit *limit,
enum nft_limit_type type)
{
u64 secs = div_u64(limit->nsecs, NSEC_PER_SEC);
u64 rate = limit->rate - limit->burst;
if (nla_put_be64(skb, NFTA_LIMIT_RATE, cpu_to_be64(rate)) ||
nla_put_be64(skb, NFTA_LIMIT_UNIT, cpu_to_be64(secs)) ||
nla_put_be32(skb, NFTA_LIMIT_BURST, htonl(limit->burst)) ||
nla_put_be32(skb, NFTA_LIMIT_TYPE, htonl(type)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static void nft_limit_pkts_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_limit_pkts *priv = nft_expr_priv(expr);
if (nft_limit_eval(&priv->limit, priv->cost))
regs->verdict.code = NFT_BREAK;
}
static int nft_limit_pkts_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_limit_pkts *priv = nft_expr_priv(expr);
int err;
err = nft_limit_init(&priv->limit, tb);
if (err < 0)
return err;
priv->cost = div_u64(priv->limit.nsecs, priv->limit.rate);
return 0;
}
static int nft_limit_pkts_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_limit_pkts *priv = nft_expr_priv(expr);
return nft_limit_dump(skb, &priv->limit, NFT_LIMIT_PKTS);
}
static void nft_limit_pkt_bytes_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_limit *priv = nft_expr_priv(expr);
u64 cost = div_u64(priv->nsecs * pkt->skb->len, priv->rate);
if (nft_limit_eval(priv, cost))
regs->verdict.code = NFT_BREAK;
}
static int nft_limit_pkt_bytes_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_limit *priv = nft_expr_priv(expr);
return nft_limit_init(priv, tb);
}
static int nft_limit_pkt_bytes_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_limit *priv = nft_expr_priv(expr);
return nft_limit_dump(skb, priv, NFT_LIMIT_PKT_BYTES);
}
static const struct nft_expr_ops *
nft_limit_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
if (tb[NFTA_LIMIT_TYPE] == NULL)
return &nft_limit_pkts_ops;
switch (ntohl(nla_get_be32(tb[NFTA_LIMIT_TYPE]))) {
case NFT_LIMIT_PKTS:
return &nft_limit_pkts_ops;
case NFT_LIMIT_PKT_BYTES:
return &nft_limit_pkt_bytes_ops;
}
return ERR_PTR(-EOPNOTSUPP);
}
static int __init nft_limit_module_init(void)
{
return nft_register_expr(&nft_limit_type);
}
static void __exit nft_limit_module_exit(void)
{
nft_unregister_expr(&nft_limit_type);
}
