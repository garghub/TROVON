static void spear_adc_set_status(struct spear_adc_info *info, u32 val)
{
__raw_writel(val, &info->adc_base_spear6xx->status);
}
static void spear_adc_set_clk(struct spear_adc_info *info, u32 val)
{
u32 clk_high, clk_low, count;
u32 apb_clk = clk_get_rate(info->clk);
count = (apb_clk + val - 1) / val;
clk_low = count / 2;
clk_high = count - clk_low;
info->current_clk = apb_clk / count;
__raw_writel(CLK_LOW(clk_low) | CLK_HIGH(clk_high),
&info->adc_base_spear6xx->clk);
}
static void spear_adc_set_ctrl(struct spear_adc_info *info, int n,
u32 val)
{
__raw_writel(val, &info->adc_base_spear6xx->ch_ctrl[n]);
}
static u32 spear_adc_get_average(struct spear_adc_info *info)
{
if (of_device_is_compatible(info->np, "st,spear600-adc")) {
return __raw_readl(&info->adc_base_spear6xx->average.msb) &
DATA_MASK;
} else {
return __raw_readl(&info->adc_base_spear3xx->average) &
DATA_MASK;
}
}
static void spear_adc_set_scanrate(struct spear_adc_info *info, u32 rate)
{
if (of_device_is_compatible(info->np, "st,spear600-adc")) {
__raw_writel(SCAN_RATE_LO(rate),
&info->adc_base_spear6xx->scan_rate_lo);
__raw_writel(SCAN_RATE_HI(rate),
&info->adc_base_spear6xx->scan_rate_hi);
} else {
__raw_writel(rate, &info->adc_base_spear3xx->scan_rate);
}
}
static int spear_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct spear_adc_info *info = iio_priv(indio_dev);
u32 status;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
status = CHANNEL_NUM(chan->channel) |
AVG_SAMPLE(info->avg_samples) |
START_CONVERSION | ADC_ENABLE;
if (info->vref_external == 0)
status |= VREF_INTERNAL;
spear_adc_set_status(info, status);
wait_for_completion(&info->completion);
*val = info->value;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = info->vref_external;
*val2 = DATA_BITS;
return IIO_VAL_FRACTIONAL_LOG2;
}
return -EINVAL;
}
static irqreturn_t spear_adc_isr(int irq, void *dev_id)
{
struct spear_adc_info *info = (struct spear_adc_info *)dev_id;
info->value = spear_adc_get_average(info);
complete(&info->completion);
return IRQ_HANDLED;
}
static int spear_adc_configure(struct spear_adc_info *info)
{
int i;
spear_adc_set_status(info, 0);
__raw_writel(0, &info->adc_base_spear6xx->clk);
for (i = 0; i < 8; i++)
spear_adc_set_ctrl(info, i, 0);
spear_adc_set_scanrate(info, 0);
spear_adc_set_clk(info, info->sampling_freq);
return 0;
}
static ssize_t spear_adc_read_frequency(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct spear_adc_info *info = iio_priv(indio_dev);
return sprintf(buf, "%d\n", info->current_clk);
}
static ssize_t spear_adc_write_frequency(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct spear_adc_info *info = iio_priv(indio_dev);
u32 clk_high, clk_low, count;
u32 apb_clk = clk_get_rate(info->clk);
unsigned long lval;
int ret;
ret = kstrtoul(buf, 10, &lval);
if (ret)
return ret;
mutex_lock(&indio_dev->mlock);
if ((lval < CLK_MIN) || (lval > CLK_MAX)) {
ret = -EINVAL;
goto out;
}
count = (apb_clk + lval - 1) / lval;
clk_low = count / 2;
clk_high = count - clk_low;
info->current_clk = apb_clk / count;
spear_adc_set_clk(info, lval);
out:
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static int spear_adc_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct device *dev = &pdev->dev;
struct spear_adc_info *info;
struct iio_dev *iodev = NULL;
int ret = -ENODEV;
int irq;
iodev = devm_iio_device_alloc(dev, sizeof(struct spear_adc_info));
if (!iodev) {
dev_err(dev, "failed allocating iio device\n");
return -ENOMEM;
}
info = iio_priv(iodev);
info->np = np;
info->adc_base_spear6xx = of_iomap(np, 0);
if (!info->adc_base_spear6xx) {
dev_err(dev, "failed mapping memory\n");
return -ENOMEM;
}
info->adc_base_spear3xx =
(struct adc_regs_spear3xx __iomem *)info->adc_base_spear6xx;
info->clk = clk_get(dev, NULL);
if (IS_ERR(info->clk)) {
dev_err(dev, "failed getting clock\n");
goto errout1;
}
ret = clk_prepare_enable(info->clk);
if (ret) {
dev_err(dev, "failed enabling clock\n");
goto errout2;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "failed getting interrupt resource\n");
ret = -EINVAL;
goto errout3;
}
ret = devm_request_irq(dev, irq, spear_adc_isr, 0, MOD_NAME, info);
if (ret < 0) {
dev_err(dev, "failed requesting interrupt\n");
goto errout3;
}
if (of_property_read_u32(np, "sampling-frequency",
&info->sampling_freq)) {
dev_err(dev, "sampling-frequency missing in DT\n");
ret = -EINVAL;
goto errout3;
}
of_property_read_u32(np, "average-samples", &info->avg_samples);
of_property_read_u32(np, "vref-external", &info->vref_external);
spear_adc_configure(info);
platform_set_drvdata(pdev, iodev);
init_completion(&info->completion);
iodev->name = MOD_NAME;
iodev->dev.parent = dev;
iodev->info = &spear_adc_iio_info;
iodev->modes = INDIO_DIRECT_MODE;
iodev->channels = spear_adc_iio_channels;
iodev->num_channels = ARRAY_SIZE(spear_adc_iio_channels);
ret = iio_device_register(iodev);
if (ret)
goto errout3;
dev_info(dev, "SPEAR ADC driver loaded, IRQ %d\n", irq);
return 0;
errout3:
clk_disable_unprepare(info->clk);
errout2:
clk_put(info->clk);
errout1:
iounmap(info->adc_base_spear6xx);
return ret;
}
static int spear_adc_remove(struct platform_device *pdev)
{
struct iio_dev *iodev = platform_get_drvdata(pdev);
struct spear_adc_info *info = iio_priv(iodev);
iio_device_unregister(iodev);
clk_disable_unprepare(info->clk);
clk_put(info->clk);
iounmap(info->adc_base_spear6xx);
return 0;
}
