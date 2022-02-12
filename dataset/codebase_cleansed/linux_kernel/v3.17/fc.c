static int fc_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type,
const void *daddr, const void *saddr, unsigned int len)
{
struct fch_hdr *fch;
int hdr_len;
if (type == ETH_P_IP || type == ETH_P_ARP)
{
struct fcllc *fcllc;
hdr_len = sizeof(struct fch_hdr) + sizeof(struct fcllc);
fch = (struct fch_hdr *)skb_push(skb, hdr_len);
fcllc = (struct fcllc *)(fch+1);
fcllc->dsap = fcllc->ssap = EXTENDED_SAP;
fcllc->llc = UI_CMD;
fcllc->protid[0] = fcllc->protid[1] = fcllc->protid[2] = 0x00;
fcllc->ethertype = htons(type);
}
else
{
hdr_len = sizeof(struct fch_hdr);
fch = (struct fch_hdr *)skb_push(skb, hdr_len);
}
if(saddr)
memcpy(fch->saddr,saddr,dev->addr_len);
else
memcpy(fch->saddr,dev->dev_addr,dev->addr_len);
if(daddr)
{
memcpy(fch->daddr,daddr,dev->addr_len);
return hdr_len;
}
return -hdr_len;
}
static int fc_rebuild_header(struct sk_buff *skb)
{
#ifdef CONFIG_INET
struct fch_hdr *fch=(struct fch_hdr *)skb->data;
struct fcllc *fcllc=(struct fcllc *)(skb->data+sizeof(struct fch_hdr));
if(fcllc->ethertype != htons(ETH_P_IP)) {
printk("fc_rebuild_header: Don't know how to resolve type %04X addresses ?\n", ntohs(fcllc->ethertype));
return 0;
}
return arp_find(fch->daddr, skb);
#else
return 0;
#endif
}
static void fc_setup(struct net_device *dev)
{
dev->header_ops = &fc_header_ops;
dev->type = ARPHRD_IEEE802;
dev->hard_header_len = FC_HLEN;
dev->mtu = 2024;
dev->addr_len = FC_ALEN;
dev->tx_queue_len = 100;
dev->flags = IFF_BROADCAST;
memset(dev->broadcast, 0xFF, FC_ALEN);
}
struct net_device *alloc_fcdev(int sizeof_priv)
{
return alloc_netdev(sizeof_priv, "fc%d", NET_NAME_UNKNOWN, fc_setup);
}
