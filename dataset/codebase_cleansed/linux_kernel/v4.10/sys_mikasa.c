static inline void
mikasa_update_irq_hw(int mask)
{
outw(mask, 0x536);
}
static inline void
mikasa_enable_irq(struct irq_data *d)
{
mikasa_update_irq_hw(cached_irq_mask |= 1 << (d->irq - 16));
}
static void
mikasa_disable_irq(struct irq_data *d)
{
mikasa_update_irq_hw(cached_irq_mask &= ~(1 << (d->irq - 16)));
}
static void
mikasa_device_interrupt(unsigned long vector)
{
unsigned long pld;
unsigned int i;
pld = (((~inw(0x534) & 0x0000ffffUL) << 16)
| (((unsigned long) inb(0xa0)) << 8)
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
static void __init
mikasa_init_irq(void)
{
long i;
if (alpha_using_srm)
alpha_mv.device_interrupt = srm_device_interrupt;
mikasa_update_irq_hw(0);
for (i = 16; i < 32; ++i) {
irq_set_chip_and_handler(i, &mikasa_irq_type,
handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
init_i8259a_irqs();
common_init_isa_dma();
}
static int __init
mikasa_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[8][5] __initdata = {
{16+12, 16+12, 16+12, 16+12, 16+12},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ -1, -1, -1, -1, -1},
{ 16+0, 16+0, 16+1, 16+2, 16+3},
{ 16+4, 16+4, 16+5, 16+6, 16+7},
{ 16+8, 16+8, 16+9, 16+10, 16+11},
};
const long min_idsel = 6, max_idsel = 13, irqs_per_slot = 5;
return COMMON_TABLE_LOOKUP;
}
static void
mikasa_apecs_machine_check(unsigned long vector, unsigned long la_ptr)
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
process_mcheck_info(vector, la_ptr, "MIKASA APECS",
(mcheck_expected(0)
&& (code == MCHK_NO_DEVSEL
|| code == MCHK_NO_TABT)));
}
