int __init pcibios_map_platform_irq(struct pci_dev *pdev, u8 slot, u8 pin)
{
if (mach_is_lboxre2())
return lboxre2_irq_tab[slot];
else
return rts7751r2d_irq_tab[slot];
}
int pci_fixup_pcic(struct pci_channel *chan)
{
unsigned long bcr1, mcr;
bcr1 = __raw_readl(SH7751_BCR1);
bcr1 |= 0x40080000;
pci_write_reg(chan, bcr1, SH4_PCIBCR1);
pci_write_reg(chan, 0x0000c3ff, SH4_PCIINTM);
pci_write_reg(chan, 0x0000380f, SH4_PCIAINTM);
pci_write_reg(chan, 0xfb900047, SH7751_PCICONF1);
pci_write_reg(chan, 0xab000001, SH7751_PCICONF4);
mcr = __raw_readl(SH7751_MCR);
mcr = (mcr & PCIMCR_MRSET_OFF) & PCIMCR_RFSH_OFF;
pci_write_reg(chan, mcr, SH4_PCIMCR);
pci_write_reg(chan, 0x0c000000, SH7751_PCICONF5);
pci_write_reg(chan, 0xd0000000, SH7751_PCICONF6);
pci_write_reg(chan, 0x0c000000, SH4_PCILAR0);
pci_write_reg(chan, 0x00000000, SH4_PCILAR1);
return 0;
}
