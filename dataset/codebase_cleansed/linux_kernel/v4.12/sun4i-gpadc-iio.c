static unsigned int sun4i_gpadc_chan_select(unsigned int chan)
{
return SUN4I_GPADC_CTRL1_ADC_CHAN_SELECT(chan);
}
static unsigned int sun6i_gpadc_chan_select(unsigned int chan)
{
return SUN6I_GPADC_CTRL1_ADC_CHAN_SELECT(chan);
}
static int sun4i_prepare_for_irq(struct iio_dev *indio_dev, int channel,
unsigned int irq)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
int ret;
u32 reg;
pm_runtime_get_sync(indio_dev->dev.parent);
reinit_completion(&info->completion);
ret = regmap_write(info->regmap, SUN4I_GPADC_INT_FIFOC,
SUN4I_GPADC_INT_FIFOC_TP_FIFO_TRIG_LEVEL(1) |
SUN4I_GPADC_INT_FIFOC_TP_FIFO_FLUSH);
if (ret)
return ret;
ret = regmap_read(info->regmap, SUN4I_GPADC_CTRL1, &reg);
if (ret)
return ret;
if (irq == info->fifo_data_irq) {
ret = regmap_write(info->regmap, SUN4I_GPADC_CTRL1,
info->data->tp_mode_en |
info->data->tp_adc_select |
info->data->adc_chan_select(channel));
if ((reg & info->data->adc_chan_mask) !=
info->data->adc_chan_select(channel))
mdelay(10);
} else {
ret = regmap_write(info->regmap, SUN4I_GPADC_CTRL1,
info->data->tp_mode_en);
}
if (ret)
return ret;
if ((reg & info->data->tp_adc_select) != info->data->tp_adc_select)
mdelay(100);
return 0;
}
static int sun4i_gpadc_read(struct iio_dev *indio_dev, int channel, int *val,
unsigned int irq)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
int ret;
mutex_lock(&info->mutex);
ret = sun4i_prepare_for_irq(indio_dev, channel, irq);
if (ret)
goto err;
enable_irq(irq);
if (!wait_for_completion_timeout(&info->completion,
msecs_to_jiffies(1000))) {
ret = -ETIMEDOUT;
goto err;
}
if (irq == info->fifo_data_irq)
*val = info->adc_data;
else
*val = info->temp_data;
ret = 0;
pm_runtime_mark_last_busy(indio_dev->dev.parent);
err:
pm_runtime_put_autosuspend(indio_dev->dev.parent);
mutex_unlock(&info->mutex);
return ret;
}
static int sun4i_gpadc_adc_read(struct iio_dev *indio_dev, int channel,
int *val)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
return sun4i_gpadc_read(indio_dev, channel, val, info->fifo_data_irq);
}
static int sun4i_gpadc_temp_read(struct iio_dev *indio_dev, int *val)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
if (info->no_irq) {
pm_runtime_get_sync(indio_dev->dev.parent);
regmap_read(info->regmap, SUN4I_GPADC_TEMP_DATA, val);
pm_runtime_mark_last_busy(indio_dev->dev.parent);
pm_runtime_put_autosuspend(indio_dev->dev.parent);
return 0;
}
return sun4i_gpadc_read(indio_dev, 0, val, info->temp_data_irq);
}
static int sun4i_gpadc_temp_offset(struct iio_dev *indio_dev, int *val)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
*val = info->data->temp_offset;
return 0;
}
static int sun4i_gpadc_temp_scale(struct iio_dev *indio_dev, int *val)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
*val = info->data->temp_scale;
return 0;
}
static int sun4i_gpadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val,
int *val2, long mask)
{
int ret;
switch (mask) {
case IIO_CHAN_INFO_OFFSET:
ret = sun4i_gpadc_temp_offset(indio_dev, val);
if (ret)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_RAW:
if (chan->type == IIO_VOLTAGE)
ret = sun4i_gpadc_adc_read(indio_dev, chan->channel,
val);
else
ret = sun4i_gpadc_temp_read(indio_dev, val);
if (ret)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (chan->type == IIO_VOLTAGE) {
*val = 0;
*val2 = 732421875;
return IIO_VAL_INT_PLUS_NANO;
}
ret = sun4i_gpadc_temp_scale(indio_dev, val);
if (ret)
return ret;
return IIO_VAL_INT;
default:
return -EINVAL;
}
return -EINVAL;
}
static irqreturn_t sun4i_gpadc_temp_data_irq_handler(int irq, void *dev_id)
{
struct sun4i_gpadc_iio *info = dev_id;
if (atomic_read(&info->ignore_temp_data_irq))
goto out;
if (!regmap_read(info->regmap, SUN4I_GPADC_TEMP_DATA, &info->temp_data))
complete(&info->completion);
out:
disable_irq_nosync(info->temp_data_irq);
return IRQ_HANDLED;
}
static irqreturn_t sun4i_gpadc_fifo_data_irq_handler(int irq, void *dev_id)
{
struct sun4i_gpadc_iio *info = dev_id;
if (atomic_read(&info->ignore_fifo_data_irq))
goto out;
if (!regmap_read(info->regmap, SUN4I_GPADC_DATA, &info->adc_data))
complete(&info->completion);
out:
disable_irq_nosync(info->fifo_data_irq);
return IRQ_HANDLED;
}
static int sun4i_gpadc_runtime_suspend(struct device *dev)
{
struct sun4i_gpadc_iio *info = iio_priv(dev_get_drvdata(dev));
regmap_write(info->regmap, SUN4I_GPADC_CTRL1, 0);
regmap_write(info->regmap, SUN4I_GPADC_TPR, 0);
return 0;
}
static int sun4i_gpadc_runtime_resume(struct device *dev)
{
struct sun4i_gpadc_iio *info = iio_priv(dev_get_drvdata(dev));
regmap_write(info->regmap, SUN4I_GPADC_CTRL0,
SUN4I_GPADC_CTRL0_ADC_CLK_DIVIDER(2) |
SUN4I_GPADC_CTRL0_FS_DIV(7) |
SUN4I_GPADC_CTRL0_T_ACQ(63));
regmap_write(info->regmap, SUN4I_GPADC_CTRL1, info->data->tp_mode_en);
regmap_write(info->regmap, SUN4I_GPADC_CTRL3,
SUN4I_GPADC_CTRL3_FILTER_EN |
SUN4I_GPADC_CTRL3_FILTER_TYPE(1));
regmap_write(info->regmap, SUN4I_GPADC_TPR,
SUN4I_GPADC_TPR_TEMP_ENABLE |
SUN4I_GPADC_TPR_TEMP_PERIOD(800));
return 0;
}
static int sun4i_gpadc_get_temp(void *data, int *temp)
{
struct sun4i_gpadc_iio *info = data;
int val, scale, offset;
if (sun4i_gpadc_temp_read(info->indio_dev, &val))
return -ETIMEDOUT;
sun4i_gpadc_temp_scale(info->indio_dev, &scale);
sun4i_gpadc_temp_offset(info->indio_dev, &offset);
*temp = (val + offset) * scale;
return 0;
}
static int sun4i_irq_init(struct platform_device *pdev, const char *name,
irq_handler_t handler, const char *devname,
unsigned int *irq, atomic_t *atomic)
{
int ret;
struct sun4i_gpadc_dev *mfd_dev = dev_get_drvdata(pdev->dev.parent);
struct sun4i_gpadc_iio *info = iio_priv(dev_get_drvdata(&pdev->dev));
atomic_set(atomic, 1);
ret = platform_get_irq_byname(pdev, name);
if (ret < 0) {
dev_err(&pdev->dev, "no %s interrupt registered\n", name);
return ret;
}
ret = regmap_irq_get_virq(mfd_dev->regmap_irqc, ret);
if (ret < 0) {
dev_err(&pdev->dev, "failed to get virq for irq %s\n", name);
return ret;
}
*irq = ret;
ret = devm_request_any_context_irq(&pdev->dev, *irq, handler, 0,
devname, info);
if (ret < 0) {
dev_err(&pdev->dev, "could not request %s interrupt: %d\n",
name, ret);
return ret;
}
disable_irq(*irq);
atomic_set(atomic, 0);
return 0;
}
static int sun4i_gpadc_probe_dt(struct platform_device *pdev,
struct iio_dev *indio_dev)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
const struct of_device_id *of_dev;
struct resource *mem;
void __iomem *base;
int ret;
of_dev = of_match_device(sun4i_gpadc_of_id, &pdev->dev);
if (!of_dev)
return -ENODEV;
info->no_irq = true;
info->data = (struct gpadc_data *)of_dev->data;
indio_dev->num_channels = ARRAY_SIZE(sun8i_a33_gpadc_channels);
indio_dev->channels = sun8i_a33_gpadc_channels;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(base))
return PTR_ERR(base);
info->regmap = devm_regmap_init_mmio(&pdev->dev, base,
&sun4i_gpadc_regmap_config);
if (IS_ERR(info->regmap)) {
ret = PTR_ERR(info->regmap);
dev_err(&pdev->dev, "failed to init regmap: %d\n", ret);
return ret;
}
if (!IS_ENABLED(CONFIG_THERMAL_OF))
return 0;
info->sensor_device = &pdev->dev;
info->tzd = thermal_zone_of_sensor_register(info->sensor_device, 0,
info, &sun4i_ts_tz_ops);
if (IS_ERR(info->tzd))
dev_err(&pdev->dev, "could not register thermal sensor: %ld\n",
PTR_ERR(info->tzd));
return PTR_ERR_OR_ZERO(info->tzd);
}
static int sun4i_gpadc_probe_mfd(struct platform_device *pdev,
struct iio_dev *indio_dev)
{
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
struct sun4i_gpadc_dev *sun4i_gpadc_dev =
dev_get_drvdata(pdev->dev.parent);
int ret;
info->no_irq = false;
info->regmap = sun4i_gpadc_dev->regmap;
indio_dev->num_channels = ARRAY_SIZE(sun4i_gpadc_channels);
indio_dev->channels = sun4i_gpadc_channels;
info->data = (struct gpadc_data *)platform_get_device_id(pdev)->driver_data;
if (IS_ENABLED(CONFIG_THERMAL_OF)) {
info->sensor_device = pdev->dev.parent;
info->tzd = thermal_zone_of_sensor_register(info->sensor_device,
0, info,
&sun4i_ts_tz_ops);
if (IS_ERR(info->tzd)) {
dev_err(&pdev->dev,
"could not register thermal sensor: %ld\n",
PTR_ERR(info->tzd));
return PTR_ERR(info->tzd);
}
} else {
indio_dev->num_channels =
ARRAY_SIZE(sun4i_gpadc_channels_no_temp);
indio_dev->channels = sun4i_gpadc_channels_no_temp;
}
if (IS_ENABLED(CONFIG_THERMAL_OF)) {
ret = sun4i_irq_init(pdev, "TEMP_DATA_PENDING",
sun4i_gpadc_temp_data_irq_handler,
"temp_data", &info->temp_data_irq,
&info->ignore_temp_data_irq);
if (ret < 0)
return ret;
}
ret = sun4i_irq_init(pdev, "FIFO_DATA_PENDING",
sun4i_gpadc_fifo_data_irq_handler, "fifo_data",
&info->fifo_data_irq, &info->ignore_fifo_data_irq);
if (ret < 0)
return ret;
if (IS_ENABLED(CONFIG_THERMAL_OF)) {
ret = iio_map_array_register(indio_dev, sun4i_gpadc_hwmon_maps);
if (ret < 0) {
dev_err(&pdev->dev,
"failed to register iio map array\n");
return ret;
}
}
return 0;
}
static int sun4i_gpadc_probe(struct platform_device *pdev)
{
struct sun4i_gpadc_iio *info;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
if (!indio_dev)
return -ENOMEM;
info = iio_priv(indio_dev);
platform_set_drvdata(pdev, indio_dev);
mutex_init(&info->mutex);
info->indio_dev = indio_dev;
init_completion(&info->completion);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &sun4i_gpadc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
if (pdev->dev.of_node)
ret = sun4i_gpadc_probe_dt(pdev, indio_dev);
else
ret = sun4i_gpadc_probe_mfd(pdev, indio_dev);
if (ret)
return ret;
pm_runtime_set_autosuspend_delay(&pdev->dev,
SUN4I_GPADC_AUTOSUSPEND_DELAY);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
pm_runtime_enable(&pdev->dev);
ret = devm_iio_device_register(&pdev->dev, indio_dev);
if (ret < 0) {
dev_err(&pdev->dev, "could not register the device\n");
goto err_map;
}
return 0;
err_map:
if (!info->no_irq && IS_ENABLED(CONFIG_THERMAL_OF))
iio_map_array_unregister(indio_dev);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return ret;
}
static int sun4i_gpadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct sun4i_gpadc_iio *info = iio_priv(indio_dev);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!IS_ENABLED(CONFIG_THERMAL_OF))
return 0;
thermal_zone_of_sensor_unregister(info->sensor_device, info->tzd);
if (!info->no_irq)
iio_map_array_unregister(indio_dev);
return 0;
}
