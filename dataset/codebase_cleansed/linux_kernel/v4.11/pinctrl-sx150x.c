static int sx150x_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
return 0;
}
static const char *sx150x_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
return NULL;
}
static int sx150x_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
return -ENOTSUPP;
}
static bool sx150x_pin_is_oscio(struct sx150x_pinctrl *pctl, unsigned int pin)
{
if (pin >= pctl->data->npins)
return false;
if (pctl->data->model != SX150X_789)
return false;
return !strcmp(pctl->data->pins[pin].name, "oscio");
}
static int sx150x_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct sx150x_pinctrl *pctl = gpiochip_get_data(chip);
unsigned int value;
int ret;
if (sx150x_pin_is_oscio(pctl, offset))
return false;
ret = regmap_read(pctl->regmap, pctl->data->reg_dir, &value);
if (ret < 0)
return ret;
return !!(value & BIT(offset));
}
static int sx150x_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct sx150x_pinctrl *pctl = gpiochip_get_data(chip);
unsigned int value;
int ret;
if (sx150x_pin_is_oscio(pctl, offset))
return -EINVAL;
ret = regmap_read(pctl->regmap, pctl->data->reg_data, &value);
if (ret < 0)
return ret;
return !!(value & BIT(offset));
}
static int __sx150x_gpio_set(struct sx150x_pinctrl *pctl, unsigned int offset,
int value)
{
return regmap_write_bits(pctl->regmap, pctl->data->reg_data,
BIT(offset), value ? BIT(offset) : 0);
}
static int sx150x_gpio_oscio_set(struct sx150x_pinctrl *pctl,
int value)
{
return regmap_write(pctl->regmap,
pctl->data->pri.x789.reg_clock,
(value ? 0x1f : 0x10));
}
static void sx150x_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct sx150x_pinctrl *pctl = gpiochip_get_data(chip);
if (sx150x_pin_is_oscio(pctl, offset))
sx150x_gpio_oscio_set(pctl, value);
else
__sx150x_gpio_set(pctl, offset, value);
}
static void sx150x_gpio_set_multiple(struct gpio_chip *chip,
unsigned long *mask,
unsigned long *bits)
{
struct sx150x_pinctrl *pctl = gpiochip_get_data(chip);
regmap_write_bits(pctl->regmap, pctl->data->reg_data, *mask, *bits);
}
static int sx150x_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct sx150x_pinctrl *pctl = gpiochip_get_data(chip);
if (sx150x_pin_is_oscio(pctl, offset))
return -EINVAL;
return regmap_write_bits(pctl->regmap,
pctl->data->reg_dir,
BIT(offset), BIT(offset));
}
static int sx150x_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct sx150x_pinctrl *pctl = gpiochip_get_data(chip);
int ret;
if (sx150x_pin_is_oscio(pctl, offset))
return sx150x_gpio_oscio_set(pctl, value);
ret = __sx150x_gpio_set(pctl, offset, value);
if (ret < 0)
return ret;
return regmap_write_bits(pctl->regmap,
pctl->data->reg_dir,
BIT(offset), 0);
}
static void sx150x_irq_mask(struct irq_data *d)
{
struct sx150x_pinctrl *pctl =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
unsigned int n = d->hwirq;
pctl->irq.masked |= BIT(n);
}
static void sx150x_irq_unmask(struct irq_data *d)
{
struct sx150x_pinctrl *pctl =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
unsigned int n = d->hwirq;
pctl->irq.masked &= ~BIT(n);
}
static void sx150x_irq_set_sense(struct sx150x_pinctrl *pctl,
unsigned int line, unsigned int sense)
{
const unsigned int n = line * 2;
const unsigned int mask = ~((SX150X_IRQ_TYPE_EDGE_RISING |
SX150X_IRQ_TYPE_EDGE_FALLING) << n);
pctl->irq.sense &= mask;
pctl->irq.sense |= sense << n;
}
static int sx150x_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct sx150x_pinctrl *pctl =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
unsigned int n, val = 0;
if (flow_type & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW))
return -EINVAL;
n = d->hwirq;
if (flow_type & IRQ_TYPE_EDGE_RISING)
val |= SX150X_IRQ_TYPE_EDGE_RISING;
if (flow_type & IRQ_TYPE_EDGE_FALLING)
val |= SX150X_IRQ_TYPE_EDGE_FALLING;
sx150x_irq_set_sense(pctl, n, val);
return 0;
}
static irqreturn_t sx150x_irq_thread_fn(int irq, void *dev_id)
{
struct sx150x_pinctrl *pctl = (struct sx150x_pinctrl *)dev_id;
unsigned long n, status;
unsigned int val;
int err;
err = regmap_read(pctl->regmap, pctl->data->reg_irq_src, &val);
if (err < 0)
return IRQ_NONE;
err = regmap_write(pctl->regmap, pctl->data->reg_irq_src, val);
if (err < 0)
return IRQ_NONE;
status = val;
for_each_set_bit(n, &status, pctl->data->ngpios)
handle_nested_irq(irq_find_mapping(pctl->gpio.irqdomain, n));
return IRQ_HANDLED;
}
static void sx150x_irq_bus_lock(struct irq_data *d)
{
struct sx150x_pinctrl *pctl =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
mutex_lock(&pctl->lock);
}
static void sx150x_irq_bus_sync_unlock(struct irq_data *d)
{
struct sx150x_pinctrl *pctl =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
regmap_write(pctl->regmap, pctl->data->reg_irq_mask, pctl->irq.masked);
regmap_write(pctl->regmap, pctl->data->reg_sense, pctl->irq.sense);
mutex_unlock(&pctl->lock);
}
static int sx150x_pinconf_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct sx150x_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
unsigned int param = pinconf_to_config_param(*config);
int ret;
u32 arg;
unsigned int data;
if (sx150x_pin_is_oscio(pctl, pin)) {
switch (param) {
case PIN_CONFIG_DRIVE_PUSH_PULL:
case PIN_CONFIG_OUTPUT:
ret = regmap_read(pctl->regmap,
pctl->data->pri.x789.reg_clock,
&data);
if (ret < 0)
return ret;
if (param == PIN_CONFIG_DRIVE_PUSH_PULL)
arg = (data & 0x1f) ? 1 : 0;
else {
if ((data & 0x1f) == 0x1f)
arg = 1;
else if ((data & 0x1f) == 0x10)
arg = 0;
else
return -EINVAL;
}
break;
default:
return -ENOTSUPP;
}
goto out;
}
switch (param) {
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = regmap_read(pctl->regmap,
pctl->data->reg_pulldn,
&data);
data &= BIT(pin);
if (ret < 0)
return ret;
if (!ret)
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_BIAS_PULL_UP:
ret = regmap_read(pctl->regmap,
pctl->data->reg_pullup,
&data);
data &= BIT(pin);
if (ret < 0)
return ret;
if (!ret)
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (pctl->data->model != SX150X_789)
return -ENOTSUPP;
ret = regmap_read(pctl->regmap,
pctl->data->pri.x789.reg_drain,
&data);
data &= BIT(pin);
if (ret < 0)
return ret;
if (!data)
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
if (pctl->data->model != SX150X_789)
arg = true;
else {
ret = regmap_read(pctl->regmap,
pctl->data->pri.x789.reg_drain,
&data);
data &= BIT(pin);
if (ret < 0)
return ret;
if (data)
return -EINVAL;
arg = 1;
}
break;
case PIN_CONFIG_OUTPUT:
ret = sx150x_gpio_get_direction(&pctl->gpio, pin);
if (ret < 0)
return ret;
if (ret)
return -EINVAL;
ret = sx150x_gpio_get(&pctl->gpio, pin);
if (ret < 0)
return ret;
arg = ret;
break;
default:
return -ENOTSUPP;
}
out:
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int sx150x_pinconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned int num_configs)
{
struct sx150x_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
u32 arg;
int i;
int ret;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
if (sx150x_pin_is_oscio(pctl, pin)) {
if (param == PIN_CONFIG_OUTPUT) {
ret = sx150x_gpio_direction_output(&pctl->gpio,
pin, arg);
if (ret < 0)
return ret;
continue;
} else
return -ENOTSUPP;
}
switch (param) {
case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
case PIN_CONFIG_BIAS_DISABLE:
ret = regmap_write_bits(pctl->regmap,
pctl->data->reg_pulldn,
BIT(pin), 0);
if (ret < 0)
return ret;
ret = regmap_write_bits(pctl->regmap,
pctl->data->reg_pullup,
BIT(pin), 0);
if (ret < 0)
return ret;
break;
case PIN_CONFIG_BIAS_PULL_UP:
ret = regmap_write_bits(pctl->regmap,
pctl->data->reg_pullup,
BIT(pin), BIT(pin));
if (ret < 0)
return ret;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = regmap_write_bits(pctl->regmap,
pctl->data->reg_pulldn,
BIT(pin), BIT(pin));
if (ret < 0)
return ret;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (pctl->data->model != SX150X_789 ||
sx150x_pin_is_oscio(pctl, pin))
return -ENOTSUPP;
ret = regmap_write_bits(pctl->regmap,
pctl->data->pri.x789.reg_drain,
BIT(pin), BIT(pin));
if (ret < 0)
return ret;
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
if (pctl->data->model != SX150X_789 ||
sx150x_pin_is_oscio(pctl, pin))
return 0;
ret = regmap_write_bits(pctl->regmap,
pctl->data->pri.x789.reg_drain,
BIT(pin), 0);
if (ret < 0)
return ret;
break;
case PIN_CONFIG_OUTPUT:
ret = sx150x_gpio_direction_output(&pctl->gpio,
pin, arg);
if (ret < 0)
return ret;
break;
default:
return -ENOTSUPP;
}
}
return 0;
}
static int sx150x_reset(struct sx150x_pinctrl *pctl)
{
int err;
err = i2c_smbus_write_byte_data(pctl->client,
pctl->data->pri.x789.reg_reset,
SX150X_789_RESET_KEY1);
if (err < 0)
return err;
err = i2c_smbus_write_byte_data(pctl->client,
pctl->data->pri.x789.reg_reset,
SX150X_789_RESET_KEY2);
return err;
}
static int sx150x_init_misc(struct sx150x_pinctrl *pctl)
{
u8 reg, value;
switch (pctl->data->model) {
case SX150X_789:
reg = pctl->data->pri.x789.reg_misc;
value = SX150X_789_REG_MISC_AUTOCLEAR_OFF;
break;
case SX150X_456:
reg = pctl->data->pri.x456.reg_advanced;
value = 0x00;
if (!reg)
return 0;
break;
case SX150X_123:
reg = pctl->data->pri.x123.reg_advanced;
value = 0x00;
break;
default:
WARN(1, "Unknown chip model %d\n", pctl->data->model);
return -EINVAL;
}
return regmap_write(pctl->regmap, reg, value);
}
static int sx150x_init_hw(struct sx150x_pinctrl *pctl)
{
const u8 reg[] = {
[SX150X_789] = pctl->data->pri.x789.reg_polarity,
[SX150X_456] = pctl->data->pri.x456.reg_pld_mode,
[SX150X_123] = pctl->data->pri.x123.reg_pld_mode,
};
int err;
if (pctl->data->model == SX150X_789 &&
of_property_read_bool(pctl->dev->of_node, "semtech,probe-reset")) {
err = sx150x_reset(pctl);
if (err < 0)
return err;
}
err = sx150x_init_misc(pctl);
if (err < 0)
return err;
return regmap_write(pctl->regmap, reg[pctl->data->model], 0);
}
static int sx150x_regmap_reg_width(struct sx150x_pinctrl *pctl,
unsigned int reg)
{
const struct sx150x_device_data *data = pctl->data;
if (reg == data->reg_sense) {
return 2 * data->ngpios;
} else if ((data->model == SX150X_789 &&
(reg == data->pri.x789.reg_misc ||
reg == data->pri.x789.reg_clock ||
reg == data->pri.x789.reg_reset))
||
(data->model == SX150X_123 &&
reg == data->pri.x123.reg_advanced)
||
(data->model == SX150X_456 &&
data->pri.x456.reg_advanced &&
reg == data->pri.x456.reg_advanced)) {
return 8;
} else {
return data->ngpios;
}
}
static unsigned int sx150x_maybe_swizzle(struct sx150x_pinctrl *pctl,
unsigned int reg, unsigned int val)
{
unsigned int a, b;
const struct sx150x_device_data *data = pctl->data;
if (reg == data->reg_sense &&
data->ngpios == 16 &&
(data->model == SX150X_123 ||
data->model == SX150X_456)) {
a = val & 0x00ff0000;
b = val & 0x0000ff00;
val &= 0xff0000ff;
val |= b << 8;
val |= a >> 8;
}
return val;
}
static int sx150x_regmap_reg_read(void *context, unsigned int reg,
unsigned int *result)
{
int ret, n;
struct sx150x_pinctrl *pctl = context;
struct i2c_client *i2c = pctl->client;
const int width = sx150x_regmap_reg_width(pctl, reg);
unsigned int idx, val;
for (n = width, val = 0, idx = reg; n > 0; n -= 8, idx++) {
val <<= 8;
ret = i2c_smbus_read_byte_data(i2c, idx);
if (ret < 0)
return ret;
val |= ret;
}
*result = sx150x_maybe_swizzle(pctl, reg, val);
return 0;
}
static int sx150x_regmap_reg_write(void *context, unsigned int reg,
unsigned int val)
{
int ret, n;
struct sx150x_pinctrl *pctl = context;
struct i2c_client *i2c = pctl->client;
const int width = sx150x_regmap_reg_width(pctl, reg);
val = sx150x_maybe_swizzle(pctl, reg, val);
n = (width - 1) & ~7;
do {
const u8 byte = (val >> n) & 0xff;
ret = i2c_smbus_write_byte_data(i2c, reg, byte);
if (ret < 0)
return ret;
reg++;
n -= 8;
} while (n >= 0);
return 0;
}
static bool sx150x_reg_volatile(struct device *dev, unsigned int reg)
{
struct sx150x_pinctrl *pctl = i2c_get_clientdata(to_i2c_client(dev));
return reg == pctl->data->reg_irq_src || reg == pctl->data->reg_data;
}
static int sx150x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static const u32 i2c_funcs = I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WRITE_WORD_DATA;
struct device *dev = &client->dev;
struct sx150x_pinctrl *pctl;
int ret;
if (!i2c_check_functionality(client->adapter, i2c_funcs))
return -ENOSYS;
pctl = devm_kzalloc(dev, sizeof(*pctl), GFP_KERNEL);
if (!pctl)
return -ENOMEM;
i2c_set_clientdata(client, pctl);
pctl->dev = dev;
pctl->client = client;
if (dev->of_node)
pctl->data = of_device_get_match_data(dev);
else
pctl->data = (struct sx150x_device_data *)id->driver_data;
if (!pctl->data)
return -EINVAL;
pctl->regmap = devm_regmap_init(dev, NULL, pctl,
&sx150x_regmap_config);
if (IS_ERR(pctl->regmap)) {
ret = PTR_ERR(pctl->regmap);
dev_err(dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
mutex_init(&pctl->lock);
ret = sx150x_init_hw(pctl);
if (ret)
return ret;
pctl->gpio.label = devm_kstrdup(dev, client->name, GFP_KERNEL);
pctl->gpio.base = -1;
pctl->gpio.ngpio = pctl->data->npins;
pctl->gpio.get_direction = sx150x_gpio_get_direction;
pctl->gpio.direction_input = sx150x_gpio_direction_input;
pctl->gpio.direction_output = sx150x_gpio_direction_output;
pctl->gpio.get = sx150x_gpio_get;
pctl->gpio.set = sx150x_gpio_set;
pctl->gpio.set_config = gpiochip_generic_config;
pctl->gpio.parent = dev;
#ifdef CONFIG_OF_GPIO
pctl->gpio.of_node = dev->of_node;
#endif
pctl->gpio.can_sleep = true;
if (pctl->data->model != SX150X_789)
pctl->gpio.set_multiple = sx150x_gpio_set_multiple;
ret = devm_gpiochip_add_data(dev, &pctl->gpio, pctl);
if (ret)
return ret;
if (client->irq > 0) {
pctl->irq_chip.name = devm_kstrdup(dev, client->name,
GFP_KERNEL);
pctl->irq_chip.irq_mask = sx150x_irq_mask;
pctl->irq_chip.irq_unmask = sx150x_irq_unmask;
pctl->irq_chip.irq_set_type = sx150x_irq_set_type;
pctl->irq_chip.irq_bus_lock = sx150x_irq_bus_lock;
pctl->irq_chip.irq_bus_sync_unlock = sx150x_irq_bus_sync_unlock;
pctl->irq.masked = ~0;
pctl->irq.sense = 0;
ret = gpiochip_irqchip_add_nested(&pctl->gpio,
&pctl->irq_chip, 0,
handle_bad_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "could not connect irqchip to gpiochip\n");
return ret;
}
ret = devm_request_threaded_irq(dev, client->irq, NULL,
sx150x_irq_thread_fn,
IRQF_ONESHOT | IRQF_SHARED |
IRQF_TRIGGER_FALLING,
pctl->irq_chip.name, pctl);
if (ret < 0)
return ret;
gpiochip_set_nested_irqchip(&pctl->gpio,
&pctl->irq_chip,
client->irq);
}
pctl->pinctrl_desc.name = "sx150x-pinctrl";
pctl->pinctrl_desc.pctlops = &sx150x_pinctrl_ops;
pctl->pinctrl_desc.confops = &sx150x_pinconf_ops;
pctl->pinctrl_desc.pins = pctl->data->pins;
pctl->pinctrl_desc.npins = pctl->data->npins;
pctl->pinctrl_desc.owner = THIS_MODULE;
pctl->pctldev = pinctrl_register(&pctl->pinctrl_desc, dev, pctl);
if (IS_ERR(pctl->pctldev)) {
dev_err(dev, "Failed to register pinctrl device\n");
return PTR_ERR(pctl->pctldev);
}
return 0;
}
static int __init sx150x_init(void)
{
return i2c_add_driver(&sx150x_driver);
}
