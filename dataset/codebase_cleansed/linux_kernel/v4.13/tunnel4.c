static inline struct xfrm_tunnel __rcu **fam_handlers(unsigned short family)
{
return (family == AF_INET) ? &tunnel4_handlers :
(family == AF_INET6) ? &tunnel64_handlers :
&tunnelmpls4_handlers;
}
int xfrm4_tunnel_register(struct xfrm_tunnel *handler, unsigned short family)
{
struct xfrm_tunnel __rcu **pprev;
struct xfrm_tunnel *t;
int ret = -EEXIST;
int priority = handler->priority;
mutex_lock(&tunnel4_mutex);
for (pprev = fam_handlers(family);
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&tunnel4_mutex))) != NULL;
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
mutex_unlock(&tunnel4_mutex);
return ret;
}
int xfrm4_tunnel_deregister(struct xfrm_tunnel *handler, unsigned short family)
{
struct xfrm_tunnel __rcu **pprev;
struct xfrm_tunnel *t;
int ret = -ENOENT;
mutex_lock(&tunnel4_mutex);
for (pprev = fam_handlers(family);
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&tunnel4_mutex))) != NULL;
pprev = &t->next) {
if (t == handler) {
*pprev = handler->next;
ret = 0;
break;
}
}
mutex_unlock(&tunnel4_mutex);
synchronize_net();
return ret;
}
static int tunnel4_rcv(struct sk_buff *skb)
{
struct xfrm_tunnel *handler;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto drop;
for_each_tunnel_rcu(tunnel4_handlers, handler)
if (!handler->handler(skb))
return 0;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static int tunnel64_rcv(struct sk_buff *skb)
{
struct xfrm_tunnel *handler;
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
goto drop;
for_each_tunnel_rcu(tunnel64_handlers, handler)
if (!handler->handler(skb))
return 0;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static int tunnelmpls4_rcv(struct sk_buff *skb)
{
struct xfrm_tunnel *handler;
if (!pskb_may_pull(skb, sizeof(struct mpls_label)))
goto drop;
for_each_tunnel_rcu(tunnelmpls4_handlers, handler)
if (!handler->handler(skb))
return 0;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
drop:
kfree_skb(skb);
return 0;
}
static void tunnel4_err(struct sk_buff *skb, u32 info)
{
struct xfrm_tunnel *handler;
for_each_tunnel_rcu(tunnel4_handlers, handler)
if (!handler->err_handler(skb, info))
break;
}
static void tunnel64_err(struct sk_buff *skb, u32 info)
{
struct xfrm_tunnel *handler;
for_each_tunnel_rcu(tunnel64_handlers, handler)
if (!handler->err_handler(skb, info))
break;
}
static void tunnelmpls4_err(struct sk_buff *skb, u32 info)
{
struct xfrm_tunnel *handler;
for_each_tunnel_rcu(tunnelmpls4_handlers, handler)
if (!handler->err_handler(skb, info))
break;
}
static int __init tunnel4_init(void)
{
if (inet_add_protocol(&tunnel4_protocol, IPPROTO_IPIP))
goto err;
#if IS_ENABLED(CONFIG_IPV6)
if (inet_add_protocol(&tunnel64_protocol, IPPROTO_IPV6)) {
inet_del_protocol(&tunnel4_protocol, IPPROTO_IPIP);
goto err;
}
#endif
#if IS_ENABLED(CONFIG_MPLS)
if (inet_add_protocol(&tunnelmpls4_protocol, IPPROTO_MPLS)) {
inet_del_protocol(&tunnel4_protocol, IPPROTO_IPIP);
#if IS_ENABLED(CONFIG_IPV6)
inet_del_protocol(&tunnel64_protocol, IPPROTO_IPV6);
#endif
goto err;
}
#endif
return 0;
err:
pr_err("%s: can't add protocol\n", __func__);
return -EAGAIN;
}
static void __exit tunnel4_fini(void)
{
#if IS_ENABLED(CONFIG_MPLS)
if (inet_del_protocol(&tunnelmpls4_protocol, IPPROTO_MPLS))
pr_err("tunnelmpls4 close: can't remove protocol\n");
#endif
#if IS_ENABLED(CONFIG_IPV6)
if (inet_del_protocol(&tunnel64_protocol, IPPROTO_IPV6))
pr_err("tunnel64 close: can't remove protocol\n");
#endif
if (inet_del_protocol(&tunnel4_protocol, IPPROTO_IPIP))
pr_err("tunnel4 close: can't remove protocol\n");
}
