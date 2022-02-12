static void pci_fixup_video(struct pci_dev *pdev)
{
struct pci_dev *bridge;
struct pci_bus *bus;
u16 config;
if ((strcmp(ia64_platform_name, "dig") != 0)
&& (strcmp(ia64_platform_name, "hpzx1") != 0))
return;
bus = pdev->bus;
while (bus) {
bridge = bus->self;
if (bridge && (pci_is_bridge(bridge))) {
pci_read_config_word(bridge, PCI_BRIDGE_CONTROL,
&config);
if (!(config & PCI_BRIDGE_CTL_VGA))
return;
}
bus = bus->parent;
}
if (!vga_default_device() || pdev == vga_default_device()) {
pci_read_config_word(pdev, PCI_COMMAND, &config);
if (config & (PCI_COMMAND_IO | PCI_COMMAND_MEMORY)) {
pdev->resource[PCI_ROM_RESOURCE].flags |= IORESOURCE_ROM_SHADOW;
dev_printk(KERN_DEBUG, &pdev->dev, "Video device with shadowed ROM\n");
}
}
}
