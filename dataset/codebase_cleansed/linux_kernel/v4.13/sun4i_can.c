static void sun4i_can_write_cmdreg(struct sun4ican_priv *priv, u8 val)
{
unsigned long flags;
spin_lock_irqsave(&priv->cmdreg_lock, flags);
writel(val, priv->base + SUN4I_REG_CMD_ADDR);
spin_unlock_irqrestore(&priv->cmdreg_lock, flags);
}
static int set_normal_mode(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
int retry = SUN4I_MODE_MAX_RETRIES;
u32 mod_reg_val = 0;
do {
mod_reg_val = readl(priv->base + SUN4I_REG_MSEL_ADDR);
mod_reg_val &= ~SUN4I_MSEL_RESET_MODE;
writel(mod_reg_val, priv->base + SUN4I_REG_MSEL_ADDR);
} while (retry-- && (mod_reg_val & SUN4I_MSEL_RESET_MODE));
if (readl(priv->base + SUN4I_REG_MSEL_ADDR) & SUN4I_MSEL_RESET_MODE) {
netdev_err(dev,
"setting controller into normal mode failed!\n");
return -ETIMEDOUT;
}
return 0;
}
static int set_reset_mode(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
int retry = SUN4I_MODE_MAX_RETRIES;
u32 mod_reg_val = 0;
do {
mod_reg_val = readl(priv->base + SUN4I_REG_MSEL_ADDR);
mod_reg_val |= SUN4I_MSEL_RESET_MODE;
writel(mod_reg_val, priv->base + SUN4I_REG_MSEL_ADDR);
} while (retry-- && !(mod_reg_val & SUN4I_MSEL_RESET_MODE));
if (!(readl(priv->base + SUN4I_REG_MSEL_ADDR) &
SUN4I_MSEL_RESET_MODE)) {
netdev_err(dev, "setting controller into reset mode failed!\n");
return -ETIMEDOUT;
}
return 0;
}
static int sun4ican_set_bittiming(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
struct can_bittiming *bt = &priv->can.bittiming;
u32 cfg;
cfg = ((bt->brp - 1) & 0x3FF) |
(((bt->sjw - 1) & 0x3) << 14) |
(((bt->prop_seg + bt->phase_seg1 - 1) & 0xf) << 16) |
(((bt->phase_seg2 - 1) & 0x7) << 20);
if (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES)
cfg |= 0x800000;
netdev_dbg(dev, "setting BITTIMING=0x%08x\n", cfg);
writel(cfg, priv->base + SUN4I_REG_BTIME_ADDR);
return 0;
}
static int sun4ican_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct sun4ican_priv *priv = netdev_priv(dev);
u32 errors;
int err;
err = clk_prepare_enable(priv->clk);
if (err) {
netdev_err(dev, "could not enable clock\n");
return err;
}
errors = readl(priv->base + SUN4I_REG_ERRC_ADDR);
bec->txerr = errors & 0xFF;
bec->rxerr = (errors >> 16) & 0xFF;
clk_disable_unprepare(priv->clk);
return 0;
}
static int sun4i_can_start(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
int err;
u32 mod_reg_val;
err = set_reset_mode(dev);
if (err) {
netdev_err(dev, "could not enter reset mode\n");
return err;
}
writel(0x00000000, priv->base + SUN4I_REG_ACPC_ADDR);
writel(0xFFFFFFFF, priv->base + SUN4I_REG_ACPM_ADDR);
writel(0, priv->base + SUN4I_REG_ERRC_ADDR);
if (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING)
writel(0xFF, priv->base + SUN4I_REG_INTEN_ADDR);
else
writel(0xFF & ~SUN4I_INTEN_BERR,
priv->base + SUN4I_REG_INTEN_ADDR);
mod_reg_val = readl(priv->base + SUN4I_REG_MSEL_ADDR);
if (priv->can.ctrlmode & CAN_CTRLMODE_PRESUME_ACK)
mod_reg_val |= SUN4I_MSEL_LOOPBACK_MODE;
else if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
mod_reg_val |= SUN4I_MSEL_LISTEN_ONLY_MODE;
writel(mod_reg_val, priv->base + SUN4I_REG_MSEL_ADDR);
err = sun4ican_set_bittiming(dev);
if (err)
return err;
err = set_normal_mode(dev);
if (err) {
netdev_err(dev, "could not enter normal mode\n");
return err;
}
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
}
static int sun4i_can_stop(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
int err;
priv->can.state = CAN_STATE_STOPPED;
err = set_reset_mode(dev);
if (err) {
netdev_err(dev, "could not enter reset mode\n");
return err;
}
writel(0, priv->base + SUN4I_REG_INTEN_ADDR);
return 0;
}
static int sun4ican_set_mode(struct net_device *dev, enum can_mode mode)
{
int err;
switch (mode) {
case CAN_MODE_START:
err = sun4i_can_start(dev);
if (err) {
netdev_err(dev, "starting CAN controller failed!\n");
return err;
}
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int sun4ican_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
struct can_frame *cf = (struct can_frame *)skb->data;
u8 dlc;
u32 dreg, msg_flag_n;
canid_t id;
int i;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
netif_stop_queue(dev);
id = cf->can_id;
dlc = cf->can_dlc;
msg_flag_n = dlc;
if (id & CAN_RTR_FLAG)
msg_flag_n |= SUN4I_MSG_RTR_FLAG;
if (id & CAN_EFF_FLAG) {
msg_flag_n |= SUN4I_MSG_EFF_FLAG;
dreg = SUN4I_REG_BUF5_ADDR;
writel((id >> 21) & 0xFF, priv->base + SUN4I_REG_BUF1_ADDR);
writel((id >> 13) & 0xFF, priv->base + SUN4I_REG_BUF2_ADDR);
writel((id >> 5) & 0xFF, priv->base + SUN4I_REG_BUF3_ADDR);
writel((id << 3) & 0xF8, priv->base + SUN4I_REG_BUF4_ADDR);
} else {
dreg = SUN4I_REG_BUF3_ADDR;
writel((id >> 3) & 0xFF, priv->base + SUN4I_REG_BUF1_ADDR);
writel((id << 5) & 0xE0, priv->base + SUN4I_REG_BUF2_ADDR);
}
for (i = 0; i < dlc; i++)
writel(cf->data[i], priv->base + (dreg + i * 4));
writel(msg_flag_n, priv->base + SUN4I_REG_BUF0_ADDR);
can_put_echo_skb(skb, dev, 0);
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)
sun4i_can_write_cmdreg(priv, SUN4I_CMD_SELF_RCV_REQ);
else
sun4i_can_write_cmdreg(priv, SUN4I_CMD_TRANS_REQ);
return NETDEV_TX_OK;
}
static void sun4i_can_rx(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u8 fi;
u32 dreg;
canid_t id;
int i;
skb = alloc_can_skb(dev, &cf);
if (!skb)
return;
fi = readl(priv->base + SUN4I_REG_BUF0_ADDR);
cf->can_dlc = get_can_dlc(fi & 0x0F);
if (fi & SUN4I_MSG_EFF_FLAG) {
dreg = SUN4I_REG_BUF5_ADDR;
id = (readl(priv->base + SUN4I_REG_BUF1_ADDR) << 21) |
(readl(priv->base + SUN4I_REG_BUF2_ADDR) << 13) |
(readl(priv->base + SUN4I_REG_BUF3_ADDR) << 5) |
((readl(priv->base + SUN4I_REG_BUF4_ADDR) >> 3) & 0x1f);
id |= CAN_EFF_FLAG;
} else {
dreg = SUN4I_REG_BUF3_ADDR;
id = (readl(priv->base + SUN4I_REG_BUF1_ADDR) << 3) |
((readl(priv->base + SUN4I_REG_BUF2_ADDR) >> 5) & 0x7);
}
if (fi & SUN4I_MSG_RTR_FLAG)
id |= CAN_RTR_FLAG;
else
for (i = 0; i < cf->can_dlc; i++)
cf->data[i] = readl(priv->base + dreg + i * 4);
cf->can_id = id;
sun4i_can_write_cmdreg(priv, SUN4I_CMD_RELEASE_RBUF);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
can_led_event(dev, CAN_LED_EVENT_RX);
}
static int sun4i_can_err(struct net_device *dev, u8 isrc, u8 status)
{
struct sun4ican_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
enum can_state state = priv->can.state;
enum can_state rx_state, tx_state;
unsigned int rxerr, txerr, errc;
u32 ecc, alc;
skb = alloc_can_err_skb(dev, &cf);
errc = readl(priv->base + SUN4I_REG_ERRC_ADDR);
rxerr = (errc >> 16) & 0xFF;
txerr = errc & 0xFF;
if (skb) {
cf->data[6] = txerr;
cf->data[7] = rxerr;
}
if (isrc & SUN4I_INT_DATA_OR) {
netdev_dbg(dev, "data overrun interrupt\n");
if (likely(skb)) {
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
}
stats->rx_over_errors++;
stats->rx_errors++;
sun4i_can_write_cmdreg(priv, SUN4I_CMD_CLEAR_OR_FLAG);
}
if (isrc & SUN4I_INT_ERR_WRN) {
netdev_dbg(dev, "error warning interrupt\n");
if (status & SUN4I_STA_BUS_OFF)
state = CAN_STATE_BUS_OFF;
else if (status & SUN4I_STA_ERR_STA)
state = CAN_STATE_ERROR_WARNING;
else
state = CAN_STATE_ERROR_ACTIVE;
}
if (isrc & SUN4I_INT_BUS_ERR) {
netdev_dbg(dev, "bus error interrupt\n");
priv->can.can_stats.bus_error++;
stats->rx_errors++;
if (likely(skb)) {
ecc = readl(priv->base + SUN4I_REG_STA_ADDR);
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
switch (ecc & SUN4I_STA_MASK_ERR) {
case SUN4I_STA_BIT_ERR:
cf->data[2] |= CAN_ERR_PROT_BIT;
break;
case SUN4I_STA_FORM_ERR:
cf->data[2] |= CAN_ERR_PROT_FORM;
break;
case SUN4I_STA_STUFF_ERR:
cf->data[2] |= CAN_ERR_PROT_STUFF;
break;
default:
cf->data[3] = (ecc & SUN4I_STA_ERR_SEG_CODE)
>> 16;
break;
}
if ((ecc & SUN4I_STA_ERR_DIR) == 0)
cf->data[2] |= CAN_ERR_PROT_TX;
}
}
if (isrc & SUN4I_INT_ERR_PASSIVE) {
netdev_dbg(dev, "error passive interrupt\n");
if (state == CAN_STATE_ERROR_PASSIVE)
state = CAN_STATE_ERROR_WARNING;
else
state = CAN_STATE_ERROR_PASSIVE;
}
if (isrc & SUN4I_INT_ARB_LOST) {
netdev_dbg(dev, "arbitration lost interrupt\n");
alc = readl(priv->base + SUN4I_REG_STA_ADDR);
priv->can.can_stats.arbitration_lost++;
stats->tx_errors++;
if (likely(skb)) {
cf->can_id |= CAN_ERR_LOSTARB;
cf->data[0] = (alc >> 8) & 0x1f;
}
}
if (state != priv->can.state) {
tx_state = txerr >= rxerr ? state : 0;
rx_state = txerr <= rxerr ? state : 0;
if (likely(skb))
can_change_state(dev, cf, tx_state, rx_state);
else
priv->can.state = state;
if (state == CAN_STATE_BUS_OFF)
can_bus_off(dev);
}
if (likely(skb)) {
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
} else {
return -ENOMEM;
}
return 0;
}
static irqreturn_t sun4i_can_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct sun4ican_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
u8 isrc, status;
int n = 0;
while ((isrc = readl(priv->base + SUN4I_REG_INT_ADDR)) &&
(n < SUN4I_CAN_MAX_IRQ)) {
n++;
status = readl(priv->base + SUN4I_REG_STA_ADDR);
if (isrc & SUN4I_INT_WAKEUP)
netdev_warn(dev, "wakeup interrupt\n");
if (isrc & SUN4I_INT_TBUF_VLD) {
stats->tx_bytes +=
readl(priv->base +
SUN4I_REG_RBUF_RBACK_START_ADDR) & 0xf;
stats->tx_packets++;
can_get_echo_skb(dev, 0);
netif_wake_queue(dev);
can_led_event(dev, CAN_LED_EVENT_TX);
}
if (isrc & SUN4I_INT_RBUF_VLD) {
while (status & SUN4I_STA_RBUF_RDY) {
sun4i_can_rx(dev);
status = readl(priv->base + SUN4I_REG_STA_ADDR);
}
}
if (isrc &
(SUN4I_INT_DATA_OR | SUN4I_INT_ERR_WRN | SUN4I_INT_BUS_ERR |
SUN4I_INT_ERR_PASSIVE | SUN4I_INT_ARB_LOST)) {
if (sun4i_can_err(dev, isrc, status))
netdev_err(dev, "can't allocate buffer - clearing pending interrupts\n");
}
writel(isrc, priv->base + SUN4I_REG_INT_ADDR);
readl(priv->base + SUN4I_REG_INT_ADDR);
}
if (n >= SUN4I_CAN_MAX_IRQ)
netdev_dbg(dev, "%d messages handled in ISR", n);
return (n) ? IRQ_HANDLED : IRQ_NONE;
}
static int sun4ican_open(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
int err;
err = open_candev(dev);
if (err)
return err;
err = request_irq(dev->irq, sun4i_can_interrupt, 0, dev->name, dev);
if (err) {
netdev_err(dev, "request_irq err: %d\n", err);
goto exit_irq;
}
err = clk_prepare_enable(priv->clk);
if (err) {
netdev_err(dev, "could not enable CAN peripheral clock\n");
goto exit_clock;
}
err = sun4i_can_start(dev);
if (err) {
netdev_err(dev, "could not start CAN peripheral\n");
goto exit_can_start;
}
can_led_event(dev, CAN_LED_EVENT_OPEN);
netif_start_queue(dev);
return 0;
exit_can_start:
clk_disable_unprepare(priv->clk);
exit_clock:
free_irq(dev->irq, dev);
exit_irq:
close_candev(dev);
return err;
}
static int sun4ican_close(struct net_device *dev)
{
struct sun4ican_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
sun4i_can_stop(dev);
clk_disable_unprepare(priv->clk);
free_irq(dev->irq, dev);
close_candev(dev);
can_led_event(dev, CAN_LED_EVENT_STOP);
return 0;
}
static int sun4ican_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
unregister_netdev(dev);
free_candev(dev);
return 0;
}
static int sun4ican_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *mem;
struct clk *clk;
void __iomem *addr;
int err, irq;
struct net_device *dev;
struct sun4ican_priv *priv;
clk = of_clk_get(np, 0);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "unable to request clock\n");
err = -ENODEV;
goto exit;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "could not get a valid irq\n");
err = -ENODEV;
goto exit;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(addr)) {
err = -EBUSY;
goto exit;
}
dev = alloc_candev(sizeof(struct sun4ican_priv), 1);
if (!dev) {
dev_err(&pdev->dev,
"could not allocate memory for CAN device\n");
err = -ENOMEM;
goto exit;
}
dev->netdev_ops = &sun4ican_netdev_ops;
dev->irq = irq;
dev->flags |= IFF_ECHO;
priv = netdev_priv(dev);
priv->can.clock.freq = clk_get_rate(clk);
priv->can.bittiming_const = &sun4ican_bittiming_const;
priv->can.do_set_mode = sun4ican_set_mode;
priv->can.do_get_berr_counter = sun4ican_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_BERR_REPORTING |
CAN_CTRLMODE_LISTENONLY |
CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_PRESUME_ACK |
CAN_CTRLMODE_3_SAMPLES;
priv->base = addr;
priv->clk = clk;
spin_lock_init(&priv->cmdreg_lock);
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_candev(dev);
if (err) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
DRV_NAME, err);
goto exit_free;
}
devm_can_led_init(dev);
dev_info(&pdev->dev, "device registered (base=%p, irq=%d)\n",
priv->base, dev->irq);
return 0;
exit_free:
free_candev(dev);
exit:
return err;
}
