static inline int xgpio_index(struct xgpio_instance *chip, int gpio)
{
if (gpio >= chip->gpio_width[0])
return 1;
return 0;
}
static inline int xgpio_regoffset(struct xgpio_instance *chip, int gpio)
{
if (xgpio_index(chip, gpio))
return XGPIO_CHANNEL_OFFSET;
return 0;
}
static inline int xgpio_offset(struct xgpio_instance *chip, int gpio)
{
if (xgpio_index(chip, gpio))
return gpio - chip->gpio_width[0];
return gpio;
}
static int xgpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip = gpiochip_get_data(gc);
u32 val;
val = xgpio_readreg(mm_gc->regs + XGPIO_DATA_OFFSET +
xgpio_regoffset(chip, gpio));
return !!(val & BIT(xgpio_offset(chip, gpio)));
}
static void xgpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip = gpiochip_get_data(gc);
int index = xgpio_index(chip, gpio);
int offset = xgpio_offset(chip, gpio);
spin_lock_irqsave(&chip->gpio_lock[index], flags);
if (val)
chip->gpio_state[index] |= BIT(offset);
else
chip->gpio_state[index] &= ~BIT(offset);
xgpio_writereg(mm_gc->regs + XGPIO_DATA_OFFSET +
xgpio_regoffset(chip, gpio), chip->gpio_state[index]);
spin_unlock_irqrestore(&chip->gpio_lock[index], flags);
}
static int xgpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip = gpiochip_get_data(gc);
int index = xgpio_index(chip, gpio);
int offset = xgpio_offset(chip, gpio);
spin_lock_irqsave(&chip->gpio_lock[index], flags);
chip->gpio_dir[index] |= BIT(offset);
xgpio_writereg(mm_gc->regs + XGPIO_TRI_OFFSET +
xgpio_regoffset(chip, gpio), chip->gpio_dir[index]);
spin_unlock_irqrestore(&chip->gpio_lock[index], flags);
return 0;
}
static int xgpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct xgpio_instance *chip = gpiochip_get_data(gc);
int index = xgpio_index(chip, gpio);
int offset = xgpio_offset(chip, gpio);
spin_lock_irqsave(&chip->gpio_lock[index], flags);
if (val)
chip->gpio_state[index] |= BIT(offset);
else
chip->gpio_state[index] &= ~BIT(offset);
xgpio_writereg(mm_gc->regs + XGPIO_DATA_OFFSET +
xgpio_regoffset(chip, gpio), chip->gpio_state[index]);
chip->gpio_dir[index] &= ~BIT(offset);
xgpio_writereg(mm_gc->regs + XGPIO_TRI_OFFSET +
xgpio_regoffset(chip, gpio), chip->gpio_dir[index]);
spin_unlock_irqrestore(&chip->gpio_lock[index], flags);
return 0;
}
static void xgpio_save_regs(struct of_mm_gpio_chip *mm_gc)
{
struct xgpio_instance *chip =
container_of(mm_gc, struct xgpio_instance, mmchip);
xgpio_writereg(mm_gc->regs + XGPIO_DATA_OFFSET, chip->gpio_state[0]);
xgpio_writereg(mm_gc->regs + XGPIO_TRI_OFFSET, chip->gpio_dir[0]);
if (!chip->gpio_width[1])
return;
xgpio_writereg(mm_gc->regs + XGPIO_DATA_OFFSET + XGPIO_CHANNEL_OFFSET,
chip->gpio_state[1]);
xgpio_writereg(mm_gc->regs + XGPIO_TRI_OFFSET + XGPIO_CHANNEL_OFFSET,
chip->gpio_dir[1]);
}
static int xgpio_remove(struct platform_device *pdev)
{
struct xgpio_instance *chip = platform_get_drvdata(pdev);
of_mm_gpiochip_remove(&chip->mmchip);
return 0;
}
static int xgpio_probe(struct platform_device *pdev)
{
struct xgpio_instance *chip;
int status = 0;
struct device_node *np = pdev->dev.of_node;
u32 is_dual;
chip = devm_kzalloc(&pdev->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
platform_set_drvdata(pdev, chip);
of_property_read_u32(np, "xlnx,dout-default", &chip->gpio_state[0]);
if (of_property_read_u32(np, "xlnx,tri-default", &chip->gpio_dir[0]))
chip->gpio_dir[0] = 0xFFFFFFFF;
if (of_property_read_u32(np, "xlnx,gpio-width", &chip->gpio_width[0]))
chip->gpio_width[0] = 32;
spin_lock_init(&chip->gpio_lock[0]);
if (of_property_read_u32(np, "xlnx,is-dual", &is_dual))
is_dual = 0;
if (is_dual) {
of_property_read_u32(np, "xlnx,dout-default-2",
&chip->gpio_state[1]);
if (of_property_read_u32(np, "xlnx,tri-default-2",
&chip->gpio_dir[1]))
chip->gpio_dir[1] = 0xFFFFFFFF;
if (of_property_read_u32(np, "xlnx,gpio2-width",
&chip->gpio_width[1]))
chip->gpio_width[1] = 32;
spin_lock_init(&chip->gpio_lock[1]);
}
chip->mmchip.gc.ngpio = chip->gpio_width[0] + chip->gpio_width[1];
chip->mmchip.gc.parent = &pdev->dev;
chip->mmchip.gc.direction_input = xgpio_dir_in;
chip->mmchip.gc.direction_output = xgpio_dir_out;
chip->mmchip.gc.get = xgpio_get;
chip->mmchip.gc.set = xgpio_set;
chip->mmchip.save_regs = xgpio_save_regs;
status = of_mm_gpiochip_add_data(np, &chip->mmchip, chip);
if (status) {
pr_err("%s: error in probe function with status %d\n",
np->full_name, status);
return status;
}
return 0;
}
static int __init xgpio_init(void)
{
return platform_driver_register(&xgpio_plat_driver);
}
static void __exit xgpio_exit(void)
{
platform_driver_unregister(&xgpio_plat_driver);
}
