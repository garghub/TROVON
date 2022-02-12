int xfrm6_mode_tunnel_input_register(struct xfrm_tunnel_notifier *handler)
{
struct xfrm_tunnel_notifier __rcu **pprev;
struct xfrm_tunnel_notifier *t;
int ret = -EEXIST;
int priority = handler->priority;
mutex_lock(&xfrm6_mode_tunnel_input_mutex);
for (pprev = &rcv_notify_handlers;
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&xfrm6_mode_tunnel_input_mutex))) != NULL;
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
mutex_unlock(&xfrm6_mode_tunnel_input_mutex);
return ret;
}
int xfrm6_mode_tunnel_input_deregister(struct xfrm_tunnel_notifier *handler)
{
struct xfrm_tunnel_notifier __rcu **pprev;
struct xfrm_tunnel_notifier *t;
int ret = -ENOENT;
mutex_lock(&xfrm6_mode_tunnel_input_mutex);
for (pprev = &rcv_notify_handlers;
(t = rcu_dereference_protected(*pprev,
lockdep_is_held(&xfrm6_mode_tunnel_input_mutex))) != NULL;
pprev = &t->next) {
if (t == handler) {
*pprev = handler->next;
ret = 0;
break;
}
}
mutex_unlock(&xfrm6_mode_tunnel_input_mutex);
synchronize_net();
return ret;
}
static inline void ipip6_ecn_decapsulate(struct sk_buff *skb)
{
const struct ipv6hdr *outer_iph = ipv6_hdr(skb);
struct ipv6hdr *inner_iph = ipipv6_hdr(skb);
if (INET_ECN_is_ce(ipv6_get_dsfield(outer_iph)))
IP6_ECN_set_ce(inner_iph);
}
static int xfrm6_mode_tunnel_output(struct xfrm_state *x, struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct ipv6hdr *top_iph;
int dsfield;
skb_set_network_header(skb, -x->props.header_len);
skb->mac_header = skb->network_header +
offsetof(struct ipv6hdr, nexthdr);
skb->transport_header = skb->network_header + sizeof(*top_iph);
top_iph = ipv6_hdr(skb);
top_iph->version = 6;
memcpy(top_iph->flow_lbl, XFRM_MODE_SKB_CB(skb)->flow_lbl,
sizeof(top_iph->flow_lbl));
top_iph->nexthdr = xfrm_af2proto(skb_dst(skb)->ops->family);
if (x->props.extra_flags & XFRM_SA_XFLAG_DONT_ENCAP_DSCP)
dsfield = 0;
else
dsfield = XFRM_MODE_SKB_CB(skb)->tos;
dsfield = INET_ECN_encapsulate(dsfield, XFRM_MODE_SKB_CB(skb)->tos);
if (x->props.flags & XFRM_STATE_NOECN)
dsfield &= ~INET_ECN_MASK;
ipv6_change_dsfield(top_iph, 0, dsfield);
top_iph->hop_limit = ip6_dst_hoplimit(dst->child);
top_iph->saddr = *(struct in6_addr *)&x->props.saddr;
top_iph->daddr = *(struct in6_addr *)&x->id.daddr;
return 0;
}
static int xfrm6_mode_tunnel_input(struct xfrm_state *x, struct sk_buff *skb)
{
struct xfrm_tunnel_notifier *handler;
int err = -EINVAL;
if (XFRM_MODE_SKB_CB(skb)->protocol != IPPROTO_IPV6)
goto out;
if (!pskb_may_pull(skb, sizeof(struct ipv6hdr)))
goto out;
for_each_input_rcu(rcv_notify_handlers, handler)
handler->handler(skb);
err = skb_unclone(skb, GFP_ATOMIC);
if (err)
goto out;
if (x->props.flags & XFRM_STATE_DECAP_DSCP)
ipv6_copy_dscp(ipv6_get_dsfield(ipv6_hdr(skb)),
ipipv6_hdr(skb));
if (!(x->props.flags & XFRM_STATE_NOECN))
ipip6_ecn_decapsulate(skb);
skb_reset_network_header(skb);
skb_mac_header_rebuild(skb);
err = 0;
out:
return err;
}
static int __init xfrm6_mode_tunnel_init(void)
{
return xfrm_register_mode(&xfrm6_tunnel_mode, AF_INET6);
}
static void __exit xfrm6_mode_tunnel_exit(void)
{
int err;
err = xfrm_unregister_mode(&xfrm6_tunnel_mode, AF_INET6);
BUG_ON(err);
}
