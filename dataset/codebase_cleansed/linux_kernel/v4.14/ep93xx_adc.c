static int ep93xx_read_raw(struct iio_dev *iiodev,
struct iio_chan_spec const *channel, int *value,
int *shift, long mask)
{
struct ep93xx_adc_priv *priv = iio_priv(iiodev);
unsigned long timeout;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&priv->lock);
if (priv->lastch != channel->channel) {
priv->lastch = channel->channel;
local_irq_disable();
writel_relaxed(0xAA, priv->base + EP93XX_ADC_SW_LOCK);
writel_relaxed(channel->address,
priv->base + EP93XX_ADC_SWITCH);
local_irq_enable();
ep93xx_adc_delay(2000, 2000);
}
readl_relaxed(priv->base + EP93XX_ADC_RESULT);
ep93xx_adc_delay(DIV_ROUND_UP(1000000, 925),
DIV_ROUND_UP(1000000, 925));
ret = IIO_VAL_INT;
timeout = jiffies + msecs_to_jiffies(1) + 1;
while (1) {
u32 t;
t = readl_relaxed(priv->base + EP93XX_ADC_RESULT);
if (t & EP93XX_ADC_SDR) {
*value = sign_extend32(t, 15);
break;
}
if (time_after(jiffies, timeout)) {
dev_err(&iiodev->dev, "Conversion timeout\n");
ret = -ETIMEDOUT;
break;
}
cpu_relax();
}
mutex_unlock(&priv->lock);
return ret;
case IIO_CHAN_INFO_OFFSET:
*value = 25000;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*value = (1ULL << 32) * 3300 / 50000;
*shift = 32;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static int ep93xx_adc_probe(struct platform_device *pdev)
{
int ret;
struct iio_dev *iiodev;
struct ep93xx_adc_priv *priv;
struct clk *pclk;
struct resource *res;
iiodev = devm_iio_device_alloc(&pdev->dev, sizeof(*priv));
if (!iiodev)
return -ENOMEM;
priv = iio_priv(iiodev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Cannot obtain memory resource\n");
return -ENXIO;
}
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base)) {
dev_err(&pdev->dev, "Cannot map memory resource\n");
return PTR_ERR(priv->base);
}
iiodev->dev.parent = &pdev->dev;
iiodev->name = dev_name(&pdev->dev);
iiodev->modes = INDIO_DIRECT_MODE;
iiodev->info = &ep93xx_adc_info;
iiodev->num_channels = ARRAY_SIZE(ep93xx_adc_channels);
iiodev->channels = ep93xx_adc_channels;
priv->lastch = -1;
mutex_init(&priv->lock);
platform_set_drvdata(pdev, iiodev);
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(&pdev->dev, "Cannot obtain clock\n");
return PTR_ERR(priv->clk);
}
pclk = clk_get_parent(priv->clk);
if (!pclk) {
dev_warn(&pdev->dev, "Cannot obtain parent clock\n");
} else {
ret = clk_set_rate(priv->clk, clk_get_rate(pclk) / 16);
if (ret)
dev_warn(&pdev->dev, "Cannot set clock rate\n");
}
ret = clk_enable(priv->clk);
if (ret) {
dev_err(&pdev->dev, "Cannot enable clock\n");
return ret;
}
ret = iio_device_register(iiodev);
if (ret)
clk_disable(priv->clk);
return ret;
}
static int ep93xx_adc_remove(struct platform_device *pdev)
{
struct iio_dev *iiodev = platform_get_drvdata(pdev);
struct ep93xx_adc_priv *priv = iio_priv(iiodev);
iio_device_unregister(iiodev);
clk_disable(priv->clk);
return 0;
}
