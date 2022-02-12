static void ixdp2351_inta_mask(struct irq_data *d)
{
*IXDP2351_CPLD_INTA_MASK_SET_REG = IXDP2351_INTA_IRQ_MASK(d->irq);
}
static void ixdp2351_inta_unmask(struct irq_data *d)
{
*IXDP2351_CPLD_INTA_MASK_CLR_REG = IXDP2351_INTA_IRQ_MASK(d->irq);
}
static void ixdp2351_inta_handler(unsigned int irq, struct irq_desc *desc)
{
u16 ex_interrupt =
*IXDP2351_CPLD_INTA_STAT_REG & IXDP2351_INTA_IRQ_VALID;
int i;
desc->irq_data.chip->irq_mask(&desc->irq_data);
for (i = 0; i < IXDP2351_INTA_IRQ_NUM; i++) {
if (ex_interrupt & (1 << i)) {
int cpld_irq =
IXP23XX_MACH_IRQ(IXDP2351_INTA_IRQ_BASE + i);
generic_handle_irq(cpld_irq);
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
static void ixdp2351_intb_mask(struct irq_data *d)
{
*IXDP2351_CPLD_INTB_MASK_SET_REG = IXDP2351_INTB_IRQ_MASK(d->irq);
}
static void ixdp2351_intb_unmask(struct irq_data *d)
{
*IXDP2351_CPLD_INTB_MASK_CLR_REG = IXDP2351_INTB_IRQ_MASK(d->irq);
}
static void ixdp2351_intb_handler(unsigned int irq, struct irq_desc *desc)
{
u16 ex_interrupt =
*IXDP2351_CPLD_INTB_STAT_REG & IXDP2351_INTB_IRQ_VALID;
int i;
desc->irq_data.chip->irq_ack(&desc->irq_data);
for (i = 0; i < IXDP2351_INTB_IRQ_NUM; i++) {
if (ex_interrupt & (1 << i)) {
int cpld_irq =
IXP23XX_MACH_IRQ(IXDP2351_INTB_IRQ_BASE + i);
generic_handle_irq(cpld_irq);
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
void __init ixdp2351_init_irq(void)
{
int irq;
*IXDP2351_CPLD_INTA_MASK_SET_REG = (u16) -1;
*IXDP2351_CPLD_INTB_MASK_SET_REG = (u16) -1;
*IXDP2351_CPLD_INTA_SIM_REG = 0;
*IXDP2351_CPLD_INTB_SIM_REG = 0;
ixp23xx_init_irq();
for (irq = IXP23XX_MACH_IRQ(IXDP2351_INTA_IRQ_BASE);
irq <
IXP23XX_MACH_IRQ(IXDP2351_INTA_IRQ_BASE + IXDP2351_INTA_IRQ_NUM);
irq++) {
if (IXDP2351_INTA_IRQ_MASK(irq) & IXDP2351_INTA_IRQ_VALID) {
set_irq_flags(irq, IRQF_VALID);
irq_set_chip_and_handler(irq, &ixdp2351_inta_chip,
handle_level_irq);
}
}
for (irq = IXP23XX_MACH_IRQ(IXDP2351_INTB_IRQ_BASE);
irq <
IXP23XX_MACH_IRQ(IXDP2351_INTB_IRQ_BASE + IXDP2351_INTB_IRQ_NUM);
irq++) {
if (IXDP2351_INTB_IRQ_MASK(irq) & IXDP2351_INTB_IRQ_VALID) {
set_irq_flags(irq, IRQF_VALID);
irq_set_chip_and_handler(irq, &ixdp2351_intb_chip,
handle_level_irq);
}
}
irq_set_chained_handler(IRQ_IXP23XX_INTA, ixdp2351_inta_handler);
irq_set_chained_handler(IRQ_IXP23XX_INTB, ixdp2351_intb_handler);
}
static int __init ixdp2351_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
u8 bus = dev->bus->number;
u32 devpin = DEVPIN(PCI_SLOT(dev->devfn), pin);
struct pci_bus *tmp_bus = dev->bus;
if (!bus)
return -1;
while ((tmp_bus->parent != NULL) && (tmp_bus->parent->parent != NULL))
tmp_bus = tmp_bus->parent;
switch (tmp_bus->self->devfn | (tmp_bus->self->bus->number << 8)) {
case 0x0008:
if (tmp_bus == dev->bus) {
switch (devpin) {
case DEVPIN(1, 1):
return IRQ_IXDP2351_INTA_82546;
case DEVPIN(1, 2):
return IRQ_IXDP2351_INTB_82546;
case DEVPIN(0, 1):
case DEVPIN(2, 4):
return IRQ_IXDP2351_SPCI_PMC_INTA;
case DEVPIN(0, 2):
case DEVPIN(2, 1):
return IRQ_IXDP2351_SPCI_PMC_INTB;
case DEVPIN(0, 3):
case DEVPIN(2, 2):
return IRQ_IXDP2351_SPCI_PMC_INTC;
case DEVPIN(0, 4):
case DEVPIN(2, 3):
return IRQ_IXDP2351_SPCI_PMC_INTD;
}
} else {
return -1;
}
break;
case 0x0010:
if (tmp_bus == dev->bus) {
switch (devpin) {
case DEVPIN(0, 1):
case DEVPIN(0, 2):
case DEVPIN(0, 3):
case DEVPIN(0, 4):
return IRQ_IXDP2351_SPCI_DB_0;
case DEVPIN(1, 1):
case DEVPIN(1, 2):
case DEVPIN(1, 3):
case DEVPIN(1, 4):
return IRQ_IXDP2351_SPCI_DB_1;
case DEVPIN(2, 1):
case DEVPIN(2, 2):
case DEVPIN(2, 3):
case DEVPIN(2, 4):
case DEVPIN(3, 1):
case DEVPIN(3, 2):
case DEVPIN(3, 3):
case DEVPIN(3, 4):
return IRQ_IXDP2351_SPCI_FIC;
}
} else {
return -1;
}
break;
}
return -1;
}
int __init ixdp2351_pci_init(void)
{
if (machine_is_ixdp2351())
pci_common_init(&ixdp2351_pci);
return 0;
}
static void __init ixdp2351_map_io(void)
{
ixp23xx_map_io();
iotable_init(ixdp2351_io_desc, ARRAY_SIZE(ixdp2351_io_desc));
}
static void __init ixdp2351_init(void)
{
platform_device_register(&ixdp2351_flash);
IXP23XX_EXP_CS0[0] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[1] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[2] |= IXP23XX_FLASH_WRITABLE;
IXP23XX_EXP_CS0[3] |= IXP23XX_FLASH_WRITABLE;
ixp23xx_sys_init();
}
