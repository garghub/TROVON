static void dwmac4_core_init(struct mac_device_info *hw, int mtu)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = readl(ioaddr + GMAC_CONFIG);
value |= GMAC_CORE_INIT;
if (mtu > 1500)
value |= GMAC_CONFIG_2K;
if (mtu > 2000)
value |= GMAC_CONFIG_JE;
if (hw->ps) {
value |= GMAC_CONFIG_TE;
if (hw->ps == SPEED_1000) {
value &= ~GMAC_CONFIG_PS;
} else {
value |= GMAC_CONFIG_PS;
if (hw->ps == SPEED_10)
value &= ~GMAC_CONFIG_FES;
else
value |= GMAC_CONFIG_FES;
}
}
writel(value, ioaddr + GMAC_CONFIG);
value = GMAC_INT_DEFAULT_MASK;
if (hw->pmt)
value |= GMAC_INT_PMT_EN;
if (hw->pcs)
value |= GMAC_PCS_IRQ_DEFAULT;
writel(value, ioaddr + GMAC_INT_EN);
}
static void dwmac4_dump_regs(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
int i;
pr_debug("\tDWMAC4 regs (base addr = 0x%p)\n", ioaddr);
for (i = 0; i < GMAC_REG_NUM; i++) {
int offset = i * 4;
pr_debug("\tReg No. %d (offset 0x%x): 0x%08x\n", i,
offset, readl(ioaddr + offset));
}
}
static int dwmac4_rx_ipc_enable(struct mac_device_info *hw)
{
void __iomem *ioaddr = hw->pcsr;
u32 value = readl(ioaddr + GMAC_CONFIG);
if (hw->rx_csum)
value |= GMAC_CONFIG_IPC;
else
value &= ~GMAC_CONFIG_IPC;
writel(value, ioaddr + GMAC_CONFIG);
value = readl(ioaddr + GMAC_CONFIG);
return !!(value & GMAC_CONFIG_IPC);
}
static void dwmac4_pmt(struct mac_device_info *hw, unsigned long mode)
{
void __iomem *ioaddr = hw->pcsr;
unsigned int pmt = 0;
if (mode & WAKE_MAGIC) {
pr_debug("GMAC: WOL Magic frame\n");
pmt |= power_down | magic_pkt_en;
}
if (mode & WAKE_UCAST) {
pr_debug("GMAC: WOL on global unicast\n");
pmt |= power_down | global_unicast | wake_up_frame_en;
}
writel(pmt, ioaddr + GMAC_PMT);
}
static void dwmac4_set_umac_addr(struct mac_device_info *hw,
unsigned char *addr, unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_dwmac4_set_mac_addr(ioaddr, addr, GMAC_ADDR_HIGH(reg_n),
GMAC_ADDR_LOW(reg_n));
}
static void dwmac4_get_umac_addr(struct mac_device_info *hw,
unsigned char *addr, unsigned int reg_n)
{
void __iomem *ioaddr = hw->pcsr;
stmmac_dwmac4_get_mac_addr(ioaddr, addr, GMAC_ADDR_HIGH(reg_n),
GMAC_ADDR_LOW(reg_n));
}
static void dwmac4_set_filter(struct mac_device_info *hw,
struct net_device *dev)
{
void __iomem *ioaddr = (void __iomem *)dev->base_addr;
unsigned int value = 0;
if (dev->flags & IFF_PROMISC) {
value = GMAC_PACKET_FILTER_PR;
} else if ((dev->flags & IFF_ALLMULTI) ||
(netdev_mc_count(dev) > HASH_TABLE_SIZE)) {
value = GMAC_PACKET_FILTER_PM;
writel(0xffffffff, ioaddr + GMAC_HASH_TAB_0_31);
writel(0xffffffff, ioaddr + GMAC_HASH_TAB_32_63);
} else if (!netdev_mc_empty(dev)) {
u32 mc_filter[2];
struct netdev_hw_addr *ha;
value = GMAC_PACKET_FILTER_HMC;
memset(mc_filter, 0, sizeof(mc_filter));
netdev_for_each_mc_addr(ha, dev) {
int bit_nr =
(bitrev32(~crc32_le(~0, ha->addr, 6)) >> 26);
mc_filter[bit_nr >> 5] |= (1 << (bit_nr & 0x1F));
}
writel(mc_filter[0], ioaddr + GMAC_HASH_TAB_0_31);
writel(mc_filter[1], ioaddr + GMAC_HASH_TAB_32_63);
}
if (netdev_uc_count(dev) > GMAC_MAX_PERFECT_ADDRESSES) {
value |= GMAC_PACKET_FILTER_PR;
} else if (!netdev_uc_empty(dev)) {
int reg = 1;
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, dev) {
dwmac4_set_umac_addr(hw, ha->addr, reg);
reg++;
}
}
writel(value, ioaddr + GMAC_PACKET_FILTER);
}
static void dwmac4_flow_ctrl(struct mac_device_info *hw, unsigned int duplex,
unsigned int fc, unsigned int pause_time)
{
void __iomem *ioaddr = hw->pcsr;
u32 channel = STMMAC_CHAN0;
unsigned int flow = 0;
pr_debug("GMAC Flow-Control:\n");
if (fc & FLOW_RX) {
pr_debug("\tReceive Flow-Control ON\n");
flow |= GMAC_RX_FLOW_CTRL_RFE;
writel(flow, ioaddr + GMAC_RX_FLOW_CTRL);
}
if (fc & FLOW_TX) {
pr_debug("\tTransmit Flow-Control ON\n");
flow |= GMAC_TX_FLOW_CTRL_TFE;
writel(flow, ioaddr + GMAC_QX_TX_FLOW_CTRL(channel));
if (duplex) {
pr_debug("\tduplex mode: PAUSE %d\n", pause_time);
flow |= (pause_time << GMAC_TX_FLOW_CTRL_PT_SHIFT);
writel(flow, ioaddr + GMAC_QX_TX_FLOW_CTRL(channel));
}
}
}
static void dwmac4_ctrl_ane(void __iomem *ioaddr, bool ane, bool srgmi_ral,
bool loopback)
{
dwmac_ctrl_ane(ioaddr, GMAC_PCS_BASE, ane, srgmi_ral, loopback);
}
static void dwmac4_rane(void __iomem *ioaddr, bool restart)
{
dwmac_rane(ioaddr, GMAC_PCS_BASE, restart);
}
static void dwmac4_get_adv_lp(void __iomem *ioaddr, struct rgmii_adv *adv)
{
dwmac_get_adv_lp(ioaddr, GMAC_PCS_BASE, adv);
}
static void dwmac4_phystatus(void __iomem *ioaddr, struct stmmac_extra_stats *x)
{
u32 status;
status = readl(ioaddr + GMAC_PHYIF_CONTROL_STATUS);
x->irq_rgmii_n++;
if (status & GMAC_PHYIF_CTRLSTATUS_LNKSTS) {
int speed_value;
x->pcs_link = 1;
speed_value = ((status & GMAC_PHYIF_CTRLSTATUS_SPEED) >>
GMAC_PHYIF_CTRLSTATUS_SPEED_SHIFT);
if (speed_value == GMAC_PHYIF_CTRLSTATUS_SPEED_125)
x->pcs_speed = SPEED_1000;
else if (speed_value == GMAC_PHYIF_CTRLSTATUS_SPEED_25)
x->pcs_speed = SPEED_100;
else
x->pcs_speed = SPEED_10;
x->pcs_duplex = (status & GMAC_PHYIF_CTRLSTATUS_LNKMOD_MASK);
pr_info("Link is Up - %d/%s\n", (int)x->pcs_speed,
x->pcs_duplex ? "Full" : "Half");
} else {
x->pcs_link = 0;
pr_info("Link is Down\n");
}
}
static int dwmac4_irq_status(struct mac_device_info *hw,
struct stmmac_extra_stats *x)
{
void __iomem *ioaddr = hw->pcsr;
u32 mtl_int_qx_status;
u32 intr_status;
int ret = 0;
intr_status = readl(ioaddr + GMAC_INT_STATUS);
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
mtl_int_qx_status = readl(ioaddr + MTL_INT_STATUS);
if (mtl_int_qx_status & MTL_INT_Q0) {
u32 status = readl(ioaddr + MTL_CHAN_INT_CTRL(STMMAC_CHAN0));
if (status & MTL_RX_OVERFLOW_INT) {
writel(status | MTL_RX_OVERFLOW_INT,
ioaddr + MTL_CHAN_INT_CTRL(STMMAC_CHAN0));
ret = CORE_IRQ_MTL_RX_OVERFLOW;
}
}
dwmac_pcs_isr(ioaddr, GMAC_PCS_BASE, intr_status, x);
if (intr_status & PCS_RGSMIIIS_IRQ)
dwmac4_phystatus(ioaddr, x);
return ret;
}
static void dwmac4_debug(void __iomem *ioaddr, struct stmmac_extra_stats *x)
{
u32 value;
value = readl(ioaddr + MTL_CHAN_TX_DEBUG(STMMAC_CHAN0));
if (value & MTL_DEBUG_TXSTSFSTS)
x->mtl_tx_status_fifo_full++;
if (value & MTL_DEBUG_TXFSTS)
x->mtl_tx_fifo_not_empty++;
if (value & MTL_DEBUG_TWCSTS)
x->mmtl_fifo_ctrl++;
if (value & MTL_DEBUG_TRCSTS_MASK) {
u32 trcsts = (value & MTL_DEBUG_TRCSTS_MASK)
>> MTL_DEBUG_TRCSTS_SHIFT;
if (trcsts == MTL_DEBUG_TRCSTS_WRITE)
x->mtl_tx_fifo_read_ctrl_write++;
else if (trcsts == MTL_DEBUG_TRCSTS_TXW)
x->mtl_tx_fifo_read_ctrl_wait++;
else if (trcsts == MTL_DEBUG_TRCSTS_READ)
x->mtl_tx_fifo_read_ctrl_read++;
else
x->mtl_tx_fifo_read_ctrl_idle++;
}
if (value & MTL_DEBUG_TXPAUSED)
x->mac_tx_in_pause++;
value = readl(ioaddr + MTL_CHAN_RX_DEBUG(STMMAC_CHAN0));
if (value & MTL_DEBUG_RXFSTS_MASK) {
u32 rxfsts = (value & MTL_DEBUG_RXFSTS_MASK)
>> MTL_DEBUG_RRCSTS_SHIFT;
if (rxfsts == MTL_DEBUG_RXFSTS_FULL)
x->mtl_rx_fifo_fill_level_full++;
else if (rxfsts == MTL_DEBUG_RXFSTS_AT)
x->mtl_rx_fifo_fill_above_thresh++;
else if (rxfsts == MTL_DEBUG_RXFSTS_BT)
x->mtl_rx_fifo_fill_below_thresh++;
else
x->mtl_rx_fifo_fill_level_empty++;
}
if (value & MTL_DEBUG_RRCSTS_MASK) {
u32 rrcsts = (value & MTL_DEBUG_RRCSTS_MASK) >>
MTL_DEBUG_RRCSTS_SHIFT;
if (rrcsts == MTL_DEBUG_RRCSTS_FLUSH)
x->mtl_rx_fifo_read_ctrl_flush++;
else if (rrcsts == MTL_DEBUG_RRCSTS_RSTAT)
x->mtl_rx_fifo_read_ctrl_read_data++;
else if (rrcsts == MTL_DEBUG_RRCSTS_RDATA)
x->mtl_rx_fifo_read_ctrl_status++;
else
x->mtl_rx_fifo_read_ctrl_idle++;
}
if (value & MTL_DEBUG_RWCSTS)
x->mtl_rx_fifo_ctrl_active++;
value = readl(ioaddr + GMAC_DEBUG);
if (value & GMAC_DEBUG_TFCSTS_MASK) {
u32 tfcsts = (value & GMAC_DEBUG_TFCSTS_MASK)
>> GMAC_DEBUG_TFCSTS_SHIFT;
if (tfcsts == GMAC_DEBUG_TFCSTS_XFER)
x->mac_tx_frame_ctrl_xfer++;
else if (tfcsts == GMAC_DEBUG_TFCSTS_GEN_PAUSE)
x->mac_tx_frame_ctrl_pause++;
else if (tfcsts == GMAC_DEBUG_TFCSTS_WAIT)
x->mac_tx_frame_ctrl_wait++;
else
x->mac_tx_frame_ctrl_idle++;
}
if (value & GMAC_DEBUG_TPESTS)
x->mac_gmii_tx_proto_engine++;
if (value & GMAC_DEBUG_RFCFCSTS_MASK)
x->mac_rx_frame_ctrl_fifo = (value & GMAC_DEBUG_RFCFCSTS_MASK)
>> GMAC_DEBUG_RFCFCSTS_SHIFT;
if (value & GMAC_DEBUG_RPESTS)
x->mac_gmii_rx_proto_engine++;
}
struct mac_device_info *dwmac4_setup(void __iomem *ioaddr, int mcbins,
int perfect_uc_entries, int *synopsys_id)
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
mac->mac = &dwmac4_ops;
mac->link.port = GMAC_CONFIG_PS;
mac->link.duplex = GMAC_CONFIG_DM;
mac->link.speed = GMAC_CONFIG_FES;
mac->mii.addr = GMAC_MDIO_ADDR;
mac->mii.data = GMAC_MDIO_DATA;
mac->mii.addr_shift = 21;
mac->mii.addr_mask = GENMASK(25, 21);
mac->mii.reg_shift = 16;
mac->mii.reg_mask = GENMASK(20, 16);
mac->mii.clk_csr_shift = 8;
mac->mii.clk_csr_mask = GENMASK(11, 8);
*synopsys_id = stmmac_get_synopsys_id(hwid);
if (*synopsys_id > DWMAC_CORE_4_00)
mac->dma = &dwmac410_dma_ops;
else
mac->dma = &dwmac4_dma_ops;
return mac;
}
