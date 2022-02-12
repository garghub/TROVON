static int samsung_keypad_is_s5pv210(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
enum samsung_keypad_type type =
platform_get_device_id(pdev)->driver_data;
return type == KEYPAD_TYPE_S5PV210;
}
static void samsung_keypad_scan(struct samsung_keypad *keypad,
unsigned int *row_state)
{
struct device *dev = keypad->input_dev->dev.parent;
unsigned int col;
unsigned int val;
for (col = 0; col < keypad->cols; col++) {
if (samsung_keypad_is_s5pv210(dev)) {
val = S5PV210_KEYIFCOLEN_MASK;
val &= ~(1 << col) << 8;
} else {
val = SAMSUNG_KEYIFCOL_MASK;
val &= ~(1 << col);
}
writel(val, keypad->base + SAMSUNG_KEYIFCOL);
mdelay(1);
val = readl(keypad->base + SAMSUNG_KEYIFROW);
row_state[col] = ~val & ((1 << keypad->rows) - 1);
}
writel(0, keypad->base + SAMSUNG_KEYIFCOL);
}
static bool samsung_keypad_report(struct samsung_keypad *keypad,
unsigned int *row_state)
{
struct input_dev *input_dev = keypad->input_dev;
unsigned int changed;
unsigned int pressed;
unsigned int key_down = 0;
unsigned int val;
unsigned int col, row;
for (col = 0; col < keypad->cols; col++) {
changed = row_state[col] ^ keypad->row_state[col];
key_down |= row_state[col];
if (!changed)
continue;
for (row = 0; row < keypad->rows; row++) {
if (!(changed & (1 << row)))
continue;
pressed = row_state[col] & (1 << row);
dev_dbg(&keypad->input_dev->dev,
"key %s, row: %d, col: %d\n",
pressed ? "pressed" : "released", row, col);
val = MATRIX_SCAN_CODE(row, col, keypad->row_shift);
input_event(input_dev, EV_MSC, MSC_SCAN, val);
input_report_key(input_dev,
keypad->keycodes[val], pressed);
}
input_sync(keypad->input_dev);
}
memcpy(keypad->row_state, row_state, sizeof(keypad->row_state));
return key_down;
}
static irqreturn_t samsung_keypad_irq(int irq, void *dev_id)
{
struct samsung_keypad *keypad = dev_id;
unsigned int row_state[SAMSUNG_MAX_COLS];
unsigned int val;
bool key_down;
do {
val = readl(keypad->base + SAMSUNG_KEYIFSTSCLR);
writel(~0x0, keypad->base + SAMSUNG_KEYIFSTSCLR);
samsung_keypad_scan(keypad, row_state);
key_down = samsung_keypad_report(keypad, row_state);
if (key_down)
wait_event_timeout(keypad->wait, keypad->stopped,
msecs_to_jiffies(50));
} while (key_down && !keypad->stopped);
return IRQ_HANDLED;
}
static void samsung_keypad_start(struct samsung_keypad *keypad)
{
unsigned int val;
keypad->stopped = false;
clk_enable(keypad->clk);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
val |= SAMSUNG_KEYIFCON_INT_F_EN | SAMSUNG_KEYIFCON_INT_R_EN;
writel(val, keypad->base + SAMSUNG_KEYIFCON);
writel(0, keypad->base + SAMSUNG_KEYIFCOL);
}
static void samsung_keypad_stop(struct samsung_keypad *keypad)
{
unsigned int val;
keypad->stopped = true;
wake_up(&keypad->wait);
disable_irq(keypad->irq);
writel(~0x0, keypad->base + SAMSUNG_KEYIFSTSCLR);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
val &= ~(SAMSUNG_KEYIFCON_INT_F_EN | SAMSUNG_KEYIFCON_INT_R_EN);
writel(val, keypad->base + SAMSUNG_KEYIFCON);
clk_disable(keypad->clk);
enable_irq(keypad->irq);
}
static int samsung_keypad_open(struct input_dev *input_dev)
{
struct samsung_keypad *keypad = input_get_drvdata(input_dev);
samsung_keypad_start(keypad);
return 0;
}
static void samsung_keypad_close(struct input_dev *input_dev)
{
struct samsung_keypad *keypad = input_get_drvdata(input_dev);
samsung_keypad_stop(keypad);
}
static int __devinit samsung_keypad_probe(struct platform_device *pdev)
{
const struct samsung_keypad_platdata *pdata;
const struct matrix_keymap_data *keymap_data;
struct samsung_keypad *keypad;
struct resource *res;
struct input_dev *input_dev;
unsigned int row_shift;
unsigned int keymap_size;
int error;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "no platform data defined\n");
return -EINVAL;
}
keymap_data = pdata->keymap_data;
if (!keymap_data) {
dev_err(&pdev->dev, "no keymap data defined\n");
return -EINVAL;
}
if (!pdata->rows || pdata->rows > SAMSUNG_MAX_ROWS)
return -EINVAL;
if (!pdata->cols || pdata->cols > SAMSUNG_MAX_COLS)
return -EINVAL;
if (pdata->cfg_gpio)
pdata->cfg_gpio(pdata->rows, pdata->cols);
row_shift = get_count_order(pdata->cols);
keymap_size = (pdata->rows << row_shift) * sizeof(keypad->keycodes[0]);
keypad = kzalloc(sizeof(*keypad) + keymap_size, GFP_KERNEL);
input_dev = input_allocate_device();
if (!keypad || !input_dev) {
error = -ENOMEM;
goto err_free_mem;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
error = -ENODEV;
goto err_free_mem;
}
keypad->base = ioremap(res->start, resource_size(res));
if (!keypad->base) {
error = -EBUSY;
goto err_free_mem;
}
keypad->clk = clk_get(&pdev->dev, "keypad");
if (IS_ERR(keypad->clk)) {
dev_err(&pdev->dev, "failed to get keypad clk\n");
error = PTR_ERR(keypad->clk);
goto err_unmap_base;
}
keypad->input_dev = input_dev;
keypad->row_shift = row_shift;
keypad->rows = pdata->rows;
keypad->cols = pdata->cols;
init_waitqueue_head(&keypad->wait);
input_dev->name = pdev->name;
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &pdev->dev;
input_set_drvdata(input_dev, keypad);
input_dev->open = samsung_keypad_open;
input_dev->close = samsung_keypad_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY);
if (!pdata->no_autorepeat)
input_dev->evbit[0] |= BIT_MASK(EV_REP);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_dev->keycode = keypad->keycodes;
input_dev->keycodesize = sizeof(keypad->keycodes[0]);
input_dev->keycodemax = pdata->rows << row_shift;
matrix_keypad_build_keymap(keymap_data, row_shift,
input_dev->keycode, input_dev->keybit);
keypad->irq = platform_get_irq(pdev, 0);
if (keypad->irq < 0) {
error = keypad->irq;
goto err_put_clk;
}
error = request_threaded_irq(keypad->irq, NULL, samsung_keypad_irq,
IRQF_ONESHOT, dev_name(&pdev->dev), keypad);
if (error) {
dev_err(&pdev->dev, "failed to register keypad interrupt\n");
goto err_put_clk;
}
error = input_register_device(keypad->input_dev);
if (error)
goto err_free_irq;
device_init_wakeup(&pdev->dev, pdata->wakeup);
platform_set_drvdata(pdev, keypad);
return 0;
err_free_irq:
free_irq(keypad->irq, keypad);
err_put_clk:
clk_put(keypad->clk);
err_unmap_base:
iounmap(keypad->base);
err_free_mem:
input_free_device(input_dev);
kfree(keypad);
return error;
}
static int __devexit samsung_keypad_remove(struct platform_device *pdev)
{
struct samsung_keypad *keypad = platform_get_drvdata(pdev);
device_init_wakeup(&pdev->dev, 0);
platform_set_drvdata(pdev, NULL);
input_unregister_device(keypad->input_dev);
free_irq(keypad->irq, keypad);
clk_put(keypad->clk);
iounmap(keypad->base);
kfree(keypad);
return 0;
}
static void samsung_keypad_toggle_wakeup(struct samsung_keypad *keypad,
bool enable)
{
struct device *dev = keypad->input_dev->dev.parent;
unsigned int val;
clk_enable(keypad->clk);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
if (enable) {
val |= SAMSUNG_KEYIFCON_WAKEUPEN;
if (device_may_wakeup(dev))
enable_irq_wake(keypad->irq);
} else {
val &= ~SAMSUNG_KEYIFCON_WAKEUPEN;
if (device_may_wakeup(dev))
disable_irq_wake(keypad->irq);
}
writel(val, keypad->base + SAMSUNG_KEYIFCON);
clk_disable(keypad->clk);
}
static int samsung_keypad_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct samsung_keypad *keypad = platform_get_drvdata(pdev);
struct input_dev *input_dev = keypad->input_dev;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
samsung_keypad_stop(keypad);
samsung_keypad_toggle_wakeup(keypad, true);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int samsung_keypad_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct samsung_keypad *keypad = platform_get_drvdata(pdev);
struct input_dev *input_dev = keypad->input_dev;
mutex_lock(&input_dev->mutex);
samsung_keypad_toggle_wakeup(keypad, false);
if (input_dev->users)
samsung_keypad_start(keypad);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int __init samsung_keypad_init(void)
{
return platform_driver_register(&samsung_keypad_driver);
}
static void __exit samsung_keypad_exit(void)
{
platform_driver_unregister(&samsung_keypad_driver);
}
