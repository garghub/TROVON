static irqreturn_t spear_kbd_interrupt(int irq, void *dev_id)
{
struct spear_kbd *kbd = dev_id;
struct input_dev *input = kbd->input;
unsigned int key;
u32 sts, val;
sts = readl_relaxed(kbd->io_base + STATUS_REG);
if (!(sts & STATUS_DATA_AVAIL))
return IRQ_NONE;
if (kbd->last_key != KEY_RESERVED) {
input_report_key(input, kbd->last_key, 0);
kbd->last_key = KEY_RESERVED;
}
val = readl_relaxed(kbd->io_base + DATA_REG) &
(DATA_ROW_MASK | DATA_COLUMN_MASK);
key = kbd->keycodes[val];
input_event(input, EV_MSC, MSC_SCAN, val);
input_report_key(input, key, 1);
input_sync(input);
kbd->last_key = key;
writel_relaxed(0, kbd->io_base + STATUS_REG);
return IRQ_HANDLED;
}
static int spear_kbd_open(struct input_dev *dev)
{
struct spear_kbd *kbd = input_get_drvdata(dev);
int error;
u32 val;
kbd->last_key = KEY_RESERVED;
error = clk_enable(kbd->clk);
if (error)
return error;
val = clk_get_rate(kbd->clk) / 1000000 - 1;
val = (val & MODE_CTL_PCLK_FREQ_MSK) << MODE_CTL_PCLK_FREQ_SHIFT;
val = MODE_CTL_SCAN_RATE_80 | MODE_CTL_KEYBOARD | val |
(kbd->mode << MODE_CTL_KEYNUM_SHIFT);
writel_relaxed(val, kbd->io_base + MODE_CTL_REG);
writel_relaxed(1, kbd->io_base + STATUS_REG);
val = readl_relaxed(kbd->io_base + MODE_CTL_REG);
val |= MODE_CTL_START_SCAN;
writel_relaxed(val, kbd->io_base + MODE_CTL_REG);
return 0;
}
static void spear_kbd_close(struct input_dev *dev)
{
struct spear_kbd *kbd = input_get_drvdata(dev);
u32 val;
val = readl_relaxed(kbd->io_base + MODE_CTL_REG);
val &= ~MODE_CTL_START_SCAN;
writel_relaxed(val, kbd->io_base + MODE_CTL_REG);
clk_disable(kbd->clk);
kbd->last_key = KEY_RESERVED;
}
static int __devinit spear_kbd_parse_dt(struct platform_device *pdev,
struct spear_kbd *kbd)
{
struct device_node *np = pdev->dev.of_node;
int error;
u32 val, suspended_rate;
if (!np) {
dev_err(&pdev->dev, "Missing DT data\n");
return -EINVAL;
}
if (of_property_read_bool(np, "autorepeat"))
kbd->rep = true;
if (of_property_read_u32(np, "suspended_rate", &suspended_rate))
kbd->suspended_rate = suspended_rate;
error = of_property_read_u32(np, "st,mode", &val);
if (error) {
dev_err(&pdev->dev, "DT: Invalid or missing mode\n");
return error;
}
kbd->mode = val;
return 0;
}
static inline int spear_kbd_parse_dt(struct platform_device *pdev,
struct spear_kbd *kbd)
{
return -ENOSYS;
}
static int __devinit spear_kbd_probe(struct platform_device *pdev)
{
struct kbd_platform_data *pdata = dev_get_platdata(&pdev->dev);
const struct matrix_keymap_data *keymap = pdata ? pdata->keymap : NULL;
struct spear_kbd *kbd;
struct input_dev *input_dev;
struct resource *res;
int irq;
int error;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no keyboard resource defined\n");
return -EBUSY;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "not able to get irq for the device\n");
return irq;
}
kbd = kzalloc(sizeof(*kbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!kbd || !input_dev) {
dev_err(&pdev->dev, "out of memory\n");
error = -ENOMEM;
goto err_free_mem;
}
kbd->input = input_dev;
kbd->irq = irq;
if (!pdata) {
error = spear_kbd_parse_dt(pdev, kbd);
if (error)
goto err_free_mem;
} else {
kbd->mode = pdata->mode;
kbd->rep = pdata->rep;
kbd->suspended_rate = pdata->suspended_rate;
}
kbd->res = request_mem_region(res->start, resource_size(res),
pdev->name);
if (!kbd->res) {
dev_err(&pdev->dev, "keyboard region already claimed\n");
error = -EBUSY;
goto err_free_mem;
}
kbd->io_base = ioremap(res->start, resource_size(res));
if (!kbd->io_base) {
dev_err(&pdev->dev, "ioremap failed for kbd_region\n");
error = -ENOMEM;
goto err_release_mem_region;
}
kbd->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(kbd->clk)) {
error = PTR_ERR(kbd->clk);
goto err_iounmap;
}
input_dev->name = "Spear Keyboard";
input_dev->phys = "keyboard/input0";
input_dev->dev.parent = &pdev->dev;
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->open = spear_kbd_open;
input_dev->close = spear_kbd_close;
error = matrix_keypad_build_keymap(keymap, NULL, NUM_ROWS, NUM_COLS,
kbd->keycodes, input_dev);
if (error) {
dev_err(&pdev->dev, "Failed to build keymap\n");
goto err_put_clk;
}
if (kbd->rep)
__set_bit(EV_REP, input_dev->evbit);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_set_drvdata(input_dev, kbd);
error = request_irq(irq, spear_kbd_interrupt, 0, "keyboard", kbd);
if (error) {
dev_err(&pdev->dev, "request_irq fail\n");
goto err_put_clk;
}
error = input_register_device(input_dev);
if (error) {
dev_err(&pdev->dev, "Unable to register keyboard device\n");
goto err_free_irq;
}
device_init_wakeup(&pdev->dev, 1);
platform_set_drvdata(pdev, kbd);
return 0;
err_free_irq:
free_irq(kbd->irq, kbd);
err_put_clk:
clk_put(kbd->clk);
err_iounmap:
iounmap(kbd->io_base);
err_release_mem_region:
release_mem_region(res->start, resource_size(res));
err_free_mem:
input_free_device(input_dev);
kfree(kbd);
return error;
}
static int __devexit spear_kbd_remove(struct platform_device *pdev)
{
struct spear_kbd *kbd = platform_get_drvdata(pdev);
free_irq(kbd->irq, kbd);
input_unregister_device(kbd->input);
clk_put(kbd->clk);
iounmap(kbd->io_base);
release_mem_region(kbd->res->start, resource_size(kbd->res));
kfree(kbd);
device_init_wakeup(&pdev->dev, 0);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int spear_kbd_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct spear_kbd *kbd = platform_get_drvdata(pdev);
struct input_dev *input_dev = kbd->input;
unsigned int rate = 0, mode_ctl_reg, val;
mutex_lock(&input_dev->mutex);
clk_enable(kbd->clk);
mode_ctl_reg = readl_relaxed(kbd->io_base + MODE_CTL_REG);
if (device_may_wakeup(&pdev->dev)) {
enable_irq_wake(kbd->irq);
if (kbd->suspended_rate)
rate = kbd->suspended_rate / 1000000 - 1;
else
rate = clk_get_rate(kbd->clk) / 1000000 - 1;
val = mode_ctl_reg &
~(MODE_CTL_PCLK_FREQ_MSK << MODE_CTL_PCLK_FREQ_SHIFT);
val |= (rate & MODE_CTL_PCLK_FREQ_MSK)
<< MODE_CTL_PCLK_FREQ_SHIFT;
writel_relaxed(val, kbd->io_base + MODE_CTL_REG);
} else {
if (input_dev->users) {
writel_relaxed(mode_ctl_reg & ~MODE_CTL_START_SCAN,
kbd->io_base + MODE_CTL_REG);
clk_disable(kbd->clk);
}
}
if (input_dev->users)
kbd->mode_ctl_reg = mode_ctl_reg;
clk_disable(kbd->clk);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int spear_kbd_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct spear_kbd *kbd = platform_get_drvdata(pdev);
struct input_dev *input_dev = kbd->input;
mutex_lock(&input_dev->mutex);
if (device_may_wakeup(&pdev->dev)) {
disable_irq_wake(kbd->irq);
} else {
if (input_dev->users)
clk_enable(kbd->clk);
}
if (input_dev->users)
writel_relaxed(kbd->mode_ctl_reg, kbd->io_base + MODE_CTL_REG);
mutex_unlock(&input_dev->mutex);
return 0;
}
