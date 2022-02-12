void nf_dup_netdev_egress(const struct nft_pktinfo *pkt, int oif)
{
struct net_device *dev;
struct sk_buff *skb;
dev = dev_get_by_index_rcu(pkt->net, oif);
if (dev == NULL)
return;
skb = skb_clone(pkt->skb, GFP_ATOMIC);
if (skb == NULL)
return;
if (skb_mac_header_was_set(skb))
skb_push(skb, skb->mac_len);
skb->dev = dev;
dev_queue_xmit(skb);
}
