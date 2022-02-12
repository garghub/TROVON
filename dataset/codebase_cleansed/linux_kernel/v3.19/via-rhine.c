static void rhine_wait_bit(struct rhine_private *rp, u8 reg, u8 mask, bool low)
{
void __iomem *ioaddr = rp->base;
int i;
for (i = 0; i < 1024; i++) {
bool has_mask_bits = !!(ioread8(ioaddr + reg) & mask);
if (low ^ has_mask_bits)
break;
udelay(10);
}
if (i > 64) {
netif_dbg(rp, hw, rp->dev, "%s bit wait (%02x/%02x) cycle "
"count: %04d\n", low ? "low" : "high", reg, mask, i);
}
}
static void rhine_wait_bit_high(struct rhine_private *rp, u8 reg, u8 mask)
{
rhine_wait_bit(rp, reg, mask, false);
}
static void rhine_wait_bit_low(struct rhine_private *rp, u8 reg, u8 mask)
{
rhine_wait_bit(rp, reg, mask, true);
}
static u32 rhine_get_events(struct rhine_private *rp)
{
void __iomem *ioaddr = rp->base;
u32 intr_status;
intr_status = ioread16(ioaddr + IntrStatus);
if (rp->quirks & rqStatusWBRace)
intr_status |= ioread8(ioaddr + IntrStatus2) << 16;
return intr_status;
}
static void rhine_ack_events(struct rhine_private *rp, u32 mask)
{
void __iomem *ioaddr = rp->base;
if (rp->quirks & rqStatusWBRace)
iowrite8(mask >> 16, ioaddr + IntrStatus2);
iowrite16(mask, ioaddr + IntrStatus);
mmiowb();
}
static void rhine_power_init(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
u16 wolstat;
if (rp->quirks & rqWOL) {
iowrite8(ioread8(ioaddr + StickyHW) & 0xFC, ioaddr + StickyHW);
iowrite8(0x80, ioaddr + WOLcgClr);
iowrite8(0xFF, ioaddr + WOLcrClr);
if (rp->quirks & rq6patterns)
iowrite8(0x03, ioaddr + WOLcrClr1);
wolstat = ioread8(ioaddr + PwrcsrSet);
if (rp->quirks & rq6patterns)
wolstat |= (ioread8(ioaddr + PwrcsrSet1) & 0x03) << 8;
iowrite8(0xFF, ioaddr + PwrcsrClr);
if (rp->quirks & rq6patterns)
iowrite8(0x03, ioaddr + PwrcsrClr1);
if (wolstat) {
char *reason;
switch (wolstat) {
case WOLmagic:
reason = "Magic packet";
break;
case WOLlnkon:
reason = "Link went up";
break;
case WOLlnkoff:
reason = "Link went down";
break;
case WOLucast:
reason = "Unicast packet";
break;
case WOLbmcast:
reason = "Multicast/broadcast packet";
break;
default:
reason = "Unknown";
}
netdev_info(dev, "Woke system up. Reason: %s\n",
reason);
}
}
}
static void rhine_chip_reset(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
u8 cmd1;
iowrite8(Cmd1Reset, ioaddr + ChipCmd1);
IOSYNC;
if (ioread8(ioaddr + ChipCmd1) & Cmd1Reset) {
netdev_info(dev, "Reset not complete yet. Trying harder.\n");
if (rp->quirks & rqForceReset)
iowrite8(0x40, ioaddr + MiscCmd);
rhine_wait_bit_low(rp, ChipCmd1, Cmd1Reset);
}
cmd1 = ioread8(ioaddr + ChipCmd1);
netif_info(rp, hw, dev, "Reset %s\n", (cmd1 & Cmd1Reset) ?
"failed" : "succeeded");
}
static void enable_mmio(long pioaddr, u32 quirks)
{
int n;
if (quirks & rqNeedEnMMIO) {
if (quirks & rqRhineI) {
n = inb(pioaddr + ConfigA) | 0x20;
outb(n, pioaddr + ConfigA);
} else {
n = inb(pioaddr + ConfigD) | 0x80;
outb(n, pioaddr + ConfigD);
}
}
}
static inline int verify_mmio(struct device *hwdev,
long pioaddr,
void __iomem *ioaddr,
u32 quirks)
{
if (quirks & rqNeedEnMMIO) {
int i = 0;
while (mmio_verify_registers[i]) {
int reg = mmio_verify_registers[i++];
unsigned char a = inb(pioaddr+reg);
unsigned char b = readb(ioaddr+reg);
if (a != b) {
dev_err(hwdev,
"MMIO do not match PIO [%02x] (%02x != %02x)\n",
reg, a, b);
return -EIO;
}
}
}
return 0;
}
static void rhine_reload_eeprom(long pioaddr, struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
int i;
outb(0x20, pioaddr + MACRegEEcsr);
for (i = 0; i < 1024; i++) {
if (!(inb(pioaddr + MACRegEEcsr) & 0x20))
break;
}
if (i > 512)
pr_info("%4d cycles used @ %s:%d\n", i, __func__, __LINE__);
enable_mmio(pioaddr, rp->quirks);
if (rp->quirks & rqWOL)
iowrite8(ioread8(ioaddr + ConfigA) & 0xFC, ioaddr + ConfigA);
}
static void rhine_poll(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
const int irq = rp->irq;
disable_irq(irq);
rhine_interrupt(irq, dev);
enable_irq(irq);
}
static void rhine_kick_tx_threshold(struct rhine_private *rp)
{
if (rp->tx_thresh < 0xe0) {
void __iomem *ioaddr = rp->base;
rp->tx_thresh += 0x20;
BYTE_REG_BITS_SET(rp->tx_thresh, 0x80, ioaddr + TxConfig);
}
}
static void rhine_tx_err(struct rhine_private *rp, u32 status)
{
struct net_device *dev = rp->dev;
if (status & IntrTxAborted) {
netif_info(rp, tx_err, dev,
"Abort %08x, frame dropped\n", status);
}
if (status & IntrTxUnderrun) {
rhine_kick_tx_threshold(rp);
netif_info(rp, tx_err ,dev, "Transmitter underrun, "
"Tx threshold now %02x\n", rp->tx_thresh);
}
if (status & IntrTxDescRace)
netif_info(rp, tx_err, dev, "Tx descriptor write-back race\n");
if ((status & IntrTxError) &&
(status & (IntrTxAborted | IntrTxUnderrun | IntrTxDescRace)) == 0) {
rhine_kick_tx_threshold(rp);
netif_info(rp, tx_err, dev, "Unspecified error. "
"Tx threshold now %02x\n", rp->tx_thresh);
}
rhine_restart_tx(dev);
}
static void rhine_update_rx_crc_and_missed_errord(struct rhine_private *rp)
{
void __iomem *ioaddr = rp->base;
struct net_device_stats *stats = &rp->dev->stats;
stats->rx_crc_errors += ioread16(ioaddr + RxCRCErrs);
stats->rx_missed_errors += ioread16(ioaddr + RxMissed);
iowrite32(0, ioaddr + RxMissed);
ioread16(ioaddr + RxCRCErrs);
ioread16(ioaddr + RxMissed);
}
static int rhine_napipoll(struct napi_struct *napi, int budget)
{
struct rhine_private *rp = container_of(napi, struct rhine_private, napi);
struct net_device *dev = rp->dev;
void __iomem *ioaddr = rp->base;
u16 enable_mask = RHINE_EVENT & 0xffff;
int work_done = 0;
u32 status;
status = rhine_get_events(rp);
rhine_ack_events(rp, status & ~RHINE_EVENT_SLOW);
if (status & RHINE_EVENT_NAPI_RX)
work_done += rhine_rx(dev, budget);
if (status & RHINE_EVENT_NAPI_TX) {
if (status & RHINE_EVENT_NAPI_TX_ERR) {
rhine_wait_bit_low(rp, ChipCmd, CmdTxOn);
if (ioread8(ioaddr + ChipCmd) & CmdTxOn)
netif_warn(rp, tx_err, dev, "Tx still on\n");
}
rhine_tx(dev);
if (status & RHINE_EVENT_NAPI_TX_ERR)
rhine_tx_err(rp, status);
}
if (status & IntrStatsMax) {
spin_lock(&rp->lock);
rhine_update_rx_crc_and_missed_errord(rp);
spin_unlock(&rp->lock);
}
if (status & RHINE_EVENT_SLOW) {
enable_mask &= ~RHINE_EVENT_SLOW;
schedule_work(&rp->slow_event_task);
}
if (work_done < budget) {
napi_complete(napi);
iowrite16(enable_mask, ioaddr + IntrEnable);
mmiowb();
}
return work_done;
}
static void rhine_hw_init(struct net_device *dev, long pioaddr)
{
struct rhine_private *rp = netdev_priv(dev);
rhine_chip_reset(dev);
if (rp->quirks & rqRhineI)
msleep(5);
if (dev_is_pci(dev->dev.parent))
rhine_reload_eeprom(pioaddr, dev);
}
static int rhine_init_one_common(struct device *hwdev, u32 quirks,
long pioaddr, void __iomem *ioaddr, int irq)
{
struct net_device *dev;
struct rhine_private *rp;
int i, rc, phy_id;
const char *name;
rc = dma_set_mask(hwdev, DMA_BIT_MASK(32));
if (rc) {
dev_err(hwdev, "32-bit DMA addresses not supported by the card!?\n");
goto err_out;
}
dev = alloc_etherdev(sizeof(struct rhine_private));
if (!dev) {
rc = -ENOMEM;
goto err_out;
}
SET_NETDEV_DEV(dev, hwdev);
rp = netdev_priv(dev);
rp->dev = dev;
rp->quirks = quirks;
rp->pioaddr = pioaddr;
rp->base = ioaddr;
rp->irq = irq;
rp->msg_enable = netif_msg_init(debug, RHINE_MSG_DEFAULT);
phy_id = rp->quirks & rqIntPHY ? 1 : 0;
u64_stats_init(&rp->tx_stats.syncp);
u64_stats_init(&rp->rx_stats.syncp);
rhine_power_init(dev);
rhine_hw_init(dev, pioaddr);
for (i = 0; i < 6; i++)
dev->dev_addr[i] = ioread8(ioaddr + StationAddr + i);
if (!is_valid_ether_addr(dev->dev_addr)) {
netdev_err(dev, "Invalid MAC address: %pM\n", dev->dev_addr);
eth_hw_addr_random(dev);
netdev_info(dev, "Using random MAC address: %pM\n",
dev->dev_addr);
}
if (!phy_id)
phy_id = ioread8(ioaddr + 0x6C);
spin_lock_init(&rp->lock);
mutex_init(&rp->task_lock);
INIT_WORK(&rp->reset_task, rhine_reset_task);
INIT_WORK(&rp->slow_event_task, rhine_slow_event_task);
rp->mii_if.dev = dev;
rp->mii_if.mdio_read = mdio_read;
rp->mii_if.mdio_write = mdio_write;
rp->mii_if.phy_id_mask = 0x1f;
rp->mii_if.reg_num_mask = 0x1f;
dev->netdev_ops = &rhine_netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
netif_napi_add(dev, &rp->napi, rhine_napipoll, 64);
if (rp->quirks & rqRhineI)
dev->features |= NETIF_F_SG|NETIF_F_HW_CSUM;
if (rp->quirks & rqMgmt)
dev->features |= NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER;
rc = register_netdev(dev);
if (rc)
goto err_out_free_netdev;
if (rp->quirks & rqRhineI)
name = "Rhine";
else if (rp->quirks & rqStatusWBRace)
name = "Rhine II";
else if (rp->quirks & rqMgmt)
name = "Rhine III (Management Adapter)";
else
name = "Rhine III";
netdev_info(dev, "VIA %s at 0x%lx, %pM, IRQ %d\n",
name, (long)ioaddr, dev->dev_addr, rp->irq);
dev_set_drvdata(hwdev, dev);
{
u16 mii_cmd;
int mii_status = mdio_read(dev, phy_id, 1);
mii_cmd = mdio_read(dev, phy_id, MII_BMCR) & ~BMCR_ISOLATE;
mdio_write(dev, phy_id, MII_BMCR, mii_cmd);
if (mii_status != 0xffff && mii_status != 0x0000) {
rp->mii_if.advertising = mdio_read(dev, phy_id, 4);
netdev_info(dev,
"MII PHY found at address %d, status 0x%04x advertising %04x Link %04x\n",
phy_id,
mii_status, rp->mii_if.advertising,
mdio_read(dev, phy_id, 5));
if (mii_status & BMSR_LSTATUS)
netif_carrier_on(dev);
else
netif_carrier_off(dev);
}
}
rp->mii_if.phy_id = phy_id;
if (avoid_D3)
netif_info(rp, probe, dev, "No D3 power state at shutdown\n");
return 0;
err_out_free_netdev:
free_netdev(dev);
err_out:
return rc;
}
static int rhine_init_one_pci(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct device *hwdev = &pdev->dev;
int rc;
long pioaddr, memaddr;
void __iomem *ioaddr;
int io_size = pdev->revision < VTunknown0 ? 128 : 256;
#ifdef CONFIG_VIA_RHINE_MMIO
u32 quirks = rqNeedEnMMIO;
#else
u32 quirks = 0;
#endif
#ifndef MODULE
pr_info_once("%s\n", version);
#endif
rc = pci_enable_device(pdev);
if (rc)
goto err_out;
if (pdev->revision < VTunknown0) {
quirks |= rqRhineI;
} else if (pdev->revision >= VT6102) {
quirks |= rqWOL | rqForceReset;
if (pdev->revision < VT6105) {
quirks |= rqStatusWBRace;
} else {
quirks |= rqIntPHY;
if (pdev->revision >= VT6105_B0)
quirks |= rq6patterns;
if (pdev->revision >= VT6105M)
quirks |= rqMgmt;
}
}
if ((pci_resource_len(pdev, 0) < io_size) ||
(pci_resource_len(pdev, 1) < io_size)) {
rc = -EIO;
dev_err(hwdev, "Insufficient PCI resources, aborting\n");
goto err_out_pci_disable;
}
pioaddr = pci_resource_start(pdev, 0);
memaddr = pci_resource_start(pdev, 1);
pci_set_master(pdev);
rc = pci_request_regions(pdev, DRV_NAME);
if (rc)
goto err_out_pci_disable;
ioaddr = pci_iomap(pdev, (quirks & rqNeedEnMMIO ? 1 : 0), io_size);
if (!ioaddr) {
rc = -EIO;
dev_err(hwdev,
"ioremap failed for device %s, region 0x%X @ 0x%lX\n",
dev_name(hwdev), io_size, memaddr);
goto err_out_free_res;
}
enable_mmio(pioaddr, quirks);
rc = verify_mmio(hwdev, pioaddr, ioaddr, quirks);
if (rc)
goto err_out_unmap;
rc = rhine_init_one_common(&pdev->dev, quirks,
pioaddr, ioaddr, pdev->irq);
if (!rc)
return 0;
err_out_unmap:
pci_iounmap(pdev, ioaddr);
err_out_free_res:
pci_release_regions(pdev);
err_out_pci_disable:
pci_disable_device(pdev);
err_out:
return rc;
}
static int rhine_init_one_platform(struct platform_device *pdev)
{
const struct of_device_id *match;
const u32 *quirks;
int irq;
struct resource *res;
void __iomem *ioaddr;
match = of_match_device(rhine_of_tbl, &pdev->dev);
if (!match)
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ioaddr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ioaddr))
return PTR_ERR(ioaddr);
irq = irq_of_parse_and_map(pdev->dev.of_node, 0);
if (!irq)
return -EINVAL;
quirks = match->data;
if (!quirks)
return -EINVAL;
return rhine_init_one_common(&pdev->dev, *quirks,
(long)ioaddr, ioaddr, irq);
}
static int alloc_ring(struct net_device* dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
void *ring;
dma_addr_t ring_dma;
ring = dma_alloc_coherent(hwdev,
RX_RING_SIZE * sizeof(struct rx_desc) +
TX_RING_SIZE * sizeof(struct tx_desc),
&ring_dma,
GFP_ATOMIC);
if (!ring) {
netdev_err(dev, "Could not allocate DMA memory\n");
return -ENOMEM;
}
if (rp->quirks & rqRhineI) {
rp->tx_bufs = dma_alloc_coherent(hwdev,
PKT_BUF_SZ * TX_RING_SIZE,
&rp->tx_bufs_dma,
GFP_ATOMIC);
if (rp->tx_bufs == NULL) {
dma_free_coherent(hwdev,
RX_RING_SIZE * sizeof(struct rx_desc) +
TX_RING_SIZE * sizeof(struct tx_desc),
ring, ring_dma);
return -ENOMEM;
}
}
rp->rx_ring = ring;
rp->tx_ring = ring + RX_RING_SIZE * sizeof(struct rx_desc);
rp->rx_ring_dma = ring_dma;
rp->tx_ring_dma = ring_dma + RX_RING_SIZE * sizeof(struct rx_desc);
return 0;
}
static void free_ring(struct net_device* dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
dma_free_coherent(hwdev,
RX_RING_SIZE * sizeof(struct rx_desc) +
TX_RING_SIZE * sizeof(struct tx_desc),
rp->rx_ring, rp->rx_ring_dma);
rp->tx_ring = NULL;
if (rp->tx_bufs)
dma_free_coherent(hwdev, PKT_BUF_SZ * TX_RING_SIZE,
rp->tx_bufs, rp->tx_bufs_dma);
rp->tx_bufs = NULL;
}
static void alloc_rbufs(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
dma_addr_t next;
int i;
rp->dirty_rx = rp->cur_rx = 0;
rp->rx_buf_sz = (dev->mtu <= 1500 ? PKT_BUF_SZ : dev->mtu + 32);
rp->rx_head_desc = &rp->rx_ring[0];
next = rp->rx_ring_dma;
for (i = 0; i < RX_RING_SIZE; i++) {
rp->rx_ring[i].rx_status = 0;
rp->rx_ring[i].desc_length = cpu_to_le32(rp->rx_buf_sz);
next += sizeof(struct rx_desc);
rp->rx_ring[i].next_desc = cpu_to_le32(next);
rp->rx_skbuff[i] = NULL;
}
rp->rx_ring[i-1].next_desc = cpu_to_le32(rp->rx_ring_dma);
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb = netdev_alloc_skb(dev, rp->rx_buf_sz);
rp->rx_skbuff[i] = skb;
if (skb == NULL)
break;
rp->rx_skbuff_dma[i] =
dma_map_single(hwdev, skb->data, rp->rx_buf_sz,
DMA_FROM_DEVICE);
if (dma_mapping_error(hwdev, rp->rx_skbuff_dma[i])) {
rp->rx_skbuff_dma[i] = 0;
dev_kfree_skb(skb);
break;
}
rp->rx_ring[i].addr = cpu_to_le32(rp->rx_skbuff_dma[i]);
rp->rx_ring[i].rx_status = cpu_to_le32(DescOwn);
}
rp->dirty_rx = (unsigned int)(i - RX_RING_SIZE);
}
static void free_rbufs(struct net_device* dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
int i;
for (i = 0; i < RX_RING_SIZE; i++) {
rp->rx_ring[i].rx_status = 0;
rp->rx_ring[i].addr = cpu_to_le32(0xBADF00D0);
if (rp->rx_skbuff[i]) {
dma_unmap_single(hwdev,
rp->rx_skbuff_dma[i],
rp->rx_buf_sz, DMA_FROM_DEVICE);
dev_kfree_skb(rp->rx_skbuff[i]);
}
rp->rx_skbuff[i] = NULL;
}
}
static void alloc_tbufs(struct net_device* dev)
{
struct rhine_private *rp = netdev_priv(dev);
dma_addr_t next;
int i;
rp->dirty_tx = rp->cur_tx = 0;
next = rp->tx_ring_dma;
for (i = 0; i < TX_RING_SIZE; i++) {
rp->tx_skbuff[i] = NULL;
rp->tx_ring[i].tx_status = 0;
rp->tx_ring[i].desc_length = cpu_to_le32(TXDESC);
next += sizeof(struct tx_desc);
rp->tx_ring[i].next_desc = cpu_to_le32(next);
if (rp->quirks & rqRhineI)
rp->tx_buf[i] = &rp->tx_bufs[i * PKT_BUF_SZ];
}
rp->tx_ring[i-1].next_desc = cpu_to_le32(rp->tx_ring_dma);
}
static void free_tbufs(struct net_device* dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
int i;
for (i = 0; i < TX_RING_SIZE; i++) {
rp->tx_ring[i].tx_status = 0;
rp->tx_ring[i].desc_length = cpu_to_le32(TXDESC);
rp->tx_ring[i].addr = cpu_to_le32(0xBADF00D0);
if (rp->tx_skbuff[i]) {
if (rp->tx_skbuff_dma[i]) {
dma_unmap_single(hwdev,
rp->tx_skbuff_dma[i],
rp->tx_skbuff[i]->len,
DMA_TO_DEVICE);
}
dev_kfree_skb(rp->tx_skbuff[i]);
}
rp->tx_skbuff[i] = NULL;
rp->tx_buf[i] = NULL;
}
}
static void rhine_check_media(struct net_device *dev, unsigned int init_media)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
mii_check_media(&rp->mii_if, netif_msg_link(rp), init_media);
if (rp->mii_if.full_duplex)
iowrite8(ioread8(ioaddr + ChipCmd1) | Cmd1FDuplex,
ioaddr + ChipCmd1);
else
iowrite8(ioread8(ioaddr + ChipCmd1) & ~Cmd1FDuplex,
ioaddr + ChipCmd1);
netif_info(rp, link, dev, "force_media %d, carrier %d\n",
rp->mii_if.force_media, netif_carrier_ok(dev));
}
static void rhine_set_carrier(struct mii_if_info *mii)
{
struct net_device *dev = mii->dev;
struct rhine_private *rp = netdev_priv(dev);
if (mii->force_media) {
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
}
rhine_check_media(dev, 0);
netif_info(rp, link, dev, "force_media %d, carrier %d\n",
mii->force_media, netif_carrier_ok(dev));
}
static void rhine_set_cam(void __iomem *ioaddr, int idx, u8 *addr)
{
int i;
iowrite8(CAMC_CAMEN, ioaddr + CamCon);
wmb();
idx &= (MCAM_SIZE - 1);
iowrite8((u8) idx, ioaddr + CamAddr);
for (i = 0; i < 6; i++, addr++)
iowrite8(*addr, ioaddr + MulticastFilter0 + i);
udelay(10);
wmb();
iowrite8(CAMC_CAMWR | CAMC_CAMEN, ioaddr + CamCon);
udelay(10);
iowrite8(0, ioaddr + CamCon);
}
static void rhine_set_vlan_cam(void __iomem *ioaddr, int idx, u8 *addr)
{
iowrite8(CAMC_CAMEN | CAMC_VCAMSL, ioaddr + CamCon);
wmb();
idx &= (VCAM_SIZE - 1);
iowrite8((u8) idx, ioaddr + CamAddr);
iowrite16(*((u16 *) addr), ioaddr + MulticastFilter0 + 6);
udelay(10);
wmb();
iowrite8(CAMC_CAMWR | CAMC_CAMEN, ioaddr + CamCon);
udelay(10);
iowrite8(0, ioaddr + CamCon);
}
static void rhine_set_cam_mask(void __iomem *ioaddr, u32 mask)
{
iowrite8(CAMC_CAMEN, ioaddr + CamCon);
wmb();
iowrite32(mask, ioaddr + CamMask);
iowrite8(0, ioaddr + CamCon);
}
static void rhine_set_vlan_cam_mask(void __iomem *ioaddr, u32 mask)
{
iowrite8(CAMC_CAMEN | CAMC_VCAMSL, ioaddr + CamCon);
wmb();
iowrite32(mask, ioaddr + CamMask);
iowrite8(0, ioaddr + CamCon);
}
static void rhine_init_cam_filter(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
rhine_set_vlan_cam_mask(ioaddr, 0);
rhine_set_cam_mask(ioaddr, 0);
BYTE_REG_BITS_ON(TCR_PQEN, ioaddr + TxConfig);
BYTE_REG_BITS_OFF(BCR1_VIDFR, ioaddr + PCIBusConfig1);
}
static void rhine_update_vcam(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
u16 vid;
u32 vCAMmask = 0;
unsigned int i = 0;
for_each_set_bit(vid, rp->active_vlans, VLAN_N_VID) {
rhine_set_vlan_cam(ioaddr, i, (u8 *)&vid);
vCAMmask |= 1 << i;
if (++i >= VCAM_SIZE)
break;
}
rhine_set_vlan_cam_mask(ioaddr, vCAMmask);
}
static int rhine_vlan_rx_add_vid(struct net_device *dev, __be16 proto, u16 vid)
{
struct rhine_private *rp = netdev_priv(dev);
spin_lock_bh(&rp->lock);
set_bit(vid, rp->active_vlans);
rhine_update_vcam(dev);
spin_unlock_bh(&rp->lock);
return 0;
}
static int rhine_vlan_rx_kill_vid(struct net_device *dev, __be16 proto, u16 vid)
{
struct rhine_private *rp = netdev_priv(dev);
spin_lock_bh(&rp->lock);
clear_bit(vid, rp->active_vlans);
rhine_update_vcam(dev);
spin_unlock_bh(&rp->lock);
return 0;
}
static void init_registers(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
int i;
for (i = 0; i < 6; i++)
iowrite8(dev->dev_addr[i], ioaddr + StationAddr + i);
iowrite16(0x0006, ioaddr + PCIBusConfig);
iowrite8(0x20, ioaddr + TxConfig);
rp->tx_thresh = 0x20;
rp->rx_thresh = 0x60;
iowrite32(rp->rx_ring_dma, ioaddr + RxRingPtr);
iowrite32(rp->tx_ring_dma, ioaddr + TxRingPtr);
rhine_set_rx_mode(dev);
if (rp->quirks & rqMgmt)
rhine_init_cam_filter(dev);
napi_enable(&rp->napi);
iowrite16(RHINE_EVENT & 0xffff, ioaddr + IntrEnable);
iowrite16(CmdStart | CmdTxOn | CmdRxOn | (Cmd1NoTxPoll << 8),
ioaddr + ChipCmd);
rhine_check_media(dev, 1);
}
static void rhine_enable_linkmon(struct rhine_private *rp)
{
void __iomem *ioaddr = rp->base;
iowrite8(0, ioaddr + MIICmd);
iowrite8(MII_BMSR, ioaddr + MIIRegAddr);
iowrite8(0x80, ioaddr + MIICmd);
rhine_wait_bit_high(rp, MIIRegAddr, 0x20);
iowrite8(MII_BMSR | 0x40, ioaddr + MIIRegAddr);
}
static void rhine_disable_linkmon(struct rhine_private *rp)
{
void __iomem *ioaddr = rp->base;
iowrite8(0, ioaddr + MIICmd);
if (rp->quirks & rqRhineI) {
iowrite8(0x01, ioaddr + MIIRegAddr);
mdelay(1);
iowrite8(0x80, ioaddr + MIICmd);
rhine_wait_bit_high(rp, MIIRegAddr, 0x20);
iowrite8(0, ioaddr + MIICmd);
}
else
rhine_wait_bit_high(rp, MIIRegAddr, 0x80);
}
static int mdio_read(struct net_device *dev, int phy_id, int regnum)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
int result;
rhine_disable_linkmon(rp);
iowrite8(phy_id, ioaddr + MIIPhyAddr);
iowrite8(regnum, ioaddr + MIIRegAddr);
iowrite8(0x40, ioaddr + MIICmd);
rhine_wait_bit_low(rp, MIICmd, 0x40);
result = ioread16(ioaddr + MIIData);
rhine_enable_linkmon(rp);
return result;
}
static void mdio_write(struct net_device *dev, int phy_id, int regnum, int value)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
rhine_disable_linkmon(rp);
iowrite8(phy_id, ioaddr + MIIPhyAddr);
iowrite8(regnum, ioaddr + MIIRegAddr);
iowrite16(value, ioaddr + MIIData);
iowrite8(0x20, ioaddr + MIICmd);
rhine_wait_bit_low(rp, MIICmd, 0x20);
rhine_enable_linkmon(rp);
}
static void rhine_task_disable(struct rhine_private *rp)
{
mutex_lock(&rp->task_lock);
rp->task_enable = false;
mutex_unlock(&rp->task_lock);
cancel_work_sync(&rp->slow_event_task);
cancel_work_sync(&rp->reset_task);
}
static void rhine_task_enable(struct rhine_private *rp)
{
mutex_lock(&rp->task_lock);
rp->task_enable = true;
mutex_unlock(&rp->task_lock);
}
static int rhine_open(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
int rc;
rc = request_irq(rp->irq, rhine_interrupt, IRQF_SHARED, dev->name, dev);
if (rc)
return rc;
netif_dbg(rp, ifup, dev, "%s() irq %d\n", __func__, rp->irq);
rc = alloc_ring(dev);
if (rc) {
free_irq(rp->irq, dev);
return rc;
}
alloc_rbufs(dev);
alloc_tbufs(dev);
rhine_chip_reset(dev);
rhine_task_enable(rp);
init_registers(dev);
netif_dbg(rp, ifup, dev, "%s() Done - status %04x MII status: %04x\n",
__func__, ioread16(ioaddr + ChipCmd),
mdio_read(dev, rp->mii_if.phy_id, MII_BMSR));
netif_start_queue(dev);
return 0;
}
static void rhine_reset_task(struct work_struct *work)
{
struct rhine_private *rp = container_of(work, struct rhine_private,
reset_task);
struct net_device *dev = rp->dev;
mutex_lock(&rp->task_lock);
if (!rp->task_enable)
goto out_unlock;
napi_disable(&rp->napi);
netif_tx_disable(dev);
spin_lock_bh(&rp->lock);
free_tbufs(dev);
free_rbufs(dev);
alloc_tbufs(dev);
alloc_rbufs(dev);
rhine_chip_reset(dev);
init_registers(dev);
spin_unlock_bh(&rp->lock);
dev->trans_start = jiffies;
dev->stats.tx_errors++;
netif_wake_queue(dev);
out_unlock:
mutex_unlock(&rp->task_lock);
}
static void rhine_tx_timeout(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
netdev_warn(dev, "Transmit timed out, status %04x, PHY status %04x, resetting...\n",
ioread16(ioaddr + IntrStatus),
mdio_read(dev, rp->mii_if.phy_id, MII_BMSR));
schedule_work(&rp->reset_task);
}
static netdev_tx_t rhine_start_tx(struct sk_buff *skb,
struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
void __iomem *ioaddr = rp->base;
unsigned entry;
entry = rp->cur_tx % TX_RING_SIZE;
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
rp->tx_skbuff[entry] = skb;
if ((rp->quirks & rqRhineI) &&
(((unsigned long)skb->data & 3) || skb_shinfo(skb)->nr_frags != 0 || skb->ip_summed == CHECKSUM_PARTIAL)) {
if (skb->len > PKT_BUF_SZ) {
dev_kfree_skb_any(skb);
rp->tx_skbuff[entry] = NULL;
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
skb_copy_and_csum_dev(skb, rp->tx_buf[entry]);
if (skb->len < ETH_ZLEN)
memset(rp->tx_buf[entry] + skb->len, 0,
ETH_ZLEN - skb->len);
rp->tx_skbuff_dma[entry] = 0;
rp->tx_ring[entry].addr = cpu_to_le32(rp->tx_bufs_dma +
(rp->tx_buf[entry] -
rp->tx_bufs));
} else {
rp->tx_skbuff_dma[entry] =
dma_map_single(hwdev, skb->data, skb->len,
DMA_TO_DEVICE);
if (dma_mapping_error(hwdev, rp->tx_skbuff_dma[entry])) {
dev_kfree_skb_any(skb);
rp->tx_skbuff_dma[entry] = 0;
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
rp->tx_ring[entry].addr = cpu_to_le32(rp->tx_skbuff_dma[entry]);
}
rp->tx_ring[entry].desc_length =
cpu_to_le32(TXDESC | (skb->len >= ETH_ZLEN ? skb->len : ETH_ZLEN));
if (unlikely(vlan_tx_tag_present(skb))) {
u16 vid_pcp = vlan_tx_tag_get(skb);
vid_pcp = (vid_pcp & VLAN_VID_MASK) |
((vid_pcp & VLAN_PRIO_MASK) >> 1);
rp->tx_ring[entry].tx_status = cpu_to_le32((vid_pcp) << 16);
rp->tx_ring[entry].desc_length |= cpu_to_le32(0x020000);
}
else
rp->tx_ring[entry].tx_status = 0;
wmb();
rp->tx_ring[entry].tx_status |= cpu_to_le32(DescOwn);
wmb();
rp->cur_tx++;
if (vlan_tx_tag_present(skb))
BYTE_REG_BITS_ON(1 << 7, ioaddr + TQWake);
iowrite8(ioread8(ioaddr + ChipCmd1) | Cmd1TxDemand,
ioaddr + ChipCmd1);
IOSYNC;
if (rp->cur_tx == rp->dirty_tx + TX_QUEUE_LEN)
netif_stop_queue(dev);
netif_dbg(rp, tx_queued, dev, "Transmit frame #%d queued in slot %d\n",
rp->cur_tx - 1, entry);
return NETDEV_TX_OK;
}
static void rhine_irq_disable(struct rhine_private *rp)
{
iowrite16(0x0000, rp->base + IntrEnable);
mmiowb();
}
static irqreturn_t rhine_interrupt(int irq, void *dev_instance)
{
struct net_device *dev = dev_instance;
struct rhine_private *rp = netdev_priv(dev);
u32 status;
int handled = 0;
status = rhine_get_events(rp);
netif_dbg(rp, intr, dev, "Interrupt, status %08x\n", status);
if (status & RHINE_EVENT) {
handled = 1;
rhine_irq_disable(rp);
napi_schedule(&rp->napi);
}
if (status & ~(IntrLinkChange | IntrStatsMax | RHINE_EVENT_NAPI)) {
netif_err(rp, intr, dev, "Something Wicked happened! %08x\n",
status);
}
return IRQ_RETVAL(handled);
}
static void rhine_tx(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
int txstatus = 0, entry = rp->dirty_tx % TX_RING_SIZE;
while (rp->dirty_tx != rp->cur_tx) {
txstatus = le32_to_cpu(rp->tx_ring[entry].tx_status);
netif_dbg(rp, tx_done, dev, "Tx scavenge %d status %08x\n",
entry, txstatus);
if (txstatus & DescOwn)
break;
if (txstatus & 0x8000) {
netif_dbg(rp, tx_done, dev,
"Transmit error, Tx status %08x\n", txstatus);
dev->stats.tx_errors++;
if (txstatus & 0x0400)
dev->stats.tx_carrier_errors++;
if (txstatus & 0x0200)
dev->stats.tx_window_errors++;
if (txstatus & 0x0100)
dev->stats.tx_aborted_errors++;
if (txstatus & 0x0080)
dev->stats.tx_heartbeat_errors++;
if (((rp->quirks & rqRhineI) && txstatus & 0x0002) ||
(txstatus & 0x0800) || (txstatus & 0x1000)) {
dev->stats.tx_fifo_errors++;
rp->tx_ring[entry].tx_status = cpu_to_le32(DescOwn);
break;
}
} else {
if (rp->quirks & rqRhineI)
dev->stats.collisions += (txstatus >> 3) & 0x0F;
else
dev->stats.collisions += txstatus & 0x0F;
netif_dbg(rp, tx_done, dev, "collisions: %1.1x:%1.1x\n",
(txstatus >> 3) & 0xF, txstatus & 0xF);
u64_stats_update_begin(&rp->tx_stats.syncp);
rp->tx_stats.bytes += rp->tx_skbuff[entry]->len;
rp->tx_stats.packets++;
u64_stats_update_end(&rp->tx_stats.syncp);
}
if (rp->tx_skbuff_dma[entry]) {
dma_unmap_single(hwdev,
rp->tx_skbuff_dma[entry],
rp->tx_skbuff[entry]->len,
DMA_TO_DEVICE);
}
dev_consume_skb_any(rp->tx_skbuff[entry]);
rp->tx_skbuff[entry] = NULL;
entry = (++rp->dirty_tx) % TX_RING_SIZE;
}
if ((rp->cur_tx - rp->dirty_tx) < TX_QUEUE_LEN - 4)
netif_wake_queue(dev);
}
static inline u16 rhine_get_vlan_tci(struct sk_buff *skb, int data_size)
{
u8 *trailer = (u8 *)skb->data + ((data_size + 3) & ~3) + 2;
return be16_to_cpup((__be16 *)trailer);
}
static int rhine_rx(struct net_device *dev, int limit)
{
struct rhine_private *rp = netdev_priv(dev);
struct device *hwdev = dev->dev.parent;
int count;
int entry = rp->cur_rx % RX_RING_SIZE;
netif_dbg(rp, rx_status, dev, "%s(), entry %d status %08x\n", __func__,
entry, le32_to_cpu(rp->rx_head_desc->rx_status));
for (count = 0; count < limit; ++count) {
struct rx_desc *desc = rp->rx_head_desc;
u32 desc_status = le32_to_cpu(desc->rx_status);
u32 desc_length = le32_to_cpu(desc->desc_length);
int data_size = desc_status >> 16;
if (desc_status & DescOwn)
break;
netif_dbg(rp, rx_status, dev, "%s() status %08x\n", __func__,
desc_status);
if ((desc_status & (RxWholePkt | RxErr)) != RxWholePkt) {
if ((desc_status & RxWholePkt) != RxWholePkt) {
netdev_warn(dev,
"Oversized Ethernet frame spanned multiple buffers, "
"entry %#x length %d status %08x!\n",
entry, data_size,
desc_status);
netdev_warn(dev,
"Oversized Ethernet frame %p vs %p\n",
rp->rx_head_desc,
&rp->rx_ring[entry]);
dev->stats.rx_length_errors++;
} else if (desc_status & RxErr) {
netif_dbg(rp, rx_err, dev,
"%s() Rx error %08x\n", __func__,
desc_status);
dev->stats.rx_errors++;
if (desc_status & 0x0030)
dev->stats.rx_length_errors++;
if (desc_status & 0x0048)
dev->stats.rx_fifo_errors++;
if (desc_status & 0x0004)
dev->stats.rx_frame_errors++;
if (desc_status & 0x0002) {
spin_lock(&rp->lock);
dev->stats.rx_crc_errors++;
spin_unlock(&rp->lock);
}
}
} else {
struct sk_buff *skb = NULL;
int pkt_len = data_size - 4;
u16 vlan_tci = 0;
if (pkt_len < rx_copybreak)
skb = netdev_alloc_skb_ip_align(dev, pkt_len);
if (skb) {
dma_sync_single_for_cpu(hwdev,
rp->rx_skbuff_dma[entry],
rp->rx_buf_sz,
DMA_FROM_DEVICE);
skb_copy_to_linear_data(skb,
rp->rx_skbuff[entry]->data,
pkt_len);
skb_put(skb, pkt_len);
dma_sync_single_for_device(hwdev,
rp->rx_skbuff_dma[entry],
rp->rx_buf_sz,
DMA_FROM_DEVICE);
} else {
skb = rp->rx_skbuff[entry];
if (skb == NULL) {
netdev_err(dev, "Inconsistent Rx descriptor chain\n");
break;
}
rp->rx_skbuff[entry] = NULL;
skb_put(skb, pkt_len);
dma_unmap_single(hwdev,
rp->rx_skbuff_dma[entry],
rp->rx_buf_sz,
DMA_FROM_DEVICE);
}
if (unlikely(desc_length & DescTag))
vlan_tci = rhine_get_vlan_tci(skb, data_size);
skb->protocol = eth_type_trans(skb, dev);
if (unlikely(desc_length & DescTag))
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vlan_tci);
netif_receive_skb(skb);
u64_stats_update_begin(&rp->rx_stats.syncp);
rp->rx_stats.bytes += pkt_len;
rp->rx_stats.packets++;
u64_stats_update_end(&rp->rx_stats.syncp);
}
entry = (++rp->cur_rx) % RX_RING_SIZE;
rp->rx_head_desc = &rp->rx_ring[entry];
}
for (; rp->cur_rx - rp->dirty_rx > 0; rp->dirty_rx++) {
struct sk_buff *skb;
entry = rp->dirty_rx % RX_RING_SIZE;
if (rp->rx_skbuff[entry] == NULL) {
skb = netdev_alloc_skb(dev, rp->rx_buf_sz);
rp->rx_skbuff[entry] = skb;
if (skb == NULL)
break;
rp->rx_skbuff_dma[entry] =
dma_map_single(hwdev, skb->data,
rp->rx_buf_sz,
DMA_FROM_DEVICE);
if (dma_mapping_error(hwdev,
rp->rx_skbuff_dma[entry])) {
dev_kfree_skb(skb);
rp->rx_skbuff_dma[entry] = 0;
break;
}
rp->rx_ring[entry].addr = cpu_to_le32(rp->rx_skbuff_dma[entry]);
}
rp->rx_ring[entry].rx_status = cpu_to_le32(DescOwn);
}
return count;
}
static void rhine_restart_tx(struct net_device *dev) {
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
int entry = rp->dirty_tx % TX_RING_SIZE;
u32 intr_status;
intr_status = rhine_get_events(rp);
if ((intr_status & IntrTxErrSummary) == 0) {
iowrite32(rp->tx_ring_dma + entry * sizeof(struct tx_desc),
ioaddr + TxRingPtr);
iowrite8(ioread8(ioaddr + ChipCmd) | CmdTxOn,
ioaddr + ChipCmd);
if (rp->tx_ring[entry].desc_length & cpu_to_le32(0x020000))
BYTE_REG_BITS_ON(1 << 7, ioaddr + TQWake);
iowrite8(ioread8(ioaddr + ChipCmd1) | Cmd1TxDemand,
ioaddr + ChipCmd1);
IOSYNC;
}
else {
netif_warn(rp, tx_err, dev, "another error occurred %08x\n",
intr_status);
}
}
static void rhine_slow_event_task(struct work_struct *work)
{
struct rhine_private *rp =
container_of(work, struct rhine_private, slow_event_task);
struct net_device *dev = rp->dev;
u32 intr_status;
mutex_lock(&rp->task_lock);
if (!rp->task_enable)
goto out_unlock;
intr_status = rhine_get_events(rp);
rhine_ack_events(rp, intr_status & RHINE_EVENT_SLOW);
if (intr_status & IntrLinkChange)
rhine_check_media(dev, 0);
if (intr_status & IntrPCIErr)
netif_warn(rp, hw, dev, "PCI error\n");
iowrite16(RHINE_EVENT & 0xffff, rp->base + IntrEnable);
out_unlock:
mutex_unlock(&rp->task_lock);
}
static struct rtnl_link_stats64 *
rhine_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *stats)
{
struct rhine_private *rp = netdev_priv(dev);
unsigned int start;
spin_lock_bh(&rp->lock);
rhine_update_rx_crc_and_missed_errord(rp);
spin_unlock_bh(&rp->lock);
netdev_stats_to_stats64(stats, &dev->stats);
do {
start = u64_stats_fetch_begin_irq(&rp->rx_stats.syncp);
stats->rx_packets = rp->rx_stats.packets;
stats->rx_bytes = rp->rx_stats.bytes;
} while (u64_stats_fetch_retry_irq(&rp->rx_stats.syncp, start));
do {
start = u64_stats_fetch_begin_irq(&rp->tx_stats.syncp);
stats->tx_packets = rp->tx_stats.packets;
stats->tx_bytes = rp->tx_stats.bytes;
} while (u64_stats_fetch_retry_irq(&rp->tx_stats.syncp, start));
return stats;
}
static void rhine_set_rx_mode(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
u32 mc_filter[2];
u8 rx_mode = 0x0C;
struct netdev_hw_addr *ha;
if (dev->flags & IFF_PROMISC) {
rx_mode = 0x1C;
iowrite32(0xffffffff, ioaddr + MulticastFilter0);
iowrite32(0xffffffff, ioaddr + MulticastFilter1);
} else if ((netdev_mc_count(dev) > multicast_filter_limit) ||
(dev->flags & IFF_ALLMULTI)) {
iowrite32(0xffffffff, ioaddr + MulticastFilter0);
iowrite32(0xffffffff, ioaddr + MulticastFilter1);
} else if (rp->quirks & rqMgmt) {
int i = 0;
u32 mCAMmask = 0;
netdev_for_each_mc_addr(ha, dev) {
if (i == MCAM_SIZE)
break;
rhine_set_cam(ioaddr, i, ha->addr);
mCAMmask |= 1 << i;
i++;
}
rhine_set_cam_mask(ioaddr, mCAMmask);
} else {
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = ether_crc(ETH_ALEN, ha->addr) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
iowrite32(mc_filter[0], ioaddr + MulticastFilter0);
iowrite32(mc_filter[1], ioaddr + MulticastFilter1);
}
if (rp->quirks & rqMgmt) {
if (dev->flags & IFF_PROMISC)
BYTE_REG_BITS_OFF(BCR1_VIDFR, ioaddr + PCIBusConfig1);
else
BYTE_REG_BITS_ON(BCR1_VIDFR, ioaddr + PCIBusConfig1);
}
BYTE_REG_BITS_ON(rx_mode, ioaddr + RxConfig);
}
static void netdev_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct device *hwdev = dev->dev.parent;
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, dev_name(hwdev), sizeof(info->bus_info));
}
static int netdev_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rhine_private *rp = netdev_priv(dev);
int rc;
mutex_lock(&rp->task_lock);
rc = mii_ethtool_gset(&rp->mii_if, cmd);
mutex_unlock(&rp->task_lock);
return rc;
}
static int netdev_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct rhine_private *rp = netdev_priv(dev);
int rc;
mutex_lock(&rp->task_lock);
rc = mii_ethtool_sset(&rp->mii_if, cmd);
rhine_set_carrier(&rp->mii_if);
mutex_unlock(&rp->task_lock);
return rc;
}
static int netdev_nway_reset(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
return mii_nway_restart(&rp->mii_if);
}
static u32 netdev_get_link(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
return mii_link_ok(&rp->mii_if);
}
static u32 netdev_get_msglevel(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
return rp->msg_enable;
}
static void netdev_set_msglevel(struct net_device *dev, u32 value)
{
struct rhine_private *rp = netdev_priv(dev);
rp->msg_enable = value;
}
static void rhine_get_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rhine_private *rp = netdev_priv(dev);
if (!(rp->quirks & rqWOL))
return;
spin_lock_irq(&rp->lock);
wol->supported = WAKE_PHY | WAKE_MAGIC |
WAKE_UCAST | WAKE_MCAST | WAKE_BCAST;
wol->wolopts = rp->wolopts;
spin_unlock_irq(&rp->lock);
}
static int rhine_set_wol(struct net_device *dev, struct ethtool_wolinfo *wol)
{
struct rhine_private *rp = netdev_priv(dev);
u32 support = WAKE_PHY | WAKE_MAGIC |
WAKE_UCAST | WAKE_MCAST | WAKE_BCAST;
if (!(rp->quirks & rqWOL))
return -EINVAL;
if (wol->wolopts & ~support)
return -EINVAL;
spin_lock_irq(&rp->lock);
rp->wolopts = wol->wolopts;
spin_unlock_irq(&rp->lock);
return 0;
}
static int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct rhine_private *rp = netdev_priv(dev);
int rc;
if (!netif_running(dev))
return -EINVAL;
mutex_lock(&rp->task_lock);
rc = generic_mii_ioctl(&rp->mii_if, if_mii(rq), cmd, NULL);
rhine_set_carrier(&rp->mii_if);
mutex_unlock(&rp->task_lock);
return rc;
}
static int rhine_close(struct net_device *dev)
{
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
rhine_task_disable(rp);
napi_disable(&rp->napi);
netif_stop_queue(dev);
netif_dbg(rp, ifdown, dev, "Shutting down ethercard, status was %04x\n",
ioread16(ioaddr + ChipCmd));
iowrite8(rp->tx_thresh | 0x02, ioaddr + TxConfig);
rhine_irq_disable(rp);
iowrite16(CmdStop, ioaddr + ChipCmd);
free_irq(rp->irq, dev);
free_rbufs(dev);
free_tbufs(dev);
free_ring(dev);
return 0;
}
static void rhine_remove_one_pci(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rhine_private *rp = netdev_priv(dev);
unregister_netdev(dev);
pci_iounmap(pdev, rp->base);
pci_release_regions(pdev);
free_netdev(dev);
pci_disable_device(pdev);
}
static int rhine_remove_one_platform(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct rhine_private *rp = netdev_priv(dev);
unregister_netdev(dev);
iounmap(rp->base);
free_netdev(dev);
return 0;
}
static void rhine_shutdown_pci(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct rhine_private *rp = netdev_priv(dev);
void __iomem *ioaddr = rp->base;
if (!(rp->quirks & rqWOL))
return;
rhine_power_init(dev);
if (rp->quirks & rq6patterns)
iowrite8(0x04, ioaddr + WOLcgClr);
spin_lock(&rp->lock);
if (rp->wolopts & WAKE_MAGIC) {
iowrite8(WOLmagic, ioaddr + WOLcrSet);
iowrite8(ioread8(ioaddr + ConfigA) | 0x03, ioaddr + ConfigA);
}
if (rp->wolopts & (WAKE_BCAST|WAKE_MCAST))
iowrite8(WOLbmcast, ioaddr + WOLcgSet);
if (rp->wolopts & WAKE_PHY)
iowrite8(WOLlnkon | WOLlnkoff, ioaddr + WOLcrSet);
if (rp->wolopts & WAKE_UCAST)
iowrite8(WOLucast, ioaddr + WOLcrSet);
if (rp->wolopts) {
iowrite8(0x01, ioaddr + PwcfgSet);
iowrite8(ioread8(ioaddr + StickyHW) | 0x04, ioaddr + StickyHW);
}
spin_unlock(&rp->lock);
if (system_state == SYSTEM_POWER_OFF && !avoid_D3) {
iowrite8(ioread8(ioaddr + StickyHW) | 0x03, ioaddr + StickyHW);
pci_wake_from_d3(pdev, true);
pci_set_power_state(pdev, PCI_D3hot);
}
}
static int rhine_suspend(struct device *device)
{
struct net_device *dev = dev_get_drvdata(device);
struct rhine_private *rp = netdev_priv(dev);
if (!netif_running(dev))
return 0;
rhine_task_disable(rp);
rhine_irq_disable(rp);
napi_disable(&rp->napi);
netif_device_detach(dev);
if (dev_is_pci(device))
rhine_shutdown_pci(to_pci_dev(device));
return 0;
}
static int rhine_resume(struct device *device)
{
struct net_device *dev = dev_get_drvdata(device);
struct rhine_private *rp = netdev_priv(dev);
if (!netif_running(dev))
return 0;
enable_mmio(rp->pioaddr, rp->quirks);
rhine_power_init(dev);
free_tbufs(dev);
free_rbufs(dev);
alloc_tbufs(dev);
alloc_rbufs(dev);
rhine_task_enable(rp);
spin_lock_bh(&rp->lock);
init_registers(dev);
spin_unlock_bh(&rp->lock);
netif_device_attach(dev);
return 0;
}
static int __init rhine_init(void)
{
int ret_pci, ret_platform;
#ifdef MODULE
pr_info("%s\n", version);
#endif
if (dmi_check_system(rhine_dmi_table)) {
avoid_D3 = true;
pr_warn("Broken BIOS detected, avoid_D3 enabled\n");
}
else if (avoid_D3)
pr_info("avoid_D3 set\n");
ret_pci = pci_register_driver(&rhine_driver_pci);
ret_platform = platform_driver_register(&rhine_driver_platform);
if ((ret_pci < 0) && (ret_platform < 0))
return ret_pci;
return 0;
}
static void __exit rhine_cleanup(void)
{
platform_driver_unregister(&rhine_driver_platform);
pci_unregister_driver(&rhine_driver_pci);
}
