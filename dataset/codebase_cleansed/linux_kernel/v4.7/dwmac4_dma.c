static void dwmac4_dma_axi(void __iomem *ioaddr, struct stmmac_axi *axi)
{
u32 value = readl(ioaddr + DMA_SYS_BUS_MODE);
int i;
pr_info("dwmac4: Master AXI performs %s burst length\n",
(value & DMA_SYS_BUS_FB) ? "fixed" : "any");
if (axi->axi_lpi_en)
value |= DMA_AXI_EN_LPI;
if (axi->axi_xit_frm)
value |= DMA_AXI_LPI_XIT_FRM;
value |= (axi->axi_wr_osr_lmt & DMA_AXI_OSR_MAX) <<
DMA_AXI_WR_OSR_LMT_SHIFT;
value |= (axi->axi_rd_osr_lmt & DMA_AXI_OSR_MAX) <<
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
writel(value, ioaddr + DMA_SYS_BUS_MODE);
}
static void dwmac4_dma_init_channel(void __iomem *ioaddr, int pbl,
u32 dma_tx_phy, u32 dma_rx_phy,
u32 channel)
{
u32 value;
value = readl(ioaddr + DMA_CHAN_CONTROL(channel));
value = value | DMA_BUS_MODE_PBL;
writel(value, ioaddr + DMA_CHAN_CONTROL(channel));
value = readl(ioaddr + DMA_CHAN_TX_CONTROL(channel));
value = value | (pbl << DMA_BUS_MODE_PBL_SHIFT);
writel(value, ioaddr + DMA_CHAN_TX_CONTROL(channel));
value = readl(ioaddr + DMA_CHAN_RX_CONTROL(channel));
value = value | (pbl << DMA_BUS_MODE_RPBL_SHIFT);
writel(value, ioaddr + DMA_CHAN_RX_CONTROL(channel));
writel(DMA_CHAN_INTR_DEFAULT_MASK, ioaddr + DMA_CHAN_INTR_ENA(channel));
writel(dma_tx_phy, ioaddr + DMA_CHAN_TX_BASE_ADDR(channel));
writel(dma_rx_phy, ioaddr + DMA_CHAN_RX_BASE_ADDR(channel));
}
static void dwmac4_dma_init(void __iomem *ioaddr, int pbl, int fb, int mb,
int aal, u32 dma_tx, u32 dma_rx, int atds)
{
u32 value = readl(ioaddr + DMA_SYS_BUS_MODE);
int i;
if (fb)
value |= DMA_SYS_BUS_FB;
if (mb)
value |= DMA_SYS_BUS_MB;
if (aal)
value |= DMA_SYS_BUS_AAL;
writel(value, ioaddr + DMA_SYS_BUS_MODE);
for (i = 0; i < DMA_CHANNEL_NB_MAX; i++)
dwmac4_dma_init_channel(ioaddr, pbl, dma_tx, dma_rx, i);
}
static void _dwmac4_dump_dma_regs(void __iomem *ioaddr, u32 channel)
{
pr_debug(" Channel %d\n", channel);
pr_debug("\tDMA_CHAN_CONTROL, offset: 0x%x, val: 0x%x\n", 0,
readl(ioaddr + DMA_CHAN_CONTROL(channel)));
pr_debug("\tDMA_CHAN_TX_CONTROL, offset: 0x%x, val: 0x%x\n", 0x4,
readl(ioaddr + DMA_CHAN_TX_CONTROL(channel)));
pr_debug("\tDMA_CHAN_RX_CONTROL, offset: 0x%x, val: 0x%x\n", 0x8,
readl(ioaddr + DMA_CHAN_RX_CONTROL(channel)));
pr_debug("\tDMA_CHAN_TX_BASE_ADDR, offset: 0x%x, val: 0x%x\n", 0x14,
readl(ioaddr + DMA_CHAN_TX_BASE_ADDR(channel)));
pr_debug("\tDMA_CHAN_RX_BASE_ADDR, offset: 0x%x, val: 0x%x\n", 0x1c,
readl(ioaddr + DMA_CHAN_RX_BASE_ADDR(channel)));
pr_debug("\tDMA_CHAN_TX_END_ADDR, offset: 0x%x, val: 0x%x\n", 0x20,
readl(ioaddr + DMA_CHAN_TX_END_ADDR(channel)));
pr_debug("\tDMA_CHAN_RX_END_ADDR, offset: 0x%x, val: 0x%x\n", 0x28,
readl(ioaddr + DMA_CHAN_RX_END_ADDR(channel)));
pr_debug("\tDMA_CHAN_TX_RING_LEN, offset: 0x%x, val: 0x%x\n", 0x2c,
readl(ioaddr + DMA_CHAN_TX_RING_LEN(channel)));
pr_debug("\tDMA_CHAN_RX_RING_LEN, offset: 0x%x, val: 0x%x\n", 0x30,
readl(ioaddr + DMA_CHAN_RX_RING_LEN(channel)));
pr_debug("\tDMA_CHAN_INTR_ENA, offset: 0x%x, val: 0x%x\n", 0x34,
readl(ioaddr + DMA_CHAN_INTR_ENA(channel)));
pr_debug("\tDMA_CHAN_RX_WATCHDOG, offset: 0x%x, val: 0x%x\n", 0x38,
readl(ioaddr + DMA_CHAN_RX_WATCHDOG(channel)));
pr_debug("\tDMA_CHAN_SLOT_CTRL_STATUS, offset: 0x%x, val: 0x%x\n", 0x3c,
readl(ioaddr + DMA_CHAN_SLOT_CTRL_STATUS(channel)));
pr_debug("\tDMA_CHAN_CUR_TX_DESC, offset: 0x%x, val: 0x%x\n", 0x44,
readl(ioaddr + DMA_CHAN_CUR_TX_DESC(channel)));
pr_debug("\tDMA_CHAN_CUR_RX_DESC, offset: 0x%x, val: 0x%x\n", 0x4c,
readl(ioaddr + DMA_CHAN_CUR_RX_DESC(channel)));
pr_debug("\tDMA_CHAN_CUR_TX_BUF_ADDR, offset: 0x%x, val: 0x%x\n", 0x54,
readl(ioaddr + DMA_CHAN_CUR_TX_BUF_ADDR(channel)));
pr_debug("\tDMA_CHAN_CUR_RX_BUF_ADDR, offset: 0x%x, val: 0x%x\n", 0x5c,
readl(ioaddr + DMA_CHAN_CUR_RX_BUF_ADDR(channel)));
pr_debug("\tDMA_CHAN_STATUS, offset: 0x%x, val: 0x%x\n", 0x60,
readl(ioaddr + DMA_CHAN_STATUS(channel)));
}
static void dwmac4_dump_dma_regs(void __iomem *ioaddr)
{
int i;
pr_debug(" GMAC4 DMA registers\n");
for (i = 0; i < DMA_CHANNEL_NB_MAX; i++)
_dwmac4_dump_dma_regs(ioaddr, i);
}
static void dwmac4_rx_watchdog(void __iomem *ioaddr, u32 riwt)
{
int i;
for (i = 0; i < DMA_CHANNEL_NB_MAX; i++)
writel(riwt, ioaddr + DMA_CHAN_RX_WATCHDOG(i));
}
static void dwmac4_dma_chan_op_mode(void __iomem *ioaddr, int txmode,
int rxmode, u32 channel)
{
u32 mtl_tx_op, mtl_rx_op, mtl_rx_int;
mtl_tx_op = readl(ioaddr + MTL_CHAN_TX_OP_MODE(channel));
if (txmode == SF_DMA_MODE) {
pr_debug("GMAC: enable TX store and forward mode\n");
mtl_tx_op |= MTL_OP_MODE_TSF;
} else {
pr_debug("GMAC: disabling TX SF (threshold %d)\n", txmode);
mtl_tx_op &= ~MTL_OP_MODE_TSF;
mtl_tx_op &= MTL_OP_MODE_TTC_MASK;
if (txmode <= 32)
mtl_tx_op |= MTL_OP_MODE_TTC_32;
else if (txmode <= 64)
mtl_tx_op |= MTL_OP_MODE_TTC_64;
else if (txmode <= 96)
mtl_tx_op |= MTL_OP_MODE_TTC_96;
else if (txmode <= 128)
mtl_tx_op |= MTL_OP_MODE_TTC_128;
else if (txmode <= 192)
mtl_tx_op |= MTL_OP_MODE_TTC_192;
else if (txmode <= 256)
mtl_tx_op |= MTL_OP_MODE_TTC_256;
else if (txmode <= 384)
mtl_tx_op |= MTL_OP_MODE_TTC_384;
else
mtl_tx_op |= MTL_OP_MODE_TTC_512;
}
writel(mtl_tx_op, ioaddr + MTL_CHAN_TX_OP_MODE(channel));
mtl_rx_op = readl(ioaddr + MTL_CHAN_RX_OP_MODE(channel));
if (rxmode == SF_DMA_MODE) {
pr_debug("GMAC: enable RX store and forward mode\n");
mtl_rx_op |= MTL_OP_MODE_RSF;
} else {
pr_debug("GMAC: disable RX SF mode (threshold %d)\n", rxmode);
mtl_rx_op &= ~MTL_OP_MODE_RSF;
mtl_rx_op &= MTL_OP_MODE_RTC_MASK;
if (rxmode <= 32)
mtl_rx_op |= MTL_OP_MODE_RTC_32;
else if (rxmode <= 64)
mtl_rx_op |= MTL_OP_MODE_RTC_64;
else if (rxmode <= 96)
mtl_rx_op |= MTL_OP_MODE_RTC_96;
else
mtl_rx_op |= MTL_OP_MODE_RTC_128;
}
writel(mtl_rx_op, ioaddr + MTL_CHAN_RX_OP_MODE(channel));
mtl_rx_int = readl(ioaddr + MTL_CHAN_INT_CTRL(channel));
writel(mtl_rx_int | MTL_RX_OVERFLOW_INT_EN,
ioaddr + MTL_CHAN_INT_CTRL(channel));
}
static void dwmac4_dma_operation_mode(void __iomem *ioaddr, int txmode,
int rxmode, int rxfifosz)
{
dwmac4_dma_chan_op_mode(ioaddr, txmode, rxmode, 0);
}
static void dwmac4_get_hw_feature(void __iomem *ioaddr,
struct dma_features *dma_cap)
{
u32 hw_cap = readl(ioaddr + GMAC_HW_FEATURE0);
dma_cap->mbps_10_100 = (hw_cap & GMAC_HW_FEAT_MIISEL);
dma_cap->mbps_1000 = (hw_cap & GMAC_HW_FEAT_GMIISEL) >> 1;
dma_cap->half_duplex = (hw_cap & GMAC_HW_FEAT_HDSEL) >> 2;
dma_cap->hash_filter = (hw_cap & GMAC_HW_FEAT_VLHASH) >> 4;
dma_cap->multi_addr = (hw_cap & GMAC_HW_FEAT_ADDMAC) >> 18;
dma_cap->pcs = (hw_cap & GMAC_HW_FEAT_PCSSEL) >> 3;
dma_cap->sma_mdio = (hw_cap & GMAC_HW_FEAT_SMASEL) >> 5;
dma_cap->pmt_remote_wake_up = (hw_cap & GMAC_HW_FEAT_RWKSEL) >> 6;
dma_cap->pmt_magic_frame = (hw_cap & GMAC_HW_FEAT_MGKSEL) >> 7;
dma_cap->rmon = (hw_cap & GMAC_HW_FEAT_MMCSEL) >> 8;
dma_cap->atime_stamp = (hw_cap & GMAC_HW_FEAT_TSSEL) >> 12;
dma_cap->eee = (hw_cap & GMAC_HW_FEAT_EEESEL) >> 13;
dma_cap->tx_coe = (hw_cap & GMAC_HW_FEAT_TXCOSEL) >> 14;
dma_cap->rx_coe = (hw_cap & GMAC_HW_FEAT_RXCOESEL) >> 16;
hw_cap = readl(ioaddr + GMAC_HW_FEATURE1);
dma_cap->av = (hw_cap & GMAC_HW_FEAT_AVSEL) >> 20;
dma_cap->tsoen = (hw_cap & GMAC_HW_TSOEN) >> 18;
hw_cap = readl(ioaddr + GMAC_HW_FEATURE2);
dma_cap->number_rx_channel =
((hw_cap & GMAC_HW_FEAT_RXCHCNT) >> 12) + 1;
dma_cap->number_tx_channel =
((hw_cap & GMAC_HW_FEAT_TXCHCNT) >> 18) + 1;
dma_cap->time_stamp = 0;
}
static void dwmac4_enable_tso(void __iomem *ioaddr, bool en, u32 chan)
{
u32 value;
if (en) {
value = readl(ioaddr + DMA_CHAN_TX_CONTROL(chan));
writel(value | DMA_CONTROL_TSE,
ioaddr + DMA_CHAN_TX_CONTROL(chan));
} else {
value = readl(ioaddr + DMA_CHAN_TX_CONTROL(chan));
writel(value & ~DMA_CONTROL_TSE,
ioaddr + DMA_CHAN_TX_CONTROL(chan));
}
}
