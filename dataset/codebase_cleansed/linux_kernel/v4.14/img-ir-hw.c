static void img_ir_timing_preprocess(struct img_ir_timing_range *range,
unsigned int unit)
{
if (range->max < range->min)
range->max = range->min;
if (unit) {
range->min = (range->min*unit)/1000;
range->max = (range->max*unit + 999)/1000;
}
}
static void img_ir_symbol_timing_preprocess(struct img_ir_symbol_timing *timing,
unsigned int unit)
{
img_ir_timing_preprocess(&timing->pulse, unit);
img_ir_timing_preprocess(&timing->space, unit);
}
static void img_ir_timings_preprocess(struct img_ir_timings *timings,
unsigned int unit)
{
img_ir_symbol_timing_preprocess(&timings->ldr, unit);
img_ir_symbol_timing_preprocess(&timings->s00, unit);
img_ir_symbol_timing_preprocess(&timings->s01, unit);
img_ir_symbol_timing_preprocess(&timings->s10, unit);
img_ir_symbol_timing_preprocess(&timings->s11, unit);
if (unit)
timings->ft.ft_min = (timings->ft.ft_min*unit + 999)/1000;
}
static void img_ir_timing_defaults(struct img_ir_timing_range *range,
struct img_ir_timing_range *defaults)
{
if (!range->min)
range->min = defaults->min;
if (!range->max)
range->max = defaults->max;
}
static void img_ir_symbol_timing_defaults(struct img_ir_symbol_timing *timing,
struct img_ir_symbol_timing *defaults)
{
img_ir_timing_defaults(&timing->pulse, &defaults->pulse);
img_ir_timing_defaults(&timing->space, &defaults->space);
}
static void img_ir_timings_defaults(struct img_ir_timings *timings,
struct img_ir_timings *defaults)
{
img_ir_symbol_timing_defaults(&timings->ldr, &defaults->ldr);
img_ir_symbol_timing_defaults(&timings->s00, &defaults->s00);
img_ir_symbol_timing_defaults(&timings->s01, &defaults->s01);
img_ir_symbol_timing_defaults(&timings->s10, &defaults->s10);
img_ir_symbol_timing_defaults(&timings->s11, &defaults->s11);
if (!timings->ft.ft_min)
timings->ft.ft_min = defaults->ft.ft_min;
}
static u32 img_ir_control(const struct img_ir_control *control)
{
u32 ctrl = control->code_type << IMG_IR_CODETYPE_SHIFT;
if (control->decoden)
ctrl |= IMG_IR_DECODEN;
if (control->hdrtog)
ctrl |= IMG_IR_HDRTOG;
if (control->ldrdec)
ctrl |= IMG_IR_LDRDEC;
if (control->decodinpol)
ctrl |= IMG_IR_DECODINPOL;
if (control->bitorien)
ctrl |= IMG_IR_BITORIEN;
if (control->d1validsel)
ctrl |= IMG_IR_D1VALIDSEL;
if (control->bitinv)
ctrl |= IMG_IR_BITINV;
if (control->decodend2)
ctrl |= IMG_IR_DECODEND2;
if (control->bitoriend2)
ctrl |= IMG_IR_BITORIEND2;
if (control->bitinvd2)
ctrl |= IMG_IR_BITINVD2;
return ctrl;
}
static void img_ir_timing_range_convert(struct img_ir_timing_range *out,
const struct img_ir_timing_range *in,
unsigned int tolerance,
unsigned long clock_hz,
unsigned int shift)
{
unsigned int min = in->min;
unsigned int max = in->max;
min = min - (min*tolerance >> 7);
max = max + (max*tolerance >> 7);
min = min*clock_hz / 1000000;
max = (max*clock_hz + 999999) / 1000000;
out->min = min >> shift;
out->max = (max + ((1 << shift) - 1)) >> shift;
}
static u32 img_ir_symbol_timing(const struct img_ir_symbol_timing *timing,
unsigned int tolerance,
unsigned long clock_hz,
unsigned int pd_shift,
unsigned int w_shift)
{
struct img_ir_timing_range hw_pulse, hw_period;
hw_period.min = timing->pulse.min + timing->space.min;
hw_period.max = timing->pulse.max + timing->space.max;
img_ir_timing_range_convert(&hw_period, &hw_period,
tolerance, clock_hz, pd_shift);
img_ir_timing_range_convert(&hw_pulse, &timing->pulse,
tolerance, clock_hz, w_shift);
return (hw_period.max << IMG_IR_PD_MAX_SHIFT) |
(hw_period.min << IMG_IR_PD_MIN_SHIFT) |
(hw_pulse.max << IMG_IR_W_MAX_SHIFT) |
(hw_pulse.min << IMG_IR_W_MIN_SHIFT);
}
static u32 img_ir_free_timing(const struct img_ir_free_timing *timing,
unsigned long clock_hz)
{
unsigned int minlen, maxlen, ft_min;
if (timing->minlen < 30)
minlen = timing->minlen & -2;
else
minlen = 30;
if (timing->maxlen < 48)
maxlen = (timing->maxlen + 1) & -2;
else
maxlen = 48;
ft_min = (timing->ft_min*clock_hz + 999999) / 1000000;
ft_min = (ft_min + 7) >> 3;
return (maxlen << IMG_IR_MAXLEN_SHIFT) |
(minlen << IMG_IR_MINLEN_SHIFT) |
(ft_min << IMG_IR_FT_MIN_SHIFT);
}
static u32 img_ir_free_timing_dynamic(u32 st_ft, struct img_ir_filter *filter)
{
unsigned int minlen, maxlen, newminlen, newmaxlen;
newminlen = filter->minlen & -2;
newmaxlen = (filter->maxlen + 1) & -2;
minlen = (st_ft & IMG_IR_MINLEN) >> IMG_IR_MINLEN_SHIFT;
maxlen = (st_ft & IMG_IR_MAXLEN) >> IMG_IR_MAXLEN_SHIFT;
if (newminlen > minlen) {
st_ft &= ~IMG_IR_MINLEN;
st_ft |= newminlen << IMG_IR_MINLEN_SHIFT;
}
if (newmaxlen < maxlen) {
st_ft &= ~IMG_IR_MAXLEN;
st_ft |= newmaxlen << IMG_IR_MAXLEN_SHIFT;
}
return st_ft;
}
static void img_ir_timings_convert(struct img_ir_timing_regvals *regs,
const struct img_ir_timings *timings,
unsigned int tolerance,
unsigned int clock_hz)
{
regs->ldr = img_ir_symbol_timing(&timings->ldr, tolerance, clock_hz,
4, 4);
regs->s00 = img_ir_symbol_timing(&timings->s00, tolerance, clock_hz,
1, 0);
regs->s01 = img_ir_symbol_timing(&timings->s01, tolerance, clock_hz,
1, 0);
regs->s10 = img_ir_symbol_timing(&timings->s10, tolerance, clock_hz,
1, 0);
regs->s11 = img_ir_symbol_timing(&timings->s11, tolerance, clock_hz,
1, 0);
regs->ft = img_ir_free_timing(&timings->ft, clock_hz);
}
static void img_ir_decoder_preprocess(struct img_ir_decoder *decoder)
{
if (!decoder->tolerance)
decoder->tolerance = 10;
decoder->tolerance = decoder->tolerance * 128 / 100;
img_ir_timings_preprocess(&decoder->timings, decoder->unit);
if (decoder->repeat) {
img_ir_timings_preprocess(&decoder->rtimings, decoder->unit);
img_ir_timings_defaults(&decoder->rtimings, &decoder->timings);
}
}
static void img_ir_decoder_convert(const struct img_ir_decoder *decoder,
struct img_ir_reg_timings *reg_timings,
unsigned int clock_hz)
{
reg_timings->ctrl = img_ir_control(&decoder->control);
img_ir_timings_convert(&reg_timings->timings, &decoder->timings,
decoder->tolerance, clock_hz);
if (decoder->repeat)
img_ir_timings_convert(&reg_timings->rtimings,
&decoder->rtimings, decoder->tolerance,
clock_hz);
}
static void img_ir_write_timings(struct img_ir_priv *priv,
struct img_ir_timing_regvals *regs,
enum rc_filter_type type)
{
struct img_ir_priv_hw *hw = &priv->hw;
u32 ft = regs->ft;
if (hw->flags & BIT(type))
ft = img_ir_free_timing_dynamic(regs->ft, &hw->filters[type]);
img_ir_write(priv, IMG_IR_LEAD_SYMB_TIMING, regs->ldr);
img_ir_write(priv, IMG_IR_S00_SYMB_TIMING, regs->s00);
img_ir_write(priv, IMG_IR_S01_SYMB_TIMING, regs->s01);
img_ir_write(priv, IMG_IR_S10_SYMB_TIMING, regs->s10);
img_ir_write(priv, IMG_IR_S11_SYMB_TIMING, regs->s11);
img_ir_write(priv, IMG_IR_FREE_SYMB_TIMING, ft);
dev_dbg(priv->dev, "timings: ldr=%#x, s=[%#x, %#x, %#x, %#x], ft=%#x\n",
regs->ldr, regs->s00, regs->s01, regs->s10, regs->s11, ft);
}
static void img_ir_write_filter(struct img_ir_priv *priv,
struct img_ir_filter *filter)
{
if (filter) {
dev_dbg(priv->dev, "IR filter=%016llx & %016llx\n",
(unsigned long long)filter->data,
(unsigned long long)filter->mask);
img_ir_write(priv, IMG_IR_IRQ_MSG_DATA_LW, (u32)filter->data);
img_ir_write(priv, IMG_IR_IRQ_MSG_DATA_UP, (u32)(filter->data
>> 32));
img_ir_write(priv, IMG_IR_IRQ_MSG_MASK_LW, (u32)filter->mask);
img_ir_write(priv, IMG_IR_IRQ_MSG_MASK_UP, (u32)(filter->mask
>> 32));
} else {
dev_dbg(priv->dev, "IR clearing filter\n");
img_ir_write(priv, IMG_IR_IRQ_MSG_MASK_LW, 0);
img_ir_write(priv, IMG_IR_IRQ_MSG_MASK_UP, 0);
}
}
static void _img_ir_set_filter(struct img_ir_priv *priv,
struct img_ir_filter *filter)
{
struct img_ir_priv_hw *hw = &priv->hw;
u32 irq_en, irq_on;
irq_en = img_ir_read(priv, IMG_IR_IRQ_ENABLE);
if (filter) {
hw->filters[RC_FILTER_NORMAL] = *filter;
hw->flags |= IMG_IR_F_FILTER;
irq_on = IMG_IR_IRQ_DATA_MATCH;
irq_en &= ~(IMG_IR_IRQ_DATA_VALID | IMG_IR_IRQ_DATA2_VALID);
} else {
hw->flags &= ~IMG_IR_F_FILTER;
irq_en &= ~IMG_IR_IRQ_DATA_MATCH;
irq_on = IMG_IR_IRQ_DATA_VALID | IMG_IR_IRQ_DATA2_VALID;
}
irq_en |= irq_on;
img_ir_write_filter(priv, filter);
img_ir_write(priv, IMG_IR_IRQ_CLEAR, irq_on);
img_ir_write(priv, IMG_IR_IRQ_ENABLE, irq_en);
}
static void _img_ir_set_wake_filter(struct img_ir_priv *priv,
struct img_ir_filter *filter)
{
struct img_ir_priv_hw *hw = &priv->hw;
if (filter) {
hw->filters[RC_FILTER_WAKEUP] = *filter;
hw->flags |= IMG_IR_F_WAKE;
} else {
hw->flags &= ~IMG_IR_F_WAKE;
}
}
static int img_ir_set_filter(struct rc_dev *dev, enum rc_filter_type type,
struct rc_scancode_filter *sc_filter)
{
struct img_ir_priv *priv = dev->priv;
struct img_ir_priv_hw *hw = &priv->hw;
struct img_ir_filter filter, *filter_ptr = &filter;
int ret = 0;
dev_dbg(priv->dev, "IR scancode %sfilter=%08x & %08x\n",
type == RC_FILTER_WAKEUP ? "wake " : "",
sc_filter->data,
sc_filter->mask);
spin_lock_irq(&priv->lock);
if (!sc_filter->mask) {
filter_ptr = NULL;
goto set_unlock;
}
if (!hw->decoder || !hw->decoder->filter) {
ret = -EINVAL;
goto unlock;
}
filter.minlen = 0;
filter.maxlen = ~0;
if (type == RC_FILTER_NORMAL) {
ret = hw->decoder->filter(sc_filter, &filter,
dev->enabled_protocols);
} else {
ret = hw->decoder->filter(sc_filter, &filter,
1ULL << dev->wakeup_protocol);
}
if (ret)
goto unlock;
dev_dbg(priv->dev, "IR raw %sfilter=%016llx & %016llx\n",
type == RC_FILTER_WAKEUP ? "wake " : "",
(unsigned long long)filter.data,
(unsigned long long)filter.mask);
set_unlock:
switch (type) {
case RC_FILTER_NORMAL:
_img_ir_set_filter(priv, filter_ptr);
break;
case RC_FILTER_WAKEUP:
_img_ir_set_wake_filter(priv, filter_ptr);
break;
default:
ret = -EINVAL;
}
unlock:
spin_unlock_irq(&priv->lock);
return ret;
}
static int img_ir_set_normal_filter(struct rc_dev *dev,
struct rc_scancode_filter *sc_filter)
{
return img_ir_set_filter(dev, RC_FILTER_NORMAL, sc_filter);
}
static int img_ir_set_wakeup_filter(struct rc_dev *dev,
struct rc_scancode_filter *sc_filter)
{
return img_ir_set_filter(dev, RC_FILTER_WAKEUP, sc_filter);
}
static void img_ir_set_decoder(struct img_ir_priv *priv,
const struct img_ir_decoder *decoder,
u64 proto)
{
struct img_ir_priv_hw *hw = &priv->hw;
struct rc_dev *rdev = hw->rdev;
u32 ir_status, irq_en;
spin_lock_irq(&priv->lock);
hw->stopping = true;
spin_unlock_irq(&priv->lock);
del_timer_sync(&hw->end_timer);
del_timer_sync(&hw->suspend_timer);
spin_lock_irq(&priv->lock);
hw->stopping = false;
img_ir_write(priv, IMG_IR_CONTROL, 0);
irq_en = img_ir_read(priv, IMG_IR_IRQ_ENABLE);
img_ir_write(priv, IMG_IR_IRQ_ENABLE, irq_en & IMG_IR_IRQ_EDGE);
img_ir_write(priv, IMG_IR_IRQ_CLEAR, IMG_IR_IRQ_ALL & ~IMG_IR_IRQ_EDGE);
ir_status = img_ir_read(priv, IMG_IR_STATUS);
if (ir_status & (IMG_IR_RXDVAL | IMG_IR_RXDVALD2)) {
ir_status &= ~(IMG_IR_RXDVAL | IMG_IR_RXDVALD2);
img_ir_write(priv, IMG_IR_STATUS, ir_status);
}
img_ir_read(priv, IMG_IR_DATA_LW);
img_ir_read(priv, IMG_IR_DATA_UP);
hw->mode = IMG_IR_M_NORMAL;
rdev->scancode_wakeup_filter.data = 0;
rdev->scancode_wakeup_filter.mask = 0;
rdev->wakeup_protocol = RC_PROTO_UNKNOWN;
_img_ir_set_filter(priv, NULL);
_img_ir_set_wake_filter(priv, NULL);
hw->enabled_protocols = 0;
hw->decoder = decoder;
if (!decoder)
goto unlock;
if (!proto)
proto = decoder->type;
hw->enabled_protocols = proto;
img_ir_decoder_convert(decoder, &hw->reg_timings, hw->clk_hz);
img_ir_write_timings(priv, &hw->reg_timings.timings, RC_FILTER_NORMAL);
img_ir_write(priv, IMG_IR_CONTROL, hw->reg_timings.ctrl);
unlock:
spin_unlock_irq(&priv->lock);
}
static bool img_ir_decoder_compatible(struct img_ir_priv *priv,
const struct img_ir_decoder *dec)
{
unsigned int ct;
ct = dec->control.code_type;
if (priv->hw.ct_quirks[ct] & IMG_IR_QUIRK_CODE_BROKEN)
return false;
return true;
}
static u64 img_ir_allowed_protos(struct img_ir_priv *priv)
{
u64 protos = 0;
struct img_ir_decoder **decp;
for (decp = img_ir_decoders; *decp; ++decp) {
const struct img_ir_decoder *dec = *decp;
if (img_ir_decoder_compatible(priv, dec))
protos |= dec->type;
}
return protos;
}
static int img_ir_change_protocol(struct rc_dev *dev, u64 *ir_type)
{
struct img_ir_priv *priv = dev->priv;
struct img_ir_priv_hw *hw = &priv->hw;
struct rc_dev *rdev = hw->rdev;
struct img_ir_decoder **decp;
u64 wakeup_protocols;
if (!*ir_type) {
img_ir_set_decoder(priv, NULL, 0);
goto success;
}
for (decp = img_ir_decoders; *decp; ++decp) {
const struct img_ir_decoder *dec = *decp;
if (!img_ir_decoder_compatible(priv, dec))
continue;
if (*ir_type & dec->type) {
*ir_type &= dec->type;
img_ir_set_decoder(priv, dec, *ir_type);
goto success;
}
}
return -EINVAL;
success:
wakeup_protocols = *ir_type;
if (!hw->decoder || !hw->decoder->filter)
wakeup_protocols = 0;
rdev->allowed_wakeup_protocols = wakeup_protocols;
return 0;
}
static void img_ir_set_protocol(struct img_ir_priv *priv, u64 proto)
{
struct rc_dev *rdev = priv->hw.rdev;
mutex_lock(&rdev->lock);
rdev->enabled_protocols = proto;
rdev->allowed_wakeup_protocols = proto;
mutex_unlock(&rdev->lock);
}
static void img_ir_init_decoders(void)
{
struct img_ir_decoder **decp;
spin_lock(&img_ir_decoders_lock);
if (!img_ir_decoders_preprocessed) {
for (decp = img_ir_decoders; *decp; ++decp)
img_ir_decoder_preprocess(*decp);
img_ir_decoders_preprocessed = true;
}
spin_unlock(&img_ir_decoders_lock);
}
static int img_ir_enable_wake(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
int ret = 0;
spin_lock_irq(&priv->lock);
if (hw->flags & IMG_IR_F_WAKE) {
hw->suspend_irqen = img_ir_read(priv, IMG_IR_IRQ_ENABLE);
img_ir_write(priv, IMG_IR_IRQ_ENABLE, IMG_IR_IRQ_DATA_MATCH);
img_ir_write_filter(priv, &hw->filters[RC_FILTER_WAKEUP]);
img_ir_write_timings(priv, &hw->reg_timings.timings,
RC_FILTER_WAKEUP);
hw->mode = IMG_IR_M_WAKE;
ret = 1;
}
spin_unlock_irq(&priv->lock);
return ret;
}
static int img_ir_disable_wake(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
int ret = 0;
spin_lock_irq(&priv->lock);
if (hw->flags & IMG_IR_F_WAKE) {
if (hw->flags & IMG_IR_F_FILTER) {
img_ir_write(priv, IMG_IR_IRQ_ENABLE,
(hw->suspend_irqen & IMG_IR_IRQ_EDGE) |
IMG_IR_IRQ_DATA_MATCH);
img_ir_write_filter(priv,
&hw->filters[RC_FILTER_NORMAL]);
} else {
img_ir_write(priv, IMG_IR_IRQ_ENABLE,
(hw->suspend_irqen & IMG_IR_IRQ_EDGE) |
IMG_IR_IRQ_DATA_VALID |
IMG_IR_IRQ_DATA2_VALID);
img_ir_write_filter(priv, NULL);
}
img_ir_write_timings(priv, &hw->reg_timings.timings,
RC_FILTER_NORMAL);
hw->mode = IMG_IR_M_NORMAL;
ret = 1;
}
spin_unlock_irq(&priv->lock);
return ret;
}
static void img_ir_begin_repeat(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
if (hw->mode == IMG_IR_M_NORMAL) {
img_ir_write(priv, IMG_IR_CONTROL, 0);
hw->mode = IMG_IR_M_REPEATING;
img_ir_write_timings(priv, &hw->reg_timings.rtimings,
RC_FILTER_NORMAL);
img_ir_write(priv, IMG_IR_CONTROL, hw->reg_timings.ctrl);
}
}
static void img_ir_end_repeat(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
if (hw->mode == IMG_IR_M_REPEATING) {
img_ir_write(priv, IMG_IR_CONTROL, 0);
hw->mode = IMG_IR_M_NORMAL;
img_ir_write_timings(priv, &hw->reg_timings.timings,
RC_FILTER_NORMAL);
img_ir_write(priv, IMG_IR_CONTROL, hw->reg_timings.ctrl);
}
}
static void img_ir_handle_data(struct img_ir_priv *priv, u32 len, u64 raw)
{
struct img_ir_priv_hw *hw = &priv->hw;
const struct img_ir_decoder *dec = hw->decoder;
int ret = IMG_IR_SCANCODE;
struct img_ir_scancode_req request;
request.protocol = RC_PROTO_UNKNOWN;
request.toggle = 0;
if (dec->scancode)
ret = dec->scancode(len, raw, hw->enabled_protocols, &request);
else if (len >= 32)
request.scancode = (u32)raw;
else if (len < 32)
request.scancode = (u32)raw & ((1 << len)-1);
dev_dbg(priv->dev, "data (%u bits) = %#llx\n",
len, (unsigned long long)raw);
if (ret == IMG_IR_SCANCODE) {
dev_dbg(priv->dev, "decoded scan code %#x, toggle %u\n",
request.scancode, request.toggle);
rc_keydown(hw->rdev, request.protocol, request.scancode,
request.toggle);
img_ir_end_repeat(priv);
} else if (ret == IMG_IR_REPEATCODE) {
if (hw->mode == IMG_IR_M_REPEATING) {
dev_dbg(priv->dev, "decoded repeat code\n");
rc_repeat(hw->rdev);
} else {
dev_dbg(priv->dev, "decoded unexpected repeat code, ignoring\n");
}
} else {
dev_dbg(priv->dev, "decode failed (%d)\n", ret);
return;
}
if (dec->repeat && !hw->stopping) {
unsigned long interval;
img_ir_begin_repeat(priv);
interval = dec->repeat + (dec->repeat >> 3);
mod_timer(&hw->end_timer,
jiffies + msecs_to_jiffies(interval));
}
}
static void img_ir_end_timer(unsigned long arg)
{
struct img_ir_priv *priv = (struct img_ir_priv *)arg;
spin_lock_irq(&priv->lock);
img_ir_end_repeat(priv);
spin_unlock_irq(&priv->lock);
}
static void img_ir_suspend_timer(unsigned long arg)
{
struct img_ir_priv *priv = (struct img_ir_priv *)arg;
spin_lock_irq(&priv->lock);
if ((priv->hw.quirk_suspend_irq & IMG_IR_IRQ_EDGE) ==
img_ir_read(priv, IMG_IR_IRQ_ENABLE))
img_ir_write(priv, IMG_IR_IRQ_ENABLE,
priv->hw.quirk_suspend_irq);
img_ir_write(priv, IMG_IR_CONTROL, priv->hw.reg_timings.ctrl);
spin_unlock_irq(&priv->lock);
}
static void img_ir_change_frequency(struct img_ir_priv *priv,
struct clk_notifier_data *change)
{
struct img_ir_priv_hw *hw = &priv->hw;
dev_dbg(priv->dev, "clk changed %lu HZ -> %lu HZ\n",
change->old_rate, change->new_rate);
spin_lock_irq(&priv->lock);
if (hw->clk_hz == change->new_rate)
goto unlock;
hw->clk_hz = change->new_rate;
if (hw->decoder) {
img_ir_decoder_convert(hw->decoder, &hw->reg_timings,
hw->clk_hz);
switch (hw->mode) {
case IMG_IR_M_NORMAL:
img_ir_write_timings(priv, &hw->reg_timings.timings,
RC_FILTER_NORMAL);
break;
case IMG_IR_M_REPEATING:
img_ir_write_timings(priv, &hw->reg_timings.rtimings,
RC_FILTER_NORMAL);
break;
#ifdef CONFIG_PM_SLEEP
case IMG_IR_M_WAKE:
img_ir_write_timings(priv, &hw->reg_timings.timings,
RC_FILTER_WAKEUP);
break;
#endif
}
}
unlock:
spin_unlock_irq(&priv->lock);
}
static int img_ir_clk_notify(struct notifier_block *self, unsigned long action,
void *data)
{
struct img_ir_priv *priv = container_of(self, struct img_ir_priv,
hw.clk_nb);
switch (action) {
case POST_RATE_CHANGE:
img_ir_change_frequency(priv, data);
break;
default:
break;
}
return NOTIFY_OK;
}
void img_ir_isr_hw(struct img_ir_priv *priv, u32 irq_status)
{
struct img_ir_priv_hw *hw = &priv->hw;
u32 ir_status, len, lw, up;
unsigned int ct;
if (!hw->decoder)
return;
ct = hw->decoder->control.code_type;
ir_status = img_ir_read(priv, IMG_IR_STATUS);
if (!(ir_status & (IMG_IR_RXDVAL | IMG_IR_RXDVALD2))) {
if (!(priv->hw.ct_quirks[ct] & IMG_IR_QUIRK_CODE_IRQ) ||
hw->stopping)
return;
img_ir_write(priv, IMG_IR_CONTROL, 0);
hw->quirk_suspend_irq = img_ir_read(priv, IMG_IR_IRQ_ENABLE);
img_ir_write(priv, IMG_IR_IRQ_ENABLE,
hw->quirk_suspend_irq & IMG_IR_IRQ_EDGE);
mod_timer(&hw->suspend_timer,
jiffies + msecs_to_jiffies(5));
return;
}
ir_status &= ~(IMG_IR_RXDVAL | IMG_IR_RXDVALD2);
img_ir_write(priv, IMG_IR_STATUS, ir_status);
len = (ir_status & IMG_IR_RXDLEN) >> IMG_IR_RXDLEN_SHIFT;
if (hw->ct_quirks[ct] & IMG_IR_QUIRK_CODE_LEN_INCR)
++len;
lw = img_ir_read(priv, IMG_IR_DATA_LW);
up = img_ir_read(priv, IMG_IR_DATA_UP);
img_ir_handle_data(priv, len, (u64)up << 32 | lw);
}
void img_ir_setup_hw(struct img_ir_priv *priv)
{
struct img_ir_decoder **decp;
if (!priv->hw.rdev)
return;
for (decp = img_ir_decoders; *decp; ++decp) {
const struct img_ir_decoder *dec = *decp;
if (img_ir_decoder_compatible(priv, dec)) {
img_ir_set_protocol(priv, dec->type);
img_ir_set_decoder(priv, dec, 0);
return;
}
}
img_ir_set_decoder(priv, NULL, 0);
}
static void img_ir_probe_hw_caps(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
hw->ct_quirks[IMG_IR_CODETYPE_PULSELEN]
|= IMG_IR_QUIRK_CODE_LEN_INCR;
hw->ct_quirks[IMG_IR_CODETYPE_BIPHASE]
|= IMG_IR_QUIRK_CODE_IRQ;
hw->ct_quirks[IMG_IR_CODETYPE_2BITPULSEPOS]
|= IMG_IR_QUIRK_CODE_BROKEN;
}
int img_ir_probe_hw(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
struct rc_dev *rdev;
int error;
img_ir_init_decoders();
img_ir_probe_hw_caps(priv);
setup_timer(&hw->end_timer, img_ir_end_timer, (unsigned long)priv);
setup_timer(&hw->suspend_timer, img_ir_suspend_timer,
(unsigned long)priv);
if (!IS_ERR(priv->clk)) {
hw->clk_hz = clk_get_rate(priv->clk);
#ifdef CONFIG_COMMON_CLK
hw->clk_nb.notifier_call = img_ir_clk_notify;
error = clk_notifier_register(priv->clk, &hw->clk_nb);
if (error)
dev_warn(priv->dev,
"failed to register clock notifier\n");
#endif
} else {
hw->clk_hz = 32768;
}
hw->rdev = rdev = rc_allocate_device(RC_DRIVER_SCANCODE);
if (!rdev) {
dev_err(priv->dev, "cannot allocate input device\n");
error = -ENOMEM;
goto err_alloc_rc;
}
rdev->priv = priv;
rdev->map_name = RC_MAP_EMPTY;
rdev->allowed_protocols = img_ir_allowed_protos(priv);
rdev->device_name = "IMG Infrared Decoder";
rdev->s_filter = img_ir_set_normal_filter;
rdev->s_wakeup_filter = img_ir_set_wakeup_filter;
error = rc_register_device(rdev);
if (error) {
dev_err(priv->dev, "failed to register IR input device\n");
goto err_register_rc;
}
rdev->change_protocol = img_ir_change_protocol;
device_init_wakeup(priv->dev, 1);
return 0;
err_register_rc:
img_ir_set_decoder(priv, NULL, 0);
hw->rdev = NULL;
rc_free_device(rdev);
err_alloc_rc:
#ifdef CONFIG_COMMON_CLK
if (!IS_ERR(priv->clk))
clk_notifier_unregister(priv->clk, &hw->clk_nb);
#endif
return error;
}
void img_ir_remove_hw(struct img_ir_priv *priv)
{
struct img_ir_priv_hw *hw = &priv->hw;
struct rc_dev *rdev = hw->rdev;
if (!rdev)
return;
img_ir_set_decoder(priv, NULL, 0);
hw->rdev = NULL;
rc_unregister_device(rdev);
#ifdef CONFIG_COMMON_CLK
if (!IS_ERR(priv->clk))
clk_notifier_unregister(priv->clk, &hw->clk_nb);
#endif
}
int img_ir_suspend(struct device *dev)
{
struct img_ir_priv *priv = dev_get_drvdata(dev);
if (device_may_wakeup(dev) && img_ir_enable_wake(priv))
enable_irq_wake(priv->irq);
return 0;
}
int img_ir_resume(struct device *dev)
{
struct img_ir_priv *priv = dev_get_drvdata(dev);
if (device_may_wakeup(dev) && img_ir_disable_wake(priv))
disable_irq_wake(priv->irq);
return 0;
}
