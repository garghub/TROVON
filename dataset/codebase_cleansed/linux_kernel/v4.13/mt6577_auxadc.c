static inline void mt6577_auxadc_mod_reg(void __iomem *reg,
u32 or_mask, u32 and_mask)
{
u32 val;
val = readl(reg);
val |= or_mask;
val &= ~and_mask;
writel(val, reg);
}
static int mt6577_auxadc_read(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan)
{
u32 val;
void __iomem *reg_channel;
int ret;
struct mt6577_auxadc_device *adc_dev = iio_priv(indio_dev);
reg_channel = adc_dev->reg_base + MT6577_AUXADC_DAT0 +
chan->channel * 0x04;
mutex_lock(&adc_dev->lock);
mt6577_auxadc_mod_reg(adc_dev->reg_base + MT6577_AUXADC_CON1,
0, 1 << chan->channel);
ret = readl_poll_timeout(reg_channel, val,
((val & MT6577_AUXADC_RDY0) == 0),
MT6577_AUXADC_SLEEP_US,
MT6577_AUXADC_TIMEOUT_US);
if (ret < 0) {
dev_err(indio_dev->dev.parent,
"wait for channel[%d] ready bit clear time out\n",
chan->channel);
goto err_timeout;
}
mt6577_auxadc_mod_reg(adc_dev->reg_base + MT6577_AUXADC_CON1,
1 << chan->channel, 0);
udelay(MT6577_AUXADC_SAMPLE_READY_US);
ret = readl_poll_timeout(adc_dev->reg_base + MT6577_AUXADC_CON2, val,
((val & MT6577_AUXADC_STA) == 0),
MT6577_AUXADC_SLEEP_US,
MT6577_AUXADC_TIMEOUT_US);
if (ret < 0) {
dev_err(indio_dev->dev.parent,
"wait for auxadc idle time out\n");
goto err_timeout;
}
ret = readl_poll_timeout(reg_channel, val,
((val & MT6577_AUXADC_RDY0) != 0),
MT6577_AUXADC_SLEEP_US,
MT6577_AUXADC_TIMEOUT_US);
if (ret < 0) {
dev_err(indio_dev->dev.parent,
"wait for channel[%d] data ready time out\n",
chan->channel);
goto err_timeout;
}
val = readl(reg_channel) & MT6577_AUXADC_DAT_MASK;
mutex_unlock(&adc_dev->lock);
return val;
err_timeout:
mutex_unlock(&adc_dev->lock);
return -ETIMEDOUT;
}
static int mt6577_auxadc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long info)
{
switch (info) {
case IIO_CHAN_INFO_PROCESSED:
*val = mt6577_auxadc_read(indio_dev, chan);
if (*val < 0) {
dev_err(indio_dev->dev.parent,
"failed to sample data on channel[%d]\n",
chan->channel);
return *val;
}
return IIO_VAL_INT;
default:
return -EINVAL;
}
}
static int mt6577_auxadc_probe(struct platform_device *pdev)
{
struct mt6577_auxadc_device *adc_dev;
unsigned long adc_clk_rate;
struct resource *res;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*adc_dev));
if (!indio_dev)
return -ENOMEM;
adc_dev = iio_priv(indio_dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = dev_name(&pdev->dev);
indio_dev->info = &mt6577_auxadc_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = mt6577_auxadc_iio_channels;
indio_dev->num_channels = ARRAY_SIZE(mt6577_auxadc_iio_channels);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
adc_dev->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(adc_dev->reg_base)) {
dev_err(&pdev->dev, "failed to get auxadc base address\n");
return PTR_ERR(adc_dev->reg_base);
}
adc_dev->adc_clk = devm_clk_get(&pdev->dev, "main");
if (IS_ERR(adc_dev->adc_clk)) {
dev_err(&pdev->dev, "failed to get auxadc clock\n");
return PTR_ERR(adc_dev->adc_clk);
}
ret = clk_prepare_enable(adc_dev->adc_clk);
if (ret) {
dev_err(&pdev->dev, "failed to enable auxadc clock\n");
return ret;
}
adc_clk_rate = clk_get_rate(adc_dev->adc_clk);
if (!adc_clk_rate) {
ret = -EINVAL;
dev_err(&pdev->dev, "null clock rate\n");
goto err_disable_clk;
}
mutex_init(&adc_dev->lock);
mt6577_auxadc_mod_reg(adc_dev->reg_base + MT6577_AUXADC_MISC,
MT6577_AUXADC_PDN_EN, 0);
mdelay(MT6577_AUXADC_POWER_READY_MS);
platform_set_drvdata(pdev, indio_dev);
ret = iio_device_register(indio_dev);
if (ret < 0) {
dev_err(&pdev->dev, "failed to register iio device\n");
goto err_power_off;
}
return 0;
err_power_off:
mt6577_auxadc_mod_reg(adc_dev->reg_base + MT6577_AUXADC_MISC,
0, MT6577_AUXADC_PDN_EN);
err_disable_clk:
clk_disable_unprepare(adc_dev->adc_clk);
return ret;
}
static int mt6577_auxadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct mt6577_auxadc_device *adc_dev = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
mt6577_auxadc_mod_reg(adc_dev->reg_base + MT6577_AUXADC_MISC,
0, MT6577_AUXADC_PDN_EN);
clk_disable_unprepare(adc_dev->adc_clk);
return 0;
}
