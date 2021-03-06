static void nft_byteorder_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_byteorder *priv = nft_expr_priv(expr);
u32 *src = &regs->data[priv->sreg];
u32 *dst = &regs->data[priv->dreg];
union { u32 u32; u16 u16; } *s, *d;
unsigned int i;
s = (void *)src;
d = (void *)dst;
switch (priv->size) {
case 8: {
u64 src64;
switch (priv->op) {
case NFT_BYTEORDER_NTOH:
for (i = 0; i < priv->len / 8; i++) {
src64 = get_unaligned((u64 *)&src[i]);
put_unaligned_be64(src64, &dst[i]);
}
break;
case NFT_BYTEORDER_HTON:
for (i = 0; i < priv->len / 8; i++) {
src64 = get_unaligned_be64(&src[i]);
put_unaligned(src64, (u64 *)&dst[i]);
}
break;
}
break;
}
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
u32 size, len;
int err;
if (tb[NFTA_BYTEORDER_SREG] == NULL ||
tb[NFTA_BYTEORDER_DREG] == NULL ||
tb[NFTA_BYTEORDER_LEN] == NULL ||
tb[NFTA_BYTEORDER_SIZE] == NULL ||
tb[NFTA_BYTEORDER_OP] == NULL)
return -EINVAL;
priv->op = ntohl(nla_get_be32(tb[NFTA_BYTEORDER_OP]));
switch (priv->op) {
case NFT_BYTEORDER_NTOH:
case NFT_BYTEORDER_HTON:
break;
default:
return -EINVAL;
}
err = nft_parse_u32_check(tb[NFTA_BYTEORDER_SIZE], U8_MAX, &size);
if (err < 0)
return err;
priv->size = size;
switch (priv->size) {
case 2:
case 4:
case 8:
break;
default:
return -EINVAL;
}
priv->sreg = nft_parse_register(tb[NFTA_BYTEORDER_SREG]);
err = nft_parse_u32_check(tb[NFTA_BYTEORDER_LEN], U8_MAX, &len);
if (err < 0)
return err;
priv->len = len;
err = nft_validate_register_load(priv->sreg, priv->len);
if (err < 0)
return err;
priv->dreg = nft_parse_register(tb[NFTA_BYTEORDER_DREG]);
return nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, priv->len);
}
static int nft_byteorder_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_byteorder *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_BYTEORDER_SREG, priv->sreg))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_BYTEORDER_DREG, priv->dreg))
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
