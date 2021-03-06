static int pt_gpio_request(struct gpio_chip *gc, unsigned offset)
{
struct pt_gpio_chip *pt_gpio = to_pt_gpio(gc);
unsigned long flags;
u32 using_pins;
dev_dbg(gc->dev, "pt_gpio_request offset=%x\n", offset);
spin_lock_irqsave(&pt_gpio->lock, flags);
using_pins = readl(pt_gpio->reg_base + PT_SYNC_REG);
if (using_pins & BIT(offset)) {
dev_warn(gc->dev, "PT GPIO pin %x reconfigured\n",
offset);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
return -EINVAL;
}
writel(using_pins | BIT(offset), pt_gpio->reg_base + PT_SYNC_REG);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
return 0;
}
static void pt_gpio_free(struct gpio_chip *gc, unsigned offset)
{
struct pt_gpio_chip *pt_gpio = to_pt_gpio(gc);
unsigned long flags;
u32 using_pins;
spin_lock_irqsave(&pt_gpio->lock, flags);
using_pins = readl(pt_gpio->reg_base + PT_SYNC_REG);
using_pins &= ~BIT(offset);
writel(using_pins, pt_gpio->reg_base + PT_SYNC_REG);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
dev_dbg(gc->dev, "pt_gpio_free offset=%x\n", offset);
}
static void pt_gpio_set_value(struct gpio_chip *gc, unsigned offset, int value)
{
struct pt_gpio_chip *pt_gpio = to_pt_gpio(gc);
unsigned long flags;
u32 data;
dev_dbg(gc->dev, "pt_gpio_set_value offset=%x, value=%x\n",
offset, value);
spin_lock_irqsave(&pt_gpio->lock, flags);
data = readl(pt_gpio->reg_base + PT_OUTPUTDATA_REG);
data &= ~BIT(offset);
if (value)
data |= BIT(offset);
writel(data, pt_gpio->reg_base + PT_OUTPUTDATA_REG);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
}
static int pt_gpio_get_value(struct gpio_chip *gc, unsigned offset)
{
struct pt_gpio_chip *pt_gpio = to_pt_gpio(gc);
unsigned long flags;
u32 data;
spin_lock_irqsave(&pt_gpio->lock, flags);
data = readl(pt_gpio->reg_base + PT_DIRECTION_REG);
if (data & BIT(offset))
data = readl(pt_gpio->reg_base + PT_OUTPUTDATA_REG);
else
data = readl(pt_gpio->reg_base + PT_INPUTDATA_REG);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
data >>= offset;
data &= 1;
dev_dbg(gc->dev, "pt_gpio_get_value offset=%x, value=%x\n",
offset, data);
return data;
}
static int pt_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct pt_gpio_chip *pt_gpio = to_pt_gpio(gc);
unsigned long flags;
u32 data;
dev_dbg(gc->dev, "pt_gpio_dirction_input offset=%x\n", offset);
spin_lock_irqsave(&pt_gpio->lock, flags);
data = readl(pt_gpio->reg_base + PT_DIRECTION_REG);
data &= ~BIT(offset);
writel(data, pt_gpio->reg_base + PT_DIRECTION_REG);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
return 0;
}
static int pt_gpio_direction_output(struct gpio_chip *gc,
unsigned offset, int value)
{
struct pt_gpio_chip *pt_gpio = to_pt_gpio(gc);
unsigned long flags;
u32 data;
dev_dbg(gc->dev, "pt_gpio_direction_output offset=%x, value=%x\n",
offset, value);
spin_lock_irqsave(&pt_gpio->lock, flags);
data = readl(pt_gpio->reg_base + PT_OUTPUTDATA_REG);
if (value)
data |= BIT(offset);
else
data &= ~BIT(offset);
writel(data, pt_gpio->reg_base + PT_OUTPUTDATA_REG);
data = readl(pt_gpio->reg_base + PT_DIRECTION_REG);
data |= BIT(offset);
writel(data, pt_gpio->reg_base + PT_DIRECTION_REG);
spin_unlock_irqrestore(&pt_gpio->lock, flags);
return 0;
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
spin_lock_init(&pt_gpio->lock);
pt_gpio->gc.label = pdev->name;
pt_gpio->gc.owner = THIS_MODULE;
pt_gpio->gc.dev = dev;
pt_gpio->gc.request = pt_gpio_request;
pt_gpio->gc.free = pt_gpio_free;
pt_gpio->gc.direction_input = pt_gpio_direction_input;
pt_gpio->gc.direction_output = pt_gpio_direction_output;
pt_gpio->gc.get = pt_gpio_get_value;
pt_gpio->gc.set = pt_gpio_set_value;
pt_gpio->gc.base = -1;
pt_gpio->gc.ngpio = PT_TOTAL_GPIO;
#if defined(CONFIG_OF_GPIO)
pt_gpio->gc.of_node = pdev->dev.of_node;
#endif
ret = gpiochip_add(&pt_gpio->gc);
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
