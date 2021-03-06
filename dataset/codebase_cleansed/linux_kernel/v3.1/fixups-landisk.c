int pcibios_map_platform_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
int irq = ((slot + pin - 1) & 0x3) + 5;
if ((slot | (pin - 1)) > 0x3) {
printk(KERN_WARNING "PCI: Bad IRQ mapping request for slot %d pin %c\n",
slot, pin - 1 + 'A');
return -1;
}
return irq;
}
int pci_fixup_pcic(struct pci_channel *chan)
{
unsigned long bcr1, mcr;
bcr1 = __raw_readl(SH7751_BCR1);
bcr1 |= 0x40080000;
pci_write_reg(chan, bcr1, SH4_PCIBCR1);
mcr = __raw_readl(SH7751_MCR);
mcr = (mcr & PCIMCR_MRSET_OFF) & PCIMCR_RFSH_OFF;
pci_write_reg(chan, mcr, SH4_PCIMCR);
pci_write_reg(chan, 0x0c000000, SH7751_PCICONF5);
pci_write_reg(chan, 0xd0000000, SH7751_PCICONF6);
pci_write_reg(chan, 0x0c000000, SH4_PCILAR0);
pci_write_reg(chan, 0x00000000, SH4_PCILAR1);
return 0;
}
