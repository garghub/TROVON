int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)\r\n{\r\nreturn pci_irq_tab[slot][pin];\r\n}\r\nint pcibios_plat_dev_init(struct pci_dev *dev)\r\n{\r\nreturn 0;\r\n}
