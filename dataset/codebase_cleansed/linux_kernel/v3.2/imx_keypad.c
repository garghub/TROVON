static void imx_keypad_scan_matrix(struct imx_keypad *keypad,
unsigned short *matrix_volatile_state)
{
int col;
unsigned short reg_val;
for (col = 0; col < MAX_MATRIX_KEY_COLS; col++) {
if ((keypad->cols_en_mask & (1 << col)) == 0)
continue;
reg_val = readw(keypad->mmio_base + KPDR);
reg_val |= 0xff00;
writew(reg_val, keypad->mmio_base + KPDR);
reg_val = readw(keypad->mmio_base + KPCR);
reg_val &= ~((keypad->cols_en_mask & 0xff) << 8);
writew(reg_val, keypad->mmio_base + KPCR);
udelay(2);
reg_val = readw(keypad->mmio_base + KPCR);
reg_val |= (keypad->cols_en_mask & 0xff) << 8;
writew(reg_val, keypad->mmio_base + KPCR);
reg_val = readw(keypad->mmio_base + KPDR);
reg_val &= ~(1 << (8 + col));
writew(reg_val, keypad->mmio_base + KPDR);
udelay(5);
reg_val = readw(keypad->mmio_base + KPDR);
matrix_volatile_state[col] = (~reg_val) & keypad->rows_en_mask;
}
reg_val = readw(keypad->mmio_base + KPDR);
reg_val &= 0x00ff;
writew(reg_val, keypad->mmio_base + KPDR);
}
static void imx_keypad_fire_events(struct imx_keypad *keypad,
unsigned short *matrix_volatile_state)
{
struct input_dev *input_dev = keypad->input_dev;
int row, col;
for (col = 0; col < MAX_MATRIX_KEY_COLS; col++) {
unsigned short bits_changed;
int code;
if ((keypad->cols_en_mask & (1 << col)) == 0)
continue;
bits_changed = keypad->matrix_stable_state[col] ^
matrix_volatile_state[col];
if (bits_changed == 0)
continue;
for (row = 0; row < MAX_MATRIX_KEY_ROWS; row++) {
if ((keypad->rows_en_mask & (1 << row)) == 0)
continue;
if ((bits_changed & (1 << row)) == 0)
continue;
code = MATRIX_SCAN_CODE(row, col, MATRIX_ROW_SHIFT);
input_event(input_dev, EV_MSC, MSC_SCAN, code);
input_report_key(input_dev, keypad->keycodes[code],
matrix_volatile_state[col] & (1 << row));
dev_dbg(&input_dev->dev, "Event code: %d, val: %d",
keypad->keycodes[code],
matrix_volatile_state[col] & (1 << row));
}
}
input_sync(input_dev);
}
static void imx_keypad_check_for_events(unsigned long data)
{
struct imx_keypad *keypad = (struct imx_keypad *) data;
unsigned short matrix_volatile_state[MAX_MATRIX_KEY_COLS];
unsigned short reg_val;
bool state_changed, is_zero_matrix;
int i;
memset(matrix_volatile_state, 0, sizeof(matrix_volatile_state));
imx_keypad_scan_matrix(keypad, matrix_volatile_state);
state_changed = false;
for (i = 0; i < MAX_MATRIX_KEY_COLS; i++) {
if ((keypad->cols_en_mask & (1 << i)) == 0)
continue;
if (keypad->matrix_unstable_state[i] ^ matrix_volatile_state[i]) {
state_changed = true;
break;
}
}
if (state_changed) {
memcpy(keypad->matrix_unstable_state, matrix_volatile_state,
sizeof(matrix_volatile_state));
keypad->stable_count = 0;
} else
keypad->stable_count++;
if (keypad->stable_count < IMX_KEYPAD_SCANS_FOR_STABILITY) {
mod_timer(&keypad->check_matrix_timer,
jiffies + msecs_to_jiffies(10));
return;
}
if (keypad->stable_count == IMX_KEYPAD_SCANS_FOR_STABILITY) {
imx_keypad_fire_events(keypad, matrix_volatile_state);
memcpy(keypad->matrix_stable_state, matrix_volatile_state,
sizeof(matrix_volatile_state));
}
is_zero_matrix = true;
for (i = 0; i < MAX_MATRIX_KEY_COLS; i++) {
if (matrix_volatile_state[i] != 0) {
is_zero_matrix = false;
break;
}
}
if (is_zero_matrix) {
reg_val = readw(keypad->mmio_base + KPSR);
reg_val |= KBD_STAT_KPKD | KBD_STAT_KDSC;
writew(reg_val, keypad->mmio_base + KPSR);
reg_val = readw(keypad->mmio_base + KPSR);
reg_val |= KBD_STAT_KDIE;
reg_val &= ~KBD_STAT_KRIE;
writew(reg_val, keypad->mmio_base + KPSR);
} else {
mod_timer(&keypad->check_matrix_timer,
jiffies + msecs_to_jiffies(60));
reg_val = readw(keypad->mmio_base + KPSR);
reg_val |= KBD_STAT_KPKR | KBD_STAT_KRSS;
writew(reg_val, keypad->mmio_base + KPSR);
reg_val = readw(keypad->mmio_base + KPSR);
reg_val |= KBD_STAT_KRIE;
reg_val &= ~KBD_STAT_KDIE;
writew(reg_val, keypad->mmio_base + KPSR);
}
}
static irqreturn_t imx_keypad_irq_handler(int irq, void *dev_id)
{
struct imx_keypad *keypad = dev_id;
unsigned short reg_val;
reg_val = readw(keypad->mmio_base + KPSR);
reg_val &= ~(KBD_STAT_KRIE | KBD_STAT_KDIE);
reg_val |= KBD_STAT_KPKR | KBD_STAT_KPKD;
writew(reg_val, keypad->mmio_base + KPSR);
if (keypad->enabled) {
keypad->stable_count = 0;
mod_timer(&keypad->check_matrix_timer,
jiffies + msecs_to_jiffies(2));
}
return IRQ_HANDLED;
}
static void imx_keypad_config(struct imx_keypad *keypad)
{
unsigned short reg_val;
reg_val = readw(keypad->mmio_base + KPCR);
reg_val |= keypad->rows_en_mask & 0xff;
reg_val |= (keypad->cols_en_mask & 0xff) << 8;
writew(reg_val, keypad->mmio_base + KPCR);
reg_val = readw(keypad->mmio_base + KPDR);
reg_val &= 0x00ff;
writew(reg_val, keypad->mmio_base + KPDR);
writew(0xff00, keypad->mmio_base + KDDR);
reg_val = readw(keypad->mmio_base + KPSR);
reg_val |= KBD_STAT_KPKR | KBD_STAT_KPKD |
KBD_STAT_KDSC | KBD_STAT_KRSS;
writew(reg_val, keypad->mmio_base + KPSR);
reg_val |= KBD_STAT_KDIE;
reg_val &= ~KBD_STAT_KRIE;
writew(reg_val, keypad->mmio_base + KPSR);
}
static void imx_keypad_inhibit(struct imx_keypad *keypad)
{
unsigned short reg_val;
reg_val = readw(keypad->mmio_base + KPSR);
reg_val &= ~(KBD_STAT_KRIE | KBD_STAT_KDIE);
writew(reg_val, keypad->mmio_base + KPSR);
writew(0xff00, keypad->mmio_base + KPCR);
}
static void imx_keypad_close(struct input_dev *dev)
{
struct imx_keypad *keypad = input_get_drvdata(dev);
dev_dbg(&dev->dev, ">%s\n", __func__);
keypad->enabled = false;
synchronize_irq(keypad->irq);
del_timer_sync(&keypad->check_matrix_timer);
imx_keypad_inhibit(keypad);
clk_disable(keypad->clk);
}
static int imx_keypad_open(struct input_dev *dev)
{
struct imx_keypad *keypad = input_get_drvdata(dev);
dev_dbg(&dev->dev, ">%s\n", __func__);
keypad->enabled = true;
clk_enable(keypad->clk);
imx_keypad_config(keypad);
if ((readw(keypad->mmio_base + KPDR) & keypad->rows_en_mask) == 0) {
dev_err(&dev->dev,
"too many keys pressed, control pins initialisation\n");
goto open_err;
}
return 0;
open_err:
imx_keypad_close(dev);
return -EIO;
}
static int __devinit imx_keypad_probe(struct platform_device *pdev)
{
const struct matrix_keymap_data *keymap_data = pdev->dev.platform_data;
struct imx_keypad *keypad;
struct input_dev *input_dev;
struct resource *res;
int irq, error, i;
if (keymap_data == NULL) {
dev_err(&pdev->dev, "no keymap defined\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq defined in platform data\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no I/O memory defined in platform data\n");
return -EINVAL;
}
res = request_mem_region(res->start, resource_size(res), pdev->name);
if (res == NULL) {
dev_err(&pdev->dev, "failed to request I/O memory\n");
return -EBUSY;
}
input_dev = input_allocate_device();
if (!input_dev) {
dev_err(&pdev->dev, "failed to allocate the input device\n");
error = -ENOMEM;
goto failed_rel_mem;
}
keypad = kzalloc(sizeof(struct imx_keypad), GFP_KERNEL);
if (!keypad) {
dev_err(&pdev->dev, "not enough memory for driver data\n");
error = -ENOMEM;
goto failed_free_input;
}
keypad->input_dev = input_dev;
keypad->irq = irq;
keypad->stable_count = 0;
setup_timer(&keypad->check_matrix_timer,
imx_keypad_check_for_events, (unsigned long) keypad);
keypad->mmio_base = ioremap(res->start, resource_size(res));
if (keypad->mmio_base == NULL) {
dev_err(&pdev->dev, "failed to remap I/O memory\n");
error = -ENOMEM;
goto failed_free_priv;
}
keypad->clk = clk_get(&pdev->dev, "kpp");
if (IS_ERR(keypad->clk)) {
dev_err(&pdev->dev, "failed to get keypad clock\n");
error = PTR_ERR(keypad->clk);
goto failed_unmap;
}
for (i = 0; i < keymap_data->keymap_size; i++) {
keypad->rows_en_mask |= 1 << KEY_ROW(keymap_data->keymap[i]);
keypad->cols_en_mask |= 1 << KEY_COL(keymap_data->keymap[i]);
}
if (keypad->rows_en_mask > ((1 << MAX_MATRIX_KEY_ROWS) - 1) ||
keypad->cols_en_mask > ((1 << MAX_MATRIX_KEY_COLS) - 1)) {
dev_err(&pdev->dev,
"invalid key data (too many rows or colums)\n");
error = -EINVAL;
goto failed_clock_put;
}
dev_dbg(&pdev->dev, "enabled rows mask: %x\n", keypad->rows_en_mask);
dev_dbg(&pdev->dev, "enabled cols mask: %x\n", keypad->cols_en_mask);
input_dev->name = pdev->name;
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &pdev->dev;
input_dev->open = imx_keypad_open;
input_dev->close = imx_keypad_close;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->keycode = keypad->keycodes;
input_dev->keycodesize = sizeof(keypad->keycodes[0]);
input_dev->keycodemax = ARRAY_SIZE(keypad->keycodes);
matrix_keypad_build_keymap(keymap_data, MATRIX_ROW_SHIFT,
keypad->keycodes, input_dev->keybit);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_set_drvdata(input_dev, keypad);
imx_keypad_inhibit(keypad);
error = request_irq(irq, imx_keypad_irq_handler, 0,
pdev->name, keypad);
if (error) {
dev_err(&pdev->dev, "failed to request IRQ\n");
goto failed_clock_put;
}
error = input_register_device(input_dev);
if (error) {
dev_err(&pdev->dev, "failed to register input device\n");
goto failed_free_irq;
}
platform_set_drvdata(pdev, keypad);
device_init_wakeup(&pdev->dev, 1);
return 0;
failed_free_irq:
free_irq(irq, pdev);
failed_clock_put:
clk_put(keypad->clk);
failed_unmap:
iounmap(keypad->mmio_base);
failed_free_priv:
kfree(keypad);
failed_free_input:
input_free_device(input_dev);
failed_rel_mem:
release_mem_region(res->start, resource_size(res));
return error;
}
static int __devexit imx_keypad_remove(struct platform_device *pdev)
{
struct imx_keypad *keypad = platform_get_drvdata(pdev);
struct resource *res;
dev_dbg(&pdev->dev, ">%s\n", __func__);
platform_set_drvdata(pdev, NULL);
input_unregister_device(keypad->input_dev);
free_irq(keypad->irq, keypad);
clk_put(keypad->clk);
iounmap(keypad->mmio_base);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
kfree(keypad);
return 0;
}
static int imx_kbd_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct imx_keypad *kbd = platform_get_drvdata(pdev);
struct input_dev *input_dev = kbd->input_dev;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
clk_disable(kbd->clk);
mutex_unlock(&input_dev->mutex);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(kbd->irq);
return 0;
}
static int imx_kbd_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct imx_keypad *kbd = platform_get_drvdata(pdev);
struct input_dev *input_dev = kbd->input_dev;
if (device_may_wakeup(&pdev->dev))
disable_irq_wake(kbd->irq);
mutex_lock(&input_dev->mutex);
if (input_dev->users)
clk_enable(kbd->clk);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int __init imx_keypad_init(void)
{
return platform_driver_register(&imx_keypad_driver);
}
static void __exit imx_keypad_exit(void)
{
platform_driver_unregister(&imx_keypad_driver);
}
