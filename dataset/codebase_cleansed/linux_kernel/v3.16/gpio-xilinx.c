static int xgpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
void __iomem *regs = mm_gc->regs + chip->offset;
return !!(xgpio_readreg(regs + XGPIO_DATA_OFFSET) & BIT(gpio));
}
static void xgpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
void __iomem *regs = mm_gc->regs;
spin_lock_irqsave(&chip->gpio_lock, flags);
if (val)
chip->gpio_state |= BIT(gpio);
else
chip->gpio_state &= ~BIT(gpio);
xgpio_writereg(regs + chip->offset + XGPIO_DATA_OFFSET,
chip->gpio_state);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
}
static int xgpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
void __iomem *regs = mm_gc->regs;
spin_lock_irqsave(&chip->gpio_lock, flags);
chip->gpio_dir |= BIT(gpio);
xgpio_writereg(regs + chip->offset + XGPIO_TRI_OFFSET, chip->gpio_dir);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
return 0;
}
static int xgpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
void __iomem *regs = mm_gc->regs;
spin_lock_irqsave(&chip->gpio_lock, flags);
if (val)
chip->gpio_state |= BIT(gpio);
else
chip->gpio_state &= ~BIT(gpio);
xgpio_writereg(regs + chip->offset + XGPIO_DATA_OFFSET,
chip->gpio_state);
chip->gpio_dir &= ~BIT(gpio);
xgpio_writereg(regs + chip->offset + XGPIO_TRI_OFFSET, chip->gpio_dir);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
return 0;
}
static void xgpio_save_regs(struct of_mm_gpio_chip *mm_gc)
{
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
xgpio_writereg(mm_gc->regs + chip->offset + XGPIO_DATA_OFFSET,
chip->gpio_state);
xgpio_writereg(mm_gc->regs + chip->offset + XGPIO_TRI_OFFSET,
chip->gpio_dir);
}
static int xgpio_of_probe(struct device_node *np)
{
struct xgpio_instance *chip;
int status = 0;
const u32 *tree_info;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
of_property_read_u32(np, "xlnx,dout-default", &chip->gpio_state);
chip->gpio_dir = 0xFFFFFFFF;
of_property_read_u32(np, "xlnx,tri-default", &chip->gpio_dir);
chip->mmchip.gc.ngpio = 32;
of_property_read_u32(np, "xlnx,gpio-width",
(u32 *)&chip->mmchip.gc.ngpio);
spin_lock_init(&chip->gpio_lock);
chip->mmchip.gc.direction_input = xgpio_dir_in;
chip->mmchip.gc.direction_output = xgpio_dir_out;
chip->mmchip.gc.get = xgpio_get;
chip->mmchip.gc.set = xgpio_set;
chip->mmchip.save_regs = xgpio_save_regs;
status = of_mm_gpiochip_add(np, &chip->mmchip);
if (status) {
kfree(chip);
pr_err("%s: error in probe function with status %d\n",
np->full_name, status);
return status;
}
pr_info("XGpio: %s: registered, base is %d\n", np->full_name,
chip->mmchip.gc.base);
tree_info = of_get_property(np, "xlnx,is-dual", NULL);
if (tree_info && be32_to_cpup(tree_info)) {
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->offset = XGPIO_CHANNEL_OFFSET;
of_property_read_u32(np, "xlnx,dout-default-2",
&chip->gpio_state);
chip->gpio_dir = 0xFFFFFFFF;
of_property_read_u32(np, "xlnx,tri-default-2", &chip->gpio_dir);
chip->mmchip.gc.ngpio = 32;
of_property_read_u32(np, "xlnx,gpio2-width",
(u32 *)&chip->mmchip.gc.ngpio);
spin_lock_init(&chip->gpio_lock);
chip->mmchip.gc.direction_input = xgpio_dir_in;
chip->mmchip.gc.direction_output = xgpio_dir_out;
chip->mmchip.gc.get = xgpio_get;
chip->mmchip.gc.set = xgpio_set;
chip->mmchip.save_regs = xgpio_save_regs;
status = of_mm_gpiochip_add(np, &chip->mmchip);
if (status) {
kfree(chip);
pr_err("%s: error in probe function with status %d\n",
np->full_name, status);
return status;
}
pr_info("XGpio: %s: dual channel registered, base is %d\n",
np->full_name, chip->mmchip.gc.base);
}
return 0;
}
static int __init xgpio_init(void)
{
struct device_node *np;
for_each_matching_node(np, xgpio_of_match)
xgpio_of_probe(np);
return 0;
}
