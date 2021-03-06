static int __init arcnet_rfc1051_init(void)
{
pr_info("%s\n", "RFC1051 \"simple standard\" (`s') encapsulation support loaded");
arc_proto_map[ARC_P_IP_RFC1051]
= arc_proto_map[ARC_P_ARP_RFC1051]
= &rfc1051_proto;
if (arc_bcast_proto == arc_proto_default)
arc_bcast_proto = &rfc1051_proto;
return 0;
}
static void __exit arcnet_rfc1051_exit(void)
{
arcnet_unregister_proto(&rfc1051_proto);
}
static __be16 type_trans(struct sk_buff *skb, struct net_device *dev)
{
struct archdr *pkt = (struct archdr *)skb->data;
struct arc_rfc1051 *soft = &pkt->soft.rfc1051;
int hdr_size = ARC_HDR_SIZE + RFC1051_HDR_SIZE;
skb_reset_mac_header(skb);
skb_pull(skb, hdr_size);
if (pkt->hard.dest == 0) {
skb->pkt_type = PACKET_BROADCAST;
} else if (dev->flags & IFF_PROMISC) {
if (pkt->hard.dest != dev->dev_addr[0])
skb->pkt_type = PACKET_OTHERHOST;
}
switch (soft->proto) {
case ARC_P_IP_RFC1051:
return htons(ETH_P_IP);
case ARC_P_ARP_RFC1051:
return htons(ETH_P_ARP);
default:
dev->stats.rx_errors++;
dev->stats.rx_crc_errors++;
return 0;
}
return htons(ETH_P_IP);
}
static void rx(struct net_device *dev, int bufnum,
struct archdr *pkthdr, int length)
{
struct arcnet_local *lp = netdev_priv(dev);
struct sk_buff *skb;
struct archdr *pkt = pkthdr;
int ofs;
arc_printk(D_DURING, dev, "it's a raw packet (length=%d)\n", length);
if (length >= MinTU)
ofs = 512 - length;
else
ofs = 256 - length;
skb = alloc_skb(length + ARC_HDR_SIZE, GFP_ATOMIC);
if (!skb) {
dev->stats.rx_dropped++;
return;
}
skb_put(skb, length + ARC_HDR_SIZE);
skb->dev = dev;
pkt = (struct archdr *)skb->data;
memcpy(pkt, pkthdr, sizeof(struct archdr));
if (length > sizeof(pkt->soft))
lp->hw.copy_from_card(dev, bufnum, ofs + sizeof(pkt->soft),
pkt->soft.raw + sizeof(pkt->soft),
length - sizeof(pkt->soft));
if (BUGLVL(D_SKB))
arcnet_dump_skb(dev, skb, "rx");
skb->protocol = type_trans(skb, dev);
netif_rx(skb);
}
static int build_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type, uint8_t daddr)
{
int hdr_size = ARC_HDR_SIZE + RFC1051_HDR_SIZE;
struct archdr *pkt = (struct archdr *)skb_push(skb, hdr_size);
struct arc_rfc1051 *soft = &pkt->soft.rfc1051;
switch (type) {
case ETH_P_IP:
soft->proto = ARC_P_IP_RFC1051;
break;
case ETH_P_ARP:
soft->proto = ARC_P_ARP_RFC1051;
break;
default:
arc_printk(D_NORMAL, dev, "RFC1051: I don't understand protocol %d (%Xh)\n",
type, type);
dev->stats.tx_errors++;
dev->stats.tx_aborted_errors++;
return 0;
}
pkt->hard.source = *dev->dev_addr;
if (dev->flags & (IFF_LOOPBACK | IFF_NOARP)) {
pkt->hard.dest = 0;
return hdr_size;
}
pkt->hard.dest = daddr;
return hdr_size;
}
static int prepare_tx(struct net_device *dev, struct archdr *pkt, int length,
int bufnum)
{
struct arcnet_local *lp = netdev_priv(dev);
struct arc_hardware *hard = &pkt->hard;
int ofs;
arc_printk(D_DURING, dev, "prepare_tx: txbufs=%d/%d/%d\n",
lp->next_tx, lp->cur_tx, bufnum);
length -= ARC_HDR_SIZE;
if (length > XMTU) {
arc_printk(D_NORMAL, dev, "Bug! prepare_tx with size %d (> %d)\n",
length, XMTU);
length = XMTU;
}
if (length > MinTU) {
hard->offset[0] = 0;
hard->offset[1] = ofs = 512 - length;
} else if (length > MTU) {
hard->offset[0] = 0;
hard->offset[1] = ofs = 512 - length - 3;
} else {
hard->offset[0] = ofs = 256 - length;
}
lp->hw.copy_to_card(dev, bufnum, 0, hard, ARC_HDR_SIZE);
lp->hw.copy_to_card(dev, bufnum, ofs, &pkt->soft, length);
lp->lastload_dest = hard->dest;
return 1;
}
