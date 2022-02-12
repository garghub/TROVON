static int rockchip_saradc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct rockchip_saradc *info = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
reinit_completion(&info->completion);
writel_relaxed(8, info->regs + SARADC_DLY_PU_SOC);
writel(SARADC_CTRL_POWER_CTRL
| (chan->channel & SARADC_CTRL_CHN_MASK)
| SARADC_CTRL_IRQ_ENABLE,
info->regs + SARADC_CTRL);
if (!wait_for_completion_timeout(&info->completion,
SARADC_TIMEOUT)) {
writel_relaxed(0, info->regs + SARADC_CTRL);
mutex_unlock(&indio_dev->mlock);
return -ETIMEDOUT;
}
*val = info->last_val;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
ret = regulator_get_voltage(info->vref);
if (ret < 0) {
dev_err(&indio_dev->dev, "failed to get voltage\n");
return ret;
}
*val = ret / 1000;
*val2 = info->data->num_bits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static irqreturn_t rockchip_saradc_isr(int irq, void *dev_id)
{
struct rockchip_saradc *info = (struct rockchip_saradc *)dev_id;
info->last_val = readl_relaxed(info->regs + SARADC_DATA);
info->last_val &= GENMASK(info->data->num_bits - 1, 0);
writel_relaxed(0, info->regs + SARADC_CTRL);
complete(&info->completion);
return IRQ_HANDLED;
}
static int rockchip_saradc_probe(struct platform_device *pdev)
{
struct rockchip_saradc *info = NULL;
struct device_node *np = pdev->dev.of_node;
struct iio_dev *indio_dev = NULL;
struct resource *mem;
const struct of_device_id *match;
int ret;
int irq;
if (!np)
return -ENODEV;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
if (!indio_dev) {
dev_err(&pdev->dev, "failed allocating iio device\n");
return -ENOMEM;
}
info = iio_priv(indio_dev);
match = of_match_device(rockchip_saradc_match, &pdev->dev);
info->data = match->data;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
init_completion(&info->completion);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, rockchip_saradc_isr,
0, dev_name(&pdev->dev), info);
if (ret < 0) {
dev_err(&pdev->dev, "failed requesting irq %d\n", irq);
return ret;
}
info->pclk = devm_clk_get(&pdev->dev, "apb_pclk");
if (IS_ERR(info->pclk)) {
dev_err(&pdev->dev, "failed to get pclk\n");
return PTR_ERR(info->pclk);
}
info->clk = devm_clk_get(&pdev->dev, "saradc");
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed to get adc clock\n");
return PTR_ERR(info->clk);
}
info->vref = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(info->vref)) {
dev_err(&pdev->dev, "failed to get regulator, %ld\n",
PTR_ERR(info->vref));
return PTR_ERR(info->vref);
}
ret = clk_set_rate(info->clk, info->data->clk_rate);
if (ret < 0) {
dev_err(&pdev->dev, "failed to set adc clk rate, %d\n", ret);
return ret;
}
ret = regulator_enable(info->vref);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable vref regulator\n");
return ret;
}
ret = clk_prepare_enable(info->pclk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable pclk\n");
goto err_reg_voltage;
}
ret = clk_prepare_enable(info->clk);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable converter clock\n");
goto err_pclk;
}
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &rockchip_saradc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = info->data->channels;
indio_dev->num_channels = info->data->num_channels;
ret = iio_device_register(indio_dev);
if (ret)
goto err_clk;
return 0;
err_clk:
clk_disable_unprepare(info->clk);
err_pclk:
clk_disable_unprepare(info->pclk);
err_reg_voltage:
regulator_disable(info->vref);
return ret;
}
static int rockchip_saradc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct rockchip_saradc *info = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
clk_disable_unprepare(info->clk);
clk_disable_unprepare(info->pclk);
regulator_disable(info->vref);
return 0;
}
static int rockchip_saradc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct rockchip_saradc *info = iio_priv(indio_dev);
clk_disable_unprepare(info->clk);
clk_disable_unprepare(info->pclk);
regulator_disable(info->vref);
return 0;
}
static int rockchip_saradc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct rockchip_saradc *info = iio_priv(indio_dev);
int ret;
ret = regulator_enable(info->vref);
if (ret)
return ret;
ret = clk_prepare_enable(info->pclk);
if (ret)
return ret;
ret = clk_prepare_enable(info->clk);
if (ret)
return ret;
return ret;
}
