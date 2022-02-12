static void samsung_keypad_scan(struct samsung_keypad *keypad,
unsigned int *row_state)
{
unsigned int col;
unsigned int val;
for (col = 0; col < keypad->cols; col++) {
if (keypad->type == KEYPAD_TYPE_S5PV210) {
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
pm_runtime_get_sync(&keypad->pdev->dev);
do {
val = readl(keypad->base + SAMSUNG_KEYIFSTSCLR);
writel(~0x0, keypad->base + SAMSUNG_KEYIFSTSCLR);
samsung_keypad_scan(keypad, row_state);
key_down = samsung_keypad_report(keypad, row_state);
if (key_down)
wait_event_timeout(keypad->wait, keypad->stopped,
msecs_to_jiffies(50));
} while (key_down && !keypad->stopped);
pm_runtime_put(&keypad->pdev->dev);
return IRQ_HANDLED;
}
static void samsung_keypad_start(struct samsung_keypad *keypad)
{
unsigned int val;
pm_runtime_get_sync(&keypad->pdev->dev);
keypad->stopped = false;
clk_enable(keypad->clk);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
val |= SAMSUNG_KEYIFCON_INT_F_EN | SAMSUNG_KEYIFCON_INT_R_EN;
writel(val, keypad->base + SAMSUNG_KEYIFCON);
writel(0, keypad->base + SAMSUNG_KEYIFCOL);
pm_runtime_put(&keypad->pdev->dev);
}
static void samsung_keypad_stop(struct samsung_keypad *keypad)
{
unsigned int val;
pm_runtime_get_sync(&keypad->pdev->dev);
keypad->stopped = true;
wake_up(&keypad->wait);
disable_irq(keypad->irq);
writel(~0x0, keypad->base + SAMSUNG_KEYIFSTSCLR);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
val &= ~(SAMSUNG_KEYIFCON_INT_F_EN | SAMSUNG_KEYIFCON_INT_R_EN);
writel(val, keypad->base + SAMSUNG_KEYIFCON);
clk_disable(keypad->clk);
enable_irq(keypad->irq);
pm_runtime_put(&keypad->pdev->dev);
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
static struct samsung_keypad_platdata *
samsung_keypad_parse_dt(struct device *dev)
{
struct samsung_keypad_platdata *pdata;
struct matrix_keymap_data *keymap_data;
uint32_t *keymap, num_rows = 0, num_cols = 0;
struct device_node *np = dev->of_node, *key_np;
unsigned int key_count;
if (!np) {
dev_err(dev, "missing device tree data\n");
return ERR_PTR(-EINVAL);
}
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(dev, "could not allocate memory for platform data\n");
return ERR_PTR(-ENOMEM);
}
of_property_read_u32(np, "samsung,keypad-num-rows", &num_rows);
of_property_read_u32(np, "samsung,keypad-num-columns", &num_cols);
if (!num_rows || !num_cols) {
dev_err(dev, "number of keypad rows/columns not specified\n");
return ERR_PTR(-EINVAL);
}
pdata->rows = num_rows;
pdata->cols = num_cols;
keymap_data = devm_kzalloc(dev, sizeof(*keymap_data), GFP_KERNEL);
if (!keymap_data) {
dev_err(dev, "could not allocate memory for keymap data\n");
return ERR_PTR(-ENOMEM);
}
pdata->keymap_data = keymap_data;
key_count = of_get_child_count(np);
keymap_data->keymap_size = key_count;
keymap = devm_kzalloc(dev, sizeof(uint32_t) * key_count, GFP_KERNEL);
if (!keymap) {
dev_err(dev, "could not allocate memory for keymap\n");
return ERR_PTR(-ENOMEM);
}
keymap_data->keymap = keymap;
for_each_child_of_node(np, key_np) {
u32 row, col, key_code;
of_property_read_u32(key_np, "keypad,row", &row);
of_property_read_u32(key_np, "keypad,column", &col);
of_property_read_u32(key_np, "linux,code", &key_code);
*keymap++ = KEY(row, col, key_code);
}
if (of_get_property(np, "linux,input-no-autorepeat", NULL))
pdata->no_autorepeat = true;
pdata->wakeup = of_property_read_bool(np, "wakeup-source") ||
of_property_read_bool(np, "linux,input-wakeup");
return pdata;
}
static struct samsung_keypad_platdata *
samsung_keypad_parse_dt(struct device *dev)
{
dev_err(dev, "no platform data defined\n");
return ERR_PTR(-EINVAL);
}
static int samsung_keypad_probe(struct platform_device *pdev)
{
const struct samsung_keypad_platdata *pdata;
const struct matrix_keymap_data *keymap_data;
struct samsung_keypad *keypad;
struct resource *res;
struct input_dev *input_dev;
unsigned int row_shift;
unsigned int keymap_size;
int error;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
pdata = samsung_keypad_parse_dt(&pdev->dev);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
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
keypad = devm_kzalloc(&pdev->dev, sizeof(*keypad) + keymap_size,
GFP_KERNEL);
input_dev = devm_input_allocate_device(&pdev->dev);
if (!keypad || !input_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
keypad->base = devm_ioremap(&pdev->dev, res->start, resource_size(res));
if (!keypad->base)
return -EBUSY;
keypad->clk = devm_clk_get(&pdev->dev, "keypad");
if (IS_ERR(keypad->clk)) {
dev_err(&pdev->dev, "failed to get keypad clk\n");
return PTR_ERR(keypad->clk);
}
error = clk_prepare(keypad->clk);
if (error) {
dev_err(&pdev->dev, "keypad clock prepare failed\n");
return error;
}
keypad->input_dev = input_dev;
keypad->pdev = pdev;
keypad->row_shift = row_shift;
keypad->rows = pdata->rows;
keypad->cols = pdata->cols;
keypad->stopped = true;
init_waitqueue_head(&keypad->wait);
if (pdev->dev.of_node)
keypad->type = of_device_is_compatible(pdev->dev.of_node,
"samsung,s5pv210-keypad");
else
keypad->type = platform_get_device_id(pdev)->driver_data;
input_dev->name = pdev->name;
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &pdev->dev;
input_dev->open = samsung_keypad_open;
input_dev->close = samsung_keypad_close;
error = matrix_keypad_build_keymap(keymap_data, NULL,
pdata->rows, pdata->cols,
keypad->keycodes, input_dev);
if (error) {
dev_err(&pdev->dev, "failed to build keymap\n");
goto err_unprepare_clk;
}
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
if (!pdata->no_autorepeat)
__set_bit(EV_REP, input_dev->evbit);
input_set_drvdata(input_dev, keypad);
keypad->irq = platform_get_irq(pdev, 0);
if (keypad->irq < 0) {
error = keypad->irq;
goto err_unprepare_clk;
}
error = devm_request_threaded_irq(&pdev->dev, keypad->irq, NULL,
samsung_keypad_irq, IRQF_ONESHOT,
dev_name(&pdev->dev), keypad);
if (error) {
dev_err(&pdev->dev, "failed to register keypad interrupt\n");
goto err_unprepare_clk;
}
device_init_wakeup(&pdev->dev, pdata->wakeup);
platform_set_drvdata(pdev, keypad);
pm_runtime_enable(&pdev->dev);
error = input_register_device(keypad->input_dev);
if (error)
goto err_disable_runtime_pm;
if (pdev->dev.of_node) {
devm_kfree(&pdev->dev, (void *)pdata->keymap_data->keymap);
devm_kfree(&pdev->dev, (void *)pdata->keymap_data);
devm_kfree(&pdev->dev, (void *)pdata);
}
return 0;
err_disable_runtime_pm:
pm_runtime_disable(&pdev->dev);
err_unprepare_clk:
clk_unprepare(keypad->clk);
return error;
}
static int samsung_keypad_remove(struct platform_device *pdev)
{
struct samsung_keypad *keypad = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
input_unregister_device(keypad->input_dev);
clk_unprepare(keypad->clk);
return 0;
}
static int samsung_keypad_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct samsung_keypad *keypad = platform_get_drvdata(pdev);
unsigned int val;
int error;
if (keypad->stopped)
return 0;
error = enable_irq_wake(keypad->irq);
if (!error)
keypad->wake_enabled = true;
val = readl(keypad->base + SAMSUNG_KEYIFCON);
val |= SAMSUNG_KEYIFCON_WAKEUPEN;
writel(val, keypad->base + SAMSUNG_KEYIFCON);
clk_disable(keypad->clk);
return 0;
}
static int samsung_keypad_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct samsung_keypad *keypad = platform_get_drvdata(pdev);
unsigned int val;
if (keypad->stopped)
return 0;
clk_enable(keypad->clk);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
val &= ~SAMSUNG_KEYIFCON_WAKEUPEN;
writel(val, keypad->base + SAMSUNG_KEYIFCON);
if (keypad->wake_enabled)
disable_irq_wake(keypad->irq);
return 0;
}
static void samsung_keypad_toggle_wakeup(struct samsung_keypad *keypad,
bool enable)
{
unsigned int val;
clk_enable(keypad->clk);
val = readl(keypad->base + SAMSUNG_KEYIFCON);
if (enable) {
val |= SAMSUNG_KEYIFCON_WAKEUPEN;
if (device_may_wakeup(&keypad->pdev->dev))
enable_irq_wake(keypad->irq);
} else {
val &= ~SAMSUNG_KEYIFCON_WAKEUPEN;
if (device_may_wakeup(&keypad->pdev->dev))
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
