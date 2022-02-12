static int pcf857x_input8(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
int status;
mutex_lock(&gpio->lock);
gpio->out |= (1 << offset);
status = i2c_smbus_write_byte(gpio->client, gpio->out);
mutex_unlock(&gpio->lock);
return status;
}
static int pcf857x_get8(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
s32 value;
value = i2c_smbus_read_byte(gpio->client);
return (value < 0) ? 0 : (value & (1 << offset));
}
static int pcf857x_output8(struct gpio_chip *chip, unsigned offset, int value)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
unsigned bit = 1 << offset;
int status;
mutex_lock(&gpio->lock);
if (value)
gpio->out |= bit;
else
gpio->out &= ~bit;
status = i2c_smbus_write_byte(gpio->client, gpio->out);
mutex_unlock(&gpio->lock);
return status;
}
static void pcf857x_set8(struct gpio_chip *chip, unsigned offset, int value)
{
pcf857x_output8(chip, offset, value);
}
static int i2c_write_le16(struct i2c_client *client, u16 word)
{
u8 buf[2] = { word & 0xff, word >> 8, };
int status;
status = i2c_master_send(client, buf, 2);
return (status < 0) ? status : 0;
}
static int i2c_read_le16(struct i2c_client *client)
{
u8 buf[2];
int status;
status = i2c_master_recv(client, buf, 2);
if (status < 0)
return status;
return (buf[1] << 8) | buf[0];
}
static int pcf857x_input16(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
int status;
mutex_lock(&gpio->lock);
gpio->out |= (1 << offset);
status = i2c_write_le16(gpio->client, gpio->out);
mutex_unlock(&gpio->lock);
return status;
}
static int pcf857x_get16(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
int value;
value = i2c_read_le16(gpio->client);
return (value < 0) ? 0 : (value & (1 << offset));
}
static int pcf857x_output16(struct gpio_chip *chip, unsigned offset, int value)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
unsigned bit = 1 << offset;
int status;
mutex_lock(&gpio->lock);
if (value)
gpio->out |= bit;
else
gpio->out &= ~bit;
status = i2c_write_le16(gpio->client, gpio->out);
mutex_unlock(&gpio->lock);
return status;
}
static void pcf857x_set16(struct gpio_chip *chip, unsigned offset, int value)
{
pcf857x_output16(chip, offset, value);
}
static int pcf857x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pcf857x_platform_data *pdata;
struct pcf857x *gpio;
int status;
pdata = client->dev.platform_data;
if (!pdata) {
dev_dbg(&client->dev, "no platform data\n");
}
gpio = kzalloc(sizeof *gpio, GFP_KERNEL);
if (!gpio)
return -ENOMEM;
mutex_init(&gpio->lock);
gpio->chip.base = pdata ? pdata->gpio_base : -1;
gpio->chip.can_sleep = 1;
gpio->chip.dev = &client->dev;
gpio->chip.owner = THIS_MODULE;
gpio->chip.ngpio = id->driver_data;
if (gpio->chip.ngpio == 8) {
gpio->chip.direction_input = pcf857x_input8;
gpio->chip.get = pcf857x_get8;
gpio->chip.direction_output = pcf857x_output8;
gpio->chip.set = pcf857x_set8;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE))
status = -EIO;
else
status = i2c_smbus_read_byte(client);
} else if (gpio->chip.ngpio == 16) {
gpio->chip.direction_input = pcf857x_input16;
gpio->chip.get = pcf857x_get16;
gpio->chip.direction_output = pcf857x_output16;
gpio->chip.set = pcf857x_set16;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
status = -EIO;
else
status = i2c_read_le16(client);
} else {
dev_dbg(&client->dev, "unsupported number of gpios\n");
status = -EINVAL;
}
if (status < 0)
goto fail;
gpio->chip.label = client->name;
gpio->client = client;
i2c_set_clientdata(client, gpio);
gpio->out = pdata ? ~pdata->n_latch : ~0;
status = gpiochip_add(&gpio->chip);
if (status < 0)
goto fail;
dev_info(&client->dev, "gpios %d..%d on a %s%s\n",
gpio->chip.base,
gpio->chip.base + gpio->chip.ngpio - 1,
client->name,
client->irq ? " (irq ignored)" : "");
if (pdata && pdata->setup) {
status = pdata->setup(client,
gpio->chip.base, gpio->chip.ngpio,
pdata->context);
if (status < 0)
dev_warn(&client->dev, "setup --> %d\n", status);
}
return 0;
fail:
dev_dbg(&client->dev, "probe error %d for '%s'\n",
status, client->name);
kfree(gpio);
return status;
}
static int pcf857x_remove(struct i2c_client *client)
{
struct pcf857x_platform_data *pdata = client->dev.platform_data;
struct pcf857x *gpio = i2c_get_clientdata(client);
int status = 0;
if (pdata && pdata->teardown) {
status = pdata->teardown(client,
gpio->chip.base, gpio->chip.ngpio,
pdata->context);
if (status < 0) {
dev_err(&client->dev, "%s --> %d\n",
"teardown", status);
return status;
}
}
status = gpiochip_remove(&gpio->chip);
if (status == 0)
kfree(gpio);
else
dev_err(&client->dev, "%s --> %d\n", "remove", status);
return status;
}
static int __init pcf857x_init(void)
{
return i2c_add_driver(&pcf857x_driver);
}
static void __exit pcf857x_exit(void)
{
i2c_del_driver(&pcf857x_driver);
}
