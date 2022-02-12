static struct sk_buff *nsh_gso_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
unsigned int nsh_len, mac_len;
__be16 proto;
int nhoff;
skb_reset_network_header(skb);
nhoff = skb->network_header - skb->mac_header;
mac_len = skb->mac_len;
if (unlikely(!pskb_may_pull(skb, NSH_BASE_HDR_LEN)))
goto out;
nsh_len = nsh_hdr_len(nsh_hdr(skb));
if (unlikely(!pskb_may_pull(skb, nsh_len)))
goto out;
proto = tun_p_to_eth_p(nsh_hdr(skb)->np);
if (!proto)
goto out;
__skb_pull(skb, nsh_len);
skb_reset_mac_header(skb);
skb_reset_mac_len(skb);
skb->protocol = proto;
features &= NETIF_F_SG;
segs = skb_mac_gso_segment(skb, features);
if (IS_ERR_OR_NULL(segs)) {
skb_gso_error_unwind(skb, htons(ETH_P_NSH), nsh_len,
skb->network_header - nhoff,
mac_len);
goto out;
}
for (skb = segs; skb; skb = skb->next) {
skb->protocol = htons(ETH_P_NSH);
__skb_push(skb, nsh_len);
skb_set_mac_header(skb, -nhoff);
skb->network_header = skb->mac_header + mac_len;
skb->mac_len = mac_len;
}
out:
return segs;
}
static int __init nsh_init_module(void)
{
dev_add_offload(&nsh_packet_offload);
return 0;
}
static void __exit nsh_cleanup_module(void)
{
dev_remove_offload(&nsh_packet_offload);
}
