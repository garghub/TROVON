static int of_pci_phb_probe(struct platform_device *dev)
{
struct pci_controller *phb;
if (ppc_md.pci_setup_phb == NULL)
return -ENODEV;
pr_info("Setting up PCI bus %s\n", dev->dev.of_node->full_name);
phb = pcibios_alloc_controller(dev->dev.of_node);
if (!phb)
return -ENODEV;
phb->parent = &dev->dev;
if (ppc_md.pci_setup_phb(phb)) {
pcibios_free_controller(phb);
return -ENODEV;
}
pci_process_bridge_OF_ranges(phb, dev->dev.of_node, 0);
pci_devs_phb_init_dynamic(phb);
eeh_dev_phb_init_dynamic(phb);
if (dev->dev.of_node->child)
eeh_add_device_tree_early(dev->dev.of_node);
pcibios_scan_phb(phb);
if (phb->bus == NULL)
return -ENXIO;
pcibios_claim_one_bus(phb->bus);
eeh_add_device_tree_late(phb->bus);
pci_bus_add_devices(phb->bus);
eeh_add_sysfs_files(phb->bus);
return 0;
}
static __init int of_pci_phb_init(void)
{
return platform_driver_register(&of_pci_phb_driver);
}
