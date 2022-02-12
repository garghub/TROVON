static bool
socket_match(const struct sk_buff *skb, struct xt_action_param *par,
const struct xt_socket_mtinfo1 *info)
{
struct sk_buff *pskb = (struct sk_buff *)skb;
struct sock *sk = skb->sk;
if (!sk)
sk = nf_sk_lookup_slow_v4(xt_net(par), skb, xt_in(par));
if (sk) {
bool wildcard;
bool transparent = true;
wildcard = (!(info->flags & XT_SOCKET_NOWILDCARD) &&
sk_fullsock(sk) &&
inet_sk(sk)->inet_rcv_saddr == 0);
if (info->flags & XT_SOCKET_TRANSPARENT)
transparent = nf_sk_is_transparent(sk);
if (info->flags & XT_SOCKET_RESTORESKMARK && !wildcard &&
transparent)
pskb->mark = sk->sk_mark;
if (sk != skb->sk)
sock_gen_put(sk);
if (wildcard || !transparent)
sk = NULL;
}
return sk != NULL;
}
static bool
socket_mt4_v0(const struct sk_buff *skb, struct xt_action_param *par)
{
static struct xt_socket_mtinfo1 xt_info_v0 = {
.flags = 0,
};
return socket_match(skb, par, &xt_info_v0);
}
static bool
socket_mt4_v1_v2_v3(const struct sk_buff *skb, struct xt_action_param *par)
{
return socket_match(skb, par, par->matchinfo);
}
static bool
socket_mt6_v1_v2_v3(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_socket_mtinfo1 *info = (struct xt_socket_mtinfo1 *) par->matchinfo;
struct sk_buff *pskb = (struct sk_buff *)skb;
struct sock *sk = skb->sk;
if (!sk)
sk = nf_sk_lookup_slow_v6(xt_net(par), skb, xt_in(par));
if (sk) {
bool wildcard;
bool transparent = true;
wildcard = (!(info->flags & XT_SOCKET_NOWILDCARD) &&
sk_fullsock(sk) &&
ipv6_addr_any(&sk->sk_v6_rcv_saddr));
if (info->flags & XT_SOCKET_TRANSPARENT)
transparent = nf_sk_is_transparent(sk);
if (info->flags & XT_SOCKET_RESTORESKMARK && !wildcard &&
transparent)
pskb->mark = sk->sk_mark;
if (sk != skb->sk)
sock_gen_put(sk);
if (wildcard || !transparent)
sk = NULL;
}
return sk != NULL;
}
static int socket_mt_enable_defrag(struct net *net, int family)
{
switch (family) {
case NFPROTO_IPV4:
return nf_defrag_ipv4_enable(net);
#if IS_ENABLED(CONFIG_IP6_NF_IPTABLES)
case NFPROTO_IPV6:
return nf_defrag_ipv6_enable(net);
#endif
}
WARN_ONCE(1, "Unknown family %d\n", family);
return 0;
}
static int socket_mt_v1_check(const struct xt_mtchk_param *par)
{
const struct xt_socket_mtinfo1 *info = (struct xt_socket_mtinfo1 *) par->matchinfo;
int err;
err = socket_mt_enable_defrag(par->net, par->family);
if (err)
return err;
if (info->flags & ~XT_SOCKET_FLAGS_V1) {
pr_info("unknown flags 0x%x\n", info->flags & ~XT_SOCKET_FLAGS_V1);
return -EINVAL;
}
return 0;
}
static int socket_mt_v2_check(const struct xt_mtchk_param *par)
{
const struct xt_socket_mtinfo2 *info = (struct xt_socket_mtinfo2 *) par->matchinfo;
int err;
err = socket_mt_enable_defrag(par->net, par->family);
if (err)
return err;
if (info->flags & ~XT_SOCKET_FLAGS_V2) {
pr_info("unknown flags 0x%x\n", info->flags & ~XT_SOCKET_FLAGS_V2);
return -EINVAL;
}
return 0;
}
static int socket_mt_v3_check(const struct xt_mtchk_param *par)
{
const struct xt_socket_mtinfo3 *info =
(struct xt_socket_mtinfo3 *)par->matchinfo;
int err;
err = socket_mt_enable_defrag(par->net, par->family);
if (err)
return err;
if (info->flags & ~XT_SOCKET_FLAGS_V3) {
pr_info("unknown flags 0x%x\n",
info->flags & ~XT_SOCKET_FLAGS_V3);
return -EINVAL;
}
return 0;
}
static int __init socket_mt_init(void)
{
return xt_register_matches(socket_mt_reg, ARRAY_SIZE(socket_mt_reg));
}
static void __exit socket_mt_exit(void)
{
xt_unregister_matches(socket_mt_reg, ARRAY_SIZE(socket_mt_reg));
}
