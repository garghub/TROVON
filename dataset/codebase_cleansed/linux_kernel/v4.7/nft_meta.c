void nft_meta_get_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_meta *priv = nft_expr_priv(expr);
const struct sk_buff *skb = pkt->skb;
const struct net_device *in = pkt->in, *out = pkt->out;
struct sock *sk;
u32 *dest = &regs->data[priv->dreg];
switch (priv->key) {
case NFT_META_LEN:
*dest = skb->len;
break;
case NFT_META_PROTOCOL:
*dest = 0;
*(__be16 *)dest = skb->protocol;
break;
case NFT_META_NFPROTO:
*dest = pkt->pf;
break;
case NFT_META_L4PROTO:
*dest = pkt->tprot;
break;
case NFT_META_PRIORITY:
*dest = skb->priority;
break;
case NFT_META_MARK:
*dest = skb->mark;
break;
case NFT_META_IIF:
if (in == NULL)
goto err;
*dest = in->ifindex;
break;
case NFT_META_OIF:
if (out == NULL)
goto err;
*dest = out->ifindex;
break;
case NFT_META_IIFNAME:
if (in == NULL)
goto err;
strncpy((char *)dest, in->name, IFNAMSIZ);
break;
case NFT_META_OIFNAME:
if (out == NULL)
goto err;
strncpy((char *)dest, out->name, IFNAMSIZ);
break;
case NFT_META_IIFTYPE:
if (in == NULL)
goto err;
*dest = 0;
*(u16 *)dest = in->type;
break;
case NFT_META_OIFTYPE:
if (out == NULL)
goto err;
*dest = 0;
*(u16 *)dest = out->type;
break;
case NFT_META_SKUID:
sk = skb_to_full_sk(skb);
if (!sk || !sk_fullsock(sk))
goto err;
read_lock_bh(&sk->sk_callback_lock);
if (sk->sk_socket == NULL ||
sk->sk_socket->file == NULL) {
read_unlock_bh(&sk->sk_callback_lock);
goto err;
}
*dest = from_kuid_munged(&init_user_ns,
sk->sk_socket->file->f_cred->fsuid);
read_unlock_bh(&sk->sk_callback_lock);
break;
case NFT_META_SKGID:
sk = skb_to_full_sk(skb);
if (!sk || !sk_fullsock(sk))
goto err;
read_lock_bh(&sk->sk_callback_lock);
if (sk->sk_socket == NULL ||
sk->sk_socket->file == NULL) {
read_unlock_bh(&sk->sk_callback_lock);
goto err;
}
*dest = from_kgid_munged(&init_user_ns,
sk->sk_socket->file->f_cred->fsgid);
read_unlock_bh(&sk->sk_callback_lock);
break;
#ifdef CONFIG_IP_ROUTE_CLASSID
case NFT_META_RTCLASSID: {
const struct dst_entry *dst = skb_dst(skb);
if (dst == NULL)
goto err;
*dest = dst->tclassid;
break;
}
#endif
#ifdef CONFIG_NETWORK_SECMARK
case NFT_META_SECMARK:
*dest = skb->secmark;
break;
#endif
case NFT_META_PKTTYPE:
if (skb->pkt_type != PACKET_LOOPBACK) {
*dest = skb->pkt_type;
break;
}
switch (pkt->pf) {
case NFPROTO_IPV4:
if (ipv4_is_multicast(ip_hdr(skb)->daddr))
*dest = PACKET_MULTICAST;
else
*dest = PACKET_BROADCAST;
break;
case NFPROTO_IPV6:
if (ipv6_hdr(skb)->daddr.s6_addr[0] == 0xFF)
*dest = PACKET_MULTICAST;
else
*dest = PACKET_BROADCAST;
break;
default:
WARN_ON(1);
goto err;
}
break;
case NFT_META_CPU:
*dest = raw_smp_processor_id();
break;
case NFT_META_IIFGROUP:
if (in == NULL)
goto err;
*dest = in->group;
break;
case NFT_META_OIFGROUP:
if (out == NULL)
goto err;
*dest = out->group;
break;
#ifdef CONFIG_CGROUP_NET_CLASSID
case NFT_META_CGROUP:
sk = skb_to_full_sk(skb);
if (!sk || !sk_fullsock(sk))
goto err;
*dest = sock_cgroup_classid(&sk->sk_cgrp_data);
break;
#endif
case NFT_META_PRANDOM: {
struct rnd_state *state = this_cpu_ptr(&nft_prandom_state);
*dest = prandom_u32_state(state);
break;
}
default:
WARN_ON(1);
goto err;
}
return;
err:
regs->verdict.code = NFT_BREAK;
}
static bool pkt_type_ok(u32 p)
{
return p == PACKET_HOST || p == PACKET_BROADCAST ||
p == PACKET_MULTICAST || p == PACKET_OTHERHOST;
}
void nft_meta_set_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_meta *meta = nft_expr_priv(expr);
struct sk_buff *skb = pkt->skb;
u32 value = regs->data[meta->sreg];
switch (meta->key) {
case NFT_META_MARK:
skb->mark = value;
break;
case NFT_META_PRIORITY:
skb->priority = value;
break;
case NFT_META_PKTTYPE:
if (skb->pkt_type != value &&
pkt_type_ok(value) && pkt_type_ok(skb->pkt_type))
skb->pkt_type = value;
break;
case NFT_META_NFTRACE:
skb->nf_trace = !!value;
break;
default:
WARN_ON(1);
}
}
int nft_meta_get_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_meta *priv = nft_expr_priv(expr);
unsigned int len;
priv->key = ntohl(nla_get_be32(tb[NFTA_META_KEY]));
switch (priv->key) {
case NFT_META_PROTOCOL:
case NFT_META_IIFTYPE:
case NFT_META_OIFTYPE:
len = sizeof(u16);
break;
case NFT_META_NFPROTO:
case NFT_META_L4PROTO:
case NFT_META_LEN:
case NFT_META_PRIORITY:
case NFT_META_MARK:
case NFT_META_IIF:
case NFT_META_OIF:
case NFT_META_SKUID:
case NFT_META_SKGID:
#ifdef CONFIG_IP_ROUTE_CLASSID
case NFT_META_RTCLASSID:
#endif
#ifdef CONFIG_NETWORK_SECMARK
case NFT_META_SECMARK:
#endif
case NFT_META_PKTTYPE:
case NFT_META_CPU:
case NFT_META_IIFGROUP:
case NFT_META_OIFGROUP:
#ifdef CONFIG_CGROUP_NET_CLASSID
case NFT_META_CGROUP:
#endif
len = sizeof(u32);
break;
case NFT_META_IIFNAME:
case NFT_META_OIFNAME:
len = IFNAMSIZ;
break;
case NFT_META_PRANDOM:
prandom_init_once(&nft_prandom_state);
len = sizeof(u32);
break;
default:
return -EOPNOTSUPP;
}
priv->dreg = nft_parse_register(tb[NFTA_META_DREG]);
return nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, len);
}
static int nft_meta_set_init_pkttype(const struct nft_ctx *ctx)
{
unsigned int hooks;
switch (ctx->afi->family) {
case NFPROTO_BRIDGE:
hooks = 1 << NF_BR_PRE_ROUTING;
break;
case NFPROTO_NETDEV:
hooks = 1 << NF_NETDEV_INGRESS;
break;
default:
return -EOPNOTSUPP;
}
return nft_chain_validate_hooks(ctx->chain, hooks);
}
int nft_meta_set_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_meta *priv = nft_expr_priv(expr);
unsigned int len;
int err;
priv->key = ntohl(nla_get_be32(tb[NFTA_META_KEY]));
switch (priv->key) {
case NFT_META_MARK:
case NFT_META_PRIORITY:
len = sizeof(u32);
break;
case NFT_META_NFTRACE:
len = sizeof(u8);
break;
case NFT_META_PKTTYPE:
err = nft_meta_set_init_pkttype(ctx);
if (err)
return err;
len = sizeof(u8);
break;
default:
return -EOPNOTSUPP;
}
priv->sreg = nft_parse_register(tb[NFTA_META_SREG]);
err = nft_validate_register_load(priv->sreg, len);
if (err < 0)
return err;
if (priv->key == NFT_META_NFTRACE)
static_branch_inc(&nft_trace_enabled);
return 0;
}
int nft_meta_get_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_meta *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_META_KEY, htonl(priv->key)))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_META_DREG, priv->dreg))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
int nft_meta_set_dump(struct sk_buff *skb,
const struct nft_expr *expr)
{
const struct nft_meta *priv = nft_expr_priv(expr);
if (nla_put_be32(skb, NFTA_META_KEY, htonl(priv->key)))
goto nla_put_failure;
if (nft_dump_register(skb, NFTA_META_SREG, priv->sreg))
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
void nft_meta_set_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
const struct nft_meta *priv = nft_expr_priv(expr);
if (priv->key == NFT_META_NFTRACE)
static_branch_dec(&nft_trace_enabled);
}
static const struct nft_expr_ops *
nft_meta_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
if (tb[NFTA_META_KEY] == NULL)
return ERR_PTR(-EINVAL);
if (tb[NFTA_META_DREG] && tb[NFTA_META_SREG])
return ERR_PTR(-EINVAL);
if (tb[NFTA_META_DREG])
return &nft_meta_get_ops;
if (tb[NFTA_META_SREG])
return &nft_meta_set_ops;
return ERR_PTR(-EINVAL);
}
static int __init nft_meta_module_init(void)
{
return nft_register_expr(&nft_meta_type);
}
static void __exit nft_meta_module_exit(void)
{
nft_unregister_expr(&nft_meta_type);
}
