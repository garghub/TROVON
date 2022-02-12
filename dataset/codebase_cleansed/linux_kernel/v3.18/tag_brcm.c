static netdev_tx_t brcm_tag_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u8 *brcm_tag;
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
if (skb_cow_head(skb, BRCM_TAG_LEN) < 0)
goto out_free;
skb_push(skb, BRCM_TAG_LEN);
memmove(skb->data, skb->data + BRCM_TAG_LEN, 2 * ETH_ALEN);
brcm_tag = skb->data + 2 * ETH_ALEN;
brcm_tag[0] = (1 << BRCM_OPCODE_SHIFT) |
((skb->priority << BRCM_IG_TC_SHIFT) & BRCM_IG_TC_MASK);
brcm_tag[1] = 0;
brcm_tag[2] = 0;
if (p->port == 8)
brcm_tag[2] = BRCM_IG_DSTMAP2_MASK;
brcm_tag[3] = (1 << p->port) & BRCM_IG_DSTMAP1_MASK;
skb->dev = p->parent->dst->master_netdev;
dev_queue_xmit(skb);
return NETDEV_TX_OK;
out_free:
kfree_skb(skb);
return NETDEV_TX_OK;
}
static int brcm_tag_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
int source_port;
u8 *brcm_tag;
if (unlikely(dst == NULL))
goto out_drop;
ds = dst->ds[0];
skb = skb_unshare(skb, GFP_ATOMIC);
if (skb == NULL)
goto out;
if (unlikely(!pskb_may_pull(skb, BRCM_TAG_LEN)))
goto out_drop;
brcm_tag = skb->data - 2;
if (unlikely((brcm_tag[0] >> BRCM_OPCODE_SHIFT) & BRCM_OPCODE_MASK))
goto out_drop;
WARN_ON(brcm_tag[2] & BRCM_EG_RC_RSVD);
source_port = brcm_tag[3] & BRCM_EG_PID_MASK;
if (source_port >= DSA_MAX_PORTS || ds->ports[source_port] == NULL)
goto out_drop;
skb_pull_rcsum(skb, BRCM_TAG_LEN);
memmove(skb->data - ETH_HLEN,
skb->data - ETH_HLEN - BRCM_TAG_LEN,
2 * ETH_ALEN);
skb_push(skb, ETH_HLEN);
skb->pkt_type = PACKET_HOST;
skb->dev = ds->ports[source_port];
skb->protocol = eth_type_trans(skb, skb->dev);
skb->dev->stats.rx_packets++;
skb->dev->stats.rx_bytes += skb->len;
netif_receive_skb(skb);
return 0;
out_drop:
kfree_skb(skb);
out:
return 0;
}
