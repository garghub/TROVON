static void dwmac1000_core_init(struct mac_device_info *hw, int mtu)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = readl(ioaddr + GMAC_CONTROL);
value |= GMAC_CORE_INIT;
if (mtu > 1500)
value |= GMAC_CONTROL_2K;
if (mtu > 2000)
value |= GMAC_CONTROL_JE;
writel(value, ioaddr + GMAC_CONTROL);
writel(0x207, ioaddr + GMAC_INT_MASK);
#ifdef STMMAC_VLAN_TAG_USED
writel(0x0, ioaddr + GMAC_VLAN_TAG);
#endif
}
static int dwmac1000_rx_ipc_enable(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = readl(ioaddr + GMAC_CONTROL);
if (hw->rx_csum)
value |= GMAC_CONTROL_IPC;
else
value &= ~GMAC_CONTROL_IPC;
writel(value, ioaddr + GMAC_CONTROL);
value = readl(ioaddr + GMAC_CONTROL);
return !!(value & GMAC_CONTROL_IPC);
}
static void dwmac1000_dump_regs(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
int i;
pr_info("\tDWMAC1000 regs (base addr = 0x%p)\n", ioaddr);
for (i = 0; i < 55; i++) {
int offset = i * 4;
pr_info("\tReg No. %d (offset 0x%x): 0x%08x\n", i,
offset, readl(ioaddr + offset));
}
}
static void dwmac1000_set_umac_addr(struct mac_device_info *hw,
unsigned char *addr,
unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_set_mac_addr(ioaddr, addr, GMAC_ADDR_HIGH(reg_n),
GMAC_ADDR_LOW(reg_n));
}
static void dwmac1000_get_umac_addr(struct mac_device_info *hw,
unsigned char *addr,
unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_get_mac_addr(ioaddr, addr, GMAC_ADDR_HIGH(reg_n),
GMAC_ADDR_LOW(reg_n));
}
static void dwmac1000_set_mchash(void __iomem *ioaddr, u32 *mcfilterbits,
int mcbitslog2)
{
int numhashregs, regs;
switch (mcbitslog2) {
case 6:
writel(mcfilterbits[0], ioaddr + GMAC_HASH_LOW);
writel(mcfilterbits[1], ioaddr + GMAC_HASH_HIGH);
return;
break;
case 7:
numhashregs = 4;
break;
case 8:
numhashregs = 8;
break;
default:
pr_debug("STMMAC: err in setting mulitcast filter\n");
return;
break;
}
for (regs = 0; regs < numhashregs; regs++)
writel(mcfilterbits[regs],
ioaddr + GMAC_EXTHASH_BASE + regs * 4);
}
static void dwmac1000_set_filter(struct mac_device_info *hw,
struct net_device *dev)
{
void __iomem *ioaddr = (void __iomem *)dev->base_addr;
unsigned int value = 0;
unsigned int perfect_addr_number = hw->unicast_filter_entries;
u32 mc_filter[8];
int mcbitslog2 = hw->mcast_bits_log2;
pr_debug("%s: # mcasts %d, # unicast %d\n", __func__,
netdev_mc_count(dev), netdev_uc_count(dev));
memset(mc_filter, 0, sizeof(mc_filter));
if (dev->flags & IFF_PROMISC) {
value = GMAC_FRAME_FILTER_PR;
} else if (dev->flags & IFF_ALLMULTI) {
value = GMAC_FRAME_FILTER_PM;
} else if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
value = GMAC_FRAME_FILTER_HMC;
netdev_for_each_mc_addr(ha, dev) {
int bit_nr = bitrev32(~crc32_le(~0, ha->addr,
ETH_ALEN)) >>
(32 - mcbitslog2);
mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);
}
}
dwmac1000_set_mchash(ioaddr, mc_filter, mcbitslog2);
if (netdev_uc_count(dev) > perfect_addr_number)
value |= GMAC_FRAME_FILTER_PR;
else {
int reg = 1;
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, dev) {
stmmac_set_mac_addr(ioaddr, ha->addr,
GMAC_ADDR_HIGH(reg),
GMAC_ADDR_LOW(reg));
reg++;
}
}
#ifdef FRAME_FILTER_DEBUG
value |= GMAC_FRAME_FILTER_RA;
#endif
writel(value, ioaddr + GMAC_FRAME_FILTER);
}
static void dwmac1000_flow_ctrl(struct mac_device_info *hw, unsigned int duplex,
unsigned int fc, unsigned int pause_time)
{
void __iomem *ioaddr = hw->pcsr;
unsigned int flow = 0;
pr_debug("GMAC Flow-Control:\n");
if (fc & FLOW_RX) {
pr_debug("\tReceive Flow-Control ON\n");
flow |= GMAC_FLOW_CTRL_RFE;
}
if (fc & FLOW_TX) {
pr_debug("\tTransmit Flow-Control ON\n");
flow |= GMAC_FLOW_CTRL_TFE;
}
if (duplex) {
pr_debug("\tduplex mode: PAUSE %d\n", pause_time);
flow |= (pause_time << GMAC_FLOW_CTRL_PT_SHIFT);
}
writel(flow, ioaddr + GMAC_FLOW_CTRL);
}
static void dwmac1000_pmt(struct mac_device_info *hw, unsigned long mode)
{
void __iomem *ioaddr = hw->pcsr;
unsigned int pmt = 0;
if (mode & WAKE_MAGIC) {
pr_debug("GMAC: WOL Magic frame\n");
pmt |= power_down | magic_pkt_en;
}
if (mode & WAKE_UCAST) {
pr_debug("GMAC: WOL on global unicast\n");
pmt |= global_unicast;
}
writel(pmt, ioaddr + GMAC_PMT);
}
static int dwmac1000_irq_status(struct mac_device_info *hw,
struct stmmac_extra_stats *x)
{
void __iomem *ioaddr = hw->pcsr;
u32 intr_status = readl(ioaddr + GMAC_INT_STATUS);
int ret = 0;
if ((intr_status & mmc_tx_irq))
x->mmc_tx_irq_n++;
if (unlikely(intr_status & mmc_rx_irq))
x->mmc_rx_irq_n++;
if (unlikely(intr_status & mmc_rx_csum_offload_irq))
x->mmc_rx_csum_offload_irq_n++;
if (unlikely(intr_status & pmt_irq)) {
readl(ioaddr + GMAC_PMT);
x->irq_receive_pmt_irq_n++;
}
if (intr_status & lpiis_irq) {
ret = readl(ioaddr + LPI_CTRL_STATUS);
if (ret & LPI_CTRL_STATUS_TLPIEN)
x->irq_tx_path_in_lpi_mode_n++;
if (ret & LPI_CTRL_STATUS_TLPIEX)
x->irq_tx_path_exit_lpi_mode_n++;
if (ret & LPI_CTRL_STATUS_RLPIEN)
x->irq_rx_path_in_lpi_mode_n++;
if (ret & LPI_CTRL_STATUS_RLPIEX)
x->irq_rx_path_exit_lpi_mode_n++;
}
if ((intr_status & pcs_ane_irq) || (intr_status & pcs_link_irq)) {
readl(ioaddr + GMAC_AN_STATUS);
x->irq_pcs_ane_n++;
}
if (intr_status & rgmii_irq) {
u32 status = readl(ioaddr + GMAC_S_R_GMII);
x->irq_rgmii_n++;
if (status & GMAC_S_R_GMII_LINK) {
int speed_value = (status & GMAC_S_R_GMII_SPEED) >>
GMAC_S_R_GMII_SPEED_SHIFT;
x->pcs_duplex = (status & GMAC_S_R_GMII_MODE);
if (speed_value == GMAC_S_R_GMII_SPEED_125)
x->pcs_speed = SPEED_1000;
else if (speed_value == GMAC_S_R_GMII_SPEED_25)
x->pcs_speed = SPEED_100;
else
x->pcs_speed = SPEED_10;
x->pcs_link = 1;
pr_debug("%s: Link is Up - %d/%s\n", __func__,
(int)x->pcs_speed,
x->pcs_duplex ? "Full" : "Half");
} else {
x->pcs_link = 0;
pr_debug("%s: Link is Down\n", __func__);
}
}
return ret;
}
static void dwmac1000_set_eee_mode(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
u32 value;
value = readl(ioaddr + LPI_CTRL_STATUS);
value |= LPI_CTRL_STATUS_LPIEN | LPI_CTRL_STATUS_LPITXA;
writel(value, ioaddr + LPI_CTRL_STATUS);
}
static void dwmac1000_reset_eee_mode(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
u32 value;
value = readl(ioaddr + LPI_CTRL_STATUS);
value &= ~(LPI_CTRL_STATUS_LPIEN | LPI_CTRL_STATUS_LPITXA);
writel(value, ioaddr + LPI_CTRL_STATUS);
}
static void dwmac1000_set_eee_pls(struct mac_device_info *hw, int link)
{
void __iomem *ioaddr = hw->pcsr;
u32 value;
value = readl(ioaddr + LPI_CTRL_STATUS);
if (link)
value |= LPI_CTRL_STATUS_PLS;
else
value &= ~LPI_CTRL_STATUS_PLS;
writel(value, ioaddr + LPI_CTRL_STATUS);
}
static void dwmac1000_set_eee_timer(struct mac_device_info *hw, int ls, int tw)
{
void __iomem *ioaddr = hw->pcsr;
int value = ((tw & 0xffff)) | ((ls & 0x7ff) << 16);
writel(value, ioaddr + LPI_TIMER_CTRL);
}
static void dwmac1000_ctrl_ane(struct mac_device_info *hw, bool restart)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = GMAC_AN_CTRL_ANE | GMAC_AN_CTRL_ELE;
if (restart)
value |= GMAC_AN_CTRL_RAN;
writel(value, ioaddr + GMAC_AN_CTRL);
}
static void dwmac1000_get_adv(struct mac_device_info *hw, struct rgmii_adv *adv)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = readl(ioaddr + GMAC_ANE_ADV);
if (value & GMAC_ANE_FD)
adv->duplex = DUPLEX_FULL;
if (value & GMAC_ANE_HD)
adv->duplex |= DUPLEX_HALF;
adv->pause = (value & GMAC_ANE_PSE) >> GMAC_ANE_PSE_SHIFT;
value = readl(ioaddr + GMAC_ANE_LPA);
if (value & GMAC_ANE_FD)
adv->lp_duplex = DUPLEX_FULL;
if (value & GMAC_ANE_HD)
adv->lp_duplex = DUPLEX_HALF;
adv->lp_pause = (value & GMAC_ANE_PSE) >> GMAC_ANE_PSE_SHIFT;
}
struct mac_device_info *dwmac1000_setup(void __iomem *ioaddr, int mcbins,
int perfect_uc_entries)
{
struct mac_device_info *mac;
u32 hwid = readl(ioaddr + GMAC_VERSION);
mac = kzalloc(sizeof(const struct mac_device_info), GFP_KERNEL);
if (!mac)
return NULL;
mac->pcsr = ioaddr;
mac->multicast_filter_bins = mcbins;
mac->unicast_filter_entries = perfect_uc_entries;
mac->mcast_bits_log2 = 0;
if (mac->multicast_filter_bins)
mac->mcast_bits_log2 = ilog2(mac->multicast_filter_bins);
mac->mac = &dwmac1000_ops;
mac->dma = &dwmac1000_dma_ops;
mac->link.port = GMAC_CONTROL_PS;
mac->link.duplex = GMAC_CONTROL_DM;
mac->link.speed = GMAC_CONTROL_FES;
mac->mii.addr = GMAC_MII_ADDR;
mac->mii.data = GMAC_MII_DATA;
mac->synopsys_uid = hwid;
return mac;
}
