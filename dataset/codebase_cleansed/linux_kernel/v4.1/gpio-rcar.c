static inline u32 gpio_rcar_read(struct gpio_rcar_priv *p, int offs)
{
return ioread32(p->base + offs);
}
static inline void gpio_rcar_write(struct gpio_rcar_priv *p, int offs,
u32 value)
{
iowrite32(value, p->base + offs);
}
static void gpio_rcar_modify_bit(struct gpio_rcar_priv *p, int offs,
int bit, bool value)
{
u32 tmp = gpio_rcar_read(p, offs);
if (value)
tmp |= BIT(bit);
else
tmp &= ~BIT(bit);
gpio_rcar_write(p, offs, tmp);
}
static void gpio_rcar_irq_disable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct gpio_rcar_priv *p = container_of(gc, struct gpio_rcar_priv,
gpio_chip);
gpio_rcar_write(p, INTMSK, ~BIT(irqd_to_hwirq(d)));
}
static void gpio_rcar_irq_enable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct gpio_rcar_priv *p = container_of(gc, struct gpio_rcar_priv,
gpio_chip);
gpio_rcar_write(p, MSKCLR, BIT(irqd_to_hwirq(d)));
}
static void gpio_rcar_config_interrupt_input_mode(struct gpio_rcar_priv *p,
unsigned int hwirq,
bool active_high_rising_edge,
bool level_trigger,
bool both)
{
unsigned long flags;
spin_lock_irqsave(&p->lock, flags);
gpio_rcar_modify_bit(p, POSNEG, hwirq, !active_high_rising_edge);
gpio_rcar_modify_bit(p, EDGLEVEL, hwirq, !level_trigger);
if (p->config.has_both_edge_trigger)
gpio_rcar_modify_bit(p, BOTHEDGE, hwirq, both);
gpio_rcar_modify_bit(p, IOINTSEL, hwirq, true);
if (!level_trigger)
gpio_rcar_write(p, INTCLR, BIT(hwirq));
spin_unlock_irqrestore(&p->lock, flags);
}
static int gpio_rcar_irq_set_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct gpio_rcar_priv *p = container_of(gc, struct gpio_rcar_priv,
gpio_chip);
unsigned int hwirq = irqd_to_hwirq(d);
dev_dbg(&p->pdev->dev, "sense irq = %d, type = %d\n", hwirq, type);
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_LEVEL_HIGH:
gpio_rcar_config_interrupt_input_mode(p, hwirq, true, true,
false);
break;
case IRQ_TYPE_LEVEL_LOW:
gpio_rcar_config_interrupt_input_mode(p, hwirq, false, true,
false);
break;
case IRQ_TYPE_EDGE_RISING:
gpio_rcar_config_interrupt_input_mode(p, hwirq, true, false,
false);
break;
case IRQ_TYPE_EDGE_FALLING:
gpio_rcar_config_interrupt_input_mode(p, hwirq, false, false,
false);
break;
case IRQ_TYPE_EDGE_BOTH:
if (!p->config.has_both_edge_trigger)
return -EINVAL;
gpio_rcar_config_interrupt_input_mode(p, hwirq, true, false,
true);
break;
default:
return -EINVAL;
}
return 0;
}
static int gpio_rcar_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct gpio_rcar_priv *p = container_of(gc, struct gpio_rcar_priv,
gpio_chip);
irq_set_irq_wake(p->irq_parent, on);
if (!p->clk)
return 0;
if (on)
clk_enable(p->clk);
else
clk_disable(p->clk);
return 0;
}
static irqreturn_t gpio_rcar_irq_handler(int irq, void *dev_id)
{
struct gpio_rcar_priv *p = dev_id;
u32 pending;
unsigned int offset, irqs_handled = 0;
while ((pending = gpio_rcar_read(p, INTDT) &
gpio_rcar_read(p, INTMSK))) {
offset = __ffs(pending);
gpio_rcar_write(p, INTCLR, BIT(offset));
generic_handle_irq(irq_find_mapping(p->gpio_chip.irqdomain,
offset));
irqs_handled++;
}
return irqs_handled ? IRQ_HANDLED : IRQ_NONE;
}
static inline struct gpio_rcar_priv *gpio_to_priv(struct gpio_chip *chip)
{
return container_of(chip, struct gpio_rcar_priv, gpio_chip);
}
static void gpio_rcar_config_general_input_output_mode(struct gpio_chip *chip,
unsigned int gpio,
bool output)
{
struct gpio_rcar_priv *p = gpio_to_priv(chip);
unsigned long flags;
spin_lock_irqsave(&p->lock, flags);
gpio_rcar_modify_bit(p, POSNEG, gpio, false);
gpio_rcar_modify_bit(p, IOINTSEL, gpio, false);
gpio_rcar_modify_bit(p, INOUTSEL, gpio, output);
spin_unlock_irqrestore(&p->lock, flags);
}
static int gpio_rcar_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void gpio_rcar_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->base + offset);
gpio_rcar_config_general_input_output_mode(chip, offset, false);
}
static int gpio_rcar_direction_input(struct gpio_chip *chip, unsigned offset)
{
gpio_rcar_config_general_input_output_mode(chip, offset, false);
return 0;
}
static int gpio_rcar_get(struct gpio_chip *chip, unsigned offset)
{
u32 bit = BIT(offset);
if (gpio_rcar_read(gpio_to_priv(chip), INOUTSEL) & bit)
return !!(gpio_rcar_read(gpio_to_priv(chip), OUTDT) & bit);
else
return !!(gpio_rcar_read(gpio_to_priv(chip), INDT) & bit);
}
static void gpio_rcar_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct gpio_rcar_priv *p = gpio_to_priv(chip);
unsigned long flags;
spin_lock_irqsave(&p->lock, flags);
gpio_rcar_modify_bit(p, OUTDT, offset, value);
spin_unlock_irqrestore(&p->lock, flags);
}
static int gpio_rcar_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
gpio_rcar_set(chip, offset, value);
gpio_rcar_config_general_input_output_mode(chip, offset, true);
return 0;
}
static int gpio_rcar_parse_pdata(struct gpio_rcar_priv *p)
{
struct gpio_rcar_config *pdata = dev_get_platdata(&p->pdev->dev);
struct device_node *np = p->pdev->dev.of_node;
struct of_phandle_args args;
int ret;
if (pdata) {
p->config = *pdata;
} else if (IS_ENABLED(CONFIG_OF) && np) {
const struct of_device_id *match;
const struct gpio_rcar_info *info;
match = of_match_node(gpio_rcar_of_table, np);
if (!match)
return -EINVAL;
info = match->data;
ret = of_parse_phandle_with_fixed_args(np, "gpio-ranges", 3, 0,
&args);
p->config.number_of_pins = ret == 0 ? args.args[2]
: RCAR_MAX_GPIO_PER_BANK;
p->config.gpio_base = -1;
p->config.has_both_edge_trigger = info->has_both_edge_trigger;
}
if (p->config.number_of_pins == 0 ||
p->config.number_of_pins > RCAR_MAX_GPIO_PER_BANK) {
dev_warn(&p->pdev->dev,
"Invalid number of gpio lines %u, using %u\n",
p->config.number_of_pins, RCAR_MAX_GPIO_PER_BANK);
p->config.number_of_pins = RCAR_MAX_GPIO_PER_BANK;
}
return 0;
}
static int gpio_rcar_probe(struct platform_device *pdev)
{
struct gpio_rcar_priv *p;
struct resource *io, *irq;
struct gpio_chip *gpio_chip;
struct irq_chip *irq_chip;
struct device *dev = &pdev->dev;
const char *name = dev_name(dev);
int ret;
p = devm_kzalloc(dev, sizeof(*p), GFP_KERNEL);
if (!p)
return -ENOMEM;
p->pdev = pdev;
spin_lock_init(&p->lock);
ret = gpio_rcar_parse_pdata(p);
if (ret < 0)
return ret;
platform_set_drvdata(pdev, p);
p->clk = devm_clk_get(dev, NULL);
if (IS_ERR(p->clk)) {
dev_warn(dev, "unable to get clock\n");
p->clk = NULL;
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
io = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!io || !irq) {
dev_err(dev, "missing IRQ or IOMEM\n");
ret = -EINVAL;
goto err0;
}
p->base = devm_ioremap_nocache(dev, io->start, resource_size(io));
if (!p->base) {
dev_err(dev, "failed to remap I/O memory\n");
ret = -ENXIO;
goto err0;
}
gpio_chip = &p->gpio_chip;
gpio_chip->request = gpio_rcar_request;
gpio_chip->free = gpio_rcar_free;
gpio_chip->direction_input = gpio_rcar_direction_input;
gpio_chip->get = gpio_rcar_get;
gpio_chip->direction_output = gpio_rcar_direction_output;
gpio_chip->set = gpio_rcar_set;
gpio_chip->label = name;
gpio_chip->dev = dev;
gpio_chip->owner = THIS_MODULE;
gpio_chip->base = p->config.gpio_base;
gpio_chip->ngpio = p->config.number_of_pins;
irq_chip = &p->irq_chip;
irq_chip->name = name;
irq_chip->irq_mask = gpio_rcar_irq_disable;
irq_chip->irq_unmask = gpio_rcar_irq_enable;
irq_chip->irq_set_type = gpio_rcar_irq_set_type;
irq_chip->irq_set_wake = gpio_rcar_irq_set_wake;
irq_chip->flags = IRQCHIP_SET_TYPE_MASKED | IRQCHIP_MASK_ON_SUSPEND;
ret = gpiochip_add(gpio_chip);
if (ret) {
dev_err(dev, "failed to add GPIO controller\n");
goto err0;
}
ret = gpiochip_irqchip_add(gpio_chip, irq_chip, p->config.irq_base,
handle_level_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "cannot add irqchip\n");
goto err1;
}
p->irq_parent = irq->start;
if (devm_request_irq(dev, irq->start, gpio_rcar_irq_handler,
IRQF_SHARED, name, p)) {
dev_err(dev, "failed to request IRQ\n");
ret = -ENOENT;
goto err1;
}
dev_info(dev, "driving %d GPIOs\n", p->config.number_of_pins);
if (p->config.irq_base) {
ret = irq_find_mapping(gpio_chip->irqdomain, 0);
if (p->config.irq_base != ret)
dev_warn(dev, "irq base mismatch (%u/%u)\n",
p->config.irq_base, ret);
}
if (p->config.pctl_name) {
ret = gpiochip_add_pin_range(gpio_chip, p->config.pctl_name, 0,
gpio_chip->base, gpio_chip->ngpio);
if (ret < 0)
dev_warn(dev, "failed to add pin range\n");
}
return 0;
err1:
gpiochip_remove(gpio_chip);
err0:
pm_runtime_put(dev);
pm_runtime_disable(dev);
return ret;
}
static int gpio_rcar_remove(struct platform_device *pdev)
{
struct gpio_rcar_priv *p = platform_get_drvdata(pdev);
gpiochip_remove(&p->gpio_chip);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
