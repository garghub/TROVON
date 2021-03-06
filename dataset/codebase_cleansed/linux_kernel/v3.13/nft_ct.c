static void nft_ct_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_ct *priv = nft_expr_priv(expr);
struct nft_data *dest = &data[priv->dreg];
enum ip_conntrack_info ctinfo;
const struct nf_conn *ct;
const struct nf_conn_help *help;
const struct nf_conntrack_tuple *tuple;
const struct nf_conntrack_helper *helper;
long diff;
unsigned int state;
ct = nf_ct_get(pkt->skb, &ctinfo);
switch (priv->key) {
case NFT_CT_STATE:
if (ct == NULL)
state = NF_CT_STATE_INVALID_BIT;
else if (nf_ct_is_untracked(ct))
state = NF_CT_STATE_UNTRACKED_BIT;
else
state = NF_CT_STATE_BIT(ctinfo);
dest->data[0] = state;
return;
}
if (ct == NULL)
goto err;
switch (priv->key) {
case NFT_CT_DIRECTION:
dest->data[0] = CTINFO2DIR(ctinfo);
return;
case NFT_CT_STATUS:
dest->data[0] = ct->status;
return;
#ifdef CONFIG_NF_CONNTRACK_MARK
case NFT_CT_MARK:
dest->data[0] = ct->mark;
return;
#endif
#ifdef CONFIG_NF_CONNTRACK_SECMARK
case NFT_CT_SECMARK:
dest->data[0] = ct->secmark;
return;
#endif
case NFT_CT_EXPIRATION:
diff = (long)jiffies - (long)ct->timeout.expires;
if (diff < 0)
diff = 0;
dest->data[0] = jiffies_to_msecs(diff);
return;
case NFT_CT_HELPER:
if (ct->master == NULL)
goto err;
help = nfct_help(ct->master);
if (help == NULL)
goto err;
helper = rcu_dereference(help->helper);
if (helper == NULL)
goto err;
if (strlen(helper->name) >= sizeof(dest->data))
goto err;
strncpy((char *)dest->data, helper->name, sizeof(dest->data));
return;
}
tuple = &ct->tuplehash[priv->dir].tuple;
switch (priv->key) {
case NFT_CT_L3PROTOCOL:
dest->data[0] = nf_ct_l3num(ct);
return;
case NFT_CT_SRC:
memcpy(dest->data, tuple->src.u3.all,
nf_ct_l3num(ct) == NFPROTO_IPV4 ? 4 : 16);
return;
case NFT_CT_DST:
memcpy(dest->data, tuple->dst.u3.all,
nf_ct_l3num(ct) == NFPROTO_IPV4 ? 4 : 16);
return;
case NFT_CT_PROTOCOL:
dest->data[0] = nf_ct_protonum(ct);
return;
case NFT_CT_PROTO_SRC:
dest->data[0] = (__force __u16)tuple->src.u.all;
return;
case NFT_CT_PROTO_DST:
dest->data[0] = (__force __u16)tuple->dst.u.all;
return;
}
return;
err:
data[NFT_REG_VERDICT].verdict = NFT_BREAK;
}
static int nft_ct_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_ct *priv = nft_expr_priv(expr);
int err;
if (tb[NFTA_CT_DREG] == NULL ||
tb[NFTA_CT_KEY] == NULL)
return -EINVAL;
priv->key = ntohl(nla_get_be32(tb[NFTA_CT_KEY]));
if (tb[NFTA_CT_DIRECTION] != NULL) {
priv->dir = nla_get_u8(tb[NFTA_CT_DIRECTION]);
switch (priv->dir) {
case IP_CT_DIR_ORIGINAL:
case IP_CT_DIR_REPLY:
break;
default:
return -EINVAL;
}
}
switch (priv->key) {
case NFT_CT_STATE:
case NFT_CT_DIRECTION:
case NFT_CT_STATUS:
#ifdef CONFIG_NF_CONNTRACK_MARK
case NFT_CT_MARK:
#endif
#ifdef CONFIG_NF_CONNTRACK_SECMARK
case NFT_CT_SECMARK:
#endif
case NFT_CT_EXPIRATION:
case NFT_CT_HELPER:
if (tb[NFTA_CT_DIRECTION] != NULL)
return -EINVAL;
break;
case NFT_CT_PROTOCOL:
case NFT_CT_SRC:
case NFT_CT_DST:
case NFT_CT_PROTO_SRC:
case NFT_CT_PROTO_DST:
if (tb[NFTA_CT_DIRECTION] == NULL)
return -EINVAL;
break;
default:
return -EOPNOTSUPP;
}
err = nf_ct_l3proto_try_module_get(ctx->afi->family);
if (err < 0)
return err;
priv->family = ctx->afi->family;
priv->dreg = ntohl(nla_get_be32(tb[NFTA_CT_DREG]));
err = nft_validate_output_register(priv->dreg);
if (err < 0)
goto err1;
err = nft_validate_data_load(ctx, priv->dreg, NULL, NFT_DATA_VALUE);
if (err < 0)
goto err1;
return 0;
err1:
nf_ct_l3proto_module_put(ctx->afi->family);
return err;
}
static void nft_ct_destroy(const struct nft_expr *expr)
{
struct nft_ct *priv = nft_expr_priv(expr);
nf_ct_l3proto_module_put(priv->family);
}
static int nft_ct_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_ct *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_CT_DREG, htonl(priv->dreg)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_CT_KEY, htonl(priv->key)))
goto nla_put_failure;
if (nla_put_u8(skb, NFTA_CT_DIRECTION, priv->dir))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init nft_ct_module_init(void)
{
return nft_register_expr(&nft_ct_type);
}
static void __exit nft_ct_module_exit(void)
{
nft_unregister_expr(&nft_ct_type);
}
