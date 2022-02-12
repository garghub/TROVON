static inline bool get_down(unsigned long data0, unsigned long data1)
{
return (!(data0 & S3C2410_ADCDAT0_UPDOWN) &&
!(data1 & S3C2410_ADCDAT0_UPDOWN));
}
static void touch_timer_fire(unsigned long data)
{
unsigned long data0;
unsigned long data1;
bool down;
data0 = readl(ts.io + S3C2410_ADCDAT0);
data1 = readl(ts.io + S3C2410_ADCDAT1);
down = get_down(data0, data1);
if (down) {
if (ts.count == (1 << ts.shift)) {
ts.xp >>= ts.shift;
ts.yp >>= ts.shift;
dev_dbg(ts.dev, "%s: X=%lu, Y=%lu, count=%d\n",
__func__, ts.xp, ts.yp, ts.count);
input_report_abs(ts.input, ABS_X, ts.xp);
input_report_abs(ts.input, ABS_Y, ts.yp);
input_report_key(ts.input, BTN_TOUCH, 1);
input_sync(ts.input);
ts.xp = 0;
ts.yp = 0;
ts.count = 0;
}
s3c_adc_start(ts.client, 0, 1 << ts.shift);
} else {
ts.xp = 0;
ts.yp = 0;
ts.count = 0;
input_report_key(ts.input, BTN_TOUCH, 0);
input_sync(ts.input);
writel(WAIT4INT | INT_DOWN, ts.io + S3C2410_ADCTSC);
}
}
static irqreturn_t stylus_irq(int irq, void *dev_id)
{
unsigned long data0;
unsigned long data1;
bool down;
data0 = readl(ts.io + S3C2410_ADCDAT0);
data1 = readl(ts.io + S3C2410_ADCDAT1);
down = get_down(data0, data1);
if (down)
s3c_adc_start(ts.client, 0, 1 << ts.shift);
else
dev_dbg(ts.dev, "%s: count=%d\n", __func__, ts.count);
if (ts.features & FEAT_PEN_IRQ) {
writel(0x0, ts.io + S3C64XX_ADCCLRINTPNDNUP);
}
return IRQ_HANDLED;
}
static void s3c24xx_ts_conversion(struct s3c_adc_client *client,
unsigned data0, unsigned data1,
unsigned *left)
{
dev_dbg(ts.dev, "%s: %d,%d\n", __func__, data0, data1);
ts.xp += data0;
ts.yp += data1;
ts.count++;
}
static void s3c24xx_ts_select(struct s3c_adc_client *client, unsigned select)
{
if (select) {
writel(S3C2410_ADCTSC_PULL_UP_DISABLE | AUTOPST,
ts.io + S3C2410_ADCTSC);
} else {
mod_timer(&touch_timer, jiffies+1);
writel(WAIT4INT | INT_UP, ts.io + S3C2410_ADCTSC);
}
}
static int s3c2410ts_probe(struct platform_device *pdev)
{
struct s3c2410_ts_mach_info *info;
struct device *dev = &pdev->dev;
struct input_dev *input_dev;
struct resource *res;
int ret = -EINVAL;
memset(&ts, 0, sizeof(struct s3c2410ts));
ts.dev = dev;
info = dev_get_platdata(&pdev->dev);
if (!info) {
dev_err(dev, "no platform data, cannot attach\n");
return -EINVAL;
}
dev_dbg(dev, "initialising touchscreen\n");
ts.clock = clk_get(dev, "adc");
if (IS_ERR(ts.clock)) {
dev_err(dev, "cannot get adc clock source\n");
return -ENOENT;
}
clk_prepare_enable(ts.clock);
dev_dbg(dev, "got and enabled clocks\n");
ts.irq_tc = ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(dev, "no resource for interrupt\n");
goto err_clk;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "no resource for registers\n");
ret = -ENOENT;
goto err_clk;
}
ts.io = ioremap(res->start, resource_size(res));
if (ts.io == NULL) {
dev_err(dev, "cannot map registers\n");
ret = -ENOMEM;
goto err_clk;
}
if (info->cfg_gpio)
info->cfg_gpio(to_platform_device(ts.dev));
ts.client = s3c_adc_register(pdev, s3c24xx_ts_select,
s3c24xx_ts_conversion, 1);
if (IS_ERR(ts.client)) {
dev_err(dev, "failed to register adc client\n");
ret = PTR_ERR(ts.client);
goto err_iomap;
}
if ((info->delay & 0xffff) > 0)
writel(info->delay & 0xffff, ts.io + S3C2410_ADCDLY);
writel(WAIT4INT | INT_DOWN, ts.io + S3C2410_ADCTSC);
input_dev = input_allocate_device();
if (!input_dev) {
dev_err(dev, "Unable to allocate the input device !!\n");
ret = -ENOMEM;
goto err_iomap;
}
ts.input = input_dev;
ts.input->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
ts.input->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(ts.input, ABS_X, 0, 0x3FF, 0, 0);
input_set_abs_params(ts.input, ABS_Y, 0, 0x3FF, 0, 0);
ts.input->name = "S3C24XX TouchScreen";
ts.input->id.bustype = BUS_HOST;
ts.input->id.vendor = 0xDEAD;
ts.input->id.product = 0xBEEF;
ts.input->id.version = 0x0102;
ts.shift = info->oversampling_shift;
ts.features = platform_get_device_id(pdev)->driver_data;
ret = request_irq(ts.irq_tc, stylus_irq, 0,
"s3c2410_ts_pen", ts.input);
if (ret) {
dev_err(dev, "cannot get TC interrupt\n");
goto err_inputdev;
}
dev_info(dev, "driver attached, registering input device\n");
ret = input_register_device(ts.input);
if (ret < 0) {
dev_err(dev, "failed to register input device\n");
ret = -EIO;
goto err_tcirq;
}
return 0;
err_tcirq:
free_irq(ts.irq_tc, ts.input);
err_inputdev:
input_free_device(ts.input);
err_iomap:
iounmap(ts.io);
err_clk:
del_timer_sync(&touch_timer);
clk_put(ts.clock);
return ret;
}
static int s3c2410ts_remove(struct platform_device *pdev)
{
free_irq(ts.irq_tc, ts.input);
del_timer_sync(&touch_timer);
clk_disable_unprepare(ts.clock);
clk_put(ts.clock);
input_unregister_device(ts.input);
iounmap(ts.io);
return 0;
}
static int s3c2410ts_suspend(struct device *dev)
{
writel(TSC_SLEEP, ts.io + S3C2410_ADCTSC);
disable_irq(ts.irq_tc);
clk_disable(ts.clock);
return 0;
}
static int s3c2410ts_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct s3c2410_ts_mach_info *info = dev_get_platdata(&pdev->dev);
clk_enable(ts.clock);
enable_irq(ts.irq_tc);
if ((info->delay & 0xffff) > 0)
writel(info->delay & 0xffff, ts.io + S3C2410_ADCDLY);
writel(WAIT4INT | INT_DOWN, ts.io + S3C2410_ADCTSC);
return 0;
}
