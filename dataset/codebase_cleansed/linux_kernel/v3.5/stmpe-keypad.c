static int stmpe_keypad_read_data(struct stmpe_keypad *keypad, u8 *data)
{
const struct stmpe_keypad_variant *variant = keypad->variant;
struct stmpe *stmpe = keypad->stmpe;
int ret;
int i;
if (variant->auto_increment)
return stmpe_block_read(stmpe, STMPE_KPC_DATA_BYTE0,
variant->num_data, data);
for (i = 0; i < variant->num_data; i++) {
ret = stmpe_reg_read(stmpe, STMPE_KPC_DATA_BYTE0 + i);
if (ret < 0)
return ret;
data[i] = ret;
}
return 0;
}
static irqreturn_t stmpe_keypad_irq(int irq, void *dev)
{
struct stmpe_keypad *keypad = dev;
struct input_dev *input = keypad->input;
const struct stmpe_keypad_variant *variant = keypad->variant;
u8 fifo[variant->num_data];
int ret;
int i;
ret = stmpe_keypad_read_data(keypad, fifo);
if (ret < 0)
return IRQ_NONE;
for (i = 0; i < variant->num_normal_data; i++) {
u8 data = fifo[i];
int row = (data & STMPE_KPC_DATA_ROW) >> 3;
int col = data & STMPE_KPC_DATA_COL;
int code = MATRIX_SCAN_CODE(row, col, STMPE_KEYPAD_ROW_SHIFT);
bool up = data & STMPE_KPC_DATA_UP;
if ((data & STMPE_KPC_DATA_NOKEY_MASK)
== STMPE_KPC_DATA_NOKEY_MASK)
continue;
input_event(input, EV_MSC, MSC_SCAN, code);
input_report_key(input, keypad->keymap[code], !up);
input_sync(input);
}
return IRQ_HANDLED;
}
static int __devinit stmpe_keypad_altfunc_init(struct stmpe_keypad *keypad)
{
const struct stmpe_keypad_variant *variant = keypad->variant;
unsigned int col_gpios = variant->col_gpios;
unsigned int row_gpios = variant->row_gpios;
struct stmpe *stmpe = keypad->stmpe;
unsigned int pins = 0;
int i;
for (i = 0; i < variant->max_cols; i++) {
int num = __ffs(col_gpios);
if (keypad->cols & (1 << i))
pins |= 1 << num;
col_gpios &= ~(1 << num);
}
for (i = 0; i < variant->max_rows; i++) {
int num = __ffs(row_gpios);
if (keypad->rows & (1 << i))
pins |= 1 << num;
row_gpios &= ~(1 << num);
}
return stmpe_set_altfunc(stmpe, pins, STMPE_BLOCK_KEYPAD);
}
static int __devinit stmpe_keypad_chip_init(struct stmpe_keypad *keypad)
{
const struct stmpe_keypad_platform_data *plat = keypad->plat;
const struct stmpe_keypad_variant *variant = keypad->variant;
struct stmpe *stmpe = keypad->stmpe;
int ret;
if (plat->debounce_ms > STMPE_KEYPAD_MAX_DEBOUNCE)
return -EINVAL;
if (plat->scan_count > STMPE_KEYPAD_MAX_SCAN_COUNT)
return -EINVAL;
ret = stmpe_enable(stmpe, STMPE_BLOCK_KEYPAD);
if (ret < 0)
return ret;
ret = stmpe_keypad_altfunc_init(keypad);
if (ret < 0)
return ret;
ret = stmpe_reg_write(stmpe, STMPE_KPC_COL, keypad->cols);
if (ret < 0)
return ret;
ret = stmpe_reg_write(stmpe, STMPE_KPC_ROW_LSB, keypad->rows);
if (ret < 0)
return ret;
if (variant->max_rows > 8) {
ret = stmpe_set_bits(stmpe, STMPE_KPC_ROW_MSB,
STMPE_KPC_ROW_MSB_ROWS,
keypad->rows >> 8);
if (ret < 0)
return ret;
}
ret = stmpe_set_bits(stmpe, STMPE_KPC_CTRL_MSB,
STMPE_KPC_CTRL_MSB_SCAN_COUNT,
plat->scan_count << 4);
if (ret < 0)
return ret;
return stmpe_set_bits(stmpe, STMPE_KPC_CTRL_LSB,
STMPE_KPC_CTRL_LSB_SCAN |
STMPE_KPC_CTRL_LSB_DEBOUNCE,
STMPE_KPC_CTRL_LSB_SCAN |
(plat->debounce_ms << 1));
}
static int __devinit stmpe_keypad_probe(struct platform_device *pdev)
{
struct stmpe *stmpe = dev_get_drvdata(pdev->dev.parent);
struct stmpe_keypad_platform_data *plat;
struct stmpe_keypad *keypad;
struct input_dev *input;
int ret;
int irq;
int i;
plat = stmpe->pdata->keypad;
if (!plat)
return -ENODEV;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
keypad = kzalloc(sizeof(struct stmpe_keypad), GFP_KERNEL);
if (!keypad)
return -ENOMEM;
input = input_allocate_device();
if (!input) {
ret = -ENOMEM;
goto out_freekeypad;
}
input->name = "STMPE keypad";
input->id.bustype = BUS_I2C;
input->dev.parent = &pdev->dev;
ret = matrix_keypad_build_keymap(plat->keymap_data, NULL,
STMPE_KEYPAD_MAX_ROWS,
STMPE_KEYPAD_MAX_COLS,
keypad->keymap, input);
if (ret)
goto out_freeinput;
input_set_capability(input, EV_MSC, MSC_SCAN);
if (!plat->no_autorepeat)
__set_bit(EV_REP, input->evbit);
for (i = 0; i < plat->keymap_data->keymap_size; i++) {
unsigned int key = plat->keymap_data->keymap[i];
keypad->cols |= 1 << KEY_COL(key);
keypad->rows |= 1 << KEY_ROW(key);
}
keypad->stmpe = stmpe;
keypad->plat = plat;
keypad->input = input;
keypad->variant = &stmpe_keypad_variants[stmpe->partnum];
ret = stmpe_keypad_chip_init(keypad);
if (ret < 0)
goto out_freeinput;
ret = input_register_device(input);
if (ret) {
dev_err(&pdev->dev,
"unable to register input device: %d\n", ret);
goto out_freeinput;
}
ret = request_threaded_irq(irq, NULL, stmpe_keypad_irq, IRQF_ONESHOT,
"stmpe-keypad", keypad);
if (ret) {
dev_err(&pdev->dev, "unable to get irq: %d\n", ret);
goto out_unregisterinput;
}
platform_set_drvdata(pdev, keypad);
return 0;
out_unregisterinput:
input_unregister_device(input);
input = NULL;
out_freeinput:
input_free_device(input);
out_freekeypad:
kfree(keypad);
return ret;
}
static int __devexit stmpe_keypad_remove(struct platform_device *pdev)
{
struct stmpe_keypad *keypad = platform_get_drvdata(pdev);
struct stmpe *stmpe = keypad->stmpe;
int irq = platform_get_irq(pdev, 0);
stmpe_disable(stmpe, STMPE_BLOCK_KEYPAD);
free_irq(irq, keypad);
input_unregister_device(keypad->input);
platform_set_drvdata(pdev, NULL);
kfree(keypad);
return 0;
}
