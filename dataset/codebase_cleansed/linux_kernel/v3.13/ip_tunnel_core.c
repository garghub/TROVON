int iptunnel_xmit(struct rtable *rt, struct sk_buff *skb,
__be32 src, __be32 dst, __u8 proto,
__u8 tos, __u8 ttl, __be16 df, bool xnet)
{
int pkt_len = skb->len;
struct iphdr *iph;
int err;
skb_scrub_packet(skb, xnet);
skb->rxhash = 0;
skb_dst_set(skb, &rt->dst);
memset(IPCB(skb), 0, sizeof(*IPCB(skb)));
skb_push(skb, sizeof(struct iphdr));
skb_reset_network_header(skb);
iph = ip_hdr(skb);
iph->version = 4;
iph->ihl = sizeof(struct iphdr) >> 2;
iph->frag_off = df;
iph->protocol = proto;
iph->tos = tos;
iph->daddr = dst;
iph->saddr = src;
iph->ttl = ttl;
__ip_select_ident(iph, &rt->dst, (skb_shinfo(skb)->gso_segs ?: 1) - 1);
err = ip_local_out(skb);
if (unlikely(net_xmit_eval(err)))
pkt_len = 0;
return pkt_len;
}
int iptunnel_pull_header(struct sk_buff *skb, int hdr_len, __be16 inner_proto)
{
if (unlikely(!pskb_may_pull(skb, hdr_len)))
return -ENOMEM;
skb_pull_rcsum(skb, hdr_len);
if (inner_proto == htons(ETH_P_TEB)) {
struct ethhdr *eh = (struct ethhdr *)skb->data;
if (unlikely(!pskb_may_pull(skb, ETH_HLEN)))
return -ENOMEM;
if (likely(ntohs(eh->h_proto) >= ETH_P_802_3_MIN))
skb->protocol = eh->h_proto;
else
skb->protocol = htons(ETH_P_802_2);
} else {
skb->protocol = inner_proto;
}
nf_reset(skb);
secpath_reset(skb);
if (!skb->l4_rxhash)
skb->rxhash = 0;
skb_dst_drop(skb);
skb->vlan_tci = 0;
skb_set_queue_mapping(skb, 0);
skb->pkt_type = PACKET_HOST;
return 0;
}
struct sk_buff *iptunnel_handle_offloads(struct sk_buff *skb,
bool csum_help,
int gso_type_mask)
{
int err;
if (likely(!skb->encapsulation)) {
skb_reset_inner_headers(skb);
skb->encapsulation = 1;
}
if (skb_is_gso(skb)) {
err = skb_unclone(skb, GFP_ATOMIC);
if (unlikely(err))
goto error;
skb_shinfo(skb)->gso_type |= gso_type_mask;
return skb;
}
if (skb->ip_summed == CHECKSUM_PARTIAL && csum_help) {
err = skb_checksum_help(skb);
if (unlikely(err))
goto error;
} else if (skb->ip_summed != CHECKSUM_PARTIAL)
skb->ip_summed = CHECKSUM_NONE;
return skb;
error:
kfree_skb(skb);
return ERR_PTR(err);
}
