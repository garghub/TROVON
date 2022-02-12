static inline void ipip_ecn_decapsulate(struct sk_buff *skb)
{
struct iphdr *inner_iph = ipip_hdr(skb);
if (INET_ECN_is_ce(XFRM_MODE_SKB_CB(skb)->tos))
IP_ECN_set_ce(inner_iph);
}
static int xfrm4_mode_tunnel_output(struct xfrm_state *x, struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct iphdr *top_iph;
int flags;
skb_set_network_header(skb, -x->props.header_len);
skb->mac_header = skb->network_header +
offsetof(struct iphdr, protocol);
skb->transport_header = skb->network_header + sizeof(*top_iph);
top_iph = ip_hdr(skb);
top_iph->ihl = 5;
top_iph->version = 4;
top_iph->protocol = xfrm_af2proto(skb_dst(skb)->ops->family);
if (x->props.extra_flags & XFRM_SA_XFLAG_DONT_ENCAP_DSCP)
top_iph->tos = 0;
else
top_iph->tos = XFRM_MODE_SKB_CB(skb)->tos;
top_iph->tos = INET_ECN_encapsulate(top_iph->tos,
XFRM_MODE_SKB_CB(skb)->tos);
flags = x->props.flags;
if (flags & XFRM_STATE_NOECN)
IP_ECN_clear(top_iph);
top_iph->frag_off = (flags & XFRM_STATE_NOPMTUDISC) ?
0 : (XFRM_MODE_SKB_CB(skb)->frag_off & htons(IP_DF));
top_iph->ttl = ip4_dst_hoplimit(dst->child);
top_iph->saddr = x->props.saddr.a4;
top_iph->daddr = x->id.daddr.a4;
ip_select_ident(dev_net(dst->dev), skb, NULL);
return 0;
}
static int xfrm4_mode_tunnel_input(struct xfrm_state *x, struct sk_buff *skb)
{
int err = -EINVAL;
if (XFRM_MODE_SKB_CB(skb)->protocol != IPPROTO_IPIP)
goto out;
if (!pskb_may_pull(skb, sizeof(struct iphdr)))
goto out;
err = skb_unclone(skb, GFP_ATOMIC);
if (err)
goto out;
if (x->props.flags & XFRM_STATE_DECAP_DSCP)
ipv4_copy_dscp(XFRM_MODE_SKB_CB(skb)->tos, ipip_hdr(skb));
if (!(x->props.flags & XFRM_STATE_NOECN))
ipip_ecn_decapsulate(skb);
skb_reset_network_header(skb);
skb_mac_header_rebuild(skb);
err = 0;
out:
return err;
}
static int __init xfrm4_mode_tunnel_init(void)
{
return xfrm_register_mode(&xfrm4_tunnel_mode, AF_INET);
}
static void __exit xfrm4_mode_tunnel_exit(void)
{
int err;
err = xfrm_unregister_mode(&xfrm4_tunnel_mode, AF_INET);
BUG_ON(err);
}
