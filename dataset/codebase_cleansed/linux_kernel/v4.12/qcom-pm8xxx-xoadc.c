static irqreturn_t pm8xxx_eoc_irq(int irq, void *d)
{
struct iio_dev *indio_dev = d;
struct pm8xxx_xoadc *adc = iio_priv(indio_dev);
complete(&adc->complete);
return IRQ_HANDLED;
}
static struct pm8xxx_chan_info *
pm8xxx_get_channel(struct pm8xxx_xoadc *adc, u8 chan)
{
struct pm8xxx_chan_info *ch;
int i;
for (i = 0; i < adc->nchans; i++) {
ch = &adc->chans[i];
if (ch->hwchan->amux_channel == chan)
break;
}
if (i == adc->nchans)
return NULL;
return ch;
}
static int pm8xxx_read_channel_rsv(struct pm8xxx_xoadc *adc,
const struct pm8xxx_chan_info *ch,
u8 rsv, u16 *adc_code,
bool force_ratiometric)
{
int ret;
unsigned int val;
u8 rsvmask, rsvval;
u8 lsb, msb;
dev_dbg(adc->dev, "read channel \"%s\", amux %d, prescale/mux: %d, rsv %d\n",
ch->name, ch->hwchan->amux_channel, ch->hwchan->pre_scale_mux, rsv);
mutex_lock(&adc->lock);
val = ch->hwchan->amux_channel << ADC_AMUX_SEL_SHIFT;
val |= ch->hwchan->pre_scale_mux << ADC_AMUX_PREMUX_SHIFT;
ret = regmap_write(adc->map, ADC_ARB_USRP_AMUX_CNTRL, val);
if (ret)
goto unlock;
rsvmask = (ADC_ARB_USRP_RSV_RST | ADC_ARB_USRP_RSV_DTEST0 |
ADC_ARB_USRP_RSV_DTEST1 | ADC_ARB_USRP_RSV_OP);
if (adc->variant->broken_ratiometric && !force_ratiometric) {
if (ch->hwchan->amux_channel == PM8XXX_CHANNEL_MUXOFF)
rsvval = ADC_ARB_USRP_RSV_IP_SEL0;
else
rsvval = ADC_ARB_USRP_RSV_IP_SEL1;
} else {
if (rsv == 0xff)
rsvval = (ch->amux_ip_rsv << ADC_RSV_IP_SEL_SHIFT) |
ADC_ARB_USRP_RSV_TRM;
else
rsvval = (rsv << ADC_RSV_IP_SEL_SHIFT) |
ADC_ARB_USRP_RSV_TRM;
}
ret = regmap_update_bits(adc->map,
ADC_ARB_USRP_RSV,
~rsvmask,
rsvval);
if (ret)
goto unlock;
ret = regmap_write(adc->map, ADC_ARB_USRP_ANA_PARAM,
ADC_ARB_USRP_ANA_PARAM_DIS);
if (ret)
goto unlock;
ret = regmap_write(adc->map, ADC_ARB_USRP_DIG_PARAM,
ADC_ARB_USRP_DIG_PARAM_SEL_SHIFT0 |
ADC_ARB_USRP_DIG_PARAM_SEL_SHIFT1 |
ch->decimation << ADC_DIG_PARAM_DEC_SHIFT);
if (ret)
goto unlock;
ret = regmap_write(adc->map, ADC_ARB_USRP_ANA_PARAM,
ADC_ARB_USRP_ANA_PARAM_EN);
if (ret)
goto unlock;
ret = regmap_write(adc->map, ADC_ARB_USRP_CNTRL,
ADC_ARB_USRP_CNTRL_EN_ARB);
if (ret)
goto unlock;
ret = regmap_write(adc->map, ADC_ARB_USRP_CNTRL,
ADC_ARB_USRP_CNTRL_EN_ARB);
if (ret)
goto unlock;
reinit_completion(&adc->complete);
ret = regmap_write(adc->map, ADC_ARB_USRP_CNTRL,
ADC_ARB_USRP_CNTRL_EN_ARB |
ADC_ARB_USRP_CNTRL_REQ);
if (ret)
goto unlock;
ret = wait_for_completion_timeout(&adc->complete,
VADC_CONV_TIME_MAX_US);
if (!ret) {
dev_err(adc->dev, "conversion timed out\n");
ret = -ETIMEDOUT;
goto unlock;
}
ret = regmap_read(adc->map, ADC_ARB_USRP_DATA0, &val);
if (ret)
goto unlock;
lsb = val;
ret = regmap_read(adc->map, ADC_ARB_USRP_DATA1, &val);
if (ret)
goto unlock;
msb = val;
*adc_code = (msb << 8) | lsb;
ret = regmap_write(adc->map, ADC_ARB_USRP_CNTRL, 0);
if (ret)
goto unlock;
ret = regmap_write(adc->map, ADC_ARB_USRP_CNTRL, 0);
if (ret)
goto unlock;
unlock:
mutex_unlock(&adc->lock);
return ret;
}
static int pm8xxx_read_channel(struct pm8xxx_xoadc *adc,
const struct pm8xxx_chan_info *ch,
u16 *adc_code)
{
return pm8xxx_read_channel_rsv(adc, ch, 0xff, adc_code, false);
}
static int pm8xxx_calibrate_device(struct pm8xxx_xoadc *adc)
{
const struct pm8xxx_chan_info *ch;
u16 read_1250v;
u16 read_0625v;
u16 read_nomux_rsv5;
u16 read_nomux_rsv4;
int ret;
adc->graph[VADC_CALIB_ABSOLUTE].dx = VADC_ABSOLUTE_RANGE_UV;
adc->graph[VADC_CALIB_RATIOMETRIC].dx = VADC_RATIOMETRIC_RANGE;
ch = pm8xxx_get_channel(adc, PM8XXX_CHANNEL_125V);
if (!ch)
return -ENODEV;
ret = pm8xxx_read_channel(adc, ch, &read_1250v);
if (ret) {
dev_err(adc->dev, "could not read 1.25V reference channel\n");
return -ENODEV;
}
ch = pm8xxx_get_channel(adc, PM8XXX_CHANNEL_INTERNAL);
if (!ch)
return -ENODEV;
ret = pm8xxx_read_channel(adc, ch, &read_0625v);
if (ret) {
dev_err(adc->dev, "could not read 0.625V reference channel\n");
return -ENODEV;
}
if (read_1250v == read_0625v) {
dev_err(adc->dev, "read same ADC code for 1.25V and 0.625V\n");
return -ENODEV;
}
adc->graph[VADC_CALIB_ABSOLUTE].dy = read_1250v - read_0625v;
adc->graph[VADC_CALIB_ABSOLUTE].gnd = read_0625v;
dev_info(adc->dev, "absolute calibration dx = %d uV, dy = %d units\n",
VADC_ABSOLUTE_RANGE_UV, adc->graph[VADC_CALIB_ABSOLUTE].dy);
ch = pm8xxx_get_channel(adc, PM8XXX_CHANNEL_MUXOFF);
if (!ch)
return -ENODEV;
ret = pm8xxx_read_channel_rsv(adc, ch, AMUX_RSV5,
&read_nomux_rsv5, true);
if (ret) {
dev_err(adc->dev, "could not read MUXOFF reference channel\n");
return -ENODEV;
}
ret = pm8xxx_read_channel_rsv(adc, ch, AMUX_RSV4,
&read_nomux_rsv4, true);
if (ret) {
dev_err(adc->dev, "could not read MUXOFF reference channel\n");
return -ENODEV;
}
adc->graph[VADC_CALIB_RATIOMETRIC].dy =
read_nomux_rsv5 - read_nomux_rsv4;
adc->graph[VADC_CALIB_RATIOMETRIC].gnd = read_nomux_rsv4;
dev_info(adc->dev, "ratiometric calibration dx = %d, dy = %d units\n",
VADC_RATIOMETRIC_RANGE,
adc->graph[VADC_CALIB_RATIOMETRIC].dy);
return 0;
}
static int pm8xxx_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct pm8xxx_xoadc *adc = iio_priv(indio_dev);
const struct pm8xxx_chan_info *ch;
u16 adc_code;
int ret;
switch (mask) {
case IIO_CHAN_INFO_PROCESSED:
ch = pm8xxx_get_channel(adc, chan->address);
if (!ch) {
dev_err(adc->dev, "no such channel %lu\n",
chan->address);
return -EINVAL;
}
ret = pm8xxx_read_channel(adc, ch, &adc_code);
if (ret)
return ret;
ret = qcom_vadc_scale(ch->hwchan->scale_fn_type,
&adc->graph[ch->calibration],
&ch->hwchan->prescale,
(ch->calibration == VADC_CALIB_ABSOLUTE),
adc_code, val);
if (ret)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_RAW:
ch = pm8xxx_get_channel(adc, chan->address);
if (!ch) {
dev_err(adc->dev, "no such channel %lu\n",
chan->address);
return -EINVAL;
}
ret = pm8xxx_read_channel(adc, ch, &adc_code);
if (ret)
return ret;
*val = (int)adc_code;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int pm8xxx_of_xlate(struct iio_dev *indio_dev,
const struct of_phandle_args *iiospec)
{
struct pm8xxx_xoadc *adc = iio_priv(indio_dev);
u8 pre_scale_mux;
u8 amux_channel;
unsigned int i;
if (iiospec->args_count != 2) {
dev_err(&indio_dev->dev, "wrong number of arguments for %s need 2 got %d\n",
iiospec->np->name,
iiospec->args_count);
return -EINVAL;
}
pre_scale_mux = (u8)iiospec->args[0];
amux_channel = (u8)iiospec->args[1];
dev_dbg(&indio_dev->dev, "pre scale/mux: %02x, amux: %02x\n",
pre_scale_mux, amux_channel);
for (i = 0; i < adc->nchans; i++)
if (adc->chans[i].hwchan->pre_scale_mux == pre_scale_mux &&
adc->chans[i].hwchan->amux_channel == amux_channel)
return i;
return -EINVAL;
}
static int pm8xxx_xoadc_parse_channel(struct device *dev,
struct device_node *np,
const struct xoadc_channel *hw_channels,
struct iio_chan_spec *iio_chan,
struct pm8xxx_chan_info *ch)
{
const char *name = np->name;
const struct xoadc_channel *hwchan;
u32 pre_scale_mux, amux_channel;
u32 rsv, dec;
int ret;
int chid;
ret = of_property_read_u32_index(np, "reg", 0, &pre_scale_mux);
if (ret) {
dev_err(dev, "invalid pre scale/mux number %s\n", name);
return ret;
}
ret = of_property_read_u32_index(np, "reg", 1, &amux_channel);
if (ret) {
dev_err(dev, "invalid amux channel number %s\n", name);
return ret;
}
chid = 0;
hwchan = &hw_channels[0];
while (hwchan && hwchan->datasheet_name) {
if (hwchan->pre_scale_mux == pre_scale_mux &&
hwchan->amux_channel == amux_channel)
break;
hwchan++;
chid++;
}
if (!hwchan->datasheet_name) {
dev_err(dev, "could not locate channel %02x/%02x\n",
pre_scale_mux, amux_channel);
return -EINVAL;
}
ch->name = name;
ch->hwchan = hwchan;
ch->calibration = VADC_CALIB_ABSOLUTE;
ch->decimation = VADC_DEF_DECIMATION;
if (!of_property_read_u32(np, "qcom,ratiometric", &rsv)) {
ch->calibration = VADC_CALIB_RATIOMETRIC;
if (rsv > XOADC_RSV_MAX) {
dev_err(dev, "%s too large RSV value %d\n", name, rsv);
return -EINVAL;
}
if (rsv == AMUX_RSV3) {
dev_err(dev, "%s invalid RSV value %d\n", name, rsv);
return -EINVAL;
}
}
ret = of_property_read_u32(np, "qcom,decimation", &dec);
if (!ret) {
ret = qcom_vadc_decimation_from_dt(dec);
if (ret < 0) {
dev_err(dev, "%s invalid decimation %d\n",
name, dec);
return ret;
}
ch->decimation = ret;
}
iio_chan->channel = chid;
iio_chan->address = hwchan->amux_channel;
iio_chan->datasheet_name = hwchan->datasheet_name;
iio_chan->type = hwchan->type;
iio_chan->info_mask_separate = BIT(IIO_CHAN_INFO_RAW) |
BIT(IIO_CHAN_INFO_PROCESSED);
iio_chan->indexed = 1;
dev_dbg(dev, "channel [PRESCALE/MUX: %02x AMUX: %02x] \"%s\" "
"ref voltage: %d, decimation %d "
"prescale %d/%d, scale function %d\n",
hwchan->pre_scale_mux, hwchan->amux_channel, ch->name,
ch->amux_ip_rsv, ch->decimation, hwchan->prescale.num,
hwchan->prescale.den, hwchan->scale_fn_type);
return 0;
}
static int pm8xxx_xoadc_parse_channels(struct pm8xxx_xoadc *adc,
struct device_node *np)
{
struct device_node *child;
struct pm8xxx_chan_info *ch;
int ret;
int i;
adc->nchans = of_get_available_child_count(np);
if (!adc->nchans) {
dev_err(adc->dev, "no channel children\n");
return -ENODEV;
}
dev_dbg(adc->dev, "found %d ADC channels\n", adc->nchans);
adc->iio_chans = devm_kcalloc(adc->dev, adc->nchans,
sizeof(*adc->iio_chans), GFP_KERNEL);
if (!adc->iio_chans)
return -ENOMEM;
adc->chans = devm_kcalloc(adc->dev, adc->nchans,
sizeof(*adc->chans), GFP_KERNEL);
if (!adc->chans)
return -ENOMEM;
i = 0;
for_each_available_child_of_node(np, child) {
ch = &adc->chans[i];
ret = pm8xxx_xoadc_parse_channel(adc->dev, child,
adc->variant->channels,
&adc->iio_chans[i],
ch);
if (ret) {
of_node_put(child);
return ret;
}
i++;
}
ch = pm8xxx_get_channel(adc, PM8XXX_CHANNEL_125V);
if (!ch) {
dev_err(adc->dev, "missing 1.25V reference channel\n");
return -ENODEV;
}
ch = pm8xxx_get_channel(adc, PM8XXX_CHANNEL_INTERNAL);
if (!ch) {
dev_err(adc->dev, "missing 0.625V reference channel\n");
return -ENODEV;
}
ch = pm8xxx_get_channel(adc, PM8XXX_CHANNEL_MUXOFF);
if (!ch) {
dev_err(adc->dev, "missing MUXOFF reference channel\n");
return -ENODEV;
}
return 0;
}
static int pm8xxx_xoadc_probe(struct platform_device *pdev)
{
const struct xoadc_variant *variant;
struct pm8xxx_xoadc *adc;
struct iio_dev *indio_dev;
struct device_node *np = pdev->dev.of_node;
struct regmap *map;
struct device *dev = &pdev->dev;
int ret;
variant = of_device_get_match_data(dev);
if (!variant)
return -ENODEV;
indio_dev = devm_iio_device_alloc(dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
platform_set_drvdata(pdev, indio_dev);
adc = iio_priv(indio_dev);
adc->dev = dev;
adc->variant = variant;
init_completion(&adc->complete);
mutex_init(&adc->lock);
ret = pm8xxx_xoadc_parse_channels(adc, np);
if (ret)
return ret;
map = dev_get_regmap(dev->parent, NULL);
if (!map) {
dev_err(dev, "parent regmap unavailable.\n");
return -ENXIO;
}
adc->map = map;
adc->vref = devm_regulator_get(dev, "xoadc-ref");
if (IS_ERR(adc->vref)) {
dev_err(dev, "failed to get XOADC VREF regulator\n");
return PTR_ERR(adc->vref);
}
ret = regulator_enable(adc->vref);
if (ret) {
dev_err(dev, "failed to enable XOADC VREF regulator\n");
return ret;
}
ret = devm_request_threaded_irq(dev, platform_get_irq(pdev, 0),
pm8xxx_eoc_irq, NULL, 0, variant->name, indio_dev);
if (ret) {
dev_err(dev, "unable to request IRQ\n");
goto out_disable_vref;
}
indio_dev->dev.parent = dev;
indio_dev->dev.of_node = np;
indio_dev->name = variant->name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &pm8xxx_xoadc_info;
indio_dev->channels = adc->iio_chans;
indio_dev->num_channels = adc->nchans;
ret = iio_device_register(indio_dev);
if (ret)
goto out_disable_vref;
ret = pm8xxx_calibrate_device(adc);
if (ret)
goto out_unreg_device;
dev_info(dev, "%s XOADC driver enabled\n", variant->name);
return 0;
out_unreg_device:
iio_device_unregister(indio_dev);
out_disable_vref:
regulator_disable(adc->vref);
return ret;
}
static int pm8xxx_xoadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct pm8xxx_xoadc *adc = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regulator_disable(adc->vref);
return 0;
}
