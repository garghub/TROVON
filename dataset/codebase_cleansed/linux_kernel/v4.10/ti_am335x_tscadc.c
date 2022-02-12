void am335x_tsc_se_set_cache(struct ti_tscadc_dev *tscadc, u32 val)
{
unsigned long flags;
spin_lock_irqsave(&tscadc->reg_lock, flags);
tscadc->reg_se_cache |= val;
if (tscadc->adc_waiting)
wake_up(&tscadc->reg_se_wait);
else if (!tscadc->adc_in_use)
regmap_write(tscadc->regmap, REG_SE, tscadc->reg_se_cache);
spin_unlock_irqrestore(&tscadc->reg_lock, flags);
}
static void am335x_tscadc_need_adc(struct ti_tscadc_dev *tscadc)
{
DEFINE_WAIT(wait);
u32 reg;
regmap_read(tscadc->regmap, REG_ADCFSM, &reg);
if (reg & SEQ_STATUS) {
tscadc->adc_waiting = true;
prepare_to_wait(&tscadc->reg_se_wait, &wait,
TASK_UNINTERRUPTIBLE);
spin_unlock_irq(&tscadc->reg_lock);
schedule();
spin_lock_irq(&tscadc->reg_lock);
finish_wait(&tscadc->reg_se_wait, &wait);
regmap_read(tscadc->regmap, REG_ADCFSM, &reg);
WARN_ON((reg & SEQ_STATUS) && !(reg & CHARGE_STEP));
tscadc->adc_waiting = false;
}
tscadc->adc_in_use = true;
}
void am335x_tsc_se_set_once(struct ti_tscadc_dev *tscadc, u32 val)
{
spin_lock_irq(&tscadc->reg_lock);
am335x_tscadc_need_adc(tscadc);
regmap_write(tscadc->regmap, REG_SE, val);
spin_unlock_irq(&tscadc->reg_lock);
}
void am335x_tsc_se_adc_done(struct ti_tscadc_dev *tscadc)
{
unsigned long flags;
spin_lock_irqsave(&tscadc->reg_lock, flags);
tscadc->adc_in_use = false;
regmap_write(tscadc->regmap, REG_SE, tscadc->reg_se_cache);
spin_unlock_irqrestore(&tscadc->reg_lock, flags);
}
void am335x_tsc_se_clr(struct ti_tscadc_dev *tscadc, u32 val)
{
unsigned long flags;
spin_lock_irqsave(&tscadc->reg_lock, flags);
tscadc->reg_se_cache &= ~val;
regmap_write(tscadc->regmap, REG_SE, tscadc->reg_se_cache);
spin_unlock_irqrestore(&tscadc->reg_lock, flags);
}
static void tscadc_idle_config(struct ti_tscadc_dev *tscadc)
{
unsigned int idleconfig;
idleconfig = STEPCONFIG_YNN | STEPCONFIG_INM_ADCREFM |
STEPCONFIG_INP_ADCREFM | STEPCONFIG_YPN;
regmap_write(tscadc->regmap, REG_IDLECONFIG, idleconfig);
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
int clock_rate;
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
tscadc = devm_kzalloc(&pdev->dev, sizeof(*tscadc), GFP_KERNEL);
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
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tscadc->tscadc_phys_base = res->start;
tscadc->tscadc_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tscadc->tscadc_base))
return PTR_ERR(tscadc->tscadc_base);
tscadc->regmap = devm_regmap_init_mmio(&pdev->dev,
tscadc->tscadc_base, &tscadc_regmap_config);
if (IS_ERR(tscadc->regmap)) {
dev_err(&pdev->dev, "regmap init failed\n");
err = PTR_ERR(tscadc->regmap);
goto ret;
}
spin_lock_init(&tscadc->reg_lock);
init_waitqueue_head(&tscadc->reg_se_wait);
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
tscadc->clk_div = clock_rate / ADC_CLK;
tscadc->clk_div--;
regmap_write(tscadc->regmap, REG_CLKDIV, tscadc->clk_div);
ctrl = CNTRLREG_STEPCONFIGWRT | CNTRLREG_STEPID;
regmap_write(tscadc->regmap, REG_CTRL, ctrl);
if (tsc_wires > 0) {
tscadc->tsc_wires = tsc_wires;
if (tsc_wires == 5)
ctrl |= CNTRLREG_5WIRE | CNTRLREG_TSCENB;
else
ctrl |= CNTRLREG_4WIRE | CNTRLREG_TSCENB;
tscadc_idle_config(tscadc);
}
ctrl |= CNTRLREG_TSCSSENB;
regmap_write(tscadc->regmap, REG_CTRL, ctrl);
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
regmap_write(tscadc->regmap, REG_SE, 0x00);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
mfd_remove_devices(tscadc->dev);
return 0;
}
static int __maybe_unused tscadc_suspend(struct device *dev)
{
struct ti_tscadc_dev *tscadc = dev_get_drvdata(dev);
regmap_write(tscadc->regmap, REG_SE, 0x00);
pm_runtime_put_sync(dev);
return 0;
}
static int __maybe_unused tscadc_resume(struct device *dev)
{
struct ti_tscadc_dev *tscadc = dev_get_drvdata(dev);
u32 ctrl;
pm_runtime_get_sync(dev);
ctrl = CNTRLREG_STEPCONFIGWRT | CNTRLREG_STEPID;
regmap_write(tscadc->regmap, REG_CTRL, ctrl);
if (tscadc->tsc_cell != -1) {
if (tscadc->tsc_wires == 5)
ctrl |= CNTRLREG_5WIRE | CNTRLREG_TSCENB;
else
ctrl |= CNTRLREG_4WIRE | CNTRLREG_TSCENB;
tscadc_idle_config(tscadc);
}
ctrl |= CNTRLREG_TSCSSENB;
regmap_write(tscadc->regmap, REG_CTRL, ctrl);
regmap_write(tscadc->regmap, REG_CLKDIV, tscadc->clk_div);
return 0;
}
