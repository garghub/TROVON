static int bfin_can_set_bittiming(struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
struct can_bittiming *bt = &priv->can.bittiming;
u16 clk, timing;
clk = bt->brp - 1;
timing = ((bt->sjw - 1) << 8) | (bt->prop_seg + bt->phase_seg1 - 1) |
((bt->phase_seg2 - 1) << 4);
if (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES)
timing |= SAM;
writew(clk, &reg->clock);
writew(timing, &reg->timing);
netdev_info(dev, "setting CLOCK=0x%04x TIMING=0x%04x\n", clk, timing);
return 0;
}
static void bfin_can_set_reset_mode(struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
int timeout = BFIN_CAN_TIMEOUT;
int i;
writew(0, &reg->mbim1);
writew(0, &reg->mbim2);
writew(0, &reg->gim);
writew(SRS | CCR, &reg->control);
writew(CCR, &reg->control);
while (!(readw(&reg->control) & CCA)) {
udelay(10);
if (--timeout == 0) {
netdev_err(dev, "fail to enter configuration mode\n");
BUG();
}
}
writew(0, &reg->mc1);
writew(0, &reg->mc2);
writew(0xFFFF, &reg->md1);
writew(0, &reg->md2);
for (i = 0; i < 2; i++) {
writew(0, &reg->chl[RECEIVE_STD_CHL + i].id0);
writew(AME, &reg->chl[RECEIVE_STD_CHL + i].id1);
writew(0, &reg->chl[RECEIVE_STD_CHL + i].dlc);
writew(0x1FFF, &reg->msk[RECEIVE_STD_CHL + i].amh);
writew(0xFFFF, &reg->msk[RECEIVE_STD_CHL + i].aml);
}
for (i = 0; i < 2; i++) {
writew(0, &reg->chl[RECEIVE_EXT_CHL + i].id0);
writew(AME | IDE, &reg->chl[RECEIVE_EXT_CHL + i].id1);
writew(0, &reg->chl[RECEIVE_EXT_CHL + i].dlc);
writew(0x1FFF, &reg->msk[RECEIVE_EXT_CHL + i].amh);
writew(0xFFFF, &reg->msk[RECEIVE_EXT_CHL + i].aml);
}
writew(BIT(TRANSMIT_CHL - 16), &reg->mc2);
writew(BIT(RECEIVE_STD_CHL) + BIT(RECEIVE_EXT_CHL), &reg->mc1);
priv->can.state = CAN_STATE_STOPPED;
}
static void bfin_can_set_normal_mode(struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
int timeout = BFIN_CAN_TIMEOUT;
writew(readw(&reg->control) & ~CCR, &reg->control);
while (readw(&reg->status) & CCA) {
udelay(10);
if (--timeout == 0) {
netdev_err(dev, "fail to leave configuration mode\n");
BUG();
}
}
writew(0xFFFF, &reg->mbtif1);
writew(0xFFFF, &reg->mbtif2);
writew(0xFFFF, &reg->mbrif1);
writew(0xFFFF, &reg->mbrif2);
writew(0x7FF, &reg->gis);
writew(BIT(RECEIVE_STD_CHL) + BIT(RECEIVE_EXT_CHL), &reg->mbim1);
writew(BIT(TRANSMIT_CHL - 16), &reg->mbim2);
writew(EPIM | BOIM | RMLIM, &reg->gim);
}
static void bfin_can_start(struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
if (priv->can.state != CAN_STATE_STOPPED)
bfin_can_set_reset_mode(dev);
bfin_can_set_normal_mode(dev);
}
static int bfin_can_set_mode(struct net_device *dev, enum can_mode mode)
{
switch (mode) {
case CAN_MODE_START:
bfin_can_start(dev);
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int bfin_can_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
u16 cec = readw(&reg->cec);
bec->txerr = cec >> 8;
bec->rxerr = cec;
return 0;
}
static int bfin_can_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
struct can_frame *cf = (struct can_frame *)skb->data;
u8 dlc = cf->can_dlc;
canid_t id = cf->can_id;
u8 *data = cf->data;
u16 val;
int i;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
netif_stop_queue(dev);
if (id & CAN_EFF_FLAG) {
writew(id, &reg->chl[TRANSMIT_CHL].id0);
val = ((id & 0x1FFF0000) >> 16) | IDE;
} else
val = (id << 2);
if (id & CAN_RTR_FLAG)
val |= RTR;
writew(val | AME, &reg->chl[TRANSMIT_CHL].id1);
for (i = 0; i < 8; i += 2) {
val = ((7 - i) < dlc ? (data[7 - i]) : 0) +
((6 - i) < dlc ? (data[6 - i] << 8) : 0);
writew(val, &reg->chl[TRANSMIT_CHL].data[i]);
}
writew(dlc, &reg->chl[TRANSMIT_CHL].dlc);
can_put_echo_skb(skb, dev, 0);
writew(BIT(TRANSMIT_CHL - 16), &reg->trs2);
return 0;
}
static void bfin_can_rx(struct net_device *dev, u16 isrc)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct bfin_can_regs __iomem *reg = priv->membase;
struct can_frame *cf;
struct sk_buff *skb;
int obj;
int i;
u16 val;
skb = alloc_can_skb(dev, &cf);
if (skb == NULL)
return;
if (isrc & BIT(RECEIVE_EXT_CHL)) {
cf->can_id = ((readw(&reg->chl[RECEIVE_EXT_CHL].id1)
& 0x1FFF) << 16)
+ readw(&reg->chl[RECEIVE_EXT_CHL].id0);
cf->can_id |= CAN_EFF_FLAG;
obj = RECEIVE_EXT_CHL;
} else {
cf->can_id = (readw(&reg->chl[RECEIVE_STD_CHL].id1)
& 0x1ffc) >> 2;
obj = RECEIVE_STD_CHL;
}
if (readw(&reg->chl[obj].id1) & RTR)
cf->can_id |= CAN_RTR_FLAG;
cf->can_dlc = get_can_dlc(readw(&reg->chl[obj].dlc) & 0xF);
for (i = 0; i < 8; i += 2) {
val = readw(&reg->chl[obj].data[i]);
cf->data[7 - i] = (7 - i) < cf->can_dlc ? val : 0;
cf->data[6 - i] = (6 - i) < cf->can_dlc ? (val >> 8) : 0;
}
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
static int bfin_can_err(struct net_device *dev, u16 isrc, u16 status)
{
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
enum can_state state = priv->can.state;
skb = alloc_can_err_skb(dev, &cf);
if (skb == NULL)
return -ENOMEM;
if (isrc & RMLIS) {
netdev_dbg(dev, "data overrun interrupt\n");
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_over_errors++;
stats->rx_errors++;
}
if (isrc & BOIS) {
netdev_dbg(dev, "bus-off mode interrupt\n");
state = CAN_STATE_BUS_OFF;
cf->can_id |= CAN_ERR_BUSOFF;
priv->can.can_stats.bus_off++;
can_bus_off(dev);
}
if (isrc & EPIS) {
netdev_dbg(dev, "error passive interrupt\n");
state = CAN_STATE_ERROR_PASSIVE;
}
if ((isrc & EWTIS) || (isrc & EWRIS)) {
netdev_dbg(dev, "Error Warning Transmit/Receive Interrupt\n");
state = CAN_STATE_ERROR_WARNING;
}
if (state != priv->can.state && (state == CAN_STATE_ERROR_WARNING ||
state == CAN_STATE_ERROR_PASSIVE)) {
u16 cec = readw(&reg->cec);
u8 rxerr = cec;
u8 txerr = cec >> 8;
cf->can_id |= CAN_ERR_CRTL;
if (state == CAN_STATE_ERROR_WARNING) {
priv->can.can_stats.error_warning++;
cf->data[1] = (txerr > rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
} else {
priv->can.can_stats.error_passive++;
cf->data[1] = (txerr > rxerr) ?
CAN_ERR_CRTL_TX_PASSIVE :
CAN_ERR_CRTL_RX_PASSIVE;
}
}
if (status) {
priv->can.can_stats.bus_error++;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
if (status & BEF)
cf->data[2] |= CAN_ERR_PROT_BIT;
else if (status & FER)
cf->data[2] |= CAN_ERR_PROT_FORM;
else if (status & SER)
cf->data[2] |= CAN_ERR_PROT_STUFF;
else
cf->data[2] |= CAN_ERR_PROT_UNSPEC;
}
priv->can.state = state;
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
return 0;
}
static irqreturn_t bfin_can_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
struct net_device_stats *stats = &dev->stats;
u16 status, isrc;
if ((irq == priv->tx_irq) && readw(&reg->mbtif2)) {
writew(0xFFFF, &reg->mbtif2);
stats->tx_packets++;
stats->tx_bytes += readw(&reg->chl[TRANSMIT_CHL].dlc);
can_get_echo_skb(dev, 0);
netif_wake_queue(dev);
} else if ((irq == priv->rx_irq) && readw(&reg->mbrif1)) {
isrc = readw(&reg->mbrif1);
writew(0xFFFF, &reg->mbrif1);
bfin_can_rx(dev, isrc);
} else if ((irq == priv->err_irq) && readw(&reg->gis)) {
isrc = readw(&reg->gis);
status = readw(&reg->esr);
writew(0x7FF, &reg->gis);
bfin_can_err(dev, isrc, status);
} else {
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int bfin_can_open(struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
int err;
bfin_can_set_reset_mode(dev);
err = open_candev(dev);
if (err)
goto exit_open;
err = request_irq(priv->rx_irq, &bfin_can_interrupt, 0,
"bfin-can-rx", dev);
if (err)
goto exit_rx_irq;
err = request_irq(priv->tx_irq, &bfin_can_interrupt, 0,
"bfin-can-tx", dev);
if (err)
goto exit_tx_irq;
err = request_irq(priv->err_irq, &bfin_can_interrupt, 0,
"bfin-can-err", dev);
if (err)
goto exit_err_irq;
bfin_can_start(dev);
netif_start_queue(dev);
return 0;
exit_err_irq:
free_irq(priv->tx_irq, dev);
exit_tx_irq:
free_irq(priv->rx_irq, dev);
exit_rx_irq:
close_candev(dev);
exit_open:
return err;
}
static int bfin_can_close(struct net_device *dev)
{
struct bfin_can_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
bfin_can_set_reset_mode(dev);
close_candev(dev);
free_irq(priv->rx_irq, dev);
free_irq(priv->tx_irq, dev);
free_irq(priv->err_irq, dev);
return 0;
}
static struct net_device *alloc_bfin_candev(void)
{
struct net_device *dev;
struct bfin_can_priv *priv;
dev = alloc_candev(sizeof(*priv), TX_ECHO_SKB_MAX);
if (!dev)
return NULL;
priv = netdev_priv(dev);
priv->dev = dev;
priv->can.bittiming_const = &bfin_can_bittiming_const;
priv->can.do_set_bittiming = bfin_can_set_bittiming;
priv->can.do_set_mode = bfin_can_set_mode;
priv->can.do_get_berr_counter = bfin_can_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_3_SAMPLES;
return dev;
}
static int bfin_can_probe(struct platform_device *pdev)
{
int err;
struct net_device *dev;
struct bfin_can_priv *priv;
struct resource *res_mem, *rx_irq, *tx_irq, *err_irq;
unsigned short *pdata;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "No platform data provided!\n");
err = -EINVAL;
goto exit;
}
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rx_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
tx_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
err_irq = platform_get_resource(pdev, IORESOURCE_IRQ, 2);
if (!res_mem || !rx_irq || !tx_irq || !err_irq) {
err = -EINVAL;
goto exit;
}
err = peripheral_request_list(pdata, dev_name(&pdev->dev));
if (err)
goto exit;
dev = alloc_bfin_candev();
if (!dev) {
err = -ENOMEM;
goto exit_peri_pin_free;
}
priv = netdev_priv(dev);
priv->membase = devm_ioremap_resource(&pdev->dev, res_mem);
if (IS_ERR(priv->membase)) {
err = PTR_ERR(priv->membase);
goto exit_peri_pin_free;
}
priv->rx_irq = rx_irq->start;
priv->tx_irq = tx_irq->start;
priv->err_irq = err_irq->start;
priv->pin_list = pdata;
priv->can.clock.freq = get_sclk();
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
dev->flags |= IFF_ECHO;
dev->netdev_ops = &bfin_can_netdev_ops;
bfin_can_set_reset_mode(dev);
err = register_candev(dev);
if (err) {
dev_err(&pdev->dev, "registering failed (err=%d)\n", err);
goto exit_candev_free;
}
dev_info(&pdev->dev,
"%s device registered"
"(&reg_base=%p, rx_irq=%d, tx_irq=%d, err_irq=%d, sclk=%d)\n",
DRV_NAME, priv->membase, priv->rx_irq,
priv->tx_irq, priv->err_irq, priv->can.clock.freq);
return 0;
exit_candev_free:
free_candev(dev);
exit_peri_pin_free:
peripheral_free_list(pdata);
exit:
return err;
}
static int bfin_can_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct bfin_can_priv *priv = netdev_priv(dev);
bfin_can_set_reset_mode(dev);
unregister_candev(dev);
peripheral_free_list(priv->pin_list);
free_candev(dev);
return 0;
}
static int bfin_can_suspend(struct platform_device *pdev, pm_message_t mesg)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
int timeout = BFIN_CAN_TIMEOUT;
if (netif_running(dev)) {
writew(readw(&reg->control) | SMR, &reg->control);
while (!(readw(&reg->intr) & SMACK)) {
udelay(10);
if (--timeout == 0) {
netdev_err(dev, "fail to enter sleep mode\n");
BUG();
}
}
}
return 0;
}
static int bfin_can_resume(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct bfin_can_priv *priv = netdev_priv(dev);
struct bfin_can_regs __iomem *reg = priv->membase;
if (netif_running(dev)) {
writew(0, &reg->intr);
}
return 0;
}
