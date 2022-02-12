static inline struct uio_pci_generic_dev *
to_uio_pci_generic_dev(struct uio_info *info)
{
return container_of(info, struct uio_pci_generic_dev, info);
}
static irqreturn_t irqhandler(int irq, struct uio_info *info)
{
struct uio_pci_generic_dev *gdev = to_uio_pci_generic_dev(info);
if (!pci_check_and_mask_intx(gdev->pdev))
return IRQ_NONE;
return IRQ_HANDLED;
}
static int __devinit probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct uio_pci_generic_dev *gdev;
int err;
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "%s: pci_enable_device failed: %d\n",
__func__, err);
return err;
}
if (!pdev->irq) {
dev_warn(&pdev->dev, "No IRQ assigned to device: "
"no support for interrupts?\n");
pci_disable_device(pdev);
return -ENODEV;
}
if (!pci_intx_mask_supported(pdev)) {
err = -ENODEV;
goto err_verify;
}
gdev = kzalloc(sizeof(struct uio_pci_generic_dev), GFP_KERNEL);
if (!gdev) {
err = -ENOMEM;
goto err_alloc;
}
gdev->info.name = "uio_pci_generic";
gdev->info.version = DRIVER_VERSION;
gdev->info.irq = pdev->irq;
gdev->info.irq_flags = IRQF_SHARED;
gdev->info.handler = irqhandler;
gdev->pdev = pdev;
if (uio_register_device(&pdev->dev, &gdev->info))
goto err_register;
pci_set_drvdata(pdev, gdev);
return 0;
err_register:
kfree(gdev);
err_alloc:
err_verify:
pci_disable_device(pdev);
return err;
}
static void remove(struct pci_dev *pdev)
{
struct uio_pci_generic_dev *gdev = pci_get_drvdata(pdev);
uio_unregister_device(&gdev->info);
pci_disable_device(pdev);
kfree(gdev);
}
static int __init init(void)
{
pr_info(DRIVER_DESC " version: " DRIVER_VERSION "\n");
return pci_register_driver(&driver);
}
static void __exit cleanup(void)
{
pci_unregister_driver(&driver);
}
