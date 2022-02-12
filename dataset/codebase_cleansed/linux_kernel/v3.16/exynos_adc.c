static inline unsigned int exynos_adc_get_version(struct platform_device *pdev)
{
const struct of_device_id *match;
match = of_match_node(exynos_adc_match, pdev->dev.of_node);
return (unsigned int)match->data;
}
static void exynos_adc_hw_init(struct exynos_adc *info)
{
u32 con1, con2;
if (info->version == ADC_V2) {
con1 = ADC_V2_CON1_SOFT_RESET;
writel(con1, ADC_V2_CON1(info->regs));
con2 = ADC_V2_CON2_OSEL | ADC_V2_CON2_ESEL |
ADC_V2_CON2_HIGHF | ADC_V2_CON2_C_TIME(0);
writel(con2, ADC_V2_CON2(info->regs));
writel(1, ADC_V2_INT_EN(info->regs));
} else {
con1 = ADC_V1_CON_PRSCLV(49) | ADC_V1_CON_PRSCEN;
con1 |= ADC_V1_CON_RES;
writel(con1, ADC_V1_CON(info->regs));
}
}
static int exynos_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct exynos_adc *info = iio_priv(indio_dev);
unsigned long timeout;
u32 con1, con2;
int ret;
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
reinit_completion(&info->completion);
if (info->version == ADC_V2) {
con2 = readl(ADC_V2_CON2(info->regs));
con2 &= ~ADC_V2_CON2_ACH_MASK;
con2 |= ADC_V2_CON2_ACH_SEL(chan->address);
writel(con2, ADC_V2_CON2(info->regs));
con1 = readl(ADC_V2_CON1(info->regs));
writel(con1 | ADC_CON_EN_START,
ADC_V2_CON1(info->regs));
} else {
writel(chan->address, ADC_V1_MUX(info->regs));
con1 = readl(ADC_V1_CON(info->regs));
writel(con1 | ADC_CON_EN_START,
ADC_V1_CON(info->regs));
}
timeout = wait_for_completion_timeout
(&info->completion, EXYNOS_ADC_TIMEOUT);
if (timeout == 0) {
dev_warn(&indio_dev->dev, "Conversion timed out! Resetting\n");
exynos_adc_hw_init(info);
ret = -ETIMEDOUT;
} else {
*val = info->value;
*val2 = 0;
ret = IIO_VAL_INT;
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static irqreturn_t exynos_adc_isr(int irq, void *dev_id)
{
struct exynos_adc *info = (struct exynos_adc *)dev_id;
info->value = readl(ADC_V1_DATX(info->regs)) &
ADC_DATX_MASK;
if (info->version == ADC_V2)
writel(1, ADC_V2_INT_ST(info->regs));
else
writel(1, ADC_V1_INTCLR(info->regs));
complete(&info->completion);
return IRQ_HANDLED;
}
static int exynos_adc_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
struct exynos_adc *info = iio_priv(indio_dev);
if (readval == NULL)
return -EINVAL;
*readval = readl(info->regs + reg);
return 0;
}
static int exynos_adc_remove_devices(struct device *dev, void *c)
{
struct platform_device *pdev = to_platform_device(dev);
platform_device_unregister(pdev);
return 0;
}
static int exynos_adc_probe(struct platform_device *pdev)
{
struct exynos_adc *info = NULL;
struct device_node *np = pdev->dev.of_node;
struct iio_dev *indio_dev = NULL;
struct resource *mem;
int ret = -ENODEV;
int irq;
if (!np)
return ret;
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(struct exynos_adc));
if (!indio_dev) {
dev_err(&pdev->dev, "failed allocating iio device\n");
return -ENOMEM;
}
info = iio_priv(indio_dev);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
info->enable_reg = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->enable_reg))
return PTR_ERR(info->enable_reg);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
info->irq = irq;
init_completion(&info->completion);
info->clk = devm_clk_get(&pdev->dev, "adc");
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed getting clock, err = %ld\n",
PTR_ERR(info->clk));
return PTR_ERR(info->clk);
}
info->vdd = devm_regulator_get(&pdev->dev, "vdd");
if (IS_ERR(info->vdd)) {
dev_err(&pdev->dev, "failed getting regulator, err = %ld\n",
PTR_ERR(info->vdd));
return PTR_ERR(info->vdd);
}
ret = regulator_enable(info->vdd);
if (ret)
return ret;
ret = clk_prepare_enable(info->clk);
if (ret)
goto err_disable_reg;
writel(1, info->enable_reg);
info->version = exynos_adc_get_version(pdev);
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &exynos_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = exynos_adc_iio_channels;
if (info->version == ADC_V1)
indio_dev->num_channels = MAX_ADC_V1_CHANNELS;
else
indio_dev->num_channels = MAX_ADC_V2_CHANNELS;
ret = request_irq(info->irq, exynos_adc_isr,
0, dev_name(&pdev->dev), info);
if (ret < 0) {
dev_err(&pdev->dev, "failed requesting irq, irq = %d\n",
info->irq);
goto err_disable_clk;
}
ret = iio_device_register(indio_dev);
if (ret)
goto err_irq;
exynos_adc_hw_init(info);
ret = of_platform_populate(np, exynos_adc_match, NULL, &indio_dev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "failed adding child nodes\n");
goto err_of_populate;
}
return 0;
err_of_populate:
device_for_each_child(&indio_dev->dev, NULL,
exynos_adc_remove_devices);
iio_device_unregister(indio_dev);
err_irq:
free_irq(info->irq, info);
err_disable_clk:
writel(0, info->enable_reg);
clk_disable_unprepare(info->clk);
err_disable_reg:
regulator_disable(info->vdd);
return ret;
}
static int exynos_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct exynos_adc *info = iio_priv(indio_dev);
device_for_each_child(&indio_dev->dev, NULL,
exynos_adc_remove_devices);
iio_device_unregister(indio_dev);
free_irq(info->irq, info);
writel(0, info->enable_reg);
clk_disable_unprepare(info->clk);
regulator_disable(info->vdd);
return 0;
}
static int exynos_adc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct exynos_adc *info = iio_priv(indio_dev);
u32 con;
if (info->version == ADC_V2) {
con = readl(ADC_V2_CON1(info->regs));
con &= ~ADC_CON_EN_START;
writel(con, ADC_V2_CON1(info->regs));
} else {
con = readl(ADC_V1_CON(info->regs));
con |= ADC_V1_CON_STANDBY;
writel(con, ADC_V1_CON(info->regs));
}
writel(0, info->enable_reg);
clk_disable_unprepare(info->clk);
regulator_disable(info->vdd);
return 0;
}
static int exynos_adc_resume(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct exynos_adc *info = iio_priv(indio_dev);
int ret;
ret = regulator_enable(info->vdd);
if (ret)
return ret;
ret = clk_prepare_enable(info->clk);
if (ret)
return ret;
writel(1, info->enable_reg);
exynos_adc_hw_init(info);
return 0;
}
