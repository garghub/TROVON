static int xlp_gpio_get_reg(void __iomem *addr, unsigned gpio)
{
u32 pos, regset;
pos = gpio % XLP_GPIO_REGSZ;
regset = (gpio / XLP_GPIO_REGSZ) * 4;
return !!(readl(addr + regset) & BIT(pos));
}
static void xlp_gpio_set_reg(void __iomem *addr, unsigned gpio, int state)
{
u32 value, pos, regset;
pos = gpio % XLP_GPIO_REGSZ;
regset = (gpio / XLP_GPIO_REGSZ) * 4;
value = readl(addr + regset);
if (state)
value |= BIT(pos);
else
value &= ~BIT(pos);
writel(value, addr + regset);
}
static void xlp_gpio_irq_disable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
xlp_gpio_set_reg(priv->gpio_intr_en, d->hwirq, 0x0);
__clear_bit(d->hwirq, priv->gpio_enabled_mask);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void xlp_gpio_irq_mask_ack(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
xlp_gpio_set_reg(priv->gpio_intr_en, d->hwirq, 0x0);
xlp_gpio_set_reg(priv->gpio_intr_stat, d->hwirq, 0x1);
__clear_bit(d->hwirq, priv->gpio_enabled_mask);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void xlp_gpio_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
xlp_gpio_set_reg(priv->gpio_intr_en, d->hwirq, 0x1);
__set_bit(d->hwirq, priv->gpio_enabled_mask);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int xlp_gpio_set_irq_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
int pol, irq_type;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
irq_type = XLP_GPIO_IRQ_TYPE_EDGE;
pol = XLP_GPIO_IRQ_POL_HIGH;
break;
case IRQ_TYPE_EDGE_FALLING:
irq_type = XLP_GPIO_IRQ_TYPE_EDGE;
pol = XLP_GPIO_IRQ_POL_LOW;
break;
case IRQ_TYPE_LEVEL_HIGH:
irq_type = XLP_GPIO_IRQ_TYPE_LVL;
pol = XLP_GPIO_IRQ_POL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
irq_type = XLP_GPIO_IRQ_TYPE_LVL;
pol = XLP_GPIO_IRQ_POL_LOW;
break;
default:
return -EINVAL;
}
xlp_gpio_set_reg(priv->gpio_intr_type, d->hwirq, irq_type);
xlp_gpio_set_reg(priv->gpio_intr_pol, d->hwirq, pol);
return 0;
}
static void xlp_gpio_generic_handler(struct irq_desc *desc)
{
struct xlp_gpio_priv *priv = irq_desc_get_handler_data(desc);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
int gpio, regoff;
u32 gpio_stat;
regoff = -1;
gpio_stat = 0;
chained_irq_enter(irqchip, desc);
for_each_set_bit(gpio, priv->gpio_enabled_mask, XLP_MAX_NR_GPIO) {
if (regoff != gpio / XLP_GPIO_REGSZ) {
regoff = gpio / XLP_GPIO_REGSZ;
gpio_stat = readl(priv->gpio_intr_stat + regoff * 4);
}
if (gpio_stat & BIT(gpio % XLP_GPIO_REGSZ))
generic_handle_irq(irq_find_mapping(
priv->chip.irqdomain, gpio));
}
chained_irq_exit(irqchip, desc);
}
static int xlp_gpio_dir_output(struct gpio_chip *gc, unsigned gpio, int state)
{
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
BUG_ON(gpio >= gc->ngpio);
xlp_gpio_set_reg(priv->gpio_out_en, gpio, 0x1);
return 0;
}
static int xlp_gpio_dir_input(struct gpio_chip *gc, unsigned gpio)
{
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
BUG_ON(gpio >= gc->ngpio);
xlp_gpio_set_reg(priv->gpio_out_en, gpio, 0x0);
return 0;
}
static int xlp_gpio_get(struct gpio_chip *gc, unsigned gpio)
{
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
BUG_ON(gpio >= gc->ngpio);
return xlp_gpio_get_reg(priv->gpio_paddrv, gpio);
}
static void xlp_gpio_set(struct gpio_chip *gc, unsigned gpio, int state)
{
struct xlp_gpio_priv *priv = gpiochip_get_data(gc);
BUG_ON(gpio >= gc->ngpio);
xlp_gpio_set_reg(priv->gpio_paddrv, gpio, state);
}
static int xlp_gpio_probe(struct platform_device *pdev)
{
struct gpio_chip *gc;
struct resource *iores;
struct xlp_gpio_priv *priv;
const struct of_device_id *of_id;
void __iomem *gpio_base;
int irq_base, irq, err;
int ngpio;
u32 soc_type;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iores)
return -ENODEV;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
gpio_base = devm_ioremap_resource(&pdev->dev, iores);
if (IS_ERR(gpio_base))
return PTR_ERR(gpio_base);
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return irq;
of_id = of_match_device(xlp_gpio_of_ids, &pdev->dev);
if (!of_id) {
dev_err(&pdev->dev, "Failed to get soc type!\n");
return -ENODEV;
}
soc_type = (uintptr_t) of_id->data;
switch (soc_type) {
case XLP_GPIO_VARIANT_XLP832:
priv->gpio_out_en = gpio_base + GPIO_OUTPUT_EN;
priv->gpio_paddrv = gpio_base + GPIO_PADDRV;
priv->gpio_intr_stat = gpio_base + GPIO_INT_STAT;
priv->gpio_intr_type = gpio_base + GPIO_INT_TYPE;
priv->gpio_intr_pol = gpio_base + GPIO_INT_POL;
priv->gpio_intr_en = gpio_base + GPIO_INT_EN00;
ngpio = 41;
break;
case XLP_GPIO_VARIANT_XLP208:
case XLP_GPIO_VARIANT_XLP316:
priv->gpio_out_en = gpio_base + GPIO_OUTPUT_EN;
priv->gpio_paddrv = gpio_base + GPIO_PADDRV;
priv->gpio_intr_stat = gpio_base + GPIO_3XX_INT_STAT;
priv->gpio_intr_type = gpio_base + GPIO_3XX_INT_TYPE;
priv->gpio_intr_pol = gpio_base + GPIO_3XX_INT_POL;
priv->gpio_intr_en = gpio_base + GPIO_3XX_INT_EN00;
ngpio = (soc_type == XLP_GPIO_VARIANT_XLP208) ? 42 : 57;
break;
case XLP_GPIO_VARIANT_XLP980:
case XLP_GPIO_VARIANT_XLP532:
case GPIO_VARIANT_VULCAN:
priv->gpio_out_en = gpio_base + GPIO_9XX_OUTPUT_EN;
priv->gpio_paddrv = gpio_base + GPIO_9XX_PADDRV;
priv->gpio_intr_stat = gpio_base + GPIO_9XX_INT_STAT;
priv->gpio_intr_type = gpio_base + GPIO_9XX_INT_TYPE;
priv->gpio_intr_pol = gpio_base + GPIO_9XX_INT_POL;
priv->gpio_intr_en = gpio_base + GPIO_9XX_INT_EN00;
if (soc_type == XLP_GPIO_VARIANT_XLP980)
ngpio = 66;
else if (soc_type == XLP_GPIO_VARIANT_XLP532)
ngpio = 67;
else
ngpio = 70;
break;
default:
dev_err(&pdev->dev, "Unknown Processor type!\n");
return -ENODEV;
}
bitmap_zero(priv->gpio_enabled_mask, XLP_MAX_NR_GPIO);
gc = &priv->chip;
gc->owner = THIS_MODULE;
gc->label = dev_name(&pdev->dev);
gc->base = 0;
gc->parent = &pdev->dev;
gc->ngpio = ngpio;
gc->of_node = pdev->dev.of_node;
gc->direction_output = xlp_gpio_dir_output;
gc->direction_input = xlp_gpio_dir_input;
gc->set = xlp_gpio_set;
gc->get = xlp_gpio_get;
spin_lock_init(&priv->lock);
if (soc_type == GPIO_VARIANT_VULCAN)
irq_base = irq_alloc_descs(-1, 0, gc->ngpio, 0);
else
irq_base = irq_alloc_descs(-1, XLP_GPIO_IRQ_BASE, gc->ngpio, 0);
if (irq_base < 0) {
dev_err(&pdev->dev, "Failed to allocate IRQ numbers\n");
return irq_base;
}
err = gpiochip_add_data(gc, priv);
if (err < 0)
goto out_free_desc;
err = gpiochip_irqchip_add(gc, &xlp_gpio_irq_chip, irq_base,
handle_level_irq, IRQ_TYPE_NONE);
if (err) {
dev_err(&pdev->dev, "Could not connect irqchip to gpiochip!\n");
goto out_gpio_remove;
}
gpiochip_set_chained_irqchip(gc, &xlp_gpio_irq_chip, irq,
xlp_gpio_generic_handler);
dev_info(&pdev->dev, "registered %d GPIOs\n", gc->ngpio);
return 0;
out_gpio_remove:
gpiochip_remove(gc);
out_free_desc:
irq_free_descs(irq_base, gc->ngpio);
return err;
}
