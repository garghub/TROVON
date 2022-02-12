static struct sk_buff *qca_tag_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u16 *phdr, hdr;
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
if (skb_cow_head(skb, 0) < 0)
return NULL;
skb_push(skb, QCA_HDR_LEN);
memmove(skb->data, skb->data + QCA_HDR_LEN, 2 * ETH_ALEN);
phdr = (u16 *)(skb->data + 2 * ETH_ALEN);
hdr = QCA_HDR_VERSION << QCA_HDR_XMIT_VERSION_S |
QCA_HDR_XMIT_FROM_CPU |
BIT(p->dp->index);
*phdr = htons(hdr);
return skb;
}
static struct sk_buff *qca_tag_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_port *cpu_dp = dsa_get_cpu_port(dst);
struct dsa_switch *ds;
u8 ver;
int port;
__be16 *phdr, hdr;
if (unlikely(!pskb_may_pull(skb, QCA_HDR_LEN)))
return NULL;
phdr = (__be16 *)(skb->data - 2);
hdr = ntohs(*phdr);
ver = (hdr & QCA_HDR_RECV_VERSION_MASK) >> QCA_HDR_RECV_VERSION_S;
if (unlikely(ver != QCA_HDR_VERSION))
return NULL;
skb_pull_rcsum(skb, QCA_HDR_LEN);
memmove(skb->data - ETH_HLEN, skb->data - ETH_HLEN - QCA_HDR_LEN,
ETH_HLEN - QCA_HDR_LEN);
ds = cpu_dp->ds;
if (!ds)
return NULL;
port = (hdr & QCA_HDR_RECV_SOURCE_PORT_MASK);
if (!ds->ports[port].netdev)
return NULL;
skb->dev = ds->ports[port].netdev;
return skb;
}
