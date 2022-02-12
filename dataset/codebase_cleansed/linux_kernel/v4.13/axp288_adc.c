static int axp288_adc_read_channel(int *val, unsigned long address,
struct regmap *regmap)
{
u8 buf[2];
if (regmap_bulk_read(regmap, address, buf, 2))
return -EIO;
*val = (buf[0] << 4) + ((buf[1] >> 4) & 0x0F);
return IIO_VAL_INT;
}
static int axp288_adc_set_ts(struct regmap *regmap, unsigned int mode,
unsigned long address)
{
int ret;
if (address != AXP288_GP_ADC_H)
return 0;
ret = regmap_write(regmap, AXP288_ADC_TS_PIN_CTRL, mode);
if (ret)
return ret;
if (mode == AXP288_ADC_TS_PIN_GPADC)
usleep_range(6000, 10000);
return 0;
}
static int axp288_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct axp288_adc_info *info = iio_priv(indio_dev);
mutex_lock(&indio_dev->mlock);
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (axp288_adc_set_ts(info->regmap, AXP288_ADC_TS_PIN_GPADC,
chan->address)) {
dev_err(&indio_dev->dev, "GPADC mode\n");
ret = -EINVAL;
break;
}
ret = axp288_adc_read_channel(val, chan->address, info->regmap);
if (axp288_adc_set_ts(info->regmap, AXP288_ADC_TS_PIN_ON,
chan->address))
dev_err(&indio_dev->dev, "TS pin restore\n");
break;
default:
ret = -EINVAL;
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int axp288_adc_set_state(struct regmap *regmap)
{
if (regmap_write(regmap, AXP288_ADC_TS_PIN_CTRL, AXP288_ADC_TS_PIN_ON))
return -EIO;
return regmap_write(regmap, AXP20X_ADC_EN1, AXP288_ADC_EN_MASK);
}
static int axp288_adc_probe(struct platform_device *pdev)
{
int ret;
struct axp288_adc_info *info;
struct iio_dev *indio_dev;
struct axp20x_dev *axp20x = dev_get_drvdata(pdev->dev.parent);
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
if (!indio_dev)
return -ENOMEM;
info = iio_priv(indio_dev);
info->irq = platform_get_irq(pdev, 0);
if (info->irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return info->irq;
}
platform_set_drvdata(pdev, indio_dev);
info->regmap = axp20x->regmap;
ret = axp288_adc_set_state(axp20x->regmap);
if (ret) {
dev_err(&pdev->dev, "unable to enable ADC device\n");
return ret;
}
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = pdev->name;
indio_dev->channels = axp288_adc_channels;
indio_dev->num_channels = ARRAY_SIZE(axp288_adc_channels);
indio_dev->info = &axp288_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_map_array_register(indio_dev, axp288_adc_default_maps);
if (ret < 0)
return ret;
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&pdev->dev, "unable to register iio device\n");
goto err_array_unregister;
}
return 0;
err_array_unregister:
iio_map_array_unregister(indio_dev);
return ret;
}
static int axp288_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
iio_map_array_unregister(indio_dev);
return 0;
}
