static void ep93xx_gpio_update_int_params(unsigned port)
{
BUG_ON(port > 2);
writeb_relaxed(0, EP93XX_GPIO_REG(int_en_register_offset[port]));
writeb_relaxed(gpio_int_type2[port],
EP93XX_GPIO_REG(int_type2_register_offset[port]));
writeb_relaxed(gpio_int_type1[port],
EP93XX_GPIO_REG(int_type1_register_offset[port]));
writeb(gpio_int_unmasked[port] & gpio_int_enabled[port],
EP93XX_GPIO_REG(int_en_register_offset[port]));
}
static void ep93xx_gpio_int_debounce(unsigned int irq, bool enable)
{
int line = irq_to_gpio(irq);
int port = line >> 3;
int port_mask = 1 << (line & 7);
if (enable)
gpio_int_debounce[port] |= port_mask;
else
gpio_int_debounce[port] &= ~port_mask;
writeb(gpio_int_debounce[port],
EP93XX_GPIO_REG(int_debounce_register_offset[port]));
}
static void ep93xx_gpio_ab_irq_handler(struct irq_desc *desc)
{
unsigned char status;
int i;
status = readb(EP93XX_GPIO_A_INT_STATUS);
for (i = 0; i < 8; i++) {
if (status & (1 << i)) {
int gpio_irq = gpio_to_irq(EP93XX_GPIO_LINE_A(0)) + i;
generic_handle_irq(gpio_irq);
}
}
status = readb(EP93XX_GPIO_B_INT_STATUS);
for (i = 0; i < 8; i++) {
if (status & (1 << i)) {
int gpio_irq = gpio_to_irq(EP93XX_GPIO_LINE_B(0)) + i;
generic_handle_irq(gpio_irq);
}
}
}
static void ep93xx_gpio_f_irq_handler(struct irq_desc *desc)
{
unsigned int irq = irq_desc_get_irq(desc);
int port_f_idx = ((irq + 1) & 7) ^ 4;
int gpio_irq = gpio_to_irq(EP93XX_GPIO_LINE_F(0)) + port_f_idx;
generic_handle_irq(gpio_irq);
}
static void ep93xx_gpio_irq_ack(struct irq_data *d)
{
int line = irq_to_gpio(d->irq);
int port = line >> 3;
int port_mask = 1 << (line & 7);
if (irqd_get_trigger_type(d) == IRQ_TYPE_EDGE_BOTH) {
gpio_int_type2[port] ^= port_mask;
ep93xx_gpio_update_int_params(port);
}
writeb(port_mask, EP93XX_GPIO_REG(eoi_register_offset[port]));
}
static void ep93xx_gpio_irq_mask_ack(struct irq_data *d)
{
int line = irq_to_gpio(d->irq);
int port = line >> 3;
int port_mask = 1 << (line & 7);
if (irqd_get_trigger_type(d) == IRQ_TYPE_EDGE_BOTH)
gpio_int_type2[port] ^= port_mask;
gpio_int_unmasked[port] &= ~port_mask;
ep93xx_gpio_update_int_params(port);
writeb(port_mask, EP93XX_GPIO_REG(eoi_register_offset[port]));
}
static void ep93xx_gpio_irq_mask(struct irq_data *d)
{
int line = irq_to_gpio(d->irq);
int port = line >> 3;
gpio_int_unmasked[port] &= ~(1 << (line & 7));
ep93xx_gpio_update_int_params(port);
}
static void ep93xx_gpio_irq_unmask(struct irq_data *d)
{
int line = irq_to_gpio(d->irq);
int port = line >> 3;
gpio_int_unmasked[port] |= 1 << (line & 7);
ep93xx_gpio_update_int_params(port);
}
static int ep93xx_gpio_irq_type(struct irq_data *d, unsigned int type)
{
const int gpio = irq_to_gpio(d->irq);
const int port = gpio >> 3;
const int port_mask = 1 << (gpio & 7);
irq_flow_handler_t handler;
gpio_direction_input(gpio);
switch (type) {
case IRQ_TYPE_EDGE_RISING:
gpio_int_type1[port] |= port_mask;
gpio_int_type2[port] |= port_mask;
handler = handle_edge_irq;
break;
case IRQ_TYPE_EDGE_FALLING:
gpio_int_type1[port] |= port_mask;
gpio_int_type2[port] &= ~port_mask;
handler = handle_edge_irq;
break;
case IRQ_TYPE_LEVEL_HIGH:
gpio_int_type1[port] &= ~port_mask;
gpio_int_type2[port] |= port_mask;
handler = handle_level_irq;
break;
case IRQ_TYPE_LEVEL_LOW:
gpio_int_type1[port] &= ~port_mask;
gpio_int_type2[port] &= ~port_mask;
handler = handle_level_irq;
break;
case IRQ_TYPE_EDGE_BOTH:
gpio_int_type1[port] |= port_mask;
if (gpio_get_value(gpio))
gpio_int_type2[port] &= ~port_mask;
else
gpio_int_type2[port] |= port_mask;
handler = handle_edge_irq;
break;
default:
return -EINVAL;
}
irq_set_handler_locked(d, handler);
gpio_int_enabled[port] |= port_mask;
ep93xx_gpio_update_int_params(port);
return 0;
}
static void ep93xx_gpio_init_irq(void)
{
int gpio_irq;
for (gpio_irq = gpio_to_irq(0);
gpio_irq <= gpio_to_irq(EP93XX_GPIO_LINE_MAX_IRQ); ++gpio_irq) {
irq_set_chip_and_handler(gpio_irq, &ep93xx_gpio_irq_chip,
handle_level_irq);
irq_clear_status_flags(gpio_irq, IRQ_NOREQUEST);
}
irq_set_chained_handler(IRQ_EP93XX_GPIO_AB,
ep93xx_gpio_ab_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO0MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO1MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO2MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO3MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO4MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO5MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO6MUX,
ep93xx_gpio_f_irq_handler);
irq_set_chained_handler(IRQ_EP93XX_GPIO7MUX,
ep93xx_gpio_f_irq_handler);
}
static int ep93xx_gpio_set_config(struct gpio_chip *chip, unsigned offset,
unsigned long config)
{
int gpio = chip->base + offset;
int irq = gpio_to_irq(gpio);
u32 debounce;
if (pinconf_to_config_param(config) != PIN_CONFIG_INPUT_DEBOUNCE)
return -ENOTSUPP;
if (irq < 0)
return -EINVAL;
debounce = pinconf_to_config_argument(config);
ep93xx_gpio_int_debounce(irq, debounce ? true : false);
return 0;
}
static int ep93xx_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
if (gpio > EP93XX_GPIO_LINE_MAX_IRQ)
return -EINVAL;
return 64 + gpio;
}
static int ep93xx_gpio_add_bank(struct gpio_chip *gc, struct device *dev,
void __iomem *mmio_base, struct ep93xx_gpio_bank *bank)
{
void __iomem *data = mmio_base + bank->data;
void __iomem *dir = mmio_base + bank->dir;
int err;
err = bgpio_init(gc, dev, 1, data, NULL, NULL, dir, NULL, 0);
if (err)
return err;
gc->label = bank->label;
gc->base = bank->base;
if (bank->has_debounce) {
gc->set_config = ep93xx_gpio_set_config;
gc->to_irq = ep93xx_gpio_to_irq;
}
return devm_gpiochip_add_data(dev, gc, NULL);
}
static int ep93xx_gpio_probe(struct platform_device *pdev)
{
struct ep93xx_gpio *ep93xx_gpio;
struct resource *res;
int i;
struct device *dev = &pdev->dev;
ep93xx_gpio = devm_kzalloc(dev, sizeof(struct ep93xx_gpio), GFP_KERNEL);
if (!ep93xx_gpio)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ep93xx_gpio->mmio_base = devm_ioremap_resource(dev, res);
if (IS_ERR(ep93xx_gpio->mmio_base))
return PTR_ERR(ep93xx_gpio->mmio_base);
for (i = 0; i < ARRAY_SIZE(ep93xx_gpio_banks); i++) {
struct gpio_chip *gc = &ep93xx_gpio->gc[i];
struct ep93xx_gpio_bank *bank = &ep93xx_gpio_banks[i];
if (ep93xx_gpio_add_bank(gc, &pdev->dev,
ep93xx_gpio->mmio_base, bank))
dev_warn(&pdev->dev, "Unable to add gpio bank %s\n",
bank->label);
}
ep93xx_gpio_init_irq();
return 0;
}
static int __init ep93xx_gpio_init(void)
{
return platform_driver_register(&ep93xx_gpio_driver);
}
