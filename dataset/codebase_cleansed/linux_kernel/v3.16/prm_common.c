static void omap_prcm_events_filter_priority(unsigned long *events,
unsigned long *priority_events)
{
int i;
for (i = 0; i < prcm_irq_setup->nr_regs; i++) {
priority_events[i] =
events[i] & prcm_irq_setup->priority_mask[i];
events[i] ^= priority_events[i];
}
}
static void omap_prcm_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned long pending[OMAP_PRCM_MAX_NR_PENDING_REG];
unsigned long priority_pending[OMAP_PRCM_MAX_NR_PENDING_REG];
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned int virtirq;
int nr_irq = prcm_irq_setup->nr_regs * 32;
if (prcm_irq_setup->suspended) {
prcm_irq_setup->save_and_clear_irqen(prcm_irq_setup->saved_mask);
prcm_irq_setup->suspend_save_flag = true;
}
while (!prcm_irq_setup->suspended) {
prcm_irq_setup->read_pending_irqs(pending);
if (find_first_bit(pending, nr_irq) >= nr_irq)
break;
omap_prcm_events_filter_priority(pending, priority_pending);
for_each_set_bit(virtirq, priority_pending, nr_irq)
generic_handle_irq(prcm_irq_setup->base_irq + virtirq);
for_each_set_bit(virtirq, pending, nr_irq)
generic_handle_irq(prcm_irq_setup->base_irq + virtirq);
}
if (chip->irq_ack)
chip->irq_ack(&desc->irq_data);
if (chip->irq_eoi)
chip->irq_eoi(&desc->irq_data);
chip->irq_unmask(&desc->irq_data);
prcm_irq_setup->ocp_barrier();
}
int omap_prcm_event_to_irq(const char *name)
{
int i;
if (!prcm_irq_setup || !name)
return -ENOENT;
for (i = 0; i < prcm_irq_setup->nr_irqs; i++)
if (!strcmp(prcm_irq_setup->irqs[i].name, name))
return prcm_irq_setup->base_irq +
prcm_irq_setup->irqs[i].offset;
return -ENOENT;
}
void omap_prcm_irq_cleanup(void)
{
int i;
if (!prcm_irq_setup) {
pr_err("PRCM: IRQ handler not initialized; cannot cleanup\n");
return;
}
if (prcm_irq_chips) {
for (i = 0; i < prcm_irq_setup->nr_regs; i++) {
if (prcm_irq_chips[i])
irq_remove_generic_chip(prcm_irq_chips[i],
0xffffffff, 0, 0);
prcm_irq_chips[i] = NULL;
}
kfree(prcm_irq_chips);
prcm_irq_chips = NULL;
}
kfree(prcm_irq_setup->saved_mask);
prcm_irq_setup->saved_mask = NULL;
kfree(prcm_irq_setup->priority_mask);
prcm_irq_setup->priority_mask = NULL;
irq_set_chained_handler(prcm_irq_setup->irq, NULL);
if (prcm_irq_setup->base_irq > 0)
irq_free_descs(prcm_irq_setup->base_irq,
prcm_irq_setup->nr_regs * 32);
prcm_irq_setup->base_irq = 0;
}
void omap_prcm_irq_prepare(void)
{
prcm_irq_setup->suspended = true;
}
void omap_prcm_irq_complete(void)
{
prcm_irq_setup->suspended = false;
if (!prcm_irq_setup->suspend_save_flag)
return;
prcm_irq_setup->suspend_save_flag = false;
prcm_irq_setup->restore_irqen(prcm_irq_setup->saved_mask);
}
int omap_prcm_register_chain_handler(struct omap_prcm_irq_setup *irq_setup)
{
int nr_regs;
u32 mask[OMAP_PRCM_MAX_NR_PENDING_REG];
int offset, i;
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
if (!irq_setup)
return -EINVAL;
nr_regs = irq_setup->nr_regs;
if (prcm_irq_setup) {
pr_err("PRCM: already initialized; won't reinitialize\n");
return -EINVAL;
}
if (nr_regs > OMAP_PRCM_MAX_NR_PENDING_REG) {
pr_err("PRCM: nr_regs too large\n");
return -EINVAL;
}
prcm_irq_setup = irq_setup;
prcm_irq_chips = kzalloc(sizeof(void *) * nr_regs, GFP_KERNEL);
prcm_irq_setup->saved_mask = kzalloc(sizeof(u32) * nr_regs, GFP_KERNEL);
prcm_irq_setup->priority_mask = kzalloc(sizeof(u32) * nr_regs,
GFP_KERNEL);
if (!prcm_irq_chips || !prcm_irq_setup->saved_mask ||
!prcm_irq_setup->priority_mask) {
pr_err("PRCM: kzalloc failed\n");
goto err;
}
memset(mask, 0, sizeof(mask));
for (i = 0; i < irq_setup->nr_irqs; i++) {
offset = irq_setup->irqs[i].offset;
mask[offset >> 5] |= 1 << (offset & 0x1f);
if (irq_setup->irqs[i].priority)
irq_setup->priority_mask[offset >> 5] |=
1 << (offset & 0x1f);
}
irq_set_chained_handler(irq_setup->irq, omap_prcm_irq_handler);
irq_setup->base_irq = irq_alloc_descs(-1, 0, irq_setup->nr_regs * 32,
0);
if (irq_setup->base_irq < 0) {
pr_err("PRCM: failed to allocate irq descs: %d\n",
irq_setup->base_irq);
goto err;
}
for (i = 0; i < irq_setup->nr_regs; i++) {
gc = irq_alloc_generic_chip("PRCM", 1,
irq_setup->base_irq + i * 32, prm_base,
handle_level_irq);
if (!gc) {
pr_err("PRCM: failed to allocate generic chip\n");
goto err;
}
ct = gc->chip_types;
ct->chip.irq_ack = irq_gc_ack_set_bit;
ct->chip.irq_mask = irq_gc_mask_clr_bit;
ct->chip.irq_unmask = irq_gc_mask_set_bit;
ct->regs.ack = irq_setup->ack + i * 4;
ct->regs.mask = irq_setup->mask + i * 4;
irq_setup_generic_chip(gc, mask[i], 0, IRQ_NOREQUEST, 0);
prcm_irq_chips[i] = gc;
}
if (of_have_populated_dt()) {
int irq = omap_prcm_event_to_irq("io");
omap_pcs_legacy_init(irq, irq_setup->reconfigure_io_chain);
}
return 0;
err:
omap_prcm_irq_cleanup();
return -ENOMEM;
}
void __init omap2_set_globals_prm(void __iomem *prm)
{
prm_base = prm;
}
u32 prm_read_reset_sources(void)
{
u32 ret = 1 << OMAP_UNKNOWN_RST_SRC_ID_SHIFT;
if (prm_ll_data->read_reset_sources)
ret = prm_ll_data->read_reset_sources();
else
WARN_ONCE(1, "prm: %s: no mapping function defined for reset sources\n", __func__);
return ret;
}
bool prm_was_any_context_lost_old(u8 part, s16 inst, u16 idx)
{
bool ret = true;
if (prm_ll_data->was_any_context_lost_old)
ret = prm_ll_data->was_any_context_lost_old(part, inst, idx);
else
WARN_ONCE(1, "prm: %s: no mapping function defined\n",
__func__);
return ret;
}
void prm_clear_context_loss_flags_old(u8 part, s16 inst, u16 idx)
{
if (prm_ll_data->clear_context_loss_flags_old)
prm_ll_data->clear_context_loss_flags_old(part, inst, idx);
else
WARN_ONCE(1, "prm: %s: no mapping function defined\n",
__func__);
}
int prm_register(struct prm_ll_data *pld)
{
if (!pld)
return -EINVAL;
if (prm_ll_data != &null_prm_ll_data)
return -EEXIST;
prm_ll_data = pld;
return 0;
}
int prm_unregister(struct prm_ll_data *pld)
{
if (!pld || prm_ll_data != pld)
return -EINVAL;
prm_ll_data = &null_prm_ll_data;
return 0;
}
static u32 prm_clk_readl(void __iomem *reg)
{
return omap2_clk_readl(&memmap_dummy_ck, reg);
}
static void prm_clk_writel(u32 val, void __iomem *reg)
{
omap2_clk_writel(val, &memmap_dummy_ck, reg);
}
int __init of_prcm_init(void)
{
struct device_node *np;
void __iomem *mem;
int memmap_index = 0;
ti_clk_ll_ops = &omap_clk_ll_ops;
for_each_matching_node(np, omap_prcm_dt_match_table) {
mem = of_iomap(np, 0);
clk_memmaps[memmap_index] = mem;
ti_dt_clk_init_provider(np, memmap_index);
memmap_index++;
}
ti_dt_clockdomains_setup();
return 0;
}
static int __init prm_late_init(void)
{
if (prm_ll_data->late_init)
return prm_ll_data->late_init();
return 0;
}
