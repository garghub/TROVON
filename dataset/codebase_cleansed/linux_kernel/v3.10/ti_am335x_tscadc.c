static unsigned int tscadc_readl(struct ti_tscadc_dev *tsadc, unsigned int reg)
{
unsigned int val;
regmap_read(tsadc->regmap_tscadc, reg, &val);
return val;
}
static void tscadc_writel(struct ti_tscadc_dev *tsadc, unsigned int reg,
unsigned int val)
{
regmap_write(tsadc->regmap_tscadc, reg, val);
}
static void tscadc_idle_config(struct ti_tscadc_dev *config)
{
unsigned int idleconfig;
idleconfig = STEPCONFIG_YNN | STEPCONFIG_INM_ADCREFM |
STEPCONFIG_INP_ADCREFM | STEPCONFIG_YPN;
tscadc_writel(config, REG_IDLECONFIG, idleconfig);
}
static int ti_tscadc_probe(struct platform_device *pdev)
{
struct ti_tscadc_dev *tscadc;
struct resource *res;
struct clk *clk;
struct mfd_tscadc_board *pdata = pdev->dev.platform_data;
struct mfd_cell *cell;
int err, ctrl;
int clk_value, clock_rate;
int tsc_wires, adc_channels = 0, total_channels;
if (!pdata) {
dev_err(&pdev->dev, "Could not find platform data\n");
return -EINVAL;
}
if (pdata->adc_init)
adc_channels = pdata->adc_init->adc_channels;
tsc_wires = pdata->tsc_init->wires;
total_channels = tsc_wires + adc_channels;
if (total_channels > 8) {
dev_err(&pdev->dev, "Number of i/p channels more than 8\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no memory resource defined.\n");
return -EINVAL;
}
tscadc = devm_kzalloc(&pdev->dev,
sizeof(struct ti_tscadc_dev), GFP_KERNEL);
if (!tscadc) {
dev_err(&pdev->dev, "failed to allocate memory.\n");
return -ENOMEM;
}
tscadc->dev = &pdev->dev;
err = platform_get_irq(pdev, 0);
if (err < 0) {
dev_err(&pdev->dev, "no irq ID is specified.\n");
goto ret;
} else
tscadc->irq = err;
res = devm_request_mem_region(&pdev->dev,
res->start, resource_size(res), pdev->name);
if (!res) {
dev_err(&pdev->dev, "failed to reserve registers.\n");
return -EBUSY;
}
tscadc->tscadc_base = devm_ioremap(&pdev->dev,
res->start, resource_size(res));
if (!tscadc->tscadc_base) {
dev_err(&pdev->dev, "failed to map registers.\n");
return -ENOMEM;
}
tscadc->regmap_tscadc = devm_regmap_init_mmio(&pdev->dev,
tscadc->tscadc_base, &tscadc_regmap_config);
if (IS_ERR(tscadc->regmap_tscadc)) {
dev_err(&pdev->dev, "regmap init failed\n");
err = PTR_ERR(tscadc->regmap_tscadc);
goto ret;
}
pm_runtime_enable(&pdev->dev);
pm_runtime_get_sync(&pdev->dev);
clk = clk_get(&pdev->dev, "adc_tsc_fck");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get TSC fck\n");
err = PTR_ERR(clk);
goto err_disable_clk;
}
clock_rate = clk_get_rate(clk);
clk_put(clk);
clk_value = clock_rate / ADC_CLK;
if (clk_value < MAX_CLK_DIV) {
dev_err(&pdev->dev, "clock input less than min clock requirement\n");
err = -EINVAL;
goto err_disable_clk;
}
clk_value = clk_value - 1;
tscadc_writel(tscadc, REG_CLKDIV, clk_value);
ctrl = CNTRLREG_STEPCONFIGWRT |
CNTRLREG_TSCENB |
CNTRLREG_STEPID |
CNTRLREG_4WIRE;
tscadc_writel(tscadc, REG_CTRL, ctrl);
tscadc_idle_config(tscadc);
ctrl = tscadc_readl(tscadc, REG_CTRL);
ctrl |= CNTRLREG_TSCSSENB;
tscadc_writel(tscadc, REG_CTRL, ctrl);
cell = &tscadc->cells[TSC_CELL];
cell->name = "tsc";
cell->platform_data = tscadc;
cell->pdata_size = sizeof(*tscadc);
cell = &tscadc->cells[ADC_CELL];
cell->name = "tiadc";
cell->platform_data = tscadc;
cell->pdata_size = sizeof(*tscadc);
err = mfd_add_devices(&pdev->dev, pdev->id, tscadc->cells,
TSCADC_CELLS, NULL, 0, NULL);
if (err < 0)
goto err_disable_clk;
device_init_wakeup(&pdev->dev, true);
platform_set_drvdata(pdev, tscadc);
return 0;
err_disable_clk:
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
ret:
return err;
}
static int ti_tscadc_remove(struct platform_device *pdev)
{
struct ti_tscadc_dev *tscadc = platform_get_drvdata(pdev);
tscadc_writel(tscadc, REG_SE, 0x00);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
mfd_remove_devices(tscadc->dev);
return 0;
}
static int tscadc_suspend(struct device *dev)
{
struct ti_tscadc_dev *tscadc_dev = dev_get_drvdata(dev);
tscadc_writel(tscadc_dev, REG_SE, 0x00);
pm_runtime_put_sync(dev);
return 0;
}
static int tscadc_resume(struct device *dev)
{
struct ti_tscadc_dev *tscadc_dev = dev_get_drvdata(dev);
unsigned int restore, ctrl;
pm_runtime_get_sync(dev);
ctrl = CNTRLREG_STEPCONFIGWRT | CNTRLREG_TSCENB |
CNTRLREG_STEPID | CNTRLREG_4WIRE;
tscadc_writel(tscadc_dev, REG_CTRL, ctrl);
tscadc_idle_config(tscadc_dev);
tscadc_writel(tscadc_dev, REG_SE, STPENB_STEPENB);
restore = tscadc_readl(tscadc_dev, REG_CTRL);
tscadc_writel(tscadc_dev, REG_CTRL,
(restore | CNTRLREG_TSCSSENB));
return 0;
}
