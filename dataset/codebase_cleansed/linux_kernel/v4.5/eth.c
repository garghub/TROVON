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
eth_zero_addr(eth->h_dest);
return ETH_HLEN;
}
return -ETH_HLEN;
}
u32 eth_get_headlen(void *data, unsigned int len)
{
const struct ethhdr *eth = (const struct ethhdr *)data;
struct flow_keys keys;
if (unlikely(len < sizeof(*eth)))
return len;
if (!skb_flow_dissect_flow_keys_buf(&keys, data, eth->h_proto,
sizeof(*eth), len, 0))
return max_t(u32, keys.control.thoff, sizeof(*eth));
return min_t(u32, __skb_get_poff(NULL, data, &keys, len), len);
}
__be16 eth_type_trans(struct sk_buff *skb, struct net_device *dev)
{
unsigned short _service_access_point;
const unsigned short *sap;
const struct ethhdr *eth;
skb->dev = dev;
skb_reset_mac_header(skb);
eth = (struct ethhdr *)skb->data;
skb_pull_inline(skb, ETH_HLEN);
if (unlikely(is_multicast_ether_addr_64bits(eth->h_dest))) {
if (ether_addr_equal_64bits(eth->h_dest, dev->broadcast))
skb->pkt_type = PACKET_BROADCAST;
else
skb->pkt_type = PACKET_MULTICAST;
}
else if (unlikely(!ether_addr_equal_64bits(eth->h_dest,
dev->dev_addr)))
skb->pkt_type = PACKET_OTHERHOST;
if (unlikely(netdev_uses_dsa(dev)))
return htons(ETH_P_XDSA);
if (likely(eth_proto_is_802_3(eth->h_proto)))
return eth->h_proto;
sap = skb_header_pointer(skb, 0, sizeof(*sap), &_service_access_point);
if (sap && *sap == 0xFFFF)
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
eth_broadcast_addr(dev->broadcast);
}
struct net_device *alloc_etherdev_mqs(int sizeof_priv, unsigned int txqs,
unsigned int rxqs)
{
return alloc_netdev_mqs(sizeof_priv, "eth%d", NET_NAME_UNKNOWN,
ether_setup, txqs, rxqs);
}
ssize_t sysfs_format_mac(char *buf, const unsigned char *addr, int len)
{
return scnprintf(buf, PAGE_SIZE, "%*phC\n", len, addr);
}
struct sk_buff **eth_gro_receive(struct sk_buff **head,
struct sk_buff *skb)
{
struct sk_buff *p, **pp = NULL;
struct ethhdr *eh, *eh2;
unsigned int hlen, off_eth;
const struct packet_offload *ptype;
__be16 type;
int flush = 1;
off_eth = skb_gro_offset(skb);
hlen = off_eth + sizeof(*eh);
eh = skb_gro_header_fast(skb, off_eth);
if (skb_gro_header_hard(skb, hlen)) {
eh = skb_gro_header_slow(skb, hlen, off_eth);
if (unlikely(!eh))
goto out;
}
flush = 0;
for (p = *head; p; p = p->next) {
if (!NAPI_GRO_CB(p)->same_flow)
continue;
eh2 = (struct ethhdr *)(p->data + off_eth);
if (compare_ether_header(eh, eh2)) {
NAPI_GRO_CB(p)->same_flow = 0;
continue;
}
}
type = eh->h_proto;
rcu_read_lock();
ptype = gro_find_receive_by_type(type);
if (ptype == NULL) {
flush = 1;
goto out_unlock;
}
skb_gro_pull(skb, sizeof(*eh));
skb_gro_postpull_rcsum(skb, eh, sizeof(*eh));
pp = ptype->callbacks.gro_receive(head, skb);
out_unlock:
rcu_read_unlock();
out:
NAPI_GRO_CB(skb)->flush |= flush;
return pp;
}
int eth_gro_complete(struct sk_buff *skb, int nhoff)
{
struct ethhdr *eh = (struct ethhdr *)(skb->data + nhoff);
__be16 type = eh->h_proto;
struct packet_offload *ptype;
int err = -ENOSYS;
if (skb->encapsulation)
skb_set_inner_mac_header(skb, nhoff);
rcu_read_lock();
ptype = gro_find_complete_by_type(type);
if (ptype != NULL)
err = ptype->callbacks.gro_complete(skb, nhoff +
sizeof(struct ethhdr));
rcu_read_unlock();
return err;
}
static int __init eth_offload_init(void)
{
dev_add_offload(&eth_packet_offload);
return 0;
}
unsigned char * __weak arch_get_platform_mac_address(void)
{
return NULL;
}
int eth_platform_get_mac_address(struct device *dev, u8 *mac_addr)
{
const unsigned char *addr;
struct device_node *dp;
if (dev_is_pci(dev))
dp = pci_device_to_OF_node(to_pci_dev(dev));
else
dp = dev->of_node;
addr = NULL;
if (dp)
addr = of_get_mac_address(dp);
if (!addr)
addr = arch_get_platform_mac_address();
if (!addr)
return -ENODEV;
ether_addr_copy(mac_addr, addr);
return 0;
}
