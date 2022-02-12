static int xfrm6_ro_output(struct xfrm_state *x, struct sk_buff *skb)
{
struct ipv6hdr *iph;
u8 *prevhdr;
int hdr_len;
iph = ipv6_hdr(skb);
hdr_len = x->type->hdr_offset(x, skb, &prevhdr);
if (hdr_len < 0)
return hdr_len;
skb_set_mac_header(skb, (prevhdr - x->props.header_len) - skb->data);
skb_set_network_header(skb, -x->props.header_len);
skb->transport_header = skb->network_header + hdr_len;
__skb_pull(skb, hdr_len);
memmove(ipv6_hdr(skb), iph, hdr_len);
x->lastused = get_seconds();
return 0;
}
static int __init xfrm6_ro_init(void)
{
return xfrm_register_mode(&xfrm6_ro_mode, AF_INET6);
}
static void __exit xfrm6_ro_exit(void)
{
int err;
err = xfrm_unregister_mode(&xfrm6_ro_mode, AF_INET6);
BUG_ON(err);
}
