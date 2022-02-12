static int __init pci_eisa_init(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rc;
if ((rc = pci_enable_device (pdev))) {
printk (KERN_ERR "pci_eisa : Could not enable device %s\n",
pci_name(pdev));
return rc;
}
pci_eisa_root.dev = &pdev->dev;
pci_eisa_root.res = pdev->bus->resource[0];
pci_eisa_root.bus_base_addr = pdev->bus->resource[0]->start;
pci_eisa_root.slots = EISA_MAX_SLOTS;
pci_eisa_root.dma_mask = pdev->dma_mask;
dev_set_drvdata(pci_eisa_root.dev, &pci_eisa_root);
if (eisa_root_register (&pci_eisa_root)) {
printk (KERN_ERR "pci_eisa : Could not register EISA root\n");
return -1;
}
return 0;
}
static int __init pci_eisa_init_module (void)
{
return pci_register_driver (&pci_eisa_driver);
}
