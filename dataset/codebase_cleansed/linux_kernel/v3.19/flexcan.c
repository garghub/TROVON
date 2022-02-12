static inline u32 flexcan_read(void __iomem *addr)
{
return in_be32(addr);
}
static inline void flexcan_write(u32 val, void __iomem *addr)
{
out_be32(addr, val);
}
static inline u32 flexcan_read(void __iomem *addr)
{
return readl(addr);
}
static inline void flexcan_write(u32 val, void __iomem *addr)
{
writel(val, addr);
}
static inline int flexcan_transceiver_enable(const struct flexcan_priv *priv)
{
if (!priv->reg_xceiver)
return 0;
return regulator_enable(priv->reg_xceiver);
}
static inline int flexcan_transceiver_disable(const struct flexcan_priv *priv)
{
if (!priv->reg_xceiver)
return 0;
return regulator_disable(priv->reg_xceiver);
}
static inline int flexcan_has_and_handle_berr(const struct flexcan_priv *priv,
u32 reg_esr)
{
return (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING) &&
(reg_esr & FLEXCAN_ESR_ERR_BUS);
}
static int flexcan_chip_enable(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
unsigned int timeout = FLEXCAN_TIMEOUT_US / 10;
u32 reg;
reg = flexcan_read(&regs->mcr);
reg &= ~FLEXCAN_MCR_MDIS;
flexcan_write(reg, &regs->mcr);
while (timeout-- && (flexcan_read(&regs->mcr) & FLEXCAN_MCR_LPM_ACK))
udelay(10);
if (flexcan_read(&regs->mcr) & FLEXCAN_MCR_LPM_ACK)
return -ETIMEDOUT;
return 0;
}
static int flexcan_chip_disable(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
unsigned int timeout = FLEXCAN_TIMEOUT_US / 10;
u32 reg;
reg = flexcan_read(&regs->mcr);
reg |= FLEXCAN_MCR_MDIS;
flexcan_write(reg, &regs->mcr);
while (timeout-- && !(flexcan_read(&regs->mcr) & FLEXCAN_MCR_LPM_ACK))
udelay(10);
if (!(flexcan_read(&regs->mcr) & FLEXCAN_MCR_LPM_ACK))
return -ETIMEDOUT;
return 0;
}
static int flexcan_chip_freeze(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
unsigned int timeout = 1000 * 1000 * 10 / priv->can.bittiming.bitrate;
u32 reg;
reg = flexcan_read(&regs->mcr);
reg |= FLEXCAN_MCR_HALT;
flexcan_write(reg, &regs->mcr);
while (timeout-- && !(flexcan_read(&regs->mcr) & FLEXCAN_MCR_FRZ_ACK))
udelay(100);
if (!(flexcan_read(&regs->mcr) & FLEXCAN_MCR_FRZ_ACK))
return -ETIMEDOUT;
return 0;
}
static int flexcan_chip_unfreeze(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
unsigned int timeout = FLEXCAN_TIMEOUT_US / 10;
u32 reg;
reg = flexcan_read(&regs->mcr);
reg &= ~FLEXCAN_MCR_HALT;
flexcan_write(reg, &regs->mcr);
while (timeout-- && (flexcan_read(&regs->mcr) & FLEXCAN_MCR_FRZ_ACK))
udelay(10);
if (flexcan_read(&regs->mcr) & FLEXCAN_MCR_FRZ_ACK)
return -ETIMEDOUT;
return 0;
}
static int flexcan_chip_softreset(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
unsigned int timeout = FLEXCAN_TIMEOUT_US / 10;
flexcan_write(FLEXCAN_MCR_SOFTRST, &regs->mcr);
while (timeout-- && (flexcan_read(&regs->mcr) & FLEXCAN_MCR_SOFTRST))
udelay(10);
if (flexcan_read(&regs->mcr) & FLEXCAN_MCR_SOFTRST)
return -ETIMEDOUT;
return 0;
}
static int __flexcan_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
const struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg = flexcan_read(&regs->ecr);
bec->txerr = (reg >> 0) & 0xff;
bec->rxerr = (reg >> 8) & 0xff;
return 0;
}
static int flexcan_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
const struct flexcan_priv *priv = netdev_priv(dev);
int err;
err = clk_prepare_enable(priv->clk_ipg);
if (err)
return err;
err = clk_prepare_enable(priv->clk_per);
if (err)
goto out_disable_ipg;
err = __flexcan_get_berr_counter(dev, bec);
clk_disable_unprepare(priv->clk_per);
out_disable_ipg:
clk_disable_unprepare(priv->clk_ipg);
return err;
}
static int flexcan_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
const struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
struct can_frame *cf = (struct can_frame *)skb->data;
u32 can_id;
u32 ctrl = FLEXCAN_MB_CNT_CODE(0xc) | (cf->can_dlc << 16);
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
netif_stop_queue(dev);
if (cf->can_id & CAN_EFF_FLAG) {
can_id = cf->can_id & CAN_EFF_MASK;
ctrl |= FLEXCAN_MB_CNT_IDE | FLEXCAN_MB_CNT_SRR;
} else {
can_id = (cf->can_id & CAN_SFF_MASK) << 18;
}
if (cf->can_id & CAN_RTR_FLAG)
ctrl |= FLEXCAN_MB_CNT_RTR;
if (cf->can_dlc > 0) {
u32 data = be32_to_cpup((__be32 *)&cf->data[0]);
flexcan_write(data, &regs->cantxfg[FLEXCAN_TX_BUF_ID].data[0]);
}
if (cf->can_dlc > 3) {
u32 data = be32_to_cpup((__be32 *)&cf->data[4]);
flexcan_write(data, &regs->cantxfg[FLEXCAN_TX_BUF_ID].data[1]);
}
can_put_echo_skb(skb, dev, 0);
flexcan_write(can_id, &regs->cantxfg[FLEXCAN_TX_BUF_ID].can_id);
flexcan_write(ctrl, &regs->cantxfg[FLEXCAN_TX_BUF_ID].can_ctrl);
flexcan_write(FLEXCAN_MB_CODE_TX_INACTIVE,
&regs->cantxfg[FLEXCAN_TX_BUF_RESERVED].can_ctrl);
flexcan_write(FLEXCAN_MB_CODE_TX_INACTIVE,
&regs->cantxfg[FLEXCAN_TX_BUF_RESERVED].can_ctrl);
return NETDEV_TX_OK;
}
static void do_bus_err(struct net_device *dev,
struct can_frame *cf, u32 reg_esr)
{
struct flexcan_priv *priv = netdev_priv(dev);
int rx_errors = 0, tx_errors = 0;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
if (reg_esr & FLEXCAN_ESR_BIT1_ERR) {
netdev_dbg(dev, "BIT1_ERR irq\n");
cf->data[2] |= CAN_ERR_PROT_BIT1;
tx_errors = 1;
}
if (reg_esr & FLEXCAN_ESR_BIT0_ERR) {
netdev_dbg(dev, "BIT0_ERR irq\n");
cf->data[2] |= CAN_ERR_PROT_BIT0;
tx_errors = 1;
}
if (reg_esr & FLEXCAN_ESR_ACK_ERR) {
netdev_dbg(dev, "ACK_ERR irq\n");
cf->can_id |= CAN_ERR_ACK;
cf->data[3] |= CAN_ERR_PROT_LOC_ACK;
tx_errors = 1;
}
if (reg_esr & FLEXCAN_ESR_CRC_ERR) {
netdev_dbg(dev, "CRC_ERR irq\n");
cf->data[2] |= CAN_ERR_PROT_BIT;
cf->data[3] |= CAN_ERR_PROT_LOC_CRC_SEQ;
rx_errors = 1;
}
if (reg_esr & FLEXCAN_ESR_FRM_ERR) {
netdev_dbg(dev, "FRM_ERR irq\n");
cf->data[2] |= CAN_ERR_PROT_FORM;
rx_errors = 1;
}
if (reg_esr & FLEXCAN_ESR_STF_ERR) {
netdev_dbg(dev, "STF_ERR irq\n");
cf->data[2] |= CAN_ERR_PROT_STUFF;
rx_errors = 1;
}
priv->can.can_stats.bus_error++;
if (rx_errors)
dev->stats.rx_errors++;
if (tx_errors)
dev->stats.tx_errors++;
}
static int flexcan_poll_bus_err(struct net_device *dev, u32 reg_esr)
{
struct sk_buff *skb;
struct can_frame *cf;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
do_bus_err(dev, cf, reg_esr);
netif_receive_skb(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += cf->can_dlc;
return 1;
}
static int flexcan_poll_state(struct net_device *dev, u32 reg_esr)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct sk_buff *skb;
struct can_frame *cf;
enum can_state new_state = 0, rx_state = 0, tx_state = 0;
int flt;
struct can_berr_counter bec;
flt = reg_esr & FLEXCAN_ESR_FLT_CONF_MASK;
if (likely(flt == FLEXCAN_ESR_FLT_CONF_ACTIVE)) {
tx_state = unlikely(reg_esr & FLEXCAN_ESR_TX_WRN) ?
CAN_STATE_ERROR_WARNING : CAN_STATE_ERROR_ACTIVE;
rx_state = unlikely(reg_esr & FLEXCAN_ESR_RX_WRN) ?
CAN_STATE_ERROR_WARNING : CAN_STATE_ERROR_ACTIVE;
new_state = max(tx_state, rx_state);
} else if (unlikely(flt == FLEXCAN_ESR_FLT_CONF_PASSIVE)) {
__flexcan_get_berr_counter(dev, &bec);
new_state = CAN_STATE_ERROR_PASSIVE;
rx_state = bec.rxerr >= bec.txerr ? new_state : 0;
tx_state = bec.rxerr <= bec.txerr ? new_state : 0;
} else {
new_state = CAN_STATE_BUS_OFF;
}
if (likely(new_state == priv->can.state))
return 0;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
can_change_state(dev, cf, tx_state, rx_state);
if (unlikely(new_state == CAN_STATE_BUS_OFF))
can_bus_off(dev);
netif_receive_skb(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += cf->can_dlc;
return 1;
}
static void flexcan_read_fifo(const struct net_device *dev,
struct can_frame *cf)
{
const struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
struct flexcan_mb __iomem *mb = &regs->cantxfg[0];
u32 reg_ctrl, reg_id;
reg_ctrl = flexcan_read(&mb->can_ctrl);
reg_id = flexcan_read(&mb->can_id);
if (reg_ctrl & FLEXCAN_MB_CNT_IDE)
cf->can_id = ((reg_id >> 0) & CAN_EFF_MASK) | CAN_EFF_FLAG;
else
cf->can_id = (reg_id >> 18) & CAN_SFF_MASK;
if (reg_ctrl & FLEXCAN_MB_CNT_RTR)
cf->can_id |= CAN_RTR_FLAG;
cf->can_dlc = get_can_dlc((reg_ctrl >> 16) & 0xf);
*(__be32 *)(cf->data + 0) = cpu_to_be32(flexcan_read(&mb->data[0]));
*(__be32 *)(cf->data + 4) = cpu_to_be32(flexcan_read(&mb->data[1]));
flexcan_write(FLEXCAN_IFLAG_RX_FIFO_AVAILABLE, &regs->iflag1);
flexcan_read(&regs->timer);
}
static int flexcan_read_frame(struct net_device *dev)
{
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
skb = alloc_can_skb(dev, &cf);
if (unlikely(!skb)) {
stats->rx_dropped++;
return 0;
}
flexcan_read_fifo(dev, cf);
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
can_led_event(dev, CAN_LED_EVENT_RX);
return 1;
}
static int flexcan_poll(struct napi_struct *napi, int quota)
{
struct net_device *dev = napi->dev;
const struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg_iflag1, reg_esr;
int work_done = 0;
reg_esr = flexcan_read(&regs->esr) | priv->reg_esr;
work_done += flexcan_poll_state(dev, reg_esr);
reg_iflag1 = flexcan_read(&regs->iflag1);
while (reg_iflag1 & FLEXCAN_IFLAG_RX_FIFO_AVAILABLE &&
work_done < quota) {
work_done += flexcan_read_frame(dev);
reg_iflag1 = flexcan_read(&regs->iflag1);
}
if (flexcan_has_and_handle_berr(priv, reg_esr) && work_done < quota)
work_done += flexcan_poll_bus_err(dev, reg_esr);
if (work_done < quota) {
napi_complete(napi);
flexcan_write(FLEXCAN_IFLAG_DEFAULT, &regs->imask1);
flexcan_write(priv->reg_ctrl_default, &regs->ctrl);
}
return work_done;
}
static irqreturn_t flexcan_irq(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct net_device_stats *stats = &dev->stats;
struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg_iflag1, reg_esr;
reg_iflag1 = flexcan_read(&regs->iflag1);
reg_esr = flexcan_read(&regs->esr);
if (reg_esr & FLEXCAN_ESR_ALL_INT)
flexcan_write(reg_esr & FLEXCAN_ESR_ALL_INT, &regs->esr);
if ((reg_iflag1 & FLEXCAN_IFLAG_RX_FIFO_AVAILABLE) ||
(reg_esr & FLEXCAN_ESR_ERR_STATE) ||
flexcan_has_and_handle_berr(priv, reg_esr)) {
priv->reg_esr = reg_esr & FLEXCAN_ESR_ERR_BUS;
flexcan_write(FLEXCAN_IFLAG_DEFAULT &
~FLEXCAN_IFLAG_RX_FIFO_AVAILABLE, &regs->imask1);
flexcan_write(priv->reg_ctrl_default & ~FLEXCAN_CTRL_ERR_ALL,
&regs->ctrl);
napi_schedule(&priv->napi);
}
if (reg_iflag1 & FLEXCAN_IFLAG_RX_FIFO_OVERFLOW) {
flexcan_write(FLEXCAN_IFLAG_RX_FIFO_OVERFLOW, &regs->iflag1);
dev->stats.rx_over_errors++;
dev->stats.rx_errors++;
}
if (reg_iflag1 & (1 << FLEXCAN_TX_BUF_ID)) {
stats->tx_bytes += can_get_echo_skb(dev, 0);
stats->tx_packets++;
can_led_event(dev, CAN_LED_EVENT_TX);
flexcan_write(FLEXCAN_MB_CODE_TX_INACTIVE,
&regs->cantxfg[FLEXCAN_TX_BUF_ID].can_ctrl);
flexcan_write((1 << FLEXCAN_TX_BUF_ID), &regs->iflag1);
netif_wake_queue(dev);
}
return IRQ_HANDLED;
}
static void flexcan_set_bittiming(struct net_device *dev)
{
const struct flexcan_priv *priv = netdev_priv(dev);
const struct can_bittiming *bt = &priv->can.bittiming;
struct flexcan_regs __iomem *regs = priv->base;
u32 reg;
reg = flexcan_read(&regs->ctrl);
reg &= ~(FLEXCAN_CTRL_PRESDIV(0xff) |
FLEXCAN_CTRL_RJW(0x3) |
FLEXCAN_CTRL_PSEG1(0x7) |
FLEXCAN_CTRL_PSEG2(0x7) |
FLEXCAN_CTRL_PROPSEG(0x7) |
FLEXCAN_CTRL_LPB |
FLEXCAN_CTRL_SMP |
FLEXCAN_CTRL_LOM);
reg |= FLEXCAN_CTRL_PRESDIV(bt->brp - 1) |
FLEXCAN_CTRL_PSEG1(bt->phase_seg1 - 1) |
FLEXCAN_CTRL_PSEG2(bt->phase_seg2 - 1) |
FLEXCAN_CTRL_RJW(bt->sjw - 1) |
FLEXCAN_CTRL_PROPSEG(bt->prop_seg - 1);
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)
reg |= FLEXCAN_CTRL_LPB;
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
reg |= FLEXCAN_CTRL_LOM;
if (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES)
reg |= FLEXCAN_CTRL_SMP;
netdev_info(dev, "writing ctrl=0x%08x\n", reg);
flexcan_write(reg, &regs->ctrl);
netdev_dbg(dev, "%s: mcr=0x%08x ctrl=0x%08x\n", __func__,
flexcan_read(&regs->mcr), flexcan_read(&regs->ctrl));
}
static int flexcan_chip_start(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg_mcr, reg_ctrl, reg_crl2, reg_mecr;
int err, i;
err = flexcan_chip_enable(priv);
if (err)
return err;
err = flexcan_chip_softreset(priv);
if (err)
goto out_chip_disable;
flexcan_set_bittiming(dev);
reg_mcr = flexcan_read(&regs->mcr);
reg_mcr &= ~FLEXCAN_MCR_MAXMB(0xff);
reg_mcr |= FLEXCAN_MCR_FRZ | FLEXCAN_MCR_FEN | FLEXCAN_MCR_HALT |
FLEXCAN_MCR_SUPV | FLEXCAN_MCR_WRN_EN |
FLEXCAN_MCR_IDAM_C | FLEXCAN_MCR_SRX_DIS |
FLEXCAN_MCR_MAXMB(FLEXCAN_TX_BUF_ID);
netdev_dbg(dev, "%s: writing mcr=0x%08x", __func__, reg_mcr);
flexcan_write(reg_mcr, &regs->mcr);
reg_ctrl = flexcan_read(&regs->ctrl);
reg_ctrl &= ~FLEXCAN_CTRL_TSYN;
reg_ctrl |= FLEXCAN_CTRL_BOFF_REC | FLEXCAN_CTRL_LBUF |
FLEXCAN_CTRL_ERR_STATE;
if (priv->devtype_data->features & FLEXCAN_HAS_BROKEN_ERR_STATE ||
priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING)
reg_ctrl |= FLEXCAN_CTRL_ERR_MSK;
else
reg_ctrl &= ~FLEXCAN_CTRL_ERR_MSK;
priv->reg_ctrl_default = reg_ctrl;
netdev_dbg(dev, "%s: writing ctrl=0x%08x", __func__, reg_ctrl);
flexcan_write(reg_ctrl, &regs->ctrl);
for (i = FLEXCAN_TX_BUF_ID; i < ARRAY_SIZE(regs->cantxfg); i++) {
flexcan_write(FLEXCAN_MB_CODE_RX_INACTIVE,
&regs->cantxfg[i].can_ctrl);
}
flexcan_write(FLEXCAN_MB_CODE_TX_INACTIVE,
&regs->cantxfg[FLEXCAN_TX_BUF_RESERVED].can_ctrl);
flexcan_write(FLEXCAN_MB_CODE_TX_INACTIVE,
&regs->cantxfg[FLEXCAN_TX_BUF_ID].can_ctrl);
flexcan_write(0x0, &regs->rxgmask);
flexcan_write(0x0, &regs->rx14mask);
flexcan_write(0x0, &regs->rx15mask);
if (priv->devtype_data->features & FLEXCAN_HAS_V10_FEATURES)
flexcan_write(0x0, &regs->rxfgmask);
if (priv->devtype_data->features & FLEXCAN_HAS_MECR_FEATURES) {
reg_crl2 = flexcan_read(&regs->crl2);
reg_crl2 |= FLEXCAN_CRL2_ECRWRE;
flexcan_write(reg_crl2, &regs->crl2);
reg_mecr = flexcan_read(&regs->mecr);
reg_mecr &= ~FLEXCAN_MECR_ECRWRDIS;
flexcan_write(reg_mecr, &regs->mecr);
reg_mecr &= ~(FLEXCAN_MECR_NCEFAFRZ | FLEXCAN_MECR_HANCEI_MSK |
FLEXCAN_MECR_FANCEI_MSK);
flexcan_write(reg_mecr, &regs->mecr);
}
err = flexcan_transceiver_enable(priv);
if (err)
goto out_chip_disable;
err = flexcan_chip_unfreeze(priv);
if (err)
goto out_transceiver_disable;
priv->can.state = CAN_STATE_ERROR_ACTIVE;
flexcan_write(FLEXCAN_IFLAG_DEFAULT, &regs->imask1);
netdev_dbg(dev, "%s: reading mcr=0x%08x ctrl=0x%08x\n", __func__,
flexcan_read(&regs->mcr), flexcan_read(&regs->ctrl));
return 0;
out_transceiver_disable:
flexcan_transceiver_disable(priv);
out_chip_disable:
flexcan_chip_disable(priv);
return err;
}
static void flexcan_chip_stop(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
flexcan_chip_freeze(priv);
flexcan_chip_disable(priv);
flexcan_write(0, &regs->imask1);
flexcan_write(priv->reg_ctrl_default & ~FLEXCAN_CTRL_ERR_ALL,
&regs->ctrl);
flexcan_transceiver_disable(priv);
priv->can.state = CAN_STATE_STOPPED;
return;
}
static int flexcan_open(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
int err;
err = clk_prepare_enable(priv->clk_ipg);
if (err)
return err;
err = clk_prepare_enable(priv->clk_per);
if (err)
goto out_disable_ipg;
err = open_candev(dev);
if (err)
goto out_disable_per;
err = request_irq(dev->irq, flexcan_irq, IRQF_SHARED, dev->name, dev);
if (err)
goto out_close;
err = flexcan_chip_start(dev);
if (err)
goto out_free_irq;
can_led_event(dev, CAN_LED_EVENT_OPEN);
napi_enable(&priv->napi);
netif_start_queue(dev);
return 0;
out_free_irq:
free_irq(dev->irq, dev);
out_close:
close_candev(dev);
out_disable_per:
clk_disable_unprepare(priv->clk_per);
out_disable_ipg:
clk_disable_unprepare(priv->clk_ipg);
return err;
}
static int flexcan_close(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&priv->napi);
flexcan_chip_stop(dev);
free_irq(dev->irq, dev);
clk_disable_unprepare(priv->clk_per);
clk_disable_unprepare(priv->clk_ipg);
close_candev(dev);
can_led_event(dev, CAN_LED_EVENT_STOP);
return 0;
}
static int flexcan_set_mode(struct net_device *dev, enum can_mode mode)
{
int err;
switch (mode) {
case CAN_MODE_START:
err = flexcan_chip_start(dev);
if (err)
return err;
netif_wake_queue(dev);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int register_flexcandev(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg, err;
err = clk_prepare_enable(priv->clk_ipg);
if (err)
return err;
err = clk_prepare_enable(priv->clk_per);
if (err)
goto out_disable_ipg;
err = flexcan_chip_disable(priv);
if (err)
goto out_disable_per;
reg = flexcan_read(&regs->ctrl);
reg |= FLEXCAN_CTRL_CLK_SRC;
flexcan_write(reg, &regs->ctrl);
err = flexcan_chip_enable(priv);
if (err)
goto out_chip_disable;
reg = flexcan_read(&regs->mcr);
reg |= FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT |
FLEXCAN_MCR_FEN | FLEXCAN_MCR_SUPV;
flexcan_write(reg, &regs->mcr);
reg = flexcan_read(&regs->mcr);
if (!(reg & FLEXCAN_MCR_FEN)) {
netdev_err(dev, "Could not enable RX FIFO, unsupported core\n");
err = -ENODEV;
goto out_chip_disable;
}
err = register_candev(dev);
out_chip_disable:
flexcan_chip_disable(priv);
out_disable_per:
clk_disable_unprepare(priv->clk_per);
out_disable_ipg:
clk_disable_unprepare(priv->clk_ipg);
return err;
}
static void unregister_flexcandev(struct net_device *dev)
{
unregister_candev(dev);
}
static int flexcan_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
const struct flexcan_devtype_data *devtype_data;
struct net_device *dev;
struct flexcan_priv *priv;
struct resource *mem;
struct clk *clk_ipg = NULL, *clk_per = NULL;
void __iomem *base;
int err, irq;
u32 clock_freq = 0;
if (pdev->dev.of_node)
of_property_read_u32(pdev->dev.of_node,
"clock-frequency", &clock_freq);
if (!clock_freq) {
clk_ipg = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(clk_ipg)) {
dev_err(&pdev->dev, "no ipg clock defined\n");
return PTR_ERR(clk_ipg);
}
clk_per = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(clk_per)) {
dev_err(&pdev->dev, "no per clock defined\n");
return PTR_ERR(clk_per);
}
clock_freq = clk_get_rate(clk_per);
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (irq <= 0)
return -ENODEV;
base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(base))
return PTR_ERR(base);
of_id = of_match_device(flexcan_of_match, &pdev->dev);
if (of_id) {
devtype_data = of_id->data;
} else if (platform_get_device_id(pdev)->driver_data) {
devtype_data = (struct flexcan_devtype_data *)
platform_get_device_id(pdev)->driver_data;
} else {
return -ENODEV;
}
dev = alloc_candev(sizeof(struct flexcan_priv), 1);
if (!dev)
return -ENOMEM;
dev->netdev_ops = &flexcan_netdev_ops;
dev->irq = irq;
dev->flags |= IFF_ECHO;
priv = netdev_priv(dev);
priv->can.clock.freq = clock_freq;
priv->can.bittiming_const = &flexcan_bittiming_const;
priv->can.do_set_mode = flexcan_set_mode;
priv->can.do_get_berr_counter = flexcan_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_LISTENONLY | CAN_CTRLMODE_3_SAMPLES |
CAN_CTRLMODE_BERR_REPORTING;
priv->base = base;
priv->dev = dev;
priv->clk_ipg = clk_ipg;
priv->clk_per = clk_per;
priv->pdata = dev_get_platdata(&pdev->dev);
priv->devtype_data = devtype_data;
priv->reg_xceiver = devm_regulator_get(&pdev->dev, "xceiver");
if (IS_ERR(priv->reg_xceiver))
priv->reg_xceiver = NULL;
netif_napi_add(dev, &priv->napi, flexcan_poll, FLEXCAN_NAPI_WEIGHT);
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_flexcandev(dev);
if (err) {
dev_err(&pdev->dev, "registering netdev failed\n");
goto failed_register;
}
devm_can_led_init(dev);
dev_info(&pdev->dev, "device registered (reg_base=%p, irq=%d)\n",
priv->base, dev->irq);
return 0;
failed_register:
free_candev(dev);
return err;
}
static int flexcan_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct flexcan_priv *priv = netdev_priv(dev);
unregister_flexcandev(dev);
netif_napi_del(&priv->napi);
free_candev(dev);
return 0;
}
static int __maybe_unused flexcan_suspend(struct device *device)
{
struct net_device *dev = dev_get_drvdata(device);
struct flexcan_priv *priv = netdev_priv(dev);
int err;
err = flexcan_chip_disable(priv);
if (err)
return err;
if (netif_running(dev)) {
netif_stop_queue(dev);
netif_device_detach(dev);
}
priv->can.state = CAN_STATE_SLEEPING;
return 0;
}
static int __maybe_unused flexcan_resume(struct device *device)
{
struct net_device *dev = dev_get_drvdata(device);
struct flexcan_priv *priv = netdev_priv(dev);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
if (netif_running(dev)) {
netif_device_attach(dev);
netif_start_queue(dev);
}
return flexcan_chip_enable(priv);
}
