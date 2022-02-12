static void __iomem *gpio_reg(struct gpio_chip *chip, unsigned offset,
enum GPIO_REG reg_type)
{
struct intel_mid_gpio *priv = gpiochip_get_data(chip);
unsigned nreg = chip->ngpio / 32;
u8 reg = offset / 32;
return priv->reg_base + reg_type * nreg * 4 + reg * 4;
}
static void __iomem *gpio_reg_2bit(struct gpio_chip *chip, unsigned offset,
enum GPIO_REG reg_type)
{
struct intel_mid_gpio *priv = gpiochip_get_data(chip);
unsigned nreg = chip->ngpio / 32;
u8 reg = offset / 16;
return priv->reg_base + reg_type * nreg * 4 + reg * 4;
}
static int intel_gpio_request(struct gpio_chip *chip, unsigned offset)
{
void __iomem *gafr = gpio_reg_2bit(chip, offset, GAFR);
u32 value = readl(gafr);
int shift = (offset % 16) << 1, af = (value >> shift) & 3;
if (af) {
value &= ~(3 << shift);
writel(value, gafr);
}
return 0;
}
static int intel_gpio_get(struct gpio_chip *chip, unsigned offset)
{
void __iomem *gplr = gpio_reg(chip, offset, GPLR);
return !!(readl(gplr) & BIT(offset % 32));
}
static void intel_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
void __iomem *gpsr, *gpcr;
if (value) {
gpsr = gpio_reg(chip, offset, GPSR);
writel(BIT(offset % 32), gpsr);
} else {
gpcr = gpio_reg(chip, offset, GPCR);
writel(BIT(offset % 32), gpcr);
}
}
static int intel_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct intel_mid_gpio *priv = gpiochip_get_data(chip);
void __iomem *gpdr = gpio_reg(chip, offset, GPDR);
u32 value;
unsigned long flags;
if (priv->pdev)
pm_runtime_get(&priv->pdev->dev);
spin_lock_irqsave(&priv->lock, flags);
value = readl(gpdr);
value &= ~BIT(offset % 32);
writel(value, gpdr);
spin_unlock_irqrestore(&priv->lock, flags);
if (priv->pdev)
pm_runtime_put(&priv->pdev->dev);
return 0;
}
static int intel_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct intel_mid_gpio *priv = gpiochip_get_data(chip);
void __iomem *gpdr = gpio_reg(chip, offset, GPDR);
unsigned long flags;
intel_gpio_set(chip, offset, value);
if (priv->pdev)
pm_runtime_get(&priv->pdev->dev);
spin_lock_irqsave(&priv->lock, flags);
value = readl(gpdr);
value |= BIT(offset % 32);
writel(value, gpdr);
spin_unlock_irqrestore(&priv->lock, flags);
if (priv->pdev)
pm_runtime_put(&priv->pdev->dev);
return 0;
}
static int intel_mid_irq_type(struct irq_data *d, unsigned type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct intel_mid_gpio *priv = gpiochip_get_data(gc);
u32 gpio = irqd_to_hwirq(d);
unsigned long flags;
u32 value;
void __iomem *grer = gpio_reg(&priv->chip, gpio, GRER);
void __iomem *gfer = gpio_reg(&priv->chip, gpio, GFER);
if (gpio >= priv->chip.ngpio)
return -EINVAL;
if (priv->pdev)
pm_runtime_get(&priv->pdev->dev);
spin_lock_irqsave(&priv->lock, flags);
if (type & IRQ_TYPE_EDGE_RISING)
value = readl(grer) | BIT(gpio % 32);
else
value = readl(grer) & (~BIT(gpio % 32));
writel(value, grer);
if (type & IRQ_TYPE_EDGE_FALLING)
value = readl(gfer) | BIT(gpio % 32);
else
value = readl(gfer) & (~BIT(gpio % 32));
writel(value, gfer);
spin_unlock_irqrestore(&priv->lock, flags);
if (priv->pdev)
pm_runtime_put(&priv->pdev->dev);
return 0;
}
static void intel_mid_irq_unmask(struct irq_data *d)
{
}
static void intel_mid_irq_mask(struct irq_data *d)
{
}
static void intel_mid_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct intel_mid_gpio *priv = gpiochip_get_data(gc);
struct irq_data *data = irq_desc_get_irq_data(desc);
struct irq_chip *chip = irq_data_get_irq_chip(data);
u32 base, gpio, mask;
unsigned long pending;
void __iomem *gedr;
for (base = 0; base < priv->chip.ngpio; base += 32) {
gedr = gpio_reg(&priv->chip, base, GEDR);
while ((pending = readl(gedr))) {
gpio = __ffs(pending);
mask = BIT(gpio);
writel(mask, gedr);
generic_handle_irq(irq_find_mapping(gc->irqdomain,
base + gpio));
}
}
chip->irq_eoi(data);
}
static void intel_mid_irq_init_hw(struct intel_mid_gpio *priv)
{
void __iomem *reg;
unsigned base;
for (base = 0; base < priv->chip.ngpio; base += 32) {
reg = gpio_reg(&priv->chip, base, GRER);
writel(0, reg);
reg = gpio_reg(&priv->chip, base, GFER);
writel(0, reg);
reg = gpio_reg(&priv->chip, base, GEDR);
writel(~0, reg);
}
}
static int intel_gpio_runtime_idle(struct device *dev)
{
int err = pm_schedule_suspend(dev, 500);
return err ?: -EBUSY;
}
static int intel_gpio_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
void __iomem *base;
struct intel_mid_gpio *priv;
u32 gpio_base;
u32 irq_base;
int retval;
struct intel_mid_gpio_ddata *ddata =
(struct intel_mid_gpio_ddata *)id->driver_data;
retval = pcim_enable_device(pdev);
if (retval)
return retval;
retval = pcim_iomap_regions(pdev, 1 << 0 | 1 << 1, pci_name(pdev));
if (retval) {
dev_err(&pdev->dev, "I/O memory mapping error\n");
return retval;
}
base = pcim_iomap_table(pdev)[1];
irq_base = readl(base);
gpio_base = readl(sizeof(u32) + base);
pcim_iounmap_regions(pdev, 1 << 1);
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&pdev->dev, "can't allocate chip data\n");
return -ENOMEM;
}
priv->reg_base = pcim_iomap_table(pdev)[0];
priv->chip.label = dev_name(&pdev->dev);
priv->chip.parent = &pdev->dev;
priv->chip.request = intel_gpio_request;
priv->chip.direction_input = intel_gpio_direction_input;
priv->chip.direction_output = intel_gpio_direction_output;
priv->chip.get = intel_gpio_get;
priv->chip.set = intel_gpio_set;
priv->chip.base = gpio_base;
priv->chip.ngpio = ddata->ngpio;
priv->chip.can_sleep = false;
priv->pdev = pdev;
spin_lock_init(&priv->lock);
pci_set_drvdata(pdev, priv);
retval = devm_gpiochip_add_data(&pdev->dev, &priv->chip, priv);
if (retval) {
dev_err(&pdev->dev, "gpiochip_add error %d\n", retval);
return retval;
}
retval = gpiochip_irqchip_add(&priv->chip,
&intel_mid_irqchip,
irq_base,
handle_simple_irq,
IRQ_TYPE_NONE);
if (retval) {
dev_err(&pdev->dev,
"could not connect irqchip to gpiochip\n");
return retval;
}
intel_mid_irq_init_hw(priv);
gpiochip_set_chained_irqchip(&priv->chip,
&intel_mid_irqchip,
pdev->irq,
intel_mid_irq_handler);
pm_runtime_put_noidle(&pdev->dev);
pm_runtime_allow(&pdev->dev);
return 0;
}
static int __init intel_gpio_init(void)
{
return pci_register_driver(&intel_gpio_driver);
}
