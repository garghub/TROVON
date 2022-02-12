static void _gef_gpio_set(void __iomem *reg, unsigned int offset, int value)
{
unsigned int data;
data = ioread32be(reg);
if (value & 0x1)
data = data | (0x1 << offset);
else
data = data & ~(0x1 << offset);
iowrite32be(data, reg);
}
static int gef_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
unsigned int data;
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
data = ioread32be(mmchip->regs + GEF_GPIO_DIRECT);
data = data | (0x1 << offset);
iowrite32be(data, mmchip->regs + GEF_GPIO_DIRECT);
return 0;
}
static int gef_gpio_dir_out(struct gpio_chip *chip, unsigned offset, int value)
{
unsigned int data;
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
_gef_gpio_set(mmchip->regs + GEF_GPIO_OUT, offset, value);
data = ioread32be(mmchip->regs + GEF_GPIO_DIRECT);
data = data & ~(0x1 << offset);
iowrite32be(data, mmchip->regs + GEF_GPIO_DIRECT);
return 0;
}
static int gef_gpio_get(struct gpio_chip *chip, unsigned offset)
{
unsigned int data;
int state = 0;
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
data = ioread32be(mmchip->regs + GEF_GPIO_IN);
state = (int)((data >> offset) & 0x1);
return state;
}
static void gef_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
_gef_gpio_set(mmchip->regs + GEF_GPIO_OUT, offset, value);
}
static int __init gef_gpio_init(void)
{
struct device_node *np;
int retval;
struct of_mm_gpio_chip *gef_gpio_chip;
for_each_compatible_node(np, NULL, "gef,sbc610-gpio") {
pr_debug("%s: Initialising GEF GPIO\n", np->full_name);
gef_gpio_chip = kzalloc(sizeof(*gef_gpio_chip), GFP_KERNEL);
if (!gef_gpio_chip) {
pr_err("%s: Unable to allocate structure\n",
np->full_name);
continue;
}
gef_gpio_chip->gc.of_gpio_n_cells = 2;
gef_gpio_chip->gc.ngpio = 19;
gef_gpio_chip->gc.direction_input = gef_gpio_dir_in;
gef_gpio_chip->gc.direction_output = gef_gpio_dir_out;
gef_gpio_chip->gc.get = gef_gpio_get;
gef_gpio_chip->gc.set = gef_gpio_set;
retval = of_mm_gpiochip_add(np, gef_gpio_chip);
if (retval) {
kfree(gef_gpio_chip);
pr_err("%s: Unable to add GPIO\n", np->full_name);
}
}
for_each_compatible_node(np, NULL, "gef,sbc310-gpio") {
pr_debug("%s: Initialising GEF GPIO\n", np->full_name);
gef_gpio_chip = kzalloc(sizeof(*gef_gpio_chip), GFP_KERNEL);
if (!gef_gpio_chip) {
pr_err("%s: Unable to allocate structure\n",
np->full_name);
continue;
}
gef_gpio_chip->gc.of_gpio_n_cells = 2;
gef_gpio_chip->gc.ngpio = 6;
gef_gpio_chip->gc.direction_input = gef_gpio_dir_in;
gef_gpio_chip->gc.direction_output = gef_gpio_dir_out;
gef_gpio_chip->gc.get = gef_gpio_get;
gef_gpio_chip->gc.set = gef_gpio_set;
retval = of_mm_gpiochip_add(np, gef_gpio_chip);
if (retval) {
kfree(gef_gpio_chip);
pr_err("%s: Unable to add GPIO\n", np->full_name);
}
}
for_each_compatible_node(np, NULL, "ge,imp3a-gpio") {
pr_debug("%s: Initialising GE GPIO\n", np->full_name);
gef_gpio_chip = kzalloc(sizeof(*gef_gpio_chip), GFP_KERNEL);
if (!gef_gpio_chip) {
pr_err("%s: Unable to allocate structure\n",
np->full_name);
continue;
}
gef_gpio_chip->gc.of_gpio_n_cells = 2;
gef_gpio_chip->gc.ngpio = 16;
gef_gpio_chip->gc.direction_input = gef_gpio_dir_in;
gef_gpio_chip->gc.direction_output = gef_gpio_dir_out;
gef_gpio_chip->gc.get = gef_gpio_get;
gef_gpio_chip->gc.set = gef_gpio_set;
retval = of_mm_gpiochip_add(np, gef_gpio_chip);
if (retval) {
kfree(gef_gpio_chip);
pr_err("%s: Unable to add GPIO\n", np->full_name);
}
}
return 0;
}
