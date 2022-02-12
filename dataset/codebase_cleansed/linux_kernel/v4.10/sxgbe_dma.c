static int sxgbe_dma_init(void __iomem *ioaddr, int fix_burst, int burst_map)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_DMA_SYSBUS_MODE_REG);
if (!fix_burst)
reg_val |= SXGBE_DMA_AXI_UNDEF_BURST;
reg_val |= (burst_map << SXGBE_DMA_BLENMAP_LSHIFT);
writel(reg_val, ioaddr + SXGBE_DMA_SYSBUS_MODE_REG);
return 0;
}
static void sxgbe_dma_channel_init(void __iomem *ioaddr, int cha_num,
int fix_burst, int pbl, dma_addr_t dma_tx,
dma_addr_t dma_rx, int t_rsize, int r_rsize)
{
u32 reg_val;
dma_addr_t dma_addr;
reg_val = readl(ioaddr + SXGBE_DMA_CHA_CTL_REG(cha_num));
if (fix_burst) {
reg_val |= SXGBE_DMA_PBL_X8MODE;
writel(reg_val, ioaddr + SXGBE_DMA_CHA_CTL_REG(cha_num));
reg_val = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cha_num));
reg_val |= (pbl << SXGBE_DMA_TXPBL_LSHIFT);
writel(reg_val, ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cha_num));
reg_val = readl(ioaddr + SXGBE_DMA_CHA_RXCTL_REG(cha_num));
reg_val |= (pbl << SXGBE_DMA_RXPBL_LSHIFT);
writel(reg_val, ioaddr + SXGBE_DMA_CHA_RXCTL_REG(cha_num));
}
writel(upper_32_bits(dma_tx),
ioaddr + SXGBE_DMA_CHA_TXDESC_HADD_REG(cha_num));
writel(lower_32_bits(dma_tx),
ioaddr + SXGBE_DMA_CHA_TXDESC_LADD_REG(cha_num));
writel(upper_32_bits(dma_rx),
ioaddr + SXGBE_DMA_CHA_RXDESC_HADD_REG(cha_num));
writel(lower_32_bits(dma_rx),
ioaddr + SXGBE_DMA_CHA_RXDESC_LADD_REG(cha_num));
dma_addr = dma_tx + ((t_rsize - 1) * SXGBE_DESC_SIZE_BYTES);
writel(lower_32_bits(dma_addr),
ioaddr + SXGBE_DMA_CHA_TXDESC_TAILPTR_REG(cha_num));
dma_addr = dma_rx + ((r_rsize - 1) * SXGBE_DESC_SIZE_BYTES);
writel(lower_32_bits(dma_addr),
ioaddr + SXGBE_DMA_CHA_RXDESC_LADD_REG(cha_num));
writel(t_rsize - 1, ioaddr + SXGBE_DMA_CHA_TXDESC_RINGLEN_REG(cha_num));
writel(r_rsize - 1, ioaddr + SXGBE_DMA_CHA_RXDESC_RINGLEN_REG(cha_num));
writel(SXGBE_DMA_ENA_INT,
ioaddr + SXGBE_DMA_CHA_INT_ENABLE_REG(cha_num));
}
static void sxgbe_enable_dma_transmission(void __iomem *ioaddr, int cha_num)
{
u32 tx_config;
tx_config = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cha_num));
tx_config |= SXGBE_TX_START_DMA;
writel(tx_config, ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cha_num));
}
static void sxgbe_enable_dma_irq(void __iomem *ioaddr, int dma_cnum)
{
writel(SXGBE_DMA_ENA_INT,
ioaddr + SXGBE_DMA_CHA_INT_ENABLE_REG(dma_cnum));
}
static void sxgbe_disable_dma_irq(void __iomem *ioaddr, int dma_cnum)
{
writel(0, ioaddr + SXGBE_DMA_CHA_INT_ENABLE_REG(dma_cnum));
}
static void sxgbe_dma_start_tx(void __iomem *ioaddr, int tchannels)
{
int cnum;
u32 tx_ctl_reg;
for (cnum = 0; cnum < tchannels; cnum++) {
tx_ctl_reg = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cnum));
tx_ctl_reg |= SXGBE_TX_ENABLE;
writel(tx_ctl_reg,
ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cnum));
}
}
static void sxgbe_dma_start_tx_queue(void __iomem *ioaddr, int dma_cnum)
{
u32 tx_ctl_reg;
tx_ctl_reg = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(dma_cnum));
tx_ctl_reg |= SXGBE_TX_ENABLE;
writel(tx_ctl_reg, ioaddr + SXGBE_DMA_CHA_TXCTL_REG(dma_cnum));
}
static void sxgbe_dma_stop_tx_queue(void __iomem *ioaddr, int dma_cnum)
{
u32 tx_ctl_reg;
tx_ctl_reg = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(dma_cnum));
tx_ctl_reg &= ~(SXGBE_TX_ENABLE);
writel(tx_ctl_reg, ioaddr + SXGBE_DMA_CHA_TXCTL_REG(dma_cnum));
}
static void sxgbe_dma_stop_tx(void __iomem *ioaddr, int tchannels)
{
int cnum;
u32 tx_ctl_reg;
for (cnum = 0; cnum < tchannels; cnum++) {
tx_ctl_reg = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cnum));
tx_ctl_reg &= ~(SXGBE_TX_ENABLE);
writel(tx_ctl_reg, ioaddr + SXGBE_DMA_CHA_TXCTL_REG(cnum));
}
}
static void sxgbe_dma_start_rx(void __iomem *ioaddr, int rchannels)
{
int cnum;
u32 rx_ctl_reg;
for (cnum = 0; cnum < rchannels; cnum++) {
rx_ctl_reg = readl(ioaddr + SXGBE_DMA_CHA_RXCTL_REG(cnum));
rx_ctl_reg |= SXGBE_RX_ENABLE;
writel(rx_ctl_reg,
ioaddr + SXGBE_DMA_CHA_RXCTL_REG(cnum));
}
}
static void sxgbe_dma_stop_rx(void __iomem *ioaddr, int rchannels)
{
int cnum;
u32 rx_ctl_reg;
for (cnum = 0; cnum < rchannels; cnum++) {
rx_ctl_reg = readl(ioaddr + SXGBE_DMA_CHA_RXCTL_REG(cnum));
rx_ctl_reg &= ~(SXGBE_RX_ENABLE);
writel(rx_ctl_reg, ioaddr + SXGBE_DMA_CHA_RXCTL_REG(cnum));
}
}
static int sxgbe_tx_dma_int_status(void __iomem *ioaddr, int channel_no,
struct sxgbe_extra_stats *x)
{
u32 int_status = readl(ioaddr + SXGBE_DMA_CHA_STATUS_REG(channel_no));
u32 clear_val = 0;
u32 ret_val = 0;
if (likely(int_status & SXGBE_DMA_INT_STATUS_NIS)) {
x->normal_irq_n++;
if (int_status & SXGBE_DMA_INT_STATUS_TI) {
ret_val |= handle_tx;
x->tx_normal_irq_n++;
clear_val |= SXGBE_DMA_INT_STATUS_TI;
}
if (int_status & SXGBE_DMA_INT_STATUS_TBU) {
x->tx_underflow_irq++;
ret_val |= tx_bump_tc;
clear_val |= SXGBE_DMA_INT_STATUS_TBU;
}
} else if (unlikely(int_status & SXGBE_DMA_INT_STATUS_AIS)) {
if (int_status & SXGBE_DMA_INT_STATUS_TPS) {
ret_val |= tx_hard_error;
clear_val |= SXGBE_DMA_INT_STATUS_TPS;
x->tx_process_stopped_irq++;
}
if (int_status & SXGBE_DMA_INT_STATUS_FBE) {
ret_val |= tx_hard_error;
x->fatal_bus_error_irq++;
if (int_status & SXGBE_DMA_INT_STATUS_TEB0) {
x->tx_read_transfer_err++;
clear_val |= SXGBE_DMA_INT_STATUS_TEB0;
} else {
x->tx_write_transfer_err++;
}
if (int_status & SXGBE_DMA_INT_STATUS_TEB1) {
x->tx_desc_access_err++;
clear_val |= SXGBE_DMA_INT_STATUS_TEB1;
} else {
x->tx_buffer_access_err++;
}
if (int_status & SXGBE_DMA_INT_STATUS_TEB2) {
x->tx_data_transfer_err++;
clear_val |= SXGBE_DMA_INT_STATUS_TEB2;
}
}
if (int_status & SXGBE_DMA_INT_STATUS_CTXTERR) {
x->tx_ctxt_desc_err++;
clear_val |= SXGBE_DMA_INT_STATUS_CTXTERR;
}
}
writel(clear_val, ioaddr + SXGBE_DMA_CHA_STATUS_REG(channel_no));
return ret_val;
}
static int sxgbe_rx_dma_int_status(void __iomem *ioaddr, int channel_no,
struct sxgbe_extra_stats *x)
{
u32 int_status = readl(ioaddr + SXGBE_DMA_CHA_STATUS_REG(channel_no));
u32 clear_val = 0;
u32 ret_val = 0;
if (likely(int_status & SXGBE_DMA_INT_STATUS_NIS)) {
x->normal_irq_n++;
if (int_status & SXGBE_DMA_INT_STATUS_RI) {
ret_val |= handle_rx;
x->rx_normal_irq_n++;
clear_val |= SXGBE_DMA_INT_STATUS_RI;
}
} else if (unlikely(int_status & SXGBE_DMA_INT_STATUS_AIS)) {
if (int_status & SXGBE_DMA_INT_STATUS_RBU) {
ret_val |= rx_bump_tc;
clear_val |= SXGBE_DMA_INT_STATUS_RBU;
x->rx_underflow_irq++;
}
if (int_status & SXGBE_DMA_INT_STATUS_RPS) {
ret_val |= rx_hard_error;
clear_val |= SXGBE_DMA_INT_STATUS_RPS;
x->rx_process_stopped_irq++;
}
if (int_status & SXGBE_DMA_INT_STATUS_FBE) {
ret_val |= rx_hard_error;
x->fatal_bus_error_irq++;
if (int_status & SXGBE_DMA_INT_STATUS_REB0) {
x->rx_read_transfer_err++;
clear_val |= SXGBE_DMA_INT_STATUS_REB0;
} else {
x->rx_write_transfer_err++;
}
if (int_status & SXGBE_DMA_INT_STATUS_REB1) {
x->rx_desc_access_err++;
clear_val |= SXGBE_DMA_INT_STATUS_REB1;
} else {
x->rx_buffer_access_err++;
}
if (int_status & SXGBE_DMA_INT_STATUS_REB2) {
x->rx_data_transfer_err++;
clear_val |= SXGBE_DMA_INT_STATUS_REB2;
}
}
}
writel(clear_val, ioaddr + SXGBE_DMA_CHA_STATUS_REG(channel_no));
return ret_val;
}
static void sxgbe_dma_rx_watchdog(void __iomem *ioaddr, u32 riwt)
{
u32 que_num;
SXGBE_FOR_EACH_QUEUE(SXGBE_RX_QUEUES, que_num) {
writel(riwt,
ioaddr + SXGBE_DMA_CHA_INT_RXWATCHTMR_REG(que_num));
}
}
static void sxgbe_enable_tso(void __iomem *ioaddr, u8 chan_num)
{
u32 ctrl;
ctrl = readl(ioaddr + SXGBE_DMA_CHA_TXCTL_REG(chan_num));
ctrl |= SXGBE_DMA_CHA_TXCTL_TSE_ENABLE;
writel(ctrl, ioaddr + SXGBE_DMA_CHA_TXCTL_REG(chan_num));
}
const struct sxgbe_dma_ops *sxgbe_get_dma_ops(void)
{
return &sxgbe_dma_ops;
}
