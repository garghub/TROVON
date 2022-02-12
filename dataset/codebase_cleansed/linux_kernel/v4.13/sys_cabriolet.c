static inline void
cabriolet_update_irq_hw(unsigned int irq, unsigned long mask)
{
int ofs = (irq - 16) / 8;
outb(mask >> (16 + ofs * 8), 0x804 + ofs);
}
static inline void
cabriolet_enable_irq(struct irq_data *d)
{
cabriolet_update_irq_hw(d->irq, cached_irq_mask &= ~(1UL << d->irq));
}
static void
cabriolet_disable_irq(struct irq_data *d)
{
cabriolet_update_irq_hw(d->irq, cached_irq_mask |= 1UL << d->irq);
}
static void
cabriolet_device_interrupt(unsigned long v)
{
unsigned long pld;
unsigned int i;
pld = inb(0x804) | (inb(0x805) << 8) | (inb(0x806) << 16);
while (pld) {
i = ffz(~pld);
pld &= pld - 1;
if (i == 4) {
isa_device_interrupt(v);
} else {
handle_irq(16 + i);
}
}
}
static void __init
common_init_irq(void (*srm_dev_int)(unsigned long v))
{
init_i8259a_irqs();
if (alpha_using_srm) {
alpha_mv.device_interrupt = srm_dev_int;
init_srm_irqs(35, 0);
}
else {
long i;
outb(0xff, 0x804);
outb(0xff, 0x805);
outb(0xff, 0x806);
for (i = 16; i < 35; ++i) {
irq_set_chip_and_handler(i, &cabriolet_irq_type,
handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
}
common_init_isa_dma();
setup_irq(16+4, &isa_cascade_irqaction);
}
static void __init
cabriolet_init_irq(void)
{
common_init_irq(srm_device_interrupt);
}
static void
pc164_srm_device_interrupt(unsigned long v)
{
__min_ipl = getipl();
srm_device_interrupt(v);
__min_ipl = 0;
}
static void
pc164_device_interrupt(unsigned long v)
{
__min_ipl = getipl();
cabriolet_device_interrupt(v);
__min_ipl = 0;
}
static void __init
pc164_init_irq(void)
{
common_init_irq(pc164_srm_device_interrupt);
}
static inline int __init
eb66p_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[5][5] __initdata = {
{16+0, 16+0, 16+5, 16+9, 16+13},
{16+1, 16+1, 16+6, 16+10, 16+14},
{ -1, -1, -1, -1, -1},
{16+2, 16+2, 16+7, 16+11, 16+15},
{16+3, 16+3, 16+8, 16+12, 16+6}
};
const long min_idsel = 6, max_idsel = 10, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static inline int __init
cabriolet_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[5][5] __initdata = {
{ 16+2, 16+2, 16+7, 16+11, 16+15},
{ 16+0, 16+0, 16+5, 16+9, 16+13},
{ 16+1, 16+1, 16+6, 16+10, 16+14},
{ -1, -1, -1, -1, -1},
{ 16+3, 16+3, 16+8, 16+12, 16+16}
};
const long min_idsel = 5, max_idsel = 9, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static inline void __init
cabriolet_enable_ide(void)
{
if (pc873xx_probe() == -1) {
printk(KERN_ERR "Probing for PC873xx Super IO chip failed.\n");
} else {
printk(KERN_INFO "Found %s Super IO chip at 0x%x\n",
pc873xx_get_model(), pc873xx_get_base());
pc873xx_enable_ide();
}
}
static inline void __init
cabriolet_init_pci(void)
{
common_init_pci();
cabriolet_enable_ide();
}
static inline void __init
cia_cab_init_pci(void)
{
cia_init_pci();
cabriolet_enable_ide();
}
static inline int __init
alphapc164_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[7][5] __initdata = {
{ 16+2, 16+2, 16+9, 16+13, 16+17},
{ 16+0, 16+0, 16+7, 16+11, 16+15},
{ 16+1, 16+1, 16+8, 16+12, 16+16},
{ -1, -1, -1, -1, -1},
{ 16+3, 16+3, 16+10, 16+14, 16+18},
{ 16+6, 16+6, 16+6, 16+6, 16+6},
{ 16+5, 16+5, 16+5, 16+5, 16+5}
};
const long min_idsel = 5, max_idsel = 11, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static inline void __init
alphapc164_init_pci(void)
{
cia_init_pci();
SMC93x_Init();
}
