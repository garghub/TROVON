static int r6040_phy_read(void __iomem *ioaddr, int phy_addr, int reg)
{
int limit = MAC_DEF_TIMEOUT;
u16 cmd;
iowrite16(MDIO_READ + reg + (phy_addr << 8), ioaddr + MMDIO);
while (limit--) {
cmd = ioread16(ioaddr + MMDIO);
if (!(cmd & MDIO_READ))
break;
}
return ioread16(ioaddr + MMRD);
}
static void r6040_phy_write(void __iomem *ioaddr,
int phy_addr, int reg, u16 val)
{
int limit = MAC_DEF_TIMEOUT;
u16 cmd;
iowrite16(val, ioaddr + MMWD);
iowrite16(MDIO_WRITE + reg + (phy_addr << 8), ioaddr + MMDIO);
while (limit--) {
cmd = ioread16(ioaddr + MMDIO);
if (!(cmd & MDIO_WRITE))
break;
}
}
static int r6040_mdiobus_read(struct mii_bus *bus, int phy_addr, int reg)
{
struct net_device *dev = bus->priv;
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
return r6040_phy_read(ioaddr, phy_addr, reg);
}
static int r6040_mdiobus_write(struct mii_bus *bus, int phy_addr,
int reg, u16 value)
{
struct net_device *dev = bus->priv;
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
r6040_phy_write(ioaddr, phy_addr, reg, value);
return 0;
}
static int r6040_mdiobus_reset(struct mii_bus *bus)
{
return 0;
}
static void r6040_free_txbufs(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
int i;
for (i = 0; i < TX_DCNT; i++) {
if (lp->tx_insert_ptr->skb_ptr) {
pci_unmap_single(lp->pdev,
le32_to_cpu(lp->tx_insert_ptr->buf),
MAX_BUF_SIZE, PCI_DMA_TODEVICE);
dev_kfree_skb(lp->tx_insert_ptr->skb_ptr);
lp->tx_insert_ptr->skb_ptr = NULL;
}
lp->tx_insert_ptr = lp->tx_insert_ptr->vndescp;
}
}
static void r6040_free_rxbufs(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
int i;
for (i = 0; i < RX_DCNT; i++) {
if (lp->rx_insert_ptr->skb_ptr) {
pci_unmap_single(lp->pdev,
le32_to_cpu(lp->rx_insert_ptr->buf),
MAX_BUF_SIZE, PCI_DMA_FROMDEVICE);
dev_kfree_skb(lp->rx_insert_ptr->skb_ptr);
lp->rx_insert_ptr->skb_ptr = NULL;
}
lp->rx_insert_ptr = lp->rx_insert_ptr->vndescp;
}
}
static void r6040_init_ring_desc(struct r6040_descriptor *desc_ring,
dma_addr_t desc_dma, int size)
{
struct r6040_descriptor *desc = desc_ring;
dma_addr_t mapping = desc_dma;
while (size-- > 0) {
mapping += sizeof(*desc);
desc->ndesc = cpu_to_le32(mapping);
desc->vndescp = desc + 1;
desc++;
}
desc--;
desc->ndesc = cpu_to_le32(desc_dma);
desc->vndescp = desc_ring;
}
static void r6040_init_txbufs(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
lp->tx_free_desc = TX_DCNT;
lp->tx_remove_ptr = lp->tx_insert_ptr = lp->tx_ring;
r6040_init_ring_desc(lp->tx_ring, lp->tx_ring_dma, TX_DCNT);
}
static int r6040_alloc_rxbufs(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
struct r6040_descriptor *desc;
struct sk_buff *skb;
int rc;
lp->rx_remove_ptr = lp->rx_insert_ptr = lp->rx_ring;
r6040_init_ring_desc(lp->rx_ring, lp->rx_ring_dma, RX_DCNT);
desc = lp->rx_ring;
do {
skb = netdev_alloc_skb(dev, MAX_BUF_SIZE);
if (!skb) {
netdev_err(dev, "failed to alloc skb for rx\n");
rc = -ENOMEM;
goto err_exit;
}
desc->skb_ptr = skb;
desc->buf = cpu_to_le32(pci_map_single(lp->pdev,
desc->skb_ptr->data,
MAX_BUF_SIZE, PCI_DMA_FROMDEVICE));
desc->status = DSC_OWNER_MAC;
desc = desc->vndescp;
} while (desc != lp->rx_ring);
return 0;
err_exit:
r6040_free_rxbufs(dev);
return rc;
}
static void r6040_reset_mac(struct r6040_private *lp)
{
void __iomem *ioaddr = lp->base;
int limit = MAC_DEF_TIMEOUT;
u16 cmd;
iowrite16(MAC_RST, ioaddr + MCR1);
while (limit--) {
cmd = ioread16(ioaddr + MCR1);
if (cmd & MAC_RST)
break;
}
iowrite16(MAC_SM_RST, ioaddr + MAC_SM);
iowrite16(0, ioaddr + MAC_SM);
mdelay(5);
}
static void r6040_init_mac_regs(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
iowrite16(MSK_INT, ioaddr + MIER);
r6040_reset_mac(lp);
iowrite16(MBCR_DEFAULT, ioaddr + MBCR);
iowrite16(MAX_BUF_SIZE, ioaddr + MR_BSR);
iowrite16(lp->tx_ring_dma, ioaddr + MTD_SA0);
iowrite16(lp->tx_ring_dma >> 16, ioaddr + MTD_SA1);
iowrite16(lp->rx_ring_dma, ioaddr + MRD_SA0);
iowrite16(lp->rx_ring_dma >> 16, ioaddr + MRD_SA1);
iowrite16(0, ioaddr + MT_ICR);
iowrite16(0, ioaddr + MR_ICR);
iowrite16(INT_MASK, ioaddr + MIER);
iowrite16(lp->mcr0 | MCR0_RCVEN, ioaddr);
iowrite16(TM2TX, ioaddr + MTPR);
}
static void r6040_tx_timeout(struct net_device *dev)
{
struct r6040_private *priv = netdev_priv(dev);
void __iomem *ioaddr = priv->base;
netdev_warn(dev, "transmit timed out, int enable %4.4x "
"status %4.4x\n",
ioread16(ioaddr + MIER),
ioread16(ioaddr + MISR));
dev->stats.tx_errors++;
r6040_init_mac_regs(dev);
}
static struct net_device_stats *r6040_get_stats(struct net_device *dev)
{
struct r6040_private *priv = netdev_priv(dev);
void __iomem *ioaddr = priv->base;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
dev->stats.rx_crc_errors += ioread8(ioaddr + ME_CNT1);
dev->stats.multicast += ioread8(ioaddr + ME_CNT0);
spin_unlock_irqrestore(&priv->lock, flags);
return &dev->stats;
}
static void r6040_down(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
u16 *adrp;
iowrite16(MSK_INT, ioaddr + MIER);
r6040_reset_mac(lp);
adrp = (u16 *) dev->dev_addr;
iowrite16(adrp[0], ioaddr + MID_0L);
iowrite16(adrp[1], ioaddr + MID_0M);
iowrite16(adrp[2], ioaddr + MID_0H);
phy_stop(lp->phydev);
}
static int r6040_close(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
struct pci_dev *pdev = lp->pdev;
spin_lock_irq(&lp->lock);
napi_disable(&lp->napi);
netif_stop_queue(dev);
r6040_down(dev);
free_irq(dev->irq, dev);
r6040_free_rxbufs(dev);
r6040_free_txbufs(dev);
spin_unlock_irq(&lp->lock);
if (lp->rx_ring) {
pci_free_consistent(pdev,
RX_DESC_SIZE, lp->rx_ring, lp->rx_ring_dma);
lp->rx_ring = NULL;
}
if (lp->tx_ring) {
pci_free_consistent(pdev,
TX_DESC_SIZE, lp->tx_ring, lp->tx_ring_dma);
lp->tx_ring = NULL;
}
return 0;
}
static int r6040_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct r6040_private *lp = netdev_priv(dev);
if (!lp->phydev)
return -EINVAL;
return phy_mii_ioctl(lp->phydev, rq, cmd);
}
static int r6040_rx(struct net_device *dev, int limit)
{
struct r6040_private *priv = netdev_priv(dev);
struct r6040_descriptor *descptr = priv->rx_remove_ptr;
struct sk_buff *skb_ptr, *new_skb;
int count = 0;
u16 err;
while (count < limit && !(descptr->status & DSC_OWNER_MAC)) {
err = descptr->status;
if (err & DSC_RX_ERR) {
if (err & DSC_RX_ERR_DRI)
dev->stats.rx_frame_errors++;
if (err & DSC_RX_ERR_BUF)
dev->stats.rx_length_errors++;
if (err & DSC_RX_ERR_LONG)
dev->stats.rx_length_errors++;
if (err & DSC_RX_ERR_RUNT)
dev->stats.rx_length_errors++;
if (err & DSC_RX_ERR_CRC) {
spin_lock(&priv->lock);
dev->stats.rx_crc_errors++;
spin_unlock(&priv->lock);
}
goto next_descr;
}
new_skb = netdev_alloc_skb(dev, MAX_BUF_SIZE);
if (!new_skb) {
dev->stats.rx_dropped++;
goto next_descr;
}
skb_ptr = descptr->skb_ptr;
skb_ptr->dev = priv->dev;
skb_put(skb_ptr, descptr->len - 4);
pci_unmap_single(priv->pdev, le32_to_cpu(descptr->buf),
MAX_BUF_SIZE, PCI_DMA_FROMDEVICE);
skb_ptr->protocol = eth_type_trans(skb_ptr, priv->dev);
netif_receive_skb(skb_ptr);
dev->stats.rx_packets++;
dev->stats.rx_bytes += descptr->len - 4;
descptr->skb_ptr = new_skb;
descptr->buf = cpu_to_le32(pci_map_single(priv->pdev,
descptr->skb_ptr->data,
MAX_BUF_SIZE, PCI_DMA_FROMDEVICE));
next_descr:
descptr->status = DSC_OWNER_MAC;
descptr = descptr->vndescp;
count++;
}
priv->rx_remove_ptr = descptr;
return count;
}
static void r6040_tx(struct net_device *dev)
{
struct r6040_private *priv = netdev_priv(dev);
struct r6040_descriptor *descptr;
void __iomem *ioaddr = priv->base;
struct sk_buff *skb_ptr;
u16 err;
spin_lock(&priv->lock);
descptr = priv->tx_remove_ptr;
while (priv->tx_free_desc < TX_DCNT) {
err = ioread16(ioaddr + MLSR);
if (err & TX_FIFO_UNDR)
dev->stats.tx_fifo_errors++;
if (err & (TX_EXCEEDC | TX_LATEC))
dev->stats.tx_carrier_errors++;
if (descptr->status & DSC_OWNER_MAC)
break;
skb_ptr = descptr->skb_ptr;
pci_unmap_single(priv->pdev, le32_to_cpu(descptr->buf),
skb_ptr->len, PCI_DMA_TODEVICE);
dev_kfree_skb_irq(skb_ptr);
descptr->skb_ptr = NULL;
descptr = descptr->vndescp;
priv->tx_free_desc++;
}
priv->tx_remove_ptr = descptr;
if (priv->tx_free_desc)
netif_wake_queue(dev);
spin_unlock(&priv->lock);
}
static int r6040_poll(struct napi_struct *napi, int budget)
{
struct r6040_private *priv =
container_of(napi, struct r6040_private, napi);
struct net_device *dev = priv->dev;
void __iomem *ioaddr = priv->base;
int work_done;
work_done = r6040_rx(dev, budget);
if (work_done < budget) {
napi_complete(napi);
iowrite16(ioread16(ioaddr + MIER) | RX_INTS, ioaddr + MIER);
}
return work_done;
}
static irqreturn_t r6040_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
u16 misr, status;
misr = ioread16(ioaddr + MIER);
iowrite16(MSK_INT, ioaddr + MIER);
status = ioread16(ioaddr + MISR);
if (status == 0x0000 || status == 0xffff) {
iowrite16(misr, ioaddr + MIER);
return IRQ_NONE;
}
if (status & RX_INTS) {
if (status & RX_NO_DESC) {
dev->stats.rx_dropped++;
dev->stats.rx_missed_errors++;
}
if (status & RX_FIFO_FULL)
dev->stats.rx_fifo_errors++;
if (likely(napi_schedule_prep(&lp->napi))) {
misr &= ~RX_INTS;
__napi_schedule(&lp->napi);
}
}
if (status & TX_INTS)
r6040_tx(dev);
iowrite16(misr, ioaddr + MIER);
return IRQ_HANDLED;
}
static void r6040_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
r6040_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static int r6040_up(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
int ret;
r6040_init_txbufs(dev);
ret = r6040_alloc_rxbufs(dev);
if (ret)
return ret;
r6040_phy_write(ioaddr, 30, 17,
(r6040_phy_read(ioaddr, 30, 17) | 0x4000));
r6040_phy_write(ioaddr, 30, 17,
~((~r6040_phy_read(ioaddr, 30, 17)) | 0x2000));
r6040_phy_write(ioaddr, 0, 19, 0x0000);
r6040_phy_write(ioaddr, 0, 30, 0x01F0);
r6040_init_mac_regs(dev);
phy_start(lp->phydev);
return 0;
}
static void r6040_mac_address(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
u16 *adrp;
r6040_reset_mac(lp);
adrp = (u16 *) dev->dev_addr;
iowrite16(adrp[0], ioaddr + MID_0L);
iowrite16(adrp[1], ioaddr + MID_0M);
iowrite16(adrp[2], ioaddr + MID_0H);
}
static int r6040_open(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
int ret;
ret = request_irq(dev->irq, r6040_interrupt,
IRQF_SHARED, dev->name, dev);
if (ret)
goto out;
r6040_mac_address(dev);
lp->rx_ring =
pci_alloc_consistent(lp->pdev, RX_DESC_SIZE, &lp->rx_ring_dma);
if (!lp->rx_ring) {
ret = -ENOMEM;
goto err_free_irq;
}
lp->tx_ring =
pci_alloc_consistent(lp->pdev, TX_DESC_SIZE, &lp->tx_ring_dma);
if (!lp->tx_ring) {
ret = -ENOMEM;
goto err_free_rx_ring;
}
ret = r6040_up(dev);
if (ret)
goto err_free_tx_ring;
napi_enable(&lp->napi);
netif_start_queue(dev);
return 0;
err_free_tx_ring:
pci_free_consistent(lp->pdev, TX_DESC_SIZE, lp->tx_ring,
lp->tx_ring_dma);
err_free_rx_ring:
pci_free_consistent(lp->pdev, RX_DESC_SIZE, lp->rx_ring,
lp->rx_ring_dma);
err_free_irq:
free_irq(dev->irq, dev);
out:
return ret;
}
static netdev_tx_t r6040_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
struct r6040_descriptor *descptr;
void __iomem *ioaddr = lp->base;
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
if (!lp->tx_free_desc) {
spin_unlock_irqrestore(&lp->lock, flags);
netif_stop_queue(dev);
netdev_err(dev, ": no tx descriptor\n");
return NETDEV_TX_BUSY;
}
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
lp->tx_free_desc--;
descptr = lp->tx_insert_ptr;
if (skb->len < MISR)
descptr->len = MISR;
else
descptr->len = skb->len;
descptr->skb_ptr = skb;
descptr->buf = cpu_to_le32(pci_map_single(lp->pdev,
skb->data, skb->len, PCI_DMA_TODEVICE));
descptr->status = DSC_OWNER_MAC;
skb_tx_timestamp(skb);
iowrite16(TM2TX, ioaddr + MTPR);
lp->tx_insert_ptr = descptr->vndescp;
if (!lp->tx_free_desc)
netif_stop_queue(dev);
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_OK;
}
static void r6040_multicast_list(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
void __iomem *ioaddr = lp->base;
unsigned long flags;
struct netdev_hw_addr *ha;
int i;
u16 *adrp;
u16 hash_table[4] = { 0 };
spin_lock_irqsave(&lp->lock, flags);
adrp = (u16 *)dev->dev_addr;
iowrite16(adrp[0], ioaddr + MID_0L);
iowrite16(adrp[1], ioaddr + MID_0M);
iowrite16(adrp[2], ioaddr + MID_0H);
lp->mcr0 = ioread16(ioaddr + MCR0) & ~(MCR0_PROMISC | MCR0_HASH_EN);
if (dev->flags & IFF_PROMISC)
lp->mcr0 |= MCR0_PROMISC;
else if (dev->flags & IFF_ALLMULTI) {
lp->mcr0 |= MCR0_HASH_EN;
for (i = 0; i < MCAST_MAX ; i++) {
iowrite16(0, ioaddr + MID_1L + 8 * i);
iowrite16(0, ioaddr + MID_1M + 8 * i);
iowrite16(0, ioaddr + MID_1H + 8 * i);
}
for (i = 0; i < 4; i++)
hash_table[i] = 0xffff;
}
else if (netdev_mc_count(dev) <= MCAST_MAX) {
i = 0;
netdev_for_each_mc_addr(ha, dev) {
u16 *adrp = (u16 *) ha->addr;
iowrite16(adrp[0], ioaddr + MID_1L + 8 * i);
iowrite16(adrp[1], ioaddr + MID_1M + 8 * i);
iowrite16(adrp[2], ioaddr + MID_1H + 8 * i);
i++;
}
while (i < MCAST_MAX) {
iowrite16(0, ioaddr + MID_1L + 8 * i);
iowrite16(0, ioaddr + MID_1M + 8 * i);
iowrite16(0, ioaddr + MID_1H + 8 * i);
i++;
}
}
else {
u32 crc;
lp->mcr0 |= MCR0_HASH_EN;
for (i = 0; i < MCAST_MAX ; i++) {
iowrite16(0, ioaddr + MID_1L + 8 * i);
iowrite16(0, ioaddr + MID_1M + 8 * i);
iowrite16(0, ioaddr + MID_1H + 8 * i);
}
netdev_for_each_mc_addr(ha, dev) {
u8 *addrs = ha->addr;
crc = ether_crc(ETH_ALEN, addrs);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (crc & 0xf);
}
}
iowrite16(lp->mcr0, ioaddr + MCR0);
if (lp->mcr0 & MCR0_HASH_EN) {
iowrite16(hash_table[0], ioaddr + MAR0);
iowrite16(hash_table[1], ioaddr + MAR1);
iowrite16(hash_table[2], ioaddr + MAR2);
iowrite16(hash_table[3], ioaddr + MAR3);
}
spin_unlock_irqrestore(&lp->lock, flags);
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct r6040_private *rp = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(rp->pdev), sizeof(info->bus_info));
}
static int netdev_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct r6040_private *rp = netdev_priv(dev);
return phy_ethtool_gset(rp->phydev, cmd);
}
static int netdev_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct r6040_private *rp = netdev_priv(dev);
return phy_ethtool_sset(rp->phydev, cmd);
}
static void r6040_adjust_link(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
struct phy_device *phydev = lp->phydev;
int status_changed = 0;
void __iomem *ioaddr = lp->base;
BUG_ON(!phydev);
if (lp->old_link != phydev->link) {
status_changed = 1;
lp->old_link = phydev->link;
}
if (phydev->link && (lp->old_duplex != phydev->duplex)) {
lp->mcr0 |= (phydev->duplex == DUPLEX_FULL ? MCR0_FD : 0);
iowrite16(lp->mcr0, ioaddr);
status_changed = 1;
lp->old_duplex = phydev->duplex;
}
if (status_changed) {
pr_info("%s: link %s", dev->name, phydev->link ?
"UP" : "DOWN");
if (phydev->link)
pr_cont(" - %d/%s", phydev->speed,
DUPLEX_FULL == phydev->duplex ? "full" : "half");
pr_cont("\n");
}
}
static int r6040_mii_probe(struct net_device *dev)
{
struct r6040_private *lp = netdev_priv(dev);
struct phy_device *phydev = NULL;
phydev = phy_find_first(lp->mii_bus);
if (!phydev) {
dev_err(&lp->pdev->dev, "no PHY found\n");
return -ENODEV;
}
phydev = phy_connect(dev, dev_name(&phydev->dev), &r6040_adjust_link,
PHY_INTERFACE_MODE_MII);
if (IS_ERR(phydev)) {
dev_err(&lp->pdev->dev, "could not attach to PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= (SUPPORTED_10baseT_Half
| SUPPORTED_10baseT_Full
| SUPPORTED_100baseT_Half
| SUPPORTED_100baseT_Full
| SUPPORTED_Autoneg
| SUPPORTED_MII
| SUPPORTED_TP);
phydev->advertising = phydev->supported;
lp->phydev = phydev;
lp->old_link = 0;
lp->old_duplex = -1;
dev_info(&lp->pdev->dev, "attached PHY driver [%s] "
"(mii_bus:phy_addr=%s)\n",
phydev->drv->name, dev_name(&phydev->dev));
return 0;
}
static int r6040_init_one(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *dev;
struct r6040_private *lp;
void __iomem *ioaddr;
int err, io_size = R6040_IO_SIZE;
static int card_idx = -1;
int bar = 0;
u16 *adrp;
int i;
pr_info("%s\n", version);
err = pci_enable_device(pdev);
if (err)
goto err_out;
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "32-bit PCI DMA addresses"
"not supported by the card\n");
goto err_out_disable_dev;
}
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "32-bit PCI DMA addresses"
"not supported by the card\n");
goto err_out_disable_dev;
}
if (pci_resource_len(pdev, bar) < io_size) {
dev_err(&pdev->dev, "Insufficient PCI resources, aborting\n");
err = -EIO;
goto err_out_disable_dev;
}
pci_set_master(pdev);
dev = alloc_etherdev(sizeof(struct r6040_private));
if (!dev) {
err = -ENOMEM;
goto err_out_disable_dev;
}
SET_NETDEV_DEV(dev, &pdev->dev);
lp = netdev_priv(dev);
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_err(&pdev->dev, "Failed to request PCI regions\n");
goto err_out_free_dev;
}
ioaddr = pci_iomap(pdev, bar, io_size);
if (!ioaddr) {
dev_err(&pdev->dev, "ioremap failed for device\n");
err = -EIO;
goto err_out_free_res;
}
if (ioread16(ioaddr + PHY_CC) == 0)
iowrite16(SCEN | PHY_MAX_ADDR << PHYAD_SHIFT |
7 << TMRDIV_SHIFT, ioaddr + PHY_CC);
lp->base = ioaddr;
dev->irq = pdev->irq;
spin_lock_init(&lp->lock);
pci_set_drvdata(pdev, dev);
card_idx++;
adrp = (u16 *)dev->dev_addr;
adrp[0] = ioread16(ioaddr + MID_0L);
adrp[1] = ioread16(ioaddr + MID_0M);
adrp[2] = ioread16(ioaddr + MID_0H);
if (!(adrp[0] || adrp[1] || adrp[2])) {
netdev_warn(dev, "MAC address not initialized, "
"generating random\n");
eth_hw_addr_random(dev);
}
lp->pdev = pdev;
lp->dev = dev;
lp->mcr0 = MCR0_XMTEN | MCR0_RCVEN;
dev->netdev_ops = &r6040_netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
netif_napi_add(dev, &lp->napi, r6040_poll, 64);
lp->mii_bus = mdiobus_alloc();
if (!lp->mii_bus) {
dev_err(&pdev->dev, "mdiobus_alloc() failed\n");
err = -ENOMEM;
goto err_out_unmap;
}
lp->mii_bus->priv = dev;
lp->mii_bus->read = r6040_mdiobus_read;
lp->mii_bus->write = r6040_mdiobus_write;
lp->mii_bus->reset = r6040_mdiobus_reset;
lp->mii_bus->name = "r6040_eth_mii";
snprintf(lp->mii_bus->id, MII_BUS_ID_SIZE, "%s-%x",
dev_name(&pdev->dev), card_idx);
lp->mii_bus->irq = kmalloc_array(PHY_MAX_ADDR, sizeof(int), GFP_KERNEL);
if (!lp->mii_bus->irq) {
err = -ENOMEM;
goto err_out_mdio;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
lp->mii_bus->irq[i] = PHY_POLL;
err = mdiobus_register(lp->mii_bus);
if (err) {
dev_err(&pdev->dev, "failed to register MII bus\n");
goto err_out_mdio_irq;
}
err = r6040_mii_probe(dev);
if (err) {
dev_err(&pdev->dev, "failed to probe MII bus\n");
goto err_out_mdio_unregister;
}
err = register_netdev(dev);
if (err) {
dev_err(&pdev->dev, "Failed to register net device\n");
goto err_out_mdio_unregister;
}
return 0;
err_out_mdio_unregister:
mdiobus_unregister(lp->mii_bus);
err_out_mdio_irq:
kfree(lp->mii_bus->irq);
err_out_mdio:
mdiobus_free(lp->mii_bus);
err_out_unmap:
netif_napi_del(&lp->napi);
pci_set_drvdata(pdev, NULL);
pci_iounmap(pdev, ioaddr);
err_out_free_res:
pci_release_regions(pdev);
err_out_free_dev:
free_netdev(dev);
err_out_disable_dev:
pci_disable_device(pdev);
err_out:
return err;
}
static void r6040_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct r6040_private *lp = netdev_priv(dev);
unregister_netdev(dev);
mdiobus_unregister(lp->mii_bus);
kfree(lp->mii_bus->irq);
mdiobus_free(lp->mii_bus);
netif_napi_del(&lp->napi);
pci_iounmap(pdev, lp->base);
pci_release_regions(pdev);
free_netdev(dev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
