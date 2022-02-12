static inline void ts5500_set_mask(u8 mask, u8 addr)
{
u8 val = inb(addr);
val |= mask;
outb(val, addr);
}
static inline void ts5500_clear_mask(u8 mask, u8 addr)
{
u8 val = inb(addr);
val &= ~mask;
outb(val, addr);
}
static int ts5500_gpio_input(struct gpio_chip *chip, unsigned offset)
{
struct ts5500_priv *priv = gpiochip_get_data(chip);
const struct ts5500_dio line = priv->pinout[offset];
unsigned long flags;
if (line.no_input)
return -ENXIO;
if (line.no_output)
return 0;
spin_lock_irqsave(&priv->lock, flags);
ts5500_clear_mask(line.control_mask, line.control_addr);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int ts5500_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct ts5500_priv *priv = gpiochip_get_data(chip);
const struct ts5500_dio line = priv->pinout[offset];
return !!(inb(line.value_addr) & line.value_mask);
}
static int ts5500_gpio_output(struct gpio_chip *chip, unsigned offset, int val)
{
struct ts5500_priv *priv = gpiochip_get_data(chip);
const struct ts5500_dio line = priv->pinout[offset];
unsigned long flags;
if (line.no_output)
return -ENXIO;
spin_lock_irqsave(&priv->lock, flags);
if (!line.no_input)
ts5500_set_mask(line.control_mask, line.control_addr);
if (val)
ts5500_set_mask(line.value_mask, line.value_addr);
else
ts5500_clear_mask(line.value_mask, line.value_addr);
spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void ts5500_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct ts5500_priv *priv = gpiochip_get_data(chip);
const struct ts5500_dio line = priv->pinout[offset];
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (val)
ts5500_set_mask(line.value_mask, line.value_addr);
else
ts5500_clear_mask(line.value_mask, line.value_addr);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int ts5500_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct ts5500_priv *priv = gpiochip_get_data(chip);
const struct ts5500_dio *block = priv->pinout;
const struct ts5500_dio line = block[offset];
if (line.irq)
return line.irq;
if (priv->strap)
return priv->hwirq;
return -ENXIO;
}
static int ts5500_enable_irq(struct ts5500_priv *priv)
{
int ret = 0;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->hwirq == 7)
ts5500_set_mask(BIT(7), 0x7a);
else if (priv->hwirq == 6)
ts5500_set_mask(BIT(7), 0x7d);
else if (priv->hwirq == 1)
ts5500_set_mask(BIT(6), 0x7d);
else
ret = -EINVAL;
spin_unlock_irqrestore(&priv->lock, flags);
return ret;
}
static void ts5500_disable_irq(struct ts5500_priv *priv)
{
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->hwirq == 7)
ts5500_clear_mask(BIT(7), 0x7a);
else if (priv->hwirq == 6)
ts5500_clear_mask(BIT(7), 0x7d);
else if (priv->hwirq == 1)
ts5500_clear_mask(BIT(6), 0x7d);
else
dev_err(priv->gpio_chip.parent, "invalid hwirq %d\n",
priv->hwirq);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int ts5500_dio_probe(struct platform_device *pdev)
{
enum ts5500_blocks block = platform_get_device_id(pdev)->driver_data;
struct ts5500_dio_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct device *dev = &pdev->dev;
const char *name = dev_name(dev);
struct ts5500_priv *priv;
struct resource *res;
unsigned long flags;
int ret;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "missing IRQ resource\n");
return -EINVAL;
}
priv = devm_kzalloc(dev, sizeof(struct ts5500_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
priv->hwirq = res->start;
spin_lock_init(&priv->lock);
priv->gpio_chip.owner = THIS_MODULE;
priv->gpio_chip.label = name;
priv->gpio_chip.parent = dev;
priv->gpio_chip.direction_input = ts5500_gpio_input;
priv->gpio_chip.direction_output = ts5500_gpio_output;
priv->gpio_chip.get = ts5500_gpio_get;
priv->gpio_chip.set = ts5500_gpio_set;
priv->gpio_chip.to_irq = ts5500_gpio_to_irq;
priv->gpio_chip.base = -1;
if (pdata) {
priv->gpio_chip.base = pdata->base;
priv->strap = pdata->strap;
}
switch (block) {
case TS5500_DIO1:
priv->pinout = ts5500_dio1;
priv->gpio_chip.ngpio = ARRAY_SIZE(ts5500_dio1);
if (!devm_request_region(dev, 0x7a, 3, name)) {
dev_err(dev, "failed to request %s ports\n", name);
return -EBUSY;
}
break;
case TS5500_DIO2:
priv->pinout = ts5500_dio2;
priv->gpio_chip.ngpio = ARRAY_SIZE(ts5500_dio2);
if (!devm_request_region(dev, 0x7e, 2, name)) {
dev_err(dev, "failed to request %s ports\n", name);
return -EBUSY;
}
if (hex7d_reserved)
break;
if (!devm_request_region(dev, 0x7d, 1, name)) {
dev_err(dev, "failed to request %s 7D\n", name);
return -EBUSY;
}
hex7d_reserved = true;
break;
case TS5500_LCD:
case TS5600_LCD:
priv->pinout = ts5500_lcd;
priv->gpio_chip.ngpio = ARRAY_SIZE(ts5500_lcd);
if (!devm_request_region(dev, 0x72, 2, name)) {
dev_err(dev, "failed to request %s ports\n", name);
return -EBUSY;
}
if (!hex7d_reserved) {
if (!devm_request_region(dev, 0x7d, 1, name)) {
dev_err(dev, "failed to request %s 7D\n", name);
return -EBUSY;
}
hex7d_reserved = true;
}
spin_lock_irqsave(&priv->lock, flags);
ts5500_clear_mask(BIT(4), 0x7d);
spin_unlock_irqrestore(&priv->lock, flags);
break;
}
ret = gpiochip_add_data(&priv->gpio_chip, priv);
if (ret) {
dev_err(dev, "failed to register the gpio chip\n");
return ret;
}
ret = ts5500_enable_irq(priv);
if (ret) {
dev_err(dev, "invalid interrupt %d\n", priv->hwirq);
goto cleanup;
}
return 0;
cleanup:
gpiochip_remove(&priv->gpio_chip);
return ret;
}
static int ts5500_dio_remove(struct platform_device *pdev)
{
struct ts5500_priv *priv = platform_get_drvdata(pdev);
ts5500_disable_irq(priv);
gpiochip_remove(&priv->gpio_chip);
return 0;
}
