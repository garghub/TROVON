static int __init __area_sdram_check(struct pci_channel *chan,
unsigned int area)
{
unsigned long word;
word = __raw_readl(SH7751_BCR1);
if (((word >> area) & 1) == 0) {
printk("PCI: Area %d is not configured for SDRAM. BCR1=0x%lx\n",
area, word);
return 0;
}
pci_write_reg(chan, word, SH4_PCIBCR1);
word = __raw_readw(SH7751_BCR2);
if (((word >> (area << 1)) & 0x3) != 0x3) {
printk("PCI: Area %d is not 32 bit SDRAM. BCR2=0x%lx\n",
area, word);
return 0;
}
pci_write_reg(chan, word, SH4_PCIBCR2);
return 1;
}
static int __init sh7751_pci_init(void)
{
struct pci_channel *chan = &sh7751_pci_controller;
unsigned int id;
u32 word, reg;
printk(KERN_NOTICE "PCI: Starting initialization.\n");
chan->reg_base = 0xfe200000;
id = pci_read_reg(chan, SH7751_PCICONF0);
if (id != ((SH7751_DEVICE_ID << 16) | SH7751_VENDOR_ID) &&
id != ((SH7751R_DEVICE_ID << 16) | SH7751_VENDOR_ID)) {
pr_debug("PCI: This is not an SH7751(R) (%x)\n", id);
return -ENODEV;
}
reg = __raw_readl(SH7751_BCR1);
reg |= 0x80000;
__raw_writel(reg, SH7751_BCR1);
pci_write_reg(chan, 0, SH4_PCICLKR);
word = SH4_PCIPINT_D3 | SH4_PCIPINT_D0;
pci_write_reg(chan, word, SH4_PCIPINT);
word = SH7751_PCICONF1_WCC | SH7751_PCICONF1_PER |
SH7751_PCICONF1_BUM | SH7751_PCICONF1_MES;
pci_write_reg(chan, word, SH7751_PCICONF1);
word = PCI_BASE_CLASS_BRIDGE << 24;
pci_write_reg(chan, word, SH7751_PCICONF2);
word = sh7751_pci_map.window0.size - 1;
pci_write_reg(chan, word, SH4_PCILSR0);
word = P2SEGADDR(sh7751_pci_map.window0.base);
pci_write_reg(chan, word, SH4_PCILAR0);
pci_write_reg(chan, word, SH7751_PCICONF5);
word = chan->resources[1].start & SH4_PCIMBR_MASK;
pr_debug("PCI: Setting upper bits of Memory window to 0x%x\n", word);
pci_write_reg(chan, word , SH4_PCIMBR);
word = chan->resources[0].start & SH4_PCIIOBR_MASK;
pr_debug("PCI: Setting upper bits of IO window to 0x%x\n", word);
pci_write_reg(chan, word, SH4_PCIIOBR);
switch (sh7751_pci_map.window0.base) {
case SH7751_CS0_BASE_ADDR: word = __area_sdram_check(chan, 0); break;
case SH7751_CS1_BASE_ADDR: word = __area_sdram_check(chan, 1); break;
case SH7751_CS2_BASE_ADDR: word = __area_sdram_check(chan, 2); break;
case SH7751_CS3_BASE_ADDR: word = __area_sdram_check(chan, 3); break;
case SH7751_CS4_BASE_ADDR: word = __area_sdram_check(chan, 4); break;
case SH7751_CS5_BASE_ADDR: word = __area_sdram_check(chan, 5); break;
case SH7751_CS6_BASE_ADDR: word = __area_sdram_check(chan, 6); break;
}
if (!word)
return -1;
word = __raw_readl(SH7751_WCR1);
pci_write_reg(chan, word, SH4_PCIWCR1);
word = __raw_readl(SH7751_WCR2);
pci_write_reg(chan, word, SH4_PCIWCR2);
word = __raw_readl(SH7751_WCR3);
pci_write_reg(chan, word, SH4_PCIWCR3);
word = __raw_readl(SH7751_MCR);
pci_write_reg(chan, word, SH4_PCIMCR);
pci_fixup_pcic(chan);
word = SH4_PCICR_PREFIX | SH4_PCICR_CFIN | SH4_PCICR_ARBM;
pci_write_reg(chan, word, SH4_PCICR);
return register_pci_controller(chan);
}
