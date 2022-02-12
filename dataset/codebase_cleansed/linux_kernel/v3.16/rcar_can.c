static void tx_failure_cleanup(struct net_device *ndev)
{
int i;
for (i = 0; i < RCAR_CAN_FIFO_DEPTH; i++)
can_free_echo_skb(ndev, i);
}
static void rcar_can_error(struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u8 eifr, txerr = 0, rxerr = 0;
skb = alloc_can_err_skb(ndev, &cf);
eifr = readb(&priv->regs->eifr);
if (eifr & (RCAR_CAN_EIFR_EWIF | RCAR_CAN_EIFR_EPIF)) {
txerr = readb(&priv->regs->tecr);
rxerr = readb(&priv->regs->recr);
if (skb) {
cf->can_id |= CAN_ERR_CRTL;
cf->data[6] = txerr;
cf->data[7] = rxerr;
}
}
if (eifr & RCAR_CAN_EIFR_BEIF) {
int rx_errors = 0, tx_errors = 0;
u8 ecsr;
netdev_dbg(priv->ndev, "Bus error interrupt:\n");
if (skb) {
cf->can_id |= CAN_ERR_BUSERROR | CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_UNSPEC;
}
ecsr = readb(&priv->regs->ecsr);
if (ecsr & RCAR_CAN_ECSR_ADEF) {
netdev_dbg(priv->ndev, "ACK Delimiter Error\n");
tx_errors++;
writeb(~RCAR_CAN_ECSR_ADEF, &priv->regs->ecsr);
if (skb)
cf->data[3] |= CAN_ERR_PROT_LOC_ACK_DEL;
}
if (ecsr & RCAR_CAN_ECSR_BE0F) {
netdev_dbg(priv->ndev, "Bit Error (dominant)\n");
tx_errors++;
writeb(~RCAR_CAN_ECSR_BE0F, &priv->regs->ecsr);
if (skb)
cf->data[2] |= CAN_ERR_PROT_BIT0;
}
if (ecsr & RCAR_CAN_ECSR_BE1F) {
netdev_dbg(priv->ndev, "Bit Error (recessive)\n");
tx_errors++;
writeb(~RCAR_CAN_ECSR_BE1F, &priv->regs->ecsr);
if (skb)
cf->data[2] |= CAN_ERR_PROT_BIT1;
}
if (ecsr & RCAR_CAN_ECSR_CEF) {
netdev_dbg(priv->ndev, "CRC Error\n");
rx_errors++;
writeb(~RCAR_CAN_ECSR_CEF, &priv->regs->ecsr);
if (skb)
cf->data[3] |= CAN_ERR_PROT_LOC_CRC_SEQ;
}
if (ecsr & RCAR_CAN_ECSR_AEF) {
netdev_dbg(priv->ndev, "ACK Error\n");
tx_errors++;
writeb(~RCAR_CAN_ECSR_AEF, &priv->regs->ecsr);
if (skb) {
cf->can_id |= CAN_ERR_ACK;
cf->data[3] |= CAN_ERR_PROT_LOC_ACK;
}
}
if (ecsr & RCAR_CAN_ECSR_FEF) {
netdev_dbg(priv->ndev, "Form Error\n");
rx_errors++;
writeb(~RCAR_CAN_ECSR_FEF, &priv->regs->ecsr);
if (skb)
cf->data[2] |= CAN_ERR_PROT_FORM;
}
if (ecsr & RCAR_CAN_ECSR_SEF) {
netdev_dbg(priv->ndev, "Stuff Error\n");
rx_errors++;
writeb(~RCAR_CAN_ECSR_SEF, &priv->regs->ecsr);
if (skb)
cf->data[2] |= CAN_ERR_PROT_STUFF;
}
priv->can.can_stats.bus_error++;
ndev->stats.rx_errors += rx_errors;
ndev->stats.tx_errors += tx_errors;
writeb(~RCAR_CAN_EIFR_BEIF, &priv->regs->eifr);
}
if (eifr & RCAR_CAN_EIFR_EWIF) {
netdev_dbg(priv->ndev, "Error warning interrupt\n");
priv->can.state = CAN_STATE_ERROR_WARNING;
priv->can.can_stats.error_warning++;
writeb(~RCAR_CAN_EIFR_EWIF, &priv->regs->eifr);
if (skb)
cf->data[1] = txerr > rxerr ? CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
}
if (eifr & RCAR_CAN_EIFR_EPIF) {
netdev_dbg(priv->ndev, "Error passive interrupt\n");
priv->can.state = CAN_STATE_ERROR_PASSIVE;
priv->can.can_stats.error_passive++;
writeb(~RCAR_CAN_EIFR_EPIF, &priv->regs->eifr);
if (skb)
cf->data[1] = txerr > rxerr ? CAN_ERR_CRTL_TX_PASSIVE :
CAN_ERR_CRTL_RX_PASSIVE;
}
if (eifr & RCAR_CAN_EIFR_BOEIF) {
netdev_dbg(priv->ndev, "Bus-off entry interrupt\n");
tx_failure_cleanup(ndev);
priv->ier = RCAR_CAN_IER_ERSIE;
writeb(priv->ier, &priv->regs->ier);
priv->can.state = CAN_STATE_BUS_OFF;
writeb(~RCAR_CAN_EIFR_BOEIF, &priv->regs->eifr);
can_bus_off(ndev);
if (skb)
cf->can_id |= CAN_ERR_BUSOFF;
}
if (eifr & RCAR_CAN_EIFR_ORIF) {
netdev_dbg(priv->ndev, "Receive overrun error interrupt\n");
ndev->stats.rx_over_errors++;
ndev->stats.rx_errors++;
writeb(~RCAR_CAN_EIFR_ORIF, &priv->regs->eifr);
if (skb) {
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
}
}
if (eifr & RCAR_CAN_EIFR_OLIF) {
netdev_dbg(priv->ndev,
"Overload Frame Transmission error interrupt\n");
ndev->stats.rx_over_errors++;
ndev->stats.rx_errors++;
writeb(~RCAR_CAN_EIFR_OLIF, &priv->regs->eifr);
if (skb) {
cf->can_id |= CAN_ERR_PROT;
cf->data[2] |= CAN_ERR_PROT_OVERLOAD;
}
}
if (skb) {
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_rx(skb);
}
}
static void rcar_can_tx_done(struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
u8 isr;
while (1) {
u8 unsent = readb(&priv->regs->tfcr);
unsent = (unsent & RCAR_CAN_TFCR_TFUST) >>
RCAR_CAN_TFCR_TFUST_SHIFT;
if (priv->tx_head - priv->tx_tail <= unsent)
break;
stats->tx_packets++;
stats->tx_bytes += priv->tx_dlc[priv->tx_tail %
RCAR_CAN_FIFO_DEPTH];
priv->tx_dlc[priv->tx_tail % RCAR_CAN_FIFO_DEPTH] = 0;
can_get_echo_skb(ndev, priv->tx_tail % RCAR_CAN_FIFO_DEPTH);
priv->tx_tail++;
netif_wake_queue(ndev);
}
isr = readb(&priv->regs->isr);
writeb(isr & ~RCAR_CAN_ISR_TXFF, &priv->regs->isr);
can_led_event(ndev, CAN_LED_EVENT_TX);
}
static irqreturn_t rcar_can_interrupt(int irq, void *dev_id)
{
struct net_device *ndev = dev_id;
struct rcar_can_priv *priv = netdev_priv(ndev);
u8 isr;
isr = readb(&priv->regs->isr);
if (!(isr & priv->ier))
return IRQ_NONE;
if (isr & RCAR_CAN_ISR_ERSF)
rcar_can_error(ndev);
if (isr & RCAR_CAN_ISR_TXFF)
rcar_can_tx_done(ndev);
if (isr & RCAR_CAN_ISR_RXFF) {
if (napi_schedule_prep(&priv->napi)) {
priv->ier &= ~RCAR_CAN_IER_RXFIE;
writeb(priv->ier, &priv->regs->ier);
__napi_schedule(&priv->napi);
}
}
return IRQ_HANDLED;
}
static void rcar_can_set_bittiming(struct net_device *dev)
{
struct rcar_can_priv *priv = netdev_priv(dev);
struct can_bittiming *bt = &priv->can.bittiming;
u32 bcr;
bcr = RCAR_CAN_BCR_TSEG1(bt->phase_seg1 + bt->prop_seg - 1) |
RCAR_CAN_BCR_BPR(bt->brp - 1) | RCAR_CAN_BCR_SJW(bt->sjw - 1) |
RCAR_CAN_BCR_TSEG2(bt->phase_seg2 - 1);
writel((bcr << 8) | priv->clock_select, &priv->regs->bcr);
}
static void rcar_can_start(struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
u16 ctlr;
int i;
ctlr = readw(&priv->regs->ctlr);
ctlr &= ~RCAR_CAN_CTLR_SLPM;
writew(ctlr, &priv->regs->ctlr);
ctlr |= RCAR_CAN_CTLR_CANM_FORCE_RESET;
writew(ctlr, &priv->regs->ctlr);
for (i = 0; i < MAX_STR_READS; i++) {
if (readw(&priv->regs->str) & RCAR_CAN_STR_RSTST)
break;
}
rcar_can_set_bittiming(ndev);
ctlr |= RCAR_CAN_CTLR_IDFM_MIXED;
ctlr |= RCAR_CAN_CTLR_BOM_ENT;
ctlr |= RCAR_CAN_CTLR_MBM;
ctlr |= RCAR_CAN_CTLR_MLM;
writew(ctlr, &priv->regs->ctlr);
writel(0, &priv->regs->mkr_2_9[6]);
writel(0, &priv->regs->mkr_2_9[7]);
writel(0, &priv->regs->mkivlr1);
writel(0, &priv->regs->fidcr[0]);
writel(RCAR_CAN_FIDCR_IDE | RCAR_CAN_FIDCR_RTR, &priv->regs->fidcr[1]);
writel(RCAR_CAN_MIER1_RXFIE | RCAR_CAN_MIER1_TXFIE, &priv->regs->mier1);
priv->ier = RCAR_CAN_IER_ERSIE | RCAR_CAN_IER_RXFIE |
RCAR_CAN_IER_TXFIE;
writeb(priv->ier, &priv->regs->ier);
writeb(RCAR_CAN_ECSR_EDPM, &priv->regs->ecsr);
writeb(RCAR_CAN_EIER_EWIE | RCAR_CAN_EIER_EPIE | RCAR_CAN_EIER_BOEIE |
(priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING ?
RCAR_CAN_EIER_BEIE : 0) | RCAR_CAN_EIER_ORIE |
RCAR_CAN_EIER_OLIE, &priv->regs->eier);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
writew(ctlr & ~RCAR_CAN_CTLR_CANM, &priv->regs->ctlr);
for (i = 0; i < MAX_STR_READS; i++) {
if (!(readw(&priv->regs->str) & RCAR_CAN_STR_RSTST))
break;
}
writeb(RCAR_CAN_RFCR_RFE, &priv->regs->rfcr);
writeb(RCAR_CAN_TFCR_TFE, &priv->regs->tfcr);
}
static int rcar_can_open(struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
int err;
err = clk_prepare_enable(priv->clk);
if (err) {
netdev_err(ndev, "clk_prepare_enable() failed, error %d\n",
err);
goto out;
}
err = open_candev(ndev);
if (err) {
netdev_err(ndev, "open_candev() failed, error %d\n", err);
goto out_clock;
}
napi_enable(&priv->napi);
err = request_irq(ndev->irq, rcar_can_interrupt, 0, ndev->name, ndev);
if (err) {
netdev_err(ndev, "error requesting interrupt %x\n", ndev->irq);
goto out_close;
}
can_led_event(ndev, CAN_LED_EVENT_OPEN);
rcar_can_start(ndev);
netif_start_queue(ndev);
return 0;
out_close:
napi_disable(&priv->napi);
close_candev(ndev);
out_clock:
clk_disable_unprepare(priv->clk);
out:
return err;
}
static void rcar_can_stop(struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
u16 ctlr;
int i;
ctlr = readw(&priv->regs->ctlr);
ctlr |= RCAR_CAN_CTLR_CANM_FORCE_RESET;
writew(ctlr, &priv->regs->ctlr);
for (i = 0; i < MAX_STR_READS; i++) {
if (readw(&priv->regs->str) & RCAR_CAN_STR_RSTST)
break;
}
writel(0, &priv->regs->mier0);
writel(0, &priv->regs->mier1);
writeb(0, &priv->regs->ier);
writeb(0, &priv->regs->eier);
ctlr |= RCAR_CAN_CTLR_SLPM;
writew(ctlr, &priv->regs->ctlr);
priv->can.state = CAN_STATE_STOPPED;
}
static int rcar_can_close(struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
rcar_can_stop(ndev);
free_irq(ndev->irq, ndev);
napi_disable(&priv->napi);
clk_disable_unprepare(priv->clk);
close_candev(ndev);
can_led_event(ndev, CAN_LED_EVENT_STOP);
return 0;
}
static netdev_tx_t rcar_can_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct rcar_can_priv *priv = netdev_priv(ndev);
struct can_frame *cf = (struct can_frame *)skb->data;
u32 data, i;
if (can_dropped_invalid_skb(ndev, skb))
return NETDEV_TX_OK;
if (cf->can_id & CAN_EFF_FLAG)
data = (cf->can_id & CAN_EFF_MASK) | RCAR_CAN_IDE;
else
data = (cf->can_id & CAN_SFF_MASK) << RCAR_CAN_SID_SHIFT;
if (cf->can_id & CAN_RTR_FLAG) {
data |= RCAR_CAN_RTR;
} else {
for (i = 0; i < cf->can_dlc; i++)
writeb(cf->data[i],
&priv->regs->mb[RCAR_CAN_TX_FIFO_MBX].data[i]);
}
writel(data, &priv->regs->mb[RCAR_CAN_TX_FIFO_MBX].id);
writeb(cf->can_dlc, &priv->regs->mb[RCAR_CAN_TX_FIFO_MBX].dlc);
priv->tx_dlc[priv->tx_head % RCAR_CAN_FIFO_DEPTH] = cf->can_dlc;
can_put_echo_skb(skb, ndev, priv->tx_head % RCAR_CAN_FIFO_DEPTH);
priv->tx_head++;
writeb(0xff, &priv->regs->tfpcr);
if (priv->tx_head - priv->tx_tail >= RCAR_CAN_FIFO_DEPTH)
netif_stop_queue(ndev);
return NETDEV_TX_OK;
}
static void rcar_can_rx_pkt(struct rcar_can_priv *priv)
{
struct net_device_stats *stats = &priv->ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u32 data;
u8 dlc;
skb = alloc_can_skb(priv->ndev, &cf);
if (!skb) {
stats->rx_dropped++;
return;
}
data = readl(&priv->regs->mb[RCAR_CAN_RX_FIFO_MBX].id);
if (data & RCAR_CAN_IDE)
cf->can_id = (data & CAN_EFF_MASK) | CAN_EFF_FLAG;
else
cf->can_id = (data >> RCAR_CAN_SID_SHIFT) & CAN_SFF_MASK;
dlc = readb(&priv->regs->mb[RCAR_CAN_RX_FIFO_MBX].dlc);
cf->can_dlc = get_can_dlc(dlc);
if (data & RCAR_CAN_RTR) {
cf->can_id |= CAN_RTR_FLAG;
} else {
for (dlc = 0; dlc < cf->can_dlc; dlc++)
cf->data[dlc] =
readb(&priv->regs->mb[RCAR_CAN_RX_FIFO_MBX].data[dlc]);
}
can_led_event(priv->ndev, CAN_LED_EVENT_RX);
stats->rx_bytes += cf->can_dlc;
stats->rx_packets++;
netif_receive_skb(skb);
}
static int rcar_can_rx_poll(struct napi_struct *napi, int quota)
{
struct rcar_can_priv *priv = container_of(napi,
struct rcar_can_priv, napi);
int num_pkts;
for (num_pkts = 0; num_pkts < quota; num_pkts++) {
u8 rfcr, isr;
isr = readb(&priv->regs->isr);
if (isr & RCAR_CAN_ISR_RXFF)
writeb(isr & ~RCAR_CAN_ISR_RXFF, &priv->regs->isr);
rfcr = readb(&priv->regs->rfcr);
if (rfcr & RCAR_CAN_RFCR_RFEST)
break;
rcar_can_rx_pkt(priv);
writeb(0xff, &priv->regs->rfpcr);
}
if (num_pkts < quota) {
napi_complete(napi);
priv->ier |= RCAR_CAN_IER_RXFIE;
writeb(priv->ier, &priv->regs->ier);
}
return num_pkts;
}
static int rcar_can_do_set_mode(struct net_device *ndev, enum can_mode mode)
{
switch (mode) {
case CAN_MODE_START:
rcar_can_start(ndev);
netif_wake_queue(ndev);
return 0;
default:
return -EOPNOTSUPP;
}
}
static int rcar_can_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct rcar_can_priv *priv = netdev_priv(dev);
int err;
err = clk_prepare_enable(priv->clk);
if (err)
return err;
bec->txerr = readb(&priv->regs->tecr);
bec->rxerr = readb(&priv->regs->recr);
clk_disable_unprepare(priv->clk);
return 0;
}
static int rcar_can_probe(struct platform_device *pdev)
{
struct rcar_can_platform_data *pdata;
struct rcar_can_priv *priv;
struct net_device *ndev;
struct resource *mem;
void __iomem *addr;
int err = -ENODEV;
int irq;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(&pdev->dev, "No platform data provided!\n");
goto fail;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "No IRQ resource\n");
goto fail;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(addr)) {
err = PTR_ERR(addr);
goto fail;
}
ndev = alloc_candev(sizeof(struct rcar_can_priv), RCAR_CAN_FIFO_DEPTH);
if (!ndev) {
dev_err(&pdev->dev, "alloc_candev() failed\n");
err = -ENOMEM;
goto fail;
}
priv = netdev_priv(ndev);
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
err = PTR_ERR(priv->clk);
dev_err(&pdev->dev, "cannot get clock: %d\n", err);
goto fail_clk;
}
ndev->netdev_ops = &rcar_can_netdev_ops;
ndev->irq = irq;
ndev->flags |= IFF_ECHO;
priv->ndev = ndev;
priv->regs = addr;
priv->clock_select = pdata->clock_select;
priv->can.clock.freq = clk_get_rate(priv->clk);
priv->can.bittiming_const = &rcar_can_bittiming_const;
priv->can.do_set_mode = rcar_can_do_set_mode;
priv->can.do_get_berr_counter = rcar_can_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_BERR_REPORTING;
platform_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, &pdev->dev);
netif_napi_add(ndev, &priv->napi, rcar_can_rx_poll,
RCAR_CAN_NAPI_WEIGHT);
err = register_candev(ndev);
if (err) {
dev_err(&pdev->dev, "register_candev() failed, error %d\n",
err);
goto fail_candev;
}
devm_can_led_init(ndev);
dev_info(&pdev->dev, "device registered (reg_base=%p, irq=%u)\n",
priv->regs, ndev->irq);
return 0;
fail_candev:
netif_napi_del(&priv->napi);
fail_clk:
free_candev(ndev);
fail:
return err;
}
static int rcar_can_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
struct rcar_can_priv *priv = netdev_priv(ndev);
unregister_candev(ndev);
netif_napi_del(&priv->napi);
free_candev(ndev);
return 0;
}
static int __maybe_unused rcar_can_suspend(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct rcar_can_priv *priv = netdev_priv(ndev);
u16 ctlr;
if (netif_running(ndev)) {
netif_stop_queue(ndev);
netif_device_detach(ndev);
}
ctlr = readw(&priv->regs->ctlr);
ctlr |= RCAR_CAN_CTLR_CANM_HALT;
writew(ctlr, &priv->regs->ctlr);
ctlr |= RCAR_CAN_CTLR_SLPM;
writew(ctlr, &priv->regs->ctlr);
priv->can.state = CAN_STATE_SLEEPING;
clk_disable(priv->clk);
return 0;
}
static int __maybe_unused rcar_can_resume(struct device *dev)
{
struct net_device *ndev = dev_get_drvdata(dev);
struct rcar_can_priv *priv = netdev_priv(ndev);
u16 ctlr;
int err;
err = clk_enable(priv->clk);
if (err) {
netdev_err(ndev, "clk_enable() failed, error %d\n", err);
return err;
}
ctlr = readw(&priv->regs->ctlr);
ctlr &= ~RCAR_CAN_CTLR_SLPM;
writew(ctlr, &priv->regs->ctlr);
ctlr &= ~RCAR_CAN_CTLR_CANM;
writew(ctlr, &priv->regs->ctlr);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
if (netif_running(ndev)) {
netif_device_attach(ndev);
netif_start_queue(ndev);
}
return 0;
}
