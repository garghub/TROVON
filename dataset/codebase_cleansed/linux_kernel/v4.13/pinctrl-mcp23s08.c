static int mcp_read(struct mcp23s08 *mcp, unsigned int reg, unsigned int *val)
{
return regmap_read(mcp->regmap, reg << mcp->reg_shift, val);
}
static int mcp_write(struct mcp23s08 *mcp, unsigned int reg, unsigned int val)
{
return regmap_write(mcp->regmap, reg << mcp->reg_shift, val);
}
static int mcp_set_mask(struct mcp23s08 *mcp, unsigned int reg,
unsigned int mask, bool enabled)
{
u16 val = enabled ? 0xffff : 0x0000;
return regmap_update_bits(mcp->regmap, reg << mcp->reg_shift,
mask, val);
}
static int mcp_set_bit(struct mcp23s08 *mcp, unsigned int reg,
unsigned int pin, bool enabled)
{
u16 mask = BIT(pin);
return mcp_set_mask(mcp, reg, mask, enabled);
}
static int mcp_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
return 0;
}
static const char *mcp_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
return NULL;
}
static int mcp_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
return -ENOTSUPP;
}
static int mcp_pinconf_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct mcp23s08 *mcp = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
unsigned int data, status;
int ret;
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
ret = mcp_read(mcp, MCP_GPPU, &data);
if (ret < 0)
return ret;
status = (data & BIT(pin)) ? 1 : 0;
break;
default:
dev_err(mcp->dev, "Invalid config param %04x\n", param);
return -ENOTSUPP;
}
*config = 0;
return status ? 0 : -EINVAL;
}
static int mcp_pinconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned int num_configs)
{
struct mcp23s08 *mcp = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
u32 arg, mask;
u16 val;
int ret = 0;
int i;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
val = arg ? 0xFFFF : 0x0000;
mask = BIT(pin);
ret = mcp_set_bit(mcp, MCP_GPPU, pin, arg);
break;
default:
dev_err(mcp->dev, "Invalid config param %04x\n", param);
return -ENOTSUPP;
}
}
return ret;
}
static int mcp23sxx_spi_write(void *context, const void *data, size_t count)
{
struct mcp23s08 *mcp = context;
struct spi_device *spi = to_spi_device(mcp->dev);
struct spi_message m;
struct spi_transfer t[2] = { { .tx_buf = &mcp->addr, .len = 1, },
{ .tx_buf = data, .len = count, }, };
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
return spi_sync(spi, &m);
}
static int mcp23sxx_spi_gather_write(void *context,
const void *reg, size_t reg_size,
const void *val, size_t val_size)
{
struct mcp23s08 *mcp = context;
struct spi_device *spi = to_spi_device(mcp->dev);
struct spi_message m;
struct spi_transfer t[3] = { { .tx_buf = &mcp->addr, .len = 1, },
{ .tx_buf = reg, .len = reg_size, },
{ .tx_buf = val, .len = val_size, }, };
spi_message_init(&m);
spi_message_add_tail(&t[0], &m);
spi_message_add_tail(&t[1], &m);
spi_message_add_tail(&t[2], &m);
return spi_sync(spi, &m);
}
static int mcp23sxx_spi_read(void *context, const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct mcp23s08 *mcp = context;
struct spi_device *spi = to_spi_device(mcp->dev);
u8 tx[2];
if (reg_size != 1)
return -EINVAL;
tx[0] = mcp->addr | 0x01;
tx[1] = *((u8 *) reg);
return spi_write_then_read(spi, tx, sizeof(tx), val, val_size);
}
static int mcp23s08_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct mcp23s08 *mcp = gpiochip_get_data(chip);
int status;
mutex_lock(&mcp->lock);
status = mcp_set_bit(mcp, MCP_IODIR, offset, true);
mutex_unlock(&mcp->lock);
return status;
}
static int mcp23s08_get(struct gpio_chip *chip, unsigned offset)
{
struct mcp23s08 *mcp = gpiochip_get_data(chip);
int status, ret;
mutex_lock(&mcp->lock);
ret = mcp_read(mcp, MCP_GPIO, &status);
if (ret < 0)
status = 0;
else
status = !!(status & (1 << offset));
mcp->cached_gpio = status;
mutex_unlock(&mcp->lock);
return status;
}
static int __mcp23s08_set(struct mcp23s08 *mcp, unsigned mask, bool value)
{
return mcp_set_mask(mcp, MCP_OLAT, mask, value);
}
static void mcp23s08_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct mcp23s08 *mcp = gpiochip_get_data(chip);
unsigned mask = BIT(offset);
mutex_lock(&mcp->lock);
__mcp23s08_set(mcp, mask, !!value);
mutex_unlock(&mcp->lock);
}
static int
mcp23s08_direction_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct mcp23s08 *mcp = gpiochip_get_data(chip);
unsigned mask = BIT(offset);
int status;
mutex_lock(&mcp->lock);
status = __mcp23s08_set(mcp, mask, value);
if (status == 0) {
status = mcp_set_mask(mcp, MCP_IODIR, mask, false);
}
mutex_unlock(&mcp->lock);
return status;
}
static irqreturn_t mcp23s08_irq(int irq, void *data)
{
struct mcp23s08 *mcp = data;
int intcap, intcon, intf, i, gpio, gpio_orig, intcap_mask, defval;
unsigned int child_irq;
bool intf_set, intcap_changed, gpio_bit_changed,
defval_changed, gpio_set;
mutex_lock(&mcp->lock);
if (mcp_read(mcp, MCP_INTF, &intf) < 0) {
mutex_unlock(&mcp->lock);
return IRQ_HANDLED;
}
if (mcp_read(mcp, MCP_INTCAP, &intcap) < 0) {
mutex_unlock(&mcp->lock);
return IRQ_HANDLED;
}
if (mcp_read(mcp, MCP_INTCON, &intcon) < 0) {
mutex_unlock(&mcp->lock);
return IRQ_HANDLED;
}
if (mcp_read(mcp, MCP_DEFVAL, &defval) < 0) {
mutex_unlock(&mcp->lock);
return IRQ_HANDLED;
}
if (mcp_read(mcp, MCP_GPIO, &gpio) < 0) {
mutex_unlock(&mcp->lock);
return IRQ_HANDLED;
}
gpio_orig = mcp->cached_gpio;
mcp->cached_gpio = gpio;
mutex_unlock(&mcp->lock);
if (intf == 0) {
return IRQ_HANDLED;
}
dev_dbg(mcp->chip.parent,
"intcap 0x%04X intf 0x%04X gpio_orig 0x%04X gpio 0x%04X\n",
intcap, intf, gpio_orig, gpio);
for (i = 0; i < mcp->chip.ngpio; i++) {
intf_set = intf & BIT(i);
if (i < 8 && intf_set)
intcap_mask = 0x00FF;
else if (i >= 8 && intf_set)
intcap_mask = 0xFF00;
else
intcap_mask = 0x00;
intcap_changed = (intcap_mask &
(intcap & BIT(i))) !=
(intcap_mask & (BIT(i) & gpio_orig));
gpio_set = BIT(i) & gpio;
gpio_bit_changed = (BIT(i) & gpio_orig) !=
(BIT(i) & gpio);
defval_changed = (BIT(i) & intcon) &&
((BIT(i) & gpio) !=
(BIT(i) & defval));
if (((gpio_bit_changed || intcap_changed) &&
(BIT(i) & mcp->irq_rise) && gpio_set) ||
((gpio_bit_changed || intcap_changed) &&
(BIT(i) & mcp->irq_fall) && !gpio_set) ||
defval_changed) {
child_irq = irq_find_mapping(mcp->chip.irqdomain, i);
handle_nested_irq(child_irq);
}
}
return IRQ_HANDLED;
}
static void mcp23s08_irq_mask(struct irq_data *data)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(data);
struct mcp23s08 *mcp = gpiochip_get_data(gc);
unsigned int pos = data->hwirq;
mcp_set_bit(mcp, MCP_GPINTEN, pos, false);
}
static void mcp23s08_irq_unmask(struct irq_data *data)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(data);
struct mcp23s08 *mcp = gpiochip_get_data(gc);
unsigned int pos = data->hwirq;
mcp_set_bit(mcp, MCP_GPINTEN, pos, true);
}
static int mcp23s08_irq_set_type(struct irq_data *data, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(data);
struct mcp23s08 *mcp = gpiochip_get_data(gc);
unsigned int pos = data->hwirq;
int status = 0;
if ((type & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
mcp_set_bit(mcp, MCP_INTCON, pos, false);
mcp->irq_rise |= BIT(pos);
mcp->irq_fall |= BIT(pos);
} else if (type & IRQ_TYPE_EDGE_RISING) {
mcp_set_bit(mcp, MCP_INTCON, pos, false);
mcp->irq_rise |= BIT(pos);
mcp->irq_fall &= ~BIT(pos);
} else if (type & IRQ_TYPE_EDGE_FALLING) {
mcp_set_bit(mcp, MCP_INTCON, pos, false);
mcp->irq_rise &= ~BIT(pos);
mcp->irq_fall |= BIT(pos);
} else if (type & IRQ_TYPE_LEVEL_HIGH) {
mcp_set_bit(mcp, MCP_INTCON, pos, true);
mcp_set_bit(mcp, MCP_DEFVAL, pos, false);
} else if (type & IRQ_TYPE_LEVEL_LOW) {
mcp_set_bit(mcp, MCP_INTCON, pos, true);
mcp_set_bit(mcp, MCP_DEFVAL, pos, true);
} else
return -EINVAL;
return status;
}
static void mcp23s08_irq_bus_lock(struct irq_data *data)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(data);
struct mcp23s08 *mcp = gpiochip_get_data(gc);
mutex_lock(&mcp->lock);
regcache_cache_only(mcp->regmap, true);
}
static void mcp23s08_irq_bus_unlock(struct irq_data *data)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(data);
struct mcp23s08 *mcp = gpiochip_get_data(gc);
regcache_cache_only(mcp->regmap, false);
regcache_sync(mcp->regmap);
mutex_unlock(&mcp->lock);
}
static int mcp23s08_irq_setup(struct mcp23s08 *mcp)
{
struct gpio_chip *chip = &mcp->chip;
int err;
unsigned long irqflags = IRQF_ONESHOT | IRQF_SHARED;
if (mcp->irq_active_high)
irqflags |= IRQF_TRIGGER_HIGH;
else
irqflags |= IRQF_TRIGGER_LOW;
err = devm_request_threaded_irq(chip->parent, mcp->irq, NULL,
mcp23s08_irq,
irqflags, dev_name(chip->parent), mcp);
if (err != 0) {
dev_err(chip->parent, "unable to request IRQ#%d: %d\n",
mcp->irq, err);
return err;
}
err = gpiochip_irqchip_add_nested(chip,
&mcp23s08_irq_chip,
0,
handle_simple_irq,
IRQ_TYPE_NONE);
if (err) {
dev_err(chip->parent,
"could not connect irqchip to gpiochip: %d\n", err);
return err;
}
gpiochip_set_nested_irqchip(chip,
&mcp23s08_irq_chip,
mcp->irq);
return 0;
}
static int __check_mcp23s08_reg_cache(struct mcp23s08 *mcp)
{
int cached[MCP23S08_CONFIG_REGS];
int err = 0, i;
for (i = 0; i < MCP23S08_CONFIG_REGS; i++) {
err = mcp_read(mcp, i, &cached[i]);
if (err)
goto out;
}
regcache_cache_bypass(mcp->regmap, true);
for (i = 0; i < MCP23S08_CONFIG_REGS; i++) {
int uncached;
err = mcp_read(mcp, i, &uncached);
if (err)
goto out;
if (uncached != cached[i]) {
dev_err(mcp->dev, "restoring reg 0x%02x from 0x%04x to 0x%04x (power-loss?)\n",
i, uncached, cached[i]);
mcp_write(mcp, i, cached[i]);
}
}
out:
if (err)
dev_err(mcp->dev, "read error: reg=%02x, err=%d", i, err);
regcache_cache_bypass(mcp->regmap, false);
return err;
}
static void mcp23s08_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
struct mcp23s08 *mcp;
char bank;
int t;
unsigned mask;
int iodir, gpio, gppu;
mcp = gpiochip_get_data(chip);
bank = '0' + ((mcp->addr >> 1) & 0x7);
mutex_lock(&mcp->lock);
t = __check_mcp23s08_reg_cache(mcp);
if (t) {
seq_printf(s, " I/O Error\n");
goto done;
}
t = mcp_read(mcp, MCP_IODIR, &iodir);
if (t) {
seq_printf(s, " I/O Error\n");
goto done;
}
t = mcp_read(mcp, MCP_GPIO, &gpio);
if (t) {
seq_printf(s, " I/O Error\n");
goto done;
}
t = mcp_read(mcp, MCP_GPPU, &gppu);
if (t) {
seq_printf(s, " I/O Error\n");
goto done;
}
for (t = 0, mask = BIT(0); t < chip->ngpio; t++, mask <<= 1) {
const char *label;
label = gpiochip_is_requested(chip, t);
if (!label)
continue;
seq_printf(s, " gpio-%-3d P%c.%d (%-12s) %s %s %s",
chip->base + t, bank, t, label,
(iodir & mask) ? "in " : "out",
(gpio & mask) ? "hi" : "lo",
(gppu & mask) ? "up" : " ");
seq_puts(s, "\n");
}
done:
mutex_unlock(&mcp->lock);
}
static int mcp23s08_probe_one(struct mcp23s08 *mcp, struct device *dev,
void *data, unsigned addr, unsigned type,
unsigned int base, int cs)
{
int status, ret;
bool mirror = false;
mutex_init(&mcp->lock);
mcp->dev = dev;
mcp->addr = addr;
mcp->irq_active_high = false;
mcp->chip.direction_input = mcp23s08_direction_input;
mcp->chip.get = mcp23s08_get;
mcp->chip.direction_output = mcp23s08_direction_output;
mcp->chip.set = mcp23s08_set;
mcp->chip.dbg_show = mcp23s08_dbg_show;
#ifdef CONFIG_OF_GPIO
mcp->chip.of_gpio_n_cells = 2;
mcp->chip.of_node = dev->of_node;
#endif
switch (type) {
#ifdef CONFIG_SPI_MASTER
case MCP_TYPE_S08:
mcp->regmap = devm_regmap_init(dev, &mcp23sxx_spi_regmap, mcp,
&mcp23x08_regmap);
mcp->reg_shift = 0;
mcp->chip.ngpio = 8;
mcp->chip.label = "mcp23s08";
break;
case MCP_TYPE_S17:
mcp->regmap = devm_regmap_init(dev, &mcp23sxx_spi_regmap, mcp,
&mcp23x17_regmap);
mcp->reg_shift = 1;
mcp->chip.ngpio = 16;
mcp->chip.label = "mcp23s17";
break;
case MCP_TYPE_S18:
mcp->regmap = devm_regmap_init(dev, &mcp23sxx_spi_regmap, mcp,
&mcp23x17_regmap);
mcp->reg_shift = 1;
mcp->chip.ngpio = 16;
mcp->chip.label = "mcp23s18";
break;
#endif
#if IS_ENABLED(CONFIG_I2C)
case MCP_TYPE_008:
mcp->regmap = devm_regmap_init_i2c(data, &mcp23x08_regmap);
mcp->reg_shift = 0;
mcp->chip.ngpio = 8;
mcp->chip.label = "mcp23008";
break;
case MCP_TYPE_017:
mcp->regmap = devm_regmap_init_i2c(data, &mcp23x17_regmap);
mcp->reg_shift = 1;
mcp->chip.ngpio = 16;
mcp->chip.label = "mcp23017";
break;
#endif
default:
dev_err(dev, "invalid device type (%d)\n", type);
return -EINVAL;
}
if (IS_ERR(mcp->regmap))
return PTR_ERR(mcp->regmap);
mcp->chip.base = base;
mcp->chip.can_sleep = true;
mcp->chip.parent = dev;
mcp->chip.owner = THIS_MODULE;
ret = mcp_read(mcp, MCP_IOCON, &status);
if (ret < 0)
goto fail;
mcp->irq_controller =
device_property_read_bool(dev, "interrupt-controller");
if (mcp->irq && mcp->irq_controller) {
mcp->irq_active_high =
device_property_read_bool(dev,
"microchip,irq-active-high");
mirror = device_property_read_bool(dev, "microchip,irq-mirror");
}
if ((status & IOCON_SEQOP) || !(status & IOCON_HAEN) || mirror ||
mcp->irq_active_high) {
status &= ~(IOCON_SEQOP | (IOCON_SEQOP << 8));
status |= IOCON_HAEN | (IOCON_HAEN << 8);
if (mcp->irq_active_high)
status |= IOCON_INTPOL | (IOCON_INTPOL << 8);
else
status &= ~(IOCON_INTPOL | (IOCON_INTPOL << 8));
if (mirror)
status |= IOCON_MIRROR | (IOCON_MIRROR << 8);
if (type == MCP_TYPE_S18)
status |= IOCON_INTCC | (IOCON_INTCC << 8);
ret = mcp_write(mcp, MCP_IOCON, status);
if (ret < 0)
goto fail;
}
ret = devm_gpiochip_add_data(dev, &mcp->chip, mcp);
if (ret < 0)
goto fail;
if (mcp->irq && mcp->irq_controller) {
ret = mcp23s08_irq_setup(mcp);
if (ret)
goto fail;
}
mcp->pinctrl_desc.name = "mcp23xxx-pinctrl";
mcp->pinctrl_desc.pctlops = &mcp_pinctrl_ops;
mcp->pinctrl_desc.confops = &mcp_pinconf_ops;
mcp->pinctrl_desc.npins = mcp->chip.ngpio;
if (mcp->pinctrl_desc.npins == 8)
mcp->pinctrl_desc.pins = mcp23x08_pins;
else if (mcp->pinctrl_desc.npins == 16)
mcp->pinctrl_desc.pins = mcp23x17_pins;
mcp->pinctrl_desc.owner = THIS_MODULE;
mcp->pctldev = devm_pinctrl_register(dev, &mcp->pinctrl_desc, mcp);
if (IS_ERR(mcp->pctldev)) {
ret = PTR_ERR(mcp->pctldev);
goto fail;
}
fail:
if (ret < 0)
dev_dbg(dev, "can't setup chip %d, --> %d\n", addr, ret);
return ret;
}
static int mcp230xx_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mcp23s08_platform_data *pdata, local_pdata;
struct mcp23s08 *mcp;
int status;
pdata = dev_get_platdata(&client->dev);
if (!pdata) {
pdata = &local_pdata;
pdata->base = -1;
}
mcp = devm_kzalloc(&client->dev, sizeof(*mcp), GFP_KERNEL);
if (!mcp)
return -ENOMEM;
mcp->irq = client->irq;
status = mcp23s08_probe_one(mcp, &client->dev, client, client->addr,
id->driver_data, pdata->base, 0);
if (status)
return status;
i2c_set_clientdata(client, mcp);
return 0;
}
static int __init mcp23s08_i2c_init(void)
{
return i2c_add_driver(&mcp230xx_driver);
}
static void mcp23s08_i2c_exit(void)
{
i2c_del_driver(&mcp230xx_driver);
}
static int __init mcp23s08_i2c_init(void) { return 0; }
static void mcp23s08_i2c_exit(void) { }
static int mcp23s08_probe(struct spi_device *spi)
{
struct mcp23s08_platform_data *pdata, local_pdata;
unsigned addr;
int chips = 0;
struct mcp23s08_driver_data *data;
int status, type;
unsigned ngpio = 0;
const struct of_device_id *match;
match = of_match_device(of_match_ptr(mcp23s08_spi_of_match), &spi->dev);
if (match)
type = (int)(uintptr_t)match->data;
else
type = spi_get_device_id(spi)->driver_data;
pdata = dev_get_platdata(&spi->dev);
if (!pdata) {
pdata = &local_pdata;
pdata->base = -1;
status = device_property_read_u32(&spi->dev,
"microchip,spi-present-mask", &pdata->spi_present_mask);
if (status) {
status = device_property_read_u32(&spi->dev,
"mcp,spi-present-mask",
&pdata->spi_present_mask);
if (status) {
dev_err(&spi->dev, "missing spi-present-mask");
return -ENODEV;
}
}
}
if (!pdata->spi_present_mask || pdata->spi_present_mask > 0xff) {
dev_err(&spi->dev, "invalid spi-present-mask");
return -ENODEV;
}
for (addr = 0; addr < MCP_MAX_DEV_PER_CS; addr++) {
if (pdata->spi_present_mask & BIT(addr))
chips++;
}
if (!chips)
return -ENODEV;
data = devm_kzalloc(&spi->dev,
sizeof(*data) + chips * sizeof(struct mcp23s08),
GFP_KERNEL);
if (!data)
return -ENOMEM;
spi_set_drvdata(spi, data);
for (addr = 0; addr < MCP_MAX_DEV_PER_CS; addr++) {
if (!(pdata->spi_present_mask & BIT(addr)))
continue;
chips--;
data->mcp[addr] = &data->chip[chips];
data->mcp[addr]->irq = spi->irq;
status = mcp23s08_probe_one(data->mcp[addr], &spi->dev, spi,
0x40 | (addr << 1), type,
pdata->base, addr);
if (status < 0)
return status;
if (pdata->base != -1)
pdata->base += data->mcp[addr]->chip.ngpio;
ngpio += data->mcp[addr]->chip.ngpio;
}
data->ngpio = ngpio;
return 0;
}
static int __init mcp23s08_spi_init(void)
{
return spi_register_driver(&mcp23s08_driver);
}
static void mcp23s08_spi_exit(void)
{
spi_unregister_driver(&mcp23s08_driver);
}
static int __init mcp23s08_spi_init(void) { return 0; }
static void mcp23s08_spi_exit(void) { }
static int __init mcp23s08_init(void)
{
int ret;
ret = mcp23s08_spi_init();
if (ret)
goto spi_fail;
ret = mcp23s08_i2c_init();
if (ret)
goto i2c_fail;
return 0;
i2c_fail:
mcp23s08_spi_exit();
spi_fail:
return ret;
}
static void __exit mcp23s08_exit(void)
{
mcp23s08_spi_exit();
mcp23s08_i2c_exit();
}
