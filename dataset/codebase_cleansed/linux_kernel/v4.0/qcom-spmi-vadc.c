static int vadc_read(struct vadc_priv *vadc, u16 offset, u8 *data)
{
return regmap_bulk_read(vadc->regmap, vadc->base + offset, data, 1);
}
static int vadc_write(struct vadc_priv *vadc, u16 offset, u8 data)
{
return regmap_write(vadc->regmap, vadc->base + offset, data);
}
static int vadc_reset(struct vadc_priv *vadc)
{
u8 data;
int ret;
ret = vadc_write(vadc, VADC_ACCESS, VADC_ACCESS_DATA);
if (ret)
return ret;
ret = vadc_read(vadc, VADC_PERH_RESET_CTL3, &data);
if (ret)
return ret;
ret = vadc_write(vadc, VADC_ACCESS, VADC_ACCESS_DATA);
if (ret)
return ret;
data |= VADC_FOLLOW_WARM_RB;
return vadc_write(vadc, VADC_PERH_RESET_CTL3, data);
}
static int vadc_set_state(struct vadc_priv *vadc, bool state)
{
return vadc_write(vadc, VADC_EN_CTL1, state ? VADC_EN_CTL1_SET : 0);
}
static void vadc_show_status(struct vadc_priv *vadc)
{
u8 mode, sta1, chan, dig, en, req;
int ret;
ret = vadc_read(vadc, VADC_MODE_CTL, &mode);
if (ret)
return;
ret = vadc_read(vadc, VADC_ADC_DIG_PARAM, &dig);
if (ret)
return;
ret = vadc_read(vadc, VADC_ADC_CH_SEL_CTL, &chan);
if (ret)
return;
ret = vadc_read(vadc, VADC_CONV_REQ, &req);
if (ret)
return;
ret = vadc_read(vadc, VADC_STATUS1, &sta1);
if (ret)
return;
ret = vadc_read(vadc, VADC_EN_CTL1, &en);
if (ret)
return;
dev_err(vadc->dev,
"mode:%02x en:%02x chan:%02x dig:%02x req:%02x sta1:%02x\n",
mode, en, chan, dig, req, sta1);
}
static int vadc_configure(struct vadc_priv *vadc,
struct vadc_channel_prop *prop)
{
u8 decimation, mode_ctrl;
int ret;
mode_ctrl = (VADC_OP_MODE_NORMAL << VADC_OP_MODE_SHIFT) |
VADC_ADC_TRIM_EN | VADC_AMUX_TRIM_EN;
ret = vadc_write(vadc, VADC_MODE_CTL, mode_ctrl);
if (ret)
return ret;
ret = vadc_write(vadc, VADC_ADC_CH_SEL_CTL, prop->channel);
if (ret)
return ret;
decimation = prop->decimation << VADC_ADC_DIG_DEC_RATIO_SEL_SHIFT;
ret = vadc_write(vadc, VADC_ADC_DIG_PARAM, decimation);
if (ret)
return ret;
ret = vadc_write(vadc, VADC_HW_SETTLE_DELAY, prop->hw_settle_time);
if (ret)
return ret;
ret = vadc_write(vadc, VADC_FAST_AVG_CTL, prop->avg_samples);
if (ret)
return ret;
if (prop->avg_samples)
ret = vadc_write(vadc, VADC_FAST_AVG_EN, VADC_FAST_AVG_EN_SET);
else
ret = vadc_write(vadc, VADC_FAST_AVG_EN, 0);
return ret;
}
static int vadc_poll_wait_eoc(struct vadc_priv *vadc, unsigned int interval_us)
{
unsigned int count, retry;
u8 sta1;
int ret;
retry = interval_us / VADC_CONV_TIME_MIN_US;
for (count = 0; count < retry; count++) {
ret = vadc_read(vadc, VADC_STATUS1, &sta1);
if (ret)
return ret;
sta1 &= VADC_STATUS1_REQ_STS_EOC_MASK;
if (sta1 == VADC_STATUS1_EOC)
return 0;
usleep_range(VADC_CONV_TIME_MIN_US, VADC_CONV_TIME_MAX_US);
}
vadc_show_status(vadc);
return -ETIMEDOUT;
}
static int vadc_read_result(struct vadc_priv *vadc, u16 *data)
{
int ret;
ret = regmap_bulk_read(vadc->regmap, vadc->base + VADC_DATA, data, 2);
if (ret)
return ret;
*data = clamp_t(u16, *data, VADC_MIN_ADC_CODE, VADC_MAX_ADC_CODE);
return 0;
}
static struct vadc_channel_prop *vadc_get_channel(struct vadc_priv *vadc,
unsigned int num)
{
unsigned int i;
for (i = 0; i < vadc->nchannels; i++)
if (vadc->chan_props[i].channel == num)
return &vadc->chan_props[i];
dev_dbg(vadc->dev, "no such channel %02x\n", num);
return NULL;
}
static int vadc_do_conversion(struct vadc_priv *vadc,
struct vadc_channel_prop *prop, u16 *data)
{
unsigned int timeout;
int ret;
mutex_lock(&vadc->lock);
ret = vadc_configure(vadc, prop);
if (ret)
goto unlock;
if (!vadc->poll_eoc)
reinit_completion(&vadc->complete);
ret = vadc_set_state(vadc, true);
if (ret)
goto unlock;
ret = vadc_write(vadc, VADC_CONV_REQ, VADC_CONV_REQ_SET);
if (ret)
goto err_disable;
timeout = BIT(prop->avg_samples) * VADC_CONV_TIME_MIN_US * 2;
if (vadc->poll_eoc) {
ret = vadc_poll_wait_eoc(vadc, timeout);
} else {
ret = wait_for_completion_timeout(&vadc->complete, timeout);
if (!ret) {
ret = -ETIMEDOUT;
goto err_disable;
}
ret = vadc_poll_wait_eoc(vadc, VADC_CONV_TIME_MIN_US);
if (ret)
goto err_disable;
}
ret = vadc_read_result(vadc, data);
err_disable:
vadc_set_state(vadc, false);
if (ret)
dev_err(vadc->dev, "conversion failed\n");
unlock:
mutex_unlock(&vadc->lock);
return ret;
}
static int vadc_measure_ref_points(struct vadc_priv *vadc)
{
struct vadc_channel_prop *prop;
u16 read_1, read_2;
int ret;
vadc->graph[VADC_CALIB_RATIOMETRIC].dx = VADC_RATIOMETRIC_RANGE_UV;
vadc->graph[VADC_CALIB_ABSOLUTE].dx = VADC_ABSOLUTE_RANGE_UV;
prop = vadc_get_channel(vadc, VADC_REF_1250MV);
ret = vadc_do_conversion(vadc, prop, &read_1);
if (ret)
goto err;
prop = vadc_get_channel(vadc, VADC_SPARE1);
if (!prop)
prop = vadc_get_channel(vadc, VADC_REF_625MV);
ret = vadc_do_conversion(vadc, prop, &read_2);
if (ret)
goto err;
if (read_1 == read_2) {
ret = -EINVAL;
goto err;
}
vadc->graph[VADC_CALIB_ABSOLUTE].dy = read_1 - read_2;
vadc->graph[VADC_CALIB_ABSOLUTE].gnd = read_2;
prop = vadc_get_channel(vadc, VADC_VDD_VADC);
ret = vadc_do_conversion(vadc, prop, &read_1);
if (ret)
goto err;
prop = vadc_get_channel(vadc, VADC_GND_REF);
ret = vadc_do_conversion(vadc, prop, &read_2);
if (ret)
goto err;
if (read_1 == read_2) {
ret = -EINVAL;
goto err;
}
vadc->graph[VADC_CALIB_RATIOMETRIC].dy = read_1 - read_2;
vadc->graph[VADC_CALIB_RATIOMETRIC].gnd = read_2;
err:
if (ret)
dev_err(vadc->dev, "measure reference points failed\n");
return ret;
}
static s32 vadc_calibrate(struct vadc_priv *vadc,
const struct vadc_channel_prop *prop, u16 adc_code)
{
const struct vadc_prescale_ratio *prescale;
s32 voltage;
voltage = adc_code - vadc->graph[prop->calibration].gnd;
voltage *= vadc->graph[prop->calibration].dx;
voltage = voltage / vadc->graph[prop->calibration].dy;
if (prop->calibration == VADC_CALIB_ABSOLUTE)
voltage += vadc->graph[prop->calibration].dx;
if (voltage < 0)
voltage = 0;
prescale = &vadc_prescale_ratios[prop->prescale];
voltage = voltage * prescale->den;
return voltage / prescale->num;
}
static int vadc_decimation_from_dt(u32 value)
{
if (!is_power_of_2(value) || value < VADC_DECIMATION_MIN ||
value > VADC_DECIMATION_MAX)
return -EINVAL;
return __ffs64(value / VADC_DECIMATION_MIN);
}
static int vadc_prescaling_from_dt(u32 num, u32 den)
{
unsigned int pre;
for (pre = 0; pre < ARRAY_SIZE(vadc_prescale_ratios); pre++)
if (vadc_prescale_ratios[pre].num == num &&
vadc_prescale_ratios[pre].den == den)
break;
if (pre == ARRAY_SIZE(vadc_prescale_ratios))
return -EINVAL;
return pre;
}
static int vadc_hw_settle_time_from_dt(u32 value)
{
if ((value <= 1000 && value % 100) || (value > 1000 && value % 2000))
return -EINVAL;
if (value <= 1000)
value /= 100;
else
value = value / 2000 + 10;
return value;
}
static int vadc_avg_samples_from_dt(u32 value)
{
if (!is_power_of_2(value) || value > VADC_AVG_SAMPLES_MAX)
return -EINVAL;
return __ffs64(value);
}
static int vadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2,
long mask)
{
struct vadc_priv *vadc = iio_priv(indio_dev);
struct vadc_channel_prop *prop;
u16 adc_code;
int ret;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
prop = &vadc->chan_props[chan->address];
ret = vadc_do_conversion(vadc, prop, &adc_code);
if (ret)
break;
*val = vadc_calibrate(vadc, prop, adc_code);
*val /= 2;
*val -= KELVINMIL_CELSIUSMIL;
return IIO_VAL_INT;
case IIO_CHAN_INFO_RAW:
prop = &vadc->chan_props[chan->address];
ret = vadc_do_conversion(vadc, prop, &adc_code);
if (ret)
break;
*val = vadc_calibrate(vadc, prop, adc_code);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 1000;
return IIO_VAL_INT_PLUS_MICRO;
default:
ret = -EINVAL;
break;
}
return ret;
}
static int vadc_of_xlate(struct iio_dev *indio_dev,
const struct of_phandle_args *iiospec)
{
struct vadc_priv *vadc = iio_priv(indio_dev);
unsigned int i;
for (i = 0; i < vadc->nchannels; i++)
if (vadc->iio_chans[i].channel == iiospec->args[0])
return i;
return -EINVAL;
}
static int vadc_get_dt_channel_data(struct device *dev,
struct vadc_channel_prop *prop,
struct device_node *node)
{
const char *name = node->name;
u32 chan, value, varr[2];
int ret;
ret = of_property_read_u32(node, "reg", &chan);
if (ret) {
dev_err(dev, "invalid channel number %s\n", name);
return ret;
}
if (chan > VADC_CHAN_MAX || chan < VADC_CHAN_MIN) {
dev_err(dev, "%s invalid channel number %d\n", name, chan);
return -EINVAL;
}
prop->channel = chan;
ret = of_property_read_u32(node, "qcom,decimation", &value);
if (!ret) {
ret = vadc_decimation_from_dt(value);
if (ret < 0) {
dev_err(dev, "%02x invalid decimation %d\n",
chan, value);
return ret;
}
prop->decimation = ret;
} else {
prop->decimation = VADC_DEF_DECIMATION;
}
ret = of_property_read_u32_array(node, "qcom,pre-scaling", varr, 2);
if (!ret) {
ret = vadc_prescaling_from_dt(varr[0], varr[1]);
if (ret < 0) {
dev_err(dev, "%02x invalid pre-scaling <%d %d>\n",
chan, varr[0], varr[1]);
return ret;
}
prop->prescale = ret;
} else {
prop->prescale = vadc_chans[prop->channel].prescale_index;
}
ret = of_property_read_u32(node, "qcom,hw-settle-time", &value);
if (!ret) {
ret = vadc_hw_settle_time_from_dt(value);
if (ret < 0) {
dev_err(dev, "%02x invalid hw-settle-time %d us\n",
chan, value);
return ret;
}
prop->hw_settle_time = ret;
} else {
prop->hw_settle_time = VADC_DEF_HW_SETTLE_TIME;
}
ret = of_property_read_u32(node, "qcom,avg-samples", &value);
if (!ret) {
ret = vadc_avg_samples_from_dt(value);
if (ret < 0) {
dev_err(dev, "%02x invalid avg-samples %d\n",
chan, value);
return ret;
}
prop->avg_samples = ret;
} else {
prop->avg_samples = VADC_DEF_AVG_SAMPLES;
}
if (of_property_read_bool(node, "qcom,ratiometric"))
prop->calibration = VADC_CALIB_RATIOMETRIC;
else
prop->calibration = VADC_CALIB_ABSOLUTE;
dev_dbg(dev, "%02x name %s\n", chan, name);
return 0;
}
static int vadc_get_dt_data(struct vadc_priv *vadc, struct device_node *node)
{
const struct vadc_channels *vadc_chan;
struct iio_chan_spec *iio_chan;
struct vadc_channel_prop prop;
struct device_node *child;
unsigned int index = 0;
int ret;
vadc->nchannels = of_get_available_child_count(node);
if (!vadc->nchannels)
return -EINVAL;
vadc->iio_chans = devm_kcalloc(vadc->dev, vadc->nchannels,
sizeof(*vadc->iio_chans), GFP_KERNEL);
if (!vadc->iio_chans)
return -ENOMEM;
vadc->chan_props = devm_kcalloc(vadc->dev, vadc->nchannels,
sizeof(*vadc->chan_props), GFP_KERNEL);
if (!vadc->chan_props)
return -ENOMEM;
iio_chan = vadc->iio_chans;
for_each_available_child_of_node(node, child) {
ret = vadc_get_dt_channel_data(vadc->dev, &prop, child);
if (ret)
return ret;
vadc->chan_props[index] = prop;
vadc_chan = &vadc_chans[prop.channel];
iio_chan->channel = prop.channel;
iio_chan->datasheet_name = vadc_chan->datasheet_name;
iio_chan->info_mask_separate = vadc_chan->info_mask;
iio_chan->type = vadc_chan->type;
iio_chan->indexed = 1;
iio_chan->address = index++;
iio_chan++;
}
if (!vadc_get_channel(vadc, VADC_REF_1250MV)) {
dev_err(vadc->dev, "Please define 1.25V channel\n");
return -ENODEV;
}
if (!vadc_get_channel(vadc, VADC_REF_625MV)) {
dev_err(vadc->dev, "Please define 0.625V channel\n");
return -ENODEV;
}
if (!vadc_get_channel(vadc, VADC_VDD_VADC)) {
dev_err(vadc->dev, "Please define VDD channel\n");
return -ENODEV;
}
if (!vadc_get_channel(vadc, VADC_GND_REF)) {
dev_err(vadc->dev, "Please define GND channel\n");
return -ENODEV;
}
return 0;
}
static irqreturn_t vadc_isr(int irq, void *dev_id)
{
struct vadc_priv *vadc = dev_id;
complete(&vadc->complete);
return IRQ_HANDLED;
}
static int vadc_check_revision(struct vadc_priv *vadc)
{
u8 val;
int ret;
ret = vadc_read(vadc, VADC_PERPH_TYPE, &val);
if (ret)
return ret;
if (val < VADC_PERPH_TYPE_ADC) {
dev_err(vadc->dev, "%d is not ADC\n", val);
return -ENODEV;
}
ret = vadc_read(vadc, VADC_PERPH_SUBTYPE, &val);
if (ret)
return ret;
if (val < VADC_PERPH_SUBTYPE_VADC) {
dev_err(vadc->dev, "%d is not VADC\n", val);
return -ENODEV;
}
ret = vadc_read(vadc, VADC_REVISION2, &val);
if (ret)
return ret;
if (val < VADC_REVISION2_SUPPORTED_VADC) {
dev_err(vadc->dev, "revision %d not supported\n", val);
return -ENODEV;
}
return 0;
}
static int vadc_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct iio_dev *indio_dev;
struct vadc_priv *vadc;
struct regmap *regmap;
int ret, irq_eoc;
u32 reg;
regmap = dev_get_regmap(dev->parent, NULL);
if (!regmap)
return -ENODEV;
ret = of_property_read_u32(node, "reg", &reg);
if (ret < 0)
return ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*vadc));
if (!indio_dev)
return -ENOMEM;
vadc = iio_priv(indio_dev);
vadc->regmap = regmap;
vadc->dev = dev;
vadc->base = reg;
vadc->are_ref_measured = false;
init_completion(&vadc->complete);
mutex_init(&vadc->lock);
ret = vadc_check_revision(vadc);
if (ret)
return ret;
ret = vadc_get_dt_data(vadc, node);
if (ret)
return ret;
irq_eoc = platform_get_irq(pdev, 0);
if (irq_eoc < 0) {
if (irq_eoc == -EPROBE_DEFER || irq_eoc == -EINVAL)
return irq_eoc;
vadc->poll_eoc = true;
} else {
ret = devm_request_irq(dev, irq_eoc, vadc_isr, 0,
"spmi-vadc", vadc);
if (ret)
return ret;
}
ret = vadc_reset(vadc);
if (ret) {
dev_err(dev, "reset failed\n");
return ret;
}
ret = vadc_measure_ref_points(vadc);
if (ret)
return ret;
indio_dev->dev.parent = dev;
indio_dev->dev.of_node = node;
indio_dev->name = pdev->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &vadc_info;
indio_dev->channels = vadc->iio_chans;
indio_dev->num_channels = vadc->nchannels;
return devm_iio_device_register(dev, indio_dev);
}
