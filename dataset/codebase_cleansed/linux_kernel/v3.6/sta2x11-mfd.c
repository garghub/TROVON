static struct sta2x11_mfd *sta2x11_mfd_find(struct pci_dev *pdev)
{
struct sta2x11_instance *instance;
struct sta2x11_mfd *mfd;
if (!pdev && !list_empty(&sta2x11_mfd_list)) {
pr_warning("%s: Unspecified device, "
"using first instance\n", __func__);
return list_entry(sta2x11_mfd_list.next,
struct sta2x11_mfd, list);
}
instance = sta2x11_get_instance(pdev);
if (!instance)
return NULL;
list_for_each_entry(mfd, &sta2x11_mfd_list, list) {
if (mfd->instance == instance)
return mfd;
}
return NULL;
}
static int __devinit sta2x11_mfd_add(struct pci_dev *pdev, gfp_t flags)
{
struct sta2x11_mfd *mfd = sta2x11_mfd_find(pdev);
struct sta2x11_instance *instance;
if (mfd)
return -EBUSY;
instance = sta2x11_get_instance(pdev);
if (!instance)
return -EINVAL;
mfd = kzalloc(sizeof(*mfd), flags);
if (!mfd)
return -ENOMEM;
INIT_LIST_HEAD(&mfd->list);
spin_lock_init(&mfd->lock);
mfd->instance = instance;
list_add(&mfd->list, &sta2x11_mfd_list);
return 0;
}
static int __devexit mfd_remove(struct pci_dev *pdev)
{
struct sta2x11_mfd *mfd = sta2x11_mfd_find(pdev);
if (!mfd)
return -ENODEV;
list_del(&mfd->list);
kfree(mfd);
return 0;
}
u32 sta2x11_sctl_mask(struct pci_dev *pdev, u32 reg, u32 mask, u32 val)
{
struct sta2x11_mfd *mfd = sta2x11_mfd_find(pdev);
u32 r;
unsigned long flags;
if (!mfd) {
dev_warn(&pdev->dev, ": can't access sctl regs\n");
return 0;
}
if (!mfd->sctl_regs) {
dev_warn(&pdev->dev, ": system ctl not initialized\n");
return 0;
}
spin_lock_irqsave(&mfd->lock, flags);
r = readl(mfd->sctl_regs + reg);
r &= ~mask;
r |= val;
if (mask)
writel(r, mfd->sctl_regs + reg);
spin_unlock_irqrestore(&mfd->lock, flags);
return r;
}
u32 sta2x11_apbreg_mask(struct pci_dev *pdev, u32 reg, u32 mask, u32 val)
{
struct sta2x11_mfd *mfd = sta2x11_mfd_find(pdev);
u32 r;
unsigned long flags;
if (!mfd) {
dev_warn(&pdev->dev, ": can't access apb regs\n");
return 0;
}
if (!mfd->apbreg_regs) {
dev_warn(&pdev->dev, ": apb bridge not initialized\n");
return 0;
}
spin_lock_irqsave(&mfd->lock, flags);
r = readl(mfd->apbreg_regs + reg);
r &= ~mask;
r |= val;
if (mask)
writel(r, mfd->apbreg_regs + reg);
spin_unlock_irqrestore(&mfd->lock, flags);
return r;
}
static int sta2x11_sctl_probe(struct platform_device *dev)
{
struct pci_dev **pdev;
struct sta2x11_mfd *mfd;
struct resource *res;
pdev = dev->dev.platform_data;
mfd = sta2x11_mfd_find(*pdev);
if (!mfd)
return -ENODEV;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENOMEM;
if (!request_mem_region(res->start, resource_size(res),
"sta2x11-sctl"))
return -EBUSY;
mfd->sctl_regs = ioremap(res->start, resource_size(res));
if (!mfd->sctl_regs) {
release_mem_region(res->start, resource_size(res));
return -ENOMEM;
}
sctl_regset.base = mfd->sctl_regs;
sta2x11_sctl_debugfs = debugfs_create_regset32("sta2x11-sctl",
S_IFREG | S_IRUGO,
NULL, &sctl_regset);
return 0;
}
static int sta2x11_apbreg_probe(struct platform_device *dev)
{
struct pci_dev **pdev;
struct sta2x11_mfd *mfd;
struct resource *res;
pdev = dev->dev.platform_data;
dev_dbg(&dev->dev, "%s: pdata is %p\n", __func__, pdev);
dev_dbg(&dev->dev, "%s: *pdata is %p\n", __func__, *pdev);
mfd = sta2x11_mfd_find(*pdev);
if (!mfd)
return -ENODEV;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENOMEM;
if (!request_mem_region(res->start, resource_size(res),
"sta2x11-apbreg"))
return -EBUSY;
mfd->apbreg_regs = ioremap(res->start, resource_size(res));
if (!mfd->apbreg_regs) {
release_mem_region(res->start, resource_size(res));
return -ENOMEM;
}
dev_dbg(&dev->dev, "%s: regbase %p\n", __func__, mfd->apbreg_regs);
apbreg_regset.base = mfd->apbreg_regs;
sta2x11_apbreg_debugfs = debugfs_create_regset32("sta2x11-apbreg",
S_IFREG | S_IRUGO,
NULL, &apbreg_regset);
return 0;
}
static int __init sta2x11_sctl_init(void)
{
pr_info("%s\n", __func__);
return platform_driver_register(&sta2x11_sctl_platform_driver);
}
static int __init sta2x11_apbreg_init(void)
{
pr_info("%s\n", __func__);
return platform_driver_register(&sta2x11_platform_driver);
}
static int sta2x11_mfd_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int sta2x11_mfd_resume(struct pci_dev *pdev)
{
int err;
pci_set_power_state(pdev, 0);
err = pci_enable_device(pdev);
if (err)
return err;
pci_restore_state(pdev);
return 0;
}
static int __devinit sta2x11_mfd_probe(struct pci_dev *pdev,
const struct pci_device_id *pci_id)
{
int err, i;
struct sta2x11_gpio_pdata *gpio_data;
dev_info(&pdev->dev, "%s\n", __func__);
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "Can't enable device.\n");
return err;
}
err = pci_enable_msi(pdev);
if (err)
dev_info(&pdev->dev, "Enable msi failed\n");
gpio_data = dev_get_platdata(&pdev->dev);
if (!gpio_data)
dev_warn(&pdev->dev, "no gpio configuration\n");
dev_dbg(&pdev->dev, "%s, gpio_data = %p (%p)\n", __func__,
gpio_data, &gpio_data);
dev_dbg(&pdev->dev, "%s, pdev = %p (%p)\n", __func__,
pdev, &pdev);
for (i = 0; i < ARRAY_SIZE(sta2x11_mfd_bar0); i++) {
sta2x11_mfd_bar0[i].pdata_size = sizeof(pdev);
sta2x11_mfd_bar0[i].platform_data = &pdev;
}
sta2x11_mfd_bar1[0].pdata_size = sizeof(pdev);
sta2x11_mfd_bar1[0].platform_data = &pdev;
sta2x11_mfd_add(pdev, GFP_ATOMIC);
err = mfd_add_devices(&pdev->dev, -1,
sta2x11_mfd_bar0,
ARRAY_SIZE(sta2x11_mfd_bar0),
&pdev->resource[0],
0, NULL);
if (err) {
dev_err(&pdev->dev, "mfd_add_devices[0] failed: %d\n", err);
goto err_disable;
}
err = mfd_add_devices(&pdev->dev, -1,
sta2x11_mfd_bar1,
ARRAY_SIZE(sta2x11_mfd_bar1),
&pdev->resource[1],
0, NULL);
if (err) {
dev_err(&pdev->dev, "mfd_add_devices[1] failed: %d\n", err);
goto err_disable;
}
return 0;
err_disable:
mfd_remove_devices(&pdev->dev);
pci_disable_device(pdev);
pci_disable_msi(pdev);
return err;
}
static int __init sta2x11_mfd_init(void)
{
pr_info("%s\n", __func__);
return pci_register_driver(&sta2x11_mfd_driver);
}
