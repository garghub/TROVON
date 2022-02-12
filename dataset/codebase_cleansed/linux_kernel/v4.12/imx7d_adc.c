static void imx7d_adc_feature_config(struct imx7d_adc *info)
{
info->adc_feature.clk_pre_div = IMX7D_ADC_ANALOG_CLK_PRE_DIV_4;
info->adc_feature.avg_num = IMX7D_ADC_AVERAGE_NUM_32;
info->adc_feature.core_time_unit = 1;
info->adc_feature.average_en = true;
}
static void imx7d_adc_sample_rate_set(struct imx7d_adc *info)
{
struct imx7d_adc_feature *adc_feature = &info->adc_feature;
struct imx7d_adc_analogue_core_clk adc_analogure_clk;
u32 i;
u32 tmp_cfg1;
u32 sample_rate = 0;
for (i = 0; i < 4; i++) {
tmp_cfg1 =
readl(info->regs + i * IMX7D_EACH_CHANNEL_REG_OFFSET);
tmp_cfg1 &= ~IMX7D_REG_ADC_CH_CFG1_CHANNEL_EN;
writel(tmp_cfg1,
info->regs + i * IMX7D_EACH_CHANNEL_REG_OFFSET);
}
adc_analogure_clk = imx7d_adc_analogue_clk[adc_feature->clk_pre_div];
sample_rate |= adc_analogure_clk.reg_config;
info->pre_div_num = adc_analogure_clk.pre_div;
sample_rate |= adc_feature->core_time_unit;
writel(sample_rate, info->regs + IMX7D_REG_ADC_TIMER_UNIT);
}
static void imx7d_adc_hw_init(struct imx7d_adc *info)
{
u32 cfg;
cfg = readl(info->regs + IMX7D_REG_ADC_ADC_CFG);
cfg &= ~(IMX7D_REG_ADC_ADC_CFG_ADC_CLK_DOWN |
IMX7D_REG_ADC_ADC_CFG_ADC_POWER_DOWN);
cfg |= IMX7D_REG_ADC_ADC_CFG_ADC_EN;
writel(cfg, info->regs + IMX7D_REG_ADC_ADC_CFG);
writel(IMX7D_REG_ADC_INT_CHANNEL_INT_EN,
info->regs + IMX7D_REG_ADC_INT_SIG_EN);
writel(IMX7D_REG_ADC_INT_CHANNEL_INT_EN,
info->regs + IMX7D_REG_ADC_INT_EN);
imx7d_adc_sample_rate_set(info);
}
static void imx7d_adc_channel_set(struct imx7d_adc *info)
{
u32 cfg1 = 0;
u32 cfg2;
u32 channel;
channel = info->channel;
cfg1 |= (IMX7D_REG_ADC_CH_CFG1_CHANNEL_EN |
IMX7D_REG_ADC_CH_CFG1_CHANNEL_SINGLE);
if (info->adc_feature.average_en)
cfg1 |= IMX7D_REG_ADC_CH_CFG1_CHANNEL_AVG_EN;
cfg1 |= IMX7D_REG_ADC_CH_CFG1_CHANNEL_SEL(channel);
cfg2 = readl(info->regs + IMX7D_EACH_CHANNEL_REG_OFFSET * channel +
IMX7D_REG_ADC_CHANNEL_CFG2_BASE);
cfg2 |= imx7d_adc_average_num[info->adc_feature.avg_num];
writel(cfg2, info->regs + IMX7D_EACH_CHANNEL_REG_OFFSET * channel +
IMX7D_REG_ADC_CHANNEL_CFG2_BASE);
writel(cfg1, info->regs + IMX7D_EACH_CHANNEL_REG_OFFSET * channel);
}
static u32 imx7d_adc_get_sample_rate(struct imx7d_adc *info)
{
u32 input_clk = 24000000;
u32 analogue_core_clk;
u32 core_time_unit = info->adc_feature.core_time_unit;
u32 tmp;
analogue_core_clk = input_clk / info->pre_div_num;
tmp = (core_time_unit + 1) * 6;
return analogue_core_clk / tmp;
}
static int imx7d_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct imx7d_adc *info = iio_priv(indio_dev);
u32 channel;
long ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&indio_dev->mlock);
reinit_completion(&info->completion);
channel = chan->channel & 0x03;
info->channel = channel;
imx7d_adc_channel_set(info);
ret = wait_for_completion_interruptible_timeout
(&info->completion, IMX7D_ADC_TIMEOUT);
if (ret == 0) {
mutex_unlock(&indio_dev->mlock);
return -ETIMEDOUT;
}
if (ret < 0) {
mutex_unlock(&indio_dev->mlock);
return ret;
}
*val = info->value;
mutex_unlock(&indio_dev->mlock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
info->vref_uv = regulator_get_voltage(info->vref);
*val = info->vref_uv / 1000;
*val2 = 12;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_SAMP_FREQ:
*val = imx7d_adc_get_sample_rate(info);
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int imx7d_adc_read_data(struct imx7d_adc *info)
{
u32 channel;
u32 value;
channel = info->channel & 0x03;
if (channel < 2)
value = readl(info->regs + IMX7D_REG_ADC_CHA_B_CNV_RSLT);
else
value = readl(info->regs + IMX7D_REG_ADC_CHC_D_CNV_RSLT);
if (channel & 0x1)
value = (value >> 16) & 0xFFF;
else
value &= 0xFFF;
return value;
}
static irqreturn_t imx7d_adc_isr(int irq, void *dev_id)
{
struct imx7d_adc *info = dev_id;
int status;
status = readl(info->regs + IMX7D_REG_ADC_INT_STATUS);
if (status & IMX7D_REG_ADC_INT_STATUS_CHANNEL_INT_STATUS) {
info->value = imx7d_adc_read_data(info);
complete(&info->completion);
status &= ~IMX7D_REG_ADC_INT_STATUS_CHANNEL_INT_STATUS;
writel(status, info->regs + IMX7D_REG_ADC_INT_STATUS);
}
if (status & IMX7D_REG_ADC_INT_STATUS_CHANNEL_CONV_TIME_OUT) {
pr_err("%s: ADC got conversion time out interrupt: 0x%08x\n",
dev_name(info->dev), status);
status &= ~IMX7D_REG_ADC_INT_STATUS_CHANNEL_CONV_TIME_OUT;
writel(status, info->regs + IMX7D_REG_ADC_INT_STATUS);
}
return IRQ_HANDLED;
}
static int imx7d_adc_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct imx7d_adc *info = iio_priv(indio_dev);
if (!readval || reg % 4 || reg > IMX7D_REG_ADC_ADC_CFG)
return -EINVAL;
*readval = readl(info->regs + reg);
return 0;
}
static void imx7d_adc_power_down(struct imx7d_adc *info)
{
u32 adc_cfg;
adc_cfg = readl(info->regs + IMX7D_REG_ADC_ADC_CFG);
adc_cfg |= IMX7D_REG_ADC_ADC_CFG_ADC_CLK_DOWN |
IMX7D_REG_ADC_ADC_CFG_ADC_POWER_DOWN;
adc_cfg &= ~IMX7D_REG_ADC_ADC_CFG_ADC_EN;
writel(adc_cfg, info->regs + IMX7D_REG_ADC_ADC_CFG);
}
static int imx7d_adc_probe(struct platform_device *pdev)
{
struct imx7d_adc *info;
struct iio_dev *indio_dev;
struct resource *mem;
int irq;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*info));
if (!indio_dev) {
dev_err(&pdev->dev, "Failed allocating iio device\n");
return -ENOMEM;
}
info = iio_priv(indio_dev);
info->dev = &pdev->dev;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->regs)) {
ret = PTR_ERR(info->regs);
dev_err(&pdev->dev,
"Failed to remap adc memory, err = %d\n", ret);
return ret;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No irq resource?\n");
return irq;
}
info->clk = devm_clk_get(&pdev->dev, "adc");
if (IS_ERR(info->clk)) {
ret = PTR_ERR(info->clk);
dev_err(&pdev->dev, "Failed getting clock, err = %d\n", ret);
return ret;
}
info->vref = devm_regulator_get(&pdev->dev, "vref");
if (IS_ERR(info->vref)) {
ret = PTR_ERR(info->vref);
dev_err(&pdev->dev,
"Failed getting reference voltage, err = %d\n", ret);
return ret;
}
ret = regulator_enable(info->vref);
if (ret) {
dev_err(&pdev->dev,
"Can't enable adc reference top voltage, err = %d\n",
ret);
return ret;
}
platform_set_drvdata(pdev, indio_dev);
init_completion(&info->completion);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &imx7d_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = imx7d_adc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(imx7d_adc_iio_channels);
ret = clk_prepare_enable(info->clk);
if (ret) {
dev_err(&pdev->dev,
"Could not prepare or enable the clock.\n");
goto error_adc_clk_enable;
}
ret = devm_request_irq(info->dev, irq,
imx7d_adc_isr, 0,
dev_name(&pdev->dev), info);
if (ret < 0) {
dev_err(&pdev->dev, "Failed requesting irq, irq = %d\n", irq);
goto error_iio_device_register;
}
imx7d_adc_feature_config(info);
imx7d_adc_hw_init(info);
ret = iio_device_register(indio_dev);
if (ret) {
imx7d_adc_power_down(info);
dev_err(&pdev->dev, "Couldn't register the device.\n");
goto error_iio_device_register;
}
return 0;
error_iio_device_register:
clk_disable_unprepare(info->clk);
error_adc_clk_enable:
regulator_disable(info->vref);
return ret;
}
static int imx7d_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct imx7d_adc *info = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
imx7d_adc_power_down(info);
clk_disable_unprepare(info->clk);
regulator_disable(info->vref);
return 0;
}
static int __maybe_unused imx7d_adc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct imx7d_adc *info = iio_priv(indio_dev);
imx7d_adc_power_down(info);
clk_disable_unprepare(info->clk);
regulator_disable(info->vref);
return 0;
}
static int __maybe_unused imx7d_adc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct imx7d_adc *info = iio_priv(indio_dev);
int ret;
ret = regulator_enable(info->vref);
if (ret) {
dev_err(info->dev,
"Can't enable adc reference top voltage, err = %d\n",
ret);
return ret;
}
ret = clk_prepare_enable(info->clk);
if (ret) {
dev_err(info->dev,
"Could not prepare or enable clock.\n");
regulator_disable(info->vref);
return ret;
}
imx7d_adc_hw_init(info);
return 0;
}
