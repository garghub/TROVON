static inline unsigned int get_mb_rx_first(const struct at91_priv *priv)
{
return priv->devtype_data.rx_first;
}
static inline unsigned int get_mb_rx_last(const struct at91_priv *priv)
{
return priv->devtype_data.rx_last;
}
static inline unsigned int get_mb_rx_split(const struct at91_priv *priv)
{
return priv->devtype_data.rx_split;
}
static inline unsigned int get_mb_rx_num(const struct at91_priv *priv)
{
return get_mb_rx_last(priv) - get_mb_rx_first(priv) + 1;
}
static inline unsigned int get_mb_rx_low_last(const struct at91_priv *priv)
{
return get_mb_rx_split(priv) - 1;
}
static inline unsigned int get_mb_rx_low_mask(const struct at91_priv *priv)
{
return AT91_MB_MASK(get_mb_rx_split(priv)) &
~AT91_MB_MASK(get_mb_rx_first(priv));
}
static inline unsigned int get_mb_tx_shift(const struct at91_priv *priv)
{
return priv->devtype_data.tx_shift;
}
static inline unsigned int get_mb_tx_num(const struct at91_priv *priv)
{
return 1 << get_mb_tx_shift(priv);
}
static inline unsigned int get_mb_tx_first(const struct at91_priv *priv)
{
return get_mb_rx_last(priv) + 1;
}
static inline unsigned int get_mb_tx_last(const struct at91_priv *priv)
{
return get_mb_tx_first(priv) + get_mb_tx_num(priv) - 1;
}
static inline unsigned int get_next_prio_shift(const struct at91_priv *priv)
{
return get_mb_tx_shift(priv);
}
static inline unsigned int get_next_prio_mask(const struct at91_priv *priv)
{
return 0xf << get_mb_tx_shift(priv);
}
static inline unsigned int get_next_mb_mask(const struct at91_priv *priv)
{
return AT91_MB_MASK(get_mb_tx_shift(priv));
}
static inline unsigned int get_next_mask(const struct at91_priv *priv)
{
return get_next_mb_mask(priv) | get_next_prio_mask(priv);
}
static inline unsigned int get_irq_mb_rx(const struct at91_priv *priv)
{
return AT91_MB_MASK(get_mb_rx_last(priv) + 1) &
~AT91_MB_MASK(get_mb_rx_first(priv));
}
static inline unsigned int get_irq_mb_tx(const struct at91_priv *priv)
{
return AT91_MB_MASK(get_mb_tx_last(priv) + 1) &
~AT91_MB_MASK(get_mb_tx_first(priv));
}
static inline unsigned int get_tx_next_mb(const struct at91_priv *priv)
{
return (priv->tx_next & get_next_mb_mask(priv)) + get_mb_tx_first(priv);
}
static inline unsigned int get_tx_next_prio(const struct at91_priv *priv)
{
return (priv->tx_next >> get_next_prio_shift(priv)) & 0xf;
}
static inline unsigned int get_tx_echo_mb(const struct at91_priv *priv)
{
return (priv->tx_echo & get_next_mb_mask(priv)) + get_mb_tx_first(priv);
}
static inline u32 at91_read(const struct at91_priv *priv, enum at91_reg reg)
{
return readl_relaxed(priv->reg_base + reg);
}
static inline void at91_write(const struct at91_priv *priv, enum at91_reg reg,
u32 value)
{
writel_relaxed(value, priv->reg_base + reg);
}
static inline void set_mb_mode_prio(const struct at91_priv *priv,
unsigned int mb, enum at91_mb_mode mode, int prio)
{
at91_write(priv, AT91_MMR(mb), (mode << 24) | (prio << 16));
}
static inline void set_mb_mode(const struct at91_priv *priv, unsigned int mb,
enum at91_mb_mode mode)
{
set_mb_mode_prio(priv, mb, mode, 0);
}
static inline u32 at91_can_id_to_reg_mid(canid_t can_id)
{
u32 reg_mid;
if (can_id & CAN_EFF_FLAG)
reg_mid = (can_id & CAN_EFF_MASK) | AT91_MID_MIDE;
else
reg_mid = (can_id & CAN_SFF_MASK) << 18;
return reg_mid;
}
static void at91_setup_mailboxes(struct net_device *dev)
{
struct at91_priv *priv = netdev_priv(dev);
unsigned int i;
u32 reg_mid;
reg_mid = at91_can_id_to_reg_mid(priv->mb0_id);
for (i = 0; i < get_mb_rx_first(priv); i++) {
set_mb_mode(priv, i, AT91_MB_MODE_DISABLED);
at91_write(priv, AT91_MID(i), reg_mid);
at91_write(priv, AT91_MCR(i), 0x0);
}
for (i = get_mb_rx_first(priv); i < get_mb_rx_last(priv); i++)
set_mb_mode(priv, i, AT91_MB_MODE_RX);
set_mb_mode(priv, get_mb_rx_last(priv), AT91_MB_MODE_RX_OVRWR);
for (i = get_mb_rx_first(priv); i <= get_mb_rx_last(priv); i++) {
at91_write(priv, AT91_MAM(i), 0x0);
at91_write(priv, AT91_MID(i), AT91_MID_MIDE);
}
for (i = get_mb_tx_first(priv); i <= get_mb_tx_last(priv); i++)
set_mb_mode_prio(priv, i, AT91_MB_MODE_TX, 0);
priv->tx_next = priv->tx_echo = 0;
priv->rx_next = get_mb_rx_first(priv);
}
static int at91_set_bittiming(struct net_device *dev)
{
const struct at91_priv *priv = netdev_priv(dev);
const struct can_bittiming *bt = &priv->can.bittiming;
u32 reg_br;
reg_br = ((priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES) ? 1 << 24 : 0) |
((bt->brp - 1) << 16) | ((bt->sjw - 1) << 12) |
((bt->prop_seg - 1) << 8) | ((bt->phase_seg1 - 1) << 4) |
((bt->phase_seg2 - 1) << 0);
netdev_info(dev, "writing AT91_BR: 0x%08x\n", reg_br);
at91_write(priv, AT91_BR, reg_br);
return 0;
}
static int at91_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
const struct at91_priv *priv = netdev_priv(dev);
u32 reg_ecr = at91_read(priv, AT91_ECR);
bec->rxerr = reg_ecr & 0xff;
bec->txerr = reg_ecr >> 16;
return 0;
}
static void at91_chip_start(struct net_device *dev)
{
struct at91_priv *priv = netdev_priv(dev);
u32 reg_mr, reg_ier;
at91_write(priv, AT91_IDR, AT91_IRQ_ALL);
reg_mr = at91_read(priv, AT91_MR);
at91_write(priv, AT91_MR, reg_mr & ~AT91_MR_CANEN);
at91_set_bittiming(dev);
at91_setup_mailboxes(dev);
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
reg_mr = AT91_MR_CANEN | AT91_MR_ABM;
else
reg_mr = AT91_MR_CANEN;
at91_write(priv, AT91_MR, reg_mr);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
reg_ier = get_irq_mb_rx(priv) | AT91_IRQ_ERRP | AT91_IRQ_ERR_FRAME;
at91_write(priv, AT91_IDR, AT91_IRQ_ALL);
at91_write(priv, AT91_IER, reg_ier);
}
static void at91_chip_stop(struct net_device *dev, enum can_state state)
{
struct at91_priv *priv = netdev_priv(dev);
u32 reg_mr;
at91_write(priv, AT91_IDR, AT91_IRQ_ALL);
reg_mr = at91_read(priv, AT91_MR);
at91_write(priv, AT91_MR, reg_mr & ~AT91_MR_CANEN);
priv->can.state = state;
}
static netdev_tx_t at91_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct at91_priv *priv = netdev_priv(dev);
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf = (struct can_frame *)skb->data;
unsigned int mb, prio;
u32 reg_mid, reg_mcr;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
mb = get_tx_next_mb(priv);
prio = get_tx_next_prio(priv);
if (unlikely(!(at91_read(priv, AT91_MSR(mb)) & AT91_MSR_MRDY))) {
netif_stop_queue(dev);
netdev_err(dev, "BUG! TX buffer full when queue awake!\n");
return NETDEV_TX_BUSY;
}
reg_mid = at91_can_id_to_reg_mid(cf->can_id);
reg_mcr = ((cf->can_id & CAN_RTR_FLAG) ? AT91_MCR_MRTR : 0) |
(cf->can_dlc << 16) | AT91_MCR_MTCR;
set_mb_mode(priv, mb, AT91_MB_MODE_DISABLED);
at91_write(priv, AT91_MID(mb), reg_mid);
set_mb_mode_prio(priv, mb, AT91_MB_MODE_TX, prio);
at91_write(priv, AT91_MDL(mb), *(u32 *)(cf->data + 0));
at91_write(priv, AT91_MDH(mb), *(u32 *)(cf->data + 4));
at91_write(priv, AT91_MCR(mb), reg_mcr);
stats->tx_bytes += cf->can_dlc;
can_put_echo_skb(skb, dev, mb - get_mb_tx_first(priv));
priv->tx_next++;
if (!(at91_read(priv, AT91_MSR(get_tx_next_mb(priv))) &
AT91_MSR_MRDY) ||
(priv->tx_next & get_next_mask(priv)) == 0)
netif_stop_queue(dev);
at91_write(priv, AT91_IER, 1 << mb);
return NETDEV_TX_OK;
}
static inline void at91_activate_rx_low(const struct at91_priv *priv)
{
u32 mask = get_mb_rx_low_mask(priv);
at91_write(priv, AT91_TCR, mask);
}
static inline void at91_activate_rx_mb(const struct at91_priv *priv,
unsigned int mb)
{
u32 mask = 1 << mb;
at91_write(priv, AT91_TCR, mask);
}
static void at91_rx_overflow_err(struct net_device *dev)
{
struct net_device_stats *stats = &dev->stats;
struct sk_buff *skb;
struct can_frame *cf;
netdev_dbg(dev, "RX buffer overflow\n");
stats->rx_over_errors++;
stats->rx_errors++;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] = CAN_ERR_CRTL_RX_OVERFLOW;
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
}
static void at91_read_mb(struct net_device *dev, unsigned int mb,
struct can_frame *cf)
{
const struct at91_priv *priv = netdev_priv(dev);
u32 reg_msr, reg_mid;
reg_mid = at91_read(priv, AT91_MID(mb));
if (reg_mid & AT91_MID_MIDE)
cf->can_id = ((reg_mid >> 0) & CAN_EFF_MASK) | CAN_EFF_FLAG;
else
cf->can_id = (reg_mid >> 18) & CAN_SFF_MASK;
reg_msr = at91_read(priv, AT91_MSR(mb));
cf->can_dlc = get_can_dlc((reg_msr >> 16) & 0xf);
if (reg_msr & AT91_MSR_MRTR)
cf->can_id |= CAN_RTR_FLAG;
else {
*(u32 *)(cf->data + 0) = at91_read(priv, AT91_MDL(mb));
*(u32 *)(cf->data + 4) = at91_read(priv, AT91_MDH(mb));
}
at91_write(priv, AT91_MID(mb), AT91_MID_MIDE);
if (unlikely(mb == get_mb_rx_last(priv) && reg_msr & AT91_MSR_MMI))
at91_rx_overflow_err(dev);
}
static void at91_read_msg(struct net_device *dev, unsigned int mb)
{
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
skb = alloc_can_skb(dev, &cf);
if (unlikely(!skb)) {
stats->rx_dropped++;
return;
}
at91_read_mb(dev, mb, cf);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
can_led_event(dev, CAN_LED_EVENT_RX);
}
static int at91_poll_rx(struct net_device *dev, int quota)
{
struct at91_priv *priv = netdev_priv(dev);
u32 reg_sr = at91_read(priv, AT91_SR);
const unsigned long *addr = (unsigned long *)&reg_sr;
unsigned int mb;
int received = 0;
if (priv->rx_next > get_mb_rx_low_last(priv) &&
reg_sr & get_mb_rx_low_mask(priv))
netdev_info(dev,
"order of incoming frames cannot be guaranteed\n");
again:
for (mb = find_next_bit(addr, get_mb_tx_first(priv), priv->rx_next);
mb < get_mb_tx_first(priv) && quota > 0;
reg_sr = at91_read(priv, AT91_SR),
mb = find_next_bit(addr, get_mb_tx_first(priv), ++priv->rx_next)) {
at91_read_msg(dev, mb);
if (mb == get_mb_rx_low_last(priv))
at91_activate_rx_low(priv);
else if (mb > get_mb_rx_low_last(priv))
at91_activate_rx_mb(priv, mb);
received++;
quota--;
}
if (priv->rx_next > get_mb_rx_low_last(priv) &&
quota > 0 && mb > get_mb_rx_last(priv)) {
priv->rx_next = get_mb_rx_first(priv);
goto again;
}
return received;
}
static void at91_poll_err_frame(struct net_device *dev,
struct can_frame *cf, u32 reg_sr)
{
struct at91_priv *priv = netdev_priv(dev);
if (reg_sr & AT91_IRQ_CERR) {
netdev_dbg(dev, "CERR irq\n");
dev->stats.rx_errors++;
priv->can.can_stats.bus_error++;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
}
if (reg_sr & AT91_IRQ_SERR) {
netdev_dbg(dev, "SERR irq\n");
dev->stats.rx_errors++;
priv->can.can_stats.bus_error++;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
cf->data[2] |= CAN_ERR_PROT_STUFF;
}
if (reg_sr & AT91_IRQ_AERR) {
netdev_dbg(dev, "AERR irq\n");
dev->stats.tx_errors++;
cf->can_id |= CAN_ERR_ACK;
}
if (reg_sr & AT91_IRQ_FERR) {
netdev_dbg(dev, "FERR irq\n");
dev->stats.rx_errors++;
priv->can.can_stats.bus_error++;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
cf->data[2] |= CAN_ERR_PROT_FORM;
}
if (reg_sr & AT91_IRQ_BERR) {
netdev_dbg(dev, "BERR irq\n");
dev->stats.tx_errors++;
priv->can.can_stats.bus_error++;
cf->can_id |= CAN_ERR_PROT | CAN_ERR_BUSERROR;
cf->data[2] |= CAN_ERR_PROT_BIT;
}
}
static int at91_poll_err(struct net_device *dev, int quota, u32 reg_sr)
{
struct sk_buff *skb;
struct can_frame *cf;
if (quota == 0)
return 0;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return 0;
at91_poll_err_frame(dev, cf, reg_sr);
dev->stats.rx_packets++;
dev->stats.rx_bytes += cf->can_dlc;
netif_receive_skb(skb);
return 1;
}
static int at91_poll(struct napi_struct *napi, int quota)
{
struct net_device *dev = napi->dev;
const struct at91_priv *priv = netdev_priv(dev);
u32 reg_sr = at91_read(priv, AT91_SR);
int work_done = 0;
if (reg_sr & get_irq_mb_rx(priv))
work_done += at91_poll_rx(dev, quota - work_done);
reg_sr |= priv->reg_sr;
if (reg_sr & AT91_IRQ_ERR_FRAME)
work_done += at91_poll_err(dev, quota - work_done, reg_sr);
if (work_done < quota) {
u32 reg_ier = AT91_IRQ_ERR_FRAME;
reg_ier |= get_irq_mb_rx(priv) & ~AT91_MB_MASK(priv->rx_next);
napi_complete(napi);
at91_write(priv, AT91_IER, reg_ier);
}
return work_done;
}
static void at91_irq_tx(struct net_device *dev, u32 reg_sr)
{
struct at91_priv *priv = netdev_priv(dev);
u32 reg_msr;
unsigned int mb;
for (; (priv->tx_next - priv->tx_echo) > 0; priv->tx_echo++) {
mb = get_tx_echo_mb(priv);
if (!(reg_sr & (1 << mb)))
break;
at91_write(priv, AT91_IDR, 1 << mb);
reg_msr = at91_read(priv, AT91_MSR(mb));
if (likely(reg_msr & AT91_MSR_MRDY &&
~reg_msr & AT91_MSR_MABT)) {
can_get_echo_skb(dev, mb - get_mb_tx_first(priv));
dev->stats.tx_packets++;
can_led_event(dev, CAN_LED_EVENT_TX);
}
}
if ((priv->tx_next & get_next_mask(priv)) != 0 ||
(priv->tx_echo & get_next_mask(priv)) == 0)
netif_wake_queue(dev);
}
static void at91_irq_err_state(struct net_device *dev,
struct can_frame *cf, enum can_state new_state)
{
struct at91_priv *priv = netdev_priv(dev);
u32 reg_idr = 0, reg_ier = 0;
struct can_berr_counter bec;
at91_get_berr_counter(dev, &bec);
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
if (new_state <= CAN_STATE_ERROR_PASSIVE) {
cf->can_id |= CAN_ERR_RESTARTED;
netdev_dbg(dev, "restarted\n");
priv->can.can_stats.restarts++;
netif_carrier_on(dev);
netif_wake_queue(dev);
}
break;
default:
break;
}
switch (new_state) {
case CAN_STATE_ERROR_ACTIVE:
netdev_dbg(dev, "Error Active\n");
cf->can_id |= CAN_ERR_PROT;
cf->data[2] = CAN_ERR_PROT_ACTIVE;
case CAN_STATE_ERROR_WARNING:
reg_idr = AT91_IRQ_ERRA | AT91_IRQ_WARN | AT91_IRQ_BOFF;
reg_ier = AT91_IRQ_ERRP;
break;
case CAN_STATE_ERROR_PASSIVE:
reg_idr = AT91_IRQ_ERRA | AT91_IRQ_WARN | AT91_IRQ_ERRP;
reg_ier = AT91_IRQ_BOFF;
break;
case CAN_STATE_BUS_OFF:
reg_idr = AT91_IRQ_ERRA | AT91_IRQ_ERRP |
AT91_IRQ_WARN | AT91_IRQ_BOFF;
reg_ier = 0;
cf->can_id |= CAN_ERR_BUSOFF;
netdev_dbg(dev, "bus-off\n");
netif_carrier_off(dev);
priv->can.can_stats.bus_off++;
if (!priv->can.restart_ms) {
at91_chip_stop(dev, CAN_STATE_BUS_OFF);
return;
}
break;
default:
break;
}
at91_write(priv, AT91_IDR, reg_idr);
at91_write(priv, AT91_IER, reg_ier);
}
static int at91_get_state_by_bec(const struct net_device *dev,
enum can_state *state)
{
struct can_berr_counter bec;
int err;
err = at91_get_berr_counter(dev, &bec);
if (err)
return err;
if (bec.txerr < 96 && bec.rxerr < 96)
*state = CAN_STATE_ERROR_ACTIVE;
else if (bec.txerr < 128 && bec.rxerr < 128)
*state = CAN_STATE_ERROR_WARNING;
else if (bec.txerr < 256 && bec.rxerr < 256)
*state = CAN_STATE_ERROR_PASSIVE;
else
*state = CAN_STATE_BUS_OFF;
return 0;
}
static void at91_irq_err(struct net_device *dev)
{
struct at91_priv *priv = netdev_priv(dev);
struct sk_buff *skb;
struct can_frame *cf;
enum can_state new_state;
u32 reg_sr;
int err;
if (at91_is_sam9263(priv)) {
reg_sr = at91_read(priv, AT91_SR);
if (unlikely(reg_sr & AT91_IRQ_BOFF))
new_state = CAN_STATE_BUS_OFF;
else if (unlikely(reg_sr & AT91_IRQ_ERRP))
new_state = CAN_STATE_ERROR_PASSIVE;
else if (unlikely(reg_sr & AT91_IRQ_WARN))
new_state = CAN_STATE_ERROR_WARNING;
else if (likely(reg_sr & AT91_IRQ_ERRA))
new_state = CAN_STATE_ERROR_ACTIVE;
else {
netdev_err(dev, "BUG! hardware in undefined state\n");
return;
}
} else {
err = at91_get_state_by_bec(dev, &new_state);
if (err)
return;
}
if (likely(new_state == priv->can.state))
return;
skb = alloc_can_err_skb(dev, &cf);
if (unlikely(!skb))
return;
at91_irq_err_state(dev, cf, new_state);
dev->stats.rx_packets++;
dev->stats.rx_bytes += cf->can_dlc;
netif_rx(skb);
priv->can.state = new_state;
}
static irqreturn_t at91_irq(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct at91_priv *priv = netdev_priv(dev);
irqreturn_t handled = IRQ_NONE;
u32 reg_sr, reg_imr;
reg_sr = at91_read(priv, AT91_SR);
reg_imr = at91_read(priv, AT91_IMR);
reg_sr &= reg_imr;
if (!reg_sr)
goto exit;
handled = IRQ_HANDLED;
if (reg_sr & (get_irq_mb_rx(priv) | AT91_IRQ_ERR_FRAME)) {
priv->reg_sr = reg_sr;
at91_write(priv, AT91_IDR,
get_irq_mb_rx(priv) | AT91_IRQ_ERR_FRAME);
napi_schedule(&priv->napi);
}
if (reg_sr & get_irq_mb_tx(priv))
at91_irq_tx(dev, reg_sr);
at91_irq_err(dev);
exit:
return handled;
}
static int at91_open(struct net_device *dev)
{
struct at91_priv *priv = netdev_priv(dev);
int err;
err = clk_prepare_enable(priv->clk);
if (err)
return err;
err = open_candev(dev);
if (err)
goto out;
if (request_irq(dev->irq, at91_irq, IRQF_SHARED,
dev->name, dev)) {
err = -EAGAIN;
goto out_close;
}
can_led_event(dev, CAN_LED_EVENT_OPEN);
at91_chip_start(dev);
napi_enable(&priv->napi);
netif_start_queue(dev);
return 0;
out_close:
close_candev(dev);
out:
clk_disable_unprepare(priv->clk);
return err;
}
static int at91_close(struct net_device *dev)
{
struct at91_priv *priv = netdev_priv(dev);
netif_stop_queue(dev);
napi_disable(&priv->napi);
at91_chip_stop(dev, CAN_STATE_STOPPED);
free_irq(dev->irq, dev);
clk_disable_unprepare(priv->clk);
close_candev(dev);
can_led_event(dev, CAN_LED_EVENT_STOP);
return 0;
}
static int at91_set_mode(struct net_device *dev, enum can_mode mode)
{
switch (mode) {
case CAN_MODE_START:
at91_chip_start(dev);
netif_wake_queue(dev);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static ssize_t at91_sysfs_show_mb0_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct at91_priv *priv = netdev_priv(to_net_dev(dev));
if (priv->mb0_id & CAN_EFF_FLAG)
return snprintf(buf, PAGE_SIZE, "0x%08x\n", priv->mb0_id);
else
return snprintf(buf, PAGE_SIZE, "0x%03x\n", priv->mb0_id);
}
static ssize_t at91_sysfs_set_mb0_id(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct net_device *ndev = to_net_dev(dev);
struct at91_priv *priv = netdev_priv(ndev);
unsigned long can_id;
ssize_t ret;
int err;
rtnl_lock();
if (ndev->flags & IFF_UP) {
ret = -EBUSY;
goto out;
}
err = kstrtoul(buf, 0, &can_id);
if (err) {
ret = err;
goto out;
}
if (can_id & CAN_EFF_FLAG)
can_id &= CAN_EFF_MASK | CAN_EFF_FLAG;
else
can_id &= CAN_SFF_MASK;
priv->mb0_id = can_id;
ret = count;
out:
rtnl_unlock();
return ret;
}
static const struct at91_devtype_data *at91_can_get_driver_data(struct platform_device *pdev)
{
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_node(at91_can_dt_ids, pdev->dev.of_node);
if (!match) {
dev_err(&pdev->dev, "no matching node found in dtb\n");
return NULL;
}
return (const struct at91_devtype_data *)match->data;
}
return (const struct at91_devtype_data *)
platform_get_device_id(pdev)->driver_data;
}
static int at91_can_probe(struct platform_device *pdev)
{
const struct at91_devtype_data *devtype_data;
struct net_device *dev;
struct at91_priv *priv;
struct resource *res;
struct clk *clk;
void __iomem *addr;
int err, irq;
devtype_data = at91_can_get_driver_data(pdev);
if (!devtype_data) {
dev_err(&pdev->dev, "no driver data\n");
err = -ENODEV;
goto exit;
}
clk = clk_get(&pdev->dev, "can_clk");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "no clock defined\n");
err = -ENODEV;
goto exit;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || irq <= 0) {
err = -ENODEV;
goto exit_put;
}
if (!request_mem_region(res->start,
resource_size(res),
pdev->name)) {
err = -EBUSY;
goto exit_put;
}
addr = ioremap_nocache(res->start, resource_size(res));
if (!addr) {
err = -ENOMEM;
goto exit_release;
}
dev = alloc_candev(sizeof(struct at91_priv),
1 << devtype_data->tx_shift);
if (!dev) {
err = -ENOMEM;
goto exit_iounmap;
}
dev->netdev_ops = &at91_netdev_ops;
dev->irq = irq;
dev->flags |= IFF_ECHO;
priv = netdev_priv(dev);
priv->can.clock.freq = clk_get_rate(clk);
priv->can.bittiming_const = &at91_bittiming_const;
priv->can.do_set_mode = at91_set_mode;
priv->can.do_get_berr_counter = at91_get_berr_counter;
priv->can.ctrlmode_supported = CAN_CTRLMODE_3_SAMPLES |
CAN_CTRLMODE_LISTENONLY;
priv->reg_base = addr;
priv->devtype_data = *devtype_data;
priv->clk = clk;
priv->pdata = dev_get_platdata(&pdev->dev);
priv->mb0_id = 0x7ff;
netif_napi_add(dev, &priv->napi, at91_poll, get_mb_rx_num(priv));
if (at91_is_sam9263(priv))
dev->sysfs_groups[0] = &at91_sysfs_attr_group;
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_candev(dev);
if (err) {
dev_err(&pdev->dev, "registering netdev failed\n");
goto exit_free;
}
devm_can_led_init(dev);
dev_info(&pdev->dev, "device registered (reg_base=%p, irq=%d)\n",
priv->reg_base, dev->irq);
return 0;
exit_free:
free_candev(dev);
exit_iounmap:
iounmap(addr);
exit_release:
release_mem_region(res->start, resource_size(res));
exit_put:
clk_put(clk);
exit:
return err;
}
static int at91_can_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct at91_priv *priv = netdev_priv(dev);
struct resource *res;
unregister_netdev(dev);
iounmap(priv->reg_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
clk_put(priv->clk);
free_candev(dev);
return 0;
}
