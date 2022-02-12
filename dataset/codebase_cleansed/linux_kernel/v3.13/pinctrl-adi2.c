static inline u8 pin_to_offset(struct pinctrl_gpio_range *range, unsigned pin)
{
return pin - range->pin_base;
}
static inline u32 hwirq_to_pintbit(struct gpio_port *port, int hwirq)
{
return port->pint_assign ? BIT(hwirq) << PINT_HI_OFFSET : BIT(hwirq);
}
static struct gpio_pint *find_gpio_pint(unsigned id)
{
struct gpio_pint *pint;
int i = 0;
list_for_each_entry(pint, &adi_pint_list, node) {
if (id == i)
return pint;
i++;
}
return NULL;
}
static inline void port_setup(struct gpio_port *port, unsigned offset,
bool use_for_gpio)
{
struct gpio_port_t *regs = port->regs;
if (use_for_gpio)
writew(readw(&regs->port_fer) & ~BIT(offset),
&regs->port_fer);
else
writew(readw(&regs->port_fer) | BIT(offset), &regs->port_fer);
}
static inline void portmux_setup(struct gpio_port *port, unsigned offset,
unsigned short function)
{
struct gpio_port_t *regs = port->regs;
u32 pmux;
pmux = readl(&regs->port_mux);
pmux &= ~(0x3 << (2 * offset));
pmux |= (function & 0x3) << (2 * offset);
writel(pmux, &regs->port_mux);
}
static inline u16 get_portmux(struct gpio_port *port, unsigned offset)
{
struct gpio_port_t *regs = port->regs;
u32 pmux = readl(&regs->port_mux);
return pmux >> (2 * offset) & 0x3;
}
static void adi_gpio_ack_irq(struct irq_data *d)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *regs = port->pint->regs;
unsigned pintbit = hwirq_to_pintbit(port, d->hwirq);
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
if (irqd_get_trigger_type(d) == IRQ_TYPE_EDGE_BOTH) {
if (readl(&regs->invert_set) & pintbit)
writel(pintbit, &regs->invert_clear);
else
writel(pintbit, &regs->invert_set);
}
writel(pintbit, &regs->request);
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
}
static void adi_gpio_mask_ack_irq(struct irq_data *d)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *regs = port->pint->regs;
unsigned pintbit = hwirq_to_pintbit(port, d->hwirq);
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
if (irqd_get_trigger_type(d) == IRQ_TYPE_EDGE_BOTH) {
if (readl(&regs->invert_set) & pintbit)
writel(pintbit, &regs->invert_clear);
else
writel(pintbit, &regs->invert_set);
}
writel(pintbit, &regs->request);
writel(pintbit, &regs->mask_clear);
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
}
static void adi_gpio_mask_irq(struct irq_data *d)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *regs = port->pint->regs;
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
writel(hwirq_to_pintbit(port, d->hwirq), &regs->mask_clear);
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
}
static void adi_gpio_unmask_irq(struct irq_data *d)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *regs = port->pint->regs;
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
writel(hwirq_to_pintbit(port, d->hwirq), &regs->mask_set);
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
}
static unsigned int adi_gpio_irq_startup(struct irq_data *d)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *regs;
if (!port) {
pr_err("GPIO IRQ %d :Not exist\n", d->irq);
return -ENODEV;
}
regs = port->pint->regs;
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
port_setup(port, d->hwirq, true);
writew(BIT(d->hwirq), &port->regs->dir_clear);
writew(readw(&port->regs->inen) | BIT(d->hwirq), &port->regs->inen);
writel(hwirq_to_pintbit(port, d->hwirq), &regs->mask_set);
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static void adi_gpio_irq_shutdown(struct irq_data *d)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *regs = port->pint->regs;
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
writel(hwirq_to_pintbit(port, d->hwirq), &regs->mask_clear);
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
}
static int adi_gpio_irq_type(struct irq_data *d, unsigned int type)
{
unsigned long flags;
struct gpio_port *port = irq_data_get_irq_chip_data(d);
struct gpio_pint_regs *pint_regs;
unsigned pintmask;
unsigned int irq = d->irq;
int ret = 0;
char buf[16];
if (!port) {
pr_err("GPIO IRQ %d :Not exist\n", d->irq);
return -ENODEV;
}
pint_regs = port->pint->regs;
pintmask = hwirq_to_pintbit(port, d->hwirq);
spin_lock_irqsave(&port->lock, flags);
spin_lock(&port->pint->lock);
if (type == IRQ_TYPE_PROBE)
type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING |
IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
snprintf(buf, 16, "gpio-irq%d", irq);
port_setup(port, d->hwirq, true);
} else
goto out;
if ((type & (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_LEVEL_LOW)))
writel(pintmask, &pint_regs->invert_set);
else
writel(pintmask, &pint_regs->invert_clear);
if ((type & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
if (gpio_get_value(port->chip.base + d->hwirq))
writel(pintmask, &pint_regs->invert_set);
else
writel(pintmask, &pint_regs->invert_clear);
}
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING)) {
writel(pintmask, &pint_regs->edge_set);
__irq_set_handler_locked(irq, handle_edge_irq);
} else {
writel(pintmask, &pint_regs->edge_clear);
__irq_set_handler_locked(irq, handle_level_irq);
}
out:
spin_unlock(&port->pint->lock);
spin_unlock_irqrestore(&port->lock, flags);
return ret;
}
static int adi_gpio_set_wake(struct irq_data *d, unsigned int state)
{
struct gpio_port *port = irq_data_get_irq_chip_data(d);
if (!port || !port->pint || port->pint->irq != d->irq)
return -EINVAL;
#ifndef SEC_GCTL
adi_internal_set_wake(port->pint->irq, state);
#endif
return 0;
}
static int adi_pint_suspend(void)
{
struct gpio_pint *pint;
list_for_each_entry(pint, &adi_pint_list, node) {
writel(0xffffffff, &pint->regs->mask_clear);
pint->saved_data.assign = readl(&pint->regs->assign);
pint->saved_data.edge_set = readl(&pint->regs->edge_set);
pint->saved_data.invert_set = readl(&pint->regs->invert_set);
}
return 0;
}
static void adi_pint_resume(void)
{
struct gpio_pint *pint;
list_for_each_entry(pint, &adi_pint_list, node) {
writel(pint->saved_data.assign, &pint->regs->assign);
writel(pint->saved_data.edge_set, &pint->regs->edge_set);
writel(pint->saved_data.invert_set, &pint->regs->invert_set);
}
}
static int adi_gpio_suspend(void)
{
struct gpio_port *port;
list_for_each_entry(port, &adi_gpio_port_list, node) {
port->saved_data.fer = readw(&port->regs->port_fer);
port->saved_data.mux = readl(&port->regs->port_mux);
port->saved_data.data = readw(&port->regs->data);
port->saved_data.inen = readw(&port->regs->inen);
port->saved_data.dir = readw(&port->regs->dir_set);
}
return adi_pint_suspend();
}
static void adi_gpio_resume(void)
{
struct gpio_port *port;
adi_pint_resume();
list_for_each_entry(port, &adi_gpio_port_list, node) {
writel(port->saved_data.mux, &port->regs->port_mux);
writew(port->saved_data.fer, &port->regs->port_fer);
writew(port->saved_data.inen, &port->regs->inen);
writew(port->saved_data.data & port->saved_data.dir,
&port->regs->data_set);
writew(port->saved_data.dir, &port->regs->dir_set);
}
}
static inline void preflow_handler(struct irq_desc *desc)
{
if (desc->preflow_handler)
desc->preflow_handler(&desc->irq_data);
}
static inline void preflow_handler(struct irq_desc *desc) { }
static void adi_gpio_handle_pint_irq(unsigned int inta_irq,
struct irq_desc *desc)
{
u32 request;
u32 level_mask, hwirq;
bool umask = false;
struct gpio_pint *pint = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
struct gpio_pint_regs *regs = pint->regs;
struct irq_domain *domain;
preflow_handler(desc);
chained_irq_enter(chip, desc);
request = readl(&regs->request);
level_mask = readl(&regs->edge_set) & request;
hwirq = 0;
domain = pint->domain[0];
while (request) {
if (hwirq == PINT_HI_OFFSET)
domain = pint->domain[1];
if (request & 1) {
if (level_mask & BIT(hwirq)) {
umask = true;
chained_irq_exit(chip, desc);
}
generic_handle_irq(irq_find_mapping(domain,
hwirq % PINT_HI_OFFSET));
}
hwirq++;
request >>= 1;
}
if (!umask)
chained_irq_exit(chip, desc);
}
static int adi_get_groups_count(struct pinctrl_dev *pctldev)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
return pinctrl->soc->ngroups;
}
static const char *adi_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
return pinctrl->soc->groups[selector].name;
}
static int adi_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = pinctrl->soc->groups[selector].pins;
*num_pins = pinctrl->soc->groups[selector].num;
return 0;
}
static int adi_pinmux_enable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
struct gpio_port *port;
struct pinctrl_gpio_range *range;
unsigned long flags;
unsigned short *mux, pin;
mux = (unsigned short *)pinctrl->soc->functions[selector].mux;
while (*mux) {
pin = P_IDENT(*mux);
range = pinctrl_find_gpio_range_from_pin(pctldev, pin);
if (range == NULL)
return -ENODEV;
port = container_of(range->gc, struct gpio_port, chip);
spin_lock_irqsave(&port->lock, flags);
portmux_setup(port, pin_to_offset(range, pin),
P_FUNCT2MUX(*mux));
port_setup(port, pin_to_offset(range, pin), false);
mux++;
spin_unlock_irqrestore(&port->lock, flags);
}
return 0;
}
static void adi_pinmux_disable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
struct gpio_port *port;
struct pinctrl_gpio_range *range;
unsigned long flags;
unsigned short *mux, pin;
mux = (unsigned short *)pinctrl->soc->functions[selector].mux;
while (*mux) {
pin = P_IDENT(*mux);
range = pinctrl_find_gpio_range_from_pin(pctldev, pin);
if (range == NULL)
return;
port = container_of(range->gc, struct gpio_port, chip);
spin_lock_irqsave(&port->lock, flags);
port_setup(port, pin_to_offset(range, pin), true);
mux++;
spin_unlock_irqrestore(&port->lock, flags);
}
}
static int adi_pinmux_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
return pinctrl->soc->nfunctions;
}
static const char *adi_pinmux_get_func_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
return pinctrl->soc->functions[selector].name;
}
static int adi_pinmux_get_groups(struct pinctrl_dev *pctldev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct adi_pinctrl *pinctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = pinctrl->soc->functions[selector].groups;
*num_groups = pinctrl->soc->functions[selector].num_groups;
return 0;
}
static int adi_pinmux_request_gpio(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned pin)
{
struct gpio_port *port;
unsigned long flags;
u8 offset;
port = container_of(range->gc, struct gpio_port, chip);
offset = pin_to_offset(range, pin);
spin_lock_irqsave(&port->lock, flags);
port_setup(port, offset, true);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static int adi_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void adi_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static int adi_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct gpio_port *port;
unsigned long flags;
port = container_of(chip, struct gpio_port, chip);
spin_lock_irqsave(&port->lock, flags);
writew(BIT(offset), &port->regs->dir_clear);
writew(readw(&port->regs->inen) | BIT(offset), &port->regs->inen);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static void adi_gpio_set_value(struct gpio_chip *chip, unsigned offset,
int value)
{
struct gpio_port *port = container_of(chip, struct gpio_port, chip);
struct gpio_port_t *regs = port->regs;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
if (value)
writew(BIT(offset), &regs->data_set);
else
writew(BIT(offset), &regs->data_clear);
spin_unlock_irqrestore(&port->lock, flags);
}
static int adi_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct gpio_port *port = container_of(chip, struct gpio_port, chip);
struct gpio_port_t *regs = port->regs;
unsigned long flags;
spin_lock_irqsave(&port->lock, flags);
writew(readw(&regs->inen) & ~BIT(offset), &regs->inen);
if (value)
writew(BIT(offset), &regs->data_set);
else
writew(BIT(offset), &regs->data_clear);
writew(BIT(offset), &regs->dir_set);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static int adi_gpio_get_value(struct gpio_chip *chip, unsigned offset)
{
struct gpio_port *port = container_of(chip, struct gpio_port, chip);
struct gpio_port_t *regs = port->regs;
unsigned long flags;
int ret;
spin_lock_irqsave(&port->lock, flags);
ret = !!(readw(&regs->data) & BIT(offset));
spin_unlock_irqrestore(&port->lock, flags);
return ret;
}
static int adi_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct gpio_port *port = container_of(chip, struct gpio_port, chip);
if (port->irq_base >= 0)
return irq_find_mapping(port->domain, offset);
else
return irq_create_mapping(port->domain, offset);
}
static int adi_pint_map_port(struct gpio_pint *pint, bool assign, u8 map,
struct irq_domain *domain)
{
struct gpio_pint_regs *regs = pint->regs;
u32 map_mask;
if (pint->map_count > 1)
return -EINVAL;
pint->map_count++;
map_mask = (map << 8) | map;
if (assign) {
map_mask <<= PINT_HI_OFFSET;
writel((readl(&regs->assign) & 0xFFFF) | map_mask,
&regs->assign);
} else
writel((readl(&regs->assign) & 0xFFFF0000) | map_mask,
&regs->assign);
pint->domain[assign] = domain;
return 0;
}
static int adi_gpio_pint_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct gpio_pint *pint;
pint = devm_kzalloc(dev, sizeof(struct gpio_pint), GFP_KERNEL);
if (!pint) {
dev_err(dev, "Memory alloc failed\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pint->base = devm_ioremap_resource(dev, res);
if (IS_ERR(pint->base))
return PTR_ERR(pint->base);
pint->regs = (struct gpio_pint_regs *)pint->base;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "Invalid IRQ resource\n");
return -ENODEV;
}
spin_lock_init(&pint->lock);
pint->irq = res->start;
pint->pint_map_port = adi_pint_map_port;
platform_set_drvdata(pdev, pint);
irq_set_chained_handler(pint->irq, adi_gpio_handle_pint_irq);
irq_set_handler_data(pint->irq, pint);
list_add_tail(&pint->node, &adi_pint_list);
return 0;
}
static int adi_gpio_pint_remove(struct platform_device *pdev)
{
struct gpio_pint *pint = platform_get_drvdata(pdev);
list_del(&pint->node);
irq_set_handler(pint->irq, handle_simple_irq);
return 0;
}
static int adi_gpio_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct gpio_port *port = d->host_data;
if (!port)
return -EINVAL;
irq_set_chip_data(irq, port);
irq_set_chip_and_handler(irq, &adi_gpio_irqchip,
handle_level_irq);
return 0;
}
static int adi_gpio_init_int(struct gpio_port *port)
{
struct device_node *node = port->dev->of_node;
struct gpio_pint *pint = port->pint;
int ret;
port->domain = irq_domain_add_linear(node, port->width,
&adi_gpio_irq_domain_ops, port);
if (!port->domain) {
dev_err(port->dev, "Failed to create irqdomain\n");
return -ENOSYS;
}
ret = pint->pint_map_port(port->pint, port->pint_assign,
port->pint_map, port->domain);
if (ret)
return ret;
if (port->irq_base >= 0) {
ret = irq_create_strict_mappings(port->domain, port->irq_base,
0, port->width);
if (ret) {
dev_err(port->dev, "Couldn't associate to domain\n");
return ret;
}
}
return 0;
}
static int adi_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct adi_pinctrl_gpio_platform_data *pdata;
struct resource *res;
struct gpio_port *port;
char pinctrl_devname[DEVNAME_SIZE];
static int gpio;
int ret = 0, ret1;
pdata = dev->platform_data;
if (!pdata)
return -EINVAL;
port = devm_kzalloc(dev, sizeof(struct gpio_port), GFP_KERNEL);
if (!port) {
dev_err(dev, "Memory alloc failed\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
port->base = devm_ioremap_resource(dev, res);
if (IS_ERR(port->base))
return PTR_ERR(port->base);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res)
port->irq_base = -1;
else
port->irq_base = res->start;
port->width = pdata->port_width;
port->dev = dev;
port->regs = (struct gpio_port_t *)port->base;
port->pint_assign = pdata->pint_assign;
port->pint_map = pdata->pint_map;
port->pint = find_gpio_pint(pdata->pint_id);
if (port->pint) {
ret = adi_gpio_init_int(port);
if (ret)
return ret;
}
spin_lock_init(&port->lock);
platform_set_drvdata(pdev, port);
port->chip.label = "adi-gpio";
port->chip.direction_input = adi_gpio_direction_input;
port->chip.get = adi_gpio_get_value;
port->chip.direction_output = adi_gpio_direction_output;
port->chip.set = adi_gpio_set_value;
port->chip.request = adi_gpio_request;
port->chip.free = adi_gpio_free;
port->chip.to_irq = adi_gpio_to_irq;
if (pdata->port_gpio_base > 0)
port->chip.base = pdata->port_gpio_base;
else
port->chip.base = gpio;
port->chip.ngpio = port->width;
gpio = port->chip.base + port->width;
ret = gpiochip_add(&port->chip);
if (ret) {
dev_err(&pdev->dev, "Fail to add GPIO chip.\n");
goto out_remove_domain;
}
snprintf(pinctrl_devname, DEVNAME_SIZE, "pinctrl-adi2.%d",
pdata->pinctrl_id);
pinctrl_devname[DEVNAME_SIZE - 1] = 0;
ret = gpiochip_add_pin_range(&port->chip, pinctrl_devname,
0, pdata->port_pin_base, port->width);
if (ret) {
dev_err(&pdev->dev, "Fail to add pin range to %s.\n",
pinctrl_devname);
goto out_remove_gpiochip;
}
list_add_tail(&port->node, &adi_gpio_port_list);
return 0;
out_remove_gpiochip:
ret1 = gpiochip_remove(&port->chip);
out_remove_domain:
if (port->pint)
irq_domain_remove(port->domain);
return ret;
}
static int adi_gpio_remove(struct platform_device *pdev)
{
struct gpio_port *port = platform_get_drvdata(pdev);
int ret;
u8 offset;
list_del(&port->node);
gpiochip_remove_pin_ranges(&port->chip);
ret = gpiochip_remove(&port->chip);
if (port->pint) {
for (offset = 0; offset < port->width; offset++)
irq_dispose_mapping(irq_find_mapping(port->domain,
offset));
irq_domain_remove(port->domain);
}
return ret;
}
static int adi_pinctrl_probe(struct platform_device *pdev)
{
struct adi_pinctrl *pinctrl;
pinctrl = devm_kzalloc(&pdev->dev, sizeof(*pinctrl), GFP_KERNEL);
if (!pinctrl)
return -ENOMEM;
pinctrl->dev = &pdev->dev;
adi_pinctrl_soc_init(&pinctrl->soc);
adi_pinmux_desc.pins = pinctrl->soc->pins;
adi_pinmux_desc.npins = pinctrl->soc->npins;
pinctrl->pctl = pinctrl_register(&adi_pinmux_desc, &pdev->dev, pinctrl);
if (!pinctrl->pctl) {
dev_err(&pdev->dev, "could not register pinctrl ADI2 driver\n");
return -EINVAL;
}
platform_set_drvdata(pdev, pinctrl);
return 0;
}
static int adi_pinctrl_remove(struct platform_device *pdev)
{
struct adi_pinctrl *pinctrl = platform_get_drvdata(pdev);
pinctrl_unregister(pinctrl->pctl);
return 0;
}
static int __init adi_pinctrl_setup(void)
{
int ret;
ret = platform_driver_register(&adi_pinctrl_driver);
if (ret)
return ret;
ret = platform_driver_register(&adi_gpio_pint_driver);
if (ret)
goto pint_error;
ret = platform_driver_register(&adi_gpio_driver);
if (ret)
goto gpio_error;
#ifdef CONFIG_PM
register_syscore_ops(&gpio_pm_syscore_ops);
#endif
return ret;
gpio_error:
platform_driver_unregister(&adi_gpio_pint_driver);
pint_error:
platform_driver_unregister(&adi_pinctrl_driver);
return ret;
}
