static inline struct xfrm4_protocol __rcu **proto_handlers(u8 protocol)
{
switch (protocol) {
case IPPROTO_ESP:
return &esp4_handlers;
case IPPROTO_AH:
return &ah4_handlers;
case IPPROTO_COMP:
return &ipcomp4_handlers;
}
return NULL;
}
int xfrm4_rcv_encap(struct sk_buff *skb, int nexthdr, __be32 spi,
int encap_type)
{
int ret;
struct xfrm4_protocol *handler;
struct xfrm4_protocol __rcu **head = proto_handlers(nexthdr);
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip4 = NULL;
XFRM_SPI_SKB_CB(skb)->family = AF_INET;
XFRM_SPI_SKB_CB(skb)->daddroff = offsetof(struct iphdr, daddr);
if (!head)
goto out;
for_each_protocol_rcu(*head, handler)
if ((ret = handler->input_handler(skb, nexthdr, spi, encap_type)) != -EINVAL)
return ret;
out:
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static int xfrm4_esp_rcv(struct sk_buff *skb)
{
int ret;
struct xfrm4_protocol *handler;
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip4 = NULL;
for_each_protocol_rcu(esp4_handlers, handler)
if ((ret = handler->handler(skb)) != -EINVAL)
return ret;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static void xfrm4_esp_err(struct sk_buff *skb, u32 info)
{
struct xfrm4_protocol *handler;
for_each_protocol_rcu(esp4_handlers, handler)
if (!handler->err_handler(skb, info))
break;
}
static int xfrm4_ah_rcv(struct sk_buff *skb)
{
int ret;
struct xfrm4_protocol *handler;
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip4 = NULL;
for_each_protocol_rcu(ah4_handlers, handler)
if ((ret = handler->handler(skb)) != -EINVAL)
return ret;;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static void xfrm4_ah_err(struct sk_buff *skb, u32 info)
{
struct xfrm4_protocol *handler;
for_each_protocol_rcu(ah4_handlers, handler)
if (!handler->err_handler(skb, info))
break;
}
static int xfrm4_ipcomp_rcv(struct sk_buff *skb)
{
int ret;
struct xfrm4_protocol *handler;
XFRM_TUNNEL_SKB_CB(skb)->tunnel.ip4 = NULL;
for_each_protocol_rcu(ipcomp4_handlers, handler)
if ((ret = handler->handler(skb)) != -EINVAL)
return ret;
icmp_send(skb, ICMP_DEST_UNREACH, ICMP_PORT_UNREACH, 0);
kfree_skb(skb);
return 0;
}
static void xfrm4_ipcomp_err(struct sk_buff *skb, u32 info)
{
struct xfrm4_protocol *handler;
for_each_protocol_rcu(ipcomp4_handlers, handler)
if (!handler->err_handler(skb, info))
break;
}
static inline const struct net_protocol *netproto(unsigned char protocol)
{
switch (protocol) {
case IPPROTO_ESP:
return &esp4_protocol;
case IPPROTO_AH:
return &ah4_protocol;
case IPPROTO_COMP:
return &ipcomp4_protocol;
}
return NULL;
}
int xfrm4_protocol_register(struct xfrm4_protocol *handler,
unsigned char protocol)
{
struct xfrm4_protocol __rcu **pprev;
struct xfrm4_protocol *t;
bool add_netproto = false;
int ret = -EEXIST;
int priority = handler->priority;
if (!proto_handlers(protocol) || !netproto(protocol))
return -EINVAL;
mutex_lock(&xfrm4_protocol_mutex);
if (!rcu_dereference_protected(*proto_handlers(protocol),
lockdep_is_held(&xfrm4_protocol_mutex)))
add_netproto = true;
for (pprev = proto_handlers(protocol);
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&xfrm4_protocol_mutex))) != NULL;
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
mutex_unlock(&xfrm4_protocol_mutex);
if (add_netproto) {
if (inet_add_protocol(netproto(protocol), protocol)) {
pr_err("%s: can't add protocol\n", __func__);
ret = -EAGAIN;
}
}
return ret;
}
int xfrm4_protocol_deregister(struct xfrm4_protocol *handler,
unsigned char protocol)
{
struct xfrm4_protocol __rcu **pprev;
struct xfrm4_protocol *t;
int ret = -ENOENT;
if (!proto_handlers(protocol) || !netproto(protocol))
return -EINVAL;
mutex_lock(&xfrm4_protocol_mutex);
for (pprev = proto_handlers(protocol);
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&xfrm4_protocol_mutex))) != NULL;
pprev = &t->next) {
if (t == handler) {
*pprev = handler->next;
ret = 0;
break;
}
}
if (!rcu_dereference_protected(*proto_handlers(protocol),
lockdep_is_held(&xfrm4_protocol_mutex))) {
if (inet_del_protocol(netproto(protocol), protocol) < 0) {
pr_err("%s: can't remove protocol\n", __func__);
ret = -EAGAIN;
}
}
mutex_unlock(&xfrm4_protocol_mutex);
synchronize_net();
return ret;
}
void __init xfrm4_protocol_init(void)
{
xfrm_input_register_afinfo(&xfrm4_input_afinfo);
}
