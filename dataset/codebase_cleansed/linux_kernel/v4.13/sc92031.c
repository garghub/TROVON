static inline void _sc92031_dummy_read(void __iomem *port_base)
{
ioread32(port_base + MAC0);
}
static u32 _sc92031_mii_wait(void __iomem *port_base)
{
u32 mii_status;
do {
udelay(10);
mii_status = ioread32(port_base + Miistatus);
} while (mii_status & Mii_StatusBusy);
return mii_status;
}
static u32 _sc92031_mii_cmd(void __iomem *port_base, u32 cmd0, u32 cmd1)
{
iowrite32(Mii_Divider, port_base + Miicmd0);
_sc92031_mii_wait(port_base);
iowrite32(cmd1, port_base + Miicmd1);
iowrite32(Mii_Divider | cmd0, port_base + Miicmd0);
return _sc92031_mii_wait(port_base);
}
static void _sc92031_mii_scan(void __iomem *port_base)
{
_sc92031_mii_cmd(port_base, Mii_SCAN, 0x1 << 6);
}
static u16 _sc92031_mii_read(void __iomem *port_base, unsigned reg)
{
return _sc92031_mii_cmd(port_base, Mii_READ, reg << 6) >> 13;
}
static void _sc92031_mii_write(void __iomem *port_base, unsigned reg, u16 val)
{
_sc92031_mii_cmd(port_base, Mii_WRITE, (reg << 6) | ((u32)val << 11));
}
static void sc92031_disable_interrupts(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
atomic_set(&priv->intr_mask, 0);
wmb();
iowrite32(0, port_base + IntrMask);
_sc92031_dummy_read(port_base);
mmiowb();
synchronize_irq(priv->pdev->irq);
tasklet_disable(&priv->tasklet);
}
static void sc92031_enable_interrupts(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
tasklet_enable(&priv->tasklet);
atomic_set(&priv->intr_mask, IntrBits);
wmb();
iowrite32(IntrBits, port_base + IntrMask);
mmiowb();
}
static void _sc92031_disable_tx_rx(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
priv->rx_config &= ~RxEnb;
priv->tx_config &= ~TxEnb;
iowrite32(priv->rx_config, port_base + RxConfig);
iowrite32(priv->tx_config, port_base + TxConfig);
}
static void _sc92031_enable_tx_rx(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
priv->rx_config |= RxEnb;
priv->tx_config |= TxEnb;
iowrite32(priv->rx_config, port_base + RxConfig);
iowrite32(priv->tx_config, port_base + TxConfig);
}
static void _sc92031_tx_clear(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
while (priv->tx_head - priv->tx_tail > 0) {
priv->tx_tail++;
dev->stats.tx_dropped++;
}
priv->tx_head = priv->tx_tail = 0;
}
static void _sc92031_set_mar(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 mar0 = 0, mar1 = 0;
if ((dev->flags & IFF_PROMISC) ||
netdev_mc_count(dev) > multicast_filter_limit ||
(dev->flags & IFF_ALLMULTI))
mar0 = mar1 = 0xffffffff;
else if (dev->flags & IFF_MULTICAST) {
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, dev) {
u32 crc;
unsigned bit = 0;
crc = ~ether_crc(ETH_ALEN, ha->addr);
crc >>= 24;
if (crc & 0x01) bit |= 0x02;
if (crc & 0x02) bit |= 0x01;
if (crc & 0x10) bit |= 0x20;
if (crc & 0x20) bit |= 0x10;
if (crc & 0x40) bit |= 0x08;
if (crc & 0x80) bit |= 0x04;
if (bit > 31)
mar0 |= 0x1 << (bit - 32);
else
mar1 |= 0x1 << bit;
}
}
iowrite32(mar0, port_base + MAR0);
iowrite32(mar1, port_base + MAR0 + 4);
}
static void _sc92031_set_rx_config(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
unsigned int old_mc_flags;
u32 rx_config_bits = 0;
old_mc_flags = priv->mc_flags;
if (dev->flags & IFF_PROMISC)
rx_config_bits |= RxSmall | RxHuge | RxErr | RxBroadcast
| RxMulticast | RxAllphys;
if (dev->flags & (IFF_ALLMULTI | IFF_MULTICAST))
rx_config_bits |= RxMulticast;
if (dev->flags & IFF_BROADCAST)
rx_config_bits |= RxBroadcast;
priv->rx_config &= ~(RxSmall | RxHuge | RxErr | RxBroadcast
| RxMulticast | RxAllphys);
priv->rx_config |= rx_config_bits;
priv->mc_flags = dev->flags & (IFF_PROMISC | IFF_ALLMULTI
| IFF_MULTICAST | IFF_BROADCAST);
if (netif_carrier_ok(dev) && priv->mc_flags != old_mc_flags)
iowrite32(priv->rx_config, port_base + RxConfig);
}
static bool _sc92031_check_media(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u16 bmsr;
bmsr = _sc92031_mii_read(port_base, MII_BMSR);
rmb();
if (bmsr & BMSR_LSTATUS) {
bool speed_100, duplex_full;
u32 flow_ctrl_config = 0;
u16 output_status = _sc92031_mii_read(port_base,
MII_OutputStatus);
_sc92031_mii_scan(port_base);
speed_100 = output_status & 0x2;
duplex_full = output_status & 0x4;
priv->rx_config = (0x40 << LowThresholdShift) | (0x1c0 << HighThresholdShift);
priv->tx_config = 0x48800000;
if (!speed_100)
priv->tx_config |= 0x80000;
_sc92031_set_rx_config(dev);
if (duplex_full) {
priv->rx_config |= RxFullDx;
priv->tx_config |= TxFullDx;
flow_ctrl_config = FlowCtrlFullDX | FlowCtrlEnb;
} else {
priv->rx_config &= ~RxFullDx;
priv->tx_config &= ~TxFullDx;
}
_sc92031_set_mar(dev);
_sc92031_set_rx_config(dev);
_sc92031_enable_tx_rx(dev);
iowrite32(flow_ctrl_config, port_base + FlowCtrlConfig);
netif_carrier_on(dev);
if (printk_ratelimit())
printk(KERN_INFO "%s: link up, %sMbps, %s-duplex\n",
dev->name,
speed_100 ? "100" : "10",
duplex_full ? "full" : "half");
return true;
} else {
_sc92031_mii_scan(port_base);
netif_carrier_off(dev);
_sc92031_disable_tx_rx(dev);
if (printk_ratelimit())
printk(KERN_INFO "%s: link down\n", dev->name);
return false;
}
}
static void _sc92031_phy_reset(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 phy_ctrl;
phy_ctrl = ioread32(port_base + PhyCtrl);
phy_ctrl &= ~(PhyCtrlDux | PhyCtrlSpd100 | PhyCtrlSpd10);
phy_ctrl |= PhyCtrlAne | PhyCtrlReset;
switch (media) {
default:
case AUTOSELECT:
phy_ctrl |= PhyCtrlDux | PhyCtrlSpd100 | PhyCtrlSpd10;
break;
case M10_HALF:
phy_ctrl |= PhyCtrlSpd10;
break;
case M10_FULL:
phy_ctrl |= PhyCtrlDux | PhyCtrlSpd10;
break;
case M100_HALF:
phy_ctrl |= PhyCtrlSpd100;
break;
case M100_FULL:
phy_ctrl |= PhyCtrlDux | PhyCtrlSpd100;
break;
}
iowrite32(phy_ctrl, port_base + PhyCtrl);
mdelay(10);
phy_ctrl &= ~PhyCtrlReset;
iowrite32(phy_ctrl, port_base + PhyCtrl);
mdelay(1);
_sc92031_mii_write(port_base, MII_JAB,
PHY_16_JAB_ENB | PHY_16_PORT_ENB);
_sc92031_mii_scan(port_base);
netif_carrier_off(dev);
netif_stop_queue(dev);
}
static void _sc92031_reset(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
iowrite32(0, port_base + PMConfig);
iowrite32(Cfg0_Reset, port_base + Config0);
mdelay(200);
iowrite32(0, port_base + Config0);
mdelay(10);
iowrite32(0, port_base + IntrMask);
iowrite32(0, port_base + MAR0);
iowrite32(0, port_base + MAR0 + 4);
iowrite32(priv->rx_ring_dma_addr, port_base + RxbufAddr);
priv->rx_ring_tail = priv->rx_ring_dma_addr;
_sc92031_tx_clear(dev);
priv->intr_status = 0;
atomic_set(&priv->intr_mask, 0);
priv->rx_config = 0;
priv->tx_config = 0;
priv->mc_flags = 0;
iowrite32(Cfg1_Rcv64K, port_base + Config1);
_sc92031_phy_reset(dev);
_sc92031_check_media(dev);
priv->rx_value = 0;
iowrite32(priv->pm_config, port_base + PMConfig);
ioread32(port_base + IntrStatus);
}
static void _sc92031_tx_tasklet(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
unsigned old_tx_tail;
unsigned entry;
u32 tx_status;
old_tx_tail = priv->tx_tail;
while (priv->tx_head - priv->tx_tail > 0) {
entry = priv->tx_tail % NUM_TX_DESC;
tx_status = ioread32(port_base + TxStatus0 + entry * 4);
if (!(tx_status & (TxStatOK | TxUnderrun | TxAborted)))
break;
priv->tx_tail++;
if (tx_status & TxStatOK) {
dev->stats.tx_bytes += tx_status & 0x1fff;
dev->stats.tx_packets++;
dev->stats.collisions += (tx_status >> 22) & 0xf;
}
if (tx_status & (TxOutOfWindow | TxAborted)) {
dev->stats.tx_errors++;
if (tx_status & TxAborted)
dev->stats.tx_aborted_errors++;
if (tx_status & TxCarrierLost)
dev->stats.tx_carrier_errors++;
if (tx_status & TxOutOfWindow)
dev->stats.tx_window_errors++;
}
if (tx_status & TxUnderrun)
dev->stats.tx_fifo_errors++;
}
if (priv->tx_tail != old_tx_tail)
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
}
static void _sc92031_rx_tasklet_error(struct net_device *dev,
u32 rx_status, unsigned rx_size)
{
if(rx_size > (MAX_ETH_FRAME_SIZE + 4) || rx_size < 16) {
dev->stats.rx_errors++;
dev->stats.rx_length_errors++;
}
if (!(rx_status & RxStatesOK)) {
dev->stats.rx_errors++;
if (rx_status & (RxHugeFrame | RxSmallFrame))
dev->stats.rx_length_errors++;
if (rx_status & RxBadAlign)
dev->stats.rx_frame_errors++;
if (!(rx_status & RxCRCOK))
dev->stats.rx_crc_errors++;
} else {
struct sc92031_priv *priv = netdev_priv(dev);
priv->rx_loss++;
}
}
static void _sc92031_rx_tasklet(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
dma_addr_t rx_ring_head;
unsigned rx_len;
unsigned rx_ring_offset;
void *rx_ring = priv->rx_ring;
rx_ring_head = ioread32(port_base + RxBufWPtr);
rmb();
rx_ring_head &= (dma_addr_t)(RX_BUF_LEN - 1);
rx_ring_head |= priv->rx_ring_dma_addr & ~(dma_addr_t)(RX_BUF_LEN - 1);
if (rx_ring_head < priv->rx_ring_dma_addr)
rx_ring_head += RX_BUF_LEN;
if (rx_ring_head >= priv->rx_ring_tail)
rx_len = rx_ring_head - priv->rx_ring_tail;
else
rx_len = RX_BUF_LEN - (priv->rx_ring_tail - rx_ring_head);
if (!rx_len)
return;
if (unlikely(rx_len > RX_BUF_LEN)) {
if (printk_ratelimit())
printk(KERN_ERR "%s: rx packets length > rx buffer\n",
dev->name);
return;
}
rx_ring_offset = (priv->rx_ring_tail - priv->rx_ring_dma_addr) % RX_BUF_LEN;
while (rx_len) {
u32 rx_status;
unsigned rx_size, rx_size_align, pkt_size;
struct sk_buff *skb;
rx_status = le32_to_cpup((__le32 *)(rx_ring + rx_ring_offset));
rmb();
rx_size = rx_status >> 20;
rx_size_align = (rx_size + 3) & ~3;
pkt_size = rx_size - 4;
rx_ring_offset = (rx_ring_offset + 4) % RX_BUF_LEN;
if (unlikely(rx_status == 0 ||
rx_size > (MAX_ETH_FRAME_SIZE + 4) ||
rx_size < 16 ||
!(rx_status & RxStatesOK))) {
_sc92031_rx_tasklet_error(dev, rx_status, rx_size);
break;
}
if (unlikely(rx_size_align + 4 > rx_len)) {
if (printk_ratelimit())
printk(KERN_ERR "%s: rx_len is too small\n", dev->name);
break;
}
rx_len -= rx_size_align + 4;
skb = netdev_alloc_skb_ip_align(dev, pkt_size);
if (unlikely(!skb)) {
if (printk_ratelimit())
printk(KERN_ERR "%s: Couldn't allocate a skb_buff for a packet of size %u\n",
dev->name, pkt_size);
goto next;
}
if ((rx_ring_offset + pkt_size) > RX_BUF_LEN) {
skb_put_data(skb, rx_ring + rx_ring_offset,
RX_BUF_LEN - rx_ring_offset);
skb_put_data(skb, rx_ring,
pkt_size - (RX_BUF_LEN - rx_ring_offset));
} else {
skb_put_data(skb, rx_ring + rx_ring_offset, pkt_size);
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_bytes += pkt_size;
dev->stats.rx_packets++;
if (rx_status & Rx_Multicast)
dev->stats.multicast++;
next:
rx_ring_offset = (rx_ring_offset + rx_size_align) % RX_BUF_LEN;
}
mb();
priv->rx_ring_tail = rx_ring_head;
iowrite32(priv->rx_ring_tail, port_base + RxBufRPtr);
}
static void _sc92031_link_tasklet(struct net_device *dev)
{
if (_sc92031_check_media(dev))
netif_wake_queue(dev);
else {
netif_stop_queue(dev);
dev->stats.tx_carrier_errors++;
}
}
static void sc92031_tasklet(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 intr_status, intr_mask;
intr_status = priv->intr_status;
spin_lock(&priv->lock);
if (unlikely(!netif_running(dev)))
goto out;
if (intr_status & TxOK)
_sc92031_tx_tasklet(dev);
if (intr_status & RxOK)
_sc92031_rx_tasklet(dev);
if (intr_status & RxOverflow)
dev->stats.rx_errors++;
if (intr_status & TimeOut) {
dev->stats.rx_errors++;
dev->stats.rx_length_errors++;
}
if (intr_status & (LinkFail | LinkOK))
_sc92031_link_tasklet(dev);
out:
intr_mask = atomic_read(&priv->intr_mask);
rmb();
iowrite32(intr_mask, port_base + IntrMask);
mmiowb();
spin_unlock(&priv->lock);
}
static irqreturn_t sc92031_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 intr_status, intr_mask;
iowrite32(0, port_base + IntrMask);
_sc92031_dummy_read(port_base);
intr_status = ioread32(port_base + IntrStatus);
if (unlikely(intr_status == 0xffffffff))
return IRQ_NONE;
intr_status &= IntrBits;
if (!intr_status)
goto out_none;
priv->intr_status = intr_status;
tasklet_schedule(&priv->tasklet);
return IRQ_HANDLED;
out_none:
intr_mask = atomic_read(&priv->intr_mask);
rmb();
iowrite32(intr_mask, port_base + IntrMask);
mmiowb();
return IRQ_NONE;
}
static struct net_device_stats *sc92031_get_stats(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
if (netif_running(dev)) {
int temp;
spin_lock_bh(&priv->lock);
temp = (ioread32(port_base + RxStatus0) >> 16) & 0xffff;
if (temp == 0xffff) {
priv->rx_value += temp;
dev->stats.rx_fifo_errors = priv->rx_value;
} else
dev->stats.rx_fifo_errors = temp + priv->rx_value;
spin_unlock_bh(&priv->lock);
}
return &dev->stats;
}
static netdev_tx_t sc92031_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
unsigned len;
unsigned entry;
u32 tx_status;
if (unlikely(skb->len > TX_BUF_SIZE)) {
dev->stats.tx_dropped++;
goto out;
}
spin_lock(&priv->lock);
if (unlikely(!netif_carrier_ok(dev))) {
dev->stats.tx_dropped++;
goto out_unlock;
}
BUG_ON(priv->tx_head - priv->tx_tail >= NUM_TX_DESC);
entry = priv->tx_head++ % NUM_TX_DESC;
skb_copy_and_csum_dev(skb, priv->tx_bufs + entry * TX_BUF_SIZE);
len = skb->len;
if (len < ETH_ZLEN) {
memset(priv->tx_bufs + entry * TX_BUF_SIZE + len,
0, ETH_ZLEN - len);
len = ETH_ZLEN;
}
wmb();
if (len < 100)
tx_status = len;
else if (len < 300)
tx_status = 0x30000 | len;
else
tx_status = 0x50000 | len;
iowrite32(priv->tx_bufs_dma_addr + entry * TX_BUF_SIZE,
port_base + TxAddr0 + entry * 4);
iowrite32(tx_status, port_base + TxStatus0 + entry * 4);
mmiowb();
if (priv->tx_head - priv->tx_tail >= NUM_TX_DESC)
netif_stop_queue(dev);
out_unlock:
spin_unlock(&priv->lock);
out:
dev_consume_skb_any(skb);
return NETDEV_TX_OK;
}
static int sc92031_open(struct net_device *dev)
{
int err;
struct sc92031_priv *priv = netdev_priv(dev);
struct pci_dev *pdev = priv->pdev;
priv->rx_ring = pci_alloc_consistent(pdev, RX_BUF_LEN,
&priv->rx_ring_dma_addr);
if (unlikely(!priv->rx_ring)) {
err = -ENOMEM;
goto out_alloc_rx_ring;
}
priv->tx_bufs = pci_alloc_consistent(pdev, TX_BUF_TOT_LEN,
&priv->tx_bufs_dma_addr);
if (unlikely(!priv->tx_bufs)) {
err = -ENOMEM;
goto out_alloc_tx_bufs;
}
priv->tx_head = priv->tx_tail = 0;
err = request_irq(pdev->irq, sc92031_interrupt,
IRQF_SHARED, dev->name, dev);
if (unlikely(err < 0))
goto out_request_irq;
priv->pm_config = 0;
spin_lock_bh(&priv->lock);
_sc92031_reset(dev);
mmiowb();
spin_unlock_bh(&priv->lock);
sc92031_enable_interrupts(dev);
if (netif_carrier_ok(dev))
netif_start_queue(dev);
else
netif_tx_disable(dev);
return 0;
out_request_irq:
pci_free_consistent(pdev, TX_BUF_TOT_LEN, priv->tx_bufs,
priv->tx_bufs_dma_addr);
out_alloc_tx_bufs:
pci_free_consistent(pdev, RX_BUF_LEN, priv->rx_ring,
priv->rx_ring_dma_addr);
out_alloc_rx_ring:
return err;
}
static int sc92031_stop(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
struct pci_dev *pdev = priv->pdev;
netif_tx_disable(dev);
sc92031_disable_interrupts(dev);
spin_lock_bh(&priv->lock);
_sc92031_disable_tx_rx(dev);
_sc92031_tx_clear(dev);
mmiowb();
spin_unlock_bh(&priv->lock);
free_irq(pdev->irq, dev);
pci_free_consistent(pdev, TX_BUF_TOT_LEN, priv->tx_bufs,
priv->tx_bufs_dma_addr);
pci_free_consistent(pdev, RX_BUF_LEN, priv->rx_ring,
priv->rx_ring_dma_addr);
return 0;
}
static void sc92031_set_multicast_list(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
spin_lock_bh(&priv->lock);
_sc92031_set_mar(dev);
_sc92031_set_rx_config(dev);
mmiowb();
spin_unlock_bh(&priv->lock);
}
static void sc92031_tx_timeout(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
sc92031_disable_interrupts(dev);
spin_lock(&priv->lock);
priv->tx_timeouts++;
_sc92031_reset(dev);
mmiowb();
spin_unlock(&priv->lock);
sc92031_enable_interrupts(dev);
if (netif_carrier_ok(dev))
netif_wake_queue(dev);
}
static void sc92031_poll_controller(struct net_device *dev)
{
struct sc92031_priv *priv = netdev_priv(dev);
const int irq = priv->pdev->irq;
disable_irq(irq);
if (sc92031_interrupt(irq, dev) != IRQ_NONE)
sc92031_tasklet((unsigned long)dev);
enable_irq(irq);
}
static int
sc92031_ethtool_get_link_ksettings(struct net_device *dev,
struct ethtool_link_ksettings *cmd)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u8 phy_address;
u32 phy_ctrl;
u16 output_status;
u32 supported, advertising;
spin_lock_bh(&priv->lock);
phy_address = ioread32(port_base + Miicmd1) >> 27;
phy_ctrl = ioread32(port_base + PhyCtrl);
output_status = _sc92031_mii_read(port_base, MII_OutputStatus);
_sc92031_mii_scan(port_base);
mmiowb();
spin_unlock_bh(&priv->lock);
supported = SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full
| SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full
| SUPPORTED_Autoneg | SUPPORTED_TP | SUPPORTED_MII;
advertising = ADVERTISED_TP | ADVERTISED_MII;
if ((phy_ctrl & (PhyCtrlDux | PhyCtrlSpd100 | PhyCtrlSpd10))
== (PhyCtrlDux | PhyCtrlSpd100 | PhyCtrlSpd10))
advertising |= ADVERTISED_Autoneg;
if ((phy_ctrl & PhyCtrlSpd10) == PhyCtrlSpd10)
advertising |= ADVERTISED_10baseT_Half;
if ((phy_ctrl & (PhyCtrlSpd10 | PhyCtrlDux))
== (PhyCtrlSpd10 | PhyCtrlDux))
advertising |= ADVERTISED_10baseT_Full;
if ((phy_ctrl & PhyCtrlSpd100) == PhyCtrlSpd100)
advertising |= ADVERTISED_100baseT_Half;
if ((phy_ctrl & (PhyCtrlSpd100 | PhyCtrlDux))
== (PhyCtrlSpd100 | PhyCtrlDux))
advertising |= ADVERTISED_100baseT_Full;
if (phy_ctrl & PhyCtrlAne)
advertising |= ADVERTISED_Autoneg;
cmd->base.speed = (output_status & 0x2) ? SPEED_100 : SPEED_10;
cmd->base.duplex = (output_status & 0x4) ? DUPLEX_FULL : DUPLEX_HALF;
cmd->base.port = PORT_MII;
cmd->base.phy_address = phy_address;
cmd->base.autoneg = (phy_ctrl & PhyCtrlAne) ?
AUTONEG_ENABLE : AUTONEG_DISABLE;
ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.supported,
supported);
ethtool_convert_legacy_u32_to_link_mode(cmd->link_modes.advertising,
advertising);
return 0;
}
static int
sc92031_ethtool_set_link_ksettings(struct net_device *dev,
const struct ethtool_link_ksettings *cmd)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 speed = cmd->base.speed;
u32 phy_ctrl;
u32 old_phy_ctrl;
u32 advertising;
ethtool_convert_link_mode_to_legacy_u32(&advertising,
cmd->link_modes.advertising);
if (!(speed == SPEED_10 || speed == SPEED_100))
return -EINVAL;
if (!(cmd->base.duplex == DUPLEX_HALF ||
cmd->base.duplex == DUPLEX_FULL))
return -EINVAL;
if (!(cmd->base.port == PORT_MII))
return -EINVAL;
if (!(cmd->base.phy_address == 0x1f))
return -EINVAL;
if (!(cmd->base.autoneg == AUTONEG_DISABLE ||
cmd->base.autoneg == AUTONEG_ENABLE))
return -EINVAL;
if (cmd->base.autoneg == AUTONEG_ENABLE) {
if (!(advertising & (ADVERTISED_Autoneg
| ADVERTISED_100baseT_Full
| ADVERTISED_100baseT_Half
| ADVERTISED_10baseT_Full
| ADVERTISED_10baseT_Half)))
return -EINVAL;
phy_ctrl = PhyCtrlAne;
if (advertising & ADVERTISED_Autoneg)
phy_ctrl |= PhyCtrlDux | PhyCtrlSpd100 | PhyCtrlSpd10;
if (advertising & ADVERTISED_100baseT_Full)
phy_ctrl |= PhyCtrlDux | PhyCtrlSpd100;
if (advertising & ADVERTISED_100baseT_Half)
phy_ctrl |= PhyCtrlSpd100;
if (advertising & ADVERTISED_10baseT_Full)
phy_ctrl |= PhyCtrlSpd10 | PhyCtrlDux;
if (advertising & ADVERTISED_10baseT_Half)
phy_ctrl |= PhyCtrlSpd10;
} else {
phy_ctrl = 0;
if (speed == SPEED_10)
phy_ctrl |= PhyCtrlSpd10;
else
phy_ctrl |= PhyCtrlSpd100;
if (cmd->base.duplex == DUPLEX_FULL)
phy_ctrl |= PhyCtrlDux;
}
spin_lock_bh(&priv->lock);
old_phy_ctrl = ioread32(port_base + PhyCtrl);
phy_ctrl |= old_phy_ctrl & ~(PhyCtrlAne | PhyCtrlDux
| PhyCtrlSpd100 | PhyCtrlSpd10);
if (phy_ctrl != old_phy_ctrl)
iowrite32(phy_ctrl, port_base + PhyCtrl);
spin_unlock_bh(&priv->lock);
return 0;
}
static void sc92031_ethtool_get_wol(struct net_device *dev,
struct ethtool_wolinfo *wolinfo)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 pm_config;
spin_lock_bh(&priv->lock);
pm_config = ioread32(port_base + PMConfig);
spin_unlock_bh(&priv->lock);
wolinfo->supported = WAKE_PHY | WAKE_MAGIC
| WAKE_UCAST | WAKE_MCAST | WAKE_BCAST;
wolinfo->wolopts = 0;
if (pm_config & PM_LinkUp)
wolinfo->wolopts |= WAKE_PHY;
if (pm_config & PM_Magic)
wolinfo->wolopts |= WAKE_MAGIC;
if (pm_config & PM_WakeUp)
wolinfo->wolopts |= WAKE_UCAST | WAKE_MCAST | WAKE_BCAST;
}
static int sc92031_ethtool_set_wol(struct net_device *dev,
struct ethtool_wolinfo *wolinfo)
{
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u32 pm_config;
spin_lock_bh(&priv->lock);
pm_config = ioread32(port_base + PMConfig)
& ~(PM_LinkUp | PM_Magic | PM_WakeUp);
if (wolinfo->wolopts & WAKE_PHY)
pm_config |= PM_LinkUp;
if (wolinfo->wolopts & WAKE_MAGIC)
pm_config |= PM_Magic;
if (wolinfo->wolopts & (WAKE_UCAST | WAKE_MCAST | WAKE_BCAST))
pm_config |= PM_WakeUp;
priv->pm_config = pm_config;
iowrite32(pm_config, port_base + PMConfig);
mmiowb();
spin_unlock_bh(&priv->lock);
return 0;
}
static int sc92031_ethtool_nway_reset(struct net_device *dev)
{
int err = 0;
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem *port_base = priv->port_base;
u16 bmcr;
spin_lock_bh(&priv->lock);
bmcr = _sc92031_mii_read(port_base, MII_BMCR);
if (!(bmcr & BMCR_ANENABLE)) {
err = -EINVAL;
goto out;
}
_sc92031_mii_write(port_base, MII_BMCR, bmcr | BMCR_ANRESTART);
out:
_sc92031_mii_scan(port_base);
mmiowb();
spin_unlock_bh(&priv->lock);
return err;
}
static void sc92031_ethtool_get_strings(struct net_device *dev,
u32 stringset, u8 *data)
{
if (stringset == ETH_SS_STATS)
memcpy(data, sc92031_ethtool_stats_strings,
SILAN_STATS_NUM * ETH_GSTRING_LEN);
}
static int sc92031_ethtool_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return SILAN_STATS_NUM;
default:
return -EOPNOTSUPP;
}
}
static void sc92031_ethtool_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *stats, u64 *data)
{
struct sc92031_priv *priv = netdev_priv(dev);
spin_lock_bh(&priv->lock);
data[0] = priv->tx_timeouts;
data[1] = priv->rx_loss;
spin_unlock_bh(&priv->lock);
}
static int sc92031_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
int err;
void __iomem* port_base;
struct net_device *dev;
struct sc92031_priv *priv;
u32 mac0, mac1;
err = pci_enable_device(pdev);
if (unlikely(err < 0))
goto out_enable_device;
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (unlikely(err < 0))
goto out_set_dma_mask;
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (unlikely(err < 0))
goto out_set_dma_mask;
err = pci_request_regions(pdev, SC92031_NAME);
if (unlikely(err < 0))
goto out_request_regions;
port_base = pci_iomap(pdev, SC92031_USE_PIO, 0);
if (unlikely(!port_base)) {
err = -EIO;
goto out_iomap;
}
dev = alloc_etherdev(sizeof(struct sc92031_priv));
if (unlikely(!dev)) {
err = -ENOMEM;
goto out_alloc_etherdev;
}
pci_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
dev->features = NETIF_F_SG | NETIF_F_HIGHDMA |
NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
dev->netdev_ops = &sc92031_netdev_ops;
dev->watchdog_timeo = TX_TIMEOUT;
dev->ethtool_ops = &sc92031_ethtool_ops;
priv = netdev_priv(dev);
spin_lock_init(&priv->lock);
priv->port_base = port_base;
priv->pdev = pdev;
tasklet_init(&priv->tasklet, sc92031_tasklet, (unsigned long)dev);
tasklet_disable_nosync(&priv->tasklet);
iowrite32((~PM_LongWF & ~PM_LWPTN) | PM_Enable, port_base + PMConfig);
mac0 = ioread32(port_base + MAC0);
mac1 = ioread32(port_base + MAC0 + 4);
dev->dev_addr[0] = mac0 >> 24;
dev->dev_addr[1] = mac0 >> 16;
dev->dev_addr[2] = mac0 >> 8;
dev->dev_addr[3] = mac0;
dev->dev_addr[4] = mac1 >> 8;
dev->dev_addr[5] = mac1;
err = register_netdev(dev);
if (err < 0)
goto out_register_netdev;
printk(KERN_INFO "%s: SC92031 at 0x%lx, %pM, IRQ %d\n", dev->name,
(long)pci_resource_start(pdev, SC92031_USE_PIO), dev->dev_addr,
pdev->irq);
return 0;
out_register_netdev:
free_netdev(dev);
out_alloc_etherdev:
pci_iounmap(pdev, port_base);
out_iomap:
pci_release_regions(pdev);
out_request_regions:
out_set_dma_mask:
pci_disable_device(pdev);
out_enable_device:
return err;
}
static void sc92031_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct sc92031_priv *priv = netdev_priv(dev);
void __iomem* port_base = priv->port_base;
unregister_netdev(dev);
free_netdev(dev);
pci_iounmap(pdev, port_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int sc92031_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct sc92031_priv *priv = netdev_priv(dev);
pci_save_state(pdev);
if (!netif_running(dev))
goto out;
netif_device_detach(dev);
sc92031_disable_interrupts(dev);
spin_lock_bh(&priv->lock);
_sc92031_disable_tx_rx(dev);
_sc92031_tx_clear(dev);
mmiowb();
spin_unlock_bh(&priv->lock);
out:
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int sc92031_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct sc92031_priv *priv = netdev_priv(dev);
pci_restore_state(pdev);
pci_set_power_state(pdev, PCI_D0);
if (!netif_running(dev))
goto out;
spin_lock_bh(&priv->lock);
_sc92031_reset(dev);
mmiowb();
spin_unlock_bh(&priv->lock);
sc92031_enable_interrupts(dev);
netif_device_attach(dev);
if (netif_carrier_ok(dev))
netif_wake_queue(dev);
else
netif_tx_disable(dev);
out:
return 0;
}
