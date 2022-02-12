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
input_event(keypad_data->input, EV_MSC, MSC_SCAN, code);
input_report_key(keypad_data->input,
keypad_data->keymap[code], state);
error = tca8418_read_byte(keypad_data, REG_KEY_EVENT_A, &reg);
}
if (error < 0)
dev_err(&keypad_data->client->dev,
"unable to read REG_KEY_EVENT_A\n");
input_sync(keypad_data->input);
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
goto exit;
}
if (reg & INT_STAT_OVR_FLOW_INT)
dev_warn(&keypad_data->client->dev, "overflow occurred\n");
if (reg & INT_STAT_K_INT)
tca8418_read_keypad(keypad_data);
exit:
reg = 0xff;
error = tca8418_write_byte(keypad_data, REG_INT_STAT, reg);
if (error)
dev_err(&keypad_data->client->dev,
"unable to clear REG_INT_STAT\n");
return IRQ_HANDLED;
}
static int __devinit tca8418_configure(struct tca8418_keypad *keypad_data)
{
int reg, error;
error = tca8418_write_byte(keypad_data, REG_CFG,
CFG_INT_CFG | CFG_OVR_FLOW_IEN | CFG_KE_IEN);
if (error < 0)
return -ENODEV;
reg = ~(~0 << keypad_data->rows);
reg += (~(~0 << keypad_data->cols)) << 8;
keypad_data->keypad_mask = reg;
error |= tca8418_write_byte(keypad_data, REG_KP_GPIO1, reg);
error |= tca8418_write_byte(keypad_data, REG_KP_GPIO2, reg >> 8);
error |= tca8418_write_byte(keypad_data, REG_KP_GPIO3, reg >> 16);
error |= tca8418_write_byte(keypad_data, REG_DEBOUNCE_DIS1, reg);
error |= tca8418_write_byte(keypad_data, REG_DEBOUNCE_DIS2, reg >> 8);
error |= tca8418_write_byte(keypad_data, REG_DEBOUNCE_DIS3, reg >> 16);
return error;
}
static int __devinit tca8418_keypad_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct tca8418_keypad_platform_data *pdata =
client->dev.platform_data;
struct tca8418_keypad *keypad_data;
struct input_dev *input;
int error, row_shift, max_keys;
if (!pdata) {
dev_dbg(&client->dev, "no platform data\n");
return -EINVAL;
}
if (!pdata->keymap_data) {
dev_err(&client->dev, "no keymap data defined\n");
return -EINVAL;
}
if (!pdata->rows || pdata->rows > TCA8418_MAX_ROWS) {
dev_err(&client->dev, "invalid rows\n");
return -EINVAL;
}
if (!pdata->cols || pdata->cols > TCA8418_MAX_COLS) {
dev_err(&client->dev, "invalid columns\n");
return -EINVAL;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE)) {
dev_err(&client->dev, "%s adapter not supported\n",
dev_driver_string(&client->adapter->dev));
return -ENODEV;
}
row_shift = get_count_order(pdata->cols);
max_keys = pdata->rows << row_shift;
keypad_data = kzalloc(sizeof(*keypad_data) +
max_keys * sizeof(keypad_data->keymap[0]), GFP_KERNEL);
if (!keypad_data)
return -ENOMEM;
keypad_data->rows = pdata->rows;
keypad_data->cols = pdata->cols;
keypad_data->client = client;
keypad_data->row_shift = row_shift;
error = tca8418_configure(keypad_data);
if (error < 0)
goto fail1;
input = input_allocate_device();
if (!input) {
error = -ENOMEM;
goto fail1;
}
keypad_data->input = input;
input->name = client->name;
input->dev.parent = &client->dev;
input->id.bustype = BUS_I2C;
input->id.vendor = 0x0001;
input->id.product = 0x001;
input->id.version = 0x0001;
error = matrix_keypad_build_keymap(pdata->keymap_data, NULL,
pdata->rows, pdata->cols,
keypad_data->keymap, input);
if (error) {
dev_dbg(&client->dev, "Failed to build keymap\n");
goto fail2;
}
if (pdata->rep)
__set_bit(EV_REP, input->evbit);
input_set_capability(input, EV_MSC, MSC_SCAN);
input_set_drvdata(input, keypad_data);
if (pdata->irq_is_gpio)
client->irq = gpio_to_irq(client->irq);
error = request_threaded_irq(client->irq, NULL, tca8418_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
client->name, keypad_data);
if (error) {
dev_dbg(&client->dev,
"Unable to claim irq %d; error %d\n",
client->irq, error);
goto fail2;
}
error = input_register_device(input);
if (error) {
dev_dbg(&client->dev,
"Unable to register input device, error: %d\n", error);
goto fail3;
}
i2c_set_clientdata(client, keypad_data);
return 0;
fail3:
free_irq(client->irq, keypad_data);
fail2:
input_free_device(input);
fail1:
kfree(keypad_data);
return error;
}
static int __devexit tca8418_keypad_remove(struct i2c_client *client)
{
struct tca8418_keypad *keypad_data = i2c_get_clientdata(client);
free_irq(keypad_data->client->irq, keypad_data);
input_unregister_device(keypad_data->input);
kfree(keypad_data);
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
