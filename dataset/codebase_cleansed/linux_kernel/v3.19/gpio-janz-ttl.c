static int ttl_get_value(struct gpio_chip *gpio, unsigned offset)
{
struct ttl_module *mod = dev_get_drvdata(gpio->dev);
u8 *shadow;
int ret;
if (offset < 8) {
shadow = &mod->porta_shadow;
} else if (offset < 16) {
shadow = &mod->portb_shadow;
offset -= 8;
} else {
shadow = &mod->portc_shadow;
offset -= 16;
}
spin_lock(&mod->lock);
ret = *shadow & (1 << offset);
spin_unlock(&mod->lock);
return ret;
}
static void ttl_set_value(struct gpio_chip *gpio, unsigned offset, int value)
{
struct ttl_module *mod = dev_get_drvdata(gpio->dev);
void __iomem *port;
u8 *shadow;
if (offset < 8) {
port = &mod->regs->porta;
shadow = &mod->porta_shadow;
} else if (offset < 16) {
port = &mod->regs->portb;
shadow = &mod->portb_shadow;
offset -= 8;
} else {
port = &mod->regs->portc;
shadow = &mod->portc_shadow;
offset -= 16;
}
spin_lock(&mod->lock);
if (value)
*shadow |= (1 << offset);
else
*shadow &= ~(1 << offset);
iowrite16be(*shadow, port);
spin_unlock(&mod->lock);
}
static void ttl_write_reg(struct ttl_module *mod, u8 reg, u16 val)
{
iowrite16be(reg, &mod->regs->control);
iowrite16be(val, &mod->regs->control);
}
static void ttl_setup_device(struct ttl_module *mod)
{
iowrite16be(0x0000, &mod->regs->control);
iowrite16be(0x0001, &mod->regs->control);
iowrite16be(0x0000, &mod->regs->control);
ttl_write_reg(mod, PORTA_IOCTL, 0x00ff);
ttl_write_reg(mod, PORTB_IOCTL, 0x00ff);
ttl_write_reg(mod, PORTC_IOCTL, 0x000f);
ttl_write_reg(mod, PORTA_DIRECTION, 0x0000);
ttl_write_reg(mod, PORTB_DIRECTION, 0x0000);
ttl_write_reg(mod, PORTC_DIRECTION, 0x0000);
iowrite16be(0x0000, &mod->regs->porta);
iowrite16be(0x0000, &mod->regs->portb);
iowrite16be(0x0000, &mod->regs->portc);
ttl_write_reg(mod, MASTER_CONF_CTL, CONF_PAE | CONF_PBE | CONF_PCE);
}
static int ttl_probe(struct platform_device *pdev)
{
struct janz_platform_data *pdata;
struct device *dev = &pdev->dev;
struct ttl_module *mod;
struct gpio_chip *gpio;
struct resource *res;
int ret;
pdata = dev_get_platdata(&pdev->dev);
if (!pdata) {
dev_err(dev, "no platform data\n");
return -ENXIO;
}
mod = devm_kzalloc(dev, sizeof(*mod), GFP_KERNEL);
if (!mod)
return -ENOMEM;
platform_set_drvdata(pdev, mod);
spin_lock_init(&mod->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mod->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(mod->regs))
return PTR_ERR(mod->regs);
ttl_setup_device(mod);
gpio = &mod->gpio;
gpio->dev = &pdev->dev;
gpio->label = pdev->name;
gpio->get = ttl_get_value;
gpio->set = ttl_set_value;
gpio->owner = THIS_MODULE;
gpio->base = -1;
gpio->ngpio = 20;
ret = gpiochip_add(gpio);
if (ret) {
dev_err(dev, "unable to add GPIO chip\n");
return ret;
}
return 0;
}
static int ttl_remove(struct platform_device *pdev)
{
struct ttl_module *mod = platform_get_drvdata(pdev);
gpiochip_remove(&mod->gpio);
return 0;
}
