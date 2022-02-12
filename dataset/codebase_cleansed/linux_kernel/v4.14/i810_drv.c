static int __init i810_init(void)
{
if (num_possible_cpus() > 1) {
pr_err("drm/i810 does not support SMP\n");
return -EINVAL;
}
driver.num_ioctls = i810_max_ioctl;
return drm_legacy_pci_init(&driver, &i810_pci_driver);
}
static void __exit i810_exit(void)
{
drm_legacy_pci_exit(&driver, &i810_pci_driver);
}
