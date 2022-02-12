static int poulsbo_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
return acpi_video_register();
}
static void poulsbo_remove(struct pci_dev *pdev)
{
acpi_video_unregister();
}
static int __init poulsbo_init(void)
{
return pci_register_driver(&poulsbo_driver);
}
static void __exit poulsbo_exit(void)
{
pci_unregister_driver(&poulsbo_driver);
}
