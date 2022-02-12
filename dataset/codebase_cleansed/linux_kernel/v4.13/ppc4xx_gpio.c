static int ppc4xx_gpio_get(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct ppc4xx_gpio __iomem *regs = mm_gc->regs;
return !!(in_be32(&regs->ir) & GPIO_MASK(gpio));
}
static inline void
__ppc4xx_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct ppc4xx_gpio __iomem *regs = mm_gc->regs;
if (val)
setbits32(&regs->or, GPIO_MASK(gpio));
else
clrbits32(&regs->or, GPIO_MASK(gpio));
}
static void
ppc4xx_gpio_set(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct ppc4xx_gpio_chip *chip = gpiochip_get_data(gc);
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
__ppc4xx_gpio_set(gc, gpio, val);
spin_unlock_irqrestore(&chip->lock, flags);
pr_debug("%s: gpio: %d val: %d\n", __func__, gpio, val);
}
static int ppc4xx_gpio_dir_in(struct gpio_chip *gc, unsigned int gpio)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct ppc4xx_gpio_chip *chip = gpiochip_get_data(gc);
struct ppc4xx_gpio __iomem *regs = mm_gc->regs;
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
clrbits32(&regs->odr, GPIO_MASK(gpio));
clrbits32(&regs->tcr, GPIO_MASK(gpio));
if (gpio < 16) {
clrbits32(&regs->osrl, GPIO_MASK2(gpio));
clrbits32(&regs->tsrl, GPIO_MASK2(gpio));
} else {
clrbits32(&regs->osrh, GPIO_MASK2(gpio));
clrbits32(&regs->tsrh, GPIO_MASK2(gpio));
}
spin_unlock_irqrestore(&chip->lock, flags);
return 0;
}
static int
ppc4xx_gpio_dir_out(struct gpio_chip *gc, unsigned int gpio, int val)
{
struct of_mm_gpio_chip *mm_gc = to_of_mm_gpio_chip(gc);
struct ppc4xx_gpio_chip *chip = gpiochip_get_data(gc);
struct ppc4xx_gpio __iomem *regs = mm_gc->regs;
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
__ppc4xx_gpio_set(gc, gpio, val);
clrbits32(&regs->odr, GPIO_MASK(gpio));
setbits32(&regs->tcr, GPIO_MASK(gpio));
if (gpio < 16) {
clrbits32(&regs->osrl, GPIO_MASK2(gpio));
clrbits32(&regs->tsrl, GPIO_MASK2(gpio));
} else {
clrbits32(&regs->osrh, GPIO_MASK2(gpio));
clrbits32(&regs->tsrh, GPIO_MASK2(gpio));
}
spin_unlock_irqrestore(&chip->lock, flags);
pr_debug("%s: gpio: %d val: %d\n", __func__, gpio, val);
return 0;
}
static int __init ppc4xx_add_gpiochips(void)
{
struct device_node *np;
for_each_compatible_node(np, NULL, "ibm,ppc4xx-gpio") {
int ret;
struct ppc4xx_gpio_chip *ppc4xx_gc;
struct of_mm_gpio_chip *mm_gc;
struct gpio_chip *gc;
ppc4xx_gc = kzalloc(sizeof(*ppc4xx_gc), GFP_KERNEL);
if (!ppc4xx_gc) {
ret = -ENOMEM;
goto err;
}
spin_lock_init(&ppc4xx_gc->lock);
mm_gc = &ppc4xx_gc->mm_gc;
gc = &mm_gc->gc;
gc->ngpio = 32;
gc->direction_input = ppc4xx_gpio_dir_in;
gc->direction_output = ppc4xx_gpio_dir_out;
gc->get = ppc4xx_gpio_get;
gc->set = ppc4xx_gpio_set;
ret = of_mm_gpiochip_add_data(np, mm_gc, ppc4xx_gc);
if (ret)
goto err;
continue;
err:
pr_err("%s: registration failed with status %d\n",
np->full_name, ret);
kfree(ppc4xx_gc);
}
return 0;
}
