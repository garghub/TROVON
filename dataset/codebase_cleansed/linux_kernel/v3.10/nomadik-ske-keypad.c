static void ske_keypad_set_bits(struct ske_keypad *keypad, u16 addr,
u8 mask, u8 data)
{
u32 ret;
spin_lock(&keypad->ske_keypad_lock);
ret = readl(keypad->reg_base + addr);
ret &= ~mask;
ret |= data;
writel(ret, keypad->reg_base + addr);
spin_unlock(&keypad->ske_keypad_lock);
}
static int __init ske_keypad_chip_init(struct ske_keypad *keypad)
{
u32 value;
int timeout = keypad->board->debounce_ms;
while ((readl(keypad->reg_base + SKE_RIS) != 0x00000000) && timeout--)
cpu_relax();
if (!timeout)
return -EINVAL;
spin_lock(&keypad->ske_keypad_lock);
value = readl(keypad->reg_base + SKE_DBCR);
value = value & 0xff;
value |= ((keypad->board->debounce_ms * 32000)/32768) << 8;
writel(value, keypad->reg_base + SKE_DBCR);
spin_unlock(&keypad->ske_keypad_lock);
ske_keypad_set_bits(keypad, SKE_CR, 0x0, SKE_KPMLT);
value = (keypad->board->kcol - 1) << 3;
ske_keypad_set_bits(keypad, SKE_CR, SKE_KPCN, value);
ske_keypad_set_bits(keypad, SKE_ICR, 0x0, SKE_KPICA | SKE_KPICS);
ske_keypad_set_bits(keypad, SKE_IMSC, 0x0, SKE_KPIMA);
ske_keypad_set_bits(keypad, SKE_CR, 0x0, SKE_KPASEN);
return 0;
}
static void ske_keypad_report(struct ske_keypad *keypad, u8 status, int col)
{
int row = 0, code, pos;
struct input_dev *input = keypad->input;
u32 ske_ris;
int key_pressed;
int num_of_rows;
num_of_rows = hweight8(status);
do {
pos = __ffs(status);
row = pos;
status &= ~(1 << pos);
code = MATRIX_SCAN_CODE(row, col, SKE_KEYPAD_ROW_SHIFT);
ske_ris = readl(keypad->reg_base + SKE_RIS);
key_pressed = ske_ris & SKE_KPRISA;
input_event(input, EV_MSC, MSC_SCAN, code);
input_report_key(input, keypad->keymap[code], key_pressed);
input_sync(input);
num_of_rows--;
} while (num_of_rows);
}
static void ske_keypad_read_data(struct ske_keypad *keypad)
{
u8 status;
int col = 0;
int ske_asr, i;
for (i = 0; i < SKE_NUM_ASRX_REGISTERS; i++) {
ske_asr = readl(keypad->reg_base + SKE_ASR0 + (4 * i));
if (!ske_asr)
continue;
status = ske_asr & 0xff;
if (status) {
col = i * 2;
ske_keypad_report(keypad, status, col);
}
status = (ske_asr & 0xff00) >> 8;
if (status) {
col = (i * 2) + 1;
ske_keypad_report(keypad, status, col);
}
}
}
static irqreturn_t ske_keypad_irq(int irq, void *dev_id)
{
struct ske_keypad *keypad = dev_id;
int timeout = keypad->board->debounce_ms;
ske_keypad_set_bits(keypad, SKE_IMSC, ~SKE_KPIMA, 0x0);
ske_keypad_set_bits(keypad, SKE_ICR, 0x0, SKE_KPICA);
while ((readl(keypad->reg_base + SKE_CR) & SKE_KPASON) && --timeout)
cpu_relax();
ske_keypad_read_data(keypad);
while ((readl(keypad->reg_base + SKE_RIS)) && --timeout)
msleep(KEY_PRESSED_DELAY);
ske_keypad_set_bits(keypad, SKE_IMSC, 0x0, SKE_KPIMA);
return IRQ_HANDLED;
}
static int __init ske_keypad_probe(struct platform_device *pdev)
{
const struct ske_keypad_platform_data *plat = pdev->dev.platform_data;
struct ske_keypad *keypad;
struct input_dev *input;
struct resource *res;
int irq;
int error;
if (!plat) {
dev_err(&pdev->dev, "invalid keypad platform data\n");
return -EINVAL;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get keypad irq\n");
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "missing platform resources\n");
return -EINVAL;
}
keypad = kzalloc(sizeof(struct ske_keypad), GFP_KERNEL);
input = input_allocate_device();
if (!keypad || !input) {
dev_err(&pdev->dev, "failed to allocate keypad memory\n");
error = -ENOMEM;
goto err_free_mem;
}
keypad->irq = irq;
keypad->board = plat;
keypad->input = input;
spin_lock_init(&keypad->ske_keypad_lock);
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "failed to request I/O memory\n");
error = -EBUSY;
goto err_free_mem;
}
keypad->reg_base = ioremap(res->start, resource_size(res));
if (!keypad->reg_base) {
dev_err(&pdev->dev, "failed to remap I/O memory\n");
error = -ENXIO;
goto err_free_mem_region;
}
keypad->pclk = clk_get(&pdev->dev, "apb_pclk");
if (IS_ERR(keypad->pclk)) {
dev_err(&pdev->dev, "failed to get pclk\n");
error = PTR_ERR(keypad->pclk);
goto err_iounmap;
}
keypad->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(keypad->clk)) {
dev_err(&pdev->dev, "failed to get clk\n");
error = PTR_ERR(keypad->clk);
goto err_pclk;
}
input->id.bustype = BUS_HOST;
input->name = "ux500-ske-keypad";
input->dev.parent = &pdev->dev;
error = matrix_keypad_build_keymap(plat->keymap_data, NULL,
SKE_KPD_NUM_ROWS, SKE_KPD_NUM_COLS,
keypad->keymap, input);
if (error) {
dev_err(&pdev->dev, "Failed to build keymap\n");
goto err_clk;
}
input_set_capability(input, EV_MSC, MSC_SCAN);
if (!plat->no_autorepeat)
__set_bit(EV_REP, input->evbit);
error = clk_prepare_enable(keypad->pclk);
if (error) {
dev_err(&pdev->dev, "Failed to prepare/enable pclk\n");
goto err_clk;
}
error = clk_prepare_enable(keypad->clk);
if (error) {
dev_err(&pdev->dev, "Failed to prepare/enable clk\n");
goto err_pclk_disable;
}
if (keypad->board->init)
keypad->board->init();
error = ske_keypad_chip_init(keypad);
if (error) {
dev_err(&pdev->dev, "unable to init keypad hardware\n");
goto err_clk_disable;
}
error = request_threaded_irq(keypad->irq, NULL, ske_keypad_irq,
IRQF_ONESHOT, "ske-keypad", keypad);
if (error) {
dev_err(&pdev->dev, "allocate irq %d failed\n", keypad->irq);
goto err_clk_disable;
}
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev,
"unable to register input device: %d\n", error);
goto err_free_irq;
}
if (plat->wakeup_enable)
device_init_wakeup(&pdev->dev, true);
platform_set_drvdata(pdev, keypad);
return 0;
err_free_irq:
free_irq(keypad->irq, keypad);
err_clk_disable:
clk_disable_unprepare(keypad->clk);
err_pclk_disable:
clk_disable_unprepare(keypad->pclk);
err_clk:
clk_put(keypad->clk);
err_pclk:
clk_put(keypad->pclk);
err_iounmap:
iounmap(keypad->reg_base);
err_free_mem_region:
release_mem_region(res->start, resource_size(res));
err_free_mem:
input_free_device(input);
kfree(keypad);
return error;
}
static int ske_keypad_remove(struct platform_device *pdev)
{
struct ske_keypad *keypad = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
free_irq(keypad->irq, keypad);
input_unregister_device(keypad->input);
clk_disable_unprepare(keypad->clk);
clk_put(keypad->clk);
if (keypad->board->exit)
keypad->board->exit();
iounmap(keypad->reg_base);
release_mem_region(res->start, resource_size(res));
kfree(keypad);
return 0;
}
static int ske_keypad_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ske_keypad *keypad = platform_get_drvdata(pdev);
int irq = platform_get_irq(pdev, 0);
if (device_may_wakeup(dev))
enable_irq_wake(irq);
else
ske_keypad_set_bits(keypad, SKE_IMSC, ~SKE_KPIMA, 0x0);
return 0;
}
static int ske_keypad_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct ske_keypad *keypad = platform_get_drvdata(pdev);
int irq = platform_get_irq(pdev, 0);
if (device_may_wakeup(dev))
disable_irq_wake(irq);
else
ske_keypad_set_bits(keypad, SKE_IMSC, 0x0, SKE_KPIMA);
return 0;
}
