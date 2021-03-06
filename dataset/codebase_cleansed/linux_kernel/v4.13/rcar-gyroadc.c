static void rcar_gyroadc_hw_init(struct rcar_gyroadc *priv)
{
const unsigned long clk_mhz = clk_get_rate(priv->clk) / 1000000;
const unsigned long clk_mul =
(priv->mode == RCAR_GYROADC_MODE_SELECT_1_MB88101A) ? 10 : 5;
unsigned long clk_len = clk_mhz * clk_mul;
if (clk_len & 1)
clk_len++;
writel(0, priv->regs + RCAR_GYROADC_START_STOP);
if (priv->model == RCAR_GYROADC_MODEL_R8A7792)
writel(0, priv->regs + RCAR_GYROADC_INTENR);
writel(priv->mode, priv->regs + RCAR_GYROADC_MODE_SELECT);
writel(clk_len, priv->regs + RCAR_GYROADC_CLOCK_LENGTH);
writel(clk_mhz * 1250, priv->regs + RCAR_GYROADC_1_25MS_LENGTH);
}
static void rcar_gyroadc_hw_start(struct rcar_gyroadc *priv)
{
writel(RCAR_GYROADC_START_STOP_START,
priv->regs + RCAR_GYROADC_START_STOP);
mdelay(3);
}
static void rcar_gyroadc_hw_stop(struct rcar_gyroadc *priv)
{
writel(0, priv->regs + RCAR_GYROADC_START_STOP);
}
static int rcar_gyroadc_set_power(struct rcar_gyroadc *priv, bool on)
{
struct device *dev = priv->dev;
int ret;
if (on) {
ret = pm_runtime_get_sync(dev);
if (ret < 0)
pm_runtime_put_noidle(dev);
} else {
pm_runtime_mark_last_busy(dev);
ret = pm_runtime_put_autosuspend(dev);
}
return ret;
}
static int rcar_gyroadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct rcar_gyroadc *priv = iio_priv(indio_dev);
struct regulator *consumer;
unsigned int datareg = RCAR_GYROADC_REALTIME_DATA(chan->channel);
unsigned int vref;
int ret;
if (priv->mode == RCAR_GYROADC_MODE_SELECT_1_MB88101A)
consumer = priv->vref[0];
else
consumer = priv->vref[chan->channel];
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type != IIO_VOLTAGE)
return -EINVAL;
if (!consumer)
return -EINVAL;
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
ret = rcar_gyroadc_set_power(priv, true);
if (ret < 0) {
iio_device_release_direct_mode(indio_dev);
return ret;
}
*val = readl(priv->regs + datareg);
*val &= BIT(priv->sample_width) - 1;
ret = rcar_gyroadc_set_power(priv, false);
iio_device_release_direct_mode(indio_dev);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
if (!consumer)
return -EINVAL;
vref = regulator_get_voltage(consumer);
*val = vref / 1000;
*val2 = 1 << priv->sample_width;
return IIO_VAL_FRACTIONAL;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = RCAR_GYROADC_SAMPLE_RATE;
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int rcar_gyroadc_reg_access(struct iio_dev *indio_dev,
unsigned int reg, unsigned int writeval,
unsigned int *readval)
{
struct rcar_gyroadc *priv = iio_priv(indio_dev);
unsigned int maxreg = RCAR_GYROADC_FIFO_STATUS;
if (readval == NULL)
return -EINVAL;
if (reg % 4)
return -EINVAL;
if (priv->model == RCAR_GYROADC_MODEL_R8A7792)
maxreg = RCAR_GYROADC_INTENR;
if (reg > maxreg)
return -EINVAL;
*readval = readl(priv->regs + reg);
return 0;
}
static int rcar_gyroadc_parse_subdevs(struct iio_dev *indio_dev)
{
const struct of_device_id *of_id;
const struct iio_chan_spec *channels;
struct rcar_gyroadc *priv = iio_priv(indio_dev);
struct device *dev = priv->dev;
struct device_node *np = dev->of_node;
struct device_node *child;
struct regulator *vref;
unsigned int reg;
unsigned int adcmode = -1, childmode;
unsigned int sample_width;
unsigned int num_channels;
int ret, first = 1;
for_each_child_of_node(np, child) {
of_id = of_match_node(rcar_gyroadc_child_match, child);
if (!of_id) {
dev_err(dev, "Ignoring unsupported ADC \"%s\".",
child->name);
continue;
}
childmode = (unsigned int)of_id->data;
switch (childmode) {
case RCAR_GYROADC_MODE_SELECT_1_MB88101A:
sample_width = 12;
channels = rcar_gyroadc_iio_channels_1;
num_channels = ARRAY_SIZE(rcar_gyroadc_iio_channels_1);
break;
case RCAR_GYROADC_MODE_SELECT_2_ADCS7476:
sample_width = 15;
channels = rcar_gyroadc_iio_channels_2;
num_channels = ARRAY_SIZE(rcar_gyroadc_iio_channels_2);
break;
case RCAR_GYROADC_MODE_SELECT_3_MAX1162:
sample_width = 16;
channels = rcar_gyroadc_iio_channels_3;
num_channels = ARRAY_SIZE(rcar_gyroadc_iio_channels_3);
break;
default:
return -EINVAL;
}
if (childmode == RCAR_GYROADC_MODE_SELECT_1_MB88101A) {
reg = 0;
} else {
ret = of_property_read_u32(child, "reg", &reg);
if (ret) {
dev_err(dev,
"Failed to get child reg property of ADC \"%s\".\n",
child->name);
return ret;
}
if (reg >= num_channels) {
dev_err(dev,
"Only %i channels supported with %s, but reg = <%i>.\n",
num_channels, child->name, reg);
return ret;
}
}
if (!first && (adcmode != childmode)) {
dev_err(dev,
"Channel %i uses different ADC mode than the rest.\n",
reg);
return ret;
}
dev->of_node = child;
vref = devm_regulator_get(dev, "vref");
dev->of_node = np;
if (IS_ERR(vref)) {
dev_dbg(dev, "Channel %i 'vref' supply not connected.\n",
reg);
return PTR_ERR(vref);
}
priv->vref[reg] = vref;
if (!first)
continue;
adcmode = childmode;
first = 0;
priv->num_channels = num_channels;
priv->mode = childmode;
priv->sample_width = sample_width;
indio_dev->channels = channels;
indio_dev->num_channels = num_channels;
if (childmode == RCAR_GYROADC_MODE_SELECT_1_MB88101A)
break;
}
if (first) {
dev_err(dev, "No valid ADC channels found, aborting.\n");
return -EINVAL;
}
return 0;
}
static void rcar_gyroadc_deinit_supplies(struct iio_dev *indio_dev)
{
struct rcar_gyroadc *priv = iio_priv(indio_dev);
unsigned int i;
for (i = 0; i < priv->num_channels; i++) {
if (!priv->vref[i])
continue;
regulator_disable(priv->vref[i]);
}
}
static int rcar_gyroadc_init_supplies(struct iio_dev *indio_dev)
{
struct rcar_gyroadc *priv = iio_priv(indio_dev);
struct device *dev = priv->dev;
unsigned int i;
int ret;
for (i = 0; i < priv->num_channels; i++) {
if (!priv->vref[i])
continue;
ret = regulator_enable(priv->vref[i]);
if (ret) {
dev_err(dev, "Failed to enable regulator %i (ret=%i)\n",
i, ret);
goto err;
}
}
return 0;
err:
rcar_gyroadc_deinit_supplies(indio_dev);
return ret;
}
static int rcar_gyroadc_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(rcar_gyroadc_match, &pdev->dev);
struct device *dev = &pdev->dev;
struct rcar_gyroadc *priv;
struct iio_dev *indio_dev;
struct resource *mem;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*priv));
if (!indio_dev) {
dev_err(dev, "Failed to allocate IIO device.\n");
return -ENOMEM;
}
priv = iio_priv(indio_dev);
priv->dev = dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(dev, mem);
if (IS_ERR(priv->regs))
return PTR_ERR(priv->regs);
priv->clk = devm_clk_get(dev, "fck");
if (IS_ERR(priv->clk)) {
ret = PTR_ERR(priv->clk);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get IF clock (ret=%i)\n", ret);
return ret;
}
ret = rcar_gyroadc_parse_subdevs(indio_dev);
if (ret)
return ret;
ret = rcar_gyroadc_init_supplies(indio_dev);
if (ret)
return ret;
priv->model = (enum rcar_gyroadc_model)of_id->data;
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = DRIVER_NAME;
indio_dev->dev.parent = dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &rcar_gyroadc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(dev, "Could not prepare or enable the IF clock.\n");
goto err_clk_if_enable;
}
pm_runtime_set_autosuspend_delay(dev, RCAR_GYROADC_RUNTIME_PM_DELAY_MS);
pm_runtime_use_autosuspend(dev);
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
rcar_gyroadc_hw_init(priv);
rcar_gyroadc_hw_start(priv);
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(dev, "Couldn't register IIO device.\n");
goto err_iio_device_register;
}
pm_runtime_put_sync(dev);
return 0;
err_iio_device_register:
rcar_gyroadc_hw_stop(priv);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
clk_disable_unprepare(priv->clk);
err_clk_if_enable:
rcar_gyroadc_deinit_supplies(indio_dev);
return ret;
}
static int rcar_gyroadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct rcar_gyroadc *priv = iio_priv(indio_dev);
struct device *dev = priv->dev;
iio_device_unregister(indio_dev);
pm_runtime_get_sync(dev);
rcar_gyroadc_hw_stop(priv);
pm_runtime_put_sync(dev);
pm_runtime_disable(dev);
pm_runtime_set_suspended(dev);
clk_disable_unprepare(priv->clk);
rcar_gyroadc_deinit_supplies(indio_dev);
return 0;
}
static int rcar_gyroadc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct rcar_gyroadc *priv = iio_priv(indio_dev);
rcar_gyroadc_hw_stop(priv);
return 0;
}
static int rcar_gyroadc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct rcar_gyroadc *priv = iio_priv(indio_dev);
rcar_gyroadc_hw_start(priv);
return 0;
}
