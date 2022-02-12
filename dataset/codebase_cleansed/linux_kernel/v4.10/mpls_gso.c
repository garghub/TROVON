static struct sk_buff *mpls_gso_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
u16 mac_offset = skb->mac_header;
netdev_features_t mpls_features;
u16 mac_len = skb->mac_len;
__be16 mpls_protocol;
unsigned int mpls_hlen;
skb_reset_network_header(skb);
mpls_hlen = skb_inner_network_header(skb) - skb_network_header(skb);
if (unlikely(!pskb_may_pull(skb, mpls_hlen)))
goto out;
mpls_protocol = skb->protocol;
skb->protocol = skb->inner_protocol;
__skb_pull(skb, mpls_hlen);
skb->mac_len = 0;
skb_reset_mac_header(skb);
mpls_features = skb->dev->mpls_features & features;
segs = skb_mac_gso_segment(skb, mpls_features);
if (IS_ERR_OR_NULL(segs)) {
skb_gso_error_unwind(skb, mpls_protocol, mpls_hlen, mac_offset,
mac_len);
goto out;
}
skb = segs;
mpls_hlen += mac_len;
do {
skb->mac_len = mac_len;
skb->protocol = mpls_protocol;
skb_reset_inner_network_header(skb);
__skb_push(skb, mpls_hlen);
skb_reset_mac_header(skb);
skb_set_network_header(skb, mac_len);
} while ((skb = skb->next));
out:
return segs;
}
static int __init mpls_gso_init(void)
{
pr_info("MPLS GSO support\n");
dev_add_offload(&mpls_uc_offload);
dev_add_offload(&mpls_mc_offload);
return 0;
}
static void __exit mpls_gso_exit(void)
{
dev_remove_offload(&mpls_uc_offload);
dev_remove_offload(&mpls_mc_offload);
}
