void WILC_WFI_SetupPool(struct net_device *dev)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
int i;
struct WILC_WFI_packet *pkt;
priv->ppool = NULL;
for (i = 0; i < pool_size; i++) {
pkt = kmalloc (sizeof (struct WILC_WFI_packet), GFP_KERNEL);
if (pkt == NULL) {
PRINT_D(RX_DBG, "Ran out of memory allocating packet pool\n");
return;
}
pkt->dev = dev;
pkt->next = priv->ppool;
priv->ppool = pkt;
}
}
void WILC_WFI_TearDownPool(struct net_device *dev)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
struct WILC_WFI_packet *pkt;
while ((pkt = priv->ppool)) {
priv->ppool = pkt->next;
kfree (pkt);
}
}
struct WILC_WFI_packet *WILC_WFI_GetTxBuffer(struct net_device *dev)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
unsigned long flags;
struct WILC_WFI_packet *pkt;
spin_lock_irqsave(&priv->lock, flags);
pkt = priv->ppool;
priv->ppool = pkt->next;
if (priv->ppool == NULL) {
PRINT_INFO(RX_DBG, "Pool empty\n");
netif_stop_queue(dev);
}
spin_unlock_irqrestore(&priv->lock, flags);
return pkt;
}
void WILC_WFI_ReleaseBuffer(struct WILC_WFI_packet *pkt)
{
unsigned long flags;
struct WILC_WFI_priv *priv = netdev_priv(pkt->dev);
spin_lock_irqsave(&priv->lock, flags);
pkt->next = priv->ppool;
priv->ppool = pkt;
spin_unlock_irqrestore(&priv->lock, flags);
if (netif_queue_stopped(pkt->dev) && pkt->next == NULL)
netif_wake_queue(pkt->dev);
}
void WILC_WFI_EnqueueBuf(struct net_device *dev, struct WILC_WFI_packet *pkt)
{
unsigned long flags;
struct WILC_WFI_priv *priv = netdev_priv(dev);
spin_lock_irqsave(&priv->lock, flags);
pkt->next = priv->rx_queue;
priv->rx_queue = pkt;
spin_unlock_irqrestore(&priv->lock, flags);
}
struct WILC_WFI_packet *WILC_WFI_DequeueBuf(struct net_device *dev)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
struct WILC_WFI_packet *pkt;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
pkt = priv->rx_queue;
if (pkt != NULL)
priv->rx_queue = pkt->next;
spin_unlock_irqrestore(&priv->lock, flags);
return pkt;
}
static void WILC_WFI_RxInts(struct net_device *dev, int enable)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
priv->rx_int_enabled = enable;
}
int WILC_WFI_Open(struct net_device *dev)
{
memcpy(dev->dev_addr, "\0WLAN0", ETH_ALEN);
if (dev == WILC_WFI_devs[1])
dev->dev_addr[ETH_ALEN - 1]++;
WILC_WFI_InitHostInt(dev);
netif_start_queue(dev);
return 0;
}
int WILC_WFI_Release(struct net_device *dev)
{
netif_stop_queue(dev);
return 0;
}
int WILC_WFI_Config(struct net_device *dev, struct ifmap *map)
{
if (dev->flags & IFF_UP)
return -EBUSY;
if (map->base_addr != dev->base_addr) {
PRINT_D(RX_DBG, KERN_WARNING "WILC_WFI: Can't change I/O address\n");
return -EOPNOTSUPP;
}
if (map->irq != dev->irq) {
dev->irq = map->irq;
}
return 0;
}
void WILC_WFI_Rx(struct net_device *dev, struct WILC_WFI_packet *pkt)
{
int i;
struct sk_buff *skb;
struct WILC_WFI_priv *priv = netdev_priv(dev);
s8 rssi;
skb = dev_alloc_skb(pkt->datalen + 2);
if (!skb) {
if (printk_ratelimit())
PRINT_D(RX_DBG, "WILC_WFI rx: low on mem - packet dropped\n");
priv->stats.rx_dropped++;
goto out;
}
skb_reserve(skb, 2);
memcpy(skb_put(skb, pkt->datalen), pkt->data, pkt->datalen);
if (priv->monitor_flag) {
PRINT_INFO(RX_DBG, "In monitor device name %s\n", dev->name);
priv = wiphy_priv(priv->dev->ieee80211_ptr->wiphy);
PRINT_D(RX_DBG, "VALUE PASSED IN OF HRWD %p\n", priv->hWILCWFIDrv);
if (INFO) {
for (i = 14; i < skb->len; i++)
PRINT_INFO(RX_DBG, "RXdata[%d] %02x\n", i, skb->data[i]);
}
WILC_WFI_monitor_rx(dev, skb);
return;
}
out:
return;
}
static int WILC_WFI_Poll(struct napi_struct *napi, int budget)
{
int npackets = 0;
struct sk_buff *skb;
struct WILC_WFI_priv *priv = container_of(napi, struct WILC_WFI_priv, napi);
struct net_device *dev = priv->dev;
struct WILC_WFI_packet *pkt;
while (npackets < budget && priv->rx_queue) {
pkt = WILC_WFI_DequeueBuf(dev);
skb = dev_alloc_skb(pkt->datalen + 2);
if (!skb) {
if (printk_ratelimit())
PRINT_D(RX_DBG, "WILC_WFI: packet dropped\n");
priv->stats.rx_dropped++;
WILC_WFI_ReleaseBuffer(pkt);
continue;
}
skb_reserve(skb, 2);
memcpy(skb_put(skb, pkt->datalen), pkt->data, pkt->datalen);
skb->dev = dev;
skb->protocol = eth_type_trans(skb, dev);
skb->ip_summed = CHECKSUM_UNNECESSARY;
netif_receive_skb(skb);
npackets++;
WILC_WFI_update_stats(priv->dev->ieee80211_ptr->wiphy, pkt->datalen, WILC_WFI_RX_PKT);
WILC_WFI_ReleaseBuffer(pkt);
}
if (npackets < budget) {
napi_complete(napi);
WILC_WFI_RxInts(dev, 1);
}
return npackets;
}
static void WILC_WFI_RegularInterrupt(int irq, void *dev_id, struct pt_regs *regs)
{
int statusword;
struct WILC_WFI_priv *priv;
struct WILC_WFI_packet *pkt = NULL;
struct net_device *dev = (struct net_device *)dev_id;
if (!dev)
return;
priv = netdev_priv(dev);
spin_lock(&priv->lock);
statusword = priv->status;
priv->status = 0;
if (statusword & WILC_WFI_RX_INTR) {
pkt = priv->rx_queue;
if (pkt) {
priv->rx_queue = pkt->next;
WILC_WFI_Rx(dev, pkt);
}
}
if (statusword & WILC_WFI_TX_INTR) {
WILC_WFI_update_stats(priv->dev->ieee80211_ptr->wiphy, priv->tx_packetlen, WILC_WFI_TX_PKT);
dev_kfree_skb(priv->skb);
}
spin_unlock(&priv->lock);
if (pkt)
WILC_WFI_ReleaseBuffer(pkt);
return;
}
static void WILC_WFI_NapiInterrupt(int irq, void *dev_id, struct pt_regs *regs)
{
int statusword;
struct WILC_WFI_priv *priv;
struct net_device *dev = (struct net_device *)dev_id;
if (!dev)
return;
priv = netdev_priv(dev);
spin_lock(&priv->lock);
statusword = priv->status;
priv->status = 0;
if (statusword & WILC_WFI_RX_INTR) {
WILC_WFI_RxInts(dev, 0);
napi_schedule(&priv->napi);
}
if (statusword & WILC_WFI_TX_INTR) {
WILC_WFI_update_stats(priv->dev->ieee80211_ptr->wiphy, priv->tx_packetlen, WILC_WFI_TX_PKT);
dev_kfree_skb(priv->skb);
}
spin_unlock(&priv->lock);
return;
}
void WILC_WFI_HwTx(char *buf, int len, struct net_device *dev)
{
struct iphdr *ih;
struct net_device *dest;
struct WILC_WFI_priv *priv;
u32 *saddr, *daddr;
struct WILC_WFI_packet *tx_buffer;
if (len < sizeof(struct ethhdr) + sizeof(struct iphdr)) {
PRINT_D(RX_DBG, "WILC_WFI: Hmm... packet too short (%i octets)\n",
len);
return;
}
if (0) {
int i;
PRINT_D(RX_DBG, "len is %i", len);
for (i = 14; i < len; i++)
PRINT_D(RX_DBG, "TXdata[%d] %02x\n", i, buf[i] & 0xff);
}
ih = (struct iphdr *)(buf + sizeof(struct ethhdr));
saddr = &ih->saddr;
daddr = &ih->daddr;
((u8 *)saddr)[2] ^= 1;
((u8 *)daddr)[2] ^= 1;
ih->check = 0;
ih->check = ip_fast_csum((unsigned char *)ih, ih->ihl);
if (dev == WILC_WFI_devs[0])
PRINT_D(RX_DBG, "%08x:%05i --> %08x:%05i\n",
ntohl(ih->saddr), ntohs(((struct tcphdr *)(ih + 1))->source),
ntohl(ih->daddr), ntohs(((struct tcphdr *)(ih + 1))->dest));
else
PRINT_D(RX_DBG, "%08x:%05i <-- %08x:%05i\n",
ntohl(ih->daddr), ntohs(((struct tcphdr *)(ih + 1))->dest),
ntohl(ih->saddr), ntohs(((struct tcphdr *)(ih + 1))->source));
dest = WILC_WFI_devs[dev == WILC_WFI_devs[0] ? 1 : 0];
priv = netdev_priv(dest);
tx_buffer = WILC_WFI_GetTxBuffer(dev);
tx_buffer->datalen = len;
memcpy(tx_buffer->data, buf, len);
WILC_WFI_EnqueueBuf(dest, tx_buffer);
if (priv->rx_int_enabled) {
priv->status |= WILC_WFI_RX_INTR;
WILC_WFI_Interrupt(0, dest, NULL);
}
priv = netdev_priv(dev);
priv->tx_packetlen = len;
priv->tx_packetdata = buf;
priv->status |= WILC_WFI_TX_INTR;
if (lockup && ((priv->stats.tx_packets + 1) % lockup) == 0) {
netif_stop_queue(dev);
PRINT_D(RX_DBG, "Simulate lockup at %ld, txp %ld\n", jiffies,
(unsigned long) priv->stats.tx_packets);
} else
WILC_WFI_Interrupt(0, dev, NULL);
}
int WILC_WFI_Tx(struct sk_buff *skb, struct net_device *dev)
{
int len;
char *data, shortpkt[ETH_ZLEN];
struct WILC_WFI_priv *priv = netdev_priv(dev);
data = skb->data;
len = skb->len;
if (len < ETH_ZLEN) {
memset(shortpkt, 0, ETH_ZLEN);
memcpy(shortpkt, skb->data, skb->len);
len = ETH_ZLEN;
data = shortpkt;
}
dev->trans_start = jiffies;
priv->skb = skb;
WILC_WFI_HwTx(data, len, dev);
return 0;
}
void WILC_WFI_TxTimeout(struct net_device *dev)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
PRINT_D(RX_DBG, "Transmit timeout at %ld, latency %ld\n", jiffies,
jiffies - dev->trans_start);
priv->status = WILC_WFI_TX_INTR;
WILC_WFI_Interrupt(0, dev, NULL);
priv->stats.tx_errors++;
netif_wake_queue(dev);
return;
}
int WILC_WFI_Ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
PRINT_D(RX_DBG, "ioctl\n");
return 0;
}
struct net_device_stats *WILC_WFI_Stats(struct net_device *dev)
{
struct WILC_WFI_priv *priv = netdev_priv(dev);
return &priv->stats;
}
int WILC_WFI_RebuildHeader(struct sk_buff *skb)
{
struct ethhdr *eth = (struct ethhdr *) skb->data;
struct net_device *dev = skb->dev;
memcpy(eth->h_source, dev->dev_addr, dev->addr_len);
memcpy(eth->h_dest, dev->dev_addr, dev->addr_len);
eth->h_dest[ETH_ALEN - 1] ^= 0x01;
return 0;
}
int WILC_WFI_Header(struct sk_buff *skb, struct net_device *dev,
unsigned short type, const void *daddr, const void *saddr,
unsigned int len)
{
struct ethhdr *eth = (struct ethhdr *)skb_push(skb, ETH_HLEN);
eth->h_proto = htons(type);
memcpy(eth->h_source, saddr ? saddr : dev->dev_addr, dev->addr_len);
memcpy(eth->h_dest, daddr ? daddr : dev->dev_addr, dev->addr_len);
eth->h_dest[ETH_ALEN - 1] ^= 0x01;
return dev->hard_header_len;
}
int WILC_WFI_ChangeMtu(struct net_device *dev, int new_mtu)
{
unsigned long flags;
struct WILC_WFI_priv *priv = netdev_priv(dev);
spinlock_t *lock = &priv->lock;
if ((new_mtu < 68) || (new_mtu > 1500))
return -EINVAL;
spin_lock_irqsave(lock, flags);
dev->mtu = new_mtu;
spin_unlock_irqrestore(lock, flags);
return 0;
}
void WILC_WFI_Init(struct net_device *dev)
{
struct WILC_WFI_priv *priv;
ether_setup(dev);
dev->netdev_ops = &WILC_WFI_netdev_ops;
dev->header_ops = &WILC_WFI_header_ops;
dev->watchdog_timeo = timeout;
dev->flags |= IFF_NOARP;
dev->features |= NETIF_F_NO_CSUM;
priv = netdev_priv(dev);
memset(priv, 0, sizeof(struct WILC_WFI_priv));
priv->dev = dev;
netif_napi_add(dev, &priv->napi, WILC_WFI_Poll, 2);
spin_lock_init(&priv->lock);
WILC_WFI_RxInts(dev, 1);
WILC_WFI_SetupPool(dev);
}
void WILC_WFI_Cleanup(void)
{
int i;
struct WILC_WFI_priv *priv[2];
for (i = 0; i < 2; i++) {
priv[i] = netdev_priv(WILC_WFI_devs[i]);
if (WILC_WFI_devs[i]) {
PRINT_D(RX_DBG, "Unregistering\n");
unregister_netdev(WILC_WFI_devs[i]);
WILC_WFI_TearDownPool(WILC_WFI_devs[i]);
free_netdev(WILC_WFI_devs[i]);
PRINT_D(RX_DBG, "[NETDEV]Stopping interface\n");
WILC_WFI_DeInitHostInt(WILC_WFI_devs[i]);
WILC_WFI_WiphyFree(WILC_WFI_devs[i]);
}
}
WILC_WFI_deinit_mon_interface();
return;
}
int WILC_WFI_InitModule(void)
{
int result, i, ret = -ENOMEM;
struct WILC_WFI_priv *priv[2], *netpriv;
struct wireless_dev *wdev;
WILC_WFI_Interrupt = use_napi ? WILC_WFI_NapiInterrupt : WILC_WFI_RegularInterrupt;
char buf[IFNAMSIZ];
for (i = 0; i < 2; i++) {
WILC_WFI_devs[i] = alloc_netdev(sizeof(struct WILC_WFI_priv), "wlan%d",
WILC_WFI_Init);
if (WILC_WFI_devs[i] == NULL)
goto out;
wdev = WILC_WFI_WiphyRegister(WILC_WFI_devs[i]);
WILC_WFI_devs[i]->ieee80211_ptr = wdev;
netpriv = netdev_priv(WILC_WFI_devs[i]);
netpriv->dev->ieee80211_ptr = wdev;
netpriv->dev->ml_priv = netpriv;
wdev->netdev = netpriv->dev;
result = register_netdev(WILC_WFI_devs[i]);
if (result)
PRINT_D(RX_DBG, "WILC_WFI: error %i registering device \"%s\"\n",
result, WILC_WFI_devs[i]->name);
else
ret = 0;
}
priv[0] = netdev_priv(WILC_WFI_devs[0]);
priv[1] = netdev_priv(WILC_WFI_devs[1]);
if (priv[1]->dev->ieee80211_ptr->wiphy->interface_modes && BIT(NL80211_IFTYPE_MONITOR)) {
}
priv[0]->bCfgScanning = false;
priv[0]->u32RcvdChCount = 0;
WILC_memset(priv[0]->au8AssociatedBss, 0xFF, ETH_ALEN);
if (ret) {
PRINT_ER("Error Init Driver\n");
}
out:
if (ret)
WILC_WFI_Cleanup();
return ret;
}
