static void spear_adc_set_status(struct spear_adc_state *st, u32 val)
{
__raw_writel(val, &st->adc_base_spear6xx->status);
}
static void spear_adc_set_clk(struct spear_adc_state *st, u32 val)
{
u32 clk_high, clk_low, count;
u32 apb_clk = clk_get_rate(st->clk);
count = DIV_ROUND_UP(apb_clk, val);
clk_low = count / 2;
clk_high = count - clk_low;
st->current_clk = apb_clk / count;
__raw_writel(SPEAR_ADC_CLK_LOW(clk_low) | SPEAR_ADC_CLK_HIGH(clk_high),
&st->adc_base_spear6xx->clk);
}
static void spear_adc_set_ctrl(struct spear_adc_state *st, int n,
u32 val)
{
__raw_writel(val, &st->adc_base_spear6xx->ch_ctrl[n]);
}
static u32 spear_adc_get_average(struct spear_adc_state *st)
{
if (of_device_is_compatible(st->np, "st,spear600-adc")) {
return __raw_readl(&st->adc_base_spear6xx->average.msb) &
SPEAR_ADC_DATA_MASK;
} else {
return __raw_readl(&st->adc_base_spear3xx->average) &
SPEAR_ADC_DATA_MASK;
}
}
static void spear_adc_set_scanrate(struct spear_adc_state *st, u32 rate)
{
if (of_device_is_compatible(st->np, "st,spear600-adc")) {
__raw_writel(SPEAR600_ADC_SCAN_RATE_LO(rate),
&st->adc_base_spear6xx->scan_rate_lo);
__raw_writel(SPEAR600_ADC_SCAN_RATE_HI(rate),
&st->adc_base_spear6xx->scan_rate_hi);
} else {
__raw_writel(rate, &st->adc_base_spear3xx->scan_rate);
}
}
static int spear_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct spear_adc_state *st = iio_priv(indio_dev);
u32 status;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
status = SPEAR_ADC_STATUS_CHANNEL_NUM(chan->channel) |
SPEAR_ADC_STATUS_AVG_SAMPLE(st->avg_samples) |
SPEAR_ADC_STATUS_START_CONVERSION |
SPEAR_ADC_STATUS_ADC_ENABLE;
if (st->vref_external == 0)
status |= SPEAR_ADC_STATUS_VREF_INTERNAL;
spear_adc_set_status(st, status);
wait_for_completion(&st->completion);
*val = st->value;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = st->vref_external;
*val2 = SPEAR_ADC_DATA_BITS;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = st->current_clk;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int spear_adc_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct spear_adc_state *st = iio_priv(indio_dev);
int ret = 0;
if (mask != IIO_CHAN_INFO_SAMP_FREQ)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
if ((val < SPEAR_ADC_CLK_MIN) ||
(val > SPEAR_ADC_CLK_MAX) ||
(val2 != 0)) {
ret = -EINVAL;
goto out;
}
spear_adc_set_clk(st, val);
out:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static irqreturn_t spear_adc_isr(int irq, void *dev_id)
{
struct spear_adc_state *st = dev_id;
st->value = spear_adc_get_average(st);
complete(&st->completion);
return IRQ_HANDLED;
}
static int spear_adc_configure(struct spear_adc_state *st)
{
int i;
spear_adc_set_status(st, 0);
__raw_writel(0, &st->adc_base_spear6xx->clk);
for (i = 0; i < 8; i++)
spear_adc_set_ctrl(st, i, 0);
spear_adc_set_scanrate(st, 0);
spear_adc_set_clk(st, st->sampling_freq);
return 0;
}
static int spear_adc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct spear_adc_state *st;
struct resource *res;
struct iio_dev *indio_dev = NULL;
int ret = -ENODEV;
int irq;
indio_dev = devm_iio_device_alloc(dev, sizeof(struct spear_adc_state));
if (!indio_dev) {
dev_err(dev, "failed allocating iio device\n");
return -ENOMEM;
}
st = iio_priv(indio_dev);
st->np = np;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
st->adc_base_spear6xx = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(st->adc_base_spear6xx))
return PTR_ERR(st->adc_base_spear6xx);
st->adc_base_spear3xx =
(struct adc_regs_spear3xx __iomem *)st->adc_base_spear6xx;
st->clk = devm_clk_get(dev, NULL);
if (IS_ERR(st->clk)) {
dev_err(dev, "failed getting clock\n");
return PTR_ERR(st->clk);
}
ret = clk_prepare_enable(st->clk);
if (ret) {
dev_err(dev, "failed enabling clock\n");
return ret;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "failed getting interrupt resource\n");
ret = -EINVAL;
goto errout2;
}
ret = devm_request_irq(dev, irq, spear_adc_isr, 0, SPEAR_ADC_MOD_NAME,
st);
if (ret < 0) {
dev_err(dev, "failed requesting interrupt\n");
goto errout2;
}
if (of_property_read_u32(np, "sampling-frequency",
&st->sampling_freq)) {
dev_err(dev, "sampling-frequency missing in DT\n");
ret = -EINVAL;
goto errout2;
}
of_property_read_u32(np, "average-samples", &st->avg_samples);
of_property_read_u32(np, "vref-external", &st->vref_external);
spear_adc_configure(st);
platform_set_drvdata(pdev, indio_dev);
init_completion(&st->completion);
indio_dev->name = SPEAR_ADC_MOD_NAME;
indio_dev->dev.parent = dev;
indio_dev->info = &spear_adc_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = spear_adc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(spear_adc_iio_channels);
ret = iio_device_register(indio_dev);
if (ret)
goto errout2;
dev_info(dev, "SPEAR ADC driver loaded, IRQ %d\n", irq);
return 0;
errout2:
clk_disable_unprepare(st->clk);
return ret;
}
static int spear_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct spear_adc_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
clk_disable_unprepare(st->clk);
return 0;
}
