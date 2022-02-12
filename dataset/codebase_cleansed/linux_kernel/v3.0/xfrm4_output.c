static int xfrm4_tunnel_check_size(struct sk_buff *skb)
{
int mtu, ret = 0;
struct dst_entry *dst;
if (IPCB(skb)->flags & IPSKB_XFRM_TUNNEL_SIZE)
goto out;
if (!(ip_hdr(skb)->frag_off & htons(IP_DF)) || skb->local_df)
goto out;
dst = skb_dst(skb);
mtu = dst_mtu(dst);
if (skb->len > mtu) {
if (skb->sk)
ip_local_error(skb->sk, EMSGSIZE, ip_hdr(skb)->daddr,
inet_sk(skb->sk)->inet_dport, mtu);
else
icmp_send(skb, ICMP_DEST_UNREACH,
ICMP_FRAG_NEEDED, htonl(mtu));
ret = -EMSGSIZE;
}
out:
return ret;
}
int xfrm4_extract_output(struct xfrm_state *x, struct sk_buff *skb)
{
int err;
err = xfrm4_tunnel_check_size(skb);
if (err)
return err;
XFRM_MODE_SKB_CB(skb)->protocol = ip_hdr(skb)->protocol;
return xfrm4_extract_header(skb);
}
int xfrm4_prepare_output(struct xfrm_state *x, struct sk_buff *skb)
{
int err;
err = xfrm_inner_extract_output(x, skb);
if (err)
return err;
memset(IPCB(skb), 0, sizeof(*IPCB(skb)));
IPCB(skb)->flags |= IPSKB_XFRM_TUNNEL_SIZE | IPSKB_XFRM_TRANSFORMED;
skb->protocol = htons(ETH_P_IP);
return x->outer_mode->output2(x, skb);
}
int xfrm4_output_finish(struct sk_buff *skb)
{
#ifdef CONFIG_NETFILTER
if (!skb_dst(skb)->xfrm) {
IPCB(skb)->flags |= IPSKB_REROUTED;
return dst_output(skb);
}
IPCB(skb)->flags |= IPSKB_XFRM_TRANSFORMED;
#endif
skb->protocol = htons(ETH_P_IP);
return xfrm_output(skb);
}
int xfrm4_output(struct sk_buff *skb)
{
struct dst_entry *dst = skb_dst(skb);
struct xfrm_state *x = dst->xfrm;
return NF_HOOK_COND(NFPROTO_IPV4, NF_INET_POST_ROUTING, skb,
NULL, dst->dev,
x->outer_mode->afinfo->output_finish,
!(IPCB(skb)->flags & IPSKB_REROUTED));
}
