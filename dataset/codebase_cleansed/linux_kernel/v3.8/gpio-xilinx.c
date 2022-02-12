static int xgpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
return (in_be32(mm_gc->regs + XGPIO_DATA_OFFSET) >> gpio) & 1;
}
static void xgpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
spin_lock_irqsave(&chip->gpio_lock, flags);
if (val)
chip->gpio_state |= 1 << gpio;
else
chip->gpio_state &= ~(1 << gpio);
out_be32(mm_gc->regs + XGPIO_DATA_OFFSET, chip->gpio_state);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
}
static int xgpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
spin_lock_irqsave(&chip->gpio_lock, flags);
chip->gpio_dir |= (1 << gpio);
out_be32(mm_gc->regs + XGPIO_TRI_OFFSET, chip->gpio_dir);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
return 0;
}
static int xgpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
spin_lock_irqsave(&chip->gpio_lock, flags);
if (val)
chip->gpio_state |= 1 << gpio;
else
chip->gpio_state &= ~(1 << gpio);
out_be32(mm_gc->regs + XGPIO_DATA_OFFSET, chip->gpio_state);
chip->gpio_dir &= (~(1 << gpio));
out_be32(mm_gc->regs + XGPIO_TRI_OFFSET, chip->gpio_dir);
spin_unlock_irqrestore(&chip->gpio_lock, flags);
return 0;
}
static void xgpio_save_regs(struct of_mm_gpio_chip *mm_gc)
{
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
out_be32(mm_gc->regs + XGPIO_DATA_OFFSET, chip->gpio_state);
out_be32(mm_gc->regs + XGPIO_TRI_OFFSET, chip->gpio_dir);
}
static int xgpio_of_probe(struct device_node *np)
{
struct xgpio_instance *chip;
int status = 0;
const u32 *tree_info;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
tree_info = of_get_property(np, "xlnx,dout-default", NULL);
if (tree_info)
chip->gpio_state = be32_to_cpup(tree_info);
chip->gpio_dir = 0xFFFFFFFF;
tree_info = of_get_property(np, "xlnx,tri-default", NULL);
if (tree_info)
chip->gpio_dir = be32_to_cpup(tree_info);
chip->mmchip.gc.ngpio = 32;
tree_info = of_get_property(np, "xlnx,gpio-width", NULL);
if (!tree_info)
tree_info = of_get_property(np->parent,
"xlnx,gpio-width", NULL);
if (tree_info)
chip->mmchip.gc.ngpio = be32_to_cpup(tree_info);
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
return 0;
}
static int __init xgpio_init(void)
{
struct device_node *np;
for_each_matching_node(np, xgpio_of_match)
xgpio_of_probe(np);
return 0;
}
