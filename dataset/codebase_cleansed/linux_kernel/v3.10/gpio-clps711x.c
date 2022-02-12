static int gpio_clps711x_get(struct gpio_chip *chip, unsigned offset)
{
return !!(readb(clps711x_port(chip)) & (1 << offset));
}
static void gpio_clps711x_set(struct gpio_chip *chip, unsigned offset,
int value)
{
int tmp;
unsigned long flags;
struct clps711x_gpio *gpio = dev_get_drvdata(chip->dev);
spin_lock_irqsave(&gpio->lock, flags);
tmp = readb(clps711x_port(chip)) & ~(1 << offset);
if (value)
tmp |= 1 << offset;
writeb(tmp, clps711x_port(chip));
spin_unlock_irqrestore(&gpio->lock, flags);
}
static int gpio_clps711x_dir_in(struct gpio_chip *chip, unsigned offset)
{
int tmp;
unsigned long flags;
struct clps711x_gpio *gpio = dev_get_drvdata(chip->dev);
spin_lock_irqsave(&gpio->lock, flags);
tmp = readb(clps711x_pdir(chip)) & ~(1 << offset);
writeb(tmp, clps711x_pdir(chip));
spin_unlock_irqrestore(&gpio->lock, flags);
return 0;
}
static int gpio_clps711x_dir_out(struct gpio_chip *chip, unsigned offset,
int value)
{
int tmp;
unsigned long flags;
struct clps711x_gpio *gpio = dev_get_drvdata(chip->dev);
spin_lock_irqsave(&gpio->lock, flags);
tmp = readb(clps711x_pdir(chip)) | (1 << offset);
writeb(tmp, clps711x_pdir(chip));
tmp = readb(clps711x_port(chip)) & ~(1 << offset);
if (value)
tmp |= 1 << offset;
writeb(tmp, clps711x_port(chip));
spin_unlock_irqrestore(&gpio->lock, flags);
return 0;
}
static int gpio_clps711x_dir_in_inv(struct gpio_chip *chip, unsigned offset)
{
int tmp;
unsigned long flags;
struct clps711x_gpio *gpio = dev_get_drvdata(chip->dev);
spin_lock_irqsave(&gpio->lock, flags);
tmp = readb(clps711x_pdir(chip)) | (1 << offset);
writeb(tmp, clps711x_pdir(chip));
spin_unlock_irqrestore(&gpio->lock, flags);
return 0;
}
static int gpio_clps711x_dir_out_inv(struct gpio_chip *chip, unsigned offset,
int value)
{
int tmp;
unsigned long flags;
struct clps711x_gpio *gpio = dev_get_drvdata(chip->dev);
spin_lock_irqsave(&gpio->lock, flags);
tmp = readb(clps711x_pdir(chip)) & ~(1 << offset);
writeb(tmp, clps711x_pdir(chip));
tmp = readb(clps711x_port(chip)) & ~(1 << offset);
if (value)
tmp |= 1 << offset;
writeb(tmp, clps711x_port(chip));
spin_unlock_irqrestore(&gpio->lock, flags);
return 0;
}
static int __init gpio_clps711x_init(void)
{
int i;
struct platform_device *pdev;
struct clps711x_gpio *gpio;
pdev = platform_device_alloc(CLPS711X_GPIO_NAME, 0);
if (!pdev) {
pr_err("Cannot create platform device: %s\n",
CLPS711X_GPIO_NAME);
return -ENOMEM;
}
platform_device_add(pdev);
gpio = devm_kzalloc(&pdev->dev, sizeof(struct clps711x_gpio),
GFP_KERNEL);
if (!gpio) {
dev_err(&pdev->dev, "GPIO allocating memory error\n");
platform_device_unregister(pdev);
return -ENOMEM;
}
platform_set_drvdata(pdev, gpio);
spin_lock_init(&gpio->lock);
for (i = 0; i < CLPS711X_GPIO_PORTS; i++) {
gpio->chip[i].owner = THIS_MODULE;
gpio->chip[i].dev = &pdev->dev;
gpio->chip[i].label = clps711x_gpio_ports[i].name;
gpio->chip[i].base = i * 8;
gpio->chip[i].ngpio = clps711x_gpio_ports[i].nr;
gpio->chip[i].get = gpio_clps711x_get;
gpio->chip[i].set = gpio_clps711x_set;
if (!clps711x_gpio_ports[i].inv_dir) {
gpio->chip[i].direction_input = gpio_clps711x_dir_in;
gpio->chip[i].direction_output = gpio_clps711x_dir_out;
} else {
gpio->chip[i].direction_input = gpio_clps711x_dir_in_inv;
gpio->chip[i].direction_output = gpio_clps711x_dir_out_inv;
}
WARN_ON(gpiochip_add(&gpio->chip[i]));
}
dev_info(&pdev->dev, "GPIO driver initialized\n");
return 0;
}
