static inline u32 zevio_gpio_port_get(struct zevio_gpio *c, unsigned pin,
unsigned port_offset)
{
unsigned section_offset = ((pin >> 3) & 3)*ZEVIO_GPIO_SECTION_SIZE;
return readl(IOMEM(c->chip.regs + section_offset + port_offset));
}
static inline void zevio_gpio_port_set(struct zevio_gpio *c, unsigned pin,
unsigned port_offset, u32 val)
{
unsigned section_offset = ((pin >> 3) & 3)*ZEVIO_GPIO_SECTION_SIZE;
writel(val, IOMEM(c->chip.regs + section_offset + port_offset));
}
static int zevio_gpio_get(struct gpio_chip *chip, unsigned pin)
{
struct zevio_gpio *controller = gpiochip_get_data(chip);
u32 val, dir;
spin_lock(&controller->lock);
dir = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_DIRECTION);
if (dir & BIT(ZEVIO_GPIO_BIT(pin)))
val = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_INPUT);
else
val = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_OUTPUT);
spin_unlock(&controller->lock);
return (val >> ZEVIO_GPIO_BIT(pin)) & 0x1;
}
static void zevio_gpio_set(struct gpio_chip *chip, unsigned pin, int value)
{
struct zevio_gpio *controller = gpiochip_get_data(chip);
u32 val;
spin_lock(&controller->lock);
val = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_OUTPUT);
if (value)
val |= BIT(ZEVIO_GPIO_BIT(pin));
else
val &= ~BIT(ZEVIO_GPIO_BIT(pin));
zevio_gpio_port_set(controller, pin, ZEVIO_GPIO_OUTPUT, val);
spin_unlock(&controller->lock);
}
static int zevio_gpio_direction_input(struct gpio_chip *chip, unsigned pin)
{
struct zevio_gpio *controller = gpiochip_get_data(chip);
u32 val;
spin_lock(&controller->lock);
val = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_DIRECTION);
val |= BIT(ZEVIO_GPIO_BIT(pin));
zevio_gpio_port_set(controller, pin, ZEVIO_GPIO_DIRECTION, val);
spin_unlock(&controller->lock);
return 0;
}
static int zevio_gpio_direction_output(struct gpio_chip *chip,
unsigned pin, int value)
{
struct zevio_gpio *controller = gpiochip_get_data(chip);
u32 val;
spin_lock(&controller->lock);
val = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_OUTPUT);
if (value)
val |= BIT(ZEVIO_GPIO_BIT(pin));
else
val &= ~BIT(ZEVIO_GPIO_BIT(pin));
zevio_gpio_port_set(controller, pin, ZEVIO_GPIO_OUTPUT, val);
val = zevio_gpio_port_get(controller, pin, ZEVIO_GPIO_DIRECTION);
val &= ~BIT(ZEVIO_GPIO_BIT(pin));
zevio_gpio_port_set(controller, pin, ZEVIO_GPIO_DIRECTION, val);
spin_unlock(&controller->lock);
return 0;
}
static int zevio_gpio_to_irq(struct gpio_chip *chip, unsigned pin)
{
return -ENXIO;
}
static int zevio_gpio_probe(struct platform_device *pdev)
{
struct zevio_gpio *controller;
int status, i;
controller = devm_kzalloc(&pdev->dev, sizeof(*controller), GFP_KERNEL);
if (!controller)
return -ENOMEM;
platform_set_drvdata(pdev, controller);
controller->chip.gc = zevio_gpio_chip;
controller->chip.gc.parent = &pdev->dev;
status = of_mm_gpiochip_add_data(pdev->dev.of_node,
&(controller->chip),
controller);
if (status) {
dev_err(&pdev->dev, "failed to add gpiochip: %d\n", status);
return status;
}
spin_lock_init(&controller->lock);
for (i = 0; i < controller->chip.gc.ngpio; i += 8)
zevio_gpio_port_set(controller, i, ZEVIO_GPIO_INT_MASK, 0xFF);
dev_dbg(controller->chip.gc.parent, "ZEVIO GPIO controller set up!\n");
return 0;
}
static int zevio_gpio_remove(struct platform_device *pdev)
{
struct zevio_gpio *controller = platform_get_drvdata(pdev);
of_mm_gpiochip_remove(&controller->chip);
return 0;
}
