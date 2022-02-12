static int mxs_lradc_read_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long m)
{
struct mxs_lradc *lradc = iio_priv(iio_dev);
int ret;
if (m != IIO_CHAN_INFO_RAW)
return -EINVAL;
if (chan->channel > LRADC_MAX_TOTAL_CHANS)
return -EINVAL;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
INIT_COMPLETION(lradc->completion);
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(0xff, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL4_LRADCSELECT_MASK(0),
lradc->base + LRADC_CTRL4 + STMP_OFFSET_REG_CLR);
writel(chan->channel, lradc->base + LRADC_CTRL4 + STMP_OFFSET_REG_SET);
writel(0, lradc->base + LRADC_CH(0));
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
writel(1 << 0, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
ret = wait_for_completion_killable_timeout(&lradc->completion, HZ);
if (!ret)
ret = -ETIMEDOUT;
if (ret < 0)
goto err;
*val = readl(lradc->base + LRADC_CH(0)) & LRADC_CH_VALUE_MASK;
ret = IIO_VAL_INT;
err:
writel(LRADC_CTRL1_LRADC_IRQ_EN(0),
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
mutex_unlock(&lradc->lock);
return ret;
}
static int mxs_lradc_ts_touched(struct mxs_lradc *lradc)
{
uint32_t reg;
writel(LRADC_CTRL0_PLATE_MASK,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL0_TOUCH_DETECT_ENABLE,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
msleep(LRADC_TS_SAMPLE_DELAY_MS);
reg = readl(lradc->base + LRADC_STATUS);
return reg & LRADC_STATUS_TOUCH_DETECT_RAW;
}
static int32_t mxs_lradc_ts_sample(struct mxs_lradc *lradc,
enum lradc_ts_plate plate, int change)
{
unsigned long delay, jiff;
uint32_t reg, ctrl0 = 0, chan = 0;
const uint8_t slot = 7;
uint32_t val;
switch (plate) {
case LRADC_SAMPLE_X:
ctrl0 = LRADC_CTRL0_XPPSW | LRADC_CTRL0_XNNSW;
chan = 3;
break;
case LRADC_SAMPLE_Y:
ctrl0 = LRADC_CTRL0_YPPSW | LRADC_CTRL0_YNNSW;
chan = 4;
break;
case LRADC_SAMPLE_PRESSURE:
ctrl0 = LRADC_CTRL0_YPPSW | LRADC_CTRL0_XNNSW;
chan = 5;
break;
}
if (change) {
writel(LRADC_CTRL0_PLATE_MASK,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
writel(ctrl0, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
writel(LRADC_CTRL4_LRADCSELECT_MASK(slot),
lradc->base + LRADC_CTRL4 + STMP_OFFSET_REG_CLR);
writel(chan << LRADC_CTRL4_LRADCSELECT_OFFSET(slot),
lradc->base + LRADC_CTRL4 + STMP_OFFSET_REG_SET);
}
writel(0xffffffff, lradc->base + LRADC_CH(slot) + STMP_OFFSET_REG_CLR);
writel(1 << slot, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
delay = jiffies + msecs_to_jiffies(LRADC_TS_SAMPLE_DELAY_MS);
do {
jiff = jiffies;
reg = readl_relaxed(lradc->base + LRADC_CTRL1);
if (reg & LRADC_CTRL1_LRADC_IRQ(slot))
break;
} while (time_before(jiff, delay));
writel(LRADC_CTRL1_LRADC_IRQ(slot),
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
if (time_after_eq(jiff, delay))
return -ETIMEDOUT;
val = readl(lradc->base + LRADC_CH(slot));
val &= LRADC_CH_VALUE_MASK;
return val;
}
static int32_t mxs_lradc_ts_sample_filter(struct mxs_lradc *lradc,
enum lradc_ts_plate plate)
{
int32_t val, tot = 0;
int i;
val = mxs_lradc_ts_sample(lradc, plate, 1);
mdelay(2);
for (i = 0; i < LRADC_TS_SAMPLE_AMOUNT; i++) {
val = mxs_lradc_ts_sample(lradc, plate, 0);
tot += val;
}
return tot / LRADC_TS_SAMPLE_AMOUNT;
}
static void mxs_lradc_ts_work(struct work_struct *ts_work)
{
struct mxs_lradc *lradc = container_of(ts_work,
struct mxs_lradc, ts_work);
int val_x, val_y, val_p;
bool valid = false;
while (mxs_lradc_ts_touched(lradc)) {
writel(LRADC_CTRL0_TOUCH_DETECT_ENABLE,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
if (likely(valid)) {
input_report_abs(lradc->ts_input, ABS_X, val_x);
input_report_abs(lradc->ts_input, ABS_Y, val_y);
input_report_abs(lradc->ts_input, ABS_PRESSURE, val_p);
input_report_key(lradc->ts_input, BTN_TOUCH, 1);
input_sync(lradc->ts_input);
}
valid = false;
val_x = mxs_lradc_ts_sample_filter(lradc, LRADC_SAMPLE_X);
if (val_x < 0)
continue;
val_y = mxs_lradc_ts_sample_filter(lradc, LRADC_SAMPLE_Y);
if (val_y < 0)
continue;
val_p = mxs_lradc_ts_sample_filter(lradc, LRADC_SAMPLE_PRESSURE);
if (val_p < 0)
continue;
valid = true;
}
input_report_abs(lradc->ts_input, ABS_PRESSURE, 0);
input_report_key(lradc->ts_input, BTN_TOUCH, 0);
input_sync(lradc->ts_input);
if (lradc->stop_touchscreen)
return;
writel(LRADC_CTRL1_TOUCH_DETECT_IRQ,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL1_TOUCH_DETECT_IRQ_EN,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
}
static int mxs_lradc_ts_open(struct input_dev *dev)
{
struct mxs_lradc *lradc = input_get_drvdata(dev);
lradc->stop_touchscreen = false;
writel(LRADC_CTRL0_TOUCH_DETECT_ENABLE,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
writel(LRADC_CTRL1_TOUCH_DETECT_IRQ_EN,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
return 0;
}
static void mxs_lradc_ts_close(struct input_dev *dev)
{
struct mxs_lradc *lradc = input_get_drvdata(dev);
lradc->stop_touchscreen = true;
mb();
cancel_work_sync(&lradc->ts_work);
writel(LRADC_CTRL1_TOUCH_DETECT_IRQ_EN,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL0_TOUCH_DETECT_ENABLE,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
}
static int mxs_lradc_ts_register(struct mxs_lradc *lradc)
{
struct input_dev *input;
struct device *dev = lradc->dev;
int ret;
if (!lradc->use_touchscreen)
return 0;
input = input_allocate_device();
if (!input) {
dev_err(dev, "Failed to allocate TS device!\n");
return -ENOMEM;
}
input->name = DRIVER_NAME;
input->id.bustype = BUS_HOST;
input->dev.parent = dev;
input->open = mxs_lradc_ts_open;
input->close = mxs_lradc_ts_close;
__set_bit(EV_ABS, input->evbit);
__set_bit(EV_KEY, input->evbit);
__set_bit(BTN_TOUCH, input->keybit);
input_set_abs_params(input, ABS_X, 0, LRADC_SINGLE_SAMPLE_MASK, 0, 0);
input_set_abs_params(input, ABS_Y, 0, LRADC_SINGLE_SAMPLE_MASK, 0, 0);
input_set_abs_params(input, ABS_PRESSURE, 0, LRADC_SINGLE_SAMPLE_MASK,
0, 0);
lradc->ts_input = input;
input_set_drvdata(input, lradc);
ret = input_register_device(input);
if (ret)
input_free_device(lradc->ts_input);
return ret;
}
static void mxs_lradc_ts_unregister(struct mxs_lradc *lradc)
{
if (!lradc->use_touchscreen)
return;
cancel_work_sync(&lradc->ts_work);
input_unregister_device(lradc->ts_input);
}
static irqreturn_t mxs_lradc_handle_irq(int irq, void *data)
{
struct iio_dev *iio = data;
struct mxs_lradc *lradc = iio_priv(iio);
unsigned long reg = readl(lradc->base + LRADC_CTRL1);
const uint32_t ts_irq_mask =
LRADC_CTRL1_TOUCH_DETECT_IRQ_EN |
LRADC_CTRL1_TOUCH_DETECT_IRQ;
if (!(reg & LRADC_CTRL1_LRADC_IRQ_MASK))
return IRQ_NONE;
if (reg & LRADC_CTRL1_TOUCH_DETECT_IRQ) {
writel(ts_irq_mask,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
if (!lradc->stop_touchscreen)
schedule_work(&lradc->ts_work);
}
if (iio_buffer_enabled(iio))
iio_trigger_poll(iio->trig, iio_get_time_ns());
else if (reg & LRADC_CTRL1_LRADC_IRQ(0))
complete(&lradc->completion);
writel(reg & LRADC_CTRL1_LRADC_IRQ_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
return IRQ_HANDLED;
}
static irqreturn_t mxs_lradc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *iio = pf->indio_dev;
struct mxs_lradc *lradc = iio_priv(iio);
const uint32_t chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
unsigned int i, j = 0;
for_each_set_bit(i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
lradc->buffer[j] = readl(lradc->base + LRADC_CH(j));
writel(chan_value, lradc->base + LRADC_CH(j));
lradc->buffer[j] &= LRADC_CH_VALUE_MASK;
lradc->buffer[j] /= LRADC_DELAY_TIMER_LOOP;
j++;
}
if (iio->scan_timestamp) {
s64 *timestamp = (s64 *)((u8 *)lradc->buffer +
ALIGN(j, sizeof(s64)));
*timestamp = pf->timestamp;
}
iio_push_to_buffers(iio, (u8 *)lradc->buffer);
iio_trigger_notify_done(iio->trig);
return IRQ_HANDLED;
}
static int mxs_lradc_configure_trigger(struct iio_trigger *trig, bool state)
{
struct iio_dev *iio = iio_trigger_get_drvdata(trig);
struct mxs_lradc *lradc = iio_priv(iio);
const uint32_t st = state ? STMP_OFFSET_REG_SET : STMP_OFFSET_REG_CLR;
writel(LRADC_DELAY_KICK, lradc->base + LRADC_DELAY(0) + st);
return 0;
}
static int mxs_lradc_trigger_init(struct iio_dev *iio)
{
int ret;
struct iio_trigger *trig;
struct mxs_lradc *lradc = iio_priv(iio);
trig = iio_trigger_alloc("%s-dev%i", iio->name, iio->id);
if (trig == NULL)
return -ENOMEM;
trig->dev.parent = lradc->dev;
iio_trigger_set_drvdata(trig, iio);
trig->ops = &mxs_lradc_trigger_ops;
ret = iio_trigger_register(trig);
if (ret) {
iio_trigger_free(trig);
return ret;
}
lradc->trig = trig;
return 0;
}
static void mxs_lradc_trigger_remove(struct iio_dev *iio)
{
struct mxs_lradc *lradc = iio_priv(iio);
iio_trigger_unregister(lradc->trig);
iio_trigger_free(lradc->trig);
}
static int mxs_lradc_buffer_preenable(struct iio_dev *iio)
{
struct mxs_lradc *lradc = iio_priv(iio);
int ret = 0, chan, ofs = 0;
unsigned long enable = 0;
uint32_t ctrl4_set = 0;
uint32_t ctrl4_clr = 0;
uint32_t ctrl1_irq = 0;
const uint32_t chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
const int len = bitmap_weight(iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS);
if (!len)
return -EINVAL;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
lradc->buffer = kmalloc(len * sizeof(*lradc->buffer), GFP_KERNEL);
if (!lradc->buffer) {
ret = -ENOMEM;
goto err_mem;
}
ret = iio_sw_buffer_preenable(iio);
if (ret < 0)
goto err_buf;
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
writel(0xff, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
for_each_set_bit(chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
ctrl4_set |= chan << LRADC_CTRL4_LRADCSELECT_OFFSET(ofs);
ctrl4_clr |= LRADC_CTRL4_LRADCSELECT_MASK(ofs);
ctrl1_irq |= LRADC_CTRL1_LRADC_IRQ_EN(ofs);
writel(chan_value, lradc->base + LRADC_CH(ofs));
bitmap_set(&enable, ofs, 1);
ofs++;
}
writel(LRADC_DELAY_TRIGGER_LRADCS_MASK | LRADC_DELAY_KICK,
lradc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_CLR);
writel(ctrl4_clr, lradc->base + LRADC_CTRL4 + STMP_OFFSET_REG_CLR);
writel(ctrl4_set, lradc->base + LRADC_CTRL4 + STMP_OFFSET_REG_SET);
writel(ctrl1_irq, lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_SET);
writel(enable << LRADC_DELAY_TRIGGER_LRADCS_OFFSET,
lradc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_SET);
return 0;
err_buf:
kfree(lradc->buffer);
err_mem:
mutex_unlock(&lradc->lock);
return ret;
}
static int mxs_lradc_buffer_postdisable(struct iio_dev *iio)
{
struct mxs_lradc *lradc = iio_priv(iio);
writel(LRADC_DELAY_TRIGGER_LRADCS_MASK | LRADC_DELAY_KICK,
lradc->base + LRADC_DELAY(0) + STMP_OFFSET_REG_CLR);
writel(0xff, lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
kfree(lradc->buffer);
mutex_unlock(&lradc->lock);
return 0;
}
static bool mxs_lradc_validate_scan_mask(struct iio_dev *iio,
const unsigned long *mask)
{
struct mxs_lradc *lradc = iio_priv(iio);
const int map_chans = bitmap_weight(mask, LRADC_MAX_TOTAL_CHANS);
int rsvd_chans = 0;
unsigned long rsvd_mask = 0;
if (lradc->use_touchbutton)
rsvd_mask |= CHAN_MASK_TOUCHBUTTON;
if (lradc->use_touchscreen == MXS_LRADC_TOUCHSCREEN_4WIRE)
rsvd_mask |= CHAN_MASK_TOUCHSCREEN_4WIRE;
if (lradc->use_touchscreen == MXS_LRADC_TOUCHSCREEN_5WIRE)
rsvd_mask |= CHAN_MASK_TOUCHSCREEN_5WIRE;
if (lradc->use_touchbutton)
rsvd_chans++;
if (lradc->use_touchscreen)
rsvd_chans++;
if (bitmap_intersects(mask, &rsvd_mask, LRADC_MAX_TOTAL_CHANS))
return false;
if (map_chans + rsvd_chans > LRADC_MAX_MAPPED_CHANS)
return false;
return true;
}
static int mxs_lradc_hw_init(struct mxs_lradc *lradc)
{
const uint32_t adc_cfg =
(1 << (LRADC_DELAY_TRIGGER_DELAYS_OFFSET + 0)) |
(LRADC_DELAY_TIMER_PER << LRADC_DELAY_DELAY_OFFSET);
int ret = stmp_reset_block(lradc->base);
if (ret)
return ret;
writel(adc_cfg, lradc->base + LRADC_DELAY(0));
writel(0, lradc->base + LRADC_DELAY(1));
writel(0, lradc->base + LRADC_DELAY(2));
writel(0, lradc->base + LRADC_DELAY(3));
writel(LRADC_CTRL0_TOUCH_SCREEN_TYPE,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_CLR);
if (lradc->use_touchscreen == MXS_LRADC_TOUCHSCREEN_5WIRE) {
writel(LRADC_CTRL0_TOUCH_SCREEN_TYPE,
lradc->base + LRADC_CTRL0 + STMP_OFFSET_REG_SET);
}
writel(0, lradc->base + LRADC_CTRL2);
return 0;
}
static void mxs_lradc_hw_stop(struct mxs_lradc *lradc)
{
int i;
writel(LRADC_CTRL1_LRADC_IRQ_EN_MASK,
lradc->base + LRADC_CTRL1 + STMP_OFFSET_REG_CLR);
for (i = 0; i < LRADC_MAX_DELAY_CHANS; i++)
writel(0, lradc->base + LRADC_DELAY(i));
}
static int mxs_lradc_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(mxs_lradc_dt_ids, &pdev->dev);
const struct mxs_lradc_of_config *of_cfg =
&mxs_lradc_of_config[(enum mxs_lradc_id)of_id->data];
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct mxs_lradc *lradc;
struct iio_dev *iio;
struct resource *iores;
uint32_t ts_wires = 0;
int ret = 0;
int i;
iio = devm_iio_device_alloc(dev, sizeof(*lradc));
if (!iio) {
dev_err(dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
lradc = iio_priv(iio);
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lradc->dev = &pdev->dev;
lradc->base = devm_ioremap_resource(dev, iores);
if (IS_ERR(lradc->base))
return PTR_ERR(lradc->base);
INIT_WORK(&lradc->ts_work, mxs_lradc_ts_work);
ret = of_property_read_u32(node, "fsl,lradc-touchscreen-wires",
&ts_wires);
if (ret)
dev_info(dev, "Touchscreen not enabled.\n");
else if (ts_wires == 4)
lradc->use_touchscreen = MXS_LRADC_TOUCHSCREEN_4WIRE;
else if (ts_wires == 5)
lradc->use_touchscreen = MXS_LRADC_TOUCHSCREEN_5WIRE;
else
dev_warn(dev, "Unsupported number of touchscreen wires (%d)\n",
ts_wires);
for (i = 0; i < of_cfg->irq_count; i++) {
lradc->irq[i] = platform_get_irq(pdev, i);
if (lradc->irq[i] < 0)
return -EINVAL;
ret = devm_request_irq(dev, lradc->irq[i],
mxs_lradc_handle_irq, 0,
of_cfg->irq_name[i], iio);
if (ret)
return ret;
}
platform_set_drvdata(pdev, iio);
init_completion(&lradc->completion);
mutex_init(&lradc->lock);
iio->name = pdev->name;
iio->dev.parent = &pdev->dev;
iio->info = &mxs_lradc_iio_info;
iio->modes = INDIO_DIRECT_MODE;
iio->channels = mxs_lradc_chan_spec;
iio->num_channels = ARRAY_SIZE(mxs_lradc_chan_spec);
iio->masklength = LRADC_MAX_TOTAL_CHANS;
ret = iio_triggered_buffer_setup(iio, &iio_pollfunc_store_time,
&mxs_lradc_trigger_handler,
&mxs_lradc_buffer_ops);
if (ret)
return ret;
ret = mxs_lradc_trigger_init(iio);
if (ret)
goto err_trig;
ret = mxs_lradc_hw_init(lradc);
if (ret)
goto err_dev;
ret = mxs_lradc_ts_register(lradc);
if (ret)
goto err_dev;
ret = iio_device_register(iio);
if (ret) {
dev_err(dev, "Failed to register IIO device\n");
goto err_ts;
}
return 0;
err_ts:
mxs_lradc_ts_unregister(lradc);
err_dev:
mxs_lradc_trigger_remove(iio);
err_trig:
iio_triggered_buffer_cleanup(iio);
return ret;
}
static int mxs_lradc_remove(struct platform_device *pdev)
{
struct iio_dev *iio = platform_get_drvdata(pdev);
struct mxs_lradc *lradc = iio_priv(iio);
mxs_lradc_ts_unregister(lradc);
mxs_lradc_hw_stop(lradc);
iio_device_unregister(iio);
iio_triggered_buffer_cleanup(iio);
mxs_lradc_trigger_remove(iio);
return 0;
}
