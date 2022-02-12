static struct sk_buff *ksz_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
struct sk_buff *nskb;
int padlen;
u8 *tag;
padlen = (skb->len >= ETH_ZLEN) ? 0 : ETH_ZLEN - skb->len;
if (skb_tailroom(skb) >= padlen + KSZ_INGRESS_TAG_LEN) {
if (__skb_put_padto(skb, skb->len + padlen, false))
return NULL;
nskb = skb;
} else {
nskb = alloc_skb(NET_IP_ALIGN + skb->len +
padlen + KSZ_INGRESS_TAG_LEN, GFP_ATOMIC);
if (!nskb)
return NULL;
skb_reserve(nskb, NET_IP_ALIGN);
skb_reset_mac_header(nskb);
skb_set_network_header(nskb,
skb_network_header(skb) - skb->head);
skb_set_transport_header(nskb,
skb_transport_header(skb) - skb->head);
skb_copy_and_csum_dev(skb, skb_put(nskb, skb->len));
if (skb_put_padto(nskb, nskb->len + padlen))
return NULL;
consume_skb(skb);
}
tag = skb_put(nskb, KSZ_INGRESS_TAG_LEN);
tag[0] = 0;
tag[1] = 1 << p->dp->index;
return nskb;
}
static struct sk_buff *ksz_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt,
struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_port *cpu_dp = dsa_get_cpu_port(dst);
struct dsa_switch *ds = cpu_dp->ds;
u8 *tag;
int source_port;
tag = skb_tail_pointer(skb) - KSZ_EGRESS_TAG_LEN;
source_port = tag[0] & 7;
if (source_port >= ds->num_ports || !ds->ports[source_port].netdev)
return NULL;
pskb_trim_rcsum(skb, skb->len - KSZ_EGRESS_TAG_LEN);
skb->dev = ds->ports[source_port].netdev;
return skb;
}
