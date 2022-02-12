static void dwmac1000_dma_axi(void __iomem *ioaddr, struct stmmac_axi *axi)
{
u32 value = readl(ioaddr + DMA_AXI_BUS_MODE);
int i;
pr_info("dwmac1000: Master AXI performs %s burst length\n",
!(value & DMA_AXI_UNDEF) ? "fixed" : "any");
if (axi->axi_lpi_en)
value |= DMA_AXI_EN_LPI;
if (axi->axi_xit_frm)
value |= DMA_AXI_LPI_XIT_FRM;
value &= ~DMA_AXI_WR_OSR_LMT;
value |= (axi->axi_wr_osr_lmt & DMA_AXI_WR_OSR_LMT_MASK) <<
DMA_AXI_WR_OSR_LMT_SHIFT;
value &= ~DMA_AXI_RD_OSR_LMT;
value |= (axi->axi_rd_osr_lmt & DMA_AXI_RD_OSR_LMT_MASK) <<
DMA_AXI_RD_OSR_LMT_SHIFT;
for (i = 0; i < AXI_BLEN; i++) {
switch (axi->axi_blen[i]) {
case 256:
value |= DMA_AXI_BLEN256;
break;
case 128:
value |= DMA_AXI_BLEN128;
break;
case 64:
value |= DMA_AXI_BLEN64;
break;
case 32:
value |= DMA_AXI_BLEN32;
break;
case 16:
value |= DMA_AXI_BLEN16;
break;
case 8:
value |= DMA_AXI_BLEN8;
break;
case 4:
value |= DMA_AXI_BLEN4;
break;
}
}
writel(value, ioaddr + DMA_AXI_BUS_MODE);
}
static void dwmac1000_dma_init(void __iomem *ioaddr, int pbl, int fb, int mb,
int aal, u32 dma_tx, u32 dma_rx, int atds)
{
u32 value = readl(ioaddr + DMA_BUS_MODE);
value |= DMA_BUS_MODE_MAXPBL;
value &= ~DMA_BUS_MODE_PBL_MASK;
value |= (pbl << DMA_BUS_MODE_PBL_SHIFT);
if (fb)
value |= DMA_BUS_MODE_FB;
if (mb)
value |= DMA_BUS_MODE_MB;
if (atds)
value |= DMA_BUS_MODE_ATDS;
if (aal)
value |= DMA_BUS_MODE_AAL;
writel(value, ioaddr + DMA_BUS_MODE);
writel(DMA_INTR_DEFAULT_MASK, ioaddr + DMA_INTR_ENA);
writel(dma_tx, ioaddr + DMA_TX_BASE_ADDR);
writel(dma_rx, ioaddr + DMA_RCV_BASE_ADDR);
}
static u32 dwmac1000_configure_fc(u32 csr6, int rxfifosz)
{
csr6 &= ~DMA_CONTROL_RFA_MASK;
csr6 &= ~DMA_CONTROL_RFD_MASK;
if (rxfifosz < 4096) {
csr6 &= ~DMA_CONTROL_EFC;
pr_debug("GMAC: disabling flow control, rxfifo too small(%d)\n",
rxfifosz);
} else {
csr6 |= DMA_CONTROL_EFC;
csr6 |= RFA_FULL_MINUS_1K;
csr6 |= RFD_FULL_MINUS_2K;
}
return csr6;
}
static void dwmac1000_dma_operation_mode(void __iomem *ioaddr, int txmode,
int rxmode, int rxfifosz)
{
u32 csr6 = readl(ioaddr + DMA_CONTROL);
if (txmode == SF_DMA_MODE) {
pr_debug("GMAC: enable TX store and forward mode\n");
csr6 |= DMA_CONTROL_TSF;
csr6 |= DMA_CONTROL_OSF;
} else {
pr_debug("GMAC: disabling TX SF (threshold %d)\n", txmode);
csr6 &= ~DMA_CONTROL_TSF;
csr6 &= DMA_CONTROL_TC_TX_MASK;
if (txmode <= 32)
csr6 |= DMA_CONTROL_TTC_32;
else if (txmode <= 64)
csr6 |= DMA_CONTROL_TTC_64;
else if (txmode <= 128)
csr6 |= DMA_CONTROL_TTC_128;
else if (txmode <= 192)
csr6 |= DMA_CONTROL_TTC_192;
else
csr6 |= DMA_CONTROL_TTC_256;
}
if (rxmode == SF_DMA_MODE) {
pr_debug("GMAC: enable RX store and forward mode\n");
csr6 |= DMA_CONTROL_RSF;
} else {
pr_debug("GMAC: disable RX SF mode (threshold %d)\n", rxmode);
csr6 &= ~DMA_CONTROL_RSF;
csr6 &= DMA_CONTROL_TC_RX_MASK;
if (rxmode <= 32)
csr6 |= DMA_CONTROL_RTC_32;
else if (rxmode <= 64)
csr6 |= DMA_CONTROL_RTC_64;
else if (rxmode <= 96)
csr6 |= DMA_CONTROL_RTC_96;
else
csr6 |= DMA_CONTROL_RTC_128;
}
csr6 = dwmac1000_configure_fc(csr6, rxfifosz);
writel(csr6, ioaddr + DMA_CONTROL);
}
static void dwmac1000_dump_dma_regs(void __iomem *ioaddr)
{
int i;
pr_info(" DMA registers\n");
for (i = 0; i < 22; i++) {
if ((i < 9) || (i > 17)) {
int offset = i * 4;
pr_err("\t Reg No. %d (offset 0x%x): 0x%08x\n", i,
(DMA_BUS_MODE + offset),
readl(ioaddr + DMA_BUS_MODE + offset));
}
}
}
static void dwmac1000_get_hw_feature(void __iomem *ioaddr,
struct dma_features *dma_cap)
{
u32 hw_cap = readl(ioaddr + DMA_HW_FEATURE);
dma_cap->mbps_10_100 = (hw_cap & DMA_HW_FEAT_MIISEL);
dma_cap->mbps_1000 = (hw_cap & DMA_HW_FEAT_GMIISEL) >> 1;
dma_cap->half_duplex = (hw_cap & DMA_HW_FEAT_HDSEL) >> 2;
dma_cap->hash_filter = (hw_cap & DMA_HW_FEAT_HASHSEL) >> 4;
dma_cap->multi_addr = (hw_cap & DMA_HW_FEAT_ADDMAC) >> 5;
dma_cap->pcs = (hw_cap & DMA_HW_FEAT_PCSSEL) >> 6;
dma_cap->sma_mdio = (hw_cap & DMA_HW_FEAT_SMASEL) >> 8;
dma_cap->pmt_remote_wake_up = (hw_cap & DMA_HW_FEAT_RWKSEL) >> 9;
dma_cap->pmt_magic_frame = (hw_cap & DMA_HW_FEAT_MGKSEL) >> 10;
dma_cap->rmon = (hw_cap & DMA_HW_FEAT_MMCSEL) >> 11;
dma_cap->time_stamp =
(hw_cap & DMA_HW_FEAT_TSVER1SEL) >> 12;
dma_cap->atime_stamp = (hw_cap & DMA_HW_FEAT_TSVER2SEL) >> 13;
dma_cap->eee = (hw_cap & DMA_HW_FEAT_EEESEL) >> 14;
dma_cap->av = (hw_cap & DMA_HW_FEAT_AVSEL) >> 15;
dma_cap->tx_coe = (hw_cap & DMA_HW_FEAT_TXCOESEL) >> 16;
dma_cap->rx_coe_type1 = (hw_cap & DMA_HW_FEAT_RXTYP1COE) >> 17;
dma_cap->rx_coe_type2 = (hw_cap & DMA_HW_FEAT_RXTYP2COE) >> 18;
dma_cap->rxfifo_over_2048 = (hw_cap & DMA_HW_FEAT_RXFIFOSIZE) >> 19;
dma_cap->number_rx_channel = (hw_cap & DMA_HW_FEAT_RXCHCNT) >> 20;
dma_cap->number_tx_channel = (hw_cap & DMA_HW_FEAT_TXCHCNT) >> 22;
dma_cap->enh_desc = (hw_cap & DMA_HW_FEAT_ENHDESSEL) >> 24;
}
static void dwmac1000_rx_watchdog(void __iomem *ioaddr, u32 riwt)
{
writel(riwt, ioaddr + DMA_RX_WATCHDOG);
}
