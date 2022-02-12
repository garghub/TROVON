static void nft_queue_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_queue *priv = nft_expr_priv(expr);
u32 queue = priv->queuenum;
u32 ret;
if (priv->queues_total > 1) {
if (priv->flags & NFT_QUEUE_FLAG_CPU_FANOUT) {
int cpu = smp_processor_id();
queue = priv->queuenum + cpu % priv->queues_total;
} else {
queue = nfqueue_hash(pkt->skb, queue,
priv->queues_total, pkt->pf,
jhash_initval);
}
}
ret = NF_QUEUE_NR(queue);
if (priv->flags & NFT_QUEUE_FLAG_BYPASS)
ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;
regs->verdict.code = ret;
}
static void nft_queue_sreg_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_queue *priv = nft_expr_priv(expr);
u32 queue, ret;
queue = regs->data[priv->sreg_qnum];
ret = NF_QUEUE_NR(queue);
if (priv->flags & NFT_QUEUE_FLAG_BYPASS)
ret |= NF_VERDICT_FLAG_QUEUE_BYPASS;
regs->verdict.code = ret;
}
static int nft_queue_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_queue *priv = nft_expr_priv(expr);
u32 maxid;
priv->queuenum = ntohs(nla_get_be16(tb[NFTA_QUEUE_NUM]));
if (tb[NFTA_QUEUE_TOTAL])
priv->queues_total = ntohs(nla_get_be16(tb[NFTA_QUEUE_TOTAL]));
else
priv->queues_total = 1;
if (priv->queues_total == 0)
return -EINVAL;
maxid = priv->queues_total - 1 + priv->queuenum;
if (maxid > U16_MAX)
return -ERANGE;
if (tb[NFTA_QUEUE_FLAGS]) {
priv->flags = ntohs(nla_get_be16(tb[NFTA_QUEUE_FLAGS]));
if (priv->flags & ~NFT_QUEUE_FLAG_MASK)
return -EINVAL;
}
return 0;
}
static int nft_queue_sreg_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_queue *priv = nft_expr_priv(expr);
int err;
priv->sreg_qnum = nft_parse_register(tb[NFTA_QUEUE_SREG_QNUM]);
err = nft_validate_register_load(priv->sreg_qnum, sizeof(u32));
if (err < 0)
return err;
if (tb[NFTA_QUEUE_FLAGS]) {
priv->flags = ntohs(nla_get_be16(tb[NFTA_QUEUE_FLAGS]));
if (priv->flags & ~NFT_QUEUE_FLAG_MASK)
return -EINVAL;
if (priv->flags & NFT_QUEUE_FLAG_CPU_FANOUT)
return -EOPNOTSUPP;
}
return 0;
}
static int nft_queue_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_queue *priv = nft_expr_priv(expr);
if (nla_put_be16(skb, NFTA_QUEUE_NUM, htons(priv->queuenum)) ||
nla_put_be16(skb, NFTA_QUEUE_TOTAL, htons(priv->queues_total)) ||
nla_put_be16(skb, NFTA_QUEUE_FLAGS, htons(priv->flags)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int
nft_queue_sreg_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_queue *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_QUEUE_SREG_QNUM, priv->sreg_qnum) ||
nla_put_be16(skb, NFTA_QUEUE_FLAGS, htons(priv->flags)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static const struct nft_expr_ops *
nft_queue_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
if (tb[NFTA_QUEUE_NUM] && tb[NFTA_QUEUE_SREG_QNUM])
return ERR_PTR(-EINVAL);
init_hashrandom(&jhash_initval);
if (tb[NFTA_QUEUE_NUM])
return &nft_queue_ops;
if (tb[NFTA_QUEUE_SREG_QNUM])
return &nft_queue_sreg_ops;
return ERR_PTR(-EINVAL);
}
static int __init nft_queue_module_init(void)
{
return nft_register_expr(&nft_queue_type);
}
static void __exit nft_queue_module_exit(void)
{
nft_unregister_expr(&nft_queue_type);
}
