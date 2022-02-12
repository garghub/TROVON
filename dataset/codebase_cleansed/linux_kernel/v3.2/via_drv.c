static int __init via_init(void)
{
driver.num_ioctls = via_max_ioctl;
via_init_command_verifier();
return drm_pci_init(&driver, &via_pci_driver);
}
static void __exit via_exit(void)
{
drm_pci_exit(&driver, &via_pci_driver);
}
