static void ixdp2x01_irq_mask(struct irq_data *d)
{
ixp2000_reg_wrb(IXDP2X01_INT_MASK_SET_REG,
IXP2000_BOARD_IRQ_MASK(d->irq));
}
static void ixdp2x01_irq_unmask(struct irq_data *d)
{
ixp2000_reg_write(IXDP2X01_INT_MASK_CLR_REG,
IXP2000_BOARD_IRQ_MASK(d->irq));
}
static void ixdp2x01_irq_handler(unsigned int irq, struct irq_desc *desc)
{
u32 ex_interrupt;
int i;
desc->irq_data.chip->irq_mask(&desc->irq_data);
ex_interrupt = *IXDP2X01_INT_STAT_REG & valid_irq_mask;
if (!ex_interrupt) {
printk(KERN_ERR "Spurious IXDP2X01 CPLD interrupt!\n");
return;
}
for (i = 0; i < IXP2000_BOARD_IRQS; i++) {
if (ex_interrupt & (1 << i)) {
int cpld_irq = IXP2000_BOARD_IRQ(0) + i;
generic_handle_irq(cpld_irq);
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
void __init ixdp2x01_init_irq(void)
{
int irq = 0;
ixp2000_init_irq();
if (machine_is_ixdp2401())
valid_irq_mask = IXDP2401_VALID_IRQ_MASK;
else
valid_irq_mask = IXDP2801_VALID_IRQ_MASK;
ixp2000_reg_write(IXDP2X01_INT_MASK_SET_REG, 0xffffffff);
ixp2000_reg_wrb(IXDP2X01_INT_SIM_REG, 0);
for (irq = NR_IXP2000_IRQS; irq < NR_IXDP2X01_IRQS; irq++) {
if (irq & valid_irq_mask) {
irq_set_chip_and_handler(irq, &ixdp2x01_irq_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID);
} else {
set_irq_flags(irq, 0);
}
}
irq_set_chained_handler(IRQ_IXP2000_PCIB, ixdp2x01_irq_handler);
}
static void __init ixdp2x01_map_io(void)
{
ixp2000_map_io();
iotable_init(&ixdp2x01_io_desc, 1);
}
static void ixdp2x01_uart_init(void)
{
platform_device_register(&ixdp2x01_serial_device1);
platform_device_register(&ixdp2x01_serial_device2);
}
static int __init ixdp2x01_clock_setup(char *str)
{
ixdp2x01_clock = simple_strtoul(str, NULL, 10);
return 1;
}
static void __init ixdp2x01_timer_init(void)
{
if (!ixdp2x01_clock)
ixdp2x01_clock = 50000000;
ixp2000_init_time(ixdp2x01_clock);
}
void __init ixdp2x01_pci_preinit(void)
{
ixp2000_reg_write(IXP2000_PCI_ADDR_EXT, 0x00000000);
ixp2000_pci_preinit();
pcibios_setup("firmware");
}
static int __init ixdp2x01_pci_map_irq(const struct pci_dev *dev, u8 slot,
u8 pin)
{
u8 bus = dev->bus->number;
u32 devpin = DEVPIN(PCI_SLOT(dev->devfn), pin);
struct pci_bus *tmp_bus = dev->bus;
if (bus == 0) {
return -1;
}
while ((tmp_bus->parent != NULL) && (tmp_bus->parent->parent != NULL)) {
tmp_bus = tmp_bus->parent;
}
switch (tmp_bus->self->devfn | (tmp_bus->self->bus->number << 8)) {
case 0x0008:
if (tmp_bus == dev->bus) {
switch (devpin) {
case DEVPIN(1, 1):
if (machine_is_ixdp2401())
return IRQ_IXDP2401_INTA_82546;
return -1;
case DEVPIN(1, 2):
if (machine_is_ixdp2401())
return IRQ_IXDP2401_INTB_82546;
return -1;
case DEVPIN(0, 1):
return IRQ_IXDP2X01_SPCI_PMC_INTA;
case DEVPIN(0, 2):
return IRQ_IXDP2X01_SPCI_PMC_INTB;
case DEVPIN(0, 3):
return IRQ_IXDP2X01_SPCI_PMC_INTC;
case DEVPIN(0, 4):
return IRQ_IXDP2X01_SPCI_PMC_INTD;
}
}
break;
case 0x0010:
if (tmp_bus == dev->bus) {
switch (devpin) {
case DEVPIN(0, 1):
return IRQ_IXDP2X01_SPCI_DB_0;
case DEVPIN(1, 1):
return IRQ_IXDP2X01_SPCI_DB_1;
}
} else {
}
break;
}
return -1;
}
static int ixdp2x01_pci_setup(int nr, struct pci_sys_data *sys)
{
sys->mem_offset = 0xe0000000;
if (machine_is_ixdp2801() || machine_is_ixdp28x5())
sys->mem_offset -= ((*IXP2000_PCI_ADDR_EXT & 0xE000) << 16);
return ixp2000_pci_setup(nr, sys);
}
int __init ixdp2x01_pci_init(void)
{
if (machine_is_ixdp2401() || machine_is_ixdp2801() ||\
machine_is_ixdp28x5())
pci_common_init(&ixdp2x01_pci);
return 0;
}
static unsigned long ixdp2x01_flash_bank_setup(unsigned long ofs)
{
ixp2000_reg_wrb(IXDP2X01_CPLD_FLASH_REG,
((ofs >> IXDP2X01_FLASH_WINDOW_BITS) | IXDP2X01_CPLD_FLASH_INTERN));
return (ofs & IXDP2X01_FLASH_WINDOW_MASK);
}
static void __init ixdp2x01_init_machine(void)
{
ixp2000_reg_wrb(IXDP2X01_CPLD_FLASH_REG,
(IXDP2X01_CPLD_FLASH_BANK_MASK | IXDP2X01_CPLD_FLASH_INTERN));
ixdp2x01_flash_data.nr_banks =
((*IXDP2X01_CPLD_FLASH_REG & IXDP2X01_CPLD_FLASH_BANK_MASK) + 1);
platform_add_devices(ixdp2x01_devices, ARRAY_SIZE(ixdp2x01_devices));
ixp2000_uart_init();
ixdp2x01_uart_init();
}
