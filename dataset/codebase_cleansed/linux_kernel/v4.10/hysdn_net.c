static int
net_open(struct net_device *dev)
{
struct in_device *in_dev;
hysdn_card *card = dev->ml_priv;
int i;
netif_start_queue(dev);
if (!card->mac_addr[0]) {
for (i = 0; i < ETH_ALEN; i++)
dev->dev_addr[i] = 0xfc;
if ((in_dev = dev->ip_ptr) != NULL) {
struct in_ifaddr *ifa = in_dev->ifa_list;
if (ifa != NULL)
memcpy(dev->dev_addr + (ETH_ALEN - sizeof(ifa->ifa_local)), &ifa->ifa_local, sizeof(ifa->ifa_local));
}
} else
memcpy(dev->dev_addr, card->mac_addr, ETH_ALEN);
return (0);
}
static void
flush_tx_buffers(struct net_local *nl)
{
while (nl->sk_count) {
dev_kfree_skb(nl->skbs[nl->out_idx++]);
if (nl->out_idx >= MAX_SKB_BUFFERS)
nl->out_idx = 0;
nl->sk_count--;
}
}
static int
net_close(struct net_device *dev)
{
netif_stop_queue(dev);
flush_tx_buffers((struct net_local *) dev);
return (0);
}
static netdev_tx_t
net_send_packet(struct sk_buff *skb, struct net_device *dev)
{
struct net_local *lp = (struct net_local *) dev;
spin_lock_irq(&lp->lock);
lp->skbs[lp->in_idx++] = skb;
if (lp->in_idx >= MAX_SKB_BUFFERS)
lp->in_idx = 0;
lp->sk_count++;
netif_trans_update(dev);
if (lp->sk_count >= MAX_SKB_BUFFERS)
netif_stop_queue(dev);
spin_unlock_irq(&lp->lock);
if (lp->sk_count <= 3) {
schedule_work(&((hysdn_card *) dev->ml_priv)->irq_queue);
}
return NETDEV_TX_OK;
}
void
hysdn_tx_netack(hysdn_card *card)
{
struct net_local *lp = card->netif;
if (!lp)
return;
if (!lp->sk_count)
return;
lp->dev->stats.tx_packets++;
lp->dev->stats.tx_bytes += lp->skbs[lp->out_idx]->len;
dev_kfree_skb(lp->skbs[lp->out_idx++]);
if (lp->out_idx >= MAX_SKB_BUFFERS)
lp->out_idx = 0;
if (lp->sk_count-- == MAX_SKB_BUFFERS)
netif_start_queue((struct net_device *) lp);
}
void
hysdn_rx_netpkt(hysdn_card *card, unsigned char *buf, unsigned short len)
{
struct net_local *lp = card->netif;
struct net_device *dev;
struct sk_buff *skb;
if (!lp)
return;
dev = lp->dev;
dev->stats.rx_bytes += len;
skb = dev_alloc_skb(len);
if (skb == NULL) {
printk(KERN_NOTICE "%s: Memory squeeze, dropping packet.\n",
dev->name);
dev->stats.rx_dropped++;
return;
}
memcpy(skb_put(skb, len), buf, len);
skb->protocol = eth_type_trans(skb, dev);
dev->stats.rx_packets++;
netif_rx(skb);
}
struct sk_buff *
hysdn_tx_netget(hysdn_card *card)
{
struct net_local *lp = card->netif;
if (!lp)
return (NULL);
if (!lp->sk_count)
return (NULL);
return (lp->skbs[lp->out_idx]);
}
int
hysdn_net_create(hysdn_card *card)
{
struct net_device *dev;
int i;
struct net_local *lp;
if (!card) {
printk(KERN_WARNING "No card-pt in hysdn_net_create!\n");
return (-ENOMEM);
}
hysdn_net_release(card);
dev = alloc_etherdev(sizeof(struct net_local));
if (!dev) {
printk(KERN_WARNING "HYSDN: unable to allocate mem\n");
return (-ENOMEM);
}
lp = netdev_priv(dev);
lp->dev = dev;
dev->netdev_ops = &hysdn_netdev_ops;
spin_lock_init(&((struct net_local *) dev)->lock);
dev->base_addr = card->iobase;
dev->irq = card->irq;
dev->netdev_ops = &hysdn_netdev_ops;
if ((i = register_netdev(dev))) {
printk(KERN_WARNING "HYSDN: unable to create network device\n");
free_netdev(dev);
return (i);
}
dev->ml_priv = card;
card->netif = dev;
if (card->debug_flags & LOG_NET_INIT)
hysdn_addlog(card, "network device created");
return (0);
}
int
hysdn_net_release(hysdn_card *card)
{
struct net_device *dev = card->netif;
if (!dev)
return (0);
card->netif = NULL;
net_close(dev);
flush_tx_buffers((struct net_local *) dev);
unregister_netdev(dev);
free_netdev(dev);
if (card->debug_flags & LOG_NET_INIT)
hysdn_addlog(card, "network device deleted");
return (0);
}
char *
hysdn_net_getname(hysdn_card *card)
{
struct net_device *dev = card->netif;
if (!dev)
return ("-");
return (dev->name);
}
