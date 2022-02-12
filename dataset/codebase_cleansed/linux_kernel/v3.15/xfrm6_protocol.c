static inline struct xfrm6_protocol __rcu **proto_handlers(u8 protocol)
{
switch (protocol) {
case IPPROTO_ESP:
return &esp6_handlers;
case IPPROTO_AH:
return &ah6_handlers;
case IPPROTO_COMP:
return &ipcomp6_handlers;
}
return NULL;
}
static int xfrm6_esp_rcv(struct sk_buff *skb)
{
int ret;
struct xfrm6_protocol *handler;
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip6 = NULL;
for_each_protocol_rcu(esp6_handlers, handler)
if ((ret = handler->handler(skb)) != -EINVAL)
return ret;
icmpv6_send(skb, ICMPV6_DEST_UNREACH, ICMPV6_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static void xfrm6_esp_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
struct xfrm6_protocol *handler;
for_each_protocol_rcu(esp6_handlers, handler)
if (!handler->err_handler(skb, opt, type, code, offset, info))
break;
}
static int xfrm6_ah_rcv(struct sk_buff *skb)
{
int ret;
struct xfrm6_protocol *handler;
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip6 = NULL;
for_each_protocol_rcu(ah6_handlers, handler)
if ((ret = handler->handler(skb)) != -EINVAL)
return ret;
icmpv6_send(skb, ICMPV6_DEST_UNREACH, ICMPV6_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static void xfrm6_ah_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
struct xfrm6_protocol *handler;
for_each_protocol_rcu(ah6_handlers, handler)
if (!handler->err_handler(skb, opt, type, code, offset, info))
break;
}
static int xfrm6_ipcomp_rcv(struct sk_buff *skb)
{
int ret;
struct xfrm6_protocol *handler;
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip6 = NULL;
for_each_protocol_rcu(ipcomp6_handlers, handler)
if ((ret = handler->handler(skb)) != -EINVAL)
return ret;
icmpv6_send(skb, ICMPV6_DEST_UNREACH, ICMPV6_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static void xfrm6_ipcomp_err(struct sk_buff *skb, struct inet6_skb_parm *opt,
u8 type, u8 code, int offset, __be32 info)
{
struct xfrm6_protocol *handler;
for_each_protocol_rcu(ipcomp6_handlers, handler)
if (!handler->err_handler(skb, opt, type, code, offset, info))
break;
}
static inline const struct inet6_protocol *netproto(unsigned char protocol)
{
switch (protocol) {
case IPPROTO_ESP:
return &esp6_protocol;
case IPPROTO_AH:
return &ah6_protocol;
case IPPROTO_COMP:
return &ipcomp6_protocol;
}
return NULL;
}
int xfrm6_protocol_register(struct xfrm6_protocol *handler,
unsigned char protocol)
{
struct xfrm6_protocol __rcu **pprev;
struct xfrm6_protocol *t;
bool add_netproto = false;
int ret = -EEXIST;
int priority = handler->priority;
if (!proto_handlers(protocol) || !netproto(protocol))
return -EINVAL;
mutex_lock(&xfrm6_protocol_mutex);
if (!rcu_dereference_protected(*proto_handlers(protocol),
lockdep_is_held(&xfrm6_protocol_mutex)))
add_netproto = true;
for (pprev = proto_handlers(protocol);
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&xfrm6_protocol_mutex))) != NULL;
pprev = &t->next) {
if (t->priority < priority)
break;
if (t->priority == priority)
goto err;
}
handler->next = *pprev;
rcu_assign_pointer(*pprev, handler);
ret = 0;
err:
mutex_unlock(&xfrm6_protocol_mutex);
if (add_netproto) {
if (inet6_add_protocol(netproto(protocol), protocol)) {
pr_err("%s: can't add protocol\n", __func__);
ret = -EAGAIN;
}
}
return ret;
}
int xfrm6_protocol_deregister(struct xfrm6_protocol *handler,
unsigned char protocol)
{
struct xfrm6_protocol __rcu **pprev;
struct xfrm6_protocol *t;
int ret = -ENOENT;
if (!proto_handlers(protocol) || !netproto(protocol))
return -EINVAL;
mutex_lock(&xfrm6_protocol_mutex);
for (pprev = proto_handlers(protocol);
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&xfrm6_protocol_mutex))) != NULL;
pprev = &t->next) {
if (t == handler) {
*pprev = handler->next;
ret = 0;
break;
}
}
if (!rcu_dereference_protected(*proto_handlers(protocol),
lockdep_is_held(&xfrm6_protocol_mutex))) {
if (inet6_del_protocol(netproto(protocol), protocol) < 0) {
pr_err("%s: can't remove protocol\n", __func__);
ret = -EAGAIN;
}
}
mutex_unlock(&xfrm6_protocol_mutex);
synchronize_net();
return ret;
}
int __init xfrm6_protocol_init(void)
{
return xfrm_input_register_afinfo(&xfrm6_input_afinfo);
}
void xfrm6_protocol_fini(void)
{
xfrm_input_unregister_afinfo(&xfrm6_input_afinfo);
}
