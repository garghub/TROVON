static void nft_objref_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_object *obj = nft_objref_priv(expr);
obj->type->eval(obj, regs, pkt);
}
static int nft_objref_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_object *obj = nft_objref_priv(expr);
u8 genmask = nft_genmask_next(ctx->net);
u32 objtype;
if (!tb[NFTA_OBJREF_IMM_NAME] ||
!tb[NFTA_OBJREF_IMM_TYPE])
return -EINVAL;
objtype = ntohl(nla_get_be32(tb[NFTA_OBJREF_IMM_TYPE]));
obj = nf_tables_obj_lookup(ctx->table, tb[NFTA_OBJREF_IMM_NAME], objtype,
genmask);
if (IS_ERR(obj))
return -ENOENT;
nft_objref_priv(expr) = obj;
obj->use++;
return 0;
}
static int nft_objref_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_object *obj = nft_objref_priv(expr);
if (nla_put_string(skb, NFTA_OBJREF_IMM_NAME, obj->name) ||
nla_put_be32(skb, NFTA_OBJREF_IMM_TYPE, htonl(obj->type->type)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static void nft_objref_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_object *obj = nft_objref_priv(expr);
obj->use--;
}
static void nft_objref_map_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nft_objref_map *priv = nft_expr_priv(expr);
const struct nft_set *set = priv->set;
const struct nft_set_ext *ext;
struct nft_object *obj;
bool found;
found = set->ops->lookup(nft_net(pkt), set, &regs->data[priv->sreg],
&ext);
if (!found) {
regs->verdict.code = NFT_BREAK;
return;
}
obj = *nft_set_ext_obj(ext);
obj->type->eval(obj, regs, pkt);
}
static int nft_objref_map_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_objref_map *priv = nft_expr_priv(expr);
u8 genmask = nft_genmask_next(ctx->net);
struct nft_set *set;
int err;
set = nf_tables_set_lookup(ctx->table, tb[NFTA_OBJREF_SET_NAME], genmask);
if (IS_ERR(set)) {
if (tb[NFTA_OBJREF_SET_ID]) {
set = nf_tables_set_lookup_byid(ctx->net,
tb[NFTA_OBJREF_SET_ID],
genmask);
}
if (IS_ERR(set))
return PTR_ERR(set);
}
if (!(set->flags & NFT_SET_OBJECT))
return -EINVAL;
priv->sreg = nft_parse_register(tb[NFTA_OBJREF_SET_SREG]);
err = nft_validate_register_load(priv->sreg, set->klen);
if (err < 0)
return err;
priv->binding.flags = set->flags & NFT_SET_OBJECT;
err = nf_tables_bind_set(ctx, set, &priv->binding);
if (err < 0)
return err;
priv->set = set;
return 0;
}
static int nft_objref_map_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_objref_map *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_OBJREF_SET_SREG, priv->sreg) ||
nla_put_string(skb, NFTA_OBJREF_SET_NAME, priv->set->name))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static void nft_objref_map_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_objref_map *priv = nft_expr_priv(expr);
nf_tables_unbind_set(ctx, priv->set, &priv->binding);
}
static const struct nft_expr_ops *
nft_objref_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
if (tb[NFTA_OBJREF_SET_SREG] &&
(tb[NFTA_OBJREF_SET_NAME] ||
tb[NFTA_OBJREF_SET_ID]))
return &nft_objref_map_ops;
else if (tb[NFTA_OBJREF_IMM_NAME] &&
tb[NFTA_OBJREF_IMM_TYPE])
return &nft_objref_ops;
return ERR_PTR(-EOPNOTSUPP);
}
static int __init nft_objref_module_init(void)
{
return nft_register_expr(&nft_objref_type);
}
static void __exit nft_objref_module_exit(void)
{
nft_unregister_expr(&nft_objref_type);
}
