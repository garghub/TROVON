static struct sk_buff *mpls_gso_segment(struct sk_buff *skb,
netdev_features_t features)
{
struct sk_buff *segs = ERR_PTR(-EINVAL);
netdev_features_t mpls_features;
__be16 mpls_protocol;
if (unlikely(skb_shinfo(skb)->gso_type &
~(SKB_GSO_TCPV4 |
SKB_GSO_TCPV6 |
SKB_GSO_UDP |
SKB_GSO_DODGY |
SKB_GSO_TCP_ECN)))
goto out;
mpls_protocol = skb->protocol;
skb->protocol = skb->inner_protocol;
__skb_push(skb, skb->mac_len);
mpls_features = skb->dev->mpls_features & features;
segs = skb_mac_gso_segment(skb, mpls_features);
skb->protocol = mpls_protocol;
__skb_pull(skb, skb->data - skb_mac_header(skb));
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
