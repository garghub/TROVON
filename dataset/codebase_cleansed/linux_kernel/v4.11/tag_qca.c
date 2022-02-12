static struct sk_buff *qca_tag_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u16 *phdr, hdr;
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
if (skb_cow_head(skb, 0) < 0)
goto out_free;
skb_push(skb, QCA_HDR_LEN);
memmove(skb->data, skb->data + QCA_HDR_LEN, 2 * ETH_ALEN);
phdr = (u16 *)(skb->data + 2 * ETH_ALEN);
hdr = QCA_HDR_VERSION << QCA_HDR_XMIT_VERSION_S |
QCA_HDR_XMIT_FROM_CPU |
BIT(p->dp->index);
*phdr = htons(hdr);
return skb;
out_free:
kfree_skb(skb);
return NULL;
}
static int qca_tag_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
u8 ver;
int port;
__be16 *phdr, hdr;
if (unlikely(!dst))
goto out_drop;
skb = skb_unshare(skb, GFP_ATOMIC);
if (!skb)
goto out;
if (unlikely(!pskb_may_pull(skb, QCA_HDR_LEN)))
goto out_drop;
phdr = (__be16 *)(skb->data - 2);
hdr = ntohs(*phdr);
ver = (hdr & QCA_HDR_RECV_VERSION_MASK) >> QCA_HDR_RECV_VERSION_S;
if (unlikely(ver != QCA_HDR_VERSION))
goto out_drop;
skb_pull_rcsum(skb, QCA_HDR_LEN);
memmove(skb->data - ETH_HLEN, skb->data - ETH_HLEN - QCA_HDR_LEN,
ETH_HLEN - QCA_HDR_LEN);
ds = dst->cpu_switch;
if (!ds)
goto out_drop;
port = (hdr & QCA_HDR_RECV_SOURCE_PORT_MASK);
if (!ds->ports[port].netdev)
goto out_drop;
skb_push(skb, ETH_HLEN);
skb->pkt_type = PACKET_HOST;
skb->dev = ds->ports[port].netdev;
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
