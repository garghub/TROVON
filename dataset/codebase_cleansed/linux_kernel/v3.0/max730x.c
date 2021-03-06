static int max7301_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct max7301 *ts = container_of(chip, struct max7301, chip);
u8 *config;
u8 offset_bits, pin_config;
int ret;
offset += 4;
offset_bits = (offset & 3) << 1;
config = &ts->port_config[offset >> 2];
if (ts->input_pullup_active & BIT(offset))
pin_config = PIN_CONFIG_IN_PULLUP;
else
pin_config = PIN_CONFIG_IN_WO_PULLUP;
mutex_lock(&ts->lock);
*config = (*config & ~(PIN_CONFIG_MASK << offset_bits))
| (pin_config << offset_bits);
ret = ts->write(ts->dev, 0x08 + (offset >> 2), *config);
mutex_unlock(&ts->lock);
return ret;
}
static int __max7301_set(struct max7301 *ts, unsigned offset, int value)
{
if (value) {
ts->out_level |= 1 << offset;
return ts->write(ts->dev, 0x20 + offset, 0x01);
} else {
ts->out_level &= ~(1 << offset);
return ts->write(ts->dev, 0x20 + offset, 0x00);
}
}
static int max7301_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct max7301 *ts = container_of(chip, struct max7301, chip);
u8 *config;
u8 offset_bits;
int ret;
offset += 4;
offset_bits = (offset & 3) << 1;
config = &ts->port_config[offset >> 2];
mutex_lock(&ts->lock);
*config = (*config & ~(PIN_CONFIG_MASK << offset_bits))
| (PIN_CONFIG_OUT << offset_bits);
ret = __max7301_set(ts, offset, value);
if (!ret)
ret = ts->write(ts->dev, 0x08 + (offset >> 2), *config);
mutex_unlock(&ts->lock);
return ret;
}
static int max7301_get(struct gpio_chip *chip, unsigned offset)
{
struct max7301 *ts = container_of(chip, struct max7301, chip);
int config, level = -EINVAL;
offset += 4;
mutex_lock(&ts->lock);
config = (ts->port_config[offset >> 2] >> ((offset & 3) << 1))
& PIN_CONFIG_MASK;
switch (config) {
case PIN_CONFIG_OUT:
level = !!(ts->out_level & (1 << offset));
break;
case PIN_CONFIG_IN_WO_PULLUP:
case PIN_CONFIG_IN_PULLUP:
level = ts->read(ts->dev, 0x20 + offset) & 0x01;
}
mutex_unlock(&ts->lock);
return level;
}
static void max7301_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct max7301 *ts = container_of(chip, struct max7301, chip);
offset += 4;
mutex_lock(&ts->lock);
__max7301_set(ts, offset, value);
mutex_unlock(&ts->lock);
}
int __devinit __max730x_probe(struct max7301 *ts)
{
struct device *dev = ts->dev;
struct max7301_platform_data *pdata;
int i, ret;
pdata = dev->platform_data;
if (!pdata || !pdata->base) {
dev_err(dev, "incorrect or missing platform data\n");
return -EINVAL;
}
mutex_init(&ts->lock);
dev_set_drvdata(dev, ts);
ts->write(dev, 0x04, 0x01);
ts->input_pullup_active = pdata->input_pullup_active;
ts->chip.label = dev->driver->name;
ts->chip.direction_input = max7301_direction_input;
ts->chip.get = max7301_get;
ts->chip.direction_output = max7301_direction_output;
ts->chip.set = max7301_set;
ts->chip.base = pdata->base;
ts->chip.ngpio = PIN_NUMBER;
ts->chip.can_sleep = 1;
ts->chip.dev = dev;
ts->chip.owner = THIS_MODULE;
for (i = 1; i < 8; i++) {
int j;
ts->port_config[i] = 0xAA;
for (j = 0; j < 4; j++) {
int offset = (i - 1) * 4 + j;
ret = max7301_direction_input(&ts->chip, offset);
if (ret)
goto exit_destroy;
}
}
ret = gpiochip_add(&ts->chip);
if (ret)
goto exit_destroy;
return ret;
exit_destroy:
dev_set_drvdata(dev, NULL);
mutex_destroy(&ts->lock);
return ret;
}
int __devexit __max730x_remove(struct device *dev)
{
struct max7301 *ts = dev_get_drvdata(dev);
int ret;
if (ts == NULL)
return -ENODEV;
dev_set_drvdata(dev, NULL);
ts->write(dev, 0x04, 0x00);
ret = gpiochip_remove(&ts->chip);
if (!ret) {
mutex_destroy(&ts->lock);
kfree(ts);
} else
dev_err(dev, "Failed to remove GPIO controller: %d\n", ret);
return ret;
}
