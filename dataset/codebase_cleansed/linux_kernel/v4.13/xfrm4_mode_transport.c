static int xfrm4_transport_output(struct xfrm_state *x, struct sk_buff *skb)
{
struct iphdr *iph = ip_hdr(skb);
int ihl = iph->ihl * 4;
skb_set_inner_transport_header(skb, skb_transport_offset(skb));
skb_set_network_header(skb, -x->props.header_len);
skb->mac_header = skb->network_header +
offsetof(struct iphdr, protocol);
skb->transport_header = skb->network_header + ihl;
__skb_pull(skb, ihl);
memmove(skb_network_header(skb), iph, ihl);
return 0;
}
static int xfrm4_transport_input(struct xfrm_state *x, struct sk_buff *skb)
{
int ihl = skb->data - skb_transport_header(skb);
struct xfrm_offload *xo = xfrm_offload(skb);
if (skb->transport_header != skb->network_header) {
memmove(skb_transport_header(skb),
skb_network_header(skb), ihl);
skb->network_header = skb->transport_header;
}
ip_hdr(skb)->tot_len = htons(skb->len + ihl);
if (!xo || !(xo->flags & XFRM_GRO))
skb_reset_transport_header(skb);
return 0;
}
static struct sk_buff *xfrm4_transport_gso_segment(struct xfrm_state *x,
struct sk_buff *skb,
netdev_features_t features)
{
const struct net_offload *ops;
struct sk_buff *segs = ERR_PTR(-EINVAL);
struct xfrm_offload *xo = xfrm_offload(skb);
skb->transport_header += x->props.header_len;
ops = rcu_dereference(inet_offloads[xo->proto]);
if (likely(ops && ops->callbacks.gso_segment))
segs = ops->callbacks.gso_segment(skb, features);
return segs;
}
static void xfrm4_transport_xmit(struct xfrm_state *x, struct sk_buff *skb)
{
struct xfrm_offload *xo = xfrm_offload(skb);
skb_reset_mac_len(skb);
pskb_pull(skb, skb->mac_len + sizeof(struct iphdr) + x->props.header_len);
if (xo->flags & XFRM_GSO_SEGMENT) {
skb_reset_transport_header(skb);
skb->transport_header -= x->props.header_len;
}
}
static int __init xfrm4_transport_init(void)
{
return xfrm_register_mode(&xfrm4_transport_mode, AF_INET);
}
static void __exit xfrm4_transport_exit(void)
{
int err;
err = xfrm_unregister_mode(&xfrm4_transport_mode, AF_INET);
BUG_ON(err);
}
