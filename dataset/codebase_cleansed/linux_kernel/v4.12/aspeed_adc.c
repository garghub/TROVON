static int aspeed_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct aspeed_adc_data *data = iio_priv(indio_dev);
const struct aspeed_adc_model_data *model_data =
of_device_get_match_data(data->dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
*val = readw(data->base + chan->address);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = model_data->vref_voltage;
*val2 = ASPEED_RESOLUTION_BITS;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = clk_get_rate(data->clk_scaler->clk) /
ASPEED_CLOCKS_PER_SAMPLE;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int aspeed_adc_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct aspeed_adc_data *data = iio_priv(indio_dev);
const struct aspeed_adc_model_data *model_data =
of_device_get_match_data(data->dev);
switch (mask) {
case IIO_CHAN_INFO_SAMP_FREQ:
if (val < model_data->min_sampling_rate ||
val > model_data->max_sampling_rate)
return -EINVAL;
clk_set_rate(data->clk_scaler->clk,
val * ASPEED_CLOCKS_PER_SAMPLE);
return 0;
case IIO_CHAN_INFO_SCALE:
case IIO_CHAN_INFO_RAW:
return -EPERM;
default:
return -EINVAL;
}
}
static int aspeed_adc_reg_access(struct iio_dev *indio_dev,
unsigned int reg, unsigned int writeval,
unsigned int *readval)
{
struct aspeed_adc_data *data = iio_priv(indio_dev);
if (!readval || reg % 4 || reg > ASPEED_REG_MAX)
return -EINVAL;
*readval = readl(data->base + reg);
return 0;
}
static int aspeed_adc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct aspeed_adc_data *data;
const struct aspeed_adc_model_data *model_data;
struct resource *res;
const char *clk_parent_name;
int ret;
u32 adc_engine_control_reg_val;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
data->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
spin_lock_init(&data->clk_lock);
clk_parent_name = of_clk_get_parent_name(pdev->dev.of_node, 0);
data->clk_prescaler = clk_hw_register_divider(
&pdev->dev, "prescaler", clk_parent_name, 0,
data->base + ASPEED_REG_CLOCK_CONTROL,
17, 15, 0, &data->clk_lock);
if (IS_ERR(data->clk_prescaler))
return PTR_ERR(data->clk_prescaler);
data->clk_scaler = clk_hw_register_divider(
&pdev->dev, "scaler", "prescaler",
CLK_SET_RATE_PARENT,
data->base + ASPEED_REG_CLOCK_CONTROL,
0, 10, 0, &data->clk_lock);
if (IS_ERR(data->clk_scaler)) {
ret = PTR_ERR(data->clk_scaler);
goto scaler_error;
}
clk_prepare_enable(data->clk_scaler->clk);
adc_engine_control_reg_val = GENMASK(31, 16) |
ASPEED_OPERATION_MODE_NORMAL | ASPEED_ENGINE_ENABLE;
writel(adc_engine_control_reg_val,
data->base + ASPEED_REG_ENGINE_CONTROL);
model_data = of_device_get_match_data(&pdev->dev);
indio_dev->name = model_data->model_name;
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &aspeed_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = aspeed_adc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(aspeed_adc_iio_channels);
ret = iio_device_register(indio_dev);
if (ret)
goto iio_register_error;
return 0;
iio_register_error:
writel(ASPEED_OPERATION_MODE_POWER_DOWN,
data->base + ASPEED_REG_ENGINE_CONTROL);
clk_disable_unprepare(data->clk_scaler->clk);
clk_hw_unregister_divider(data->clk_scaler);
scaler_error:
clk_hw_unregister_divider(data->clk_prescaler);
return ret;
}
static int aspeed_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct aspeed_adc_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
writel(ASPEED_OPERATION_MODE_POWER_DOWN,
data->base + ASPEED_REG_ENGINE_CONTROL);
clk_disable_unprepare(data->clk_scaler->clk);
clk_hw_unregister_divider(data->clk_scaler);
clk_hw_unregister_divider(data->clk_prescaler);
return 0;
}
