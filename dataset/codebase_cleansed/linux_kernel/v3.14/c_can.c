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
static inline int get_tx_next_msg_obj(const struct c_can_priv *priv)
{
return (priv->tx_next & C_CAN_NEXT_MSG_OBJ_MASK) +
C_CAN_MSG_OBJ_TX_FIRST;
}
static inline int get_tx_echo_msg_obj(const struct c_can_priv *priv)
{
return (priv->tx_echo & C_CAN_NEXT_MSG_OBJ_MASK) +
C_CAN_MSG_OBJ_TX_FIRST;
}
static u32 c_can_read_reg32(struct c_can_priv *priv, enum reg index)
{
u32 val = priv->read_reg(priv, index);
val |= ((u32) priv->read_reg(priv, index + 1)) << 16;
return val;
}
static void c_can_enable_all_interrupts(struct c_can_priv *priv,
int enable)
{
unsigned int cntrl_save = priv->read_reg(priv,
C_CAN_CTRL_REG);
if (enable)
cntrl_save |= (CONTROL_SIE | CONTROL_EIE | CONTROL_IE);
else
cntrl_save &= ~(CONTROL_EIE | CONTROL_IE | CONTROL_SIE);
priv->write_reg(priv, C_CAN_CTRL_REG, cntrl_save);
}
static inline int c_can_msg_obj_is_busy(struct c_can_priv *priv, int iface)
{
int count = MIN_TIMEOUT_VALUE;
while (count && priv->read_reg(priv,
C_CAN_IFACE(COMREQ_REG, iface)) &
IF_COMR_BUSY) {
count--;
udelay(1);
}
if (!count)
return 1;
return 0;
}
static inline void c_can_object_get(struct net_device *dev,
int iface, int objno, int mask)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(COMMSK_REG, iface),
IFX_WRITE_LOW_16BIT(mask));
priv->write_reg(priv, C_CAN_IFACE(COMREQ_REG, iface),
IFX_WRITE_LOW_16BIT(objno));
if (c_can_msg_obj_is_busy(priv, iface))
netdev_err(dev, "timed out in object get\n");
}
static inline void c_can_object_put(struct net_device *dev,
int iface, int objno, int mask)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(COMMSK_REG, iface),
(IF_COMM_WR | IFX_WRITE_LOW_16BIT(mask)));
priv->write_reg(priv, C_CAN_IFACE(COMREQ_REG, iface),
IFX_WRITE_LOW_16BIT(objno));
if (c_can_msg_obj_is_busy(priv, iface))
netdev_err(dev, "timed out in object put\n");
}
static void c_can_write_msg_object(struct net_device *dev,
int iface, struct can_frame *frame, int objno)
{
int i;
u16 flags = 0;
unsigned int id;
struct c_can_priv *priv = netdev_priv(dev);
if (!(frame->can_id & CAN_RTR_FLAG))
flags |= IF_ARB_TRANSMIT;
if (frame->can_id & CAN_EFF_FLAG) {
id = frame->can_id & CAN_EFF_MASK;
flags |= IF_ARB_MSGXTD;
} else
id = ((frame->can_id & CAN_SFF_MASK) << 18);
flags |= IF_ARB_MSGVAL;
priv->write_reg(priv, C_CAN_IFACE(ARB1_REG, iface),
IFX_WRITE_LOW_16BIT(id));
priv->write_reg(priv, C_CAN_IFACE(ARB2_REG, iface), flags |
IFX_WRITE_HIGH_16BIT(id));
for (i = 0; i < frame->can_dlc; i += 2) {
priv->write_reg(priv, C_CAN_IFACE(DATA1_REG, iface) + i / 2,
frame->data[i] | (frame->data[i + 1] << 8));
}
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface),
IF_MCONT_TXIE | IF_MCONT_TXRQST | IF_MCONT_EOB |
frame->can_dlc);
c_can_object_put(dev, iface, objno, IF_COMM_ALL);
}
static inline void c_can_mark_rx_msg_obj(struct net_device *dev,
int iface, int ctrl_mask,
int obj)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface),
ctrl_mask & ~(IF_MCONT_MSGLST | IF_MCONT_INTPND));
c_can_object_put(dev, iface, obj, IF_COMM_CONTROL);
}
static inline void c_can_activate_all_lower_rx_msg_obj(struct net_device *dev,
int iface,
int ctrl_mask)
{
int i;
struct c_can_priv *priv = netdev_priv(dev);
for (i = C_CAN_MSG_OBJ_RX_FIRST; i <= C_CAN_MSG_RX_LOW_LAST; i++) {
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface),
ctrl_mask & ~(IF_MCONT_MSGLST |
IF_MCONT_INTPND | IF_MCONT_NEWDAT));
c_can_object_put(dev, iface, i, IF_COMM_CONTROL);
}
}
static inline void c_can_activate_rx_msg_obj(struct net_device *dev,
int iface, int ctrl_mask,
int obj)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface),
ctrl_mask & ~(IF_MCONT_MSGLST |
IF_MCONT_INTPND | IF_MCONT_NEWDAT));
c_can_object_put(dev, iface, obj, IF_COMM_CONTROL);
}
static void c_can_handle_lost_msg_obj(struct net_device *dev,
int iface, int objno)
{
struct c_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct sk_buff *skb;
struct can_frame *frame;
netdev_err(dev, "msg lost in buffer %d\n", objno);
c_can_object_get(dev, iface, objno, IF_COMM_ALL & ~IF_COMM_TXRQST);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface),
IF_MCONT_CLR_MSGLST);
c_can_object_put(dev, 0, objno, IF_COMM_CONTROL);
skb = alloc_can_err_skb(dev, &frame);
if (unlikely(!skb))
return;
frame->can_id |= CAN_ERR_CRTL;
frame->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_errors++;
stats->rx_over_errors++;
netif_receive_skb(skb);
}
static int c_can_read_msg_object(struct net_device *dev, int iface, int ctrl)
{
u16 flags, data;
int i;
unsigned int val;
struct c_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct sk_buff *skb;
struct can_frame *frame;
skb = alloc_can_skb(dev, &frame);
if (!skb) {
stats->rx_dropped++;
return -ENOMEM;
}
frame->can_dlc = get_can_dlc(ctrl & 0x0F);
flags = priv->read_reg(priv, C_CAN_IFACE(ARB2_REG, iface));
val = priv->read_reg(priv, C_CAN_IFACE(ARB1_REG, iface)) |
(flags << 16);
if (flags & IF_ARB_MSGXTD)
frame->can_id = (val & CAN_EFF_MASK) | CAN_EFF_FLAG;
else
frame->can_id = (val >> 18) & CAN_SFF_MASK;
if (flags & IF_ARB_TRANSMIT)
frame->can_id |= CAN_RTR_FLAG;
else {
for (i = 0; i < frame->can_dlc; i += 2) {
data = priv->read_reg(priv,
C_CAN_IFACE(DATA1_REG, iface) + i / 2);
frame->data[i] = data;
frame->data[i + 1] = data >> 8;
}
}
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += frame->can_dlc;
can_led_event(dev, CAN_LED_EVENT_RX);
return 0;
}
static void c_can_setup_receive_object(struct net_device *dev, int iface,
int objno, unsigned int mask,
unsigned int id, unsigned int mcont)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(MASK1_REG, iface),
IFX_WRITE_LOW_16BIT(mask));
priv->write_reg(priv, C_CAN_IFACE(MASK2_REG, iface),
IFX_WRITE_HIGH_16BIT(mask) | BIT(13));
priv->write_reg(priv, C_CAN_IFACE(ARB1_REG, iface),
IFX_WRITE_LOW_16BIT(id));
priv->write_reg(priv, C_CAN_IFACE(ARB2_REG, iface),
(IF_ARB_MSGVAL | IFX_WRITE_HIGH_16BIT(id)));
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface), mcont);
c_can_object_put(dev, iface, objno, IF_COMM_ALL & ~IF_COMM_TXRQST);
netdev_dbg(dev, "obj no:%d, msgval:0x%08x\n", objno,
c_can_read_reg32(priv, C_CAN_MSGVAL1_REG));
}
static void c_can_inval_msg_object(struct net_device *dev, int iface, int objno)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_IFACE(ARB1_REG, iface), 0);
priv->write_reg(priv, C_CAN_IFACE(ARB2_REG, iface), 0);
priv->write_reg(priv, C_CAN_IFACE(MSGCTRL_REG, iface), 0);
c_can_object_put(dev, iface, objno, IF_COMM_ARB | IF_COMM_CONTROL);
netdev_dbg(dev, "obj no:%d, msgval:0x%08x\n", objno,
c_can_read_reg32(priv, C_CAN_MSGVAL1_REG));
}
static inline int c_can_is_next_tx_obj_busy(struct c_can_priv *priv, int objno)
{
int val = c_can_read_reg32(priv, C_CAN_TXRQST1_REG);
if (val & (1 << (objno - 1)))
return 1;
return 0;
}
static netdev_tx_t c_can_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
u32 msg_obj_no;
struct c_can_priv *priv = netdev_priv(dev);
struct can_frame *frame = (struct can_frame *)skb->data;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
msg_obj_no = get_tx_next_msg_obj(priv);
c_can_write_msg_object(dev, 0, frame, msg_obj_no);
can_put_echo_skb(skb, dev, msg_obj_no - C_CAN_MSG_OBJ_TX_FIRST);
priv->tx_next++;
if (c_can_is_next_tx_obj_busy(priv, get_tx_next_msg_obj(priv)) ||
(priv->tx_next & C_CAN_NEXT_MSG_OBJ_MASK) == 0)
netif_stop_queue(dev);
return NETDEV_TX_OK;
}
static int c_can_set_bittiming(struct net_device *dev)
{
unsigned int reg_btr, reg_brpe, ctrl_save;
u8 brp, brpe, sjw, tseg1, tseg2;
u32 ten_bit_brp;
struct c_can_priv *priv = netdev_priv(dev);
const struct can_bittiming *bt = &priv->can.bittiming;
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
priv->write_reg(priv, C_CAN_CTRL_REG,
ctrl_save | CONTROL_CCE | CONTROL_INIT);
priv->write_reg(priv, C_CAN_BTR_REG, reg_btr);
priv->write_reg(priv, C_CAN_BRPEXT_REG, reg_brpe);
priv->write_reg(priv, C_CAN_CTRL_REG, ctrl_save);
return 0;
}
static void c_can_configure_msg_objects(struct net_device *dev)
{
int i;
for (i = C_CAN_MSG_OBJ_RX_FIRST; i <= C_CAN_NO_OF_OBJECTS; i++)
c_can_inval_msg_object(dev, 0, i);
for (i = C_CAN_MSG_OBJ_RX_FIRST; i < C_CAN_MSG_OBJ_RX_LAST; i++)
c_can_setup_receive_object(dev, 0, i, 0, 0,
(IF_MCONT_RXIE | IF_MCONT_UMASK) & ~IF_MCONT_EOB);
c_can_setup_receive_object(dev, 0, C_CAN_MSG_OBJ_RX_LAST, 0, 0,
IF_MCONT_EOB | IF_MCONT_RXIE | IF_MCONT_UMASK);
}
static void c_can_chip_config(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
priv->write_reg(priv, C_CAN_CTRL_REG,
CONTROL_ENABLE_AR);
if ((priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY) &&
(priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)) {
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_EIE |
CONTROL_SIE | CONTROL_IE | CONTROL_TEST);
priv->write_reg(priv, C_CAN_TEST_REG,
TEST_LBACK | TEST_SILENT);
} else if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK) {
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_EIE |
CONTROL_SIE | CONTROL_IE | CONTROL_TEST);
priv->write_reg(priv, C_CAN_TEST_REG, TEST_LBACK);
} else if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY) {
priv->write_reg(priv, C_CAN_CTRL_REG, CONTROL_EIE |
CONTROL_SIE | CONTROL_IE | CONTROL_TEST);
priv->write_reg(priv, C_CAN_TEST_REG, TEST_SILENT);
} else
priv->write_reg(priv, C_CAN_CTRL_REG,
CONTROL_EIE | CONTROL_SIE | CONTROL_IE);
c_can_configure_msg_objects(dev);
priv->write_reg(priv, C_CAN_STS_REG, LEC_UNUSED);
c_can_set_bittiming(dev);
}
static void c_can_start(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
c_can_chip_config(dev);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
priv->tx_next = priv->tx_echo = 0;
c_can_enable_all_interrupts(priv, ENABLE_ALL_INTERRUPTS);
}
static void c_can_stop(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
c_can_enable_all_interrupts(priv, DISABLE_ALL_INTERRUPTS);
priv->can.state = CAN_STATE_STOPPED;
}
static int c_can_set_mode(struct net_device *dev, enum can_mode mode)
{
switch (mode) {
case CAN_MODE_START:
c_can_start(dev);
netif_wake_queue(dev);
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
u32 val;
u32 msg_obj_no;
struct c_can_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
for (; (priv->tx_next - priv->tx_echo) > 0; priv->tx_echo++) {
msg_obj_no = get_tx_echo_msg_obj(priv);
val = c_can_read_reg32(priv, C_CAN_TXRQST1_REG);
if (!(val & (1 << (msg_obj_no - 1)))) {
can_get_echo_skb(dev,
msg_obj_no - C_CAN_MSG_OBJ_TX_FIRST);
c_can_object_get(dev, 0, msg_obj_no, IF_COMM_ALL);
stats->tx_bytes += priv->read_reg(priv,
C_CAN_IFACE(MSGCTRL_REG, 0))
& IF_MCONT_DLC_MASK;
stats->tx_packets++;
can_led_event(dev, CAN_LED_EVENT_TX);
c_can_inval_msg_object(dev, 0, msg_obj_no);
} else {
break;
}
}
if (((priv->tx_next & C_CAN_NEXT_MSG_OBJ_MASK) != 0) ||
((priv->tx_echo & C_CAN_NEXT_MSG_OBJ_MASK) == 0))
netif_wake_queue(dev);
}
static int c_can_do_rx_poll(struct net_device *dev, int quota)
{
u32 num_rx_pkts = 0;
unsigned int msg_obj, msg_ctrl_save;
struct c_can_priv *priv = netdev_priv(dev);
u16 val;
BUILD_BUG_ON_MSG(C_CAN_MSG_OBJ_RX_LAST > 16,
"Implementation does not support more message objects than 16");
while (quota > 0 && (val = priv->read_reg(priv, C_CAN_INTPND1_REG))) {
while ((msg_obj = ffs(val)) && quota > 0) {
val &= ~BIT(msg_obj - 1);
c_can_object_get(dev, 0, msg_obj, IF_COMM_ALL &
~IF_COMM_TXRQST);
msg_ctrl_save = priv->read_reg(priv,
C_CAN_IFACE(MSGCTRL_REG, 0));
if (msg_ctrl_save & IF_MCONT_MSGLST) {
c_can_handle_lost_msg_obj(dev, 0, msg_obj);
num_rx_pkts++;
quota--;
continue;
}
if (msg_ctrl_save & IF_MCONT_EOB)
return num_rx_pkts;
if (!(msg_ctrl_save & IF_MCONT_NEWDAT))
continue;
c_can_read_msg_object(dev, 0, msg_ctrl_save);
if (msg_obj < C_CAN_MSG_RX_LOW_LAST)
c_can_mark_rx_msg_obj(dev, 0,
msg_ctrl_save, msg_obj);
else if (msg_obj > C_CAN_MSG_RX_LOW_LAST)
c_can_activate_rx_msg_obj(dev, 0,
msg_ctrl_save, msg_obj);
else if (msg_obj == C_CAN_MSG_RX_LOW_LAST)
c_can_activate_all_lower_rx_msg_obj(dev,
0, msg_ctrl_save);
num_rx_pkts++;
quota--;
}
}
return num_rx_pkts;
}
static inline int c_can_has_and_handle_berr(struct c_can_priv *priv)
{
return (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING) &&
(priv->current_status & LEC_UNUSED);
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
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
__c_can_get_berr_counter(dev, &bec);
reg_err_counter = priv->read_reg(priv, C_CAN_ERR_CNT_REG);
rx_err_passive = (reg_err_counter & ERR_CNT_RP_MASK) >>
ERR_CNT_RP_SHIFT;
switch (error_type) {
case C_CAN_ERROR_WARNING:
priv->can.can_stats.error_warning++;
priv->can.state = CAN_STATE_ERROR_WARNING;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = (bec.txerr > bec.rxerr) ?
CAN_ERR_CRTL_TX_WARNING :
CAN_ERR_CRTL_RX_WARNING;
cf->data[6] = bec.txerr;
cf->data[7] = bec.rxerr;
break;
case C_CAN_ERROR_PASSIVE:
priv->can.can_stats.error_passive++;
priv->can.state = CAN_STATE_ERROR_PASSIVE;
cf->can_id |= CAN_ERR_CRTL;
if (rx_err_passive)
cf->data[1] |= CAN_ERR_CRTL_RX_PASSIVE;
if (bec.txerr > 127)
cf->data[1] |= CAN_ERR_CRTL_TX_PASSIVE;
cf->data[6] = bec.txerr;
cf->data[7] = bec.rxerr;
break;
case C_CAN_BUS_OFF:
priv->can.state = CAN_STATE_BUS_OFF;
cf->can_id |= CAN_ERR_BUSOFF;
c_can_enable_all_interrupts(priv, DISABLE_ALL_INTERRUPTS);
can_bus_off(dev);
break;
default:
break;
}
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
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
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
priv->can.can_stats.bus_error++;
stats->rx_errors++;
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
priv->write_reg(priv, C_CAN_STS_REG, LEC_UNUSED);
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
return 1;
}
static int c_can_poll(struct napi_struct *napi, int quota)
{
u16 irqstatus;
int lec_type = 0;
int work_done = 0;
struct net_device *dev = napi->dev;
struct c_can_priv *priv = netdev_priv(dev);
irqstatus = priv->irqstatus;
if (!irqstatus)
goto end;
if (irqstatus == STATUS_INTERRUPT) {
priv->current_status = priv->read_reg(priv,
C_CAN_STS_REG);
if (priv->current_status & STATUS_TXOK)
priv->write_reg(priv, C_CAN_STS_REG,
priv->current_status & ~STATUS_TXOK);
if (priv->current_status & STATUS_RXOK)
priv->write_reg(priv, C_CAN_STS_REG,
priv->current_status & ~STATUS_RXOK);
if ((priv->current_status & STATUS_EWARN) &&
(!(priv->last_status & STATUS_EWARN))) {
netdev_dbg(dev, "entered error warning state\n");
work_done += c_can_handle_state_change(dev,
C_CAN_ERROR_WARNING);
}
if ((priv->current_status & STATUS_EPASS) &&
(!(priv->last_status & STATUS_EPASS))) {
netdev_dbg(dev, "entered error passive state\n");
work_done += c_can_handle_state_change(dev,
C_CAN_ERROR_PASSIVE);
}
if ((priv->current_status & STATUS_BOFF) &&
(!(priv->last_status & STATUS_BOFF))) {
netdev_dbg(dev, "entered bus off state\n");
work_done += c_can_handle_state_change(dev,
C_CAN_BUS_OFF);
}
if ((!(priv->current_status & STATUS_BOFF)) &&
(priv->last_status & STATUS_BOFF)) {
netdev_dbg(dev, "left bus off state\n");
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
if ((!(priv->current_status & STATUS_EPASS)) &&
(priv->last_status & STATUS_EPASS)) {
netdev_dbg(dev, "left error passive state\n");
priv->can.state = CAN_STATE_ERROR_ACTIVE;
}
priv->last_status = priv->current_status;
lec_type = c_can_has_and_handle_berr(priv);
if (lec_type)
work_done += c_can_handle_bus_err(dev, lec_type);
} else if ((irqstatus >= C_CAN_MSG_OBJ_RX_FIRST) &&
(irqstatus <= C_CAN_MSG_OBJ_RX_LAST)) {
work_done += c_can_do_rx_poll(dev, (quota - work_done));
} else if ((irqstatus >= C_CAN_MSG_OBJ_TX_FIRST) &&
(irqstatus <= C_CAN_MSG_OBJ_TX_LAST)) {
c_can_do_tx(dev);
}
end:
if (work_done < quota) {
napi_complete(napi);
c_can_enable_all_interrupts(priv, ENABLE_ALL_INTERRUPTS);
}
return work_done;
}
static irqreturn_t c_can_isr(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct c_can_priv *priv = netdev_priv(dev);
priv->irqstatus = priv->read_reg(priv, C_CAN_INT_REG);
if (!priv->irqstatus)
return IRQ_NONE;
c_can_enable_all_interrupts(priv, DISABLE_ALL_INTERRUPTS);
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
napi_enable(&priv->napi);
can_led_event(dev, CAN_LED_EVENT_OPEN);
c_can_start(dev);
netif_start_queue(dev);
return 0;
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
c_can_start(dev);
return 0;
}
void free_c_can_dev(struct net_device *dev)
{
free_candev(dev);
}
int register_c_can_dev(struct net_device *dev)
{
struct c_can_priv *priv = netdev_priv(dev);
int err;
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
