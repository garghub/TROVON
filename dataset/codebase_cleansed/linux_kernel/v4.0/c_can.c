static inline void c_can_pm_runtime_enable(const struct c_can_priv *priv)
{
if (priv->device)
pm_runtime_enable(priv->device);
}
static inline void c_can_pm_runtime_disable(const struct c_can_priv *priv)
{
if (priv->device)
pm_runtime_disable(priv->device);
}
static inline void c_can_pm_runtime_get_sync(const struct c_can_priv *priv)
{
if (priv->device)
pm_runtime_get_sync(priv->device);
}
static inline void c_can_pm_runtime_put_sync(const struct c_can_priv *priv)
{
if (priv->device)
pm_runtime_put_sync(priv->device);
}
static inline void c_can_reset_ram(const struct c_can_priv *priv, bool enable)
{
if (priv->raminit)
priv->raminit(priv, enable);
}
static void c_can_irq_control(struct c_can_priv *priv, bool enable)
{
u32 ctrl = priv->read_reg(priv, C_CAN_CTRL_REG) & ~CONTROL_IRQMSK;
if (enable)
ctrl |= CONTROL_IRQMSK;
priv->write_reg(priv, C_CAN_CTRL_REG, ctrl);
}
static void c_can_obj_update(struct net_device *dev, int iface, u32 cmd, u32 obj)
{
struct c_can_priv *priv = netdev_priv(dev);
int cnt, reg = C_CAN_IFACE(COMREQ_REG, iface);
priv->write_reg32(priv, reg, (cmd << 16) | obj);
for (cnt = MIN_TIMEOUT_VALUE; cnt; cnt--) {
if (!(priv->read_reg(priv, reg) & IF_COMR_BUSY))
return;
udelay(1);
}
netdev_err(dev, "Updating object timed out\n");
}
static inline void c_can_object_get(struct net_device *dev, int iface,
u32 obj, u32 cmd)
{
c_can_obj_update(dev, iface, cmd, obj);
}
static inline void c_can_object_put(struct net_device *dev, int iface,
u32 obj, u32 cmd)
{
c_can_obj_update(dev, iface, cmd | IF_COMM_WR, obj);
}
static void c_can_inval_tx_object(struct net_device *dev, int iface, int obj)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface), 0);
c_can_object_put(dev, iface, obj, IF_COMM_INVAL);
}
static void c_can_inval_msg_object(struct net_device *dev, int iface, int obj)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(ARB1_REG, iface), 0);
priv->write_reg(priv, C_CAN_IFACE(ARB2_REG, iface), 0);
c_can_inval_tx_object(dev, iface, obj);
}
static void c_can_setup_tx_object(struct net_device *dev, int iface,
struct can_frame *frame, int idx)
{
struct c_can_priv *priv = netdev_priv(dev);
u16 ctrl = IF_MCONT_TX | frame->can_dlc;
bool rtr = frame->can_id & CAN_RTR_FLAG;
u32 arb = IF_ARB_MSGVAL;
int i;
if (frame->can_id & CAN_EFF_FLAG) {
arb |= frame->can_id & CAN_EFF_MASK;
arb |= IF_ARB_MSGXTD;
} else {
arb |= (frame->can_id & CAN_SFF_MASK) << 18;
}
if (!rtr)
arb |= IF_ARB_TRANSMIT;
if (rtr != (bool)test_bit(idx, &priv->tx_dir)) {
u32 obj = idx + C_CAN_MSG_OBJ_TX_FIRST;
c_can_inval_msg_object(dev, iface, obj);
change_bit(idx, &priv->tx_dir);
}
priv->write_reg32(priv, C_CAN_IFACE(ARB1_REG, iface), arb);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface), ctrl);
for (i = 0; i < frame->can_dlc; i += 2) {
priv->write_reg(priv, C_CAN_IFACE(DATA1_REG, iface) + i / 2,
frame->data[i] | (frame->data[i + 1] << 8));
}
}
static inline void c_can_activate_all_lower_rx_msg_obj(struct net_device *dev,
int iface)
{
int i;
for (i = C_CAN_MSG_OBJ_RX_FIRST; i <= C_CAN_MSG_RX_LOW_LAST; i++)
c_can_object_get(dev, iface, i, IF_COMM_CLR_NEWDAT);
}
static int c_can_handle_lost_msg_obj(struct net_device *dev,
int iface, int objno, u32 ctrl)
{
struct net_device_stats *stats = &dev->stats;
struct c_can_priv *priv = netdev_priv(dev);
struct can_frame *frame;
struct sk_buff *skb;
ctrl &= ~(IF_MCONT_MSGLST | IF_MCONT_INTPND | IF_MCONT_NEWDAT);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface), ctrl);
c_can_object_put(dev, iface, objno, IF_COMM_CONTROL);
stats->rx_errors++;
stats->rx_over_errors++;
skb = alloc_can_err_skb(dev, &frame);
if (unlikely(!skb))
return 0;
frame->can_id |= CAN_ERR_CRTL;
frame->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
netif_receive_skb(skb);
return 1;
}
static int c_can_read_msg_object(struct net_device *dev, int iface, u32 ctrl)
{
struct net_device_stats *stats = &dev->stats;
struct c_can_priv *priv = netdev_priv(dev);
struct can_frame *frame;
struct sk_buff *skb;
u32 arb, data;
skb = alloc_can_skb(dev, &frame);
if (!skb) {
stats->rx_dropped++;
return -ENOMEM;
}
frame->can_dlc = get_can_dlc(ctrl & 0x0F);
arb = priv->read_reg32(priv, C_CAN_IFACE(ARB1_REG, iface));
if (arb & IF_ARB_MSGXTD)
frame->can_id = (arb & CAN_EFF_MASK) | CAN_EFF_FLAG;
else
frame->can_id = (arb >> 18) & CAN_SFF_MASK;
if (arb & IF_ARB_TRANSMIT) {
frame->can_id |= CAN_RTR_FLAG;
} else {
int i, dreg = C_CAN_IFACE(DATA1_REG, iface);
for (i = 0; i < frame->can_dlc; i += 2, dreg ++) {
data = priv->read_reg(priv, dreg);
frame->data[i] = data;
frame->data[i + 1] = data >> 8;
}
}
stats->rx_packets++;
stats->rx_bytes += frame->can_dlc;
netif_receive_skb(skb);
return 0;
}
static void c_can_setup_receive_object(struct net_device *dev, int iface,
u32 obj, u32 mask, u32 id, u32 mcont)
{
struct c_can_priv *priv = netdev_priv(dev);
mask |= BIT(29);
priv->write_reg32(priv, C_CAN_IFACE(MASK1_REG, iface), mask);
id |= IF_ARB_MSGVAL;
priv->write_reg32(priv, C_CAN_IFACE(ARB1_REG, iface), id);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface), mcont);
c_can_object_put(dev, iface, obj, IF_COMM_RCV_SETUP);
}
static netdev_tx_t c_can_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct can_frame *frame = (struct can_frame *)skb->data;
struct c_can_priv *priv = netdev_priv(dev);
u32 idx, obj;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
idx = fls(atomic_read(&priv->tx_active));
obj = idx + C_CAN_MSG_OBJ_TX_FIRST;
if (idx == C_CAN_MSG_OBJ_TX_NUM - 1)
netif_stop_queue(dev);
c_can_setup_tx_object(dev, IF_TX, frame, idx);
priv->dlc[idx] = frame->can_dlc;
can_put_echo_skb(skb, dev, idx);
atomic_add((1 << idx), &priv->tx_active);
c_can_object_put(dev, IF_TX, obj, IF_COMM_TX);
return NETDEV_TX_OK;
}
static int c_can_wait_for_ctrl_init(struct net_device *dev,
struct c_can_priv *priv, u32 init)
{
int retry = 0;
while (init != (priv->read_reg(priv, C_CAN_CTRL_REG) & CONTROL_INIT)) {
udelay(10);
if (retry++ > 1000) {
netdev_err(dev, "CCTRL: set CONTROL_INIT failed\n");
return -EIO;
}
}
return 0;
}
static int c_can_set_bittiming(struct net_device *dev)
{
unsigned int reg_btr, reg_brpe, ctrl_save;
u8 brp, brpe, sjw, tseg1, tseg2;
u32 ten_bit_brp;
struct c_can_priv *priv = netdev_priv(dev);
const struct can_bittiming *bt = &priv->can.bittiming;
int res;
ten_bit_brp = bt->brp - 1;
brp = ten_bit_brp & BTR_BRP_MASK;
brpe = ten_bit_brp >> 6;
sjw = bt->sjw - 1;
tseg1 = bt->prop_seg + bt->phase_seg1 - 1;
tseg2 = bt->phase_seg2 - 1;
reg_btr = brp | (sjw << BTR_SJW_SHIFT) | (tseg1 << BTR_TSEG1_SHIFT) |
(tseg2 << BTR_TSEG2_SHIFT);
reg_brpe = brpe & BRP_EXT_BRPE_MASK;
netdev_info(dev,
"setting BTR=%04x BRPE=%04x\n", reg_btr, reg_brpe);
ctrl_save = priv->read_reg(priv, C_CAN_CTRL_REG);
ctrl_save &= ~CONTROL_INIT;
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_CCE | CONTROL_INIT);
res = c_can_wait_for_ctrl_init(dev, priv, CONTROL_INIT);
if (res)
return res;
priv->write_reg(priv, C_CAN_BTR_REG, reg_btr);
priv->write_reg(priv, C_CAN_BRPEXT_REG, reg_brpe);
priv->write_reg(priv, C_CAN_CTRL_REG, ctrl_save);
return c_can_wait_for_ctrl_init(dev, priv, 0);
}
static void c_can_configure_msg_objects(struct net_device *dev)
{
int i;
for (i = C_CAN_MSG_OBJ_RX_FIRST; i <= C_CAN_NO_OF_OBJECTS; i++)
c_can_inval_msg_object(dev, IF_RX, i);
for (i = C_CAN_MSG_OBJ_RX_FIRST; i < C_CAN_MSG_OBJ_RX_LAST; i++)
c_can_setup_receive_object(dev, IF_RX, i, 0, 0, IF_MCONT_RCV);
c_can_setup_receive_object(dev, IF_RX, C_CAN_MSG_OBJ_RX_LAST, 0, 0,
IF_MCONT_RCV_EOB);
}
static int c_can_chip_config(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_ENABLE_AR);
if ((priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY) &&
(priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)) {
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_TEST);
priv->write_reg(priv, C_CAN_TEST_REG, TEST_LBACK | TEST_SILENT);
} else if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK) {
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_TEST);
priv->write_reg(priv, C_CAN_TEST_REG, TEST_LBACK);
} else if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY) {
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_TEST);
priv->write_reg(priv, C_CAN_TEST_REG, TEST_SILENT);
}
c_can_configure_msg_objects(dev);
priv->write_reg(priv, C_CAN_STS_REG, LEC_UNUSED);
atomic_set(&priv->tx_active, 0);
priv->rxmasked = 0;
priv->tx_dir = 0;
return c_can_set_bittiming(dev);
}
static int c_can_start(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
int err;
err = c_can_chip_config(dev);
if (err)
return err;
priv->comm_rcv_high = priv->type != BOSCH_D_CAN ?
IF_COMM_RCV_LOW : IF_COMM_RCV_HIGH;
priv->can.state = CAN_STATE_ERROR_ACTIVE;
pinctrl_pm_select_default_state(dev->dev.parent);
return 0;
}
static void c_can_stop(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
c_can_irq_control(priv, false);
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_INIT);
pinctrl_pm_select_sleep_state(dev->dev.parent);
priv->can.state = CAN_STATE_STOPPED;
}
static int c_can_set_mode(struct net_device *dev, enum can_mode mode)
{
struct c_can_priv *priv = netdev_priv(dev);
int err;
switch (mode) {
case CAN_MODE_START:
err = c_can_start(dev);
if (err)
return err;
netif_wake_queue(dev);
c_can_irq_control(priv, true);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int __c_can_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
unsigned int reg_err_counter;
struct c_can_priv *priv = netdev_priv(dev);
reg_err_counter = priv->read_reg(priv, C_CAN_ERR_CNT_REG);
bec->rxerr = (reg_err_counter & ERR_CNT_REC_MASK) >>
ERR_CNT_REC_SHIFT;
bec->txerr = reg_err_counter & ERR_CNT_TEC_MASK;
return 0;
}
static int c_can_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct c_can_priv *priv = netdev_priv(dev);
int err;
c_can_pm_runtime_get_sync(priv);
err = __c_can_get_berr_counter(dev, bec);
c_can_pm_runtime_put_sync(priv);
return err;
}
static void c_can_do_tx(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
u32 idx, obj, pkts = 0, bytes = 0, pend, clr;
clr = pend = priv->read_reg(priv, C_CAN_INTPND2_REG);
while ((idx = ffs(pend))) {
idx--;
pend &= ~(1 << idx);
obj = idx + C_CAN_MSG_OBJ_TX_FIRST;
c_can_inval_tx_object(dev, IF_RX, obj);
can_get_echo_skb(dev, idx);
bytes += priv->dlc[idx];
pkts++;
}
atomic_sub(clr, &priv->tx_active);
if (clr & (1 << (C_CAN_MSG_OBJ_TX_NUM - 1)))
netif_wake_queue(dev);
if (pkts) {
stats->tx_bytes += bytes;
stats->tx_packets += pkts;
can_led_event(dev, CAN_LED_EVENT_TX);
}
}
static u32 c_can_adjust_pending(u32 pend)
{
u32 weight, lasts;
if (pend == RECEIVE_OBJECT_BITS)
return pend;
weight = hweight32(pend);
lasts = fls(pend);
if (lasts == weight)
return pend;
for (lasts--; pend & (1 << (lasts - 1)); lasts--);
return pend & ~((1 << lasts) - 1);
}
static inline void c_can_rx_object_get(struct net_device *dev,
struct c_can_priv *priv, u32 obj)
{
c_can_object_get(dev, IF_RX, obj, priv->comm_rcv_high);
}
static inline void c_can_rx_finalize(struct net_device *dev,
struct c_can_priv *priv, u32 obj)
{
if (priv->type != BOSCH_D_CAN)
c_can_object_get(dev, IF_RX, obj, IF_COMM_CLR_NEWDAT);
}
static int c_can_read_objects(struct net_device *dev, struct c_can_priv *priv,
u32 pend, int quota)
{
u32 pkts = 0, ctrl, obj;
while ((obj = ffs(pend)) && quota > 0) {
pend &= ~BIT(obj - 1);
c_can_rx_object_get(dev, priv, obj);
ctrl = priv->read_reg(priv, C_CAN_IFACE(MSGCTRL_REG, IF_RX));
if (ctrl & IF_MCONT_MSGLST) {
int n = c_can_handle_lost_msg_obj(dev, IF_RX, obj, ctrl);
pkts += n;
quota -= n;
continue;
}
if (!(ctrl & IF_MCONT_NEWDAT))
continue;
c_can_read_msg_object(dev, IF_RX, ctrl);
c_can_rx_finalize(dev, priv, obj);
pkts++;
quota--;
}
return pkts;
}
static inline u32 c_can_get_pending(struct c_can_priv *priv)
{
u32 pend = priv->read_reg(priv, C_CAN_NEWDAT1_REG);
return pend;
}
static int c_can_do_rx_poll(struct net_device *dev, int quota)
{
struct c_can_priv *priv = netdev_priv(dev);
u32 pkts = 0, pend = 0, toread, n;
BUILD_BUG_ON_MSG(C_CAN_MSG_OBJ_RX_LAST > 16,
"Implementation does not support more message objects than 16");
while (quota > 0) {
if (!pend) {
pend = c_can_get_pending(priv);
if (!pend)
break;
toread = c_can_adjust_pending(pend);
} else {
toread = pend;
}
pend &= ~toread;
n = c_can_read_objects(dev, priv, toread, quota);
pkts += n;
quota -= n;
}
if (pkts)
can_led_event(dev, CAN_LED_EVENT_RX);
return pkts;
}
static int c_can_handle_state_change(struct net_device *dev,
enum c_can_bus_error_types error_type)
{
unsigned int reg_err_counter;
unsigned int rx_err_passive;
struct c_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
struct can_berr_counter bec;
switch (error_type) {
case C_CAN_ERROR_WARNING:
priv->can.can_stats.error_warning++;
priv->can.state = CAN_STATE_ERROR_WARNING;
break;
case C_CAN_ERROR_PASSIVE:
priv->can.can_stats.error_passive++;
priv->can.state = CAN_STATE_ERROR_PASSIVE;
break;
case C_CAN_BUS_OFF:
priv->can.state = CAN_STATE_BUS_OFF;
priv->can.can_stats.bus_off++;
break;
default:
break;
}
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
__c_can_get_berr_counter(dev, &bec);
reg_err_counter = priv->read_reg(priv, C_CAN_ERR_CNT_REG);
rx_err_passive = (reg_err_counter & ERR_CNT_RP_MASK) >>
ERR_CNT_RP_SHIFT;
switch (error_type) {
case C_CAN_ERROR_WARNING:
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = (bec.txerr > bec.rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
cf->data[6] = bec.txerr;
cf->data[7] = bec.rxerr;
break;
case C_CAN_ERROR_PASSIVE:
cf->can_id |= CAN_ERR_CRTL;
if (rx_err_passive)
cf->data[1] |= CAN_ERR_CRTL_RX_PASSIVE;
if (bec.txerr > 127)
cf->data[1] |= CAN_ERR_CRTL_TX_PASSIVE;
cf->data[6] = bec.txerr;
cf->data[7] = bec.rxerr;
break;
case C_CAN_BUS_OFF:
cf->can_id |= CAN_ERR_BUSOFF;
can_bus_off(dev);
break;
default:
break;
}
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
return 1;
}
static int c_can_handle_bus_err(struct net_device *dev,
enum c_can_lec_type lec_type)
{
struct c_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
if (lec_type == LEC_UNUSED || lec_type == LEC_NO_ERROR)
return 0;
if (!(priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING))
return 0;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
cf->data[2] |= CAN_ERR_PROT_UNSPEC;
switch (lec_type) {
case LEC_STUFF_ERROR:
netdev_dbg(dev, "stuff error\n");
cf->data[2] |= CAN_ERR_PROT_STUFF;
break;
case LEC_FORM_ERROR:
netdev_dbg(dev, "form error\n");
cf->data[2] |= CAN_ERR_PROT_FORM;
break;
case LEC_ACK_ERROR:
netdev_dbg(dev, "ack error\n");
cf->data[3] |= (CAN_ERR_PROT_LOC_ACK |
CAN_ERR_PROT_LOC_ACK_DEL);
break;
case LEC_BIT1_ERROR:
netdev_dbg(dev, "bit1 error\n");
cf->data[2] |= CAN_ERR_PROT_BIT1;
break;
case LEC_BIT0_ERROR:
netdev_dbg(dev, "bit0 error\n");
cf->data[2] |= CAN_ERR_PROT_BIT0;
break;
case LEC_CRC_ERROR:
netdev_dbg(dev, "CRC error\n");
cf->data[3] |= (CAN_ERR_PROT_LOC_CRC_SEQ |
CAN_ERR_PROT_LOC_CRC_DEL);
break;
default:
break;
}
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
return 1;
}
static int c_can_poll(struct napi_struct *napi, int quota)
{
struct net_device *dev = napi->dev;
struct c_can_priv *priv = netdev_priv(dev);
u16 curr, last = priv->last_status;
int work_done = 0;
priv->last_status = curr = priv->read_reg(priv, C_CAN_STS_REG);
if (priv->type != BOSCH_D_CAN)
priv->write_reg(priv, C_CAN_STS_REG, LEC_UNUSED);
if ((curr & STATUS_EWARN) && (!(last & STATUS_EWARN))) {
netdev_dbg(dev, "entered error warning state\n");
work_done += c_can_handle_state_change(dev, C_CAN_ERROR_WARNING);
}
if ((curr & STATUS_EPASS) && (!(last & STATUS_EPASS))) {
netdev_dbg(dev, "entered error passive state\n");
work_done += c_can_handle_state_change(dev, C_CAN_ERROR_PASSIVE);
}
if ((curr & STATUS_BOFF) && (!(last & STATUS_BOFF))) {
netdev_dbg(dev, "entered bus off state\n");
work_done += c_can_handle_state_change(dev, C_CAN_BUS_OFF);
goto end;
}
if ((!(curr & STATUS_BOFF)) && (last & STATUS_BOFF)) {
netdev_dbg(dev, "left bus off state\n");
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
if ((!(curr & STATUS_EPASS)) && (last & STATUS_EPASS)) {
netdev_dbg(dev, "left error passive state\n");
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
work_done += c_can_handle_bus_err(dev, curr & LEC_MASK);
work_done += c_can_do_rx_poll(dev, (quota - work_done));
c_can_do_tx(dev);
end:
if (work_done < quota) {
napi_complete(napi);
if (priv->can.state != CAN_STATE_BUS_OFF)
c_can_irq_control(priv, true);
}
return work_done;
}
static irqreturn_t c_can_isr(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct c_can_priv *priv = netdev_priv(dev);
if (!priv->read_reg(priv, C_CAN_INT_REG))
return IRQ_NONE;
c_can_irq_control(priv, false);
napi_schedule(&priv->napi);
return IRQ_HANDLED;
}
static int c_can_open(struct net_device *dev)
{
int err;
struct c_can_priv *priv = netdev_priv(dev);
c_can_pm_runtime_get_sync(priv);
c_can_reset_ram(priv, true);
err = open_candev(dev);
if (err) {
netdev_err(dev, "failed to open can device\n");
goto exit_open_fail;
}
err = request_irq(dev->irq, &c_can_isr, IRQF_SHARED, dev->name,
dev);
if (err < 0) {
netdev_err(dev, "failed to request interrupt\n");
goto exit_irq_fail;
}
err = c_can_start(dev);
if (err)
goto exit_start_fail;
can_led_event(dev, CAN_LED_EVENT_OPEN);
napi_enable(&priv->napi);
c_can_irq_control(priv, true);
netif_start_queue(dev);
return 0;
exit_start_fail:
free_irq(dev->irq, dev);
exit_irq_fail:
close_candev(dev);
exit_open_fail:
c_can_reset_ram(priv, false);
c_can_pm_runtime_put_sync(priv);
return err;
}
static int c_can_close(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&priv->napi);
c_can_stop(dev);
free_irq(dev->irq, dev);
close_candev(dev);
c_can_reset_ram(priv, false);
c_can_pm_runtime_put_sync(priv);
can_led_event(dev, CAN_LED_EVENT_STOP);
return 0;
}
struct net_device *alloc_c_can_dev(void)
{
struct net_device *dev;
struct c_can_priv *priv;
dev = alloc_candev(sizeof(struct c_can_priv), C_CAN_MSG_OBJ_TX_NUM);
if (!dev)
return NULL;
priv = netdev_priv(dev);
netif_napi_add(dev, &priv->napi, c_can_poll, C_CAN_NAPI_WEIGHT);
priv->dev = dev;
priv->can.bittiming_const = &c_can_bittiming_const;
priv->can.do_set_mode = c_can_set_mode;
priv->can.do_get_berr_counter = c_can_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_LISTENONLY |
CAN_CTRLMODE_BERR_REPORTING;
return dev;
}
int c_can_power_down(struct net_device *dev)
{
u32 val;
unsigned long time_out;
struct c_can_priv *priv = netdev_priv(dev);
if (!(dev->flags & IFF_UP))
return 0;
WARN_ON(priv->type != BOSCH_D_CAN);
val = priv->read_reg(priv, C_CAN_CTRL_EX_REG);
val |= CONTROL_EX_PDR;
priv->write_reg(priv, C_CAN_CTRL_EX_REG, val);
time_out = jiffies + msecs_to_jiffies(INIT_WAIT_MS);
while (!(priv->read_reg(priv, C_CAN_STS_REG) & STATUS_PDA) &&
time_after(time_out, jiffies))
cpu_relax();
if (time_after(jiffies, time_out))
return -ETIMEDOUT;
c_can_stop(dev);
c_can_reset_ram(priv, false);
c_can_pm_runtime_put_sync(priv);
return 0;
}
int c_can_power_up(struct net_device *dev)
{
u32 val;
unsigned long time_out;
struct c_can_priv *priv = netdev_priv(dev);
int ret;
if (!(dev->flags & IFF_UP))
return 0;
WARN_ON(priv->type != BOSCH_D_CAN);
c_can_pm_runtime_get_sync(priv);
c_can_reset_ram(priv, true);
val = priv->read_reg(priv, C_CAN_CTRL_EX_REG);
val &= ~CONTROL_EX_PDR;
priv->write_reg(priv, C_CAN_CTRL_EX_REG, val);
val = priv->read_reg(priv, C_CAN_CTRL_REG);
val &= ~CONTROL_INIT;
priv->write_reg(priv, C_CAN_CTRL_REG, val);
time_out = jiffies + msecs_to_jiffies(INIT_WAIT_MS);
while ((priv->read_reg(priv, C_CAN_STS_REG) & STATUS_PDA) &&
time_after(time_out, jiffies))
cpu_relax();
if (time_after(jiffies, time_out))
return -ETIMEDOUT;
ret = c_can_start(dev);
if (!ret)
c_can_irq_control(priv, true);
return ret;
}
void free_c_can_dev(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
netif_napi_del(&priv->napi);
free_candev(dev);
}
int register_c_can_dev(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
int err;
pinctrl_pm_select_sleep_state(dev->dev.parent);
c_can_pm_runtime_enable(priv);
dev->flags |= IFF_ECHO;
dev->netdev_ops = &c_can_netdev_ops;
err = register_candev(dev);
if (err)
c_can_pm_runtime_disable(priv);
else
devm_can_led_init(dev);
return err;
}
void unregister_c_can_dev(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
unregister_candev(dev);
c_can_pm_runtime_disable(priv);
}
