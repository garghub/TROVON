static int max7359_write_reg(struct i2c_client *client, u8 reg, u8 val)
{
int ret = i2c_smbus_write_byte_data(client, reg, val);
if (ret < 0)
dev_err(&client->dev, "%s: reg 0x%x, val 0x%x, err %d\n",
__func__, reg, val, ret);
return ret;
}
static int max7359_read_reg(struct i2c_client *client, int reg)
{
int ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0)
dev_err(&client->dev, "%s: reg 0x%x, err %d\n",
__func__, reg, ret);
return ret;
}
static void max7359_build_keycode(struct max7359_keypad *keypad,
const struct matrix_keymap_data *keymap_data)
{
struct input_dev *input_dev = keypad->input_dev;
int i;
for (i = 0; i < keymap_data->keymap_size; i++) {
unsigned int key = keymap_data->keymap[i];
unsigned int row = KEY_ROW(key);
unsigned int col = KEY_COL(key);
unsigned int scancode = MATRIX_SCAN_CODE(row, col,
MAX7359_ROW_SHIFT);
unsigned short keycode = KEY_VAL(key);
keypad->keycodes[scancode] = keycode;
__set_bit(keycode, input_dev->keybit);
}
__clear_bit(KEY_RESERVED, input_dev->keybit);
}
static irqreturn_t max7359_interrupt(int irq, void *dev_id)
{
struct max7359_keypad *keypad = dev_id;
struct input_dev *input_dev = keypad->input_dev;
int val, row, col, release, code;
val = max7359_read_reg(keypad->client, MAX7359_REG_KEYFIFO);
row = val & 0x7;
col = (val >> 3) & 0x7;
release = val & 0x40;
code = MATRIX_SCAN_CODE(row, col, MAX7359_ROW_SHIFT);
dev_dbg(&keypad->client->dev,
"key[%d:%d] %s\n", row, col, release ? "release" : "press");
input_event(input_dev, EV_MSC, MSC_SCAN, code);
input_report_key(input_dev, keypad->keycodes[code], !release);
input_sync(input_dev);
return IRQ_HANDLED;
}
static inline void max7359_fall_deepsleep(struct i2c_client *client)
{
max7359_write_reg(client, MAX7359_REG_SLEEP, MAX7359_AUTOSLEEP_8192);
}
static inline void max7359_take_catnap(struct i2c_client *client)
{
max7359_write_reg(client, MAX7359_REG_SLEEP, MAX7359_AUTOSLEEP_256);
}
static int max7359_open(struct input_dev *dev)
{
struct max7359_keypad *keypad = input_get_drvdata(dev);
max7359_take_catnap(keypad->client);
return 0;
}
static void max7359_close(struct input_dev *dev)
{
struct max7359_keypad *keypad = input_get_drvdata(dev);
max7359_fall_deepsleep(keypad->client);
}
static void max7359_initialize(struct i2c_client *client)
{
max7359_write_reg(client, MAX7359_REG_CONFIG,
MAX7359_CFG_INTERRUPT |
MAX7359_CFG_KEY_RELEASE |
MAX7359_CFG_WAKEUP);
max7359_write_reg(client, MAX7359_REG_DEBOUNCE, 0x1F);
max7359_write_reg(client, MAX7359_REG_INTERRUPT, 0x01);
max7359_fall_deepsleep(client);
}
static int __devinit max7359_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct matrix_keymap_data *keymap_data = client->dev.platform_data;
struct max7359_keypad *keypad;
struct input_dev *input_dev;
int ret;
int error;
if (!client->irq) {
dev_err(&client->dev, "The irq number should not be zero\n");
return -EINVAL;
}
ret = max7359_read_reg(client, MAX7359_REG_KEYFIFO);
if (ret < 0) {
dev_err(&client->dev, "failed to detect device\n");
return -ENODEV;
}
dev_dbg(&client->dev, "keys FIFO is 0x%02x\n", ret);
keypad = kzalloc(sizeof(struct max7359_keypad), GFP_KERNEL);
input_dev = input_allocate_device();
if (!keypad || !input_dev) {
dev_err(&client->dev, "failed to allocate memory\n");
error = -ENOMEM;
goto failed_free_mem;
}
keypad->client = client;
keypad->input_dev = input_dev;
input_dev->name = client->name;
input_dev->id.bustype = BUS_I2C;
input_dev->open = max7359_open;
input_dev->close = max7359_close;
input_dev->dev.parent = &client->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_dev->keycodesize = sizeof(keypad->keycodes[0]);
input_dev->keycodemax = ARRAY_SIZE(keypad->keycodes);
input_dev->keycode = keypad->keycodes;
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_set_drvdata(input_dev, keypad);
max7359_build_keycode(keypad, keymap_data);
error = request_threaded_irq(client->irq, NULL, max7359_interrupt,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
client->name, keypad);
if (error) {
dev_err(&client->dev, "failed to register interrupt\n");
goto failed_free_mem;
}
error = input_register_device(input_dev);
if (error) {
dev_err(&client->dev, "failed to register input device\n");
goto failed_free_irq;
}
max7359_initialize(client);
i2c_set_clientdata(client, keypad);
device_init_wakeup(&client->dev, 1);
return 0;
failed_free_irq:
free_irq(client->irq, keypad);
failed_free_mem:
input_free_device(input_dev);
kfree(keypad);
return error;
}
static int __devexit max7359_remove(struct i2c_client *client)
{
struct max7359_keypad *keypad = i2c_get_clientdata(client);
free_irq(client->irq, keypad);
input_unregister_device(keypad->input_dev);
kfree(keypad);
return 0;
}
static int max7359_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
max7359_fall_deepsleep(client);
if (device_may_wakeup(&client->dev))
enable_irq_wake(client->irq);
return 0;
}
static int max7359_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
if (device_may_wakeup(&client->dev))
disable_irq_wake(client->irq);
max7359_take_catnap(client);
return 0;
}
static int __init max7359_init(void)
{
return i2c_add_driver(&max7359_i2c_driver);
}
static void __exit max7359_exit(void)
{
i2c_del_driver(&max7359_i2c_driver);
}
