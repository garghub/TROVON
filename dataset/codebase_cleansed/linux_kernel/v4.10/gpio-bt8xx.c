static int bt8xxgpio_gpio_direction_input(struct gpio_chip *gpio, unsigned nr)
{
struct bt8xxgpio *bg = gpiochip_get_data(gpio);
unsigned long flags;
u32 outen, data;
spin_lock_irqsave(&bg->lock, flags);
data = bgread(BT848_GPIO_DATA);
data &= ~(1 << nr);
bgwrite(data, BT848_GPIO_DATA);
outen = bgread(BT848_GPIO_OUT_EN);
outen &= ~(1 << nr);
bgwrite(outen, BT848_GPIO_OUT_EN);
spin_unlock_irqrestore(&bg->lock, flags);
return 0;
}
static int bt8xxgpio_gpio_get(struct gpio_chip *gpio, unsigned nr)
{
struct bt8xxgpio *bg = gpiochip_get_data(gpio);
unsigned long flags;
u32 val;
spin_lock_irqsave(&bg->lock, flags);
val = bgread(BT848_GPIO_DATA);
spin_unlock_irqrestore(&bg->lock, flags);
return !!(val & (1 << nr));
}
static int bt8xxgpio_gpio_direction_output(struct gpio_chip *gpio,
unsigned nr, int val)
{
struct bt8xxgpio *bg = gpiochip_get_data(gpio);
unsigned long flags;
u32 outen, data;
spin_lock_irqsave(&bg->lock, flags);
outen = bgread(BT848_GPIO_OUT_EN);
outen |= (1 << nr);
bgwrite(outen, BT848_GPIO_OUT_EN);
data = bgread(BT848_GPIO_DATA);
if (val)
data |= (1 << nr);
else
data &= ~(1 << nr);
bgwrite(data, BT848_GPIO_DATA);
spin_unlock_irqrestore(&bg->lock, flags);
return 0;
}
static void bt8xxgpio_gpio_set(struct gpio_chip *gpio,
unsigned nr, int val)
{
struct bt8xxgpio *bg = gpiochip_get_data(gpio);
unsigned long flags;
u32 data;
spin_lock_irqsave(&bg->lock, flags);
data = bgread(BT848_GPIO_DATA);
if (val)
data |= (1 << nr);
else
data &= ~(1 << nr);
bgwrite(data, BT848_GPIO_DATA);
spin_unlock_irqrestore(&bg->lock, flags);
}
static void bt8xxgpio_gpio_setup(struct bt8xxgpio *bg)
{
struct gpio_chip *c = &bg->gpio;
c->label = dev_name(&bg->pdev->dev);
c->owner = THIS_MODULE;
c->direction_input = bt8xxgpio_gpio_direction_input;
c->get = bt8xxgpio_gpio_get;
c->direction_output = bt8xxgpio_gpio_direction_output;
c->set = bt8xxgpio_gpio_set;
c->dbg_show = NULL;
c->base = modparam_gpiobase;
c->ngpio = BT8XXGPIO_NR_GPIOS;
c->can_sleep = false;
}
static int bt8xxgpio_probe(struct pci_dev *dev,
const struct pci_device_id *pci_id)
{
struct bt8xxgpio *bg;
int err;
bg = devm_kzalloc(&dev->dev, sizeof(struct bt8xxgpio), GFP_KERNEL);
if (!bg)
return -ENOMEM;
bg->pdev = dev;
spin_lock_init(&bg->lock);
err = pci_enable_device(dev);
if (err) {
printk(KERN_ERR "bt8xxgpio: Can't enable device.\n");
return err;
}
if (!devm_request_mem_region(&dev->dev, pci_resource_start(dev, 0),
pci_resource_len(dev, 0),
"bt8xxgpio")) {
printk(KERN_WARNING "bt8xxgpio: Can't request iomem (0x%llx).\n",
(unsigned long long)pci_resource_start(dev, 0));
err = -EBUSY;
goto err_disable;
}
pci_set_master(dev);
pci_set_drvdata(dev, bg);
bg->mmio = devm_ioremap(&dev->dev, pci_resource_start(dev, 0), 0x1000);
if (!bg->mmio) {
printk(KERN_ERR "bt8xxgpio: ioremap() failed\n");
err = -EIO;
goto err_disable;
}
bgwrite(0, BT848_INT_MASK);
bgwrite(0, BT848_GPIO_DMA_CTL);
bgwrite(0, BT848_GPIO_REG_INP);
bgwrite(0, BT848_GPIO_OUT_EN);
bt8xxgpio_gpio_setup(bg);
err = gpiochip_add_data(&bg->gpio, bg);
if (err) {
printk(KERN_ERR "bt8xxgpio: Failed to register GPIOs\n");
goto err_disable;
}
return 0;
err_disable:
pci_disable_device(dev);
return err;
}
static void bt8xxgpio_remove(struct pci_dev *pdev)
{
struct bt8xxgpio *bg = pci_get_drvdata(pdev);
gpiochip_remove(&bg->gpio);
bgwrite(0, BT848_INT_MASK);
bgwrite(~0x0, BT848_INT_STAT);
bgwrite(0x0, BT848_GPIO_OUT_EN);
pci_disable_device(pdev);
}
static int bt8xxgpio_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct bt8xxgpio *bg = pci_get_drvdata(pdev);
unsigned long flags;
spin_lock_irqsave(&bg->lock, flags);
bg->saved_outen = bgread(BT848_GPIO_OUT_EN);
bg->saved_data = bgread(BT848_GPIO_DATA);
bgwrite(0, BT848_INT_MASK);
bgwrite(~0x0, BT848_INT_STAT);
bgwrite(0x0, BT848_GPIO_OUT_EN);
spin_unlock_irqrestore(&bg->lock, flags);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int bt8xxgpio_resume(struct pci_dev *pdev)
{
struct bt8xxgpio *bg = pci_get_drvdata(pdev);
unsigned long flags;
int err;
pci_set_power_state(pdev, PCI_D0);
err = pci_enable_device(pdev);
if (err)
return err;
pci_restore_state(pdev);
spin_lock_irqsave(&bg->lock, flags);
bgwrite(0, BT848_INT_MASK);
bgwrite(0, BT848_GPIO_DMA_CTL);
bgwrite(0, BT848_GPIO_REG_INP);
bgwrite(bg->saved_outen, BT848_GPIO_OUT_EN);
bgwrite(bg->saved_data & bg->saved_outen,
BT848_GPIO_DATA);
spin_unlock_irqrestore(&bg->lock, flags);
return 0;
}
