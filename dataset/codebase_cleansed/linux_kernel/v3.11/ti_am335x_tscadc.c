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
void am335x_tsc_se_update(struct ti_tscadc_dev *tsadc)
{
tscadc_writel(tsadc, REG_SE, tsadc->reg_se_cache);
}
void am335x_tsc_se_set(struct ti_tscadc_dev *tsadc, u32 val)
{
spin_lock(&tsadc->reg_lock);
tsadc->reg_se_cache |= val;
spin_unlock(&tsadc->reg_lock);
am335x_tsc_se_update(tsadc);
}
void am335x_tsc_se_clr(struct ti_tscadc_dev *tsadc, u32 val)
{
spin_lock(&tsadc->reg_lock);
tsadc->reg_se_cache &= ~val;
spin_unlock(&tsadc->reg_lock);
am335x_tsc_se_update(tsadc);
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
struct device_node *node = pdev->dev.of_node;
struct mfd_cell *cell;
struct property *prop;
const __be32 *cur;
u32 val;
int err, ctrl;
int clk_value, clock_rate;
int tsc_wires = 0, adc_channels = 0, total_channels;
int readouts = 0;
if (!pdev->dev.of_node) {
dev_err(&pdev->dev, "Could not find valid DT data.\n");
return -EINVAL;
}
node = of_get_child_by_name(pdev->dev.of_node, "tsc");
of_property_read_u32(node, "ti,wires", &tsc_wires);
of_property_read_u32(node, "ti,coordiante-readouts", &readouts);
node = of_get_child_by_name(pdev->dev.of_node, "adc");
of_property_for_each_u32(node, "ti,adc-channels", prop, cur, val) {
adc_channels++;
if (val > 7) {
dev_err(&pdev->dev, " PIN numbers are 0..7 (not %d)\n",
val);
return -EINVAL;
}
}
total_channels = tsc_wires + adc_channels;
if (total_channels > 8) {
dev_err(&pdev->dev, "Number of i/p channels more than 8\n");
return -EINVAL;
}
if (total_channels == 0) {
dev_err(&pdev->dev, "Need atleast one channel.\n");
return -EINVAL;
}
if (readouts * 2 + 2 + adc_channels > 16) {
dev_err(&pdev->dev, "Too many step configurations requested\n");
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
spin_lock_init(&tscadc->reg_lock);
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
tscadc->used_cells = 0;
tscadc->tsc_cell = -1;
tscadc->adc_cell = -1;
if (tsc_wires > 0) {
tscadc->tsc_cell = tscadc->used_cells;
cell = &tscadc->cells[tscadc->used_cells++];
cell->name = "TI-am335x-tsc";
cell->of_compatible = "ti,am3359-tsc";
cell->platform_data = &tscadc;
cell->pdata_size = sizeof(tscadc);
}
if (adc_channels > 0) {
tscadc->adc_cell = tscadc->used_cells;
cell = &tscadc->cells[tscadc->used_cells++];
cell->name = "TI-am335x-adc";
cell->of_compatible = "ti,am3359-adc";
cell->platform_data = &tscadc;
cell->pdata_size = sizeof(tscadc);
}
err = mfd_add_devices(&pdev->dev, pdev->id, tscadc->cells,
tscadc->used_cells, NULL, 0, NULL);
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
am335x_tsc_se_update(tscadc_dev);
restore = tscadc_readl(tscadc_dev, REG_CTRL);
tscadc_writel(tscadc_dev, REG_CTRL,
(restore | CNTRLREG_TSCSSENB));
return 0;
}
