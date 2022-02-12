static inline dma_addr_t fd_virt_to_bus(struct tc35815_local *lp, void *virt)
{
return lp->fd_buf_dma + ((u8 *)virt - (u8 *)lp->fd_buf);
}
static inline void *fd_bus_to_virt(struct tc35815_local *lp, dma_addr_t bus)
{
return (void *)((u8 *)lp->fd_buf + (bus - lp->fd_buf_dma));
}
static struct sk_buff *alloc_rxbuf_skb(struct net_device *dev,
struct pci_dev *hwdev,
dma_addr_t *dma_handle)
{
struct sk_buff *skb;
skb = netdev_alloc_skb(dev, RX_BUF_SIZE);
if (!skb)
return NULL;
*dma_handle = pci_map_single(hwdev, skb->data, RX_BUF_SIZE,
PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(hwdev, *dma_handle)) {
dev_kfree_skb_any(skb);
return NULL;
}
skb_reserve(skb, 2);
return skb;
}
static void free_rxbuf_skb(struct pci_dev *hwdev, struct sk_buff *skb, dma_addr_t dma_handle)
{
pci_unmap_single(hwdev, dma_handle, RX_BUF_SIZE,
PCI_DMA_FROMDEVICE);
dev_kfree_skb_any(skb);
}
static int tc_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct net_device *dev = bus->priv;
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
unsigned long timeout = jiffies + HZ;
tc_writel(MD_CA_Busy | (mii_id << 5) | (regnum & 0x1f), &tr->MD_CA);
udelay(12);
while (tc_readl(&tr->MD_CA) & MD_CA_Busy) {
if (time_after(jiffies, timeout))
return -EIO;
cpu_relax();
}
return tc_readl(&tr->MD_Data) & 0xffff;
}
static int tc_mdio_write(struct mii_bus *bus, int mii_id, int regnum, u16 val)
{
struct net_device *dev = bus->priv;
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
unsigned long timeout = jiffies + HZ;
tc_writel(val, &tr->MD_Data);
tc_writel(MD_CA_Busy | MD_CA_Wr | (mii_id << 5) | (regnum & 0x1f),
&tr->MD_CA);
udelay(12);
while (tc_readl(&tr->MD_CA) & MD_CA_Busy) {
if (time_after(jiffies, timeout))
return -EIO;
cpu_relax();
}
return 0;
}
static void tc_handle_link_change(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct phy_device *phydev = lp->phy_dev;
unsigned long flags;
int status_change = 0;
spin_lock_irqsave(&lp->lock, flags);
if (phydev->link &&
(lp->speed != phydev->speed || lp->duplex != phydev->duplex)) {
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
u32 reg;
reg = tc_readl(&tr->MAC_Ctl);
reg |= MAC_HaltReq;
tc_writel(reg, &tr->MAC_Ctl);
if (phydev->duplex == DUPLEX_FULL)
reg |= MAC_FullDup;
else
reg &= ~MAC_FullDup;
tc_writel(reg, &tr->MAC_Ctl);
reg &= ~MAC_HaltReq;
tc_writel(reg, &tr->MAC_Ctl);
if (phydev->duplex == DUPLEX_HALF &&
lp->chiptype != TC35815_TX4939)
tc_writel(tc_readl(&tr->Tx_Ctl) | Tx_EnLCarr,
&tr->Tx_Ctl);
lp->speed = phydev->speed;
lp->duplex = phydev->duplex;
status_change = 1;
}
if (phydev->link != lp->link) {
if (phydev->link) {
if (dev->flags & IFF_PROMISC)
tc35815_set_multicast_list(dev);
} else {
lp->speed = 0;
lp->duplex = -1;
}
lp->link = phydev->link;
status_change = 1;
}
spin_unlock_irqrestore(&lp->lock, flags);
if (status_change && netif_msg_link(lp)) {
phy_print_status(phydev);
pr_debug("%s: MII BMCR %04x BMSR %04x LPA %04x\n",
dev->name,
phy_read(phydev, MII_BMCR),
phy_read(phydev, MII_BMSR),
phy_read(phydev, MII_LPA));
}
}
static int tc_mii_probe(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct phy_device *phydev = NULL;
int phy_addr;
u32 dropmask;
for (phy_addr = 0; phy_addr < PHY_MAX_ADDR; phy_addr++) {
if (lp->mii_bus->phy_map[phy_addr]) {
if (phydev) {
printk(KERN_ERR "%s: multiple PHYs found\n",
dev->name);
return -EINVAL;
}
phydev = lp->mii_bus->phy_map[phy_addr];
break;
}
}
if (!phydev) {
printk(KERN_ERR "%s: no PHY found\n", dev->name);
return -ENODEV;
}
phydev = phy_connect(dev, dev_name(&phydev->dev),
&tc_handle_link_change, 0,
lp->chiptype == TC35815_TX4939 ?
PHY_INTERFACE_MODE_RMII : PHY_INTERFACE_MODE_MII);
if (IS_ERR(phydev)) {
printk(KERN_ERR "%s: Could not attach to PHY\n", dev->name);
return PTR_ERR(phydev);
}
printk(KERN_INFO "%s: attached PHY driver [%s] "
"(mii_bus:phy_addr=%s, id=%x)\n",
dev->name, phydev->drv->name, dev_name(&phydev->dev),
phydev->phy_id);
phydev->supported &= PHY_BASIC_FEATURES;
dropmask = 0;
if (options.speed == 10)
dropmask |= SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full;
else if (options.speed == 100)
dropmask |= SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full;
if (options.duplex == 1)
dropmask |= SUPPORTED_10baseT_Full | SUPPORTED_100baseT_Full;
else if (options.duplex == 2)
dropmask |= SUPPORTED_10baseT_Half | SUPPORTED_100baseT_Half;
phydev->supported &= ~dropmask;
phydev->advertising = phydev->supported;
lp->link = 0;
lp->speed = 0;
lp->duplex = -1;
lp->phy_dev = phydev;
return 0;
}
static int tc_mii_init(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
int err;
int i;
lp->mii_bus = mdiobus_alloc();
if (lp->mii_bus == NULL) {
err = -ENOMEM;
goto err_out;
}
lp->mii_bus->name = "tc35815_mii_bus";
lp->mii_bus->read = tc_mdio_read;
lp->mii_bus->write = tc_mdio_write;
snprintf(lp->mii_bus->id, MII_BUS_ID_SIZE, "%x",
(lp->pci_dev->bus->number << 8) | lp->pci_dev->devfn);
lp->mii_bus->priv = dev;
lp->mii_bus->parent = &lp->pci_dev->dev;
lp->mii_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!lp->mii_bus->irq) {
err = -ENOMEM;
goto err_out_free_mii_bus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
lp->mii_bus->irq[i] = PHY_POLL;
err = mdiobus_register(lp->mii_bus);
if (err)
goto err_out_free_mdio_irq;
err = tc_mii_probe(dev);
if (err)
goto err_out_unregister_bus;
return 0;
err_out_unregister_bus:
mdiobus_unregister(lp->mii_bus);
err_out_free_mdio_irq:
kfree(lp->mii_bus->irq);
err_out_free_mii_bus:
mdiobus_free(lp->mii_bus);
err_out:
return err;
}
static int tc35815_mac_match(struct device *dev, void *data)
{
struct platform_device *plat_dev = to_platform_device(dev);
struct pci_dev *pci_dev = data;
unsigned int id = pci_dev->irq;
return !strcmp(plat_dev->name, "tc35815-mac") && plat_dev->id == id;
}
static int tc35815_read_plat_dev_addr(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct device *pd = bus_find_device(&platform_bus_type, NULL,
lp->pci_dev, tc35815_mac_match);
if (pd) {
if (pd->platform_data)
memcpy(dev->dev_addr, pd->platform_data, ETH_ALEN);
put_device(pd);
return is_valid_ether_addr(dev->dev_addr) ? 0 : -ENODEV;
}
return -ENODEV;
}
static int tc35815_read_plat_dev_addr(struct net_device *dev)
{
return -ENODEV;
}
static int tc35815_init_dev_addr(struct net_device *dev)
{
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
int i;
while (tc_readl(&tr->PROM_Ctl) & PROM_Busy)
;
for (i = 0; i < 6; i += 2) {
unsigned short data;
tc_writel(PROM_Busy | PROM_Read | (i / 2 + 2), &tr->PROM_Ctl);
while (tc_readl(&tr->PROM_Ctl) & PROM_Busy)
;
data = tc_readl(&tr->PROM_Data);
dev->dev_addr[i] = data & 0xff;
dev->dev_addr[i+1] = data >> 8;
}
if (!is_valid_ether_addr(dev->dev_addr))
return tc35815_read_plat_dev_addr(dev);
return 0;
}
static int tc35815_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
void __iomem *ioaddr = NULL;
struct net_device *dev;
struct tc35815_local *lp;
int rc;
static int printed_version;
if (!printed_version++) {
printk(version);
dev_printk(KERN_DEBUG, &pdev->dev,
"speed:%d duplex:%d\n",
options.speed, options.duplex);
}
if (!pdev->irq) {
dev_warn(&pdev->dev, "no IRQ assigned.\n");
return -ENODEV;
}
dev = alloc_etherdev(sizeof(*lp));
if (dev == NULL)
return -ENOMEM;
SET_NETDEV_DEV(dev, &pdev->dev);
lp = netdev_priv(dev);
lp->dev = dev;
rc = pcim_enable_device(pdev);
if (rc)
goto err_out;
rc = pcim_iomap_regions(pdev, 1 << 1, MODNAME);
if (rc)
goto err_out;
pci_set_master(pdev);
ioaddr = pcim_iomap_table(pdev)[1];
dev->netdev_ops = &tc35815_netdev_ops;
dev->ethtool_ops = &tc35815_ethtool_ops;
dev->watchdog_timeo = TC35815_TX_TIMEOUT;
netif_napi_add(dev, &lp->napi, tc35815_poll, NAPI_WEIGHT);
dev->irq = pdev->irq;
dev->base_addr = (unsigned long)ioaddr;
INIT_WORK(&lp->restart_work, tc35815_restart_work);
spin_lock_init(&lp->lock);
spin_lock_init(&lp->rx_lock);
lp->pci_dev = pdev;
lp->chiptype = ent->driver_data;
lp->msg_enable = NETIF_MSG_TX_ERR | NETIF_MSG_HW | NETIF_MSG_DRV | NETIF_MSG_LINK;
pci_set_drvdata(pdev, dev);
tc35815_chip_reset(dev);
if (tc35815_init_dev_addr(dev)) {
dev_warn(&pdev->dev, "not valid ether addr\n");
eth_hw_addr_random(dev);
}
rc = register_netdev(dev);
if (rc)
goto err_out;
memcpy(dev->perm_addr, dev->dev_addr, dev->addr_len);
printk(KERN_INFO "%s: %s at 0x%lx, %pM, IRQ %d\n",
dev->name,
chip_info[ent->driver_data].name,
dev->base_addr,
dev->dev_addr,
dev->irq);
rc = tc_mii_init(dev);
if (rc)
goto err_out_unregister;
return 0;
err_out_unregister:
unregister_netdev(dev);
err_out:
free_netdev(dev);
return rc;
}
static void tc35815_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct tc35815_local *lp = netdev_priv(dev);
phy_disconnect(lp->phy_dev);
mdiobus_unregister(lp->mii_bus);
kfree(lp->mii_bus->irq);
mdiobus_free(lp->mii_bus);
unregister_netdev(dev);
free_netdev(dev);
pci_set_drvdata(pdev, NULL);
}
static int
tc35815_init_queues(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
int i;
unsigned long fd_addr;
if (!lp->fd_buf) {
BUG_ON(sizeof(struct FDesc) +
sizeof(struct BDesc) * RX_BUF_NUM +
sizeof(struct FDesc) * RX_FD_NUM +
sizeof(struct TxFD) * TX_FD_NUM >
PAGE_SIZE * FD_PAGE_NUM);
lp->fd_buf = pci_alloc_consistent(lp->pci_dev,
PAGE_SIZE * FD_PAGE_NUM,
&lp->fd_buf_dma);
if (!lp->fd_buf)
return -ENOMEM;
for (i = 0; i < RX_BUF_NUM; i++) {
lp->rx_skbs[i].skb =
alloc_rxbuf_skb(dev, lp->pci_dev,
&lp->rx_skbs[i].skb_dma);
if (!lp->rx_skbs[i].skb) {
while (--i >= 0) {
free_rxbuf_skb(lp->pci_dev,
lp->rx_skbs[i].skb,
lp->rx_skbs[i].skb_dma);
lp->rx_skbs[i].skb = NULL;
}
pci_free_consistent(lp->pci_dev,
PAGE_SIZE * FD_PAGE_NUM,
lp->fd_buf,
lp->fd_buf_dma);
lp->fd_buf = NULL;
return -ENOMEM;
}
}
printk(KERN_DEBUG "%s: FD buf %p DataBuf",
dev->name, lp->fd_buf);
printk("\n");
} else {
for (i = 0; i < FD_PAGE_NUM; i++)
clear_page((void *)((unsigned long)lp->fd_buf +
i * PAGE_SIZE));
}
fd_addr = (unsigned long)lp->fd_buf;
lp->rfd_base = (struct RxFD *)fd_addr;
fd_addr += sizeof(struct RxFD) * RX_FD_NUM;
for (i = 0; i < RX_FD_NUM; i++)
lp->rfd_base[i].fd.FDCtl = cpu_to_le32(FD_CownsFD);
lp->rfd_cur = lp->rfd_base;
lp->rfd_limit = (struct RxFD *)fd_addr - (RX_FD_RESERVE + 1);
lp->tfd_base = (struct TxFD *)fd_addr;
fd_addr += sizeof(struct TxFD) * TX_FD_NUM;
for (i = 0; i < TX_FD_NUM; i++) {
lp->tfd_base[i].fd.FDNext = cpu_to_le32(fd_virt_to_bus(lp, &lp->tfd_base[i+1]));
lp->tfd_base[i].fd.FDSystem = cpu_to_le32(0xffffffff);
lp->tfd_base[i].fd.FDCtl = cpu_to_le32(0);
}
lp->tfd_base[TX_FD_NUM-1].fd.FDNext = cpu_to_le32(fd_virt_to_bus(lp, &lp->tfd_base[0]));
lp->tfd_start = 0;
lp->tfd_end = 0;
lp->fbl_ptr = (struct FrFD *)fd_addr;
lp->fbl_ptr->fd.FDNext = cpu_to_le32(fd_virt_to_bus(lp, lp->fbl_ptr));
lp->fbl_ptr->fd.FDCtl = cpu_to_le32(RX_BUF_NUM | FD_CownsFD);
lp->fbl_count = 0;
for (i = 0; i < RX_BUF_NUM; i++) {
if (lp->rx_skbs[i].skb) {
if (i != lp->fbl_count) {
lp->rx_skbs[lp->fbl_count].skb =
lp->rx_skbs[i].skb;
lp->rx_skbs[lp->fbl_count].skb_dma =
lp->rx_skbs[i].skb_dma;
}
lp->fbl_count++;
}
}
for (i = 0; i < RX_BUF_NUM; i++) {
if (i >= lp->fbl_count) {
lp->fbl_ptr->bd[i].BuffData = 0;
lp->fbl_ptr->bd[i].BDCtl = 0;
continue;
}
lp->fbl_ptr->bd[i].BuffData =
cpu_to_le32(lp->rx_skbs[i].skb_dma);
lp->fbl_ptr->bd[i].BDCtl =
cpu_to_le32(BD_CownsBD | (i << BD_RxBDID_SHIFT) |
RX_BUF_SIZE);
}
printk(KERN_DEBUG "%s: TxFD %p RxFD %p FrFD %p\n",
dev->name, lp->tfd_base, lp->rfd_base, lp->fbl_ptr);
return 0;
}
static void
tc35815_clear_queues(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
int i;
for (i = 0; i < TX_FD_NUM; i++) {
u32 fdsystem = le32_to_cpu(lp->tfd_base[i].fd.FDSystem);
struct sk_buff *skb =
fdsystem != 0xffffffff ?
lp->tx_skbs[fdsystem].skb : NULL;
#ifdef DEBUG
if (lp->tx_skbs[i].skb != skb) {
printk("%s: tx_skbs mismatch(%d).\n", dev->name, i);
panic_queues(dev);
}
#else
BUG_ON(lp->tx_skbs[i].skb != skb);
#endif
if (skb) {
pci_unmap_single(lp->pci_dev, lp->tx_skbs[i].skb_dma, skb->len, PCI_DMA_TODEVICE);
lp->tx_skbs[i].skb = NULL;
lp->tx_skbs[i].skb_dma = 0;
dev_kfree_skb_any(skb);
}
lp->tfd_base[i].fd.FDSystem = cpu_to_le32(0xffffffff);
}
tc35815_init_queues(dev);
}
static void
tc35815_free_queues(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
int i;
if (lp->tfd_base) {
for (i = 0; i < TX_FD_NUM; i++) {
u32 fdsystem = le32_to_cpu(lp->tfd_base[i].fd.FDSystem);
struct sk_buff *skb =
fdsystem != 0xffffffff ?
lp->tx_skbs[fdsystem].skb : NULL;
#ifdef DEBUG
if (lp->tx_skbs[i].skb != skb) {
printk("%s: tx_skbs mismatch(%d).\n", dev->name, i);
panic_queues(dev);
}
#else
BUG_ON(lp->tx_skbs[i].skb != skb);
#endif
if (skb) {
dev_kfree_skb(skb);
pci_unmap_single(lp->pci_dev, lp->tx_skbs[i].skb_dma, skb->len, PCI_DMA_TODEVICE);
lp->tx_skbs[i].skb = NULL;
lp->tx_skbs[i].skb_dma = 0;
}
lp->tfd_base[i].fd.FDSystem = cpu_to_le32(0xffffffff);
}
}
lp->rfd_base = NULL;
lp->rfd_limit = NULL;
lp->rfd_cur = NULL;
lp->fbl_ptr = NULL;
for (i = 0; i < RX_BUF_NUM; i++) {
if (lp->rx_skbs[i].skb) {
free_rxbuf_skb(lp->pci_dev, lp->rx_skbs[i].skb,
lp->rx_skbs[i].skb_dma);
lp->rx_skbs[i].skb = NULL;
}
}
if (lp->fd_buf) {
pci_free_consistent(lp->pci_dev, PAGE_SIZE * FD_PAGE_NUM,
lp->fd_buf, lp->fd_buf_dma);
lp->fd_buf = NULL;
}
}
static void
dump_txfd(struct TxFD *fd)
{
printk("TxFD(%p): %08x %08x %08x %08x\n", fd,
le32_to_cpu(fd->fd.FDNext),
le32_to_cpu(fd->fd.FDSystem),
le32_to_cpu(fd->fd.FDStat),
le32_to_cpu(fd->fd.FDCtl));
printk("BD: ");
printk(" %08x %08x",
le32_to_cpu(fd->bd.BuffData),
le32_to_cpu(fd->bd.BDCtl));
printk("\n");
}
static int
dump_rxfd(struct RxFD *fd)
{
int i, bd_count = (le32_to_cpu(fd->fd.FDCtl) & FD_BDCnt_MASK) >> FD_BDCnt_SHIFT;
if (bd_count > 8)
bd_count = 8;
printk("RxFD(%p): %08x %08x %08x %08x\n", fd,
le32_to_cpu(fd->fd.FDNext),
le32_to_cpu(fd->fd.FDSystem),
le32_to_cpu(fd->fd.FDStat),
le32_to_cpu(fd->fd.FDCtl));
if (le32_to_cpu(fd->fd.FDCtl) & FD_CownsFD)
return 0;
printk("BD: ");
for (i = 0; i < bd_count; i++)
printk(" %08x %08x",
le32_to_cpu(fd->bd[i].BuffData),
le32_to_cpu(fd->bd[i].BDCtl));
printk("\n");
return bd_count;
}
static void
dump_frfd(struct FrFD *fd)
{
int i;
printk("FrFD(%p): %08x %08x %08x %08x\n", fd,
le32_to_cpu(fd->fd.FDNext),
le32_to_cpu(fd->fd.FDSystem),
le32_to_cpu(fd->fd.FDStat),
le32_to_cpu(fd->fd.FDCtl));
printk("BD: ");
for (i = 0; i < RX_BUF_NUM; i++)
printk(" %08x %08x",
le32_to_cpu(fd->bd[i].BuffData),
le32_to_cpu(fd->bd[i].BDCtl));
printk("\n");
}
static void
panic_queues(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
int i;
printk("TxFD base %p, start %u, end %u\n",
lp->tfd_base, lp->tfd_start, lp->tfd_end);
printk("RxFD base %p limit %p cur %p\n",
lp->rfd_base, lp->rfd_limit, lp->rfd_cur);
printk("FrFD %p\n", lp->fbl_ptr);
for (i = 0; i < TX_FD_NUM; i++)
dump_txfd(&lp->tfd_base[i]);
for (i = 0; i < RX_FD_NUM; i++) {
int bd_count = dump_rxfd(&lp->rfd_base[i]);
i += (bd_count + 1) / 2;
}
dump_frfd(lp->fbl_ptr);
panic("%s: Illegal queue state.", dev->name);
}
static void print_eth(const u8 *add)
{
printk(KERN_DEBUG "print_eth(%p)\n", add);
printk(KERN_DEBUG " %pM => %pM : %02x%02x\n",
add + 6, add, add[12], add[13]);
}
static int tc35815_tx_full(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
return (lp->tfd_start + 1) % TX_FD_NUM == lp->tfd_end;
}
static void tc35815_restart(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
if (lp->phy_dev) {
int timeout;
phy_write(lp->phy_dev, MII_BMCR, BMCR_RESET);
timeout = 100;
while (--timeout) {
if (!(phy_read(lp->phy_dev, MII_BMCR) & BMCR_RESET))
break;
udelay(1);
}
if (!timeout)
printk(KERN_ERR "%s: BMCR reset failed.\n", dev->name);
}
spin_lock_bh(&lp->rx_lock);
spin_lock_irq(&lp->lock);
tc35815_chip_reset(dev);
tc35815_clear_queues(dev);
tc35815_chip_init(dev);
tc35815_set_multicast_list(dev);
spin_unlock_irq(&lp->lock);
spin_unlock_bh(&lp->rx_lock);
netif_wake_queue(dev);
}
static void tc35815_restart_work(struct work_struct *work)
{
struct tc35815_local *lp =
container_of(work, struct tc35815_local, restart_work);
struct net_device *dev = lp->dev;
tc35815_restart(dev);
}
static void tc35815_schedule_restart(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
tc_writel(0, &tr->Int_En);
tc_writel(tc_readl(&tr->DMA_Ctl) | DMA_IntMask, &tr->DMA_Ctl);
schedule_work(&lp->restart_work);
spin_unlock_irqrestore(&lp->lock, flags);
}
static void tc35815_tx_timeout(struct net_device *dev)
{
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
printk(KERN_WARNING "%s: transmit timed out, status %#x\n",
dev->name, tc_readl(&tr->Tx_Stat));
tc35815_schedule_restart(dev);
dev->stats.tx_errors++;
}
static int
tc35815_open(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
if (request_irq(dev->irq, tc35815_interrupt, IRQF_SHARED,
dev->name, dev))
return -EAGAIN;
tc35815_chip_reset(dev);
if (tc35815_init_queues(dev) != 0) {
free_irq(dev->irq, dev);
return -EAGAIN;
}
napi_enable(&lp->napi);
spin_lock_irq(&lp->lock);
tc35815_chip_init(dev);
spin_unlock_irq(&lp->lock);
netif_carrier_off(dev);
phy_start(lp->phy_dev);
netif_start_queue(dev);
return 0;
}
static int tc35815_send_packet(struct sk_buff *skb, struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct TxFD *txfd;
unsigned long flags;
spin_lock_irqsave(&lp->lock, flags);
if ((lp->tfd_start + TX_FD_NUM - lp->tfd_end) % TX_FD_NUM >
TX_FD_NUM / 2)
tc35815_txdone(dev);
if (netif_msg_pktdata(lp))
print_eth(skb->data);
#ifdef DEBUG
if (lp->tx_skbs[lp->tfd_start].skb) {
printk("%s: tx_skbs conflict.\n", dev->name);
panic_queues(dev);
}
#else
BUG_ON(lp->tx_skbs[lp->tfd_start].skb);
#endif
lp->tx_skbs[lp->tfd_start].skb = skb;
lp->tx_skbs[lp->tfd_start].skb_dma = pci_map_single(lp->pci_dev, skb->data, skb->len, PCI_DMA_TODEVICE);
txfd = &lp->tfd_base[lp->tfd_start];
txfd->bd.BuffData = cpu_to_le32(lp->tx_skbs[lp->tfd_start].skb_dma);
txfd->bd.BDCtl = cpu_to_le32(skb->len);
txfd->fd.FDSystem = cpu_to_le32(lp->tfd_start);
txfd->fd.FDCtl = cpu_to_le32(FD_CownsFD | (1 << FD_BDCnt_SHIFT));
if (lp->tfd_start == lp->tfd_end) {
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
txfd->fd.FDNext |= cpu_to_le32(FD_Next_EOL);
txfd->fd.FDCtl |= cpu_to_le32(FD_FrmOpt_IntTx);
if (netif_msg_tx_queued(lp)) {
printk("%s: starting TxFD.\n", dev->name);
dump_txfd(txfd);
}
tc_writel(fd_virt_to_bus(lp, txfd), &tr->TxFrmPtr);
} else {
txfd->fd.FDNext &= cpu_to_le32(~FD_Next_EOL);
if (netif_msg_tx_queued(lp)) {
printk("%s: queueing TxFD.\n", dev->name);
dump_txfd(txfd);
}
}
lp->tfd_start = (lp->tfd_start + 1) % TX_FD_NUM;
if (tc35815_tx_full(dev)) {
if (netif_msg_tx_queued(lp))
printk(KERN_WARNING "%s: TxFD Exhausted.\n", dev->name);
netif_stop_queue(dev);
}
spin_unlock_irqrestore(&lp->lock, flags);
return NETDEV_TX_OK;
}
static void tc35815_fatal_error_interrupt(struct net_device *dev, u32 status)
{
static int count;
printk(KERN_WARNING "%s: Fatal Error Intterrupt (%#x):",
dev->name, status);
if (status & Int_IntPCI)
printk(" IntPCI");
if (status & Int_DmParErr)
printk(" DmParErr");
if (status & Int_IntNRAbt)
printk(" IntNRAbt");
printk("\n");
if (count++ > 100)
panic("%s: Too many fatal errors.", dev->name);
printk(KERN_WARNING "%s: Resetting ...\n", dev->name);
tc35815_schedule_restart(dev);
}
static int tc35815_do_interrupt(struct net_device *dev, u32 status, int limit)
{
struct tc35815_local *lp = netdev_priv(dev);
int ret = -1;
if (status & FATAL_ERROR_INT) {
tc35815_fatal_error_interrupt(dev, status);
return 0;
}
if (status & Int_IntFDAEx) {
if (netif_msg_rx_err(lp))
dev_warn(&dev->dev,
"Free Descriptor Area Exhausted (%#x).\n",
status);
dev->stats.rx_dropped++;
ret = 0;
}
if (status & Int_IntBLEx) {
if (netif_msg_rx_err(lp))
dev_warn(&dev->dev,
"Buffer List Exhausted (%#x).\n",
status);
dev->stats.rx_dropped++;
ret = 0;
}
if (status & Int_IntExBD) {
if (netif_msg_rx_err(lp))
dev_warn(&dev->dev,
"Excessive Buffer Descriptiors (%#x).\n",
status);
dev->stats.rx_length_errors++;
ret = 0;
}
if (status & Int_IntMacRx) {
ret = tc35815_rx(dev, limit);
lp->lstats.rx_ints++;
}
if (status & Int_IntMacTx) {
lp->lstats.tx_ints++;
spin_lock_irq(&lp->lock);
tc35815_txdone(dev);
spin_unlock_irq(&lp->lock);
if (ret < 0)
ret = 0;
}
return ret;
}
static irqreturn_t tc35815_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct tc35815_local *lp = netdev_priv(dev);
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
u32 dmactl = tc_readl(&tr->DMA_Ctl);
if (!(dmactl & DMA_IntMask)) {
tc_writel(dmactl | DMA_IntMask, &tr->DMA_Ctl);
if (napi_schedule_prep(&lp->napi))
__napi_schedule(&lp->napi);
else {
printk(KERN_ERR "%s: interrupt taken in poll\n",
dev->name);
BUG();
}
(void)tc_readl(&tr->Int_Src);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void tc35815_poll_controller(struct net_device *dev)
{
disable_irq(dev->irq);
tc35815_interrupt(dev->irq, dev);
enable_irq(dev->irq);
}
static int
tc35815_rx(struct net_device *dev, int limit)
{
struct tc35815_local *lp = netdev_priv(dev);
unsigned int fdctl;
int i;
int received = 0;
while (!((fdctl = le32_to_cpu(lp->rfd_cur->fd.FDCtl)) & FD_CownsFD)) {
int status = le32_to_cpu(lp->rfd_cur->fd.FDStat);
int pkt_len = fdctl & FD_FDLength_MASK;
int bd_count = (fdctl & FD_BDCnt_MASK) >> FD_BDCnt_SHIFT;
#ifdef DEBUG
struct RxFD *next_rfd;
#endif
#if (RX_CTL_CMD & Rx_StripCRC) == 0
pkt_len -= ETH_FCS_LEN;
#endif
if (netif_msg_rx_status(lp))
dump_rxfd(lp->rfd_cur);
if (status & Rx_Good) {
struct sk_buff *skb;
unsigned char *data;
int cur_bd;
if (--limit < 0)
break;
BUG_ON(bd_count > 1);
cur_bd = (le32_to_cpu(lp->rfd_cur->bd[0].BDCtl)
& BD_RxBDID_MASK) >> BD_RxBDID_SHIFT;
#ifdef DEBUG
if (cur_bd >= RX_BUF_NUM) {
printk("%s: invalid BDID.\n", dev->name);
panic_queues(dev);
}
BUG_ON(lp->rx_skbs[cur_bd].skb_dma !=
(le32_to_cpu(lp->rfd_cur->bd[0].BuffData) & ~3));
if (!lp->rx_skbs[cur_bd].skb) {
printk("%s: NULL skb.\n", dev->name);
panic_queues(dev);
}
#else
BUG_ON(cur_bd >= RX_BUF_NUM);
#endif
skb = lp->rx_skbs[cur_bd].skb;
prefetch(skb->data);
lp->rx_skbs[cur_bd].skb = NULL;
pci_unmap_single(lp->pci_dev,
lp->rx_skbs[cur_bd].skb_dma,
RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
if (!HAVE_DMA_RXALIGN(lp) && NET_IP_ALIGN)
memmove(skb->data, skb->data - NET_IP_ALIGN,
pkt_len);
data = skb_put(skb, pkt_len);
if (netif_msg_pktdata(lp))
print_eth(data);
skb->protocol = eth_type_trans(skb, dev);
netif_receive_skb(skb);
received++;
dev->stats.rx_packets++;
dev->stats.rx_bytes += pkt_len;
} else {
dev->stats.rx_errors++;
if (netif_msg_rx_err(lp))
dev_info(&dev->dev, "Rx error (status %x)\n",
status & Rx_Stat_Mask);
if ((status & Rx_LongErr) && (status & Rx_CRCErr)) {
status &= ~(Rx_LongErr|Rx_CRCErr);
status |= Rx_Over;
}
if (status & Rx_LongErr)
dev->stats.rx_length_errors++;
if (status & Rx_Over)
dev->stats.rx_fifo_errors++;
if (status & Rx_CRCErr)
dev->stats.rx_crc_errors++;
if (status & Rx_Align)
dev->stats.rx_frame_errors++;
}
if (bd_count > 0) {
int bdctl = le32_to_cpu(lp->rfd_cur->bd[bd_count - 1].BDCtl);
unsigned char id =
(bdctl & BD_RxBDID_MASK) >> BD_RxBDID_SHIFT;
#ifdef DEBUG
if (id >= RX_BUF_NUM) {
printk("%s: invalid BDID.\n", dev->name);
panic_queues(dev);
}
#else
BUG_ON(id >= RX_BUF_NUM);
#endif
lp->fbl_count--;
while (lp->fbl_count < RX_BUF_NUM)
{
unsigned char curid =
(id + 1 + lp->fbl_count) % RX_BUF_NUM;
struct BDesc *bd = &lp->fbl_ptr->bd[curid];
#ifdef DEBUG
bdctl = le32_to_cpu(bd->BDCtl);
if (bdctl & BD_CownsBD) {
printk("%s: Freeing invalid BD.\n",
dev->name);
panic_queues(dev);
}
#endif
if (!lp->rx_skbs[curid].skb) {
lp->rx_skbs[curid].skb =
alloc_rxbuf_skb(dev,
lp->pci_dev,
&lp->rx_skbs[curid].skb_dma);
if (!lp->rx_skbs[curid].skb)
break;
bd->BuffData = cpu_to_le32(lp->rx_skbs[curid].skb_dma);
}
bd->BDCtl = cpu_to_le32(BD_CownsBD |
(curid << BD_RxBDID_SHIFT) |
RX_BUF_SIZE);
lp->fbl_count++;
}
}
#ifdef DEBUG
next_rfd = fd_bus_to_virt(lp,
le32_to_cpu(lp->rfd_cur->fd.FDNext));
if (next_rfd < lp->rfd_base || next_rfd > lp->rfd_limit) {
printk("%s: RxFD FDNext invalid.\n", dev->name);
panic_queues(dev);
}
#endif
for (i = 0; i < (bd_count + 1) / 2 + 1; i++) {
#ifdef DEBUG
lp->rfd_cur->fd.FDNext = cpu_to_le32(0xdeaddead);
#else
lp->rfd_cur->fd.FDNext = cpu_to_le32(FD_Next_EOL);
#endif
lp->rfd_cur->fd.FDCtl = cpu_to_le32(FD_CownsFD);
lp->rfd_cur++;
}
if (lp->rfd_cur > lp->rfd_limit)
lp->rfd_cur = lp->rfd_base;
#ifdef DEBUG
if (lp->rfd_cur != next_rfd)
printk("rfd_cur = %p, next_rfd %p\n",
lp->rfd_cur, next_rfd);
#endif
}
return received;
}
static int tc35815_poll(struct napi_struct *napi, int budget)
{
struct tc35815_local *lp = container_of(napi, struct tc35815_local, napi);
struct net_device *dev = lp->dev;
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
int received = 0, handled;
u32 status;
spin_lock(&lp->rx_lock);
status = tc_readl(&tr->Int_Src);
do {
tc_writel(status & ~(Int_BLEx | Int_FDAEx),
&tr->Int_Src);
handled = tc35815_do_interrupt(dev, status, budget - received);
if (status & (Int_BLEx | Int_FDAEx))
tc_writel(status & (Int_BLEx | Int_FDAEx),
&tr->Int_Src);
if (handled >= 0) {
received += handled;
if (received >= budget)
break;
}
status = tc_readl(&tr->Int_Src);
} while (status);
spin_unlock(&lp->rx_lock);
if (received < budget) {
napi_complete(napi);
tc_writel(tc_readl(&tr->DMA_Ctl) & ~DMA_IntMask, &tr->DMA_Ctl);
}
return received;
}
static void
tc35815_check_tx_stat(struct net_device *dev, int status)
{
struct tc35815_local *lp = netdev_priv(dev);
const char *msg = NULL;
if (status & Tx_ExColl)
dev->stats.collisions += 16;
if (status & Tx_TxColl_MASK)
dev->stats.collisions += status & Tx_TxColl_MASK;
if (lp->chiptype == TC35815_TX4939)
status &= ~Tx_NCarr;
if (!lp->link || lp->duplex == DUPLEX_FULL)
status &= ~Tx_NCarr;
if (!(status & TX_STA_ERR)) {
dev->stats.tx_packets++;
return;
}
dev->stats.tx_errors++;
if (status & Tx_ExColl) {
dev->stats.tx_aborted_errors++;
msg = "Excessive Collision.";
}
if (status & Tx_Under) {
dev->stats.tx_fifo_errors++;
msg = "Tx FIFO Underrun.";
if (lp->lstats.tx_underrun < TX_THRESHOLD_KEEP_LIMIT) {
lp->lstats.tx_underrun++;
if (lp->lstats.tx_underrun >= TX_THRESHOLD_KEEP_LIMIT) {
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
tc_writel(TX_THRESHOLD_MAX, &tr->TxThrsh);
msg = "Tx FIFO Underrun.Change Tx threshold to max.";
}
}
}
if (status & Tx_Defer) {
dev->stats.tx_fifo_errors++;
msg = "Excessive Deferral.";
}
if (status & Tx_NCarr) {
dev->stats.tx_carrier_errors++;
msg = "Lost Carrier Sense.";
}
if (status & Tx_LateColl) {
dev->stats.tx_aborted_errors++;
msg = "Late Collision.";
}
if (status & Tx_TxPar) {
dev->stats.tx_fifo_errors++;
msg = "Transmit Parity Error.";
}
if (status & Tx_SQErr) {
dev->stats.tx_heartbeat_errors++;
msg = "Signal Quality Error.";
}
if (msg && netif_msg_tx_err(lp))
printk(KERN_WARNING "%s: %s (%#x)\n", dev->name, msg, status);
}
static void
tc35815_txdone(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct TxFD *txfd;
unsigned int fdctl;
txfd = &lp->tfd_base[lp->tfd_end];
while (lp->tfd_start != lp->tfd_end &&
!((fdctl = le32_to_cpu(txfd->fd.FDCtl)) & FD_CownsFD)) {
int status = le32_to_cpu(txfd->fd.FDStat);
struct sk_buff *skb;
unsigned long fdnext = le32_to_cpu(txfd->fd.FDNext);
u32 fdsystem = le32_to_cpu(txfd->fd.FDSystem);
if (netif_msg_tx_done(lp)) {
printk("%s: complete TxFD.\n", dev->name);
dump_txfd(txfd);
}
tc35815_check_tx_stat(dev, status);
skb = fdsystem != 0xffffffff ?
lp->tx_skbs[fdsystem].skb : NULL;
#ifdef DEBUG
if (lp->tx_skbs[lp->tfd_end].skb != skb) {
printk("%s: tx_skbs mismatch.\n", dev->name);
panic_queues(dev);
}
#else
BUG_ON(lp->tx_skbs[lp->tfd_end].skb != skb);
#endif
if (skb) {
dev->stats.tx_bytes += skb->len;
pci_unmap_single(lp->pci_dev, lp->tx_skbs[lp->tfd_end].skb_dma, skb->len, PCI_DMA_TODEVICE);
lp->tx_skbs[lp->tfd_end].skb = NULL;
lp->tx_skbs[lp->tfd_end].skb_dma = 0;
dev_kfree_skb_any(skb);
}
txfd->fd.FDSystem = cpu_to_le32(0xffffffff);
lp->tfd_end = (lp->tfd_end + 1) % TX_FD_NUM;
txfd = &lp->tfd_base[lp->tfd_end];
#ifdef DEBUG
if ((fdnext & ~FD_Next_EOL) != fd_virt_to_bus(lp, txfd)) {
printk("%s: TxFD FDNext invalid.\n", dev->name);
panic_queues(dev);
}
#endif
if (fdnext & FD_Next_EOL) {
if (lp->tfd_end != lp->tfd_start) {
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
int head = (lp->tfd_start + TX_FD_NUM - 1) % TX_FD_NUM;
struct TxFD *txhead = &lp->tfd_base[head];
int qlen = (lp->tfd_start + TX_FD_NUM
- lp->tfd_end) % TX_FD_NUM;
#ifdef DEBUG
if (!(le32_to_cpu(txfd->fd.FDCtl) & FD_CownsFD)) {
printk("%s: TxFD FDCtl invalid.\n", dev->name);
panic_queues(dev);
}
#endif
if (lp->lstats.max_tx_qlen < qlen)
lp->lstats.max_tx_qlen = qlen;
txhead->fd.FDNext |= cpu_to_le32(FD_Next_EOL);
txhead->fd.FDCtl |= cpu_to_le32(FD_FrmOpt_IntTx);
if (netif_msg_tx_queued(lp)) {
printk("%s: start TxFD on queue.\n",
dev->name);
dump_txfd(txfd);
}
tc_writel(fd_virt_to_bus(lp, txfd), &tr->TxFrmPtr);
}
break;
}
}
if (netif_queue_stopped(dev) && !tc35815_tx_full(dev))
netif_wake_queue(dev);
}
static int
tc35815_close(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&lp->napi);
if (lp->phy_dev)
phy_stop(lp->phy_dev);
cancel_work_sync(&lp->restart_work);
tc35815_chip_reset(dev);
free_irq(dev->irq, dev);
tc35815_free_queues(dev);
return 0;
}
static struct net_device_stats *tc35815_get_stats(struct net_device *dev)
{
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
if (netif_running(dev))
dev->stats.rx_missed_errors += tc_readl(&tr->Miss_Cnt);
return &dev->stats;
}
static void tc35815_set_cam_entry(struct net_device *dev, int index, unsigned char *addr)
{
struct tc35815_local *lp = netdev_priv(dev);
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
int cam_index = index * 6;
u32 cam_data;
u32 saved_addr;
saved_addr = tc_readl(&tr->CAM_Adr);
if (netif_msg_hw(lp))
printk(KERN_DEBUG "%s: CAM %d: %pM\n",
dev->name, index, addr);
if (index & 1) {
tc_writel(cam_index - 2, &tr->CAM_Adr);
cam_data = tc_readl(&tr->CAM_Data) & 0xffff0000;
cam_data |= addr[0] << 8 | addr[1];
tc_writel(cam_data, &tr->CAM_Data);
tc_writel(cam_index + 2, &tr->CAM_Adr);
cam_data = (addr[2] << 24) | (addr[3] << 16) | (addr[4] << 8) | addr[5];
tc_writel(cam_data, &tr->CAM_Data);
} else {
tc_writel(cam_index, &tr->CAM_Adr);
cam_data = (addr[0] << 24) | (addr[1] << 16) | (addr[2] << 8) | addr[3];
tc_writel(cam_data, &tr->CAM_Data);
tc_writel(cam_index + 4, &tr->CAM_Adr);
cam_data = tc_readl(&tr->CAM_Data) & 0x0000ffff;
cam_data |= addr[4] << 24 | (addr[5] << 16);
tc_writel(cam_data, &tr->CAM_Data);
}
tc_writel(saved_addr, &tr->CAM_Adr);
}
static void
tc35815_set_multicast_list(struct net_device *dev)
{
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
if (dev->flags & IFF_PROMISC) {
struct tc35815_local *lp = netdev_priv(dev);
if (!lp->link)
return;
tc_writel(CAM_CompEn | CAM_BroadAcc | CAM_GroupAcc | CAM_StationAcc, &tr->CAM_Ctl);
} else if ((dev->flags & IFF_ALLMULTI) ||
netdev_mc_count(dev) > CAM_ENTRY_MAX - 3) {
tc_writel(CAM_CompEn | CAM_BroadAcc | CAM_GroupAcc, &tr->CAM_Ctl);
} else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
int i;
int ena_bits = CAM_Ena_Bit(CAM_ENTRY_SOURCE);
tc_writel(0, &tr->CAM_Ctl);
i = 0;
netdev_for_each_mc_addr(ha, dev) {
tc35815_set_cam_entry(dev, i + 2, ha->addr);
ena_bits |= CAM_Ena_Bit(i + 2);
i++;
}
tc_writel(ena_bits, &tr->CAM_Ena);
tc_writel(CAM_CompEn | CAM_BroadAcc, &tr->CAM_Ctl);
} else {
tc_writel(CAM_Ena_Bit(CAM_ENTRY_SOURCE), &tr->CAM_Ena);
tc_writel(CAM_CompEn | CAM_BroadAcc, &tr->CAM_Ctl);
}
}
static void tc35815_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct tc35815_local *lp = netdev_priv(dev);
strcpy(info->driver, MODNAME);
strcpy(info->version, DRV_VERSION);
strcpy(info->bus_info, pci_name(lp->pci_dev));
}
static int tc35815_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct tc35815_local *lp = netdev_priv(dev);
if (!lp->phy_dev)
return -ENODEV;
return phy_ethtool_gset(lp->phy_dev, cmd);
}
static int tc35815_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct tc35815_local *lp = netdev_priv(dev);
if (!lp->phy_dev)
return -ENODEV;
return phy_ethtool_sset(lp->phy_dev, cmd);
}
static u32 tc35815_get_msglevel(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
return lp->msg_enable;
}
static void tc35815_set_msglevel(struct net_device *dev, u32 datum)
{
struct tc35815_local *lp = netdev_priv(dev);
lp->msg_enable = datum;
}
static int tc35815_get_sset_count(struct net_device *dev, int sset)
{
struct tc35815_local *lp = netdev_priv(dev);
switch (sset) {
case ETH_SS_STATS:
return sizeof(lp->lstats) / sizeof(int);
default:
return -EOPNOTSUPP;
}
}
static void tc35815_get_ethtool_stats(struct net_device *dev, struct ethtool_stats *stats, u64 *data)
{
struct tc35815_local *lp = netdev_priv(dev);
data[0] = lp->lstats.max_tx_qlen;
data[1] = lp->lstats.tx_ints;
data[2] = lp->lstats.rx_ints;
data[3] = lp->lstats.tx_underrun;
}
static void tc35815_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
memcpy(data, ethtool_stats_keys, sizeof(ethtool_stats_keys));
}
static int tc35815_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct tc35815_local *lp = netdev_priv(dev);
if (!netif_running(dev))
return -EINVAL;
if (!lp->phy_dev)
return -ENODEV;
return phy_mii_ioctl(lp->phy_dev, rq, cmd);
}
static void tc35815_chip_reset(struct net_device *dev)
{
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
int i;
tc_writel(MAC_Reset, &tr->MAC_Ctl);
udelay(4);
i = 0;
while (tc_readl(&tr->MAC_Ctl) & MAC_Reset) {
if (i++ > 100) {
printk(KERN_ERR "%s: MAC reset failed.\n", dev->name);
break;
}
mdelay(1);
}
tc_writel(0, &tr->MAC_Ctl);
tc_writel(0, &tr->DMA_Ctl);
tc_writel(0, &tr->TxThrsh);
tc_writel(0, &tr->TxPollCtr);
tc_writel(0, &tr->RxFragSize);
tc_writel(0, &tr->Int_En);
tc_writel(0, &tr->FDA_Bas);
tc_writel(0, &tr->FDA_Lim);
tc_writel(0xffffffff, &tr->Int_Src);
tc_writel(0, &tr->CAM_Ctl);
tc_writel(0, &tr->Tx_Ctl);
tc_writel(0, &tr->Rx_Ctl);
tc_writel(0, &tr->CAM_Ena);
(void)tc_readl(&tr->Miss_Cnt);
tc_writel(DMA_TestMode, &tr->DMA_Ctl);
for (i = 0; i < 0x1000; i += 4) {
tc_writel(i, &tr->CAM_Adr);
tc_writel(0, &tr->CAM_Data);
}
tc_writel(0, &tr->DMA_Ctl);
}
static void tc35815_chip_init(struct net_device *dev)
{
struct tc35815_local *lp = netdev_priv(dev);
struct tc35815_regs __iomem *tr =
(struct tc35815_regs __iomem *)dev->base_addr;
unsigned long txctl = TX_CTL_CMD;
tc35815_set_cam_entry(dev, CAM_ENTRY_SOURCE, dev->dev_addr);
tc_writel(CAM_Ena_Bit(CAM_ENTRY_SOURCE), &tr->CAM_Ena);
tc_writel(CAM_CompEn | CAM_BroadAcc, &tr->CAM_Ctl);
if (HAVE_DMA_RXALIGN(lp))
tc_writel(DMA_BURST_SIZE | DMA_RxAlign_2, &tr->DMA_Ctl);
else
tc_writel(DMA_BURST_SIZE, &tr->DMA_Ctl);
tc_writel(0, &tr->TxPollCtr);
tc_writel(TX_THRESHOLD, &tr->TxThrsh);
tc_writel(INT_EN_CMD, &tr->Int_En);
tc_writel(fd_virt_to_bus(lp, lp->rfd_base), &tr->FDA_Bas);
tc_writel((unsigned long)lp->rfd_limit - (unsigned long)lp->rfd_base,
&tr->FDA_Lim);
tc_writel(fd_virt_to_bus(lp, lp->fbl_ptr), &tr->BLFrmPtr);
tc_writel(RX_CTL_CMD, &tr->Rx_Ctl);
if (lp->chiptype == TC35815_TX4939)
txctl &= ~Tx_EnLCarr;
if (!lp->phy_dev || !lp->link || lp->duplex == DUPLEX_FULL)
txctl &= ~Tx_EnLCarr;
tc_writel(txctl, &tr->Tx_Ctl);
}
static int tc35815_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct tc35815_local *lp = netdev_priv(dev);
unsigned long flags;
pci_save_state(pdev);
if (!netif_running(dev))
return 0;
netif_device_detach(dev);
if (lp->phy_dev)
phy_stop(lp->phy_dev);
spin_lock_irqsave(&lp->lock, flags);
tc35815_chip_reset(dev);
spin_unlock_irqrestore(&lp->lock, flags);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int tc35815_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct tc35815_local *lp = netdev_priv(dev);
pci_restore_state(pdev);
if (!netif_running(dev))
return 0;
pci_set_power_state(pdev, PCI_D0);
tc35815_restart(dev);
netif_carrier_off(dev);
if (lp->phy_dev)
phy_start(lp->phy_dev);
netif_device_attach(dev);
return 0;
}
static int __init tc35815_init_module(void)
{
return pci_register_driver(&tc35815_pci_driver);
}
static void __exit tc35815_cleanup_module(void)
{
pci_unregister_driver(&tc35815_pci_driver);
}
