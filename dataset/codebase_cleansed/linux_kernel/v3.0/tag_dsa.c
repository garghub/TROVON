netdev_tx_t dsa_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct dsa_slave_priv *p = netdev_priv(dev);
u8 *dsa_header;
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
if (skb->protocol == htons(ETH_P_8021Q)) {
if (skb_cow_head(skb, 0) < 0)
goto out_free;
dsa_header = skb->data + 2 * ETH_ALEN;
dsa_header[0] = 0x60 | p->parent->index;
dsa_header[1] = p->port << 3;
if (dsa_header[2] & 0x10) {
dsa_header[1] |= 0x01;
dsa_header[2] &= ~0x10;
}
} else {
if (skb_cow_head(skb, DSA_HLEN) < 0)
goto out_free;
skb_push(skb, DSA_HLEN);
memmove(skb->data, skb->data + DSA_HLEN, 2 * ETH_ALEN);
dsa_header = skb->data + 2 * ETH_ALEN;
dsa_header[0] = 0x40 | p->parent->index;
dsa_header[1] = p->port << 3;
dsa_header[2] = 0x00;
dsa_header[3] = 0x00;
}
skb->protocol = htons(ETH_P_DSA);
skb->dev = p->parent->dst->master_netdev;
dev_queue_xmit(skb);
return NETDEV_TX_OK;
out_free:
kfree_skb(skb);
return NETDEV_TX_OK;
}
static int dsa_rcv(struct sk_buff *skb, struct net_device *dev,
struct packet_type *pt, struct net_device *orig_dev)
{
struct dsa_switch_tree *dst = dev->dsa_ptr;
struct dsa_switch *ds;
u8 *dsa_header;
int source_device;
int source_port;
if (unlikely(dst == NULL))
goto out_drop;
skb = skb_unshare(skb, GFP_ATOMIC);
if (skb == NULL)
goto out;
if (unlikely(!pskb_may_pull(skb, DSA_HLEN)))
goto out_drop;
dsa_header = skb->data - 2;
if ((dsa_header[0] & 0xc0) != 0x00 && (dsa_header[0] & 0xc0) != 0xc0)
goto out_drop;
source_device = dsa_header[0] & 0x1f;
source_port = (dsa_header[1] >> 3) & 0x1f;
if (source_device >= dst->pd->nr_chips)
goto out_drop;
ds = dst->ds[source_device];
if (source_port >= DSA_MAX_PORTS || ds->ports[source_port] == NULL)
goto out_drop;
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
skb->dev = ds->ports[source_port];
skb_push(skb, ETH_HLEN);
skb->pkt_type = PACKET_HOST;
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
static int __init dsa_init_module(void)
{
dev_add_pack(&dsa_packet_type);
return 0;
}
static void __exit dsa_cleanup_module(void)
{
dev_remove_pack(&dsa_packet_type);
}
