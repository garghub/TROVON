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
static int stmpe_keypad_altfunc_init(struct stmpe_keypad *keypad)
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
static int stmpe_keypad_chip_init(struct stmpe_keypad *keypad)
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
static void stmpe_keypad_fill_used_pins(struct stmpe_keypad *keypad)
{
int row, col;
for (row = 0; row < STMPE_KEYPAD_MAX_ROWS; row++) {
for (col = 0; col < STMPE_KEYPAD_MAX_COLS; col++) {
int code = MATRIX_SCAN_CODE(row, col,
STMPE_KEYPAD_ROW_SHIFT);
if (keypad->keymap[code] != KEY_RESERVED) {
keypad->rows |= 1 << row;
keypad->cols |= 1 << col;
}
}
}
}
static const struct stmpe_keypad_platform_data *
stmpe_keypad_of_probe(struct device *dev)
{
struct device_node *np = dev->of_node;
struct stmpe_keypad_platform_data *plat;
if (!np)
return ERR_PTR(-ENODEV);
plat = devm_kzalloc(dev, sizeof(*plat), GFP_KERNEL);
if (!plat)
return ERR_PTR(-ENOMEM);
of_property_read_u32(np, "debounce-interval", &plat->debounce_ms);
of_property_read_u32(np, "st,scan-count", &plat->scan_count);
plat->no_autorepeat = of_property_read_bool(np, "st,no-autorepeat");
return plat;
}
static inline const struct stmpe_keypad_platform_data *
stmpe_keypad_of_probe(struct device *dev)
{
return ERR_PTR(-EINVAL);
}
static int stmpe_keypad_probe(struct platform_device *pdev)
{
struct stmpe *stmpe = dev_get_drvdata(pdev->dev.parent);
const struct stmpe_keypad_platform_data *plat;
struct stmpe_keypad *keypad;
struct input_dev *input;
int error;
int irq;
plat = stmpe->pdata->keypad;
if (!plat) {
plat = stmpe_keypad_of_probe(&pdev->dev);
if (IS_ERR(plat))
return PTR_ERR(plat);
}
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
keypad = devm_kzalloc(&pdev->dev, sizeof(struct stmpe_keypad),
GFP_KERNEL);
if (!keypad)
return -ENOMEM;
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
input->name = "STMPE keypad";
input->id.bustype = BUS_I2C;
input->dev.parent = &pdev->dev;
error = matrix_keypad_build_keymap(plat->keymap_data, NULL,
STMPE_KEYPAD_MAX_ROWS,
STMPE_KEYPAD_MAX_COLS,
keypad->keymap, input);
if (error)
return error;
input_set_capability(input, EV_MSC, MSC_SCAN);
if (!plat->no_autorepeat)
__set_bit(EV_REP, input->evbit);
stmpe_keypad_fill_used_pins(keypad);
keypad->stmpe = stmpe;
keypad->plat = plat;
keypad->input = input;
keypad->variant = &stmpe_keypad_variants[stmpe->partnum];
error = stmpe_keypad_chip_init(keypad);
if (error < 0)
return error;
error = devm_request_threaded_irq(&pdev->dev, irq,
NULL, stmpe_keypad_irq,
IRQF_ONESHOT, "stmpe-keypad", keypad);
if (error) {
dev_err(&pdev->dev, "unable to get irq: %d\n", error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(&pdev->dev,
"unable to register input device: %d\n", error);
return error;
}
platform_set_drvdata(pdev, keypad);
return 0;
}
static int stmpe_keypad_remove(struct platform_device *pdev)
{
struct stmpe_keypad *keypad = platform_get_drvdata(pdev);
stmpe_disable(keypad->stmpe, STMPE_BLOCK_KEYPAD);
return 0;
}
