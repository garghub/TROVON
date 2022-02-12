static int pt_gpio_request(struct gpio_chip *gc, unsigned offset)
{
struct pt_gpio_chip *pt_gpio = gpiochip_get_data(gc);
unsigned long flags;
u32 using_pins;
dev_dbg(gc->parent, "pt_gpio_request offset=%x\n", offset);
spin_lock_irqsave(&gc->bgpio_lock, flags);
using_pins = readl(pt_gpio->reg_base + PT_SYNC_REG);
if (using_pins & BIT(offset)) {
dev_warn(gc->parent, "PT GPIO pin %x reconfigured\n",
offset);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return -EINVAL;
}
writel(using_pins | BIT(offset), pt_gpio->reg_base + PT_SYNC_REG);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
return 0;
}
static void pt_gpio_free(struct gpio_chip *gc, unsigned offset)
{
struct pt_gpio_chip *pt_gpio = gpiochip_get_data(gc);
unsigned long flags;
u32 using_pins;
spin_lock_irqsave(&gc->bgpio_lock, flags);
using_pins = readl(pt_gpio->reg_base + PT_SYNC_REG);
using_pins &= ~BIT(offset);
writel(using_pins, pt_gpio->reg_base + PT_SYNC_REG);
spin_unlock_irqrestore(&gc->bgpio_lock, flags);
dev_dbg(gc->parent, "pt_gpio_free offset=%x\n", offset);
}
static int pt_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct acpi_device *acpi_dev;
acpi_handle handle = ACPI_HANDLE(dev);
struct pt_gpio_chip *pt_gpio;
struct resource *res_mem;
int ret = 0;
if (acpi_bus_get_device(handle, &acpi_dev)) {
dev_err(dev, "PT GPIO device node not found\n");
return -ENODEV;
}
pt_gpio = devm_kzalloc(dev, sizeof(struct pt_gpio_chip), GFP_KERNEL);
if (!pt_gpio)
return -ENOMEM;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_mem) {
dev_err(&pdev->dev, "Failed to get MMIO resource for PT GPIO.\n");
return -EINVAL;
}
pt_gpio->reg_base = devm_ioremap_resource(dev, res_mem);
if (IS_ERR(pt_gpio->reg_base)) {
dev_err(&pdev->dev, "Failed to map MMIO resource for PT GPIO.\n");
return PTR_ERR(pt_gpio->reg_base);
}
ret = bgpio_init(&pt_gpio->gc, dev, 4,
pt_gpio->reg_base + PT_INPUTDATA_REG,
pt_gpio->reg_base + PT_OUTPUTDATA_REG, NULL,
pt_gpio->reg_base + PT_DIRECTION_REG, NULL,
BGPIOF_READ_OUTPUT_REG_SET);
if (ret) {
dev_err(&pdev->dev, "bgpio_init failed\n");
return ret;
}
pt_gpio->gc.owner = THIS_MODULE;
pt_gpio->gc.request = pt_gpio_request;
pt_gpio->gc.free = pt_gpio_free;
pt_gpio->gc.ngpio = PT_TOTAL_GPIO;
#if defined(CONFIG_OF_GPIO)
pt_gpio->gc.of_node = pdev->dev.of_node;
#endif
ret = gpiochip_add_data(&pt_gpio->gc, pt_gpio);
if (ret) {
dev_err(&pdev->dev, "Failed to register GPIO lib\n");
return ret;
}
platform_set_drvdata(pdev, pt_gpio);
writel(0, pt_gpio->reg_base + PT_SYNC_REG);
writel(0, pt_gpio->reg_base + PT_CLOCKRATE_REG);
dev_dbg(&pdev->dev, "PT GPIO driver loaded\n");
return ret;
}
static int pt_gpio_remove(struct platform_device *pdev)
{
struct pt_gpio_chip *pt_gpio = platform_get_drvdata(pdev);
gpiochip_remove(&pt_gpio->gc);
return 0;
}
