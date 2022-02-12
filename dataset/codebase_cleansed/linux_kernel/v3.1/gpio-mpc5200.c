static int mpc52xx_wkup_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpio_wkup __iomem *regs = mm_gc->regs;
unsigned int ret;
ret = (in_8(&regs->wkup_ival) >> (7 - gpio)) & 1;
pr_debug("%s: gpio: %d ret: %d\n", __func__, gpio, ret);
return ret;
}
static inline void
__mpc52xx_wkup_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpiochip *chip = container_of(mm_gc,
struct mpc52xx_gpiochip, mmchip);
struct mpc52xx_gpio_wkup __iomem *regs = mm_gc->regs;
if (val)
chip->shadow_dvo |= 1 << (7 - gpio);
else
chip->shadow_dvo &= ~(1 << (7 - gpio));
out_8(&regs->wkup_dvo, chip->shadow_dvo);
}
static void
mpc52xx_wkup_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
__mpc52xx_wkup_gpio_set(gc, gpio, val);
spin_unlock_irqrestore(&gpio_lock, flags);
pr_debug("%s: gpio: %d val: %d\n", __func__, gpio, val);
}
static int mpc52xx_wkup_gpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpiochip *chip = container_of(mm_gc,
struct mpc52xx_gpiochip, mmchip);
struct mpc52xx_gpio_wkup __iomem *regs = mm_gc->regs;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
chip->shadow_ddr &= ~(1 << (7 - gpio));
out_8(&regs->wkup_ddr, chip->shadow_ddr);
chip->shadow_gpioe |= 1 << (7 - gpio);
out_8(&regs->wkup_gpioe, chip->shadow_gpioe);
spin_unlock_irqrestore(&gpio_lock, flags);
return 0;
}
static int
mpc52xx_wkup_gpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpio_wkup __iomem *regs = mm_gc->regs;
struct mpc52xx_gpiochip *chip = container_of(mm_gc,
struct mpc52xx_gpiochip, mmchip);
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
__mpc52xx_wkup_gpio_set(gc, gpio, val);
chip->shadow_ddr |= 1 << (7 - gpio);
out_8(&regs->wkup_ddr, chip->shadow_ddr);
chip->shadow_gpioe |= 1 << (7 - gpio);
out_8(&regs->wkup_gpioe, chip->shadow_gpioe);
spin_unlock_irqrestore(&gpio_lock, flags);
pr_debug("%s: gpio: %d val: %d\n", __func__, gpio, val);
return 0;
}
static int __devinit mpc52xx_wkup_gpiochip_probe(struct platform_device *ofdev)
{
struct mpc52xx_gpiochip *chip;
struct mpc52xx_gpio_wkup __iomem *regs;
struct gpio_chip *gc;
int ret;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
gc = &chip->mmchip.gc;
gc->ngpio = 8;
gc->direction_input = mpc52xx_wkup_gpio_dir_in;
gc->direction_output = mpc52xx_wkup_gpio_dir_out;
gc->get = mpc52xx_wkup_gpio_get;
gc->set = mpc52xx_wkup_gpio_set;
ret = of_mm_gpiochip_add(ofdev->dev.of_node, &chip->mmchip);
if (ret)
return ret;
regs = chip->mmchip.regs;
chip->shadow_gpioe = in_8(&regs->wkup_gpioe);
chip->shadow_ddr = in_8(&regs->wkup_ddr);
chip->shadow_dvo = in_8(&regs->wkup_dvo);
return 0;
}
static int mpc52xx_gpiochip_remove(struct platform_device *ofdev)
{
return -EBUSY;
}
static int mpc52xx_simple_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpio __iomem *regs = mm_gc->regs;
unsigned int ret;
ret = (in_be32(&regs->simple_ival) >> (31 - gpio)) & 1;
return ret;
}
static inline void
__mpc52xx_simple_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpiochip *chip = container_of(mm_gc,
struct mpc52xx_gpiochip, mmchip);
struct mpc52xx_gpio __iomem *regs = mm_gc->regs;
if (val)
chip->shadow_dvo |= 1 << (31 - gpio);
else
chip->shadow_dvo &= ~(1 << (31 - gpio));
out_be32(&regs->simple_dvo, chip->shadow_dvo);
}
static void
mpc52xx_simple_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
__mpc52xx_simple_gpio_set(gc, gpio, val);
spin_unlock_irqrestore(&gpio_lock, flags);
pr_debug("%s: gpio: %d val: %d\n", __func__, gpio, val);
}
static int mpc52xx_simple_gpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpiochip *chip = container_of(mm_gc,
struct mpc52xx_gpiochip, mmchip);
struct mpc52xx_gpio __iomem *regs = mm_gc->regs;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
chip->shadow_ddr &= ~(1 << (31 - gpio));
out_be32(&regs->simple_ddr, chip->shadow_ddr);
chip->shadow_gpioe |= 1 << (31 - gpio);
out_be32(&regs->simple_gpioe, chip->shadow_gpioe);
spin_unlock_irqrestore(&gpio_lock, flags);
return 0;
}
static int
mpc52xx_simple_gpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct mpc52xx_gpiochip *chip = container_of(mm_gc,
struct mpc52xx_gpiochip, mmchip);
struct mpc52xx_gpio __iomem *regs = mm_gc->regs;
unsigned long flags;
spin_lock_irqsave(&gpio_lock, flags);
__mpc52xx_simple_gpio_set(gc, gpio, val);
chip->shadow_ddr |= 1 << (31 - gpio);
out_be32(&regs->simple_ddr, chip->shadow_ddr);
chip->shadow_gpioe |= 1 << (31 - gpio);
out_be32(&regs->simple_gpioe, chip->shadow_gpioe);
spin_unlock_irqrestore(&gpio_lock, flags);
pr_debug("%s: gpio: %d val: %d\n", __func__, gpio, val);
return 0;
}
static int __devinit mpc52xx_simple_gpiochip_probe(struct platform_device *ofdev)
{
struct mpc52xx_gpiochip *chip;
struct gpio_chip *gc;
struct mpc52xx_gpio __iomem *regs;
int ret;
chip = kzalloc(sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
gc = &chip->mmchip.gc;
gc->ngpio = 32;
gc->direction_input = mpc52xx_simple_gpio_dir_in;
gc->direction_output = mpc52xx_simple_gpio_dir_out;
gc->get = mpc52xx_simple_gpio_get;
gc->set = mpc52xx_simple_gpio_set;
ret = of_mm_gpiochip_add(ofdev->dev.of_node, &chip->mmchip);
if (ret)
return ret;
regs = chip->mmchip.regs;
chip->shadow_gpioe = in_be32(&regs->simple_gpioe);
chip->shadow_ddr = in_be32(&regs->simple_ddr);
chip->shadow_dvo = in_be32(&regs->simple_dvo);
return 0;
}
static int __init mpc52xx_gpio_init(void)
{
if (platform_driver_register(&mpc52xx_wkup_gpiochip_driver))
printk(KERN_ERR "Unable to register wakeup GPIO driver\n");
if (platform_driver_register(&mpc52xx_simple_gpiochip_driver))
printk(KERN_ERR "Unable to register simple GPIO driver\n");
return 0;
}
