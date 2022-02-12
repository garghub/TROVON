static inline void
rx164_update_irq_hw(unsigned long mask)
{
volatile unsigned int *irq_mask;
irq_mask = (void *)(POLARIS_DENSE_CONFIG_BASE + 0x74);
*irq_mask = mask;
mb();
*irq_mask;
}
static inline void
rx164_enable_irq(struct irq_data *d)
{
rx164_update_irq_hw(cached_irq_mask |= 1UL << (d->irq - 16));
}
static void
rx164_disable_irq(struct irq_data *d)
{
rx164_update_irq_hw(cached_irq_mask &= ~(1UL << (d->irq - 16)));
}
static void
rx164_device_interrupt(unsigned long vector)
{
unsigned long pld;
volatile unsigned int *dirr;
long i;
dirr = (void *)(POLARIS_DENSE_CONFIG_BASE + 0x84);
pld = *dirr;
while (pld) {
i = ffz(~pld);
pld &= pld - 1;
if (i == 20) {
isa_no_iack_sc_device_interrupt(vector);
} else {
handle_irq(16+i);
}
}
}
static void __init
rx164_init_irq(void)
{
long i;
rx164_update_irq_hw(0);
for (i = 16; i < 40; ++i) {
irq_set_chip_and_handler(i, &rx164_irq_type, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
init_i8259a_irqs();
common_init_isa_dma();
setup_irq(16+20, &isa_cascade_irqaction);
}
static int
rx164_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
#if 0
static char irq_tab_pass1[6][5] __initdata = {
{ 16+3, 16+3, 16+8, 16+13, 16+18},
{ 16+5, 16+5, 16+10, 16+15, 16+20},
{ 16+4, 16+4, 16+9, 16+14, 16+19},
{ -1, -1, -1, -1, -1},
{ 16+2, 16+2, 16+7, 16+12, 16+17},
{ 16+1, 16+1, 16+6, 16+11, 16+16},
};
#else
static char irq_tab[6][5] = {
{ 16+0, 16+0, 16+6, 16+11, 16+16},
{ 16+1, 16+1, 16+7, 16+12, 16+17},
{ -1, -1, -1, -1, -1},
{ 16+2, 16+2, 16+8, 16+13, 16+18},
{ 16+3, 16+3, 16+9, 16+14, 16+19},
{ 16+4, 16+4, 16+10, 16+15, 16+5},
};
#endif
const long min_idsel = 5, max_idsel = 10, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
