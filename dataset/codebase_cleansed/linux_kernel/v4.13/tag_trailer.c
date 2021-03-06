static struct sk_buff *trailer_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
struct sk_buff *nskb;
int padlen;
u8 *trailer;
padlen = 0;
if (skb->len < 60)
padlen = 60 - skb->len;
nskb = alloc_skb(NET_IP_ALIGN + skb->len + padlen + 4, GFP_ATOMIC);
if (!nskb)
return NULL;
skb_reserve(nskb, NET_IP_ALIGN);
skb_reset_mac_header(nskb);
skb_set_network_header(nskb, skb_network_header(skb) - skb->head);
skb_set_transport_header(nskb, skb_transport_header(skb) - skb->head);
skb_copy_and_csum_dev(skb, skb_put(nskb, skb->len));
consume_skb(skb);
if (padlen) {
skb_put_zero(nskb, padlen);
}
trailer = skb_put(nskb, 4);
trailer[0] = 0x80;
trailer[1] = 1 << p->dp->index;
trailer[2] = 0x10;
trailer[3] = 0x00;
return nskb;
}
static struct sk_buff *trailer_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt,
struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_port *cpu_dp = dsa_get_cpu_port(dst);
struct dsa_switch *ds = cpu_dp->ds;
u8 *trailer;
int source_port;
if (skb_linearize(skb))
return NULL;
trailer = skb_tail_pointer(skb) - 4;
if (trailer[0] != 0x80 || (trailer[1] & 0xf8) != 0x00 ||
(trailer[2] & 0xef) != 0x00 || trailer[3] != 0x00)
return NULL;
source_port = trailer[1] & 7;
if (source_port >= ds->num_ports || !ds->ports[source_port].netdev)
return NULL;
pskb_trim_rcsum(skb, skb->len - 4);
skb->dev = ds->ports[source_port].netdev;
return skb;
}
