static void dwceqos_reset_state(struct net_local *lp)
{
lp->link = 0;
lp->speed = 0;
lp->duplex = DUPLEX_UNKNOWN;
lp->flowcontrol.rx_current = 0;
lp->flowcontrol.tx_current = 0;
lp->eee_active = 0;
lp->eee_enabled = 0;
}
static void print_descriptor(struct net_local *lp, int index, int tx)
{
struct dwceqos_dma_desc *dd;
if (tx)
dd = (struct dwceqos_dma_desc *)&lp->tx_descs[index];
else
dd = (struct dwceqos_dma_desc *)&lp->rx_descs[index];
pr_info("%s DMA Descriptor #%d@%p Contents:\n", tx ? "TX" : "RX",
index, dd);
pr_info("0x%08x 0x%08x 0x%08x 0x%08x\n", dd->des0, dd->des1, dd->des2,
dd->des3);
}
static void print_status(struct net_local *lp)
{
size_t desci, i;
pr_info("tx_free %zu, tx_cur %zu, tx_next %zu\n", lp->tx_free,
lp->tx_cur, lp->tx_next);
print_descriptor(lp, lp->rx_cur, 0);
for (desci = (lp->tx_cur - 10) % DWCEQOS_TX_DCNT, i = 0;
i < DWCEQOS_TX_DCNT;
++i) {
print_descriptor(lp, desci, 1);
desci = (desci + 1) % DWCEQOS_TX_DCNT;
}
pr_info("DMA_Debug_Status0: 0x%08x\n",
dwceqos_read(lp, REG_DWCEQOS_DMA_DEBUG_ST0));
pr_info("DMA_CH0_Status: 0x%08x\n",
dwceqos_read(lp, REG_DWCEQOS_DMA_IS));
pr_info("DMA_CH0_Current_App_TxDesc: 0x%08x\n",
dwceqos_read(lp, 0x1144));
pr_info("DMA_CH0_Current_App_TxBuff: 0x%08x\n",
dwceqos_read(lp, 0x1154));
pr_info("MTL_Debug_Status: 0x%08x\n",
dwceqos_read(lp, REG_DWCEQOS_MTL_DEBUG_ST));
pr_info("MTL_TXQ0_Debug_Status: 0x%08x\n",
dwceqos_read(lp, REG_DWCEQOS_MTL_TXQ0_DEBUG_ST));
pr_info("MTL_RXQ0_Debug_Status: 0x%08x\n",
dwceqos_read(lp, REG_DWCEQOS_MTL_RXQ0_DEBUG_ST));
pr_info("Current TX DMA: 0x%08x, RX DMA: 0x%08x\n",
dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_CUR_TXDESC),
dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_CUR_RXDESC));
}
static void dwceqos_mdio_set_csr(struct net_local *lp)
{
int rate = clk_get_rate(lp->apb_pclk);
if (rate <= 20000000)
lp->csr_val = DWCEQOS_MAC_MDIO_ADDR_CR_20;
else if (rate <= 35000000)
lp->csr_val = DWCEQOS_MAC_MDIO_ADDR_CR_35;
else if (rate <= 60000000)
lp->csr_val = DWCEQOS_MAC_MDIO_ADDR_CR_60;
else if (rate <= 100000000)
lp->csr_val = DWCEQOS_MAC_MDIO_ADDR_CR_100;
else if (rate <= 150000000)
lp->csr_val = DWCEQOS_MAC_MDIO_ADDR_CR_150;
else if (rate <= 250000000)
lp->csr_val = DWCEQOS_MAC_MDIO_ADDR_CR_250;
}
static int dwceqos_mdio_read(struct mii_bus *bus, int mii_id, int phyreg)
{
struct net_local *lp = bus->priv;
u32 regval;
int i;
int data;
regval = DWCEQOS_MDIO_PHYADDR(mii_id) |
DWCEQOS_MDIO_PHYREG(phyreg) |
DWCEQOS_MAC_MDIO_ADDR_CR(lp->csr_val) |
DWCEQOS_MAC_MDIO_ADDR_GB |
DWCEQOS_MAC_MDIO_ADDR_GOC_READ;
dwceqos_write(lp, REG_DWCEQOS_MAC_MDIO_ADDR, regval);
for (i = 0; i < 5; ++i) {
usleep_range(64, 128);
if (!(dwceqos_read(lp, REG_DWCEQOS_MAC_MDIO_ADDR) &
DWCEQOS_MAC_MDIO_ADDR_GB))
break;
}
data = dwceqos_read(lp, REG_DWCEQOS_MAC_MDIO_DATA);
if (i == 5) {
netdev_warn(lp->ndev, "MDIO read timed out\n");
data = 0xffff;
}
return data & 0xffff;
}
static int dwceqos_mdio_write(struct mii_bus *bus, int mii_id, int phyreg,
u16 value)
{
struct net_local *lp = bus->priv;
u32 regval;
int i;
dwceqos_write(lp, REG_DWCEQOS_MAC_MDIO_DATA, value);
regval = DWCEQOS_MDIO_PHYADDR(mii_id) |
DWCEQOS_MDIO_PHYREG(phyreg) |
DWCEQOS_MAC_MDIO_ADDR_CR(lp->csr_val) |
DWCEQOS_MAC_MDIO_ADDR_GB |
DWCEQOS_MAC_MDIO_ADDR_GOC_WRITE;
dwceqos_write(lp, REG_DWCEQOS_MAC_MDIO_ADDR, regval);
for (i = 0; i < 5; ++i) {
usleep_range(64, 128);
if (!(dwceqos_read(lp, REG_DWCEQOS_MAC_MDIO_ADDR) &
DWCEQOS_MAC_MDIO_ADDR_GB))
break;
}
if (i == 5)
netdev_warn(lp->ndev, "MDIO write timed out\n");
return 0;
}
static int dwceqos_ioctl(struct net_device *ndev, struct ifreq *rq, int cmd)
{
struct net_local *lp = netdev_priv(ndev);
struct phy_device *phydev = lp->phy_dev;
if (!netif_running(ndev))
return -EINVAL;
if (!phydev)
return -ENODEV;
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
return phy_mii_ioctl(phydev, rq, cmd);
default:
dev_info(&lp->pdev->dev, "ioctl %X not implemented.\n", cmd);
return -EOPNOTSUPP;
}
}
static void dwceqos_link_down(struct net_local *lp)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
regval &= ~DWCEQOS_MAC_LPI_CTRL_STATUS_PLS;
dwceqos_write(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_link_up(struct net_local *lp)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
regval |= DWCEQOS_MAC_LPI_CTRL_STATUS_PLS;
dwceqos_write(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
lp->eee_active = !phy_init_eee(lp->phy_dev, 0);
if (!lp->eee_active && lp->eee_enabled) {
lp->eee_enabled = 0;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
regval &= ~DWCEQOS_LPI_CTRL_ENABLE_EEE;
dwceqos_write(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
}
static void dwceqos_set_speed(struct net_local *lp)
{
struct phy_device *phydev = lp->phy_dev;
u32 regval;
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_CFG);
regval &= ~(DWCEQOS_MAC_CFG_PS | DWCEQOS_MAC_CFG_FES |
DWCEQOS_MAC_CFG_DM);
if (phydev->duplex)
regval |= DWCEQOS_MAC_CFG_DM;
if (phydev->speed == SPEED_10) {
regval |= DWCEQOS_MAC_CFG_PS;
} else if (phydev->speed == SPEED_100) {
regval |= DWCEQOS_MAC_CFG_PS |
DWCEQOS_MAC_CFG_FES;
} else if (phydev->speed != SPEED_1000) {
netdev_err(lp->ndev,
"unknown PHY speed %d\n",
phydev->speed);
return;
}
dwceqos_write(lp, REG_DWCEQOS_MAC_CFG, regval);
}
static void dwceqos_adjust_link(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
struct phy_device *phydev = lp->phy_dev;
int status_change = 0;
if (phydev->link) {
if ((lp->speed != phydev->speed) ||
(lp->duplex != phydev->duplex)) {
dwceqos_set_speed(lp);
lp->speed = phydev->speed;
lp->duplex = phydev->duplex;
status_change = 1;
}
if (lp->flowcontrol.autoneg) {
lp->flowcontrol.rx = phydev->pause ||
phydev->asym_pause;
lp->flowcontrol.tx = phydev->pause ||
phydev->asym_pause;
}
if (lp->flowcontrol.rx != lp->flowcontrol.rx_current) {
if (netif_msg_link(lp))
netdev_dbg(ndev, "set rx flow to %d\n",
lp->flowcontrol.rx);
dwceqos_set_rx_flowcontrol(lp, lp->flowcontrol.rx);
lp->flowcontrol.rx_current = lp->flowcontrol.rx;
}
if (lp->flowcontrol.tx != lp->flowcontrol.tx_current) {
if (netif_msg_link(lp))
netdev_dbg(ndev, "set tx flow to %d\n",
lp->flowcontrol.tx);
dwceqos_set_tx_flowcontrol(lp, lp->flowcontrol.tx);
lp->flowcontrol.tx_current = lp->flowcontrol.tx;
}
}
if (phydev->link != lp->link) {
lp->link = phydev->link;
status_change = 1;
}
if (status_change) {
if (phydev->link) {
lp->ndev->trans_start = jiffies;
dwceqos_link_up(lp);
} else {
dwceqos_link_down(lp);
}
phy_print_status(phydev);
}
}
static int dwceqos_mii_probe(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
struct phy_device *phydev = NULL;
if (lp->phy_node) {
phydev = of_phy_connect(lp->ndev,
lp->phy_node,
&dwceqos_adjust_link,
0,
lp->phy_interface);
if (!phydev) {
netdev_err(ndev, "no PHY found\n");
return -1;
}
} else {
netdev_err(ndev, "no PHY configured\n");
return -ENODEV;
}
if (netif_msg_probe(lp))
netdev_dbg(lp->ndev,
"phydev %p, phydev->phy_id 0xa%x, phydev->addr 0x%x\n",
phydev, phydev->phy_id, phydev->addr);
phydev->supported &= PHY_GBIT_FEATURES;
lp->link = 0;
lp->speed = 0;
lp->duplex = DUPLEX_UNKNOWN;
lp->phy_dev = phydev;
if (netif_msg_probe(lp)) {
netdev_dbg(lp->ndev, "phy_addr 0x%x, phy_id 0x%08x\n",
lp->phy_dev->addr, lp->phy_dev->phy_id);
netdev_dbg(lp->ndev, "attach [%s] phy driver\n",
lp->phy_dev->drv->name);
}
return 0;
}
static void dwceqos_alloc_rxring_desc(struct net_local *lp, int index)
{
struct sk_buff *new_skb;
dma_addr_t new_skb_baddr = 0;
new_skb = netdev_alloc_skb(lp->ndev, DWCEQOS_RX_BUF_SIZE);
if (!new_skb) {
netdev_err(lp->ndev, "alloc_skb error for desc %d\n", index);
goto err_out;
}
new_skb_baddr = dma_map_single(lp->ndev->dev.parent,
new_skb->data, DWCEQOS_RX_BUF_SIZE,
DMA_FROM_DEVICE);
if (dma_mapping_error(lp->ndev->dev.parent, new_skb_baddr)) {
netdev_err(lp->ndev, "DMA map error\n");
dev_kfree_skb(new_skb);
new_skb = NULL;
goto err_out;
}
lp->rx_descs[index].des0 = new_skb_baddr;
lp->rx_descs[index].des1 = 0;
lp->rx_descs[index].des2 = 0;
lp->rx_descs[index].des3 = DWCEQOS_DMA_RDES3_INTE |
DWCEQOS_DMA_RDES3_BUF1V |
DWCEQOS_DMA_RDES3_OWN;
lp->rx_skb[index].mapping = new_skb_baddr;
lp->rx_skb[index].len = DWCEQOS_RX_BUF_SIZE;
err_out:
lp->rx_skb[index].skb = new_skb;
}
static void dwceqos_clean_rings(struct net_local *lp)
{
int i;
if (lp->rx_skb) {
for (i = 0; i < DWCEQOS_RX_DCNT; i++) {
if (lp->rx_skb[i].skb) {
dma_unmap_single(lp->ndev->dev.parent,
lp->rx_skb[i].mapping,
lp->rx_skb[i].len,
DMA_FROM_DEVICE);
dev_kfree_skb(lp->rx_skb[i].skb);
lp->rx_skb[i].skb = NULL;
lp->rx_skb[i].mapping = 0;
}
}
}
if (lp->tx_skb) {
for (i = 0; i < DWCEQOS_TX_DCNT; i++) {
if (lp->tx_skb[i].skb) {
dev_kfree_skb(lp->tx_skb[i].skb);
lp->tx_skb[i].skb = NULL;
}
if (lp->tx_skb[i].mapping) {
dma_unmap_single(lp->ndev->dev.parent,
lp->tx_skb[i].mapping,
lp->tx_skb[i].len,
DMA_TO_DEVICE);
lp->tx_skb[i].mapping = 0;
}
}
}
}
static void dwceqos_descriptor_free(struct net_local *lp)
{
int size;
dwceqos_clean_rings(lp);
kfree(lp->tx_skb);
lp->tx_skb = NULL;
kfree(lp->rx_skb);
lp->rx_skb = NULL;
size = DWCEQOS_RX_DCNT * sizeof(struct dwceqos_dma_desc);
if (lp->rx_descs) {
dma_free_coherent(lp->ndev->dev.parent, size,
(void *)(lp->rx_descs), lp->rx_descs_addr);
lp->rx_descs = NULL;
}
size = DWCEQOS_TX_DCNT * sizeof(struct dwceqos_dma_desc);
if (lp->tx_descs) {
dma_free_coherent(lp->ndev->dev.parent, size,
(void *)(lp->tx_descs), lp->tx_descs_addr);
lp->tx_descs = NULL;
}
}
static int dwceqos_descriptor_init(struct net_local *lp)
{
int size;
u32 i;
lp->gso_size = 0;
lp->tx_skb = NULL;
lp->rx_skb = NULL;
lp->rx_descs = NULL;
lp->tx_descs = NULL;
lp->rx_cur = 0;
lp->tx_cur = 0;
lp->tx_next = 0;
lp->tx_free = DWCEQOS_TX_DCNT;
size = DWCEQOS_RX_DCNT * sizeof(struct ring_desc);
lp->rx_skb = kzalloc(size, GFP_KERNEL);
if (!lp->rx_skb)
goto err_out;
size = DWCEQOS_TX_DCNT * sizeof(struct ring_desc);
lp->tx_skb = kzalloc(size, GFP_KERNEL);
if (!lp->tx_skb)
goto err_out;
size = DWCEQOS_RX_DCNT * sizeof(struct dwceqos_dma_desc);
lp->rx_descs = dma_alloc_coherent(lp->ndev->dev.parent, size,
&lp->rx_descs_addr, 0);
if (!lp->rx_descs)
goto err_out;
lp->rx_descs_tail_addr = lp->rx_descs_addr +
sizeof(struct dwceqos_dma_desc) * DWCEQOS_RX_DCNT;
size = DWCEQOS_TX_DCNT * sizeof(struct dwceqos_dma_desc);
lp->tx_descs = dma_alloc_coherent(lp->ndev->dev.parent, size,
&lp->tx_descs_addr, 0);
if (!lp->tx_descs)
goto err_out;
lp->tx_descs_tail_addr = lp->tx_descs_addr +
sizeof(struct dwceqos_dma_desc) * DWCEQOS_TX_DCNT;
for (i = 0; i < DWCEQOS_RX_DCNT; ++i) {
dwceqos_alloc_rxring_desc(lp, i);
if (!(lp->rx_skb[lp->rx_cur].skb))
goto err_out;
}
for (i = 0; i < DWCEQOS_TX_DCNT; ++i) {
lp->tx_descs[i].des0 = 0;
lp->tx_descs[i].des1 = 0;
lp->tx_descs[i].des2 = 0;
lp->tx_descs[i].des3 = 0;
}
wmb();
return 0;
err_out:
dwceqos_descriptor_free(lp);
return -ENOMEM;
}
static int dwceqos_packet_avail(struct net_local *lp)
{
return !(lp->rx_descs[lp->rx_cur].des3 & DWCEQOS_DMA_RDES3_OWN);
}
static void dwceqos_get_hwfeatures(struct net_local *lp)
{
lp->feature0 = dwceqos_read(lp, REG_DWCEQOS_MAC_HW_FEATURE0);
lp->feature1 = dwceqos_read(lp, REG_DWCEQOS_MAC_HW_FEATURE1);
lp->feature2 = dwceqos_read(lp, REG_DWCEQOS_MAC_HW_FEATURE2);
}
static void dwceqos_dma_enable_txirq(struct net_local *lp)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_IE);
regval |= DWCEQOS_DMA_CH0_IE_TIE;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_IE, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_dma_disable_txirq(struct net_local *lp)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_IE);
regval &= ~DWCEQOS_DMA_CH0_IE_TIE;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_IE, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_dma_enable_rxirq(struct net_local *lp)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_IE);
regval |= DWCEQOS_DMA_CH0_IE_RIE;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_IE, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_dma_disable_rxirq(struct net_local *lp)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_IE);
regval &= ~DWCEQOS_DMA_CH0_IE_RIE;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_IE, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_enable_mmc_interrupt(struct net_local *lp)
{
dwceqos_write(lp, REG_DWCEQOS_MMC_RXIRQMASK, 0);
dwceqos_write(lp, REG_DWCEQOS_MMC_TXIRQMASK, 0);
}
static int dwceqos_mii_init(struct net_local *lp)
{
int ret = -ENXIO, i;
struct resource res;
struct device_node *mdionode;
mdionode = of_get_child_by_name(lp->pdev->dev.of_node, "mdio");
if (!mdionode)
return 0;
lp->mii_bus = mdiobus_alloc();
if (!lp->mii_bus) {
ret = -ENOMEM;
goto err_out;
}
lp->mii_bus->name = "DWCEQOS MII bus";
lp->mii_bus->read = &dwceqos_mdio_read;
lp->mii_bus->write = &dwceqos_mdio_write;
lp->mii_bus->priv = lp;
lp->mii_bus->parent = &lp->ndev->dev;
lp->mii_bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!lp->mii_bus->irq) {
ret = -ENOMEM;
goto err_out_free_mdiobus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
lp->mii_bus->irq[i] = PHY_POLL;
of_address_to_resource(lp->pdev->dev.of_node, 0, &res);
snprintf(lp->mii_bus->id, MII_BUS_ID_SIZE, "%.8llx",
(unsigned long long)res.start);
if (of_mdiobus_register(lp->mii_bus, mdionode))
goto err_out_free_mdio_irq;
return 0;
err_out_free_mdio_irq:
kfree(lp->mii_bus->irq);
err_out_free_mdiobus:
mdiobus_free(lp->mii_bus);
err_out:
of_node_put(mdionode);
return ret;
}
static void dwceqos_reset_hw(struct net_local *lp)
{
int i = 5000;
u32 reg;
reg = dwceqos_read(lp, REG_DWCEQOS_MAC_CFG);
reg &= ~(DWCEQOS_MAC_CFG_PS | DWCEQOS_MAC_CFG_FES);
reg |= DWCEQOS_MAC_CFG_DM;
dwceqos_write(lp, REG_DWCEQOS_MAC_CFG, reg);
dwceqos_write(lp, REG_DWCEQOS_DMA_MODE, DWCEQOS_DMA_MODE_SWR);
do {
udelay(100);
i--;
reg = dwceqos_read(lp, REG_DWCEQOS_DMA_MODE);
} while ((reg & DWCEQOS_DMA_MODE_SWR) && i);
if (!i)
netdev_err(lp->ndev, "DMA reset timed out!\n");
}
static void dwceqos_fatal_bus_error(struct net_local *lp, u32 dma_status)
{
if (dma_status & DWCEQOS_DMA_CH0_IS_TEB) {
netdev_err(lp->ndev, "txdma bus error %s %s (status=%08x)\n",
dma_status & DWCEQOS_DMA_CH0_IS_TX_ERR_READ ?
"read" : "write",
dma_status & DWCEQOS_DMA_CH0_IS_TX_ERR_DESCR ?
"descr" : "data",
dma_status);
print_status(lp);
}
if (dma_status & DWCEQOS_DMA_CH0_IS_REB) {
netdev_err(lp->ndev, "rxdma bus error %s %s (status=%08x)\n",
dma_status & DWCEQOS_DMA_CH0_IS_RX_ERR_READ ?
"read" : "write",
dma_status & DWCEQOS_DMA_CH0_IS_RX_ERR_DESCR ?
"descr" : "data",
dma_status);
print_status(lp);
}
}
static void dwceqos_mmc_interrupt(struct net_local *lp)
{
unsigned long flags;
spin_lock_irqsave(&lp->stats_lock, flags);
dwceqos_read_mmc_counters(lp,
dwceqos_read(lp, REG_DWCEQOS_MMC_RXIRQ),
dwceqos_read(lp, REG_DWCEQOS_MMC_TXIRQ));
spin_unlock_irqrestore(&lp->stats_lock, flags);
}
static void dwceqos_mac_interrupt(struct net_local *lp)
{
u32 cause;
cause = dwceqos_read(lp, REG_DWCEQOS_MAC_IS);
if (cause & DWCEQOS_MAC_IS_MMC_INT)
dwceqos_mmc_interrupt(lp);
}
static irqreturn_t dwceqos_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct net_local *lp = netdev_priv(ndev);
u32 cause;
u32 dma_status;
irqreturn_t ret = IRQ_NONE;
cause = dwceqos_read(lp, REG_DWCEQOS_DMA_IS);
if (cause & DWCEQOS_DMA_IS_DC0IS) {
dma_status = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_STA);
if (dma_status & DWCEQOS_DMA_CH0_IS_TI) {
tasklet_schedule(&lp->tx_bdreclaim_tasklet);
dwceqos_dma_disable_txirq(lp);
}
if (dma_status & DWCEQOS_DMA_CH0_IS_RI) {
dwceqos_dma_disable_rxirq(lp);
napi_schedule(&lp->napi);
}
if (unlikely(dma_status & DWCEQOS_DMA_CH0_IS_FBE)) {
dwceqos_fatal_bus_error(lp, dma_status);
dma_status |= DWCEQOS_DMA_CH0_IS_TEB |
DWCEQOS_DMA_CH0_IS_REB;
}
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_STA, dma_status);
ret = IRQ_HANDLED;
}
if (cause & DWCEQOS_DMA_IS_MTLIS) {
u32 val = dwceqos_read(lp, REG_DWCEQOS_MTL_Q0_ISCTRL);
dwceqos_write(lp, REG_DWCEQOS_MTL_Q0_ISCTRL, val);
ret = IRQ_HANDLED;
}
if (cause & DWCEQOS_DMA_IS_MACIS) {
dwceqos_mac_interrupt(lp);
ret = IRQ_HANDLED;
}
return ret;
}
static void dwceqos_set_rx_flowcontrol(struct net_local *lp, bool enable)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_RX_FLOW_CTRL);
if (enable)
regval |= DWCEQOS_MAC_RX_FLOW_CTRL_RFE;
else
regval &= ~DWCEQOS_MAC_RX_FLOW_CTRL_RFE;
dwceqos_write(lp, REG_DWCEQOS_MAC_RX_FLOW_CTRL, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_set_tx_flowcontrol(struct net_local *lp, bool enable)
{
u32 regval;
unsigned long flags;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MTL_RXQ0_OPER);
if (enable)
regval |= DWCEQOS_MTL_RXQ_EHFC;
else
regval &= ~DWCEQOS_MTL_RXQ_EHFC;
dwceqos_write(lp, REG_DWCEQOS_MTL_RXQ0_OPER, regval);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_Q0_TX_FLOW);
if (enable)
regval |= DWCEQOS_MAC_Q0_TX_FLOW_TFE;
else
regval &= ~DWCEQOS_MAC_Q0_TX_FLOW_TFE;
dwceqos_write(lp, REG_DWCEQOS_MAC_Q0_TX_FLOW, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_configure_flow_control(struct net_local *lp)
{
u32 regval;
unsigned long flags;
int RQS, RFD, RFA;
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MTL_RXQ0_OPER);
RQS = ((regval >> 20) & 0x3FF) + 1;
RQS /= 2;
RFD = RQS / 2 - 2;
RFA = RQS / 8 - 2;
regval = (regval & 0xFFF000FF) | (RFD << 14) | (RFA << 8);
if (RFD >= 0 && RFA >= 0) {
dwceqos_write(lp, REG_DWCEQOS_MTL_RXQ0_OPER, regval);
} else {
netdev_warn(lp->ndev,
"FIFO too small for flow control.");
}
regval = DWCEQOS_MAC_Q0_TX_FLOW_PT(256) |
DWCEQOS_MAC_Q0_TX_FLOW_PLT_4_SLOTS;
dwceqos_write(lp, REG_DWCEQOS_MAC_Q0_TX_FLOW, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
static void dwceqos_configure_clock(struct net_local *lp)
{
unsigned long rate_mhz = clk_get_rate(lp->apb_pclk) / 1000000;
BUG_ON(!rate_mhz);
dwceqos_write(lp,
REG_DWCEQOS_MAC_1US_TIC_COUNTER,
DWCEQOS_MAC_1US_TIC_COUNTER_VAL(rate_mhz - 1));
}
static void dwceqos_configure_bus(struct net_local *lp)
{
u32 sysbus_reg;
sysbus_reg = DWCEQOS_DMA_SYSBUS_MODE_AAL;
if (lp->bus_cfg.en_lpi)
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_EN_LPI;
if (lp->bus_cfg.burst_map)
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_BURST(
lp->bus_cfg.burst_map);
else
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_BURST(
DWCEQOS_DMA_SYSBUS_MODE_BURST_DEFAULT);
if (lp->bus_cfg.read_requests)
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_RD_OSR_LIMIT(
lp->bus_cfg.read_requests - 1);
else
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_RD_OSR_LIMIT(
DWCEQOS_DMA_SYSBUS_MODE_RD_OSR_LIMIT_DEFAULT);
if (lp->bus_cfg.write_requests)
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_WR_OSR_LIMIT(
lp->bus_cfg.write_requests - 1);
else
sysbus_reg |= DWCEQOS_DMA_SYSBUS_MODE_WR_OSR_LIMIT(
DWCEQOS_DMA_SYSBUS_MODE_WR_OSR_LIMIT_DEFAULT);
if (netif_msg_hw(lp))
netdev_dbg(lp->ndev, "SysbusMode %#X\n", sysbus_reg);
dwceqos_write(lp, REG_DWCEQOS_DMA_SYSBUS_MODE, sysbus_reg);
}
static void dwceqos_init_hw(struct net_local *lp)
{
u32 regval;
u32 buswidth;
u32 dma_skip;
dwceqos_reset_hw(lp);
dwceqos_configure_bus(lp);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TXDESC_TAIL, 0xF);
regval = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_TXDESC_TAIL);
buswidth = (regval ^ 0xF) + 1;
dma_skip = (sizeof(struct dwceqos_dma_desc) - 16) / buswidth;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_CTRL,
DWCEQOS_DMA_CH_CTRL_DSL(dma_skip) |
DWCEQOS_DMA_CH_CTRL_PBLX8);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TXDESC_LEN, DWCEQOS_TX_DCNT - 1);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_RXDESC_LEN, DWCEQOS_RX_DCNT - 1);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TXDESC_LIST,
(u32)lp->tx_descs_addr);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_RXDESC_LIST,
(u32)lp->rx_descs_addr);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TXDESC_TAIL,
lp->tx_descs_tail_addr);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_RXDESC_TAIL,
lp->rx_descs_tail_addr);
if (lp->bus_cfg.tx_pbl)
regval = DWCEQOS_DMA_CH_CTRL_PBL(lp->bus_cfg.tx_pbl);
else
regval = DWCEQOS_DMA_CH_CTRL_PBL(2);
if (lp->feature1 & DWCEQOS_MAC_HW_FEATURE1_TSOEN)
regval |= DWCEQOS_DMA_CH_TX_TSE;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TX_CTRL, regval);
if (lp->bus_cfg.rx_pbl)
regval = DWCEQOS_DMA_CH_CTRL_PBL(lp->bus_cfg.rx_pbl);
else
regval = DWCEQOS_DMA_CH_CTRL_PBL(2);
regval |= DWCEQOS_DMA_CH_RX_CTRL_BUFSIZE(DWCEQOS_DWCEQOS_RX_BUF_SIZE);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_RX_CTRL, regval);
regval |= DWCEQOS_DMA_CH_CTRL_START;
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_RX_CTRL, regval);
regval = DWCEQOS_MTL_SCHALG_STRICT;
dwceqos_write(lp, REG_DWCEQOS_MTL_OPER, regval);
regval = DWCEQOS_MTL_TXQ_SIZE(
DWCEQOS_MAC_HW_FEATURE1_TXFIFOSIZE(lp->feature1)) |
DWCEQOS_MTL_TXQ_TXQEN | DWCEQOS_MTL_TXQ_TSF |
DWCEQOS_MTL_TXQ_TTC512;
dwceqos_write(lp, REG_DWCEQOS_MTL_TXQ0_OPER, regval);
regval = DWCEQOS_MTL_RXQ_SIZE(
DWCEQOS_MAC_HW_FEATURE1_RXFIFOSIZE(lp->feature1)) |
DWCEQOS_MTL_RXQ_FUP | DWCEQOS_MTL_RXQ_FEP | DWCEQOS_MTL_RXQ_RSF;
dwceqos_write(lp, REG_DWCEQOS_MTL_RXQ0_OPER, regval);
dwceqos_configure_flow_control(lp);
dwceqos_set_umac_addr(lp, lp->ndev->dev_addr, 0);
lp->eee_enabled = 0;
dwceqos_configure_clock(lp);
dwceqos_write(lp, REG_DWCEQOS_MMC_RXIRQMASK, ~0u);
dwceqos_write(lp, REG_DWCEQOS_MMC_TXIRQMASK, ~0u);
lp->mmc_rx_counters_mask = dwceqos_read(lp, REG_DWCEQOS_MMC_RXIRQMASK);
lp->mmc_tx_counters_mask = dwceqos_read(lp, REG_DWCEQOS_MMC_TXIRQMASK);
dwceqos_write(lp, REG_DWCEQOS_MMC_CTRL, DWCEQOS_MMC_CTRL_CNTRST |
DWCEQOS_MMC_CTRL_RSTONRD);
dwceqos_enable_mmc_interrupt(lp);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_IE,
DWCEQOS_DMA_CH0_IE_NIE |
DWCEQOS_DMA_CH0_IE_RIE | DWCEQOS_DMA_CH0_IE_TIE |
DWCEQOS_DMA_CH0_IE_AIE |
DWCEQOS_DMA_CH0_IE_FBEE);
dwceqos_write(lp, REG_DWCEQOS_MAC_IE, 0);
dwceqos_write(lp, REG_DWCEQOS_MAC_CFG, DWCEQOS_MAC_CFG_IPC |
DWCEQOS_MAC_CFG_DM | DWCEQOS_MAC_CFG_TE | DWCEQOS_MAC_CFG_RE);
regval = dwceqos_read(lp, REG_DWCEQOS_DMA_CH0_TX_CTRL);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TX_CTRL,
regval | DWCEQOS_DMA_CH_CTRL_START);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_CFG);
dwceqos_write(lp, REG_DWCEQOS_MAC_CFG,
regval | DWCEQOS_MAC_CFG_TE | DWCEQOS_MAC_CFG_RE);
}
static void dwceqos_tx_reclaim(unsigned long data)
{
struct net_device *ndev = (struct net_device *)data;
struct net_local *lp = netdev_priv(ndev);
unsigned int tx_bytes = 0;
unsigned int tx_packets = 0;
spin_lock(&lp->tx_lock);
while (lp->tx_free < DWCEQOS_TX_DCNT) {
struct dwceqos_dma_desc *dd = &lp->tx_descs[lp->tx_cur];
struct ring_desc *rd = &lp->tx_skb[lp->tx_cur];
if (dd->des3 & DWCEQOS_DMA_TDES3_OWN)
break;
if (rd->mapping)
dma_unmap_single(ndev->dev.parent, rd->mapping, rd->len,
DMA_TO_DEVICE);
if (unlikely(rd->skb)) {
++tx_packets;
tx_bytes += rd->skb->len;
dev_consume_skb_any(rd->skb);
}
rd->skb = NULL;
rd->mapping = 0;
lp->tx_free++;
lp->tx_cur = (lp->tx_cur + 1) % DWCEQOS_TX_DCNT;
if ((dd->des3 & DWCEQOS_DMA_TDES3_LD) &&
(dd->des3 & DWCEQOS_DMA_RDES3_ES)) {
if (netif_msg_tx_err(lp))
netdev_err(ndev, "TX Error, TDES3 = 0x%x\n",
dd->des3);
if (netif_msg_hw(lp))
print_status(lp);
}
}
spin_unlock(&lp->tx_lock);
netdev_completed_queue(ndev, tx_packets, tx_bytes);
dwceqos_dma_enable_txirq(lp);
netif_wake_queue(ndev);
}
static int dwceqos_rx(struct net_local *lp, int budget)
{
struct sk_buff *skb;
u32 tot_size = 0;
unsigned int n_packets = 0;
unsigned int n_descs = 0;
u32 len;
struct dwceqos_dma_desc *dd;
struct sk_buff *new_skb;
dma_addr_t new_skb_baddr = 0;
while (n_descs < budget) {
if (!dwceqos_packet_avail(lp))
break;
new_skb = netdev_alloc_skb(lp->ndev, DWCEQOS_RX_BUF_SIZE);
if (!new_skb) {
netdev_err(lp->ndev, "no memory for new sk_buff\n");
break;
}
new_skb_baddr = (u32)dma_map_single(lp->ndev->dev.parent,
new_skb->data,
DWCEQOS_RX_BUF_SIZE,
DMA_FROM_DEVICE);
if (dma_mapping_error(lp->ndev->dev.parent, new_skb_baddr)) {
netdev_err(lp->ndev, "DMA map error\n");
dev_kfree_skb(new_skb);
break;
}
dma_rmb();
dd = &lp->rx_descs[lp->rx_cur];
len = DWCEQOS_DMA_RDES3_PL(dd->des3);
skb = lp->rx_skb[lp->rx_cur].skb;
dma_unmap_single(lp->ndev->dev.parent,
lp->rx_skb[lp->rx_cur].mapping,
lp->rx_skb[lp->rx_cur].len, DMA_FROM_DEVICE);
if ((dd->des3 & DWCEQOS_DMA_RDES3_ES) ||
(dd->des1 & DWCEQOS_DMA_RDES1_IPCE)) {
dev_kfree_skb(skb);
skb = NULL;
} else {
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, lp->ndev);
switch (dd->des1 & DWCEQOS_DMA_RDES1_PT) {
case DWCEQOS_DMA_RDES1_PT_UDP:
case DWCEQOS_DMA_RDES1_PT_TCP:
case DWCEQOS_DMA_RDES1_PT_ICMP:
skb->ip_summed = CHECKSUM_UNNECESSARY;
break;
default:
skb->ip_summed = CHECKSUM_NONE;
break;
}
}
if (unlikely(!skb)) {
if (netif_msg_rx_err(lp))
netdev_dbg(lp->ndev, "rx error: des3=%X\n",
lp->rx_descs[lp->rx_cur].des3);
} else {
tot_size += skb->len;
n_packets++;
netif_receive_skb(skb);
}
lp->rx_descs[lp->rx_cur].des0 = new_skb_baddr;
lp->rx_descs[lp->rx_cur].des1 = 0;
lp->rx_descs[lp->rx_cur].des2 = 0;
wmb();
lp->rx_descs[lp->rx_cur].des3 = DWCEQOS_DMA_RDES3_INTE |
DWCEQOS_DMA_RDES3_OWN |
DWCEQOS_DMA_RDES3_BUF1V;
lp->rx_skb[lp->rx_cur].mapping = new_skb_baddr;
lp->rx_skb[lp->rx_cur].len = DWCEQOS_RX_BUF_SIZE;
lp->rx_skb[lp->rx_cur].skb = new_skb;
n_descs++;
lp->rx_cur = (lp->rx_cur + 1) % DWCEQOS_RX_DCNT;
}
wmb();
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_STA, DWCEQOS_DMA_CH0_IS_RI);
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_RXDESC_TAIL,
lp->rx_descs_tail_addr);
return n_descs;
}
static int dwceqos_rx_poll(struct napi_struct *napi, int budget)
{
struct net_local *lp = container_of(napi, struct net_local, napi);
int work_done = 0;
work_done = dwceqos_rx(lp, budget - work_done);
if (!dwceqos_packet_avail(lp) && work_done < budget) {
napi_complete(napi);
dwceqos_dma_enable_rxirq(lp);
} else {
work_done = budget;
}
return work_done;
}
static void dwceqos_reinit_for_txtimeout(struct work_struct *data)
{
struct net_local *lp = container_of(data, struct net_local,
txtimeout_reinit);
netdev_err(lp->ndev, "transmit timeout %d s, resetting...\n",
DWCEQOS_TX_TIMEOUT);
if (netif_msg_hw(lp))
print_status(lp);
rtnl_lock();
dwceqos_stop(lp->ndev);
dwceqos_open(lp->ndev);
rtnl_unlock();
}
static inline int dwceqos_probe_config_dt(struct platform_device *pdev)
{
struct net_device *ndev;
struct net_local *lp;
const void *mac_address;
struct dwceqos_bus_cfg *bus_cfg;
struct device_node *np = pdev->dev.of_node;
ndev = platform_get_drvdata(pdev);
lp = netdev_priv(ndev);
bus_cfg = &lp->bus_cfg;
mac_address = of_get_mac_address(pdev->dev.of_node);
if (mac_address)
ether_addr_copy(ndev->dev_addr, mac_address);
lp->en_tx_lpi_clockgating = of_property_read_bool(np,
"snps,en-tx-lpi-clockgating");
bus_cfg->en_lpi = of_property_read_bool(np, "snps,en-lpi");
of_property_read_u32(np, "snps,write-requests",
&bus_cfg->write_requests);
of_property_read_u32(np, "snps,read-requests", &bus_cfg->read_requests);
of_property_read_u32(np, "snps,burst-map", &bus_cfg->burst_map);
of_property_read_u32(np, "snps,txpbl", &bus_cfg->tx_pbl);
of_property_read_u32(np, "snps,rxpbl", &bus_cfg->rx_pbl);
netdev_dbg(ndev, "BusCfg: lpi:%u wr:%u rr:%u bm:%X rxpbl:%u txpbl:%d\n",
bus_cfg->en_lpi,
bus_cfg->write_requests,
bus_cfg->read_requests,
bus_cfg->burst_map,
bus_cfg->rx_pbl,
bus_cfg->tx_pbl);
return 0;
}
static int dwceqos_open(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
int res;
dwceqos_reset_state(lp);
res = dwceqos_descriptor_init(lp);
if (res) {
netdev_err(ndev, "Unable to allocate DMA memory, rc %d\n", res);
return res;
}
netdev_reset_queue(ndev);
napi_enable(&lp->napi);
phy_start(lp->phy_dev);
dwceqos_init_hw(lp);
netif_start_queue(ndev);
tasklet_enable(&lp->tx_bdreclaim_tasklet);
return 0;
}
static bool dweqos_is_tx_dma_suspended(struct net_local *lp)
{
u32 reg;
reg = dwceqos_read(lp, REG_DWCEQOS_DMA_DEBUG_ST0);
reg = DMA_GET_TX_STATE_CH0(reg);
return reg == DMA_TX_CH_SUSPENDED;
}
static void dwceqos_drain_dma(struct net_local *lp)
{
size_t limit = (DWCEQOS_TX_DCNT * 1250) / 100;
while (!dweqos_is_tx_dma_suspended(lp) && limit--)
usleep_range(100, 200);
}
static int dwceqos_stop(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
phy_stop(lp->phy_dev);
tasklet_disable(&lp->tx_bdreclaim_tasklet);
netif_stop_queue(ndev);
napi_disable(&lp->napi);
dwceqos_drain_dma(lp);
netif_tx_lock(lp->ndev);
dwceqos_reset_hw(lp);
dwceqos_descriptor_free(lp);
netif_tx_unlock(lp->ndev);
return 0;
}
static void dwceqos_dmadesc_set_ctx(struct net_local *lp,
unsigned short gso_size)
{
struct dwceqos_dma_desc *dd = &lp->tx_descs[lp->tx_next];
dd->des0 = 0;
dd->des1 = 0;
dd->des2 = gso_size;
dd->des3 = DWCEQOS_DMA_TDES3_CTXT | DWCEQOS_DMA_TDES3_TCMSSV;
lp->tx_next = (lp->tx_next + 1) % DWCEQOS_TX_DCNT;
}
static void dwceqos_tx_poll_demand(struct net_local *lp)
{
dwceqos_write(lp, REG_DWCEQOS_DMA_CH0_TXDESC_TAIL,
lp->tx_descs_tail_addr);
}
static void dwceqos_tx_prepare(struct sk_buff *skb, struct net_local *lp,
struct dwceqos_tx *tx)
{
size_t n = 1;
size_t i;
if (skb_is_gso(skb) && skb_shinfo(skb)->gso_size != lp->gso_size)
++n;
for (i = 0; i < skb_shinfo(skb)->nr_frags; ++i) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
n += (skb_frag_size(frag) + BYTES_PER_DMA_DESC - 1) /
BYTES_PER_DMA_DESC;
}
tx->nr_descriptors = n;
tx->initial_descriptor = lp->tx_next;
tx->last_descriptor = lp->tx_next;
tx->prev_gso_size = lp->gso_size;
tx->network_header_len = skb_transport_offset(skb);
if (skb_is_gso(skb))
tx->network_header_len += tcp_hdrlen(skb);
}
static int dwceqos_tx_linear(struct sk_buff *skb, struct net_local *lp,
struct dwceqos_tx *tx)
{
struct ring_desc *rd;
struct dwceqos_dma_desc *dd;
size_t payload_len;
dma_addr_t dma_handle;
if (skb_is_gso(skb) && skb_shinfo(skb)->gso_size != lp->gso_size) {
dwceqos_dmadesc_set_ctx(lp, skb_shinfo(skb)->gso_size);
lp->gso_size = skb_shinfo(skb)->gso_size;
}
dma_handle = dma_map_single(lp->ndev->dev.parent, skb->data,
skb_headlen(skb), DMA_TO_DEVICE);
if (dma_mapping_error(lp->ndev->dev.parent, dma_handle)) {
netdev_err(lp->ndev, "TX DMA Mapping error\n");
return -ENOMEM;
}
rd = &lp->tx_skb[lp->tx_next];
dd = &lp->tx_descs[lp->tx_next];
rd->skb = NULL;
rd->len = skb_headlen(skb);
rd->mapping = dma_handle;
dd->des0 = dma_handle;
if (skb_is_gso(skb)) {
payload_len = skb_headlen(skb) - tx->network_header_len;
if (payload_len)
dd->des1 = dma_handle + tx->network_header_len;
dd->des2 = tx->network_header_len |
DWCEQOS_DMA_DES2_B2L(payload_len);
dd->des3 = DWCEQOS_DMA_TDES3_TSE |
DWCEQOS_DMA_DES3_THL((tcp_hdrlen(skb) / 4)) |
(skb->len - tx->network_header_len);
} else {
dd->des1 = 0;
dd->des2 = skb_headlen(skb);
dd->des3 = skb->len;
switch (skb->ip_summed) {
case CHECKSUM_PARTIAL:
dd->des3 |= DWCEQOS_DMA_TDES3_CA;
case CHECKSUM_NONE:
case CHECKSUM_UNNECESSARY:
case CHECKSUM_COMPLETE:
default:
break;
}
}
dd->des3 |= DWCEQOS_DMA_TDES3_FD;
if (lp->tx_next != tx->initial_descriptor)
dd->des3 |= DWCEQOS_DMA_TDES3_OWN;
tx->last_descriptor = lp->tx_next;
lp->tx_next = (lp->tx_next + 1) % DWCEQOS_TX_DCNT;
return 0;
}
static int dwceqos_tx_frags(struct sk_buff *skb, struct net_local *lp,
struct dwceqos_tx *tx)
{
struct ring_desc *rd = NULL;
struct dwceqos_dma_desc *dd;
dma_addr_t dma_handle;
size_t i;
for (i = 0; i < skb_shinfo(skb)->nr_frags; ++i) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
size_t frag_size;
size_t consumed_size;
dma_handle = skb_frag_dma_map(lp->ndev->dev.parent, frag, 0,
skb_frag_size(frag),
DMA_TO_DEVICE);
if (dma_mapping_error(lp->ndev->dev.parent, dma_handle)) {
netdev_err(lp->ndev, "DMA Mapping error\n");
return -ENOMEM;
}
frag_size = skb_frag_size(frag);
consumed_size = 0;
while (consumed_size < frag_size) {
size_t dma_size = min_t(size_t, 16376,
frag_size - consumed_size);
rd = &lp->tx_skb[lp->tx_next];
memset(rd, 0, sizeof(*rd));
dd = &lp->tx_descs[lp->tx_next];
dd->des0 = dma_handle;
dd->des1 = 0;
dd->des2 = dma_size;
if (skb_is_gso(skb))
dd->des3 = (skb->len - tx->network_header_len);
else
dd->des3 = skb->len;
dd->des3 |= DWCEQOS_DMA_TDES3_OWN;
tx->last_descriptor = lp->tx_next;
lp->tx_next = (lp->tx_next + 1) % DWCEQOS_TX_DCNT;
consumed_size += dma_size;
}
rd->len = skb_frag_size(frag);
rd->mapping = dma_handle;
}
return 0;
}
static void dwceqos_tx_finalize(struct sk_buff *skb, struct net_local *lp,
struct dwceqos_tx *tx)
{
lp->tx_descs[tx->last_descriptor].des3 |= DWCEQOS_DMA_TDES3_LD;
lp->tx_descs[tx->last_descriptor].des2 |= DWCEQOS_DMA_TDES2_IOC;
lp->tx_skb[tx->last_descriptor].skb = skb;
wmb();
lp->tx_descs[tx->initial_descriptor].des3 |= DWCEQOS_DMA_TDES3_OWN;
wmb();
dwceqos_tx_poll_demand(lp);
}
static void dwceqos_tx_rollback(struct net_local *lp, struct dwceqos_tx *tx)
{
size_t i = tx->initial_descriptor;
while (i != lp->tx_next) {
if (lp->tx_skb[i].mapping)
dma_unmap_single(lp->ndev->dev.parent,
lp->tx_skb[i].mapping,
lp->tx_skb[i].len,
DMA_TO_DEVICE);
lp->tx_skb[i].mapping = 0;
lp->tx_skb[i].skb = NULL;
memset(&lp->tx_descs[i], 0, sizeof(lp->tx_descs[i]));
i = (i + 1) % DWCEQOS_TX_DCNT;
}
lp->tx_next = tx->initial_descriptor;
lp->gso_size = tx->prev_gso_size;
}
static int dwceqos_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
struct dwceqos_tx trans;
int err;
dwceqos_tx_prepare(skb, lp, &trans);
if (lp->tx_free < trans.nr_descriptors) {
netif_stop_queue(ndev);
return NETDEV_TX_BUSY;
}
err = dwceqos_tx_linear(skb, lp, &trans);
if (err)
goto tx_error;
err = dwceqos_tx_frags(skb, lp, &trans);
if (err)
goto tx_error;
WARN_ON(lp->tx_next !=
((trans.initial_descriptor + trans.nr_descriptors) %
DWCEQOS_TX_DCNT));
dwceqos_tx_finalize(skb, lp, &trans);
netdev_sent_queue(ndev, skb->len);
spin_lock_bh(&lp->tx_lock);
lp->tx_free -= trans.nr_descriptors;
spin_unlock_bh(&lp->tx_lock);
ndev->trans_start = jiffies;
return 0;
tx_error:
dwceqos_tx_rollback(lp, &trans);
dev_kfree_skb(skb);
return 0;
}
static int dwceqos_set_mac_address(struct net_device *ndev, void *addr)
{
struct net_local *lp = netdev_priv(ndev);
struct sockaddr *hwaddr = (struct sockaddr *)addr;
if (netif_running(ndev))
return -EBUSY;
if (!is_valid_ether_addr(hwaddr->sa_data))
return -EADDRNOTAVAIL;
memcpy(ndev->dev_addr, hwaddr->sa_data, ndev->addr_len);
dwceqos_set_umac_addr(lp, lp->ndev->dev_addr, 0);
return 0;
}
static void dwceqos_tx_timeout(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
queue_work(lp->txtimeout_handler_wq, &lp->txtimeout_reinit);
}
static void dwceqos_set_umac_addr(struct net_local *lp, unsigned char *addr,
unsigned int reg_n)
{
unsigned long data;
data = (addr[5] << 8) | addr[4];
dwceqos_write(lp, DWCEQOS_ADDR_HIGH(reg_n),
data | DWCEQOS_MAC_MAC_ADDR_HI_EN);
data = (addr[3] << 24) | (addr[2] << 16) | (addr[1] << 8) | addr[0];
dwceqos_write(lp, DWCEQOS_ADDR_LOW(reg_n), data);
}
static void dwceqos_disable_umac_addr(struct net_local *lp, unsigned int reg_n)
{
if (reg_n != 0)
dwceqos_write(lp, DWCEQOS_ADDR_HIGH(reg_n), 0);
}
static void dwceqos_set_rx_mode(struct net_device *ndev)
{
struct net_local *lp = netdev_priv(ndev);
u32 regval = 0;
u32 mc_filter[2];
int reg = 1;
struct netdev_hw_addr *ha;
unsigned int max_mac_addr;
max_mac_addr = DWCEQOS_MAX_PERFECT_ADDRESSES(lp->feature1);
if (ndev->flags & IFF_PROMISC) {
regval = DWCEQOS_MAC_PKT_FILT_PR;
} else if (((netdev_mc_count(ndev) > DWCEQOS_HASH_TABLE_SIZE) ||
(ndev->flags & IFF_ALLMULTI))) {
regval = DWCEQOS_MAC_PKT_FILT_PM;
dwceqos_write(lp, REG_DWCEQOS_HASTABLE_LO, 0xffffffff);
dwceqos_write(lp, REG_DWCEQOS_HASTABLE_HI, 0xffffffff);
} else if (!netdev_mc_empty(ndev)) {
regval = DWCEQOS_MAC_PKT_FILT_HMC;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, ndev) {
int bit_nr = bitrev32(~crc32_le(~0, ha->addr, 6)) >> 26;
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
dwceqos_write(lp, REG_DWCEQOS_HASTABLE_LO, mc_filter[0]);
dwceqos_write(lp, REG_DWCEQOS_HASTABLE_HI, mc_filter[1]);
}
if (netdev_uc_count(ndev) > max_mac_addr) {
regval |= DWCEQOS_MAC_PKT_FILT_PR;
} else {
netdev_for_each_uc_addr(ha, ndev) {
dwceqos_set_umac_addr(lp, ha->addr, reg);
reg++;
}
for (; reg < DWCEQOS_MAX_PERFECT_ADDRESSES(lp->feature1); reg++)
dwceqos_disable_umac_addr(lp, reg);
}
dwceqos_write(lp, REG_DWCEQOS_MAC_PKT_FILT, regval);
}
static void dwceqos_poll_controller(struct net_device *ndev)
{
disable_irq(ndev->irq);
dwceqos_interrupt(ndev->irq, ndev);
enable_irq(ndev->irq);
}
static void dwceqos_read_mmc_counters(struct net_local *lp, u32 rx_mask,
u32 tx_mask)
{
if (tx_mask & BIT(27))
lp->mmc_counters.txlpitranscntr +=
dwceqos_read(lp, DWC_MMC_TXLPITRANSCNTR);
if (tx_mask & BIT(26))
lp->mmc_counters.txpiuscntr +=
dwceqos_read(lp, DWC_MMC_TXLPIUSCNTR);
if (tx_mask & BIT(25))
lp->mmc_counters.txoversize_g +=
dwceqos_read(lp, DWC_MMC_TXOVERSIZE_G);
if (tx_mask & BIT(24))
lp->mmc_counters.txvlanpackets_g +=
dwceqos_read(lp, DWC_MMC_TXVLANPACKETS_G);
if (tx_mask & BIT(23))
lp->mmc_counters.txpausepackets +=
dwceqos_read(lp, DWC_MMC_TXPAUSEPACKETS);
if (tx_mask & BIT(22))
lp->mmc_counters.txexcessdef +=
dwceqos_read(lp, DWC_MMC_TXEXCESSDEF);
if (tx_mask & BIT(21))
lp->mmc_counters.txpacketcount_g +=
dwceqos_read(lp, DWC_MMC_TXPACKETCOUNT_G);
if (tx_mask & BIT(20))
lp->mmc_counters.txoctetcount_g +=
dwceqos_read(lp, DWC_MMC_TXOCTETCOUNT_G);
if (tx_mask & BIT(19))
lp->mmc_counters.txcarriererror +=
dwceqos_read(lp, DWC_MMC_TXCARRIERERROR);
if (tx_mask & BIT(18))
lp->mmc_counters.txexcesscol +=
dwceqos_read(lp, DWC_MMC_TXEXCESSCOL);
if (tx_mask & BIT(17))
lp->mmc_counters.txlatecol +=
dwceqos_read(lp, DWC_MMC_TXLATECOL);
if (tx_mask & BIT(16))
lp->mmc_counters.txdeferred +=
dwceqos_read(lp, DWC_MMC_TXDEFERRED);
if (tx_mask & BIT(15))
lp->mmc_counters.txmulticol_g +=
dwceqos_read(lp, DWC_MMC_TXMULTICOL_G);
if (tx_mask & BIT(14))
lp->mmc_counters.txsinglecol_g +=
dwceqos_read(lp, DWC_MMC_TXSINGLECOL_G);
if (tx_mask & BIT(13))
lp->mmc_counters.txunderflowerror +=
dwceqos_read(lp, DWC_MMC_TXUNDERFLOWERROR);
if (tx_mask & BIT(12))
lp->mmc_counters.txbroadcastpackets_gb +=
dwceqos_read(lp, DWC_MMC_TXBROADCASTPACKETS_GB);
if (tx_mask & BIT(11))
lp->mmc_counters.txmulticastpackets_gb +=
dwceqos_read(lp, DWC_MMC_TXMULTICASTPACKETS_GB);
if (tx_mask & BIT(10))
lp->mmc_counters.txunicastpackets_gb +=
dwceqos_read(lp, DWC_MMC_TXUNICASTPACKETS_GB);
if (tx_mask & BIT(9))
lp->mmc_counters.tx1024tomaxoctets_gb +=
dwceqos_read(lp, DWC_MMC_TX1024TOMAXOCTETS_GB);
if (tx_mask & BIT(8))
lp->mmc_counters.tx512to1023octets_gb +=
dwceqos_read(lp, DWC_MMC_TX512TO1023OCTETS_GB);
if (tx_mask & BIT(7))
lp->mmc_counters.tx256to511octets_gb +=
dwceqos_read(lp, DWC_MMC_TX256TO511OCTETS_GB);
if (tx_mask & BIT(6))
lp->mmc_counters.tx128to255octets_gb +=
dwceqos_read(lp, DWC_MMC_TX128TO255OCTETS_GB);
if (tx_mask & BIT(5))
lp->mmc_counters.tx65to127octets_gb +=
dwceqos_read(lp, DWC_MMC_TX65TO127OCTETS_GB);
if (tx_mask & BIT(4))
lp->mmc_counters.tx64octets_gb +=
dwceqos_read(lp, DWC_MMC_TX64OCTETS_GB);
if (tx_mask & BIT(3))
lp->mmc_counters.txmulticastpackets_g +=
dwceqos_read(lp, DWC_MMC_TXMULTICASTPACKETS_G);
if (tx_mask & BIT(2))
lp->mmc_counters.txbroadcastpackets_g +=
dwceqos_read(lp, DWC_MMC_TXBROADCASTPACKETS_G);
if (tx_mask & BIT(1))
lp->mmc_counters.txpacketcount_gb +=
dwceqos_read(lp, DWC_MMC_TXPACKETCOUNT_GB);
if (tx_mask & BIT(0))
lp->mmc_counters.txoctetcount_gb +=
dwceqos_read(lp, DWC_MMC_TXOCTETCOUNT_GB);
if (rx_mask & BIT(27))
lp->mmc_counters.rxlpitranscntr +=
dwceqos_read(lp, DWC_MMC_RXLPITRANSCNTR);
if (rx_mask & BIT(26))
lp->mmc_counters.rxlpiuscntr +=
dwceqos_read(lp, DWC_MMC_RXLPIUSCNTR);
if (rx_mask & BIT(25))
lp->mmc_counters.rxctrlpackets_g +=
dwceqos_read(lp, DWC_MMC_RXCTRLPACKETS_G);
if (rx_mask & BIT(24))
lp->mmc_counters.rxrcverror +=
dwceqos_read(lp, DWC_MMC_RXRCVERROR);
if (rx_mask & BIT(23))
lp->mmc_counters.rxwatchdog +=
dwceqos_read(lp, DWC_MMC_RXWATCHDOG);
if (rx_mask & BIT(22))
lp->mmc_counters.rxvlanpackets_gb +=
dwceqos_read(lp, DWC_MMC_RXVLANPACKETS_GB);
if (rx_mask & BIT(21))
lp->mmc_counters.rxfifooverflow +=
dwceqos_read(lp, DWC_MMC_RXFIFOOVERFLOW);
if (rx_mask & BIT(20))
lp->mmc_counters.rxpausepackets +=
dwceqos_read(lp, DWC_MMC_RXPAUSEPACKETS);
if (rx_mask & BIT(19))
lp->mmc_counters.rxoutofrangetype +=
dwceqos_read(lp, DWC_MMC_RXOUTOFRANGETYPE);
if (rx_mask & BIT(18))
lp->mmc_counters.rxlengtherror +=
dwceqos_read(lp, DWC_MMC_RXLENGTHERROR);
if (rx_mask & BIT(17))
lp->mmc_counters.rxunicastpackets_g +=
dwceqos_read(lp, DWC_MMC_RXUNICASTPACKETS_G);
if (rx_mask & BIT(16))
lp->mmc_counters.rx1024tomaxoctets_gb +=
dwceqos_read(lp, DWC_MMC_RX1024TOMAXOCTETS_GB);
if (rx_mask & BIT(15))
lp->mmc_counters.rx512to1023octets_gb +=
dwceqos_read(lp, DWC_MMC_RX512TO1023OCTETS_GB);
if (rx_mask & BIT(14))
lp->mmc_counters.rx256to511octets_gb +=
dwceqos_read(lp, DWC_MMC_RX256TO511OCTETS_GB);
if (rx_mask & BIT(13))
lp->mmc_counters.rx128to255octets_gb +=
dwceqos_read(lp, DWC_MMC_RX128TO255OCTETS_GB);
if (rx_mask & BIT(12))
lp->mmc_counters.rx65to127octets_gb +=
dwceqos_read(lp, DWC_MMC_RX65TO127OCTETS_GB);
if (rx_mask & BIT(11))
lp->mmc_counters.rx64octets_gb +=
dwceqos_read(lp, DWC_MMC_RX64OCTETS_GB);
if (rx_mask & BIT(10))
lp->mmc_counters.rxoversize_g +=
dwceqos_read(lp, DWC_MMC_RXOVERSIZE_G);
if (rx_mask & BIT(9))
lp->mmc_counters.rxundersize_g +=
dwceqos_read(lp, DWC_MMC_RXUNDERSIZE_G);
if (rx_mask & BIT(8))
lp->mmc_counters.rxjabbererror +=
dwceqos_read(lp, DWC_MMC_RXJABBERERROR);
if (rx_mask & BIT(7))
lp->mmc_counters.rxrunterror +=
dwceqos_read(lp, DWC_MMC_RXRUNTERROR);
if (rx_mask & BIT(6))
lp->mmc_counters.rxalignmenterror +=
dwceqos_read(lp, DWC_MMC_RXALIGNMENTERROR);
if (rx_mask & BIT(5))
lp->mmc_counters.rxcrcerror +=
dwceqos_read(lp, DWC_MMC_RXCRCERROR);
if (rx_mask & BIT(4))
lp->mmc_counters.rxmulticastpackets_g +=
dwceqos_read(lp, DWC_MMC_RXMULTICASTPACKETS_G);
if (rx_mask & BIT(3))
lp->mmc_counters.rxbroadcastpackets_g +=
dwceqos_read(lp, DWC_MMC_RXBROADCASTPACKETS_G);
if (rx_mask & BIT(2))
lp->mmc_counters.rxoctetcount_g +=
dwceqos_read(lp, DWC_MMC_RXOCTETCOUNT_G);
if (rx_mask & BIT(1))
lp->mmc_counters.rxoctetcount_gb +=
dwceqos_read(lp, DWC_MMC_RXOCTETCOUNT_GB);
if (rx_mask & BIT(0))
lp->mmc_counters.rxpacketcount_gb +=
dwceqos_read(lp, DWC_MMC_RXPACKETCOUNT_GB);
}
static struct rtnl_link_stats64*
dwceqos_get_stats64(struct net_device *ndev, struct rtnl_link_stats64 *s)
{
unsigned long flags;
struct net_local *lp = netdev_priv(ndev);
struct dwceqos_mmc_counters *hwstats = &lp->mmc_counters;
spin_lock_irqsave(&lp->stats_lock, flags);
dwceqos_read_mmc_counters(lp, lp->mmc_rx_counters_mask,
lp->mmc_tx_counters_mask);
spin_unlock_irqrestore(&lp->stats_lock, flags);
s->rx_packets = hwstats->rxpacketcount_gb;
s->rx_bytes = hwstats->rxoctetcount_gb;
s->rx_errors = hwstats->rxpacketcount_gb -
hwstats->rxbroadcastpackets_g -
hwstats->rxmulticastpackets_g -
hwstats->rxunicastpackets_g;
s->multicast = hwstats->rxmulticastpackets_g;
s->rx_length_errors = hwstats->rxlengtherror;
s->rx_crc_errors = hwstats->rxcrcerror;
s->rx_fifo_errors = hwstats->rxfifooverflow;
s->tx_packets = hwstats->txpacketcount_gb;
s->tx_bytes = hwstats->txoctetcount_gb;
if (lp->mmc_tx_counters_mask & BIT(21))
s->tx_errors = hwstats->txpacketcount_gb -
hwstats->txpacketcount_g;
else
s->tx_errors = hwstats->txunderflowerror +
hwstats->txcarriererror;
return s;
}
static int
dwceqos_get_settings(struct net_device *ndev, struct ethtool_cmd *ecmd)
{
struct net_local *lp = netdev_priv(ndev);
struct phy_device *phydev = lp->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_gset(phydev, ecmd);
}
static int
dwceqos_set_settings(struct net_device *ndev, struct ethtool_cmd *ecmd)
{
struct net_local *lp = netdev_priv(ndev);
struct phy_device *phydev = lp->phy_dev;
if (!phydev)
return -ENODEV;
return phy_ethtool_sset(phydev, ecmd);
}
static void
dwceqos_get_drvinfo(struct net_device *ndev, struct ethtool_drvinfo *ed)
{
const struct net_local *lp = netdev_priv(ndev);
strcpy(ed->driver, lp->pdev->dev.driver->name);
strcpy(ed->version, DRIVER_VERSION);
}
static void dwceqos_get_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pp)
{
const struct net_local *lp = netdev_priv(ndev);
pp->autoneg = lp->flowcontrol.autoneg;
pp->tx_pause = lp->flowcontrol.tx;
pp->rx_pause = lp->flowcontrol.rx;
}
static int dwceqos_set_pauseparam(struct net_device *ndev,
struct ethtool_pauseparam *pp)
{
struct net_local *lp = netdev_priv(ndev);
int ret = 0;
lp->flowcontrol.autoneg = pp->autoneg;
if (pp->autoneg) {
lp->phy_dev->advertising |= ADVERTISED_Pause;
lp->phy_dev->advertising |= ADVERTISED_Asym_Pause;
} else {
lp->phy_dev->advertising &= ~ADVERTISED_Pause;
lp->phy_dev->advertising &= ~ADVERTISED_Asym_Pause;
lp->flowcontrol.rx = pp->rx_pause;
lp->flowcontrol.tx = pp->tx_pause;
}
if (netif_running(ndev))
ret = phy_start_aneg(lp->phy_dev);
return ret;
}
static void dwceqos_get_strings(struct net_device *ndev, u32 stringset,
u8 *data)
{
size_t i;
if (stringset != ETH_SS_STATS)
return;
for (i = 0; i < ARRAY_SIZE(dwceqos_ethtool_stats); ++i) {
memcpy(data, dwceqos_ethtool_stats[i].stat_name,
ETH_GSTRING_LEN);
data += ETH_GSTRING_LEN;
}
}
static void dwceqos_get_ethtool_stats(struct net_device *ndev,
struct ethtool_stats *stats, u64 *data)
{
struct net_local *lp = netdev_priv(ndev);
unsigned long flags;
size_t i;
u8 *mmcstat = (u8 *)&lp->mmc_counters;
spin_lock_irqsave(&lp->stats_lock, flags);
dwceqos_read_mmc_counters(lp, lp->mmc_rx_counters_mask,
lp->mmc_tx_counters_mask);
spin_unlock_irqrestore(&lp->stats_lock, flags);
for (i = 0; i < ARRAY_SIZE(dwceqos_ethtool_stats); ++i) {
memcpy(data,
mmcstat + dwceqos_ethtool_stats[i].offset,
sizeof(u64));
data++;
}
}
static int dwceqos_get_sset_count(struct net_device *ndev, int sset)
{
if (sset == ETH_SS_STATS)
return ARRAY_SIZE(dwceqos_ethtool_stats);
return -EOPNOTSUPP;
}
static void dwceqos_get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *space)
{
const struct net_local *lp = netdev_priv(dev);
u32 *reg_space = (u32 *)space;
int reg_offset;
int reg_ix = 0;
for (reg_offset = START_MAC_REG_OFFSET;
reg_offset <= MAX_DMA_REG_OFFSET; reg_offset += 4) {
reg_space[reg_ix] = dwceqos_read(lp, reg_offset);
reg_ix++;
}
for (reg_offset = START_MTL_REG_OFFSET;
reg_offset <= MAX_MTL_REG_OFFSET; reg_offset += 4) {
reg_space[reg_ix] = dwceqos_read(lp, reg_offset);
reg_ix++;
}
for (reg_offset = START_DMA_REG_OFFSET;
reg_offset <= MAX_DMA_REG_OFFSET; reg_offset += 4) {
reg_space[reg_ix] = dwceqos_read(lp, reg_offset);
reg_ix++;
}
BUG_ON(4 * reg_ix > REG_SPACE_SIZE);
}
static int dwceqos_get_regs_len(struct net_device *dev)
{
return REG_SPACE_SIZE;
}
static inline const char *dwceqos_get_rx_lpi_state(u32 lpi_ctrl)
{
return (lpi_ctrl & DWCEQOS_MAC_LPI_CTRL_STATUS_RLPIST) ? "on" : "off";
}
static inline const char *dwceqos_get_tx_lpi_state(u32 lpi_ctrl)
{
return (lpi_ctrl & DWCEQOS_MAC_LPI_CTRL_STATUS_TLPIST) ? "on" : "off";
}
static int dwceqos_get_eee(struct net_device *ndev, struct ethtool_eee *edata)
{
struct net_local *lp = netdev_priv(ndev);
u32 lpi_status;
u32 lpi_enabled;
if (!(lp->feature0 & DWCEQOS_MAC_HW_FEATURE0_EEESEL))
return -EOPNOTSUPP;
edata->eee_active = lp->eee_active;
edata->eee_enabled = lp->eee_enabled;
edata->tx_lpi_timer = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_ENTRY_TIMER);
lpi_status = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
lpi_enabled = !!(lpi_status & DWCEQOS_MAC_LPI_CTRL_STATUS_LIPTXA);
edata->tx_lpi_enabled = lpi_enabled;
if (netif_msg_hw(lp)) {
u32 regval;
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
netdev_info(lp->ndev, "MAC LPI State: RX:%s TX:%s\n",
dwceqos_get_rx_lpi_state(regval),
dwceqos_get_tx_lpi_state(regval));
}
return phy_ethtool_get_eee(lp->phy_dev, edata);
}
static int dwceqos_set_eee(struct net_device *ndev, struct ethtool_eee *edata)
{
struct net_local *lp = netdev_priv(ndev);
u32 regval;
unsigned long flags;
if (!(lp->feature0 & DWCEQOS_MAC_HW_FEATURE0_EEESEL))
return -EOPNOTSUPP;
if (edata->eee_enabled && !lp->eee_active)
return -EOPNOTSUPP;
if (edata->tx_lpi_enabled) {
if (edata->tx_lpi_timer < DWCEQOS_LPI_TIMER_MIN ||
edata->tx_lpi_timer > DWCEQOS_LPI_TIMER_MAX)
return -EINVAL;
}
lp->eee_enabled = edata->eee_enabled;
if (edata->eee_enabled && edata->tx_lpi_enabled) {
dwceqos_write(lp, REG_DWCEQOS_MAC_LPI_ENTRY_TIMER,
edata->tx_lpi_timer);
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
regval |= DWCEQOS_LPI_CTRL_ENABLE_EEE;
if (lp->en_tx_lpi_clockgating)
regval |= DWCEQOS_MAC_LPI_CTRL_STATUS_LPITCSE;
dwceqos_write(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
} else {
spin_lock_irqsave(&lp->hw_lock, flags);
regval = dwceqos_read(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS);
regval &= ~DWCEQOS_LPI_CTRL_ENABLE_EEE;
dwceqos_write(lp, REG_DWCEQOS_MAC_LPI_CTRL_STATUS, regval);
spin_unlock_irqrestore(&lp->hw_lock, flags);
}
return phy_ethtool_set_eee(lp->phy_dev, edata);
}
static u32 dwceqos_get_msglevel(struct net_device *ndev)
{
const struct net_local *lp = netdev_priv(ndev);
return lp->msg_enable;
}
static void dwceqos_set_msglevel(struct net_device *ndev, u32 msglevel)
{
struct net_local *lp = netdev_priv(ndev);
lp->msg_enable = msglevel;
}
static int dwceqos_probe(struct platform_device *pdev)
{
struct resource *r_mem = NULL;
struct net_device *ndev;
struct net_local *lp;
int ret = -ENXIO;
r_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r_mem) {
dev_err(&pdev->dev, "no IO resource defined.\n");
return -ENXIO;
}
ndev = alloc_etherdev(sizeof(*lp));
if (!ndev) {
dev_err(&pdev->dev, "etherdev allocation failed.\n");
return -ENOMEM;
}
SET_NETDEV_DEV(ndev, &pdev->dev);
lp = netdev_priv(ndev);
lp->ndev = ndev;
lp->pdev = pdev;
lp->msg_enable = netif_msg_init(debug, DWCEQOS_MSG_DEFAULT);
spin_lock_init(&lp->tx_lock);
spin_lock_init(&lp->hw_lock);
spin_lock_init(&lp->stats_lock);
lp->apb_pclk = devm_clk_get(&pdev->dev, "apb_pclk");
if (IS_ERR(lp->apb_pclk)) {
dev_err(&pdev->dev, "apb_pclk clock not found.\n");
ret = PTR_ERR(lp->apb_pclk);
goto err_out_free_netdev;
}
ret = clk_prepare_enable(lp->apb_pclk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable APER clock.\n");
goto err_out_free_netdev;
}
lp->baseaddr = devm_ioremap_resource(&pdev->dev, r_mem);
if (IS_ERR(lp->baseaddr)) {
dev_err(&pdev->dev, "failed to map baseaddress.\n");
ret = PTR_ERR(lp->baseaddr);
goto err_out_clk_dis_aper;
}
ndev->irq = platform_get_irq(pdev, 0);
ndev->watchdog_timeo = DWCEQOS_TX_TIMEOUT * HZ;
ndev->netdev_ops = &netdev_ops;
ndev->ethtool_ops = &dwceqos_ethtool_ops;
ndev->base_addr = r_mem->start;
dwceqos_get_hwfeatures(lp);
dwceqos_mdio_set_csr(lp);
ndev->hw_features = NETIF_F_SG;
if (lp->feature1 & DWCEQOS_MAC_HW_FEATURE1_TSOEN)
ndev->hw_features |= NETIF_F_TSO | NETIF_F_TSO6;
if (lp->feature0 & DWCEQOS_MAC_HW_FEATURE0_TXCOESEL)
ndev->hw_features |= NETIF_F_IP_CSUM | NETIF_F_IPV6_CSUM;
if (lp->feature0 & DWCEQOS_MAC_HW_FEATURE0_RXCOESEL)
ndev->hw_features |= NETIF_F_RXCSUM;
ndev->features = ndev->hw_features;
netif_napi_add(ndev, &lp->napi, dwceqos_rx_poll, NAPI_POLL_WEIGHT);
ret = register_netdev(ndev);
if (ret) {
dev_err(&pdev->dev, "Cannot register net device, aborting.\n");
goto err_out_clk_dis_aper;
}
lp->phy_ref_clk = devm_clk_get(&pdev->dev, "phy_ref_clk");
if (IS_ERR(lp->phy_ref_clk)) {
dev_err(&pdev->dev, "phy_ref_clk clock not found.\n");
ret = PTR_ERR(lp->phy_ref_clk);
goto err_out_unregister_netdev;
}
ret = clk_prepare_enable(lp->phy_ref_clk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable device clock.\n");
goto err_out_unregister_netdev;
}
lp->phy_node = of_parse_phandle(lp->pdev->dev.of_node,
"phy-handle", 0);
if (!lp->phy_node && of_phy_is_fixed_link(lp->pdev->dev.of_node)) {
ret = of_phy_register_fixed_link(lp->pdev->dev.of_node);
if (ret < 0) {
dev_err(&pdev->dev, "invalid fixed-link");
goto err_out_unregister_netdev;
}
lp->phy_node = of_node_get(lp->pdev->dev.of_node);
}
ret = of_get_phy_mode(lp->pdev->dev.of_node);
if (ret < 0) {
dev_err(&lp->pdev->dev, "error in getting phy i/f\n");
goto err_out_unregister_clk_notifier;
}
lp->phy_interface = ret;
ret = dwceqos_mii_init(lp);
if (ret) {
dev_err(&lp->pdev->dev, "error in dwceqos_mii_init\n");
goto err_out_unregister_clk_notifier;
}
ret = dwceqos_mii_probe(ndev);
if (ret != 0) {
netdev_err(ndev, "mii_probe fail.\n");
ret = -ENXIO;
goto err_out_unregister_clk_notifier;
}
dwceqos_set_umac_addr(lp, lp->ndev->dev_addr, 0);
tasklet_init(&lp->tx_bdreclaim_tasklet, dwceqos_tx_reclaim,
(unsigned long)ndev);
tasklet_disable(&lp->tx_bdreclaim_tasklet);
lp->txtimeout_handler_wq = create_singlethread_workqueue(DRIVER_NAME);
INIT_WORK(&lp->txtimeout_reinit, dwceqos_reinit_for_txtimeout);
platform_set_drvdata(pdev, ndev);
ret = dwceqos_probe_config_dt(pdev);
if (ret) {
dev_err(&lp->pdev->dev, "Unable to retrieve DT, error %d\n",
ret);
goto err_out_unregister_clk_notifier;
}
dev_info(&lp->pdev->dev, "pdev->id %d, baseaddr 0x%08lx, irq %d\n",
pdev->id, ndev->base_addr, ndev->irq);
ret = devm_request_irq(&pdev->dev, ndev->irq, &dwceqos_interrupt, 0,
ndev->name, ndev);
if (ret) {
dev_err(&lp->pdev->dev, "Unable to request IRQ %d, error %d\n",
ndev->irq, ret);
goto err_out_unregister_clk_notifier;
}
if (netif_msg_probe(lp))
netdev_dbg(ndev, "net_local@%p\n", lp);
return 0;
err_out_unregister_clk_notifier:
clk_disable_unprepare(lp->phy_ref_clk);
err_out_unregister_netdev:
unregister_netdev(ndev);
err_out_clk_dis_aper:
clk_disable_unprepare(lp->apb_pclk);
err_out_free_netdev:
of_node_put(lp->phy_node);
free_netdev(ndev);
platform_set_drvdata(pdev, NULL);
return ret;
}
static int dwceqos_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct net_local *lp;
if (ndev) {
lp = netdev_priv(ndev);
if (lp->phy_dev)
phy_disconnect(lp->phy_dev);
mdiobus_unregister(lp->mii_bus);
kfree(lp->mii_bus->irq);
mdiobus_free(lp->mii_bus);
unregister_netdev(ndev);
clk_disable_unprepare(lp->phy_ref_clk);
clk_disable_unprepare(lp->apb_pclk);
free_netdev(ndev);
}
return 0;
}
