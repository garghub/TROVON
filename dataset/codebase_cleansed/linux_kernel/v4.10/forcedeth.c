static inline struct fe_priv *get_nvpriv(struct net_device *dev)
{
return netdev_priv(dev);
}
static inline u8 __iomem *get_hwbase(struct net_device *dev)
{
return ((struct fe_priv *)netdev_priv(dev))->base;
}
static inline void pci_push(u8 __iomem *base)
{
readl(base);
}
static inline u32 nv_descr_getlength(struct ring_desc *prd, u32 v)
{
return le32_to_cpu(prd->flaglen)
& ((v == DESC_VER_1) ? LEN_MASK_V1 : LEN_MASK_V2);
}
static inline u32 nv_descr_getlength_ex(struct ring_desc_ex *prd, u32 v)
{
return le32_to_cpu(prd->flaglen) & LEN_MASK_V2;
}
static bool nv_optimized(struct fe_priv *np)
{
if (np->desc_ver == DESC_VER_1 || np->desc_ver == DESC_VER_2)
return false;
return true;
}
static int reg_delay(struct net_device *dev, int offset, u32 mask, u32 target,
int delay, int delaymax)
{
u8 __iomem *base = get_hwbase(dev);
pci_push(base);
do {
udelay(delay);
delaymax -= delay;
if (delaymax < 0)
return 1;
} while ((readl(base + offset) & mask) != target);
return 0;
}
static inline u32 dma_low(dma_addr_t addr)
{
return addr;
}
static inline u32 dma_high(dma_addr_t addr)
{
return addr>>31>>1;
}
static void setup_hw_rings(struct net_device *dev, int rxtx_flags)
{
struct fe_priv *np = get_nvpriv(dev);
u8 __iomem *base = get_hwbase(dev);
if (!nv_optimized(np)) {
if (rxtx_flags & NV_SETUP_RX_RING)
writel(dma_low(np->ring_addr), base + NvRegRxRingPhysAddr);
if (rxtx_flags & NV_SETUP_TX_RING)
writel(dma_low(np->ring_addr + np->rx_ring_size*sizeof(struct ring_desc)), base + NvRegTxRingPhysAddr);
} else {
if (rxtx_flags & NV_SETUP_RX_RING) {
writel(dma_low(np->ring_addr), base + NvRegRxRingPhysAddr);
writel(dma_high(np->ring_addr), base + NvRegRxRingPhysAddrHigh);
}
if (rxtx_flags & NV_SETUP_TX_RING) {
writel(dma_low(np->ring_addr + np->rx_ring_size*sizeof(struct ring_desc_ex)), base + NvRegTxRingPhysAddr);
writel(dma_high(np->ring_addr + np->rx_ring_size*sizeof(struct ring_desc_ex)), base + NvRegTxRingPhysAddrHigh);
}
}
}
static void free_rings(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
if (!nv_optimized(np)) {
if (np->rx_ring.orig)
pci_free_consistent(np->pci_dev, sizeof(struct ring_desc) * (np->rx_ring_size + np->tx_ring_size),
np->rx_ring.orig, np->ring_addr);
} else {
if (np->rx_ring.ex)
pci_free_consistent(np->pci_dev, sizeof(struct ring_desc_ex) * (np->rx_ring_size + np->tx_ring_size),
np->rx_ring.ex, np->ring_addr);
}
kfree(np->rx_skb);
kfree(np->tx_skb);
}
static int using_multi_irqs(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
if (!(np->msi_flags & NV_MSI_X_ENABLED) ||
((np->msi_flags & NV_MSI_X_ENABLED) &&
((np->msi_flags & NV_MSI_X_VECTORS_MASK) == 0x1)))
return 0;
else
return 1;
}
static void nv_txrx_gate(struct net_device *dev, bool gate)
{
struct fe_priv *np = get_nvpriv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 powerstate;
if (!np->mac_in_use &&
(np->driver_data & DEV_HAS_POWER_CNTRL)) {
powerstate = readl(base + NvRegPowerState2);
if (gate)
powerstate |= NVREG_POWERSTATE2_GATE_CLOCKS;
else
powerstate &= ~NVREG_POWERSTATE2_GATE_CLOCKS;
writel(powerstate, base + NvRegPowerState2);
}
}
static void nv_enable_irq(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
if (!using_multi_irqs(dev)) {
if (np->msi_flags & NV_MSI_X_ENABLED)
enable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_ALL].vector);
else
enable_irq(np->pci_dev->irq);
} else {
enable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_RX].vector);
enable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_TX].vector);
enable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_OTHER].vector);
}
}
static void nv_disable_irq(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
if (!using_multi_irqs(dev)) {
if (np->msi_flags & NV_MSI_X_ENABLED)
disable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_ALL].vector);
else
disable_irq(np->pci_dev->irq);
} else {
disable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_RX].vector);
disable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_TX].vector);
disable_irq(np->msi_x_entry[NV_MSI_X_VECTOR_OTHER].vector);
}
}
static void nv_enable_hw_interrupts(struct net_device *dev, u32 mask)
{
u8 __iomem *base = get_hwbase(dev);
writel(mask, base + NvRegIrqMask);
}
static void nv_disable_hw_interrupts(struct net_device *dev, u32 mask)
{
struct fe_priv *np = get_nvpriv(dev);
u8 __iomem *base = get_hwbase(dev);
if (np->msi_flags & NV_MSI_X_ENABLED) {
writel(mask, base + NvRegIrqMask);
} else {
if (np->msi_flags & NV_MSI_ENABLED)
writel(0, base + NvRegMSIIrqMask);
writel(0, base + NvRegIrqMask);
}
}
static void nv_napi_enable(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
napi_enable(&np->napi);
}
static void nv_napi_disable(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
napi_disable(&np->napi);
}
static int mii_rw(struct net_device *dev, int addr, int miireg, int value)
{
u8 __iomem *base = get_hwbase(dev);
u32 reg;
int retval;
writel(NVREG_MIISTAT_MASK_RW, base + NvRegMIIStatus);
reg = readl(base + NvRegMIIControl);
if (reg & NVREG_MIICTL_INUSE) {
writel(NVREG_MIICTL_INUSE, base + NvRegMIIControl);
udelay(NV_MIIBUSY_DELAY);
}
reg = (addr << NVREG_MIICTL_ADDRSHIFT) | miireg;
if (value != MII_READ) {
writel(value, base + NvRegMIIData);
reg |= NVREG_MIICTL_WRITE;
}
writel(reg, base + NvRegMIIControl);
if (reg_delay(dev, NvRegMIIControl, NVREG_MIICTL_INUSE, 0,
NV_MIIPHY_DELAY, NV_MIIPHY_DELAYMAX)) {
retval = -1;
} else if (value != MII_READ) {
retval = 0;
} else if (readl(base + NvRegMIIStatus) & NVREG_MIISTAT_ERROR) {
retval = -1;
} else {
retval = readl(base + NvRegMIIData);
}
return retval;
}
static int phy_reset(struct net_device *dev, u32 bmcr_setup)
{
struct fe_priv *np = netdev_priv(dev);
u32 miicontrol;
unsigned int tries = 0;
miicontrol = BMCR_RESET | bmcr_setup;
if (mii_rw(dev, np->phyaddr, MII_BMCR, miicontrol))
return -1;
msleep(500);
while (miicontrol & BMCR_RESET) {
usleep_range(10000, 20000);
miicontrol = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
if (tries++ > 100)
return -1;
}
return 0;
}
static int init_realtek_8211b(struct net_device *dev, struct fe_priv *np)
{
static const struct {
int reg;
int init;
} ri[] = {
{ PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT1 },
{ PHY_REALTEK_INIT_REG2, PHY_REALTEK_INIT2 },
{ PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT3 },
{ PHY_REALTEK_INIT_REG3, PHY_REALTEK_INIT4 },
{ PHY_REALTEK_INIT_REG4, PHY_REALTEK_INIT5 },
{ PHY_REALTEK_INIT_REG5, PHY_REALTEK_INIT6 },
{ PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT1 },
};
int i;
for (i = 0; i < ARRAY_SIZE(ri); i++) {
if (mii_rw(dev, np->phyaddr, ri[i].reg, ri[i].init))
return PHY_ERROR;
}
return 0;
}
static int init_realtek_8211c(struct net_device *dev, struct fe_priv *np)
{
u32 reg;
u8 __iomem *base = get_hwbase(dev);
u32 powerstate = readl(base + NvRegPowerState2);
powerstate |= NVREG_POWERSTATE2_PHY_RESET;
writel(powerstate, base + NvRegPowerState2);
msleep(25);
powerstate &= ~NVREG_POWERSTATE2_PHY_RESET;
writel(powerstate, base + NvRegPowerState2);
msleep(25);
reg = mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG6, MII_READ);
reg |= PHY_REALTEK_INIT9;
if (mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG6, reg))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT10))
return PHY_ERROR;
reg = mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG7, MII_READ);
if (!(reg & PHY_REALTEK_INIT11)) {
reg |= PHY_REALTEK_INIT11;
if (mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG7, reg))
return PHY_ERROR;
}
if (mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT1))
return PHY_ERROR;
return 0;
}
static int init_realtek_8201(struct net_device *dev, struct fe_priv *np)
{
u32 phy_reserved;
if (np->driver_data & DEV_NEED_PHY_INIT_FIX) {
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG6, MII_READ);
phy_reserved |= PHY_REALTEK_INIT7;
if (mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG6, phy_reserved))
return PHY_ERROR;
}
return 0;
}
static int init_realtek_8201_cross(struct net_device *dev, struct fe_priv *np)
{
u32 phy_reserved;
if (phy_cross == NV_CROSSOVER_DETECTION_DISABLED) {
if (mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT3))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG2, MII_READ);
phy_reserved &= ~PHY_REALTEK_INIT_MSK1;
phy_reserved |= PHY_REALTEK_INIT3;
if (mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG2, phy_reserved))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT1))
return PHY_ERROR;
}
return 0;
}
static int init_cicada(struct net_device *dev, struct fe_priv *np,
u32 phyinterface)
{
u32 phy_reserved;
if (phyinterface & PHY_RGMII) {
phy_reserved = mii_rw(dev, np->phyaddr, MII_RESV1, MII_READ);
phy_reserved &= ~(PHY_CICADA_INIT1 | PHY_CICADA_INIT2);
phy_reserved |= (PHY_CICADA_INIT3 | PHY_CICADA_INIT4);
if (mii_rw(dev, np->phyaddr, MII_RESV1, phy_reserved))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr, MII_NCONFIG, MII_READ);
phy_reserved |= PHY_CICADA_INIT5;
if (mii_rw(dev, np->phyaddr, MII_NCONFIG, phy_reserved))
return PHY_ERROR;
}
phy_reserved = mii_rw(dev, np->phyaddr, MII_SREVISION, MII_READ);
phy_reserved |= PHY_CICADA_INIT6;
if (mii_rw(dev, np->phyaddr, MII_SREVISION, phy_reserved))
return PHY_ERROR;
return 0;
}
static int init_vitesse(struct net_device *dev, struct fe_priv *np)
{
u32 phy_reserved;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG1, PHY_VITESSE_INIT1))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG2, PHY_VITESSE_INIT2))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG4, MII_READ);
if (mii_rw(dev, np->phyaddr, PHY_VITESSE_INIT_REG4, phy_reserved))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG3, MII_READ);
phy_reserved &= ~PHY_VITESSE_INIT_MSK1;
phy_reserved |= PHY_VITESSE_INIT3;
if (mii_rw(dev, np->phyaddr, PHY_VITESSE_INIT_REG3, phy_reserved))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG2, PHY_VITESSE_INIT4))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG2, PHY_VITESSE_INIT5))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG4, MII_READ);
phy_reserved &= ~PHY_VITESSE_INIT_MSK1;
phy_reserved |= PHY_VITESSE_INIT3;
if (mii_rw(dev, np->phyaddr, PHY_VITESSE_INIT_REG4, phy_reserved))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG3, MII_READ);
if (mii_rw(dev, np->phyaddr, PHY_VITESSE_INIT_REG3, phy_reserved))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG2, PHY_VITESSE_INIT6))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG2, PHY_VITESSE_INIT7))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG4, MII_READ);
if (mii_rw(dev, np->phyaddr, PHY_VITESSE_INIT_REG4, phy_reserved))
return PHY_ERROR;
phy_reserved = mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG3, MII_READ);
phy_reserved &= ~PHY_VITESSE_INIT_MSK2;
phy_reserved |= PHY_VITESSE_INIT8;
if (mii_rw(dev, np->phyaddr, PHY_VITESSE_INIT_REG3, phy_reserved))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG2, PHY_VITESSE_INIT9))
return PHY_ERROR;
if (mii_rw(dev, np->phyaddr,
PHY_VITESSE_INIT_REG1, PHY_VITESSE_INIT10))
return PHY_ERROR;
return 0;
}
static int phy_init(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 phyinterface;
u32 mii_status, mii_control, mii_control_1000, reg;
if (np->phy_model == PHY_MODEL_MARVELL_E3016) {
reg = mii_rw(dev, np->phyaddr, MII_NCONFIG, MII_READ);
reg &= ~PHY_MARVELL_E3016_INITMASK;
if (mii_rw(dev, np->phyaddr, MII_NCONFIG, reg)) {
netdev_info(dev, "%s: phy write to errata reg failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
}
if (np->phy_oui == PHY_OUI_REALTEK) {
if (np->phy_model == PHY_MODEL_REALTEK_8211 &&
np->phy_rev == PHY_REV_REALTEK_8211B) {
if (init_realtek_8211b(dev, np)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else if (np->phy_model == PHY_MODEL_REALTEK_8211 &&
np->phy_rev == PHY_REV_REALTEK_8211C) {
if (init_realtek_8211c(dev, np)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else if (np->phy_model == PHY_MODEL_REALTEK_8201) {
if (init_realtek_8201(dev, np)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
}
}
reg = mii_rw(dev, np->phyaddr, MII_ADVERTISE, MII_READ);
reg |= (ADVERTISE_10HALF | ADVERTISE_10FULL |
ADVERTISE_100HALF | ADVERTISE_100FULL |
ADVERTISE_PAUSE_ASYM | ADVERTISE_PAUSE_CAP);
if (mii_rw(dev, np->phyaddr, MII_ADVERTISE, reg)) {
netdev_info(dev, "%s: phy write to advertise failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
phyinterface = readl(base + NvRegPhyInterface);
mii_status = mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
if (mii_status & PHY_GIGABIT) {
np->gigabit = PHY_GIGABIT;
mii_control_1000 = mii_rw(dev, np->phyaddr,
MII_CTRL1000, MII_READ);
mii_control_1000 &= ~ADVERTISE_1000HALF;
if (phyinterface & PHY_RGMII)
mii_control_1000 |= ADVERTISE_1000FULL;
else
mii_control_1000 &= ~ADVERTISE_1000FULL;
if (mii_rw(dev, np->phyaddr, MII_CTRL1000, mii_control_1000)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else
np->gigabit = 0;
mii_control = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
mii_control |= BMCR_ANENABLE;
if (np->phy_oui == PHY_OUI_REALTEK &&
np->phy_model == PHY_MODEL_REALTEK_8211 &&
np->phy_rev == PHY_REV_REALTEK_8211C) {
mii_control |= BMCR_ANRESTART;
if (mii_rw(dev, np->phyaddr, MII_BMCR, mii_control)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else {
if (phy_reset(dev, mii_control)) {
netdev_info(dev, "%s: phy reset failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
}
if (np->phy_oui == PHY_OUI_CICADA) {
if (init_cicada(dev, np, phyinterface)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else if (np->phy_oui == PHY_OUI_VITESSE) {
if (init_vitesse(dev, np)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else if (np->phy_oui == PHY_OUI_REALTEK) {
if (np->phy_model == PHY_MODEL_REALTEK_8211 &&
np->phy_rev == PHY_REV_REALTEK_8211B) {
if (init_realtek_8211b(dev, np)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
} else if (np->phy_model == PHY_MODEL_REALTEK_8201) {
if (init_realtek_8201(dev, np) ||
init_realtek_8201_cross(dev, np)) {
netdev_info(dev, "%s: phy init failed\n",
pci_name(np->pci_dev));
return PHY_ERROR;
}
}
}
mii_rw(dev, np->phyaddr, MII_ADVERTISE, reg);
mii_control = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
mii_control |= (BMCR_ANRESTART | BMCR_ANENABLE);
if (phy_power_down)
mii_control |= BMCR_PDOWN;
if (mii_rw(dev, np->phyaddr, MII_BMCR, mii_control))
return PHY_ERROR;
return 0;
}
static void nv_start_rx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 rx_ctrl = readl(base + NvRegReceiverControl);
if ((readl(base + NvRegReceiverControl) & NVREG_RCVCTL_START) && !np->mac_in_use) {
rx_ctrl &= ~NVREG_RCVCTL_START;
writel(rx_ctrl, base + NvRegReceiverControl);
pci_push(base);
}
writel(np->linkspeed, base + NvRegLinkSpeed);
pci_push(base);
rx_ctrl |= NVREG_RCVCTL_START;
if (np->mac_in_use)
rx_ctrl &= ~NVREG_RCVCTL_RX_PATH_EN;
writel(rx_ctrl, base + NvRegReceiverControl);
pci_push(base);
}
static void nv_stop_rx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 rx_ctrl = readl(base + NvRegReceiverControl);
if (!np->mac_in_use)
rx_ctrl &= ~NVREG_RCVCTL_START;
else
rx_ctrl |= NVREG_RCVCTL_RX_PATH_EN;
writel(rx_ctrl, base + NvRegReceiverControl);
if (reg_delay(dev, NvRegReceiverStatus, NVREG_RCVSTAT_BUSY, 0,
NV_RXSTOP_DELAY1, NV_RXSTOP_DELAY1MAX))
netdev_info(dev, "%s: ReceiverStatus remained busy\n",
__func__);
udelay(NV_RXSTOP_DELAY2);
if (!np->mac_in_use)
writel(0, base + NvRegLinkSpeed);
}
static void nv_start_tx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 tx_ctrl = readl(base + NvRegTransmitterControl);
tx_ctrl |= NVREG_XMITCTL_START;
if (np->mac_in_use)
tx_ctrl &= ~NVREG_XMITCTL_TX_PATH_EN;
writel(tx_ctrl, base + NvRegTransmitterControl);
pci_push(base);
}
static void nv_stop_tx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 tx_ctrl = readl(base + NvRegTransmitterControl);
if (!np->mac_in_use)
tx_ctrl &= ~NVREG_XMITCTL_START;
else
tx_ctrl |= NVREG_XMITCTL_TX_PATH_EN;
writel(tx_ctrl, base + NvRegTransmitterControl);
if (reg_delay(dev, NvRegTransmitterStatus, NVREG_XMITSTAT_BUSY, 0,
NV_TXSTOP_DELAY1, NV_TXSTOP_DELAY1MAX))
netdev_info(dev, "%s: TransmitterStatus remained busy\n",
__func__);
udelay(NV_TXSTOP_DELAY2);
if (!np->mac_in_use)
writel(readl(base + NvRegTransmitPoll) & NVREG_TRANSMITPOLL_MAC_ADDR_REV,
base + NvRegTransmitPoll);
}
static void nv_start_rxtx(struct net_device *dev)
{
nv_start_rx(dev);
nv_start_tx(dev);
}
static void nv_stop_rxtx(struct net_device *dev)
{
nv_stop_rx(dev);
nv_stop_tx(dev);
}
static void nv_txrx_reset(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
writel(NVREG_TXRXCTL_BIT2 | NVREG_TXRXCTL_RESET | np->txrxctl_bits, base + NvRegTxRxControl);
pci_push(base);
udelay(NV_TXRX_RESET_DELAY);
writel(NVREG_TXRXCTL_BIT2 | np->txrxctl_bits, base + NvRegTxRxControl);
pci_push(base);
}
static void nv_mac_reset(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 temp1, temp2, temp3;
writel(NVREG_TXRXCTL_BIT2 | NVREG_TXRXCTL_RESET | np->txrxctl_bits, base + NvRegTxRxControl);
pci_push(base);
temp1 = readl(base + NvRegMacAddrA);
temp2 = readl(base + NvRegMacAddrB);
temp3 = readl(base + NvRegTransmitPoll);
writel(NVREG_MAC_RESET_ASSERT, base + NvRegMacReset);
pci_push(base);
udelay(NV_MAC_RESET_DELAY);
writel(0, base + NvRegMacReset);
pci_push(base);
udelay(NV_MAC_RESET_DELAY);
writel(temp1, base + NvRegMacAddrA);
writel(temp2, base + NvRegMacAddrB);
writel(temp3, base + NvRegTransmitPoll);
writel(NVREG_TXRXCTL_BIT2 | np->txrxctl_bits, base + NvRegTxRxControl);
pci_push(base);
}
static void nv_update_stats(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
WARN_ONCE(in_irq(), "forcedeth: estats spin_lock(_bh) from top-half");
assert_spin_locked(&np->hwstats_lock);
np->estats.tx_bytes += readl(base + NvRegTxCnt);
np->estats.tx_zero_rexmt += readl(base + NvRegTxZeroReXmt);
np->estats.tx_one_rexmt += readl(base + NvRegTxOneReXmt);
np->estats.tx_many_rexmt += readl(base + NvRegTxManyReXmt);
np->estats.tx_late_collision += readl(base + NvRegTxLateCol);
np->estats.tx_fifo_errors += readl(base + NvRegTxUnderflow);
np->estats.tx_carrier_errors += readl(base + NvRegTxLossCarrier);
np->estats.tx_excess_deferral += readl(base + NvRegTxExcessDef);
np->estats.tx_retry_error += readl(base + NvRegTxRetryErr);
np->estats.rx_frame_error += readl(base + NvRegRxFrameErr);
np->estats.rx_extra_byte += readl(base + NvRegRxExtraByte);
np->estats.rx_late_collision += readl(base + NvRegRxLateCol);
np->estats.rx_runt += readl(base + NvRegRxRunt);
np->estats.rx_frame_too_long += readl(base + NvRegRxFrameTooLong);
np->estats.rx_over_errors += readl(base + NvRegRxOverflow);
np->estats.rx_crc_errors += readl(base + NvRegRxFCSErr);
np->estats.rx_frame_align_error += readl(base + NvRegRxFrameAlignErr);
np->estats.rx_length_error += readl(base + NvRegRxLenErr);
np->estats.rx_unicast += readl(base + NvRegRxUnicast);
np->estats.rx_multicast += readl(base + NvRegRxMulticast);
np->estats.rx_broadcast += readl(base + NvRegRxBroadcast);
np->estats.rx_packets =
np->estats.rx_unicast +
np->estats.rx_multicast +
np->estats.rx_broadcast;
np->estats.rx_errors_total =
np->estats.rx_crc_errors +
np->estats.rx_over_errors +
np->estats.rx_frame_error +
(np->estats.rx_frame_align_error - np->estats.rx_extra_byte) +
np->estats.rx_late_collision +
np->estats.rx_runt +
np->estats.rx_frame_too_long;
np->estats.tx_errors_total =
np->estats.tx_late_collision +
np->estats.tx_fifo_errors +
np->estats.tx_carrier_errors +
np->estats.tx_excess_deferral +
np->estats.tx_retry_error;
if (np->driver_data & DEV_HAS_STATISTICS_V2) {
np->estats.tx_deferral += readl(base + NvRegTxDef);
np->estats.tx_packets += readl(base + NvRegTxFrame);
np->estats.rx_bytes += readl(base + NvRegRxCnt);
np->estats.tx_pause += readl(base + NvRegTxPause);
np->estats.rx_pause += readl(base + NvRegRxPause);
np->estats.rx_drop_frame += readl(base + NvRegRxDropFrame);
np->estats.rx_errors_total += np->estats.rx_drop_frame;
}
if (np->driver_data & DEV_HAS_STATISTICS_V3) {
np->estats.tx_unicast += readl(base + NvRegTxUnicast);
np->estats.tx_multicast += readl(base + NvRegTxMulticast);
np->estats.tx_broadcast += readl(base + NvRegTxBroadcast);
}
}
static struct rtnl_link_stats64*
nv_get_stats64(struct net_device *dev, struct rtnl_link_stats64 *storage)
__acquires(&netdev_priv(dev)->hwstats_lock
static int nv_alloc_rx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
struct ring_desc *less_rx;
less_rx = np->get_rx.orig;
if (less_rx-- == np->first_rx.orig)
less_rx = np->last_rx.orig;
while (np->put_rx.orig != less_rx) {
struct sk_buff *skb = netdev_alloc_skb(dev, np->rx_buf_sz + NV_RX_ALLOC_PAD);
if (skb) {
np->put_rx_ctx->skb = skb;
np->put_rx_ctx->dma = pci_map_single(np->pci_dev,
skb->data,
skb_tailroom(skb),
PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(np->pci_dev,
np->put_rx_ctx->dma)) {
kfree_skb(skb);
goto packet_dropped;
}
np->put_rx_ctx->dma_len = skb_tailroom(skb);
np->put_rx.orig->buf = cpu_to_le32(np->put_rx_ctx->dma);
wmb();
np->put_rx.orig->flaglen = cpu_to_le32(np->rx_buf_sz | NV_RX_AVAIL);
if (unlikely(np->put_rx.orig++ == np->last_rx.orig))
np->put_rx.orig = np->first_rx.orig;
if (unlikely(np->put_rx_ctx++ == np->last_rx_ctx))
np->put_rx_ctx = np->first_rx_ctx;
} else {
packet_dropped:
u64_stats_update_begin(&np->swstats_rx_syncp);
np->stat_rx_dropped++;
u64_stats_update_end(&np->swstats_rx_syncp);
return 1;
}
}
return 0;
}
static int nv_alloc_rx_optimized(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
struct ring_desc_ex *less_rx;
less_rx = np->get_rx.ex;
if (less_rx-- == np->first_rx.ex)
less_rx = np->last_rx.ex;
while (np->put_rx.ex != less_rx) {
struct sk_buff *skb = netdev_alloc_skb(dev, np->rx_buf_sz + NV_RX_ALLOC_PAD);
if (skb) {
np->put_rx_ctx->skb = skb;
np->put_rx_ctx->dma = pci_map_single(np->pci_dev,
skb->data,
skb_tailroom(skb),
PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(np->pci_dev,
np->put_rx_ctx->dma)) {
kfree_skb(skb);
goto packet_dropped;
}
np->put_rx_ctx->dma_len = skb_tailroom(skb);
np->put_rx.ex->bufhigh = cpu_to_le32(dma_high(np->put_rx_ctx->dma));
np->put_rx.ex->buflow = cpu_to_le32(dma_low(np->put_rx_ctx->dma));
wmb();
np->put_rx.ex->flaglen = cpu_to_le32(np->rx_buf_sz | NV_RX2_AVAIL);
if (unlikely(np->put_rx.ex++ == np->last_rx.ex))
np->put_rx.ex = np->first_rx.ex;
if (unlikely(np->put_rx_ctx++ == np->last_rx_ctx))
np->put_rx_ctx = np->first_rx_ctx;
} else {
packet_dropped:
u64_stats_update_begin(&np->swstats_rx_syncp);
np->stat_rx_dropped++;
u64_stats_update_end(&np->swstats_rx_syncp);
return 1;
}
}
return 0;
}
static void nv_do_rx_refill(unsigned long data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
napi_schedule(&np->napi);
}
static void nv_init_rx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
int i;
np->get_rx = np->put_rx = np->first_rx = np->rx_ring;
if (!nv_optimized(np))
np->last_rx.orig = &np->rx_ring.orig[np->rx_ring_size-1];
else
np->last_rx.ex = &np->rx_ring.ex[np->rx_ring_size-1];
np->get_rx_ctx = np->put_rx_ctx = np->first_rx_ctx = np->rx_skb;
np->last_rx_ctx = &np->rx_skb[np->rx_ring_size-1];
for (i = 0; i < np->rx_ring_size; i++) {
if (!nv_optimized(np)) {
np->rx_ring.orig[i].flaglen = 0;
np->rx_ring.orig[i].buf = 0;
} else {
np->rx_ring.ex[i].flaglen = 0;
np->rx_ring.ex[i].txvlan = 0;
np->rx_ring.ex[i].bufhigh = 0;
np->rx_ring.ex[i].buflow = 0;
}
np->rx_skb[i].skb = NULL;
np->rx_skb[i].dma = 0;
}
}
static void nv_init_tx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
int i;
np->get_tx = np->put_tx = np->first_tx = np->tx_ring;
if (!nv_optimized(np))
np->last_tx.orig = &np->tx_ring.orig[np->tx_ring_size-1];
else
np->last_tx.ex = &np->tx_ring.ex[np->tx_ring_size-1];
np->get_tx_ctx = np->put_tx_ctx = np->first_tx_ctx = np->tx_skb;
np->last_tx_ctx = &np->tx_skb[np->tx_ring_size-1];
netdev_reset_queue(np->dev);
np->tx_pkts_in_progress = 0;
np->tx_change_owner = NULL;
np->tx_end_flip = NULL;
np->tx_stop = 0;
for (i = 0; i < np->tx_ring_size; i++) {
if (!nv_optimized(np)) {
np->tx_ring.orig[i].flaglen = 0;
np->tx_ring.orig[i].buf = 0;
} else {
np->tx_ring.ex[i].flaglen = 0;
np->tx_ring.ex[i].txvlan = 0;
np->tx_ring.ex[i].bufhigh = 0;
np->tx_ring.ex[i].buflow = 0;
}
np->tx_skb[i].skb = NULL;
np->tx_skb[i].dma = 0;
np->tx_skb[i].dma_len = 0;
np->tx_skb[i].dma_single = 0;
np->tx_skb[i].first_tx_desc = NULL;
np->tx_skb[i].next_tx_ctx = NULL;
}
}
static int nv_init_ring(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
nv_init_tx(dev);
nv_init_rx(dev);
if (!nv_optimized(np))
return nv_alloc_rx(dev);
else
return nv_alloc_rx_optimized(dev);
}
static void nv_unmap_txskb(struct fe_priv *np, struct nv_skb_map *tx_skb)
{
if (tx_skb->dma) {
if (tx_skb->dma_single)
pci_unmap_single(np->pci_dev, tx_skb->dma,
tx_skb->dma_len,
PCI_DMA_TODEVICE);
else
pci_unmap_page(np->pci_dev, tx_skb->dma,
tx_skb->dma_len,
PCI_DMA_TODEVICE);
tx_skb->dma = 0;
}
}
static int nv_release_txskb(struct fe_priv *np, struct nv_skb_map *tx_skb)
{
nv_unmap_txskb(np, tx_skb);
if (tx_skb->skb) {
dev_kfree_skb_any(tx_skb->skb);
tx_skb->skb = NULL;
return 1;
}
return 0;
}
static void nv_drain_tx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
unsigned int i;
for (i = 0; i < np->tx_ring_size; i++) {
if (!nv_optimized(np)) {
np->tx_ring.orig[i].flaglen = 0;
np->tx_ring.orig[i].buf = 0;
} else {
np->tx_ring.ex[i].flaglen = 0;
np->tx_ring.ex[i].txvlan = 0;
np->tx_ring.ex[i].bufhigh = 0;
np->tx_ring.ex[i].buflow = 0;
}
if (nv_release_txskb(np, &np->tx_skb[i])) {
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_dropped++;
u64_stats_update_end(&np->swstats_tx_syncp);
}
np->tx_skb[i].dma = 0;
np->tx_skb[i].dma_len = 0;
np->tx_skb[i].dma_single = 0;
np->tx_skb[i].first_tx_desc = NULL;
np->tx_skb[i].next_tx_ctx = NULL;
}
np->tx_pkts_in_progress = 0;
np->tx_change_owner = NULL;
np->tx_end_flip = NULL;
}
static void nv_drain_rx(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
int i;
for (i = 0; i < np->rx_ring_size; i++) {
if (!nv_optimized(np)) {
np->rx_ring.orig[i].flaglen = 0;
np->rx_ring.orig[i].buf = 0;
} else {
np->rx_ring.ex[i].flaglen = 0;
np->rx_ring.ex[i].txvlan = 0;
np->rx_ring.ex[i].bufhigh = 0;
np->rx_ring.ex[i].buflow = 0;
}
wmb();
if (np->rx_skb[i].skb) {
pci_unmap_single(np->pci_dev, np->rx_skb[i].dma,
(skb_end_pointer(np->rx_skb[i].skb) -
np->rx_skb[i].skb->data),
PCI_DMA_FROMDEVICE);
dev_kfree_skb(np->rx_skb[i].skb);
np->rx_skb[i].skb = NULL;
}
}
}
static void nv_drain_rxtx(struct net_device *dev)
{
nv_drain_tx(dev);
nv_drain_rx(dev);
}
static inline u32 nv_get_empty_tx_slots(struct fe_priv *np)
{
return (u32)(np->tx_ring_size - ((np->tx_ring_size + (np->put_tx_ctx - np->get_tx_ctx)) % np->tx_ring_size));
}
static void nv_legacybackoff_reseed(struct net_device *dev)
{
u8 __iomem *base = get_hwbase(dev);
u32 reg;
u32 low;
int tx_status = 0;
reg = readl(base + NvRegSlotTime) & ~NVREG_SLOTTIME_MASK;
get_random_bytes(&low, sizeof(low));
reg |= low & NVREG_SLOTTIME_MASK;
tx_status = readl(base + NvRegTransmitterControl) & NVREG_XMITCTL_START;
if (tx_status)
nv_stop_tx(dev);
nv_stop_rx(dev);
writel(reg, base + NvRegSlotTime);
if (tx_status)
nv_start_tx(dev);
nv_start_rx(dev);
}
static void nv_gear_backoff_reseed(struct net_device *dev)
{
u8 __iomem *base = get_hwbase(dev);
u32 miniseed1, miniseed2, miniseed2_reversed, miniseed3, miniseed3_reversed;
u32 temp, seedset, combinedSeed;
int i;
get_random_bytes(&miniseed1, sizeof(miniseed1));
miniseed1 &= 0x0fff;
if (miniseed1 == 0)
miniseed1 = 0xabc;
get_random_bytes(&miniseed2, sizeof(miniseed2));
miniseed2 &= 0x0fff;
if (miniseed2 == 0)
miniseed2 = 0xabc;
miniseed2_reversed =
((miniseed2 & 0xF00) >> 8) |
(miniseed2 & 0x0F0) |
((miniseed2 & 0x00F) << 8);
get_random_bytes(&miniseed3, sizeof(miniseed3));
miniseed3 &= 0x0fff;
if (miniseed3 == 0)
miniseed3 = 0xabc;
miniseed3_reversed =
((miniseed3 & 0xF00) >> 8) |
(miniseed3 & 0x0F0) |
((miniseed3 & 0x00F) << 8);
combinedSeed = ((miniseed1 ^ miniseed2_reversed) << 12) |
(miniseed2 ^ miniseed3_reversed);
if ((combinedSeed & NVREG_BKOFFCTRL_SEED_MASK) == 0)
combinedSeed |= 0x08;
if ((combinedSeed & (NVREG_BKOFFCTRL_SEED_MASK << NVREG_BKOFFCTRL_GEAR)) == 0)
combinedSeed |= 0x8000;
temp = NVREG_BKOFFCTRL_DEFAULT | (0 << NVREG_BKOFFCTRL_SELECT);
temp |= combinedSeed & NVREG_BKOFFCTRL_SEED_MASK;
temp |= combinedSeed >> NVREG_BKOFFCTRL_GEAR;
writel(temp, base + NvRegBackOffControl);
get_random_bytes(&seedset, sizeof(seedset));
seedset = seedset % BACKOFF_SEEDSET_ROWS;
for (i = 1; i <= BACKOFF_SEEDSET_LFSRS; i++) {
temp = NVREG_BKOFFCTRL_DEFAULT | (i << NVREG_BKOFFCTRL_SELECT);
temp |= main_seedset[seedset][i-1] & 0x3ff;
temp |= ((gear_seedset[seedset][i-1] & 0x3ff) << NVREG_BKOFFCTRL_GEAR);
writel(temp, base + NvRegBackOffControl);
}
}
static netdev_tx_t nv_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u32 tx_flags = 0;
u32 tx_flags_extra = (np->desc_ver == DESC_VER_1 ? NV_TX_LASTPACKET : NV_TX2_LASTPACKET);
unsigned int fragments = skb_shinfo(skb)->nr_frags;
unsigned int i;
u32 offset = 0;
u32 bcnt;
u32 size = skb_headlen(skb);
u32 entries = (size >> NV_TX2_TSO_MAX_SHIFT) + ((size & (NV_TX2_TSO_MAX_SIZE-1)) ? 1 : 0);
u32 empty_slots;
struct ring_desc *put_tx;
struct ring_desc *start_tx;
struct ring_desc *prev_tx;
struct nv_skb_map *prev_tx_ctx;
struct nv_skb_map *tmp_tx_ctx = NULL, *start_tx_ctx = NULL;
unsigned long flags;
for (i = 0; i < fragments; i++) {
u32 frag_size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
entries += (frag_size >> NV_TX2_TSO_MAX_SHIFT) +
((frag_size & (NV_TX2_TSO_MAX_SIZE-1)) ? 1 : 0);
}
spin_lock_irqsave(&np->lock, flags);
empty_slots = nv_get_empty_tx_slots(np);
if (unlikely(empty_slots <= entries)) {
netif_stop_queue(dev);
np->tx_stop = 1;
spin_unlock_irqrestore(&np->lock, flags);
return NETDEV_TX_BUSY;
}
spin_unlock_irqrestore(&np->lock, flags);
start_tx = put_tx = np->put_tx.orig;
do {
prev_tx = put_tx;
prev_tx_ctx = np->put_tx_ctx;
bcnt = (size > NV_TX2_TSO_MAX_SIZE) ? NV_TX2_TSO_MAX_SIZE : size;
np->put_tx_ctx->dma = pci_map_single(np->pci_dev, skb->data + offset, bcnt,
PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(np->pci_dev,
np->put_tx_ctx->dma)) {
dev_kfree_skb_any(skb);
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_dropped++;
u64_stats_update_end(&np->swstats_tx_syncp);
return NETDEV_TX_OK;
}
np->put_tx_ctx->dma_len = bcnt;
np->put_tx_ctx->dma_single = 1;
put_tx->buf = cpu_to_le32(np->put_tx_ctx->dma);
put_tx->flaglen = cpu_to_le32((bcnt-1) | tx_flags);
tx_flags = np->tx_flags;
offset += bcnt;
size -= bcnt;
if (unlikely(put_tx++ == np->last_tx.orig))
put_tx = np->first_tx.orig;
if (unlikely(np->put_tx_ctx++ == np->last_tx_ctx))
np->put_tx_ctx = np->first_tx_ctx;
} while (size);
for (i = 0; i < fragments; i++) {
const skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
u32 frag_size = skb_frag_size(frag);
offset = 0;
do {
prev_tx = put_tx;
prev_tx_ctx = np->put_tx_ctx;
if (!start_tx_ctx)
start_tx_ctx = tmp_tx_ctx = np->put_tx_ctx;
bcnt = (frag_size > NV_TX2_TSO_MAX_SIZE) ? NV_TX2_TSO_MAX_SIZE : frag_size;
np->put_tx_ctx->dma = skb_frag_dma_map(
&np->pci_dev->dev,
frag, offset,
bcnt,
DMA_TO_DEVICE);
if (dma_mapping_error(&np->pci_dev->dev, np->put_tx_ctx->dma)) {
do {
nv_unmap_txskb(np, start_tx_ctx);
if (unlikely(tmp_tx_ctx++ == np->last_tx_ctx))
tmp_tx_ctx = np->first_tx_ctx;
} while (tmp_tx_ctx != np->put_tx_ctx);
dev_kfree_skb_any(skb);
np->put_tx_ctx = start_tx_ctx;
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_dropped++;
u64_stats_update_end(&np->swstats_tx_syncp);
return NETDEV_TX_OK;
}
np->put_tx_ctx->dma_len = bcnt;
np->put_tx_ctx->dma_single = 0;
put_tx->buf = cpu_to_le32(np->put_tx_ctx->dma);
put_tx->flaglen = cpu_to_le32((bcnt-1) | tx_flags);
offset += bcnt;
frag_size -= bcnt;
if (unlikely(put_tx++ == np->last_tx.orig))
put_tx = np->first_tx.orig;
if (unlikely(np->put_tx_ctx++ == np->last_tx_ctx))
np->put_tx_ctx = np->first_tx_ctx;
} while (frag_size);
}
prev_tx->flaglen |= cpu_to_le32(tx_flags_extra);
prev_tx_ctx->skb = skb;
if (skb_is_gso(skb))
tx_flags_extra = NV_TX2_TSO | (skb_shinfo(skb)->gso_size << NV_TX2_TSO_SHIFT);
else
tx_flags_extra = skb->ip_summed == CHECKSUM_PARTIAL ?
NV_TX2_CHECKSUM_L3 | NV_TX2_CHECKSUM_L4 : 0;
spin_lock_irqsave(&np->lock, flags);
start_tx->flaglen |= cpu_to_le32(tx_flags | tx_flags_extra);
netdev_sent_queue(np->dev, skb->len);
skb_tx_timestamp(skb);
np->put_tx.orig = put_tx;
spin_unlock_irqrestore(&np->lock, flags);
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
return NETDEV_TX_OK;
}
static netdev_tx_t nv_start_xmit_optimized(struct sk_buff *skb,
struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u32 tx_flags = 0;
u32 tx_flags_extra;
unsigned int fragments = skb_shinfo(skb)->nr_frags;
unsigned int i;
u32 offset = 0;
u32 bcnt;
u32 size = skb_headlen(skb);
u32 entries = (size >> NV_TX2_TSO_MAX_SHIFT) + ((size & (NV_TX2_TSO_MAX_SIZE-1)) ? 1 : 0);
u32 empty_slots;
struct ring_desc_ex *put_tx;
struct ring_desc_ex *start_tx;
struct ring_desc_ex *prev_tx;
struct nv_skb_map *prev_tx_ctx;
struct nv_skb_map *start_tx_ctx = NULL;
struct nv_skb_map *tmp_tx_ctx = NULL;
unsigned long flags;
for (i = 0; i < fragments; i++) {
u32 frag_size = skb_frag_size(&skb_shinfo(skb)->frags[i]);
entries += (frag_size >> NV_TX2_TSO_MAX_SHIFT) +
((frag_size & (NV_TX2_TSO_MAX_SIZE-1)) ? 1 : 0);
}
spin_lock_irqsave(&np->lock, flags);
empty_slots = nv_get_empty_tx_slots(np);
if (unlikely(empty_slots <= entries)) {
netif_stop_queue(dev);
np->tx_stop = 1;
spin_unlock_irqrestore(&np->lock, flags);
return NETDEV_TX_BUSY;
}
spin_unlock_irqrestore(&np->lock, flags);
start_tx = put_tx = np->put_tx.ex;
start_tx_ctx = np->put_tx_ctx;
do {
prev_tx = put_tx;
prev_tx_ctx = np->put_tx_ctx;
bcnt = (size > NV_TX2_TSO_MAX_SIZE) ? NV_TX2_TSO_MAX_SIZE : size;
np->put_tx_ctx->dma = pci_map_single(np->pci_dev, skb->data + offset, bcnt,
PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(np->pci_dev,
np->put_tx_ctx->dma)) {
dev_kfree_skb_any(skb);
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_dropped++;
u64_stats_update_end(&np->swstats_tx_syncp);
return NETDEV_TX_OK;
}
np->put_tx_ctx->dma_len = bcnt;
np->put_tx_ctx->dma_single = 1;
put_tx->bufhigh = cpu_to_le32(dma_high(np->put_tx_ctx->dma));
put_tx->buflow = cpu_to_le32(dma_low(np->put_tx_ctx->dma));
put_tx->flaglen = cpu_to_le32((bcnt-1) | tx_flags);
tx_flags = NV_TX2_VALID;
offset += bcnt;
size -= bcnt;
if (unlikely(put_tx++ == np->last_tx.ex))
put_tx = np->first_tx.ex;
if (unlikely(np->put_tx_ctx++ == np->last_tx_ctx))
np->put_tx_ctx = np->first_tx_ctx;
} while (size);
for (i = 0; i < fragments; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
u32 frag_size = skb_frag_size(frag);
offset = 0;
do {
prev_tx = put_tx;
prev_tx_ctx = np->put_tx_ctx;
bcnt = (frag_size > NV_TX2_TSO_MAX_SIZE) ? NV_TX2_TSO_MAX_SIZE : frag_size;
if (!start_tx_ctx)
start_tx_ctx = tmp_tx_ctx = np->put_tx_ctx;
np->put_tx_ctx->dma = skb_frag_dma_map(
&np->pci_dev->dev,
frag, offset,
bcnt,
DMA_TO_DEVICE);
if (dma_mapping_error(&np->pci_dev->dev, np->put_tx_ctx->dma)) {
do {
nv_unmap_txskb(np, start_tx_ctx);
if (unlikely(tmp_tx_ctx++ == np->last_tx_ctx))
tmp_tx_ctx = np->first_tx_ctx;
} while (tmp_tx_ctx != np->put_tx_ctx);
dev_kfree_skb_any(skb);
np->put_tx_ctx = start_tx_ctx;
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_dropped++;
u64_stats_update_end(&np->swstats_tx_syncp);
return NETDEV_TX_OK;
}
np->put_tx_ctx->dma_len = bcnt;
np->put_tx_ctx->dma_single = 0;
put_tx->bufhigh = cpu_to_le32(dma_high(np->put_tx_ctx->dma));
put_tx->buflow = cpu_to_le32(dma_low(np->put_tx_ctx->dma));
put_tx->flaglen = cpu_to_le32((bcnt-1) | tx_flags);
offset += bcnt;
frag_size -= bcnt;
if (unlikely(put_tx++ == np->last_tx.ex))
put_tx = np->first_tx.ex;
if (unlikely(np->put_tx_ctx++ == np->last_tx_ctx))
np->put_tx_ctx = np->first_tx_ctx;
} while (frag_size);
}
prev_tx->flaglen |= cpu_to_le32(NV_TX2_LASTPACKET);
prev_tx_ctx->skb = skb;
if (skb_is_gso(skb))
tx_flags_extra = NV_TX2_TSO | (skb_shinfo(skb)->gso_size << NV_TX2_TSO_SHIFT);
else
tx_flags_extra = skb->ip_summed == CHECKSUM_PARTIAL ?
NV_TX2_CHECKSUM_L3 | NV_TX2_CHECKSUM_L4 : 0;
if (skb_vlan_tag_present(skb))
start_tx->txvlan = cpu_to_le32(NV_TX3_VLAN_TAG_PRESENT |
skb_vlan_tag_get(skb));
else
start_tx->txvlan = 0;
spin_lock_irqsave(&np->lock, flags);
if (np->tx_limit) {
if (np->tx_pkts_in_progress == NV_TX_LIMIT_COUNT) {
if (!np->tx_change_owner)
np->tx_change_owner = start_tx_ctx;
tx_flags &= ~NV_TX2_VALID;
start_tx_ctx->first_tx_desc = start_tx;
start_tx_ctx->next_tx_ctx = np->put_tx_ctx;
np->tx_end_flip = np->put_tx_ctx;
} else {
np->tx_pkts_in_progress++;
}
}
start_tx->flaglen |= cpu_to_le32(tx_flags | tx_flags_extra);
netdev_sent_queue(np->dev, skb->len);
skb_tx_timestamp(skb);
np->put_tx.ex = put_tx;
spin_unlock_irqrestore(&np->lock, flags);
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
return NETDEV_TX_OK;
}
static inline void nv_tx_flip_ownership(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
np->tx_pkts_in_progress--;
if (np->tx_change_owner) {
np->tx_change_owner->first_tx_desc->flaglen |=
cpu_to_le32(NV_TX2_VALID);
np->tx_pkts_in_progress++;
np->tx_change_owner = np->tx_change_owner->next_tx_ctx;
if (np->tx_change_owner == np->tx_end_flip)
np->tx_change_owner = NULL;
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
}
}
static int nv_tx_done(struct net_device *dev, int limit)
{
struct fe_priv *np = netdev_priv(dev);
u32 flags;
int tx_work = 0;
struct ring_desc *orig_get_tx = np->get_tx.orig;
unsigned int bytes_compl = 0;
while ((np->get_tx.orig != np->put_tx.orig) &&
!((flags = le32_to_cpu(np->get_tx.orig->flaglen)) & NV_TX_VALID) &&
(tx_work < limit)) {
nv_unmap_txskb(np, np->get_tx_ctx);
if (np->desc_ver == DESC_VER_1) {
if (flags & NV_TX_LASTPACKET) {
if (flags & NV_TX_ERROR) {
if ((flags & NV_TX_RETRYERROR)
&& !(flags & NV_TX_RETRYCOUNT_MASK))
nv_legacybackoff_reseed(dev);
} else {
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_packets++;
np->stat_tx_bytes += np->get_tx_ctx->skb->len;
u64_stats_update_end(&np->swstats_tx_syncp);
}
bytes_compl += np->get_tx_ctx->skb->len;
dev_kfree_skb_any(np->get_tx_ctx->skb);
np->get_tx_ctx->skb = NULL;
tx_work++;
}
} else {
if (flags & NV_TX2_LASTPACKET) {
if (flags & NV_TX2_ERROR) {
if ((flags & NV_TX2_RETRYERROR)
&& !(flags & NV_TX2_RETRYCOUNT_MASK))
nv_legacybackoff_reseed(dev);
} else {
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_packets++;
np->stat_tx_bytes += np->get_tx_ctx->skb->len;
u64_stats_update_end(&np->swstats_tx_syncp);
}
bytes_compl += np->get_tx_ctx->skb->len;
dev_kfree_skb_any(np->get_tx_ctx->skb);
np->get_tx_ctx->skb = NULL;
tx_work++;
}
}
if (unlikely(np->get_tx.orig++ == np->last_tx.orig))
np->get_tx.orig = np->first_tx.orig;
if (unlikely(np->get_tx_ctx++ == np->last_tx_ctx))
np->get_tx_ctx = np->first_tx_ctx;
}
netdev_completed_queue(np->dev, tx_work, bytes_compl);
if (unlikely((np->tx_stop == 1) && (np->get_tx.orig != orig_get_tx))) {
np->tx_stop = 0;
netif_wake_queue(dev);
}
return tx_work;
}
static int nv_tx_done_optimized(struct net_device *dev, int limit)
{
struct fe_priv *np = netdev_priv(dev);
u32 flags;
int tx_work = 0;
struct ring_desc_ex *orig_get_tx = np->get_tx.ex;
unsigned long bytes_cleaned = 0;
while ((np->get_tx.ex != np->put_tx.ex) &&
!((flags = le32_to_cpu(np->get_tx.ex->flaglen)) & NV_TX2_VALID) &&
(tx_work < limit)) {
nv_unmap_txskb(np, np->get_tx_ctx);
if (flags & NV_TX2_LASTPACKET) {
if (flags & NV_TX2_ERROR) {
if ((flags & NV_TX2_RETRYERROR)
&& !(flags & NV_TX2_RETRYCOUNT_MASK)) {
if (np->driver_data & DEV_HAS_GEAR_MODE)
nv_gear_backoff_reseed(dev);
else
nv_legacybackoff_reseed(dev);
}
} else {
u64_stats_update_begin(&np->swstats_tx_syncp);
np->stat_tx_packets++;
np->stat_tx_bytes += np->get_tx_ctx->skb->len;
u64_stats_update_end(&np->swstats_tx_syncp);
}
bytes_cleaned += np->get_tx_ctx->skb->len;
dev_kfree_skb_any(np->get_tx_ctx->skb);
np->get_tx_ctx->skb = NULL;
tx_work++;
if (np->tx_limit)
nv_tx_flip_ownership(dev);
}
if (unlikely(np->get_tx.ex++ == np->last_tx.ex))
np->get_tx.ex = np->first_tx.ex;
if (unlikely(np->get_tx_ctx++ == np->last_tx_ctx))
np->get_tx_ctx = np->first_tx_ctx;
}
netdev_completed_queue(np->dev, tx_work, bytes_cleaned);
if (unlikely((np->tx_stop == 1) && (np->get_tx.ex != orig_get_tx))) {
np->tx_stop = 0;
netif_wake_queue(dev);
}
return tx_work;
}
static void nv_tx_timeout(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 status;
union ring_type put_tx;
int saved_tx_limit;
if (np->msi_flags & NV_MSI_X_ENABLED)
status = readl(base + NvRegMSIXIrqStatus) & NVREG_IRQSTAT_MASK;
else
status = readl(base + NvRegIrqStatus) & NVREG_IRQSTAT_MASK;
netdev_warn(dev, "Got tx_timeout. irq status: %08x\n", status);
if (unlikely(debug_tx_timeout)) {
int i;
netdev_info(dev, "Ring at %lx\n", (unsigned long)np->ring_addr);
netdev_info(dev, "Dumping tx registers\n");
for (i = 0; i <= np->register_size; i += 32) {
netdev_info(dev,
"%3x: %08x %08x %08x %08x "
"%08x %08x %08x %08x\n",
i,
readl(base + i + 0), readl(base + i + 4),
readl(base + i + 8), readl(base + i + 12),
readl(base + i + 16), readl(base + i + 20),
readl(base + i + 24), readl(base + i + 28));
}
netdev_info(dev, "Dumping tx ring\n");
for (i = 0; i < np->tx_ring_size; i += 4) {
if (!nv_optimized(np)) {
netdev_info(dev,
"%03x: %08x %08x // %08x %08x "
"// %08x %08x // %08x %08x\n",
i,
le32_to_cpu(np->tx_ring.orig[i].buf),
le32_to_cpu(np->tx_ring.orig[i].flaglen),
le32_to_cpu(np->tx_ring.orig[i+1].buf),
le32_to_cpu(np->tx_ring.orig[i+1].flaglen),
le32_to_cpu(np->tx_ring.orig[i+2].buf),
le32_to_cpu(np->tx_ring.orig[i+2].flaglen),
le32_to_cpu(np->tx_ring.orig[i+3].buf),
le32_to_cpu(np->tx_ring.orig[i+3].flaglen));
} else {
netdev_info(dev,
"%03x: %08x %08x %08x "
"// %08x %08x %08x "
"// %08x %08x %08x "
"// %08x %08x %08x\n",
i,
le32_to_cpu(np->tx_ring.ex[i].bufhigh),
le32_to_cpu(np->tx_ring.ex[i].buflow),
le32_to_cpu(np->tx_ring.ex[i].flaglen),
le32_to_cpu(np->tx_ring.ex[i+1].bufhigh),
le32_to_cpu(np->tx_ring.ex[i+1].buflow),
le32_to_cpu(np->tx_ring.ex[i+1].flaglen),
le32_to_cpu(np->tx_ring.ex[i+2].bufhigh),
le32_to_cpu(np->tx_ring.ex[i+2].buflow),
le32_to_cpu(np->tx_ring.ex[i+2].flaglen),
le32_to_cpu(np->tx_ring.ex[i+3].bufhigh),
le32_to_cpu(np->tx_ring.ex[i+3].buflow),
le32_to_cpu(np->tx_ring.ex[i+3].flaglen));
}
}
}
spin_lock_irq(&np->lock);
nv_stop_tx(dev);
saved_tx_limit = np->tx_limit;
np->tx_limit = 0;
np->tx_stop = 0;
if (!nv_optimized(np))
nv_tx_done(dev, np->tx_ring_size);
else
nv_tx_done_optimized(dev, np->tx_ring_size);
if (np->tx_change_owner)
put_tx.ex = np->tx_change_owner->first_tx_desc;
else
put_tx = np->put_tx;
nv_drain_tx(dev);
nv_init_tx(dev);
np->get_tx = np->put_tx = put_tx;
np->tx_limit = saved_tx_limit;
nv_start_tx(dev);
netif_wake_queue(dev);
spin_unlock_irq(&np->lock);
}
static int nv_getlen(struct net_device *dev, void *packet, int datalen)
{
int hdrlen;
int protolen;
if (((struct vlan_ethhdr *)packet)->h_vlan_proto == htons(ETH_P_8021Q)) {
protolen = ntohs(((struct vlan_ethhdr *)packet)->h_vlan_encapsulated_proto);
hdrlen = VLAN_HLEN;
} else {
protolen = ntohs(((struct ethhdr *)packet)->h_proto);
hdrlen = ETH_HLEN;
}
if (protolen > ETH_DATA_LEN)
return datalen;
protolen += hdrlen;
if (datalen > ETH_ZLEN) {
if (datalen >= protolen) {
return protolen;
} else {
return -1;
}
} else {
if (protolen > ETH_ZLEN) {
return -1;
}
return datalen;
}
}
static int nv_rx_process(struct net_device *dev, int limit)
{
struct fe_priv *np = netdev_priv(dev);
u32 flags;
int rx_work = 0;
struct sk_buff *skb;
int len;
while ((np->get_rx.orig != np->put_rx.orig) &&
!((flags = le32_to_cpu(np->get_rx.orig->flaglen)) & NV_RX_AVAIL) &&
(rx_work < limit)) {
pci_unmap_single(np->pci_dev, np->get_rx_ctx->dma,
np->get_rx_ctx->dma_len,
PCI_DMA_FROMDEVICE);
skb = np->get_rx_ctx->skb;
np->get_rx_ctx->skb = NULL;
if (np->desc_ver == DESC_VER_1) {
if (likely(flags & NV_RX_DESCRIPTORVALID)) {
len = flags & LEN_MASK_V1;
if (unlikely(flags & NV_RX_ERROR)) {
if ((flags & NV_RX_ERROR_MASK) == NV_RX_ERROR4) {
len = nv_getlen(dev, skb->data, len);
if (len < 0) {
dev_kfree_skb(skb);
goto next_pkt;
}
}
else if ((flags & NV_RX_ERROR_MASK) == NV_RX_FRAMINGERR) {
if (flags & NV_RX_SUBTRACT1)
len--;
}
else {
if (flags & NV_RX_MISSEDFRAME) {
u64_stats_update_begin(&np->swstats_rx_syncp);
np->stat_rx_missed_errors++;
u64_stats_update_end(&np->swstats_rx_syncp);
}
dev_kfree_skb(skb);
goto next_pkt;
}
}
} else {
dev_kfree_skb(skb);
goto next_pkt;
}
} else {
if (likely(flags & NV_RX2_DESCRIPTORVALID)) {
len = flags & LEN_MASK_V2;
if (unlikely(flags & NV_RX2_ERROR)) {
if ((flags & NV_RX2_ERROR_MASK) == NV_RX2_ERROR4) {
len = nv_getlen(dev, skb->data, len);
if (len < 0) {
dev_kfree_skb(skb);
goto next_pkt;
}
}
else if ((flags & NV_RX2_ERROR_MASK) == NV_RX2_FRAMINGERR) {
if (flags & NV_RX2_SUBTRACT1)
len--;
}
else {
dev_kfree_skb(skb);
goto next_pkt;
}
}
if (((flags & NV_RX2_CHECKSUMMASK) == NV_RX2_CHECKSUM_IP_TCP) ||
((flags & NV_RX2_CHECKSUMMASK) == NV_RX2_CHECKSUM_IP_UDP))
skb->ip_summed = CHECKSUM_UNNECESSARY;
} else {
dev_kfree_skb(skb);
goto next_pkt;
}
}
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, dev);
napi_gro_receive(&np->napi, skb);
u64_stats_update_begin(&np->swstats_rx_syncp);
np->stat_rx_packets++;
np->stat_rx_bytes += len;
u64_stats_update_end(&np->swstats_rx_syncp);
next_pkt:
if (unlikely(np->get_rx.orig++ == np->last_rx.orig))
np->get_rx.orig = np->first_rx.orig;
if (unlikely(np->get_rx_ctx++ == np->last_rx_ctx))
np->get_rx_ctx = np->first_rx_ctx;
rx_work++;
}
return rx_work;
}
static int nv_rx_process_optimized(struct net_device *dev, int limit)
{
struct fe_priv *np = netdev_priv(dev);
u32 flags;
u32 vlanflags = 0;
int rx_work = 0;
struct sk_buff *skb;
int len;
while ((np->get_rx.ex != np->put_rx.ex) &&
!((flags = le32_to_cpu(np->get_rx.ex->flaglen)) & NV_RX2_AVAIL) &&
(rx_work < limit)) {
pci_unmap_single(np->pci_dev, np->get_rx_ctx->dma,
np->get_rx_ctx->dma_len,
PCI_DMA_FROMDEVICE);
skb = np->get_rx_ctx->skb;
np->get_rx_ctx->skb = NULL;
if (likely(flags & NV_RX2_DESCRIPTORVALID)) {
len = flags & LEN_MASK_V2;
if (unlikely(flags & NV_RX2_ERROR)) {
if ((flags & NV_RX2_ERROR_MASK) == NV_RX2_ERROR4) {
len = nv_getlen(dev, skb->data, len);
if (len < 0) {
dev_kfree_skb(skb);
goto next_pkt;
}
}
else if ((flags & NV_RX2_ERROR_MASK) == NV_RX2_FRAMINGERR) {
if (flags & NV_RX2_SUBTRACT1)
len--;
}
else {
dev_kfree_skb(skb);
goto next_pkt;
}
}
if (((flags & NV_RX2_CHECKSUMMASK) == NV_RX2_CHECKSUM_IP_TCP) ||
((flags & NV_RX2_CHECKSUMMASK) == NV_RX2_CHECKSUM_IP_UDP))
skb->ip_summed = CHECKSUM_UNNECESSARY;
skb_put(skb, len);
skb->protocol = eth_type_trans(skb, dev);
prefetch(skb->data);
vlanflags = le32_to_cpu(np->get_rx.ex->buflow);
if (dev->features & NETIF_F_HW_VLAN_CTAG_RX &&
vlanflags & NV_RX3_VLAN_TAG_PRESENT) {
u16 vid = vlanflags & NV_RX3_VLAN_TAG_MASK;
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vid);
}
napi_gro_receive(&np->napi, skb);
u64_stats_update_begin(&np->swstats_rx_syncp);
np->stat_rx_packets++;
np->stat_rx_bytes += len;
u64_stats_update_end(&np->swstats_rx_syncp);
} else {
dev_kfree_skb(skb);
}
next_pkt:
if (unlikely(np->get_rx.ex++ == np->last_rx.ex))
np->get_rx.ex = np->first_rx.ex;
if (unlikely(np->get_rx_ctx++ == np->last_rx_ctx))
np->get_rx_ctx = np->first_rx_ctx;
rx_work++;
}
return rx_work;
}
static void set_bufsize(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
if (dev->mtu <= ETH_DATA_LEN)
np->rx_buf_sz = ETH_DATA_LEN + NV_RX_HEADERS;
else
np->rx_buf_sz = dev->mtu + NV_RX_HEADERS;
}
static int nv_change_mtu(struct net_device *dev, int new_mtu)
{
struct fe_priv *np = netdev_priv(dev);
int old_mtu;
old_mtu = dev->mtu;
dev->mtu = new_mtu;
if (old_mtu <= ETH_DATA_LEN && new_mtu <= ETH_DATA_LEN)
return 0;
if (netif_running(dev)) {
u8 __iomem *base = get_hwbase(dev);
nv_disable_irq(dev);
nv_napi_disable(dev);
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock(&np->lock);
nv_stop_rxtx(dev);
nv_txrx_reset(dev);
nv_drain_rxtx(dev);
set_bufsize(dev);
if (nv_init_ring(dev)) {
if (!np->in_shutdown)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
}
writel(np->rx_buf_sz, base + NvRegOffloadConfig);
setup_hw_rings(dev, NV_SETUP_RX_RING | NV_SETUP_TX_RING);
writel(((np->rx_ring_size-1) << NVREG_RINGSZ_RXSHIFT) + ((np->tx_ring_size-1) << NVREG_RINGSZ_TXSHIFT),
base + NvRegRingSizes);
pci_push(base);
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
pci_push(base);
nv_start_rxtx(dev);
spin_unlock(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
nv_napi_enable(dev);
nv_enable_irq(dev);
}
return 0;
}
static void nv_copy_mac_to_hw(struct net_device *dev)
{
u8 __iomem *base = get_hwbase(dev);
u32 mac[2];
mac[0] = (dev->dev_addr[0] << 0) + (dev->dev_addr[1] << 8) +
(dev->dev_addr[2] << 16) + (dev->dev_addr[3] << 24);
mac[1] = (dev->dev_addr[4] << 0) + (dev->dev_addr[5] << 8);
writel(mac[0], base + NvRegMacAddrA);
writel(mac[1], base + NvRegMacAddrB);
}
static int nv_set_mac_address(struct net_device *dev, void *addr)
{
struct fe_priv *np = netdev_priv(dev);
struct sockaddr *macaddr = (struct sockaddr *)addr;
if (!is_valid_ether_addr(macaddr->sa_data))
return -EADDRNOTAVAIL;
memcpy(dev->dev_addr, macaddr->sa_data, ETH_ALEN);
if (netif_running(dev)) {
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock_irq(&np->lock);
nv_stop_rx(dev);
nv_copy_mac_to_hw(dev);
nv_start_rx(dev);
spin_unlock_irq(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
} else {
nv_copy_mac_to_hw(dev);
}
return 0;
}
static void nv_set_multicast(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 addr[2];
u32 mask[2];
u32 pff = readl(base + NvRegPacketFilterFlags) & NVREG_PFF_PAUSE_RX;
memset(addr, 0, sizeof(addr));
memset(mask, 0, sizeof(mask));
if (dev->flags & IFF_PROMISC) {
pff |= NVREG_PFF_PROMISC;
} else {
pff |= NVREG_PFF_MYADDR;
if (dev->flags & IFF_ALLMULTI || !netdev_mc_empty(dev)) {
u32 alwaysOff[2];
u32 alwaysOn[2];
alwaysOn[0] = alwaysOn[1] = alwaysOff[0] = alwaysOff[1] = 0xffffffff;
if (dev->flags & IFF_ALLMULTI) {
alwaysOn[0] = alwaysOn[1] = alwaysOff[0] = alwaysOff[1] = 0;
} else {
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, dev) {
unsigned char *hw_addr = ha->addr;
u32 a, b;
a = le32_to_cpu(*(__le32 *) hw_addr);
b = le16_to_cpu(*(__le16 *) (&hw_addr[4]));
alwaysOn[0] &= a;
alwaysOff[0] &= ~a;
alwaysOn[1] &= b;
alwaysOff[1] &= ~b;
}
}
addr[0] = alwaysOn[0];
addr[1] = alwaysOn[1];
mask[0] = alwaysOn[0] | alwaysOff[0];
mask[1] = alwaysOn[1] | alwaysOff[1];
} else {
mask[0] = NVREG_MCASTMASKA_NONE;
mask[1] = NVREG_MCASTMASKB_NONE;
}
}
addr[0] |= NVREG_MCASTADDRA_FORCE;
pff |= NVREG_PFF_ALWAYS;
spin_lock_irq(&np->lock);
nv_stop_rx(dev);
writel(addr[0], base + NvRegMulticastAddrA);
writel(addr[1], base + NvRegMulticastAddrB);
writel(mask[0], base + NvRegMulticastMaskA);
writel(mask[1], base + NvRegMulticastMaskB);
writel(pff, base + NvRegPacketFilterFlags);
nv_start_rx(dev);
spin_unlock_irq(&np->lock);
}
static void nv_update_pause(struct net_device *dev, u32 pause_flags)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
np->pause_flags &= ~(NV_PAUSEFRAME_TX_ENABLE | NV_PAUSEFRAME_RX_ENABLE);
if (np->pause_flags & NV_PAUSEFRAME_RX_CAPABLE) {
u32 pff = readl(base + NvRegPacketFilterFlags) & ~NVREG_PFF_PAUSE_RX;
if (pause_flags & NV_PAUSEFRAME_RX_ENABLE) {
writel(pff|NVREG_PFF_PAUSE_RX, base + NvRegPacketFilterFlags);
np->pause_flags |= NV_PAUSEFRAME_RX_ENABLE;
} else {
writel(pff, base + NvRegPacketFilterFlags);
}
}
if (np->pause_flags & NV_PAUSEFRAME_TX_CAPABLE) {
u32 regmisc = readl(base + NvRegMisc1) & ~NVREG_MISC1_PAUSE_TX;
if (pause_flags & NV_PAUSEFRAME_TX_ENABLE) {
u32 pause_enable = NVREG_TX_PAUSEFRAME_ENABLE_V1;
if (np->driver_data & DEV_HAS_PAUSEFRAME_TX_V2)
pause_enable = NVREG_TX_PAUSEFRAME_ENABLE_V2;
if (np->driver_data & DEV_HAS_PAUSEFRAME_TX_V3) {
pause_enable = NVREG_TX_PAUSEFRAME_ENABLE_V3;
writel(readl(base + NvRegTxPauseFrameLimit)|NVREG_TX_PAUSEFRAMELIMIT_ENABLE, base + NvRegTxPauseFrameLimit);
}
writel(pause_enable, base + NvRegTxPauseFrame);
writel(regmisc|NVREG_MISC1_PAUSE_TX, base + NvRegMisc1);
np->pause_flags |= NV_PAUSEFRAME_TX_ENABLE;
} else {
writel(NVREG_TX_PAUSEFRAME_DISABLE, base + NvRegTxPauseFrame);
writel(regmisc, base + NvRegMisc1);
}
}
}
static void nv_force_linkspeed(struct net_device *dev, int speed, int duplex)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 phyreg, txreg;
int mii_status;
np->linkspeed = NVREG_LINKSPEED_FORCE|speed;
np->duplex = duplex;
mii_status = mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
if (mii_status & PHY_GIGABIT) {
np->gigabit = PHY_GIGABIT;
phyreg = readl(base + NvRegSlotTime);
phyreg &= ~(0x3FF00);
if ((np->linkspeed & 0xFFF) == NVREG_LINKSPEED_10)
phyreg |= NVREG_SLOTTIME_10_100_FULL;
else if ((np->linkspeed & 0xFFF) == NVREG_LINKSPEED_100)
phyreg |= NVREG_SLOTTIME_10_100_FULL;
else if ((np->linkspeed & 0xFFF) == NVREG_LINKSPEED_1000)
phyreg |= NVREG_SLOTTIME_1000_FULL;
writel(phyreg, base + NvRegSlotTime);
}
phyreg = readl(base + NvRegPhyInterface);
phyreg &= ~(PHY_HALF|PHY_100|PHY_1000);
if (np->duplex == 0)
phyreg |= PHY_HALF;
if ((np->linkspeed & NVREG_LINKSPEED_MASK) == NVREG_LINKSPEED_100)
phyreg |= PHY_100;
else if ((np->linkspeed & NVREG_LINKSPEED_MASK) ==
NVREG_LINKSPEED_1000)
phyreg |= PHY_1000;
writel(phyreg, base + NvRegPhyInterface);
if (phyreg & PHY_RGMII) {
if ((np->linkspeed & NVREG_LINKSPEED_MASK) ==
NVREG_LINKSPEED_1000)
txreg = NVREG_TX_DEFERRAL_RGMII_1000;
else
txreg = NVREG_TX_DEFERRAL_RGMII_10_100;
} else {
txreg = NVREG_TX_DEFERRAL_DEFAULT;
}
writel(txreg, base + NvRegTxDeferral);
if (np->desc_ver == DESC_VER_1) {
txreg = NVREG_TX_WM_DESC1_DEFAULT;
} else {
if ((np->linkspeed & NVREG_LINKSPEED_MASK) ==
NVREG_LINKSPEED_1000)
txreg = NVREG_TX_WM_DESC2_3_1000;
else
txreg = NVREG_TX_WM_DESC2_3_DEFAULT;
}
writel(txreg, base + NvRegTxWatermark);
writel(NVREG_MISC1_FORCE | (np->duplex ? 0 : NVREG_MISC1_HD),
base + NvRegMisc1);
pci_push(base);
writel(np->linkspeed, base + NvRegLinkSpeed);
pci_push(base);
return;
}
static int nv_update_linkspeed(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int adv = 0;
int lpa = 0;
int adv_lpa, adv_pause, lpa_pause;
int newls = np->linkspeed;
int newdup = np->duplex;
int mii_status;
u32 bmcr;
int retval = 0;
u32 control_1000, status_1000, phyreg, pause_flags, txreg;
u32 txrxFlags = 0;
u32 phy_exp;
bmcr = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
if (bmcr & BMCR_LOOPBACK) {
if (netif_running(dev)) {
nv_force_linkspeed(dev, NVREG_LINKSPEED_1000, 1);
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
}
return 1;
}
mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
mii_status = mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
if (!(mii_status & BMSR_LSTATUS)) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 0;
retval = 0;
goto set_speed;
}
if (np->autoneg == 0) {
if (np->fixed_mode & LPA_100FULL) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_100;
newdup = 1;
} else if (np->fixed_mode & LPA_100HALF) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_100;
newdup = 0;
} else if (np->fixed_mode & LPA_10FULL) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 1;
} else {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 0;
}
retval = 1;
goto set_speed;
}
if (!(mii_status & BMSR_ANEGCOMPLETE)) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 0;
retval = 0;
goto set_speed;
}
adv = mii_rw(dev, np->phyaddr, MII_ADVERTISE, MII_READ);
lpa = mii_rw(dev, np->phyaddr, MII_LPA, MII_READ);
retval = 1;
if (np->gigabit == PHY_GIGABIT) {
control_1000 = mii_rw(dev, np->phyaddr, MII_CTRL1000, MII_READ);
status_1000 = mii_rw(dev, np->phyaddr, MII_STAT1000, MII_READ);
if ((control_1000 & ADVERTISE_1000FULL) &&
(status_1000 & LPA_1000FULL)) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_1000;
newdup = 1;
goto set_speed;
}
}
adv_lpa = lpa & adv;
if (adv_lpa & LPA_100FULL) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_100;
newdup = 1;
} else if (adv_lpa & LPA_100HALF) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_100;
newdup = 0;
} else if (adv_lpa & LPA_10FULL) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 1;
} else if (adv_lpa & LPA_10HALF) {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 0;
} else {
newls = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
newdup = 0;
}
set_speed:
if (np->duplex == newdup && np->linkspeed == newls)
return retval;
np->duplex = newdup;
np->linkspeed = newls;
if (readl(base + NvRegTransmitterControl) & NVREG_XMITCTL_START) {
txrxFlags |= NV_RESTART_TX;
nv_stop_tx(dev);
}
if (readl(base + NvRegReceiverControl) & NVREG_RCVCTL_START) {
txrxFlags |= NV_RESTART_RX;
nv_stop_rx(dev);
}
if (np->gigabit == PHY_GIGABIT) {
phyreg = readl(base + NvRegSlotTime);
phyreg &= ~(0x3FF00);
if (((np->linkspeed & 0xFFF) == NVREG_LINKSPEED_10) ||
((np->linkspeed & 0xFFF) == NVREG_LINKSPEED_100))
phyreg |= NVREG_SLOTTIME_10_100_FULL;
else if ((np->linkspeed & 0xFFF) == NVREG_LINKSPEED_1000)
phyreg |= NVREG_SLOTTIME_1000_FULL;
writel(phyreg, base + NvRegSlotTime);
}
phyreg = readl(base + NvRegPhyInterface);
phyreg &= ~(PHY_HALF|PHY_100|PHY_1000);
if (np->duplex == 0)
phyreg |= PHY_HALF;
if ((np->linkspeed & NVREG_LINKSPEED_MASK) == NVREG_LINKSPEED_100)
phyreg |= PHY_100;
else if ((np->linkspeed & NVREG_LINKSPEED_MASK) == NVREG_LINKSPEED_1000)
phyreg |= PHY_1000;
writel(phyreg, base + NvRegPhyInterface);
phy_exp = mii_rw(dev, np->phyaddr, MII_EXPANSION, MII_READ) & EXPANSION_NWAY;
if (phyreg & PHY_RGMII) {
if ((np->linkspeed & NVREG_LINKSPEED_MASK) == NVREG_LINKSPEED_1000) {
txreg = NVREG_TX_DEFERRAL_RGMII_1000;
} else {
if (!phy_exp && !np->duplex && (np->driver_data & DEV_HAS_COLLISION_FIX)) {
if ((np->linkspeed & NVREG_LINKSPEED_MASK) == NVREG_LINKSPEED_10)
txreg = NVREG_TX_DEFERRAL_RGMII_STRETCH_10;
else
txreg = NVREG_TX_DEFERRAL_RGMII_STRETCH_100;
} else {
txreg = NVREG_TX_DEFERRAL_RGMII_10_100;
}
}
} else {
if (!phy_exp && !np->duplex && (np->driver_data & DEV_HAS_COLLISION_FIX))
txreg = NVREG_TX_DEFERRAL_MII_STRETCH;
else
txreg = NVREG_TX_DEFERRAL_DEFAULT;
}
writel(txreg, base + NvRegTxDeferral);
if (np->desc_ver == DESC_VER_1) {
txreg = NVREG_TX_WM_DESC1_DEFAULT;
} else {
if ((np->linkspeed & NVREG_LINKSPEED_MASK) == NVREG_LINKSPEED_1000)
txreg = NVREG_TX_WM_DESC2_3_1000;
else
txreg = NVREG_TX_WM_DESC2_3_DEFAULT;
}
writel(txreg, base + NvRegTxWatermark);
writel(NVREG_MISC1_FORCE | (np->duplex ? 0 : NVREG_MISC1_HD),
base + NvRegMisc1);
pci_push(base);
writel(np->linkspeed, base + NvRegLinkSpeed);
pci_push(base);
pause_flags = 0;
if (netif_running(dev) && (np->duplex != 0)) {
if (np->autoneg && np->pause_flags & NV_PAUSEFRAME_AUTONEG) {
adv_pause = adv & (ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM);
lpa_pause = lpa & (LPA_PAUSE_CAP | LPA_PAUSE_ASYM);
switch (adv_pause) {
case ADVERTISE_PAUSE_CAP:
if (lpa_pause & LPA_PAUSE_CAP) {
pause_flags |= NV_PAUSEFRAME_RX_ENABLE;
if (np->pause_flags & NV_PAUSEFRAME_TX_REQ)
pause_flags |= NV_PAUSEFRAME_TX_ENABLE;
}
break;
case ADVERTISE_PAUSE_ASYM:
if (lpa_pause == (LPA_PAUSE_CAP | LPA_PAUSE_ASYM))
pause_flags |= NV_PAUSEFRAME_TX_ENABLE;
break;
case ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM:
if (lpa_pause & LPA_PAUSE_CAP) {
pause_flags |= NV_PAUSEFRAME_RX_ENABLE;
if (np->pause_flags & NV_PAUSEFRAME_TX_REQ)
pause_flags |= NV_PAUSEFRAME_TX_ENABLE;
}
if (lpa_pause == LPA_PAUSE_ASYM)
pause_flags |= NV_PAUSEFRAME_RX_ENABLE;
break;
}
} else {
pause_flags = np->pause_flags;
}
}
nv_update_pause(dev, pause_flags);
if (txrxFlags & NV_RESTART_TX)
nv_start_tx(dev);
if (txrxFlags & NV_RESTART_RX)
nv_start_rx(dev);
return retval;
}
static void nv_linkchange(struct net_device *dev)
{
if (nv_update_linkspeed(dev)) {
if (!netif_carrier_ok(dev)) {
netif_carrier_on(dev);
netdev_info(dev, "link up\n");
nv_txrx_gate(dev, false);
nv_start_rx(dev);
}
} else {
if (netif_carrier_ok(dev)) {
netif_carrier_off(dev);
netdev_info(dev, "link down\n");
nv_txrx_gate(dev, true);
nv_stop_rx(dev);
}
}
}
static void nv_link_irq(struct net_device *dev)
{
u8 __iomem *base = get_hwbase(dev);
u32 miistat;
miistat = readl(base + NvRegMIIStatus);
writel(NVREG_MIISTAT_LINKCHANGE, base + NvRegMIIStatus);
if (miistat & (NVREG_MIISTAT_LINKCHANGE))
nv_linkchange(dev);
}
static void nv_msi_workaround(struct fe_priv *np)
{
if (np->msi_flags & NV_MSI_ENABLED) {
u8 __iomem *base = np->base;
writel(0, base + NvRegMSIIrqMask);
writel(NVREG_MSI_VECTOR_0_ENABLED, base + NvRegMSIIrqMask);
}
}
static inline int nv_change_interrupt_mode(struct net_device *dev, int total_work)
{
struct fe_priv *np = netdev_priv(dev);
if (optimization_mode == NV_OPTIMIZATION_MODE_DYNAMIC) {
if (total_work > NV_DYNAMIC_THRESHOLD) {
np->quiet_count = 0;
if (np->irqmask != NVREG_IRQMASK_CPU) {
np->irqmask = NVREG_IRQMASK_CPU;
return 1;
}
} else {
if (np->quiet_count < NV_DYNAMIC_MAX_QUIET_COUNT) {
np->quiet_count++;
} else {
if (np->irqmask != NVREG_IRQMASK_THROUGHPUT) {
np->irqmask = NVREG_IRQMASK_THROUGHPUT;
return 1;
}
}
}
}
return 0;
}
static irqreturn_t nv_nic_irq(int foo, void *data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
if (!(np->msi_flags & NV_MSI_X_ENABLED)) {
np->events = readl(base + NvRegIrqStatus);
writel(np->events, base + NvRegIrqStatus);
} else {
np->events = readl(base + NvRegMSIXIrqStatus);
writel(np->events, base + NvRegMSIXIrqStatus);
}
if (!(np->events & np->irqmask))
return IRQ_NONE;
nv_msi_workaround(np);
if (napi_schedule_prep(&np->napi)) {
writel(0, base + NvRegIrqMask);
__napi_schedule(&np->napi);
}
return IRQ_HANDLED;
}
static irqreturn_t nv_nic_irq_optimized(int foo, void *data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
if (!(np->msi_flags & NV_MSI_X_ENABLED)) {
np->events = readl(base + NvRegIrqStatus);
writel(np->events, base + NvRegIrqStatus);
} else {
np->events = readl(base + NvRegMSIXIrqStatus);
writel(np->events, base + NvRegMSIXIrqStatus);
}
if (!(np->events & np->irqmask))
return IRQ_NONE;
nv_msi_workaround(np);
if (napi_schedule_prep(&np->napi)) {
writel(0, base + NvRegIrqMask);
__napi_schedule(&np->napi);
}
return IRQ_HANDLED;
}
static irqreturn_t nv_nic_irq_tx(int foo, void *data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 events;
int i;
unsigned long flags;
for (i = 0;; i++) {
events = readl(base + NvRegMSIXIrqStatus) & NVREG_IRQ_TX_ALL;
writel(events, base + NvRegMSIXIrqStatus);
netdev_dbg(dev, "tx irq events: %08x\n", events);
if (!(events & np->irqmask))
break;
spin_lock_irqsave(&np->lock, flags);
nv_tx_done_optimized(dev, TX_WORK_PER_LOOP);
spin_unlock_irqrestore(&np->lock, flags);
if (unlikely(i > max_interrupt_work)) {
spin_lock_irqsave(&np->lock, flags);
writel(NVREG_IRQ_TX_ALL, base + NvRegIrqMask);
pci_push(base);
if (!np->in_shutdown) {
np->nic_poll_irq |= NVREG_IRQ_TX_ALL;
mod_timer(&np->nic_poll, jiffies + POLL_WAIT);
}
spin_unlock_irqrestore(&np->lock, flags);
netdev_dbg(dev, "%s: too many iterations (%d)\n",
__func__, i);
break;
}
}
return IRQ_RETVAL(i);
}
static int nv_napi_poll(struct napi_struct *napi, int budget)
{
struct fe_priv *np = container_of(napi, struct fe_priv, napi);
struct net_device *dev = np->dev;
u8 __iomem *base = get_hwbase(dev);
unsigned long flags;
int retcode;
int rx_count, tx_work = 0, rx_work = 0;
do {
if (!nv_optimized(np)) {
spin_lock_irqsave(&np->lock, flags);
tx_work += nv_tx_done(dev, np->tx_ring_size);
spin_unlock_irqrestore(&np->lock, flags);
rx_count = nv_rx_process(dev, budget - rx_work);
retcode = nv_alloc_rx(dev);
} else {
spin_lock_irqsave(&np->lock, flags);
tx_work += nv_tx_done_optimized(dev, np->tx_ring_size);
spin_unlock_irqrestore(&np->lock, flags);
rx_count = nv_rx_process_optimized(dev,
budget - rx_work);
retcode = nv_alloc_rx_optimized(dev);
}
} while (retcode == 0 &&
rx_count > 0 && (rx_work += rx_count) < budget);
if (retcode) {
spin_lock_irqsave(&np->lock, flags);
if (!np->in_shutdown)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
spin_unlock_irqrestore(&np->lock, flags);
}
nv_change_interrupt_mode(dev, tx_work + rx_work);
if (unlikely(np->events & NVREG_IRQ_LINK)) {
spin_lock_irqsave(&np->lock, flags);
nv_link_irq(dev);
spin_unlock_irqrestore(&np->lock, flags);
}
if (unlikely(np->need_linktimer && time_after(jiffies, np->link_timeout))) {
spin_lock_irqsave(&np->lock, flags);
nv_linkchange(dev);
spin_unlock_irqrestore(&np->lock, flags);
np->link_timeout = jiffies + LINK_TIMEOUT;
}
if (unlikely(np->events & NVREG_IRQ_RECOVER_ERROR)) {
spin_lock_irqsave(&np->lock, flags);
if (!np->in_shutdown) {
np->nic_poll_irq = np->irqmask;
np->recover_error = 1;
mod_timer(&np->nic_poll, jiffies + POLL_WAIT);
}
spin_unlock_irqrestore(&np->lock, flags);
napi_complete(napi);
return rx_work;
}
if (rx_work < budget) {
napi_complete(napi);
writel(np->irqmask, base + NvRegIrqMask);
}
return rx_work;
}
static irqreturn_t nv_nic_irq_rx(int foo, void *data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 events;
int i;
unsigned long flags;
for (i = 0;; i++) {
events = readl(base + NvRegMSIXIrqStatus) & NVREG_IRQ_RX_ALL;
writel(events, base + NvRegMSIXIrqStatus);
netdev_dbg(dev, "rx irq events: %08x\n", events);
if (!(events & np->irqmask))
break;
if (nv_rx_process_optimized(dev, RX_WORK_PER_LOOP)) {
if (unlikely(nv_alloc_rx_optimized(dev))) {
spin_lock_irqsave(&np->lock, flags);
if (!np->in_shutdown)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
spin_unlock_irqrestore(&np->lock, flags);
}
}
if (unlikely(i > max_interrupt_work)) {
spin_lock_irqsave(&np->lock, flags);
writel(NVREG_IRQ_RX_ALL, base + NvRegIrqMask);
pci_push(base);
if (!np->in_shutdown) {
np->nic_poll_irq |= NVREG_IRQ_RX_ALL;
mod_timer(&np->nic_poll, jiffies + POLL_WAIT);
}
spin_unlock_irqrestore(&np->lock, flags);
netdev_dbg(dev, "%s: too many iterations (%d)\n",
__func__, i);
break;
}
}
return IRQ_RETVAL(i);
}
static irqreturn_t nv_nic_irq_other(int foo, void *data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 events;
int i;
unsigned long flags;
for (i = 0;; i++) {
events = readl(base + NvRegMSIXIrqStatus) & NVREG_IRQ_OTHER;
writel(events, base + NvRegMSIXIrqStatus);
netdev_dbg(dev, "irq events: %08x\n", events);
if (!(events & np->irqmask))
break;
spin_lock_irqsave(&np->lock, flags);
nv_tx_done_optimized(dev, TX_WORK_PER_LOOP);
spin_unlock_irqrestore(&np->lock, flags);
if (events & NVREG_IRQ_LINK) {
spin_lock_irqsave(&np->lock, flags);
nv_link_irq(dev);
spin_unlock_irqrestore(&np->lock, flags);
}
if (np->need_linktimer && time_after(jiffies, np->link_timeout)) {
spin_lock_irqsave(&np->lock, flags);
nv_linkchange(dev);
spin_unlock_irqrestore(&np->lock, flags);
np->link_timeout = jiffies + LINK_TIMEOUT;
}
if (events & NVREG_IRQ_RECOVER_ERROR) {
spin_lock_irqsave(&np->lock, flags);
writel(NVREG_IRQ_OTHER, base + NvRegIrqMask);
pci_push(base);
if (!np->in_shutdown) {
np->nic_poll_irq |= NVREG_IRQ_OTHER;
np->recover_error = 1;
mod_timer(&np->nic_poll, jiffies + POLL_WAIT);
}
spin_unlock_irqrestore(&np->lock, flags);
break;
}
if (unlikely(i > max_interrupt_work)) {
spin_lock_irqsave(&np->lock, flags);
writel(NVREG_IRQ_OTHER, base + NvRegIrqMask);
pci_push(base);
if (!np->in_shutdown) {
np->nic_poll_irq |= NVREG_IRQ_OTHER;
mod_timer(&np->nic_poll, jiffies + POLL_WAIT);
}
spin_unlock_irqrestore(&np->lock, flags);
netdev_dbg(dev, "%s: too many iterations (%d)\n",
__func__, i);
break;
}
}
return IRQ_RETVAL(i);
}
static irqreturn_t nv_nic_irq_test(int foo, void *data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 events;
if (!(np->msi_flags & NV_MSI_X_ENABLED)) {
events = readl(base + NvRegIrqStatus) & NVREG_IRQSTAT_MASK;
writel(events & NVREG_IRQ_TIMER, base + NvRegIrqStatus);
} else {
events = readl(base + NvRegMSIXIrqStatus) & NVREG_IRQSTAT_MASK;
writel(events & NVREG_IRQ_TIMER, base + NvRegMSIXIrqStatus);
}
pci_push(base);
if (!(events & NVREG_IRQ_TIMER))
return IRQ_RETVAL(0);
nv_msi_workaround(np);
spin_lock(&np->lock);
np->intr_test = 1;
spin_unlock(&np->lock);
return IRQ_RETVAL(1);
}
static void set_msix_vector_map(struct net_device *dev, u32 vector, u32 irqmask)
{
u8 __iomem *base = get_hwbase(dev);
int i;
u32 msixmap = 0;
for (i = 0; i < 8; i++) {
if ((irqmask >> i) & 0x1)
msixmap |= vector << (i << 2);
}
writel(readl(base + NvRegMSIXMap0) | msixmap, base + NvRegMSIXMap0);
msixmap = 0;
for (i = 0; i < 8; i++) {
if ((irqmask >> (i + 8)) & 0x1)
msixmap |= vector << (i << 2);
}
writel(readl(base + NvRegMSIXMap1) | msixmap, base + NvRegMSIXMap1);
}
static int nv_request_irq(struct net_device *dev, int intr_test)
{
struct fe_priv *np = get_nvpriv(dev);
u8 __iomem *base = get_hwbase(dev);
int ret;
int i;
irqreturn_t (*handler)(int foo, void *data);
if (intr_test) {
handler = nv_nic_irq_test;
} else {
if (nv_optimized(np))
handler = nv_nic_irq_optimized;
else
handler = nv_nic_irq;
}
if (np->msi_flags & NV_MSI_X_CAPABLE) {
for (i = 0; i < (np->msi_flags & NV_MSI_X_VECTORS_MASK); i++)
np->msi_x_entry[i].entry = i;
ret = pci_enable_msix_range(np->pci_dev,
np->msi_x_entry,
np->msi_flags & NV_MSI_X_VECTORS_MASK,
np->msi_flags & NV_MSI_X_VECTORS_MASK);
if (ret > 0) {
np->msi_flags |= NV_MSI_X_ENABLED;
if (optimization_mode == NV_OPTIMIZATION_MODE_THROUGHPUT && !intr_test) {
sprintf(np->name_rx, "%s-rx", dev->name);
ret = request_irq(np->msi_x_entry[NV_MSI_X_VECTOR_RX].vector,
nv_nic_irq_rx, IRQF_SHARED, np->name_rx, dev);
if (ret) {
netdev_info(dev,
"request_irq failed for rx %d\n",
ret);
pci_disable_msix(np->pci_dev);
np->msi_flags &= ~NV_MSI_X_ENABLED;
goto out_err;
}
sprintf(np->name_tx, "%s-tx", dev->name);
ret = request_irq(np->msi_x_entry[NV_MSI_X_VECTOR_TX].vector,
nv_nic_irq_tx, IRQF_SHARED, np->name_tx, dev);
if (ret) {
netdev_info(dev,
"request_irq failed for tx %d\n",
ret);
pci_disable_msix(np->pci_dev);
np->msi_flags &= ~NV_MSI_X_ENABLED;
goto out_free_rx;
}
sprintf(np->name_other, "%s-other", dev->name);
ret = request_irq(np->msi_x_entry[NV_MSI_X_VECTOR_OTHER].vector,
nv_nic_irq_other, IRQF_SHARED, np->name_other, dev);
if (ret) {
netdev_info(dev,
"request_irq failed for link %d\n",
ret);
pci_disable_msix(np->pci_dev);
np->msi_flags &= ~NV_MSI_X_ENABLED;
goto out_free_tx;
}
writel(0, base + NvRegMSIXMap0);
writel(0, base + NvRegMSIXMap1);
set_msix_vector_map(dev, NV_MSI_X_VECTOR_RX, NVREG_IRQ_RX_ALL);
set_msix_vector_map(dev, NV_MSI_X_VECTOR_TX, NVREG_IRQ_TX_ALL);
set_msix_vector_map(dev, NV_MSI_X_VECTOR_OTHER, NVREG_IRQ_OTHER);
} else {
ret = request_irq(np->msi_x_entry[NV_MSI_X_VECTOR_ALL].vector,
handler, IRQF_SHARED, dev->name, dev);
if (ret) {
netdev_info(dev,
"request_irq failed %d\n",
ret);
pci_disable_msix(np->pci_dev);
np->msi_flags &= ~NV_MSI_X_ENABLED;
goto out_err;
}
writel(0, base + NvRegMSIXMap0);
writel(0, base + NvRegMSIXMap1);
}
netdev_info(dev, "MSI-X enabled\n");
return 0;
}
}
if (np->msi_flags & NV_MSI_CAPABLE) {
ret = pci_enable_msi(np->pci_dev);
if (ret == 0) {
np->msi_flags |= NV_MSI_ENABLED;
ret = request_irq(np->pci_dev->irq, handler, IRQF_SHARED, dev->name, dev);
if (ret) {
netdev_info(dev, "request_irq failed %d\n",
ret);
pci_disable_msi(np->pci_dev);
np->msi_flags &= ~NV_MSI_ENABLED;
goto out_err;
}
writel(0, base + NvRegMSIMap0);
writel(0, base + NvRegMSIMap1);
writel(NVREG_MSI_VECTOR_0_ENABLED, base + NvRegMSIIrqMask);
netdev_info(dev, "MSI enabled\n");
return 0;
}
}
if (request_irq(np->pci_dev->irq, handler, IRQF_SHARED, dev->name, dev) != 0)
goto out_err;
return 0;
out_free_tx:
free_irq(np->msi_x_entry[NV_MSI_X_VECTOR_TX].vector, dev);
out_free_rx:
free_irq(np->msi_x_entry[NV_MSI_X_VECTOR_RX].vector, dev);
out_err:
return 1;
}
static void nv_free_irq(struct net_device *dev)
{
struct fe_priv *np = get_nvpriv(dev);
int i;
if (np->msi_flags & NV_MSI_X_ENABLED) {
for (i = 0; i < (np->msi_flags & NV_MSI_X_VECTORS_MASK); i++)
free_irq(np->msi_x_entry[i].vector, dev);
pci_disable_msix(np->pci_dev);
np->msi_flags &= ~NV_MSI_X_ENABLED;
} else {
free_irq(np->pci_dev->irq, dev);
if (np->msi_flags & NV_MSI_ENABLED) {
pci_disable_msi(np->pci_dev);
np->msi_flags &= ~NV_MSI_ENABLED;
}
}
}
static void nv_do_nic_poll(unsigned long data)
{
struct net_device *dev = (struct net_device *) data;
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 mask = 0;
unsigned long flags;
unsigned int irq = 0;
if (!using_multi_irqs(dev)) {
if (np->msi_flags & NV_MSI_X_ENABLED)
irq = np->msi_x_entry[NV_MSI_X_VECTOR_ALL].vector;
else
irq = np->pci_dev->irq;
mask = np->irqmask;
} else {
if (np->nic_poll_irq & NVREG_IRQ_RX_ALL) {
irq = np->msi_x_entry[NV_MSI_X_VECTOR_RX].vector;
mask |= NVREG_IRQ_RX_ALL;
}
if (np->nic_poll_irq & NVREG_IRQ_TX_ALL) {
irq = np->msi_x_entry[NV_MSI_X_VECTOR_TX].vector;
mask |= NVREG_IRQ_TX_ALL;
}
if (np->nic_poll_irq & NVREG_IRQ_OTHER) {
irq = np->msi_x_entry[NV_MSI_X_VECTOR_OTHER].vector;
mask |= NVREG_IRQ_OTHER;
}
}
disable_irq_nosync_lockdep_irqsave(irq, &flags);
synchronize_irq(irq);
if (np->recover_error) {
np->recover_error = 0;
netdev_info(dev, "MAC in recoverable error state\n");
if (netif_running(dev)) {
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock(&np->lock);
nv_stop_rxtx(dev);
if (np->driver_data & DEV_HAS_POWER_CNTRL)
nv_mac_reset(dev);
nv_txrx_reset(dev);
nv_drain_rxtx(dev);
set_bufsize(dev);
if (nv_init_ring(dev)) {
if (!np->in_shutdown)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
}
writel(np->rx_buf_sz, base + NvRegOffloadConfig);
setup_hw_rings(dev, NV_SETUP_RX_RING | NV_SETUP_TX_RING);
writel(((np->rx_ring_size-1) << NVREG_RINGSZ_RXSHIFT) + ((np->tx_ring_size-1) << NVREG_RINGSZ_TXSHIFT),
base + NvRegRingSizes);
pci_push(base);
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
pci_push(base);
if (!(np->msi_flags & NV_MSI_X_ENABLED))
writel(NVREG_IRQSTAT_MASK, base + NvRegIrqStatus);
else
writel(NVREG_IRQSTAT_MASK, base + NvRegMSIXIrqStatus);
nv_start_rxtx(dev);
spin_unlock(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
}
}
writel(mask, base + NvRegIrqMask);
pci_push(base);
if (!using_multi_irqs(dev)) {
np->nic_poll_irq = 0;
if (nv_optimized(np))
nv_nic_irq_optimized(0, dev);
else
nv_nic_irq(0, dev);
} else {
if (np->nic_poll_irq & NVREG_IRQ_RX_ALL) {
np->nic_poll_irq &= ~NVREG_IRQ_RX_ALL;
nv_nic_irq_rx(0, dev);
}
if (np->nic_poll_irq & NVREG_IRQ_TX_ALL) {
np->nic_poll_irq &= ~NVREG_IRQ_TX_ALL;
nv_nic_irq_tx(0, dev);
}
if (np->nic_poll_irq & NVREG_IRQ_OTHER) {
np->nic_poll_irq &= ~NVREG_IRQ_OTHER;
nv_nic_irq_other(0, dev);
}
}
enable_irq_lockdep_irqrestore(irq, &flags);
}
static void nv_poll_controller(struct net_device *dev)
{
nv_do_nic_poll((unsigned long) dev);
}
static void nv_do_stats_poll(unsigned long data)
__acquires(&netdev_priv(dev)->hwstats_lock
static void nv_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct fe_priv *np = netdev_priv(dev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, FORCEDETH_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(np->pci_dev), sizeof(info->bus_info));
}
static void nv_get_wol(struct net_device *dev, struct ethtool_wolinfo *wolinfo)
{
struct fe_priv *np = netdev_priv(dev);
wolinfo->supported = WAKE_MAGIC;
spin_lock_irq(&np->lock);
if (np->wolenabled)
wolinfo->wolopts = WAKE_MAGIC;
spin_unlock_irq(&np->lock);
}
static int nv_set_wol(struct net_device *dev, struct ethtool_wolinfo *wolinfo)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 flags = 0;
if (wolinfo->wolopts == 0) {
np->wolenabled = 0;
} else if (wolinfo->wolopts & WAKE_MAGIC) {
np->wolenabled = 1;
flags = NVREG_WAKEUPFLAGS_ENABLE;
}
if (netif_running(dev)) {
spin_lock_irq(&np->lock);
writel(flags, base + NvRegWakeUpFlags);
spin_unlock_irq(&np->lock);
}
device_set_wakeup_enable(&np->pci_dev->dev, np->wolenabled);
return 0;
}
static int nv_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct fe_priv *np = netdev_priv(dev);
u32 speed;
int adv;
spin_lock_irq(&np->lock);
ecmd->port = PORT_MII;
if (!netif_running(dev)) {
if (nv_update_linkspeed(dev)) {
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
} else {
if (netif_carrier_ok(dev))
netif_carrier_off(dev);
}
}
if (netif_carrier_ok(dev)) {
switch (np->linkspeed & (NVREG_LINKSPEED_MASK)) {
case NVREG_LINKSPEED_10:
speed = SPEED_10;
break;
case NVREG_LINKSPEED_100:
speed = SPEED_100;
break;
case NVREG_LINKSPEED_1000:
speed = SPEED_1000;
break;
default:
speed = -1;
break;
}
ecmd->duplex = DUPLEX_HALF;
if (np->duplex)
ecmd->duplex = DUPLEX_FULL;
} else {
speed = SPEED_UNKNOWN;
ecmd->duplex = DUPLEX_UNKNOWN;
}
ethtool_cmd_speed_set(ecmd, speed);
ecmd->autoneg = np->autoneg;
ecmd->advertising = ADVERTISED_MII;
if (np->autoneg) {
ecmd->advertising |= ADVERTISED_Autoneg;
adv = mii_rw(dev, np->phyaddr, MII_ADVERTISE, MII_READ);
if (adv & ADVERTISE_10HALF)
ecmd->advertising |= ADVERTISED_10baseT_Half;
if (adv & ADVERTISE_10FULL)
ecmd->advertising |= ADVERTISED_10baseT_Full;
if (adv & ADVERTISE_100HALF)
ecmd->advertising |= ADVERTISED_100baseT_Half;
if (adv & ADVERTISE_100FULL)
ecmd->advertising |= ADVERTISED_100baseT_Full;
if (np->gigabit == PHY_GIGABIT) {
adv = mii_rw(dev, np->phyaddr, MII_CTRL1000, MII_READ);
if (adv & ADVERTISE_1000FULL)
ecmd->advertising |= ADVERTISED_1000baseT_Full;
}
}
ecmd->supported = (SUPPORTED_Autoneg |
SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
SUPPORTED_MII);
if (np->gigabit == PHY_GIGABIT)
ecmd->supported |= SUPPORTED_1000baseT_Full;
ecmd->phy_address = np->phyaddr;
ecmd->transceiver = XCVR_EXTERNAL;
spin_unlock_irq(&np->lock);
return 0;
}
static int nv_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct fe_priv *np = netdev_priv(dev);
u32 speed = ethtool_cmd_speed(ecmd);
if (ecmd->port != PORT_MII)
return -EINVAL;
if (ecmd->transceiver != XCVR_EXTERNAL)
return -EINVAL;
if (ecmd->phy_address != np->phyaddr) {
return -EINVAL;
}
if (ecmd->autoneg == AUTONEG_ENABLE) {
u32 mask;
mask = ADVERTISED_10baseT_Half | ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half | ADVERTISED_100baseT_Full;
if (np->gigabit == PHY_GIGABIT)
mask |= ADVERTISED_1000baseT_Full;
if ((ecmd->advertising & mask) == 0)
return -EINVAL;
} else if (ecmd->autoneg == AUTONEG_DISABLE) {
if (speed != SPEED_10 && speed != SPEED_100)
return -EINVAL;
if (ecmd->duplex != DUPLEX_HALF && ecmd->duplex != DUPLEX_FULL)
return -EINVAL;
} else {
return -EINVAL;
}
netif_carrier_off(dev);
if (netif_running(dev)) {
unsigned long flags;
nv_disable_irq(dev);
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock_irqsave(&np->lock, flags);
nv_stop_rxtx(dev);
spin_unlock_irqrestore(&np->lock, flags);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
}
if (ecmd->autoneg == AUTONEG_ENABLE) {
int adv, bmcr;
np->autoneg = 1;
adv = mii_rw(dev, np->phyaddr, MII_ADVERTISE, MII_READ);
adv &= ~(ADVERTISE_ALL | ADVERTISE_100BASE4 | ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM);
if (ecmd->advertising & ADVERTISED_10baseT_Half)
adv |= ADVERTISE_10HALF;
if (ecmd->advertising & ADVERTISED_10baseT_Full)
adv |= ADVERTISE_10FULL;
if (ecmd->advertising & ADVERTISED_100baseT_Half)
adv |= ADVERTISE_100HALF;
if (ecmd->advertising & ADVERTISED_100baseT_Full)
adv |= ADVERTISE_100FULL;
if (np->pause_flags & NV_PAUSEFRAME_RX_REQ)
adv |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
if (np->pause_flags & NV_PAUSEFRAME_TX_REQ)
adv |= ADVERTISE_PAUSE_ASYM;
mii_rw(dev, np->phyaddr, MII_ADVERTISE, adv);
if (np->gigabit == PHY_GIGABIT) {
adv = mii_rw(dev, np->phyaddr, MII_CTRL1000, MII_READ);
adv &= ~ADVERTISE_1000FULL;
if (ecmd->advertising & ADVERTISED_1000baseT_Full)
adv |= ADVERTISE_1000FULL;
mii_rw(dev, np->phyaddr, MII_CTRL1000, adv);
}
if (netif_running(dev))
netdev_info(dev, "link down\n");
bmcr = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
if (np->phy_model == PHY_MODEL_MARVELL_E3016) {
bmcr |= BMCR_ANENABLE;
if (phy_reset(dev, bmcr)) {
netdev_info(dev, "phy reset failed\n");
return -EINVAL;
}
} else {
bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
mii_rw(dev, np->phyaddr, MII_BMCR, bmcr);
}
} else {
int adv, bmcr;
np->autoneg = 0;
adv = mii_rw(dev, np->phyaddr, MII_ADVERTISE, MII_READ);
adv &= ~(ADVERTISE_ALL | ADVERTISE_100BASE4 | ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM);
if (speed == SPEED_10 && ecmd->duplex == DUPLEX_HALF)
adv |= ADVERTISE_10HALF;
if (speed == SPEED_10 && ecmd->duplex == DUPLEX_FULL)
adv |= ADVERTISE_10FULL;
if (speed == SPEED_100 && ecmd->duplex == DUPLEX_HALF)
adv |= ADVERTISE_100HALF;
if (speed == SPEED_100 && ecmd->duplex == DUPLEX_FULL)
adv |= ADVERTISE_100FULL;
np->pause_flags &= ~(NV_PAUSEFRAME_AUTONEG|NV_PAUSEFRAME_RX_ENABLE|NV_PAUSEFRAME_TX_ENABLE);
if (np->pause_flags & NV_PAUSEFRAME_RX_REQ) {
adv |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
np->pause_flags |= NV_PAUSEFRAME_RX_ENABLE;
}
if (np->pause_flags & NV_PAUSEFRAME_TX_REQ) {
adv |= ADVERTISE_PAUSE_ASYM;
np->pause_flags |= NV_PAUSEFRAME_TX_ENABLE;
}
mii_rw(dev, np->phyaddr, MII_ADVERTISE, adv);
np->fixed_mode = adv;
if (np->gigabit == PHY_GIGABIT) {
adv = mii_rw(dev, np->phyaddr, MII_CTRL1000, MII_READ);
adv &= ~ADVERTISE_1000FULL;
mii_rw(dev, np->phyaddr, MII_CTRL1000, adv);
}
bmcr = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
bmcr &= ~(BMCR_ANENABLE|BMCR_SPEED100|BMCR_SPEED1000|BMCR_FULLDPLX);
if (np->fixed_mode & (ADVERTISE_10FULL|ADVERTISE_100FULL))
bmcr |= BMCR_FULLDPLX;
if (np->fixed_mode & (ADVERTISE_100HALF|ADVERTISE_100FULL))
bmcr |= BMCR_SPEED100;
if (np->phy_oui == PHY_OUI_MARVELL) {
if (phy_reset(dev, bmcr)) {
netdev_info(dev, "phy reset failed\n");
return -EINVAL;
}
} else {
mii_rw(dev, np->phyaddr, MII_BMCR, bmcr);
if (netif_running(dev)) {
udelay(10);
nv_linkchange(dev);
}
}
}
if (netif_running(dev)) {
nv_start_rxtx(dev);
nv_enable_irq(dev);
}
return 0;
}
static int nv_get_regs_len(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
return np->register_size;
}
static void nv_get_regs(struct net_device *dev, struct ethtool_regs *regs, void *buf)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 *rbuf = buf;
int i;
regs->version = FORCEDETH_REGS_VER;
spin_lock_irq(&np->lock);
for (i = 0; i < np->register_size/sizeof(u32); i++)
rbuf[i] = readl(base + i*sizeof(u32));
spin_unlock_irq(&np->lock);
}
static int nv_nway_reset(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
int ret;
if (np->autoneg) {
int bmcr;
netif_carrier_off(dev);
if (netif_running(dev)) {
nv_disable_irq(dev);
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock(&np->lock);
nv_stop_rxtx(dev);
spin_unlock(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
netdev_info(dev, "link down\n");
}
bmcr = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
if (np->phy_model == PHY_MODEL_MARVELL_E3016) {
bmcr |= BMCR_ANENABLE;
if (phy_reset(dev, bmcr)) {
netdev_info(dev, "phy reset failed\n");
return -EINVAL;
}
} else {
bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
mii_rw(dev, np->phyaddr, MII_BMCR, bmcr);
}
if (netif_running(dev)) {
nv_start_rxtx(dev);
nv_enable_irq(dev);
}
ret = 0;
} else {
ret = -EINVAL;
}
return ret;
}
static void nv_get_ringparam(struct net_device *dev, struct ethtool_ringparam* ring)
{
struct fe_priv *np = netdev_priv(dev);
ring->rx_max_pending = (np->desc_ver == DESC_VER_1) ? RING_MAX_DESC_VER_1 : RING_MAX_DESC_VER_2_3;
ring->tx_max_pending = (np->desc_ver == DESC_VER_1) ? RING_MAX_DESC_VER_1 : RING_MAX_DESC_VER_2_3;
ring->rx_pending = np->rx_ring_size;
ring->tx_pending = np->tx_ring_size;
}
static int nv_set_ringparam(struct net_device *dev, struct ethtool_ringparam* ring)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u8 *rxtx_ring, *rx_skbuff, *tx_skbuff;
dma_addr_t ring_addr;
if (ring->rx_pending < RX_RING_MIN ||
ring->tx_pending < TX_RING_MIN ||
ring->rx_mini_pending != 0 ||
ring->rx_jumbo_pending != 0 ||
(np->desc_ver == DESC_VER_1 &&
(ring->rx_pending > RING_MAX_DESC_VER_1 ||
ring->tx_pending > RING_MAX_DESC_VER_1)) ||
(np->desc_ver != DESC_VER_1 &&
(ring->rx_pending > RING_MAX_DESC_VER_2_3 ||
ring->tx_pending > RING_MAX_DESC_VER_2_3))) {
return -EINVAL;
}
if (!nv_optimized(np)) {
rxtx_ring = pci_alloc_consistent(np->pci_dev,
sizeof(struct ring_desc) * (ring->rx_pending + ring->tx_pending),
&ring_addr);
} else {
rxtx_ring = pci_alloc_consistent(np->pci_dev,
sizeof(struct ring_desc_ex) * (ring->rx_pending + ring->tx_pending),
&ring_addr);
}
rx_skbuff = kmalloc(sizeof(struct nv_skb_map) * ring->rx_pending, GFP_KERNEL);
tx_skbuff = kmalloc(sizeof(struct nv_skb_map) * ring->tx_pending, GFP_KERNEL);
if (!rxtx_ring || !rx_skbuff || !tx_skbuff) {
if (!nv_optimized(np)) {
if (rxtx_ring)
pci_free_consistent(np->pci_dev, sizeof(struct ring_desc) * (ring->rx_pending + ring->tx_pending),
rxtx_ring, ring_addr);
} else {
if (rxtx_ring)
pci_free_consistent(np->pci_dev, sizeof(struct ring_desc_ex) * (ring->rx_pending + ring->tx_pending),
rxtx_ring, ring_addr);
}
kfree(rx_skbuff);
kfree(tx_skbuff);
goto exit;
}
if (netif_running(dev)) {
nv_disable_irq(dev);
nv_napi_disable(dev);
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock(&np->lock);
nv_stop_rxtx(dev);
nv_txrx_reset(dev);
nv_drain_rxtx(dev);
free_rings(dev);
}
np->rx_ring_size = ring->rx_pending;
np->tx_ring_size = ring->tx_pending;
if (!nv_optimized(np)) {
np->rx_ring.orig = (struct ring_desc *)rxtx_ring;
np->tx_ring.orig = &np->rx_ring.orig[np->rx_ring_size];
} else {
np->rx_ring.ex = (struct ring_desc_ex *)rxtx_ring;
np->tx_ring.ex = &np->rx_ring.ex[np->rx_ring_size];
}
np->rx_skb = (struct nv_skb_map *)rx_skbuff;
np->tx_skb = (struct nv_skb_map *)tx_skbuff;
np->ring_addr = ring_addr;
memset(np->rx_skb, 0, sizeof(struct nv_skb_map) * np->rx_ring_size);
memset(np->tx_skb, 0, sizeof(struct nv_skb_map) * np->tx_ring_size);
if (netif_running(dev)) {
set_bufsize(dev);
if (nv_init_ring(dev)) {
if (!np->in_shutdown)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
}
writel(np->rx_buf_sz, base + NvRegOffloadConfig);
setup_hw_rings(dev, NV_SETUP_RX_RING | NV_SETUP_TX_RING);
writel(((np->rx_ring_size-1) << NVREG_RINGSZ_RXSHIFT) + ((np->tx_ring_size-1) << NVREG_RINGSZ_TXSHIFT),
base + NvRegRingSizes);
pci_push(base);
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
pci_push(base);
nv_start_rxtx(dev);
spin_unlock(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
nv_napi_enable(dev);
nv_enable_irq(dev);
}
return 0;
exit:
return -ENOMEM;
}
static void nv_get_pauseparam(struct net_device *dev, struct ethtool_pauseparam* pause)
{
struct fe_priv *np = netdev_priv(dev);
pause->autoneg = (np->pause_flags & NV_PAUSEFRAME_AUTONEG) != 0;
pause->rx_pause = (np->pause_flags & NV_PAUSEFRAME_RX_ENABLE) != 0;
pause->tx_pause = (np->pause_flags & NV_PAUSEFRAME_TX_ENABLE) != 0;
}
static int nv_set_pauseparam(struct net_device *dev, struct ethtool_pauseparam* pause)
{
struct fe_priv *np = netdev_priv(dev);
int adv, bmcr;
if ((!np->autoneg && np->duplex == 0) ||
(np->autoneg && !pause->autoneg && np->duplex == 0)) {
netdev_info(dev, "can not set pause settings when forced link is in half duplex\n");
return -EINVAL;
}
if (pause->tx_pause && !(np->pause_flags & NV_PAUSEFRAME_TX_CAPABLE)) {
netdev_info(dev, "hardware does not support tx pause frames\n");
return -EINVAL;
}
netif_carrier_off(dev);
if (netif_running(dev)) {
nv_disable_irq(dev);
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock(&np->lock);
nv_stop_rxtx(dev);
spin_unlock(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
}
np->pause_flags &= ~(NV_PAUSEFRAME_RX_REQ|NV_PAUSEFRAME_TX_REQ);
if (pause->rx_pause)
np->pause_flags |= NV_PAUSEFRAME_RX_REQ;
if (pause->tx_pause)
np->pause_flags |= NV_PAUSEFRAME_TX_REQ;
if (np->autoneg && pause->autoneg) {
np->pause_flags |= NV_PAUSEFRAME_AUTONEG;
adv = mii_rw(dev, np->phyaddr, MII_ADVERTISE, MII_READ);
adv &= ~(ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM);
if (np->pause_flags & NV_PAUSEFRAME_RX_REQ)
adv |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
if (np->pause_flags & NV_PAUSEFRAME_TX_REQ)
adv |= ADVERTISE_PAUSE_ASYM;
mii_rw(dev, np->phyaddr, MII_ADVERTISE, adv);
if (netif_running(dev))
netdev_info(dev, "link down\n");
bmcr = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
bmcr |= (BMCR_ANENABLE | BMCR_ANRESTART);
mii_rw(dev, np->phyaddr, MII_BMCR, bmcr);
} else {
np->pause_flags &= ~(NV_PAUSEFRAME_AUTONEG|NV_PAUSEFRAME_RX_ENABLE|NV_PAUSEFRAME_TX_ENABLE);
if (pause->rx_pause)
np->pause_flags |= NV_PAUSEFRAME_RX_ENABLE;
if (pause->tx_pause)
np->pause_flags |= NV_PAUSEFRAME_TX_ENABLE;
if (!netif_running(dev))
nv_update_linkspeed(dev);
else
nv_update_pause(dev, np->pause_flags);
}
if (netif_running(dev)) {
nv_start_rxtx(dev);
nv_enable_irq(dev);
}
return 0;
}
static int nv_set_loopback(struct net_device *dev, netdev_features_t features)
{
struct fe_priv *np = netdev_priv(dev);
unsigned long flags;
u32 miicontrol;
int err, retval = 0;
spin_lock_irqsave(&np->lock, flags);
miicontrol = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
if (features & NETIF_F_LOOPBACK) {
if (miicontrol & BMCR_LOOPBACK) {
spin_unlock_irqrestore(&np->lock, flags);
netdev_info(dev, "Loopback already enabled\n");
return 0;
}
nv_disable_irq(dev);
miicontrol |= BMCR_LOOPBACK | BMCR_FULLDPLX | BMCR_SPEED1000;
err = mii_rw(dev, np->phyaddr, MII_BMCR, miicontrol);
if (err) {
retval = PHY_ERROR;
spin_unlock_irqrestore(&np->lock, flags);
phy_init(dev);
} else {
if (netif_running(dev)) {
nv_force_linkspeed(dev, NVREG_LINKSPEED_1000,
1);
netif_carrier_on(dev);
}
spin_unlock_irqrestore(&np->lock, flags);
netdev_info(dev,
"Internal PHY loopback mode enabled.\n");
}
} else {
if (!(miicontrol & BMCR_LOOPBACK)) {
spin_unlock_irqrestore(&np->lock, flags);
netdev_info(dev, "Loopback already disabled\n");
return 0;
}
nv_disable_irq(dev);
spin_unlock_irqrestore(&np->lock, flags);
netdev_info(dev, "Internal PHY loopback mode disabled.\n");
phy_init(dev);
}
msleep(500);
spin_lock_irqsave(&np->lock, flags);
nv_enable_irq(dev);
spin_unlock_irqrestore(&np->lock, flags);
return retval;
}
static netdev_features_t nv_fix_features(struct net_device *dev,
netdev_features_t features)
{
if (features & (NETIF_F_HW_VLAN_CTAG_TX|NETIF_F_HW_VLAN_CTAG_RX))
features |= NETIF_F_RXCSUM;
return features;
}
static void nv_vlan_mode(struct net_device *dev, netdev_features_t features)
{
struct fe_priv *np = get_nvpriv(dev);
spin_lock_irq(&np->lock);
if (features & NETIF_F_HW_VLAN_CTAG_RX)
np->txrxctl_bits |= NVREG_TXRXCTL_VLANSTRIP;
else
np->txrxctl_bits &= ~NVREG_TXRXCTL_VLANSTRIP;
if (features & NETIF_F_HW_VLAN_CTAG_TX)
np->txrxctl_bits |= NVREG_TXRXCTL_VLANINS;
else
np->txrxctl_bits &= ~NVREG_TXRXCTL_VLANINS;
writel(np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
spin_unlock_irq(&np->lock);
}
static int nv_set_features(struct net_device *dev, netdev_features_t features)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
netdev_features_t changed = dev->features ^ features;
int retval;
if ((changed & NETIF_F_LOOPBACK) && netif_running(dev)) {
retval = nv_set_loopback(dev, features);
if (retval != 0)
return retval;
}
if (changed & NETIF_F_RXCSUM) {
spin_lock_irq(&np->lock);
if (features & NETIF_F_RXCSUM)
np->txrxctl_bits |= NVREG_TXRXCTL_RXCHECK;
else
np->txrxctl_bits &= ~NVREG_TXRXCTL_RXCHECK;
if (netif_running(dev))
writel(np->txrxctl_bits, base + NvRegTxRxControl);
spin_unlock_irq(&np->lock);
}
if (changed & (NETIF_F_HW_VLAN_CTAG_TX | NETIF_F_HW_VLAN_CTAG_RX))
nv_vlan_mode(dev, features);
return 0;
}
static int nv_get_sset_count(struct net_device *dev, int sset)
{
struct fe_priv *np = netdev_priv(dev);
switch (sset) {
case ETH_SS_TEST:
if (np->driver_data & DEV_HAS_TEST_EXTENDED)
return NV_TEST_COUNT_EXTENDED;
else
return NV_TEST_COUNT_BASE;
case ETH_SS_STATS:
if (np->driver_data & DEV_HAS_STATISTICS_V3)
return NV_DEV_STATISTICS_V3_COUNT;
else if (np->driver_data & DEV_HAS_STATISTICS_V2)
return NV_DEV_STATISTICS_V2_COUNT;
else if (np->driver_data & DEV_HAS_STATISTICS_V1)
return NV_DEV_STATISTICS_V1_COUNT;
else
return 0;
default:
return -EOPNOTSUPP;
}
}
static void nv_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *estats, u64 *buffer)
__acquires(&netdev_priv(dev)->hwstats_lock
static int nv_link_test(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
int mii_status;
mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
mii_status = mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
if (!(mii_status & BMSR_LSTATUS))
return 0;
else
return 1;
}
static int nv_register_test(struct net_device *dev)
{
u8 __iomem *base = get_hwbase(dev);
int i = 0;
u32 orig_read, new_read;
do {
orig_read = readl(base + nv_registers_test[i].reg);
orig_read ^= nv_registers_test[i].mask;
writel(orig_read, base + nv_registers_test[i].reg);
new_read = readl(base + nv_registers_test[i].reg);
if ((new_read & nv_registers_test[i].mask) != (orig_read & nv_registers_test[i].mask))
return 0;
orig_read ^= nv_registers_test[i].mask;
writel(orig_read, base + nv_registers_test[i].reg);
} while (nv_registers_test[++i].reg != 0);
return 1;
}
static int nv_interrupt_test(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int ret = 1;
int testcnt;
u32 save_msi_flags, save_poll_interval = 0;
if (netif_running(dev)) {
nv_free_irq(dev);
save_poll_interval = readl(base+NvRegPollingInterval);
}
np->intr_test = 0;
save_msi_flags = np->msi_flags;
np->msi_flags &= ~NV_MSI_X_VECTORS_MASK;
np->msi_flags |= 0x001;
if (nv_request_irq(dev, 1))
return 0;
writel(NVREG_POLL_DEFAULT_CPU, base + NvRegPollingInterval);
writel(NVREG_UNKSETUP6_VAL, base + NvRegUnknownSetupReg6);
nv_enable_hw_interrupts(dev, NVREG_IRQ_TIMER);
msleep(100);
spin_lock_irq(&np->lock);
testcnt = np->intr_test;
if (!testcnt)
ret = 2;
nv_disable_hw_interrupts(dev, NVREG_IRQ_TIMER);
if (!(np->msi_flags & NV_MSI_X_ENABLED))
writel(NVREG_IRQSTAT_MASK, base + NvRegIrqStatus);
else
writel(NVREG_IRQSTAT_MASK, base + NvRegMSIXIrqStatus);
spin_unlock_irq(&np->lock);
nv_free_irq(dev);
np->msi_flags = save_msi_flags;
if (netif_running(dev)) {
writel(save_poll_interval, base + NvRegPollingInterval);
writel(NVREG_UNKSETUP6_VAL, base + NvRegUnknownSetupReg6);
if (nv_request_irq(dev, 0))
return 0;
}
return ret;
}
static int nv_loopback_test(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
struct sk_buff *tx_skb, *rx_skb;
dma_addr_t test_dma_addr;
u32 tx_flags_extra = (np->desc_ver == DESC_VER_1 ? NV_TX_LASTPACKET : NV_TX2_LASTPACKET);
u32 flags;
int len, i, pkt_len;
u8 *pkt_data;
u32 filter_flags = 0;
u32 misc1_flags = 0;
int ret = 1;
if (netif_running(dev)) {
nv_disable_irq(dev);
filter_flags = readl(base + NvRegPacketFilterFlags);
misc1_flags = readl(base + NvRegMisc1);
} else {
nv_txrx_reset(dev);
}
set_bufsize(dev);
nv_init_ring(dev);
writel(NVREG_MISC1_FORCE, base + NvRegMisc1);
writel(NVREG_PFF_ALWAYS | NVREG_PFF_LOOPBACK, base + NvRegPacketFilterFlags);
writel(np->rx_buf_sz, base + NvRegOffloadConfig);
setup_hw_rings(dev, NV_SETUP_RX_RING | NV_SETUP_TX_RING);
writel(((np->rx_ring_size-1) << NVREG_RINGSZ_RXSHIFT) + ((np->tx_ring_size-1) << NVREG_RINGSZ_TXSHIFT),
base + NvRegRingSizes);
pci_push(base);
nv_start_rxtx(dev);
pkt_len = ETH_DATA_LEN;
tx_skb = netdev_alloc_skb(dev, pkt_len);
if (!tx_skb) {
ret = 0;
goto out;
}
test_dma_addr = pci_map_single(np->pci_dev, tx_skb->data,
skb_tailroom(tx_skb),
PCI_DMA_FROMDEVICE);
if (pci_dma_mapping_error(np->pci_dev,
test_dma_addr)) {
dev_kfree_skb_any(tx_skb);
goto out;
}
pkt_data = skb_put(tx_skb, pkt_len);
for (i = 0; i < pkt_len; i++)
pkt_data[i] = (u8)(i & 0xff);
if (!nv_optimized(np)) {
np->tx_ring.orig[0].buf = cpu_to_le32(test_dma_addr);
np->tx_ring.orig[0].flaglen = cpu_to_le32((pkt_len-1) | np->tx_flags | tx_flags_extra);
} else {
np->tx_ring.ex[0].bufhigh = cpu_to_le32(dma_high(test_dma_addr));
np->tx_ring.ex[0].buflow = cpu_to_le32(dma_low(test_dma_addr));
np->tx_ring.ex[0].flaglen = cpu_to_le32((pkt_len-1) | np->tx_flags | tx_flags_extra);
}
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
pci_push(get_hwbase(dev));
msleep(500);
if (!nv_optimized(np)) {
flags = le32_to_cpu(np->rx_ring.orig[0].flaglen);
len = nv_descr_getlength(&np->rx_ring.orig[0], np->desc_ver);
} else {
flags = le32_to_cpu(np->rx_ring.ex[0].flaglen);
len = nv_descr_getlength_ex(&np->rx_ring.ex[0], np->desc_ver);
}
if (flags & NV_RX_AVAIL) {
ret = 0;
} else if (np->desc_ver == DESC_VER_1) {
if (flags & NV_RX_ERROR)
ret = 0;
} else {
if (flags & NV_RX2_ERROR)
ret = 0;
}
if (ret) {
if (len != pkt_len) {
ret = 0;
} else {
rx_skb = np->rx_skb[0].skb;
for (i = 0; i < pkt_len; i++) {
if (rx_skb->data[i] != (u8)(i & 0xff)) {
ret = 0;
break;
}
}
}
}
pci_unmap_single(np->pci_dev, test_dma_addr,
(skb_end_pointer(tx_skb) - tx_skb->data),
PCI_DMA_TODEVICE);
dev_kfree_skb_any(tx_skb);
out:
nv_stop_rxtx(dev);
nv_txrx_reset(dev);
nv_drain_rxtx(dev);
if (netif_running(dev)) {
writel(misc1_flags, base + NvRegMisc1);
writel(filter_flags, base + NvRegPacketFilterFlags);
nv_enable_irq(dev);
}
return ret;
}
static void nv_self_test(struct net_device *dev, struct ethtool_test *test, u64 *buffer)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int result, count;
count = nv_get_sset_count(dev, ETH_SS_TEST);
memset(buffer, 0, count * sizeof(u64));
if (!nv_link_test(dev)) {
test->flags |= ETH_TEST_FL_FAILED;
buffer[0] = 1;
}
if (test->flags & ETH_TEST_FL_OFFLINE) {
if (netif_running(dev)) {
netif_stop_queue(dev);
nv_napi_disable(dev);
netif_tx_lock_bh(dev);
netif_addr_lock(dev);
spin_lock_irq(&np->lock);
nv_disable_hw_interrupts(dev, np->irqmask);
if (!(np->msi_flags & NV_MSI_X_ENABLED))
writel(NVREG_IRQSTAT_MASK, base + NvRegIrqStatus);
else
writel(NVREG_IRQSTAT_MASK, base + NvRegMSIXIrqStatus);
nv_stop_rxtx(dev);
nv_txrx_reset(dev);
nv_drain_rxtx(dev);
spin_unlock_irq(&np->lock);
netif_addr_unlock(dev);
netif_tx_unlock_bh(dev);
}
if (!nv_register_test(dev)) {
test->flags |= ETH_TEST_FL_FAILED;
buffer[1] = 1;
}
result = nv_interrupt_test(dev);
if (result != 1) {
test->flags |= ETH_TEST_FL_FAILED;
buffer[2] = 1;
}
if (result == 0) {
return;
}
if (count > NV_TEST_COUNT_BASE && !nv_loopback_test(dev)) {
test->flags |= ETH_TEST_FL_FAILED;
buffer[3] = 1;
}
if (netif_running(dev)) {
set_bufsize(dev);
if (nv_init_ring(dev)) {
if (!np->in_shutdown)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
}
writel(np->rx_buf_sz, base + NvRegOffloadConfig);
setup_hw_rings(dev, NV_SETUP_RX_RING | NV_SETUP_TX_RING);
writel(((np->rx_ring_size-1) << NVREG_RINGSZ_RXSHIFT) + ((np->tx_ring_size-1) << NVREG_RINGSZ_TXSHIFT),
base + NvRegRingSizes);
pci_push(base);
writel(NVREG_TXRXCTL_KICK|np->txrxctl_bits, get_hwbase(dev) + NvRegTxRxControl);
pci_push(base);
nv_start_rxtx(dev);
netif_start_queue(dev);
nv_napi_enable(dev);
nv_enable_hw_interrupts(dev, np->irqmask);
}
}
}
static void nv_get_strings(struct net_device *dev, u32 stringset, u8 *buffer)
{
switch (stringset) {
case ETH_SS_STATS:
memcpy(buffer, &nv_estats_str, nv_get_sset_count(dev, ETH_SS_STATS)*sizeof(struct nv_ethtool_str));
break;
case ETH_SS_TEST:
memcpy(buffer, &nv_etests_str, nv_get_sset_count(dev, ETH_SS_TEST)*sizeof(struct nv_ethtool_str));
break;
}
}
static int nv_mgmt_acquire_sema(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int i;
u32 tx_ctrl, mgmt_sema;
for (i = 0; i < 10; i++) {
mgmt_sema = readl(base + NvRegTransmitterControl) & NVREG_XMITCTL_MGMT_SEMA_MASK;
if (mgmt_sema == NVREG_XMITCTL_MGMT_SEMA_FREE)
break;
msleep(500);
}
if (mgmt_sema != NVREG_XMITCTL_MGMT_SEMA_FREE)
return 0;
for (i = 0; i < 2; i++) {
tx_ctrl = readl(base + NvRegTransmitterControl);
tx_ctrl |= NVREG_XMITCTL_HOST_SEMA_ACQ;
writel(tx_ctrl, base + NvRegTransmitterControl);
tx_ctrl = readl(base + NvRegTransmitterControl);
if (((tx_ctrl & NVREG_XMITCTL_HOST_SEMA_MASK) == NVREG_XMITCTL_HOST_SEMA_ACQ) &&
((tx_ctrl & NVREG_XMITCTL_MGMT_SEMA_MASK) == NVREG_XMITCTL_MGMT_SEMA_FREE)) {
np->mgmt_sema = 1;
return 1;
} else
udelay(50);
}
return 0;
}
static void nv_mgmt_release_sema(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 tx_ctrl;
if (np->driver_data & DEV_HAS_MGMT_UNIT) {
if (np->mgmt_sema) {
tx_ctrl = readl(base + NvRegTransmitterControl);
tx_ctrl &= ~NVREG_XMITCTL_HOST_SEMA_ACQ;
writel(tx_ctrl, base + NvRegTransmitterControl);
}
}
}
static int nv_mgmt_get_version(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
u32 data_ready = readl(base + NvRegTransmitterControl);
u32 data_ready2 = 0;
unsigned long start;
int ready = 0;
writel(NVREG_MGMTUNITGETVERSION, base + NvRegMgmtUnitGetVersion);
writel(data_ready ^ NVREG_XMITCTL_DATA_START, base + NvRegTransmitterControl);
start = jiffies;
while (time_before(jiffies, start + 5*HZ)) {
data_ready2 = readl(base + NvRegTransmitterControl);
if ((data_ready & NVREG_XMITCTL_DATA_READY) != (data_ready2 & NVREG_XMITCTL_DATA_READY)) {
ready = 1;
break;
}
schedule_timeout_uninterruptible(1);
}
if (!ready || (data_ready2 & NVREG_XMITCTL_DATA_ERROR))
return 0;
np->mgmt_version = readl(base + NvRegMgmtUnitVersion) & NVREG_MGMTUNITVERSION;
return 1;
}
static int nv_open(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int ret = 1;
int oom, i;
u32 low;
mii_rw(dev, np->phyaddr, MII_BMCR,
mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ) & ~BMCR_PDOWN);
nv_txrx_gate(dev, false);
if (np->driver_data & DEV_HAS_POWER_CNTRL)
nv_mac_reset(dev);
writel(NVREG_MCASTADDRA_FORCE, base + NvRegMulticastAddrA);
writel(0, base + NvRegMulticastAddrB);
writel(NVREG_MCASTMASKA_NONE, base + NvRegMulticastMaskA);
writel(NVREG_MCASTMASKB_NONE, base + NvRegMulticastMaskB);
writel(0, base + NvRegPacketFilterFlags);
writel(0, base + NvRegTransmitterControl);
writel(0, base + NvRegReceiverControl);
writel(0, base + NvRegAdapterControl);
if (np->pause_flags & NV_PAUSEFRAME_TX_CAPABLE)
writel(NVREG_TX_PAUSEFRAME_DISABLE, base + NvRegTxPauseFrame);
set_bufsize(dev);
oom = nv_init_ring(dev);
writel(0, base + NvRegLinkSpeed);
writel(readl(base + NvRegTransmitPoll) & NVREG_TRANSMITPOLL_MAC_ADDR_REV, base + NvRegTransmitPoll);
nv_txrx_reset(dev);
writel(0, base + NvRegUnknownSetupReg6);
np->in_shutdown = 0;
setup_hw_rings(dev, NV_SETUP_RX_RING | NV_SETUP_TX_RING);
writel(((np->rx_ring_size-1) << NVREG_RINGSZ_RXSHIFT) + ((np->tx_ring_size-1) << NVREG_RINGSZ_TXSHIFT),
base + NvRegRingSizes);
writel(np->linkspeed, base + NvRegLinkSpeed);
if (np->desc_ver == DESC_VER_1)
writel(NVREG_TX_WM_DESC1_DEFAULT, base + NvRegTxWatermark);
else
writel(NVREG_TX_WM_DESC2_3_DEFAULT, base + NvRegTxWatermark);
writel(np->txrxctl_bits, base + NvRegTxRxControl);
writel(np->vlanctl_bits, base + NvRegVlanControl);
pci_push(base);
writel(NVREG_TXRXCTL_BIT1|np->txrxctl_bits, base + NvRegTxRxControl);
if (reg_delay(dev, NvRegUnknownSetupReg5,
NVREG_UNKSETUP5_BIT31, NVREG_UNKSETUP5_BIT31,
NV_SETUP5_DELAY, NV_SETUP5_DELAYMAX))
netdev_info(dev,
"%s: SetupReg5, Bit 31 remained off\n", __func__);
writel(0, base + NvRegMIIMask);
writel(NVREG_IRQSTAT_MASK, base + NvRegIrqStatus);
writel(NVREG_MIISTAT_MASK_ALL, base + NvRegMIIStatus);
writel(NVREG_MISC1_FORCE | NVREG_MISC1_HD, base + NvRegMisc1);
writel(readl(base + NvRegTransmitterStatus), base + NvRegTransmitterStatus);
writel(NVREG_PFF_ALWAYS, base + NvRegPacketFilterFlags);
writel(np->rx_buf_sz, base + NvRegOffloadConfig);
writel(readl(base + NvRegReceiverStatus), base + NvRegReceiverStatus);
get_random_bytes(&low, sizeof(low));
low &= NVREG_SLOTTIME_MASK;
if (np->desc_ver == DESC_VER_1) {
writel(low|NVREG_SLOTTIME_DEFAULT, base + NvRegSlotTime);
} else {
if (!(np->driver_data & DEV_HAS_GEAR_MODE)) {
writel(NVREG_SLOTTIME_LEGBF_ENABLED|NVREG_SLOTTIME_10_100_FULL|low, base + NvRegSlotTime);
} else {
writel(NVREG_SLOTTIME_10_100_FULL, base + NvRegSlotTime);
nv_gear_backoff_reseed(dev);
}
}
writel(NVREG_TX_DEFERRAL_DEFAULT, base + NvRegTxDeferral);
writel(NVREG_RX_DEFERRAL_DEFAULT, base + NvRegRxDeferral);
if (poll_interval == -1) {
if (optimization_mode == NV_OPTIMIZATION_MODE_THROUGHPUT)
writel(NVREG_POLL_DEFAULT_THROUGHPUT, base + NvRegPollingInterval);
else
writel(NVREG_POLL_DEFAULT_CPU, base + NvRegPollingInterval);
} else
writel(poll_interval & 0xFFFF, base + NvRegPollingInterval);
writel(NVREG_UNKSETUP6_VAL, base + NvRegUnknownSetupReg6);
writel((np->phyaddr << NVREG_ADAPTCTL_PHYSHIFT)|NVREG_ADAPTCTL_PHYVALID|NVREG_ADAPTCTL_RUNNING,
base + NvRegAdapterControl);
writel(NVREG_MIISPEED_BIT8|NVREG_MIIDELAY, base + NvRegMIISpeed);
writel(NVREG_MII_LINKCHANGE, base + NvRegMIIMask);
if (np->wolenabled)
writel(NVREG_WAKEUPFLAGS_ENABLE , base + NvRegWakeUpFlags);
i = readl(base + NvRegPowerState);
if ((i & NVREG_POWERSTATE_POWEREDUP) == 0)
writel(NVREG_POWERSTATE_POWEREDUP|i, base + NvRegPowerState);
pci_push(base);
udelay(10);
writel(readl(base + NvRegPowerState) | NVREG_POWERSTATE_VALID, base + NvRegPowerState);
nv_disable_hw_interrupts(dev, np->irqmask);
pci_push(base);
writel(NVREG_MIISTAT_MASK_ALL, base + NvRegMIIStatus);
writel(NVREG_IRQSTAT_MASK, base + NvRegIrqStatus);
pci_push(base);
if (nv_request_irq(dev, 0))
goto out_drain;
nv_enable_hw_interrupts(dev, np->irqmask);
spin_lock_irq(&np->lock);
writel(NVREG_MCASTADDRA_FORCE, base + NvRegMulticastAddrA);
writel(0, base + NvRegMulticastAddrB);
writel(NVREG_MCASTMASKA_NONE, base + NvRegMulticastMaskA);
writel(NVREG_MCASTMASKB_NONE, base + NvRegMulticastMaskB);
writel(NVREG_PFF_ALWAYS|NVREG_PFF_MYADDR, base + NvRegPacketFilterFlags);
{
u32 miistat;
miistat = readl(base + NvRegMIIStatus);
writel(NVREG_MIISTAT_MASK_ALL, base + NvRegMIIStatus);
}
np->linkspeed = 0;
ret = nv_update_linkspeed(dev);
nv_start_rxtx(dev);
netif_start_queue(dev);
nv_napi_enable(dev);
if (ret) {
netif_carrier_on(dev);
} else {
netdev_info(dev, "no link during initialization\n");
netif_carrier_off(dev);
}
if (oom)
mod_timer(&np->oom_kick, jiffies + OOM_REFILL);
if (np->driver_data & (DEV_HAS_STATISTICS_V1|DEV_HAS_STATISTICS_V2|DEV_HAS_STATISTICS_V3))
mod_timer(&np->stats_poll,
round_jiffies(jiffies + STATS_INTERVAL));
spin_unlock_irq(&np->lock);
if (dev->features & NETIF_F_LOOPBACK)
nv_set_loopback(dev, dev->features);
return 0;
out_drain:
nv_drain_rxtx(dev);
return ret;
}
static int nv_close(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base;
spin_lock_irq(&np->lock);
np->in_shutdown = 1;
spin_unlock_irq(&np->lock);
nv_napi_disable(dev);
synchronize_irq(np->pci_dev->irq);
del_timer_sync(&np->oom_kick);
del_timer_sync(&np->nic_poll);
del_timer_sync(&np->stats_poll);
netif_stop_queue(dev);
spin_lock_irq(&np->lock);
nv_update_pause(dev, 0);
nv_stop_rxtx(dev);
nv_txrx_reset(dev);
base = get_hwbase(dev);
nv_disable_hw_interrupts(dev, np->irqmask);
pci_push(base);
spin_unlock_irq(&np->lock);
nv_free_irq(dev);
nv_drain_rxtx(dev);
if (np->wolenabled || !phy_power_down) {
nv_txrx_gate(dev, false);
writel(NVREG_PFF_ALWAYS|NVREG_PFF_MYADDR, base + NvRegPacketFilterFlags);
nv_start_rx(dev);
} else {
mii_rw(dev, np->phyaddr, MII_BMCR,
mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ)|BMCR_PDOWN);
nv_txrx_gate(dev, true);
}
return 0;
}
static int nv_probe(struct pci_dev *pci_dev, const struct pci_device_id *id)
{
struct net_device *dev;
struct fe_priv *np;
unsigned long addr;
u8 __iomem *base;
int err, i;
u32 powerstate, txreg;
u32 phystate_orig = 0, phystate;
int phyinitialized = 0;
static int printed_version;
if (!printed_version++)
pr_info("Reverse Engineered nForce ethernet driver. Version %s.\n",
FORCEDETH_VERSION);
dev = alloc_etherdev(sizeof(struct fe_priv));
err = -ENOMEM;
if (!dev)
goto out;
np = netdev_priv(dev);
np->dev = dev;
np->pci_dev = pci_dev;
spin_lock_init(&np->lock);
spin_lock_init(&np->hwstats_lock);
SET_NETDEV_DEV(dev, &pci_dev->dev);
u64_stats_init(&np->swstats_rx_syncp);
u64_stats_init(&np->swstats_tx_syncp);
setup_timer(&np->oom_kick, nv_do_rx_refill, (unsigned long)dev);
setup_timer(&np->nic_poll, nv_do_nic_poll, (unsigned long)dev);
init_timer_deferrable(&np->stats_poll);
np->stats_poll.data = (unsigned long) dev;
np->stats_poll.function = nv_do_stats_poll;
err = pci_enable_device(pci_dev);
if (err)
goto out_free;
pci_set_master(pci_dev);
err = pci_request_regions(pci_dev, DRV_NAME);
if (err < 0)
goto out_disable;
if (id->driver_data & (DEV_HAS_VLAN|DEV_HAS_MSI_X|DEV_HAS_POWER_CNTRL|DEV_HAS_STATISTICS_V2|DEV_HAS_STATISTICS_V3))
np->register_size = NV_PCI_REGSZ_VER3;
else if (id->driver_data & DEV_HAS_STATISTICS_V1)
np->register_size = NV_PCI_REGSZ_VER2;
else
np->register_size = NV_PCI_REGSZ_VER1;
err = -EINVAL;
addr = 0;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
if (pci_resource_flags(pci_dev, i) & IORESOURCE_MEM &&
pci_resource_len(pci_dev, i) >= np->register_size) {
addr = pci_resource_start(pci_dev, i);
break;
}
}
if (i == DEVICE_COUNT_RESOURCE) {
dev_info(&pci_dev->dev, "Couldn't find register window\n");
goto out_relreg;
}
np->driver_data = id->driver_data;
np->device_id = id->device;
if (id->driver_data & DEV_HAS_HIGH_DMA) {
np->desc_ver = DESC_VER_3;
np->txrxctl_bits = NVREG_TXRXCTL_DESC_3;
if (dma_64bit) {
if (pci_set_dma_mask(pci_dev, DMA_BIT_MASK(39)))
dev_info(&pci_dev->dev,
"64-bit DMA failed, using 32-bit addressing\n");
else
dev->features |= NETIF_F_HIGHDMA;
if (pci_set_consistent_dma_mask(pci_dev, DMA_BIT_MASK(39))) {
dev_info(&pci_dev->dev,
"64-bit DMA (consistent) failed, using 32-bit ring buffers\n");
}
}
} else if (id->driver_data & DEV_HAS_LARGEDESC) {
np->desc_ver = DESC_VER_2;
np->txrxctl_bits = NVREG_TXRXCTL_DESC_2;
} else {
np->desc_ver = DESC_VER_1;
np->txrxctl_bits = NVREG_TXRXCTL_DESC_1;
}
np->pkt_limit = NV_PKTLIMIT_1;
if (id->driver_data & DEV_HAS_LARGEDESC)
np->pkt_limit = NV_PKTLIMIT_2;
if (id->driver_data & DEV_HAS_CHECKSUM) {
np->txrxctl_bits |= NVREG_TXRXCTL_RXCHECK;
dev->hw_features |= NETIF_F_IP_CSUM | NETIF_F_SG |
NETIF_F_TSO | NETIF_F_RXCSUM;
}
np->vlanctl_bits = 0;
if (id->driver_data & DEV_HAS_VLAN) {
np->vlanctl_bits = NVREG_VLANCONTROL_ENABLE;
dev->hw_features |= NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
}
dev->features |= dev->hw_features;
dev->hw_features |= NETIF_F_LOOPBACK;
dev->min_mtu = ETH_ZLEN + ETH_FCS_LEN;
dev->max_mtu = np->pkt_limit;
np->pause_flags = NV_PAUSEFRAME_RX_CAPABLE | NV_PAUSEFRAME_RX_REQ | NV_PAUSEFRAME_AUTONEG;
if ((id->driver_data & DEV_HAS_PAUSEFRAME_TX_V1) ||
(id->driver_data & DEV_HAS_PAUSEFRAME_TX_V2) ||
(id->driver_data & DEV_HAS_PAUSEFRAME_TX_V3)) {
np->pause_flags |= NV_PAUSEFRAME_TX_CAPABLE | NV_PAUSEFRAME_TX_REQ;
}
err = -ENOMEM;
np->base = ioremap(addr, np->register_size);
if (!np->base)
goto out_relreg;
np->rx_ring_size = RX_RING_DEFAULT;
np->tx_ring_size = TX_RING_DEFAULT;
if (!nv_optimized(np)) {
np->rx_ring.orig = pci_alloc_consistent(pci_dev,
sizeof(struct ring_desc) * (np->rx_ring_size + np->tx_ring_size),
&np->ring_addr);
if (!np->rx_ring.orig)
goto out_unmap;
np->tx_ring.orig = &np->rx_ring.orig[np->rx_ring_size];
} else {
np->rx_ring.ex = pci_alloc_consistent(pci_dev,
sizeof(struct ring_desc_ex) * (np->rx_ring_size + np->tx_ring_size),
&np->ring_addr);
if (!np->rx_ring.ex)
goto out_unmap;
np->tx_ring.ex = &np->rx_ring.ex[np->rx_ring_size];
}
np->rx_skb = kcalloc(np->rx_ring_size, sizeof(struct nv_skb_map), GFP_KERNEL);
np->tx_skb = kcalloc(np->tx_ring_size, sizeof(struct nv_skb_map), GFP_KERNEL);
if (!np->rx_skb || !np->tx_skb)
goto out_freering;
if (!nv_optimized(np))
dev->netdev_ops = &nv_netdev_ops;
else
dev->netdev_ops = &nv_netdev_ops_optimized;
netif_napi_add(dev, &np->napi, nv_napi_poll, RX_WORK_PER_LOOP);
dev->ethtool_ops = &ops;
dev->watchdog_timeo = NV_WATCHDOG_TIMEO;
pci_set_drvdata(pci_dev, dev);
base = get_hwbase(dev);
np->orig_mac[0] = readl(base + NvRegMacAddrA);
np->orig_mac[1] = readl(base + NvRegMacAddrB);
txreg = readl(base + NvRegTransmitPoll);
if (id->driver_data & DEV_HAS_CORRECT_MACADDR) {
dev->dev_addr[0] = (np->orig_mac[0] >> 0) & 0xff;
dev->dev_addr[1] = (np->orig_mac[0] >> 8) & 0xff;
dev->dev_addr[2] = (np->orig_mac[0] >> 16) & 0xff;
dev->dev_addr[3] = (np->orig_mac[0] >> 24) & 0xff;
dev->dev_addr[4] = (np->orig_mac[1] >> 0) & 0xff;
dev->dev_addr[5] = (np->orig_mac[1] >> 8) & 0xff;
} else if (txreg & NVREG_TRANSMITPOLL_MAC_ADDR_REV) {
dev->dev_addr[0] = (np->orig_mac[0] >> 0) & 0xff;
dev->dev_addr[1] = (np->orig_mac[0] >> 8) & 0xff;
dev->dev_addr[2] = (np->orig_mac[0] >> 16) & 0xff;
dev->dev_addr[3] = (np->orig_mac[0] >> 24) & 0xff;
dev->dev_addr[4] = (np->orig_mac[1] >> 0) & 0xff;
dev->dev_addr[5] = (np->orig_mac[1] >> 8) & 0xff;
np->orig_mac[0] = (dev->dev_addr[5] << 0) + (dev->dev_addr[4] << 8) +
(dev->dev_addr[3] << 16) + (dev->dev_addr[2] << 24);
np->orig_mac[1] = (dev->dev_addr[1] << 0) + (dev->dev_addr[0] << 8);
} else {
dev->dev_addr[0] = (np->orig_mac[1] >> 8) & 0xff;
dev->dev_addr[1] = (np->orig_mac[1] >> 0) & 0xff;
dev->dev_addr[2] = (np->orig_mac[0] >> 24) & 0xff;
dev->dev_addr[3] = (np->orig_mac[0] >> 16) & 0xff;
dev->dev_addr[4] = (np->orig_mac[0] >> 8) & 0xff;
dev->dev_addr[5] = (np->orig_mac[0] >> 0) & 0xff;
writel(txreg|NVREG_TRANSMITPOLL_MAC_ADDR_REV, base + NvRegTransmitPoll);
dev_dbg(&pci_dev->dev,
"%s: set workaround bit for reversed mac addr\n",
__func__);
}
if (!is_valid_ether_addr(dev->dev_addr)) {
dev_err(&pci_dev->dev,
"Invalid MAC address detected: %pM - Please complain to your hardware vendor.\n",
dev->dev_addr);
eth_hw_addr_random(dev);
dev_err(&pci_dev->dev,
"Using random MAC address: %pM\n", dev->dev_addr);
}
nv_copy_mac_to_hw(dev);
writel(0, base + NvRegWakeUpFlags);
np->wolenabled = 0;
device_set_wakeup_enable(&pci_dev->dev, false);
if (id->driver_data & DEV_HAS_POWER_CNTRL) {
powerstate = readl(base + NvRegPowerState2);
powerstate &= ~NVREG_POWERSTATE2_POWERUP_MASK;
if ((id->driver_data & DEV_NEED_LOW_POWER_FIX) &&
pci_dev->revision >= 0xA3)
powerstate |= NVREG_POWERSTATE2_POWERUP_REV_A3;
writel(powerstate, base + NvRegPowerState2);
}
if (np->desc_ver == DESC_VER_1)
np->tx_flags = NV_TX_VALID;
else
np->tx_flags = NV_TX2_VALID;
np->msi_flags = 0;
if ((id->driver_data & DEV_HAS_MSI) && msi)
np->msi_flags |= NV_MSI_CAPABLE;
if ((id->driver_data & DEV_HAS_MSI_X) && msix) {
#if 0
np->msi_flags |= NV_MSI_X_CAPABLE;
#endif
}
if (optimization_mode == NV_OPTIMIZATION_MODE_CPU) {
np->irqmask = NVREG_IRQMASK_CPU;
if (np->msi_flags & NV_MSI_X_CAPABLE)
np->msi_flags |= 0x0001;
} else if (optimization_mode == NV_OPTIMIZATION_MODE_DYNAMIC &&
!(id->driver_data & DEV_NEED_TIMERIRQ)) {
np->irqmask = NVREG_IRQMASK_THROUGHPUT;
np->msi_flags &= ~NV_MSI_X_CAPABLE;
} else {
optimization_mode = NV_OPTIMIZATION_MODE_THROUGHPUT;
np->irqmask = NVREG_IRQMASK_THROUGHPUT;
if (np->msi_flags & NV_MSI_X_CAPABLE)
np->msi_flags |= 0x0003;
}
if (id->driver_data & DEV_NEED_TIMERIRQ)
np->irqmask |= NVREG_IRQ_TIMER;
if (id->driver_data & DEV_NEED_LINKTIMER) {
np->need_linktimer = 1;
np->link_timeout = jiffies + LINK_TIMEOUT;
} else {
np->need_linktimer = 0;
}
if (id->driver_data & DEV_NEED_TX_LIMIT) {
np->tx_limit = 1;
if (((id->driver_data & DEV_NEED_TX_LIMIT2) == DEV_NEED_TX_LIMIT2) &&
pci_dev->revision >= 0xA2)
np->tx_limit = 0;
}
writel(0, base + NvRegMIIMask);
phystate = readl(base + NvRegAdapterControl);
if (phystate & NVREG_ADAPTCTL_RUNNING) {
phystate_orig = 1;
phystate &= ~NVREG_ADAPTCTL_RUNNING;
writel(phystate, base + NvRegAdapterControl);
}
writel(NVREG_MIISTAT_MASK_ALL, base + NvRegMIIStatus);
if (id->driver_data & DEV_HAS_MGMT_UNIT) {
if ((readl(base + NvRegTransmitterControl) & NVREG_XMITCTL_MGMT_ST) &&
(readl(base + NvRegTransmitterControl) & NVREG_XMITCTL_SYNC_PHY_INIT) &&
nv_mgmt_acquire_sema(dev) &&
nv_mgmt_get_version(dev)) {
np->mac_in_use = 1;
if (np->mgmt_version > 0)
np->mac_in_use = readl(base + NvRegMgmtUnitControl) & NVREG_MGMTUNITCONTROL_INUSE;
if (np->mac_in_use &&
((readl(base + NvRegTransmitterControl) & NVREG_XMITCTL_SYNC_MASK) ==
NVREG_XMITCTL_SYNC_PHY_INIT)) {
phyinitialized = 1;
} else {
}
}
}
for (i = 1; i <= 32; i++) {
int id1, id2;
int phyaddr = i & 0x1F;
spin_lock_irq(&np->lock);
id1 = mii_rw(dev, phyaddr, MII_PHYSID1, MII_READ);
spin_unlock_irq(&np->lock);
if (id1 < 0 || id1 == 0xffff)
continue;
spin_lock_irq(&np->lock);
id2 = mii_rw(dev, phyaddr, MII_PHYSID2, MII_READ);
spin_unlock_irq(&np->lock);
if (id2 < 0 || id2 == 0xffff)
continue;
np->phy_model = id2 & PHYID2_MODEL_MASK;
id1 = (id1 & PHYID1_OUI_MASK) << PHYID1_OUI_SHFT;
id2 = (id2 & PHYID2_OUI_MASK) >> PHYID2_OUI_SHFT;
np->phyaddr = phyaddr;
np->phy_oui = id1 | id2;
if (np->phy_oui == PHY_OUI_REALTEK2)
np->phy_oui = PHY_OUI_REALTEK;
if (np->phy_oui == PHY_OUI_REALTEK && np->phy_model == PHY_MODEL_REALTEK_8211)
np->phy_rev = mii_rw(dev, phyaddr, MII_RESV1, MII_READ) & PHY_REV_MASK;
break;
}
if (i == 33) {
dev_info(&pci_dev->dev, "open: Could not find a valid PHY\n");
goto out_error;
}
if (!phyinitialized) {
phy_init(dev);
} else {
u32 mii_status = mii_rw(dev, np->phyaddr, MII_BMSR, MII_READ);
if (mii_status & PHY_GIGABIT)
np->gigabit = PHY_GIGABIT;
}
np->linkspeed = NVREG_LINKSPEED_FORCE|NVREG_LINKSPEED_10;
np->duplex = 0;
np->autoneg = 1;
err = register_netdev(dev);
if (err) {
dev_info(&pci_dev->dev, "unable to register netdev: %d\n", err);
goto out_error;
}
netif_carrier_off(dev);
nv_update_pause(dev, 0);
nv_start_tx(dev);
nv_stop_tx(dev);
if (id->driver_data & DEV_HAS_VLAN)
nv_vlan_mode(dev, dev->features);
dev_info(&pci_dev->dev, "ifname %s, PHY OUI 0x%x @ %d, addr %pM\n",
dev->name, np->phy_oui, np->phyaddr, dev->dev_addr);
dev_info(&pci_dev->dev, "%s%s%s%s%s%s%s%s%s%s%sdesc-v%u\n",
dev->features & NETIF_F_HIGHDMA ? "highdma " : "",
dev->features & (NETIF_F_IP_CSUM | NETIF_F_SG) ?
"csum " : "",
dev->features & (NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX) ?
"vlan " : "",
dev->features & (NETIF_F_LOOPBACK) ?
"loopback " : "",
id->driver_data & DEV_HAS_POWER_CNTRL ? "pwrctl " : "",
id->driver_data & DEV_HAS_MGMT_UNIT ? "mgmt " : "",
id->driver_data & DEV_NEED_TIMERIRQ ? "timirq " : "",
np->gigabit == PHY_GIGABIT ? "gbit " : "",
np->need_linktimer ? "lnktim " : "",
np->msi_flags & NV_MSI_CAPABLE ? "msi " : "",
np->msi_flags & NV_MSI_X_CAPABLE ? "msi-x " : "",
np->desc_ver);
return 0;
out_error:
if (phystate_orig)
writel(phystate|NVREG_ADAPTCTL_RUNNING, base + NvRegAdapterControl);
out_freering:
free_rings(dev);
out_unmap:
iounmap(get_hwbase(dev));
out_relreg:
pci_release_regions(pci_dev);
out_disable:
pci_disable_device(pci_dev);
out_free:
free_netdev(dev);
out:
return err;
}
static void nv_restore_phy(struct net_device *dev)
{
struct fe_priv *np = netdev_priv(dev);
u16 phy_reserved, mii_control;
if (np->phy_oui == PHY_OUI_REALTEK &&
np->phy_model == PHY_MODEL_REALTEK_8201 &&
phy_cross == NV_CROSSOVER_DETECTION_DISABLED) {
mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT3);
phy_reserved = mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG2, MII_READ);
phy_reserved &= ~PHY_REALTEK_INIT_MSK1;
phy_reserved |= PHY_REALTEK_INIT8;
mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG2, phy_reserved);
mii_rw(dev, np->phyaddr, PHY_REALTEK_INIT_REG1, PHY_REALTEK_INIT1);
mii_control = mii_rw(dev, np->phyaddr, MII_BMCR, MII_READ);
mii_control |= (BMCR_ANRESTART | BMCR_ANENABLE);
mii_rw(dev, np->phyaddr, MII_BMCR, mii_control);
}
}
static void nv_restore_mac_addr(struct pci_dev *pci_dev)
{
struct net_device *dev = pci_get_drvdata(pci_dev);
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
writel(np->orig_mac[0], base + NvRegMacAddrA);
writel(np->orig_mac[1], base + NvRegMacAddrB);
writel(readl(base + NvRegTransmitPoll) & ~NVREG_TRANSMITPOLL_MAC_ADDR_REV,
base + NvRegTransmitPoll);
}
static void nv_remove(struct pci_dev *pci_dev)
{
struct net_device *dev = pci_get_drvdata(pci_dev);
unregister_netdev(dev);
nv_restore_mac_addr(pci_dev);
nv_restore_phy(dev);
nv_mgmt_release_sema(dev);
free_rings(dev);
iounmap(get_hwbase(dev));
pci_release_regions(pci_dev);
pci_disable_device(pci_dev);
free_netdev(dev);
}
static int nv_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int i;
if (netif_running(dev)) {
nv_close(dev);
}
netif_device_detach(dev);
for (i = 0; i <= np->register_size/sizeof(u32); i++)
np->saved_config_space[i] = readl(base + i*sizeof(u32));
return 0;
}
static int nv_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct net_device *dev = pci_get_drvdata(pdev);
struct fe_priv *np = netdev_priv(dev);
u8 __iomem *base = get_hwbase(dev);
int i, rc = 0;
for (i = 0; i <= np->register_size/sizeof(u32); i++)
writel(np->saved_config_space[i], base+i*sizeof(u32));
if (np->driver_data & DEV_NEED_MSI_FIX)
pci_write_config_dword(pdev, NV_MSI_PRIV_OFFSET, NV_MSI_PRIV_VALUE);
phy_init(dev);
netif_device_attach(dev);
if (netif_running(dev)) {
rc = nv_open(dev);
nv_set_multicast(dev);
}
return rc;
}
static void nv_shutdown(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct fe_priv *np = netdev_priv(dev);
if (netif_running(dev))
nv_close(dev);
if (system_state != SYSTEM_POWER_OFF)
nv_restore_mac_addr(pdev);
pci_disable_device(pdev);
if (system_state == SYSTEM_POWER_OFF) {
pci_wake_from_d3(pdev, np->wolenabled);
pci_set_power_state(pdev, PCI_D3hot);
}
}
