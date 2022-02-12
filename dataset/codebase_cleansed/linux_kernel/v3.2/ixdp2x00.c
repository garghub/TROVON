static void ixdp2x00_irq_mask(struct irq_data *d)
{
unsigned long dummy;
static struct slowport_cfg old_cfg;
#ifdef CONFIG_ARCH_IXDP2400
if (machine_is_ixdp2400())
ixp2000_acquire_slowport(&slowport_cpld_cfg, &old_cfg);
#endif
dummy = *board_irq_mask;
dummy |= IXP2000_BOARD_IRQ_MASK(d->irq);
ixp2000_reg_wrb(board_irq_mask, dummy);
#ifdef CONFIG_ARCH_IXDP2400
if (machine_is_ixdp2400())
ixp2000_release_slowport(&old_cfg);
#endif
}
static void ixdp2x00_irq_unmask(struct irq_data *d)
{
unsigned long dummy;
static struct slowport_cfg old_cfg;
#ifdef CONFIG_ARCH_IXDP2400
if (machine_is_ixdp2400())
ixp2000_acquire_slowport(&slowport_cpld_cfg, &old_cfg);
#endif
dummy = *board_irq_mask;
dummy &= ~IXP2000_BOARD_IRQ_MASK(d->irq);
ixp2000_reg_wrb(board_irq_mask, dummy);
if (machine_is_ixdp2400())
ixp2000_release_slowport(&old_cfg);
}
static void ixdp2x00_irq_handler(unsigned int irq, struct irq_desc *desc)
{
volatile u32 ex_interrupt = 0;
static struct slowport_cfg old_cfg;
int i;
desc->irq_data.chip->irq_mask(&desc->irq_data);
#ifdef CONFIG_ARCH_IXDP2400
if (machine_is_ixdp2400())
ixp2000_acquire_slowport(&slowport_cpld_cfg, &old_cfg);
#endif
ex_interrupt = *board_irq_stat & 0xff;
if (machine_is_ixdp2400())
ixp2000_release_slowport(&old_cfg);
if(!ex_interrupt) {
printk(KERN_ERR "Spurious IXDP2x00 CPLD interrupt!\n");
return;
}
for(i = 0; i < board_irq_count; i++) {
if(ex_interrupt & (1 << i)) {
int cpld_irq = IXP2000_BOARD_IRQ(0) + i;
generic_handle_irq(cpld_irq);
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
void __init ixdp2x00_init_irq(volatile unsigned long *stat_reg, volatile unsigned long *mask_reg, unsigned long nr_of_irqs)
{
unsigned int irq;
ixp2000_init_irq();
if (!ixdp2x00_master_npu())
return;
board_irq_stat = stat_reg;
board_irq_mask = mask_reg;
board_irq_count = nr_of_irqs;
*board_irq_mask = 0xffffffff;
for(irq = IXP2000_BOARD_IRQ(0); irq < IXP2000_BOARD_IRQ(board_irq_count); irq++) {
irq_set_chip_and_handler(irq, &ixdp2x00_cpld_irq_chip,
handle_level_irq);
set_irq_flags(irq, IRQF_VALID);
}
irq_set_chained_handler(IRQ_IXP2000_PCIB, ixdp2x00_irq_handler);
}
void __init ixdp2x00_map_io(void)
{
ixp2000_map_io();
iotable_init(&ixdp2x00_io_desc, 1);
}
void ixdp2x00_slave_pci_postinit(void)
{
struct pci_dev *dev;
if((dev = pci_get_bus_and_slot(1, IXDP2X00_PMC_DEVFN))) {
pci_remove_bus_device(dev);
pci_dev_put(dev);
}
dev = pci_get_bus_and_slot(0, IXDP2X00_21555_DEVFN);
pci_remove_bus_device(dev);
pci_dev_put(dev);
}
void __init ixdp2x00_init_machine(void)
{
gpio_line_set(IXDP2X00_GPIO_I2C_ENABLE, 1);
gpio_line_config(IXDP2X00_GPIO_I2C_ENABLE, GPIO_OUT);
platform_add_devices(ixdp2x00_devices, ARRAY_SIZE(ixdp2x00_devices));
ixp2000_uart_init();
}
