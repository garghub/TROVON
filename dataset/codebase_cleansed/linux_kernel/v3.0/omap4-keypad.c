static irqreturn_t omap4_keypad_interrupt(int irq, void *dev_id)
{
struct omap4_keypad *keypad_data = dev_id;
struct input_dev *input_dev = keypad_data->input;
unsigned char key_state[ARRAY_SIZE(keypad_data->key_state)];
unsigned int col, row, code, changed;
u32 *new_state = (u32 *) key_state;
__raw_writel(OMAP4_VAL_IRQDISABLE,
keypad_data->base + OMAP4_KBD_IRQENABLE);
*new_state = __raw_readl(keypad_data->base + OMAP4_KBD_FULLCODE31_0);
*(new_state + 1) = __raw_readl(keypad_data->base
+ OMAP4_KBD_FULLCODE63_32);
for (row = 0; row < keypad_data->rows; row++) {
changed = key_state[row] ^ keypad_data->key_state[row];
if (!changed)
continue;
for (col = 0; col < keypad_data->cols; col++) {
if (changed & (1 << col)) {
code = MATRIX_SCAN_CODE(row, col,
keypad_data->row_shift);
input_event(input_dev, EV_MSC, MSC_SCAN, code);
input_report_key(input_dev,
keypad_data->keymap[code],
key_state[row] & (1 << col));
}
}
}
input_sync(input_dev);
memcpy(keypad_data->key_state, key_state,
sizeof(keypad_data->key_state));
__raw_writel(__raw_readl(keypad_data->base + OMAP4_KBD_IRQSTATUS),
keypad_data->base + OMAP4_KBD_IRQSTATUS);
__raw_writel(OMAP4_DEF_IRQENABLE_EVENTEN | OMAP4_DEF_IRQENABLE_LONGKEY,
keypad_data->base + OMAP4_KBD_IRQENABLE);
return IRQ_HANDLED;
}
static int omap4_keypad_open(struct input_dev *input)
{
struct omap4_keypad *keypad_data = input_get_drvdata(input);
pm_runtime_get_sync(input->dev.parent);
disable_irq(keypad_data->irq);
__raw_writel(OMAP4_VAL_FUNCTIONALCFG,
keypad_data->base + OMAP4_KBD_CTRL);
__raw_writel(OMAP4_VAL_DEBOUNCINGTIME,
keypad_data->base + OMAP4_KBD_DEBOUNCINGTIME);
__raw_writel(OMAP4_VAL_IRQDISABLE,
keypad_data->base + OMAP4_KBD_IRQSTATUS);
__raw_writel(OMAP4_DEF_IRQENABLE_EVENTEN | OMAP4_DEF_IRQENABLE_LONGKEY,
keypad_data->base + OMAP4_KBD_IRQENABLE);
__raw_writel(OMAP4_DEF_WUP_EVENT_ENA | OMAP4_DEF_WUP_LONG_KEY_ENA,
keypad_data->base + OMAP4_KBD_WAKEUPENABLE);
enable_irq(keypad_data->irq);
return 0;
}
static void omap4_keypad_close(struct input_dev *input)
{
struct omap4_keypad *keypad_data = input_get_drvdata(input);
disable_irq(keypad_data->irq);
__raw_writel(OMAP4_VAL_IRQDISABLE,
keypad_data->base + OMAP4_KBD_IRQENABLE);
__raw_writel(__raw_readl(keypad_data->base + OMAP4_KBD_IRQSTATUS),
keypad_data->base + OMAP4_KBD_IRQSTATUS);
enable_irq(keypad_data->irq);
pm_runtime_put_sync(input->dev.parent);
}
static int __devinit omap4_keypad_probe(struct platform_device *pdev)
{
const struct omap4_keypad_platform_data *pdata;
struct omap4_keypad *keypad_data;
struct input_dev *input_dev;
struct resource *res;
resource_size_t size;
unsigned int row_shift, max_keys;
int irq;
int error;
pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "no platform data defined\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no base address specified\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (!irq) {
dev_err(&pdev->dev, "no keyboard irq assigned\n");
return -EINVAL;
}
if (!pdata->keymap_data) {
dev_err(&pdev->dev, "no keymap data defined\n");
return -EINVAL;
}
row_shift = get_count_order(pdata->cols);
max_keys = pdata->rows << row_shift;
keypad_data = kzalloc(sizeof(struct omap4_keypad) +
max_keys * sizeof(keypad_data->keymap[0]),
GFP_KERNEL);
if (!keypad_data) {
dev_err(&pdev->dev, "keypad_data memory allocation failed\n");
return -ENOMEM;
}
size = resource_size(res);
res = request_mem_region(res->start, size, pdev->name);
if (!res) {
dev_err(&pdev->dev, "can't request mem region\n");
error = -EBUSY;
goto err_free_keypad;
}
keypad_data->base = ioremap(res->start, resource_size(res));
if (!keypad_data->base) {
dev_err(&pdev->dev, "can't ioremap mem resource\n");
error = -ENOMEM;
goto err_release_mem;
}
keypad_data->irq = irq;
keypad_data->row_shift = row_shift;
keypad_data->rows = pdata->rows;
keypad_data->cols = pdata->cols;
keypad_data->input = input_dev = input_allocate_device();
if (!input_dev) {
error = -ENOMEM;
goto err_unmap;
}
input_dev->name = pdev->name;
input_dev->dev.parent = &pdev->dev;
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0001;
input_dev->open = omap4_keypad_open;
input_dev->close = omap4_keypad_close;
input_dev->keycode = keypad_data->keymap;
input_dev->keycodesize = sizeof(keypad_data->keymap[0]);
input_dev->keycodemax = max_keys;
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(EV_REP, input_dev->evbit);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_set_drvdata(input_dev, keypad_data);
matrix_keypad_build_keymap(pdata->keymap_data, row_shift,
input_dev->keycode, input_dev->keybit);
error = request_irq(keypad_data->irq, omap4_keypad_interrupt,
IRQF_TRIGGER_RISING,
"omap4-keypad", keypad_data);
if (error) {
dev_err(&pdev->dev, "failed to register interrupt\n");
goto err_free_input;
}
pm_runtime_enable(&pdev->dev);
error = input_register_device(keypad_data->input);
if (error < 0) {
dev_err(&pdev->dev, "failed to register input device\n");
goto err_pm_disable;
}
platform_set_drvdata(pdev, keypad_data);
return 0;
err_pm_disable:
pm_runtime_disable(&pdev->dev);
free_irq(keypad_data->irq, keypad_data);
err_free_input:
input_free_device(input_dev);
err_unmap:
iounmap(keypad_data->base);
err_release_mem:
release_mem_region(res->start, size);
err_free_keypad:
kfree(keypad_data);
return error;
}
static int __devexit omap4_keypad_remove(struct platform_device *pdev)
{
struct omap4_keypad *keypad_data = platform_get_drvdata(pdev);
struct resource *res;
free_irq(keypad_data->irq, keypad_data);
pm_runtime_disable(&pdev->dev);
input_unregister_device(keypad_data->input);
iounmap(keypad_data->base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
kfree(keypad_data);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int __init omap4_keypad_init(void)
{
return platform_driver_register(&omap4_keypad_driver);
}
static void __exit omap4_keypad_exit(void)
{
platform_driver_unregister(&omap4_keypad_driver);
}
