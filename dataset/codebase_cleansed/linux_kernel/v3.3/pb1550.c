const char *get_system_type(void)
{
return "PB1550";
}
void __init board_setup(void)
{
u32 pin_func;
bcsr_init(PB1550_BCSR_PHYS_ADDR,
PB1550_BCSR_PHYS_ADDR + PB1550_BCSR_HEXLED_OFS);
alchemy_gpio2_enable();
pin_func = au_readl(SYS_PINFUNC);
au_sync();
pin_func |= SYS_PF_MUST_BE_SET | SYS_PF_PSC1_S1;
au_writel(pin_func, SYS_PINFUNC);
bcsr_write(BCSR_PCMCIA, 0);
printk(KERN_INFO "AMD Alchemy Pb1550 Board\n");
}
static int pb1550_map_pci_irq(const struct pci_dev *d, u8 slot, u8 pin)
{
if ((slot < 12) || (slot > 13) || pin == 0)
return -1;
if (slot == 12) {
switch (pin) {
case 1: return AU1500_PCI_INTB;
case 2: return AU1500_PCI_INTC;
case 3: return AU1500_PCI_INTD;
case 4: return AU1500_PCI_INTA;
}
}
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
static void __init pb1550_nand_setup(void)
{
int boot_swapboot = (au_readl(MEM_STSTAT) & (0x7 << 1)) |
((bcsr_read(BCSR_STATUS) >> 6) & 0x1);
switch (boot_swapboot) {
case 0:
case 2:
case 8:
case 0xC:
case 0xD:
pb1550_nand_pd.devwidth = 1;
case 1:
case 9:
case 3:
case 0xE:
case 0xF:
platform_device_register(&pb1550_nand_dev);
}
}
static int __init pb1550_dev_init(void)
{
int swapped;
irq_set_irq_type(AU1550_GPIO0_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1550_GPIO1_INT, IRQF_TRIGGER_LOW);
irq_set_irq_type(AU1550_GPIO201_205_INT, IRQF_TRIGGER_HIGH);
alchemy_gpio2_enable_int(201);
alchemy_gpio2_enable_int(202);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x000400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x000010000 - 1,
AU1550_GPIO201_205_INT, AU1550_GPIO0_INT, 0, 0, 0);
db1x_register_pcmcia_socket(
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x008000000,
AU1000_PCMCIA_ATTR_PHYS_ADDR + 0x008400000 - 1,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x008000000,
AU1000_PCMCIA_MEM_PHYS_ADDR + 0x008400000 - 1,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x008000000,
AU1000_PCMCIA_IO_PHYS_ADDR + 0x008010000 - 1,
AU1550_GPIO201_205_INT, AU1550_GPIO1_INT, 0, 0, 1);
gpio_direction_input(206);
pb1550_nand_setup();
swapped = bcsr_read(BCSR_STATUS) & BCSR_STATUS_PB1550_SWAPBOOT;
db1x_register_norflash(128 * 1024 * 1024, 4, swapped);
platform_device_register(&pb1550_pci_host);
platform_device_register(&pb1550_i2c_dev);
return 0;
}
