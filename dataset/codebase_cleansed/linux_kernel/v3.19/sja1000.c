static void sja1000_write_cmdreg(struct sja1000_priv *priv, u8 val)
{
unsigned long flags;
spin_lock_irqsave(&priv->cmdreg_lock, flags);
priv->write_reg(priv, SJA1000_CMR, val);
priv->read_reg(priv, SJA1000_SR);
spin_unlock_irqrestore(&priv->cmdreg_lock, flags);
}
static int sja1000_is_absent(struct sja1000_priv *priv)
{
return (priv->read_reg(priv, SJA1000_MOD) == 0xFF);
}
static int sja1000_probe_chip(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
if (priv->reg_base && sja1000_is_absent(priv)) {
netdev_err(dev, "probing failed\n");
return 0;
}
return -1;
}
static void set_reset_mode(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
unsigned char status = priv->read_reg(priv, SJA1000_MOD);
int i;
priv->write_reg(priv, SJA1000_IER, IRQ_OFF);
for (i = 0; i < 100; i++) {
if (status & MOD_RM) {
priv->can.state = CAN_STATE_STOPPED;
return;
}
priv->write_reg(priv, SJA1000_MOD, MOD_RM);
udelay(10);
status = priv->read_reg(priv, SJA1000_MOD);
}
netdev_err(dev, "setting SJA1000 into reset mode failed!\n");
}
static void set_normal_mode(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
unsigned char status = priv->read_reg(priv, SJA1000_MOD);
u8 mod_reg_val = 0x00;
int i;
for (i = 0; i < 100; i++) {
if ((status & MOD_RM) == 0) {
priv->can.state = CAN_STATE_ERROR_ACTIVE;
if (priv->can.ctrlmode & CAN_CTRLMODE_BERR_REPORTING)
priv->write_reg(priv, SJA1000_IER, IRQ_ALL);
else
priv->write_reg(priv, SJA1000_IER,
IRQ_ALL & ~IRQ_BEI);
return;
}
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
mod_reg_val |= MOD_LOM;
if (priv->can.ctrlmode & CAN_CTRLMODE_PRESUME_ACK)
mod_reg_val |= MOD_STM;
priv->write_reg(priv, SJA1000_MOD, mod_reg_val);
udelay(10);
status = priv->read_reg(priv, SJA1000_MOD);
}
netdev_err(dev, "setting SJA1000 into normal mode failed!\n");
}
static void chipset_init(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
priv->write_reg(priv, SJA1000_CDR, priv->cdr | CDR_PELICAN);
priv->write_reg(priv, SJA1000_ACCC0, 0x00);
priv->write_reg(priv, SJA1000_ACCC1, 0x00);
priv->write_reg(priv, SJA1000_ACCC2, 0x00);
priv->write_reg(priv, SJA1000_ACCC3, 0x00);
priv->write_reg(priv, SJA1000_ACCM0, 0xFF);
priv->write_reg(priv, SJA1000_ACCM1, 0xFF);
priv->write_reg(priv, SJA1000_ACCM2, 0xFF);
priv->write_reg(priv, SJA1000_ACCM3, 0xFF);
priv->write_reg(priv, SJA1000_OCR, priv->ocr | OCR_MODE_NORMAL);
}
static void sja1000_start(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
if (priv->can.state != CAN_STATE_STOPPED)
set_reset_mode(dev);
if (!(priv->read_reg(priv, SJA1000_CDR) & CDR_PELICAN))
chipset_init(dev);
priv->write_reg(priv, SJA1000_TXERR, 0x0);
priv->write_reg(priv, SJA1000_RXERR, 0x0);
priv->read_reg(priv, SJA1000_ECC);
set_normal_mode(dev);
}
static int sja1000_set_mode(struct net_device *dev, enum can_mode mode)
{
switch (mode) {
case CAN_MODE_START:
sja1000_start(dev);
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int sja1000_set_bittiming(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct can_bittiming *bt = &priv->can.bittiming;
u8 btr0, btr1;
btr0 = ((bt->brp - 1) & 0x3f) | (((bt->sjw - 1) & 0x3) << 6);
btr1 = ((bt->prop_seg + bt->phase_seg1 - 1) & 0xf) |
(((bt->phase_seg2 - 1) & 0x7) << 4);
if (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES)
btr1 |= 0x80;
netdev_info(dev, "setting BTR0=0x%02x BTR1=0x%02x\n", btr0, btr1);
priv->write_reg(priv, SJA1000_BTR0, btr0);
priv->write_reg(priv, SJA1000_BTR1, btr1);
return 0;
}
static int sja1000_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct sja1000_priv *priv = netdev_priv(dev);
bec->txerr = priv->read_reg(priv, SJA1000_TXERR);
bec->rxerr = priv->read_reg(priv, SJA1000_RXERR);
return 0;
}
static netdev_tx_t sja1000_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct can_frame *cf = (struct can_frame *)skb->data;
uint8_t fi;
uint8_t dlc;
canid_t id;
uint8_t dreg;
u8 cmd_reg_val = 0x00;
int i;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
netif_stop_queue(dev);
fi = dlc = cf->can_dlc;
id = cf->can_id;
if (id & CAN_RTR_FLAG)
fi |= SJA1000_FI_RTR;
if (id & CAN_EFF_FLAG) {
fi |= SJA1000_FI_FF;
dreg = SJA1000_EFF_BUF;
priv->write_reg(priv, SJA1000_FI, fi);
priv->write_reg(priv, SJA1000_ID1, (id & 0x1fe00000) >> 21);
priv->write_reg(priv, SJA1000_ID2, (id & 0x001fe000) >> 13);
priv->write_reg(priv, SJA1000_ID3, (id & 0x00001fe0) >> 5);
priv->write_reg(priv, SJA1000_ID4, (id & 0x0000001f) << 3);
} else {
dreg = SJA1000_SFF_BUF;
priv->write_reg(priv, SJA1000_FI, fi);
priv->write_reg(priv, SJA1000_ID1, (id & 0x000007f8) >> 3);
priv->write_reg(priv, SJA1000_ID2, (id & 0x00000007) << 5);
}
for (i = 0; i < dlc; i++)
priv->write_reg(priv, dreg++, cf->data[i]);
can_put_echo_skb(skb, dev, 0);
if (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT)
cmd_reg_val |= CMD_AT;
if (priv->can.ctrlmode & CAN_CTRLMODE_LOOPBACK)
cmd_reg_val |= CMD_SRR;
else
cmd_reg_val |= CMD_TR;
sja1000_write_cmdreg(priv, cmd_reg_val);
return NETDEV_TX_OK;
}
static void sja1000_rx(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
uint8_t fi;
uint8_t dreg;
canid_t id;
int i;
skb = alloc_can_skb(dev, &cf);
if (skb == NULL)
return;
fi = priv->read_reg(priv, SJA1000_FI);
if (fi & SJA1000_FI_FF) {
dreg = SJA1000_EFF_BUF;
id = (priv->read_reg(priv, SJA1000_ID1) << 21)
| (priv->read_reg(priv, SJA1000_ID2) << 13)
| (priv->read_reg(priv, SJA1000_ID3) << 5)
| (priv->read_reg(priv, SJA1000_ID4) >> 3);
id |= CAN_EFF_FLAG;
} else {
dreg = SJA1000_SFF_BUF;
id = (priv->read_reg(priv, SJA1000_ID1) << 3)
| (priv->read_reg(priv, SJA1000_ID2) >> 5);
}
cf->can_dlc = get_can_dlc(fi & 0x0F);
if (fi & SJA1000_FI_RTR) {
id |= CAN_RTR_FLAG;
} else {
for (i = 0; i < cf->can_dlc; i++)
cf->data[i] = priv->read_reg(priv, dreg++);
}
cf->can_id = id;
sja1000_write_cmdreg(priv, CMD_RRB);
netif_rx(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
can_led_event(dev, CAN_LED_EVENT_RX);
}
static int sja1000_err(struct net_device *dev, uint8_t isrc, uint8_t status)
{
struct sja1000_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
enum can_state state = priv->can.state;
enum can_state rx_state, tx_state;
unsigned int rxerr, txerr;
uint8_t ecc, alc;
skb = alloc_can_err_skb(dev, &cf);
if (skb == NULL)
return -ENOMEM;
txerr = priv->read_reg(priv, SJA1000_TXERR);
rxerr = priv->read_reg(priv, SJA1000_RXERR);
cf->data[6] = txerr;
cf->data[7] = rxerr;
if (isrc & IRQ_DOI) {
netdev_dbg(dev, "data overrun interrupt\n");
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_over_errors++;
stats->rx_errors++;
sja1000_write_cmdreg(priv, CMD_CDO);
}
if (isrc & IRQ_EI) {
netdev_dbg(dev, "error warning interrupt\n");
if (status & SR_BS)
state = CAN_STATE_BUS_OFF;
else if (status & SR_ES)
state = CAN_STATE_ERROR_WARNING;
else
state = CAN_STATE_ERROR_ACTIVE;
}
if (isrc & IRQ_BEI) {
priv->can.can_stats.bus_error++;
stats->rx_errors++;
ecc = priv->read_reg(priv, SJA1000_ECC);
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
switch (ecc & ECC_MASK) {
case ECC_BIT:
cf->data[2] |= CAN_ERR_PROT_BIT;
break;
case ECC_FORM:
cf->data[2] |= CAN_ERR_PROT_FORM;
break;
case ECC_STUFF:
cf->data[2] |= CAN_ERR_PROT_STUFF;
break;
default:
cf->data[2] |= CAN_ERR_PROT_UNSPEC;
cf->data[3] = ecc & ECC_SEG;
break;
}
if ((ecc & ECC_DIR) == 0)
cf->data[2] |= CAN_ERR_PROT_TX;
}
if (isrc & IRQ_EPI) {
netdev_dbg(dev, "error passive interrupt\n");
if (state == CAN_STATE_ERROR_PASSIVE)
state = CAN_STATE_ERROR_WARNING;
else
state = CAN_STATE_ERROR_PASSIVE;
}
if (isrc & IRQ_ALI) {
netdev_dbg(dev, "arbitration lost interrupt\n");
alc = priv->read_reg(priv, SJA1000_ALC);
priv->can.can_stats.arbitration_lost++;
stats->tx_errors++;
cf->can_id |= CAN_ERR_LOSTARB;
cf->data[0] = alc & 0x1f;
}
if (state != priv->can.state) {
tx_state = txerr >= rxerr ? state : 0;
rx_state = txerr <= rxerr ? state : 0;
can_change_state(dev, cf, tx_state, rx_state);
if(state == CAN_STATE_BUS_OFF)
can_bus_off(dev);
}
netif_rx(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
return 0;
}
irqreturn_t sja1000_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct sja1000_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
uint8_t isrc, status;
int n = 0;
if (priv->pre_irq)
priv->pre_irq(priv);
if (priv->read_reg(priv, SJA1000_IER) == IRQ_OFF)
goto out;
while ((isrc = priv->read_reg(priv, SJA1000_IR)) &&
(n < SJA1000_MAX_IRQ)) {
status = priv->read_reg(priv, SJA1000_SR);
if (status == 0xFF && sja1000_is_absent(priv))
goto out;
if (isrc & IRQ_WUI)
netdev_warn(dev, "wakeup interrupt\n");
if (isrc & IRQ_TI) {
if (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT &&
!(status & SR_TCS)) {
stats->tx_errors++;
can_free_echo_skb(dev, 0);
} else {
stats->tx_bytes +=
priv->read_reg(priv, SJA1000_FI) & 0xf;
stats->tx_packets++;
can_get_echo_skb(dev, 0);
}
netif_wake_queue(dev);
can_led_event(dev, CAN_LED_EVENT_TX);
}
if (isrc & IRQ_RI) {
while (status & SR_RBS) {
sja1000_rx(dev);
status = priv->read_reg(priv, SJA1000_SR);
if (status == 0xFF && sja1000_is_absent(priv))
goto out;
}
}
if (isrc & (IRQ_DOI | IRQ_EI | IRQ_BEI | IRQ_EPI | IRQ_ALI)) {
if (sja1000_err(dev, isrc, status))
break;
}
n++;
}
out:
if (priv->post_irq)
priv->post_irq(priv);
if (n >= SJA1000_MAX_IRQ)
netdev_dbg(dev, "%d messages handled in ISR", n);
return (n) ? IRQ_HANDLED : IRQ_NONE;
}
static int sja1000_open(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
int err;
set_reset_mode(dev);
err = open_candev(dev);
if (err)
return err;
if (!(priv->flags & SJA1000_CUSTOM_IRQ_HANDLER)) {
err = request_irq(dev->irq, sja1000_interrupt, priv->irq_flags,
dev->name, (void *)dev);
if (err) {
close_candev(dev);
return -EAGAIN;
}
}
sja1000_start(dev);
can_led_event(dev, CAN_LED_EVENT_OPEN);
netif_start_queue(dev);
return 0;
}
static int sja1000_close(struct net_device *dev)
{
struct sja1000_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
set_reset_mode(dev);
if (!(priv->flags & SJA1000_CUSTOM_IRQ_HANDLER))
free_irq(dev->irq, (void *)dev);
close_candev(dev);
can_led_event(dev, CAN_LED_EVENT_STOP);
return 0;
}
struct net_device *alloc_sja1000dev(int sizeof_priv)
{
struct net_device *dev;
struct sja1000_priv *priv;
dev = alloc_candev(sizeof(struct sja1000_priv) + sizeof_priv,
SJA1000_ECHO_SKB_MAX);
if (!dev)
return NULL;
priv = netdev_priv(dev);
priv->dev = dev;
priv->can.bittiming_const = &sja1000_bittiming_const;
priv->can.do_set_bittiming = sja1000_set_bittiming;
priv->can.do_set_mode = sja1000_set_mode;
priv->can.do_get_berr_counter = sja1000_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_LOOPBACK |
CAN_CTRLMODE_LISTENONLY |
CAN_CTRLMODE_3_SAMPLES |
CAN_CTRLMODE_ONE_SHOT |
CAN_CTRLMODE_BERR_REPORTING |
CAN_CTRLMODE_PRESUME_ACK;
spin_lock_init(&priv->cmdreg_lock);
if (sizeof_priv)
priv->priv = (void *)priv + sizeof(struct sja1000_priv);
return dev;
}
void free_sja1000dev(struct net_device *dev)
{
free_candev(dev);
}
int register_sja1000dev(struct net_device *dev)
{
int ret;
if (!sja1000_probe_chip(dev))
return -ENODEV;
dev->flags |= IFF_ECHO;
dev->netdev_ops = &sja1000_netdev_ops;
set_reset_mode(dev);
chipset_init(dev);
ret = register_candev(dev);
if (!ret)
devm_can_led_init(dev);
return ret;
}
void unregister_sja1000dev(struct net_device *dev)
{
set_reset_mode(dev);
unregister_candev(dev);
}
static __init int sja1000_init(void)
{
printk(KERN_INFO "%s CAN netdevice driver\n", DRV_NAME);
return 0;
}
static __exit void sja1000_exit(void)
{
printk(KERN_INFO "%s: driver removed\n", DRV_NAME);
}
