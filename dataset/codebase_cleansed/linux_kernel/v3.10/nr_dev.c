int nr_rx_ip(struct sk_buff *skb, struct net_device *dev)
{
struct net_device_stats *stats = &dev->stats;
if (!netif_running(dev)) {
stats->rx_dropped++;
return 0;
}
stats->rx_packets++;
stats->rx_bytes += skb->len;
skb->protocol = htons(ETH_P_IP);
skb->dev = dev;
skb->mac_header = skb->network_header;
skb_reset_network_header(skb);
skb->pkt_type = PACKET_HOST;
netif_rx(skb);
return 1;
}
static int nr_rebuild_header(struct sk_buff *skb)
{
unsigned char *bp = skb->data;
if (arp_find(bp + 7, skb))
return 1;
bp[6] &= ~AX25_CBIT;
bp[6] &= ~AX25_EBIT;
bp[6] |= AX25_SSSID_SPARE;
bp += AX25_ADDR_LEN;
bp[6] &= ~AX25_CBIT;
bp[6] |= AX25_EBIT;
bp[6] |= AX25_SSSID_SPARE;
return 0;
}
static int nr_rebuild_header(struct sk_buff *skb)
{
return 1;
}
static int nr_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned int len)
{
unsigned char *buff = skb_push(skb, NR_NETWORK_LEN + NR_TRANSPORT_LEN);
memcpy(buff, (saddr != NULL) ? saddr : dev->dev_addr, dev->addr_len);
buff[6] &= ~AX25_CBIT;
buff[6] &= ~AX25_EBIT;
buff[6] |= AX25_SSSID_SPARE;
buff += AX25_ADDR_LEN;
if (daddr != NULL)
memcpy(buff, daddr, dev->addr_len);
buff[6] &= ~AX25_CBIT;
buff[6] |= AX25_EBIT;
buff[6] |= AX25_SSSID_SPARE;
buff += AX25_ADDR_LEN;
*buff++ = sysctl_netrom_network_ttl_initialiser;
*buff++ = NR_PROTO_IP;
*buff++ = NR_PROTO_IP;
*buff++ = 0;
*buff++ = 0;
*buff++ = NR_PROTOEXT;
if (daddr != NULL)
return 37;
return -37;
}
static int __must_check nr_set_mac_address(struct net_device *dev, void *addr)
{
struct sockaddr *sa = addr;
int err;
if (!memcmp(dev->dev_addr, sa->sa_data, dev->addr_len))
return 0;
if (dev->flags & IFF_UP) {
err = ax25_listen_register((ax25_address *)sa->sa_data, NULL);
if (err)
return err;
ax25_listen_release((ax25_address *)dev->dev_addr, NULL);
}
memcpy(dev->dev_addr, sa->sa_data, dev->addr_len);
return 0;
}
static int nr_open(struct net_device *dev)
{
int err;
err = ax25_listen_register((ax25_address *)dev->dev_addr, NULL);
if (err)
return err;
netif_start_queue(dev);
return 0;
}
static int nr_close(struct net_device *dev)
{
ax25_listen_release((ax25_address *)dev->dev_addr, NULL);
netif_stop_queue(dev);
return 0;
}
static netdev_tx_t nr_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct net_device_stats *stats = &dev->stats;
unsigned int len = skb->len;
if (!nr_route_frame(skb, NULL)) {
kfree_skb(skb);
stats->tx_errors++;
return NETDEV_TX_OK;
}
stats->tx_packets++;
stats->tx_bytes += len;
return NETDEV_TX_OK;
}
void nr_setup(struct net_device *dev)
{
dev->mtu = NR_MAX_PACKET_SIZE;
dev->netdev_ops = &nr_netdev_ops;
dev->header_ops = &nr_header_ops;
dev->hard_header_len = NR_NETWORK_LEN + NR_TRANSPORT_LEN;
dev->addr_len = AX25_ADDR_LEN;
dev->type = ARPHRD_NETROM;
dev->flags = IFF_NOARP;
}
