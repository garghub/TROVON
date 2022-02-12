static void ioh_gpio_set(struct gpio_chip *gpio, unsigned nr, int val)
{
u32 reg_val;
struct ioh_gpio *chip = container_of(gpio, struct ioh_gpio, gpio);
mutex_lock(&chip->lock);
reg_val = ioread32(&chip->reg->regs[chip->ch].po);
if (val)
reg_val |= (1 << nr);
else
reg_val &= ~(1 << nr);
iowrite32(reg_val, &chip->reg->regs[chip->ch].po);
mutex_unlock(&chip->lock);
}
static int ioh_gpio_get(struct gpio_chip *gpio, unsigned nr)
{
struct ioh_gpio *chip = container_of(gpio, struct ioh_gpio, gpio);
return ioread32(&chip->reg->regs[chip->ch].pi) & (1 << nr);
}
static int ioh_gpio_direction_output(struct gpio_chip *gpio, unsigned nr,
int val)
{
struct ioh_gpio *chip = container_of(gpio, struct ioh_gpio, gpio);
u32 pm;
u32 reg_val;
mutex_lock(&chip->lock);
pm = ioread32(&chip->reg->regs[chip->ch].pm) &
((1 << num_ports[chip->ch]) - 1);
pm |= (1 << nr);
iowrite32(pm, &chip->reg->regs[chip->ch].pm);
reg_val = ioread32(&chip->reg->regs[chip->ch].po);
if (val)
reg_val |= (1 << nr);
else
reg_val &= ~(1 << nr);
iowrite32(reg_val, &chip->reg->regs[chip->ch].po);
mutex_unlock(&chip->lock);
return 0;
}
static int ioh_gpio_direction_input(struct gpio_chip *gpio, unsigned nr)
{
struct ioh_gpio *chip = container_of(gpio, struct ioh_gpio, gpio);
u32 pm;
mutex_lock(&chip->lock);
pm = ioread32(&chip->reg->regs[chip->ch].pm) &
((1 << num_ports[chip->ch]) - 1);
pm &= ~(1 << nr);
iowrite32(pm, &chip->reg->regs[chip->ch].pm);
mutex_unlock(&chip->lock);
return 0;
}
static void ioh_gpio_save_reg_conf(struct ioh_gpio *chip)
{
chip->ioh_gpio_reg.po_reg = ioread32(&chip->reg->regs[chip->ch].po);
chip->ioh_gpio_reg.pm_reg = ioread32(&chip->reg->regs[chip->ch].pm);
}
static void ioh_gpio_restore_reg_conf(struct ioh_gpio *chip)
{
iowrite32(chip->ioh_gpio_reg.po_reg, &chip->reg->regs[chip->ch].po);
iowrite32(chip->ioh_gpio_reg.pm_reg, &chip->reg->regs[chip->ch].pm);
}
static void ioh_gpio_setup(struct ioh_gpio *chip, int num_port)
{
struct gpio_chip *gpio = &chip->gpio;
gpio->label = dev_name(chip->dev);
gpio->owner = THIS_MODULE;
gpio->direction_input = ioh_gpio_direction_input;
gpio->get = ioh_gpio_get;
gpio->direction_output = ioh_gpio_direction_output;
gpio->set = ioh_gpio_set;
gpio->dbg_show = NULL;
gpio->base = -1;
gpio->ngpio = num_port;
gpio->can_sleep = 0;
}
static int __devinit ioh_gpio_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int ret;
int i;
struct ioh_gpio *chip;
void __iomem *base;
void __iomem *chip_save;
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "%s : pci_enable_device failed", __func__);
goto err_pci_enable;
}
ret = pci_request_regions(pdev, KBUILD_MODNAME);
if (ret) {
dev_err(&pdev->dev, "pci_request_regions failed-%d", ret);
goto err_request_regions;
}
base = pci_iomap(pdev, 1, 0);
if (base == 0) {
dev_err(&pdev->dev, "%s : pci_iomap failed", __func__);
ret = -ENOMEM;
goto err_iomap;
}
chip_save = kzalloc(sizeof(*chip) * 8, GFP_KERNEL);
if (chip_save == NULL) {
dev_err(&pdev->dev, "%s : kzalloc failed", __func__);
ret = -ENOMEM;
goto err_kzalloc;
}
chip = chip_save;
for (i = 0; i < 8; i++, chip++) {
chip->dev = &pdev->dev;
chip->base = base;
chip->reg = chip->base;
chip->ch = i;
mutex_init(&chip->lock);
ioh_gpio_setup(chip, num_ports[i]);
ret = gpiochip_add(&chip->gpio);
if (ret) {
dev_err(&pdev->dev, "IOH gpio: Failed to register GPIO\n");
goto err_gpiochip_add;
}
}
chip = chip_save;
pci_set_drvdata(pdev, chip);
return 0;
err_gpiochip_add:
while (--i >= 0) {
chip--;
ret = gpiochip_remove(&chip->gpio);
if (ret)
dev_err(&pdev->dev, "Failed gpiochip_remove(%d)\n", i);
}
kfree(chip_save);
err_kzalloc:
pci_iounmap(pdev, base);
err_iomap:
pci_release_regions(pdev);
err_request_regions:
pci_disable_device(pdev);
err_pci_enable:
dev_err(&pdev->dev, "%s Failed returns %d\n", __func__, ret);
return ret;
}
static void __devexit ioh_gpio_remove(struct pci_dev *pdev)
{
int err;
int i;
struct ioh_gpio *chip = pci_get_drvdata(pdev);
void __iomem *chip_save;
chip_save = chip;
for (i = 0; i < 8; i++, chip++) {
err = gpiochip_remove(&chip->gpio);
if (err)
dev_err(&pdev->dev, "Failed gpiochip_remove\n");
}
chip = chip_save;
pci_iounmap(pdev, chip->base);
pci_release_regions(pdev);
pci_disable_device(pdev);
kfree(chip);
}
static int ioh_gpio_suspend(struct pci_dev *pdev, pm_message_t state)
{
s32 ret;
struct ioh_gpio *chip = pci_get_drvdata(pdev);
ioh_gpio_save_reg_conf(chip);
ioh_gpio_restore_reg_conf(chip);
ret = pci_save_state(pdev);
if (ret) {
dev_err(&pdev->dev, "pci_save_state Failed-%d\n", ret);
return ret;
}
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D0);
ret = pci_enable_wake(pdev, PCI_D0, 1);
if (ret)
dev_err(&pdev->dev, "pci_enable_wake Failed -%d\n", ret);
return 0;
}
static int ioh_gpio_resume(struct pci_dev *pdev)
{
s32 ret;
struct ioh_gpio *chip = pci_get_drvdata(pdev);
ret = pci_enable_wake(pdev, PCI_D0, 0);
pci_set_power_state(pdev, PCI_D0);
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "pci_enable_device Failed-%d ", ret);
return ret;
}
pci_restore_state(pdev);
iowrite32(0x01, &chip->reg->srst);
iowrite32(0x00, &chip->reg->srst);
ioh_gpio_restore_reg_conf(chip);
return 0;
}
static int __init ioh_gpio_pci_init(void)
{
return pci_register_driver(&ioh_gpio_driver);
}
static void __exit ioh_gpio_pci_exit(void)
{
pci_unregister_driver(&ioh_gpio_driver);
}
