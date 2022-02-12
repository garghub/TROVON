static inline void
at86rf230_sleep(struct at86rf230_local *lp)
{
if (gpio_is_valid(lp->slp_tr)) {
gpio_set_value(lp->slp_tr, 1);
usleep_range(lp->data->t_off_to_sleep,
lp->data->t_off_to_sleep + 10);
lp->sleep = true;
}
}
static inline void
at86rf230_awake(struct at86rf230_local *lp)
{
if (gpio_is_valid(lp->slp_tr)) {
gpio_set_value(lp->slp_tr, 0);
usleep_range(lp->data->t_sleep_to_off,
lp->data->t_sleep_to_off + 100);
lp->sleep = false;
}
}
static inline int
__at86rf230_write(struct at86rf230_local *lp,
unsigned int addr, unsigned int data)
{
bool sleep = lp->sleep;
int ret;
if (sleep)
at86rf230_awake(lp);
ret = regmap_write(lp->regmap, addr, data);
if (sleep)
at86rf230_sleep(lp);
return ret;
}
static inline int
__at86rf230_read(struct at86rf230_local *lp,
unsigned int addr, unsigned int *data)
{
bool sleep = lp->sleep;
int ret;
if (sleep)
at86rf230_awake(lp);
ret = regmap_read(lp->regmap, addr, data);
if (sleep)
at86rf230_sleep(lp);
return ret;
}
static inline int
at86rf230_read_subreg(struct at86rf230_local *lp,
unsigned int addr, unsigned int mask,
unsigned int shift, unsigned int *data)
{
int rc;
rc = __at86rf230_read(lp, addr, data);
if (!rc)
*data = (*data & mask) >> shift;
return rc;
}
static inline int
at86rf230_write_subreg(struct at86rf230_local *lp,
unsigned int addr, unsigned int mask,
unsigned int shift, unsigned int data)
{
bool sleep = lp->sleep;
int ret;
if (sleep)
at86rf230_awake(lp);
ret = regmap_update_bits(lp->regmap, addr, mask, data << shift);
if (sleep)
at86rf230_sleep(lp);
return ret;
}
static inline void
at86rf230_slp_tr_rising_edge(struct at86rf230_local *lp)
{
gpio_set_value(lp->slp_tr, 1);
udelay(1);
gpio_set_value(lp->slp_tr, 0);
}
static bool
at86rf230_reg_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case RG_TRX_STATE:
case RG_TRX_CTRL_0:
case RG_TRX_CTRL_1:
case RG_PHY_TX_PWR:
case RG_PHY_ED_LEVEL:
case RG_PHY_CC_CCA:
case RG_CCA_THRES:
case RG_RX_CTRL:
case RG_SFD_VALUE:
case RG_TRX_CTRL_2:
case RG_ANT_DIV:
case RG_IRQ_MASK:
case RG_VREG_CTRL:
case RG_BATMON:
case RG_XOSC_CTRL:
case RG_RX_SYN:
case RG_XAH_CTRL_1:
case RG_FTN_CTRL:
case RG_PLL_CF:
case RG_PLL_DCU:
case RG_SHORT_ADDR_0:
case RG_SHORT_ADDR_1:
case RG_PAN_ID_0:
case RG_PAN_ID_1:
case RG_IEEE_ADDR_0:
case RG_IEEE_ADDR_1:
case RG_IEEE_ADDR_2:
case RG_IEEE_ADDR_3:
case RG_IEEE_ADDR_4:
case RG_IEEE_ADDR_5:
case RG_IEEE_ADDR_6:
case RG_IEEE_ADDR_7:
case RG_XAH_CTRL_0:
case RG_CSMA_SEED_0:
case RG_CSMA_SEED_1:
case RG_CSMA_BE:
return true;
default:
return false;
}
}
static bool
at86rf230_reg_readable(struct device *dev, unsigned int reg)
{
bool rc;
rc = at86rf230_reg_writeable(dev, reg);
if (rc)
return rc;
switch (reg) {
case RG_TRX_STATUS:
case RG_PHY_RSSI:
case RG_IRQ_STATUS:
case RG_PART_NUM:
case RG_VERSION_NUM:
case RG_MAN_ID_1:
case RG_MAN_ID_0:
return true;
default:
return false;
}
}
static bool
at86rf230_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case RG_TRX_STATUS:
case RG_TRX_STATE:
case RG_PHY_RSSI:
case RG_PHY_ED_LEVEL:
case RG_IRQ_STATUS:
case RG_VREG_CTRL:
case RG_PLL_CF:
case RG_PLL_DCU:
return true;
default:
return false;
}
}
static bool
at86rf230_reg_precious(struct device *dev, unsigned int reg)
{
switch (reg) {
case RG_IRQ_STATUS:
return true;
default:
return false;
}
}
static void
at86rf230_async_error_recover(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
lp->is_tx = 0;
at86rf230_async_state_change(lp, ctx, STATE_RX_AACK_ON, NULL, false);
ieee802154_wake_queue(lp->hw);
}
static inline void
at86rf230_async_error(struct at86rf230_local *lp,
struct at86rf230_state_change *ctx, int rc)
{
dev_err(&lp->spi->dev, "spi_async error %d\n", rc);
at86rf230_async_state_change(lp, ctx, STATE_FORCE_TRX_OFF,
at86rf230_async_error_recover, false);
}
static void
at86rf230_async_read_reg(struct at86rf230_local *lp, const u8 reg,
struct at86rf230_state_change *ctx,
void (*complete)(void *context),
const bool irq_enable)
{
int rc;
u8 *tx_buf = ctx->buf;
tx_buf[0] = (reg & CMD_REG_MASK) | CMD_REG;
ctx->msg.complete = complete;
ctx->irq_enable = irq_enable;
rc = spi_async(lp->spi, &ctx->msg);
if (rc) {
if (irq_enable)
enable_irq(ctx->irq);
at86rf230_async_error(lp, ctx, rc);
}
}
static inline u8 at86rf230_state_to_force(u8 state)
{
if (state == STATE_TX_ON)
return STATE_FORCE_TX_ON;
else
return STATE_FORCE_TRX_OFF;
}
static void
at86rf230_async_state_assert(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
const u8 *buf = ctx->buf;
const u8 trx_state = buf[1] & TRX_STATE_MASK;
if (trx_state != ctx->to_state) {
if (trx_state == STATE_BUSY_RX_AACK) {
if (ctx->to_state == STATE_RX_AACK_ON)
goto done;
if (ctx->to_state == STATE_TX_ON ||
ctx->to_state == STATE_TRX_OFF) {
u8 state = ctx->to_state;
if (lp->tx_retry >= AT86RF2XX_MAX_TX_RETRIES)
state = at86rf230_state_to_force(state);
lp->tx_retry++;
at86rf230_async_state_change(lp, ctx, state,
ctx->complete,
ctx->irq_enable);
return;
}
}
dev_warn(&lp->spi->dev, "unexcept state change from 0x%02x to 0x%02x. Actual state: 0x%02x\n",
ctx->from_state, ctx->to_state, trx_state);
}
done:
if (ctx->complete)
ctx->complete(context);
}
static enum hrtimer_restart at86rf230_async_state_timer(struct hrtimer *timer)
{
struct at86rf230_state_change *ctx =
container_of(timer, struct at86rf230_state_change, timer);
struct at86rf230_local *lp = ctx->lp;
at86rf230_async_read_reg(lp, RG_TRX_STATUS, ctx,
at86rf230_async_state_assert,
ctx->irq_enable);
return HRTIMER_NORESTART;
}
static void
at86rf230_async_state_delay(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
struct at86rf2xx_chip_data *c = lp->data;
bool force = false;
ktime_t tim;
switch (ctx->to_state) {
case STATE_FORCE_TX_ON:
ctx->to_state = STATE_TX_ON;
force = true;
break;
case STATE_FORCE_TRX_OFF:
ctx->to_state = STATE_TRX_OFF;
force = true;
break;
default:
break;
}
switch (ctx->from_state) {
case STATE_TRX_OFF:
switch (ctx->to_state) {
case STATE_RX_AACK_ON:
tim = ktime_set(0, c->t_off_to_aack * NSEC_PER_USEC);
lp->cal_timeout = jiffies + AT86RF2XX_CAL_LOOP_TIMEOUT;
goto change;
case STATE_TX_ARET_ON:
case STATE_TX_ON:
tim = ktime_set(0, c->t_off_to_tx_on * NSEC_PER_USEC);
lp->cal_timeout = jiffies + AT86RF2XX_CAL_LOOP_TIMEOUT;
goto change;
default:
break;
}
break;
case STATE_BUSY_RX_AACK:
switch (ctx->to_state) {
case STATE_TRX_OFF:
case STATE_TX_ON:
if (!force) {
tim = ktime_set(0, (c->t_frame + c->t_p_ack) *
NSEC_PER_USEC);
goto change;
}
break;
default:
break;
}
break;
case STATE_P_ON:
switch (ctx->to_state) {
case STATE_TRX_OFF:
tim = ktime_set(0, c->t_reset_to_off * NSEC_PER_USEC);
goto change;
default:
break;
}
break;
default:
break;
}
tim = ktime_set(0, NSEC_PER_USEC);
change:
hrtimer_start(&ctx->timer, tim, HRTIMER_MODE_REL);
}
static void
at86rf230_async_state_change_start(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
u8 *buf = ctx->buf;
const u8 trx_state = buf[1] & TRX_STATE_MASK;
int rc;
if (trx_state == STATE_TRANSITION_IN_PROGRESS) {
udelay(1);
at86rf230_async_read_reg(lp, RG_TRX_STATUS, ctx,
at86rf230_async_state_change_start,
ctx->irq_enable);
return;
}
if (trx_state == ctx->to_state) {
if (ctx->complete)
ctx->complete(context);
return;
}
ctx->from_state = trx_state;
buf[0] = (RG_TRX_STATE & CMD_REG_MASK) | CMD_REG | CMD_WRITE;
buf[1] = ctx->to_state;
ctx->msg.complete = at86rf230_async_state_delay;
rc = spi_async(lp->spi, &ctx->msg);
if (rc) {
if (ctx->irq_enable)
enable_irq(ctx->irq);
at86rf230_async_error(lp, ctx, rc);
}
}
static void
at86rf230_async_state_change(struct at86rf230_local *lp,
struct at86rf230_state_change *ctx,
const u8 state, void (*complete)(void *context),
const bool irq_enable)
{
ctx->to_state = state;
ctx->complete = complete;
ctx->irq_enable = irq_enable;
at86rf230_async_read_reg(lp, RG_TRX_STATUS, ctx,
at86rf230_async_state_change_start,
irq_enable);
}
static void
at86rf230_sync_state_change_complete(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
complete(&lp->state_complete);
}
static int
at86rf230_sync_state_change(struct at86rf230_local *lp, unsigned int state)
{
unsigned long rc;
at86rf230_async_state_change(lp, &lp->state, state,
at86rf230_sync_state_change_complete,
false);
rc = wait_for_completion_timeout(&lp->state_complete,
msecs_to_jiffies(100));
if (!rc) {
at86rf230_async_error(lp, &lp->state, -ETIMEDOUT);
return -ETIMEDOUT;
}
return 0;
}
static void
at86rf230_tx_complete(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
enable_irq(ctx->irq);
ieee802154_xmit_complete(lp->hw, lp->tx_skb, !lp->tx_aret);
}
static void
at86rf230_tx_on(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
at86rf230_async_state_change(lp, ctx, STATE_RX_AACK_ON,
at86rf230_tx_complete, true);
}
static void
at86rf230_tx_trac_check(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
const u8 *buf = ctx->buf;
const u8 trac = (buf[1] & 0xe0) >> 5;
if (trac)
at86rf230_async_state_change(lp, ctx, STATE_FORCE_TRX_OFF,
at86rf230_tx_on, true);
else
at86rf230_tx_on(context);
}
static void
at86rf230_tx_trac_status(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
at86rf230_async_read_reg(lp, RG_TRX_STATE, ctx,
at86rf230_tx_trac_check, true);
}
static void
at86rf230_rx_read_frame_complete(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
u8 rx_local_buf[AT86RF2XX_MAX_BUF];
const u8 *buf = ctx->buf;
struct sk_buff *skb;
u8 len, lqi;
len = buf[1];
if (!ieee802154_is_valid_psdu_len(len)) {
dev_vdbg(&lp->spi->dev, "corrupted frame received\n");
len = IEEE802154_MTU;
}
lqi = buf[2 + len];
memcpy(rx_local_buf, buf + 2, len);
ctx->trx.len = 2;
enable_irq(ctx->irq);
skb = dev_alloc_skb(IEEE802154_MTU);
if (!skb) {
dev_vdbg(&lp->spi->dev, "failed to allocate sk_buff\n");
return;
}
memcpy(skb_put(skb, len), rx_local_buf, len);
ieee802154_rx_irqsafe(lp->hw, skb, lqi);
}
static void
at86rf230_rx_read_frame(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
u8 *buf = ctx->buf;
int rc;
buf[0] = CMD_FB;
ctx->trx.len = AT86RF2XX_MAX_BUF;
ctx->msg.complete = at86rf230_rx_read_frame_complete;
rc = spi_async(lp->spi, &ctx->msg);
if (rc) {
ctx->trx.len = 2;
enable_irq(ctx->irq);
at86rf230_async_error(lp, ctx, rc);
}
}
static void
at86rf230_rx_trac_check(void *context)
{
at86rf230_rx_read_frame(context);
}
static void
at86rf230_irq_trx_end(struct at86rf230_local *lp)
{
if (lp->is_tx) {
lp->is_tx = 0;
if (lp->tx_aret)
at86rf230_async_state_change(lp, &lp->irq,
STATE_FORCE_TX_ON,
at86rf230_tx_trac_status,
true);
else
at86rf230_async_state_change(lp, &lp->irq,
STATE_RX_AACK_ON,
at86rf230_tx_complete,
true);
} else {
at86rf230_async_read_reg(lp, RG_TRX_STATE, &lp->irq,
at86rf230_rx_trac_check, true);
}
}
static void
at86rf230_irq_status(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
const u8 *buf = ctx->buf;
const u8 irq = buf[1];
if (irq & IRQ_TRX_END) {
at86rf230_irq_trx_end(lp);
} else {
enable_irq(ctx->irq);
dev_err(&lp->spi->dev, "not supported irq %02x received\n",
irq);
}
}
static irqreturn_t at86rf230_isr(int irq, void *data)
{
struct at86rf230_local *lp = data;
struct at86rf230_state_change *ctx = &lp->irq;
u8 *buf = ctx->buf;
int rc;
disable_irq_nosync(irq);
buf[0] = (RG_IRQ_STATUS & CMD_REG_MASK) | CMD_REG;
ctx->msg.complete = at86rf230_irq_status;
rc = spi_async(lp->spi, &ctx->msg);
if (rc) {
enable_irq(irq);
at86rf230_async_error(lp, ctx, rc);
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static void
at86rf230_write_frame_complete(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
u8 *buf = ctx->buf;
int rc;
ctx->trx.len = 2;
if (gpio_is_valid(lp->slp_tr)) {
at86rf230_slp_tr_rising_edge(lp);
} else {
buf[0] = (RG_TRX_STATE & CMD_REG_MASK) | CMD_REG | CMD_WRITE;
buf[1] = STATE_BUSY_TX;
ctx->msg.complete = NULL;
rc = spi_async(lp->spi, &ctx->msg);
if (rc)
at86rf230_async_error(lp, ctx, rc);
}
}
static void
at86rf230_write_frame(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
struct sk_buff *skb = lp->tx_skb;
u8 *buf = ctx->buf;
int rc;
lp->is_tx = 1;
buf[0] = CMD_FB | CMD_WRITE;
buf[1] = skb->len + 2;
memcpy(buf + 2, skb->data, skb->len);
ctx->trx.len = skb->len + 2;
ctx->msg.complete = at86rf230_write_frame_complete;
rc = spi_async(lp->spi, &ctx->msg);
if (rc) {
ctx->trx.len = 2;
at86rf230_async_error(lp, ctx, rc);
}
}
static void
at86rf230_xmit_tx_on(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
at86rf230_async_state_change(lp, ctx, STATE_TX_ARET_ON,
at86rf230_write_frame, false);
}
static void
at86rf230_xmit_start(void *context)
{
struct at86rf230_state_change *ctx = context;
struct at86rf230_local *lp = ctx->lp;
if (lp->tx_aret) {
if (lp->is_tx_from_off) {
lp->is_tx_from_off = false;
at86rf230_async_state_change(lp, ctx, STATE_TX_ARET_ON,
at86rf230_write_frame,
false);
} else {
at86rf230_async_state_change(lp, ctx, STATE_TX_ON,
at86rf230_xmit_tx_on,
false);
}
} else {
at86rf230_async_state_change(lp, ctx, STATE_TX_ON,
at86rf230_write_frame, false);
}
}
static int
at86rf230_xmit(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct at86rf230_local *lp = hw->priv;
struct at86rf230_state_change *ctx = &lp->tx;
lp->tx_skb = skb;
lp->tx_retry = 0;
if (time_is_before_jiffies(lp->cal_timeout)) {
lp->is_tx_from_off = true;
at86rf230_async_state_change(lp, ctx, STATE_TRX_OFF,
at86rf230_xmit_start, false);
} else {
at86rf230_xmit_start(ctx);
}
return 0;
}
static int
at86rf230_ed(struct ieee802154_hw *hw, u8 *level)
{
BUG_ON(!level);
*level = 0xbe;
return 0;
}
static int
at86rf230_start(struct ieee802154_hw *hw)
{
struct at86rf230_local *lp = hw->priv;
at86rf230_awake(lp);
enable_irq(lp->spi->irq);
return at86rf230_sync_state_change(lp, STATE_RX_AACK_ON);
}
static void
at86rf230_stop(struct ieee802154_hw *hw)
{
struct at86rf230_local *lp = hw->priv;
u8 csma_seed[2];
at86rf230_sync_state_change(lp, STATE_FORCE_TRX_OFF);
disable_irq(lp->spi->irq);
get_random_bytes(csma_seed, ARRAY_SIZE(csma_seed));
at86rf230_write_subreg(lp, SR_CSMA_SEED_0, csma_seed[0]);
at86rf230_write_subreg(lp, SR_CSMA_SEED_1, csma_seed[1]);
at86rf230_sleep(lp);
}
static int
at86rf23x_set_channel(struct at86rf230_local *lp, u8 page, u8 channel)
{
return at86rf230_write_subreg(lp, SR_CHANNEL, channel);
}
static inline int
at86rf212_update_cca_ed_level(struct at86rf230_local *lp, int rssi_base_val)
{
unsigned int cca_ed_thres;
int rc;
rc = at86rf230_read_subreg(lp, SR_CCA_ED_THRES, &cca_ed_thres);
if (rc < 0)
return rc;
switch (rssi_base_val) {
case -98:
lp->hw->phy->supported.cca_ed_levels = at86rf212_ed_levels_98;
lp->hw->phy->supported.cca_ed_levels_size = ARRAY_SIZE(at86rf212_ed_levels_98);
lp->hw->phy->cca_ed_level = at86rf212_ed_levels_98[cca_ed_thres];
break;
case -100:
lp->hw->phy->supported.cca_ed_levels = at86rf212_ed_levels_100;
lp->hw->phy->supported.cca_ed_levels_size = ARRAY_SIZE(at86rf212_ed_levels_100);
lp->hw->phy->cca_ed_level = at86rf212_ed_levels_100[cca_ed_thres];
break;
default:
WARN_ON(1);
}
return 0;
}
static int
at86rf212_set_channel(struct at86rf230_local *lp, u8 page, u8 channel)
{
int rc;
if (channel == 0)
rc = at86rf230_write_subreg(lp, SR_SUB_MODE, 0);
else
rc = at86rf230_write_subreg(lp, SR_SUB_MODE, 1);
if (rc < 0)
return rc;
if (page == 0) {
rc = at86rf230_write_subreg(lp, SR_BPSK_QPSK, 0);
lp->data->rssi_base_val = -100;
} else {
rc = at86rf230_write_subreg(lp, SR_BPSK_QPSK, 1);
lp->data->rssi_base_val = -98;
}
if (rc < 0)
return rc;
rc = at86rf212_update_cca_ed_level(lp, lp->data->rssi_base_val);
if (rc < 0)
return rc;
if (channel == 0) {
if (page == 0) {
lp->hw->phy->symbol_duration = 50;
} else {
lp->hw->phy->symbol_duration = 25;
}
} else {
if (page == 0)
lp->hw->phy->symbol_duration = 40;
else
lp->hw->phy->symbol_duration = 16;
}
lp->hw->phy->lifs_period = IEEE802154_LIFS_PERIOD *
lp->hw->phy->symbol_duration;
lp->hw->phy->sifs_period = IEEE802154_SIFS_PERIOD *
lp->hw->phy->symbol_duration;
return at86rf230_write_subreg(lp, SR_CHANNEL, channel);
}
static int
at86rf230_channel(struct ieee802154_hw *hw, u8 page, u8 channel)
{
struct at86rf230_local *lp = hw->priv;
int rc;
rc = lp->data->set_channel(lp, page, channel);
usleep_range(lp->data->t_channel_switch,
lp->data->t_channel_switch + 10);
lp->cal_timeout = jiffies + AT86RF2XX_CAL_LOOP_TIMEOUT;
return rc;
}
static int
at86rf230_set_hw_addr_filt(struct ieee802154_hw *hw,
struct ieee802154_hw_addr_filt *filt,
unsigned long changed)
{
struct at86rf230_local *lp = hw->priv;
if (changed & IEEE802154_AFILT_SADDR_CHANGED) {
u16 addr = le16_to_cpu(filt->short_addr);
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for saddr\n");
__at86rf230_write(lp, RG_SHORT_ADDR_0, addr);
__at86rf230_write(lp, RG_SHORT_ADDR_1, addr >> 8);
}
if (changed & IEEE802154_AFILT_PANID_CHANGED) {
u16 pan = le16_to_cpu(filt->pan_id);
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for pan id\n");
__at86rf230_write(lp, RG_PAN_ID_0, pan);
__at86rf230_write(lp, RG_PAN_ID_1, pan >> 8);
}
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
u8 i, addr[8];
memcpy(addr, &filt->ieee_addr, 8);
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for IEEE addr\n");
for (i = 0; i < 8; i++)
__at86rf230_write(lp, RG_IEEE_ADDR_0 + i, addr[i]);
}
if (changed & IEEE802154_AFILT_PANC_CHANGED) {
dev_vdbg(&lp->spi->dev,
"at86rf230_set_hw_addr_filt called for panc change\n");
if (filt->pan_coord)
at86rf230_write_subreg(lp, SR_AACK_I_AM_COORD, 1);
else
at86rf230_write_subreg(lp, SR_AACK_I_AM_COORD, 0);
}
return 0;
}
static int
at86rf23x_set_txpower(struct at86rf230_local *lp, s32 mbm)
{
u32 i;
for (i = 0; i < lp->hw->phy->supported.tx_powers_size; i++) {
if (lp->hw->phy->supported.tx_powers[i] == mbm)
return at86rf230_write_subreg(lp, SR_TX_PWR_23X, i);
}
return -EINVAL;
}
static int
at86rf212_set_txpower(struct at86rf230_local *lp, s32 mbm)
{
u32 i;
for (i = 0; i < lp->hw->phy->supported.tx_powers_size; i++) {
if (lp->hw->phy->supported.tx_powers[i] == mbm)
return at86rf230_write_subreg(lp, SR_TX_PWR_212, i);
}
return -EINVAL;
}
static int
at86rf230_set_txpower(struct ieee802154_hw *hw, s32 mbm)
{
struct at86rf230_local *lp = hw->priv;
return lp->data->set_txpower(lp, mbm);
}
static int
at86rf230_set_lbt(struct ieee802154_hw *hw, bool on)
{
struct at86rf230_local *lp = hw->priv;
return at86rf230_write_subreg(lp, SR_CSMA_LBT_MODE, on);
}
static int
at86rf230_set_cca_mode(struct ieee802154_hw *hw,
const struct wpan_phy_cca *cca)
{
struct at86rf230_local *lp = hw->priv;
u8 val;
switch (cca->mode) {
case NL802154_CCA_ENERGY:
val = 1;
break;
case NL802154_CCA_CARRIER:
val = 2;
break;
case NL802154_CCA_ENERGY_CARRIER:
switch (cca->opt) {
case NL802154_CCA_OPT_ENERGY_CARRIER_AND:
val = 3;
break;
case NL802154_CCA_OPT_ENERGY_CARRIER_OR:
val = 0;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return at86rf230_write_subreg(lp, SR_CCA_MODE, val);
}
static int
at86rf230_set_cca_ed_level(struct ieee802154_hw *hw, s32 mbm)
{
struct at86rf230_local *lp = hw->priv;
u32 i;
for (i = 0; i < hw->phy->supported.cca_ed_levels_size; i++) {
if (hw->phy->supported.cca_ed_levels[i] == mbm)
return at86rf230_write_subreg(lp, SR_CCA_ED_THRES, i);
}
return -EINVAL;
}
static int
at86rf230_set_csma_params(struct ieee802154_hw *hw, u8 min_be, u8 max_be,
u8 retries)
{
struct at86rf230_local *lp = hw->priv;
int rc;
rc = at86rf230_write_subreg(lp, SR_MIN_BE, min_be);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_MAX_BE, max_be);
if (rc)
return rc;
return at86rf230_write_subreg(lp, SR_MAX_CSMA_RETRIES, retries);
}
static int
at86rf230_set_frame_retries(struct ieee802154_hw *hw, s8 retries)
{
struct at86rf230_local *lp = hw->priv;
int rc = 0;
lp->tx_aret = retries >= 0;
lp->max_frame_retries = retries;
if (retries >= 0)
rc = at86rf230_write_subreg(lp, SR_MAX_FRAME_RETRIES, retries);
return rc;
}
static int
at86rf230_set_promiscuous_mode(struct ieee802154_hw *hw, const bool on)
{
struct at86rf230_local *lp = hw->priv;
int rc;
if (on) {
rc = at86rf230_write_subreg(lp, SR_AACK_DIS_ACK, 1);
if (rc < 0)
return rc;
rc = at86rf230_write_subreg(lp, SR_AACK_PROM_MODE, 1);
if (rc < 0)
return rc;
} else {
rc = at86rf230_write_subreg(lp, SR_AACK_PROM_MODE, 0);
if (rc < 0)
return rc;
rc = at86rf230_write_subreg(lp, SR_AACK_DIS_ACK, 0);
if (rc < 0)
return rc;
}
return 0;
}
static int at86rf230_hw_init(struct at86rf230_local *lp, u8 xtal_trim)
{
int rc, irq_type, irq_pol = IRQ_ACTIVE_HIGH;
unsigned int dvdd;
u8 csma_seed[2];
rc = at86rf230_sync_state_change(lp, STATE_FORCE_TRX_OFF);
if (rc)
return rc;
irq_type = irq_get_trigger_type(lp->spi->irq);
if (irq_type == IRQ_TYPE_EDGE_RISING ||
irq_type == IRQ_TYPE_EDGE_FALLING)
dev_warn(&lp->spi->dev,
"Using edge triggered irq's are not recommended!\n");
if (irq_type == IRQ_TYPE_EDGE_FALLING ||
irq_type == IRQ_TYPE_LEVEL_LOW)
irq_pol = IRQ_ACTIVE_LOW;
rc = at86rf230_write_subreg(lp, SR_IRQ_POLARITY, irq_pol);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_RX_SAFE_MODE, 1);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_IRQ_MASK, IRQ_TRX_END);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_IRQ_MASK_MODE, 0);
if (rc)
return rc;
get_random_bytes(csma_seed, ARRAY_SIZE(csma_seed));
rc = at86rf230_write_subreg(lp, SR_CSMA_SEED_0, csma_seed[0]);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CSMA_SEED_1, csma_seed[1]);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CLKM_SHA_SEL, 0x00);
if (rc)
return rc;
rc = at86rf230_write_subreg(lp, SR_CLKM_CTRL, 0x00);
if (rc)
return rc;
usleep_range(lp->data->t_sleep_cycle,
lp->data->t_sleep_cycle + 100);
rc = at86rf230_write_subreg(lp, SR_XTAL_TRIM, xtal_trim);
if (rc)
return rc;
rc = at86rf230_read_subreg(lp, SR_DVDD_OK, &dvdd);
if (rc)
return rc;
if (!dvdd) {
dev_err(&lp->spi->dev, "DVDD error\n");
return -EINVAL;
}
return at86rf230_write_subreg(lp, SR_SLOTTED_OPERATION, 0);
}
static int
at86rf230_get_pdata(struct spi_device *spi, int *rstn, int *slp_tr,
u8 *xtal_trim)
{
struct at86rf230_platform_data *pdata = spi->dev.platform_data;
int ret;
if (!IS_ENABLED(CONFIG_OF) || !spi->dev.of_node) {
if (!pdata)
return -ENOENT;
*rstn = pdata->rstn;
*slp_tr = pdata->slp_tr;
*xtal_trim = pdata->xtal_trim;
return 0;
}
*rstn = of_get_named_gpio(spi->dev.of_node, "reset-gpio", 0);
*slp_tr = of_get_named_gpio(spi->dev.of_node, "sleep-gpio", 0);
ret = of_property_read_u8(spi->dev.of_node, "xtal-trim", xtal_trim);
if (ret < 0 && ret != -EINVAL)
return ret;
return 0;
}
static int
at86rf230_detect_device(struct at86rf230_local *lp)
{
unsigned int part, version, val;
u16 man_id = 0;
const char *chip;
int rc;
rc = __at86rf230_read(lp, RG_MAN_ID_0, &val);
if (rc)
return rc;
man_id |= val;
rc = __at86rf230_read(lp, RG_MAN_ID_1, &val);
if (rc)
return rc;
man_id |= (val << 8);
rc = __at86rf230_read(lp, RG_PART_NUM, &part);
if (rc)
return rc;
rc = __at86rf230_read(lp, RG_VERSION_NUM, &version);
if (rc)
return rc;
if (man_id != 0x001f) {
dev_err(&lp->spi->dev, "Non-Atmel dev found (MAN_ID %02x %02x)\n",
man_id >> 8, man_id & 0xFF);
return -EINVAL;
}
lp->hw->flags = IEEE802154_HW_TX_OMIT_CKSUM |
IEEE802154_HW_CSMA_PARAMS |
IEEE802154_HW_FRAME_RETRIES | IEEE802154_HW_AFILT |
IEEE802154_HW_PROMISCUOUS;
lp->hw->phy->flags = WPAN_PHY_FLAG_TXPOWER |
WPAN_PHY_FLAG_CCA_ED_LEVEL |
WPAN_PHY_FLAG_CCA_MODE;
lp->hw->phy->supported.cca_modes = BIT(NL802154_CCA_ENERGY) |
BIT(NL802154_CCA_CARRIER) | BIT(NL802154_CCA_ENERGY_CARRIER);
lp->hw->phy->supported.cca_opts = BIT(NL802154_CCA_OPT_ENERGY_CARRIER_AND) |
BIT(NL802154_CCA_OPT_ENERGY_CARRIER_OR);
lp->hw->phy->supported.cca_ed_levels = at86rf23x_ed_levels;
lp->hw->phy->supported.cca_ed_levels_size = ARRAY_SIZE(at86rf23x_ed_levels);
lp->hw->phy->cca.mode = NL802154_CCA_ENERGY;
switch (part) {
case 2:
chip = "at86rf230";
rc = -ENOTSUPP;
goto not_supp;
case 3:
chip = "at86rf231";
lp->data = &at86rf231_data;
lp->hw->phy->supported.channels[0] = 0x7FFF800;
lp->hw->phy->current_channel = 11;
lp->hw->phy->symbol_duration = 16;
lp->hw->phy->supported.tx_powers = at86rf231_powers;
lp->hw->phy->supported.tx_powers_size = ARRAY_SIZE(at86rf231_powers);
break;
case 7:
chip = "at86rf212";
lp->data = &at86rf212_data;
lp->hw->flags |= IEEE802154_HW_LBT;
lp->hw->phy->supported.channels[0] = 0x00007FF;
lp->hw->phy->supported.channels[2] = 0x00007FF;
lp->hw->phy->current_channel = 5;
lp->hw->phy->symbol_duration = 25;
lp->hw->phy->supported.lbt = NL802154_SUPPORTED_BOOL_BOTH;
lp->hw->phy->supported.tx_powers = at86rf212_powers;
lp->hw->phy->supported.tx_powers_size = ARRAY_SIZE(at86rf212_powers);
lp->hw->phy->supported.cca_ed_levels = at86rf212_ed_levels_100;
lp->hw->phy->supported.cca_ed_levels_size = ARRAY_SIZE(at86rf212_ed_levels_100);
break;
case 11:
chip = "at86rf233";
lp->data = &at86rf233_data;
lp->hw->phy->supported.channels[0] = 0x7FFF800;
lp->hw->phy->current_channel = 13;
lp->hw->phy->symbol_duration = 16;
lp->hw->phy->supported.tx_powers = at86rf233_powers;
lp->hw->phy->supported.tx_powers_size = ARRAY_SIZE(at86rf233_powers);
break;
default:
chip = "unknown";
rc = -ENOTSUPP;
goto not_supp;
}
lp->hw->phy->cca_ed_level = lp->hw->phy->supported.cca_ed_levels[7];
lp->hw->phy->transmit_power = lp->hw->phy->supported.tx_powers[0];
not_supp:
dev_info(&lp->spi->dev, "Detected %s chip version %d\n", chip, version);
return rc;
}
static void
at86rf230_setup_spi_messages(struct at86rf230_local *lp)
{
lp->state.lp = lp;
lp->state.irq = lp->spi->irq;
spi_message_init(&lp->state.msg);
lp->state.msg.context = &lp->state;
lp->state.trx.len = 2;
lp->state.trx.tx_buf = lp->state.buf;
lp->state.trx.rx_buf = lp->state.buf;
spi_message_add_tail(&lp->state.trx, &lp->state.msg);
hrtimer_init(&lp->state.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
lp->state.timer.function = at86rf230_async_state_timer;
lp->irq.lp = lp;
lp->irq.irq = lp->spi->irq;
spi_message_init(&lp->irq.msg);
lp->irq.msg.context = &lp->irq;
lp->irq.trx.len = 2;
lp->irq.trx.tx_buf = lp->irq.buf;
lp->irq.trx.rx_buf = lp->irq.buf;
spi_message_add_tail(&lp->irq.trx, &lp->irq.msg);
hrtimer_init(&lp->irq.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
lp->irq.timer.function = at86rf230_async_state_timer;
lp->tx.lp = lp;
lp->tx.irq = lp->spi->irq;
spi_message_init(&lp->tx.msg);
lp->tx.msg.context = &lp->tx;
lp->tx.trx.len = 2;
lp->tx.trx.tx_buf = lp->tx.buf;
lp->tx.trx.rx_buf = lp->tx.buf;
spi_message_add_tail(&lp->tx.trx, &lp->tx.msg);
hrtimer_init(&lp->tx.timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
lp->tx.timer.function = at86rf230_async_state_timer;
}
static int at86rf230_probe(struct spi_device *spi)
{
struct ieee802154_hw *hw;
struct at86rf230_local *lp;
unsigned int status;
int rc, irq_type, rstn, slp_tr;
u8 xtal_trim = 0;
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ specified\n");
return -EINVAL;
}
rc = at86rf230_get_pdata(spi, &rstn, &slp_tr, &xtal_trim);
if (rc < 0) {
dev_err(&spi->dev, "failed to parse platform_data: %d\n", rc);
return rc;
}
if (gpio_is_valid(rstn)) {
rc = devm_gpio_request_one(&spi->dev, rstn,
GPIOF_OUT_INIT_HIGH, "rstn");
if (rc)
return rc;
}
if (gpio_is_valid(slp_tr)) {
rc = devm_gpio_request_one(&spi->dev, slp_tr,
GPIOF_OUT_INIT_LOW, "slp_tr");
if (rc)
return rc;
}
if (gpio_is_valid(rstn)) {
udelay(1);
gpio_set_value(rstn, 0);
udelay(1);
gpio_set_value(rstn, 1);
usleep_range(120, 240);
}
hw = ieee802154_alloc_hw(sizeof(*lp), &at86rf230_ops);
if (!hw)
return -ENOMEM;
lp = hw->priv;
lp->hw = hw;
lp->spi = spi;
lp->slp_tr = slp_tr;
hw->parent = &spi->dev;
ieee802154_random_extended_addr(&hw->phy->perm_extended_addr);
lp->regmap = devm_regmap_init_spi(spi, &at86rf230_regmap_spi_config);
if (IS_ERR(lp->regmap)) {
rc = PTR_ERR(lp->regmap);
dev_err(&spi->dev, "Failed to allocate register map: %d\n",
rc);
goto free_dev;
}
at86rf230_setup_spi_messages(lp);
rc = at86rf230_detect_device(lp);
if (rc < 0)
goto free_dev;
init_completion(&lp->state_complete);
spi_set_drvdata(spi, lp);
rc = at86rf230_hw_init(lp, xtal_trim);
if (rc)
goto free_dev;
rc = at86rf230_read_subreg(lp, RG_IRQ_STATUS, 0xff, 0, &status);
if (rc)
goto free_dev;
irq_type = irq_get_trigger_type(spi->irq);
if (!irq_type)
irq_type = IRQF_TRIGGER_HIGH;
rc = devm_request_irq(&spi->dev, spi->irq, at86rf230_isr,
IRQF_SHARED | irq_type, dev_name(&spi->dev), lp);
if (rc)
goto free_dev;
disable_irq(spi->irq);
at86rf230_sleep(lp);
rc = ieee802154_register_hw(lp->hw);
if (rc)
goto free_dev;
return rc;
free_dev:
ieee802154_free_hw(lp->hw);
return rc;
}
static int at86rf230_remove(struct spi_device *spi)
{
struct at86rf230_local *lp = spi_get_drvdata(spi);
at86rf230_write_subreg(lp, SR_IRQ_MASK, 0);
ieee802154_unregister_hw(lp->hw);
ieee802154_free_hw(lp->hw);
dev_dbg(&spi->dev, "unregistered at86rf230\n");
return 0;
}
