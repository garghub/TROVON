static void sxgbe_mtl_init(void __iomem *ioaddr, unsigned int etsalg,
unsigned int raa)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_OP_MODE_REG);
reg_val &= ETS_RST;
switch (etsalg & SXGBE_MTL_OPMODE_ESTMASK) {
case ETS_WRR:
reg_val &= ETS_WRR;
break;
case ETS_WFQ:
reg_val |= ETS_WFQ;
break;
case ETS_DWRR:
reg_val |= ETS_DWRR;
break;
}
writel(reg_val, ioaddr + SXGBE_MTL_OP_MODE_REG);
switch (raa & SXGBE_MTL_OPMODE_RAAMASK) {
case RAA_SP:
reg_val &= RAA_SP;
break;
case RAA_WSP:
reg_val |= RAA_WSP;
break;
}
writel(reg_val, ioaddr + SXGBE_MTL_OP_MODE_REG);
}
static void sxgbe_mtl_dma_dm_rxqueue(void __iomem *ioaddr)
{
writel(RX_QUEUE_DYNAMIC, ioaddr + SXGBE_MTL_RXQ_DMAMAP0_REG);
writel(RX_QUEUE_DYNAMIC, ioaddr + SXGBE_MTL_RXQ_DMAMAP1_REG);
writel(RX_QUEUE_DYNAMIC, ioaddr + SXGBE_MTL_RXQ_DMAMAP2_REG);
}
static void sxgbe_mtl_set_txfifosize(void __iomem *ioaddr, int queue_num,
int queue_fifo)
{
u32 fifo_bits, reg_val;
fifo_bits = (queue_fifo / SXGBE_MTL_TX_FIFO_DIV) - 1;
reg_val = readl(ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
reg_val |= (fifo_bits << SXGBE_MTL_FIFO_LSHIFT);
writel(reg_val, ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_set_rxfifosize(void __iomem *ioaddr, int queue_num,
int queue_fifo)
{
u32 fifo_bits, reg_val;
fifo_bits = (queue_fifo / SXGBE_MTL_RX_FIFO_DIV)-1;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val |= (fifo_bits << SXGBE_MTL_FIFO_LSHIFT);
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_enable_txqueue(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
reg_val |= SXGBE_MTL_ENABLE_QUEUE;
writel(reg_val, ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_disable_txqueue(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
reg_val &= ~SXGBE_MTL_ENABLE_QUEUE;
writel(reg_val, ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fc_active(void __iomem *ioaddr, int queue_num,
int threshold)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val &= ~(SXGBE_MTL_FCMASK << RX_FC_ACTIVE);
reg_val |= (threshold << RX_FC_ACTIVE);
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fc_enable(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val |= SXGBE_MTL_ENABLE_FC;
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fc_deactive(void __iomem *ioaddr, int queue_num,
int threshold)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val &= ~(SXGBE_MTL_FCMASK << RX_FC_DEACTIVE);
reg_val |= (threshold << RX_FC_DEACTIVE);
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fep_enable(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val |= SXGBE_MTL_RXQ_OP_FEP;
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fep_disable(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val &= ~(SXGBE_MTL_RXQ_OP_FEP);
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fup_enable(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val |= SXGBE_MTL_RXQ_OP_FUP;
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_mtl_fup_disable(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
reg_val &= ~(SXGBE_MTL_RXQ_OP_FUP);
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
static void sxgbe_set_tx_mtl_mode(void __iomem *ioaddr, int queue_num,
int tx_mode)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
if (tx_mode == SXGBE_MTL_SFMODE) {
reg_val |= SXGBE_MTL_SFMODE;
} else {
if (tx_mode <= 64)
reg_val |= MTL_CONTROL_TTC_64;
else if (tx_mode <= 96)
reg_val |= MTL_CONTROL_TTC_96;
else if (tx_mode <= 128)
reg_val |= MTL_CONTROL_TTC_128;
else if (tx_mode <= 192)
reg_val |= MTL_CONTROL_TTC_192;
else if (tx_mode <= 256)
reg_val |= MTL_CONTROL_TTC_256;
else if (tx_mode <= 384)
reg_val |= MTL_CONTROL_TTC_384;
else
reg_val |= MTL_CONTROL_TTC_512;
}
writel(reg_val, ioaddr + SXGBE_MTL_TXQ_OPMODE_REG(queue_num));
}
static void sxgbe_set_rx_mtl_mode(void __iomem *ioaddr, int queue_num,
int rx_mode)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
if (rx_mode == SXGBE_RX_MTL_SFMODE) {
reg_val |= SXGBE_RX_MTL_SFMODE;
} else {
if (rx_mode <= 64)
reg_val |= MTL_CONTROL_RTC_64;
else if (rx_mode <= 96)
reg_val |= MTL_CONTROL_RTC_96;
else if (rx_mode <= 128)
reg_val |= MTL_CONTROL_RTC_128;
}
writel(reg_val, ioaddr + SXGBE_MTL_RXQ_OPMODE_REG(queue_num));
}
const struct sxgbe_mtl_ops *sxgbe_get_mtl_ops(void)
{
return &mtl_ops;
}
