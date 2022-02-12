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
retval = -EBUSY;
goto errout1;
}
iodev = iio_device_alloc(sizeof(struct lpc32xx_adc_info));
if (!iodev) {
dev_err(&pdev->dev, "failed allocating iio device\n");
retval = -ENOMEM;
goto errout1;
}
info = iio_priv(iodev);
info->adc_base = ioremap(res->start, resource_size(res));
if (!info->adc_base) {
dev_err(&pdev->dev, "failed mapping memory\n");
retval = -EBUSY;
goto errout2;
}
info->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed getting clock\n");
goto errout3;
}
irq = platform_get_irq(pdev, 0);
if ((irq < 0) || (irq >= NR_IRQS)) {
dev_err(&pdev->dev, "failed getting interrupt resource\n");
retval = -EINVAL;
goto errout4;
}
retval = request_irq(irq, lpc32xx_adc_isr, 0, MOD_NAME, info);
if (retval < 0) {
dev_err(&pdev->dev, "failed requesting interrupt\n");
goto errout4;
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
goto errout5;
dev_info(&pdev->dev, "LPC32XX ADC driver loaded, IRQ %d\n", irq);
return 0;
errout5:
free_irq(irq, info);
errout4:
clk_put(info->clk);
errout3:
iounmap(info->adc_base);
errout2:
iio_device_free(iodev);
errout1:
return retval;
}
static int lpc32xx_adc_remove(struct platform_device *pdev)
{
struct iio_dev *iodev = platform_get_drvdata(pdev);
struct lpc32xx_adc_info *info = iio_priv(iodev);
int irq = platform_get_irq(pdev, 0);
iio_device_unregister(iodev);
free_irq(irq, info);
clk_put(info->clk);
iounmap(info->adc_base);
iio_device_free(iodev);
return 0;
}
