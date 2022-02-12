static int xfrm6_transport_output(struct xfrm_state *x, struct sk_buff *skb)
{
struct ipv6hdr *iph;
u8 *prevhdr;
int hdr_len;
iph = ipv6_hdr(skb);
hdr_len = x->type->hdr_offset(x, skb, &prevhdr);
skb_set_mac_header(skb, (prevhdr - x->props.header_len) - skb->data);
skb_set_network_header(skb, -x->props.header_len);
skb->transport_header = skb->network_header + hdr_len;
__skb_pull(skb, hdr_len);
memmove(ipv6_hdr(skb), iph, hdr_len);
return 0;
}
static int xfrm6_transport_input(struct xfrm_state *x, struct sk_buff *skb)
{
int ihl = skb->data - skb_transport_header(skb);
struct xfrm_offload *xo = xfrm_offload(skb);
if (skb->transport_header != skb->network_header) {
memmove(skb_transport_header(skb),
skb_network_header(skb), ihl);
skb->network_header = skb->transport_header;
}
ipv6_hdr(skb)->payload_len = htons(skb->len + ihl -
sizeof(struct ipv6hdr));
if (!xo || !(xo->flags & XFRM_GRO))
skb_reset_transport_header(skb);
return 0;
}
static int __init xfrm6_transport_init(void)
{
return xfrm_register_mode(&xfrm6_transport_mode, AF_INET6);
}
static void __exit xfrm6_transport_exit(void)
{
int err;
err = xfrm_unregister_mode(&xfrm6_transport_mode, AF_INET6);
BUG_ON(err);
}
