static inline void memcpy_swab32(u32 *dest, u32 *src, int cnt)
{
int i;
for (i = 0; i < cnt; i++)
dest[i] = swab32(src[i]);
}
static int ixp_ptp_match(struct sk_buff *skb, u16 uid_hi, u32 uid_lo, u16 seqid)
{
u8 *data = skb->data;
unsigned int offset;
u16 *hi, *id;
u32 lo;
if (sk_run_filter(skb, ptp_filter) != PTP_CLASS_V1_IPV4)
return 0;
offset = ETH_HLEN + IPV4_HLEN(data) + UDP_HLEN;
if (skb->len < offset + OFF_PTP_SEQUENCE_ID + sizeof(seqid))
return 0;
hi = (u16 *)(data + offset + OFF_PTP_SOURCE_UUID);
id = (u16 *)(data + offset + OFF_PTP_SEQUENCE_ID);
memcpy(&lo, &hi[1], sizeof(lo));
return (uid_hi == ntohs(*hi) &&
uid_lo == ntohl(lo) &&
seqid == ntohs(*id));
}
static void ixp_rx_timestamp(struct port *port, struct sk_buff *skb)
{
struct skb_shared_hwtstamps *shhwtstamps;
struct ixp46x_ts_regs *regs;
u64 ns;
u32 ch, hi, lo, val;
u16 uid, seq;
if (!port->hwts_rx_en)
return;
ch = PORT2CHANNEL(port);
regs = (struct ixp46x_ts_regs __iomem *) IXP4XX_TIMESYNC_BASE_VIRT;
val = __raw_readl(&regs->channel[ch].ch_event);
if (!(val & RX_SNAPSHOT_LOCKED))
return;
lo = __raw_readl(&regs->channel[ch].src_uuid_lo);
hi = __raw_readl(&regs->channel[ch].src_uuid_hi);
uid = hi & 0xffff;
seq = (hi >> 16) & 0xffff;
if (!ixp_ptp_match(skb, htons(uid), htonl(lo), htons(seq)))
goto out;
lo = __raw_readl(&regs->channel[ch].rx_snap_lo);
hi = __raw_readl(&regs->channel[ch].rx_snap_hi);
ns = ((u64) hi) << 32;
ns |= lo;
ns <<= TICKS_NS_SHIFT;
shhwtstamps = skb_hwtstamps(skb);
memset(shhwtstamps, 0, sizeof(*shhwtstamps));
shhwtstamps->hwtstamp = ns_to_ktime(ns);
out:
__raw_writel(RX_SNAPSHOT_LOCKED, &regs->channel[ch].ch_event);
}
static void ixp_tx_timestamp(struct port *port, struct sk_buff *skb)
{
struct skb_shared_hwtstamps shhwtstamps;
struct ixp46x_ts_regs *regs;
struct skb_shared_info *shtx;
u64 ns;
u32 ch, cnt, hi, lo, val;
shtx = skb_shinfo(skb);
if (unlikely(shtx->tx_flags & SKBTX_HW_TSTAMP && port->hwts_tx_en))
shtx->tx_flags |= SKBTX_IN_PROGRESS;
else
return;
ch = PORT2CHANNEL(port);
regs = (struct ixp46x_ts_regs __iomem *) IXP4XX_TIMESYNC_BASE_VIRT;
for (cnt = 0; cnt < 100; cnt++) {
val = __raw_readl(&regs->channel[ch].ch_event);
if (val & TX_SNAPSHOT_LOCKED)
break;
udelay(1);
}
if (!(val & TX_SNAPSHOT_LOCKED)) {
shtx->tx_flags &= ~SKBTX_IN_PROGRESS;
return;
}
lo = __raw_readl(&regs->channel[ch].tx_snap_lo);
hi = __raw_readl(&regs->channel[ch].tx_snap_hi);
ns = ((u64) hi) << 32;
ns |= lo;
ns <<= TICKS_NS_SHIFT;
memset(&shhwtstamps, 0, sizeof(shhwtstamps));
shhwtstamps.hwtstamp = ns_to_ktime(ns);
skb_tstamp_tx(skb, &shhwtstamps);
__raw_writel(TX_SNAPSHOT_LOCKED, &regs->channel[ch].ch_event);
}
static int hwtstamp_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
struct hwtstamp_config cfg;
struct ixp46x_ts_regs *regs;
struct port *port = netdev_priv(netdev);
int ch;
if (copy_from_user(&cfg, ifr->ifr_data, sizeof(cfg)))
return -EFAULT;
if (cfg.flags)
return -EINVAL;
ch = PORT2CHANNEL(port);
regs = (struct ixp46x_ts_regs __iomem *) IXP4XX_TIMESYNC_BASE_VIRT;
switch (cfg.tx_type) {
case HWTSTAMP_TX_OFF:
port->hwts_tx_en = 0;
break;
case HWTSTAMP_TX_ON:
port->hwts_tx_en = 1;
break;
default:
return -ERANGE;
}
switch (cfg.rx_filter) {
case HWTSTAMP_FILTER_NONE:
port->hwts_rx_en = 0;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
port->hwts_rx_en = PTP_SLAVE_MODE;
__raw_writel(0, &regs->channel[ch].ch_control);
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
port->hwts_rx_en = PTP_MASTER_MODE;
__raw_writel(MASTER_MODE, &regs->channel[ch].ch_control);
break;
default:
return -ERANGE;
}
__raw_writel(TX_SNAPSHOT_LOCKED | RX_SNAPSHOT_LOCKED,
&regs->channel[ch].ch_event);
return copy_to_user(ifr->ifr_data, &cfg, sizeof(cfg)) ? -EFAULT : 0;
}
static int ixp4xx_mdio_cmd(struct mii_bus *bus, int phy_id, int location,
int write, u16 cmd)
{
int cycles = 0;
if (__raw_readl(&mdio_regs->mdio_command[3]) & 0x80) {
printk(KERN_ERR "%s: MII not ready to transmit\n", bus->name);
return -1;
}
if (write) {
__raw_writel(cmd & 0xFF, &mdio_regs->mdio_command[0]);
__raw_writel(cmd >> 8, &mdio_regs->mdio_command[1]);
}
__raw_writel(((phy_id << 5) | location) & 0xFF,
&mdio_regs->mdio_command[2]);
__raw_writel((phy_id >> 3) | (write << 2) | 0x80 ,
&mdio_regs->mdio_command[3]);
while ((cycles < MAX_MDIO_RETRIES) &&
(__raw_readl(&mdio_regs->mdio_command[3]) & 0x80)) {
udelay(1);
cycles++;
}
if (cycles == MAX_MDIO_RETRIES) {
printk(KERN_ERR "%s #%i: MII write failed\n", bus->name,
phy_id);
return -1;
}
#if DEBUG_MDIO
printk(KERN_DEBUG "%s #%i: mdio_%s() took %i cycles\n", bus->name,
phy_id, write ? "write" : "read", cycles);
#endif
if (write)
return 0;
if (__raw_readl(&mdio_regs->mdio_status[3]) & 0x80) {
#if DEBUG_MDIO
printk(KERN_DEBUG "%s #%i: MII read failed\n", bus->name,
phy_id);
#endif
return 0xFFFF;
}
return (__raw_readl(&mdio_regs->mdio_status[0]) & 0xFF) |
((__raw_readl(&mdio_regs->mdio_status[1]) & 0xFF) << 8);
}
static int ixp4xx_mdio_read(struct mii_bus *bus, int phy_id, int location)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&mdio_lock, flags);
ret = ixp4xx_mdio_cmd(bus, phy_id, location, 0, 0);
spin_unlock_irqrestore(&mdio_lock, flags);
#if DEBUG_MDIO
printk(KERN_DEBUG "%s #%i: MII read [%i] -> 0x%X\n", bus->name,
phy_id, location, ret);
#endif
return ret;
}
static int ixp4xx_mdio_write(struct mii_bus *bus, int phy_id, int location,
u16 val)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&mdio_lock, flags);
ret = ixp4xx_mdio_cmd(bus, phy_id, location, 1, val);
spin_unlock_irqrestore(&mdio_lock, flags);
#if DEBUG_MDIO
printk(KERN_DEBUG "%s #%i: MII write [%i] <- 0x%X, err = %i\n",
bus->name, phy_id, location, val, ret);
#endif
return ret;
}
static int ixp4xx_mdio_register(void)
{
int err;
if (!(mdio_bus = mdiobus_alloc()))
return -ENOMEM;
if (cpu_is_ixp43x()) {
if (!(ixp4xx_read_feature_bits() & IXP4XX_FEATURE_NPEC_ETH))
return -ENODEV;
mdio_regs = (struct eth_regs __iomem *)IXP4XX_EthC_BASE_VIRT;
} else {
if (!(ixp4xx_read_feature_bits() & IXP4XX_FEATURE_NPEB_ETH0))
return -ENODEV;
mdio_regs = (struct eth_regs __iomem *)IXP4XX_EthB_BASE_VIRT;
}
__raw_writel(DEFAULT_CORE_CNTRL, &mdio_regs->core_control);
spin_lock_init(&mdio_lock);
mdio_bus->name = "IXP4xx MII Bus";
mdio_bus->read = &ixp4xx_mdio_read;
mdio_bus->write = &ixp4xx_mdio_write;
snprintf(mdio_bus->id, MII_BUS_ID_SIZE, "ixp4xx-eth-0");
if ((err = mdiobus_register(mdio_bus)))
mdiobus_free(mdio_bus);
return err;
}
static void ixp4xx_mdio_remove(void)
{
mdiobus_unregister(mdio_bus);
mdiobus_free(mdio_bus);
}
static void ixp4xx_adjust_link(struct net_device *dev)
{
struct port *port = netdev_priv(dev);
struct phy_device *phydev = port->phydev;
if (!phydev->link) {
if (port->speed) {
port->speed = 0;
printk(KERN_INFO "%s: link down\n", dev->name);
}
return;
}
if (port->speed == phydev->speed && port->duplex == phydev->duplex)
return;
port->speed = phydev->speed;
port->duplex = phydev->duplex;
if (port->duplex)
__raw_writel(DEFAULT_TX_CNTRL0 & ~TX_CNTRL0_HALFDUPLEX,
&port->regs->tx_control[0]);
else
__raw_writel(DEFAULT_TX_CNTRL0 | TX_CNTRL0_HALFDUPLEX,
&port->regs->tx_control[0]);
printk(KERN_INFO "%s: link up, speed %u Mb/s, %s duplex\n",
dev->name, port->speed, port->duplex ? "full" : "half");
}
static inline void debug_pkt(struct net_device *dev, const char *func,
u8 *data, int len)
{
#if DEBUG_PKT_BYTES
int i;
printk(KERN_DEBUG "%s: %s(%i) ", dev->name, func, len);
for (i = 0; i < len; i++) {
if (i >= DEBUG_PKT_BYTES)
break;
printk("%s%02X",
((i == 6) || (i == 12) || (i >= 14)) ? " " : "",
data[i]);
}
printk("\n");
#endif
}
static inline void debug_desc(u32 phys, struct desc *desc)
{
#if DEBUG_DESC
printk(KERN_DEBUG "%X: %X %3X %3X %08X %2X < %2X %4X %X"
" %X %X %02X%02X%02X%02X%02X%02X < %02X%02X%02X%02X%02X%02X\n",
phys, desc->next, desc->buf_len, desc->pkt_len,
desc->data, desc->dest_id, desc->src_id, desc->flags,
desc->qos, desc->padlen, desc->vlan_tci,
desc->dst_mac_0, desc->dst_mac_1, desc->dst_mac_2,
desc->dst_mac_3, desc->dst_mac_4, desc->dst_mac_5,
desc->src_mac_0, desc->src_mac_1, desc->src_mac_2,
desc->src_mac_3, desc->src_mac_4, desc->src_mac_5);
#endif
}
static inline int queue_get_desc(unsigned int queue, struct port *port,
int is_tx)
{
u32 phys, tab_phys, n_desc;
struct desc *tab;
if (!(phys = qmgr_get_entry(queue)))
return -1;
phys &= ~0x1F;
tab_phys = is_tx ? tx_desc_phys(port, 0) : rx_desc_phys(port, 0);
tab = is_tx ? tx_desc_ptr(port, 0) : rx_desc_ptr(port, 0);
n_desc = (phys - tab_phys) / sizeof(struct desc);
BUG_ON(n_desc >= (is_tx ? TX_DESCS : RX_DESCS));
debug_desc(phys, &tab[n_desc]);
BUG_ON(tab[n_desc].next);
return n_desc;
}
static inline void queue_put_desc(unsigned int queue, u32 phys,
struct desc *desc)
{
debug_desc(phys, desc);
BUG_ON(phys & 0x1F);
qmgr_put_entry(queue, phys);
}
static inline void dma_unmap_tx(struct port *port, struct desc *desc)
{
#ifdef __ARMEB__
dma_unmap_single(&port->netdev->dev, desc->data,
desc->buf_len, DMA_TO_DEVICE);
#else
dma_unmap_single(&port->netdev->dev, desc->data & ~3,
ALIGN((desc->data & 3) + desc->buf_len, 4),
DMA_TO_DEVICE);
#endif
}
static void eth_rx_irq(void *pdev)
{
struct net_device *dev = pdev;
struct port *port = netdev_priv(dev);
#if DEBUG_RX
printk(KERN_DEBUG "%s: eth_rx_irq\n", dev->name);
#endif
qmgr_disable_irq(port->plat->rxq);
napi_schedule(&port->napi);
}
static int eth_poll(struct napi_struct *napi, int budget)
{
struct port *port = container_of(napi, struct port, napi);
struct net_device *dev = port->netdev;
unsigned int rxq = port->plat->rxq, rxfreeq = RXFREE_QUEUE(port->id);
int received = 0;
#if DEBUG_RX
printk(KERN_DEBUG "%s: eth_poll\n", dev->name);
#endif
while (received < budget) {
struct sk_buff *skb;
struct desc *desc;
int n;
#ifdef __ARMEB__
struct sk_buff *temp;
u32 phys;
#endif
if ((n = queue_get_desc(rxq, port, 0)) < 0) {
#if DEBUG_RX
printk(KERN_DEBUG "%s: eth_poll napi_complete\n",
dev->name);
#endif
napi_complete(napi);
qmgr_enable_irq(rxq);
if (!qmgr_stat_below_low_watermark(rxq) &&
napi_reschedule(napi)) {
#if DEBUG_RX
printk(KERN_DEBUG "%s: eth_poll"
" napi_reschedule successed\n",
dev->name);
#endif
qmgr_disable_irq(rxq);
continue;
}
#if DEBUG_RX
printk(KERN_DEBUG "%s: eth_poll all done\n",
dev->name);
#endif
return received;
}
desc = rx_desc_ptr(port, n);
#ifdef __ARMEB__
if ((skb = netdev_alloc_skb(dev, RX_BUFF_SIZE))) {
phys = dma_map_single(&dev->dev, skb->data,
RX_BUFF_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&dev->dev, phys)) {
dev_kfree_skb(skb);
skb = NULL;
}
}
#else
skb = netdev_alloc_skb(dev,
ALIGN(NET_IP_ALIGN + desc->pkt_len, 4));
#endif
if (!skb) {
dev->stats.rx_dropped++;
desc->buf_len = MAX_MRU;
desc->pkt_len = 0;
queue_put_desc(rxfreeq, rx_desc_phys(port, n), desc);
continue;
}
#ifdef __ARMEB__
temp = skb;
skb = port->rx_buff_tab[n];
dma_unmap_single(&dev->dev, desc->data - NET_IP_ALIGN,
RX_BUFF_SIZE, DMA_FROM_DEVICE);
#else
dma_sync_single_for_cpu(&dev->dev, desc->data - NET_IP_ALIGN,
RX_BUFF_SIZE, DMA_FROM_DEVICE);
memcpy_swab32((u32 *)skb->data, (u32 *)port->rx_buff_tab[n],
ALIGN(NET_IP_ALIGN + desc->pkt_len, 4) / 4);
#endif
skb_reserve(skb, NET_IP_ALIGN);
skb_put(skb, desc->pkt_len);
debug_pkt(dev, "eth_poll", skb->data, skb->len);
ixp_rx_timestamp(port, skb);
skb->protocol = eth_type_trans(skb, dev);
dev->stats.rx_packets++;
dev->stats.rx_bytes += skb->len;
netif_receive_skb(skb);
#ifdef __ARMEB__
port->rx_buff_tab[n] = temp;
desc->data = phys + NET_IP_ALIGN;
#endif
desc->buf_len = MAX_MRU;
desc->pkt_len = 0;
queue_put_desc(rxfreeq, rx_desc_phys(port, n), desc);
received++;
}
#if DEBUG_RX
printk(KERN_DEBUG "eth_poll(): end, not all work done\n");
#endif
return received;
}
static void eth_txdone_irq(void *unused)
{
u32 phys;
#if DEBUG_TX
printk(KERN_DEBUG DRV_NAME ": eth_txdone_irq\n");
#endif
while ((phys = qmgr_get_entry(TXDONE_QUEUE)) != 0) {
u32 npe_id, n_desc;
struct port *port;
struct desc *desc;
int start;
npe_id = phys & 3;
BUG_ON(npe_id >= MAX_NPES);
port = npe_port_tab[npe_id];
BUG_ON(!port);
phys &= ~0x1F;
n_desc = (phys - tx_desc_phys(port, 0)) / sizeof(struct desc);
BUG_ON(n_desc >= TX_DESCS);
desc = tx_desc_ptr(port, n_desc);
debug_desc(phys, desc);
if (port->tx_buff_tab[n_desc]) {
port->netdev->stats.tx_packets++;
port->netdev->stats.tx_bytes += desc->pkt_len;
dma_unmap_tx(port, desc);
#if DEBUG_TX
printk(KERN_DEBUG "%s: eth_txdone_irq free %p\n",
port->netdev->name, port->tx_buff_tab[n_desc]);
#endif
free_buffer_irq(port->tx_buff_tab[n_desc]);
port->tx_buff_tab[n_desc] = NULL;
}
start = qmgr_stat_below_low_watermark(port->plat->txreadyq);
queue_put_desc(port->plat->txreadyq, phys, desc);
if (start) {
#if DEBUG_TX
printk(KERN_DEBUG "%s: eth_txdone_irq xmit ready\n",
port->netdev->name);
#endif
netif_wake_queue(port->netdev);
}
}
}
static int eth_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct port *port = netdev_priv(dev);
unsigned int txreadyq = port->plat->txreadyq;
int len, offset, bytes, n;
void *mem;
u32 phys;
struct desc *desc;
#if DEBUG_TX
printk(KERN_DEBUG "%s: eth_xmit\n", dev->name);
#endif
if (unlikely(skb->len > MAX_MRU)) {
dev_kfree_skb(skb);
dev->stats.tx_errors++;
return NETDEV_TX_OK;
}
debug_pkt(dev, "eth_xmit", skb->data, skb->len);
len = skb->len;
#ifdef __ARMEB__
offset = 0;
bytes = len;
mem = skb->data;
#else
offset = (int)skb->data & 3;
bytes = ALIGN(offset + len, 4);
if (!(mem = kmalloc(bytes, GFP_ATOMIC))) {
dev_kfree_skb(skb);
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
memcpy_swab32(mem, (u32 *)((int)skb->data & ~3), bytes / 4);
#endif
phys = dma_map_single(&dev->dev, mem, bytes, DMA_TO_DEVICE);
if (dma_mapping_error(&dev->dev, phys)) {
dev_kfree_skb(skb);
#ifndef __ARMEB__
kfree(mem);
#endif
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
n = queue_get_desc(txreadyq, port, 1);
BUG_ON(n < 0);
desc = tx_desc_ptr(port, n);
#ifdef __ARMEB__
port->tx_buff_tab[n] = skb;
#else
port->tx_buff_tab[n] = mem;
#endif
desc->data = phys + offset;
desc->buf_len = desc->pkt_len = len;
wmb();
queue_put_desc(TX_QUEUE(port->id), tx_desc_phys(port, n), desc);
if (qmgr_stat_below_low_watermark(txreadyq)) {
#if DEBUG_TX
printk(KERN_DEBUG "%s: eth_xmit queue full\n", dev->name);
#endif
netif_stop_queue(dev);
if (!qmgr_stat_below_low_watermark(txreadyq)) {
#if DEBUG_TX
printk(KERN_DEBUG "%s: eth_xmit ready again\n",
dev->name);
#endif
netif_wake_queue(dev);
}
}
#if DEBUG_TX
printk(KERN_DEBUG "%s: eth_xmit end\n", dev->name);
#endif
ixp_tx_timestamp(port, skb);
skb_tx_timestamp(skb);
#ifndef __ARMEB__
dev_kfree_skb(skb);
#endif
return NETDEV_TX_OK;
}
static void eth_set_mcast_list(struct net_device *dev)
{
struct port *port = netdev_priv(dev);
struct netdev_hw_addr *ha;
u8 diffs[ETH_ALEN], *addr;
int i;
static const u8 allmulti[] = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x00 };
if (dev->flags & IFF_ALLMULTI) {
for (i = 0; i < ETH_ALEN; i++) {
__raw_writel(allmulti[i], &port->regs->mcast_addr[i]);
__raw_writel(allmulti[i], &port->regs->mcast_mask[i]);
}
__raw_writel(DEFAULT_RX_CNTRL0 | RX_CNTRL0_ADDR_FLTR_EN,
&port->regs->rx_control[0]);
return;
}
if ((dev->flags & IFF_PROMISC) || netdev_mc_empty(dev)) {
__raw_writel(DEFAULT_RX_CNTRL0 & ~RX_CNTRL0_ADDR_FLTR_EN,
&port->regs->rx_control[0]);
return;
}
memset(diffs, 0, ETH_ALEN);
addr = NULL;
netdev_for_each_mc_addr(ha, dev) {
if (!addr)
addr = ha->addr;
for (i = 0; i < ETH_ALEN; i++)
diffs[i] |= addr[i] ^ ha->addr[i];
}
for (i = 0; i < ETH_ALEN; i++) {
__raw_writel(addr[i], &port->regs->mcast_addr[i]);
__raw_writel(~diffs[i], &port->regs->mcast_mask[i]);
}
__raw_writel(DEFAULT_RX_CNTRL0 | RX_CNTRL0_ADDR_FLTR_EN,
&port->regs->rx_control[0]);
}
static int eth_ioctl(struct net_device *dev, struct ifreq *req, int cmd)
{
struct port *port = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (cpu_is_ixp46x() && cmd == SIOCSHWTSTAMP)
return hwtstamp_ioctl(dev, req, cmd);
return phy_mii_ioctl(port->phydev, req, cmd);
}
static void ixp4xx_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct port *port = netdev_priv(dev);
strcpy(info->driver, DRV_NAME);
snprintf(info->fw_version, sizeof(info->fw_version), "%u:%u:%u:%u",
port->firmware[0], port->firmware[1],
port->firmware[2], port->firmware[3]);
strcpy(info->bus_info, "internal");
}
static int ixp4xx_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct port *port = netdev_priv(dev);
return phy_ethtool_gset(port->phydev, cmd);
}
static int ixp4xx_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct port *port = netdev_priv(dev);
return phy_ethtool_sset(port->phydev, cmd);
}
static int ixp4xx_nway_reset(struct net_device *dev)
{
struct port *port = netdev_priv(dev);
return phy_start_aneg(port->phydev);
}
static int request_queues(struct port *port)
{
int err;
err = qmgr_request_queue(RXFREE_QUEUE(port->id), RX_DESCS, 0, 0,
"%s:RX-free", port->netdev->name);
if (err)
return err;
err = qmgr_request_queue(port->plat->rxq, RX_DESCS, 0, 0,
"%s:RX", port->netdev->name);
if (err)
goto rel_rxfree;
err = qmgr_request_queue(TX_QUEUE(port->id), TX_DESCS, 0, 0,
"%s:TX", port->netdev->name);
if (err)
goto rel_rx;
err = qmgr_request_queue(port->plat->txreadyq, TX_DESCS, 0, 0,
"%s:TX-ready", port->netdev->name);
if (err)
goto rel_tx;
if (!ports_open) {
err = qmgr_request_queue(TXDONE_QUEUE, TXDONE_QUEUE_LEN, 0, 0,
"%s:TX-done", DRV_NAME);
if (err)
goto rel_txready;
}
return 0;
rel_txready:
qmgr_release_queue(port->plat->txreadyq);
rel_tx:
qmgr_release_queue(TX_QUEUE(port->id));
rel_rx:
qmgr_release_queue(port->plat->rxq);
rel_rxfree:
qmgr_release_queue(RXFREE_QUEUE(port->id));
printk(KERN_DEBUG "%s: unable to request hardware queues\n",
port->netdev->name);
return err;
}
static void release_queues(struct port *port)
{
qmgr_release_queue(RXFREE_QUEUE(port->id));
qmgr_release_queue(port->plat->rxq);
qmgr_release_queue(TX_QUEUE(port->id));
qmgr_release_queue(port->plat->txreadyq);
if (!ports_open)
qmgr_release_queue(TXDONE_QUEUE);
}
static int init_queues(struct port *port)
{
int i;
if (!ports_open)
if (!(dma_pool = dma_pool_create(DRV_NAME, NULL,
POOL_ALLOC_SIZE, 32, 0)))
return -ENOMEM;
if (!(port->desc_tab = dma_pool_alloc(dma_pool, GFP_KERNEL,
&port->desc_tab_phys)))
return -ENOMEM;
memset(port->desc_tab, 0, POOL_ALLOC_SIZE);
memset(port->rx_buff_tab, 0, sizeof(port->rx_buff_tab));
memset(port->tx_buff_tab, 0, sizeof(port->tx_buff_tab));
for (i = 0; i < RX_DESCS; i++) {
struct desc *desc = rx_desc_ptr(port, i);
buffer_t *buff;
void *data;
#ifdef __ARMEB__
if (!(buff = netdev_alloc_skb(port->netdev, RX_BUFF_SIZE)))
return -ENOMEM;
data = buff->data;
#else
if (!(buff = kmalloc(RX_BUFF_SIZE, GFP_KERNEL)))
return -ENOMEM;
data = buff;
#endif
desc->buf_len = MAX_MRU;
desc->data = dma_map_single(&port->netdev->dev, data,
RX_BUFF_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(&port->netdev->dev, desc->data)) {
free_buffer(buff);
return -EIO;
}
desc->data += NET_IP_ALIGN;
port->rx_buff_tab[i] = buff;
}
return 0;
}
static void destroy_queues(struct port *port)
{
int i;
if (port->desc_tab) {
for (i = 0; i < RX_DESCS; i++) {
struct desc *desc = rx_desc_ptr(port, i);
buffer_t *buff = port->rx_buff_tab[i];
if (buff) {
dma_unmap_single(&port->netdev->dev,
desc->data - NET_IP_ALIGN,
RX_BUFF_SIZE, DMA_FROM_DEVICE);
free_buffer(buff);
}
}
for (i = 0; i < TX_DESCS; i++) {
struct desc *desc = tx_desc_ptr(port, i);
buffer_t *buff = port->tx_buff_tab[i];
if (buff) {
dma_unmap_tx(port, desc);
free_buffer(buff);
}
}
dma_pool_free(dma_pool, port->desc_tab, port->desc_tab_phys);
port->desc_tab = NULL;
}
if (!ports_open && dma_pool) {
dma_pool_destroy(dma_pool);
dma_pool = NULL;
}
}
static int eth_open(struct net_device *dev)
{
struct port *port = netdev_priv(dev);
struct npe *npe = port->npe;
struct msg msg;
int i, err;
if (!npe_running(npe)) {
err = npe_load_firmware(npe, npe_name(npe), &dev->dev);
if (err)
return err;
if (npe_recv_message(npe, &msg, "ETH_GET_STATUS")) {
printk(KERN_ERR "%s: %s not responding\n", dev->name,
npe_name(npe));
return -EIO;
}
port->firmware[0] = msg.byte4;
port->firmware[1] = msg.byte5;
port->firmware[2] = msg.byte6;
port->firmware[3] = msg.byte7;
}
memset(&msg, 0, sizeof(msg));
msg.cmd = NPE_VLAN_SETRXQOSENTRY;
msg.eth_id = port->id;
msg.byte5 = port->plat->rxq | 0x80;
msg.byte7 = port->plat->rxq << 4;
for (i = 0; i < 8; i++) {
msg.byte3 = i;
if (npe_send_recv_message(port->npe, &msg, "ETH_SET_RXQ"))
return -EIO;
}
msg.cmd = NPE_EDB_SETPORTADDRESS;
msg.eth_id = PHYSICAL_ID(port->id);
msg.byte2 = dev->dev_addr[0];
msg.byte3 = dev->dev_addr[1];
msg.byte4 = dev->dev_addr[2];
msg.byte5 = dev->dev_addr[3];
msg.byte6 = dev->dev_addr[4];
msg.byte7 = dev->dev_addr[5];
if (npe_send_recv_message(port->npe, &msg, "ETH_SET_MAC"))
return -EIO;
memset(&msg, 0, sizeof(msg));
msg.cmd = NPE_FW_SETFIREWALLMODE;
msg.eth_id = port->id;
if (npe_send_recv_message(port->npe, &msg, "ETH_SET_FIREWALL_MODE"))
return -EIO;
if ((err = request_queues(port)) != 0)
return err;
if ((err = init_queues(port)) != 0) {
destroy_queues(port);
release_queues(port);
return err;
}
port->speed = 0;
phy_start(port->phydev);
for (i = 0; i < ETH_ALEN; i++)
__raw_writel(dev->dev_addr[i], &port->regs->hw_addr[i]);
__raw_writel(0x08, &port->regs->random_seed);
__raw_writel(0x12, &port->regs->partial_empty_threshold);
__raw_writel(0x30, &port->regs->partial_full_threshold);
__raw_writel(0x08, &port->regs->tx_start_bytes);
__raw_writel(0x15, &port->regs->tx_deferral);
__raw_writel(0x08, &port->regs->tx_2part_deferral[0]);
__raw_writel(0x07, &port->regs->tx_2part_deferral[1]);
__raw_writel(0x80, &port->regs->slot_time);
__raw_writel(0x01, &port->regs->int_clock_threshold);
for (i = 0; i < TX_DESCS; i++)
queue_put_desc(port->plat->txreadyq,
tx_desc_phys(port, i), tx_desc_ptr(port, i));
for (i = 0; i < RX_DESCS; i++)
queue_put_desc(RXFREE_QUEUE(port->id),
rx_desc_phys(port, i), rx_desc_ptr(port, i));
__raw_writel(TX_CNTRL1_RETRIES, &port->regs->tx_control[1]);
__raw_writel(DEFAULT_TX_CNTRL0, &port->regs->tx_control[0]);
__raw_writel(0, &port->regs->rx_control[1]);
__raw_writel(DEFAULT_RX_CNTRL0, &port->regs->rx_control[0]);
napi_enable(&port->napi);
eth_set_mcast_list(dev);
netif_start_queue(dev);
qmgr_set_irq(port->plat->rxq, QUEUE_IRQ_SRC_NOT_EMPTY,
eth_rx_irq, dev);
if (!ports_open) {
qmgr_set_irq(TXDONE_QUEUE, QUEUE_IRQ_SRC_NOT_EMPTY,
eth_txdone_irq, NULL);
qmgr_enable_irq(TXDONE_QUEUE);
}
ports_open++;
napi_schedule(&port->napi);
return 0;
}
static int eth_close(struct net_device *dev)
{
struct port *port = netdev_priv(dev);
struct msg msg;
int buffs = RX_DESCS;
int i;
ports_open--;
qmgr_disable_irq(port->plat->rxq);
napi_disable(&port->napi);
netif_stop_queue(dev);
while (queue_get_desc(RXFREE_QUEUE(port->id), port, 0) >= 0)
buffs--;
memset(&msg, 0, sizeof(msg));
msg.cmd = NPE_SETLOOPBACK_MODE;
msg.eth_id = port->id;
msg.byte3 = 1;
if (npe_send_recv_message(port->npe, &msg, "ETH_ENABLE_LOOPBACK"))
printk(KERN_CRIT "%s: unable to enable loopback\n", dev->name);
i = 0;
do {
while (queue_get_desc(port->plat->rxq, port, 0) >= 0)
buffs--;
if (!buffs)
break;
if (qmgr_stat_empty(TX_QUEUE(port->id))) {
struct desc *desc;
u32 phys;
int n = queue_get_desc(port->plat->txreadyq, port, 1);
BUG_ON(n < 0);
desc = tx_desc_ptr(port, n);
phys = tx_desc_phys(port, n);
desc->buf_len = desc->pkt_len = 1;
wmb();
queue_put_desc(TX_QUEUE(port->id), phys, desc);
}
udelay(1);
} while (++i < MAX_CLOSE_WAIT);
if (buffs)
printk(KERN_CRIT "%s: unable to drain RX queue, %i buffer(s)"
" left in NPE\n", dev->name, buffs);
#if DEBUG_CLOSE
if (!buffs)
printk(KERN_DEBUG "Draining RX queue took %i cycles\n", i);
#endif
buffs = TX_DESCS;
while (queue_get_desc(TX_QUEUE(port->id), port, 1) >= 0)
buffs--;
i = 0;
do {
while (queue_get_desc(port->plat->txreadyq, port, 1) >= 0)
buffs--;
if (!buffs)
break;
} while (++i < MAX_CLOSE_WAIT);
if (buffs)
printk(KERN_CRIT "%s: unable to drain TX queue, %i buffer(s) "
"left in NPE\n", dev->name, buffs);
#if DEBUG_CLOSE
if (!buffs)
printk(KERN_DEBUG "Draining TX queues took %i cycles\n", i);
#endif
msg.byte3 = 0;
if (npe_send_recv_message(port->npe, &msg, "ETH_DISABLE_LOOPBACK"))
printk(KERN_CRIT "%s: unable to disable loopback\n",
dev->name);
phy_stop(port->phydev);
if (!ports_open)
qmgr_disable_irq(TXDONE_QUEUE);
destroy_queues(port);
release_queues(port);
return 0;
}
static int __devinit eth_init_one(struct platform_device *pdev)
{
struct port *port;
struct net_device *dev;
struct eth_plat_info *plat = pdev->dev.platform_data;
u32 regs_phys;
char phy_id[MII_BUS_ID_SIZE + 3];
int err;
if (ptp_filter_init(ptp_filter, ARRAY_SIZE(ptp_filter))) {
pr_err("ixp4xx_eth: bad ptp filter\n");
return -EINVAL;
}
if (!(dev = alloc_etherdev(sizeof(struct port))))
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
port = netdev_priv(dev);
port->netdev = dev;
port->id = pdev->id;
switch (port->id) {
case IXP4XX_ETH_NPEA:
port->regs = (struct eth_regs __iomem *)IXP4XX_EthA_BASE_VIRT;
regs_phys = IXP4XX_EthA_BASE_PHYS;
break;
case IXP4XX_ETH_NPEB:
port->regs = (struct eth_regs __iomem *)IXP4XX_EthB_BASE_VIRT;
regs_phys = IXP4XX_EthB_BASE_PHYS;
break;
case IXP4XX_ETH_NPEC:
port->regs = (struct eth_regs __iomem *)IXP4XX_EthC_BASE_VIRT;
regs_phys = IXP4XX_EthC_BASE_PHYS;
break;
default:
err = -ENODEV;
goto err_free;
}
dev->netdev_ops = &ixp4xx_netdev_ops;
dev->ethtool_ops = &ixp4xx_ethtool_ops;
dev->tx_queue_len = 100;
netif_napi_add(dev, &port->napi, eth_poll, NAPI_WEIGHT);
if (!(port->npe = npe_request(NPE_ID(port->id)))) {
err = -EIO;
goto err_free;
}
port->mem_res = request_mem_region(regs_phys, REGS_SIZE, dev->name);
if (!port->mem_res) {
err = -EBUSY;
goto err_npe_rel;
}
port->plat = plat;
npe_port_tab[NPE_ID(port->id)] = port;
memcpy(dev->dev_addr, plat->hwaddr, ETH_ALEN);
platform_set_drvdata(pdev, dev);
__raw_writel(DEFAULT_CORE_CNTRL | CORE_RESET,
&port->regs->core_control);
udelay(50);
__raw_writel(DEFAULT_CORE_CNTRL, &port->regs->core_control);
udelay(50);
snprintf(phy_id, MII_BUS_ID_SIZE + 3, PHY_ID_FMT,
mdio_bus->id, plat->phy);
port->phydev = phy_connect(dev, phy_id, &ixp4xx_adjust_link, 0,
PHY_INTERFACE_MODE_MII);
if (IS_ERR(port->phydev)) {
err = PTR_ERR(port->phydev);
goto err_free_mem;
}
port->phydev->irq = PHY_POLL;
if ((err = register_netdev(dev)))
goto err_phy_dis;
printk(KERN_INFO "%s: MII PHY %i on %s\n", dev->name, plat->phy,
npe_name(port->npe));
return 0;
err_phy_dis:
phy_disconnect(port->phydev);
err_free_mem:
npe_port_tab[NPE_ID(port->id)] = NULL;
platform_set_drvdata(pdev, NULL);
release_resource(port->mem_res);
err_npe_rel:
npe_release(port->npe);
err_free:
free_netdev(dev);
return err;
}
static int __devexit eth_remove_one(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct port *port = netdev_priv(dev);
unregister_netdev(dev);
phy_disconnect(port->phydev);
npe_port_tab[NPE_ID(port->id)] = NULL;
platform_set_drvdata(pdev, NULL);
npe_release(port->npe);
release_resource(port->mem_res);
free_netdev(dev);
return 0;
}
static int __init eth_init_module(void)
{
int err;
if ((err = ixp4xx_mdio_register()))
return err;
return platform_driver_register(&ixp4xx_eth_driver);
}
static void __exit eth_cleanup_module(void)
{
platform_driver_unregister(&ixp4xx_eth_driver);
ixp4xx_mdio_remove();
}
