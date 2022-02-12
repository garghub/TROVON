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
value &= ~DMA_AXI_WR_OSR_LMT;
value |= (axi->axi_wr_osr_lmt & DMA_AXI_OSR_MAX) <<
DMA_AXI_WR_OSR_LMT_SHIFT;
value &= ~DMA_AXI_RD_OSR_LMT;
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
void dwmac4_dma_init_rx_chan(void __iomem *ioaddr,
struct stmmac_dma_cfg *dma_cfg,
u32 dma_rx_phy, u32 chan)
{
u32 value;
u32 rxpbl = dma_cfg->rxpbl ?: dma_cfg->pbl;
value = readl(ioaddr + DMA_CHAN_RX_CONTROL(chan));
value = value | (rxpbl << DMA_BUS_MODE_RPBL_SHIFT);
writel(value, ioaddr + DMA_CHAN_RX_CONTROL(chan));
writel(dma_rx_phy, ioaddr + DMA_CHAN_RX_BASE_ADDR(chan));
}
void dwmac4_dma_init_tx_chan(void __iomem *ioaddr,
struct stmmac_dma_cfg *dma_cfg,
u32 dma_tx_phy, u32 chan)
{
u32 value;
u32 txpbl = dma_cfg->txpbl ?: dma_cfg->pbl;
value = readl(ioaddr + DMA_CHAN_TX_CONTROL(chan));
value = value | (txpbl << DMA_BUS_MODE_PBL_SHIFT);
writel(value, ioaddr + DMA_CHAN_TX_CONTROL(chan));
writel(dma_tx_phy, ioaddr + DMA_CHAN_TX_BASE_ADDR(chan));
}
void dwmac4_dma_init_channel(void __iomem *ioaddr,
struct stmmac_dma_cfg *dma_cfg, u32 chan)
{
u32 value;
value = readl(ioaddr + DMA_CHAN_CONTROL(chan));
if (dma_cfg->pblx8)
value = value | DMA_BUS_MODE_PBL;
writel(value, ioaddr + DMA_CHAN_CONTROL(chan));
writel(DMA_CHAN_INTR_DEFAULT_MASK,
ioaddr + DMA_CHAN_INTR_ENA(chan));
}
static void dwmac4_dma_init(void __iomem *ioaddr,
struct stmmac_dma_cfg *dma_cfg,
u32 dma_tx, u32 dma_rx, int atds)
{
u32 value = readl(ioaddr + DMA_SYS_BUS_MODE);
if (dma_cfg->fixed_burst)
value |= DMA_SYS_BUS_FB;
if (dma_cfg->mixed_burst)
value |= DMA_SYS_BUS_MB;
if (dma_cfg->aal)
value |= DMA_SYS_BUS_AAL;
writel(value, ioaddr + DMA_SYS_BUS_MODE);
}
static void _dwmac4_dump_dma_regs(void __iomem *ioaddr, u32 channel,
u32 *reg_space)
{
reg_space[DMA_CHAN_CONTROL(channel) / 4] =
readl(ioaddr + DMA_CHAN_CONTROL(channel));
reg_space[DMA_CHAN_TX_CONTROL(channel) / 4] =
readl(ioaddr + DMA_CHAN_TX_CONTROL(channel));
reg_space[DMA_CHAN_RX_CONTROL(channel) / 4] =
readl(ioaddr + DMA_CHAN_RX_CONTROL(channel));
reg_space[DMA_CHAN_TX_BASE_ADDR(channel) / 4] =
readl(ioaddr + DMA_CHAN_TX_BASE_ADDR(channel));
reg_space[DMA_CHAN_RX_BASE_ADDR(channel) / 4] =
readl(ioaddr + DMA_CHAN_RX_BASE_ADDR(channel));
reg_space[DMA_CHAN_TX_END_ADDR(channel) / 4] =
readl(ioaddr + DMA_CHAN_TX_END_ADDR(channel));
reg_space[DMA_CHAN_RX_END_ADDR(channel) / 4] =
readl(ioaddr + DMA_CHAN_RX_END_ADDR(channel));
reg_space[DMA_CHAN_TX_RING_LEN(channel) / 4] =
readl(ioaddr + DMA_CHAN_TX_RING_LEN(channel));
reg_space[DMA_CHAN_RX_RING_LEN(channel) / 4] =
readl(ioaddr + DMA_CHAN_RX_RING_LEN(channel));
reg_space[DMA_CHAN_INTR_ENA(channel) / 4] =
readl(ioaddr + DMA_CHAN_INTR_ENA(channel));
reg_space[DMA_CHAN_RX_WATCHDOG(channel) / 4] =
readl(ioaddr + DMA_CHAN_RX_WATCHDOG(channel));
reg_space[DMA_CHAN_SLOT_CTRL_STATUS(channel) / 4] =
readl(ioaddr + DMA_CHAN_SLOT_CTRL_STATUS(channel));
reg_space[DMA_CHAN_CUR_TX_DESC(channel) / 4] =
readl(ioaddr + DMA_CHAN_CUR_TX_DESC(channel));
reg_space[DMA_CHAN_CUR_RX_DESC(channel) / 4] =
readl(ioaddr + DMA_CHAN_CUR_RX_DESC(channel));
reg_space[DMA_CHAN_CUR_TX_BUF_ADDR(channel) / 4] =
readl(ioaddr + DMA_CHAN_CUR_TX_BUF_ADDR(channel));
reg_space[DMA_CHAN_CUR_RX_BUF_ADDR(channel) / 4] =
readl(ioaddr + DMA_CHAN_CUR_RX_BUF_ADDR(channel));
reg_space[DMA_CHAN_STATUS(channel) / 4] =
readl(ioaddr + DMA_CHAN_STATUS(channel));
}
static void dwmac4_dump_dma_regs(void __iomem *ioaddr, u32 *reg_space)
{
int i;
for (i = 0; i < DMA_CHANNEL_NB_MAX; i++)
_dwmac4_dump_dma_regs(ioaddr, i, reg_space);
}
static void dwmac4_rx_watchdog(void __iomem *ioaddr, u32 riwt, u32 number_chan)
{
u32 chan;
for (chan = 0; chan < number_chan; chan++)
writel(riwt, ioaddr + DMA_CHAN_RX_WATCHDOG(chan));
}
static void dwmac4_dma_rx_chan_op_mode(void __iomem *ioaddr, int mode,
u32 channel, int fifosz)
{
unsigned int rqs = fifosz / 256 - 1;
u32 mtl_rx_op, mtl_rx_int;
mtl_rx_op = readl(ioaddr + MTL_CHAN_RX_OP_MODE(channel));
if (mode == SF_DMA_MODE) {
pr_debug("GMAC: enable RX store and forward mode\n");
mtl_rx_op |= MTL_OP_MODE_RSF;
} else {
pr_debug("GMAC: disable RX SF mode (threshold %d)\n", mode);
mtl_rx_op &= ~MTL_OP_MODE_RSF;
mtl_rx_op &= MTL_OP_MODE_RTC_MASK;
if (mode <= 32)
mtl_rx_op |= MTL_OP_MODE_RTC_32;
else if (mode <= 64)
mtl_rx_op |= MTL_OP_MODE_RTC_64;
else if (mode <= 96)
mtl_rx_op |= MTL_OP_MODE_RTC_96;
else
mtl_rx_op |= MTL_OP_MODE_RTC_128;
}
mtl_rx_op &= ~MTL_OP_MODE_RQS_MASK;
mtl_rx_op |= rqs << MTL_OP_MODE_RQS_SHIFT;
if (fifosz >= 4096) {
unsigned int rfd, rfa;
mtl_rx_op |= MTL_OP_MODE_EHFC;
switch (fifosz) {
case 4096:
rfd = 0x03;
rfa = 0x01;
break;
case 8192:
rfd = 0x06;
rfa = 0x0a;
break;
case 16384:
rfd = 0x06;
rfa = 0x12;
break;
default:
rfd = 0x06;
rfa = 0x1e;
break;
}
mtl_rx_op &= ~MTL_OP_MODE_RFD_MASK;
mtl_rx_op |= rfd << MTL_OP_MODE_RFD_SHIFT;
mtl_rx_op &= ~MTL_OP_MODE_RFA_MASK;
mtl_rx_op |= rfa << MTL_OP_MODE_RFA_SHIFT;
}
writel(mtl_rx_op, ioaddr + MTL_CHAN_RX_OP_MODE(channel));
mtl_rx_int = readl(ioaddr + MTL_CHAN_INT_CTRL(channel));
writel(mtl_rx_int | MTL_RX_OVERFLOW_INT_EN,
ioaddr + MTL_CHAN_INT_CTRL(channel));
}
static void dwmac4_dma_tx_chan_op_mode(void __iomem *ioaddr, int mode,
u32 channel)
{
u32 mtl_tx_op = readl(ioaddr + MTL_CHAN_TX_OP_MODE(channel));
if (mode == SF_DMA_MODE) {
pr_debug("GMAC: enable TX store and forward mode\n");
mtl_tx_op |= MTL_OP_MODE_TSF;
} else {
pr_debug("GMAC: disabling TX SF (threshold %d)\n", mode);
mtl_tx_op &= ~MTL_OP_MODE_TSF;
mtl_tx_op &= MTL_OP_MODE_TTC_MASK;
if (mode <= 32)
mtl_tx_op |= MTL_OP_MODE_TTC_32;
else if (mode <= 64)
mtl_tx_op |= MTL_OP_MODE_TTC_64;
else if (mode <= 96)
mtl_tx_op |= MTL_OP_MODE_TTC_96;
else if (mode <= 128)
mtl_tx_op |= MTL_OP_MODE_TTC_128;
else if (mode <= 192)
mtl_tx_op |= MTL_OP_MODE_TTC_192;
else if (mode <= 256)
mtl_tx_op |= MTL_OP_MODE_TTC_256;
else if (mode <= 384)
mtl_tx_op |= MTL_OP_MODE_TTC_384;
else
mtl_tx_op |= MTL_OP_MODE_TTC_512;
}
mtl_tx_op |= MTL_OP_MODE_TXQEN | MTL_OP_MODE_TQS_MASK;
writel(mtl_tx_op, ioaddr + MTL_CHAN_TX_OP_MODE(channel));
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
dma_cap->tx_fifo_size = 128 << ((hw_cap & GMAC_HW_TXFIFOSIZE) >> 6);
dma_cap->rx_fifo_size = 128 << ((hw_cap & GMAC_HW_RXFIFOSIZE) >> 0);
hw_cap = readl(ioaddr + GMAC_HW_FEATURE2);
dma_cap->number_rx_channel =
((hw_cap & GMAC_HW_FEAT_RXCHCNT) >> 12) + 1;
dma_cap->number_tx_channel =
((hw_cap & GMAC_HW_FEAT_TXCHCNT) >> 18) + 1;
dma_cap->number_rx_queues =
((hw_cap & GMAC_HW_FEAT_RXQCNT) >> 0) + 1;
dma_cap->number_tx_queues =
((hw_cap & GMAC_HW_FEAT_TXQCNT) >> 6) + 1;
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
