const char *get_system_type(void)
{
return "PB1500";
}
void __init board_setup(void)
{
u32 pin_func;
u32 sys_freqctrl, sys_clksrc;
bcsr_init(DB1000_BCSR_PHYS_ADDR,
DB1000_BCSR_PHYS_ADDR + DB1000_BCSR_HEXLED_OFS);
sys_clksrc = sys_freqctrl = pin_func = 0;
au_writel(8, SYS_AUXPLL);
alchemy_gpio1_input_enable();
udelay(100);
alchemy_gpio_direction_input(201);
alchemy_gpio_direction_input(203);
#if IS_ENABLED(CONFIG_USB_OHCI_HCD)
sys_freqctrl = au_readl(SYS_FREQCTRL0);
sys_freqctrl &= ~0xFFF00000;
au_writel(sys_freqctrl, SYS_FREQCTRL0);
sys_clksrc = au_readl(SYS_CLKSRC);
sys_clksrc &= ~(SYS_CS_CUD | SYS_CS_DUD | SYS_CS_MUD_MASK |
SYS_CS_CUH | SYS_CS_DUH | SYS_CS_MUH_MASK);
au_writel(sys_clksrc, SYS_CLKSRC);
sys_freqctrl = au_readl(SYS_FREQCTRL0);
sys_freqctrl &= ~0xFFF00000;
sys_clksrc = au_readl(SYS_CLKSRC);
sys_clksrc &= ~(SYS_CS_CUD | SYS_CS_DUD | SYS_CS_MUD_MASK |
SYS_CS_CUH | SYS_CS_DUH | SYS_CS_MUH_MASK);
sys_freqctrl |= (0 << SYS_FC_FRDIV2_BIT) | SYS_FC_FE2 | SYS_FC_FS2;
au_writel(sys_freqctrl, SYS_FREQCTRL0);
sys_clksrc |= SYS_CS_MUX_FQ2 << SYS_CS_MUH_BIT;
au_writel(sys_clksrc, SYS_CLKSRC);
pin_func = au_readl(SYS_PINFUNC) & ~SYS_PF_USB;
pin_func |= SYS_PF_USB;
au_writel(pin_func, SYS_PINFUNC);
#endif
#ifdef CONFIG_PCI
{
void __iomem *base =
(void __iomem *)KSEG1ADDR(AU1500_PCI_PHYS_ADDR);
__raw_writel(0x00003fff, base + PCI_REG_CMEM);
__raw_writel(0xf0000000, base + PCI_REG_MWMASK_DEV);
__raw_writel(0, base + PCI_REG_MWBASE_REV_CCL);
__raw_writel(0x02a00356, base + PCI_REG_STATCMD);
__raw_writel(0x00003c04, base + PCI_REG_PARAM);
__raw_writel(0x00000008, base + PCI_REG_MBAR);
wmb();
}
#endif
au_writel(au_readl(SYS_POWERCTRL) | (0x3 << 5), SYS_POWERCTRL);
if (!(au_readl(0xac000028) & 0x20)) {
printk(KERN_INFO "enabling clock ...\n");
au_writel((au_readl(0xac000028) | 0x20), 0xac000028);
}
if (au_readl(0xac00002c) & 0x4) {
au_writel(au_readl(0xac00002c) & ~0x4, 0xac00002c);
au_sync();
}
}
static int pb1500_map_pci_irq(const struct pci_dev *d, u8 slot, u8 pin)
{
if ((slot < 12) || (slot > 13) || pin == 0)
return -1;
if (slot == 12)
return (pin == 1) ? AU1500_PCI_INTA : 0xff;
if (slot == 13) {
switch (pin) {
case 1: return AU1500_PCI_INTA;
case 2: return AU1500_PCI_INTB;
case 3: return AU1500_PCI_INTC;
case 4: return AU1500_PCI_INTD;
}
}
return -1;
}
static int __init pb1500_dev_init(void)
{
int swapped;
irq_set_irq_type(AU1500_GPIO9_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1500_GPIO10_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1500_GPIO11_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1500_GPIO204_INT, IRQF_TRIGGER_HIGH);
irq_set_irq_type(AU1500_GPIO201_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1500_GPIO202_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1500_GPIO203_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1500_GPIO205_INT, IRQF_TRIGGER_LOW);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x000010000 - 1,
AU1500_GPIO11_INT, AU1500_GPIO9_INT,
0, 0, 0);
swapped = bcsr_read(BCSR_STATUS) & BCSR_STATUS_DB1000_SWAPBOOT;
db1x_register_norflash(64 * 1024 * 1024, 4, swapped);
platform_device_register(&pb1500_pci_host);
return 0;
}
