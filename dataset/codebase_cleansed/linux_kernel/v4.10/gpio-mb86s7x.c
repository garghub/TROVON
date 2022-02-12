static int mb86s70_gpio_request(struct gpio_chip *gc, unsigned gpio)
{
struct mb86s70_gpio_chip *gchip = gpiochip_get_data(gc);
unsigned long flags;
u32 val;
spin_lock_irqsave(&gchip->lock, flags);
val = readl(gchip->base + PFR(gpio));
if (!(val & OFFSET(gpio))) {
spin_unlock_irqrestore(&gchip->lock, flags);
return -EINVAL;
}
val &= ~OFFSET(gpio);
writel(val, gchip->base + PFR(gpio));
spin_unlock_irqrestore(&gchip->lock, flags);
return 0;
}
static void mb86s70_gpio_free(struct gpio_chip *gc, unsigned gpio)
{
struct mb86s70_gpio_chip *gchip = gpiochip_get_data(gc);
unsigned long flags;
u32 val;
spin_lock_irqsave(&gchip->lock, flags);
val = readl(gchip->base + PFR(gpio));
val |= OFFSET(gpio);
writel(val, gchip->base + PFR(gpio));
spin_unlock_irqrestore(&gchip->lock, flags);
}
static int mb86s70_gpio_direction_input(struct gpio_chip *gc, unsigned gpio)
{
struct mb86s70_gpio_chip *gchip = gpiochip_get_data(gc);
unsigned long flags;
unsigned char val;
spin_lock_irqsave(&gchip->lock, flags);
val = readl(gchip->base + DDR(gpio));
val &= ~OFFSET(gpio);
writel(val, gchip->base + DDR(gpio));
spin_unlock_irqrestore(&gchip->lock, flags);
return 0;
}
static int mb86s70_gpio_direction_output(struct gpio_chip *gc,
unsigned gpio, int value)
{
struct mb86s70_gpio_chip *gchip = gpiochip_get_data(gc);
unsigned long flags;
unsigned char val;
spin_lock_irqsave(&gchip->lock, flags);
val = readl(gchip->base + PDR(gpio));
if (value)
val |= OFFSET(gpio);
else
val &= ~OFFSET(gpio);
writel(val, gchip->base + PDR(gpio));
val = readl(gchip->base + DDR(gpio));
val |= OFFSET(gpio);
writel(val, gchip->base + DDR(gpio));
spin_unlock_irqrestore(&gchip->lock, flags);
return 0;
}
static int mb86s70_gpio_get(struct gpio_chip *gc, unsigned gpio)
{
struct mb86s70_gpio_chip *gchip = gpiochip_get_data(gc);
return !!(readl(gchip->base + PDR(gpio)) & OFFSET(gpio));
}
static void mb86s70_gpio_set(struct gpio_chip *gc, unsigned gpio, int value)
{
struct mb86s70_gpio_chip *gchip = gpiochip_get_data(gc);
unsigned long flags;
unsigned char val;
spin_lock_irqsave(&gchip->lock, flags);
val = readl(gchip->base + PDR(gpio));
if (value)
val |= OFFSET(gpio);
else
val &= ~OFFSET(gpio);
writel(val, gchip->base + PDR(gpio));
spin_unlock_irqrestore(&gchip->lock, flags);
}
static int mb86s70_gpio_probe(struct platform_device *pdev)
{
struct mb86s70_gpio_chip *gchip;
struct resource *res;
int ret;
gchip = devm_kzalloc(&pdev->dev, sizeof(*gchip), GFP_KERNEL);
if (gchip == NULL)
return -ENOMEM;
platform_set_drvdata(pdev, gchip);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gchip->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(gchip->base))
return PTR_ERR(gchip->base);
gchip->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(gchip->clk))
return PTR_ERR(gchip->clk);
clk_prepare_enable(gchip->clk);
spin_lock_init(&gchip->lock);
gchip->gc.direction_output = mb86s70_gpio_direction_output;
gchip->gc.direction_input = mb86s70_gpio_direction_input;
gchip->gc.request = mb86s70_gpio_request;
gchip->gc.free = mb86s70_gpio_free;
gchip->gc.get = mb86s70_gpio_get;
gchip->gc.set = mb86s70_gpio_set;
gchip->gc.label = dev_name(&pdev->dev);
gchip->gc.ngpio = 32;
gchip->gc.owner = THIS_MODULE;
gchip->gc.parent = &pdev->dev;
gchip->gc.base = -1;
ret = gpiochip_add_data(&gchip->gc, gchip);
if (ret) {
dev_err(&pdev->dev, "couldn't register gpio driver\n");
clk_disable_unprepare(gchip->clk);
}
return ret;
}
static int mb86s70_gpio_remove(struct platform_device *pdev)
{
struct mb86s70_gpio_chip *gchip = platform_get_drvdata(pdev);
gpiochip_remove(&gchip->gc);
clk_disable_unprepare(gchip->clk);
return 0;
}
