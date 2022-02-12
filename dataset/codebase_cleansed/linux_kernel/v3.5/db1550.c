const char *get_system_type(void)
{
return "DB1550";
}
static void __init db1550_hw_setup(void)
{
void __iomem *base;
alchemy_gpio_direction_output(203, 0);
base = (void __iomem *)SYS_CLKSRC;
__raw_writel(__raw_readl(base) | 0x000001e0, base);
base = (void __iomem *)SYS_PINFUNC;
__raw_writel(__raw_readl(base) | 1, base);
wmb();
base = (void __iomem *)KSEG1ADDR(AU1550_PSC1_PHYS_ADDR);
__raw_writel(PSC_SEL_CLK_SERCLK | PSC_SEL_PS_AC97MODE,
base + PSC_SEL_OFFSET);
__raw_writel(PSC_CTRL_DISABLE, base + PSC_CTRL_OFFSET);
wmb();
__raw_writel(PSC_AC97RST_RST, base + PSC_AC97RST_OFFSET);
wmb();
alchemy_gpio_direction_output(202, 0);
}
void __init board_setup(void)
{
unsigned short whoami;
bcsr_init(DB1550_BCSR_PHYS_ADDR,
DB1550_BCSR_PHYS_ADDR + DB1550_BCSR_HEXLED_OFS);
whoami = bcsr_read(BCSR_WHOAMI);
printk(KERN_INFO "Alchemy/AMD DB1550 Board, CPLD Rev %d"
" Board-ID %d Daughtercard ID %d\n",
(whoami >> 4) & 0xf, (whoami >> 8) & 0xf, whoami & 0xf);
db1550_hw_setup();
}
static void au1550_nand_cmd_ctrl(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct nand_chip *this = mtd->priv;
unsigned long ioaddr = (unsigned long)this->IO_ADDR_W;
ioaddr &= 0xffffff00;
if (ctrl & NAND_CLE) {
ioaddr += MEM_STNAND_CMD;
} else if (ctrl & NAND_ALE) {
ioaddr += MEM_STNAND_ADDR;
} else {
ioaddr += MEM_STNAND_DATA;
}
this->IO_ADDR_R = this->IO_ADDR_W = (void __iomem *)ioaddr;
if (cmd != NAND_CMD_NONE) {
__raw_writeb(cmd, this->IO_ADDR_W);
wmb();
}
}
static int au1550_nand_device_ready(struct mtd_info *mtd)
{
return __raw_readl((void __iomem *)MEM_STSTAT) & 1;
}
static void db1550_spi_cs_en(struct au1550_spi_info *spi, int cs, int pol)
{
if (cs)
bcsr_mod(BCSR_BOARD, 0, BCSR_BOARD_SPISEL);
else
bcsr_mod(BCSR_BOARD, BCSR_BOARD_SPISEL, 0);
}
static int db1550_map_pci_irq(const struct pci_dev *d, u8 slot, u8 pin)
{
if ((slot < 11) || (slot > 13) || pin == 0)
return -1;
if (slot == 11)
return (pin == 1) ? AU1550_PCI_INTC : 0xff;
if (slot == 12) {
switch (pin) {
case 1: return AU1550_PCI_INTB;
case 2: return AU1550_PCI_INTC;
case 3: return AU1550_PCI_INTD;
case 4: return AU1550_PCI_INTA;
}
}
if (slot == 13) {
switch (pin) {
case 1: return AU1550_PCI_INTA;
case 2: return AU1550_PCI_INTB;
case 3: return AU1550_PCI_INTC;
case 4: return AU1550_PCI_INTD;
}
}
return -1;
}
static int __init db1550_pci_init(void)
{
return platform_device_register(&db1550_pci_host_dev);
}
static int __init db1550_dev_init(void)
{
int swapped;
irq_set_irq_type(AU1550_GPIO0_INT, IRQ_TYPE_EDGE_BOTH);
irq_set_irq_type(AU1550_GPIO1_INT, IRQ_TYPE_EDGE_BOTH);
irq_set_irq_type(AU1550_GPIO3_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1550_GPIO5_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1550_GPIO21_INT, IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(AU1550_GPIO22_INT, IRQ_TYPE_LEVEL_LOW);
i2c_register_board_info(0, db1550_i2c_devs,
ARRAY_SIZE(db1550_i2c_devs));
spi_register_board_info(db1550_spi_devs,
ARRAY_SIZE(db1550_i2c_devs));
__raw_writel(PSC_SEL_CLK_SERCLK,
(void __iomem *)KSEG1ADDR(AU1550_PSC1_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
__raw_writel(PSC_SEL_CLK_SERCLK,
(void __iomem *)KSEG1ADDR(AU1550_PSC3_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
__raw_writel(PSC_SEL_CLK_INTCLK,
(void __iomem *)KSEG1ADDR(AU1550_PSC0_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
__raw_writel(PSC_SEL_CLK_INTCLK,
(void __iomem *)KSEG1ADDR(AU1550_PSC2_PHYS_ADDR) + PSC_SEL_OFFSET);
wmb();
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x000010000 - 1,
AU1550_GPIO3_INT, AU1550_GPIO0_INT,
0, 0, 0);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x004400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x004400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x004000000,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x004010000 - 1,
AU1550_GPIO5_INT, AU1550_GPIO1_INT,
0, 0, 1);
swapped = bcsr_read(BCSR_STATUS) & BCSR_STATUS_DB1000_SWAPBOOT;
db1x_register_norflash(128 << 20, 4, swapped);
return platform_add_devices(db1550_devs, ARRAY_SIZE(db1550_devs));
}
