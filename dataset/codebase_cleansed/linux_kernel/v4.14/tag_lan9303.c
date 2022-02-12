static struct sk_buff *lan9303_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u16 *lan9303_tag;
if (skb_cow_head(skb, LAN9303_TAG_LEN) < 0) {
dev_dbg(&dev->dev,
"Cannot make room for the special tag. Dropping packet\n");
return NULL;
}
skb_push(skb, LAN9303_TAG_LEN);
memmove(skb->data, skb->data + LAN9303_TAG_LEN, 2 * ETH_ALEN);
lan9303_tag = (u16 *)(skb->data + 2 * ETH_ALEN);
lan9303_tag[0] = htons(ETH_P_8021Q);
lan9303_tag[1] = htons(p->dp->index | BIT(4));
return skb;
}
static struct sk_buff *lan9303_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt)
{
u16 *lan9303_tag;
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
unsigned int source_port;
ds = dst->ds[0];
if (unlikely(!ds)) {
dev_warn_ratelimited(&dev->dev, "Dropping packet, due to missing DSA switch device\n");
return NULL;
}
if (unlikely(!pskb_may_pull(skb, LAN9303_TAG_LEN))) {
dev_warn_ratelimited(&dev->dev,
"Dropping packet, cannot pull\n");
return NULL;
}
lan9303_tag = (u16 *)(skb->data - 2);
if (lan9303_tag[0] != htons(ETH_P_8021Q)) {
dev_warn_ratelimited(&dev->dev, "Dropping packet due to invalid VLAN marker\n");
return NULL;
}
source_port = ntohs(lan9303_tag[1]) & 0x3;
if (source_port >= ds->num_ports) {
dev_warn_ratelimited(&dev->dev, "Dropping packet due to invalid source port\n");
return NULL;
}
if (!ds->ports[source_port].netdev) {
dev_warn_ratelimited(&dev->dev, "Dropping packet due to invalid netdev or device\n");
return NULL;
}
skb_pull_rcsum(skb, 2 + 2);
memmove(skb->data - ETH_HLEN, skb->data - (ETH_HLEN + LAN9303_TAG_LEN),
2 * ETH_ALEN);
skb->dev = ds->ports[source_port].netdev;
return skb;
}
