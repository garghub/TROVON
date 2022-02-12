static void mcp251x_clean(struct net_device *net)
{
struct mcp251x_priv *priv = netdev_priv(net);
if (priv->tx_skb || priv->tx_len)
net->stats.tx_errors++;
if (priv->tx_skb)
dev_kfree_skb(priv->tx_skb);
if (priv->tx_len)
can_free_echo_skb(priv->net, 0);
priv->tx_skb = NULL;
priv->tx_len = 0;
}
static int mcp251x_spi_trans(struct spi_device *spi, int len)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
struct spi_transfer t = {
.tx_buf = priv->spi_tx_buf,
.rx_buf = priv->spi_rx_buf,
.len = len,
.cs_change = 0,
};
struct spi_message m;
int ret;
spi_message_init(&m);
if (mcp251x_enable_dma) {
t.tx_dma = priv->spi_tx_dma;
t.rx_dma = priv->spi_rx_dma;
m.is_dma_mapped = 1;
}
spi_message_add_tail(&t, &m);
ret = spi_sync(spi, &m);
if (ret)
dev_err(&spi->dev, "spi transfer failed: ret = %d\n", ret);
return ret;
}
static u8 mcp251x_read_reg(struct spi_device *spi, uint8_t reg)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
u8 val = 0;
priv->spi_tx_buf[0] = INSTRUCTION_READ;
priv->spi_tx_buf[1] = reg;
mcp251x_spi_trans(spi, 3);
val = priv->spi_rx_buf[2];
return val;
}
static void mcp251x_read_2regs(struct spi_device *spi, uint8_t reg,
uint8_t *v1, uint8_t *v2)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
priv->spi_tx_buf[0] = INSTRUCTION_READ;
priv->spi_tx_buf[1] = reg;
mcp251x_spi_trans(spi, 4);
*v1 = priv->spi_rx_buf[2];
*v2 = priv->spi_rx_buf[3];
}
static void mcp251x_write_reg(struct spi_device *spi, u8 reg, uint8_t val)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
priv->spi_tx_buf[0] = INSTRUCTION_WRITE;
priv->spi_tx_buf[1] = reg;
priv->spi_tx_buf[2] = val;
mcp251x_spi_trans(spi, 3);
}
static void mcp251x_write_bits(struct spi_device *spi, u8 reg,
u8 mask, uint8_t val)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
priv->spi_tx_buf[0] = INSTRUCTION_BIT_MODIFY;
priv->spi_tx_buf[1] = reg;
priv->spi_tx_buf[2] = mask;
priv->spi_tx_buf[3] = val;
mcp251x_spi_trans(spi, 4);
}
static void mcp251x_hw_tx_frame(struct spi_device *spi, u8 *buf,
int len, int tx_buf_idx)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
if (mcp251x_is_2510(spi)) {
int i;
for (i = 1; i < TXBDAT_OFF + len; i++)
mcp251x_write_reg(spi, TXBCTRL(tx_buf_idx) + i,
buf[i]);
} else {
memcpy(priv->spi_tx_buf, buf, TXBDAT_OFF + len);
mcp251x_spi_trans(spi, TXBDAT_OFF + len);
}
}
static void mcp251x_hw_tx(struct spi_device *spi, struct can_frame *frame,
int tx_buf_idx)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
u32 sid, eid, exide, rtr;
u8 buf[SPI_TRANSFER_BUF_LEN];
exide = (frame->can_id & CAN_EFF_FLAG) ? 1 : 0;
if (exide)
sid = (frame->can_id & CAN_EFF_MASK) >> 18;
else
sid = frame->can_id & CAN_SFF_MASK;
eid = frame->can_id & CAN_EFF_MASK;
rtr = (frame->can_id & CAN_RTR_FLAG) ? 1 : 0;
buf[TXBCTRL_OFF] = INSTRUCTION_LOAD_TXB(tx_buf_idx);
buf[TXBSIDH_OFF] = sid >> SIDH_SHIFT;
buf[TXBSIDL_OFF] = ((sid & SIDL_SID_MASK) << SIDL_SID_SHIFT) |
(exide << SIDL_EXIDE_SHIFT) |
((eid >> SIDL_EID_SHIFT) & SIDL_EID_MASK);
buf[TXBEID8_OFF] = GET_BYTE(eid, 1);
buf[TXBEID0_OFF] = GET_BYTE(eid, 0);
buf[TXBDLC_OFF] = (rtr << DLC_RTR_SHIFT) | frame->can_dlc;
memcpy(buf + TXBDAT_OFF, frame->data, frame->can_dlc);
mcp251x_hw_tx_frame(spi, buf, frame->can_dlc, tx_buf_idx);
priv->spi_tx_buf[0] = INSTRUCTION_RTS(1 << tx_buf_idx);
mcp251x_spi_trans(priv->spi, 1);
}
static void mcp251x_hw_rx_frame(struct spi_device *spi, u8 *buf,
int buf_idx)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
if (mcp251x_is_2510(spi)) {
int i, len;
for (i = 1; i < RXBDAT_OFF; i++)
buf[i] = mcp251x_read_reg(spi, RXBCTRL(buf_idx) + i);
len = get_can_dlc(buf[RXBDLC_OFF] & RXBDLC_LEN_MASK);
for (; i < (RXBDAT_OFF + len); i++)
buf[i] = mcp251x_read_reg(spi, RXBCTRL(buf_idx) + i);
} else {
priv->spi_tx_buf[RXBCTRL_OFF] = INSTRUCTION_READ_RXB(buf_idx);
mcp251x_spi_trans(spi, SPI_TRANSFER_BUF_LEN);
memcpy(buf, priv->spi_rx_buf, SPI_TRANSFER_BUF_LEN);
}
}
static void mcp251x_hw_rx(struct spi_device *spi, int buf_idx)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
struct sk_buff *skb;
struct can_frame *frame;
u8 buf[SPI_TRANSFER_BUF_LEN];
skb = alloc_can_skb(priv->net, &frame);
if (!skb) {
dev_err(&spi->dev, "cannot allocate RX skb\n");
priv->net->stats.rx_dropped++;
return;
}
mcp251x_hw_rx_frame(spi, buf, buf_idx);
if (buf[RXBSIDL_OFF] & RXBSIDL_IDE) {
frame->can_id = CAN_EFF_FLAG;
frame->can_id |=
SET_BYTE(buf[RXBSIDL_OFF] & RXBSIDL_EID, 2) |
SET_BYTE(buf[RXBEID8_OFF], 1) |
SET_BYTE(buf[RXBEID0_OFF], 0) |
(((buf[RXBSIDH_OFF] << RXBSIDH_SHIFT) |
(buf[RXBSIDL_OFF] >> RXBSIDL_SHIFT)) << 18);
if (buf[RXBDLC_OFF] & RXBDLC_RTR)
frame->can_id |= CAN_RTR_FLAG;
} else {
frame->can_id =
(buf[RXBSIDH_OFF] << RXBSIDH_SHIFT) |
(buf[RXBSIDL_OFF] >> RXBSIDL_SHIFT);
if (buf[RXBSIDL_OFF] & RXBSIDL_SRR)
frame->can_id |= CAN_RTR_FLAG;
}
frame->can_dlc = get_can_dlc(buf[RXBDLC_OFF] & RXBDLC_LEN_MASK);
memcpy(frame->data, buf + RXBDAT_OFF, frame->can_dlc);
priv->net->stats.rx_packets++;
priv->net->stats.rx_bytes += frame->can_dlc;
can_led_event(priv->net, CAN_LED_EVENT_RX);
netif_rx_ni(skb);
}
static void mcp251x_hw_sleep(struct spi_device *spi)
{
mcp251x_write_reg(spi, CANCTRL, CANCTRL_REQOP_SLEEP);
}
static netdev_tx_t mcp251x_hard_start_xmit(struct sk_buff *skb,
struct net_device *net)
{
struct mcp251x_priv *priv = netdev_priv(net);
struct spi_device *spi = priv->spi;
if (priv->tx_skb || priv->tx_len) {
dev_warn(&spi->dev, "hard_xmit called while tx busy\n");
return NETDEV_TX_BUSY;
}
if (can_dropped_invalid_skb(net, skb))
return NETDEV_TX_OK;
netif_stop_queue(net);
priv->tx_skb = skb;
queue_work(priv->wq, &priv->tx_work);
return NETDEV_TX_OK;
}
static int mcp251x_do_set_mode(struct net_device *net, enum can_mode mode)
{
struct mcp251x_priv *priv = netdev_priv(net);
switch (mode) {
case CAN_MODE_START:
mcp251x_clean(net);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
priv->restart_tx = 1;
if (priv->can.restart_ms == 0)
priv->after_suspend = AFTER_SUSPEND_RESTART;
queue_work(priv->wq, &priv->restart_work);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int mcp251x_set_normal_mode(struct spi_device *spi)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
unsigned long timeout;
mcp251x_write_reg(spi, CANINTE,
CANINTE_ERRIE | CANINTE_TX2IE | CANINTE_TX1IE |
CANINTE_TX0IE | CANINTE_RX1IE | CANINTE_RX0IE);
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK) {
mcp251x_write_reg(spi, CANCTRL, CANCTRL_REQOP_LOOPBACK);
} else if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY) {
mcp251x_write_reg(spi, CANCTRL, CANCTRL_REQOP_LISTEN_ONLY);
} else {
mcp251x_write_reg(spi, CANCTRL, CANCTRL_REQOP_NORMAL);
timeout = jiffies + HZ;
while (mcp251x_read_reg(spi, CANSTAT) & CANCTRL_REQOP_MASK) {
schedule();
if (time_after(jiffies, timeout)) {
dev_err(&spi->dev, "MCP251x didn't"
" enter in normal mode\n");
return -EBUSY;
}
}
}
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
}
static int mcp251x_do_set_bittiming(struct net_device *net)
{
struct mcp251x_priv *priv = netdev_priv(net);
struct can_bittiming *bt = &priv->can.bittiming;
struct spi_device *spi = priv->spi;
mcp251x_write_reg(spi, CNF1, ((bt->sjw - 1) << CNF1_SJW_SHIFT) |
(bt->brp - 1));
mcp251x_write_reg(spi, CNF2, CNF2_BTLMODE |
(priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES ?
CNF2_SAM : 0) |
((bt->phase_seg1 - 1) << CNF2_PS1_SHIFT) |
(bt->prop_seg - 1));
mcp251x_write_bits(spi, CNF3, CNF3_PHSEG2_MASK,
(bt->phase_seg2 - 1));
dev_dbg(&spi->dev, "CNF: 0x%02x 0x%02x 0x%02x\n",
mcp251x_read_reg(spi, CNF1),
mcp251x_read_reg(spi, CNF2),
mcp251x_read_reg(spi, CNF3));
return 0;
}
static int mcp251x_setup(struct net_device *net, struct mcp251x_priv *priv,
struct spi_device *spi)
{
mcp251x_do_set_bittiming(net);
mcp251x_write_reg(spi, RXBCTRL(0),
RXBCTRL_BUKT | RXBCTRL_RXM0 | RXBCTRL_RXM1);
mcp251x_write_reg(spi, RXBCTRL(1),
RXBCTRL_RXM0 | RXBCTRL_RXM1);
return 0;
}
static int mcp251x_hw_reset(struct spi_device *spi)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
u8 reg;
int ret;
mdelay(MCP251X_OST_DELAY_MS);
priv->spi_tx_buf[0] = INSTRUCTION_RESET;
ret = mcp251x_spi_trans(spi, 1);
if (ret)
return ret;
mdelay(MCP251X_OST_DELAY_MS);
reg = mcp251x_read_reg(spi, CANSTAT);
if ((reg & CANCTRL_REQOP_MASK) != CANCTRL_REQOP_CONF)
return -ENODEV;
return 0;
}
static int mcp251x_hw_probe(struct spi_device *spi)
{
u8 ctrl;
int ret;
ret = mcp251x_hw_reset(spi);
if (ret)
return ret;
ctrl = mcp251x_read_reg(spi, CANCTRL);
dev_dbg(&spi->dev, "CANCTRL 0x%02x\n", ctrl);
if ((ctrl & 0x17) != 0x07)
return -ENODEV;
return 0;
}
static int mcp251x_power_enable(struct regulator *reg, int enable)
{
if (IS_ERR_OR_NULL(reg))
return 0;
if (enable)
return regulator_enable(reg);
else
return regulator_disable(reg);
}
static void mcp251x_open_clean(struct net_device *net)
{
struct mcp251x_priv *priv = netdev_priv(net);
struct spi_device *spi = priv->spi;
free_irq(spi->irq, priv);
mcp251x_hw_sleep(spi);
mcp251x_power_enable(priv->transceiver, 0);
close_candev(net);
}
static int mcp251x_stop(struct net_device *net)
{
struct mcp251x_priv *priv = netdev_priv(net);
struct spi_device *spi = priv->spi;
close_candev(net);
priv->force_quit = 1;
free_irq(spi->irq, priv);
destroy_workqueue(priv->wq);
priv->wq = NULL;
mutex_lock(&priv->mcp_lock);
mcp251x_write_reg(spi, CANINTE, 0x00);
mcp251x_write_reg(spi, CANINTF, 0x00);
mcp251x_write_reg(spi, TXBCTRL(0), 0);
mcp251x_clean(net);
mcp251x_hw_sleep(spi);
mcp251x_power_enable(priv->transceiver, 0);
priv->can.state = CAN_STATE_STOPPED;
mutex_unlock(&priv->mcp_lock);
can_led_event(net, CAN_LED_EVENT_STOP);
return 0;
}
static void mcp251x_error_skb(struct net_device *net, int can_id, int data1)
{
struct sk_buff *skb;
struct can_frame *frame;
skb = alloc_can_err_skb(net, &frame);
if (skb) {
frame->can_id |= can_id;
frame->data[1] = data1;
netif_rx_ni(skb);
} else {
netdev_err(net, "cannot allocate error skb\n");
}
}
static void mcp251x_tx_work_handler(struct work_struct *ws)
{
struct mcp251x_priv *priv = container_of(ws, struct mcp251x_priv,
tx_work);
struct spi_device *spi = priv->spi;
struct net_device *net = priv->net;
struct can_frame *frame;
mutex_lock(&priv->mcp_lock);
if (priv->tx_skb) {
if (priv->can.state == CAN_STATE_BUS_OFF) {
mcp251x_clean(net);
} else {
frame = (struct can_frame *)priv->tx_skb->data;
if (frame->can_dlc > CAN_FRAME_MAX_DATA_LEN)
frame->can_dlc = CAN_FRAME_MAX_DATA_LEN;
mcp251x_hw_tx(spi, frame, 0);
priv->tx_len = 1 + frame->can_dlc;
can_put_echo_skb(priv->tx_skb, net, 0);
priv->tx_skb = NULL;
}
}
mutex_unlock(&priv->mcp_lock);
}
static void mcp251x_restart_work_handler(struct work_struct *ws)
{
struct mcp251x_priv *priv = container_of(ws, struct mcp251x_priv,
restart_work);
struct spi_device *spi = priv->spi;
struct net_device *net = priv->net;
mutex_lock(&priv->mcp_lock);
if (priv->after_suspend) {
mcp251x_hw_reset(spi);
mcp251x_setup(net, priv, spi);
if (priv->after_suspend & AFTER_SUSPEND_RESTART) {
mcp251x_set_normal_mode(spi);
} else if (priv->after_suspend & AFTER_SUSPEND_UP) {
netif_device_attach(net);
mcp251x_clean(net);
mcp251x_set_normal_mode(spi);
netif_wake_queue(net);
} else {
mcp251x_hw_sleep(spi);
}
priv->after_suspend = 0;
priv->force_quit = 0;
}
if (priv->restart_tx) {
priv->restart_tx = 0;
mcp251x_write_reg(spi, TXBCTRL(0), 0);
mcp251x_clean(net);
netif_wake_queue(net);
mcp251x_error_skb(net, CAN_ERR_RESTARTED, 0);
}
mutex_unlock(&priv->mcp_lock);
}
static irqreturn_t mcp251x_can_ist(int irq, void *dev_id)
{
struct mcp251x_priv *priv = dev_id;
struct spi_device *spi = priv->spi;
struct net_device *net = priv->net;
mutex_lock(&priv->mcp_lock);
while (!priv->force_quit) {
enum can_state new_state;
u8 intf, eflag;
u8 clear_intf = 0;
int can_id = 0, data1 = 0;
mcp251x_read_2regs(spi, CANINTF, &intf, &eflag);
intf &= CANINTF_RX | CANINTF_TX | CANINTF_ERR;
if (intf & CANINTF_RX0IF) {
mcp251x_hw_rx(spi, 0);
if (mcp251x_is_2510(spi))
mcp251x_write_bits(spi, CANINTF, CANINTF_RX0IF, 0x00);
}
if (intf & CANINTF_RX1IF) {
mcp251x_hw_rx(spi, 1);
if (mcp251x_is_2510(spi))
clear_intf |= CANINTF_RX1IF;
}
if (intf & (CANINTF_ERR | CANINTF_TX))
clear_intf |= intf & (CANINTF_ERR | CANINTF_TX);
if (clear_intf)
mcp251x_write_bits(spi, CANINTF, clear_intf, 0x00);
if (eflag & (EFLG_RX0OVR | EFLG_RX1OVR))
mcp251x_write_bits(spi, EFLG, eflag, 0x00);
if (eflag & EFLG_TXBO) {
new_state = CAN_STATE_BUS_OFF;
can_id |= CAN_ERR_BUSOFF;
} else if (eflag & EFLG_TXEP) {
new_state = CAN_STATE_ERROR_PASSIVE;
can_id |= CAN_ERR_CRTL;
data1 |= CAN_ERR_CRTL_TX_PASSIVE;
} else if (eflag & EFLG_RXEP) {
new_state = CAN_STATE_ERROR_PASSIVE;
can_id |= CAN_ERR_CRTL;
data1 |= CAN_ERR_CRTL_RX_PASSIVE;
} else if (eflag & EFLG_TXWAR) {
new_state = CAN_STATE_ERROR_WARNING;
can_id |= CAN_ERR_CRTL;
data1 |= CAN_ERR_CRTL_TX_WARNING;
} else if (eflag & EFLG_RXWAR) {
new_state = CAN_STATE_ERROR_WARNING;
can_id |= CAN_ERR_CRTL;
data1 |= CAN_ERR_CRTL_RX_WARNING;
} else {
new_state = CAN_STATE_ERROR_ACTIVE;
}
switch (priv->can.state) {
case CAN_STATE_ERROR_ACTIVE:
if (new_state >= CAN_STATE_ERROR_WARNING &&
new_state <= CAN_STATE_BUS_OFF)
priv->can.can_stats.error_warning++;
case CAN_STATE_ERROR_WARNING:
if (new_state >= CAN_STATE_ERROR_PASSIVE &&
new_state <= CAN_STATE_BUS_OFF)
priv->can.can_stats.error_passive++;
break;
default:
break;
}
priv->can.state = new_state;
if (intf & CANINTF_ERRIF) {
if (eflag & (EFLG_RX0OVR | EFLG_RX1OVR)) {
if (eflag & EFLG_RX0OVR) {
net->stats.rx_over_errors++;
net->stats.rx_errors++;
}
if (eflag & EFLG_RX1OVR) {
net->stats.rx_over_errors++;
net->stats.rx_errors++;
}
can_id |= CAN_ERR_CRTL;
data1 |= CAN_ERR_CRTL_RX_OVERFLOW;
}
mcp251x_error_skb(net, can_id, data1);
}
if (priv->can.state == CAN_STATE_BUS_OFF) {
if (priv->can.restart_ms == 0) {
priv->force_quit = 1;
priv->can.can_stats.bus_off++;
can_bus_off(net);
mcp251x_hw_sleep(spi);
break;
}
}
if (intf == 0)
break;
if (intf & CANINTF_TX) {
net->stats.tx_packets++;
net->stats.tx_bytes += priv->tx_len - 1;
can_led_event(net, CAN_LED_EVENT_TX);
if (priv->tx_len) {
can_get_echo_skb(net, 0);
priv->tx_len = 0;
}
netif_wake_queue(net);
}
}
mutex_unlock(&priv->mcp_lock);
return IRQ_HANDLED;
}
static int mcp251x_open(struct net_device *net)
{
struct mcp251x_priv *priv = netdev_priv(net);
struct spi_device *spi = priv->spi;
unsigned long flags = IRQF_ONESHOT | IRQF_TRIGGER_FALLING;
int ret;
ret = open_candev(net);
if (ret) {
dev_err(&spi->dev, "unable to set initial baudrate!\n");
return ret;
}
mutex_lock(&priv->mcp_lock);
mcp251x_power_enable(priv->transceiver, 1);
priv->force_quit = 0;
priv->tx_skb = NULL;
priv->tx_len = 0;
ret = request_threaded_irq(spi->irq, NULL, mcp251x_can_ist,
flags | IRQF_ONESHOT, DEVICE_NAME, priv);
if (ret) {
dev_err(&spi->dev, "failed to acquire irq %d\n", spi->irq);
mcp251x_power_enable(priv->transceiver, 0);
close_candev(net);
goto open_unlock;
}
priv->wq = alloc_workqueue("mcp251x_wq", WQ_FREEZABLE | WQ_MEM_RECLAIM,
0);
INIT_WORK(&priv->tx_work, mcp251x_tx_work_handler);
INIT_WORK(&priv->restart_work, mcp251x_restart_work_handler);
ret = mcp251x_hw_reset(spi);
if (ret) {
mcp251x_open_clean(net);
goto open_unlock;
}
ret = mcp251x_setup(net, priv, spi);
if (ret) {
mcp251x_open_clean(net);
goto open_unlock;
}
ret = mcp251x_set_normal_mode(spi);
if (ret) {
mcp251x_open_clean(net);
goto open_unlock;
}
can_led_event(net, CAN_LED_EVENT_OPEN);
netif_wake_queue(net);
open_unlock:
mutex_unlock(&priv->mcp_lock);
return ret;
}
static int mcp251x_can_probe(struct spi_device *spi)
{
const struct of_device_id *of_id = of_match_device(mcp251x_of_match,
&spi->dev);
struct mcp251x_platform_data *pdata = dev_get_platdata(&spi->dev);
struct net_device *net;
struct mcp251x_priv *priv;
struct clk *clk;
int freq, ret;
clk = devm_clk_get(&spi->dev, NULL);
if (IS_ERR(clk)) {
if (pdata)
freq = pdata->oscillator_frequency;
else
return PTR_ERR(clk);
} else {
freq = clk_get_rate(clk);
}
if (freq < 1000000 || freq > 25000000)
return -ERANGE;
net = alloc_candev(sizeof(struct mcp251x_priv), TX_ECHO_SKB_MAX);
if (!net)
return -ENOMEM;
if (!IS_ERR(clk)) {
ret = clk_prepare_enable(clk);
if (ret)
goto out_free;
}
net->netdev_ops = &mcp251x_netdev_ops;
net->flags |= IFF_ECHO;
priv = netdev_priv(net);
priv->can.bittiming_const = &mcp251x_bittiming_const;
priv->can.do_set_mode = mcp251x_do_set_mode;
priv->can.clock.freq = freq / 2;
priv->can.ctrlmode_supported = CAN_CTRLMODE_3_SAMPLES |
CAN_CTRLMODE_LOOPBACK | CAN_CTRLMODE_LISTENONLY;
if (of_id)
priv->model = (enum mcp251x_model)of_id->data;
else
priv->model = spi_get_device_id(spi)->driver_data;
priv->net = net;
priv->clk = clk;
spi_set_drvdata(spi, priv);
spi->bits_per_word = 8;
if (mcp251x_is_2510(spi))
spi->max_speed_hz = spi->max_speed_hz ? : 5 * 1000 * 1000;
else
spi->max_speed_hz = spi->max_speed_hz ? : 10 * 1000 * 1000;
ret = spi_setup(spi);
if (ret)
goto out_clk;
priv->power = devm_regulator_get_optional(&spi->dev, "vdd");
priv->transceiver = devm_regulator_get_optional(&spi->dev, "xceiver");
if ((PTR_ERR(priv->power) == -EPROBE_DEFER) ||
(PTR_ERR(priv->transceiver) == -EPROBE_DEFER)) {
ret = -EPROBE_DEFER;
goto out_clk;
}
ret = mcp251x_power_enable(priv->power, 1);
if (ret)
goto out_clk;
priv->spi = spi;
mutex_init(&priv->mcp_lock);
if (mcp251x_enable_dma) {
spi->dev.coherent_dma_mask = ~0;
priv->spi_tx_buf = dmam_alloc_coherent(&spi->dev,
PAGE_SIZE,
&priv->spi_tx_dma,
GFP_DMA);
if (priv->spi_tx_buf) {
priv->spi_rx_buf = (priv->spi_tx_buf + (PAGE_SIZE / 2));
priv->spi_rx_dma = (dma_addr_t)(priv->spi_tx_dma +
(PAGE_SIZE / 2));
} else {
mcp251x_enable_dma = 0;
}
}
if (!mcp251x_enable_dma) {
priv->spi_tx_buf = devm_kzalloc(&spi->dev, SPI_TRANSFER_BUF_LEN,
GFP_KERNEL);
if (!priv->spi_tx_buf) {
ret = -ENOMEM;
goto error_probe;
}
priv->spi_rx_buf = devm_kzalloc(&spi->dev, SPI_TRANSFER_BUF_LEN,
GFP_KERNEL);
if (!priv->spi_rx_buf) {
ret = -ENOMEM;
goto error_probe;
}
}
SET_NETDEV_DEV(net, &spi->dev);
ret = mcp251x_hw_probe(spi);
if (ret) {
if (ret == -ENODEV)
dev_err(&spi->dev, "Cannot initialize MCP%x. Wrong wiring?\n", priv->model);
goto error_probe;
}
mcp251x_hw_sleep(spi);
ret = register_candev(net);
if (ret)
goto error_probe;
devm_can_led_init(net);
netdev_info(net, "MCP%x successfully initialized.\n", priv->model);
return 0;
error_probe:
mcp251x_power_enable(priv->power, 0);
out_clk:
if (!IS_ERR(clk))
clk_disable_unprepare(clk);
out_free:
free_candev(net);
dev_err(&spi->dev, "Probe failed, err=%d\n", -ret);
return ret;
}
static int mcp251x_can_remove(struct spi_device *spi)
{
struct mcp251x_priv *priv = spi_get_drvdata(spi);
struct net_device *net = priv->net;
unregister_candev(net);
mcp251x_power_enable(priv->power, 0);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
free_candev(net);
return 0;
}
static int __maybe_unused mcp251x_can_suspend(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct mcp251x_priv *priv = spi_get_drvdata(spi);
struct net_device *net = priv->net;
priv->force_quit = 1;
disable_irq(spi->irq);
if (netif_running(net)) {
netif_device_detach(net);
mcp251x_hw_sleep(spi);
mcp251x_power_enable(priv->transceiver, 0);
priv->after_suspend = AFTER_SUSPEND_UP;
} else {
priv->after_suspend = AFTER_SUSPEND_DOWN;
}
if (!IS_ERR_OR_NULL(priv->power)) {
regulator_disable(priv->power);
priv->after_suspend |= AFTER_SUSPEND_POWER;
}
return 0;
}
static int __maybe_unused mcp251x_can_resume(struct device *dev)
{
struct spi_device *spi = to_spi_device(dev);
struct mcp251x_priv *priv = spi_get_drvdata(spi);
if (priv->after_suspend & AFTER_SUSPEND_POWER)
mcp251x_power_enable(priv->power, 1);
if (priv->after_suspend & AFTER_SUSPEND_UP) {
mcp251x_power_enable(priv->transceiver, 1);
queue_work(priv->wq, &priv->restart_work);
} else {
priv->after_suspend = 0;
}
priv->force_quit = 0;
enable_irq(spi->irq);
return 0;
}
