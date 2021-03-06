static void nft_cmp_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_cmp_expr *priv = nft_expr_priv(expr);
int d;
d = memcmp(&regs->data[priv->sreg], &priv->data, priv->len);
switch (priv->op) {
case NFT_CMP_EQ:
if (d != 0)
goto mismatch;
break;
case NFT_CMP_NEQ:
if (d == 0)
goto mismatch;
break;
case NFT_CMP_LT:
if (d == 0)
goto mismatch;
case NFT_CMP_LTE:
if (d > 0)
goto mismatch;
break;
case NFT_CMP_GT:
if (d == 0)
goto mismatch;
case NFT_CMP_GTE:
if (d < 0)
goto mismatch;
break;
}
return;
mismatch:
regs->verdict.code = NFT_BREAK;
}
static int nft_cmp_init(const struct nft_ctx *ctx, const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_cmp_expr *priv = nft_expr_priv(expr);
struct nft_data_desc desc;
int err;
err = nft_data_init(NULL, &priv->data, sizeof(priv->data), &desc,
tb[NFTA_CMP_DATA]);
BUG_ON(err < 0);
priv->sreg = nft_parse_register(tb[NFTA_CMP_SREG]);
err = nft_validate_register_load(priv->sreg, desc.len);
if (err < 0)
return err;
if (desc.len > U8_MAX)
return -ERANGE;
priv->op = ntohl(nla_get_be32(tb[NFTA_CMP_OP]));
priv->len = desc.len;
return 0;
}
static int nft_cmp_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_cmp_expr *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_CMP_SREG, priv->sreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_CMP_OP, htonl(priv->op)))
goto nla_put_failure;
if (nft_data_dump(skb, NFTA_CMP_DATA, &priv->data,
NFT_DATA_VALUE, priv->len) < 0)
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int nft_cmp_fast_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_cmp_fast_expr *priv = nft_expr_priv(expr);
struct nft_data_desc desc;
struct nft_data data;
u32 mask;
int err;
err = nft_data_init(NULL, &data, sizeof(data), &desc,
tb[NFTA_CMP_DATA]);
BUG_ON(err < 0);
priv->sreg = nft_parse_register(tb[NFTA_CMP_SREG]);
err = nft_validate_register_load(priv->sreg, desc.len);
if (err < 0)
return err;
desc.len *= BITS_PER_BYTE;
mask = nft_cmp_fast_mask(desc.len);
priv->data = data.data[0] & mask;
priv->len = desc.len;
return 0;
}
static int nft_cmp_fast_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_cmp_fast_expr *priv = nft_expr_priv(expr);
struct nft_data data;
if (nft_dump_register(skb, NFTA_CMP_SREG, priv->sreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_CMP_OP, htonl(NFT_CMP_EQ)))
goto nla_put_failure;
data.data[0] = priv->data;
if (nft_data_dump(skb, NFTA_CMP_DATA, &data,
NFT_DATA_VALUE, priv->len / BITS_PER_BYTE) < 0)
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static const struct nft_expr_ops *
nft_cmp_select_ops(const struct nft_ctx *ctx, const struct nlattr * const tb[])
{
struct nft_data_desc desc;
struct nft_data data;
enum nft_cmp_ops op;
int err;
if (tb[NFTA_CMP_SREG] == NULL ||
tb[NFTA_CMP_OP] == NULL ||
tb[NFTA_CMP_DATA] == NULL)
return ERR_PTR(-EINVAL);
op = ntohl(nla_get_be32(tb[NFTA_CMP_OP]));
switch (op) {
case NFT_CMP_EQ:
case NFT_CMP_NEQ:
case NFT_CMP_LT:
case NFT_CMP_LTE:
case NFT_CMP_GT:
case NFT_CMP_GTE:
break;
default:
return ERR_PTR(-EINVAL);
}
err = nft_data_init(NULL, &data, sizeof(data), &desc,
tb[NFTA_CMP_DATA]);
if (err < 0)
return ERR_PTR(err);
if (desc.len <= sizeof(u32) && op == NFT_CMP_EQ)
return &nft_cmp_fast_ops;
else
return &nft_cmp_ops;
}
int __init nft_cmp_module_init(void)
{
return nft_register_expr(&nft_cmp_type);
}
void nft_cmp_module_exit(void)
{
nft_unregister_expr(&nft_cmp_type);
}
