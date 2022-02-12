static int lpc32xx_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct lpc32xx_adc_state *st = iio_priv(indio_dev);
int ret;
if (mask == IIO_CHAN_INFO_RAW) {
mutex_lock(&indio_dev->mlock);
ret = clk_prepare_enable(st->clk);
if (ret) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
__raw_writel(LPC32XXAD_INTERNAL | (chan->address) |
LPC32XXAD_REFp | LPC32XXAD_REFm,
LPC32XXAD_SELECT(st->adc_base));
__raw_writel(LPC32XXAD_PDN_CTRL | LPC32XXAD_STROBE,
LPC32XXAD_CTRL(st->adc_base));
wait_for_completion(&st->completion);
clk_disable_unprepare(st->clk);
*val = st->value;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
}
return -EINVAL;
}
static irqreturn_t lpc32xx_adc_isr(int irq, void *dev_id)
{
struct lpc32xx_adc_state *st = dev_id;
st->value = __raw_readl(LPC32XXAD_VALUE(st->adc_base)) &
LPC32XXAD_VALUE_MASK;
complete(&st->completion);
return IRQ_HANDLED;
}
static int lpc32xx_adc_probe(struct platform_device *pdev)
{
struct lpc32xx_adc_state *st = NULL;
struct resource *res;
int retval = -ENODEV;
struct iio_dev *iodev = NULL;
int irq;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get platform I/O memory\n");
return -ENXIO;
}
iodev = devm_iio_device_alloc(&pdev->dev, sizeof(*st));
if (!iodev)
return -ENOMEM;
st = iio_priv(iodev);
st->adc_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!st->adc_base) {
dev_err(&pdev->dev, "failed mapping memory\n");
return -EBUSY;
}
st->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(st->clk)) {
dev_err(&pdev->dev, "failed getting clock\n");
return PTR_ERR(st->clk);
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "failed getting interrupt resource\n");
return -ENXIO;
}
retval = devm_request_irq(&pdev->dev, irq, lpc32xx_adc_isr, 0,
LPC32XXAD_NAME, st);
if (retval < 0) {
dev_err(&pdev->dev, "failed requesting interrupt\n");
return retval;
}
platform_set_drvdata(pdev, iodev);
init_completion(&st->completion);
iodev->name = LPC32XXAD_NAME;
iodev->dev.parent = &pdev->dev;
iodev->info = &lpc32xx_adc_iio_info;
iodev->modes = INDIO_DIRECT_MODE;
iodev->channels = lpc32xx_adc_iio_channels;
iodev->num_channels = ARRAY_SIZE(lpc32xx_adc_iio_channels);
retval = devm_iio_device_register(&pdev->dev, iodev);
if (retval)
return retval;
dev_info(&pdev->dev, "LPC32XX ADC driver loaded, IRQ %d\n", irq);
return 0;
}
