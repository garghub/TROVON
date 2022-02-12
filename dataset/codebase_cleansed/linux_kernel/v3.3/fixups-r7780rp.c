int __init pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)\r\n{\r\nreturn irq_tab[slot];\r\n}
