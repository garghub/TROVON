int eth_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned int len)
{
struct ethhdr *eth = (struct ethhdr *)skb_push(skb, ETH_HLEN);
if (type != ETH_P_802_3 && type != ETH_P_802_2)
eth->h_proto = htons(type);
else
eth->h_proto = htons(len);
if (!saddr)
saddr = dev->dev_addr;
memcpy(eth->h_source, saddr, ETH_ALEN);
if (daddr) {
memcpy(eth->h_dest, daddr, ETH_ALEN);
return ETH_HLEN;
}
if (dev->flags & (IFF_LOOPBACK | IFF_NOARP)) {
memset(eth->h_dest, 0, ETH_ALEN);
return ETH_HLEN;
}
return -ETH_HLEN;
}
int eth_rebuild_header(struct sk_buff *skb)
{
struct ethhdr *eth = (struct ethhdr *)skb->data;
struct net_device *dev = skb->dev;
switch (eth->h_proto) {
#ifdef CONFIG_INET
case htons(ETH_P_IP):
return arp_find(eth->h_dest, skb);
#endif
default:
netdev_dbg(dev,
"%s: unable to resolve type %X addresses.\n",
dev->name, ntohs(eth->h_proto));
memcpy(eth->h_source, dev->dev_addr, ETH_ALEN);
break;
}
return 0;
}
__be16 eth_type_trans(struct sk_buff *skb, struct net_device *dev)
{
struct ethhdr *eth;
skb->dev = dev;
skb_reset_mac_header(skb);
skb_pull_inline(skb, ETH_HLEN);
eth = eth_hdr(skb);
if (unlikely(is_multicast_ether_addr(eth->h_dest))) {
if (ether_addr_equal_64bits(eth->h_dest, dev->broadcast))
skb->pkt_type = PACKET_BROADCAST;
else
skb->pkt_type = PACKET_MULTICAST;
}
else if (unlikely(!ether_addr_equal_64bits(eth->h_dest,
dev->dev_addr)))
skb->pkt_type = PACKET_OTHERHOST;
if (unlikely(netdev_uses_dsa_tags(dev)))
return htons(ETH_P_DSA);
if (unlikely(netdev_uses_trailer_tags(dev)))
return htons(ETH_P_TRAILER);
if (likely(ntohs(eth->h_proto) >= ETH_P_802_3_MIN))
return eth->h_proto;
if (unlikely(skb->len >= 2 && *(unsigned short *)(skb->data) == 0xFFFF))
return htons(ETH_P_802_3);
return htons(ETH_P_802_2);
}
int eth_header_parse(const struct sk_buff *skb, unsigned char *haddr)
{
const struct ethhdr *eth = eth_hdr(skb);
memcpy(haddr, eth->h_source, ETH_ALEN);
return ETH_ALEN;
}
int eth_header_cache(const struct neighbour *neigh, struct hh_cache *hh, __be16 type)
{
struct ethhdr *eth;
const struct net_device *dev = neigh->dev;
eth = (struct ethhdr *)
(((u8 *) hh->hh_data) + (HH_DATA_OFF(sizeof(*eth))));
if (type == htons(ETH_P_802_3))
return -1;
eth->h_proto = type;
memcpy(eth->h_source, dev->dev_addr, ETH_ALEN);
memcpy(eth->h_dest, neigh->ha, ETH_ALEN);
hh->hh_len = ETH_HLEN;
return 0;
}
void eth_header_cache_update(struct hh_cache *hh,
const struct net_device *dev,
const unsigned char *haddr)
{
memcpy(((u8 *) hh->hh_data) + HH_DATA_OFF(sizeof(struct ethhdr)),
haddr, ETH_ALEN);
}
int eth_prepare_mac_addr_change(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
if (!(dev->priv_flags & IFF_LIVE_ADDR_CHANGE) && netif_running(dev))
return -EBUSY;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
return 0;
}
void eth_commit_mac_addr_change(struct net_device *dev, void *p)
{
struct sockaddr *addr = p;
memcpy(dev->dev_addr, addr->sa_data, ETH_ALEN);
}
int eth_mac_addr(struct net_device *dev, void *p)
{
int ret;
ret = eth_prepare_mac_addr_change(dev, p);
if (ret < 0)
return ret;
eth_commit_mac_addr_change(dev, p);
return 0;
}
int eth_change_mtu(struct net_device *dev, int new_mtu)
{
if (new_mtu < 68 || new_mtu > ETH_DATA_LEN)
return -EINVAL;
dev->mtu = new_mtu;
return 0;
}
int eth_validate_addr(struct net_device *dev)
{
if (!is_valid_ether_addr(dev->dev_addr))
return -EADDRNOTAVAIL;
return 0;
}
void ether_setup(struct net_device *dev)
{
dev->header_ops = &eth_header_ops;
dev->type = ARPHRD_ETHER;
dev->hard_header_len = ETH_HLEN;
dev->mtu = ETH_DATA_LEN;
dev->addr_len = ETH_ALEN;
dev->tx_queue_len = 1000;
dev->flags = IFF_BROADCAST|IFF_MULTICAST;
dev->priv_flags |= IFF_TX_SKB_SHARING;
memset(dev->broadcast, 0xFF, ETH_ALEN);
}
struct net_device *alloc_etherdev_mqs(int sizeof_priv, unsigned int txqs,
unsigned int rxqs)
{
return alloc_netdev_mqs(sizeof_priv, "eth%d", ether_setup, txqs, rxqs);
}
ssize_t sysfs_format_mac(char *buf, const unsigned char *addr, int len)
{
return scnprintf(buf, PAGE_SIZE, "%*phC\n", len, addr);
}
