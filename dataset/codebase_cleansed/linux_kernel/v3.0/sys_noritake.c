static inline void
noritake_update_irq_hw(int irq, int mask)
{
int port = 0x54a;
if (irq >= 32) {
mask >>= 16;
port = 0x54c;
}
outw(mask, port);
}
static void
noritake_enable_irq(struct irq_data *d)
{
noritake_update_irq_hw(d->irq, cached_irq_mask |= 1 << (d->irq - 16));
}
static void
noritake_disable_irq(struct irq_data *d)
{
noritake_update_irq_hw(d->irq, cached_irq_mask &= ~(1 << (d->irq - 16)));
}
static void
noritake_device_interrupt(unsigned long vector)
{
unsigned long pld;
unsigned int i;
pld = (((unsigned long) inw(0x54c) << 32)
| ((unsigned long) inw(0x54a) << 16)
| ((unsigned long) inb(0xa0) << 8)
| inb(0x20));
while (pld) {
i = ffz(~pld);
pld &= pld - 1;
if (i < 16) {
isa_device_interrupt(vector);
} else {
handle_irq(i);
}
}
}
static void
noritake_srm_device_interrupt(unsigned long vector)
{
int irq;
irq = (vector - 0x800) >> 4;
if (irq >= 16)
irq = irq + 1;
handle_irq(irq);
}
static void __init
noritake_init_irq(void)
{
long i;
if (alpha_using_srm)
alpha_mv.device_interrupt = noritake_srm_device_interrupt;
outw(0, 0x54a);
outw(0, 0x54c);
for (i = 16; i < 48; ++i) {
irq_set_chip_and_handler(i, &noritake_irq_type,
handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
init_i8259a_irqs();
common_init_isa_dma();
}
static int __init
noritake_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[15][5] __initdata = {
{ 16+1, 16+1, 16+1, 16+1, 16+1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ 16+2, 16+2, 16+3, 32+2, 32+3},
{ 16+4, 16+4, 16+5, 32+4, 32+5},
{ 16+6, 16+6, 16+7, 32+6, 32+7},
{ 16+8, 16+8, 16+9, 32+8, 32+9},
{ 16+1, 16+1, 16+1, 16+1, 16+1},
{ 16+8, 16+8, 16+9, 32+8, 32+9},
{16+10, 16+10, 16+11, 32+10, 32+11},
{16+12, 16+12, 16+13, 32+12, 32+13},
{16+14, 16+14, 16+15, 32+14, 32+15},
};
const long min_idsel = 5, max_idsel = 19, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static u8 __init
noritake_swizzle(struct pci_dev *dev, u8 *pinp)
{
int slot, pin = *pinp;
if (dev->bus->number == 0) {
slot = PCI_SLOT(dev->devfn);
}
else if (PCI_SLOT(dev->bus->self->devfn) == 8) {
slot = PCI_SLOT(dev->devfn) + 15;
}
else
{
do {
if (PCI_SLOT(dev->bus->self->devfn) == 8) {
slot = PCI_SLOT(dev->devfn) + 15;
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
static void
noritake_apecs_machine_check(unsigned long vector, unsigned long la_ptr)
{
#define MCHK_NO_DEVSEL 0x205U
#define MCHK_NO_TABT 0x204U
struct el_common *mchk_header;
unsigned int code;
mchk_header = (struct el_common *)la_ptr;
mb();
mb();
draina();
apecs_pci_clr_err();
wrmces(0x7);
mb();
code = mchk_header->code;
process_mcheck_info(vector, la_ptr, "NORITAKE APECS",
(mcheck_expected(0)
&& (code == MCHK_NO_DEVSEL
|| code == MCHK_NO_TABT)));
}
