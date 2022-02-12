void ConfigMACRegs1(struct et131x_adapter *etdev)
{
struct mac_regs __iomem *pMac = &etdev->regs->mac;
u32 station1;
u32 station2;
u32 ipg;
writel(0xC00F0000, &pMac->cfg1);
ipg = 0x38005860;
ipg |= 0x50 << 8;
writel(ipg, &pMac->ipg);
writel(0x00A1F037, &pMac->hfdp);
writel(0, &pMac->if_ctrl);
writel(0x07, &pMac->mii_mgmt_cfg);
station2 = (etdev->addr[1] << ET_MAC_STATION_ADDR2_OC2_SHIFT) |
(etdev->addr[0] << ET_MAC_STATION_ADDR2_OC1_SHIFT);
station1 = (etdev->addr[5] << ET_MAC_STATION_ADDR1_OC6_SHIFT) |
(etdev->addr[4] << ET_MAC_STATION_ADDR1_OC5_SHIFT) |
(etdev->addr[3] << ET_MAC_STATION_ADDR1_OC4_SHIFT) |
etdev->addr[2];
writel(station1, &pMac->station_addr_1);
writel(station2, &pMac->station_addr_2);
writel(etdev->RegistryJumboPacket + 4, &pMac->max_fm_len);
writel(0, &pMac->cfg1);
}
void ConfigMACRegs2(struct et131x_adapter *etdev)
{
int32_t delay = 0;
struct mac_regs __iomem *pMac = &etdev->regs->mac;
u32 cfg1;
u32 cfg2;
u32 ifctrl;
u32 ctl;
ctl = readl(&etdev->regs->txmac.ctl);
cfg1 = readl(&pMac->cfg1);
cfg2 = readl(&pMac->cfg2);
ifctrl = readl(&pMac->if_ctrl);
cfg2 &= ~0x300;
if (etdev->linkspeed == TRUEPHY_SPEED_1000MBPS) {
cfg2 |= 0x200;
ifctrl &= ~(1 << 24);
} else {
cfg2 |= 0x100;
ifctrl |= (1 << 24);
}
cfg1 |= CFG1_RX_ENABLE|CFG1_TX_ENABLE|CFG1_TX_FLOW;
cfg1 &= ~(CFG1_LOOPBACK|CFG1_RX_FLOW);
if (etdev->flowcontrol == FLOW_RXONLY || etdev->flowcontrol == FLOW_BOTH)
cfg1 |= CFG1_RX_FLOW;
writel(cfg1, &pMac->cfg1);
cfg2 |= 0x7016;
cfg2 &= ~0x0021;
if (etdev->duplex_mode)
cfg2 |= 0x01;
ifctrl &= ~(1 << 26);
if (!etdev->duplex_mode)
ifctrl |= (1<<26);
writel(ifctrl, &pMac->if_ctrl);
writel(cfg2, &pMac->cfg2);
do {
udelay(10);
delay++;
cfg1 = readl(&pMac->cfg1);
} while ((cfg1 & CFG1_WAIT) != CFG1_WAIT && delay < 100);
if (delay == 100) {
dev_warn(&etdev->pdev->dev,
"Syncd bits did not respond correctly cfg1 word 0x%08x\n",
cfg1);
}
ctl |= 0x09;
writel(ctl, &etdev->regs->txmac.ctl);
if (etdev->flags & fMP_ADAPTER_LOWER_POWER) {
et131x_rx_dma_enable(etdev);
et131x_tx_dma_enable(etdev);
}
}
void ConfigRxMacRegs(struct et131x_adapter *etdev)
{
struct rxmac_regs __iomem *pRxMac = &etdev->regs->rxmac;
u32 sa_lo;
u32 sa_hi = 0;
u32 pf_ctrl = 0;
writel(0x8, &pRxMac->ctrl);
writel(0, &pRxMac->crc0);
writel(0, &pRxMac->crc12);
writel(0, &pRxMac->crc34);
writel(0, &pRxMac->mask0_word0);
writel(0, &pRxMac->mask0_word1);
writel(0, &pRxMac->mask0_word2);
writel(0, &pRxMac->mask0_word3);
writel(0, &pRxMac->mask1_word0);
writel(0, &pRxMac->mask1_word1);
writel(0, &pRxMac->mask1_word2);
writel(0, &pRxMac->mask1_word3);
writel(0, &pRxMac->mask2_word0);
writel(0, &pRxMac->mask2_word1);
writel(0, &pRxMac->mask2_word2);
writel(0, &pRxMac->mask2_word3);
writel(0, &pRxMac->mask3_word0);
writel(0, &pRxMac->mask3_word1);
writel(0, &pRxMac->mask3_word2);
writel(0, &pRxMac->mask3_word3);
writel(0, &pRxMac->mask4_word0);
writel(0, &pRxMac->mask4_word1);
writel(0, &pRxMac->mask4_word2);
writel(0, &pRxMac->mask4_word3);
sa_lo = (etdev->addr[2] << ET_WOL_LO_SA3_SHIFT) |
(etdev->addr[3] << ET_WOL_LO_SA4_SHIFT) |
(etdev->addr[4] << ET_WOL_LO_SA5_SHIFT) |
etdev->addr[5];
writel(sa_lo, &pRxMac->sa_lo);
sa_hi = (u32) (etdev->addr[0] << ET_WOL_HI_SA1_SHIFT) |
etdev->addr[1];
writel(sa_hi, &pRxMac->sa_hi);
writel(0, &pRxMac->pf_ctrl);
if (etdev->PacketFilter & ET131X_PACKET_TYPE_DIRECTED) {
SetupDeviceForUnicast(etdev);
pf_ctrl |= 4;
} else {
writel(0, &pRxMac->uni_pf_addr1);
writel(0, &pRxMac->uni_pf_addr2);
writel(0, &pRxMac->uni_pf_addr3);
}
if (!(etdev->PacketFilter & ET131X_PACKET_TYPE_ALL_MULTICAST)) {
pf_ctrl |= 2;
SetupDeviceForMulticast(etdev);
}
pf_ctrl |= (NIC_MIN_PACKET_SIZE + 4) << 16;
pf_ctrl |= 8;
if (etdev->RegistryJumboPacket > 8192)
writel(0x41, &pRxMac->mcif_ctrl_max_seg);
else
writel(0, &pRxMac->mcif_ctrl_max_seg);
writel(0, &pRxMac->mcif_water_mark);
writel(0, &pRxMac->mif_ctrl);
writel(0, &pRxMac->space_avail);
if (etdev->linkspeed == TRUEPHY_SPEED_100MBPS)
writel(0x30038, &pRxMac->mif_ctrl);
else
writel(0x30030, &pRxMac->mif_ctrl);
writel(pf_ctrl, &pRxMac->pf_ctrl);
writel(0x9, &pRxMac->ctrl);
}
void ConfigTxMacRegs(struct et131x_adapter *etdev)
{
struct txmac_regs *txmac = &etdev->regs->txmac;
if (etdev->flowcontrol == FLOW_NONE)
writel(0, &txmac->cf_param);
else
writel(0x40, &txmac->cf_param);
}
void ConfigMacStatRegs(struct et131x_adapter *etdev)
{
struct macstat_regs __iomem *macstat =
&etdev->regs->macstat;
writel(0, &macstat->txrx_0_64_byte_frames);
writel(0, &macstat->txrx_65_127_byte_frames);
writel(0, &macstat->txrx_128_255_byte_frames);
writel(0, &macstat->txrx_256_511_byte_frames);
writel(0, &macstat->txrx_512_1023_byte_frames);
writel(0, &macstat->txrx_1024_1518_byte_frames);
writel(0, &macstat->txrx_1519_1522_gvln_frames);
writel(0, &macstat->rx_bytes);
writel(0, &macstat->rx_packets);
writel(0, &macstat->rx_fcs_errs);
writel(0, &macstat->rx_multicast_packets);
writel(0, &macstat->rx_broadcast_packets);
writel(0, &macstat->rx_control_frames);
writel(0, &macstat->rx_pause_frames);
writel(0, &macstat->rx_unknown_opcodes);
writel(0, &macstat->rx_align_errs);
writel(0, &macstat->rx_frame_len_errs);
writel(0, &macstat->rx_code_errs);
writel(0, &macstat->rx_carrier_sense_errs);
writel(0, &macstat->rx_undersize_packets);
writel(0, &macstat->rx_oversize_packets);
writel(0, &macstat->rx_fragment_packets);
writel(0, &macstat->rx_jabbers);
writel(0, &macstat->rx_drops);
writel(0, &macstat->tx_bytes);
writel(0, &macstat->tx_packets);
writel(0, &macstat->tx_multicast_packets);
writel(0, &macstat->tx_broadcast_packets);
writel(0, &macstat->tx_pause_frames);
writel(0, &macstat->tx_deferred);
writel(0, &macstat->tx_excessive_deferred);
writel(0, &macstat->tx_single_collisions);
writel(0, &macstat->tx_multiple_collisions);
writel(0, &macstat->tx_late_collisions);
writel(0, &macstat->tx_excessive_collisions);
writel(0, &macstat->tx_total_collisions);
writel(0, &macstat->tx_pause_honored_frames);
writel(0, &macstat->tx_drops);
writel(0, &macstat->tx_jabbers);
writel(0, &macstat->tx_fcs_errs);
writel(0, &macstat->tx_control_frames);
writel(0, &macstat->tx_oversize_frames);
writel(0, &macstat->tx_undersize_frames);
writel(0, &macstat->tx_fragments);
writel(0, &macstat->carry_reg1);
writel(0, &macstat->carry_reg2);
writel(0xFFFFBE32, &macstat->carry_reg1_mask);
writel(0xFFFE7E8B, &macstat->carry_reg2_mask);
}
void ConfigFlowControl(struct et131x_adapter *etdev)
{
if (etdev->duplex_mode == 0) {
etdev->flowcontrol = FLOW_NONE;
} else {
char remote_pause, remote_async_pause;
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_READ, 5, 10, &remote_pause);
ET1310_PhyAccessMiBit(etdev,
TRUEPHY_BIT_READ, 5, 11,
&remote_async_pause);
if ((remote_pause == TRUEPHY_BIT_SET) &&
(remote_async_pause == TRUEPHY_BIT_SET)) {
etdev->flowcontrol = etdev->wanted_flow;
} else if ((remote_pause == TRUEPHY_BIT_SET) &&
(remote_async_pause == TRUEPHY_BIT_CLEAR)) {
if (etdev->wanted_flow == FLOW_BOTH)
etdev->flowcontrol = FLOW_BOTH;
else
etdev->flowcontrol = FLOW_NONE;
} else if ((remote_pause == TRUEPHY_BIT_CLEAR) &&
(remote_async_pause == TRUEPHY_BIT_CLEAR)) {
etdev->flowcontrol = FLOW_NONE;
} else {
if (etdev->wanted_flow == FLOW_BOTH)
etdev->flowcontrol = FLOW_RXONLY;
else
etdev->flowcontrol = FLOW_NONE;
}
}
}
void UpdateMacStatHostCounters(struct et131x_adapter *etdev)
{
struct ce_stats *stats = &etdev->stats;
struct macstat_regs __iomem *macstat =
&etdev->regs->macstat;
stats->collisions += readl(&macstat->tx_total_collisions);
stats->first_collision += readl(&macstat->tx_single_collisions);
stats->tx_deferred += readl(&macstat->tx_deferred);
stats->excessive_collisions += readl(&macstat->tx_multiple_collisions);
stats->late_collisions += readl(&macstat->tx_late_collisions);
stats->tx_uflo += readl(&macstat->tx_undersize_frames);
stats->max_pkt_error += readl(&macstat->tx_oversize_frames);
stats->alignment_err += readl(&macstat->rx_align_errs);
stats->crc_err += readl(&macstat->rx_code_errs);
stats->norcvbuf += readl(&macstat->rx_drops);
stats->rx_ov_flow += readl(&macstat->rx_oversize_packets);
stats->code_violations += readl(&macstat->rx_fcs_errs);
stats->length_err += readl(&macstat->rx_frame_len_errs);
stats->other_errors += readl(&macstat->rx_fragment_packets);
}
void HandleMacStatInterrupt(struct et131x_adapter *etdev)
{
u32 carry_reg1;
u32 carry_reg2;
carry_reg1 = readl(&etdev->regs->macstat.carry_reg1);
carry_reg2 = readl(&etdev->regs->macstat.carry_reg2);
writel(carry_reg2, &etdev->regs->macstat.carry_reg1);
writel(carry_reg2, &etdev->regs->macstat.carry_reg2);
if (carry_reg1 & (1 << 14))
etdev->stats.code_violations += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 8))
etdev->stats.alignment_err += COUNTER_WRAP_12_BIT;
if (carry_reg1 & (1 << 7))
etdev->stats.length_err += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 2))
etdev->stats.other_errors += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 6))
etdev->stats.crc_err += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 3))
etdev->stats.rx_ov_flow += COUNTER_WRAP_16_BIT;
if (carry_reg1 & (1 << 0))
etdev->stats.norcvbuf += COUNTER_WRAP_16_BIT;
if (carry_reg2 & (1 << 16))
etdev->stats.max_pkt_error += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 15))
etdev->stats.tx_uflo += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 6))
etdev->stats.first_collision += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 8))
etdev->stats.tx_deferred += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 5))
etdev->stats.excessive_collisions += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 4))
etdev->stats.late_collisions += COUNTER_WRAP_12_BIT;
if (carry_reg2 & (1 << 2))
etdev->stats.collisions += COUNTER_WRAP_12_BIT;
}
void SetupDeviceForMulticast(struct et131x_adapter *etdev)
{
struct rxmac_regs __iomem *rxmac = &etdev->regs->rxmac;
uint32_t nIndex;
uint32_t result;
uint32_t hash1 = 0;
uint32_t hash2 = 0;
uint32_t hash3 = 0;
uint32_t hash4 = 0;
u32 pm_csr;
if (etdev->PacketFilter & ET131X_PACKET_TYPE_MULTICAST) {
for (nIndex = 0; nIndex < etdev->MCAddressCount; nIndex++) {
result = ether_crc(6, etdev->MCList[nIndex]);
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
pm_csr = readl(&etdev->regs->global.pm_csr);
if ((pm_csr & ET_PM_PHY_SW_COMA) == 0) {
writel(hash1, &rxmac->multi_hash1);
writel(hash2, &rxmac->multi_hash2);
writel(hash3, &rxmac->multi_hash3);
writel(hash4, &rxmac->multi_hash4);
}
}
void SetupDeviceForUnicast(struct et131x_adapter *etdev)
{
struct rxmac_regs __iomem *rxmac = &etdev->regs->rxmac;
u32 uni_pf1;
u32 uni_pf2;
u32 uni_pf3;
u32 pm_csr;
uni_pf3 = (etdev->addr[0] << ET_UNI_PF_ADDR2_1_SHIFT) |
(etdev->addr[1] << ET_UNI_PF_ADDR2_2_SHIFT) |
(etdev->addr[0] << ET_UNI_PF_ADDR1_1_SHIFT) |
etdev->addr[1];
uni_pf2 = (etdev->addr[2] << ET_UNI_PF_ADDR2_3_SHIFT) |
(etdev->addr[3] << ET_UNI_PF_ADDR2_4_SHIFT) |
(etdev->addr[4] << ET_UNI_PF_ADDR2_5_SHIFT) |
etdev->addr[5];
uni_pf1 = (etdev->addr[2] << ET_UNI_PF_ADDR1_3_SHIFT) |
(etdev->addr[3] << ET_UNI_PF_ADDR1_4_SHIFT) |
(etdev->addr[4] << ET_UNI_PF_ADDR1_5_SHIFT) |
etdev->addr[5];
pm_csr = readl(&etdev->regs->global.pm_csr);
if ((pm_csr & ET_PM_PHY_SW_COMA) == 0) {
writel(uni_pf1, &rxmac->uni_pf_addr1);
writel(uni_pf2, &rxmac->uni_pf_addr2);
writel(uni_pf3, &rxmac->uni_pf_addr3);
}
}
