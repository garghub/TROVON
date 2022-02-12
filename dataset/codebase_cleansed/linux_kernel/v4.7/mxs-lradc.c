static void mxs_lradc_reg_set(struct mxs_lradc *lradc, u32 val, u32 reg)
{
writel(val, lradc->base + reg + STMP_OFFSET_REG_SET);
}
static void mxs_lradc_reg_clear(struct mxs_lradc *lradc, u32 val, u32 reg)
{
writel(val, lradc->base + reg + STMP_OFFSET_REG_CLR);
}
static void mxs_lradc_reg_wrt(struct mxs_lradc *lradc, u32 val, u32 reg)
{
writel(val, lradc->base + reg);
}
static u32 mxs_lradc_plate_mask(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL0_MX23_PLATE_MASK;
return LRADC_CTRL0_MX28_PLATE_MASK;
}
static u32 mxs_lradc_irq_en_mask(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL1_MX23_LRADC_IRQ_EN_MASK;
return LRADC_CTRL1_MX28_LRADC_IRQ_EN_MASK;
}
static u32 mxs_lradc_irq_mask(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL1_MX23_LRADC_IRQ_MASK;
return LRADC_CTRL1_MX28_LRADC_IRQ_MASK;
}
static u32 mxs_lradc_touch_detect_bit(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL0_MX23_TOUCH_DETECT_ENABLE;
return LRADC_CTRL0_MX28_TOUCH_DETECT_ENABLE;
}
static u32 mxs_lradc_drive_x_plate(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL0_MX23_XP | LRADC_CTRL0_MX23_XM;
return LRADC_CTRL0_MX28_XPPSW | LRADC_CTRL0_MX28_XNNSW;
}
static u32 mxs_lradc_drive_y_plate(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL0_MX23_YP | LRADC_CTRL0_MX23_YM;
return LRADC_CTRL0_MX28_YPPSW | LRADC_CTRL0_MX28_YNNSW;
}
static u32 mxs_lradc_drive_pressure(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX23_LRADC)
return LRADC_CTRL0_MX23_YP | LRADC_CTRL0_MX23_XM;
return LRADC_CTRL0_MX28_YPPSW | LRADC_CTRL0_MX28_XNNSW;
}
static bool mxs_lradc_check_touch_event(struct mxs_lradc *lradc)
{
return !!(readl(lradc->base + LRADC_STATUS) &
LRADC_STATUS_TOUCH_DETECT_RAW);
}
static void mxs_lradc_map_channel(struct mxs_lradc *lradc, unsigned vch,
unsigned ch)
{
mxs_lradc_reg_clear(lradc, LRADC_CTRL4_LRADCSELECT_MASK(vch),
LRADC_CTRL4);
mxs_lradc_reg_set(lradc, LRADC_CTRL4_LRADCSELECT(vch, ch), LRADC_CTRL4);
}
static void mxs_lradc_setup_ts_channel(struct mxs_lradc *lradc, unsigned ch)
{
mxs_lradc_reg_wrt(lradc, LRADC_CH_ACCUMULATE |
LRADC_CH_NUM_SAMPLES(lradc->over_sample_cnt - 1),
LRADC_CH(ch));
mxs_lradc_reg_clear(lradc, LRADC_CH_VALUE_MASK, LRADC_CH(ch));
mxs_lradc_reg_wrt(lradc, LRADC_DELAY_TRIGGER(1 << ch) |
LRADC_DELAY_TRIGGER_DELAYS(0) |
LRADC_DELAY_LOOP(lradc->over_sample_cnt - 1) |
LRADC_DELAY_DELAY(lradc->over_sample_delay - 1),
LRADC_DELAY(3));
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_LRADC_IRQ(ch), LRADC_CTRL1);
mxs_lradc_reg_wrt(
lradc,
LRADC_DELAY_TRIGGER(0) |
LRADC_DELAY_TRIGGER_DELAYS(BIT(3)) |
LRADC_DELAY_KICK |
LRADC_DELAY_DELAY(lradc->settling_delay),
LRADC_DELAY(2));
}
static void mxs_lradc_setup_ts_pressure(struct mxs_lradc *lradc, unsigned ch1,
unsigned ch2)
{
u32 reg;
reg = LRADC_CH_ACCUMULATE |
LRADC_CH_NUM_SAMPLES(lradc->over_sample_cnt - 1);
mxs_lradc_reg_wrt(lradc, reg, LRADC_CH(ch1));
mxs_lradc_reg_wrt(lradc, reg, LRADC_CH(ch2));
mxs_lradc_reg_clear(lradc, LRADC_CH_VALUE_MASK, LRADC_CH(ch1));
mxs_lradc_reg_clear(lradc, LRADC_CH_VALUE_MASK, LRADC_CH(ch2));
mxs_lradc_reg_wrt(
lradc,
LRADC_DELAY_TRIGGER(1 << ch1) |
LRADC_DELAY_TRIGGER(1 << ch2) |
LRADC_DELAY_TRIGGER_DELAYS(0) |
LRADC_DELAY_LOOP(lradc->over_sample_cnt - 1) |
LRADC_DELAY_DELAY(lradc->over_sample_delay - 1),
LRADC_DELAY(3));
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_LRADC_IRQ(ch2), LRADC_CTRL1);
mxs_lradc_reg_wrt(
lradc,
LRADC_DELAY_TRIGGER(0) |
LRADC_DELAY_TRIGGER_DELAYS(BIT(3)) |
LRADC_DELAY_KICK |
LRADC_DELAY_DELAY(lradc->settling_delay), LRADC_DELAY(2));
}
static unsigned mxs_lradc_read_raw_channel(struct mxs_lradc *lradc,
unsigned channel)
{
u32 reg;
unsigned num_samples, val;
reg = readl(lradc->base + LRADC_CH(channel));
if (reg & LRADC_CH_ACCUMULATE)
num_samples = lradc->over_sample_cnt;
else
num_samples = 1;
val = (reg & LRADC_CH_VALUE_MASK) >> LRADC_CH_VALUE_OFFSET;
return val / num_samples;
}
static unsigned mxs_lradc_read_ts_pressure(struct mxs_lradc *lradc,
unsigned ch1, unsigned ch2)
{
u32 reg, mask;
unsigned pressure, m1, m2;
mask = LRADC_CTRL1_LRADC_IRQ(ch1) | LRADC_CTRL1_LRADC_IRQ(ch2);
reg = readl(lradc->base + LRADC_CTRL1) & mask;
while (reg != mask) {
reg = readl(lradc->base + LRADC_CTRL1) & mask;
dev_dbg(lradc->dev, "One channel is still busy: %X\n", reg);
}
m1 = mxs_lradc_read_raw_channel(lradc, ch1);
m2 = mxs_lradc_read_raw_channel(lradc, ch2);
if (m2 == 0) {
dev_warn(lradc->dev, "Cannot calculate pressure\n");
return 1 << (LRADC_RESOLUTION - 1);
}
pressure = m1;
pressure *= (1 << LRADC_RESOLUTION);
pressure /= m2;
dev_dbg(lradc->dev, "Pressure = %u\n", pressure);
return pressure;
}
static void mxs_lradc_setup_touch_detection(struct mxs_lradc *lradc)
{
mxs_lradc_reg_clear(lradc, mxs_lradc_plate_mask(lradc), LRADC_CTRL0);
mxs_lradc_reg_set(lradc, mxs_lradc_touch_detect_bit(lradc),
LRADC_CTRL0);
}
static void mxs_lradc_prepare_x_pos(struct mxs_lradc *lradc)
{
mxs_lradc_reg_clear(lradc, mxs_lradc_plate_mask(lradc), LRADC_CTRL0);
mxs_lradc_reg_set(lradc, mxs_lradc_drive_x_plate(lradc), LRADC_CTRL0);
lradc->cur_plate = LRADC_SAMPLE_X;
mxs_lradc_map_channel(lradc, TOUCHSCREEN_VCHANNEL1, TS_CH_YP);
mxs_lradc_setup_ts_channel(lradc, TOUCHSCREEN_VCHANNEL1);
}
static void mxs_lradc_prepare_y_pos(struct mxs_lradc *lradc)
{
mxs_lradc_reg_clear(lradc, mxs_lradc_plate_mask(lradc), LRADC_CTRL0);
mxs_lradc_reg_set(lradc, mxs_lradc_drive_y_plate(lradc), LRADC_CTRL0);
lradc->cur_plate = LRADC_SAMPLE_Y;
mxs_lradc_map_channel(lradc, TOUCHSCREEN_VCHANNEL1, TS_CH_XM);
mxs_lradc_setup_ts_channel(lradc, TOUCHSCREEN_VCHANNEL1);
}
static void mxs_lradc_prepare_pressure(struct mxs_lradc *lradc)
{
mxs_lradc_reg_clear(lradc, mxs_lradc_plate_mask(lradc), LRADC_CTRL0);
mxs_lradc_reg_set(lradc, mxs_lradc_drive_pressure(lradc), LRADC_CTRL0);
lradc->cur_plate = LRADC_SAMPLE_PRESSURE;
mxs_lradc_map_channel(lradc, TOUCHSCREEN_VCHANNEL1, TS_CH_YM);
mxs_lradc_map_channel(lradc, TOUCHSCREEN_VCHANNEL2, TS_CH_XP);
mxs_lradc_setup_ts_pressure(lradc, TOUCHSCREEN_VCHANNEL2,
TOUCHSCREEN_VCHANNEL1);
}
static void mxs_lradc_enable_touch_detection(struct mxs_lradc *lradc)
{
if (lradc->soc == IMX28_LRADC) {
mxs_lradc_reg_clear(lradc, LRADC_CTRL0_MX28_TOUCH_SCREEN_TYPE,
LRADC_CTRL0);
if (lradc->use_touchscreen == MXS_LRADC_TOUCHSCREEN_5WIRE)
mxs_lradc_reg_set(lradc,
LRADC_CTRL0_MX28_TOUCH_SCREEN_TYPE,
LRADC_CTRL0);
}
mxs_lradc_setup_touch_detection(lradc);
lradc->cur_plate = LRADC_TOUCH;
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_TOUCH_DETECT_IRQ |
LRADC_CTRL1_TOUCH_DETECT_IRQ_EN, LRADC_CTRL1);
mxs_lradc_reg_set(lradc, LRADC_CTRL1_TOUCH_DETECT_IRQ_EN, LRADC_CTRL1);
}
static void mxs_lradc_start_touch_event(struct mxs_lradc *lradc)
{
mxs_lradc_reg_clear(lradc,
LRADC_CTRL1_TOUCH_DETECT_IRQ_EN,
LRADC_CTRL1);
mxs_lradc_reg_set(lradc,
LRADC_CTRL1_LRADC_IRQ_EN(TOUCHSCREEN_VCHANNEL1),
LRADC_CTRL1);
mxs_lradc_prepare_y_pos(lradc);
}
static void mxs_lradc_report_ts_event(struct mxs_lradc *lradc)
{
input_report_abs(lradc->ts_input, ABS_X, lradc->ts_x_pos);
input_report_abs(lradc->ts_input, ABS_Y, lradc->ts_y_pos);
input_report_abs(lradc->ts_input, ABS_PRESSURE, lradc->ts_pressure);
input_report_key(lradc->ts_input, BTN_TOUCH, 1);
input_sync(lradc->ts_input);
}
static void mxs_lradc_complete_touch_event(struct mxs_lradc *lradc)
{
mxs_lradc_setup_touch_detection(lradc);
lradc->cur_plate = LRADC_SAMPLE_VALID;
mxs_lradc_reg_wrt(lradc, 0, LRADC_CH(TOUCHSCREEN_VCHANNEL1));
mxs_lradc_reg_clear(lradc,
LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL1) |
LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL2),
LRADC_CTRL1);
mxs_lradc_reg_wrt(
lradc,
LRADC_DELAY_TRIGGER(1 << TOUCHSCREEN_VCHANNEL1) |
LRADC_DELAY_KICK | LRADC_DELAY_DELAY(10),
LRADC_DELAY(2));
}
static void mxs_lradc_finish_touch_event(struct mxs_lradc *lradc, bool valid)
{
if (valid && mxs_lradc_check_touch_event(lradc)) {
lradc->ts_valid = true;
mxs_lradc_report_ts_event(lradc);
}
if (mxs_lradc_check_touch_event(lradc)) {
mxs_lradc_prepare_y_pos(lradc);
return;
}
if (lradc->ts_valid) {
lradc->ts_valid = false;
input_report_key(lradc->ts_input, BTN_TOUCH, 0);
input_sync(lradc->ts_input);
}
lradc->cur_plate = LRADC_TOUCH;
mxs_lradc_reg_wrt(lradc, 0, LRADC_DELAY(2));
mxs_lradc_reg_wrt(lradc, 0, LRADC_DELAY(3));
mxs_lradc_reg_clear(lradc,
LRADC_CTRL1_TOUCH_DETECT_IRQ |
LRADC_CTRL1_LRADC_IRQ_EN(TOUCHSCREEN_VCHANNEL1) |
LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL1),
LRADC_CTRL1);
mxs_lradc_reg_set(lradc, LRADC_CTRL1_TOUCH_DETECT_IRQ_EN, LRADC_CTRL1);
}
static void mxs_lradc_handle_touch(struct mxs_lradc *lradc)
{
switch (lradc->cur_plate) {
case LRADC_TOUCH:
if (mxs_lradc_check_touch_event(lradc))
mxs_lradc_start_touch_event(lradc);
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_TOUCH_DETECT_IRQ,
LRADC_CTRL1);
return;
case LRADC_SAMPLE_Y:
lradc->ts_y_pos =
mxs_lradc_read_raw_channel(lradc,
TOUCHSCREEN_VCHANNEL1);
mxs_lradc_prepare_x_pos(lradc);
return;
case LRADC_SAMPLE_X:
lradc->ts_x_pos =
mxs_lradc_read_raw_channel(lradc,
TOUCHSCREEN_VCHANNEL1);
mxs_lradc_prepare_pressure(lradc);
return;
case LRADC_SAMPLE_PRESSURE:
lradc->ts_pressure =
mxs_lradc_read_ts_pressure(lradc,
TOUCHSCREEN_VCHANNEL2,
TOUCHSCREEN_VCHANNEL1);
mxs_lradc_complete_touch_event(lradc);
return;
case LRADC_SAMPLE_VALID:
mxs_lradc_finish_touch_event(lradc, 1);
break;
}
}
static int mxs_lradc_read_single(struct iio_dev *iio_dev, int chan, int *val)
{
struct mxs_lradc *lradc = iio_priv(iio_dev);
int ret;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
reinit_completion(&lradc->completion);
if (lradc->soc == IMX28_LRADC)
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_LRADC_IRQ_EN(0),
LRADC_CTRL1);
mxs_lradc_reg_clear(lradc, 0x1, LRADC_CTRL0);
if (test_bit(chan, &lradc->is_divided))
mxs_lradc_reg_set(lradc,
1 << LRADC_CTRL2_DIVIDE_BY_TWO_OFFSET,
LRADC_CTRL2);
else
mxs_lradc_reg_clear(lradc,
1 << LRADC_CTRL2_DIVIDE_BY_TWO_OFFSET,
LRADC_CTRL2);
mxs_lradc_reg_clear(lradc, LRADC_CTRL4_LRADCSELECT_MASK(0),
LRADC_CTRL4);
mxs_lradc_reg_set(lradc, chan, LRADC_CTRL4);
mxs_lradc_reg_wrt(lradc, 0, LRADC_CH(0));
mxs_lradc_reg_set(lradc, LRADC_CTRL1_LRADC_IRQ_EN(0), LRADC_CTRL1);
mxs_lradc_reg_set(lradc, BIT(0), LRADC_CTRL0);
ret = wait_for_completion_killable_timeout(&lradc->completion, HZ);
if (!ret)
ret = -ETIMEDOUT;
if (ret < 0)
goto err;
*val = readl(lradc->base + LRADC_CH(0)) & LRADC_CH_VALUE_MASK;
ret = IIO_VAL_INT;
err:
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_LRADC_IRQ_EN(0), LRADC_CTRL1);
mutex_unlock(&lradc->lock);
return ret;
}
static int mxs_lradc_read_temp(struct iio_dev *iio_dev, int *val)
{
int ret, min, max;
ret = mxs_lradc_read_single(iio_dev, 8, &min);
if (ret != IIO_VAL_INT)
return ret;
ret = mxs_lradc_read_single(iio_dev, 9, &max);
if (ret != IIO_VAL_INT)
return ret;
*val = max - min;
return IIO_VAL_INT;
}
static int mxs_lradc_read_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long m)
{
struct mxs_lradc *lradc = iio_priv(iio_dev);
switch (m) {
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_TEMP)
return mxs_lradc_read_temp(iio_dev, val);
return mxs_lradc_read_single(iio_dev, chan->channel, val);
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_TEMP) {
*val = 0;
*val2 = 253000;
return IIO_VAL_INT_PLUS_MICRO;
}
*val = lradc->vref_mv[chan->channel];
*val2 = chan->scan_type.realbits -
test_bit(chan->channel, &lradc->is_divided);
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
static int mxs_lradc_write_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int val, int val2, long m)
{
struct mxs_lradc *lradc = iio_priv(iio_dev);
struct mxs_lradc_scale *scale_avail =
lradc->scale_avail[chan->channel];
int ret;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
switch (m) {
case IIO_CHAN_INFO_SCALE:
ret = -EINVAL;
if (val == scale_avail[MXS_LRADC_DIV_DISABLED].integer &&
val2 == scale_avail[MXS_LRADC_DIV_DISABLED].nano) {
clear_bit(chan->channel, &lradc->is_divided);
ret = 0;
} else if (val == scale_avail[MXS_LRADC_DIV_ENABLED].integer &&
val2 == scale_avail[MXS_LRADC_DIV_ENABLED].nano) {
set_bit(chan->channel, &lradc->is_divided);
ret = 0;
}
break;
default:
ret = -EINVAL;
break;
}
mutex_unlock(&lradc->lock);
return ret;
}
static int mxs_lradc_write_raw_get_fmt(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
long m)
{
return IIO_VAL_INT_PLUS_NANO;
}
static ssize_t mxs_lradc_show_scale_available_ch(struct device *dev,
struct device_attribute *attr,
char *buf,
int ch)
{
struct iio_dev *iio = dev_to_iio_dev(dev);
struct mxs_lradc *lradc = iio_priv(iio);
int i, len = 0;
for (i = 0; i < ARRAY_SIZE(lradc->scale_avail[ch]); i++)
len += sprintf(buf + len, "%u.%09u ",
lradc->scale_avail[ch][i].integer,
lradc->scale_avail[ch][i].nano);
len += sprintf(buf + len, "\n");
return len;
}
static ssize_t mxs_lradc_show_scale_available(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev_attr *iio_attr = to_iio_dev_attr(attr);
return mxs_lradc_show_scale_available_ch(dev, attr, buf,
iio_attr->address);
}
static int mxs_lradc_ts_open(struct input_dev *dev)
{
struct mxs_lradc *lradc = input_get_drvdata(dev);
mxs_lradc_enable_touch_detection(lradc);
return 0;
}
static void mxs_lradc_disable_ts(struct mxs_lradc *lradc)
{
mxs_lradc_reg_clear(lradc, LRADC_CTRL1_TOUCH_DETECT_IRQ_EN |
LRADC_CTRL1_LRADC_IRQ_EN(TOUCHSCREEN_VCHANNEL1) |
LRADC_CTRL1_LRADC_IRQ_EN(TOUCHSCREEN_VCHANNEL2), LRADC_CTRL1);
mxs_lradc_reg_clear(lradc, mxs_lradc_plate_mask(lradc), LRADC_CTRL0);
}
static void mxs_lradc_ts_close(struct input_dev *dev)
{
struct mxs_lradc *lradc = input_get_drvdata(dev);
mxs_lradc_disable_ts(lradc);
}
static int mxs_lradc_ts_register(struct mxs_lradc *lradc)
{
struct input_dev *input;
struct device *dev = lradc->dev;
int ret;
if (!lradc->use_touchscreen)
return 0;
input = input_allocate_device();
if (!input)
return -ENOMEM;
input->name = DRIVER_NAME;
input->id.bustype = BUS_HOST;
input->dev.parent = dev;
input->open = mxs_lradc_ts_open;
input->close = mxs_lradc_ts_close;
__set_bit(EV_ABS, input->evbit);
__set_bit(EV_KEY, input->evbit);
__set_bit(BTN_TOUCH, input->keybit);
__set_bit(INPUT_PROP_DIRECT, input->propbit);
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
mxs_lradc_disable_ts(lradc);
input_unregister_device(lradc->ts_input);
}
static irqreturn_t mxs_lradc_handle_irq(int irq, void *data)
{
struct iio_dev *iio = data;
struct mxs_lradc *lradc = iio_priv(iio);
unsigned long reg = readl(lradc->base + LRADC_CTRL1);
u32 clr_irq = mxs_lradc_irq_mask(lradc);
const u32 ts_irq_mask =
LRADC_CTRL1_TOUCH_DETECT_IRQ |
LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL1) |
LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL2);
if (!(reg & mxs_lradc_irq_mask(lradc)))
return IRQ_NONE;
if (lradc->use_touchscreen && (reg & ts_irq_mask)) {
mxs_lradc_handle_touch(lradc);
clr_irq &= ~(LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL1) |
LRADC_CTRL1_LRADC_IRQ(TOUCHSCREEN_VCHANNEL2));
}
if (iio_buffer_enabled(iio)) {
if (reg & lradc->buffer_vchans)
iio_trigger_poll(iio->trig);
} else if (reg & LRADC_CTRL1_LRADC_IRQ(0)) {
complete(&lradc->completion);
}
mxs_lradc_reg_clear(lradc, reg & clr_irq, LRADC_CTRL1);
return IRQ_HANDLED;
}
static irqreturn_t mxs_lradc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *iio = pf->indio_dev;
struct mxs_lradc *lradc = iio_priv(iio);
const u32 chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
unsigned int i, j = 0;
for_each_set_bit(i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
lradc->buffer[j] = readl(lradc->base + LRADC_CH(j));
mxs_lradc_reg_wrt(lradc, chan_value, LRADC_CH(j));
lradc->buffer[j] &= LRADC_CH_VALUE_MASK;
lradc->buffer[j] /= LRADC_DELAY_TIMER_LOOP;
j++;
}
iio_push_to_buffers_with_timestamp(iio, lradc->buffer, pf->timestamp);
iio_trigger_notify_done(iio->trig);
return IRQ_HANDLED;
}
static int mxs_lradc_configure_trigger(struct iio_trigger *trig, bool state)
{
struct iio_dev *iio = iio_trigger_get_drvdata(trig);
struct mxs_lradc *lradc = iio_priv(iio);
const u32 st = state ? STMP_OFFSET_REG_SET : STMP_OFFSET_REG_CLR;
mxs_lradc_reg_wrt(lradc, LRADC_DELAY_KICK, LRADC_DELAY(0) + st);
return 0;
}
static int mxs_lradc_trigger_init(struct iio_dev *iio)
{
int ret;
struct iio_trigger *trig;
struct mxs_lradc *lradc = iio_priv(iio);
trig = iio_trigger_alloc("%s-dev%i", iio->name, iio->id);
if (!trig)
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
u32 ctrl4_set = 0;
u32 ctrl4_clr = 0;
u32 ctrl1_irq = 0;
const u32 chan_value = LRADC_CH_ACCUMULATE |
((LRADC_DELAY_TIMER_LOOP - 1) << LRADC_CH_NUM_SAMPLES_OFFSET);
const int len = bitmap_weight(iio->active_scan_mask,
LRADC_MAX_TOTAL_CHANS);
if (!len)
return -EINVAL;
ret = mutex_trylock(&lradc->lock);
if (!ret)
return -EBUSY;
lradc->buffer = kmalloc_array(len, sizeof(*lradc->buffer), GFP_KERNEL);
if (!lradc->buffer) {
ret = -ENOMEM;
goto err_mem;
}
if (lradc->soc == IMX28_LRADC)
mxs_lradc_reg_clear(
lradc,
lradc->buffer_vchans << LRADC_CTRL1_LRADC_IRQ_EN_OFFSET,
LRADC_CTRL1);
mxs_lradc_reg_clear(lradc, lradc->buffer_vchans, LRADC_CTRL0);
for_each_set_bit(chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
ctrl4_set |= chan << LRADC_CTRL4_LRADCSELECT_OFFSET(ofs);
ctrl4_clr |= LRADC_CTRL4_LRADCSELECT_MASK(ofs);
ctrl1_irq |= LRADC_CTRL1_LRADC_IRQ_EN(ofs);
mxs_lradc_reg_wrt(lradc, chan_value, LRADC_CH(ofs));
bitmap_set(&enable, ofs, 1);
ofs++;
}
mxs_lradc_reg_clear(lradc, LRADC_DELAY_TRIGGER_LRADCS_MASK |
LRADC_DELAY_KICK, LRADC_DELAY(0));
mxs_lradc_reg_clear(lradc, ctrl4_clr, LRADC_CTRL4);
mxs_lradc_reg_set(lradc, ctrl4_set, LRADC_CTRL4);
mxs_lradc_reg_set(lradc, ctrl1_irq, LRADC_CTRL1);
mxs_lradc_reg_set(lradc, enable << LRADC_DELAY_TRIGGER_LRADCS_OFFSET,
LRADC_DELAY(0));
return 0;
err_mem:
mutex_unlock(&lradc->lock);
return ret;
}
static int mxs_lradc_buffer_postdisable(struct iio_dev *iio)
{
struct mxs_lradc *lradc = iio_priv(iio);
mxs_lradc_reg_clear(lradc, LRADC_DELAY_TRIGGER_LRADCS_MASK |
LRADC_DELAY_KICK, LRADC_DELAY(0));
mxs_lradc_reg_clear(lradc, lradc->buffer_vchans, LRADC_CTRL0);
if (lradc->soc == IMX28_LRADC)
mxs_lradc_reg_clear(
lradc,
lradc->buffer_vchans << LRADC_CTRL1_LRADC_IRQ_EN_OFFSET,
LRADC_CTRL1);
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
rsvd_chans += 2;
if (bitmap_intersects(mask, &rsvd_mask, LRADC_MAX_TOTAL_CHANS))
return false;
if (map_chans + rsvd_chans > LRADC_MAX_MAPPED_CHANS)
return false;
return true;
}
static void mxs_lradc_hw_init(struct mxs_lradc *lradc)
{
const u32 adc_cfg =
(1 << (LRADC_DELAY_TRIGGER_DELAYS_OFFSET + 0)) |
(LRADC_DELAY_TIMER_PER << LRADC_DELAY_DELAY_OFFSET);
mxs_lradc_reg_wrt(lradc, adc_cfg, LRADC_DELAY(0));
mxs_lradc_reg_wrt(lradc, 0, LRADC_DELAY(1));
mxs_lradc_reg_wrt(lradc, 0, LRADC_DELAY(2));
mxs_lradc_reg_wrt(lradc, 0, LRADC_DELAY(3));
mxs_lradc_reg_wrt(lradc, 0, LRADC_CTRL2);
}
static void mxs_lradc_hw_stop(struct mxs_lradc *lradc)
{
int i;
mxs_lradc_reg_clear(lradc, mxs_lradc_irq_en_mask(lradc), LRADC_CTRL1);
for (i = 0; i < LRADC_MAX_DELAY_CHANS; i++)
mxs_lradc_reg_wrt(lradc, 0, LRADC_DELAY(i));
}
static int mxs_lradc_probe_touchscreen(struct mxs_lradc *lradc,
struct device_node *lradc_node)
{
int ret;
u32 ts_wires = 0, adapt;
ret = of_property_read_u32(lradc_node, "fsl,lradc-touchscreen-wires",
&ts_wires);
if (ret)
return -ENODEV;
switch (ts_wires) {
case 4:
lradc->use_touchscreen = MXS_LRADC_TOUCHSCREEN_4WIRE;
break;
case 5:
if (lradc->soc == IMX28_LRADC) {
lradc->use_touchscreen = MXS_LRADC_TOUCHSCREEN_5WIRE;
break;
}
default:
dev_err(lradc->dev,
"Unsupported number of touchscreen wires (%d)\n",
ts_wires);
return -EINVAL;
}
if (of_property_read_u32(lradc_node, "fsl,ave-ctrl", &adapt)) {
lradc->over_sample_cnt = 4;
} else {
if (adapt < 1 || adapt > 32) {
dev_err(lradc->dev, "Invalid sample count (%u)\n",
adapt);
return -EINVAL;
}
lradc->over_sample_cnt = adapt;
}
if (of_property_read_u32(lradc_node, "fsl,ave-delay", &adapt)) {
lradc->over_sample_delay = 2;
} else {
if (adapt < 2 || adapt > LRADC_DELAY_DELAY_MASK + 1) {
dev_err(lradc->dev, "Invalid sample delay (%u)\n",
adapt);
return -EINVAL;
}
lradc->over_sample_delay = adapt;
}
if (of_property_read_u32(lradc_node, "fsl,settling", &adapt)) {
lradc->settling_delay = 10;
} else {
if (adapt < 1 || adapt > LRADC_DELAY_DELAY_MASK) {
dev_err(lradc->dev, "Invalid settling delay (%u)\n",
adapt);
return -EINVAL;
}
lradc->settling_delay = adapt;
}
return 0;
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
int ret = 0, touch_ret;
int i, s;
u64 scale_uv;
iio = devm_iio_device_alloc(dev, sizeof(*lradc));
if (!iio) {
dev_err(dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
lradc = iio_priv(iio);
lradc->soc = (enum mxs_lradc_id)of_id->data;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
lradc->dev = &pdev->dev;
lradc->base = devm_ioremap_resource(dev, iores);
if (IS_ERR(lradc->base))
return PTR_ERR(lradc->base);
lradc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(lradc->clk)) {
dev_err(dev, "Failed to get the delay unit clock\n");
return PTR_ERR(lradc->clk);
}
ret = clk_prepare_enable(lradc->clk);
if (ret != 0) {
dev_err(dev, "Failed to enable the delay unit clock\n");
return ret;
}
touch_ret = mxs_lradc_probe_touchscreen(lradc, node);
if (touch_ret == 0)
lradc->buffer_vchans = BUFFER_VCHANS_LIMITED;
else
lradc->buffer_vchans = BUFFER_VCHANS_ALL;
for (i = 0; i < of_cfg->irq_count; i++) {
lradc->irq[i] = platform_get_irq(pdev, i);
if (lradc->irq[i] < 0) {
ret = lradc->irq[i];
goto err_clk;
}
ret = devm_request_irq(dev, lradc->irq[i],
mxs_lradc_handle_irq, 0,
of_cfg->irq_name[i], iio);
if (ret)
goto err_clk;
}
lradc->vref_mv = of_cfg->vref_mv;
platform_set_drvdata(pdev, iio);
init_completion(&lradc->completion);
mutex_init(&lradc->lock);
iio->name = pdev->name;
iio->dev.parent = &pdev->dev;
iio->info = &mxs_lradc_iio_info;
iio->modes = INDIO_DIRECT_MODE;
iio->masklength = LRADC_MAX_TOTAL_CHANS;
if (lradc->soc == IMX23_LRADC) {
iio->channels = mx23_lradc_chan_spec;
iio->num_channels = ARRAY_SIZE(mx23_lradc_chan_spec);
} else {
iio->channels = mx28_lradc_chan_spec;
iio->num_channels = ARRAY_SIZE(mx28_lradc_chan_spec);
}
ret = iio_triggered_buffer_setup(iio, &iio_pollfunc_store_time,
&mxs_lradc_trigger_handler,
&mxs_lradc_buffer_ops);
if (ret)
goto err_clk;
ret = mxs_lradc_trigger_init(iio);
if (ret)
goto err_trig;
for (i = 0; i < LRADC_MAX_TOTAL_CHANS; i++) {
for (s = 0; s < ARRAY_SIZE(lradc->scale_avail[i]); s++) {
scale_uv = ((u64)lradc->vref_mv[i] * 100000000) >>
(LRADC_RESOLUTION - s);
lradc->scale_avail[i][s].nano =
do_div(scale_uv, 100000000) * 10;
lradc->scale_avail[i][s].integer = scale_uv;
}
}
ret = stmp_reset_block(lradc->base);
if (ret)
goto err_dev;
mxs_lradc_hw_init(lradc);
if (touch_ret == 0) {
ret = mxs_lradc_ts_register(lradc);
if (ret)
goto err_ts_register;
}
ret = iio_device_register(iio);
if (ret) {
dev_err(dev, "Failed to register IIO device\n");
goto err_ts;
}
return 0;
err_ts:
mxs_lradc_ts_unregister(lradc);
err_ts_register:
mxs_lradc_hw_stop(lradc);
err_dev:
mxs_lradc_trigger_remove(iio);
err_trig:
iio_triggered_buffer_cleanup(iio);
err_clk:
clk_disable_unprepare(lradc->clk);
return ret;
}
static int mxs_lradc_remove(struct platform_device *pdev)
{
struct iio_dev *iio = platform_get_drvdata(pdev);
struct mxs_lradc *lradc = iio_priv(iio);
iio_device_unregister(iio);
mxs_lradc_ts_unregister(lradc);
mxs_lradc_hw_stop(lradc);
mxs_lradc_trigger_remove(iio);
iio_triggered_buffer_cleanup(iio);
clk_disable_unprepare(lradc->clk);
return 0;
}
