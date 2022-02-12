static inline int uhc_clkctrl_ready(u32 val)
{
const u32 mask = SCC_UHC_USBCEN | SCC_UHC_USBCEN;
return((val & mask) == mask);
}
static void enable_scc_uhc(struct pci_dev *dev)
{
void __iomem *uhc_base;
u32 __iomem *uhc_clkctrl;
u32 __iomem *uhc_ecmode;
u32 val = 0;
int i;
if (!machine_is(celleb_beat) &&
!machine_is(celleb_native))
return;
uhc_base = ioremap(pci_resource_start(dev, 0),
pci_resource_len(dev, 0));
if (!uhc_base) {
printk(KERN_ERR "failed to map UHC register base.\n");
return;
}
uhc_clkctrl = uhc_base + SCC_UHC_CKRCTRL;
uhc_ecmode = uhc_base + SCC_UHC_ECMODE;
val |= SCC_UHC_F48MCKLEN;
out_be32(uhc_clkctrl, val);
val |= SCC_UHC_PHY_SUSPEND_SEL;
out_be32(uhc_clkctrl, val);
udelay(10);
val |= SCC_UHC_PHYEN;
out_be32(uhc_clkctrl, val);
udelay(50);
val |= SCC_UHC_HCLKEN;
out_be32(uhc_clkctrl, val);
val |= (SCC_UHC_USBCEN | SCC_UHC_USBEN);
out_be32(uhc_clkctrl, val);
i = 0;
while (!uhc_clkctrl_ready(in_be32(uhc_clkctrl))) {
udelay(10);
if (i++ > UHC_RESET_WAIT_MAX) {
printk(KERN_ERR "Failed to disable UHC reset %x\n",
in_be32(uhc_clkctrl));
break;
}
}
out_be32(uhc_ecmode, SCC_UHC_ECMODE_BY_BYTE);
iounmap(uhc_base);
}
