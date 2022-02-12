static int i915_pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct intel_device_info *intel_info =
(struct intel_device_info *) ent->driver_data;
if (IS_ALPHA_SUPPORT(intel_info) && !i915.alpha_support) {
DRM_INFO("The driver support for your hardware in this kernel version is alpha quality\n"
"See CONFIG_DRM_I915_ALPHA_SUPPORT or i915.alpha_support module parameter\n"
"to enable support in this kernel version, or check for kernel updates.\n");
return -ENODEV;
}
if (PCI_FUNC(pdev->devfn))
return -ENODEV;
if (vga_switcheroo_client_probe_defer(pdev))
return -EPROBE_DEFER;
return i915_driver_load(pdev, ent);
}
static void i915_pci_remove(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
i915_driver_unload(dev);
drm_dev_unref(dev);
}
static int __init i915_init(void)
{
bool use_kms = true;
if (i915.modeset == 0)
use_kms = false;
if (vgacon_text_force() && i915.modeset == -1)
use_kms = false;
if (!use_kms) {
DRM_DEBUG_DRIVER("KMS disabled.\n");
return 0;
}
return pci_register_driver(&i915_pci_driver);
}
static void __exit i915_exit(void)
{
if (!i915_pci_driver.driver.owner)
return;
pci_unregister_driver(&i915_pci_driver);
}
