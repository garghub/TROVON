static void ifi_canfd_irq_enable(struct net_device *ndev, bool enable)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
u32 enirq = 0;
if (enable) {
enirq = IFI_CANFD_IRQMASK_TXFIFO_EMPTY |
IFI_CANFD_IRQMASK_RXFIFO_NEMPTY;
if (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING)
enirq |= IFI_CANFD_INTERRUPT_ERROR_COUNTER;
}
writel(IFI_CANFD_IRQMASK_SET_ERR |
IFI_CANFD_IRQMASK_SET_TS |
IFI_CANFD_IRQMASK_SET_TX |
IFI_CANFD_IRQMASK_SET_RX | enirq,
priv->base + IFI_CANFD_IRQMASK);
}
static void ifi_canfd_read_fifo(struct net_device *ndev)
{
struct net_device_stats *stats = &ndev->stats;
struct ifi_canfd_priv *priv = netdev_priv(ndev);
struct canfd_frame *cf;
struct sk_buff *skb;
const u32 rx_irq_mask = IFI_CANFD_INTERRUPT_RXFIFO_NEMPTY |
IFI_CANFD_INTERRUPT_RXFIFO_NEMPTY_PER;
u32 rxdlc, rxid;
u32 dlc, id;
int i;
rxdlc = readl(priv->base + IFI_CANFD_RXFIFO_DLC);
if (rxdlc & IFI_CANFD_RXFIFO_DLC_EDL)
skb = alloc_canfd_skb(ndev, &cf);
else
skb = alloc_can_skb(ndev, (struct can_frame **)&cf);
if (!skb) {
stats->rx_dropped++;
return;
}
dlc = (rxdlc >> IFI_CANFD_RXFIFO_DLC_DLC_OFFSET) &
IFI_CANFD_RXFIFO_DLC_DLC_MASK;
if (rxdlc & IFI_CANFD_RXFIFO_DLC_EDL)
cf->len = can_dlc2len(dlc);
else
cf->len = get_can_dlc(dlc);
rxid = readl(priv->base + IFI_CANFD_RXFIFO_ID);
id = (rxid >> IFI_CANFD_RXFIFO_ID_ID_OFFSET);
if (id & IFI_CANFD_RXFIFO_ID_IDE) {
id &= IFI_CANFD_RXFIFO_ID_ID_XTD_MASK;
id = (id >> IFI_CANFD_RXFIFO_ID_ID_XTD_OFFSET) |
((id & IFI_CANFD_RXFIFO_ID_ID_STD_MASK) <<
IFI_CANFD_RXFIFO_ID_ID_XTD_WIDTH);
id |= CAN_EFF_FLAG;
} else {
id &= IFI_CANFD_RXFIFO_ID_ID_STD_MASK;
}
cf->can_id = id;
if (rxdlc & IFI_CANFD_RXFIFO_DLC_ESI) {
cf->flags |= CANFD_ESI;
netdev_dbg(ndev, "ESI Error\n");
}
if (!(rxdlc & IFI_CANFD_RXFIFO_DLC_EDL) &&
(rxdlc & IFI_CANFD_RXFIFO_DLC_RTR)) {
cf->can_id |= CAN_RTR_FLAG;
} else {
if (rxdlc & IFI_CANFD_RXFIFO_DLC_BRS)
cf->flags |= CANFD_BRS;
for (i = 0; i < cf->len; i += 4) {
*(u32 *)(cf->data + i) =
readl(priv->base + IFI_CANFD_RXFIFO_DATA + i);
}
}
writel(IFI_CANFD_RXSTCMD_REMOVE_MSG, priv->base + IFI_CANFD_RXSTCMD);
writel(rx_irq_mask, priv->base + IFI_CANFD_INTERRUPT);
stats->rx_packets++;
stats->rx_bytes += cf->len;
netif_receive_skb(skb);
}
static int ifi_canfd_do_rx_poll(struct net_device *ndev, int quota)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
u32 pkts = 0;
u32 rxst;
rxst = readl(priv->base + IFI_CANFD_RXSTCMD);
if (rxst & IFI_CANFD_RXSTCMD_EMPTY) {
netdev_dbg(ndev, "No messages in RX FIFO\n");
return 0;
}
for (;;) {
if (rxst & IFI_CANFD_RXSTCMD_EMPTY)
break;
if (quota <= 0)
break;
ifi_canfd_read_fifo(ndev);
quota--;
pkts++;
rxst = readl(priv->base + IFI_CANFD_RXSTCMD);
}
if (pkts)
can_led_event(ndev, CAN_LED_EVENT_RX);
return pkts;
}
static int ifi_canfd_handle_lost_msg(struct net_device *ndev)
{
struct net_device_stats *stats = &ndev->stats;
struct sk_buff *skb;
struct can_frame *frame;
netdev_err(ndev, "RX FIFO overflow, message(s) lost.\n");
stats->rx_errors++;
stats->rx_over_errors++;
skb = alloc_can_err_skb(ndev, &frame);
if (unlikely(!skb))
return 0;
frame->can_id |= CAN_ERR_CRTL;
frame->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
netif_receive_skb(skb);
return 1;
}
static int ifi_canfd_handle_lec_err(struct net_device *ndev, const u32 errctr)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
const u32 errmask = IFI_CANFD_ERROR_CTR_OVERLOAD_FIRST |
IFI_CANFD_ERROR_CTR_ACK_ERROR_FIRST |
IFI_CANFD_ERROR_CTR_BIT0_ERROR_FIRST |
IFI_CANFD_ERROR_CTR_BIT1_ERROR_FIRST |
IFI_CANFD_ERROR_CTR_STUFF_ERROR_FIRST |
IFI_CANFD_ERROR_CTR_CRC_ERROR_FIRST |
IFI_CANFD_ERROR_CTR_FORM_ERROR_FIRST;
if (!(errctr & errmask))
return 0;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
skb = alloc_can_err_skb(ndev, &cf);
if (unlikely(!skb))
return 0;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
if (errctr & IFI_CANFD_ERROR_CTR_OVERLOAD_FIRST)
cf->data[2] |= CAN_ERR_PROT_OVERLOAD;
if (errctr & IFI_CANFD_ERROR_CTR_ACK_ERROR_FIRST)
cf->data[3] = CAN_ERR_PROT_LOC_ACK;
if (errctr & IFI_CANFD_ERROR_CTR_BIT0_ERROR_FIRST)
cf->data[2] |= CAN_ERR_PROT_BIT0;
if (errctr & IFI_CANFD_ERROR_CTR_BIT1_ERROR_FIRST)
cf->data[2] |= CAN_ERR_PROT_BIT1;
if (errctr & IFI_CANFD_ERROR_CTR_STUFF_ERROR_FIRST)
cf->data[2] |= CAN_ERR_PROT_STUFF;
if (errctr & IFI_CANFD_ERROR_CTR_CRC_ERROR_FIRST)
cf->data[3] = CAN_ERR_PROT_LOC_CRC_SEQ;
if (errctr & IFI_CANFD_ERROR_CTR_FORM_ERROR_FIRST)
cf->data[2] |= CAN_ERR_PROT_FORM;
writel(IFI_CANFD_ERROR_CTR_ER_RESET, priv->base + IFI_CANFD_ERROR_CTR);
writel(IFI_CANFD_INTERRUPT_ERROR_COUNTER,
priv->base + IFI_CANFD_INTERRUPT);
writel(IFI_CANFD_ERROR_CTR_ER_ENABLE, priv->base + IFI_CANFD_ERROR_CTR);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
return 1;
}
static int ifi_canfd_get_berr_counter(const struct net_device *ndev,
struct can_berr_counter *bec)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
u32 err;
err = readl(priv->base + IFI_CANFD_ERROR);
bec->rxerr = (err >> IFI_CANFD_ERROR_RX_OFFSET) &
IFI_CANFD_ERROR_RX_MASK;
bec->txerr = (err >> IFI_CANFD_ERROR_TX_OFFSET) &
IFI_CANFD_ERROR_TX_MASK;
return 0;
}
static int ifi_canfd_handle_state_change(struct net_device *ndev,
enum can_state new_state)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
struct can_frame *cf;
struct sk_buff *skb;
struct can_berr_counter bec;
switch (new_state) {
case CAN_STATE_ERROR_ACTIVE:
priv->can.can_stats.error_warning++;
priv->can.state = CAN_STATE_ERROR_WARNING;
break;
case CAN_STATE_ERROR_PASSIVE:
priv->can.can_stats.error_passive++;
priv->can.state = CAN_STATE_ERROR_PASSIVE;
break;
case CAN_STATE_BUS_OFF:
priv->can.state = CAN_STATE_BUS_OFF;
ifi_canfd_irq_enable(ndev, 0);
priv->can.can_stats.bus_off++;
can_bus_off(ndev);
break;
default:
break;
}
skb = alloc_can_err_skb(ndev, &cf);
if (unlikely(!skb))
return 0;
ifi_canfd_get_berr_counter(ndev, &bec);
switch (new_state) {
case CAN_STATE_ERROR_ACTIVE:
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = (bec.txerr > bec.rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
cf->data[6] = bec.txerr;
cf->data[7] = bec.rxerr;
break;
case CAN_STATE_ERROR_PASSIVE:
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] |= CAN_ERR_CRTL_RX_PASSIVE;
if (bec.txerr > 127)
cf->data[1] |= CAN_ERR_CRTL_TX_PASSIVE;
cf->data[6] = bec.txerr;
cf->data[7] = bec.rxerr;
break;
case CAN_STATE_BUS_OFF:
cf->can_id |= CAN_ERR_BUSOFF;
break;
default:
break;
}
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
return 1;
}
static int ifi_canfd_handle_state_errors(struct net_device *ndev, u32 stcmd)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
int work_done = 0;
u32 isr;
isr = readl(priv->base + IFI_CANFD_INTERRUPT);
if ((isr & IFI_CANFD_INTERRUPT_ERROR_WARNING) &&
(priv->can.state != CAN_STATE_ERROR_WARNING)) {
writel(IFI_CANFD_INTERRUPT_ERROR_WARNING,
priv->base + IFI_CANFD_INTERRUPT);
netdev_dbg(ndev, "Error, entered warning state\n");
work_done += ifi_canfd_handle_state_change(ndev,
CAN_STATE_ERROR_WARNING);
}
if ((stcmd & IFI_CANFD_STCMD_ERROR_PASSIVE) &&
(priv->can.state != CAN_STATE_ERROR_PASSIVE)) {
netdev_dbg(ndev, "Error, entered passive state\n");
work_done += ifi_canfd_handle_state_change(ndev,
CAN_STATE_ERROR_PASSIVE);
}
if ((stcmd & IFI_CANFD_STCMD_BUSOFF) &&
(priv->can.state != CAN_STATE_BUS_OFF)) {
netdev_dbg(ndev, "Error, entered bus-off state\n");
work_done += ifi_canfd_handle_state_change(ndev,
CAN_STATE_BUS_OFF);
}
return work_done;
}
static int ifi_canfd_poll(struct napi_struct *napi, int quota)
{
struct net_device *ndev = napi->dev;
struct ifi_canfd_priv *priv = netdev_priv(ndev);
const u32 stcmd_state_mask = IFI_CANFD_STCMD_ERROR_PASSIVE |
IFI_CANFD_STCMD_BUSOFF;
int work_done = 0;
u32 stcmd = readl(priv->base + IFI_CANFD_STCMD);
u32 rxstcmd = readl(priv->base + IFI_CANFD_RXSTCMD);
u32 errctr = readl(priv->base + IFI_CANFD_ERROR_CTR);
if ((stcmd & stcmd_state_mask) ||
((stcmd & IFI_CANFD_STCMD_ERROR_ACTIVE) == 0))
work_done += ifi_canfd_handle_state_errors(ndev, stcmd);
if (rxstcmd & IFI_CANFD_RXSTCMD_OVERFLOW)
work_done += ifi_canfd_handle_lost_msg(ndev);
if (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING)
work_done += ifi_canfd_handle_lec_err(ndev, errctr);
if (!(rxstcmd & IFI_CANFD_RXSTCMD_EMPTY))
work_done += ifi_canfd_do_rx_poll(ndev, quota - work_done);
if (work_done < quota) {
napi_complete_done(napi, work_done);
ifi_canfd_irq_enable(ndev, 1);
}
return work_done;
}
static irqreturn_t ifi_canfd_isr(int irq, void *dev_id)
{
struct net_device *ndev = (struct net_device *)dev_id;
struct ifi_canfd_priv *priv = netdev_priv(ndev);
struct net_device_stats *stats = &ndev->stats;
const u32 rx_irq_mask = IFI_CANFD_INTERRUPT_RXFIFO_NEMPTY |
IFI_CANFD_INTERRUPT_RXFIFO_NEMPTY_PER |
IFI_CANFD_INTERRUPT_ERROR_WARNING |
IFI_CANFD_INTERRUPT_ERROR_COUNTER;
const u32 tx_irq_mask = IFI_CANFD_INTERRUPT_TXFIFO_EMPTY |
IFI_CANFD_INTERRUPT_TXFIFO_REMOVE;
const u32 clr_irq_mask = ~((u32)(IFI_CANFD_INTERRUPT_SET_IRQ |
IFI_CANFD_INTERRUPT_ERROR_WARNING));
u32 isr;
isr = readl(priv->base + IFI_CANFD_INTERRUPT);
if (isr == 0)
return IRQ_NONE;
writel(clr_irq_mask, priv->base + IFI_CANFD_INTERRUPT);
if (isr & rx_irq_mask) {
ifi_canfd_irq_enable(ndev, 0);
napi_schedule(&priv->napi);
}
if (isr & IFI_CANFD_INTERRUPT_TXFIFO_REMOVE) {
stats->tx_bytes += can_get_echo_skb(ndev, 0);
stats->tx_packets++;
can_led_event(ndev, CAN_LED_EVENT_TX);
}
if (isr & tx_irq_mask)
netif_wake_queue(ndev);
return IRQ_HANDLED;
}
static void ifi_canfd_set_bittiming(struct net_device *ndev)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
const struct can_bittiming *bt = &priv->can.bittiming;
const struct can_bittiming *dbt = &priv->can.data_bittiming;
u16 brp, sjw, tseg1, tseg2, tdc;
brp = bt->brp - 2;
sjw = bt->sjw - 1;
tseg1 = bt->prop_seg + bt->phase_seg1 - 1;
tseg2 = bt->phase_seg2 - 2;
writel((tseg2 << IFI_CANFD_TIME_TIMEB_OFF) |
(tseg1 << IFI_CANFD_TIME_TIMEA_OFF) |
(brp << IFI_CANFD_TIME_PRESCALE_OFF) |
(sjw << IFI_CANFD_TIME_SJW_OFF_7_9_8_8),
priv->base + IFI_CANFD_TIME);
brp = dbt->brp - 2;
sjw = dbt->sjw - 1;
tseg1 = dbt->prop_seg + dbt->phase_seg1 - 1;
tseg2 = dbt->phase_seg2 - 2;
writel((tseg2 << IFI_CANFD_TIME_TIMEB_OFF) |
(tseg1 << IFI_CANFD_TIME_TIMEA_OFF) |
(brp << IFI_CANFD_TIME_PRESCALE_OFF) |
(sjw << IFI_CANFD_TIME_SJW_OFF_7_9_8_8),
priv->base + IFI_CANFD_FTIME);
tdc = (dbt->brp * (dbt->phase_seg1 + 1)) & IFI_CANFD_TDELAY_MASK;
writel(IFI_CANFD_TDELAY_EN | IFI_CANFD_TDELAY_ABS | tdc,
priv->base + IFI_CANFD_TDELAY);
}
static void ifi_canfd_set_filter(struct net_device *ndev, const u32 id,
const u32 mask, const u32 ident)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
writel(mask, priv->base + IFI_CANFD_FILTER_MASK(id));
writel(ident, priv->base + IFI_CANFD_FILTER_IDENT(id));
}
static void ifi_canfd_set_filters(struct net_device *ndev)
{
ifi_canfd_set_filter(ndev, 0,
IFI_CANFD_FILTER_MASK_VALID |
IFI_CANFD_FILTER_MASK_EXT,
IFI_CANFD_FILTER_IDENT_VALID);
ifi_canfd_set_filter(ndev, 1,
IFI_CANFD_FILTER_MASK_VALID |
IFI_CANFD_FILTER_MASK_EXT,
IFI_CANFD_FILTER_IDENT_VALID |
IFI_CANFD_FILTER_IDENT_IDE);
ifi_canfd_set_filter(ndev, 2,
IFI_CANFD_FILTER_MASK_VALID |
IFI_CANFD_FILTER_MASK_EDL |
IFI_CANFD_FILTER_MASK_EXT,
IFI_CANFD_FILTER_IDENT_VALID |
IFI_CANFD_FILTER_IDENT_CANFD |
IFI_CANFD_FILTER_IDENT_IDE);
}
static void ifi_canfd_start(struct net_device *ndev)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
u32 stcmd;
writel(IFI_CANFD_STCMD_HARDRESET, priv->base + IFI_CANFD_STCMD);
writel(IFI_CANFD_STCMD_ENABLE_7_9_8_8_TIMING,
priv->base + IFI_CANFD_STCMD);
ifi_canfd_set_bittiming(ndev);
ifi_canfd_set_filters(ndev);
writel(IFI_CANFD_RXSTCMD_RESET, priv->base + IFI_CANFD_RXSTCMD);
writel(0, priv->base + IFI_CANFD_RXSTCMD);
writel(IFI_CANFD_TXSTCMD_RESET, priv->base + IFI_CANFD_TXSTCMD);
writel(0, priv->base + IFI_CANFD_TXSTCMD);
writel(0, priv->base + IFI_CANFD_REPEAT);
writel(0, priv->base + IFI_CANFD_SUSPEND);
writel((u32)(~IFI_CANFD_INTERRUPT_SET_IRQ),
priv->base + IFI_CANFD_INTERRUPT);
stcmd = IFI_CANFD_STCMD_ENABLE | IFI_CANFD_STCMD_NORMAL_MODE |
IFI_CANFD_STCMD_ENABLE_7_9_8_8_TIMING;
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
stcmd |= IFI_CANFD_STCMD_BUSMONITOR;
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)
stcmd |= IFI_CANFD_STCMD_LOOPBACK;
if ((priv->can.ctrlmode & CAN_CTRLMODE_FD) &&
!(priv->can.ctrlmode & CAN_CTRLMODE_FD_NON_ISO))
stcmd |= IFI_CANFD_STCMD_ENABLE_ISO;
if (!(priv->can.ctrlmode & CAN_CTRLMODE_FD))
stcmd |= IFI_CANFD_STCMD_DISABLE_CANFD;
priv->can.state = CAN_STATE_ERROR_ACTIVE;
ifi_canfd_irq_enable(ndev, 1);
writel(IFI_CANFD_ERROR_CTR_UNLOCK_MAGIC,
priv->base + IFI_CANFD_ERROR_CTR);
writel(IFI_CANFD_ERROR_CTR_ER_RESET, priv->base + IFI_CANFD_ERROR_CTR);
writel(IFI_CANFD_ERROR_CTR_ER_ENABLE, priv->base + IFI_CANFD_ERROR_CTR);
writel(stcmd, priv->base + IFI_CANFD_STCMD);
}
static void ifi_canfd_stop(struct net_device *ndev)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
writel(IFI_CANFD_ERROR_CTR_ER_RESET, priv->base + IFI_CANFD_ERROR_CTR);
writel(0, priv->base + IFI_CANFD_ERROR_CTR);
writel(IFI_CANFD_STCMD_HARDRESET, priv->base + IFI_CANFD_STCMD);
writel(~0, priv->base + IFI_CANFD_IRQMASK);
writel((u32)(~IFI_CANFD_INTERRUPT_SET_IRQ),
priv->base + IFI_CANFD_INTERRUPT);
priv->can.state = CAN_STATE_STOPPED;
}
static int ifi_canfd_set_mode(struct net_device *ndev, enum can_mode mode)
{
switch (mode) {
case CAN_MODE_START:
ifi_canfd_start(ndev);
netif_wake_queue(ndev);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int ifi_canfd_open(struct net_device *ndev)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
int ret;
ret = open_candev(ndev);
if (ret) {
netdev_err(ndev, "Failed to open CAN device\n");
return ret;
}
ret = request_irq(ndev->irq, ifi_canfd_isr, IRQF_SHARED,
ndev->name, ndev);
if (ret < 0) {
netdev_err(ndev, "Failed to request interrupt\n");
goto err_irq;
}
ifi_canfd_start(ndev);
can_led_event(ndev, CAN_LED_EVENT_OPEN);
napi_enable(&priv->napi);
netif_start_queue(ndev);
return 0;
err_irq:
close_candev(ndev);
return ret;
}
static int ifi_canfd_close(struct net_device *ndev)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
netif_stop_queue(ndev);
napi_disable(&priv->napi);
ifi_canfd_stop(ndev);
free_irq(ndev->irq, ndev);
close_candev(ndev);
can_led_event(ndev, CAN_LED_EVENT_STOP);
return 0;
}
static netdev_tx_t ifi_canfd_start_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
struct ifi_canfd_priv *priv = netdev_priv(ndev);
struct canfd_frame *cf = (struct canfd_frame *)skb->data;
u32 txst, txid, txdlc;
int i;
if (can_dropped_invalid_skb(ndev, skb))
return NETDEV_TX_OK;
txst = readl(priv->base + IFI_CANFD_TXSTCMD);
if (txst & IFI_CANFD_TXSTCMD_FULL) {
netif_stop_queue(ndev);
netdev_err(ndev, "BUG! TX FIFO full when queue awake!\n");
return NETDEV_TX_BUSY;
}
netif_stop_queue(ndev);
if (cf->can_id & CAN_EFF_FLAG) {
txid = cf->can_id & CAN_EFF_MASK;
txid = (txid >> IFI_CANFD_TXFIFO_ID_ID_XTD_WIDTH) |
((txid & IFI_CANFD_TXFIFO_ID_ID_XTD_MASK) <<
IFI_CANFD_TXFIFO_ID_ID_XTD_OFFSET);
txid |= IFI_CANFD_TXFIFO_ID_IDE;
} else {
txid = cf->can_id & CAN_SFF_MASK;
}
txdlc = can_len2dlc(cf->len);
if ((priv->can.ctrlmode & CAN_CTRLMODE_FD) && can_is_canfd_skb(skb)) {
txdlc |= IFI_CANFD_TXFIFO_DLC_EDL;
if (cf->flags & CANFD_BRS)
txdlc |= IFI_CANFD_TXFIFO_DLC_BRS;
}
if (cf->can_id & CAN_RTR_FLAG)
txdlc |= IFI_CANFD_TXFIFO_DLC_RTR;
writel(txid, priv->base + IFI_CANFD_TXFIFO_ID);
writel(txdlc, priv->base + IFI_CANFD_TXFIFO_DLC);
for (i = 0; i < cf->len; i += 4) {
writel(*(u32 *)(cf->data + i),
priv->base + IFI_CANFD_TXFIFO_DATA + i);
}
writel(0, priv->base + IFI_CANFD_TXFIFO_REPEATCOUNT);
writel(0, priv->base + IFI_CANFD_TXFIFO_SUSPEND_US);
can_put_echo_skb(skb, ndev, 0);
writel(IFI_CANFD_TXSTCMD_ADD_MSG, priv->base + IFI_CANFD_TXSTCMD);
return NETDEV_TX_OK;
}
static int ifi_canfd_plat_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct net_device *ndev;
struct ifi_canfd_priv *priv;
struct resource *res;
void __iomem *addr;
int irq, ret;
u32 id;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(dev, res);
irq = platform_get_irq(pdev, 0);
if (IS_ERR(addr) || irq < 0)
return -EINVAL;
id = readl(addr + IFI_CANFD_IP_ID);
if (id != IFI_CANFD_IP_ID_VALUE) {
dev_err(dev, "This block is not IFI CANFD, id=%08x\n", id);
return -EINVAL;
}
ndev = alloc_candev(sizeof(*priv), 1);
if (!ndev)
return -ENOMEM;
ndev->irq = irq;
ndev->flags |= IFF_ECHO;
ndev->netdev_ops = &ifi_canfd_netdev_ops;
priv = netdev_priv(ndev);
priv->ndev = ndev;
priv->base = addr;
netif_napi_add(ndev, &priv->napi, ifi_canfd_poll, 64);
priv->can.state = CAN_STATE_STOPPED;
priv->can.clock.freq = readl(addr + IFI_CANFD_CANCLOCK);
priv->can.bittiming_const = &ifi_canfd_bittiming_const;
priv->can.data_bittiming_const = &ifi_canfd_bittiming_const;
priv->can.do_set_mode = ifi_canfd_set_mode;
priv->can.do_get_berr_counter = ifi_canfd_get_berr_counter;
priv->can.ctrlmode = CAN_CTRLMODE_FD;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_LISTENONLY |
CAN_CTRLMODE_FD |
CAN_CTRLMODE_FD_NON_ISO |
CAN_CTRLMODE_BERR_REPORTING;
platform_set_drvdata(pdev, ndev);
SET_NETDEV_DEV(ndev, dev);
ret = register_candev(ndev);
if (ret) {
dev_err(dev, "Failed to register (ret=%d)\n", ret);
goto err_reg;
}
devm_can_led_init(ndev);
dev_info(dev, "Driver registered: regs=%p, irq=%d, clock=%d\n",
priv->base, ndev->irq, priv->can.clock.freq);
return 0;
err_reg:
free_candev(ndev);
return ret;
}
static int ifi_canfd_plat_remove(struct platform_device *pdev)
{
struct net_device *ndev = platform_get_drvdata(pdev);
unregister_candev(ndev);
platform_set_drvdata(pdev, NULL);
free_candev(ndev);
return 0;
}
