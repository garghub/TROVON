static struct sk_buff *dsa_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u8 *dsa_header;
if (skb->protocol == htons(ETH_P_8021Q)) {
if (skb_cow_head(skb, 0) < 0)
return NULL;
dsa_header = skb->data + 2 * ETH_ALEN;
dsa_header[0] = 0x60 | p->dp->ds->index;
dsa_header[1] = p->dp->index << 3;
if (dsa_header[2] & 0x10) {
dsa_header[1] |= 0x01;
dsa_header[2] &= ~0x10;
}
} else {
if (skb_cow_head(skb, DSA_HLEN) < 0)
return NULL;
skb_push(skb, DSA_HLEN);
memmove(skb->data, skb->data + DSA_HLEN, 2 * ETH_ALEN);
dsa_header = skb->data + 2 * ETH_ALEN;
dsa_header[0] = 0x40 | p->dp->ds->index;
dsa_header[1] = p->dp->index << 3;
dsa_header[2] = 0x00;
dsa_header[3] = 0x00;
}
return skb;
}
static struct sk_buff *dsa_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
u8 *dsa_header;
int source_device;
int source_port;
if (unlikely(!pskb_may_pull(skb, DSA_HLEN)))
return NULL;
dsa_header = skb->data - 2;
if ((dsa_header[0] & 0xc0) != 0x00 && (dsa_header[0] & 0xc0) != 0xc0)
return NULL;
source_device = dsa_header[0] & 0x1f;
source_port = (dsa_header[1] >> 3) & 0x1f;
if (source_device >= DSA_MAX_SWITCHES)
return NULL;
ds = dst->ds[source_device];
if (!ds)
return NULL;
if (source_port >= ds->num_ports || !ds->ports[source_port].netdev)
return NULL;
if (dsa_header[0] & 0x20) {
u8 new_header[4];
new_header[0] = (ETH_P_8021Q >> 8) & 0xff;
new_header[1] = ETH_P_8021Q & 0xff;
new_header[2] = dsa_header[2] & ~0x10;
new_header[3] = dsa_header[3];
if (dsa_header[1] & 0x01)
new_header[2] |= 0x10;
if (skb->ip_summed == CHECKSUM_COMPLETE) {
__wsum c = skb->csum;
c = csum_add(c, csum_partial(new_header + 2, 2, 0));
c = csum_sub(c, csum_partial(dsa_header + 2, 2, 0));
skb->csum = c;
}
memcpy(dsa_header, new_header, DSA_HLEN);
} else {
skb_pull_rcsum(skb, DSA_HLEN);
memmove(skb->data - ETH_HLEN,
skb->data - ETH_HLEN - DSA_HLEN,
2 * ETH_ALEN);
}
skb->dev = ds->ports[source_port].netdev;
return skb;
}
