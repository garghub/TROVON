static int is_80219(void)
{
return !!((read_cpuid_id() & 0xffffffe0) == 0x69052e20);
}
static int is_ep80219(void)
{
if (machine_is_ep80219() || force_ep80219)
return 1;
else
return 0;
}
static void __init iq31244_timer_init(void)
{
if (is_ep80219()) {
iop_init_time(200000000);
} else {
iop_init_time(198000000);
}
}
void __init iq31244_map_io(void)
{
iop3xx_map_io();
iotable_init(iq31244_io_desc, ARRAY_SIZE(iq31244_io_desc));
}
static int __init
ep80219_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
if (slot == 0) {
irq = IRQ_IOP32X_XINT1;
} else if (slot == 1) {
irq = IRQ_IOP32X_XINT0;
} else if (slot == 2) {
irq = IRQ_IOP32X_XINT3;
} else if (slot == 3) {
irq = IRQ_IOP32X_XINT2;
} else {
printk(KERN_ERR "ep80219_pci_map_irq() called for unknown "
"device PCI:%d:%d:%d\n", dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
irq = -1;
}
return irq;
}
static int __init
iq31244_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
if (slot == 0) {
irq = IRQ_IOP32X_XINT1;
} else if (slot == 1) {
irq = IRQ_IOP32X_XINT2;
} else if (slot == 2) {
irq = IRQ_IOP32X_XINT3;
} else if (slot == 3) {
irq = IRQ_IOP32X_XINT0;
} else {
printk(KERN_ERR "iq31244_pci_map_irq called for unknown "
"device PCI:%d:%d:%d\n", dev->bus->number,
PCI_SLOT(dev->devfn), PCI_FUNC(dev->devfn));
irq = -1;
}
return irq;
}
static int __init iq31244_pci_init(void)
{
if (is_ep80219())
pci_common_init(&ep80219_pci);
else if (machine_is_iq31244()) {
if (is_80219()) {
printk("note: iq31244 board type has been selected\n");
printk("note: to select ep80219 operation:\n");
printk("\t1/ specify \"force_ep80219\" on the kernel"
" command line\n");
printk("\t2/ update boot loader to pass"
" the ep80219 id: %d\n", MACH_TYPE_EP80219);
}
pci_common_init(&iq31244_pci);
}
return 0;
}
void ep80219_power_off(void)
{
*IOP3XX_IDBR1 = 0x60;
*IOP3XX_ICR1 = 0xE9;
mdelay(1);
*IOP3XX_IDBR1 = 0x0F;
*IOP3XX_ICR1 = 0xE8;
mdelay(1);
*IOP3XX_IDBR1 = 0x03;
*IOP3XX_ICR1 = 0xE8;
mdelay(1);
*IOP3XX_IDBR1 = 0x00;
*IOP3XX_ICR1 = 0xEA;
while (1)
;
}
static void __init iq31244_init_machine(void)
{
register_iop32x_gpio();
platform_device_register(&iop3xx_i2c0_device);
platform_device_register(&iop3xx_i2c1_device);
platform_device_register(&iq31244_flash_device);
platform_device_register(&iq31244_serial_device);
platform_device_register(&iop3xx_dma_0_channel);
platform_device_register(&iop3xx_dma_1_channel);
if (is_ep80219())
pm_power_off = ep80219_power_off;
if (!is_80219())
platform_device_register(&iop3xx_aau_channel);
}
static int __init force_ep80219_setup(char *str)
{
force_ep80219 = 1;
return 1;
}
