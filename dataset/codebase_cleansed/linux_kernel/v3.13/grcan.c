static inline u32 grcan_read_reg(u32 __iomem *reg)
{
return ioread32be(reg);
}
static inline void grcan_write_reg(u32 __iomem *reg, u32 val)
{
iowrite32be(val, reg);
}
static inline u32 grcan_read_reg(u32 __iomem *reg)
{
return ioread32(reg);
}
static inline void grcan_write_reg(u32 __iomem *reg, u32 val)
{
iowrite32(val, reg);
}
static inline void grcan_clear_bits(u32 __iomem *reg, u32 mask)
{
grcan_write_reg(reg, grcan_read_reg(reg) & ~mask);
}
static inline void grcan_set_bits(u32 __iomem *reg, u32 mask)
{
grcan_write_reg(reg, grcan_read_reg(reg) | mask);
}
static inline u32 grcan_read_bits(u32 __iomem *reg, u32 mask)
{
return grcan_read_reg(reg) & mask;
}
static inline void grcan_write_bits(u32 __iomem *reg, u32 value, u32 mask)
{
u32 old = grcan_read_reg(reg);
grcan_write_reg(reg, (old & ~mask) | (value & mask));
}
static inline u32 grcan_ring_add(u32 a, u32 b, u32 size)
{
u32 sum = a + b;
if (sum < size)
return sum;
else
return sum - size;
}
static inline u32 grcan_ring_sub(u32 a, u32 b, u32 size)
{
return grcan_ring_add(a, size - b, size);
}
static inline u32 grcan_txspace(size_t txsize, u32 txwr, u32 eskbp)
{
u32 slots = txsize / GRCAN_MSG_SIZE - 1;
u32 used = grcan_ring_sub(txwr, eskbp, txsize) / GRCAN_MSG_SIZE;
return slots - used;
}
static int grcan_set_bittiming(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct can_bittiming *bt = &priv->can.bittiming;
u32 timing = 0;
int bpr, rsj, ps1, ps2, scaler;
if (grcan_read_bits(&regs->ctrl, GRCAN_CTRL_ENABLE))
return -EBUSY;
bpr = 0;
rsj = bt->sjw;
ps1 = (bt->prop_seg + bt->phase_seg1) - 1;
ps2 = bt->phase_seg2;
scaler = (bt->brp - 1);
netdev_dbg(dev, "Request for BPR=%d, RSJ=%d, PS1=%d, PS2=%d, SCALER=%d",
bpr, rsj, ps1, ps2, scaler);
if (!(ps1 > ps2)) {
netdev_err(dev, "PS1 > PS2 must hold: PS1=%d, PS2=%d\n",
ps1, ps2);
return -EINVAL;
}
if (!(ps2 >= rsj)) {
netdev_err(dev, "PS2 >= RSJ must hold: PS2=%d, RSJ=%d\n",
ps2, rsj);
return -EINVAL;
}
timing |= (bpr << GRCAN_CONF_BPR_BIT) & GRCAN_CONF_BPR;
timing |= (rsj << GRCAN_CONF_RSJ_BIT) & GRCAN_CONF_RSJ;
timing |= (ps1 << GRCAN_CONF_PS1_BIT) & GRCAN_CONF_PS1;
timing |= (ps2 << GRCAN_CONF_PS2_BIT) & GRCAN_CONF_PS2;
timing |= (scaler << GRCAN_CONF_SCALER_BIT) & GRCAN_CONF_SCALER;
netdev_info(dev, "setting timing=0x%x\n", timing);
grcan_write_bits(&regs->conf, timing, GRCAN_CONF_TIMING);
return 0;
}
static int grcan_get_berr_counter(const struct net_device *dev,
struct can_berr_counter *bec)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
u32 status = grcan_read_reg(&regs->stat);
bec->txerr = (status & GRCAN_STAT_TXERRCNT) >> GRCAN_STAT_TXERRCNT_BIT;
bec->rxerr = (status & GRCAN_STAT_RXERRCNT) >> GRCAN_STAT_RXERRCNT_BIT;
return 0;
}
static void grcan_reset(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
u32 config = grcan_read_reg(&regs->conf);
grcan_set_bits(&regs->ctrl, GRCAN_CTRL_RESET);
grcan_write_reg(&regs->conf, config);
priv->eskbp = grcan_read_reg(&regs->txrd);
priv->can.state = CAN_STATE_STOPPED;
grcan_write_reg(&regs->rxmask, 0);
}
static void grcan_stop_hardware(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
grcan_write_reg(&regs->imr, GRCAN_IRQ_NONE);
grcan_clear_bits(&regs->txctrl, GRCAN_TXCTRL_ENABLE);
grcan_clear_bits(&regs->rxctrl, GRCAN_RXCTRL_ENABLE);
grcan_clear_bits(&regs->ctrl, GRCAN_CTRL_ENABLE);
}
static int catch_up_echo_skb(struct net_device *dev, int budget, bool echo)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct grcan_dma *dma = &priv->dma;
struct net_device_stats *stats = &dev->stats;
int i, work_done;
u32 txrd = grcan_read_reg(&regs->txrd);
for (work_done = 0; work_done < budget || budget < 0; work_done++) {
if (priv->eskbp == txrd)
break;
i = priv->eskbp / GRCAN_MSG_SIZE;
if (echo) {
stats->tx_packets++;
stats->tx_bytes += priv->txdlc[i];
priv->txdlc[i] = 0;
can_get_echo_skb(dev, i);
} else {
can_free_echo_skb(dev, i);
}
priv->eskbp = grcan_ring_add(priv->eskbp, GRCAN_MSG_SIZE,
dma->tx.size);
txrd = grcan_read_reg(&regs->txrd);
}
return work_done;
}
static void grcan_lost_one_shot_frame(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct grcan_dma *dma = &priv->dma;
u32 txrd;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
catch_up_echo_skb(dev, -1, true);
if (unlikely(grcan_read_bits(&regs->txctrl, GRCAN_TXCTRL_ENABLE))) {
netdev_err(dev, "TXCTRL enabled at TXLOSS in one shot mode\n");
} else {
txrd = grcan_read_reg(&regs->txrd);
txrd = grcan_ring_add(txrd, GRCAN_MSG_SIZE, dma->tx.size);
grcan_write_reg(&regs->txrd, txrd);
catch_up_echo_skb(dev, -1, false);
if (!priv->resetting && !priv->closing &&
!(priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)) {
netif_wake_queue(dev);
grcan_set_bits(&regs->txctrl, GRCAN_TXCTRL_ENABLE);
}
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static void grcan_err(struct net_device *dev, u32 sources, u32 status)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct grcan_dma *dma = &priv->dma;
struct net_device_stats *stats = &dev->stats;
struct can_frame cf;
memset(&cf, 0, sizeof(cf));
if (sources & GRCAN_IRQ_TXLOSS) {
if (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT)
grcan_lost_one_shot_frame(dev);
if (!(status & GRCAN_STAT_ERRCTR_RELATED)) {
netdev_dbg(dev, "tx message lost\n");
stats->tx_errors++;
}
}
if ((sources & GRCAN_IRQ_ERRCTR_RELATED) ||
(status & GRCAN_STAT_ERRCTR_RELATED)) {
enum can_state state = priv->can.state;
enum can_state oldstate = state;
u32 txerr = (status & GRCAN_STAT_TXERRCNT)
>> GRCAN_STAT_TXERRCNT_BIT;
u32 rxerr = (status & GRCAN_STAT_RXERRCNT)
>> GRCAN_STAT_RXERRCNT_BIT;
if (status & GRCAN_STAT_OFF) {
state = CAN_STATE_BUS_OFF;
} else if (status & GRCAN_STAT_PASS) {
state = CAN_STATE_ERROR_PASSIVE;
} else if (txerr >= GRCAN_STAT_ERRCNT_WARNING_LIMIT ||
rxerr >= GRCAN_STAT_ERRCNT_WARNING_LIMIT) {
state = CAN_STATE_ERROR_WARNING;
} else {
state = CAN_STATE_ERROR_ACTIVE;
}
if (state != oldstate) {
switch (state) {
case CAN_STATE_BUS_OFF:
netdev_dbg(dev, "bus-off\n");
netif_carrier_off(dev);
priv->can.can_stats.bus_off++;
if (!priv->can.restart_ms)
grcan_stop_hardware(dev);
cf.can_id |= CAN_ERR_BUSOFF;
break;
case CAN_STATE_ERROR_PASSIVE:
netdev_dbg(dev, "Error passive condition\n");
priv->can.can_stats.error_passive++;
cf.can_id |= CAN_ERR_CRTL;
if (txerr >= GRCAN_STAT_ERRCNT_PASSIVE_LIMIT)
cf.data[1] |= CAN_ERR_CRTL_TX_PASSIVE;
if (rxerr >= GRCAN_STAT_ERRCNT_PASSIVE_LIMIT)
cf.data[1] |= CAN_ERR_CRTL_RX_PASSIVE;
break;
case CAN_STATE_ERROR_WARNING:
netdev_dbg(dev, "Error warning condition\n");
priv->can.can_stats.error_warning++;
cf.can_id |= CAN_ERR_CRTL;
if (txerr >= GRCAN_STAT_ERRCNT_WARNING_LIMIT)
cf.data[1] |= CAN_ERR_CRTL_TX_WARNING;
if (rxerr >= GRCAN_STAT_ERRCNT_WARNING_LIMIT)
cf.data[1] |= CAN_ERR_CRTL_RX_WARNING;
break;
case CAN_STATE_ERROR_ACTIVE:
netdev_dbg(dev, "Error active condition\n");
cf.can_id |= CAN_ERR_CRTL;
break;
default:
break;
}
cf.data[6] = txerr;
cf.data[7] = rxerr;
priv->can.state = state;
}
if (priv->can.restart_ms && oldstate == CAN_STATE_BUS_OFF) {
unsigned long flags;
cf.can_id |= CAN_ERR_RESTARTED;
netdev_dbg(dev, "restarted\n");
priv->can.can_stats.restarts++;
netif_carrier_on(dev);
spin_lock_irqsave(&priv->lock, flags);
if (!priv->resetting && !priv->closing) {
u32 txwr = grcan_read_reg(&regs->txwr);
if (grcan_txspace(dma->tx.size, txwr,
priv->eskbp))
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&priv->lock, flags);
}
}
if ((sources & GRCAN_IRQ_OR) || (status & GRCAN_STAT_OR)) {
netdev_dbg(dev, "got data overrun interrupt\n");
stats->rx_over_errors++;
stats->rx_errors++;
cf.can_id |= CAN_ERR_CRTL;
cf.data[1] |= CAN_ERR_CRTL_RX_OVERFLOW;
}
if (sources & (GRCAN_IRQ_TXAHBERR | GRCAN_IRQ_RXAHBERR) ||
(status & GRCAN_STAT_AHBERR)) {
char *txrx = "";
unsigned long flags;
if (sources & GRCAN_IRQ_TXAHBERR) {
txrx = "on tx ";
stats->tx_errors++;
} else if (sources & GRCAN_IRQ_RXAHBERR) {
txrx = "on rx ";
stats->rx_errors++;
}
netdev_err(dev, "Fatal AHB buss error %s- halting device\n",
txrx);
spin_lock_irqsave(&priv->lock, flags);
priv->closing = true;
netif_stop_queue(dev);
grcan_stop_hardware(dev);
priv->can.state = CAN_STATE_STOPPED;
spin_unlock_irqrestore(&priv->lock, flags);
}
if (cf.can_id) {
struct can_frame *skb_cf;
struct sk_buff *skb = alloc_can_err_skb(dev, &skb_cf);
if (skb == NULL) {
netdev_dbg(dev, "could not allocate error frame\n");
return;
}
skb_cf->can_id |= cf.can_id;
memcpy(skb_cf->data, cf.data, sizeof(cf.data));
netif_rx(skb);
}
}
static irqreturn_t grcan_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
u32 sources, status;
sources = grcan_read_reg(&regs->pimsr);
if (!sources)
return IRQ_NONE;
grcan_write_reg(&regs->picr, sources);
status = grcan_read_reg(&regs->stat);
if (priv->need_txbug_workaround &&
(sources & (GRCAN_IRQ_TX | GRCAN_IRQ_TXLOSS))) {
del_timer(&priv->hang_timer);
}
if (sources & (GRCAN_IRQ_TX | GRCAN_IRQ_RX)) {
grcan_clear_bits(&regs->imr, GRCAN_IRQ_TX | GRCAN_IRQ_RX);
napi_schedule(&priv->napi);
}
if (sources & GRCAN_IRQ_ERRORS)
grcan_err(dev, sources, status);
return IRQ_HANDLED;
}
static void grcan_running_reset(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
priv->resetting = false;
del_timer(&priv->hang_timer);
del_timer(&priv->rr_timer);
if (!priv->closing) {
u32 imr = grcan_read_reg(&regs->imr);
u32 txaddr = grcan_read_reg(&regs->txaddr);
u32 txsize = grcan_read_reg(&regs->txsize);
u32 txwr = grcan_read_reg(&regs->txwr);
u32 txrd = grcan_read_reg(&regs->txrd);
u32 eskbp = priv->eskbp;
u32 rxaddr = grcan_read_reg(&regs->rxaddr);
u32 rxsize = grcan_read_reg(&regs->rxsize);
u32 rxwr = grcan_read_reg(&regs->rxwr);
u32 rxrd = grcan_read_reg(&regs->rxrd);
grcan_reset(dev);
grcan_write_reg(&regs->txaddr, txaddr);
grcan_write_reg(&regs->txsize, txsize);
grcan_write_reg(&regs->txwr, txwr);
grcan_write_reg(&regs->txrd, txrd);
priv->eskbp = eskbp;
grcan_write_reg(&regs->rxaddr, rxaddr);
grcan_write_reg(&regs->rxsize, rxsize);
grcan_write_reg(&regs->rxwr, rxwr);
grcan_write_reg(&regs->rxrd, rxrd);
grcan_write_reg(&regs->imr, imr);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
grcan_write_reg(&regs->txctrl, GRCAN_TXCTRL_ENABLE
| (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT
? GRCAN_TXCTRL_SINGLE : 0));
grcan_write_reg(&regs->rxctrl, GRCAN_RXCTRL_ENABLE);
grcan_write_reg(&regs->ctrl, GRCAN_CTRL_ENABLE);
if (grcan_txspace(priv->dma.tx.size, txwr, priv->eskbp) &&
!(priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY))
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&priv->lock, flags);
netdev_err(dev, "Device reset and restored\n");
}
static inline u32 grcan_ongoing_wait_usecs(__u32 bitrate)
{
return 1000000 * 3 * GRCAN_EFF_FRAME_MAX_BITS / bitrate;
}
static inline void grcan_reset_timer(struct timer_list *timer, __u32 bitrate)
{
u32 wait_jiffies = usecs_to_jiffies(grcan_ongoing_wait_usecs(bitrate));
mod_timer(timer, jiffies + wait_jiffies);
}
static void grcan_initiate_running_reset(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
unsigned long flags;
netdev_err(dev, "Device seems hanged - reset scheduled\n");
spin_lock_irqsave(&priv->lock, flags);
if (!priv->resetting && !priv->closing) {
priv->resetting = true;
netif_stop_queue(dev);
grcan_clear_bits(&regs->txctrl, GRCAN_TXCTRL_ENABLE);
grcan_clear_bits(&regs->rxctrl, GRCAN_RXCTRL_ENABLE);
grcan_reset_timer(&priv->rr_timer, priv->can.bittiming.bitrate);
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static void grcan_free_dma_buffers(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_dma *dma = &priv->dma;
dma_free_coherent(&dev->dev, dma->base_size, dma->base_buf,
dma->base_handle);
memset(dma, 0, sizeof(*dma));
}
static int grcan_allocate_dma_buffers(struct net_device *dev,
size_t tsize, size_t rsize)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_dma *dma = &priv->dma;
struct grcan_dma_buffer *large = rsize > tsize ? &dma->rx : &dma->tx;
struct grcan_dma_buffer *small = rsize > tsize ? &dma->tx : &dma->rx;
size_t shift;
size_t maxs = max(tsize, rsize);
size_t lsize = ALIGN(maxs, GRCAN_BUFFER_ALIGNMENT);
size_t ssize = min(tsize, rsize);
dma->base_size = lsize + ssize + GRCAN_BUFFER_ALIGNMENT;
dma->base_buf = dma_alloc_coherent(&dev->dev,
dma->base_size,
&dma->base_handle,
GFP_KERNEL);
if (!dma->base_buf)
return -ENOMEM;
dma->tx.size = tsize;
dma->rx.size = rsize;
large->handle = ALIGN(dma->base_handle, GRCAN_BUFFER_ALIGNMENT);
small->handle = large->handle + lsize;
shift = large->handle - dma->base_handle;
large->buf = dma->base_buf + shift;
small->buf = large->buf + lsize;
return 0;
}
static int grcan_start(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
u32 confop, txctrl;
grcan_reset(dev);
grcan_write_reg(&regs->txaddr, priv->dma.tx.handle);
grcan_write_reg(&regs->txsize, priv->dma.tx.size);
grcan_write_reg(&regs->rxaddr, priv->dma.rx.handle);
grcan_write_reg(&regs->rxsize, priv->dma.rx.size);
grcan_read_reg(&regs->pir);
grcan_write_reg(&regs->imr, GRCAN_IRQ_DEFAULT);
confop = GRCAN_CONF_ABORT
| (priv->config.enable0 ? GRCAN_CONF_ENABLE0 : 0)
| (priv->config.enable1 ? GRCAN_CONF_ENABLE1 : 0)
| (priv->config.select ? GRCAN_CONF_SELECT : 0)
| (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY ?
GRCAN_CONF_SILENT : 0)
| (priv->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES ?
GRCAN_CONF_SAM : 0);
grcan_write_bits(&regs->conf, confop, GRCAN_CONF_OPERATION);
txctrl = GRCAN_TXCTRL_ENABLE
| (priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT
? GRCAN_TXCTRL_SINGLE : 0);
grcan_write_reg(&regs->txctrl, txctrl);
grcan_write_reg(&regs->rxctrl, GRCAN_RXCTRL_ENABLE);
grcan_write_reg(&regs->ctrl, GRCAN_CTRL_ENABLE);
priv->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
}
static int grcan_set_mode(struct net_device *dev, enum can_mode mode)
{
struct grcan_priv *priv = netdev_priv(dev);
unsigned long flags;
int err = 0;
if (mode == CAN_MODE_START) {
spin_lock_irqsave(&priv->lock, flags);
if (priv->closing || priv->resetting) {
err = -EBUSY;
} else {
netdev_info(dev, "Restarting device\n");
grcan_start(dev);
if (!(priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY))
netif_wake_queue(dev);
}
spin_unlock_irqrestore(&priv->lock, flags);
return err;
}
return -EOPNOTSUPP;
}
static int grcan_open(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_dma *dma = &priv->dma;
unsigned long flags;
int err;
err = grcan_allocate_dma_buffers(dev, priv->config.txsize,
priv->config.rxsize);
if (err) {
netdev_err(dev, "could not allocate DMA buffers\n");
return err;
}
priv->echo_skb = kzalloc(dma->tx.size * sizeof(*priv->echo_skb),
GFP_KERNEL);
if (!priv->echo_skb) {
err = -ENOMEM;
goto exit_free_dma_buffers;
}
priv->can.echo_skb_max = dma->tx.size;
priv->can.echo_skb = priv->echo_skb;
priv->txdlc = kzalloc(dma->tx.size * sizeof(*priv->txdlc), GFP_KERNEL);
if (!priv->txdlc) {
err = -ENOMEM;
goto exit_free_echo_skb;
}
err = open_candev(dev);
if (err)
goto exit_free_txdlc;
err = request_irq(dev->irq, grcan_interrupt, IRQF_SHARED,
dev->name, dev);
if (err)
goto exit_close_candev;
spin_lock_irqsave(&priv->lock, flags);
napi_enable(&priv->napi);
grcan_start(dev);
if (!(priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY))
netif_start_queue(dev);
priv->resetting = false;
priv->closing = false;
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
exit_close_candev:
close_candev(dev);
exit_free_txdlc:
kfree(priv->txdlc);
exit_free_echo_skb:
kfree(priv->echo_skb);
exit_free_dma_buffers:
grcan_free_dma_buffers(dev);
return err;
}
static int grcan_close(struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
unsigned long flags;
napi_disable(&priv->napi);
spin_lock_irqsave(&priv->lock, flags);
priv->closing = true;
if (priv->need_txbug_workaround) {
del_timer_sync(&priv->hang_timer);
del_timer_sync(&priv->rr_timer);
}
netif_stop_queue(dev);
grcan_stop_hardware(dev);
priv->can.state = CAN_STATE_STOPPED;
spin_unlock_irqrestore(&priv->lock, flags);
free_irq(dev->irq, dev);
close_candev(dev);
grcan_free_dma_buffers(dev);
priv->can.echo_skb_max = 0;
priv->can.echo_skb = NULL;
kfree(priv->echo_skb);
kfree(priv->txdlc);
return 0;
}
static int grcan_transmit_catch_up(struct net_device *dev, int budget)
{
struct grcan_priv *priv = netdev_priv(dev);
unsigned long flags;
int work_done;
spin_lock_irqsave(&priv->lock, flags);
work_done = catch_up_echo_skb(dev, budget, true);
if (work_done) {
if (!priv->resetting && !priv->closing &&
!(priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY))
netif_wake_queue(dev);
if (priv->need_txbug_workaround)
del_timer(&priv->hang_timer);
}
spin_unlock_irqrestore(&priv->lock, flags);
return work_done;
}
static int grcan_receive(struct net_device *dev, int budget)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct grcan_dma *dma = &priv->dma;
struct net_device_stats *stats = &dev->stats;
struct can_frame *cf;
struct sk_buff *skb;
u32 wr, rd, startrd;
u32 *slot;
u32 i, rtr, eff, j, shift;
int work_done = 0;
rd = grcan_read_reg(&regs->rxrd);
startrd = rd;
for (work_done = 0; work_done < budget; work_done++) {
wr = grcan_read_reg(&regs->rxwr);
if (rd == wr)
break;
skb = alloc_can_skb(dev, &cf);
if (skb == NULL) {
netdev_err(dev,
"dropping frame: skb allocation failed\n");
stats->rx_dropped++;
continue;
}
slot = dma->rx.buf + rd;
eff = slot[0] & GRCAN_MSG_IDE;
rtr = slot[0] & GRCAN_MSG_RTR;
if (eff) {
cf->can_id = ((slot[0] & GRCAN_MSG_EID)
>> GRCAN_MSG_EID_BIT);
cf->can_id |= CAN_EFF_FLAG;
} else {
cf->can_id = ((slot[0] & GRCAN_MSG_BID)
>> GRCAN_MSG_BID_BIT);
}
cf->can_dlc = get_can_dlc((slot[1] & GRCAN_MSG_DLC)
>> GRCAN_MSG_DLC_BIT);
if (rtr) {
cf->can_id |= CAN_RTR_FLAG;
} else {
for (i = 0; i < cf->can_dlc; i++) {
j = GRCAN_MSG_DATA_SLOT_INDEX(i);
shift = GRCAN_MSG_DATA_SHIFT(i);
cf->data[i] = (u8)(slot[j] >> shift);
}
}
netif_receive_skb(skb);
stats->rx_packets++;
stats->rx_bytes += cf->can_dlc;
rd = grcan_ring_add(rd, GRCAN_MSG_SIZE, dma->rx.size);
}
mb();
if (likely(rd != startrd))
grcan_write_reg(&regs->rxrd, rd);
return work_done;
}
static int grcan_poll(struct napi_struct *napi, int budget)
{
struct grcan_priv *priv = container_of(napi, struct grcan_priv, napi);
struct net_device *dev = priv->dev;
struct grcan_registers __iomem *regs = priv->regs;
unsigned long flags;
int tx_work_done, rx_work_done;
int rx_budget = budget / 2;
int tx_budget = budget - rx_budget;
rx_work_done = grcan_receive(dev, rx_budget);
tx_work_done = grcan_transmit_catch_up(dev, tx_budget);
if (rx_work_done < rx_budget && tx_work_done < tx_budget) {
napi_complete(napi);
spin_lock_irqsave(&priv->lock, flags);
grcan_set_bits(&regs->imr, GRCAN_IRQ_TX | GRCAN_IRQ_RX);
spin_unlock_irqrestore(&priv->lock, flags);
}
return rx_work_done + tx_work_done;
}
static int grcan_txbug_workaround(struct net_device *dev, struct sk_buff *skb,
u32 txwr, u32 oneshotmode,
netdev_tx_t *netdev_tx_status)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct grcan_dma *dma = &priv->dma;
int i;
unsigned long flags;
for (i = 0; i < GRCAN_SHORTWAIT_USECS; i++) {
udelay(1);
if (!grcan_read_bits(&regs->txctrl, GRCAN_TXCTRL_ONGOING) ||
grcan_read_reg(&regs->txrd) == txwr) {
return 0;
}
}
spin_lock_irqsave(&priv->lock, flags);
if (!priv->resetting && !priv->closing) {
if (grcan_txspace(dma->tx.size, txwr, priv->eskbp))
netif_wake_queue(dev);
if (!timer_pending(&priv->hang_timer))
grcan_reset_timer(&priv->hang_timer,
priv->can.bittiming.bitrate);
}
spin_unlock_irqrestore(&priv->lock, flags);
if (oneshotmode) {
kfree_skb(skb);
*netdev_tx_status = NETDEV_TX_OK;
} else {
*netdev_tx_status = NETDEV_TX_BUSY;
}
return -EBUSY;
}
static netdev_tx_t grcan_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct grcan_priv *priv = netdev_priv(dev);
struct grcan_registers __iomem *regs = priv->regs;
struct grcan_dma *dma = &priv->dma;
struct can_frame *cf = (struct can_frame *)skb->data;
u32 id, txwr, txrd, space, txctrl;
int slotindex;
u32 *slot;
u32 i, rtr, eff, dlc, tmp, err;
int j, shift;
unsigned long flags;
u32 oneshotmode = priv->can.ctrlmode & CAN_CTRLMODE_ONE_SHOT;
if (can_dropped_invalid_skb(dev, skb))
return NETDEV_TX_OK;
if (priv->can.ctrlmode & CAN_CTRLMODE_LISTENONLY)
return NETDEV_TX_BUSY;
spin_lock_irqsave(&priv->lock, flags);
txwr = grcan_read_reg(&regs->txwr);
space = grcan_txspace(dma->tx.size, txwr, priv->eskbp);
slotindex = txwr / GRCAN_MSG_SIZE;
slot = dma->tx.buf + txwr;
if (unlikely(space == 1))
netif_stop_queue(dev);
spin_unlock_irqrestore(&priv->lock, flags);
if (unlikely(!space)) {
netdev_err(dev, "No buffer space, but queue is non-stopped.\n");
return NETDEV_TX_BUSY;
}
eff = cf->can_id & CAN_EFF_FLAG;
rtr = cf->can_id & CAN_RTR_FLAG;
id = cf->can_id & (eff ? CAN_EFF_MASK : CAN_SFF_MASK);
dlc = cf->can_dlc;
if (eff)
tmp = (id << GRCAN_MSG_EID_BIT) & GRCAN_MSG_EID;
else
tmp = (id << GRCAN_MSG_BID_BIT) & GRCAN_MSG_BID;
slot[0] = (eff ? GRCAN_MSG_IDE : 0) | (rtr ? GRCAN_MSG_RTR : 0) | tmp;
slot[1] = ((dlc << GRCAN_MSG_DLC_BIT) & GRCAN_MSG_DLC);
slot[2] = 0;
slot[3] = 0;
for (i = 0; i < dlc; i++) {
j = GRCAN_MSG_DATA_SLOT_INDEX(i);
shift = GRCAN_MSG_DATA_SHIFT(i);
slot[j] |= cf->data[i] << shift;
}
txctrl = grcan_read_reg(&regs->txctrl);
if (!(txctrl & GRCAN_TXCTRL_ENABLE))
netdev_err(dev, "tx channel spuriously disabled\n");
if (oneshotmode && !(txctrl & GRCAN_TXCTRL_SINGLE))
netdev_err(dev, "one-shot mode spuriously disabled\n");
if (priv->need_txbug_workaround) {
txrd = grcan_read_reg(&regs->txrd);
if (unlikely(grcan_ring_sub(txwr, txrd, dma->tx.size) == 1)) {
netdev_tx_t txstatus;
err = grcan_txbug_workaround(dev, skb, txwr,
oneshotmode, &txstatus);
if (err)
return txstatus;
}
}
priv->txdlc[slotindex] = cf->can_dlc;
can_put_echo_skb(skb, dev, slotindex);
wmb();
grcan_write_reg(&regs->txwr,
grcan_ring_add(txwr, GRCAN_MSG_SIZE, dma->tx.size));
return NETDEV_TX_OK;
}
static void grcan_sanitize_module_config(struct platform_device *ofdev)
{
grcan_sanitize_enable0(ofdev);
grcan_sanitize_enable1(ofdev);
grcan_sanitize_select(ofdev);
grcan_sanitize_txsize(ofdev);
grcan_sanitize_rxsize(ofdev);
}
static int grcan_setup_netdev(struct platform_device *ofdev,
void __iomem *base,
int irq, u32 ambafreq, bool txbug)
{
struct net_device *dev;
struct grcan_priv *priv;
struct grcan_registers __iomem *regs;
int err;
dev = alloc_candev(sizeof(struct grcan_priv), 0);
if (!dev)
return -ENOMEM;
dev->irq = irq;
dev->flags |= IFF_ECHO;
dev->netdev_ops = &grcan_netdev_ops;
dev->sysfs_groups[0] = &sysfs_grcan_group;
priv = netdev_priv(dev);
memcpy(&priv->config, &grcan_module_config,
sizeof(struct grcan_device_config));
priv->dev = dev;
priv->regs = base;
priv->can.bittiming_const = &grcan_bittiming_const;
priv->can.do_set_bittiming = grcan_set_bittiming;
priv->can.do_set_mode = grcan_set_mode;
priv->can.do_get_berr_counter = grcan_get_berr_counter;
priv->can.clock.freq = ambafreq;
priv->can.ctrlmode_supported =
CAN_CTRLMODE_LISTENONLY | CAN_CTRLMODE_ONE_SHOT;
priv->need_txbug_workaround = txbug;
regs = priv->regs;
grcan_set_bits(&regs->ctrl, GRCAN_CTRL_RESET);
grcan_set_bits(&regs->conf, GRCAN_CONF_SAM);
if (grcan_read_bits(&regs->conf, GRCAN_CONF_SAM)) {
priv->can.ctrlmode_supported |= CAN_CTRLMODE_3_SAMPLES;
dev_dbg(&ofdev->dev, "Hardware supports triple-sampling\n");
}
spin_lock_init(&priv->lock);
if (priv->need_txbug_workaround) {
init_timer(&priv->rr_timer);
priv->rr_timer.function = grcan_running_reset;
priv->rr_timer.data = (unsigned long)dev;
init_timer(&priv->hang_timer);
priv->hang_timer.function = grcan_initiate_running_reset;
priv->hang_timer.data = (unsigned long)dev;
}
netif_napi_add(dev, &priv->napi, grcan_poll, GRCAN_NAPI_WEIGHT);
SET_NETDEV_DEV(dev, &ofdev->dev);
dev_info(&ofdev->dev, "regs=0x%p, irq=%d, clock=%d\n",
priv->regs, dev->irq, priv->can.clock.freq);
err = register_candev(dev);
if (err)
goto exit_free_candev;
platform_set_drvdata(ofdev, dev);
grcan_write_reg(&regs->ctrl, GRCAN_CTRL_RESET);
return 0;
exit_free_candev:
free_candev(dev);
return err;
}
static int grcan_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct resource *res;
u32 sysid, ambafreq;
int irq, err;
void __iomem *base;
bool txbug = true;
err = of_property_read_u32(np, "systemid", &sysid);
if (!err && ((sysid & GRLIB_VERSION_MASK)
>= GRCAN_TXBUG_SAFE_GRLIB_VERSION))
txbug = false;
err = of_property_read_u32(np, "freq", &ambafreq);
if (err) {
dev_err(&ofdev->dev, "unable to fetch \"freq\" property\n");
goto exit_error;
}
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(base)) {
err = PTR_ERR(base);
goto exit_error;
}
irq = irq_of_parse_and_map(np, GRCAN_IRQIX_IRQ);
if (!irq) {
dev_err(&ofdev->dev, "no irq found\n");
err = -ENODEV;
goto exit_error;
}
grcan_sanitize_module_config(ofdev);
err = grcan_setup_netdev(ofdev, base, irq, ambafreq, txbug);
if (err)
goto exit_dispose_irq;
return 0;
exit_dispose_irq:
irq_dispose_mapping(irq);
exit_error:
dev_err(&ofdev->dev,
"%s socket CAN driver initialization failed with error %d\n",
DRV_NAME, err);
return err;
}
static int grcan_remove(struct platform_device *ofdev)
{
struct net_device *dev = platform_get_drvdata(ofdev);
struct grcan_priv *priv = netdev_priv(dev);
unregister_candev(dev);
irq_dispose_mapping(dev->irq);
netif_napi_del(&priv->napi);
free_candev(dev);
return 0;
}
