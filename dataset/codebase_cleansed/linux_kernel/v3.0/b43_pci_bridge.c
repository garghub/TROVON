int __init b43_pci_ssb_bridge_init(void)
{
return ssb_pcihost_register(&b43_pci_bridge_driver);
}
void __exit b43_pci_ssb_bridge_exit(void)
{
ssb_pcihost_unregister(&b43_pci_bridge_driver);
}
