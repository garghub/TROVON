int xfrm6_tunnel_register(struct xfrm6_tunnel *handler, unsigned short family)
{
struct xfrm6_tunnel __rcu **pprev;
struct xfrm6_tunnel *t;
int ret = -EEXIST;
int priority = handler->priority;
mutex_lock(&tunnel6_mutex);
for (pprev = (family == AF_INET6) ? &tunnel6_handlers : &tunnel46_handlers;
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&tunnel6_mutex))) != NULL;
pprev = &t->next) {
if (t->priority > priority)
break;
if (t->priority == priority)
goto err;
}
handler->next = *pprev;
rcu_assign_pointer(*pprev, handler);
ret = 0;
err:
mutex_unlock(&tunnel6_mutex);
return ret;
}
int xfrm6_tunnel_deregister(struct xfrm6_tunnel *handler, unsigned short family)
{
struct xfrm6_tunnel __rcu **pprev;
struct xfrm6_tunnel *t;
int ret = -ENOENT;
mutex_lock(&tunnel6_mutex);
for (pprev = (family == AF_INET6) ? &tunnel6_handlers : &tunnel46_handlers;
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&tunnel6_mutex))) != NULL;
pprev = &t->next) {
if (t == handler) {
*pprev = handler->next;
ret = 0;
break;
}
}
mutex_unlock(&tunnel6_mutex);
synchronize_net();
return ret;
}
static int tunnel46_rcv(struct sk_buff *skb)
{
struct xfrm6_tunnel *handler;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto drop;
for_each_tunnel_rcu(tunnel46_handlers, handler)
if (!handler->handler(skb))
return 0;
icmpv6_send(skb, ICMPV6_DEST_UNREACH, ICMPV6_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static void tunnel6_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
struct xfrm6_tunnel *handler;
for_each_tunnel_rcu(tunnel6_handlers, handler)
if (!handler->err_handler(skb, opt, type, code, offset, info))
break;
}
static void tunnel46_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
struct xfrm6_tunnel *handler;
for_each_tunnel_rcu(tunnel46_handlers, handler)
if (!handler->err_handler(skb, opt, type, code, offset, info))
break;
}
static int __init tunnel6_init(void)
{
if (inet6_add_protocol(&tunnel6_protocol, IPPROTO_IPV6)) {
pr_err("%s: can't add protocol\n", __func__);
return -EAGAIN;
}
if (inet6_add_protocol(&tunnel46_protocol, IPPROTO_IPIP)) {
pr_err("%s: can't add protocol\n", __func__);
inet6_del_protocol(&tunnel6_protocol, IPPROTO_IPV6);
return -EAGAIN;
}
return 0;
}
static void __exit tunnel6_fini(void)
{
if (inet6_del_protocol(&tunnel46_protocol, IPPROTO_IPIP))
pr_err("%s: can't remove protocol\n", __func__);
if (inet6_del_protocol(&tunnel6_protocol, IPPROTO_IPV6))
pr_err("%s: can't remove protocol\n", __func__);
}
