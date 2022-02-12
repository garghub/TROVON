static irqreturn_t cm3605_prox_irq(int irq, void *d)
{
struct iio_dev *indio_dev = d;
struct cm3605 *cm3605 = iio_priv(indio_dev);
u64 ev;
ev = IIO_UNMOD_EVENT_CODE(IIO_PROXIMITY, CM3605_PROX_CHANNEL,
IIO_EV_TYPE_THRESH, cm3605->dir);
iio_push_event(indio_dev, ev, iio_get_time_ns(indio_dev));
if (cm3605->dir == IIO_EV_DIR_RISING)
cm3605->dir = IIO_EV_DIR_FALLING;
else
cm3605->dir = IIO_EV_DIR_RISING;
return IRQ_HANDLED;
}
static int cm3605_get_lux(struct cm3605 *cm3605)
{
int ret, res;
s64 lux;
ret = iio_read_channel_processed(cm3605->aout, &res);
if (ret < 0)
return ret;
dev_dbg(cm3605->dev, "read %d mV from ADC\n", res);
if (res < 30)
return 0;
if (res > CM3605_AOUT_MAX_MV)
dev_err(cm3605->dev, "device out of range\n");
lux = res - 30;
lux *= cm3605->als_max;
lux = div64_s64(lux, CM3605_AOUT_TYP_MAX_MV);
return lux;
}
static int cm3605_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cm3605 *cm3605 = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->type) {
case IIO_LIGHT:
ret = cm3605_get_lux(cm3605);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
default:
return -EINVAL;
}
}
static int cm3605_probe(struct platform_device *pdev)
{
struct cm3605 *cm3605;
struct iio_dev *indio_dev;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
enum iio_chan_type ch_type;
u32 rset;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*cm3605));
if (!indio_dev)
return -ENOMEM;
platform_set_drvdata(pdev, indio_dev);
cm3605 = iio_priv(indio_dev);
cm3605->dev = dev;
cm3605->dir = IIO_EV_DIR_FALLING;
ret = of_property_read_u32(np, "capella,aset-resistance-ohms", &rset);
if (ret) {
dev_info(dev, "no RSET specified, assuming 100K\n");
rset = 100000;
}
switch (rset) {
case 50000:
cm3605->als_max = 650;
break;
case 100000:
cm3605->als_max = 300;
break;
case 300000:
cm3605->als_max = 100;
break;
case 600000:
cm3605->als_max = 50;
break;
default:
dev_info(dev, "non-standard resistance\n");
return -EINVAL;
}
cm3605->aout = devm_iio_channel_get(dev, "aout");
if (IS_ERR(cm3605->aout)) {
if (PTR_ERR(cm3605->aout) == -ENODEV) {
dev_err(dev, "no ADC, deferring...\n");
return -EPROBE_DEFER;
}
dev_err(dev, "failed to get AOUT ADC channel\n");
return PTR_ERR(cm3605->aout);
}
ret = iio_get_channel_type(cm3605->aout, &ch_type);
if (ret < 0)
return ret;
if (ch_type != IIO_VOLTAGE) {
dev_err(dev, "wrong type of IIO channel specified for AOUT\n");
return -EINVAL;
}
cm3605->vdd = devm_regulator_get(dev, "vdd");
if (IS_ERR(cm3605->vdd)) {
dev_err(dev, "failed to get VDD regulator\n");
return PTR_ERR(cm3605->vdd);
}
ret = regulator_enable(cm3605->vdd);
if (ret) {
dev_err(dev, "failed to enable VDD regulator\n");
return ret;
}
cm3605->aset = devm_gpiod_get(dev, "aset", GPIOD_OUT_HIGH);
if (IS_ERR(cm3605->aset)) {
dev_err(dev, "no ASET GPIO\n");
ret = PTR_ERR(cm3605->aset);
goto out_disable_vdd;
}
ret = devm_request_threaded_irq(dev, platform_get_irq(pdev, 0),
cm3605_prox_irq, NULL, 0, "cm3605", indio_dev);
if (ret) {
dev_err(dev, "unable to request IRQ\n");
goto out_disable_aset;
}
led_trigger_register_simple("cm3605", &cm3605->led);
led_trigger_event(cm3605->led, LED_FULL);
indio_dev->dev.parent = dev;
indio_dev->info = &cm3605_info;
indio_dev->name = "cm3605";
indio_dev->channels = cm3605_channels;
indio_dev->num_channels = ARRAY_SIZE(cm3605_channels);
indio_dev->modes = INDIO_DIRECT_MODE;
ret = iio_device_register(indio_dev);
if (ret)
goto out_remove_trigger;
dev_info(dev, "Capella Microsystems CM3605 enabled range 0..%d LUX\n",
cm3605->als_max);
return 0;
out_remove_trigger:
led_trigger_event(cm3605->led, LED_OFF);
led_trigger_unregister_simple(cm3605->led);
out_disable_aset:
gpiod_set_value_cansleep(cm3605->aset, 0);
out_disable_vdd:
regulator_disable(cm3605->vdd);
return ret;
}
static int cm3605_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct cm3605 *cm3605 = iio_priv(indio_dev);
led_trigger_event(cm3605->led, LED_OFF);
led_trigger_unregister_simple(cm3605->led);
gpiod_set_value_cansleep(cm3605->aset, 0);
iio_device_unregister(indio_dev);
regulator_disable(cm3605->vdd);
return 0;
}
static int __maybe_unused cm3605_pm_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct cm3605 *cm3605 = iio_priv(indio_dev);
led_trigger_event(cm3605->led, LED_OFF);
regulator_disable(cm3605->vdd);
return 0;
}
static int __maybe_unused cm3605_pm_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct cm3605 *cm3605 = iio_priv(indio_dev);
int ret;
ret = regulator_enable(cm3605->vdd);
if (ret)
dev_err(dev, "failed to enable regulator in resume path\n");
led_trigger_event(cm3605->led, LED_FULL);
return 0;
}
