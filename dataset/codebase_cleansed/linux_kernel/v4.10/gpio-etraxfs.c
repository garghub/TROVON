static unsigned int etraxfs_gpio_chip_to_port(struct gpio_chip *gc)
{
return gc->label[0] - 'A';
}
static int etraxfs_gpio_of_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec,
u32 *flags)
{
if (etraxfs_gpio_chip_to_port(gc) + 0xA != gpiospec->args[2])
return -EINVAL;
return of_gpio_simple_xlate(gc, gpiospec, flags);
}
static unsigned int etraxfs_gpio_to_group_irq(unsigned int gpio)
{
return gpio % 8;
}
static unsigned int etraxfs_gpio_to_group_pin(struct etraxfs_gpio_chip *chip,
unsigned int gpio)
{
return 4 * etraxfs_gpio_chip_to_port(&chip->gc) + gpio / 8;
}
static void etraxfs_gpio_irq_ack(struct irq_data *d)
{
struct etraxfs_gpio_chip *chip =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
struct etraxfs_gpio_block *block = chip->block;
unsigned int grpirq = etraxfs_gpio_to_group_irq(d->hwirq);
writel(BIT(grpirq), block->regs + block->info->rw_ack_intr);
}
static void etraxfs_gpio_irq_mask(struct irq_data *d)
{
struct etraxfs_gpio_chip *chip =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
struct etraxfs_gpio_block *block = chip->block;
unsigned int grpirq = etraxfs_gpio_to_group_irq(d->hwirq);
spin_lock(&block->lock);
block->mask &= ~BIT(grpirq);
writel(block->mask, block->regs + block->info->rw_intr_mask);
spin_unlock(&block->lock);
}
static void etraxfs_gpio_irq_unmask(struct irq_data *d)
{
struct etraxfs_gpio_chip *chip =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
struct etraxfs_gpio_block *block = chip->block;
unsigned int grpirq = etraxfs_gpio_to_group_irq(d->hwirq);
spin_lock(&block->lock);
block->mask |= BIT(grpirq);
writel(block->mask, block->regs + block->info->rw_intr_mask);
spin_unlock(&block->lock);
}
static int etraxfs_gpio_irq_set_type(struct irq_data *d, u32 type)
{
struct etraxfs_gpio_chip *chip =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
struct etraxfs_gpio_block *block = chip->block;
unsigned int grpirq = etraxfs_gpio_to_group_irq(d->hwirq);
u32 cfg;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
cfg = GIO_CFG_POSEDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
cfg = GIO_CFG_NEGEDGE;
break;
case IRQ_TYPE_EDGE_BOTH:
cfg = GIO_CFG_ANYEDGE;
break;
case IRQ_TYPE_LEVEL_LOW:
cfg = GIO_CFG_LO;
break;
case IRQ_TYPE_LEVEL_HIGH:
cfg = GIO_CFG_HI;
break;
default:
return -EINVAL;
}
spin_lock(&block->lock);
block->cfg &= ~(0x7 << (grpirq * 3));
block->cfg |= (cfg << (grpirq * 3));
writel(block->cfg, block->regs + block->info->rw_intr_cfg);
spin_unlock(&block->lock);
return 0;
}
static int etraxfs_gpio_irq_request_resources(struct irq_data *d)
{
struct etraxfs_gpio_chip *chip =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
struct etraxfs_gpio_block *block = chip->block;
unsigned int grpirq = etraxfs_gpio_to_group_irq(d->hwirq);
int ret = -EBUSY;
spin_lock(&block->lock);
if (block->group[grpirq])
goto out;
ret = gpiochip_lock_as_irq(&chip->gc, d->hwirq);
if (ret)
goto out;
block->group[grpirq] = d->irq;
if (block->info->rw_intr_pins) {
unsigned int pin = etraxfs_gpio_to_group_pin(chip, d->hwirq);
block->pins &= ~(0xf << (grpirq * 4));
block->pins |= (pin << (grpirq * 4));
writel(block->pins, block->regs + block->info->rw_intr_pins);
}
out:
spin_unlock(&block->lock);
return ret;
}
static void etraxfs_gpio_irq_release_resources(struct irq_data *d)
{
struct etraxfs_gpio_chip *chip =
gpiochip_get_data(irq_data_get_irq_chip_data(d));
struct etraxfs_gpio_block *block = chip->block;
unsigned int grpirq = etraxfs_gpio_to_group_irq(d->hwirq);
spin_lock(&block->lock);
block->group[grpirq] = 0;
gpiochip_unlock_as_irq(&chip->gc, d->hwirq);
spin_unlock(&block->lock);
}
static irqreturn_t etraxfs_gpio_interrupt(int irq, void *dev_id)
{
struct etraxfs_gpio_block *block = dev_id;
unsigned long intr = readl(block->regs + block->info->r_masked_intr);
int bit;
for_each_set_bit(bit, &intr, 8)
generic_handle_irq(block->group[bit]);
return IRQ_RETVAL(intr & 0xff);
}
static int etraxfs_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct etraxfs_gpio_info *info;
const struct of_device_id *match;
struct etraxfs_gpio_block *block;
struct etraxfs_gpio_chip *chips;
struct resource *res, *irq;
bool allportsirq = false;
void __iomem *regs;
int ret;
int i;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
match = of_match_node(etraxfs_gpio_of_table, dev->of_node);
if (!match)
return -EINVAL;
info = match->data;
chips = devm_kzalloc(dev, sizeof(*chips) * info->num_ports, GFP_KERNEL);
if (!chips)
return -ENOMEM;
irq = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!irq)
return -EINVAL;
block = devm_kzalloc(dev, sizeof(*block), GFP_KERNEL);
if (!block)
return -ENOMEM;
spin_lock_init(&block->lock);
block->regs = regs;
block->info = info;
writel(0, block->regs + info->rw_intr_mask);
writel(0, block->regs + info->rw_intr_cfg);
if (info->rw_intr_pins) {
allportsirq = true;
writel(0, block->regs + info->rw_intr_pins);
}
ret = devm_request_irq(dev, irq->start, etraxfs_gpio_interrupt,
IRQF_SHARED, dev_name(dev), block);
if (ret) {
dev_err(dev, "Unable to request irq %d\n", ret);
return ret;
}
for (i = 0; i < info->num_ports; i++) {
struct etraxfs_gpio_chip *chip = &chips[i];
struct gpio_chip *gc = &chip->gc;
const struct etraxfs_gpio_port *port = &info->ports[i];
unsigned long flags = BGPIOF_READ_OUTPUT_REG_SET;
void __iomem *dat = regs + port->din;
void __iomem *set = regs + port->dout;
void __iomem *dirout = regs + port->oe;
chip->block = block;
if (dirout == set) {
dirout = set = NULL;
flags = BGPIOF_NO_OUTPUT;
}
ret = bgpio_init(gc, dev, 4,
dat, set, NULL, dirout, NULL,
flags);
if (ret) {
dev_err(dev, "Unable to init port %s\n",
port->label);
continue;
}
gc->ngpio = port->ngpio;
gc->label = port->label;
gc->of_node = dev->of_node;
gc->of_gpio_n_cells = 3;
gc->of_xlate = etraxfs_gpio_of_xlate;
ret = gpiochip_add_data(gc, chip);
if (ret) {
dev_err(dev, "Unable to register port %s\n",
gc->label);
continue;
}
if (i > 0 && !allportsirq)
continue;
ret = gpiochip_irqchip_add(gc, &etraxfs_gpio_irq_chip, 0,
handle_level_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "Unable to add irqchip to port %s\n",
gc->label);
}
}
return 0;
}
