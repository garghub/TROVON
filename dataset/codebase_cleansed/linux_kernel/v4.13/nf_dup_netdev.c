static void nf_do_netdev_egress(struct sk_buff *skb, struct net_device *dev)
{
if (skb_mac_header_was_set(skb))
skb_push(skb, skb->mac_len);
skb->dev = dev;
dev_queue_xmit(skb);
}
void nf_fwd_netdev_egress(const struct nft_pktinfo *pkt, int oif)
{
struct net_device *dev;
dev = dev_get_by_index_rcu(nft_net(pkt), oif);
if (!dev) {
kfree_skb(pkt->skb);
return;
}
nf_do_netdev_egress(pkt->skb, dev);
}
void nf_dup_netdev_egress(const struct nft_pktinfo *pkt, int oif)
{
struct net_device *dev;
struct sk_buff *skb;
dev = dev_get_by_index_rcu(nft_net(pkt), oif);
if (dev == NULL)
return;
skb = skb_clone(pkt->skb, GFP_ATOMIC);
if (skb)
nf_do_netdev_egress(skb, dev);
}
