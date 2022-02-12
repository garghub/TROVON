static void __iomem *gpio_reg(struct gpio_chip *chip, unsigned int offset,
unsigned int reg_type_offset)
{
struct mrfld_gpio *priv = gpiochip_get_data(chip);
u8 reg = offset / 32;
return priv->reg_base + reg_type_offset + reg * 4;
}
static int mrfld_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
void __iomem *gplr = gpio_reg(chip, offset, GPLR);
return !!(readl(gplr) & BIT(offset % 32));
}
static void mrfld_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct mrfld_gpio *priv = gpiochip_get_data(chip);
void __iomem *gpsr, *gpcr;
unsigned long flags;
raw_spin_lock_irqsave(&priv->lock, flags);
if (value) {
gpsr = gpio_reg(chip, offset, GPSR);
writel(BIT(offset % 32), gpsr);
} else {
gpcr = gpio_reg(chip, offset, GPCR);
writel(BIT(offset % 32), gpcr);
}
raw_spin_unlock_irqrestore(&priv->lock, flags);
}
static int mrfld_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct mrfld_gpio *priv = gpiochip_get_data(chip);
void __iomem *gpdr = gpio_reg(chip, offset, GPDR);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&priv->lock, flags);
value = readl(gpdr);
value &= ~BIT(offset % 32);
writel(value, gpdr);
raw_spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int mrfld_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct mrfld_gpio *priv = gpiochip_get_data(chip);
void __iomem *gpdr = gpio_reg(chip, offset, GPDR);
unsigned long flags;
mrfld_gpio_set(chip, offset, value);
raw_spin_lock_irqsave(&priv->lock, flags);
value = readl(gpdr);
value |= BIT(offset % 32);
writel(value, gpdr);
raw_spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static void mrfld_irq_ack(struct irq_data *d)
{
struct mrfld_gpio *priv = irq_data_get_irq_chip_data(d);
u32 gpio = irqd_to_hwirq(d);
void __iomem *gisr = gpio_reg(&priv->chip, gpio, GISR);
unsigned long flags;
raw_spin_lock_irqsave(&priv->lock, flags);
writel(BIT(gpio % 32), gisr);
raw_spin_unlock_irqrestore(&priv->lock, flags);
}
static void mrfld_irq_unmask_mask(struct irq_data *d, bool unmask)
{
struct mrfld_gpio *priv = irq_data_get_irq_chip_data(d);
u32 gpio = irqd_to_hwirq(d);
void __iomem *gimr = gpio_reg(&priv->chip, gpio, GIMR);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&priv->lock, flags);
if (unmask)
value = readl(gimr) | BIT(gpio % 32);
else
value = readl(gimr) & ~BIT(gpio % 32);
writel(value, gimr);
raw_spin_unlock_irqrestore(&priv->lock, flags);
}
static void mrfld_irq_mask(struct irq_data *d)
{
mrfld_irq_unmask_mask(d, false);
}
static void mrfld_irq_unmask(struct irq_data *d)
{
mrfld_irq_unmask_mask(d, true);
}
static int mrfld_irq_set_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct mrfld_gpio *priv = gpiochip_get_data(gc);
u32 gpio = irqd_to_hwirq(d);
void __iomem *grer = gpio_reg(&priv->chip, gpio, GRER);
void __iomem *gfer = gpio_reg(&priv->chip, gpio, GFER);
void __iomem *gitr = gpio_reg(&priv->chip, gpio, GITR);
void __iomem *glpr = gpio_reg(&priv->chip, gpio, GLPR);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&priv->lock, flags);
if (type & IRQ_TYPE_EDGE_RISING)
value = readl(grer) | BIT(gpio % 32);
else
value = readl(grer) & ~BIT(gpio % 32);
writel(value, grer);
if (type & IRQ_TYPE_EDGE_FALLING)
value = readl(gfer) | BIT(gpio % 32);
else
value = readl(gfer) & ~BIT(gpio % 32);
writel(value, gfer);
if (type & IRQ_TYPE_LEVEL_LOW)
value = readl(glpr) | BIT(gpio % 32);
else
value = readl(glpr) & ~BIT(gpio % 32);
writel(value, glpr);
if (type & IRQ_TYPE_LEVEL_MASK) {
value = readl(gitr) | BIT(gpio % 32);
writel(value, gitr);
irq_set_handler_locked(d, handle_level_irq);
} else if (type & IRQ_TYPE_EDGE_BOTH) {
value = readl(gitr) & ~BIT(gpio % 32);
writel(value, gitr);
irq_set_handler_locked(d, handle_edge_irq);
}
raw_spin_unlock_irqrestore(&priv->lock, flags);
return 0;
}
static int mrfld_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct mrfld_gpio *priv = gpiochip_get_data(gc);
u32 gpio = irqd_to_hwirq(d);
void __iomem *gwmr = gpio_reg(&priv->chip, gpio, GWMR);
void __iomem *gwsr = gpio_reg(&priv->chip, gpio, GWSR);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&priv->lock, flags);
writel(BIT(gpio % 32), gwsr);
if (on)
value = readl(gwmr) | BIT(gpio % 32);
else
value = readl(gwmr) & ~BIT(gpio % 32);
writel(value, gwmr);
raw_spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(priv->dev, "%sable wake for gpio %u\n", on ? "en" : "dis", gpio);
return 0;
}
static void mrfld_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct mrfld_gpio *priv = gpiochip_get_data(gc);
struct irq_chip *irqchip = irq_desc_get_chip(desc);
unsigned long base, gpio;
chained_irq_enter(irqchip, desc);
for (base = 0; base < priv->chip.ngpio; base += 32) {
void __iomem *gisr = gpio_reg(&priv->chip, base, GISR);
void __iomem *gimr = gpio_reg(&priv->chip, base, GIMR);
unsigned long pending, enabled;
pending = readl(gisr);
enabled = readl(gimr);
pending &= enabled;
for_each_set_bit(gpio, &pending, 32) {
unsigned int irq;
irq = irq_find_mapping(gc->irqdomain, base + gpio);
generic_handle_irq(irq);
}
}
chained_irq_exit(irqchip, desc);
}
static void mrfld_irq_init_hw(struct mrfld_gpio *priv)
{
void __iomem *reg;
unsigned int base;
for (base = 0; base < priv->chip.ngpio; base += 32) {
reg = gpio_reg(&priv->chip, base, GRER);
writel(0, reg);
reg = gpio_reg(&priv->chip, base, GFER);
writel(0, reg);
}
}
static int mrfld_gpio_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
const struct mrfld_gpio_pinrange *range;
struct mrfld_gpio *priv;
u32 gpio_base, irq_base;
void __iomem *base;
unsigned int i;
int retval;
retval = pcim_enable_device(pdev);
if (retval)
return retval;
retval = pcim_iomap_regions(pdev, BIT(1) | BIT(0), pci_name(pdev));
if (retval) {
dev_err(&pdev->dev, "I/O memory mapping error\n");
return retval;
}
base = pcim_iomap_table(pdev)[1];
irq_base = readl(base);
gpio_base = readl(sizeof(u32) + base);
pcim_iounmap_regions(pdev, BIT(1));
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "can't allocate chip data\n");
return -ENOMEM;
}
priv->dev = &pdev->dev;
priv->reg_base = pcim_iomap_table(pdev)[0];
priv->chip.label = dev_name(&pdev->dev);
priv->chip.parent = &pdev->dev;
priv->chip.request = gpiochip_generic_request;
priv->chip.free = gpiochip_generic_free;
priv->chip.direction_input = mrfld_gpio_direction_input;
priv->chip.direction_output = mrfld_gpio_direction_output;
priv->chip.get = mrfld_gpio_get;
priv->chip.set = mrfld_gpio_set;
priv->chip.base = gpio_base;
priv->chip.ngpio = MRFLD_NGPIO;
priv->chip.can_sleep = false;
raw_spin_lock_init(&priv->lock);
pci_set_drvdata(pdev, priv);
retval = devm_gpiochip_add_data(&pdev->dev, &priv->chip, priv);
if (retval) {
dev_err(&pdev->dev, "gpiochip_add error %d\n", retval);
return retval;
}
for (i = 0; i < ARRAY_SIZE(mrfld_gpio_ranges); i++) {
range = &mrfld_gpio_ranges[i];
retval = gpiochip_add_pin_range(&priv->chip,
"pinctrl-merrifield",
range->gpio_base,
range->pin_base,
range->npins);
if (retval) {
dev_err(&pdev->dev, "failed to add GPIO pin range\n");
return retval;
}
}
retval = gpiochip_irqchip_add(&priv->chip, &mrfld_irqchip, irq_base,
handle_simple_irq, IRQ_TYPE_NONE);
if (retval) {
dev_err(&pdev->dev, "could not connect irqchip to gpiochip\n");
return retval;
}
mrfld_irq_init_hw(priv);
gpiochip_set_chained_irqchip(&priv->chip, &mrfld_irqchip, pdev->irq,
mrfld_irq_handler);
return 0;
}
