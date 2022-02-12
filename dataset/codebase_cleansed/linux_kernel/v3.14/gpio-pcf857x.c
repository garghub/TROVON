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
static int pcf857x_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct pcf857x *gpio = container_of(chip, struct pcf857x, chip);
int ret;
ret = irq_create_mapping(gpio->irq_domain, offset);
if (ret > 0)
gpio->irq_mapped |= (1 << offset);
return ret;
}
static irqreturn_t pcf857x_irq(int irq, void *data)
{
struct pcf857x *gpio = data;
unsigned long change, i, status, flags;
status = gpio->read(gpio->client);
spin_lock_irqsave(&gpio->slock, flags);
change = ((gpio->status ^ status) & gpio->irq_mapped);
for_each_set_bit(i, &change, gpio->chip.ngpio)
generic_handle_irq(irq_find_mapping(gpio->irq_domain, i));
gpio->status = status;
spin_unlock_irqrestore(&gpio->slock, flags);
return IRQ_HANDLED;
}
static int pcf857x_irq_domain_map(struct irq_domain *domain, unsigned int irq,
irq_hw_number_t hw)
{
struct pcf857x *gpio = domain->host_data;
irq_set_chip_and_handler(irq,
&dummy_irq_chip,
handle_level_irq);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
gpio->irq_mapped |= (1 << hw);
return 0;
}
static void pcf857x_irq_domain_cleanup(struct pcf857x *gpio)
{
if (gpio->irq_domain)
irq_domain_remove(gpio->irq_domain);
}
static int pcf857x_irq_domain_init(struct pcf857x *gpio,
struct i2c_client *client)
{
int status;
gpio->irq_domain = irq_domain_add_linear(client->dev.of_node,
gpio->chip.ngpio,
&pcf857x_irq_domain_ops,
gpio);
if (!gpio->irq_domain)
goto fail;
status = devm_request_threaded_irq(&client->dev, client->irq,
NULL, pcf857x_irq, IRQF_ONESHOT |
IRQF_TRIGGER_FALLING,
dev_name(&client->dev), gpio);
if (status)
goto fail;
gpio->chip.to_irq = pcf857x_to_irq;
return 0;
fail:
pcf857x_irq_domain_cleanup(gpio);
return -EINVAL;
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
spin_lock_init(&gpio->slock);
gpio->chip.base = pdata ? pdata->gpio_base : -1;
gpio->chip.can_sleep = true;
gpio->chip.dev = &client->dev;
gpio->chip.owner = THIS_MODULE;
gpio->chip.get = pcf857x_get;
gpio->chip.set = pcf857x_set;
gpio->chip.direction_input = pcf857x_input;
gpio->chip.direction_output = pcf857x_output;
gpio->chip.ngpio = id->driver_data;
if (client->irq) {
status = pcf857x_irq_domain_init(gpio, client);
if (status < 0) {
dev_err(&client->dev, "irq_domain init failed\n");
goto fail;
}
}
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
if (pdata && pdata->setup) {
status = pdata->setup(client,
gpio->chip.base, gpio->chip.ngpio,
pdata->context);
if (status < 0)
dev_warn(&client->dev, "setup --> %d\n", status);
}
dev_info(&client->dev, "probed\n");
return 0;
fail:
dev_dbg(&client->dev, "probe error %d for '%s'\n",
status, client->name);
if (client->irq)
pcf857x_irq_domain_cleanup(gpio);
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
if (client->irq)
pcf857x_irq_domain_cleanup(gpio);
status = gpiochip_remove(&gpio->chip);
if (status)
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
