static void lpc32xx_fifo_clear(struct lpc32xx_tsc *tsc)
{
while (!(tsc_readl(tsc, LPC32XX_TSC_STAT) &
LPC32XX_TSC_STAT_FIFO_EMPTY))
tsc_readl(tsc, LPC32XX_TSC_FIFO);
}
static irqreturn_t lpc32xx_ts_interrupt(int irq, void *dev_id)
{
u32 tmp, rv[4], xs[4], ys[4];
int idx;
struct lpc32xx_tsc *tsc = dev_id;
struct input_dev *input = tsc->dev;
tmp = tsc_readl(tsc, LPC32XX_TSC_STAT);
if (tmp & LPC32XX_TSC_STAT_FIFO_OVRRN) {
lpc32xx_fifo_clear(tsc);
return IRQ_HANDLED;
}
idx = 0;
while (idx < 4 &&
!(tsc_readl(tsc, LPC32XX_TSC_STAT) &
LPC32XX_TSC_STAT_FIFO_EMPTY)) {
tmp = tsc_readl(tsc, LPC32XX_TSC_FIFO);
xs[idx] = LPC32XX_TSC_ADCDAT_VALUE_MASK -
LPC32XX_TSC_FIFO_NORMALIZE_X_VAL(tmp);
ys[idx] = LPC32XX_TSC_ADCDAT_VALUE_MASK -
LPC32XX_TSC_FIFO_NORMALIZE_Y_VAL(tmp);
rv[idx] = tmp;
idx++;
}
if (!(rv[3] & LPC32XX_TSC_FIFO_TS_P_LEVEL) && idx == 4) {
input_report_abs(input, ABS_X, (xs[1] + xs[2]) / 2);
input_report_abs(input, ABS_Y, (ys[1] + ys[2]) / 2);
input_report_key(input, BTN_TOUCH, 1);
} else {
input_report_key(input, BTN_TOUCH, 0);
}
input_sync(input);
return IRQ_HANDLED;
}
static void lpc32xx_stop_tsc(struct lpc32xx_tsc *tsc)
{
tsc_writel(tsc, LPC32XX_TSC_CON,
tsc_readl(tsc, LPC32XX_TSC_CON) &
~LPC32XX_TSC_ADCCON_AUTO_EN);
clk_disable(tsc->clk);
}
static void lpc32xx_setup_tsc(struct lpc32xx_tsc *tsc)
{
u32 tmp;
clk_enable(tsc->clk);
tmp = tsc_readl(tsc, LPC32XX_TSC_CON) & ~LPC32XX_TSC_ADCCON_POWER_UP;
tmp = LPC32XX_TSC_ADCCON_IRQ_TO_FIFO_4 |
LPC32XX_TSC_ADCCON_X_SAMPLE_SIZE(10) |
LPC32XX_TSC_ADCCON_Y_SAMPLE_SIZE(10);
tsc_writel(tsc, LPC32XX_TSC_CON, tmp);
tsc_writel(tsc, LPC32XX_TSC_SEL, LPC32XX_TSC_SEL_DEFVAL);
tsc_writel(tsc, LPC32XX_TSC_MIN_X, LPC32XX_TSC_MIN_XY_VAL);
tsc_writel(tsc, LPC32XX_TSC_MAX_X, LPC32XX_TSC_MAX_XY_VAL);
tsc_writel(tsc, LPC32XX_TSC_MIN_Y, LPC32XX_TSC_MIN_XY_VAL);
tsc_writel(tsc, LPC32XX_TSC_MAX_Y, LPC32XX_TSC_MAX_XY_VAL);
tsc_writel(tsc, LPC32XX_TSC_AUX_UTR, 0);
tsc_writel(tsc, LPC32XX_TSC_AUX_MIN, 0);
tsc_writel(tsc, LPC32XX_TSC_AUX_MAX, 0);
tsc_writel(tsc, LPC32XX_TSC_RTR, 0x2);
tsc_writel(tsc, LPC32XX_TSC_DTR, 0x2);
tsc_writel(tsc, LPC32XX_TSC_TTR, 0x10);
tsc_writel(tsc, LPC32XX_TSC_DXP, 0x4);
tsc_writel(tsc, LPC32XX_TSC_UTR, 88);
lpc32xx_fifo_clear(tsc);
tsc_writel(tsc, LPC32XX_TSC_CON, tmp | LPC32XX_TSC_ADCCON_AUTO_EN);
}
static int lpc32xx_ts_open(struct input_dev *dev)
{
struct lpc32xx_tsc *tsc = input_get_drvdata(dev);
lpc32xx_setup_tsc(tsc);
return 0;
}
static void lpc32xx_ts_close(struct input_dev *dev)
{
struct lpc32xx_tsc *tsc = input_get_drvdata(dev);
lpc32xx_stop_tsc(tsc);
}
static int lpc32xx_ts_probe(struct platform_device *pdev)
{
struct lpc32xx_tsc *tsc;
struct input_dev *input;
struct resource *res;
resource_size_t size;
int irq;
int error;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Can't get memory resource\n");
return -ENOENT;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "Can't get interrupt resource\n");
return irq;
}
tsc = kzalloc(sizeof(*tsc), GFP_KERNEL);
input = input_allocate_device();
if (!tsc || !input) {
dev_err(&pdev->dev, "failed allocating memory\n");
error = -ENOMEM;
goto err_free_mem;
}
tsc->dev = input;
tsc->irq = irq;
size = resource_size(res);
if (!request_mem_region(res->start, size, pdev->name)) {
dev_err(&pdev->dev, "TSC registers are not free\n");
error = -EBUSY;
goto err_free_mem;
}
tsc->tsc_base = ioremap(res->start, size);
if (!tsc->tsc_base) {
dev_err(&pdev->dev, "Can't map memory\n");
error = -ENOMEM;
goto err_release_mem;
}
tsc->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(tsc->clk)) {
dev_err(&pdev->dev, "failed getting clock\n");
error = PTR_ERR(tsc->clk);
goto err_unmap;
}
input->name = MOD_NAME;
input->phys = "lpc32xx/input0";
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0002;
input->id.version = 0x0100;
input->dev.parent = &pdev->dev;
input->open = lpc32xx_ts_open;
input->close = lpc32xx_ts_close;
input->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input, ABS_X, LPC32XX_TSC_MIN_XY_VAL,
LPC32XX_TSC_MAX_XY_VAL, 0, 0);
input_set_abs_params(input, ABS_Y, LPC32XX_TSC_MIN_XY_VAL,
LPC32XX_TSC_MAX_XY_VAL, 0, 0);
input_set_drvdata(input, tsc);
error = request_irq(tsc->irq, lpc32xx_ts_interrupt,
0, pdev->name, tsc);
if (error) {
dev_err(&pdev->dev, "failed requesting interrupt\n");
goto err_put_clock;
}
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev, "failed registering input device\n");
goto err_free_irq;
}
platform_set_drvdata(pdev, tsc);
device_init_wakeup(&pdev->dev, 1);
return 0;
err_free_irq:
free_irq(tsc->irq, tsc);
err_put_clock:
clk_put(tsc->clk);
err_unmap:
iounmap(tsc->tsc_base);
err_release_mem:
release_mem_region(res->start, size);
err_free_mem:
input_free_device(input);
kfree(tsc);
return error;
}
static int lpc32xx_ts_remove(struct platform_device *pdev)
{
struct lpc32xx_tsc *tsc = platform_get_drvdata(pdev);
struct resource *res;
device_init_wakeup(&pdev->dev, 0);
free_irq(tsc->irq, tsc);
input_unregister_device(tsc->dev);
clk_put(tsc->clk);
iounmap(tsc->tsc_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
kfree(tsc);
return 0;
}
static int lpc32xx_ts_suspend(struct device *dev)
{
struct lpc32xx_tsc *tsc = dev_get_drvdata(dev);
struct input_dev *input = tsc->dev;
mutex_lock(&input->mutex);
if (input->users) {
if (device_may_wakeup(dev))
enable_irq_wake(tsc->irq);
else
lpc32xx_stop_tsc(tsc);
}
mutex_unlock(&input->mutex);
return 0;
}
static int lpc32xx_ts_resume(struct device *dev)
{
struct lpc32xx_tsc *tsc = dev_get_drvdata(dev);
struct input_dev *input = tsc->dev;
mutex_lock(&input->mutex);
if (input->users) {
if (device_may_wakeup(dev))
disable_irq_wake(tsc->irq);
else
lpc32xx_setup_tsc(tsc);
}
mutex_unlock(&input->mutex);
return 0;
}
