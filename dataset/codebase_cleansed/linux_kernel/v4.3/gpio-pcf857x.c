static int i2c_write_le8(struct i2c_client *client, unsigned data)
{
return i2c_smbus_write_byte(client, data);
}
static int i2c_read_le8(struct i2c_client *client)
{
return (int)i2c_smbus_read_byte(client);
}
static int i2c_write_le16(struct i2c_client *client, unsigned word)
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
static int pcf857x_input(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
int status;
mutex_lock(&gpio->lock);
gpio->out |= (1 << offset);
status = gpio->write(gpio->client, gpio->out);
mutex_unlock(&gpio->lock);
return status;
}
static int pcf857x_get(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
int value;
value = gpio->read(gpio->client);
return (value < 0) ? 0 : (value & (1 << offset));
}
static int pcf857x_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
unsigned bit = 1 << offset;
int status;
mutex_lock(&gpio->lock);
if (value)
gpio->out |= bit;
else
gpio->out &= ~bit;
status = gpio->write(gpio->client, gpio->out);
mutex_unlock(&gpio->lock);
return status;
}
static void pcf857x_set(struct gpio_chip *chip, unsigned offset, int value)
{
pcf857x_output(chip, offset, value);
}
static irqreturn_t pcf857x_irq(int irq, void *data)
{
struct pcf857x *gpio = data;
unsigned long change, i, status;
status = gpio->read(gpio->client);
mutex_lock(&gpio->lock);
change = (gpio->status ^ status) & gpio->irq_enabled;
gpio->status = status;
mutex_unlock(&gpio->lock);
for_each_set_bit(i, &change, gpio->chip.ngpio)
handle_nested_irq(irq_find_mapping(gpio->chip.irqdomain, i));
return IRQ_HANDLED;
}
static void noop(struct irq_data *data) { }
static int pcf857x_irq_set_wake(struct irq_data *data, unsigned int on)
{
struct pcf857x *gpio = irq_data_get_irq_chip_data(data);
int error = 0;
if (gpio->irq_parent) {
error = irq_set_irq_wake(gpio->irq_parent, on);
if (error) {
dev_dbg(&gpio->client->dev,
"irq %u doesn't support irq_set_wake\n",
gpio->irq_parent);
gpio->irq_parent = 0;
}
}
return error;
}
static void pcf857x_irq_enable(struct irq_data *data)
{
struct pcf857x *gpio = irq_data_get_irq_chip_data(data);
gpio->irq_enabled |= (1 << data->hwirq);
}
static void pcf857x_irq_disable(struct irq_data *data)
{
struct pcf857x *gpio = irq_data_get_irq_chip_data(data);
gpio->irq_enabled &= ~(1 << data->hwirq);
}
static void pcf857x_irq_bus_lock(struct irq_data *data)
{
struct pcf857x *gpio = irq_data_get_irq_chip_data(data);
mutex_lock(&gpio->lock);
}
static void pcf857x_irq_bus_sync_unlock(struct irq_data *data)
{
struct pcf857x *gpio = irq_data_get_irq_chip_data(data);
mutex_unlock(&gpio->lock);
}
static int pcf857x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pcf857x_platform_data *pdata = dev_get_platdata(&client->dev);
struct device_node *np = client->dev.of_node;
struct pcf857x *gpio;
unsigned int n_latch = 0;
int status;
if (IS_ENABLED(CONFIG_OF) && np)
of_property_read_u32(np, "lines-initial-states", &n_latch);
else if (pdata)
n_latch = pdata->n_latch;
else
dev_dbg(&client->dev, "no platform data\n");
gpio = devm_kzalloc(&client->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
mutex_init(&gpio->lock);
gpio->chip.base = pdata ? pdata->gpio_base : -1;
gpio->chip.can_sleep = true;
gpio->chip.dev = &client->dev;
gpio->chip.owner = THIS_MODULE;
gpio->chip.get = pcf857x_get;
gpio->chip.set = pcf857x_set;
gpio->chip.direction_input = pcf857x_input;
gpio->chip.direction_output = pcf857x_output;
gpio->chip.ngpio = id->driver_data;
if (gpio->chip.ngpio == 8) {
gpio->write = i2c_write_le8;
gpio->read = i2c_read_le8;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE))
status = -EIO;
else
status = i2c_smbus_read_byte(client);
} else if (gpio->chip.ngpio == 16) {
gpio->write = i2c_write_le16;
gpio->read = i2c_read_le16;
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
gpio->out = ~n_latch;
gpio->status = gpio->out;
status = gpiochip_add(&gpio->chip);
if (status < 0)
goto fail;
if (client->irq) {
status = gpiochip_irqchip_add(&gpio->chip, &pcf857x_irq_chip,
0, handle_level_irq,
IRQ_TYPE_NONE);
if (status) {
dev_err(&client->dev, "cannot add irqchip\n");
goto fail_irq;
}
status = devm_request_threaded_irq(&client->dev, client->irq,
NULL, pcf857x_irq, IRQF_ONESHOT |
IRQF_TRIGGER_FALLING | IRQF_SHARED,
dev_name(&client->dev), gpio);
if (status)
goto fail_irq;
gpiochip_set_chained_irqchip(&gpio->chip, &pcf857x_irq_chip,
client->irq, NULL);
gpio->irq_parent = client->irq;
}
if (pdata && pdata->setup) {
status = pdata->setup(client,
gpio->chip.base, gpio->chip.ngpio,
pdata->context);
if (status < 0)
dev_warn(&client->dev, "setup --> %d\n", status);
}
dev_info(&client->dev, "probed\n");
return 0;
fail_irq:
gpiochip_remove(&gpio->chip);
fail:
dev_dbg(&client->dev, "probe error %d for '%s'\n", status,
client->name);
return status;
}
static int pcf857x_remove(struct i2c_client *client)
{
struct pcf857x_platform_data *pdata = dev_get_platdata(&client->dev);
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
gpiochip_remove(&gpio->chip);
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
