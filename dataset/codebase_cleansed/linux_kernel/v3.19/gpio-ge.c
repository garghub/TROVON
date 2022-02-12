static void gef_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
unsigned int data;
data = ioread32be(mmchip->regs + GEF_GPIO_OUT);
if (value)
data = data | BIT(offset);
else
data = data & ~BIT(offset);
iowrite32be(data, mmchip->regs + GEF_GPIO_OUT);
}
static int gef_gpio_dir_in(struct gpio_chip *chip, unsigned offset)
{
unsigned int data;
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
data = ioread32be(mmchip->regs + GEF_GPIO_DIRECT);
data = data | BIT(offset);
iowrite32be(data, mmchip->regs + GEF_GPIO_DIRECT);
return 0;
}
static int gef_gpio_dir_out(struct gpio_chip *chip, unsigned offset, int value)
{
unsigned int data;
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
gef_gpio_set(mmchip->regs + GEF_GPIO_OUT, offset, value);
data = ioread32be(mmchip->regs + GEF_GPIO_DIRECT);
data = data & ~BIT(offset);
iowrite32be(data, mmchip->regs + GEF_GPIO_DIRECT);
return 0;
}
static int gef_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct of_mm_gpio_chip *mmchip = to_of_mm_gpio_chip(chip);
return !!(ioread32be(mmchip->regs + GEF_GPIO_IN) & BIT(offset));
}
static int __init gef_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id =
of_match_device(gef_gpio_ids, &pdev->dev);
struct of_mm_gpio_chip *mmchip;
mmchip = devm_kzalloc(&pdev->dev, sizeof(*mmchip), GFP_KERNEL);
if (!mmchip)
return -ENOMEM;
mmchip->gc.ngpio = (u16)(uintptr_t)of_id->data;
mmchip->gc.of_gpio_n_cells = 2;
mmchip->gc.direction_input = gef_gpio_dir_in;
mmchip->gc.direction_output = gef_gpio_dir_out;
mmchip->gc.get = gef_gpio_get;
mmchip->gc.set = gef_gpio_set;
return of_mm_gpiochip_add(pdev->dev.of_node, mmchip);
}
