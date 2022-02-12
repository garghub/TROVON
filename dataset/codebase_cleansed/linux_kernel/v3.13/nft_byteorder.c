static void nft_byteorder_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_byteorder *priv = nft_expr_priv(expr);
struct nft_data *src = &data[priv->sreg], *dst = &data[priv->dreg];
union { u32 u32; u16 u16; } *s, *d;
unsigned int i;
s = (void *)src->data;
d = (void *)dst->data;
switch (priv->size) {
case 4:
switch (priv->op) {
case NFT_BYTEORDER_NTOH:
for (i = 0; i < priv->len / 4; i++)
d[i].u32 = ntohl((__force __be32)s[i].u32);
break;
case NFT_BYTEORDER_HTON:
for (i = 0; i < priv->len / 4; i++)
d[i].u32 = (__force __u32)htonl(s[i].u32);
break;
}
break;
case 2:
switch (priv->op) {
case NFT_BYTEORDER_NTOH:
for (i = 0; i < priv->len / 2; i++)
d[i].u16 = ntohs((__force __be16)s[i].u16);
break;
case NFT_BYTEORDER_HTON:
for (i = 0; i < priv->len / 2; i++)
d[i].u16 = (__force __u16)htons(s[i].u16);
break;
}
break;
}
}
static int nft_byteorder_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_byteorder *priv = nft_expr_priv(expr);
int err;
if (tb[NFTA_BYTEORDER_SREG] == NULL ||
tb[NFTA_BYTEORDER_DREG] == NULL ||
tb[NFTA_BYTEORDER_LEN] == NULL ||
tb[NFTA_BYTEORDER_SIZE] == NULL ||
tb[NFTA_BYTEORDER_OP] == NULL)
return -EINVAL;
priv->sreg = ntohl(nla_get_be32(tb[NFTA_BYTEORDER_SREG]));
err = nft_validate_input_register(priv->sreg);
if (err < 0)
return err;
priv->dreg = ntohl(nla_get_be32(tb[NFTA_BYTEORDER_DREG]));
err = nft_validate_output_register(priv->dreg);
if (err < 0)
return err;
err = nft_validate_data_load(ctx, priv->dreg, NULL, NFT_DATA_VALUE);
if (err < 0)
return err;
priv->op = ntohl(nla_get_be32(tb[NFTA_BYTEORDER_OP]));
switch (priv->op) {
case NFT_BYTEORDER_NTOH:
case NFT_BYTEORDER_HTON:
break;
default:
return -EINVAL;
}
priv->len = ntohl(nla_get_be32(tb[NFTA_BYTEORDER_LEN]));
if (priv->len == 0 || priv->len > FIELD_SIZEOF(struct nft_data, data))
return -EINVAL;
priv->size = ntohl(nla_get_be32(tb[NFTA_BYTEORDER_SIZE]));
switch (priv->size) {
case 2:
case 4:
break;
default:
return -EINVAL;
}
return 0;
}
static int nft_byteorder_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_byteorder *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_BYTEORDER_SREG, htonl(priv->sreg)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_BYTEORDER_DREG, htonl(priv->dreg)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_BYTEORDER_OP, htonl(priv->op)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_BYTEORDER_LEN, htonl(priv->len)))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_BYTEORDER_SIZE, htonl(priv->size)))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
int __init nft_byteorder_module_init(void)
{
return nft_register_expr(&nft_byteorder_type);
}
void nft_byteorder_module_exit(void)
{
nft_unregister_expr(&nft_byteorder_type);
}
