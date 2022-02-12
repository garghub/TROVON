static void __init
ruffian_init_irq(void)
{
*(vulp)PYXIS_INT_HILO = 0x000000c0UL; mb();
*(vulp)PYXIS_INT_CNFG = 0x00002064UL; mb();
outb(0x11,0xA0);
outb(0x08,0xA1);
outb(0x02,0xA1);
outb(0x01,0xA1);
outb(0xFF,0xA1);
outb(0x11,0x20);
outb(0x00,0x21);
outb(0x04,0x21);
outb(0x01,0x21);
outb(0xFF,0x21);
outb(0x20,0xA0);
outb(0x20,0x20);
init_i8259a_irqs();
init_pyxis_irqs(0x16f0000);
common_init_isa_dma();
}
static void __init
ruffian_init_rtc(void)
{
outb(0x34, 0x43);
outb(RUFFIAN_LATCH & 0xff, 0x40);
outb(RUFFIAN_LATCH >> 8, 0x40);
outb(0xb6, 0x43);
outb(0x31, 0x42);
outb(0x13, 0x42);
setup_irq(0, &timer_irqaction);
}
static void
ruffian_kill_arch (int mode)
{
cia_kill_arch(mode);
#if 0
*(vuip) PYXIS_RESET = 0x0000dead;
mb();
#endif
}
static int __init
ruffian_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[11][5] __initdata = {
{-1, -1, -1, -1, -1},
{-1, -1, -1, -1, -1},
{44, 44, 44, 44, 44},
{-1, -1, -1, -1, -1},
{43, 43, 42, 41, 40},
{19, 19, 18, 17, 16},
{31, 31, 30, 29, 28},
{27, 27, 26, 25, 24},
{39, 39, 38, 37, 36},
{35, 35, 34, 33, 32},
{20, 20, 20, 20, 20},
};
const long min_idsel = 13, max_idsel = 23, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static u8 __init
ruffian_swizzle(struct pci_dev *dev, u8 *pinp)
{
int slot, pin = *pinp;
if (dev->bus->number == 0) {
slot = PCI_SLOT(dev->devfn);
}
else if (PCI_SLOT(dev->bus->self->devfn) == 13) {
slot = PCI_SLOT(dev->devfn) + 10;
}
else
{
do {
if (PCI_SLOT(dev->bus->self->devfn) == 13) {
slot = PCI_SLOT(dev->devfn) + 10;
break;
}
pin = pci_swizzle_interrupt_pin(dev, pin);
dev = dev->bus->self;
slot = PCI_SLOT(dev->devfn);
} while (dev->bus->self);
}
*pinp = pin;
return slot;
}
static unsigned long __init
ruffian_get_bank_size(unsigned long offset)
{
unsigned long bank_addr, bank, ret = 0;
bank_addr = (unsigned long)PYXIS_MCR + offset;
bank = *(vulp)bank_addr;
if (bank & 0x01) {
static unsigned long size[] __initdata = {
0x40000000UL,
0x20000000UL,
0x10000000UL,
0x08000000UL,
0x04000000UL,
0x02000000UL,
0x01000000UL,
0x00800000UL,
0x80000000UL,
};
bank = (bank & 0x1e) >> 1;
if (bank < ARRAY_SIZE(size))
ret = size[bank];
}
return ret;
}
