static int mxs_lradc_adc_read_single(struct iio_dev *iio_dev, int chan,
int *val)
{
struct mxs_lradc_adc *adc = iio_priv(iio_dev);
struct mxs_lradc *lradc = adc->lradc;
int ret;
ret = iio_device_claim_direct_mode(iio_dev);
if (ret)
return ret;
reinit_completion(&adc->completion);
if (lradc->soc == IMX28_LRADC)
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(0x1, adc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
if (test_bit(chan, &adc->is_divided))
writel(1 << LRADC_CTRL2_DIVIDE_BY_TWO_OFFSET,
adc->base + LRADC_CTRL2 + STMP_OFFSET_REG_SET);
else
writel(1 << LRADC_CTRL2_DIVIDE_BY_TWO_OFFSET,
adc->base + LRADC_CTRL2 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL4_LRADCSELECT_MASK(0),
adc->base + LRADC_CTRL4 + STMP_OFFSET_REG_CLR);
writel(chan, adc->base + LRADC_CTRL4 + STMP_OFFSET_REG_SET);
writel(0, adc->base + LRADC_CH(0));
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
writel(BIT(0), adc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
ret = wait_for_completion_killable_timeout(&adc->completion, HZ);
if (!ret)
ret = -ETIMEDOUT;
if (ret < 0)
goto err;
*val = readl(adc->base + LRADC_CH(0)) & LRADC_CH_VALUE_MASK;
ret = IIO_VAL_INT;
err:
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
iio_device_release_direct_mode(iio_dev);
return ret;
}
static int mxs_lradc_adc_read_temp(struct iio_dev *iio_dev, int *val)
{
int ret, min, max;
ret = mxs_lradc_adc_read_single(iio_dev, 8, &min);
if (ret != IIO_VAL_INT)
return ret;
ret = mxs_lradc_adc_read_single(iio_dev, 9, &max);
if (ret != IIO_VAL_INT)
return ret;
*val = max - min;
return IIO_VAL_INT;
}
static int mxs_lradc_adc_read_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long m)
{
struct mxs_lradc_adc *adc = iio_priv(iio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_TEMP)
return mxs_lradc_adc_read_temp(iio_dev, val);
return mxs_lradc_adc_read_single(iio_dev, chan->channel, val);
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_TEMP) {
*val = 0;
*val2 = 253000;
return IIO_VAL_INT_PLUS_MICRO;
}
*val = adc->vref_mv[chan->channel];
*val2 = chan->scan_type.realbits -
test_bit(chan->channel, &adc->is_divided);
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_OFFSET:
if (chan->type == IIO_TEMP) {
*val = -1079;
*val2 = 644268;
return IIO_VAL_INT_PLUS_MICRO;
}
return -EINVAL;
default:
break;
}
return -EINVAL;
}
static int mxs_lradc_adc_write_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int val, int val2, long m)
{
struct mxs_lradc_adc *adc = iio_priv(iio_dev);
struct mxs_lradc_scale *scale_avail =
adc->scale_avail[chan->channel];
int ret;
ret = iio_device_claim_direct_mode(iio_dev);
if (ret)
return ret;
switch (m) {
case IIO_CHAN_INFO_SCALE:
ret = -EINVAL;
if (val == scale_avail[MXS_LRADC_DIV_DISABLED].integer &&
val2 == scale_avail[MXS_LRADC_DIV_DISABLED].nano) {
clear_bit(chan->channel, &adc->is_divided);
ret = 0;
} else if (val == scale_avail[MXS_LRADC_DIV_ENABLED].integer &&
val2 == scale_avail[MXS_LRADC_DIV_ENABLED].nano) {
set_bit(chan->channel, &adc->is_divided);
ret = 0;
}
break;
default:
ret = -EINVAL;
break;
}
iio_device_release_direct_mode(iio_dev);
return ret;
}
static int mxs_lradc_adc_write_raw_get_fmt(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
long m)
{
return IIO_VAL_INT_PLUS_NANO;
}
static ssize_t mxs_lradc_adc_show_scale_avail(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *iio = dev_to_iio_dev(dev);
struct mxs_lradc_adc *adc = iio_priv(iio);
struct iio_dev_attr *iio_attr = to_iio_dev_attr(attr);
int i, ch, len = 0;
ch = iio_attr->address;
for (i = 0; i < ARRAY_SIZE(adc->scale_avail[ch]); i++)
len += sprintf(buf + len, "%u.%09u ",
adc->scale_avail[ch][i].integer,
adc->scale_avail[ch][i].nano);
len += sprintf(buf + len, "\n");
return len;
}
static irqreturn_t mxs_lradc_adc_handle_irq(int irq, void *data)
{
struct iio_dev *iio = data;
struct mxs_lradc_adc *adc = iio_priv(iio);
struct mxs_lradc *lradc = adc->lradc;
unsigned long reg = readl(adc->base + LRADC_CTRL1);
unsigned long flags;
if (!(reg & mxs_lradc_irq_mask(lradc)))
return IRQ_NONE;
if (iio_buffer_enabled(iio)) {
if (reg & lradc->buffer_vchans) {
spin_lock_irqsave(&adc->lock, flags);
iio_trigger_poll(iio->trig);
spin_unlock_irqrestore(&adc->lock, flags);
}
} else if (reg & LRADC_CTRL1_LRADC_IRQ(0)) {
complete(&adc->completion);
}
writel(reg & mxs_lradc_irq_mask(lradc),
adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
return IRQ_HANDLED;
}
static irqreturn_t mxs_lradc_adc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *iio = pf->indio_dev;
struct mxs_lradc_adc *adc = iio_priv(iio);
const u32 chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
unsigned int i, j = 0;
for_each_set_bit(i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
adc->buffer[j] = readl(adc->base + LRADC_CH(j));
writel(chan_value, adc->base + LRADC_CH(j));
adc->buffer[j] &= LRADC_CH_VALUE_MASK;
adc->buffer[j] /= LRADC_DELAY_TIMER_LOOP;
j++;
}
iio_push_to_buffers_with_timestamp(iio, adc->buffer, pf->timestamp);
iio_trigger_notify_done(iio->trig);
return IRQ_HANDLED;
}
static int mxs_lradc_adc_configure_trigger(struct iio_trigger *trig, bool state)
{
struct iio_dev *iio = iio_trigger_get_drvdata(trig);
struct mxs_lradc_adc *adc = iio_priv(iio);
const u32 st = state ? STMP_OFFSET_REG_SET : STMP_OFFSET_REG_CLR;
writel(LRADC_DELAY_KICK, adc->base + (LRADC_DELAY(0) + st));
return 0;
}
static int mxs_lradc_adc_trigger_init(struct iio_dev *iio)
{
int ret;
struct iio_trigger *trig;
struct mxs_lradc_adc *adc = iio_priv(iio);
trig = devm_iio_trigger_alloc(&iio->dev, "%s-dev%i", iio->name,
iio->id);
trig->dev.parent = adc->dev;
iio_trigger_set_drvdata(trig, iio);
trig->ops = &mxs_lradc_adc_trigger_ops;
ret = iio_trigger_register(trig);
if (ret)
return ret;
adc->trig = trig;
return 0;
}
static void mxs_lradc_adc_trigger_remove(struct iio_dev *iio)
{
struct mxs_lradc_adc *adc = iio_priv(iio);
iio_trigger_unregister(adc->trig);
}
static int mxs_lradc_adc_buffer_preenable(struct iio_dev *iio)
{
struct mxs_lradc_adc *adc = iio_priv(iio);
struct mxs_lradc *lradc = adc->lradc;
int chan, ofs = 0;
unsigned long enable = 0;
u32 ctrl4_set = 0;
u32 ctrl4_clr = 0;
u32 ctrl1_irq = 0;
const u32 chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
if (lradc->soc == IMX28_LRADC)
writel(lradc->buffer_vchans << LRADC_CTRL1_LRADC_IRQ_EN_OFFSET,
adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(lradc->buffer_vchans,
adc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
for_each_set_bit(chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
ctrl4_set |= chan << LRADC_CTRL4_LRADCSELECT_OFFSET(ofs);
ctrl4_clr |= LRADC_CTRL4_LRADCSELECT_MASK(ofs);
ctrl1_irq |= LRADC_CTRL1_LRADC_IRQ_EN(ofs);
writel(chan_value, adc->base + LRADC_CH(ofs));
bitmap_set(&enable, ofs, 1);
ofs++;
}
writel(LRADC_DELAY_TRIGGER_LRADCS_MASK | LRADC_DELAY_KICK,
adc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_CLR);
writel(ctrl4_clr, adc->base + LRADC_CTRL4 + STMP_OFFSET_REG_CLR);
writel(ctrl4_set, adc->base + LRADC_CTRL4 + STMP_OFFSET_REG_SET);
writel(ctrl1_irq, adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
writel(enable << LRADC_DELAY_TRIGGER_LRADCS_OFFSET,
adc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_SET);
return 0;
}
static int mxs_lradc_adc_buffer_postdisable(struct iio_dev *iio)
{
struct mxs_lradc_adc *adc = iio_priv(iio);
struct mxs_lradc *lradc = adc->lradc;
writel(LRADC_DELAY_TRIGGER_LRADCS_MASK | LRADC_DELAY_KICK,
adc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_CLR);
writel(lradc->buffer_vchans,
adc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
if (lradc->soc == IMX28_LRADC)
writel(lradc->buffer_vchans << LRADC_CTRL1_LRADC_IRQ_EN_OFFSET,
adc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
return 0;
}
static bool mxs_lradc_adc_validate_scan_mask(struct iio_dev *iio,
const unsigned long *mask)
{
struct mxs_lradc_adc *adc = iio_priv(iio);
struct mxs_lradc *lradc = adc->lradc;
const int map_chans = bitmap_weight(mask, LRADC_MAX_TOTAL_CHANS);
int rsvd_chans = 0;
unsigned long rsvd_mask = 0;
if (lradc->use_touchbutton)
rsvd_mask |= CHAN_MASK_TOUCHBUTTON;
if (lradc->touchscreen_wire == MXS_LRADC_TOUCHSCREEN_4WIRE)
rsvd_mask |= CHAN_MASK_TOUCHSCREEN_4WIRE;
if (lradc->touchscreen_wire == MXS_LRADC_TOUCHSCREEN_5WIRE)
rsvd_mask |= CHAN_MASK_TOUCHSCREEN_5WIRE;
if (lradc->use_touchbutton)
rsvd_chans++;
if (lradc->touchscreen_wire)
rsvd_chans += 2;
if (bitmap_intersects(mask, &rsvd_mask, LRADC_MAX_TOTAL_CHANS))
return false;
if (map_chans + rsvd_chans > LRADC_MAX_MAPPED_CHANS)
return false;
return true;
}
static void mxs_lradc_adc_hw_init(struct mxs_lradc_adc *adc)
{
const u32 adc_cfg =
(1 << (LRADC_DELAY_TRIGGER_DELAYS_OFFSET + 0)) |
(LRADC_DELAY_TIMER_PER << LRADC_DELAY_DELAY_OFFSET);
writel(adc_cfg, adc->base + LRADC_DELAY(0));
writel(0, adc->base + LRADC_CTRL2);
}
static void mxs_lradc_adc_hw_stop(struct mxs_lradc_adc *adc)
{
writel(0, adc->base + LRADC_DELAY(0));
}
static int mxs_lradc_adc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mxs_lradc *lradc = dev_get_drvdata(dev->parent);
struct mxs_lradc_adc *adc;
struct iio_dev *iio;
struct resource *iores;
int ret, irq, virq, i, s, n;
u64 scale_uv;
const char **irq_name;
iio = devm_iio_device_alloc(dev, sizeof(*adc));
if (!iio) {
dev_err(dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
adc = iio_priv(iio);
adc->lradc = lradc;
adc->dev = dev;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -EINVAL;
adc->base = devm_ioremap(dev, iores->start, resource_size(iores));
if (!adc->base)
return -ENOMEM;
init_completion(&adc->completion);
spin_lock_init(&adc->lock);
platform_set_drvdata(pdev, iio);
iio->name = pdev->name;
iio->dev.parent = dev;
iio->dev.of_node = dev->parent->of_node;
iio->info = &mxs_lradc_adc_iio_info;
iio->modes = INDIO_DIRECT_MODE;
iio->masklength = LRADC_MAX_TOTAL_CHANS;
if (lradc->soc == IMX23_LRADC) {
iio->channels = mx23_lradc_chan_spec;
iio->num_channels = ARRAY_SIZE(mx23_lradc_chan_spec);
irq_name = mx23_lradc_adc_irq_names;
n = ARRAY_SIZE(mx23_lradc_adc_irq_names);
} else {
iio->channels = mx28_lradc_chan_spec;
iio->num_channels = ARRAY_SIZE(mx28_lradc_chan_spec);
irq_name = mx28_lradc_adc_irq_names;
n = ARRAY_SIZE(mx28_lradc_adc_irq_names);
}
ret = stmp_reset_block(adc->base);
if (ret)
return ret;
for (i = 0; i < n; i++) {
irq = platform_get_irq_byname(pdev, irq_name[i]);
if (irq < 0)
return irq;
virq = irq_of_parse_and_map(dev->parent->of_node, irq);
ret = devm_request_irq(dev, virq, mxs_lradc_adc_handle_irq,
0, irq_name[i], iio);
if (ret)
return ret;
}
ret = mxs_lradc_adc_trigger_init(iio);
if (ret)
goto err_trig;
ret = iio_triggered_buffer_setup(iio, &iio_pollfunc_store_time,
&mxs_lradc_adc_trigger_handler,
&mxs_lradc_adc_buffer_ops);
if (ret)
return ret;
adc->vref_mv = mxs_lradc_adc_vref_mv[lradc->soc];
for (i = 0; i < LRADC_MAX_TOTAL_CHANS; i++) {
for (s = 0; s < ARRAY_SIZE(adc->scale_avail[i]); s++) {
scale_uv = ((u64)adc->vref_mv[i] * 100000000) >>
(LRADC_RESOLUTION - s);
adc->scale_avail[i][s].nano =
do_div(scale_uv, 100000000) * 10;
adc->scale_avail[i][s].integer = scale_uv;
}
}
mxs_lradc_adc_hw_init(adc);
ret = iio_device_register(iio);
if (ret) {
dev_err(dev, "Failed to register IIO device\n");
goto err_dev;
}
return 0;
err_dev:
mxs_lradc_adc_hw_stop(adc);
mxs_lradc_adc_trigger_remove(iio);
err_trig:
iio_triggered_buffer_cleanup(iio);
return ret;
}
static int mxs_lradc_adc_remove(struct platform_device *pdev)
{
struct iio_dev *iio = platform_get_drvdata(pdev);
struct mxs_lradc_adc *adc = iio_priv(iio);
iio_device_unregister(iio);
mxs_lradc_adc_hw_stop(adc);
mxs_lradc_adc_trigger_remove(iio);
iio_triggered_buffer_cleanup(iio);
return 0;
}
