static irqreturn_t da9150_gpadc_irq(int irq, void *data)
{
struct da9150_gpadc *gpadc = data;
complete(&gpadc->complete);
return IRQ_HANDLED;
}
static int da9150_gpadc_read_adc(struct da9150_gpadc *gpadc, int hw_chan)
{
u8 result_regs[2];
int result;
mutex_lock(&gpadc->lock);
da9150_reg_write(gpadc->da9150, DA9150_GPADC_MAN,
(DA9150_GPADC_EN_MASK |
hw_chan << DA9150_GPADC_MUX_SHIFT));
try_wait_for_completion(&gpadc->complete);
wait_for_completion_timeout(&gpadc->complete, msecs_to_jiffies(5));
da9150_bulk_read(gpadc->da9150, DA9150_GPADC_RES_A, 2, result_regs);
mutex_unlock(&gpadc->lock);
if (result_regs[1] & DA9150_GPADC_RUN_MASK) {
dev_err(gpadc->dev, "Timeout on channel %d of GPADC\n",
hw_chan);
return -ETIMEDOUT;
}
result = (result_regs[1] & DA9150_GPADC_RES_L_MASK) >>
DA9150_GPADC_RES_L_SHIFT;
result |= result_regs[0] << DA9150_GPADC_RES_L_BITS;
return result;
}
static inline int da9150_gpadc_gpio_6v_voltage_now(int raw_val)
{
return (6 * ((raw_val * 1000) + 500)) / 1024;
}
static inline int da9150_gpadc_ibus_current_avg(int raw_val)
{
return (4 * ((raw_val * 1000) + 500)) / 2048;
}
static inline int da9150_gpadc_vbus_21v_voltage_now(int raw_val)
{
return (21 * ((raw_val * 1000) + 500)) / 1024;
}
static inline int da9150_gpadc_vsys_6v_voltage_now(int raw_val)
{
return (3 * ((raw_val * 1000) + 500)) / 512;
}
static int da9150_gpadc_read_processed(struct da9150_gpadc *gpadc, int channel,
int hw_chan, int *val)
{
int raw_val;
raw_val = da9150_gpadc_read_adc(gpadc, hw_chan);
if (raw_val < 0)
return raw_val;
switch (channel) {
case DA9150_GPADC_CHAN_GPIOA:
case DA9150_GPADC_CHAN_GPIOB:
case DA9150_GPADC_CHAN_GPIOC:
case DA9150_GPADC_CHAN_GPIOD:
*val = da9150_gpadc_gpio_6v_voltage_now(raw_val);
break;
case DA9150_GPADC_CHAN_IBUS:
*val = da9150_gpadc_ibus_current_avg(raw_val);
break;
case DA9150_GPADC_CHAN_VBUS:
*val = da9150_gpadc_vbus_21v_voltage_now(raw_val);
break;
case DA9150_GPADC_CHAN_VSYS:
*val = da9150_gpadc_vsys_6v_voltage_now(raw_val);
break;
default:
*val = raw_val;
break;
}
return IIO_VAL_INT;
}
static int da9150_gpadc_read_scale(int channel, int *val, int *val2)
{
switch (channel) {
case DA9150_GPADC_CHAN_VBAT:
*val = 2932;
*val2 = 1000;
return IIO_VAL_FRACTIONAL;
case DA9150_GPADC_CHAN_TJUNC_CORE:
case DA9150_GPADC_CHAN_TJUNC_OVP:
*val = 1000000;
*val2 = 4420;
return IIO_VAL_FRACTIONAL;
default:
return -EINVAL;
}
}
static int da9150_gpadc_read_offset(int channel, int *val)
{
switch (channel) {
case DA9150_GPADC_CHAN_VBAT:
*val = 1500000 / 2932;
return IIO_VAL_INT;
case DA9150_GPADC_CHAN_TJUNC_CORE:
case DA9150_GPADC_CHAN_TJUNC_OVP:
*val = -144;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int da9150_gpadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct da9150_gpadc *gpadc = iio_priv(indio_dev);
if ((chan->channel < DA9150_GPADC_CHAN_GPIOA) ||
(chan->channel > DA9150_GPADC_CHAN_TJUNC_OVP))
return -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
return da9150_gpadc_read_processed(gpadc, chan->channel,
chan->address, val);
case IIO_CHAN_INFO_SCALE:
return da9150_gpadc_read_scale(chan->channel, val, val2);
case IIO_CHAN_INFO_OFFSET:
return da9150_gpadc_read_offset(chan->channel, val);
default:
return -EINVAL;
}
}
static int da9150_gpadc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct da9150 *da9150 = dev_get_drvdata(dev->parent);
struct da9150_gpadc *gpadc;
struct iio_dev *indio_dev;
int irq, ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*gpadc));
if (!indio_dev) {
dev_err(&pdev->dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
gpadc = iio_priv(indio_dev);
platform_set_drvdata(pdev, indio_dev);
gpadc->da9150 = da9150;
gpadc->dev = dev;
mutex_init(&gpadc->lock);
init_completion(&gpadc->complete);
irq = platform_get_irq_byname(pdev, "GPADC");
if (irq < 0) {
dev_err(dev, "Failed to get IRQ: %d\n", irq);
return irq;
}
ret = devm_request_threaded_irq(dev, irq, NULL, da9150_gpadc_irq,
IRQF_ONESHOT, "GPADC", gpadc);
if (ret) {
dev_err(dev, "Failed to request IRQ %d: %d\n", irq, ret);
return ret;
}
ret = iio_map_array_register(indio_dev, da9150_gpadc_default_maps);
if (ret) {
dev_err(dev, "Failed to register IIO maps: %d\n", ret);
return ret;
}
indio_dev->name = dev_name(dev);
indio_dev->dev.parent = dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &da9150_gpadc_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = da9150_gpadc_channels;
indio_dev->num_channels = ARRAY_SIZE(da9150_gpadc_channels);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(dev, "Failed to register IIO device: %d\n", ret);
goto iio_map_unreg;
}
return 0;
iio_map_unreg:
iio_map_array_unregister(indio_dev);
return ret;
}
static int da9150_gpadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
iio_device_unregister(indio_dev);
iio_map_array_unregister(indio_dev);
return 0;
}
