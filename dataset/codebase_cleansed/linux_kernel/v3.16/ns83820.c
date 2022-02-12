static inline struct ns83820 *PRIV(struct net_device *dev)
{
return netdev_priv(dev);
}
static inline void kick_rx(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
dprintk("kick_rx: maybe kicking\n");
if (test_and_clear_bit(0, &dev->rx_info.idle)) {
dprintk("actually kicking\n");
writel(dev->rx_info.phy_descs +
(4 * DESC_SIZE * dev->rx_info.next_rx),
dev->base + RXDP);
if (dev->rx_info.next_rx == dev->rx_info.next_empty)
printk(KERN_DEBUG "%s: uh-oh: next_rx == next_empty???\n",
ndev->name);
__kick_rx(dev);
}
}
static inline void build_rx_desc(struct ns83820 *dev, __le32 *desc, dma_addr_t link, dma_addr_t buf, u32 cmdsts, u32 extsts)
{
desc_addr_set(desc + DESC_LINK, link);
desc_addr_set(desc + DESC_BUFPTR, buf);
desc[DESC_EXTSTS] = cpu_to_le32(extsts);
mb();
desc[DESC_CMDSTS] = cpu_to_le32(cmdsts);
}
static inline int ns83820_add_rx_skb(struct ns83820 *dev, struct sk_buff *skb)
{
unsigned next_empty;
u32 cmdsts;
__le32 *sg;
dma_addr_t buf;
next_empty = dev->rx_info.next_empty;
if (unlikely(nr_rx_empty(dev) <= 2)) {
kfree_skb(skb);
return 1;
}
#if 0
dprintk("next_empty[%d] nr_used[%d] next_rx[%d]\n",
dev->rx_info.next_empty,
dev->rx_info.nr_used,
dev->rx_info.next_rx
);
#endif
sg = dev->rx_info.descs + (next_empty * DESC_SIZE);
BUG_ON(NULL != dev->rx_info.skbs[next_empty]);
dev->rx_info.skbs[next_empty] = skb;
dev->rx_info.next_empty = (next_empty + 1) % NR_RX_DESC;
cmdsts = REAL_RX_BUF_SIZE | CMDSTS_INTR;
buf = pci_map_single(dev->pci_dev, skb->data,
REAL_RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
build_rx_desc(dev, sg, 0, buf, cmdsts, 0);
if (likely(next_empty != dev->rx_info.next_rx))
dev->rx_info.descs[((NR_RX_DESC + next_empty - 1) % NR_RX_DESC) * DESC_SIZE] = cpu_to_le32(dev->rx_info.phy_descs + (next_empty * DESC_SIZE * 4));
return 0;
}
static inline int rx_refill(struct net_device *ndev, gfp_t gfp)
{
struct ns83820 *dev = PRIV(ndev);
unsigned i;
unsigned long flags = 0;
if (unlikely(nr_rx_empty(dev) <= 2))
return 0;
dprintk("rx_refill(%p)\n", ndev);
if (gfp == GFP_ATOMIC)
spin_lock_irqsave(&dev->rx_info.lock, flags);
for (i=0; i<NR_RX_DESC; i++) {
struct sk_buff *skb;
long res;
skb = __netdev_alloc_skb(ndev, REAL_RX_BUF_SIZE+16, gfp);
if (unlikely(!skb))
break;
skb_reserve(skb, skb->data - PTR_ALIGN(skb->data, 16));
if (gfp != GFP_ATOMIC)
spin_lock_irqsave(&dev->rx_info.lock, flags);
res = ns83820_add_rx_skb(dev, skb);
if (gfp != GFP_ATOMIC)
spin_unlock_irqrestore(&dev->rx_info.lock, flags);
if (res) {
i = 1;
break;
}
}
if (gfp == GFP_ATOMIC)
spin_unlock_irqrestore(&dev->rx_info.lock, flags);
return i ? 0 : -ENOMEM;
}
static void rx_refill_atomic(struct net_device *ndev)
{
rx_refill(ndev, GFP_ATOMIC);
}
static inline void queue_refill(struct work_struct *work)
{
struct ns83820 *dev = container_of(work, struct ns83820, tq_refill);
struct net_device *ndev = dev->ndev;
rx_refill(ndev, GFP_KERNEL);
if (dev->rx_info.up)
kick_rx(ndev);
}
static inline void clear_rx_desc(struct ns83820 *dev, unsigned i)
{
build_rx_desc(dev, dev->rx_info.descs + (DESC_SIZE * i), 0, 0, CMDSTS_OWN, 0);
}
static void phy_intr(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
static const char *speeds[] = { "10", "100", "1000", "1000(?)", "1000F" };
u32 cfg, new_cfg;
u32 tbisr, tanar, tanlpar;
int speed, fullduplex, newlinkstate;
cfg = readl(dev->base + CFG) ^ SPDSTS_POLARITY;
if (dev->CFG_cache & CFG_TBI_EN) {
tbisr = readl(dev->base + TBISR);
tanar = readl(dev->base + TANAR);
tanlpar = readl(dev->base + TANLPAR);
dprintk("phy_intr: tbisr=%08x, tanar=%08x, tanlpar=%08x\n",
tbisr, tanar, tanlpar);
if ( (fullduplex = (tanlpar & TANAR_FULL_DUP) &&
(tanar & TANAR_FULL_DUP)) ) {
writel(readl(dev->base + TXCFG)
| TXCFG_CSI | TXCFG_HBI | TXCFG_ATP,
dev->base + TXCFG);
writel(readl(dev->base + RXCFG) | RXCFG_RX_FD,
dev->base + RXCFG);
writel(readl(dev->base + GPIOR) | GPIOR_GP1_OUT,
dev->base + GPIOR);
} else if (((tanlpar & TANAR_HALF_DUP) &&
(tanar & TANAR_HALF_DUP)) ||
((tanlpar & TANAR_FULL_DUP) &&
(tanar & TANAR_HALF_DUP)) ||
((tanlpar & TANAR_HALF_DUP) &&
(tanar & TANAR_FULL_DUP))) {
writel((readl(dev->base + TXCFG)
& ~(TXCFG_CSI | TXCFG_HBI)) | TXCFG_ATP,
dev->base + TXCFG);
writel(readl(dev->base + RXCFG) & ~RXCFG_RX_FD,
dev->base + RXCFG);
writel(readl(dev->base + GPIOR) & ~GPIOR_GP1_OUT,
dev->base + GPIOR);
}
speed = 4;
} else {
new_cfg = dev->CFG_cache & ~(CFG_SB | CFG_MODE_1000 | CFG_SPDSTS);
if (cfg & CFG_SPDSTS1)
new_cfg |= CFG_MODE_1000;
else
new_cfg &= ~CFG_MODE_1000;
speed = ((cfg / CFG_SPDSTS0) & 3);
fullduplex = (cfg & CFG_DUPSTS);
if (fullduplex) {
new_cfg |= CFG_SB;
writel(readl(dev->base + TXCFG)
| TXCFG_CSI | TXCFG_HBI,
dev->base + TXCFG);
writel(readl(dev->base + RXCFG) | RXCFG_RX_FD,
dev->base + RXCFG);
} else {
writel(readl(dev->base + TXCFG)
& ~(TXCFG_CSI | TXCFG_HBI),
dev->base + TXCFG);
writel(readl(dev->base + RXCFG) & ~(RXCFG_RX_FD),
dev->base + RXCFG);
}
if ((cfg & CFG_LNKSTS) &&
((new_cfg ^ dev->CFG_cache) != 0)) {
writel(new_cfg, dev->base + CFG);
dev->CFG_cache = new_cfg;
}
dev->CFG_cache &= ~CFG_SPDSTS;
dev->CFG_cache |= cfg & CFG_SPDSTS;
}
newlinkstate = (cfg & CFG_LNKSTS) ? LINK_UP : LINK_DOWN;
if (newlinkstate & LINK_UP &&
dev->linkstate != newlinkstate) {
netif_start_queue(ndev);
netif_wake_queue(ndev);
printk(KERN_INFO "%s: link now %s mbps, %s duplex and up.\n",
ndev->name,
speeds[speed],
fullduplex ? "full" : "half");
} else if (newlinkstate & LINK_DOWN &&
dev->linkstate != newlinkstate) {
netif_stop_queue(ndev);
printk(KERN_INFO "%s: link now down.\n", ndev->name);
}
dev->linkstate = newlinkstate;
}
static int ns83820_setup_rx(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
unsigned i;
int ret;
dprintk("ns83820_setup_rx(%p)\n", ndev);
dev->rx_info.idle = 1;
dev->rx_info.next_rx = 0;
dev->rx_info.next_rx_desc = dev->rx_info.descs;
dev->rx_info.next_empty = 0;
for (i=0; i<NR_RX_DESC; i++)
clear_rx_desc(dev, i);
writel(0, dev->base + RXDP_HI);
writel(dev->rx_info.phy_descs, dev->base + RXDP);
ret = rx_refill(ndev, GFP_KERNEL);
if (!ret) {
dprintk("starting receiver\n");
spin_lock_irq(&dev->rx_info.lock);
writel(0x0001, dev->base + CCSR);
writel(0, dev->base + RFCR);
writel(0x7fc00000, dev->base + RFCR);
writel(0xffc00000, dev->base + RFCR);
dev->rx_info.up = 1;
phy_intr(ndev);
spin_lock(&dev->misc_lock);
dev->IMR_cache |= ISR_PHY;
dev->IMR_cache |= ISR_RXRCMP;
dev->IMR_cache |= ISR_RXORN;
dev->IMR_cache |= ISR_RXSOVR;
dev->IMR_cache |= ISR_RXDESC;
dev->IMR_cache |= ISR_RXIDLE;
dev->IMR_cache |= ISR_TXDESC;
dev->IMR_cache |= ISR_TXIDLE;
writel(dev->IMR_cache, dev->base + IMR);
writel(1, dev->base + IER);
spin_unlock(&dev->misc_lock);
kick_rx(ndev);
spin_unlock_irq(&dev->rx_info.lock);
}
return ret;
}
static void ns83820_cleanup_rx(struct ns83820 *dev)
{
unsigned i;
unsigned long flags;
dprintk("ns83820_cleanup_rx(%p)\n", dev);
spin_lock_irqsave(&dev->misc_lock, flags);
dev->IMR_cache &= ~(ISR_RXOK | ISR_RXDESC | ISR_RXERR | ISR_RXEARLY | ISR_RXIDLE);
writel(dev->IMR_cache, dev->base + IMR);
spin_unlock_irqrestore(&dev->misc_lock, flags);
dev->rx_info.up = 0;
synchronize_irq(dev->pci_dev->irq);
readl(dev->base + IMR);
writel(0, dev->base + RXDP_HI);
writel(0, dev->base + RXDP);
for (i=0; i<NR_RX_DESC; i++) {
struct sk_buff *skb = dev->rx_info.skbs[i];
dev->rx_info.skbs[i] = NULL;
clear_rx_desc(dev, i);
kfree_skb(skb);
}
}
static void ns83820_rx_kick(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
{
if (dev->rx_info.up) {
rx_refill_atomic(ndev);
kick_rx(ndev);
}
}
if (dev->rx_info.up && nr_rx_empty(dev) > NR_RX_DESC*3/4)
schedule_work(&dev->tq_refill);
else
kick_rx(ndev);
if (dev->rx_info.idle)
printk(KERN_DEBUG "%s: BAD\n", ndev->name);
}
static void rx_action(unsigned long _dev)
{
struct net_device *ndev = (void *)_dev;
struct ns83820 *dev = PRIV(ndev);
rx_irq(ndev);
writel(ihr, dev->base + IHR);
spin_lock_irq(&dev->misc_lock);
dev->IMR_cache |= ISR_RXDESC;
writel(dev->IMR_cache, dev->base + IMR);
spin_unlock_irq(&dev->misc_lock);
rx_irq(ndev);
ns83820_rx_kick(ndev);
}
static inline void kick_tx(struct ns83820 *dev)
{
dprintk("kick_tx(%p): tx_idx=%d free_idx=%d\n",
dev, dev->tx_idx, dev->tx_free_idx);
writel(CR_TXE, dev->base + CR);
}
static void do_tx_done(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
u32 cmdsts, tx_done_idx;
__le32 *desc;
dprintk("do_tx_done(%p)\n", ndev);
tx_done_idx = dev->tx_done_idx;
desc = dev->tx_descs + (tx_done_idx * DESC_SIZE);
dprintk("tx_done_idx=%d free_idx=%d cmdsts=%08x\n",
tx_done_idx, dev->tx_free_idx, le32_to_cpu(desc[DESC_CMDSTS]));
while ((tx_done_idx != dev->tx_free_idx) &&
!(CMDSTS_OWN & (cmdsts = le32_to_cpu(desc[DESC_CMDSTS]))) ) {
struct sk_buff *skb;
unsigned len;
dma_addr_t addr;
if (cmdsts & CMDSTS_ERR)
ndev->stats.tx_errors++;
if (cmdsts & CMDSTS_OK)
ndev->stats.tx_packets++;
if (cmdsts & CMDSTS_OK)
ndev->stats.tx_bytes += cmdsts & 0xffff;
dprintk("tx_done_idx=%d free_idx=%d cmdsts=%08x\n",
tx_done_idx, dev->tx_free_idx, cmdsts);
skb = dev->tx_skbs[tx_done_idx];
dev->tx_skbs[tx_done_idx] = NULL;
dprintk("done(%p)\n", skb);
len = cmdsts & CMDSTS_LEN_MASK;
addr = desc_addr_get(desc + DESC_BUFPTR);
if (skb) {
pci_unmap_single(dev->pci_dev,
addr,
len,
PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
atomic_dec(&dev->nr_tx_skbs);
} else
pci_unmap_page(dev->pci_dev,
addr,
len,
PCI_DMA_TODEVICE);
tx_done_idx = (tx_done_idx + 1) % NR_TX_DESC;
dev->tx_done_idx = tx_done_idx;
desc[DESC_CMDSTS] = cpu_to_le32(0);
mb();
desc = dev->tx_descs + (tx_done_idx * DESC_SIZE);
}
if (netif_queue_stopped(ndev) && start_tx_okay(dev)) {
dprintk("start_queue(%p)\n", ndev);
netif_start_queue(ndev);
netif_wake_queue(ndev);
}
}
static void ns83820_cleanup_tx(struct ns83820 *dev)
{
unsigned i;
for (i=0; i<NR_TX_DESC; i++) {
struct sk_buff *skb = dev->tx_skbs[i];
dev->tx_skbs[i] = NULL;
if (skb) {
__le32 *desc = dev->tx_descs + (i * DESC_SIZE);
pci_unmap_single(dev->pci_dev,
desc_addr_get(desc + DESC_BUFPTR),
le32_to_cpu(desc[DESC_CMDSTS]) & CMDSTS_LEN_MASK,
PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb);
atomic_dec(&dev->nr_tx_skbs);
}
}
memset(dev->tx_descs, 0, NR_TX_DESC * DESC_SIZE * 4);
}
static netdev_tx_t ns83820_hard_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
u32 free_idx, cmdsts, extsts;
int nr_free, nr_frags;
unsigned tx_done_idx, last_idx;
dma_addr_t buf;
unsigned len;
skb_frag_t *frag;
int stopped = 0;
int do_intr = 0;
volatile __le32 *first_desc;
dprintk("ns83820_hard_start_xmit\n");
nr_frags = skb_shinfo(skb)->nr_frags;
again:
if (unlikely(dev->CFG_cache & CFG_LNKSTS)) {
netif_stop_queue(ndev);
if (unlikely(dev->CFG_cache & CFG_LNKSTS))
return NETDEV_TX_BUSY;
netif_start_queue(ndev);
}
last_idx = free_idx = dev->tx_free_idx;
tx_done_idx = dev->tx_done_idx;
nr_free = (tx_done_idx + NR_TX_DESC-2 - free_idx) % NR_TX_DESC;
nr_free -= 1;
if (nr_free <= nr_frags) {
dprintk("stop_queue - not enough(%p)\n", ndev);
netif_stop_queue(ndev);
if (dev->tx_done_idx != tx_done_idx) {
dprintk("restart queue(%p)\n", ndev);
netif_start_queue(ndev);
goto again;
}
return NETDEV_TX_BUSY;
}
if (free_idx == dev->tx_intr_idx) {
do_intr = 1;
dev->tx_intr_idx = (dev->tx_intr_idx + NR_TX_DESC/4) % NR_TX_DESC;
}
nr_free -= nr_frags;
if (nr_free < MIN_TX_DESC_FREE) {
dprintk("stop_queue - last entry(%p)\n", ndev);
netif_stop_queue(ndev);
stopped = 1;
}
frag = skb_shinfo(skb)->frags;
if (!nr_frags)
frag = NULL;
extsts = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
extsts |= EXTSTS_IPPKT;
if (IPPROTO_TCP == ip_hdr(skb)->protocol)
extsts |= EXTSTS_TCPPKT;
else if (IPPROTO_UDP == ip_hdr(skb)->protocol)
extsts |= EXTSTS_UDPPKT;
}
#ifdef NS83820_VLAN_ACCEL_SUPPORT
if(vlan_tx_tag_present(skb)) {
short tag = vlan_tx_tag_get(skb);
extsts |= (EXTSTS_VPKT | htons(tag));
}
#endif
len = skb->len;
if (nr_frags)
len -= skb->data_len;
buf = pci_map_single(dev->pci_dev, skb->data, len, PCI_DMA_TODEVICE);
first_desc = dev->tx_descs + (free_idx * DESC_SIZE);
for (;;) {
volatile __le32 *desc = dev->tx_descs + (free_idx * DESC_SIZE);
dprintk("frag[%3u]: %4u @ 0x%08Lx\n", free_idx, len,
(unsigned long long)buf);
last_idx = free_idx;
free_idx = (free_idx + 1) % NR_TX_DESC;
desc[DESC_LINK] = cpu_to_le32(dev->tx_phy_descs + (free_idx * DESC_SIZE * 4));
desc_addr_set(desc + DESC_BUFPTR, buf);
desc[DESC_EXTSTS] = cpu_to_le32(extsts);
cmdsts = ((nr_frags) ? CMDSTS_MORE : do_intr ? CMDSTS_INTR : 0);
cmdsts |= (desc == first_desc) ? 0 : CMDSTS_OWN;
cmdsts |= len;
desc[DESC_CMDSTS] = cpu_to_le32(cmdsts);
if (!nr_frags)
break;
buf = skb_frag_dma_map(&dev->pci_dev->dev, frag, 0,
skb_frag_size(frag), DMA_TO_DEVICE);
dprintk("frag: buf=%08Lx page=%08lx offset=%08lx\n",
(long long)buf, (long) page_to_pfn(frag->page),
frag->page_offset);
len = skb_frag_size(frag);
frag++;
nr_frags--;
}
dprintk("done pkt\n");
spin_lock_irq(&dev->tx_lock);
dev->tx_skbs[last_idx] = skb;
first_desc[DESC_CMDSTS] |= cpu_to_le32(CMDSTS_OWN);
dev->tx_free_idx = free_idx;
atomic_inc(&dev->nr_tx_skbs);
spin_unlock_irq(&dev->tx_lock);
kick_tx(dev);
if (stopped && (dev->tx_done_idx != tx_done_idx) && start_tx_okay(dev))
netif_start_queue(ndev);
return NETDEV_TX_OK;
}
static void ns83820_update_stats(struct ns83820 *dev)
{
struct net_device *ndev = dev->ndev;
u8 __iomem *base = dev->base;
ndev->stats.rx_errors += readl(base + 0x60) & 0xffff;
ndev->stats.rx_crc_errors += readl(base + 0x64) & 0xffff;
ndev->stats.rx_missed_errors += readl(base + 0x68) & 0xffff;
ndev->stats.rx_frame_errors += readl(base + 0x6c) & 0xffff;
readl(base + 0x70);
ndev->stats.rx_length_errors += readl(base + 0x74) & 0xffff;
ndev->stats.rx_length_errors += readl(base + 0x78) & 0xffff;
readl(base + 0x7c);
readl(base + 0x80);
readl(base + 0x84);
ndev->stats.tx_carrier_errors += readl(base + 0x88) & 0xff;
}
static struct net_device_stats *ns83820_get_stats(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
spin_lock_irq(&dev->misc_lock);
ns83820_update_stats(dev);
spin_unlock_irq(&dev->misc_lock);
return &ndev->stats;
}
static int ns83820_get_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct ns83820 *dev = PRIV(ndev);
u32 cfg, tanar, tbicr;
int fullduplex = 0;
cfg = readl(dev->base + CFG) ^ SPDSTS_POLARITY;
tanar = readl(dev->base + TANAR);
tbicr = readl(dev->base + TBICR);
fullduplex = (cfg & CFG_DUPSTS) ? 1 : 0;
cmd->supported = SUPPORTED_Autoneg;
if (dev->CFG_cache & CFG_TBI_EN) {
cmd->supported |= SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full |
SUPPORTED_FIBRE;
cmd->port = PORT_FIBRE;
} else {
cmd->supported |= SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full | SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full | SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full |
SUPPORTED_MII;
cmd->port = PORT_MII;
}
cmd->duplex = fullduplex ? DUPLEX_FULL : DUPLEX_HALF;
switch (cfg / CFG_SPDSTS0 & 3) {
case 2:
ethtool_cmd_speed_set(cmd, SPEED_1000);
break;
case 1:
ethtool_cmd_speed_set(cmd, SPEED_100);
break;
default:
ethtool_cmd_speed_set(cmd, SPEED_10);
break;
}
cmd->autoneg = (tbicr & TBICR_MR_AN_ENABLE)
? AUTONEG_ENABLE : AUTONEG_DISABLE;
return 0;
}
static int ns83820_set_settings(struct net_device *ndev,
struct ethtool_cmd *cmd)
{
struct ns83820 *dev = PRIV(ndev);
u32 cfg, tanar;
int have_optical = 0;
int fullduplex = 0;
cfg = readl(dev->base + CFG) ^ SPDSTS_POLARITY;
tanar = readl(dev->base + TANAR);
if (dev->CFG_cache & CFG_TBI_EN) {
have_optical = 1;
fullduplex = (tanar & TANAR_FULL_DUP);
} else {
fullduplex = cfg & CFG_DUPSTS;
}
spin_lock_irq(&dev->misc_lock);
spin_lock(&dev->tx_lock);
if (cmd->duplex != fullduplex) {
if (have_optical) {
if (cmd->duplex == DUPLEX_FULL) {
writel(readl(dev->base + TXCFG)
| TXCFG_CSI | TXCFG_HBI | TXCFG_ATP,
dev->base + TXCFG);
writel(readl(dev->base + RXCFG) | RXCFG_RX_FD,
dev->base + RXCFG);
writel(readl(dev->base + GPIOR) | GPIOR_GP1_OUT,
dev->base + GPIOR);
} else {
}
} else {
}
printk(KERN_INFO "%s: Duplex set via ethtool\n",
ndev->name);
}
if (1) {
if (cmd->autoneg == AUTONEG_ENABLE) {
writel(TBICR_MR_AN_ENABLE | TBICR_MR_RESTART_AN,
dev->base + TBICR);
writel(TBICR_MR_AN_ENABLE, dev->base + TBICR);
dev->linkstate = LINK_AUTONEGOTIATE;
printk(KERN_INFO "%s: autoneg enabled via ethtool\n",
ndev->name);
} else {
writel(0x00000000, dev->base + TBICR);
}
printk(KERN_INFO "%s: autoneg %s via ethtool\n", ndev->name,
cmd->autoneg ? "ENABLED" : "DISABLED");
}
phy_intr(ndev);
spin_unlock(&dev->tx_lock);
spin_unlock_irq(&dev->misc_lock);
return 0;
}
static void ns83820_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *info)
{
struct ns83820 *dev = PRIV(ndev);
strlcpy(info->driver, "ns83820", sizeof(info->driver));
strlcpy(info->version, VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(dev->pci_dev), sizeof(info->bus_info));
}
static u32 ns83820_get_link(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
u32 cfg = readl(dev->base + CFG) ^ SPDSTS_POLARITY;
return cfg & CFG_LNKSTS ? 1 : 0;
}
static inline void ns83820_disable_interrupts(struct ns83820 *dev)
{
writel(0, dev->base + IMR);
writel(0, dev->base + IER);
readl(dev->base + IER);
}
static void ns83820_mib_isr(struct ns83820 *dev)
{
unsigned long flags;
spin_lock_irqsave(&dev->misc_lock, flags);
ns83820_update_stats(dev);
spin_unlock_irqrestore(&dev->misc_lock, flags);
}
static irqreturn_t ns83820_irq(int foo, void *data)
{
struct net_device *ndev = data;
struct ns83820 *dev = PRIV(ndev);
u32 isr;
dprintk("ns83820_irq(%p)\n", ndev);
dev->ihr = 0;
isr = readl(dev->base + ISR);
dprintk("irq: %08x\n", isr);
ns83820_do_isr(ndev, isr);
return IRQ_HANDLED;
}
static void ns83820_do_isr(struct net_device *ndev, u32 isr)
{
struct ns83820 *dev = PRIV(ndev);
unsigned long flags;
#ifdef DEBUG
if (isr & ~(ISR_PHY | ISR_RXDESC | ISR_RXEARLY | ISR_RXOK | ISR_RXERR | ISR_TXIDLE | ISR_TXOK | ISR_TXDESC))
Dprintk("odd isr? 0x%08x\n", isr);
#endif
if (ISR_RXIDLE & isr) {
dev->rx_info.idle = 1;
Dprintk("oh dear, we are idle\n");
ns83820_rx_kick(ndev);
}
if ((ISR_RXDESC | ISR_RXOK) & isr) {
prefetch(dev->rx_info.next_rx_desc);
spin_lock_irqsave(&dev->misc_lock, flags);
dev->IMR_cache &= ~(ISR_RXDESC | ISR_RXOK);
writel(dev->IMR_cache, dev->base + IMR);
spin_unlock_irqrestore(&dev->misc_lock, flags);
tasklet_schedule(&dev->rx_tasklet);
}
if ((ISR_RXIDLE | ISR_RXORN | ISR_RXDESC | ISR_RXOK | ISR_RXERR) & isr)
ns83820_rx_kick(ndev);
if (unlikely(ISR_RXSOVR & isr)) {
ndev->stats.rx_fifo_errors++;
}
if (unlikely(ISR_RXORN & isr)) {
ndev->stats.rx_fifo_errors++;
}
if ((ISR_RXRCMP & isr) && dev->rx_info.up)
writel(CR_RXE, dev->base + CR);
if (ISR_TXIDLE & isr) {
u32 txdp;
txdp = readl(dev->base + TXDP);
dprintk("txdp: %08x\n", txdp);
txdp -= dev->tx_phy_descs;
dev->tx_idx = txdp / (DESC_SIZE * 4);
if (dev->tx_idx >= NR_TX_DESC) {
printk(KERN_ALERT "%s: BUG -- txdp out of range\n", ndev->name);
dev->tx_idx = 0;
}
if (dev->tx_idx != dev->tx_free_idx)
kick_tx(dev);
}
if ((ISR_TXDESC | ISR_TXIDLE | ISR_TXOK | ISR_TXERR) & isr) {
spin_lock_irqsave(&dev->tx_lock, flags);
do_tx_done(ndev);
spin_unlock_irqrestore(&dev->tx_lock, flags);
if ((dev->tx_done_idx == dev->tx_free_idx) &&
(dev->IMR_cache & ISR_TXOK)) {
spin_lock_irqsave(&dev->misc_lock, flags);
dev->IMR_cache &= ~ISR_TXOK;
writel(dev->IMR_cache, dev->base + IMR);
spin_unlock_irqrestore(&dev->misc_lock, flags);
}
}
if ((ISR_TXIDLE & isr) && (dev->tx_done_idx != dev->tx_free_idx)) {
spin_lock_irqsave(&dev->misc_lock, flags);
dev->IMR_cache |= ISR_TXOK;
writel(dev->IMR_cache, dev->base + IMR);
spin_unlock_irqrestore(&dev->misc_lock, flags);
}
if (unlikely(ISR_MIB & isr))
ns83820_mib_isr(dev);
if (unlikely(ISR_PHY & isr))
phy_intr(ndev);
#if 0
if (dev->ihr)
writel(dev->ihr, dev->base + IHR);
#endif
}
static void ns83820_do_reset(struct ns83820 *dev, u32 which)
{
Dprintk("resetting chip...\n");
writel(which, dev->base + CR);
do {
schedule();
} while (readl(dev->base + CR) & which);
Dprintk("okay!\n");
}
static int ns83820_stop(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
del_timer_sync(&dev->tx_watchdog);
ns83820_disable_interrupts(dev);
dev->rx_info.up = 0;
synchronize_irq(dev->pci_dev->irq);
ns83820_do_reset(dev, CR_RST);
synchronize_irq(dev->pci_dev->irq);
spin_lock_irq(&dev->misc_lock);
dev->IMR_cache &= ~(ISR_TXURN | ISR_TXIDLE | ISR_TXERR | ISR_TXDESC | ISR_TXOK);
spin_unlock_irq(&dev->misc_lock);
ns83820_cleanup_rx(dev);
ns83820_cleanup_tx(dev);
return 0;
}
static void ns83820_tx_timeout(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
u32 tx_done_idx;
__le32 *desc;
unsigned long flags;
spin_lock_irqsave(&dev->tx_lock, flags);
tx_done_idx = dev->tx_done_idx;
desc = dev->tx_descs + (tx_done_idx * DESC_SIZE);
printk(KERN_INFO "%s: tx_timeout: tx_done_idx=%d free_idx=%d cmdsts=%08x\n",
ndev->name,
tx_done_idx, dev->tx_free_idx, le32_to_cpu(desc[DESC_CMDSTS]));
#if defined(DEBUG)
{
u32 isr;
isr = readl(dev->base + ISR);
printk("irq: %08x imr: %08x\n", isr, dev->IMR_cache);
ns83820_do_isr(ndev, isr);
}
#endif
do_tx_done(ndev);
tx_done_idx = dev->tx_done_idx;
desc = dev->tx_descs + (tx_done_idx * DESC_SIZE);
printk(KERN_INFO "%s: after: tx_done_idx=%d free_idx=%d cmdsts=%08x\n",
ndev->name,
tx_done_idx, dev->tx_free_idx, le32_to_cpu(desc[DESC_CMDSTS]));
spin_unlock_irqrestore(&dev->tx_lock, flags);
}
static void ns83820_tx_watch(unsigned long data)
{
struct net_device *ndev = (void *)data;
struct ns83820 *dev = PRIV(ndev);
#if defined(DEBUG)
printk("ns83820_tx_watch: %u %u %d\n",
dev->tx_done_idx, dev->tx_free_idx, atomic_read(&dev->nr_tx_skbs)
);
#endif
if (time_after(jiffies, dev_trans_start(ndev) + 1*HZ) &&
dev->tx_done_idx != dev->tx_free_idx) {
printk(KERN_DEBUG "%s: ns83820_tx_watch: %u %u %d\n",
ndev->name,
dev->tx_done_idx, dev->tx_free_idx,
atomic_read(&dev->nr_tx_skbs));
ns83820_tx_timeout(ndev);
}
mod_timer(&dev->tx_watchdog, jiffies + 2*HZ);
}
static int ns83820_open(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
unsigned i;
u32 desc;
int ret;
dprintk("ns83820_open\n");
writel(0, dev->base + PQCR);
ret = ns83820_setup_rx(ndev);
if (ret)
goto failed;
memset(dev->tx_descs, 0, 4 * NR_TX_DESC * DESC_SIZE);
for (i=0; i<NR_TX_DESC; i++) {
dev->tx_descs[(i * DESC_SIZE) + DESC_LINK]
= cpu_to_le32(
dev->tx_phy_descs
+ ((i+1) % NR_TX_DESC) * DESC_SIZE * 4);
}
dev->tx_idx = 0;
dev->tx_done_idx = 0;
desc = dev->tx_phy_descs;
writel(0, dev->base + TXDP_HI);
writel(desc, dev->base + TXDP);
init_timer(&dev->tx_watchdog);
dev->tx_watchdog.data = (unsigned long)ndev;
dev->tx_watchdog.function = ns83820_tx_watch;
mod_timer(&dev->tx_watchdog, jiffies + 2*HZ);
netif_start_queue(ndev);
return 0;
failed:
ns83820_stop(ndev);
return ret;
}
static void ns83820_getmac(struct ns83820 *dev, u8 *mac)
{
unsigned i;
for (i=0; i<3; i++) {
u32 data;
writel(i*2, dev->base + RFCR);
data = readl(dev->base + RFDR);
*mac++ = data;
*mac++ = data >> 8;
}
}
static int ns83820_change_mtu(struct net_device *ndev, int new_mtu)
{
if (new_mtu > RX_BUF_SIZE)
return -EINVAL;
ndev->mtu = new_mtu;
return 0;
}
static void ns83820_set_multicast(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
u8 __iomem *rfcr = dev->base + RFCR;
u32 and_mask = 0xffffffff;
u32 or_mask = 0;
u32 val;
if (ndev->flags & IFF_PROMISC)
or_mask |= RFCR_AAU | RFCR_AAM;
else
and_mask &= ~(RFCR_AAU | RFCR_AAM);
if (ndev->flags & IFF_ALLMULTI || netdev_mc_count(ndev))
or_mask |= RFCR_AAM;
else
and_mask &= ~RFCR_AAM;
spin_lock_irq(&dev->misc_lock);
val = (readl(rfcr) & and_mask) | or_mask;
writel(val & ~RFCR_RFEN, rfcr);
writel(val, rfcr);
spin_unlock_irq(&dev->misc_lock);
}
static void ns83820_run_bist(struct net_device *ndev, const char *name, u32 enable, u32 done, u32 fail)
{
struct ns83820 *dev = PRIV(ndev);
int timed_out = 0;
unsigned long start;
u32 status;
int loops = 0;
dprintk("%s: start %s\n", ndev->name, name);
start = jiffies;
writel(enable, dev->base + PTSCR);
for (;;) {
loops++;
status = readl(dev->base + PTSCR);
if (!(status & enable))
break;
if (status & done)
break;
if (status & fail)
break;
if (time_after_eq(jiffies, start + HZ)) {
timed_out = 1;
break;
}
schedule_timeout_uninterruptible(1);
}
if (status & fail)
printk(KERN_INFO "%s: %s failed! (0x%08x & 0x%08x)\n",
ndev->name, name, status, fail);
else if (timed_out)
printk(KERN_INFO "%s: run_bist %s timed out! (%08x)\n",
ndev->name, name, status);
dprintk("%s: done %s in %d loops\n", ndev->name, name, loops);
}
static void ns83820_mii_write_bit(struct ns83820 *dev, int bit)
{
dev->MEAR_cache &= ~MEAR_MDC;
writel(dev->MEAR_cache, dev->base + MEAR);
readl(dev->base + MEAR);
dev->MEAR_cache |= MEAR_MDDIR;
if (bit)
dev->MEAR_cache |= MEAR_MDIO;
else
dev->MEAR_cache &= ~MEAR_MDIO;
writel(dev->MEAR_cache, dev->base + MEAR);
readl(dev->base + MEAR);
udelay(1);
dev->MEAR_cache |= MEAR_MDC;
writel(dev->MEAR_cache, dev->base + MEAR);
readl(dev->base + MEAR);
udelay(1);
}
static int ns83820_mii_read_bit(struct ns83820 *dev)
{
int bit;
dev->MEAR_cache &= ~MEAR_MDC;
dev->MEAR_cache &= ~MEAR_MDDIR;
writel(dev->MEAR_cache, dev->base + MEAR);
readl(dev->base + MEAR);
udelay(1);
bit = (readl(dev->base + MEAR) & MEAR_MDIO) ? 1 : 0;
dev->MEAR_cache |= MEAR_MDC;
writel(dev->MEAR_cache, dev->base + MEAR);
udelay(1);
return bit;
}
static unsigned ns83820_mii_read_reg(struct ns83820 *dev, unsigned phy, unsigned reg)
{
unsigned data = 0;
int i;
for (i=0; i<64; i++)
ns83820_mii_read_bit(dev);
ns83820_mii_write_bit(dev, 0);
ns83820_mii_write_bit(dev, 1);
ns83820_mii_write_bit(dev, 1);
ns83820_mii_write_bit(dev, 0);
for (i=0; i<5; i++)
ns83820_mii_write_bit(dev, phy & (0x10 >> i));
for (i=0; i<5; i++)
ns83820_mii_write_bit(dev, reg & (0x10 >> i));
ns83820_mii_read_bit(dev);
ns83820_mii_read_bit(dev);
for (i=0; i<16; i++) {
data <<= 1;
data |= ns83820_mii_read_bit(dev);
}
return data;
}
static unsigned ns83820_mii_write_reg(struct ns83820 *dev, unsigned phy, unsigned reg, unsigned data)
{
int i;
for (i=0; i<64; i++)
ns83820_mii_read_bit(dev);
ns83820_mii_write_bit(dev, 0);
ns83820_mii_write_bit(dev, 1);
ns83820_mii_write_bit(dev, 0);
ns83820_mii_write_bit(dev, 1);
for (i=0; i<5; i++)
ns83820_mii_write_bit(dev, phy & (0x10 >> i));
for (i=0; i<5; i++)
ns83820_mii_write_bit(dev, reg & (0x10 >> i));
ns83820_mii_read_bit(dev);
ns83820_mii_read_bit(dev);
for (i=0; i<16; i++)
ns83820_mii_write_bit(dev, (data >> (15 - i)) & 1);
return data;
}
static void ns83820_probe_phy(struct net_device *ndev)
{
struct ns83820 *dev = PRIV(ndev);
static int first;
int i;
#define MII_PHYIDR1 0x02
#define MII_PHYIDR2 0x03
#if 0
if (!first) {
unsigned tmp;
ns83820_mii_read_reg(dev, 1, 0x09);
ns83820_mii_write_reg(dev, 1, 0x10, 0x0d3e);
tmp = ns83820_mii_read_reg(dev, 1, 0x00);
ns83820_mii_write_reg(dev, 1, 0x00, tmp | 0x8000);
udelay(1300);
ns83820_mii_read_reg(dev, 1, 0x09);
}
#endif
first = 1;
for (i=1; i<2; i++) {
int j;
unsigned a, b;
a = ns83820_mii_read_reg(dev, i, MII_PHYIDR1);
b = ns83820_mii_read_reg(dev, i, MII_PHYIDR2);
for (j=0; j<0x16; j+=4) {
dprintk("%s: [0x%02x] %04x %04x %04x %04x\n",
ndev->name, j,
ns83820_mii_read_reg(dev, i, 0 + j),
ns83820_mii_read_reg(dev, i, 1 + j),
ns83820_mii_read_reg(dev, i, 2 + j),
ns83820_mii_read_reg(dev, i, 3 + j)
);
}
}
{
unsigned a, b;
ns83820_mii_write_reg(dev, 1, 0x16, 0x000d);
ns83820_mii_write_reg(dev, 1, 0x1e, 0x810e);
a = ns83820_mii_read_reg(dev, 1, 0x1d);
ns83820_mii_write_reg(dev, 1, 0x16, 0x000d);
ns83820_mii_write_reg(dev, 1, 0x1e, 0x810e);
b = ns83820_mii_read_reg(dev, 1, 0x1d);
dprintk("version: 0x%04x 0x%04x\n", a, b);
}
}
static int ns83820_init_one(struct pci_dev *pci_dev,
const struct pci_device_id *id)
{
struct net_device *ndev;
struct ns83820 *dev;
long addr;
int err;
int using_dac = 0;
if (sizeof(dma_addr_t) == 8 &&
!pci_set_dma_mask(pci_dev, DMA_BIT_MASK(64))) {
using_dac = 1;
} else if (!pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32))) {
using_dac = 0;
} else {
dev_warn(&pci_dev->dev, "pci_set_dma_mask failed!\n");
return -ENODEV;
}
ndev = alloc_etherdev(sizeof(struct ns83820));
err = -ENOMEM;
if (!ndev)
goto out;
dev = PRIV(ndev);
dev->ndev = ndev;
spin_lock_init(&dev->rx_info.lock);
spin_lock_init(&dev->tx_lock);
spin_lock_init(&dev->misc_lock);
dev->pci_dev = pci_dev;
SET_NETDEV_DEV(ndev, &pci_dev->dev);
INIT_WORK(&dev->tq_refill, queue_refill);
tasklet_init(&dev->rx_tasklet, rx_action, (unsigned long)ndev);
err = pci_enable_device(pci_dev);
if (err) {
dev_info(&pci_dev->dev, "pci_enable_dev failed: %d\n", err);
goto out_free;
}
pci_set_master(pci_dev);
addr = pci_resource_start(pci_dev, 1);
dev->base = ioremap_nocache(addr, PAGE_SIZE);
dev->tx_descs = pci_alloc_consistent(pci_dev,
4 * DESC_SIZE * NR_TX_DESC, &dev->tx_phy_descs);
dev->rx_info.descs = pci_alloc_consistent(pci_dev,
4 * DESC_SIZE * NR_RX_DESC, &dev->rx_info.phy_descs);
err = -ENOMEM;
if (!dev->base || !dev->tx_descs || !dev->rx_info.descs)
goto out_disable;
dprintk("%p: %08lx %p: %08lx\n",
dev->tx_descs, (long)dev->tx_phy_descs,
dev->rx_info.descs, (long)dev->rx_info.phy_descs);
ns83820_disable_interrupts(dev);
dev->IMR_cache = 0;
err = request_irq(pci_dev->irq, ns83820_irq, IRQF_SHARED,
DRV_NAME, ndev);
if (err) {
dev_info(&pci_dev->dev, "unable to register irq %d, err %d\n",
pci_dev->irq, err);
goto out_disable;
}
rtnl_lock();
err = dev_alloc_name(ndev, ndev->name);
if (err < 0) {
dev_info(&pci_dev->dev, "unable to get netdev name: %d\n", err);
goto out_free_irq;
}
printk("%s: ns83820.c: 0x22c: %08x, subsystem: %04x:%04x\n",
ndev->name, le32_to_cpu(readl(dev->base + 0x22c)),
pci_dev->subsystem_vendor, pci_dev->subsystem_device);
ndev->netdev_ops = &netdev_ops;
ndev->ethtool_ops = &ops;
ndev->watchdog_timeo = 5 * HZ;
pci_set_drvdata(pci_dev, ndev);
ns83820_do_reset(dev, CR_RST);
writel(PTSCR_RBIST_RST, dev->base + PTSCR);
ns83820_run_bist(ndev, "sram bist", PTSCR_RBIST_EN,
PTSCR_RBIST_DONE, PTSCR_RBIST_FAIL);
ns83820_run_bist(ndev, "eeprom bist", PTSCR_EEBIST_EN, 0,
PTSCR_EEBIST_FAIL);
ns83820_run_bist(ndev, "eeprom load", PTSCR_EELOAD_EN, 0, 0);
dev->CFG_cache = readl(dev->base + CFG);
if ((dev->CFG_cache & CFG_PCI64_DET)) {
printk(KERN_INFO "%s: detected 64 bit PCI data bus.\n",
ndev->name);
if (!(dev->CFG_cache & CFG_DATA64_EN))
printk(KERN_INFO "%s: EEPROM did not enable 64 bit bus. Disabled.\n",
ndev->name);
} else
dev->CFG_cache &= ~(CFG_DATA64_EN);
dev->CFG_cache &= (CFG_TBI_EN | CFG_MRM_DIS | CFG_MWI_DIS |
CFG_T64ADDR | CFG_DATA64_EN | CFG_EXT_125 |
CFG_M64ADDR);
dev->CFG_cache |= CFG_PINT_DUPSTS | CFG_PINT_LNKSTS | CFG_PINT_SPDSTS |
CFG_EXTSTS_EN | CFG_EXD | CFG_PESEL;
dev->CFG_cache |= CFG_REQALG;
dev->CFG_cache |= CFG_POW;
dev->CFG_cache |= CFG_TMRTEST;
if (sizeof(dma_addr_t) == 8)
dev->CFG_cache |= CFG_M64ADDR;
if (using_dac)
dev->CFG_cache |= CFG_T64ADDR;
dev->CFG_cache &= ~CFG_BEM;
if (dev->CFG_cache & CFG_TBI_EN) {
printk(KERN_INFO "%s: enabling optical transceiver\n",
ndev->name);
writel(readl(dev->base + GPIOR) | 0x3e8, dev->base + GPIOR);
writel(readl(dev->base + TANAR)
| TANAR_HALF_DUP | TANAR_FULL_DUP,
dev->base + TANAR);
writel(TBICR_MR_AN_ENABLE | TBICR_MR_RESTART_AN,
dev->base + TBICR);
writel(TBICR_MR_AN_ENABLE, dev->base + TBICR);
dev->linkstate = LINK_AUTONEGOTIATE;
dev->CFG_cache |= CFG_MODE_1000;
}
writel(dev->CFG_cache, dev->base + CFG);
dprintk("CFG: %08x\n", dev->CFG_cache);
if (reset_phy) {
printk(KERN_INFO "%s: resetting phy\n", ndev->name);
writel(dev->CFG_cache | CFG_PHY_RST, dev->base + CFG);
msleep(10);
writel(dev->CFG_cache, dev->base + CFG);
}
#if 0
if (readl(dev->base + SRR))
writel(readl(dev->base+0x20c) | 0xfe00, dev->base + 0x20c);
#endif
writel(TXCFG_CSI | TXCFG_HBI | TXCFG_ATP | TXCFG_MXDMA512
| ((1600 / 32) * 0x100),
dev->base + TXCFG);
writel(0x000, dev->base + IHR);
writel(0x100, dev->base + IHR);
writel(0x000, dev->base + IHR);
writel(RXCFG_AEP | RXCFG_ARP | RXCFG_AIRL | RXCFG_RX_FD
| RXCFG_STRIPCRC
| (RXCFG_MXDMA512) | 0, dev->base + RXCFG);
writel(0, dev->base + PQCR);
#ifdef NS83820_VLAN_ACCEL_SUPPORT
#define VRCR_INIT_VALUE (VRCR_IPEN|VRCR_VTDEN|VRCR_VTREN)
#else
#define VRCR_INIT_VALUE (VRCR_IPEN|VRCR_VTDEN)
#endif
writel(VRCR_INIT_VALUE, dev->base + VRCR);
#ifdef NS83820_VLAN_ACCEL_SUPPORT
#define VTCR_INIT_VALUE (VTCR_PPCHK|VTCR_VPPTI)
#else
#define VTCR_INIT_VALUE VTCR_PPCHK
#endif
writel(VTCR_INIT_VALUE, dev->base + VTCR);
writel((PCR_PS_MCAST | PCR_PS_DA | PCR_PSEN | PCR_FFLO_4K |
PCR_FFHI_8K | PCR_STLO_4 | PCR_STHI_8 | PCR_PAUSE_CNT),
dev->base + PCR);
writel(0, dev->base + WCSR);
ns83820_getmac(dev, ndev->dev_addr);
ndev->features |= NETIF_F_SG;
ndev->features |= NETIF_F_IP_CSUM;
#ifdef NS83820_VLAN_ACCEL_SUPPORT
ndev->features |= NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX;
#endif
if (using_dac) {
printk(KERN_INFO "%s: using 64 bit addressing.\n",
ndev->name);
ndev->features |= NETIF_F_HIGHDMA;
}
printk(KERN_INFO "%s: ns83820 v" VERSION ": DP83820 v%u.%u: %pM io=0x%08lx irq=%d f=%s\n",
ndev->name,
(unsigned)readl(dev->base + SRR) >> 8,
(unsigned)readl(dev->base + SRR) & 0xff,
ndev->dev_addr, addr, pci_dev->irq,
(ndev->features & NETIF_F_HIGHDMA) ? "h,sg" : "sg"
);
#ifdef PHY_CODE_IS_FINISHED
ns83820_probe_phy(ndev);
#endif
err = register_netdevice(ndev);
if (err) {
printk(KERN_INFO "ns83820: unable to register netdev: %d\n", err);
goto out_cleanup;
}
rtnl_unlock();
return 0;
out_cleanup:
ns83820_disable_interrupts(dev);
out_free_irq:
rtnl_unlock();
free_irq(pci_dev->irq, ndev);
out_disable:
if (dev->base)
iounmap(dev->base);
pci_free_consistent(pci_dev, 4 * DESC_SIZE * NR_TX_DESC, dev->tx_descs, dev->tx_phy_descs);
pci_free_consistent(pci_dev, 4 * DESC_SIZE * NR_RX_DESC, dev->rx_info.descs, dev->rx_info.phy_descs);
pci_disable_device(pci_dev);
out_free:
free_netdev(ndev);
out:
return err;
}
static void ns83820_remove_one(struct pci_dev *pci_dev)
{
struct net_device *ndev = pci_get_drvdata(pci_dev);
struct ns83820 *dev = PRIV(ndev);
if (!ndev)
return;
ns83820_disable_interrupts(dev);
unregister_netdev(ndev);
free_irq(dev->pci_dev->irq, ndev);
iounmap(dev->base);
pci_free_consistent(dev->pci_dev, 4 * DESC_SIZE * NR_TX_DESC,
dev->tx_descs, dev->tx_phy_descs);
pci_free_consistent(dev->pci_dev, 4 * DESC_SIZE * NR_RX_DESC,
dev->rx_info.descs, dev->rx_info.phy_descs);
pci_disable_device(dev->pci_dev);
free_netdev(ndev);
}
static int __init ns83820_init(void)
{
printk(KERN_INFO "ns83820.c: National Semiconductor DP83820 10/100/1000 driver.\n");
return pci_register_driver(&driver);
}
static void __exit ns83820_exit(void)
{
pci_unregister_driver(&driver);
}
