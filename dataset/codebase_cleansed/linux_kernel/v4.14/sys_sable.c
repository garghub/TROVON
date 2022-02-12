static void
sable_update_irq_hw(unsigned long bit, unsigned long mask)
{
int port = 0x537;
if (bit >= 16) {
port = 0x53d;
mask >>= 16;
} else if (bit >= 8) {
port = 0x53b;
mask >>= 8;
}
outb(mask, port);
}
static void
sable_ack_irq_hw(unsigned long bit)
{
int port, val1, val2;
if (bit >= 16) {
port = 0x53c;
val1 = 0xE0 | (bit - 16);
val2 = 0xE0 | 4;
} else if (bit >= 8) {
port = 0x53a;
val1 = 0xE0 | (bit - 8);
val2 = 0xE0 | 3;
} else {
port = 0x536;
val1 = 0xE0 | (bit - 0);
val2 = 0xE0 | 1;
}
outb(val1, port);
outb(val2, 0x534);
}
static void __init
sable_init_irq(void)
{
outb(-1, 0x537);
outb(-1, 0x53b);
outb(-1, 0x53d);
outb(0x44, 0x535);
sable_lynx_irq_swizzle = &sable_irq_swizzle;
sable_lynx_init_irq(40);
}
static int
sable_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[9][5] = {
{ 32+0, 32+0, 32+0, 32+0, 32+0},
{ 32+1, 32+1, 32+1, 32+1, 32+1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ 32+2, 32+2, 32+2, 32+2, 32+2},
{ 32+3, 32+3, 32+3, 32+3, 32+3},
{ 32+4, 32+4, 32+4, 32+4, 32+4}
};
long min_idsel = 0, max_idsel = 8, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static void
lynx_update_irq_hw(unsigned long bit, unsigned long mask)
{
*(vulp)T2_AIR = 0x40;
mb();
*(vulp)T2_AIR;
mb();
*(vulp)T2_DIR = mask;
mb();
mb();
}
static void
lynx_ack_irq_hw(unsigned long bit)
{
*(vulp)T2_VAR = (u_long) bit;
mb();
mb();
}
static void __init
lynx_init_irq(void)
{
sable_lynx_irq_swizzle = &lynx_irq_swizzle;
sable_lynx_init_irq(64);
}
static int
lynx_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[19][5] = {
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ 28, 28, 28, 28, 28},
{ -1, -1, -1, -1, -1},
{ 32, 32, 33, 34, 35},
{ 36, 36, 37, 38, 39},
{ 40, 40, 41, 42, 43},
{ 44, 44, 45, 46, 47},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ 28, 28, 28, 28, 28},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ 48, 48, 49, 50, 51},
{ 52, 52, 53, 54, 55},
{ 56, 56, 57, 58, 59},
{ 60, 60, 61, 62, 63}
};
const long min_idsel = 2, max_idsel = 20, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static u8
lynx_swizzle(struct pci_dev *dev, u8 *pinp)
{
int slot, pin = *pinp;
if (dev->bus->number == 0) {
slot = PCI_SLOT(dev->devfn);
}
else if (PCI_SLOT(dev->bus->self->devfn) == 3) {
slot = PCI_SLOT(dev->devfn) + 11;
}
else
{
do {
if (PCI_SLOT(dev->bus->self->devfn) == 3) {
slot = PCI_SLOT(dev->devfn) + 11;
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
static inline void
sable_lynx_enable_irq(struct irq_data *d)
{
unsigned long bit, mask;
bit = sable_lynx_irq_swizzle->irq_to_mask[d->irq];
spin_lock(&sable_lynx_irq_lock);
mask = sable_lynx_irq_swizzle->shadow_mask &= ~(1UL << bit);
sable_lynx_irq_swizzle->update_irq_hw(bit, mask);
spin_unlock(&sable_lynx_irq_lock);
#if 0
printk("%s: mask 0x%lx bit 0x%lx irq 0x%x\n",
__func__, mask, bit, irq);
#endif
}
static void
sable_lynx_disable_irq(struct irq_data *d)
{
unsigned long bit, mask;
bit = sable_lynx_irq_swizzle->irq_to_mask[d->irq];
spin_lock(&sable_lynx_irq_lock);
mask = sable_lynx_irq_swizzle->shadow_mask |= 1UL << bit;
sable_lynx_irq_swizzle->update_irq_hw(bit, mask);
spin_unlock(&sable_lynx_irq_lock);
#if 0
printk("%s: mask 0x%lx bit 0x%lx irq 0x%x\n",
__func__, mask, bit, irq);
#endif
}
static void
sable_lynx_mask_and_ack_irq(struct irq_data *d)
{
unsigned long bit, mask;
bit = sable_lynx_irq_swizzle->irq_to_mask[d->irq];
spin_lock(&sable_lynx_irq_lock);
mask = sable_lynx_irq_swizzle->shadow_mask |= 1UL << bit;
sable_lynx_irq_swizzle->update_irq_hw(bit, mask);
sable_lynx_irq_swizzle->ack_irq_hw(bit);
spin_unlock(&sable_lynx_irq_lock);
}
static void
sable_lynx_srm_device_interrupt(unsigned long vector)
{
int bit, irq;
bit = (vector - 0x800) >> 4;
irq = sable_lynx_irq_swizzle->mask_to_irq[bit];
#if 0
printk("%s: vector 0x%lx bit 0x%x irq 0x%x\n",
__func__, vector, bit, irq);
#endif
handle_irq(irq);
}
static void __init
sable_lynx_init_irq(int nr_of_irqs)
{
long i;
for (i = 0; i < nr_of_irqs; ++i) {
irq_set_chip_and_handler(i, &sable_lynx_irq_type,
handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
common_init_isa_dma();
}
static void __init
sable_lynx_init_pci(void)
{
common_init_pci();
}
