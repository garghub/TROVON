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
static void flexcan_transceiver_switch(const struct flexcan_priv *priv, int on)
{
if (priv->pdata && priv->pdata->transceiver_switch)
priv->pdata->transceiver_switch(on);
}
static inline int flexcan_has_and_handle_berr(const struct flexcan_priv *priv,
u32 reg_esr)
{
return (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING) &&
(reg_esr & FLEXCAN_ESR_ERR_BUS);
}
static inline void flexcan_chip_enable(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
u32 reg;
reg = flexcan_read(&regs->mcr);
reg &= ~FLEXCAN_MCR_MDIS;
flexcan_write(reg, &regs->mcr);
udelay(10);
}
static inline void flexcan_chip_disable(struct flexcan_priv *priv)
{
struct flexcan_regs __iomem *regs = priv->base;
u32 reg;
reg = flexcan_read(&regs->mcr);
reg |= FLEXCAN_MCR_MDIS;
flexcan_write(reg, &regs->mcr);
}
static int flexcan_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
const struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg = flexcan_read(&regs->ecr);
bec->txerr = (reg >> 0) & 0xff;
bec->rxerr = (reg >> 8) & 0xff;
return 0;
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
static void do_state(struct net_device *dev,
struct can_frame *cf, enum can_state new_state)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct can_berr_counter bec;
flexcan_get_berr_counter(dev, &bec);
switch (priv->can.state) {
case CAN_STATE_ERROR_ACTIVE:
if (new_state >= CAN_STATE_ERROR_WARNING &&
new_state <= CAN_STATE_BUS_OFF) {
netdev_dbg(dev, "Error Warning IRQ\n");
priv->can.can_stats.error_warning++;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = (bec.txerr > bec.rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
}
case CAN_STATE_ERROR_WARNING:
if (new_state >= CAN_STATE_ERROR_PASSIVE &&
new_state <= CAN_STATE_BUS_OFF) {
netdev_dbg(dev, "Error Passive IRQ\n");
priv->can.can_stats.error_passive++;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = (bec.txerr > bec.rxerr) ?
CAN_ERR_CRTL_TX_PASSIVE :
CAN_ERR_CRTL_RX_PASSIVE;
}
break;
case CAN_STATE_BUS_OFF:
netdev_err(dev, "BUG! "
"hardware recovered automatically from BUS_OFF\n");
break;
default:
break;
}
switch (new_state) {
case CAN_STATE_ERROR_ACTIVE:
netdev_dbg(dev, "Error Active\n");
cf->can_id |= CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_ACTIVE;
break;
case CAN_STATE_BUS_OFF:
cf->can_id |= CAN_ERR_BUSOFF;
can_bus_off(dev);
break;
default:
break;
}
}
static int flexcan_poll_state(struct net_device *dev, u32 reg_esr)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct sk_buff *skb;
struct can_frame *cf;
enum can_state new_state;
int flt;
flt = reg_esr & FLEXCAN_ESR_FLT_CONF_MASK;
if (likely(flt == FLEXCAN_ESR_FLT_CONF_ACTIVE)) {
if (likely(!(reg_esr & (FLEXCAN_ESR_TX_WRN |
FLEXCAN_ESR_RX_WRN))))
new_state = CAN_STATE_ERROR_ACTIVE;
else
new_state = CAN_STATE_ERROR_WARNING;
} else if (unlikely(flt == FLEXCAN_ESR_FLT_CONF_PASSIVE))
new_state = CAN_STATE_ERROR_PASSIVE;
else
new_state = CAN_STATE_BUS_OFF;
if (likely(new_state == priv->can.state))
return 0;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
do_state(dev, cf, new_state);
priv->can.state = new_state;
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
unsigned int i;
int err;
u32 reg_mcr, reg_ctrl;
flexcan_chip_enable(priv);
flexcan_write(FLEXCAN_MCR_SOFTRST, &regs->mcr);
udelay(10);
reg_mcr = flexcan_read(&regs->mcr);
if (reg_mcr & FLEXCAN_MCR_SOFTRST) {
netdev_err(dev, "Failed to softreset can module (mcr=0x%08x)\n",
reg_mcr);
err = -ENODEV;
goto out;
}
flexcan_set_bittiming(dev);
reg_mcr = flexcan_read(&regs->mcr);
reg_mcr |= FLEXCAN_MCR_FRZ | FLEXCAN_MCR_FEN | FLEXCAN_MCR_HALT |
FLEXCAN_MCR_SUPV | FLEXCAN_MCR_WRN_EN |
FLEXCAN_MCR_IDAM_C | FLEXCAN_MCR_SRX_DIS;
netdev_dbg(dev, "%s: writing mcr=0x%08x", __func__, reg_mcr);
flexcan_write(reg_mcr, &regs->mcr);
reg_ctrl = flexcan_read(&regs->ctrl);
reg_ctrl &= ~FLEXCAN_CTRL_TSYN;
reg_ctrl |= FLEXCAN_CTRL_BOFF_REC | FLEXCAN_CTRL_LBUF |
FLEXCAN_CTRL_ERR_STATE | FLEXCAN_CTRL_ERR_MSK;
priv->reg_ctrl_default = reg_ctrl;
netdev_dbg(dev, "%s: writing ctrl=0x%08x", __func__, reg_ctrl);
flexcan_write(reg_ctrl, &regs->ctrl);
for (i = 0; i < ARRAY_SIZE(regs->cantxfg); i++) {
flexcan_write(0, &regs->cantxfg[i].can_ctrl);
flexcan_write(0, &regs->cantxfg[i].can_id);
flexcan_write(0, &regs->cantxfg[i].data[0]);
flexcan_write(0, &regs->cantxfg[i].data[1]);
flexcan_write(FLEXCAN_MB_CNT_CODE(0x4),
&regs->cantxfg[i].can_ctrl);
}
flexcan_write(0x0, &regs->rxgmask);
flexcan_write(0x0, &regs->rx14mask);
flexcan_write(0x0, &regs->rx15mask);
flexcan_transceiver_switch(priv, 1);
reg_mcr = flexcan_read(&regs->mcr);
reg_mcr &= ~FLEXCAN_MCR_HALT;
flexcan_write(reg_mcr, &regs->mcr);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
flexcan_write(FLEXCAN_IFLAG_DEFAULT, &regs->imask1);
netdev_dbg(dev, "%s: reading mcr=0x%08x ctrl=0x%08x\n", __func__,
flexcan_read(&regs->mcr), flexcan_read(&regs->ctrl));
return 0;
out:
flexcan_chip_disable(priv);
return err;
}
static void flexcan_chip_stop(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg;
flexcan_write(0, &regs->imask1);
reg = flexcan_read(&regs->mcr);
reg |= FLEXCAN_MCR_MDIS | FLEXCAN_MCR_HALT;
flexcan_write(reg, &regs->mcr);
flexcan_transceiver_switch(priv, 0);
priv->can.state = CAN_STATE_STOPPED;
return;
}
static int flexcan_open(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
int err;
clk_prepare_enable(priv->clk);
err = open_candev(dev);
if (err)
goto out;
err = request_irq(dev->irq, flexcan_irq, IRQF_SHARED, dev->name, dev);
if (err)
goto out_close;
err = flexcan_chip_start(dev);
if (err)
goto out_close;
napi_enable(&priv->napi);
netif_start_queue(dev);
return 0;
out_close:
close_candev(dev);
out:
clk_disable_unprepare(priv->clk);
return err;
}
static int flexcan_close(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&priv->napi);
flexcan_chip_stop(dev);
free_irq(dev->irq, dev);
clk_disable_unprepare(priv->clk);
close_candev(dev);
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
static int __devinit register_flexcandev(struct net_device *dev)
{
struct flexcan_priv *priv = netdev_priv(dev);
struct flexcan_regs __iomem *regs = priv->base;
u32 reg, err;
clk_prepare_enable(priv->clk);
flexcan_chip_disable(priv);
reg = flexcan_read(&regs->ctrl);
reg |= FLEXCAN_CTRL_CLK_SRC;
flexcan_write(reg, &regs->ctrl);
flexcan_chip_enable(priv);
reg = flexcan_read(&regs->mcr);
reg |= FLEXCAN_MCR_FRZ | FLEXCAN_MCR_HALT |
FLEXCAN_MCR_FEN | FLEXCAN_MCR_SUPV;
flexcan_write(reg, &regs->mcr);
reg = flexcan_read(&regs->mcr);
if (!(reg & FLEXCAN_MCR_FEN)) {
netdev_err(dev, "Could not enable RX FIFO, unsupported core\n");
err = -ENODEV;
goto out;
}
err = register_candev(dev);
out:
flexcan_chip_disable(priv);
clk_disable_unprepare(priv->clk);
return err;
}
static void __devexit unregister_flexcandev(struct net_device *dev)
{
unregister_candev(dev);
}
static int __devinit flexcan_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct flexcan_priv *priv;
struct resource *mem;
struct clk *clk = NULL;
void __iomem *base;
resource_size_t mem_size;
int err, irq;
u32 clock_freq = 0;
if (pdev->dev.of_node) {
const u32 *clock_freq_p;
clock_freq_p = of_get_property(pdev->dev.of_node,
"clock-frequency", NULL);
if (clock_freq_p)
clock_freq = *clock_freq_p;
}
if (!clock_freq) {
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "no clock defined\n");
err = PTR_ERR(clk);
goto failed_clock;
}
clock_freq = clk_get_rate(clk);
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!mem || irq <= 0) {
err = -ENODEV;
goto failed_get;
}
mem_size = resource_size(mem);
if (!request_mem_region(mem->start, mem_size, pdev->name)) {
err = -EBUSY;
goto failed_get;
}
base = ioremap(mem->start, mem_size);
if (!base) {
err = -ENOMEM;
goto failed_map;
}
dev = alloc_candev(sizeof(struct flexcan_priv), 1);
if (!dev) {
err = -ENOMEM;
goto failed_alloc;
}
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
priv->clk = clk;
priv->pdata = pdev->dev.platform_data;
netif_napi_add(dev, &priv->napi, flexcan_poll, FLEXCAN_NAPI_WEIGHT);
dev_set_drvdata(&pdev->dev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_flexcandev(dev);
if (err) {
dev_err(&pdev->dev, "registering netdev failed\n");
goto failed_register;
}
dev_info(&pdev->dev, "device registered (reg_base=%p, irq=%d)\n",
priv->base, dev->irq);
return 0;
failed_register:
free_candev(dev);
failed_alloc:
iounmap(base);
failed_map:
release_mem_region(mem->start, mem_size);
failed_get:
if (clk)
clk_put(clk);
failed_clock:
return err;
}
static int __devexit flexcan_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct flexcan_priv *priv = netdev_priv(dev);
struct resource *mem;
unregister_flexcandev(dev);
platform_set_drvdata(pdev, NULL);
iounmap(priv->base);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
if (priv->clk)
clk_put(priv->clk);
free_candev(dev);
return 0;
}
