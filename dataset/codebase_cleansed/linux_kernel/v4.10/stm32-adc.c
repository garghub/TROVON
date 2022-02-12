static u32 stm32_adc_readl(struct stm32_adc *adc, u32 reg)
{
return readl_relaxed(adc->common->base + adc->offset + reg);
}
static u16 stm32_adc_readw(struct stm32_adc *adc, u32 reg)
{
return readw_relaxed(adc->common->base + adc->offset + reg);
}
static void stm32_adc_writel(struct stm32_adc *adc, u32 reg, u32 val)
{
writel_relaxed(val, adc->common->base + adc->offset + reg);
}
static void stm32_adc_set_bits(struct stm32_adc *adc, u32 reg, u32 bits)
{
unsigned long flags;
spin_lock_irqsave(&adc->lock, flags);
stm32_adc_writel(adc, reg, stm32_adc_readl(adc, reg) | bits);
spin_unlock_irqrestore(&adc->lock, flags);
}
static void stm32_adc_clr_bits(struct stm32_adc *adc, u32 reg, u32 bits)
{
unsigned long flags;
spin_lock_irqsave(&adc->lock, flags);
stm32_adc_writel(adc, reg, stm32_adc_readl(adc, reg) & ~bits);
spin_unlock_irqrestore(&adc->lock, flags);
}
static void stm32_adc_conv_irq_enable(struct stm32_adc *adc)
{
stm32_adc_set_bits(adc, STM32F4_ADC_CR1, STM32F4_EOCIE);
}
static void stm32_adc_conv_irq_disable(struct stm32_adc *adc)
{
stm32_adc_clr_bits(adc, STM32F4_ADC_CR1, STM32F4_EOCIE);
}
static void stm32_adc_start_conv(struct stm32_adc *adc)
{
stm32_adc_set_bits(adc, STM32F4_ADC_CR1, STM32F4_SCAN);
stm32_adc_set_bits(adc, STM32F4_ADC_CR2, STM32F4_EOCS | STM32F4_ADON);
usleep_range(2, 3);
if (!(stm32_adc_readl(adc, STM32F4_ADC_CR2) & STM32F4_EXTEN_MASK))
stm32_adc_set_bits(adc, STM32F4_ADC_CR2, STM32F4_SWSTART);
}
static void stm32_adc_stop_conv(struct stm32_adc *adc)
{
stm32_adc_clr_bits(adc, STM32F4_ADC_CR2, STM32F4_EXTEN_MASK);
stm32_adc_clr_bits(adc, STM32F4_ADC_SR, STM32F4_STRT);
stm32_adc_clr_bits(adc, STM32F4_ADC_CR1, STM32F4_SCAN);
stm32_adc_clr_bits(adc, STM32F4_ADC_CR2, STM32F4_ADON);
}
static int stm32_adc_single_conv(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *res)
{
struct stm32_adc *adc = iio_priv(indio_dev);
long timeout;
u32 val;
u16 result;
int ret;
reinit_completion(&adc->completion);
adc->buffer = &result;
val = stm32_adc_readl(adc, STM32F4_ADC_SQR3);
val &= ~STM32F4_SQ1_MASK;
val |= chan->channel << STM32F4_SQ1_SHIFT;
stm32_adc_writel(adc, STM32F4_ADC_SQR3, val);
stm32_adc_clr_bits(adc, STM32F4_ADC_SQR1, STM32F4_L_MASK);
stm32_adc_clr_bits(adc, STM32F4_ADC_CR2, STM32F4_EXTEN_MASK);
stm32_adc_conv_irq_enable(adc);
stm32_adc_start_conv(adc);
timeout = wait_for_completion_interruptible_timeout(
&adc->completion, STM32_ADC_TIMEOUT);
if (timeout == 0) {
ret = -ETIMEDOUT;
} else if (timeout < 0) {
ret = timeout;
} else {
*res = result;
ret = IIO_VAL_INT;
}
stm32_adc_stop_conv(adc);
stm32_adc_conv_irq_disable(adc);
return ret;
}
static int stm32_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct stm32_adc *adc = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = iio_device_claim_direct_mode(indio_dev);
if (ret)
return ret;
if (chan->type == IIO_VOLTAGE)
ret = stm32_adc_single_conv(indio_dev, chan, val);
else
ret = -EINVAL;
iio_device_release_direct_mode(indio_dev);
return ret;
case IIO_CHAN_INFO_SCALE:
*val = adc->common->vref_mv;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
default:
return -EINVAL;
}
}
static irqreturn_t stm32_adc_isr(int irq, void *data)
{
struct stm32_adc *adc = data;
u32 status = stm32_adc_readl(adc, STM32F4_ADC_SR);
if (status & STM32F4_EOC) {
*adc->buffer = stm32_adc_readw(adc, STM32F4_ADC_DR);
complete(&adc->completion);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int stm32_adc_of_xlate(struct iio_dev *indio_dev,
const struct of_phandle_args *iiospec)
{
int i;
for (i = 0; i < indio_dev->num_channels; i++)
if (indio_dev->channels[i].channel == iiospec->args[0])
return i;
return -EINVAL;
}
static int stm32_adc_debugfs_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct stm32_adc *adc = iio_priv(indio_dev);
if (!readval)
stm32_adc_writel(adc, reg, writeval);
else
*readval = stm32_adc_readl(adc, reg);
return 0;
}
static void stm32_adc_chan_init_one(struct iio_dev *indio_dev,
struct iio_chan_spec *chan,
const struct stm32_adc_chan_spec *channel,
int scan_index)
{
chan->type = channel->type;
chan->channel = channel->channel;
chan->datasheet_name = channel->name;
chan->scan_index = scan_index;
chan->indexed = 1;
chan->info_mask_separate = BIT(IIO_CHAN_INFO_RAW);
chan->info_mask_shared_by_type = BIT(IIO_CHAN_INFO_SCALE);
chan->scan_type.sign = 'u';
chan->scan_type.realbits = 12;
chan->scan_type.storagebits = 16;
}
static int stm32_adc_chan_of_init(struct iio_dev *indio_dev)
{
struct device_node *node = indio_dev->dev.of_node;
struct property *prop;
const __be32 *cur;
struct iio_chan_spec *channels;
int scan_index = 0, num_channels;
u32 val;
num_channels = of_property_count_u32_elems(node, "st,adc-channels");
if (num_channels < 0 ||
num_channels >= ARRAY_SIZE(stm32f4_adc123_channels)) {
dev_err(&indio_dev->dev, "Bad st,adc-channels?\n");
return num_channels < 0 ? num_channels : -EINVAL;
}
channels = devm_kcalloc(&indio_dev->dev, num_channels,
sizeof(struct iio_chan_spec), GFP_KERNEL);
if (!channels)
return -ENOMEM;
of_property_for_each_u32(node, "st,adc-channels", prop, cur, val) {
if (val >= ARRAY_SIZE(stm32f4_adc123_channels)) {
dev_err(&indio_dev->dev, "Invalid channel %d\n", val);
return -EINVAL;
}
stm32_adc_chan_init_one(indio_dev, &channels[scan_index],
&stm32f4_adc123_channels[val],
scan_index);
scan_index++;
}
indio_dev->num_channels = scan_index;
indio_dev->channels = channels;
return 0;
}
static int stm32_adc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct stm32_adc *adc;
int ret;
if (!pdev->dev.of_node)
return -ENODEV;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc));
if (!indio_dev)
return -ENOMEM;
adc = iio_priv(indio_dev);
adc->common = dev_get_drvdata(pdev->dev.parent);
spin_lock_init(&adc->lock);
init_completion(&adc->completion);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &stm32_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
platform_set_drvdata(pdev, adc);
ret = of_property_read_u32(pdev->dev.of_node, "reg", &adc->offset);
if (ret != 0) {
dev_err(&pdev->dev, "missing reg property\n");
return -EINVAL;
}
adc->irq = platform_get_irq(pdev, 0);
if (adc->irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return adc->irq;
}
ret = devm_request_irq(&pdev->dev, adc->irq, stm32_adc_isr,
0, pdev->name, adc);
if (ret) {
dev_err(&pdev->dev, "failed to request IRQ\n");
return ret;
}
adc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(adc->clk)) {
dev_err(&pdev->dev, "Can't get clock\n");
return PTR_ERR(adc->clk);
}
ret = clk_prepare_enable(adc->clk);
if (ret < 0) {
dev_err(&pdev->dev, "clk enable failed\n");
return ret;
}
ret = stm32_adc_chan_of_init(indio_dev);
if (ret < 0)
goto err_clk_disable;
ret = iio_device_register(indio_dev);
if (ret) {
dev_err(&pdev->dev, "iio dev register failed\n");
goto err_clk_disable;
}
return 0;
err_clk_disable:
clk_disable_unprepare(adc->clk);
return ret;
}
static int stm32_adc_remove(struct platform_device *pdev)
{
struct stm32_adc *adc = platform_get_drvdata(pdev);
struct iio_dev *indio_dev = iio_priv_to_dev(adc);
iio_device_unregister(indio_dev);
clk_disable_unprepare(adc->clk);
return 0;
}
