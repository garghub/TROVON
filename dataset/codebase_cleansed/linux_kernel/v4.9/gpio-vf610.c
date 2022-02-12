static inline void vf610_gpio_writel(u32 val, void __iomem *reg)
{
writel_relaxed(val, reg);
}
static inline u32 vf610_gpio_readl(void __iomem *reg)
{
return readl_relaxed(reg);
}
static int vf610_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct vf610_gpio_port *port = gpiochip_get_data(gc);
return !!(vf610_gpio_readl(port->gpio_base + GPIO_PDIR) & BIT(gpio));
}
static void vf610_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct vf610_gpio_port *port = gpiochip_get_data(gc);
unsigned long mask = BIT(gpio);
if (val)
vf610_gpio_writel(mask, port->gpio_base + GPIO_PSOR);
else
vf610_gpio_writel(mask, port->gpio_base + GPIO_PCOR);
}
static int vf610_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
return pinctrl_gpio_direction_input(chip->base + gpio);
}
static int vf610_gpio_direction_output(struct gpio_chip *chip, unsigned gpio,
int value)
{
vf610_gpio_set(chip, gpio, value);
return pinctrl_gpio_direction_output(chip->base + gpio);
}
static void vf610_gpio_irq_handler(struct irq_desc *desc)
{
struct vf610_gpio_port *port =
gpiochip_get_data(irq_desc_get_handler_data(desc));
struct irq_chip *chip = irq_desc_get_chip(desc);
int pin;
unsigned long irq_isfr;
chained_irq_enter(chip, desc);
irq_isfr = vf610_gpio_readl(port->base + PORT_ISFR);
for_each_set_bit(pin, &irq_isfr, VF610_GPIO_PER_PORT) {
vf610_gpio_writel(BIT(pin), port->base + PORT_ISFR);
generic_handle_irq(irq_find_mapping(port->gc.irqdomain, pin));
}
chained_irq_exit(chip, desc);
}
static void vf610_gpio_irq_ack(struct irq_data *d)
{
struct vf610_gpio_port *port =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
int gpio = d->hwirq;
vf610_gpio_writel(BIT(gpio), port->base + PORT_ISFR);
}
static int vf610_gpio_irq_set_type(struct irq_data *d, u32 type)
{
struct vf610_gpio_port *port =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
u8 irqc;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
irqc = PORT_INT_RISING_EDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
irqc = PORT_INT_FALLING_EDGE;
break;
case IRQ_TYPE_EDGE_BOTH:
irqc = PORT_INT_EITHER_EDGE;
break;
case IRQ_TYPE_LEVEL_LOW:
irqc = PORT_INT_LOGIC_ZERO;
break;
case IRQ_TYPE_LEVEL_HIGH:
irqc = PORT_INT_LOGIC_ONE;
break;
default:
return -EINVAL;
}
port->irqc[d->hwirq] = irqc;
if (type & IRQ_TYPE_LEVEL_MASK)
irq_set_handler_locked(d, handle_level_irq);
else
irq_set_handler_locked(d, handle_edge_irq);
return 0;
}
static void vf610_gpio_irq_mask(struct irq_data *d)
{
struct vf610_gpio_port *port =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
void __iomem *pcr_base = port->base + PORT_PCR(d->hwirq);
vf610_gpio_writel(0, pcr_base);
}
static void vf610_gpio_irq_unmask(struct irq_data *d)
{
struct vf610_gpio_port *port =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
void __iomem *pcr_base = port->base + PORT_PCR(d->hwirq);
vf610_gpio_writel(port->irqc[d->hwirq] << PORT_PCR_IRQC_OFFSET,
pcr_base);
}
static int vf610_gpio_irq_set_wake(struct irq_data *d, u32 enable)
{
struct vf610_gpio_port *port =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
if (enable)
enable_irq_wake(port->irq);
else
disable_irq_wake(port->irq);
return 0;
}
static int vf610_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct vf610_gpio_port *port;
struct resource *iores;
struct gpio_chip *gc;
int ret;
port = devm_kzalloc(&pdev->dev, sizeof(*port), GFP_KERNEL);
if (!port)
return -ENOMEM;
iores = platform_get_resource(pdev, IORESOURCE_MEM, 0);
port->base = devm_ioremap_resource(dev, iores);
if (IS_ERR(port->base))
return PTR_ERR(port->base);
iores = platform_get_resource(pdev, IORESOURCE_MEM, 1);
port->gpio_base = devm_ioremap_resource(dev, iores);
if (IS_ERR(port->gpio_base))
return PTR_ERR(port->gpio_base);
port->irq = platform_get_irq(pdev, 0);
if (port->irq < 0)
return port->irq;
gc = &port->gc;
gc->of_node = np;
gc->parent = dev;
gc->label = "vf610-gpio";
gc->ngpio = VF610_GPIO_PER_PORT;
gc->base = of_alias_get_id(np, "gpio") * VF610_GPIO_PER_PORT;
gc->request = gpiochip_generic_request;
gc->free = gpiochip_generic_free;
gc->direction_input = vf610_gpio_direction_input;
gc->get = vf610_gpio_get;
gc->direction_output = vf610_gpio_direction_output;
gc->set = vf610_gpio_set;
ret = gpiochip_add_data(gc, port);
if (ret < 0)
return ret;
vf610_gpio_writel(~0, port->base + PORT_ISFR);
ret = gpiochip_irqchip_add(gc, &vf610_gpio_irq_chip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "failed to add irqchip\n");
gpiochip_remove(gc);
return ret;
}
gpiochip_set_chained_irqchip(gc, &vf610_gpio_irq_chip, port->irq,
vf610_gpio_irq_handler);
return 0;
}
static int __init gpio_vf610_init(void)
{
return platform_driver_register(&vf610_gpio_driver);
}
