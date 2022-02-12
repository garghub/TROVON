static int tca8418_write_byte(struct tca8418_keypad *keypad_data,
int reg, u8 val)
{
int error;
error = i2c_smbus_write_byte_data(keypad_data->client, reg, val);
if (error < 0) {
dev_err(&keypad_data->client->dev,
"%s failed, reg: %d, val: %d, error: %d\n",
__func__, reg, val, error);
return error;
}
return 0;
}
static int tca8418_read_byte(struct tca8418_keypad *keypad_data,
int reg, u8 *val)
{
int error;
error = i2c_smbus_read_byte_data(keypad_data->client, reg);
if (error < 0) {
dev_err(&keypad_data->client->dev,
"%s failed, reg: %d, error: %d\n",
__func__, reg, error);
return error;
}
*val = (u8)error;
return 0;
}
static void tca8418_read_keypad(struct tca8418_keypad *keypad_data)
{
struct input_dev *input = keypad_data->input;
unsigned short *keymap = input->keycode;
int error, col, row;
u8 reg, state, code;
error = tca8418_read_byte(keypad_data, REG_KEY_EVENT_A, &reg);
while (error >= 0 && reg > 0) {
state = reg & KEY_EVENT_VALUE;
code = reg & KEY_EVENT_CODE;
row = code / TCA8418_MAX_COLS;
col = code % TCA8418_MAX_COLS;
row = (col) ? row : row - 1;
col = (col) ? col - 1 : TCA8418_MAX_COLS - 1;
code = MATRIX_SCAN_CODE(row, col, keypad_data->row_shift);
input_event(input, EV_MSC, MSC_SCAN, code);
input_report_key(input, keymap[code], state);
error = tca8418_read_byte(keypad_data, REG_KEY_EVENT_A, &reg);
}
if (error < 0)
dev_err(&keypad_data->client->dev,
"unable to read REG_KEY_EVENT_A\n");
input_sync(input);
}
static irqreturn_t tca8418_irq_handler(int irq, void *dev_id)
{
struct tca8418_keypad *keypad_data = dev_id;
u8 reg;
int error;
error = tca8418_read_byte(keypad_data, REG_INT_STAT, &reg);
if (error) {
dev_err(&keypad_data->client->dev,
"unable to read REG_INT_STAT\n");
return IRQ_NONE;
}
if (!reg)
return IRQ_NONE;
if (reg & INT_STAT_OVR_FLOW_INT)
dev_warn(&keypad_data->client->dev, "overflow occurred\n");
if (reg & INT_STAT_K_INT)
tca8418_read_keypad(keypad_data);
reg = 0xff;
error = tca8418_write_byte(keypad_data, REG_INT_STAT, reg);
if (error)
dev_err(&keypad_data->client->dev,
"unable to clear REG_INT_STAT\n");
return IRQ_HANDLED;
}
static int tca8418_configure(struct tca8418_keypad *keypad_data,
u32 rows, u32 cols)
{
int reg, error;
error = tca8418_write_byte(keypad_data, REG_CFG,
CFG_INT_CFG | CFG_OVR_FLOW_IEN | CFG_KE_IEN);
if (error < 0)
return -ENODEV;
reg = ~(~0 << rows);
reg += (~(~0 << cols)) << 8;
error |= tca8418_write_byte(keypad_data, REG_KP_GPIO1, reg);
error |= tca8418_write_byte(keypad_data, REG_KP_GPIO2, reg >> 8);
error |= tca8418_write_byte(keypad_data, REG_KP_GPIO3, reg >> 16);
error |= tca8418_write_byte(keypad_data, REG_DEBOUNCE_DIS1, reg);
error |= tca8418_write_byte(keypad_data, REG_DEBOUNCE_DIS2, reg >> 8);
error |= tca8418_write_byte(keypad_data, REG_DEBOUNCE_DIS3, reg >> 16);
return error;
}
static int tca8418_keypad_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
const struct tca8418_keypad_platform_data *pdata =
dev_get_platdata(dev);
struct tca8418_keypad *keypad_data;
struct input_dev *input;
const struct matrix_keymap_data *keymap_data = NULL;
u32 rows = 0, cols = 0;
bool rep = false;
bool irq_is_gpio = false;
int irq;
int error, row_shift, max_keys;
if (pdata) {
if (!pdata->keymap_data) {
dev_err(dev, "no keymap data defined\n");
return -EINVAL;
}
keymap_data = pdata->keymap_data;
rows = pdata->rows;
cols = pdata->cols;
rep = pdata->rep;
irq_is_gpio = pdata->irq_is_gpio;
} else {
struct device_node *np = dev->of_node;
int err;
err = matrix_keypad_parse_of_params(dev, &rows, &cols);
if (err)
return err;
rep = of_property_read_bool(np, "keypad,autorepeat");
}
if (!rows || rows > TCA8418_MAX_ROWS) {
dev_err(dev, "invalid rows\n");
return -EINVAL;
}
if (!cols || cols > TCA8418_MAX_COLS) {
dev_err(dev, "invalid columns\n");
return -EINVAL;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE)) {
dev_err(dev, "%s adapter not supported\n",
dev_driver_string(&client->adapter->dev));
return -ENODEV;
}
row_shift = get_count_order(cols);
max_keys = rows << row_shift;
keypad_data = devm_kzalloc(dev, sizeof(*keypad_data), GFP_KERNEL);
if (!keypad_data)
return -ENOMEM;
keypad_data->client = client;
keypad_data->row_shift = row_shift;
error = tca8418_configure(keypad_data, rows, cols);
if (error < 0)
return error;
input = devm_input_allocate_device(dev);
if (!input)
return -ENOMEM;
keypad_data->input = input;
input->name = client->name;
input->id.bustype = BUS_I2C;
input->id.vendor = 0x0001;
input->id.product = 0x001;
input->id.version = 0x0001;
error = matrix_keypad_build_keymap(keymap_data, NULL, rows, cols,
NULL, input);
if (error) {
dev_err(dev, "Failed to build keymap\n");
return error;
}
if (rep)
__set_bit(EV_REP, input->evbit);
input_set_capability(input, EV_MSC, MSC_SCAN);
input_set_drvdata(input, keypad_data);
irq = client->irq;
if (irq_is_gpio)
irq = gpio_to_irq(irq);
error = devm_request_threaded_irq(dev, irq, NULL, tca8418_irq_handler,
IRQF_TRIGGER_FALLING |
IRQF_SHARED |
IRQF_ONESHOT,
client->name, keypad_data);
if (error) {
dev_err(dev, "Unable to claim irq %d; error %d\n",
client->irq, error);
return error;
}
error = input_register_device(input);
if (error) {
dev_err(dev, "Unable to register input device, error: %d\n",
error);
return error;
}
return 0;
}
static int __init tca8418_keypad_init(void)
{
return i2c_add_driver(&tca8418_keypad_driver);
}
static void __exit tca8418_keypad_exit(void)
{
i2c_del_driver(&tca8418_keypad_driver);
}
