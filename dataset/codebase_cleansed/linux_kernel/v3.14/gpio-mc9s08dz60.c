static inline struct mc9s08dz60 *to_mc9s08dz60(struct gpio_chip *gc)
{
return container_of(gc, struct mc9s08dz60, chip);
}
static void mc9s_gpio_to_reg_and_bit(int offset, u8 *reg, u8 *bit)
{
*reg = 0x20 + offset / GPIO_NUM_PER_GROUP;
*bit = offset % GPIO_NUM_PER_GROUP;
}
static int mc9s08dz60_get_value(struct gpio_chip *gc, unsigned offset)
{
u8 reg, bit;
s32 value;
struct mc9s08dz60 *mc9s = to_mc9s08dz60(gc);
mc9s_gpio_to_reg_and_bit(offset, &reg, &bit);
value = i2c_smbus_read_byte_data(mc9s->client, reg);
return (value >= 0) ? (value >> bit) & 0x1 : 0;
}
static int mc9s08dz60_set(struct mc9s08dz60 *mc9s, unsigned offset, int val)
{
u8 reg, bit;
s32 value;
mc9s_gpio_to_reg_and_bit(offset, &reg, &bit);
value = i2c_smbus_read_byte_data(mc9s->client, reg);
if (value >= 0) {
if (val)
value |= 1 << bit;
else
value &= ~(1 << bit);
return i2c_smbus_write_byte_data(mc9s->client, reg, value);
} else
return value;
}
static void mc9s08dz60_set_value(struct gpio_chip *gc, unsigned offset, int val)
{
struct mc9s08dz60 *mc9s = to_mc9s08dz60(gc);
mc9s08dz60_set(mc9s, offset, val);
}
static int mc9s08dz60_direction_output(struct gpio_chip *gc,
unsigned offset, int val)
{
struct mc9s08dz60 *mc9s = to_mc9s08dz60(gc);
return mc9s08dz60_set(mc9s, offset, val);
}
static int mc9s08dz60_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mc9s08dz60 *mc9s;
mc9s = devm_kzalloc(&client->dev, sizeof(*mc9s), GFP_KERNEL);
if (!mc9s)
return -ENOMEM;
mc9s->chip.label = client->name;
mc9s->chip.base = -1;
mc9s->chip.dev = &client->dev;
mc9s->chip.owner = THIS_MODULE;
mc9s->chip.ngpio = GPIO_NUM;
mc9s->chip.can_sleep = true;
mc9s->chip.get = mc9s08dz60_get_value;
mc9s->chip.set = mc9s08dz60_set_value;
mc9s->chip.direction_output = mc9s08dz60_direction_output;
mc9s->client = client;
i2c_set_clientdata(client, mc9s);
return gpiochip_add(&mc9s->chip);
}
static int mc9s08dz60_remove(struct i2c_client *client)
{
struct mc9s08dz60 *mc9s;
mc9s = i2c_get_clientdata(client);
return gpiochip_remove(&mc9s->chip);
}
