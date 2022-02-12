static int bochs_unload(struct drm_device *dev)
{
struct bochs_device *bochs = dev->dev_private;
bochs_fbdev_fini(bochs);
bochs_kms_fini(bochs);
bochs_mm_fini(bochs);
bochs_hw_fini(dev);
kfree(bochs);
dev->dev_private = NULL;
return 0;
}
static int bochs_load(struct drm_device *dev, unsigned long flags)
{
struct bochs_device *bochs;
int ret;
bochs = kzalloc(sizeof(*bochs), GFP_KERNEL);
if (bochs == NULL)
return -ENOMEM;
dev->dev_private = bochs;
bochs->dev = dev;
ret = bochs_hw_init(dev, flags);
if (ret)
goto err;
ret = bochs_mm_init(bochs);
if (ret)
goto err;
ret = bochs_kms_init(bochs);
if (ret)
goto err;
if (enable_fbdev)
bochs_fbdev_init(bochs);
return 0;
err:
bochs_unload(dev);
return ret;
}
static int bochs_kick_out_firmware_fb(struct pci_dev *pdev)
{
struct apertures_struct *ap;
ap = alloc_apertures(1);
if (!ap)
return -ENOMEM;
ap->ranges[0].base = pci_resource_start(pdev, 0);
ap->ranges[0].size = pci_resource_len(pdev, 0);
remove_conflicting_framebuffers(ap, "bochsdrmfb", false);
kfree(ap);
return 0;
}
static int bochs_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int ret;
ret = bochs_kick_out_firmware_fb(pdev);
if (ret)
return ret;
return drm_get_pci_dev(pdev, ent, &bochs_driver);
}
static void bochs_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
drm_put_dev(dev);
}
static int __init bochs_init(void)
{
return drm_pci_init(&bochs_driver, &bochs_pci_driver);
}
static void __exit bochs_exit(void)
{
drm_pci_exit(&bochs_driver, &bochs_pci_driver);
}
