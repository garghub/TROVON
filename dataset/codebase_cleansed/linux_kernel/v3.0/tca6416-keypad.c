static int tca6416_write_reg(struct tca6416_keypad_chip *chip, int reg, u16 val)
{
int error;
error = chip->io_size > 8 ?
i2c_smbus_write_word_data(chip->client, reg << 1, val) :
i2c_smbus_write_byte_data(chip->client, reg, val);
if (error < 0) {
dev_err(&chip->client->dev,
"%s failed, reg: %d, val: %d, error: %d\n",
__func__, reg, val, error);
return error;
}
return 0;
}
static int tca6416_read_reg(struct tca6416_keypad_chip *chip, int reg, u16 *val)
{
int retval;
retval = chip->io_size > 8 ?
i2c_smbus_read_word_data(chip->client, reg << 1) :
i2c_smbus_read_byte_data(chip->client, reg);
if (retval < 0) {
dev_err(&chip->client->dev, "%s failed, reg: %d, error: %d\n",
__func__, reg, retval);
return retval;
}
*val = (u16)retval;
return 0;
}
static void tca6416_keys_scan(struct tca6416_keypad_chip *chip)
{
struct input_dev *input = chip->input;
u16 reg_val, val;
int error, i, pin_index;
error = tca6416_read_reg(chip, TCA6416_INPUT, &reg_val);
if (error)
return;
reg_val &= chip->pinmask;
val = reg_val ^ chip->reg_input;
chip->reg_input = reg_val;
for (i = 0, pin_index = 0; i < 16; i++) {
if (val & (1 << i)) {
struct tca6416_button *button = &chip->buttons[pin_index];
unsigned int type = button->type ?: EV_KEY;
int state = ((reg_val & (1 << i)) ? 1 : 0)
^ button->active_low;
input_event(input, type, button->code, !!state);
input_sync(input);
}
if (chip->pinmask & (1 << i))
pin_index++;
}
}
static irqreturn_t tca6416_keys_isr(int irq, void *dev_id)
{
struct tca6416_keypad_chip *chip = dev_id;
tca6416_keys_scan(chip);
return IRQ_HANDLED;
}
static void tca6416_keys_work_func(struct work_struct *work)
{
struct tca6416_keypad_chip *chip =
container_of(work, struct tca6416_keypad_chip, dwork.work);
tca6416_keys_scan(chip);
schedule_delayed_work(&chip->dwork, msecs_to_jiffies(100));
}
static int tca6416_keys_open(struct input_dev *dev)
{
struct tca6416_keypad_chip *chip = input_get_drvdata(dev);
tca6416_keys_scan(chip);
if (chip->use_polling)
schedule_delayed_work(&chip->dwork, msecs_to_jiffies(100));
else
enable_irq(chip->irqnum);
return 0;
}
static void tca6416_keys_close(struct input_dev *dev)
{
struct tca6416_keypad_chip *chip = input_get_drvdata(dev);
if (chip->use_polling)
cancel_delayed_work_sync(&chip->dwork);
else
disable_irq(chip->irqnum);
}
static int __devinit tca6416_setup_registers(struct tca6416_keypad_chip *chip)
{
int error;
error = tca6416_read_reg(chip, TCA6416_OUTPUT, &chip->reg_output);
if (error)
return error;
error = tca6416_read_reg(chip, TCA6416_DIRECTION, &chip->reg_direction);
if (error)
return error;
error = tca6416_write_reg(chip, TCA6416_DIRECTION,
chip->reg_direction | chip->pinmask);
if (error)
return error;
error = tca6416_read_reg(chip, TCA6416_DIRECTION, &chip->reg_direction);
if (error)
return error;
error = tca6416_read_reg(chip, TCA6416_INPUT, &chip->reg_input);
if (error)
return error;
chip->reg_input &= chip->pinmask;
return 0;
}
static int __devinit tca6416_keypad_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tca6416_keys_platform_data *pdata;
struct tca6416_keypad_chip *chip;
struct input_dev *input;
int error;
int i;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_SMBUS_BYTE)) {
dev_err(&client->dev, "%s adapter not supported\n",
dev_driver_string(&client->adapter->dev));
return -ENODEV;
}
pdata = client->dev.platform_data;
if (!pdata) {
dev_dbg(&client->dev, "no platform data\n");
return -EINVAL;
}
chip = kzalloc(sizeof(struct tca6416_keypad_chip) +
pdata->nbuttons * sizeof(struct tca6416_button),
GFP_KERNEL);
input = input_allocate_device();
if (!chip || !input) {
error = -ENOMEM;
goto fail1;
}
chip->client = client;
chip->input = input;
chip->io_size = id->driver_data;
chip->pinmask = pdata->pinmask;
chip->use_polling = pdata->use_polling;
INIT_DELAYED_WORK(&chip->dwork, tca6416_keys_work_func);
input->phys = "tca6416-keys/input0";
input->name = client->name;
input->dev.parent = &client->dev;
input->open = tca6416_keys_open;
input->close = tca6416_keys_close;
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0100;
if (pdata->rep)
__set_bit(EV_REP, input->evbit);
for (i = 0; i < pdata->nbuttons; i++) {
unsigned int type;
chip->buttons[i] = pdata->buttons[i];
type = (pdata->buttons[i].type) ?: EV_KEY;
input_set_capability(input, type, pdata->buttons[i].code);
}
input_set_drvdata(input, chip);
error = tca6416_setup_registers(chip);
if (error)
goto fail1;
if (!chip->use_polling) {
if (pdata->irq_is_gpio)
chip->irqnum = gpio_to_irq(client->irq);
else
chip->irqnum = client->irq;
error = request_threaded_irq(chip->irqnum, NULL,
tca6416_keys_isr,
IRQF_TRIGGER_FALLING,
"tca6416-keypad", chip);
if (error) {
dev_dbg(&client->dev,
"Unable to claim irq %d; error %d\n",
chip->irqnum, error);
goto fail1;
}
disable_irq(chip->irqnum);
}
error = input_register_device(input);
if (error) {
dev_dbg(&client->dev,
"Unable to register input device, error: %d\n", error);
goto fail2;
}
i2c_set_clientdata(client, chip);
device_init_wakeup(&client->dev, 1);
return 0;
fail2:
if (!chip->use_polling) {
free_irq(chip->irqnum, chip);
enable_irq(chip->irqnum);
}
fail1:
input_free_device(input);
kfree(chip);
return error;
}
static int __devexit tca6416_keypad_remove(struct i2c_client *client)
{
struct tca6416_keypad_chip *chip = i2c_get_clientdata(client);
if (!chip->use_polling) {
free_irq(chip->irqnum, chip);
enable_irq(chip->irqnum);
}
input_unregister_device(chip->input);
kfree(chip);
return 0;
}
static int tca6416_keypad_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tca6416_keypad_chip *chip = i2c_get_clientdata(client);
if (device_may_wakeup(dev))
enable_irq_wake(chip->irqnum);
return 0;
}
static int tca6416_keypad_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct tca6416_keypad_chip *chip = i2c_get_clientdata(client);
if (device_may_wakeup(dev))
disable_irq_wake(chip->irqnum);
return 0;
}
static int __init tca6416_keypad_init(void)
{
return i2c_add_driver(&tca6416_keypad_driver);
}
static void __exit tca6416_keypad_exit(void)
{
i2c_del_driver(&tca6416_keypad_driver);
}
