static inline struct u300_gpio *to_u300_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct u300_gpio, chip);
}
static int u300_gpio_request(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
return pinctrl_request_gpio(gpio);
}
static void u300_gpio_free(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
pinctrl_free_gpio(gpio);
}
static int u300_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
return readl(U300_PIN_REG(offset, dir)) & U300_PIN_BIT(offset);
}
static void u300_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
unsigned long flags;
u32 val;
local_irq_save(flags);
val = readl(U300_PIN_REG(offset, dor));
if (value)
writel(val | U300_PIN_BIT(offset), U300_PIN_REG(offset, dor));
else
writel(val & ~U300_PIN_BIT(offset), U300_PIN_REG(offset, dor));
local_irq_restore(flags);
}
static int u300_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
unsigned long flags;
u32 val;
local_irq_save(flags);
val = readl(U300_PIN_REG(offset, pcr));
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK << ((offset & 0x07) << 1));
writel(val, U300_PIN_REG(offset, pcr));
local_irq_restore(flags);
return 0;
}
static int u300_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
unsigned long flags;
u32 oldmode;
u32 val;
local_irq_save(flags);
val = readl(U300_PIN_REG(offset, pcr));
oldmode = val & (U300_GPIO_PXPCR_PIN_MODE_MASK <<
((offset & 0x07) << 1));
if (oldmode == 0) {
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK <<
((offset & 0x07) << 1));
val |= (U300_GPIO_PXPCR_PIN_MODE_OUTPUT_PUSH_PULL
<< ((offset & 0x07) << 1));
writel(val, U300_PIN_REG(offset, pcr));
}
u300_gpio_set(chip, offset, value);
local_irq_restore(flags);
return 0;
}
static int u300_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
int portno = offset >> 3;
struct u300_gpio_port *port = NULL;
struct list_head *p;
int retirq;
bool found = false;
list_for_each(p, &gpio->port_list) {
port = list_entry(p, struct u300_gpio_port, node);
if (port->number == portno) {
found = true;
break;
}
}
if (!found) {
dev_err(gpio->dev, "could not locate port for GPIO %d IRQ\n",
offset);
return -EINVAL;
}
retirq = irq_find_mapping(port->domain, (offset & 0x7));
dev_dbg(gpio->dev, "request IRQ for GPIO %d, return %d from port %d\n",
offset, retirq, port->number);
return retirq;
}
int u300_gpio_config_get(struct gpio_chip *chip,
unsigned offset,
unsigned long *config)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
enum pin_config_param param = (enum pin_config_param) *config;
bool biasmode;
u32 drmode;
biasmode = !!(readl(U300_PIN_REG(offset, per)) & U300_PIN_BIT(offset));
drmode = readl(U300_PIN_REG(offset, pcr));
drmode &= (U300_GPIO_PXPCR_PIN_MODE_MASK << ((offset & 0x07) << 1));
drmode >>= ((offset & 0x07) << 1);
switch (param) {
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
*config = 0;
if (biasmode)
return 0;
else
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
*config = 0;
if (!biasmode)
return 0;
else
return -EINVAL;
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
*config = 0;
if (drmode == U300_GPIO_PXPCR_PIN_MODE_OUTPUT_PUSH_PULL)
return 0;
else
return -EINVAL;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
*config = 0;
if (drmode == U300_GPIO_PXPCR_PIN_MODE_OUTPUT_OPEN_DRAIN)
return 0;
else
return -EINVAL;
break;
case PIN_CONFIG_DRIVE_OPEN_SOURCE:
*config = 0;
if (drmode == U300_GPIO_PXPCR_PIN_MODE_OUTPUT_OPEN_SOURCE)
return 0;
else
return -EINVAL;
break;
default:
break;
}
return -ENOTSUPP;
}
int u300_gpio_config_set(struct gpio_chip *chip, unsigned offset,
enum pin_config_param param)
{
struct u300_gpio *gpio = to_u300_gpio(chip);
unsigned long flags;
u32 val;
local_irq_save(flags);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
val = readl(U300_PIN_REG(offset, per));
writel(val | U300_PIN_BIT(offset), U300_PIN_REG(offset, per));
break;
case PIN_CONFIG_BIAS_PULL_UP:
val = readl(U300_PIN_REG(offset, per));
writel(val & ~U300_PIN_BIT(offset), U300_PIN_REG(offset, per));
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
val = readl(U300_PIN_REG(offset, pcr));
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK
<< ((offset & 0x07) << 1));
val |= (U300_GPIO_PXPCR_PIN_MODE_OUTPUT_PUSH_PULL
<< ((offset & 0x07) << 1));
writel(val, U300_PIN_REG(offset, pcr));
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
val = readl(U300_PIN_REG(offset, pcr));
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK
<< ((offset & 0x07) << 1));
val |= (U300_GPIO_PXPCR_PIN_MODE_OUTPUT_OPEN_DRAIN
<< ((offset & 0x07) << 1));
writel(val, U300_PIN_REG(offset, pcr));
break;
case PIN_CONFIG_DRIVE_OPEN_SOURCE:
val = readl(U300_PIN_REG(offset, pcr));
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK
<< ((offset & 0x07) << 1));
val |= (U300_GPIO_PXPCR_PIN_MODE_OUTPUT_OPEN_SOURCE
<< ((offset & 0x07) << 1));
writel(val, U300_PIN_REG(offset, pcr));
break;
default:
local_irq_restore(flags);
dev_err(gpio->dev, "illegal configuration requested\n");
return -EINVAL;
}
local_irq_restore(flags);
return 0;
}
static void u300_toggle_trigger(struct u300_gpio *gpio, unsigned offset)
{
u32 val;
val = readl(U300_PIN_REG(offset, icr));
if (u300_gpio_get(&gpio->chip, offset)) {
writel(val & ~U300_PIN_BIT(offset), U300_PIN_REG(offset, icr));
dev_dbg(gpio->dev, "next IRQ on falling edge on pin %d\n",
offset);
} else {
writel(val | U300_PIN_BIT(offset), U300_PIN_REG(offset, icr));
dev_dbg(gpio->dev, "next IRQ on rising edge on pin %d\n",
offset);
}
}
static int u300_gpio_irq_type(struct irq_data *d, unsigned trigger)
{
struct u300_gpio_port *port = irq_data_get_irq_chip_data(d);
struct u300_gpio *gpio = port->gpio;
int offset = (port->number << 3) + d->hwirq;
u32 val;
if ((trigger & IRQF_TRIGGER_RISING) &&
(trigger & IRQF_TRIGGER_FALLING)) {
dev_dbg(gpio->dev,
"trigger on both rising and falling edge on pin %d\n",
offset);
port->toggle_edge_mode |= U300_PIN_BIT(offset);
u300_toggle_trigger(gpio, offset);
} else if (trigger & IRQF_TRIGGER_RISING) {
dev_dbg(gpio->dev, "trigger on rising edge on pin %d\n",
offset);
val = readl(U300_PIN_REG(offset, icr));
writel(val | U300_PIN_BIT(offset), U300_PIN_REG(offset, icr));
port->toggle_edge_mode &= ~U300_PIN_BIT(offset);
} else if (trigger & IRQF_TRIGGER_FALLING) {
dev_dbg(gpio->dev, "trigger on falling edge on pin %d\n",
offset);
val = readl(U300_PIN_REG(offset, icr));
writel(val & ~U300_PIN_BIT(offset), U300_PIN_REG(offset, icr));
port->toggle_edge_mode &= ~U300_PIN_BIT(offset);
}
return 0;
}
static void u300_gpio_irq_enable(struct irq_data *d)
{
struct u300_gpio_port *port = irq_data_get_irq_chip_data(d);
struct u300_gpio *gpio = port->gpio;
int offset = (port->number << 3) + d->hwirq;
u32 val;
unsigned long flags;
dev_dbg(gpio->dev, "enable IRQ for hwirq %lu on port %s, offset %d\n",
d->hwirq, port->name, offset);
local_irq_save(flags);
val = readl(U300_PIN_REG(offset, ien));
writel(val | U300_PIN_BIT(offset), U300_PIN_REG(offset, ien));
local_irq_restore(flags);
}
static void u300_gpio_irq_disable(struct irq_data *d)
{
struct u300_gpio_port *port = irq_data_get_irq_chip_data(d);
struct u300_gpio *gpio = port->gpio;
int offset = (port->number << 3) + d->hwirq;
u32 val;
unsigned long flags;
local_irq_save(flags);
val = readl(U300_PIN_REG(offset, ien));
writel(val & ~U300_PIN_BIT(offset), U300_PIN_REG(offset, ien));
local_irq_restore(flags);
}
static void u300_gpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct u300_gpio_port *port = irq_get_handler_data(irq);
struct u300_gpio *gpio = port->gpio;
int pinoffset = port->number << 3;
unsigned long val;
desc->irq_data.chip->irq_ack(&desc->irq_data);
val = readl(U300_PIN_REG(pinoffset, iev));
val &= 0xFFU;
writel(val, U300_PIN_REG(pinoffset, iev));
if (val != 0) {
int irqoffset;
for_each_set_bit(irqoffset, &val, U300_GPIO_PINS_PER_PORT) {
int pin_irq = irq_find_mapping(port->domain, irqoffset);
int offset = pinoffset + irqoffset;
dev_dbg(gpio->dev, "GPIO IRQ %d on pin %d\n",
pin_irq, offset);
generic_handle_irq(pin_irq);
if (port->toggle_edge_mode & U300_PIN_BIT(offset))
u300_toggle_trigger(gpio, offset);
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
static void __init u300_gpio_init_pin(struct u300_gpio *gpio,
int offset,
const struct u300_gpio_confdata *conf)
{
if (conf->output) {
u300_gpio_direction_output(&gpio->chip, offset, conf->outval);
u300_gpio_config_set(&gpio->chip, offset,
PIN_CONFIG_BIAS_HIGH_IMPEDANCE);
u300_gpio_config_set(&gpio->chip, offset,
PIN_CONFIG_DRIVE_PUSH_PULL);
dev_dbg(gpio->dev, "set up pin %d as output, value: %d\n",
offset, conf->outval);
} else {
u300_gpio_direction_input(&gpio->chip, offset);
u300_gpio_set(&gpio->chip, offset, 0);
u300_gpio_config_set(&gpio->chip, offset, conf->bias_mode);
dev_dbg(gpio->dev, "set up pin %d as input, bias: %04x\n",
offset, conf->bias_mode);
}
}
static void __init u300_gpio_init_coh901571(struct u300_gpio *gpio)
{
int i, j;
for (i = 0; i < U300_GPIO_NUM_PORTS; i++) {
for (j = 0; j < 8; j++) {
const struct u300_gpio_confdata *conf;
int offset = (i*8) + j;
conf = &bs335_gpio_config[i][j];
u300_gpio_init_pin(gpio, offset, conf);
}
}
}
static inline void u300_gpio_free_ports(struct u300_gpio *gpio)
{
struct u300_gpio_port *port;
struct list_head *p, *n;
list_for_each_safe(p, n, &gpio->port_list) {
port = list_entry(p, struct u300_gpio_port, node);
list_del(&port->node);
if (port->domain)
irq_domain_remove(port->domain);
kfree(port);
}
}
static int __init u300_gpio_probe(struct platform_device *pdev)
{
struct u300_gpio *gpio;
struct resource *memres;
int err = 0;
int portno;
u32 val;
u32 ifr;
int i;
gpio = devm_kzalloc(&pdev->dev, sizeof(struct u300_gpio), GFP_KERNEL);
if (gpio == NULL)
return -ENOMEM;
gpio->chip = u300_gpio_chip;
gpio->chip.ngpio = U300_GPIO_NUM_PORTS * U300_GPIO_PINS_PER_PORT;
gpio->chip.dev = &pdev->dev;
gpio->chip.base = 0;
gpio->dev = &pdev->dev;
memres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gpio->base = devm_ioremap_resource(&pdev->dev, memres);
if (IS_ERR(gpio->base))
return PTR_ERR(gpio->base);
gpio->clk = devm_clk_get(gpio->dev, NULL);
if (IS_ERR(gpio->clk)) {
err = PTR_ERR(gpio->clk);
dev_err(gpio->dev, "could not get GPIO clock\n");
return err;
}
err = clk_prepare_enable(gpio->clk);
if (err) {
dev_err(gpio->dev, "could not enable GPIO clock\n");
return err;
}
dev_info(gpio->dev,
"initializing GPIO Controller COH 901 571/3\n");
gpio->stride = U300_GPIO_PORT_STRIDE;
gpio->pcr = U300_GPIO_PXPCR;
gpio->dor = U300_GPIO_PXPDOR;
gpio->dir = U300_GPIO_PXPDIR;
gpio->per = U300_GPIO_PXPER;
gpio->icr = U300_GPIO_PXICR;
gpio->ien = U300_GPIO_PXIEN;
gpio->iev = U300_GPIO_PXIEV;
ifr = U300_GPIO_PXIFR;
val = readl(gpio->base + U300_GPIO_CR);
dev_info(gpio->dev, "COH901571/3 block version: %d, " \
"number of cores: %d totalling %d pins\n",
((val & 0x000001FC) >> 2),
((val & 0x0000FE00) >> 9),
((val & 0x0000FE00) >> 9) * 8);
writel(U300_GPIO_CR_BLOCK_CLKRQ_ENABLE,
gpio->base + U300_GPIO_CR);
u300_gpio_init_coh901571(gpio);
INIT_LIST_HEAD(&gpio->port_list);
for (portno = 0 ; portno < U300_GPIO_NUM_PORTS; portno++) {
struct u300_gpio_port *port =
kmalloc(sizeof(struct u300_gpio_port), GFP_KERNEL);
if (!port) {
dev_err(gpio->dev, "out of memory\n");
err = -ENOMEM;
goto err_no_port;
}
snprintf(port->name, 8, "gpio%d", portno);
port->number = portno;
port->gpio = gpio;
port->irq = platform_get_irq(pdev, portno);
dev_dbg(gpio->dev, "register IRQ %d for port %s\n", port->irq,
port->name);
port->domain = irq_domain_add_linear(pdev->dev.of_node,
U300_GPIO_PINS_PER_PORT,
&irq_domain_simple_ops,
port);
if (!port->domain) {
err = -ENOMEM;
goto err_no_domain;
}
irq_set_chained_handler(port->irq, u300_gpio_irq_handler);
irq_set_handler_data(port->irq, port);
for (i = 0; i < U300_GPIO_PINS_PER_PORT; i++) {
int irqno = irq_create_mapping(port->domain, i);
dev_dbg(gpio->dev, "GPIO%d on port %s gets IRQ %d\n",
gpio->chip.base + (port->number << 3) + i,
port->name, irqno);
irq_set_chip_and_handler(irqno, &u300_gpio_irqchip,
handle_simple_irq);
set_irq_flags(irqno, IRQF_VALID);
irq_set_chip_data(irqno, port);
}
writel(0x0, gpio->base + portno * gpio->stride + ifr);
list_add_tail(&port->node, &gpio->port_list);
}
dev_dbg(gpio->dev, "initialized %d GPIO ports\n", portno);
#ifdef CONFIG_OF_GPIO
gpio->chip.of_node = pdev->dev.of_node;
#endif
err = gpiochip_add(&gpio->chip);
if (err) {
dev_err(gpio->dev, "unable to add gpiochip: %d\n", err);
goto err_no_chip;
}
for (i = 0; i < ARRAY_SIZE(coh901_pintable); i++) {
struct coh901_pinpair *p = &coh901_pintable[i];
err = gpiochip_add_pin_range(&gpio->chip, "pinctrl-u300",
p->offset, p->pin_base, 1);
if (err)
goto err_no_range;
}
platform_set_drvdata(pdev, gpio);
return 0;
err_no_range:
if (gpiochip_remove(&gpio->chip))
dev_err(&pdev->dev, "failed to remove gpio chip\n");
err_no_chip:
err_no_domain:
err_no_port:
u300_gpio_free_ports(gpio);
clk_disable_unprepare(gpio->clk);
dev_err(&pdev->dev, "module ERROR:%d\n", err);
return err;
}
static int __exit u300_gpio_remove(struct platform_device *pdev)
{
struct u300_gpio *gpio = platform_get_drvdata(pdev);
int err;
writel(0x00000000U, gpio->base + U300_GPIO_CR);
err = gpiochip_remove(&gpio->chip);
if (err < 0) {
dev_err(gpio->dev, "unable to remove gpiochip: %d\n", err);
return err;
}
u300_gpio_free_ports(gpio);
clk_disable_unprepare(gpio->clk);
return 0;
}
static int __init u300_gpio_init(void)
{
return platform_driver_probe(&u300_gpio_driver, u300_gpio_probe);
}
static void __exit u300_gpio_exit(void)
{
platform_driver_unregister(&u300_gpio_driver);
}
