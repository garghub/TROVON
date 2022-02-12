void ConfigMACRegs1(struct et131x_adapter *etdev)
{
struct _MAC_t __iomem *pMac = &etdev->regs->mac;
MAC_STATION_ADDR1_t station1;
MAC_STATION_ADDR2_t station2;
u32 ipg;
writel(0xC00F0000, &pMac->cfg1);
ipg = 0x38005860;
ipg |= 0x50 << 8;
writel(ipg, &pMac->ipg);
writel(0x00A1F037, &pMac->hfdp);
writel(0, &pMac->if_ctrl);
writel(0x07, &pMac->mii_mgmt_cfg);
station2.bits.Octet1 = etdev->addr[0];
station2.bits.Octet2 = etdev->addr[1];
station1.bits.Octet3 = etdev->addr[2];
station1.bits.Octet4 = etdev->addr[3];
station1.bits.Octet5 = etdev->addr[4];
station1.bits.Octet6 = etdev->addr[5];
writel(station1.value, &pMac->station_addr_1.value);
writel(station2.value, &pMac->station_addr_2.value);
writel(etdev->RegistryJumboPacket + 4, &pMac->max_fm_len);
writel(0, &pMac->cfg1);
}
void ConfigMACRegs2(struct et131x_adapter *etdev)
{
int32_t delay = 0;
struct _MAC_t __iomem *pMac = &etdev->regs->mac;
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
if (etdev->Flags & fMP_ADAPTER_LOWER_POWER) {
et131x_rx_dma_enable(etdev);
et131x_tx_dma_enable(etdev);
}
}
void ConfigRxMacRegs(struct et131x_adapter *etdev)
{
struct _RXMAC_t __iomem *pRxMac = &etdev->regs->rxmac;
RXMAC_WOL_SA_LO_t sa_lo;
RXMAC_WOL_SA_HI_t sa_hi;
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
sa_lo.bits.sa3 = etdev->addr[2];
sa_lo.bits.sa4 = etdev->addr[3];
sa_lo.bits.sa5 = etdev->addr[4];
sa_lo.bits.sa6 = etdev->addr[5];
writel(sa_lo.value, &pRxMac->sa_lo.value);
sa_hi.bits.sa1 = etdev->addr[0];
sa_hi.bits.sa2 = etdev->addr[1];
writel(sa_hi.value, &pRxMac->sa_hi.value);
writel(0, &pRxMac->pf_ctrl);
if (etdev->PacketFilter & ET131X_PACKET_TYPE_DIRECTED) {
SetupDeviceForUnicast(etdev);
pf_ctrl |= 4;
} else {
writel(0, &pRxMac->uni_pf_addr1.value);
writel(0, &pRxMac->uni_pf_addr2.value);
writel(0, &pRxMac->uni_pf_addr3.value);
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
writel(0, &macstat->RFcs);
writel(0, &macstat->RAln);
writel(0, &macstat->RFlr);
writel(0, &macstat->RDrp);
writel(0, &macstat->RCde);
writel(0, &macstat->ROvr);
writel(0, &macstat->RFrg);
writel(0, &macstat->TScl);
writel(0, &macstat->TDfr);
writel(0, &macstat->TMcl);
writel(0, &macstat->TLcl);
writel(0, &macstat->TNcl);
writel(0, &macstat->TOvr);
writel(0, &macstat->TUnd);
writel(0xFFFFBE32, &macstat->Carry1M);
writel(0xFFFE7E8B, &macstat->Carry2M);
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
struct _ce_stats_t *stats = &etdev->Stats;
struct macstat_regs __iomem *macstat =
&etdev->regs->macstat;
stats->collisions += readl(&macstat->TNcl);
stats->first_collision += readl(&macstat->TScl);
stats->tx_deferred += readl(&macstat->TDfr);
stats->excessive_collisions += readl(&macstat->TMcl);
stats->late_collisions += readl(&macstat->TLcl);
stats->tx_uflo += readl(&macstat->TUnd);
stats->max_pkt_error += readl(&macstat->TOvr);
stats->alignment_err += readl(&macstat->RAln);
stats->crc_err += readl(&macstat->RCde);
stats->norcvbuf += readl(&macstat->RDrp);
stats->rx_ov_flow += readl(&macstat->ROvr);
stats->code_violations += readl(&macstat->RFcs);
stats->length_err += readl(&macstat->RFlr);
stats->other_errors += readl(&macstat->RFrg);
}
void HandleMacStatInterrupt(struct et131x_adapter *etdev)
{
u32 Carry1;
u32 Carry2;
Carry1 = readl(&etdev->regs->macstat.Carry1);
Carry2 = readl(&etdev->regs->macstat.Carry2);
writel(Carry1, &etdev->regs->macstat.Carry1);
writel(Carry2, &etdev->regs->macstat.Carry2);
if (Carry1 & (1 << 14))
etdev->Stats.code_violations += COUNTER_WRAP_16_BIT;
if (Carry1 & (1 << 8))
etdev->Stats.alignment_err += COUNTER_WRAP_12_BIT;
if (Carry1 & (1 << 7))
etdev->Stats.length_err += COUNTER_WRAP_16_BIT;
if (Carry1 & (1 << 2))
etdev->Stats.other_errors += COUNTER_WRAP_16_BIT;
if (Carry1 & (1 << 6))
etdev->Stats.crc_err += COUNTER_WRAP_16_BIT;
if (Carry1 & (1 << 3))
etdev->Stats.rx_ov_flow += COUNTER_WRAP_16_BIT;
if (Carry1 & (1 << 0))
etdev->Stats.norcvbuf += COUNTER_WRAP_16_BIT;
if (Carry2 & (1 << 16))
etdev->Stats.max_pkt_error += COUNTER_WRAP_12_BIT;
if (Carry2 & (1 << 15))
etdev->Stats.tx_uflo += COUNTER_WRAP_12_BIT;
if (Carry2 & (1 << 6))
etdev->Stats.first_collision += COUNTER_WRAP_12_BIT;
if (Carry2 & (1 << 8))
etdev->Stats.tx_deferred += COUNTER_WRAP_12_BIT;
if (Carry2 & (1 << 5))
etdev->Stats.excessive_collisions += COUNTER_WRAP_12_BIT;
if (Carry2 & (1 << 4))
etdev->Stats.late_collisions += COUNTER_WRAP_12_BIT;
if (Carry2 & (1 << 2))
etdev->Stats.collisions += COUNTER_WRAP_12_BIT;
}
void SetupDeviceForMulticast(struct et131x_adapter *etdev)
{
struct _RXMAC_t __iomem *rxmac = &etdev->regs->rxmac;
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
struct _RXMAC_t __iomem *rxmac = &etdev->regs->rxmac;
RXMAC_UNI_PF_ADDR1_t uni_pf1;
RXMAC_UNI_PF_ADDR2_t uni_pf2;
RXMAC_UNI_PF_ADDR3_t uni_pf3;
u32 pm_csr;
uni_pf3.bits.addr1_1 = etdev->addr[0];
uni_pf3.bits.addr1_2 = etdev->addr[1];
uni_pf3.bits.addr2_1 = etdev->addr[0];
uni_pf3.bits.addr2_2 = etdev->addr[1];
uni_pf2.bits.addr2_3 = etdev->addr[2];
uni_pf2.bits.addr2_4 = etdev->addr[3];
uni_pf2.bits.addr2_5 = etdev->addr[4];
uni_pf2.bits.addr2_6 = etdev->addr[5];
uni_pf1.bits.addr1_3 = etdev->addr[2];
uni_pf1.bits.addr1_4 = etdev->addr[3];
uni_pf1.bits.addr1_5 = etdev->addr[4];
uni_pf1.bits.addr1_6 = etdev->addr[5];
pm_csr = readl(&etdev->regs->global.pm_csr);
if ((pm_csr & ET_PM_PHY_SW_COMA) == 0) {
writel(uni_pf1.value, &rxmac->uni_pf_addr1.value);
writel(uni_pf2.value, &rxmac->uni_pf_addr2.value);
writel(uni_pf3.value, &rxmac->uni_pf_addr3.value);
}
}
