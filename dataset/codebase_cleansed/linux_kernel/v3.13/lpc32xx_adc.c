static int lpc32xx_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct lpc32xx_adc_info *info = iio_priv(indio_dev);
if (mask == IIO_CHAN_INFO_RAW) {
mutex_lock(&indio_dev->mlock);
clk_enable(info->clk);
__raw_writel(AD_INTERNAL | (chan->address) | AD_REFp | AD_REFm,
LPC32XX_ADC_SELECT(info->adc_base));
__raw_writel(AD_PDN_CTRL | AD_STROBE,
LPC32XX_ADC_CTRL(info->adc_base));
wait_for_completion(&info->completion);
clk_disable(info->clk);
*val = info->value;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
}
return -EINVAL;
}
static irqreturn_t lpc32xx_adc_isr(int irq, void *dev_id)
{
struct lpc32xx_adc_info *info = (struct lpc32xx_adc_info *) dev_id;
info->value = __raw_readl(LPC32XX_ADC_VALUE(info->adc_base)) &
ADC_VALUE_MASK;
complete(&info->completion);
return IRQ_HANDLED;
}
static int lpc32xx_adc_probe(struct platform_device *pdev)
{
struct lpc32xx_adc_info *info = NULL;
struct resource *res;
int retval = -ENODEV;
struct iio_dev *iodev = NULL;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get platform I/O memory\n");
return -EBUSY;
}
iodev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
if (!iodev)
return -ENOMEM;
info = iio_priv(iodev);
info->adc_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!info->adc_base) {
dev_err(&pdev->dev, "failed mapping memory\n");
return -EBUSY;
}
info->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed getting clock\n");
return PTR_ERR(info->clk);
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "failed getting interrupt resource\n");
return -EINVAL;
}
retval = devm_request_irq(&pdev->dev, irq, lpc32xx_adc_isr, 0,
MOD_NAME, info);
if (retval < 0) {
dev_err(&pdev->dev, "failed requesting interrupt\n");
return retval;
}
platform_set_drvdata(pdev, iodev);
init_completion(&info->completion);
iodev->name = MOD_NAME;
iodev->dev.parent = &pdev->dev;
iodev->info = &lpc32xx_adc_iio_info;
iodev->modes = INDIO_DIRECT_MODE;
iodev->channels = lpc32xx_adc_iio_channels;
iodev->num_channels = ARRAY_SIZE(lpc32xx_adc_iio_channels);
retval = iio_device_register(iodev);
if (retval)
return retval;
dev_info(&pdev->dev, "LPC32XX ADC driver loaded, IRQ %d\n", irq);
return 0;
}
static int lpc32xx_adc_remove(struct platform_device *pdev)
{
struct iio_dev *iodev = platform_get_drvdata(pdev);
iio_device_unregister(iodev);
return 0;
}
