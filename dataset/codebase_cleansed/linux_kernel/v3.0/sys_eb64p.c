static inline void
eb64p_update_irq_hw(unsigned int irq, unsigned long mask)
{
outb(mask >> (irq >= 24 ? 24 : 16), (irq >= 24 ? 0x27 : 0x26));
}
static inline void
eb64p_enable_irq(struct irq_data *d)
{
eb64p_update_irq_hw(d->irq, cached_irq_mask &= ~(1 << d->irq));
}
static void
eb64p_disable_irq(struct irq_data *d)
{
eb64p_update_irq_hw(d->irq, cached_irq_mask |= 1 << d->irq);
}
static void
eb64p_device_interrupt(unsigned long vector)
{
unsigned long pld;
unsigned int i;
pld = inb(0x26) | (inb(0x27) << 8);
while (pld) {
i = ffz(~pld);
pld &= pld - 1;
if (i == 5) {
isa_device_interrupt(vector);
} else {
handle_irq(16 + i);
}
}
}
static void __init
eb64p_init_irq(void)
{
long i;
#if defined(CONFIG_ALPHA_GENERIC) || defined(CONFIG_ALPHA_CABRIOLET)
if (inw(0x806) != 0xffff) {
extern struct alpha_machine_vector cabriolet_mv;
printk("Detected Cabriolet: correcting HWRPB.\n");
hwrpb->sys_variation |= 2L << 10;
hwrpb_update_checksum(hwrpb);
alpha_mv = cabriolet_mv;
alpha_mv.init_irq();
return;
}
#endif
outb(0xff, 0x26);
outb(0xff, 0x27);
init_i8259a_irqs();
for (i = 16; i < 32; ++i) {
irq_set_chip_and_handler(i, &eb64p_irq_type, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
common_init_isa_dma();
setup_irq(16+5, &isa_cascade_irqaction);
}
static int __init
eb64p_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[5][5] __initdata = {
{16+7, 16+7, 16+7, 16+7, 16+7},
{16+0, 16+0, 16+2, 16+4, 16+9},
{16+1, 16+1, 16+3, 16+8, 16+10},
{ -1, -1, -1, -1, -1},
{16+6, 16+6, 16+6, 16+6, 16+6},
};
const long min_idsel = 5, max_idsel = 9, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
