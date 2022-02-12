static inline void
rawhide_update_irq_hw(int hose, int mask)
{
*(vuip)MCPCIA_INT_MASK0(MCPCIA_HOSE2MID(hose)) = mask;
mb();
*(vuip)MCPCIA_INT_MASK0(MCPCIA_HOSE2MID(hose));
}
static inline void
rawhide_enable_irq(struct irq_data *d)
{
unsigned int mask, hose;
unsigned int irq = d->irq;
irq -= 16;
hose = irq / 24;
if (!hose_exists(hose))
return;
irq -= hose * 24;
mask = 1 << irq;
spin_lock(&rawhide_irq_lock);
mask |= cached_irq_masks[hose];
cached_irq_masks[hose] = mask;
rawhide_update_irq_hw(hose, mask);
spin_unlock(&rawhide_irq_lock);
}
static void
rawhide_disable_irq(struct irq_data *d)
{
unsigned int mask, hose;
unsigned int irq = d->irq;
irq -= 16;
hose = irq / 24;
if (!hose_exists(hose))
return;
irq -= hose * 24;
mask = ~(1 << irq) | hose_irq_masks[hose];
spin_lock(&rawhide_irq_lock);
mask &= cached_irq_masks[hose];
cached_irq_masks[hose] = mask;
rawhide_update_irq_hw(hose, mask);
spin_unlock(&rawhide_irq_lock);
}
static void
rawhide_mask_and_ack_irq(struct irq_data *d)
{
unsigned int mask, mask1, hose;
unsigned int irq = d->irq;
irq -= 16;
hose = irq / 24;
if (!hose_exists(hose))
return;
irq -= hose * 24;
mask1 = 1 << irq;
mask = ~mask1 | hose_irq_masks[hose];
spin_lock(&rawhide_irq_lock);
mask &= cached_irq_masks[hose];
cached_irq_masks[hose] = mask;
rawhide_update_irq_hw(hose, mask);
*(vuip)MCPCIA_INT_REQ(MCPCIA_HOSE2MID(hose)) = mask1;
spin_unlock(&rawhide_irq_lock);
}
static void
rawhide_srm_device_interrupt(unsigned long vector)
{
int irq;
irq = (vector - 0x800) >> 4;
if (irq == 52) {
irq = 72;
}
irq -= ((irq + 16) >> 2) & 0x38;
handle_irq(irq);
}
static void __init
rawhide_init_irq(void)
{
struct pci_controller *hose;
long i;
mcpcia_init_hoses();
for (i = 0; i < MCPCIA_MAX_HOSES; i++) cached_irq_masks[i] = 0;
for (hose = hose_head; hose; hose = hose->next) {
unsigned int h = hose->index;
unsigned int mask = hose_irq_masks[h];
cached_irq_masks[h] = mask;
*(vuip)MCPCIA_INT_MASK0(MCPCIA_HOSE2MID(h)) = mask;
*(vuip)MCPCIA_INT_MASK1(MCPCIA_HOSE2MID(h)) = 0;
}
for (i = 16; i < 128; ++i) {
irq_set_chip_and_handler(i, &rawhide_irq_type,
handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
init_i8259a_irqs();
common_init_isa_dma();
}
static int __init
rawhide_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[5][5] __initdata = {
{ 16+16, 16+16, 16+16, 16+16, 16+16},
{ 16+ 0, 16+ 0, 16+ 1, 16+ 2, 16+ 3},
{ 16+ 4, 16+ 4, 16+ 5, 16+ 6, 16+ 7},
{ 16+ 8, 16+ 8, 16+ 9, 16+10, 16+11},
{ 16+12, 16+12, 16+13, 16+14, 16+15}
};
const long min_idsel = 1, max_idsel = 5, irqs_per_slot = 5;
struct pci_controller *hose = dev->sysdata;
int irq = COMMON_TABLE_LOOKUP;
if (irq >= 0)
irq += 24 * hose->index;
return irq;
}
