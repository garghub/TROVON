static int eeprom_wait_ready(struct pci_dev *pdev, u32 *status)
{
u32 reg;
int i;
for (i = 0; i < MAX_NUM_REGISTER_POLLS; i++) {
if (pci_read_config_dword(pdev, LBCIF_DWORD1_GROUP, &reg))
return -EIO;
if ((reg & 0x3000) == 0x3000) {
if (status)
*status = reg;
return reg & 0xFF;
}
}
return -ETIMEDOUT;
}
static int eeprom_write(struct et131x_adapter *adapter, u32 addr, u8 data)
{
struct pci_dev *pdev = adapter->pdev;
int index = 0;
int retries;
int err = 0;
int writeok = 0;
u32 status;
u32 val = 0;
err = eeprom_wait_ready(pdev, NULL);
if (err < 0)
return err;
if (pci_write_config_byte(pdev, LBCIF_CONTROL_REGISTER,
LBCIF_CONTROL_LBCIF_ENABLE |
LBCIF_CONTROL_I2C_WRITE))
return -EIO;
for (retries = 0; retries < MAX_NUM_WRITE_RETRIES; retries++) {
if (pci_write_config_dword(pdev, LBCIF_ADDRESS_REGISTER, addr))
break;
if (pci_write_config_byte(pdev, LBCIF_DATA_REGISTER, data))
break;
err = eeprom_wait_ready(pdev, &status);
if (err < 0)
return 0;
if ((status & LBCIF_STATUS_GENERAL_ERROR) &&
adapter->pdev->revision == 0)
break;
if (status & LBCIF_STATUS_ACK_ERROR) {
udelay(10);
continue;
}
writeok = 1;
break;
}
udelay(10);
while (1) {
if (pci_write_config_byte(pdev, LBCIF_CONTROL_REGISTER,
LBCIF_CONTROL_LBCIF_ENABLE))
writeok = 0;
do {
pci_write_config_dword(pdev,
LBCIF_ADDRESS_REGISTER,
addr);
do {
pci_read_config_dword(pdev,
LBCIF_DATA_REGISTER,
&val);
} while ((val & 0x00010000) == 0);
} while (val & 0x00040000);
if ((val & 0xFF00) != 0xC000 || index == 10000)
break;
index++;
}
return writeok ? 0 : -EIO;
}
static int eeprom_read(struct et131x_adapter *adapter, u32 addr, u8 *pdata)
{
struct pci_dev *pdev = adapter->pdev;
int err;
u32 status;
err = eeprom_wait_ready(pdev, NULL);
if (err < 0)
return err;
if (pci_write_config_byte(pdev, LBCIF_CONTROL_REGISTER,
LBCIF_CONTROL_LBCIF_ENABLE))
return -EIO;
if (pci_write_config_dword(pdev, LBCIF_ADDRESS_REGISTER, addr))
return -EIO;
err = eeprom_wait_ready(pdev, &status);
if (err < 0)
return err;
*pdata = err;
return (status & LBCIF_STATUS_ACK_ERROR) ? -EIO : 0;
}
static int et131x_init_eeprom(struct et131x_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
u8 eestatus;
pci_read_config_byte(pdev, ET1310_PCI_EEPROM_STATUS, &eestatus);
if (pci_read_config_byte(pdev, ET1310_PCI_EEPROM_STATUS, &eestatus)) {
dev_err(&pdev->dev,
"Could not read PCI config space for EEPROM Status\n");
return -EIO;
}
if (eestatus & 0x4C) {
int write_failed = 0;
if (pdev->revision == 0x01) {
int i;
static const u8 eedata[4] = { 0xFE, 0x13, 0x10, 0xFF };
for (i = 0; i < 3; i++)
if (eeprom_write(adapter, i, eedata[i]) < 0)
write_failed = 1;
}
if (pdev->revision != 0x01 || write_failed) {
dev_err(&pdev->dev,
"Fatal EEPROM Status Error - 0x%04x\n",
eestatus);
adapter->has_eeprom = 0;
return -EIO;
}
}
adapter->has_eeprom = 1;
eeprom_read(adapter, 0x70, &adapter->eeprom_data[0]);
eeprom_read(adapter, 0x71, &adapter->eeprom_data[1]);
if (adapter->eeprom_data[0] != 0xcd)
adapter->eeprom_data[1] = 0x00;
return 0;
}
static void et131x_rx_dma_enable(struct et131x_adapter *adapter)
{
u32 csr = ET_RXDMA_CSR_FBR1_ENABLE;
struct rx_ring *rx_ring = &adapter->rx_ring;
if (rx_ring->fbr[1]->buffsize == 4096)
csr |= ET_RXDMA_CSR_FBR1_SIZE_LO;
else if (rx_ring->fbr[1]->buffsize == 8192)
csr |= ET_RXDMA_CSR_FBR1_SIZE_HI;
else if (rx_ring->fbr[1]->buffsize == 16384)
csr |= ET_RXDMA_CSR_FBR1_SIZE_LO | ET_RXDMA_CSR_FBR1_SIZE_HI;
csr |= ET_RXDMA_CSR_FBR0_ENABLE;
if (rx_ring->fbr[0]->buffsize == 256)
csr |= ET_RXDMA_CSR_FBR0_SIZE_LO;
else if (rx_ring->fbr[0]->buffsize == 512)
csr |= ET_RXDMA_CSR_FBR0_SIZE_HI;
else if (rx_ring->fbr[0]->buffsize == 1024)
csr |= ET_RXDMA_CSR_FBR0_SIZE_LO | ET_RXDMA_CSR_FBR0_SIZE_HI;
writel(csr, &adapter->regs->rxdma.csr);
csr = readl(&adapter->regs->rxdma.csr);
if (csr & ET_RXDMA_CSR_HALT_STATUS) {
udelay(5);
csr = readl(&adapter->regs->rxdma.csr);
if (csr & ET_RXDMA_CSR_HALT_STATUS) {
dev_err(&adapter->pdev->dev,
"RX Dma failed to exit halt state. CSR 0x%08x\n",
csr);
}
}
}
static void et131x_rx_dma_disable(struct et131x_adapter *adapter)
{
u32 csr;
writel(ET_RXDMA_CSR_HALT | ET_RXDMA_CSR_FBR1_ENABLE,
&adapter->regs->rxdma.csr);
csr = readl(&adapter->regs->rxdma.csr);
if (!(csr & ET_RXDMA_CSR_HALT_STATUS)) {
udelay(5);
csr = readl(&adapter->regs->rxdma.csr);
if (!(csr & ET_RXDMA_CSR_HALT_STATUS))
dev_err(&adapter->pdev->dev,
"RX Dma failed to enter halt state. CSR 0x%08x\n",
csr);
}
}
static void et131x_tx_dma_enable(struct et131x_adapter *adapter)
{
writel(ET_TXDMA_SNGL_EPKT | (PARM_DMA_CACHE_DEF << ET_TXDMA_CACHE_SHIFT),
&adapter->regs->txdma.csr);
}
static inline void add_10bit(u32 *v, int n)
{
*v = INDEX10(*v + n) | (*v & ET_DMA10_WRAP);
}
static inline void add_12bit(u32 *v, int n)
{
*v = INDEX12(*v + n) | (*v & ET_DMA12_WRAP);
}
static void et1310_config_mac_regs1(struct et131x_adapter *adapter)
{
struct mac_regs __iomem *macregs = &adapter->regs->mac;
u32 station1;
u32 station2;
u32 ipg;
writel(ET_MAC_CFG1_SOFT_RESET | ET_MAC_CFG1_SIM_RESET |
ET_MAC_CFG1_RESET_RXMC | ET_MAC_CFG1_RESET_TXMC |
ET_MAC_CFG1_RESET_RXFUNC | ET_MAC_CFG1_RESET_TXFUNC,
&macregs->cfg1);
ipg = 0x38005860;
ipg |= 0x50 << 8;
writel(ipg, &macregs->ipg);
writel(0x00A1F037, &macregs->hfdp);
writel(0, &macregs->if_ctrl);
writel(ET_MAC_MIIMGMT_CLK_RST, &macregs->mii_mgmt_cfg);
station2 = (adapter->addr[1] << ET_MAC_STATION_ADDR2_OC2_SHIFT) |
(adapter->addr[0] << ET_MAC_STATION_ADDR2_OC1_SHIFT);
station1 = (adapter->addr[5] << ET_MAC_STATION_ADDR1_OC6_SHIFT) |
(adapter->addr[4] << ET_MAC_STATION_ADDR1_OC5_SHIFT) |
(adapter->addr[3] << ET_MAC_STATION_ADDR1_OC4_SHIFT) |
adapter->addr[2];
writel(station1, &macregs->station_addr_1);
writel(station2, &macregs->station_addr_2);
writel(adapter->registry_jumbo_packet + 4, &macregs->max_fm_len);
writel(0, &macregs->cfg1);
}
static void et1310_config_mac_regs2(struct et131x_adapter *adapter)
{
int32_t delay = 0;
struct mac_regs __iomem *mac = &adapter->regs->mac;
struct phy_device *phydev = adapter->netdev->phydev;
u32 cfg1;
u32 cfg2;
u32 ifctrl;
u32 ctl;
ctl = readl(&adapter->regs->txmac.ctl);
cfg1 = readl(&mac->cfg1);
cfg2 = readl(&mac->cfg2);
ifctrl = readl(&mac->if_ctrl);
cfg2 &= ~ET_MAC_CFG2_IFMODE_MASK;
if (phydev->speed == SPEED_1000) {
cfg2 |= ET_MAC_CFG2_IFMODE_1000;
ifctrl &= ~ET_MAC_IFCTRL_PHYMODE;
} else {
cfg2 |= ET_MAC_CFG2_IFMODE_100;
ifctrl |= ET_MAC_IFCTRL_PHYMODE;
}
cfg1 |= ET_MAC_CFG1_RX_ENABLE | ET_MAC_CFG1_TX_ENABLE |
ET_MAC_CFG1_TX_FLOW;
cfg1 &= ~(ET_MAC_CFG1_LOOPBACK | ET_MAC_CFG1_RX_FLOW);
if (adapter->flow == FLOW_RXONLY || adapter->flow == FLOW_BOTH)
cfg1 |= ET_MAC_CFG1_RX_FLOW;
writel(cfg1, &mac->cfg1);
cfg2 |= 0x7 << ET_MAC_CFG2_PREAMBLE_SHIFT;
cfg2 |= ET_MAC_CFG2_IFMODE_LEN_CHECK;
cfg2 |= ET_MAC_CFG2_IFMODE_PAD_CRC;
cfg2 |= ET_MAC_CFG2_IFMODE_CRC_ENABLE;
cfg2 &= ~ET_MAC_CFG2_IFMODE_HUGE_FRAME;
cfg2 &= ~ET_MAC_CFG2_IFMODE_FULL_DPLX;
if (phydev->duplex == DUPLEX_FULL)
cfg2 |= ET_MAC_CFG2_IFMODE_FULL_DPLX;
ifctrl &= ~ET_MAC_IFCTRL_GHDMODE;
if (phydev->duplex == DUPLEX_HALF)
ifctrl |= ET_MAC_IFCTRL_GHDMODE;
writel(ifctrl, &mac->if_ctrl);
writel(cfg2, &mac->cfg2);
do {
udelay(10);
delay++;
cfg1 = readl(&mac->cfg1);
} while ((cfg1 & ET_MAC_CFG1_WAIT) != ET_MAC_CFG1_WAIT && delay < 100);
if (delay == 100) {
dev_warn(&adapter->pdev->dev,
"Syncd bits did not respond correctly cfg1 word 0x%08x\n",
cfg1);
}
ctl |= ET_TX_CTRL_TXMAC_ENABLE | ET_TX_CTRL_FC_DISABLE;
writel(ctl, &adapter->regs->txmac.ctl);
if (adapter->flags & FMP_ADAPTER_LOWER_POWER) {
et131x_rx_dma_enable(adapter);
et131x_tx_dma_enable(adapter);
}
}
static int et1310_in_phy_coma(struct et131x_adapter *adapter)
{
u32 pmcsr = readl(&adapter->regs->global.pm_csr);
return ET_PM_PHY_SW_COMA & pmcsr ? 1 : 0;
}
static void et1310_setup_device_for_multicast(struct et131x_adapter *adapter)
{
struct rxmac_regs __iomem *rxmac = &adapter->regs->rxmac;
u32 hash1 = 0;
u32 hash2 = 0;
u32 hash3 = 0;
u32 hash4 = 0;
u32 pm_csr;
if (adapter->packet_filter & ET131X_PACKET_TYPE_MULTICAST) {
int i;
for (i = 0; i < adapter->multicast_addr_count; i++) {
u32 result;
result = ether_crc(6, adapter->multicast_list[i]);
result = (result & 0x3F800000) >> 23;
if (result < 32) {
hash1 |= (1 << result);
} else if ((31 < result) && (result < 64)) {
result -= 32;
hash2 |= (1 << result);
} else if ((63 < result) && (result < 96)) {
result -= 64;
hash3 |= (1 << result);
} else {
result -= 96;
hash4 |= (1 << result);
}
}
}
pm_csr = readl(&adapter->regs->global.pm_csr);
if (!et1310_in_phy_coma(adapter)) {
writel(hash1, &rxmac->multi_hash1);
writel(hash2, &rxmac->multi_hash2);
writel(hash3, &rxmac->multi_hash3);
writel(hash4, &rxmac->multi_hash4);
}
}
static void et1310_setup_device_for_unicast(struct et131x_adapter *adapter)
{
struct rxmac_regs __iomem *rxmac = &adapter->regs->rxmac;
u32 uni_pf1;
u32 uni_pf2;
u32 uni_pf3;
u32 pm_csr;
uni_pf3 = (adapter->addr[0] << ET_RX_UNI_PF_ADDR2_1_SHIFT) |
(adapter->addr[1] << ET_RX_UNI_PF_ADDR2_2_SHIFT) |
(adapter->addr[0] << ET_RX_UNI_PF_ADDR1_1_SHIFT) |
adapter->addr[1];
uni_pf2 = (adapter->addr[2] << ET_RX_UNI_PF_ADDR2_3_SHIFT) |
(adapter->addr[3] << ET_RX_UNI_PF_ADDR2_4_SHIFT) |
(adapter->addr[4] << ET_RX_UNI_PF_ADDR2_5_SHIFT) |
adapter->addr[5];
uni_pf1 = (adapter->addr[2] << ET_RX_UNI_PF_ADDR1_3_SHIFT) |
(adapter->addr[3] << ET_RX_UNI_PF_ADDR1_4_SHIFT) |
(adapter->addr[4] << ET_RX_UNI_PF_ADDR1_5_SHIFT) |
adapter->addr[5];
pm_csr = readl(&adapter->regs->global.pm_csr);
if (!et1310_in_phy_coma(adapter)) {
writel(uni_pf1, &rxmac->uni_pf_addr1);
writel(uni_pf2, &rxmac->uni_pf_addr2);
writel(uni_pf3, &rxmac->uni_pf_addr3);
}
}
static void et1310_config_rxmac_regs(struct et131x_adapter *adapter)
{
struct rxmac_regs __iomem *rxmac = &adapter->regs->rxmac;
struct phy_device *phydev = adapter->netdev->phydev;
u32 sa_lo;
u32 sa_hi = 0;
u32 pf_ctrl = 0;
u32 __iomem *wolw;
writel(0x8, &rxmac->ctrl);
writel(0, &rxmac->crc0);
writel(0, &rxmac->crc12);
writel(0, &rxmac->crc34);
for (wolw = &rxmac->mask0_word0; wolw <= &rxmac->mask4_word3; wolw++)
writel(0, wolw);
sa_lo = (adapter->addr[2] << ET_RX_WOL_LO_SA3_SHIFT) |
(adapter->addr[3] << ET_RX_WOL_LO_SA4_SHIFT) |
(adapter->addr[4] << ET_RX_WOL_LO_SA5_SHIFT) |
adapter->addr[5];
writel(sa_lo, &rxmac->sa_lo);
sa_hi = (u32)(adapter->addr[0] << ET_RX_WOL_HI_SA1_SHIFT) |
adapter->addr[1];
writel(sa_hi, &rxmac->sa_hi);
writel(0, &rxmac->pf_ctrl);
if (adapter->packet_filter & ET131X_PACKET_TYPE_DIRECTED) {
et1310_setup_device_for_unicast(adapter);
pf_ctrl |= ET_RX_PFCTRL_UNICST_FILTER_ENABLE;
} else {
writel(0, &rxmac->uni_pf_addr1);
writel(0, &rxmac->uni_pf_addr2);
writel(0, &rxmac->uni_pf_addr3);
}
if (!(adapter->packet_filter & ET131X_PACKET_TYPE_ALL_MULTICAST)) {
pf_ctrl |= ET_RX_PFCTRL_MLTCST_FILTER_ENABLE;
et1310_setup_device_for_multicast(adapter);
}
pf_ctrl |= (NIC_MIN_PACKET_SIZE + 4) << ET_RX_PFCTRL_MIN_PKT_SZ_SHIFT;
pf_ctrl |= ET_RX_PFCTRL_FRAG_FILTER_ENABLE;
if (adapter->registry_jumbo_packet > 8192)
writel(0x41, &rxmac->mcif_ctrl_max_seg);
else
writel(0, &rxmac->mcif_ctrl_max_seg);
writel(0, &rxmac->mcif_water_mark);
writel(0, &rxmac->mif_ctrl);
writel(0, &rxmac->space_avail);
if (phydev && phydev->speed == SPEED_100)
writel(0x30038, &rxmac->mif_ctrl);
else
writel(0x30030, &rxmac->mif_ctrl);
writel(pf_ctrl, &rxmac->pf_ctrl);
writel(ET_RX_CTRL_RXMAC_ENABLE | ET_RX_CTRL_WOL_DISABLE, &rxmac->ctrl);
}
static void et1310_config_txmac_regs(struct et131x_adapter *adapter)
{
struct txmac_regs __iomem *txmac = &adapter->regs->txmac;
if (adapter->flow == FLOW_NONE)
writel(0, &txmac->cf_param);
else
writel(0x40, &txmac->cf_param);
}
static void et1310_config_macstat_regs(struct et131x_adapter *adapter)
{
struct macstat_regs __iomem *macstat = &adapter->regs->macstat;
u32 __iomem *reg;
for (reg = &macstat->txrx_0_64_byte_frames;
reg <= &macstat->carry_reg2; reg++)
writel(0, reg);
writel(0xFFFFBE32, &macstat->carry_reg1_mask);
writel(0xFFFE7E8B, &macstat->carry_reg2_mask);
}
static int et131x_phy_mii_read(struct et131x_adapter *adapter, u8 addr,
u8 reg, u16 *value)
{
struct mac_regs __iomem *mac = &adapter->regs->mac;
int status = 0;
u32 delay = 0;
u32 mii_addr;
u32 mii_cmd;
u32 mii_indicator;
mii_addr = readl(&mac->mii_mgmt_addr);
mii_cmd = readl(&mac->mii_mgmt_cmd);
writel(0, &mac->mii_mgmt_cmd);
writel(ET_MAC_MII_ADDR(addr, reg), &mac->mii_mgmt_addr);
writel(0x1, &mac->mii_mgmt_cmd);
do {
udelay(50);
delay++;
mii_indicator = readl(&mac->mii_mgmt_indicator);
} while ((mii_indicator & ET_MAC_MGMT_WAIT) && delay < 50);
if (delay == 50) {
dev_warn(&adapter->pdev->dev,
"reg 0x%08x could not be read\n", reg);
dev_warn(&adapter->pdev->dev, "status is 0x%08x\n",
mii_indicator);
status = -EIO;
goto out;
}
*value = readl(&mac->mii_mgmt_stat) & ET_MAC_MIIMGMT_STAT_PHYCRTL_MASK;
out:
writel(0, &mac->mii_mgmt_cmd);
writel(mii_addr, &mac->mii_mgmt_addr);
writel(mii_cmd, &mac->mii_mgmt_cmd);
return status;
}
static int et131x_mii_read(struct et131x_adapter *adapter, u8 reg, u16 *value)
{
struct phy_device *phydev = adapter->netdev->phydev;
if (!phydev)
return -EIO;
return et131x_phy_mii_read(adapter, phydev->mdio.addr, reg, value);
}
static int et131x_mii_write(struct et131x_adapter *adapter, u8 addr, u8 reg,
u16 value)
{
struct mac_regs __iomem *mac = &adapter->regs->mac;
int status = 0;
u32 delay = 0;
u32 mii_addr;
u32 mii_cmd;
u32 mii_indicator;
mii_addr = readl(&mac->mii_mgmt_addr);
mii_cmd = readl(&mac->mii_mgmt_cmd);
writel(0, &mac->mii_mgmt_cmd);
writel(ET_MAC_MII_ADDR(addr, reg), &mac->mii_mgmt_addr);
writel(value, &mac->mii_mgmt_ctrl);
do {
udelay(50);
delay++;
mii_indicator = readl(&mac->mii_mgmt_indicator);
} while ((mii_indicator & ET_MAC_MGMT_BUSY) && delay < 100);
if (delay == 100) {
u16 tmp;
dev_warn(&adapter->pdev->dev,
"reg 0x%08x could not be written", reg);
dev_warn(&adapter->pdev->dev, "status is 0x%08x\n",
mii_indicator);
dev_warn(&adapter->pdev->dev, "command is 0x%08x\n",
readl(&mac->mii_mgmt_cmd));
et131x_mii_read(adapter, reg, &tmp);
status = -EIO;
}
writel(0, &mac->mii_mgmt_cmd);
writel(mii_addr, &mac->mii_mgmt_addr);
writel(mii_cmd, &mac->mii_mgmt_cmd);
return status;
}
static void et1310_phy_read_mii_bit(struct et131x_adapter *adapter,
u16 regnum,
u16 bitnum,
u8 *value)
{
u16 reg;
u16 mask = 1 << bitnum;
et131x_mii_read(adapter, regnum, &reg);
*value = (reg & mask) >> bitnum;
}
static void et1310_config_flow_control(struct et131x_adapter *adapter)
{
struct phy_device *phydev = adapter->netdev->phydev;
if (phydev->duplex == DUPLEX_HALF) {
adapter->flow = FLOW_NONE;
} else {
char remote_pause, remote_async_pause;
et1310_phy_read_mii_bit(adapter, 5, 10, &remote_pause);
et1310_phy_read_mii_bit(adapter, 5, 11, &remote_async_pause);
if (remote_pause && remote_async_pause) {
adapter->flow = adapter->wanted_flow;
} else if (remote_pause && !remote_async_pause) {
if (adapter->wanted_flow == FLOW_BOTH)
adapter->flow = FLOW_BOTH;
else
adapter->flow = FLOW_NONE;
} else if (!remote_pause && !remote_async_pause) {
adapter->flow = FLOW_NONE;
} else {
if (adapter->wanted_flow == FLOW_BOTH)
adapter->flow = FLOW_RXONLY;
else
adapter->flow = FLOW_NONE;
}
}
}
static void et1310_update_macstat_host_counters(struct et131x_adapter *adapter)
{
struct ce_stats *stats = &adapter->stats;
struct macstat_regs __iomem *macstat =
&adapter->regs->macstat;
stats->tx_collisions += readl(&macstat->tx_total_collisions);
stats->tx_first_collisions += readl(&macstat->tx_single_collisions);
stats->tx_deferred += readl(&macstat->tx_deferred);
stats->tx_excessive_collisions +=
readl(&macstat->tx_multiple_collisions);
stats->tx_late_collisions += readl(&macstat->tx_late_collisions);
stats->tx_underflows += readl(&macstat->tx_undersize_frames);
stats->tx_max_pkt_errs += readl(&macstat->tx_oversize_frames);
stats->rx_align_errs += readl(&macstat->rx_align_errs);
stats->rx_crc_errs += readl(&macstat->rx_code_errs);
stats->rcvd_pkts_dropped += readl(&macstat->rx_drops);
stats->rx_overflows += readl(&macstat->rx_oversize_packets);
stats->rx_code_violations += readl(&macstat->rx_fcs_errs);
stats->rx_length_errs += readl(&macstat->rx_frame_len_errs);
stats->rx_other_errs += readl(&macstat->rx_fragment_packets);
}
static void et1310_handle_macstat_interrupt(struct et131x_adapter *adapter)
{
u32 carry_reg1;
u32 carry_reg2;
carry_reg1 = readl(&adapter->regs->macstat.carry_reg1);
carry_reg2 = readl(&adapter->regs->macstat.carry_reg2);
writel(carry_reg1, &adapter->regs->macstat.carry_reg1);
writel(carry_reg2, &adapter->regs->macstat.carry_reg2);
if (carry_reg1 & (1 << 14))
adapter->stats.rx_code_violations += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 8))
adapter->stats.rx_align_errs += COUNTER_WRAP_12_BIT;
if (carry_reg1 & (1 << 7))
adapter->stats.rx_length_errs += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 2))
adapter->stats.rx_other_errs += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 6))
adapter->stats.rx_crc_errs += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 3))
adapter->stats.rx_overflows += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 0))
adapter->stats.rcvd_pkts_dropped += COUNTER_WRAP_16_BIT;
if (carry_reg2 & (1 << 16))
adapter->stats.tx_max_pkt_errs += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 15))
adapter->stats.tx_underflows += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 6))
adapter->stats.tx_first_collisions += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 8))
adapter->stats.tx_deferred += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 5))
adapter->stats.tx_excessive_collisions += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 4))
adapter->stats.tx_late_collisions += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 2))
adapter->stats.tx_collisions += COUNTER_WRAP_12_BIT;
}
static int et131x_mdio_read(struct mii_bus *bus, int phy_addr, int reg)
{
struct net_device *netdev = bus->priv;
struct et131x_adapter *adapter = netdev_priv(netdev);
u16 value;
int ret;
ret = et131x_phy_mii_read(adapter, phy_addr, reg, &value);
if (ret < 0)
return ret;
return value;
}
static int et131x_mdio_write(struct mii_bus *bus, int phy_addr,
int reg, u16 value)
{
struct net_device *netdev = bus->priv;
struct et131x_adapter *adapter = netdev_priv(netdev);
return et131x_mii_write(adapter, phy_addr, reg, value);
}
static void et1310_phy_power_switch(struct et131x_adapter *adapter, bool down)
{
u16 data;
struct phy_device *phydev = adapter->netdev->phydev;
et131x_mii_read(adapter, MII_BMCR, &data);
data &= ~BMCR_PDOWN;
if (down)
data |= BMCR_PDOWN;
et131x_mii_write(adapter, phydev->mdio.addr, MII_BMCR, data);
}
static void et131x_xcvr_init(struct et131x_adapter *adapter)
{
u16 lcr2;
struct phy_device *phydev = adapter->netdev->phydev;
if ((adapter->eeprom_data[1] & 0x4) == 0) {
et131x_mii_read(adapter, PHY_LED_2, &lcr2);
lcr2 &= (ET_LED2_LED_100TX | ET_LED2_LED_1000T);
lcr2 |= (LED_VAL_LINKON_ACTIVE << LED_LINK_SHIFT);
if ((adapter->eeprom_data[1] & 0x8) == 0)
lcr2 |= (LED_VAL_1000BT_100BTX << LED_TXRX_SHIFT);
else
lcr2 |= (LED_VAL_LINKON << LED_TXRX_SHIFT);
et131x_mii_write(adapter, phydev->mdio.addr, PHY_LED_2, lcr2);
}
}
static void et131x_configure_global_regs(struct et131x_adapter *adapter)
{
struct global_regs __iomem *regs = &adapter->regs->global;
writel(0, &regs->rxq_start_addr);
writel(INTERNAL_MEM_SIZE - 1, &regs->txq_end_addr);
if (adapter->registry_jumbo_packet < 2048) {
writel(PARM_RX_MEM_END_DEF, &regs->rxq_end_addr);
writel(PARM_RX_MEM_END_DEF + 1, &regs->txq_start_addr);
} else if (adapter->registry_jumbo_packet < 8192) {
writel(INTERNAL_MEM_RX_OFFSET, &regs->rxq_end_addr);
writel(INTERNAL_MEM_RX_OFFSET + 1, &regs->txq_start_addr);
} else {
writel(0x01b3, &regs->rxq_end_addr);
writel(0x01b4, &regs->txq_start_addr);
}
writel(0, &regs->loopback);
writel(0, &regs->msi_config);
writel(0, &regs->watchdog_timer);
}
static void et131x_config_rx_dma_regs(struct et131x_adapter *adapter)
{
struct rxdma_regs __iomem *rx_dma = &adapter->regs->rxdma;
struct rx_ring *rx_local = &adapter->rx_ring;
struct fbr_desc *fbr_entry;
u32 entry;
u32 psr_num_des;
unsigned long flags;
u8 id;
et131x_rx_dma_disable(adapter);
writel(upper_32_bits(rx_local->rx_status_bus), &rx_dma->dma_wb_base_hi);
writel(lower_32_bits(rx_local->rx_status_bus), &rx_dma->dma_wb_base_lo);
memset(rx_local->rx_status_block, 0, sizeof(struct rx_status_block));
writel(upper_32_bits(rx_local->ps_ring_physaddr), &rx_dma->psr_base_hi);
writel(lower_32_bits(rx_local->ps_ring_physaddr), &rx_dma->psr_base_lo);
writel(rx_local->psr_entries - 1, &rx_dma->psr_num_des);
writel(0, &rx_dma->psr_full_offset);
psr_num_des = readl(&rx_dma->psr_num_des) & ET_RXDMA_PSR_NUM_DES_MASK;
writel((psr_num_des * LO_MARK_PERCENT_FOR_PSR) / 100,
&rx_dma->psr_min_des);
spin_lock_irqsave(&adapter->rcv_lock, flags);
rx_local->local_psr_full = 0;
for (id = 0; id < NUM_FBRS; id++) {
u32 __iomem *num_des;
u32 __iomem *full_offset;
u32 __iomem *min_des;
u32 __iomem *base_hi;
u32 __iomem *base_lo;
struct fbr_lookup *fbr = rx_local->fbr[id];
if (id == 0) {
num_des = &rx_dma->fbr0_num_des;
full_offset = &rx_dma->fbr0_full_offset;
min_des = &rx_dma->fbr0_min_des;
base_hi = &rx_dma->fbr0_base_hi;
base_lo = &rx_dma->fbr0_base_lo;
} else {
num_des = &rx_dma->fbr1_num_des;
full_offset = &rx_dma->fbr1_full_offset;
min_des = &rx_dma->fbr1_min_des;
base_hi = &rx_dma->fbr1_base_hi;
base_lo = &rx_dma->fbr1_base_lo;
}
fbr_entry = fbr->ring_virtaddr;
for (entry = 0; entry < fbr->num_entries; entry++) {
fbr_entry->addr_hi = fbr->bus_high[entry];
fbr_entry->addr_lo = fbr->bus_low[entry];
fbr_entry->word2 = entry;
fbr_entry++;
}
writel(upper_32_bits(fbr->ring_physaddr), base_hi);
writel(lower_32_bits(fbr->ring_physaddr), base_lo);
writel(fbr->num_entries - 1, num_des);
writel(ET_DMA10_WRAP, full_offset);
fbr->local_full = ET_DMA10_WRAP;
writel(((fbr->num_entries * LO_MARK_PERCENT_FOR_RX) / 100) - 1,
min_des);
}
writel(PARM_RX_NUM_BUFS_DEF, &rx_dma->num_pkt_done);
writel(PARM_RX_TIME_INT_DEF, &rx_dma->max_pkt_time);
spin_unlock_irqrestore(&adapter->rcv_lock, flags);
}
static void et131x_config_tx_dma_regs(struct et131x_adapter *adapter)
{
struct txdma_regs __iomem *txdma = &adapter->regs->txdma;
struct tx_ring *tx_ring = &adapter->tx_ring;
writel(upper_32_bits(tx_ring->tx_desc_ring_pa), &txdma->pr_base_hi);
writel(lower_32_bits(tx_ring->tx_desc_ring_pa), &txdma->pr_base_lo);
writel(NUM_DESC_PER_RING_TX - 1, &txdma->pr_num_des);
writel(upper_32_bits(tx_ring->tx_status_pa), &txdma->dma_wb_base_hi);
writel(lower_32_bits(tx_ring->tx_status_pa), &txdma->dma_wb_base_lo);
*tx_ring->tx_status = 0;
writel(0, &txdma->service_request);
tx_ring->send_idx = 0;
}
static void et131x_adapter_setup(struct et131x_adapter *adapter)
{
et131x_configure_global_regs(adapter);
et1310_config_mac_regs1(adapter);
writel(ET_MMC_ENABLE, &adapter->regs->mmc.mmc_ctrl);
et1310_config_rxmac_regs(adapter);
et1310_config_txmac_regs(adapter);
et131x_config_rx_dma_regs(adapter);
et131x_config_tx_dma_regs(adapter);
et1310_config_macstat_regs(adapter);
et1310_phy_power_switch(adapter, 0);
et131x_xcvr_init(adapter);
}
static void et131x_soft_reset(struct et131x_adapter *adapter)
{
u32 reg;
reg = ET_MAC_CFG1_SOFT_RESET | ET_MAC_CFG1_SIM_RESET |
ET_MAC_CFG1_RESET_RXMC | ET_MAC_CFG1_RESET_TXMC |
ET_MAC_CFG1_RESET_RXFUNC | ET_MAC_CFG1_RESET_TXFUNC;
writel(reg, &adapter->regs->mac.cfg1);
reg = ET_RESET_ALL;
writel(reg, &adapter->regs->global.sw_reset);
reg = ET_MAC_CFG1_RESET_RXMC | ET_MAC_CFG1_RESET_TXMC |
ET_MAC_CFG1_RESET_RXFUNC | ET_MAC_CFG1_RESET_TXFUNC;
writel(reg, &adapter->regs->mac.cfg1);
writel(0, &adapter->regs->mac.cfg1);
}
static void et131x_enable_interrupts(struct et131x_adapter *adapter)
{
u32 mask;
if (adapter->flow == FLOW_TXONLY || adapter->flow == FLOW_BOTH)
mask = INT_MASK_ENABLE;
else
mask = INT_MASK_ENABLE_NO_FLOW;
writel(mask, &adapter->regs->global.int_mask);
}
static void et131x_disable_interrupts(struct et131x_adapter *adapter)
{
writel(INT_MASK_DISABLE, &adapter->regs->global.int_mask);
}
static void et131x_tx_dma_disable(struct et131x_adapter *adapter)
{
writel(ET_TXDMA_CSR_HALT | ET_TXDMA_SNGL_EPKT,
&adapter->regs->txdma.csr);
}
static void et131x_enable_txrx(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
et131x_rx_dma_enable(adapter);
et131x_tx_dma_enable(adapter);
if (adapter->flags & FMP_ADAPTER_INTERRUPT_IN_USE)
et131x_enable_interrupts(adapter);
netif_start_queue(netdev);
}
static void et131x_disable_txrx(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
netif_stop_queue(netdev);
et131x_rx_dma_disable(adapter);
et131x_tx_dma_disable(adapter);
et131x_disable_interrupts(adapter);
}
static void et131x_init_send(struct et131x_adapter *adapter)
{
int i;
struct tx_ring *tx_ring = &adapter->tx_ring;
struct tcb *tcb = tx_ring->tcb_ring;
tx_ring->tcb_qhead = tcb;
memset(tcb, 0, sizeof(struct tcb) * NUM_TCB);
for (i = 0; i < NUM_TCB; i++) {
tcb->next = tcb + 1;
tcb++;
}
tcb--;
tx_ring->tcb_qtail = tcb;
tcb->next = NULL;
tx_ring->send_head = NULL;
tx_ring->send_tail = NULL;
}
static void et1310_enable_phy_coma(struct et131x_adapter *adapter)
{
u32 pmcsr = readl(&adapter->regs->global.pm_csr);
adapter->flags |= FMP_ADAPTER_LOWER_POWER;
et131x_disable_txrx(adapter->netdev);
pmcsr &= ~ET_PMCSR_INIT;
writel(pmcsr, &adapter->regs->global.pm_csr);
pmcsr |= ET_PM_PHY_SW_COMA;
writel(pmcsr, &adapter->regs->global.pm_csr);
}
static void et1310_disable_phy_coma(struct et131x_adapter *adapter)
{
u32 pmcsr;
pmcsr = readl(&adapter->regs->global.pm_csr);
pmcsr |= ET_PMCSR_INIT;
pmcsr &= ~ET_PM_PHY_SW_COMA;
writel(pmcsr, &adapter->regs->global.pm_csr);
et131x_init_send(adapter);
et131x_soft_reset(adapter);
et131x_adapter_setup(adapter);
adapter->flags &= ~FMP_ADAPTER_LOWER_POWER;
et131x_enable_txrx(adapter->netdev);
}
static inline u32 bump_free_buff_ring(u32 *free_buff_ring, u32 limit)
{
u32 tmp_free_buff_ring = *free_buff_ring;
tmp_free_buff_ring++;
if ((tmp_free_buff_ring & ET_DMA10_MASK) > limit) {
tmp_free_buff_ring &= ~ET_DMA10_MASK;
tmp_free_buff_ring ^= ET_DMA10_WRAP;
}
tmp_free_buff_ring &= (ET_DMA10_MASK | ET_DMA10_WRAP);
*free_buff_ring = tmp_free_buff_ring;
return tmp_free_buff_ring;
}
static int et131x_rx_dma_memory_alloc(struct et131x_adapter *adapter)
{
u8 id;
u32 i, j;
u32 bufsize;
u32 psr_size;
u32 fbr_chunksize;
struct rx_ring *rx_ring = &adapter->rx_ring;
struct fbr_lookup *fbr;
rx_ring->fbr[0] = kzalloc(sizeof(*fbr), GFP_KERNEL);
if (rx_ring->fbr[0] == NULL)
return -ENOMEM;
rx_ring->fbr[1] = kzalloc(sizeof(*fbr), GFP_KERNEL);
if (rx_ring->fbr[1] == NULL)
return -ENOMEM;
if (adapter->registry_jumbo_packet < 2048) {
rx_ring->fbr[0]->buffsize = 256;
rx_ring->fbr[0]->num_entries = 512;
rx_ring->fbr[1]->buffsize = 2048;
rx_ring->fbr[1]->num_entries = 512;
} else if (adapter->registry_jumbo_packet < 4096) {
rx_ring->fbr[0]->buffsize = 512;
rx_ring->fbr[0]->num_entries = 1024;
rx_ring->fbr[1]->buffsize = 4096;
rx_ring->fbr[1]->num_entries = 512;
} else {
rx_ring->fbr[0]->buffsize = 1024;
rx_ring->fbr[0]->num_entries = 768;
rx_ring->fbr[1]->buffsize = 16384;
rx_ring->fbr[1]->num_entries = 128;
}
rx_ring->psr_entries = rx_ring->fbr[0]->num_entries +
rx_ring->fbr[1]->num_entries;
for (id = 0; id < NUM_FBRS; id++) {
fbr = rx_ring->fbr[id];
bufsize = sizeof(struct fbr_desc) * fbr->num_entries;
fbr->ring_virtaddr = dma_alloc_coherent(&adapter->pdev->dev,
bufsize,
&fbr->ring_physaddr,
GFP_KERNEL);
if (!fbr->ring_virtaddr) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Free Buffer Ring %d\n",
id);
return -ENOMEM;
}
}
for (id = 0; id < NUM_FBRS; id++) {
fbr = rx_ring->fbr[id];
fbr_chunksize = (FBR_CHUNKS * fbr->buffsize);
for (i = 0; i < fbr->num_entries / FBR_CHUNKS; i++) {
dma_addr_t fbr_physaddr;
fbr->mem_virtaddrs[i] = dma_alloc_coherent(
&adapter->pdev->dev, fbr_chunksize,
&fbr->mem_physaddrs[i],
GFP_KERNEL);
if (!fbr->mem_virtaddrs[i]) {
dev_err(&adapter->pdev->dev,
"Could not alloc memory\n");
return -ENOMEM;
}
fbr_physaddr = fbr->mem_physaddrs[i];
for (j = 0; j < FBR_CHUNKS; j++) {
u32 k = (i * FBR_CHUNKS) + j;
fbr->virt[k] = (u8 *)fbr->mem_virtaddrs[i] +
(j * fbr->buffsize);
fbr->bus_high[k] = upper_32_bits(fbr_physaddr);
fbr->bus_low[k] = lower_32_bits(fbr_physaddr);
fbr_physaddr += fbr->buffsize;
}
}
}
psr_size = sizeof(struct pkt_stat_desc) * rx_ring->psr_entries;
rx_ring->ps_ring_virtaddr = dma_alloc_coherent(&adapter->pdev->dev,
psr_size,
&rx_ring->ps_ring_physaddr,
GFP_KERNEL);
if (!rx_ring->ps_ring_virtaddr) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Packet Status Ring\n");
return -ENOMEM;
}
rx_ring->rx_status_block = dma_alloc_coherent(&adapter->pdev->dev,
sizeof(struct rx_status_block),
&rx_ring->rx_status_bus,
GFP_KERNEL);
if (!rx_ring->rx_status_block) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Status Block\n");
return -ENOMEM;
}
rx_ring->num_rfd = NIC_DEFAULT_NUM_RFD;
INIT_LIST_HEAD(&rx_ring->recv_list);
return 0;
}
static void et131x_rx_dma_memory_free(struct et131x_adapter *adapter)
{
u8 id;
u32 ii;
u32 bufsize;
u32 psr_size;
struct rfd *rfd;
struct rx_ring *rx_ring = &adapter->rx_ring;
struct fbr_lookup *fbr;
WARN_ON(rx_ring->num_ready_recv != rx_ring->num_rfd);
while (!list_empty(&rx_ring->recv_list)) {
rfd = list_entry(rx_ring->recv_list.next,
struct rfd, list_node);
list_del(&rfd->list_node);
rfd->skb = NULL;
kfree(rfd);
}
for (id = 0; id < NUM_FBRS; id++) {
fbr = rx_ring->fbr[id];
if (!fbr || !fbr->ring_virtaddr)
continue;
for (ii = 0; ii < fbr->num_entries / FBR_CHUNKS; ii++) {
if (fbr->mem_virtaddrs[ii]) {
bufsize = fbr->buffsize * FBR_CHUNKS;
dma_free_coherent(&adapter->pdev->dev,
bufsize,
fbr->mem_virtaddrs[ii],
fbr->mem_physaddrs[ii]);
fbr->mem_virtaddrs[ii] = NULL;
}
}
bufsize = sizeof(struct fbr_desc) * fbr->num_entries;
dma_free_coherent(&adapter->pdev->dev,
bufsize,
fbr->ring_virtaddr,
fbr->ring_physaddr);
fbr->ring_virtaddr = NULL;
}
if (rx_ring->ps_ring_virtaddr) {
psr_size = sizeof(struct pkt_stat_desc) * rx_ring->psr_entries;
dma_free_coherent(&adapter->pdev->dev, psr_size,
rx_ring->ps_ring_virtaddr,
rx_ring->ps_ring_physaddr);
rx_ring->ps_ring_virtaddr = NULL;
}
if (rx_ring->rx_status_block) {
dma_free_coherent(&adapter->pdev->dev,
sizeof(struct rx_status_block),
rx_ring->rx_status_block,
rx_ring->rx_status_bus);
rx_ring->rx_status_block = NULL;
}
kfree(rx_ring->fbr[0]);
kfree(rx_ring->fbr[1]);
rx_ring->num_ready_recv = 0;
}
static int et131x_init_recv(struct et131x_adapter *adapter)
{
struct rfd *rfd;
u32 rfdct;
struct rx_ring *rx_ring = &adapter->rx_ring;
for (rfdct = 0; rfdct < rx_ring->num_rfd; rfdct++) {
rfd = kzalloc(sizeof(*rfd), GFP_ATOMIC | GFP_DMA);
if (!rfd)
return -ENOMEM;
rfd->skb = NULL;
list_add_tail(&rfd->list_node, &rx_ring->recv_list);
rx_ring->num_ready_recv++;
}
return 0;
}
static void et131x_set_rx_dma_timer(struct et131x_adapter *adapter)
{
struct phy_device *phydev = adapter->netdev->phydev;
if ((phydev->speed == SPEED_100) || (phydev->speed == SPEED_10)) {
writel(0, &adapter->regs->rxdma.max_pkt_time);
writel(1, &adapter->regs->rxdma.num_pkt_done);
}
}
static void nic_return_rfd(struct et131x_adapter *adapter, struct rfd *rfd)
{
struct rx_ring *rx_local = &adapter->rx_ring;
struct rxdma_regs __iomem *rx_dma = &adapter->regs->rxdma;
u16 buff_index = rfd->bufferindex;
u8 ring_index = rfd->ringindex;
unsigned long flags;
struct fbr_lookup *fbr = rx_local->fbr[ring_index];
if (buff_index < fbr->num_entries) {
u32 free_buff_ring;
u32 __iomem *offset;
struct fbr_desc *next;
if (ring_index == 0)
offset = &rx_dma->fbr0_full_offset;
else
offset = &rx_dma->fbr1_full_offset;
next = (struct fbr_desc *)(fbr->ring_virtaddr) +
INDEX10(fbr->local_full);
next->addr_hi = fbr->bus_high[buff_index];
next->addr_lo = fbr->bus_low[buff_index];
next->word2 = buff_index;
free_buff_ring = bump_free_buff_ring(&fbr->local_full,
fbr->num_entries - 1);
writel(free_buff_ring, offset);
} else {
dev_err(&adapter->pdev->dev,
"%s illegal Buffer Index returned\n", __func__);
}
spin_lock_irqsave(&adapter->rcv_lock, flags);
list_add_tail(&rfd->list_node, &rx_local->recv_list);
rx_local->num_ready_recv++;
spin_unlock_irqrestore(&adapter->rcv_lock, flags);
WARN_ON(rx_local->num_ready_recv > rx_local->num_rfd);
}
static struct rfd *nic_rx_pkts(struct et131x_adapter *adapter)
{
struct rx_ring *rx_local = &adapter->rx_ring;
struct rx_status_block *status;
struct pkt_stat_desc *psr;
struct rfd *rfd;
unsigned long flags;
struct list_head *element;
u8 ring_index;
u16 buff_index;
u32 len;
u32 word0;
u32 word1;
struct sk_buff *skb;
struct fbr_lookup *fbr;
status = rx_local->rx_status_block;
word1 = status->word1 >> 16;
if ((word1 & 0x1FFF) == (rx_local->local_psr_full & 0x1FFF))
return NULL;
psr = (struct pkt_stat_desc *)(rx_local->ps_ring_virtaddr) +
(rx_local->local_psr_full & 0xFFF);
len = psr->word1 & 0xFFFF;
ring_index = (psr->word1 >> 26) & 0x03;
fbr = rx_local->fbr[ring_index];
buff_index = (psr->word1 >> 16) & 0x3FF;
word0 = psr->word0;
add_12bit(&rx_local->local_psr_full, 1);
if ((rx_local->local_psr_full & 0xFFF) > rx_local->psr_entries - 1) {
rx_local->local_psr_full &= ~0xFFF;
rx_local->local_psr_full ^= 0x1000;
}
writel(rx_local->local_psr_full, &adapter->regs->rxdma.psr_full_offset);
if (ring_index > 1 || buff_index > fbr->num_entries - 1) {
dev_err(&adapter->pdev->dev,
"NICRxPkts PSR Entry %d indicates length of %d and/or bad bi(%d)\n",
rx_local->local_psr_full & 0xFFF, len, buff_index);
return NULL;
}
spin_lock_irqsave(&adapter->rcv_lock, flags);
element = rx_local->recv_list.next;
rfd = list_entry(element, struct rfd, list_node);
if (!rfd) {
spin_unlock_irqrestore(&adapter->rcv_lock, flags);
return NULL;
}
list_del(&rfd->list_node);
rx_local->num_ready_recv--;
spin_unlock_irqrestore(&adapter->rcv_lock, flags);
rfd->bufferindex = buff_index;
rfd->ringindex = ring_index;
if (len < (NIC_MIN_PACKET_SIZE + 4)) {
adapter->stats.rx_other_errs++;
rfd->len = 0;
goto out;
}
if ((word0 & ALCATEL_MULTICAST_PKT) && !(word0 & ALCATEL_BROADCAST_PKT))
adapter->stats.multicast_pkts_rcvd++;
rfd->len = len;
skb = dev_alloc_skb(rfd->len + 2);
if (!skb)
return NULL;
adapter->netdev->stats.rx_bytes += rfd->len;
memcpy(skb_put(skb, rfd->len), fbr->virt[buff_index], rfd->len);
skb->protocol = eth_type_trans(skb, adapter->netdev);
skb->ip_summed = CHECKSUM_NONE;
netif_receive_skb(skb);
out:
nic_return_rfd(adapter, rfd);
return rfd;
}
static int et131x_handle_recv_pkts(struct et131x_adapter *adapter, int budget)
{
struct rfd *rfd = NULL;
int count = 0;
int limit = budget;
bool done = true;
struct rx_ring *rx_ring = &adapter->rx_ring;
if (budget > MAX_PACKETS_HANDLED)
limit = MAX_PACKETS_HANDLED;
while (count < limit) {
if (list_empty(&rx_ring->recv_list)) {
WARN_ON(rx_ring->num_ready_recv != 0);
done = false;
break;
}
rfd = nic_rx_pkts(adapter);
if (rfd == NULL)
break;
if (!adapter->packet_filter ||
!netif_carrier_ok(adapter->netdev) ||
rfd->len == 0)
continue;
adapter->netdev->stats.rx_packets++;
if (rx_ring->num_ready_recv < RFD_LOW_WATER_MARK)
dev_warn(&adapter->pdev->dev, "RFD's are running out\n");
count++;
}
if (count == limit || !done) {
rx_ring->unfinished_receives = true;
writel(PARM_TX_TIME_INT_DEF * NANO_IN_A_MICRO,
&adapter->regs->global.watchdog_timer);
} else {
rx_ring->unfinished_receives = false;
}
return count;
}
static int et131x_tx_dma_memory_alloc(struct et131x_adapter *adapter)
{
int desc_size = 0;
struct tx_ring *tx_ring = &adapter->tx_ring;
tx_ring->tcb_ring = kcalloc(NUM_TCB, sizeof(struct tcb),
GFP_ATOMIC | GFP_DMA);
if (!tx_ring->tcb_ring)
return -ENOMEM;
desc_size = (sizeof(struct tx_desc) * NUM_DESC_PER_RING_TX);
tx_ring->tx_desc_ring = dma_alloc_coherent(&adapter->pdev->dev,
desc_size,
&tx_ring->tx_desc_ring_pa,
GFP_KERNEL);
if (!tx_ring->tx_desc_ring) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Tx Ring\n");
return -ENOMEM;
}
tx_ring->tx_status = dma_alloc_coherent(&adapter->pdev->dev,
sizeof(u32),
&tx_ring->tx_status_pa,
GFP_KERNEL);
if (!tx_ring->tx_status) {
dev_err(&adapter->pdev->dev,
"Cannot alloc memory for Tx status block\n");
return -ENOMEM;
}
return 0;
}
static void et131x_tx_dma_memory_free(struct et131x_adapter *adapter)
{
int desc_size = 0;
struct tx_ring *tx_ring = &adapter->tx_ring;
if (tx_ring->tx_desc_ring) {
desc_size = (sizeof(struct tx_desc) * NUM_DESC_PER_RING_TX);
dma_free_coherent(&adapter->pdev->dev,
desc_size,
tx_ring->tx_desc_ring,
tx_ring->tx_desc_ring_pa);
tx_ring->tx_desc_ring = NULL;
}
if (tx_ring->tx_status) {
dma_free_coherent(&adapter->pdev->dev,
sizeof(u32),
tx_ring->tx_status,
tx_ring->tx_status_pa);
tx_ring->tx_status = NULL;
}
kfree(tx_ring->tcb_ring);
}
static int nic_send_packet(struct et131x_adapter *adapter, struct tcb *tcb)
{
u32 i;
struct tx_desc desc[24];
u32 frag = 0;
u32 thiscopy, remainder;
struct sk_buff *skb = tcb->skb;
u32 nr_frags = skb_shinfo(skb)->nr_frags + 1;
struct skb_frag_struct *frags = &skb_shinfo(skb)->frags[0];
struct phy_device *phydev = adapter->netdev->phydev;
dma_addr_t dma_addr;
struct tx_ring *tx_ring = &adapter->tx_ring;
BUILD_BUG_ON(MAX_SKB_FRAGS + 1 > 23);
memset(desc, 0, sizeof(struct tx_desc) * (nr_frags + 1));
for (i = 0; i < nr_frags; i++) {
if (i == 0) {
if (skb_headlen(skb) <= 1514) {
desc[frag].len_vlan = skb_headlen(skb);
dma_addr = dma_map_single(&adapter->pdev->dev,
skb->data,
skb_headlen(skb),
DMA_TO_DEVICE);
desc[frag].addr_lo = lower_32_bits(dma_addr);
desc[frag].addr_hi = upper_32_bits(dma_addr);
frag++;
} else {
desc[frag].len_vlan = skb_headlen(skb) / 2;
dma_addr = dma_map_single(&adapter->pdev->dev,
skb->data,
skb_headlen(skb) / 2,
DMA_TO_DEVICE);
desc[frag].addr_lo = lower_32_bits(dma_addr);
desc[frag].addr_hi = upper_32_bits(dma_addr);
frag++;
desc[frag].len_vlan = skb_headlen(skb) / 2;
dma_addr = dma_map_single(&adapter->pdev->dev,
skb->data +
skb_headlen(skb) / 2,
skb_headlen(skb) / 2,
DMA_TO_DEVICE);
desc[frag].addr_lo = lower_32_bits(dma_addr);
desc[frag].addr_hi = upper_32_bits(dma_addr);
frag++;
}
} else {
desc[frag].len_vlan = frags[i - 1].size;
dma_addr = skb_frag_dma_map(&adapter->pdev->dev,
&frags[i - 1],
0,
frags[i - 1].size,
DMA_TO_DEVICE);
desc[frag].addr_lo = lower_32_bits(dma_addr);
desc[frag].addr_hi = upper_32_bits(dma_addr);
frag++;
}
}
if (phydev && phydev->speed == SPEED_1000) {
if (++tx_ring->since_irq == PARM_TX_NUM_BUFS_DEF) {
desc[frag - 1].flags =
TXDESC_FLAG_INTPROC | TXDESC_FLAG_LASTPKT;
tx_ring->since_irq = 0;
} else {
desc[frag - 1].flags = TXDESC_FLAG_LASTPKT;
}
} else {
desc[frag - 1].flags =
TXDESC_FLAG_INTPROC | TXDESC_FLAG_LASTPKT;
}
desc[0].flags |= TXDESC_FLAG_FIRSTPKT;
tcb->index_start = tx_ring->send_idx;
tcb->stale = 0;
thiscopy = NUM_DESC_PER_RING_TX - INDEX10(tx_ring->send_idx);
if (thiscopy >= frag) {
remainder = 0;
thiscopy = frag;
} else {
remainder = frag - thiscopy;
}
memcpy(tx_ring->tx_desc_ring + INDEX10(tx_ring->send_idx),
desc,
sizeof(struct tx_desc) * thiscopy);
add_10bit(&tx_ring->send_idx, thiscopy);
if (INDEX10(tx_ring->send_idx) == 0 ||
INDEX10(tx_ring->send_idx) == NUM_DESC_PER_RING_TX) {
tx_ring->send_idx &= ~ET_DMA10_MASK;
tx_ring->send_idx ^= ET_DMA10_WRAP;
}
if (remainder) {
memcpy(tx_ring->tx_desc_ring,
desc + thiscopy,
sizeof(struct tx_desc) * remainder);
add_10bit(&tx_ring->send_idx, remainder);
}
if (INDEX10(tx_ring->send_idx) == 0) {
if (tx_ring->send_idx)
tcb->index = NUM_DESC_PER_RING_TX - 1;
else
tcb->index = ET_DMA10_WRAP|(NUM_DESC_PER_RING_TX - 1);
} else {
tcb->index = tx_ring->send_idx - 1;
}
spin_lock(&adapter->tcb_send_qlock);
if (tx_ring->send_tail)
tx_ring->send_tail->next = tcb;
else
tx_ring->send_head = tcb;
tx_ring->send_tail = tcb;
WARN_ON(tcb->next != NULL);
tx_ring->used++;
spin_unlock(&adapter->tcb_send_qlock);
writel(tx_ring->send_idx, &adapter->regs->txdma.service_request);
if (phydev && phydev->speed == SPEED_1000) {
writel(PARM_TX_TIME_INT_DEF * NANO_IN_A_MICRO,
&adapter->regs->global.watchdog_timer);
}
return 0;
}
static int send_packet(struct sk_buff *skb, struct et131x_adapter *adapter)
{
int status;
struct tcb *tcb;
unsigned long flags;
struct tx_ring *tx_ring = &adapter->tx_ring;
if (skb->len < ETH_HLEN)
return -EIO;
spin_lock_irqsave(&adapter->tcb_ready_qlock, flags);
tcb = tx_ring->tcb_qhead;
if (tcb == NULL) {
spin_unlock_irqrestore(&adapter->tcb_ready_qlock, flags);
return -ENOMEM;
}
tx_ring->tcb_qhead = tcb->next;
if (tx_ring->tcb_qhead == NULL)
tx_ring->tcb_qtail = NULL;
spin_unlock_irqrestore(&adapter->tcb_ready_qlock, flags);
tcb->skb = skb;
tcb->next = NULL;
status = nic_send_packet(adapter, tcb);
if (status != 0) {
spin_lock_irqsave(&adapter->tcb_ready_qlock, flags);
if (tx_ring->tcb_qtail)
tx_ring->tcb_qtail->next = tcb;
else
tx_ring->tcb_qhead = tcb;
tx_ring->tcb_qtail = tcb;
spin_unlock_irqrestore(&adapter->tcb_ready_qlock, flags);
return status;
}
WARN_ON(tx_ring->used > NUM_TCB);
return 0;
}
static inline void free_send_packet(struct et131x_adapter *adapter,
struct tcb *tcb)
{
unsigned long flags;
struct tx_desc *desc = NULL;
struct net_device_stats *stats = &adapter->netdev->stats;
struct tx_ring *tx_ring = &adapter->tx_ring;
u64 dma_addr;
if (tcb->skb) {
stats->tx_bytes += tcb->skb->len;
do {
desc = tx_ring->tx_desc_ring +
INDEX10(tcb->index_start);
dma_addr = desc->addr_lo;
dma_addr |= (u64)desc->addr_hi << 32;
dma_unmap_single(&adapter->pdev->dev,
dma_addr,
desc->len_vlan, DMA_TO_DEVICE);
add_10bit(&tcb->index_start, 1);
if (INDEX10(tcb->index_start) >=
NUM_DESC_PER_RING_TX) {
tcb->index_start &= ~ET_DMA10_MASK;
tcb->index_start ^= ET_DMA10_WRAP;
}
} while (desc != tx_ring->tx_desc_ring + INDEX10(tcb->index));
dev_kfree_skb_any(tcb->skb);
}
memset(tcb, 0, sizeof(struct tcb));
spin_lock_irqsave(&adapter->tcb_ready_qlock, flags);
stats->tx_packets++;
if (tx_ring->tcb_qtail)
tx_ring->tcb_qtail->next = tcb;
else
tx_ring->tcb_qhead = tcb;
tx_ring->tcb_qtail = tcb;
spin_unlock_irqrestore(&adapter->tcb_ready_qlock, flags);
WARN_ON(tx_ring->used < 0);
}
static void et131x_free_busy_send_packets(struct et131x_adapter *adapter)
{
struct tcb *tcb;
unsigned long flags;
u32 freed = 0;
struct tx_ring *tx_ring = &adapter->tx_ring;
spin_lock_irqsave(&adapter->tcb_send_qlock, flags);
tcb = tx_ring->send_head;
while (tcb != NULL && freed < NUM_TCB) {
struct tcb *next = tcb->next;
tx_ring->send_head = next;
if (next == NULL)
tx_ring->send_tail = NULL;
tx_ring->used--;
spin_unlock_irqrestore(&adapter->tcb_send_qlock, flags);
freed++;
free_send_packet(adapter, tcb);
spin_lock_irqsave(&adapter->tcb_send_qlock, flags);
tcb = tx_ring->send_head;
}
WARN_ON(freed == NUM_TCB);
spin_unlock_irqrestore(&adapter->tcb_send_qlock, flags);
tx_ring->used = 0;
}
static void et131x_handle_send_pkts(struct et131x_adapter *adapter)
{
unsigned long flags;
u32 serviced;
struct tcb *tcb;
u32 index;
struct tx_ring *tx_ring = &adapter->tx_ring;
serviced = readl(&adapter->regs->txdma.new_service_complete);
index = INDEX10(serviced);
spin_lock_irqsave(&adapter->tcb_send_qlock, flags);
tcb = tx_ring->send_head;
while (tcb &&
((serviced ^ tcb->index) & ET_DMA10_WRAP) &&
index < INDEX10(tcb->index)) {
tx_ring->used--;
tx_ring->send_head = tcb->next;
if (tcb->next == NULL)
tx_ring->send_tail = NULL;
spin_unlock_irqrestore(&adapter->tcb_send_qlock, flags);
free_send_packet(adapter, tcb);
spin_lock_irqsave(&adapter->tcb_send_qlock, flags);
tcb = tx_ring->send_head;
}
while (tcb &&
!((serviced ^ tcb->index) & ET_DMA10_WRAP) &&
index > (tcb->index & ET_DMA10_MASK)) {
tx_ring->used--;
tx_ring->send_head = tcb->next;
if (tcb->next == NULL)
tx_ring->send_tail = NULL;
spin_unlock_irqrestore(&adapter->tcb_send_qlock, flags);
free_send_packet(adapter, tcb);
spin_lock_irqsave(&adapter->tcb_send_qlock, flags);
tcb = tx_ring->send_head;
}
if (tx_ring->used <= NUM_TCB / 3)
netif_wake_queue(adapter->netdev);
spin_unlock_irqrestore(&adapter->tcb_send_qlock, flags);
}
static int et131x_get_regs_len(struct net_device *netdev)
{
#define ET131X_REGS_LEN 256
return ET131X_REGS_LEN * sizeof(u32);
}
static void et131x_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *regs_data)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct address_map __iomem *aregs = adapter->regs;
u32 *regs_buff = regs_data;
u32 num = 0;
u16 tmp;
memset(regs_data, 0, et131x_get_regs_len(netdev));
regs->version = (1 << 24) | (adapter->pdev->revision << 16) |
adapter->pdev->device;
et131x_mii_read(adapter, MII_BMCR, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_BMSR, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_PHYSID1, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_PHYSID2, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_ADVERTISE, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_LPA, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_EXPANSION, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, 0x07, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, 0x08, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_CTRL1000, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_STAT1000, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, 0x0b, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, 0x0c, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_MMD_CTRL, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_MMD_DATA, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, MII_ESTATUS, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_INDEX_REG, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_DATA_REG, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_MPHY_CONTROL_REG, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_LOOPBACK_CONTROL, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_LOOPBACK_CONTROL + 1, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_REGISTER_MGMT_CONTROL, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_CONFIG, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_PHY_CONTROL, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_INTERRUPT_MASK, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_INTERRUPT_STATUS, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_PHY_STATUS, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_LED_1, &tmp);
regs_buff[num++] = tmp;
et131x_mii_read(adapter, PHY_LED_2, &tmp);
regs_buff[num++] = tmp;
regs_buff[num++] = readl(&aregs->global.txq_start_addr);
regs_buff[num++] = readl(&aregs->global.txq_end_addr);
regs_buff[num++] = readl(&aregs->global.rxq_start_addr);
regs_buff[num++] = readl(&aregs->global.rxq_end_addr);
regs_buff[num++] = readl(&aregs->global.pm_csr);
regs_buff[num++] = adapter->stats.interrupt_status;
regs_buff[num++] = readl(&aregs->global.int_mask);
regs_buff[num++] = readl(&aregs->global.int_alias_clr_en);
regs_buff[num++] = readl(&aregs->global.int_status_alias);
regs_buff[num++] = readl(&aregs->global.sw_reset);
regs_buff[num++] = readl(&aregs->global.slv_timer);
regs_buff[num++] = readl(&aregs->global.msi_config);
regs_buff[num++] = readl(&aregs->global.loopback);
regs_buff[num++] = readl(&aregs->global.watchdog_timer);
regs_buff[num++] = readl(&aregs->txdma.csr);
regs_buff[num++] = readl(&aregs->txdma.pr_base_hi);
regs_buff[num++] = readl(&aregs->txdma.pr_base_lo);
regs_buff[num++] = readl(&aregs->txdma.pr_num_des);
regs_buff[num++] = readl(&aregs->txdma.txq_wr_addr);
regs_buff[num++] = readl(&aregs->txdma.txq_wr_addr_ext);
regs_buff[num++] = readl(&aregs->txdma.txq_rd_addr);
regs_buff[num++] = readl(&aregs->txdma.dma_wb_base_hi);
regs_buff[num++] = readl(&aregs->txdma.dma_wb_base_lo);
regs_buff[num++] = readl(&aregs->txdma.service_request);
regs_buff[num++] = readl(&aregs->txdma.service_complete);
regs_buff[num++] = readl(&aregs->txdma.cache_rd_index);
regs_buff[num++] = readl(&aregs->txdma.cache_wr_index);
regs_buff[num++] = readl(&aregs->txdma.tx_dma_error);
regs_buff[num++] = readl(&aregs->txdma.desc_abort_cnt);
regs_buff[num++] = readl(&aregs->txdma.payload_abort_cnt);
regs_buff[num++] = readl(&aregs->txdma.writeback_abort_cnt);
regs_buff[num++] = readl(&aregs->txdma.desc_timeout_cnt);
regs_buff[num++] = readl(&aregs->txdma.payload_timeout_cnt);
regs_buff[num++] = readl(&aregs->txdma.writeback_timeout_cnt);
regs_buff[num++] = readl(&aregs->txdma.desc_error_cnt);
regs_buff[num++] = readl(&aregs->txdma.payload_error_cnt);
regs_buff[num++] = readl(&aregs->txdma.writeback_error_cnt);
regs_buff[num++] = readl(&aregs->txdma.dropped_tlp_cnt);
regs_buff[num++] = readl(&aregs->txdma.new_service_complete);
regs_buff[num++] = readl(&aregs->txdma.ethernet_packet_cnt);
regs_buff[num++] = readl(&aregs->rxdma.csr);
regs_buff[num++] = readl(&aregs->rxdma.dma_wb_base_hi);
regs_buff[num++] = readl(&aregs->rxdma.dma_wb_base_lo);
regs_buff[num++] = readl(&aregs->rxdma.num_pkt_done);
regs_buff[num++] = readl(&aregs->rxdma.max_pkt_time);
regs_buff[num++] = readl(&aregs->rxdma.rxq_rd_addr);
regs_buff[num++] = readl(&aregs->rxdma.rxq_rd_addr_ext);
regs_buff[num++] = readl(&aregs->rxdma.rxq_wr_addr);
regs_buff[num++] = readl(&aregs->rxdma.psr_base_hi);
regs_buff[num++] = readl(&aregs->rxdma.psr_base_lo);
regs_buff[num++] = readl(&aregs->rxdma.psr_num_des);
regs_buff[num++] = readl(&aregs->rxdma.psr_avail_offset);
regs_buff[num++] = readl(&aregs->rxdma.psr_full_offset);
regs_buff[num++] = readl(&aregs->rxdma.psr_access_index);
regs_buff[num++] = readl(&aregs->rxdma.psr_min_des);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_base_lo);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_base_hi);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_num_des);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_avail_offset);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_full_offset);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_rd_index);
regs_buff[num++] = readl(&aregs->rxdma.fbr0_min_des);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_base_lo);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_base_hi);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_num_des);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_avail_offset);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_full_offset);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_rd_index);
regs_buff[num++] = readl(&aregs->rxdma.fbr1_min_des);
}
static void et131x_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *info)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
strlcpy(info->driver, DRIVER_NAME, sizeof(info->driver));
strlcpy(info->version, DRIVER_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(adapter->pdev),
sizeof(info->bus_info));
}
static void et131x_hwaddr_init(struct et131x_adapter *adapter)
{
if (is_zero_ether_addr(adapter->rom_addr)) {
get_random_bytes(&adapter->addr[5], 1);
ether_addr_copy(adapter->rom_addr, adapter->addr);
} else {
ether_addr_copy(adapter->addr, adapter->rom_addr);
}
}
static int et131x_pci_init(struct et131x_adapter *adapter,
struct pci_dev *pdev)
{
u16 max_payload;
int i, rc;
rc = et131x_init_eeprom(adapter);
if (rc < 0)
goto out;
if (!pci_is_pcie(pdev)) {
dev_err(&pdev->dev, "Missing PCIe capabilities\n");
goto err_out;
}
max_payload = pdev->pcie_mpss;
if (max_payload < 2) {
static const u16 acknak[2] = { 0x76, 0xD0 };
static const u16 replay[2] = { 0x1E0, 0x2ED };
if (pci_write_config_word(pdev, ET1310_PCI_ACK_NACK,
acknak[max_payload])) {
dev_err(&pdev->dev,
"Could not write PCI config space for ACK/NAK\n");
goto err_out;
}
if (pci_write_config_word(pdev, ET1310_PCI_REPLAY,
replay[max_payload])) {
dev_err(&pdev->dev,
"Could not write PCI config space for Replay Timer\n");
goto err_out;
}
}
if (pci_write_config_byte(pdev, ET1310_PCI_L0L1LATENCY, 0x11)) {
dev_err(&pdev->dev,
"Could not write PCI config space for Latency Timers\n");
goto err_out;
}
if (pcie_set_readrq(pdev, 2048)) {
dev_err(&pdev->dev,
"Couldn't change PCI config space for Max read size\n");
goto err_out;
}
if (!adapter->has_eeprom) {
et131x_hwaddr_init(adapter);
return 0;
}
for (i = 0; i < ETH_ALEN; i++) {
if (pci_read_config_byte(pdev, ET1310_PCI_MAC_ADDRESS + i,
adapter->rom_addr + i)) {
dev_err(&pdev->dev, "Could not read PCI config space for MAC address\n");
goto err_out;
}
}
ether_addr_copy(adapter->addr, adapter->rom_addr);
out:
return rc;
err_out:
rc = -EIO;
goto out;
}
static void et131x_error_timer_handler(unsigned long data)
{
struct et131x_adapter *adapter = (struct et131x_adapter *)data;
struct phy_device *phydev = adapter->netdev->phydev;
if (et1310_in_phy_coma(adapter)) {
et1310_disable_phy_coma(adapter);
adapter->boot_coma = 20;
} else {
et1310_update_macstat_host_counters(adapter);
}
if (!phydev->link && adapter->boot_coma < 11)
adapter->boot_coma++;
if (adapter->boot_coma == 10) {
if (!phydev->link) {
if (!et1310_in_phy_coma(adapter)) {
et131x_enable_interrupts(adapter);
et1310_enable_phy_coma(adapter);
}
}
}
mod_timer(&adapter->error_timer, jiffies +
msecs_to_jiffies(TX_ERROR_PERIOD));
}
static void et131x_adapter_memory_free(struct et131x_adapter *adapter)
{
et131x_tx_dma_memory_free(adapter);
et131x_rx_dma_memory_free(adapter);
}
static int et131x_adapter_memory_alloc(struct et131x_adapter *adapter)
{
int status;
status = et131x_tx_dma_memory_alloc(adapter);
if (status) {
dev_err(&adapter->pdev->dev,
"et131x_tx_dma_memory_alloc FAILED\n");
et131x_tx_dma_memory_free(adapter);
return status;
}
status = et131x_rx_dma_memory_alloc(adapter);
if (status) {
dev_err(&adapter->pdev->dev,
"et131x_rx_dma_memory_alloc FAILED\n");
et131x_adapter_memory_free(adapter);
return status;
}
status = et131x_init_recv(adapter);
if (status) {
dev_err(&adapter->pdev->dev, "et131x_init_recv FAILED\n");
et131x_adapter_memory_free(adapter);
}
return status;
}
static void et131x_adjust_link(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct phy_device *phydev = netdev->phydev;
if (!phydev)
return;
if (phydev->link == adapter->link)
return;
if (et1310_in_phy_coma(adapter))
et1310_disable_phy_coma(adapter);
adapter->link = phydev->link;
phy_print_status(phydev);
if (phydev->link) {
adapter->boot_coma = 20;
if (phydev->speed == SPEED_10) {
u16 register18;
et131x_mii_read(adapter, PHY_MPHY_CONTROL_REG,
&register18);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_MPHY_CONTROL_REG,
register18 | 0x4);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_INDEX_REG, register18 | 0x8402);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_DATA_REG, register18 | 511);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_MPHY_CONTROL_REG, register18);
}
et1310_config_flow_control(adapter);
if (phydev->speed == SPEED_1000 &&
adapter->registry_jumbo_packet > 2048) {
u16 reg;
et131x_mii_read(adapter, PHY_CONFIG, &reg);
reg &= ~ET_PHY_CONFIG_TX_FIFO_DEPTH;
reg |= ET_PHY_CONFIG_FIFO_DEPTH_32;
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_CONFIG, reg);
}
et131x_set_rx_dma_timer(adapter);
et1310_config_mac_regs2(adapter);
} else {
adapter->boot_coma = 0;
if (phydev->speed == SPEED_10) {
u16 register18;
et131x_mii_read(adapter, PHY_MPHY_CONTROL_REG,
&register18);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_MPHY_CONTROL_REG,
register18 | 0x4);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_INDEX_REG, register18 | 0x8402);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_DATA_REG, register18 | 511);
et131x_mii_write(adapter, phydev->mdio.addr,
PHY_MPHY_CONTROL_REG, register18);
}
et131x_free_busy_send_packets(adapter);
et131x_init_send(adapter);
et131x_soft_reset(adapter);
et131x_adapter_setup(adapter);
et131x_disable_txrx(netdev);
et131x_enable_txrx(netdev);
}
}
static int et131x_mii_probe(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct phy_device *phydev = NULL;
phydev = phy_find_first(adapter->mii_bus);
if (!phydev) {
dev_err(&adapter->pdev->dev, "no PHY found\n");
return -ENODEV;
}
phydev = phy_connect(netdev, phydev_name(phydev),
&et131x_adjust_link, PHY_INTERFACE_MODE_MII);
if (IS_ERR(phydev)) {
dev_err(&adapter->pdev->dev, "Could not attach to PHY\n");
return PTR_ERR(phydev);
}
phydev->supported &= (SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg |
SUPPORTED_MII |
SUPPORTED_TP);
if (adapter->pdev->device != ET131X_PCI_DEVICE_ID_FAST)
phydev->supported |= SUPPORTED_1000baseT_Half |
SUPPORTED_1000baseT_Full;
phydev->advertising = phydev->supported;
phydev->autoneg = AUTONEG_ENABLE;
phy_attached_info(phydev);
return 0;
}
static struct et131x_adapter *et131x_adapter_init(struct net_device *netdev,
struct pci_dev *pdev)
{
static const u8 default_mac[] = { 0x00, 0x05, 0x3d, 0x00, 0x02, 0x00 };
struct et131x_adapter *adapter;
adapter = netdev_priv(netdev);
adapter->pdev = pci_dev_get(pdev);
adapter->netdev = netdev;
spin_lock_init(&adapter->tcb_send_qlock);
spin_lock_init(&adapter->tcb_ready_qlock);
spin_lock_init(&adapter->rcv_lock);
adapter->registry_jumbo_packet = 1514;
ether_addr_copy(adapter->addr, default_mac);
return adapter;
}
static void et131x_pci_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct et131x_adapter *adapter = netdev_priv(netdev);
unregister_netdev(netdev);
netif_napi_del(&adapter->napi);
phy_disconnect(netdev->phydev);
mdiobus_unregister(adapter->mii_bus);
mdiobus_free(adapter->mii_bus);
et131x_adapter_memory_free(adapter);
iounmap(adapter->regs);
pci_dev_put(pdev);
free_netdev(netdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static void et131x_up(struct net_device *netdev)
{
et131x_enable_txrx(netdev);
phy_start(netdev->phydev);
}
static void et131x_down(struct net_device *netdev)
{
netif_trans_update(netdev);
phy_stop(netdev->phydev);
et131x_disable_txrx(netdev);
}
static int et131x_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *netdev = pci_get_drvdata(pdev);
if (netif_running(netdev)) {
netif_device_detach(netdev);
et131x_down(netdev);
pci_save_state(pdev);
}
return 0;
}
static int et131x_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *netdev = pci_get_drvdata(pdev);
if (netif_running(netdev)) {
pci_restore_state(pdev);
et131x_up(netdev);
netif_device_attach(netdev);
}
return 0;
}
static irqreturn_t et131x_isr(int irq, void *dev_id)
{
bool handled = true;
bool enable_interrupts = true;
struct net_device *netdev = dev_id;
struct et131x_adapter *adapter = netdev_priv(netdev);
struct address_map __iomem *iomem = adapter->regs;
struct rx_ring *rx_ring = &adapter->rx_ring;
struct tx_ring *tx_ring = &adapter->tx_ring;
u32 status;
if (!netif_device_present(netdev)) {
handled = false;
enable_interrupts = false;
goto out;
}
et131x_disable_interrupts(adapter);
status = readl(&adapter->regs->global.int_status);
if (adapter->flow == FLOW_TXONLY || adapter->flow == FLOW_BOTH)
status &= ~INT_MASK_ENABLE;
else
status &= ~INT_MASK_ENABLE_NO_FLOW;
if (!status) {
handled = false;
et131x_enable_interrupts(adapter);
goto out;
}
if (status & ET_INTR_WATCHDOG) {
struct tcb *tcb = tx_ring->send_head;
if (tcb)
if (++tcb->stale > 1)
status |= ET_INTR_TXDMA_ISR;
if (rx_ring->unfinished_receives)
status |= ET_INTR_RXDMA_XFR_DONE;
else if (tcb == NULL)
writel(0, &adapter->regs->global.watchdog_timer);
status &= ~ET_INTR_WATCHDOG;
}
if (status & (ET_INTR_RXDMA_XFR_DONE | ET_INTR_TXDMA_ISR)) {
enable_interrupts = false;
napi_schedule(&adapter->napi);
}
status &= ~(ET_INTR_TXDMA_ISR | ET_INTR_RXDMA_XFR_DONE);
if (!status)
goto out;
if (status & ET_INTR_TXDMA_ERR) {
u32 txdma_err = readl(&iomem->txdma.tx_dma_error);
dev_warn(&adapter->pdev->dev,
"TXDMA_ERR interrupt, error = %d\n",
txdma_err);
}
if (status & (ET_INTR_RXDMA_FB_R0_LOW | ET_INTR_RXDMA_FB_R1_LOW)) {
if (adapter->flow == FLOW_TXONLY || adapter->flow == FLOW_BOTH) {
u32 pm_csr;
pm_csr = readl(&iomem->global.pm_csr);
if (!et1310_in_phy_coma(adapter))
writel(3, &iomem->txmac.bp_ctrl);
}
}
if (status & ET_INTR_RXDMA_STAT_LOW) {
}
if (status & ET_INTR_RXDMA_ERR) {
dev_warn(&adapter->pdev->dev, "RxDMA_ERR interrupt, error %x\n",
readl(&iomem->txmac.tx_test));
}
if (status & ET_INTR_WOL) {
dev_err(&adapter->pdev->dev, "WAKE_ON_LAN interrupt\n");
}
if (status & ET_INTR_TXMAC) {
u32 err = readl(&iomem->txmac.err);
dev_warn(&adapter->pdev->dev, "TXMAC interrupt, error 0x%08x\n",
err);
}
if (status & ET_INTR_RXMAC) {
dev_warn(&adapter->pdev->dev,
"RXMAC interrupt, error 0x%08x. Requesting reset\n",
readl(&iomem->rxmac.err_reg));
dev_warn(&adapter->pdev->dev,
"Enable 0x%08x, Diag 0x%08x\n",
readl(&iomem->rxmac.ctrl),
readl(&iomem->rxmac.rxq_diag));
}
if (status & ET_INTR_MAC_STAT) {
et1310_handle_macstat_interrupt(adapter);
}
if (status & ET_INTR_SLV_TIMEOUT) {
}
out:
if (enable_interrupts)
et131x_enable_interrupts(adapter);
return IRQ_RETVAL(handled);
}
static int et131x_poll(struct napi_struct *napi, int budget)
{
struct et131x_adapter *adapter =
container_of(napi, struct et131x_adapter, napi);
int work_done = et131x_handle_recv_pkts(adapter, budget);
et131x_handle_send_pkts(adapter);
if (work_done < budget) {
napi_complete(&adapter->napi);
et131x_enable_interrupts(adapter);
}
return work_done;
}
static struct net_device_stats *et131x_stats(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct net_device_stats *stats = &adapter->netdev->stats;
struct ce_stats *devstat = &adapter->stats;
stats->rx_errors = devstat->rx_length_errs +
devstat->rx_align_errs +
devstat->rx_crc_errs +
devstat->rx_code_violations +
devstat->rx_other_errs;
stats->tx_errors = devstat->tx_max_pkt_errs;
stats->multicast = devstat->multicast_pkts_rcvd;
stats->collisions = devstat->tx_collisions;
stats->rx_length_errors = devstat->rx_length_errs;
stats->rx_over_errors = devstat->rx_overflows;
stats->rx_crc_errors = devstat->rx_crc_errs;
stats->rx_dropped = devstat->rcvd_pkts_dropped;
return stats;
}
static int et131x_open(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct pci_dev *pdev = adapter->pdev;
unsigned int irq = pdev->irq;
int result;
init_timer(&adapter->error_timer);
adapter->error_timer.expires = jiffies +
msecs_to_jiffies(TX_ERROR_PERIOD);
adapter->error_timer.function = et131x_error_timer_handler;
adapter->error_timer.data = (unsigned long)adapter;
add_timer(&adapter->error_timer);
result = request_irq(irq, et131x_isr,
IRQF_SHARED, netdev->name, netdev);
if (result) {
dev_err(&pdev->dev, "could not register IRQ %d\n", irq);
return result;
}
adapter->flags |= FMP_ADAPTER_INTERRUPT_IN_USE;
napi_enable(&adapter->napi);
et131x_up(netdev);
return result;
}
static int et131x_close(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
et131x_down(netdev);
napi_disable(&adapter->napi);
adapter->flags &= ~FMP_ADAPTER_INTERRUPT_IN_USE;
free_irq(adapter->pdev->irq, netdev);
return del_timer_sync(&adapter->error_timer);
}
static int et131x_ioctl(struct net_device *netdev, struct ifreq *reqbuf,
int cmd)
{
if (!netdev->phydev)
return -EINVAL;
return phy_mii_ioctl(netdev->phydev, reqbuf, cmd);
}
static int et131x_set_packet_filter(struct et131x_adapter *adapter)
{
int filter = adapter->packet_filter;
u32 ctrl;
u32 pf_ctrl;
ctrl = readl(&adapter->regs->rxmac.ctrl);
pf_ctrl = readl(&adapter->regs->rxmac.pf_ctrl);
ctrl |= 0x04;
if ((filter & ET131X_PACKET_TYPE_PROMISCUOUS) || filter == 0)
pf_ctrl &= ~7;
else {
if (filter & ET131X_PACKET_TYPE_ALL_MULTICAST)
pf_ctrl &= ~2;
else {
et1310_setup_device_for_multicast(adapter);
pf_ctrl |= 2;
ctrl &= ~0x04;
}
if (filter & ET131X_PACKET_TYPE_DIRECTED) {
et1310_setup_device_for_unicast(adapter);
pf_ctrl |= 4;
ctrl &= ~0x04;
}
if (filter & ET131X_PACKET_TYPE_BROADCAST) {
pf_ctrl |= 1;
ctrl &= ~0x04;
} else {
pf_ctrl &= ~1;
}
writel(pf_ctrl, &adapter->regs->rxmac.pf_ctrl);
writel(ctrl, &adapter->regs->rxmac.ctrl);
}
return 0;
}
static void et131x_multicast(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
int packet_filter;
struct netdev_hw_addr *ha;
int i;
packet_filter = adapter->packet_filter;
packet_filter &= ~ET131X_PACKET_TYPE_MULTICAST;
if (netdev->flags & IFF_PROMISC)
adapter->packet_filter |= ET131X_PACKET_TYPE_PROMISCUOUS;
else
adapter->packet_filter &= ~ET131X_PACKET_TYPE_PROMISCUOUS;
if ((netdev->flags & IFF_ALLMULTI) ||
(netdev_mc_count(netdev) > NIC_MAX_MCAST_LIST))
adapter->packet_filter |= ET131X_PACKET_TYPE_ALL_MULTICAST;
if (netdev_mc_count(netdev) < 1) {
adapter->packet_filter &= ~ET131X_PACKET_TYPE_ALL_MULTICAST;
adapter->packet_filter &= ~ET131X_PACKET_TYPE_MULTICAST;
} else {
adapter->packet_filter |= ET131X_PACKET_TYPE_MULTICAST;
}
i = 0;
netdev_for_each_mc_addr(ha, netdev) {
if (i == NIC_MAX_MCAST_LIST)
break;
ether_addr_copy(adapter->multicast_list[i++], ha->addr);
}
adapter->multicast_addr_count = i;
if (packet_filter != adapter->packet_filter)
et131x_set_packet_filter(adapter);
}
static netdev_tx_t et131x_tx(struct sk_buff *skb, struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct tx_ring *tx_ring = &adapter->tx_ring;
if (tx_ring->used >= NUM_TCB - 1 && !netif_queue_stopped(netdev))
netif_stop_queue(netdev);
netif_trans_update(netdev);
if (tx_ring->used >= NUM_TCB)
goto drop_err;
if ((adapter->flags & FMP_ADAPTER_FAIL_SEND_MASK) ||
!netif_carrier_ok(netdev))
goto drop_err;
if (send_packet(skb, adapter))
goto drop_err;
return NETDEV_TX_OK;
drop_err:
dev_kfree_skb_any(skb);
adapter->netdev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
static void et131x_tx_timeout(struct net_device *netdev)
{
struct et131x_adapter *adapter = netdev_priv(netdev);
struct tx_ring *tx_ring = &adapter->tx_ring;
struct tcb *tcb;
unsigned long flags;
if (!(adapter->flags & FMP_ADAPTER_INTERRUPT_IN_USE))
return;
if (adapter->flags & FMP_ADAPTER_NON_RECOVER_ERROR)
return;
if (adapter->flags & FMP_ADAPTER_HARDWARE_ERROR) {
dev_err(&adapter->pdev->dev, "hardware error - reset\n");
return;
}
spin_lock_irqsave(&adapter->tcb_send_qlock, flags);
tcb = tx_ring->send_head;
spin_unlock_irqrestore(&adapter->tcb_send_qlock, flags);
if (tcb) {
tcb->count++;
if (tcb->count > NIC_SEND_HANG_THRESHOLD) {
dev_warn(&adapter->pdev->dev,
"Send stuck - reset. tcb->WrIndex %x\n",
tcb->index);
adapter->netdev->stats.tx_errors++;
et131x_disable_txrx(netdev);
et131x_enable_txrx(netdev);
}
}
}
static int et131x_change_mtu(struct net_device *netdev, int new_mtu)
{
int result = 0;
struct et131x_adapter *adapter = netdev_priv(netdev);
et131x_disable_txrx(netdev);
netdev->mtu = new_mtu;
et131x_adapter_memory_free(adapter);
adapter->registry_jumbo_packet = new_mtu + 14;
et131x_soft_reset(adapter);
result = et131x_adapter_memory_alloc(adapter);
if (result != 0) {
dev_warn(&adapter->pdev->dev,
"Change MTU failed; couldn't re-alloc DMA memory\n");
return result;
}
et131x_init_send(adapter);
et131x_hwaddr_init(adapter);
ether_addr_copy(netdev->dev_addr, adapter->addr);
et131x_adapter_setup(adapter);
et131x_enable_txrx(netdev);
return result;
}
static int et131x_pci_setup(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *netdev;
struct et131x_adapter *adapter;
int rc;
rc = pci_enable_device(pdev);
if (rc < 0) {
dev_err(&pdev->dev, "pci_enable_device() failed\n");
goto out;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
dev_err(&pdev->dev, "Can't find PCI device's base address\n");
rc = -ENODEV;
goto err_disable;
}
rc = pci_request_regions(pdev, DRIVER_NAME);
if (rc < 0) {
dev_err(&pdev->dev, "Can't get PCI resources\n");
goto err_disable;
}
pci_set_master(pdev);
if (dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64)) &&
dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32))) {
dev_err(&pdev->dev, "No usable DMA addressing method\n");
rc = -EIO;
goto err_release_res;
}
netdev = alloc_etherdev(sizeof(struct et131x_adapter));
if (!netdev) {
dev_err(&pdev->dev, "Couldn't alloc netdev struct\n");
rc = -ENOMEM;
goto err_release_res;
}
netdev->watchdog_timeo = ET131X_TX_TIMEOUT;
netdev->netdev_ops = &et131x_netdev_ops;
netdev->min_mtu = ET131X_MIN_MTU;
netdev->max_mtu = ET131X_MAX_MTU;
SET_NETDEV_DEV(netdev, &pdev->dev);
netdev->ethtool_ops = &et131x_ethtool_ops;
adapter = et131x_adapter_init(netdev, pdev);
rc = et131x_pci_init(adapter, pdev);
if (rc < 0)
goto err_free_dev;
adapter->regs = pci_ioremap_bar(pdev, 0);
if (!adapter->regs) {
dev_err(&pdev->dev, "Cannot map device registers\n");
rc = -ENOMEM;
goto err_free_dev;
}
writel(ET_PMCSR_INIT, &adapter->regs->global.pm_csr);
et131x_soft_reset(adapter);
et131x_disable_interrupts(adapter);
rc = et131x_adapter_memory_alloc(adapter);
if (rc < 0) {
dev_err(&pdev->dev, "Could not alloc adapter memory (DMA)\n");
goto err_iounmap;
}
et131x_init_send(adapter);
netif_napi_add(netdev, &adapter->napi, et131x_poll, 64);
ether_addr_copy(netdev->dev_addr, adapter->addr);
rc = -ENOMEM;
adapter->mii_bus = mdiobus_alloc();
if (!adapter->mii_bus) {
dev_err(&pdev->dev, "Alloc of mii_bus struct failed\n");
goto err_mem_free;
}
adapter->mii_bus->name = "et131x_eth_mii";
snprintf(adapter->mii_bus->id, MII_BUS_ID_SIZE, "%x",
(adapter->pdev->bus->number << 8) | adapter->pdev->devfn);
adapter->mii_bus->priv = netdev;
adapter->mii_bus->read = et131x_mdio_read;
adapter->mii_bus->write = et131x_mdio_write;
rc = mdiobus_register(adapter->mii_bus);
if (rc < 0) {
dev_err(&pdev->dev, "failed to register MII bus\n");
goto err_mdio_free;
}
rc = et131x_mii_probe(netdev);
if (rc < 0) {
dev_err(&pdev->dev, "failed to probe MII bus\n");
goto err_mdio_unregister;
}
et131x_adapter_setup(adapter);
adapter->boot_coma = 0;
et1310_disable_phy_coma(adapter);
rc = register_netdev(netdev);
if (rc < 0) {
dev_err(&pdev->dev, "register_netdev() failed\n");
goto err_phy_disconnect;
}
pci_set_drvdata(pdev, netdev);
out:
return rc;
err_phy_disconnect:
phy_disconnect(netdev->phydev);
err_mdio_unregister:
mdiobus_unregister(adapter->mii_bus);
err_mdio_free:
mdiobus_free(adapter->mii_bus);
err_mem_free:
et131x_adapter_memory_free(adapter);
err_iounmap:
iounmap(adapter->regs);
err_free_dev:
pci_dev_put(pdev);
free_netdev(netdev);
err_release_res:
pci_release_regions(pdev);
err_disable:
pci_disable_device(pdev);
goto out;
}
