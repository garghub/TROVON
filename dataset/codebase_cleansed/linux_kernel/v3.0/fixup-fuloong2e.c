int __init pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq = 0;
if (slot == sb_slot) {
switch (PCI_FUNC(dev->devfn)) {
case 2:
irq = 10;
break;
case 3:
irq = 11;
break;
case 5:
irq = 9;
break;
}
} else {
irq = LOONGSON_IRQ_BASE + 25 + pin;
}
return irq;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
static void __init loongson2e_nec_fixup(struct pci_dev *pdev)
{
unsigned int val;
pci_read_config_dword(pdev, 0xe0, &val);
pci_write_config_dword(pdev, 0xe0, (val & ~7) | 0x4);
pci_write_config_dword(pdev, 0xe4, 1 << 5);
}
static void __init loongson2e_686b_func0_fixup(struct pci_dev *pdev)
{
unsigned char c;
sb_slot = PCI_SLOT(pdev->devfn);
printk(KERN_INFO "via686b fix: ISA bridge\n");
pci_write_config_byte(pdev, 0x40, 0x08);
pci_write_config_byte(pdev, 0x41, 0x01);
pci_write_config_byte(pdev, 0x45, 0x00);
pci_write_config_byte(pdev, 0x46, 0xe0);
pci_write_config_byte(pdev, 0x47, 0xe6);
outb(0x2e, 0x4d1);
pci_write_config_byte(pdev, 0x48, 0x01);
pci_write_config_byte(pdev, 0x4a, 0x84);
pci_write_config_byte(pdev, 0x50, 0x0e);
pci_write_config_byte(pdev, 0x51, 0x76);
pci_write_config_byte(pdev, 0x52, 0x34);
pci_write_config_byte(pdev, 0x54, 0x00);
pci_write_config_byte(pdev, 0x55, 0x90);
pci_write_config_byte(pdev, 0x56, 0xba);
pci_write_config_byte(pdev, 0x57, 0xd0);
pci_read_config_byte(pdev, 0x85, &c);
c &= ~(0x3 << 2);
pci_write_config_byte(pdev, 0x85, c);
printk(KERN_INFO"via686b fix: ISA bridge done\n");
}
static void __init loongson2e_686b_func1_fixup(struct pci_dev *pdev)
{
printk(KERN_INFO"via686b fix: IDE\n");
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 48);
pci_write_config_byte(pdev, PCI_COMMAND,
PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER);
pci_write_config_byte(pdev, 0x40, 0x0b);
pci_write_config_byte(pdev, 0x42, 0x09);
#if 1
pci_write_config_byte(pdev, 0x41, 0x02);
pci_write_config_byte(pdev, 0x43, 0x0a);
pci_write_config_byte(pdev, 0x44, 0x00);
pci_write_config_byte(pdev, 0x45, 0x00);
#else
pci_write_config_byte(pdev, 0x41, 0xc2);
pci_write_config_byte(pdev, 0x43, 0x35);
pci_write_config_byte(pdev, 0x44, 0x1c);
pci_write_config_byte(pdev, 0x45, 0x10);
#endif
printk(KERN_INFO"via686b fix: IDE done\n");
}
static void __init loongson2e_686b_func2_fixup(struct pci_dev *pdev)
{
pci_write_config_byte(pdev, PCI_INTERRUPT_LINE, 10);
}
static void __init loongson2e_686b_func3_fixup(struct pci_dev *pdev)
{
pci_write_config_byte(pdev, PCI_INTERRUPT_LINE, 11);
}
static void __init loongson2e_686b_func5_fixup(struct pci_dev *pdev)
{
unsigned int val;
unsigned char c;
pci_write_config_byte(pdev, PCI_COMMAND,
PCI_COMMAND_IO | PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER);
pci_read_config_dword(pdev, 0x4, &val);
pci_write_config_dword(pdev, 0x4, val | 1);
pci_write_config_byte(pdev, 0x3c, 9);
pci_read_config_byte(pdev, 0x8, &c);
pci_write_config_byte(pdev, 0x41, 0xcc);
pci_write_config_byte(pdev, 0x42, 0x20);
pci_write_config_word(pdev, 0x2c, 0x1005);
pci_write_config_word(pdev, 0x2e, 0x4710);
pci_read_config_dword(pdev, 0x2c, &val);
pci_write_config_byte(pdev, 0x42, 0x0);
}
