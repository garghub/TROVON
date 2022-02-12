static int __init tdfx_init(void)
{
return drm_pci_init(&driver, &tdfx_pci_driver);
}
static void __exit tdfx_exit(void)
{
drm_pci_exit(&driver, &tdfx_pci_driver);
}
