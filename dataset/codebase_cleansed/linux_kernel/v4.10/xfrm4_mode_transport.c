static int xfrm4_transport_output(struct xfrm_state *x, struct sk_buff *skb)
{
struct iphdr *iph = ip_hdr(skb);
int ihl = iph->ihl * 4;
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
if (skb->transport_header != skb->network_header) {
memmove(skb_transport_header(skb),
skb_network_header(skb), ihl);
skb->network_header = skb->transport_header;
}
ip_hdr(skb)->tot_len = htons(skb->len + ihl);
skb_reset_transport_header(skb);
return 0;
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
