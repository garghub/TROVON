static void sxgbe_core_init(void __iomem *ioaddr)
{
u32 regval;
regval = readl(ioaddr + SXGBE_CORE_TX_CONFIG_REG);
regval |= SXGBE_TX_JABBER_DISABLE;
writel(regval, ioaddr + SXGBE_CORE_TX_CONFIG_REG);
regval = readl(ioaddr + SXGBE_CORE_RX_CONFIG_REG);
regval |= SXGBE_RX_JUMBPKT_ENABLE | SXGBE_RX_ACS_ENABLE;
writel(regval, ioaddr + SXGBE_CORE_RX_CONFIG_REG);
}
static void sxgbe_core_dump_regs(void __iomem *ioaddr)
{
}
static int sxgbe_get_lpi_status(void __iomem *ioaddr, const u32 irq_status)
{
int status = 0;
int lpi_status;
lpi_status = readl(ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
if (lpi_status & LPI_CTRL_STATUS_TLPIEN)
status |= TX_ENTRY_LPI_MODE;
if (lpi_status & LPI_CTRL_STATUS_TLPIEX)
status |= TX_EXIT_LPI_MODE;
if (lpi_status & LPI_CTRL_STATUS_RLPIEN)
status |= RX_ENTRY_LPI_MODE;
if (lpi_status & LPI_CTRL_STATUS_RLPIEX)
status |= RX_EXIT_LPI_MODE;
return status;
}
static int sxgbe_core_host_irq_status(void __iomem *ioaddr,
struct sxgbe_extra_stats *x)
{
int irq_status, status = 0;
irq_status = readl(ioaddr + SXGBE_CORE_INT_STATUS_REG);
if (unlikely(irq_status & LPI_INT_STATUS))
status |= sxgbe_get_lpi_status(ioaddr, irq_status);
return status;
}
static void sxgbe_core_pmt(void __iomem *ioaddr, unsigned long mode)
{
}
static void sxgbe_core_set_umac_addr(void __iomem *ioaddr, unsigned char *addr,
unsigned int reg_n)
{
u32 high_word, low_word;
high_word = (addr[5] << 8) | (addr[4]);
low_word = (addr[3] << 24) | (addr[2] << 16) |
(addr[1] << 8) | (addr[0]);
writel(high_word, ioaddr + SXGBE_CORE_ADD_HIGHOFFSET(reg_n));
writel(low_word, ioaddr + SXGBE_CORE_ADD_LOWOFFSET(reg_n));
}
static void sxgbe_core_get_umac_addr(void __iomem *ioaddr, unsigned char *addr,
unsigned int reg_n)
{
u32 high_word, low_word;
high_word = readl(ioaddr + SXGBE_CORE_ADD_HIGHOFFSET(reg_n));
low_word = readl(ioaddr + SXGBE_CORE_ADD_LOWOFFSET(reg_n));
addr[5] = (high_word & 0x0000FF00) >> 8;
addr[4] = (high_word & 0x000000FF);
addr[3] = (low_word & 0xFF000000) >> 24;
addr[2] = (low_word & 0x00FF0000) >> 16;
addr[1] = (low_word & 0x0000FF00) >> 8;
addr[0] = (low_word & 0x000000FF);
}
static void sxgbe_enable_tx(void __iomem *ioaddr, bool enable)
{
u32 tx_config;
tx_config = readl(ioaddr + SXGBE_CORE_TX_CONFIG_REG);
tx_config &= ~SXGBE_TX_ENABLE;
if (enable)
tx_config |= SXGBE_TX_ENABLE;
writel(tx_config, ioaddr + SXGBE_CORE_TX_CONFIG_REG);
}
static void sxgbe_enable_rx(void __iomem *ioaddr, bool enable)
{
u32 rx_config;
rx_config = readl(ioaddr + SXGBE_CORE_RX_CONFIG_REG);
rx_config &= ~SXGBE_RX_ENABLE;
if (enable)
rx_config |= SXGBE_RX_ENABLE;
writel(rx_config, ioaddr + SXGBE_CORE_RX_CONFIG_REG);
}
static int sxgbe_get_controller_version(void __iomem *ioaddr)
{
return readl(ioaddr + SXGBE_CORE_VERSION_REG);
}
static unsigned int sxgbe_get_hw_feature(void __iomem *ioaddr,
unsigned char feature_index)
{
return readl(ioaddr + (SXGBE_CORE_HW_FEA_REG(feature_index)));
}
static void sxgbe_core_set_speed(void __iomem *ioaddr, unsigned char speed)
{
u32 tx_cfg = readl(ioaddr + SXGBE_CORE_TX_CONFIG_REG);
tx_cfg &= ~0x60000000;
tx_cfg |= (speed << SXGBE_SPEED_LSHIFT);
writel(tx_cfg, ioaddr + SXGBE_CORE_TX_CONFIG_REG);
}
static void sxgbe_core_enable_rxqueue(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_CORE_RX_CTL0_REG);
reg_val &= ~(SXGBE_CORE_RXQ_ENABLE_MASK << queue_num);
reg_val |= SXGBE_CORE_RXQ_ENABLE;
writel(reg_val, ioaddr + SXGBE_CORE_RX_CTL0_REG);
}
static void sxgbe_core_disable_rxqueue(void __iomem *ioaddr, int queue_num)
{
u32 reg_val;
reg_val = readl(ioaddr + SXGBE_CORE_RX_CTL0_REG);
reg_val &= ~(SXGBE_CORE_RXQ_ENABLE_MASK << queue_num);
reg_val |= SXGBE_CORE_RXQ_DISABLE;
writel(reg_val, ioaddr + SXGBE_CORE_RX_CTL0_REG);
}
static void sxgbe_set_eee_mode(void __iomem *ioaddr)
{
u32 ctrl;
ctrl = readl(ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
ctrl |= LPI_CTRL_STATUS_LPIEN | LPI_CTRL_STATUS_TXA;
writel(ctrl, ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
}
static void sxgbe_reset_eee_mode(void __iomem *ioaddr)
{
u32 ctrl;
ctrl = readl(ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
ctrl &= ~(LPI_CTRL_STATUS_LPIEN | LPI_CTRL_STATUS_TXA);
writel(ctrl, ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
}
static void sxgbe_set_eee_pls(void __iomem *ioaddr, const int link)
{
u32 ctrl;
ctrl = readl(ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
if (link)
ctrl |= LPI_CTRL_STATUS_PLS;
else
ctrl &= ~LPI_CTRL_STATUS_PLS;
writel(ctrl, ioaddr + SXGBE_CORE_LPI_CTRL_STATUS);
}
static void sxgbe_set_eee_timer(void __iomem *ioaddr,
const int ls, const int tw)
{
int value = ((tw & 0xffff)) | ((ls & 0x7ff) << 16);
writel(value, ioaddr + SXGBE_CORE_LPI_TIMER_CTRL);
}
static void sxgbe_enable_rx_csum(void __iomem *ioaddr)
{
u32 ctrl;
ctrl = readl(ioaddr + SXGBE_CORE_RX_CONFIG_REG);
ctrl |= SXGBE_RX_CSUMOFFLOAD_ENABLE;
writel(ctrl, ioaddr + SXGBE_CORE_RX_CONFIG_REG);
}
static void sxgbe_disable_rx_csum(void __iomem *ioaddr)
{
u32 ctrl;
ctrl = readl(ioaddr + SXGBE_CORE_RX_CONFIG_REG);
ctrl &= ~SXGBE_RX_CSUMOFFLOAD_ENABLE;
writel(ctrl, ioaddr + SXGBE_CORE_RX_CONFIG_REG);
}
const struct sxgbe_core_ops *sxgbe_get_core_ops(void)
{
return &core_ops;
}
