static int amd_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct amd_gpio *agp = to_agp(chip);
agp->orig[offset] = ioread8(agp->pm + AMD_REG_GPIO(offset)) &
(AMD_GPIO_DEBOUNCE | AMD_GPIO_MODE_MASK | AMD_GPIO_X_MASK);
dev_dbg(&agp->pdev->dev, "Requested gpio %d, data %x\n", offset, agp->orig[offset]);
return 0;
}
static void amd_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct amd_gpio *agp = to_agp(chip);
dev_dbg(&agp->pdev->dev, "Freed gpio %d, data %x\n", offset, agp->orig[offset]);
iowrite8(agp->orig[offset], agp->pm + AMD_REG_GPIO(offset));
}
static void amd_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct amd_gpio *agp = to_agp(chip);
u8 temp;
unsigned long flags;
spin_lock_irqsave(&agp->lock, flags);
temp = ioread8(agp->pm + AMD_REG_GPIO(offset));
temp = (temp & AMD_GPIO_DEBOUNCE) | AMD_GPIO_MODE_OUT | (value ? AMD_GPIO_X_OUT_HI : AMD_GPIO_X_OUT_LOW);
iowrite8(temp, agp->pm + AMD_REG_GPIO(offset));
spin_unlock_irqrestore(&agp->lock, flags);
dev_dbg(&agp->pdev->dev, "Setting gpio %d, value %d, reg=%02x\n", offset, !!value, temp);
}
static int amd_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct amd_gpio *agp = to_agp(chip);
u8 temp;
temp = ioread8(agp->pm + AMD_REG_GPIO(offset));
dev_dbg(&agp->pdev->dev, "Getting gpio %d, reg=%02x\n", offset, temp);
return (temp & AMD_GPIO_RTIN) ? 1 : 0;
}
static int amd_gpio_dirout(struct gpio_chip *chip, unsigned offset, int value)
{
struct amd_gpio *agp = to_agp(chip);
u8 temp;
unsigned long flags;
spin_lock_irqsave(&agp->lock, flags);
temp = ioread8(agp->pm + AMD_REG_GPIO(offset));
temp = (temp & AMD_GPIO_DEBOUNCE) | AMD_GPIO_MODE_OUT | (value ? AMD_GPIO_X_OUT_HI : AMD_GPIO_X_OUT_LOW);
iowrite8(temp, agp->pm + AMD_REG_GPIO(offset));
spin_unlock_irqrestore(&agp->lock, flags);
dev_dbg(&agp->pdev->dev, "Dirout gpio %d, value %d, reg=%02x\n", offset, !!value, temp);
return 0;
}
static int amd_gpio_dirin(struct gpio_chip *chip, unsigned offset)
{
struct amd_gpio *agp = to_agp(chip);
u8 temp;
unsigned long flags;
spin_lock_irqsave(&agp->lock, flags);
temp = ioread8(agp->pm + AMD_REG_GPIO(offset));
temp = (temp & AMD_GPIO_DEBOUNCE) | AMD_GPIO_MODE_IN;
iowrite8(temp, agp->pm + AMD_REG_GPIO(offset));
spin_unlock_irqrestore(&agp->lock, flags);
dev_dbg(&agp->pdev->dev, "Dirin gpio %d, reg=%02x\n", offset, temp);
return 0;
}
static int __init amd_gpio_init(void)
{
int err = -ENODEV;
struct pci_dev *pdev = NULL;
const struct pci_device_id *ent;
for_each_pci_dev(pdev) {
ent = pci_match_id(pci_tbl, pdev);
if (ent)
goto found;
}
goto out;
found:
err = pci_read_config_dword(pdev, 0x58, &gp.pmbase);
if (err)
goto out;
err = -EIO;
gp.pmbase &= 0x0000FF00;
if (gp.pmbase == 0)
goto out;
if (!request_region(gp.pmbase + PMBASE_OFFSET, PMBASE_SIZE, "AMD GPIO")) {
dev_err(&pdev->dev, "AMD GPIO region 0x%x already in use!\n",
gp.pmbase + PMBASE_OFFSET);
err = -EBUSY;
goto out;
}
gp.pm = ioport_map(gp.pmbase + PMBASE_OFFSET, PMBASE_SIZE);
gp.pdev = pdev;
gp.chip.dev = &pdev->dev;
spin_lock_init(&gp.lock);
printk(KERN_INFO "AMD-8111 GPIO detected\n");
err = gpiochip_add(&gp.chip);
if (err) {
printk(KERN_ERR "GPIO registering failed (%d)\n",
err);
release_region(gp.pmbase + PMBASE_OFFSET, PMBASE_SIZE);
goto out;
}
out:
return err;
}
static void __exit amd_gpio_exit(void)
{
gpiochip_remove(&gp.chip);
ioport_unmap(gp.pm);
release_region(gp.pmbase + PMBASE_OFFSET, PMBASE_SIZE);
}
