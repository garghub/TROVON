static int max732x_writeb(struct max732x_chip *chip, int group_a, uint8_t val)
{
struct i2c_client *client;
int ret;
client = group_a ? chip->client_group_a : chip->client_group_b;
ret = i2c_smbus_write_byte(client, val);
if (ret < 0) {
dev_err(&client->dev, "failed writing\n");
return ret;
}
return 0;
}
static int max732x_readb(struct max732x_chip *chip, int group_a, uint8_t *val)
{
struct i2c_client *client;
int ret;
client = group_a ? chip->client_group_a : chip->client_group_b;
ret = i2c_smbus_read_byte(client);
if (ret < 0) {
dev_err(&client->dev, "failed reading\n");
return ret;
}
*val = (uint8_t)ret;
return 0;
}
static inline int is_group_a(struct max732x_chip *chip, unsigned off)
{
return (1u << off) & chip->mask_group_a;
}
static int max732x_gpio_get_value(struct gpio_chip *gc, unsigned off)
{
struct max732x_chip *chip;
uint8_t reg_val;
int ret;
chip = container_of(gc, struct max732x_chip, gpio_chip);
ret = max732x_readb(chip, is_group_a(chip, off), &reg_val);
if (ret < 0)
return 0;
return reg_val & (1u << (off & 0x7));
}
static void max732x_gpio_set_value(struct gpio_chip *gc, unsigned off, int val)
{
struct max732x_chip *chip;
uint8_t reg_out, mask = 1u << (off & 0x7);
int ret;
chip = container_of(gc, struct max732x_chip, gpio_chip);
mutex_lock(&chip->lock);
reg_out = (off > 7) ? chip->reg_out[1] : chip->reg_out[0];
reg_out = (val) ? reg_out | mask : reg_out & ~mask;
ret = max732x_writeb(chip, is_group_a(chip, off), reg_out);
if (ret < 0)
goto out;
if (off > 7)
chip->reg_out[1] = reg_out;
else
chip->reg_out[0] = reg_out;
out:
mutex_unlock(&chip->lock);
}
static int max732x_gpio_direction_input(struct gpio_chip *gc, unsigned off)
{
struct max732x_chip *chip;
unsigned int mask = 1u << off;
chip = container_of(gc, struct max732x_chip, gpio_chip);
if ((mask & chip->dir_input) == 0) {
dev_dbg(&chip->client->dev, "%s port %d is output only\n",
chip->client->name, off);
return -EACCES;
}
if ((mask & chip->dir_output))
max732x_gpio_set_value(gc, off, 1);
return 0;
}
static int max732x_gpio_direction_output(struct gpio_chip *gc,
unsigned off, int val)
{
struct max732x_chip *chip;
unsigned int mask = 1u << off;
chip = container_of(gc, struct max732x_chip, gpio_chip);
if ((mask & chip->dir_output) == 0) {
dev_dbg(&chip->client->dev, "%s port %d is input only\n",
chip->client->name, off);
return -EACCES;
}
max732x_gpio_set_value(gc, off, val);
return 0;
}
static int max732x_writew(struct max732x_chip *chip, uint16_t val)
{
int ret;
val = cpu_to_le16(val);
ret = i2c_master_send(chip->client_group_a, (char *)&val, 2);
if (ret < 0) {
dev_err(&chip->client_group_a->dev, "failed writing\n");
return ret;
}
return 0;
}
static int max732x_readw(struct max732x_chip *chip, uint16_t *val)
{
int ret;
ret = i2c_master_recv(chip->client_group_a, (char *)val, 2);
if (ret < 0) {
dev_err(&chip->client_group_a->dev, "failed reading\n");
return ret;
}
*val = le16_to_cpu(*val);
return 0;
}
static void max732x_irq_update_mask(struct max732x_chip *chip)
{
uint16_t msg;
if (chip->irq_mask == chip->irq_mask_cur)
return;
chip->irq_mask = chip->irq_mask_cur;
if (chip->irq_features == INT_NO_MASK)
return;
mutex_lock(&chip->lock);
switch (chip->irq_features) {
case INT_INDEP_MASK:
msg = (chip->irq_mask << 8) | chip->reg_out[0];
max732x_writew(chip, msg);
break;
case INT_MERGED_MASK:
msg = chip->irq_mask | chip->reg_out[0];
max732x_writeb(chip, 1, (uint8_t)msg);
break;
}
mutex_unlock(&chip->lock);
}
static int max732x_gpio_to_irq(struct gpio_chip *gc, unsigned off)
{
struct max732x_chip *chip;
chip = container_of(gc, struct max732x_chip, gpio_chip);
return chip->irq_base + off;
}
static void max732x_irq_mask(struct irq_data *d)
{
struct max732x_chip *chip = irq_data_get_irq_chip_data(d);
chip->irq_mask_cur &= ~(1 << (d->irq - chip->irq_base));
}
static void max732x_irq_unmask(struct irq_data *d)
{
struct max732x_chip *chip = irq_data_get_irq_chip_data(d);
chip->irq_mask_cur |= 1 << (d->irq - chip->irq_base);
}
static void max732x_irq_bus_lock(struct irq_data *d)
{
struct max732x_chip *chip = irq_data_get_irq_chip_data(d);
mutex_lock(&chip->irq_lock);
chip->irq_mask_cur = chip->irq_mask;
}
static void max732x_irq_bus_sync_unlock(struct irq_data *d)
{
struct max732x_chip *chip = irq_data_get_irq_chip_data(d);
max732x_irq_update_mask(chip);
mutex_unlock(&chip->irq_lock);
}
static int max732x_irq_set_type(struct irq_data *d, unsigned int type)
{
struct max732x_chip *chip = irq_data_get_irq_chip_data(d);
uint16_t off = d->irq - chip->irq_base;
uint16_t mask = 1 << off;
if (!(mask & chip->dir_input)) {
dev_dbg(&chip->client->dev, "%s port %d is output only\n",
chip->client->name, off);
return -EACCES;
}
if (!(type & IRQ_TYPE_EDGE_BOTH)) {
dev_err(&chip->client->dev, "irq %d: unsupported type %d\n",
d->irq, type);
return -EINVAL;
}
if (type & IRQ_TYPE_EDGE_FALLING)
chip->irq_trig_fall |= mask;
else
chip->irq_trig_fall &= ~mask;
if (type & IRQ_TYPE_EDGE_RISING)
chip->irq_trig_raise |= mask;
else
chip->irq_trig_raise &= ~mask;
return max732x_gpio_direction_input(&chip->gpio_chip, off);
}
static uint8_t max732x_irq_pending(struct max732x_chip *chip)
{
uint8_t cur_stat;
uint8_t old_stat;
uint8_t trigger;
uint8_t pending;
uint16_t status;
int ret;
ret = max732x_readw(chip, &status);
if (ret)
return 0;
trigger = status >> 8;
trigger &= chip->irq_mask;
if (!trigger)
return 0;
cur_stat = status & 0xFF;
cur_stat &= chip->irq_mask;
old_stat = cur_stat ^ trigger;
pending = (old_stat & chip->irq_trig_fall) |
(cur_stat & chip->irq_trig_raise);
pending &= trigger;
return pending;
}
static irqreturn_t max732x_irq_handler(int irq, void *devid)
{
struct max732x_chip *chip = devid;
uint8_t pending;
uint8_t level;
pending = max732x_irq_pending(chip);
if (!pending)
return IRQ_HANDLED;
do {
level = __ffs(pending);
handle_nested_irq(level + chip->irq_base);
pending &= ~(1 << level);
} while (pending);
return IRQ_HANDLED;
}
static int max732x_irq_setup(struct max732x_chip *chip,
const struct i2c_device_id *id)
{
struct i2c_client *client = chip->client;
struct max732x_platform_data *pdata = client->dev.platform_data;
int has_irq = max732x_features[id->driver_data] >> 32;
int ret;
if (pdata->irq_base && has_irq != INT_NONE) {
int lvl;
chip->irq_base = pdata->irq_base;
chip->irq_features = has_irq;
mutex_init(&chip->irq_lock);
for (lvl = 0; lvl < chip->gpio_chip.ngpio; lvl++) {
int irq = lvl + chip->irq_base;
if (!(chip->dir_input & (1 << lvl)))
continue;
irq_set_chip_data(irq, chip);
irq_set_chip_and_handler(irq, &max732x_irq_chip,
handle_edge_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
ret = request_threaded_irq(client->irq,
NULL,
max732x_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
dev_name(&client->dev), chip);
if (ret) {
dev_err(&client->dev, "failed to request irq %d\n",
client->irq);
goto out_failed;
}
chip->gpio_chip.to_irq = max732x_gpio_to_irq;
}
return 0;
out_failed:
chip->irq_base = 0;
return ret;
}
static void max732x_irq_teardown(struct max732x_chip *chip)
{
if (chip->irq_base)
free_irq(chip->client->irq, chip);
}
static int max732x_irq_setup(struct max732x_chip *chip,
const struct i2c_device_id *id)
{
struct i2c_client *client = chip->client;
struct max732x_platform_data *pdata = client->dev.platform_data;
int has_irq = max732x_features[id->driver_data] >> 32;
if (pdata->irq_base && has_irq != INT_NONE)
dev_warn(&client->dev, "interrupt support not compiled in\n");
return 0;
}
static void max732x_irq_teardown(struct max732x_chip *chip)
{
}
static int max732x_setup_gpio(struct max732x_chip *chip,
const struct i2c_device_id *id,
unsigned gpio_start)
{
struct gpio_chip *gc = &chip->gpio_chip;
uint32_t id_data = (uint32_t)max732x_features[id->driver_data];
int i, port = 0;
for (i = 0; i < 16; i++, id_data >>= 2) {
unsigned int mask = 1 << port;
switch (id_data & 0x3) {
case PORT_OUTPUT:
chip->dir_output |= mask;
break;
case PORT_INPUT:
chip->dir_input |= mask;
break;
case PORT_OPENDRAIN:
chip->dir_output |= mask;
chip->dir_input |= mask;
break;
default:
continue;
}
if (i < 8)
chip->mask_group_a |= mask;
port++;
}
if (chip->dir_input)
gc->direction_input = max732x_gpio_direction_input;
if (chip->dir_output) {
gc->direction_output = max732x_gpio_direction_output;
gc->set = max732x_gpio_set_value;
}
gc->get = max732x_gpio_get_value;
gc->can_sleep = 1;
gc->base = gpio_start;
gc->ngpio = port;
gc->label = chip->client->name;
gc->owner = THIS_MODULE;
return port;
}
static int max732x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max732x_platform_data *pdata;
struct max732x_chip *chip;
struct i2c_client *c;
uint16_t addr_a, addr_b;
int ret, nr_port;
pdata = client->dev.platform_data;
if (pdata == NULL) {
dev_dbg(&client->dev, "no platform data\n");
return -EINVAL;
}
chip = devm_kzalloc(&client->dev, sizeof(struct max732x_chip),
GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->client = client;
nr_port = max732x_setup_gpio(chip, id, pdata->gpio_base);
addr_a = (client->addr & 0x0f) | 0x60;
addr_b = (client->addr & 0x0f) | 0x50;
switch (client->addr & 0x70) {
case 0x60:
chip->client_group_a = client;
if (nr_port > 8) {
c = i2c_new_dummy(client->adapter, addr_b);
chip->client_group_b = chip->client_dummy = c;
}
break;
case 0x50:
chip->client_group_b = client;
if (nr_port > 8) {
c = i2c_new_dummy(client->adapter, addr_a);
chip->client_group_a = chip->client_dummy = c;
}
break;
default:
dev_err(&client->dev, "invalid I2C address specified %02x\n",
client->addr);
ret = -EINVAL;
goto out_failed;
}
mutex_init(&chip->lock);
max732x_readb(chip, is_group_a(chip, 0), &chip->reg_out[0]);
if (nr_port > 8)
max732x_readb(chip, is_group_a(chip, 8), &chip->reg_out[1]);
ret = max732x_irq_setup(chip, id);
if (ret)
goto out_failed;
ret = gpiochip_add(&chip->gpio_chip);
if (ret)
goto out_failed;
if (pdata->setup) {
ret = pdata->setup(client, chip->gpio_chip.base,
chip->gpio_chip.ngpio, pdata->context);
if (ret < 0)
dev_warn(&client->dev, "setup failed, %d\n", ret);
}
i2c_set_clientdata(client, chip);
return 0;
out_failed:
max732x_irq_teardown(chip);
return ret;
}
static int max732x_remove(struct i2c_client *client)
{
struct max732x_platform_data *pdata = client->dev.platform_data;
struct max732x_chip *chip = i2c_get_clientdata(client);
int ret;
if (pdata->teardown) {
ret = pdata->teardown(client, chip->gpio_chip.base,
chip->gpio_chip.ngpio, pdata->context);
if (ret < 0) {
dev_err(&client->dev, "%s failed, %d\n",
"teardown", ret);
return ret;
}
}
ret = gpiochip_remove(&chip->gpio_chip);
if (ret) {
dev_err(&client->dev, "%s failed, %d\n",
"gpiochip_remove()", ret);
return ret;
}
max732x_irq_teardown(chip);
if (chip->client_dummy)
i2c_unregister_device(chip->client_dummy);
return 0;
}
static int __init max732x_init(void)
{
return i2c_add_driver(&max732x_driver);
}
static void __exit max732x_exit(void)
{
i2c_del_driver(&max732x_driver);
}
