static int axp20x_adc_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val)
{
struct axp20x_adc_iio *info = iio_priv(indio_dev);
int size = 12;
if (chan->type == IIO_CURRENT && chan->channel == AXP20X_BATT_DISCHRG_I)
size = 13;
else
size = 12;
*val = axp20x_read_variable_width(info->regmap, chan->address, size);
if (*val < 0)
return *val;
return IIO_VAL_INT;
}
static int axp22x_adc_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val)
{
struct axp20x_adc_iio *info = iio_priv(indio_dev);
int size;
if (chan->type == IIO_CURRENT && chan->channel == AXP22X_BATT_DISCHRG_I)
size = 13;
else
size = 12;
*val = axp20x_read_variable_width(info->regmap, chan->address, size);
if (*val < 0)
return *val;
return IIO_VAL_INT;
}
static int axp20x_adc_scale_voltage(int channel, int *val, int *val2)
{
switch (channel) {
case AXP20X_ACIN_V:
case AXP20X_VBUS_V:
*val = 1;
*val2 = 700000;
return IIO_VAL_INT_PLUS_MICRO;
case AXP20X_GPIO0_V:
case AXP20X_GPIO1_V:
*val = 0;
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
case AXP20X_BATT_V:
*val = 1;
*val2 = 100000;
return IIO_VAL_INT_PLUS_MICRO;
case AXP20X_IPSOUT_V:
*val = 1;
*val2 = 400000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int axp20x_adc_scale_current(int channel, int *val, int *val2)
{
switch (channel) {
case AXP20X_ACIN_I:
*val = 0;
*val2 = 625000;
return IIO_VAL_INT_PLUS_MICRO;
case AXP20X_VBUS_I:
*val = 0;
*val2 = 375000;
return IIO_VAL_INT_PLUS_MICRO;
case AXP20X_BATT_DISCHRG_I:
case AXP20X_BATT_CHRG_I:
*val = 0;
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int axp20x_adc_scale(struct iio_chan_spec const *chan, int *val,
int *val2)
{
switch (chan->type) {
case IIO_VOLTAGE:
return axp20x_adc_scale_voltage(chan->channel, val, val2);
case IIO_CURRENT:
return axp20x_adc_scale_current(chan->channel, val, val2);
case IIO_TEMP:
*val = 100;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int axp22x_adc_scale(struct iio_chan_spec const *chan, int *val,
int *val2)
{
switch (chan->type) {
case IIO_VOLTAGE:
if (chan->channel != AXP22X_BATT_V)
return -EINVAL;
*val = 1;
*val2 = 100000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_CURRENT:
*val = 0;
*val2 = 500000;
return IIO_VAL_INT_PLUS_MICRO;
case IIO_TEMP:
*val = 100;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int axp20x_adc_offset_voltage(struct iio_dev *indio_dev, int channel,
int *val)
{
struct axp20x_adc_iio *info = iio_priv(indio_dev);
int ret;
ret = regmap_read(info->regmap, AXP20X_GPIO10_IN_RANGE, val);
if (ret < 0)
return ret;
switch (channel) {
case AXP20X_GPIO0_V:
*val &= AXP20X_GPIO10_IN_RANGE_GPIO0;
break;
case AXP20X_GPIO1_V:
*val &= AXP20X_GPIO10_IN_RANGE_GPIO1;
break;
default:
return -EINVAL;
}
*val = !!(*val) * 700000;
return IIO_VAL_INT;
}
static int axp20x_adc_offset(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val)
{
switch (chan->type) {
case IIO_VOLTAGE:
return axp20x_adc_offset_voltage(indio_dev, chan->channel, val);
case IIO_TEMP:
*val = -1447;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int axp20x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
switch (mask) {
case IIO_CHAN_INFO_OFFSET:
return axp20x_adc_offset(indio_dev, chan, val);
case IIO_CHAN_INFO_SCALE:
return axp20x_adc_scale(chan, val, val2);
case IIO_CHAN_INFO_RAW:
return axp20x_adc_raw(indio_dev, chan, val);
default:
return -EINVAL;
}
}
static int axp22x_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
switch (mask) {
case IIO_CHAN_INFO_OFFSET:
*val = -2677;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
return axp22x_adc_scale(chan, val, val2);
case IIO_CHAN_INFO_RAW:
return axp22x_adc_raw(indio_dev, chan, val);
default:
return -EINVAL;
}
}
static int axp20x_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int val, int val2,
long mask)
{
struct axp20x_adc_iio *info = iio_priv(indio_dev);
unsigned int reg, regval;
if (mask != IIO_CHAN_INFO_OFFSET)
return -EINVAL;
if (val != 0 && val != 700000)
return -EINVAL;
switch (chan->channel) {
case AXP20X_GPIO0_V:
reg = AXP20X_GPIO10_IN_RANGE_GPIO0;
regval = AXP20X_GPIO10_IN_RANGE_GPIO0_VAL(!!val);
break;
case AXP20X_GPIO1_V:
reg = AXP20X_GPIO10_IN_RANGE_GPIO1;
regval = AXP20X_GPIO10_IN_RANGE_GPIO1_VAL(!!val);
break;
default:
return -EINVAL;
}
return regmap_update_bits(info->regmap, AXP20X_GPIO10_IN_RANGE, reg,
regval);
}
static int axp20x_adc_rate(int rate)
{
return AXP20X_ADC_RATE_HZ(rate);
}
static int axp22x_adc_rate(int rate)
{
return AXP22X_ADC_RATE_HZ(rate);
}
static int axp20x_probe(struct platform_device *pdev)
{
struct axp20x_adc_iio *info;
struct iio_dev *indio_dev;
struct axp20x_dev *axp20x_dev;
int ret;
axp20x_dev = dev_get_drvdata(pdev->dev.parent);
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
if (!indio_dev)
return -ENOMEM;
info = iio_priv(indio_dev);
platform_set_drvdata(pdev, indio_dev);
info->regmap = axp20x_dev->regmap;
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->modes = INDIO_DIRECT_MODE;
info->data = (struct axp_data *)platform_get_device_id(pdev)->driver_data;
indio_dev->name = platform_get_device_id(pdev)->name;
indio_dev->info = info->data->iio_info;
indio_dev->num_channels = info->data->num_channels;
indio_dev->channels = info->data->channels;
regmap_write(info->regmap, AXP20X_ADC_EN1, info->data->adc_en1_mask);
if (info->data->adc_en2)
regmap_update_bits(info->regmap, AXP20X_ADC_EN2,
AXP20X_ADC_EN2_MASK, AXP20X_ADC_EN2_MASK);
regmap_update_bits(info->regmap, AXP20X_ADC_RATE, AXP20X_ADC_RATE_MASK,
info->data->adc_rate(100));
ret = iio_map_array_register(indio_dev, info->data->maps);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register IIO maps: %d\n", ret);
goto fail_map;
}
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&pdev->dev, "could not register the device\n");
goto fail_register;
}
return 0;
fail_register:
iio_map_array_unregister(indio_dev);
fail_map:
regmap_write(info->regmap, AXP20X_ADC_EN1, 0);
if (info->data->adc_en2)
regmap_write(info->regmap, AXP20X_ADC_EN2, 0);
return ret;
}
static int axp20x_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct axp20x_adc_iio *info = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_map_array_unregister(indio_dev);
regmap_write(info->regmap, AXP20X_ADC_EN1, 0);
if (info->data->adc_en2)
regmap_write(info->regmap, AXP20X_ADC_EN2, 0);
return 0;
}
