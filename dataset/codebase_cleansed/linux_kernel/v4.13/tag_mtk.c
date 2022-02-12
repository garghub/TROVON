static struct sk_buff *mtk_tag_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u8 *mtk_tag;
if (skb_cow_head(skb, MTK_HDR_LEN) < 0)
return NULL;
skb_push(skb, MTK_HDR_LEN);
memmove(skb->data, skb->data + MTK_HDR_LEN, 2 * ETH_ALEN);
mtk_tag = skb->data + 2 * ETH_ALEN;
mtk_tag[0] = 0;
mtk_tag[1] = (1 << p->dp->index) & MTK_HDR_XMIT_DP_BIT_MASK;
mtk_tag[2] = 0;
mtk_tag[3] = 0;
return skb;
}
static struct sk_buff *mtk_tag_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt,
struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
int port;
__be16 *phdr, hdr;
if (unlikely(!pskb_may_pull(skb, MTK_HDR_LEN)))
return NULL;
phdr = (__be16 *)(skb->data - 2);
hdr = ntohs(*phdr);
skb_pull_rcsum(skb, MTK_HDR_LEN);
memmove(skb->data - ETH_HLEN,
skb->data - ETH_HLEN - MTK_HDR_LEN,
2 * ETH_ALEN);
ds = dst->ds[0];
if (!ds)
return NULL;
port = (hdr & MTK_HDR_RECV_SOURCE_PORT_MASK);
if (!ds->ports[port].netdev)
return NULL;
skb->dev = ds->ports[port].netdev;
return skb;
}
