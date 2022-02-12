static void xcan_write_reg_le(const struct xcan_priv *priv, enum xcan_reg reg,
u32 val)
{
iowrite32(val, priv->reg_base + reg);
}
static u32 xcan_read_reg_le(const struct xcan_priv *priv, enum xcan_reg reg)
{
return ioread32(priv->reg_base + reg);
}
static void xcan_write_reg_be(const struct xcan_priv *priv, enum xcan_reg reg,
u32 val)
{
iowrite32be(val, priv->reg_base + reg);
}
static u32 xcan_read_reg_be(const struct xcan_priv *priv, enum xcan_reg reg)
{
return ioread32be(priv->reg_base + reg);
}
static int set_reset_mode(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
unsigned long timeout;
priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
timeout = jiffies + XCAN_TIMEOUT;
while (!(priv->read_reg(priv, XCAN_SR_OFFSET) & XCAN_SR_CONFIG_MASK)) {
if (time_after(jiffies, timeout)) {
netdev_warn(ndev, "timed out for config mode\n");
return -ETIMEDOUT;
}
usleep_range(500, 10000);
}
return 0;
}
static int xcan_set_bittiming(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
struct can_bittiming *bt = &priv->can.bittiming;
u32 btr0, btr1;
u32 is_config_mode;
is_config_mode = priv->read_reg(priv, XCAN_SR_OFFSET) &
XCAN_SR_CONFIG_MASK;
if (!is_config_mode) {
netdev_alert(ndev,
"BUG! Cannot set bittiming - CAN is not in config mode\n");
return -EPERM;
}
btr0 = (bt->brp - 1);
btr1 = (bt->prop_seg + bt->phase_seg1 - 1);
btr1 |= (bt->phase_seg2 - 1) << XCAN_BTR_TS2_SHIFT;
btr1 |= (bt->sjw - 1) << XCAN_BTR_SJW_SHIFT;
priv->write_reg(priv, XCAN_BRPR_OFFSET, btr0);
priv->write_reg(priv, XCAN_BTR_OFFSET, btr1);
netdev_dbg(ndev, "BRPR=0x%08x, BTR=0x%08x\n",
priv->read_reg(priv, XCAN_BRPR_OFFSET),
priv->read_reg(priv, XCAN_BTR_OFFSET));
return 0;
}
static int xcan_chip_start(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
u32 reg_msr, reg_sr_mask;
int err;
unsigned long timeout;
err = set_reset_mode(ndev);
if (err < 0)
return err;
err = xcan_set_bittiming(ndev);
if (err < 0)
return err;
priv->write_reg(priv, XCAN_IER_OFFSET, XCAN_INTR_ALL);
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK) {
reg_msr = XCAN_MSR_LBACK_MASK;
reg_sr_mask = XCAN_SR_LBACK_MASK;
} else {
reg_msr = 0x0;
reg_sr_mask = XCAN_SR_NORMAL_MASK;
}
priv->write_reg(priv, XCAN_MSR_OFFSET, reg_msr);
priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_CEN_MASK);
timeout = jiffies + XCAN_TIMEOUT;
while (!(priv->read_reg(priv, XCAN_SR_OFFSET) & reg_sr_mask)) {
if (time_after(jiffies, timeout)) {
netdev_warn(ndev,
"timed out for correct mode\n");
return -ETIMEDOUT;
}
}
netdev_dbg(ndev, "status:#x%08x\n",
priv->read_reg(priv, XCAN_SR_OFFSET));
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
}
static int xcan_do_set_mode(struct net_device *ndev, enum can_mode mode)
{
int ret;
switch (mode) {
case CAN_MODE_START:
ret = xcan_chip_start(ndev);
if (ret < 0) {
netdev_err(ndev, "xcan_chip_start failed!\n");
return ret;
}
netif_wake_queue(ndev);
break;
default:
ret = -EOPNOTSUPP;
break;
}
return ret;
}
static int xcan_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf = (struct can_frame *)skb->data;
u32 id, dlc, data[2] = {0, 0};
if (can_dropped_invalid_skb(ndev, skb))
return NETDEV_TX_OK;
if (unlikely(priv->read_reg(priv, XCAN_SR_OFFSET) &
XCAN_SR_TXFLL_MASK)) {
netif_stop_queue(ndev);
netdev_err(ndev, "BUG!, TX FIFO full when queue awake!\n");
return NETDEV_TX_BUSY;
}
if (cf->can_id & CAN_EFF_FLAG) {
id = ((cf->can_id & CAN_EFF_MASK) << XCAN_IDR_ID2_SHIFT) &
XCAN_IDR_ID2_MASK;
id |= (((cf->can_id & CAN_EFF_MASK) >>
(CAN_EFF_ID_BITS-CAN_SFF_ID_BITS)) <<
XCAN_IDR_ID1_SHIFT) & XCAN_IDR_ID1_MASK;
id |= XCAN_IDR_IDE_MASK | XCAN_IDR_SRR_MASK;
if (cf->can_id & CAN_RTR_FLAG)
id |= XCAN_IDR_RTR_MASK;
} else {
id = ((cf->can_id & CAN_SFF_MASK) << XCAN_IDR_ID1_SHIFT) &
XCAN_IDR_ID1_MASK;
if (cf->can_id & CAN_RTR_FLAG)
id |= XCAN_IDR_SRR_MASK;
}
dlc = cf->can_dlc << XCAN_DLCR_DLC_SHIFT;
if (cf->can_dlc > 0)
data[0] = be32_to_cpup((__be32 *)(cf->data + 0));
if (cf->can_dlc > 4)
data[1] = be32_to_cpup((__be32 *)(cf->data + 4));
can_put_echo_skb(skb, ndev, priv->tx_head % priv->tx_max);
priv->tx_head++;
priv->write_reg(priv, XCAN_TXFIFO_ID_OFFSET, id);
priv->write_reg(priv, XCAN_TXFIFO_DLC_OFFSET, dlc);
if (!(cf->can_id & CAN_RTR_FLAG)) {
priv->write_reg(priv, XCAN_TXFIFO_DW1_OFFSET, data[0]);
priv->write_reg(priv, XCAN_TXFIFO_DW2_OFFSET, data[1]);
stats->tx_bytes += cf->can_dlc;
}
if ((priv->tx_head - priv->tx_tail) == priv->tx_max)
netif_stop_queue(ndev);
return NETDEV_TX_OK;
}
static int xcan_rx(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u32 id_xcan, dlc, data[2] = {0, 0};
skb = alloc_can_skb(ndev, &cf);
if (unlikely(!skb)) {
stats->rx_dropped++;
return 0;
}
id_xcan = priv->read_reg(priv, XCAN_RXFIFO_ID_OFFSET);
dlc = priv->read_reg(priv, XCAN_RXFIFO_DLC_OFFSET) >>
XCAN_DLCR_DLC_SHIFT;
cf->can_dlc = get_can_dlc(dlc);
if (id_xcan & XCAN_IDR_IDE_MASK) {
cf->can_id = (id_xcan & XCAN_IDR_ID1_MASK) >> 3;
cf->can_id |= (id_xcan & XCAN_IDR_ID2_MASK) >>
XCAN_IDR_ID2_SHIFT;
cf->can_id |= CAN_EFF_FLAG;
if (id_xcan & XCAN_IDR_RTR_MASK)
cf->can_id |= CAN_RTR_FLAG;
} else {
cf->can_id = (id_xcan & XCAN_IDR_ID1_MASK) >>
XCAN_IDR_ID1_SHIFT;
if (id_xcan & XCAN_IDR_SRR_MASK)
cf->can_id |= CAN_RTR_FLAG;
}
data[0] = priv->read_reg(priv, XCAN_RXFIFO_DW1_OFFSET);
data[1] = priv->read_reg(priv, XCAN_RXFIFO_DW2_OFFSET);
if (!(cf->can_id & CAN_RTR_FLAG)) {
if (cf->can_dlc > 0)
*(__be32 *)(cf->data) = cpu_to_be32(data[0]);
if (cf->can_dlc > 4)
*(__be32 *)(cf->data + 4) = cpu_to_be32(data[1]);
}
stats->rx_bytes += cf->can_dlc;
stats->rx_packets++;
netif_receive_skb(skb);
return 1;
}
static void xcan_err_interrupt(struct net_device *ndev, u32 isr)
{
struct xcan_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u32 err_status, status, txerr = 0, rxerr = 0;
skb = alloc_can_err_skb(ndev, &cf);
err_status = priv->read_reg(priv, XCAN_ESR_OFFSET);
priv->write_reg(priv, XCAN_ESR_OFFSET, err_status);
txerr = priv->read_reg(priv, XCAN_ECR_OFFSET) & XCAN_ECR_TEC_MASK;
rxerr = ((priv->read_reg(priv, XCAN_ECR_OFFSET) &
XCAN_ECR_REC_MASK) >> XCAN_ESR_REC_SHIFT);
status = priv->read_reg(priv, XCAN_SR_OFFSET);
if (isr & XCAN_IXR_BSOFF_MASK) {
priv->can.state = CAN_STATE_BUS_OFF;
priv->can.can_stats.bus_off++;
priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
can_bus_off(ndev);
if (skb)
cf->can_id |= CAN_ERR_BUSOFF;
} else if ((status & XCAN_SR_ESTAT_MASK) == XCAN_SR_ESTAT_MASK) {
priv->can.state = CAN_STATE_ERROR_PASSIVE;
priv->can.can_stats.error_passive++;
if (skb) {
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = (rxerr > 127) ?
CAN_ERR_CRTL_RX_PASSIVE :
CAN_ERR_CRTL_TX_PASSIVE;
cf->data[6] = txerr;
cf->data[7] = rxerr;
}
} else if (status & XCAN_SR_ERRWRN_MASK) {
priv->can.state = CAN_STATE_ERROR_WARNING;
priv->can.can_stats.error_warning++;
if (skb) {
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] |= (txerr > rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
cf->data[6] = txerr;
cf->data[7] = rxerr;
}
}
if (isr & XCAN_IXR_ARBLST_MASK) {
priv->can.can_stats.arbitration_lost++;
if (skb) {
cf->can_id |= CAN_ERR_LOSTARB;
cf->data[0] = CAN_ERR_LOSTARB_UNSPEC;
}
}
if (isr & XCAN_IXR_RXOFLW_MASK) {
stats->rx_over_errors++;
stats->rx_errors++;
priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
if (skb) {
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] |= CAN_ERR_CRTL_RX_OVERFLOW;
}
}
if (isr & XCAN_IXR_ERROR_MASK) {
if (skb)
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
if (err_status & XCAN_ESR_ACKER_MASK) {
stats->tx_errors++;
if (skb) {
cf->can_id |= CAN_ERR_ACK;
cf->data[3] = CAN_ERR_PROT_LOC_ACK;
}
}
if (err_status & XCAN_ESR_BERR_MASK) {
stats->tx_errors++;
if (skb) {
cf->can_id |= CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_BIT;
}
}
if (err_status & XCAN_ESR_STER_MASK) {
stats->rx_errors++;
if (skb) {
cf->can_id |= CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_STUFF;
}
}
if (err_status & XCAN_ESR_FMER_MASK) {
stats->rx_errors++;
if (skb) {
cf->can_id |= CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_FORM;
}
}
if (err_status & XCAN_ESR_CRCER_MASK) {
stats->rx_errors++;
if (skb) {
cf->can_id |= CAN_ERR_PROT;
cf->data[3] = CAN_ERR_PROT_LOC_CRC_SEQ;
}
}
priv->can.can_stats.bus_error++;
}
if (skb) {
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
netdev_dbg(ndev, "%s: error status register:0x%x\n",
__func__, priv->read_reg(priv, XCAN_ESR_OFFSET));
}
static void xcan_state_interrupt(struct net_device *ndev, u32 isr)
{
struct xcan_priv *priv = netdev_priv(ndev);
if (isr & XCAN_IXR_SLP_MASK)
priv->can.state = CAN_STATE_SLEEPING;
if (isr & XCAN_IXR_WKUP_MASK)
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
static int xcan_rx_poll(struct napi_struct *napi, int quota)
{
struct net_device *ndev = napi->dev;
struct xcan_priv *priv = netdev_priv(ndev);
u32 isr, ier;
int work_done = 0;
isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
while ((isr & XCAN_IXR_RXNEMP_MASK) && (work_done < quota)) {
if (isr & XCAN_IXR_RXOK_MASK) {
priv->write_reg(priv, XCAN_ICR_OFFSET,
XCAN_IXR_RXOK_MASK);
work_done += xcan_rx(ndev);
} else {
priv->write_reg(priv, XCAN_ICR_OFFSET,
XCAN_IXR_RXNEMP_MASK);
break;
}
priv->write_reg(priv, XCAN_ICR_OFFSET, XCAN_IXR_RXNEMP_MASK);
isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
}
if (work_done)
can_led_event(ndev, CAN_LED_EVENT_RX);
if (work_done < quota) {
napi_complete(napi);
ier = priv->read_reg(priv, XCAN_IER_OFFSET);
ier |= (XCAN_IXR_RXOK_MASK | XCAN_IXR_RXNEMP_MASK);
priv->write_reg(priv, XCAN_IER_OFFSET, ier);
}
return work_done;
}
static void xcan_tx_interrupt(struct net_device *ndev, u32 isr)
{
struct xcan_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
while ((priv->tx_head - priv->tx_tail > 0) &&
(isr & XCAN_IXR_TXOK_MASK)) {
priv->write_reg(priv, XCAN_ICR_OFFSET, XCAN_IXR_TXOK_MASK);
can_get_echo_skb(ndev, priv->tx_tail %
priv->tx_max);
priv->tx_tail++;
stats->tx_packets++;
isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
}
can_led_event(ndev, CAN_LED_EVENT_TX);
netif_wake_queue(ndev);
}
static irqreturn_t xcan_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct xcan_priv *priv = netdev_priv(ndev);
u32 isr, ier;
isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
if (!isr)
return IRQ_NONE;
if (isr & (XCAN_IXR_SLP_MASK | XCAN_IXR_WKUP_MASK)) {
priv->write_reg(priv, XCAN_ICR_OFFSET, (XCAN_IXR_SLP_MASK |
XCAN_IXR_WKUP_MASK));
xcan_state_interrupt(ndev, isr);
}
if (isr & XCAN_IXR_TXOK_MASK)
xcan_tx_interrupt(ndev, isr);
if (isr & (XCAN_IXR_ERROR_MASK | XCAN_IXR_RXOFLW_MASK |
XCAN_IXR_BSOFF_MASK | XCAN_IXR_ARBLST_MASK)) {
priv->write_reg(priv, XCAN_ICR_OFFSET, (XCAN_IXR_ERROR_MASK |
XCAN_IXR_RXOFLW_MASK | XCAN_IXR_BSOFF_MASK |
XCAN_IXR_ARBLST_MASK));
xcan_err_interrupt(ndev, isr);
}
if (isr & (XCAN_IXR_RXNEMP_MASK | XCAN_IXR_RXOK_MASK)) {
ier = priv->read_reg(priv, XCAN_IER_OFFSET);
ier &= ~(XCAN_IXR_RXNEMP_MASK | XCAN_IXR_RXOK_MASK);
priv->write_reg(priv, XCAN_IER_OFFSET, ier);
napi_schedule(&priv->napi);
}
return IRQ_HANDLED;
}
static void xcan_chip_stop(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
u32 ier;
ier = priv->read_reg(priv, XCAN_IER_OFFSET);
ier &= ~XCAN_INTR_ALL;
priv->write_reg(priv, XCAN_IER_OFFSET, ier);
priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
priv->can.state = CAN_STATE_STOPPED;
}
static int xcan_open(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
int ret;
ret = pm_runtime_get_sync(priv->dev);
if (ret < 0) {
netdev_err(ndev, "%s: pm_runtime_get failed(%d)\n",
__func__, ret);
return ret;
}
ret = request_irq(ndev->irq, xcan_interrupt, priv->irq_flags,
ndev->name, ndev);
if (ret < 0) {
netdev_err(ndev, "irq allocation for CAN failed\n");
goto err;
}
ret = set_reset_mode(ndev);
if (ret < 0) {
netdev_err(ndev, "mode resetting failed!\n");
goto err_irq;
}
ret = open_candev(ndev);
if (ret)
goto err_irq;
ret = xcan_chip_start(ndev);
if (ret < 0) {
netdev_err(ndev, "xcan_chip_start failed!\n");
goto err_candev;
}
can_led_event(ndev, CAN_LED_EVENT_OPEN);
napi_enable(&priv->napi);
netif_start_queue(ndev);
return 0;
err_candev:
close_candev(ndev);
err_irq:
free_irq(ndev->irq, ndev);
err:
pm_runtime_put(priv->dev);
return ret;
}
static int xcan_close(struct net_device *ndev)
{
struct xcan_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
napi_disable(&priv->napi);
xcan_chip_stop(ndev);
free_irq(ndev->irq, ndev);
close_candev(ndev);
can_led_event(ndev, CAN_LED_EVENT_STOP);
pm_runtime_put(priv->dev);
return 0;
}
static int xcan_get_berr_counter(const struct net_device *ndev,
struct can_berr_counter *bec)
{
struct xcan_priv *priv = netdev_priv(ndev);
int ret;
ret = pm_runtime_get_sync(priv->dev);
if (ret < 0) {
netdev_err(ndev, "%s: pm_runtime_get failed(%d)\n",
__func__, ret);
return ret;
}
bec->txerr = priv->read_reg(priv, XCAN_ECR_OFFSET) & XCAN_ECR_TEC_MASK;
bec->rxerr = ((priv->read_reg(priv, XCAN_ECR_OFFSET) &
XCAN_ECR_REC_MASK) >> XCAN_ESR_REC_SHIFT);
pm_runtime_put(priv->dev);
return 0;
}
static int __maybe_unused xcan_suspend(struct device *dev)
{
if (!device_may_wakeup(dev))
return pm_runtime_force_suspend(dev);
return 0;
}
static int __maybe_unused xcan_resume(struct device *dev)
{
if (!device_may_wakeup(dev))
return pm_runtime_force_resume(dev);
return 0;
}
static int __maybe_unused xcan_runtime_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct xcan_priv *priv = netdev_priv(ndev);
if (netif_running(ndev)) {
netif_stop_queue(ndev);
netif_device_detach(ndev);
}
priv->write_reg(priv, XCAN_MSR_OFFSET, XCAN_MSR_SLEEP_MASK);
priv->can.state = CAN_STATE_SLEEPING;
clk_disable_unprepare(priv->bus_clk);
clk_disable_unprepare(priv->can_clk);
return 0;
}
static int __maybe_unused xcan_runtime_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct xcan_priv *priv = netdev_priv(ndev);
int ret;
u32 isr, status;
ret = clk_prepare_enable(priv->bus_clk);
if (ret) {
dev_err(dev, "Cannot enable clock.\n");
return ret;
}
ret = clk_prepare_enable(priv->can_clk);
if (ret) {
dev_err(dev, "Cannot enable clock.\n");
clk_disable_unprepare(priv->bus_clk);
return ret;
}
priv->write_reg(priv, XCAN_SRR_OFFSET, XCAN_SRR_RESET_MASK);
isr = priv->read_reg(priv, XCAN_ISR_OFFSET);
status = priv->read_reg(priv, XCAN_SR_OFFSET);
if (netif_running(ndev)) {
if (isr & XCAN_IXR_BSOFF_MASK) {
priv->can.state = CAN_STATE_BUS_OFF;
priv->write_reg(priv, XCAN_SRR_OFFSET,
XCAN_SRR_RESET_MASK);
} else if ((status & XCAN_SR_ESTAT_MASK) ==
XCAN_SR_ESTAT_MASK) {
priv->can.state = CAN_STATE_ERROR_PASSIVE;
} else if (status & XCAN_SR_ERRWRN_MASK) {
priv->can.state = CAN_STATE_ERROR_WARNING;
} else {
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
netif_device_attach(ndev);
netif_start_queue(ndev);
}
return 0;
}
static int xcan_probe(struct platform_device *pdev)
{
struct resource *res;
struct net_device *ndev;
struct xcan_priv *priv;
void __iomem *addr;
int ret, rx_max, tx_max;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(addr)) {
ret = PTR_ERR(addr);
goto err;
}
ret = of_property_read_u32(pdev->dev.of_node, "tx-fifo-depth", &tx_max);
if (ret < 0)
goto err;
ret = of_property_read_u32(pdev->dev.of_node, "rx-fifo-depth", &rx_max);
if (ret < 0)
goto err;
ndev = alloc_candev(sizeof(struct xcan_priv), tx_max);
if (!ndev)
return -ENOMEM;
priv = netdev_priv(ndev);
priv->dev = &pdev->dev;
priv->can.bittiming_const = &xcan_bittiming_const;
priv->can.do_set_mode = xcan_do_set_mode;
priv->can.do_get_berr_counter = xcan_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_BERR_REPORTING;
priv->reg_base = addr;
priv->tx_max = tx_max;
ndev->irq = platform_get_irq(pdev, 0);
ndev->flags |= IFF_ECHO;
platform_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, &pdev->dev);
ndev->netdev_ops = &xcan_netdev_ops;
priv->can_clk = devm_clk_get(&pdev->dev, "can_clk");
if (IS_ERR(priv->can_clk)) {
dev_err(&pdev->dev, "Device clock not found.\n");
ret = PTR_ERR(priv->can_clk);
goto err_free;
}
if (of_device_is_compatible(pdev->dev.of_node,
"xlnx,zynq-can-1.0")) {
priv->bus_clk = devm_clk_get(&pdev->dev, "pclk");
if (IS_ERR(priv->bus_clk)) {
dev_err(&pdev->dev, "bus clock not found\n");
ret = PTR_ERR(priv->bus_clk);
goto err_free;
}
} else {
priv->bus_clk = devm_clk_get(&pdev->dev, "s_axi_aclk");
if (IS_ERR(priv->bus_clk)) {
dev_err(&pdev->dev, "bus clock not found\n");
ret = PTR_ERR(priv->bus_clk);
goto err_free;
}
}
priv->write_reg = xcan_write_reg_le;
priv->read_reg = xcan_read_reg_le;
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
netdev_err(ndev, "%s: pm_runtime_get failed(%d)\n",
__func__, ret);
goto err_pmdisable;
}
if (priv->read_reg(priv, XCAN_SR_OFFSET) != XCAN_SR_CONFIG_MASK) {
priv->write_reg = xcan_write_reg_be;
priv->read_reg = xcan_read_reg_be;
}
priv->can.clock.freq = clk_get_rate(priv->can_clk);
netif_napi_add(ndev, &priv->napi, xcan_rx_poll, rx_max);
ret = register_candev(ndev);
if (ret) {
dev_err(&pdev->dev, "fail to register failed (err=%d)\n", ret);
goto err_disableclks;
}
devm_can_led_init(ndev);
pm_runtime_put(&pdev->dev);
netdev_dbg(ndev, "reg_base=0x%p irq=%d clock=%d, tx fifo depth:%d\n",
priv->reg_base, ndev->irq, priv->can.clock.freq,
priv->tx_max);
return 0;
err_disableclks:
pm_runtime_put(priv->dev);
err_pmdisable:
pm_runtime_disable(&pdev->dev);
err_free:
free_candev(ndev);
err:
return ret;
}
static int xcan_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct xcan_priv *priv = netdev_priv(ndev);
unregister_candev(ndev);
pm_runtime_disable(&pdev->dev);
netif_napi_del(&priv->napi);
free_candev(ndev);
return 0;
}
