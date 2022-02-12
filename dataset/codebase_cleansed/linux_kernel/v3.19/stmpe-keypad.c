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
u8 pureg = stmpe->regs[STMPE_IDX_GPPUR_LSB];
unsigned int pins = 0;
unsigned int pu_pins = 0;
int ret;
int i;
for (i = 0; i < variant->max_cols; i++) {
int num = __ffs(col_gpios);
if (keypad->cols & (1 << i)) {
pins |= 1 << num;
pu_pins |= 1 << num;
}
col_gpios &= ~(1 << num);
}
for (i = 0; i < variant->max_rows; i++) {
int num = __ffs(row_gpios);
if (keypad->rows & (1 << i))
pins |= 1 << num;
row_gpios &= ~(1 << num);
}
ret = stmpe_set_altfunc(stmpe, pins, STMPE_BLOCK_KEYPAD);
if (ret)
return ret;
if (variant->set_pullup) {
u8 val;
ret = stmpe_reg_read(stmpe, pureg);
if (ret)
return ret;
val = ret & ~pu_pins;
val |= pu_pins;
ret = stmpe_reg_write(stmpe, pureg, val);
}
return 0;
}
static int stmpe_keypad_chip_init(struct stmpe_keypad *keypad)
{
const struct stmpe_keypad_variant *variant = keypad->variant;
struct stmpe *stmpe = keypad->stmpe;
int ret;
if (keypad->debounce_ms > STMPE_KEYPAD_MAX_DEBOUNCE)
return -EINVAL;
if (keypad->scan_count > STMPE_KEYPAD_MAX_SCAN_COUNT)
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
keypad->scan_count << 4);
if (ret < 0)
return ret;
return stmpe_set_bits(stmpe, STMPE_KPC_CTRL_LSB,
STMPE_KPC_CTRL_LSB_SCAN |
STMPE_KPC_CTRL_LSB_DEBOUNCE,
STMPE_KPC_CTRL_LSB_SCAN |
(keypad->debounce_ms << 1));
}
static void stmpe_keypad_fill_used_pins(struct stmpe_keypad *keypad,
u32 used_rows, u32 used_cols)
{
int row, col;
for (row = 0; row < used_rows; row++) {
for (col = 0; col < used_cols; col++) {
int code = MATRIX_SCAN_CODE(row, col,
STMPE_KEYPAD_ROW_SHIFT);
if (keypad->keymap[code] != KEY_RESERVED) {
keypad->rows |= 1 << row;
keypad->cols |= 1 << col;
}
}
}
}
static int stmpe_keypad_probe(struct platform_device *pdev)
{
struct stmpe *stmpe = dev_get_drvdata(pdev->dev.parent);
struct device_node *np = pdev->dev.of_node;
struct stmpe_keypad *keypad;
struct input_dev *input;
u32 rows;
u32 cols;
int error;
int irq;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
keypad = devm_kzalloc(&pdev->dev, sizeof(struct stmpe_keypad),
GFP_KERNEL);
if (!keypad)
return -ENOMEM;
keypad->stmpe = stmpe;
keypad->variant = &stmpe_keypad_variants[stmpe->partnum];
of_property_read_u32(np, "debounce-interval", &keypad->debounce_ms);
of_property_read_u32(np, "st,scan-count", &keypad->scan_count);
keypad->no_autorepeat = of_property_read_bool(np, "st,no-autorepeat");
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
input->name = "STMPE keypad";
input->id.bustype = BUS_I2C;
input->dev.parent = &pdev->dev;
error = matrix_keypad_parse_of_params(&pdev->dev, &rows, &cols);
if (error)
return error;
error = matrix_keypad_build_keymap(NULL, NULL, rows, cols,
keypad->keymap, input);
if (error)
return error;
input_set_capability(input, EV_MSC, MSC_SCAN);
if (!keypad->no_autorepeat)
__set_bit(EV_REP, input->evbit);
stmpe_keypad_fill_used_pins(keypad, rows, cols);
keypad->input = input;
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
