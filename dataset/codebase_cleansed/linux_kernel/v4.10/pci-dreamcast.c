static int __init gapspci_init(void)
{
char idbuf[16];
int i;
for (i=0; i<16; i++)
idbuf[i] = inb(GAPSPCI_REGS+i);
if (strncmp(idbuf, "GAPSPCI_BRIDGE_2", 16))
return -ENODEV;
outl(0x5a14a501, GAPSPCI_REGS+0x18);
for (i=0; i<1000000; i++)
cpu_relax();
if (inl(GAPSPCI_REGS+0x18) != 1)
return -EINVAL;
outl(0x01000000, GAPSPCI_REGS+0x20);
outl(0x01000000, GAPSPCI_REGS+0x24);
outl(GAPSPCI_DMA_BASE, GAPSPCI_REGS+0x28);
outl(GAPSPCI_DMA_BASE+GAPSPCI_DMA_SIZE, GAPSPCI_REGS+0x2c);
outl(1, GAPSPCI_REGS+0x14);
outl(1, GAPSPCI_REGS+0x34);
outw(0xf900, GAPSPCI_BBA_CONFIG+0x06);
outl(0x00000000, GAPSPCI_BBA_CONFIG+0x30);
outb(0x00, GAPSPCI_BBA_CONFIG+0x3c);
outb(0xf0, GAPSPCI_BBA_CONFIG+0x0d);
outw(0x0006, GAPSPCI_BBA_CONFIG+0x04);
outl(0x00002001, GAPSPCI_BBA_CONFIG+0x10);
outl(0x01000000, GAPSPCI_BBA_CONFIG+0x14);
return register_pci_controller(&dreamcast_pci_controller);
}
