static struct sk_buff *edsa_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u8 *edsa_header;
if (skb->protocol == htons(ETH_P_8021Q)) {
if (skb_cow_head(skb, DSA_HLEN) < 0)
return NULL;
skb_push(skb, DSA_HLEN);
memmove(skb->data, skb->data + DSA_HLEN, 2 * ETH_ALEN);
edsa_header = skb->data + 2 * ETH_ALEN;
edsa_header[0] = (ETH_P_EDSA >> 8) & 0xff;
edsa_header[1] = ETH_P_EDSA & 0xff;
edsa_header[2] = 0x00;
edsa_header[3] = 0x00;
edsa_header[4] = 0x60 | p->dp->ds->index;
edsa_header[5] = p->dp->index << 3;
if (edsa_header[6] & 0x10) {
edsa_header[5] |= 0x01;
edsa_header[6] &= ~0x10;
}
} else {
if (skb_cow_head(skb, EDSA_HLEN) < 0)
return NULL;
skb_push(skb, EDSA_HLEN);
memmove(skb->data, skb->data + EDSA_HLEN, 2 * ETH_ALEN);
edsa_header = skb->data + 2 * ETH_ALEN;
edsa_header[0] = (ETH_P_EDSA >> 8) & 0xff;
edsa_header[1] = ETH_P_EDSA & 0xff;
edsa_header[2] = 0x00;
edsa_header[3] = 0x00;
edsa_header[4] = 0x40 | p->dp->ds->index;
edsa_header[5] = p->dp->index << 3;
edsa_header[6] = 0x00;
edsa_header[7] = 0x00;
}
return skb;
}
static struct sk_buff *edsa_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt,
struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
u8 *edsa_header;
int source_device;
int source_port;
if (unlikely(!pskb_may_pull(skb, EDSA_HLEN)))
return NULL;
edsa_header = skb->data + 2;
if ((edsa_header[0] & 0xc0) != 0x00 && (edsa_header[0] & 0xc0) != 0xc0)
return NULL;
source_device = edsa_header[0] & 0x1f;
source_port = (edsa_header[1] >> 3) & 0x1f;
if (source_device >= DSA_MAX_SWITCHES)
return NULL;
ds = dst->ds[source_device];
if (!ds)
return NULL;
if (source_port >= ds->num_ports || !ds->ports[source_port].netdev)
return NULL;
if (edsa_header[0] & 0x20) {
u8 new_header[4];
new_header[0] = (ETH_P_8021Q >> 8) & 0xff;
new_header[1] = ETH_P_8021Q & 0xff;
new_header[2] = edsa_header[2] & ~0x10;
new_header[3] = edsa_header[3];
if (edsa_header[1] & 0x01)
new_header[2] |= 0x10;
skb_pull_rcsum(skb, DSA_HLEN);
if (skb->ip_summed == CHECKSUM_COMPLETE) {
__wsum c = skb->csum;
c = csum_add(c, csum_partial(new_header + 2, 2, 0));
c = csum_sub(c, csum_partial(edsa_header + 2, 2, 0));
skb->csum = c;
}
memcpy(edsa_header, new_header, DSA_HLEN);
memmove(skb->data - ETH_HLEN,
skb->data - ETH_HLEN - DSA_HLEN,
2 * ETH_ALEN);
} else {
skb_pull_rcsum(skb, EDSA_HLEN);
memmove(skb->data - ETH_HLEN,
skb->data - ETH_HLEN - EDSA_HLEN,
2 * ETH_ALEN);
}
skb->dev = ds->ports[source_port].netdev;
return skb;
}
