static void exynos_adc_unprepare_clk(struct exynos_adc *info)
{
if (info->data->needs_sclk)
clk_unprepare(info->sclk);
clk_unprepare(info->clk);
}
static int exynos_adc_prepare_clk(struct exynos_adc *info)
{
int ret;
ret = clk_prepare(info->clk);
if (ret) {
dev_err(info->dev, "failed preparing adc clock: %d\n", ret);
return ret;
}
if (info->data->needs_sclk) {
ret = clk_prepare(info->sclk);
if (ret) {
clk_unprepare(info->clk);
dev_err(info->dev,
"failed preparing sclk_adc clock: %d\n", ret);
return ret;
}
}
return 0;
}
static void exynos_adc_disable_clk(struct exynos_adc *info)
{
if (info->data->needs_sclk)
clk_disable(info->sclk);
clk_disable(info->clk);
}
static int exynos_adc_enable_clk(struct exynos_adc *info)
{
int ret;
ret = clk_enable(info->clk);
if (ret) {
dev_err(info->dev, "failed enabling adc clock: %d\n", ret);
return ret;
}
if (info->data->needs_sclk) {
ret = clk_enable(info->sclk);
if (ret) {
clk_disable(info->clk);
dev_err(info->dev,
"failed enabling sclk_adc clock: %d\n", ret);
return ret;
}
}
return 0;
}
static void exynos_adc_v1_init_hw(struct exynos_adc *info)
{
u32 con1;
if (info->data->needs_adc_phy)
writel(1, info->enable_reg);
con1 = ADC_V1_CON_PRSCLV(49) | ADC_V1_CON_PRSCEN;
con1 |= ADC_V1_CON_RES;
writel(con1, ADC_V1_CON(info->regs));
}
static void exynos_adc_v1_exit_hw(struct exynos_adc *info)
{
u32 con;
if (info->data->needs_adc_phy)
writel(0, info->enable_reg);
con = readl(ADC_V1_CON(info->regs));
con |= ADC_V1_CON_STANDBY;
writel(con, ADC_V1_CON(info->regs));
}
static void exynos_adc_v1_clear_irq(struct exynos_adc *info)
{
writel(1, ADC_V1_INTCLR(info->regs));
}
static void exynos_adc_v1_start_conv(struct exynos_adc *info,
unsigned long addr)
{
u32 con1;
writel(addr, ADC_V1_MUX(info->regs));
con1 = readl(ADC_V1_CON(info->regs));
writel(con1 | ADC_CON_EN_START, ADC_V1_CON(info->regs));
}
static void exynos_adc_s3c2416_start_conv(struct exynos_adc *info,
unsigned long addr)
{
u32 con1;
con1 = readl(ADC_V1_CON(info->regs));
con1 |= ADC_S3C2416_CON_RES_SEL;
writel(con1, ADC_V1_CON(info->regs));
writel(addr, ADC_S3C2410_MUX(info->regs));
con1 = readl(ADC_V1_CON(info->regs));
writel(con1 | ADC_CON_EN_START, ADC_V1_CON(info->regs));
}
static void exynos_adc_s3c2443_start_conv(struct exynos_adc *info,
unsigned long addr)
{
u32 con1;
writel(addr, ADC_S3C2410_MUX(info->regs));
con1 = readl(ADC_V1_CON(info->regs));
writel(con1 | ADC_CON_EN_START, ADC_V1_CON(info->regs));
}
static void exynos_adc_s3c64xx_start_conv(struct exynos_adc *info,
unsigned long addr)
{
u32 con1;
con1 = readl(ADC_V1_CON(info->regs));
con1 &= ~ADC_S3C2410_CON_SELMUX(0x7);
con1 |= ADC_S3C2410_CON_SELMUX(addr);
writel(con1 | ADC_CON_EN_START, ADC_V1_CON(info->regs));
}
static void exynos_adc_v2_init_hw(struct exynos_adc *info)
{
u32 con1, con2;
if (info->data->needs_adc_phy)
writel(1, info->enable_reg);
con1 = ADC_V2_CON1_SOFT_RESET;
writel(con1, ADC_V2_CON1(info->regs));
con2 = ADC_V2_CON2_OSEL | ADC_V2_CON2_ESEL |
ADC_V2_CON2_HIGHF | ADC_V2_CON2_C_TIME(0);
writel(con2, ADC_V2_CON2(info->regs));
writel(1, ADC_V2_INT_EN(info->regs));
}
static void exynos_adc_v2_exit_hw(struct exynos_adc *info)
{
u32 con;
if (info->data->needs_adc_phy)
writel(0, info->enable_reg);
con = readl(ADC_V2_CON1(info->regs));
con &= ~ADC_CON_EN_START;
writel(con, ADC_V2_CON1(info->regs));
}
static void exynos_adc_v2_clear_irq(struct exynos_adc *info)
{
writel(1, ADC_V2_INT_ST(info->regs));
}
static void exynos_adc_v2_start_conv(struct exynos_adc *info,
unsigned long addr)
{
u32 con1, con2;
con2 = readl(ADC_V2_CON2(info->regs));
con2 &= ~ADC_V2_CON2_ACH_MASK;
con2 |= ADC_V2_CON2_ACH_SEL(addr);
writel(con2, ADC_V2_CON2(info->regs));
con1 = readl(ADC_V2_CON1(info->regs));
writel(con1 | ADC_CON_EN_START, ADC_V2_CON1(info->regs));
}
static struct exynos_adc_data *exynos_adc_get_data(struct platform_device *pdev)
{
const struct of_device_id *match;
match = of_match_node(exynos_adc_match, pdev->dev.of_node);
return (struct exynos_adc_data *)match->data;
}
static int exynos_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long mask)
{
struct exynos_adc *info = iio_priv(indio_dev);
unsigned long timeout;
int ret;
if (mask != IIO_CHAN_INFO_RAW)
return -EINVAL;
mutex_lock(&indio_dev->mlock);
reinit_completion(&info->completion);
if (info->data->start_conv)
info->data->start_conv(info, chan->address);
timeout = wait_for_completion_timeout
(&info->completion, EXYNOS_ADC_TIMEOUT);
if (timeout == 0) {
dev_warn(&indio_dev->dev, "Conversion timed out! Resetting\n");
if (info->data->init_hw)
info->data->init_hw(info);
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
u32 mask = info->data->mask;
info->value = readl(ADC_V1_DATX(info->regs)) & mask;
if (info->data->clear_irq)
info->data->clear_irq(info);
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
info->data = exynos_adc_get_data(pdev);
if (!info->data) {
dev_err(&pdev->dev, "failed getting exynos_adc_data\n");
return -EINVAL;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->regs))
return PTR_ERR(info->regs);
if (info->data->needs_adc_phy) {
mem = platform_get_resource(pdev, IORESOURCE_MEM, 1);
info->enable_reg = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(info->enable_reg))
return PTR_ERR(info->enable_reg);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
info->irq = irq;
info->dev = &pdev->dev;
init_completion(&info->completion);
info->clk = devm_clk_get(&pdev->dev, "adc");
if (IS_ERR(info->clk)) {
dev_err(&pdev->dev, "failed getting clock, err = %ld\n",
PTR_ERR(info->clk));
return PTR_ERR(info->clk);
}
if (info->data->needs_sclk) {
info->sclk = devm_clk_get(&pdev->dev, "sclk");
if (IS_ERR(info->sclk)) {
dev_err(&pdev->dev,
"failed getting sclk clock, err = %ld\n",
PTR_ERR(info->sclk));
return PTR_ERR(info->sclk);
}
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
ret = exynos_adc_prepare_clk(info);
if (ret)
goto err_disable_reg;
ret = exynos_adc_enable_clk(info);
if (ret)
goto err_unprepare_clk;
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->info = &exynos_adc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = exynos_adc_iio_channels;
indio_dev->num_channels = info->data->num_channels;
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
if (info->data->init_hw)
info->data->init_hw(info);
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
if (info->data->exit_hw)
info->data->exit_hw(info);
exynos_adc_disable_clk(info);
err_unprepare_clk:
exynos_adc_unprepare_clk(info);
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
if (info->data->exit_hw)
info->data->exit_hw(info);
exynos_adc_disable_clk(info);
exynos_adc_unprepare_clk(info);
regulator_disable(info->vdd);
return 0;
}
static int exynos_adc_suspend(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct exynos_adc *info = iio_priv(indio_dev);
if (info->data->exit_hw)
info->data->exit_hw(info);
exynos_adc_disable_clk(info);
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
ret = exynos_adc_enable_clk(info);
if (ret)
return ret;
if (info->data->init_hw)
info->data->init_hw(info);
return 0;
}
