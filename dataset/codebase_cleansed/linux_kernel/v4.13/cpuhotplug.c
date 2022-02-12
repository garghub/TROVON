static inline bool irq_needs_fixup(struct irq_data *d)
{
const struct cpumask *m = irq_data_get_effective_affinity_mask(d);
return cpumask_test_cpu(smp_processor_id(), m);
}
static bool migrate_one_irq(struct irq_desc *desc)
{
struct irq_data *d = irq_desc_get_irq_data(desc);
struct irq_chip *chip = irq_data_get_irq_chip(d);
bool maskchip = !irq_can_move_pcntxt(d) && !irqd_irq_masked(d);
const struct cpumask *affinity;
bool brokeaff = false;
int err;
if (!chip || !chip->irq_set_affinity) {
pr_debug("IRQ %u: Unable to migrate away\n", d->irq);
return false;
}
if (irqd_is_per_cpu(d) || !irqd_is_started(d) || !irq_needs_fixup(d)) {
irq_fixup_move_pending(desc, false);
return false;
}
irq_force_complete_move(desc);
if (irq_fixup_move_pending(desc, true))
affinity = irq_desc_get_pending_mask(desc);
else
affinity = irq_data_get_affinity_mask(d);
if (maskchip && chip->irq_mask)
chip->irq_mask(d);
if (cpumask_any_and(affinity, cpu_online_mask) >= nr_cpu_ids) {
if (irqd_affinity_is_managed(d)) {
irqd_set_managed_shutdown(d);
irq_shutdown(desc);
return false;
}
affinity = cpu_online_mask;
brokeaff = true;
}
err = irq_do_set_affinity(d, affinity, false);
if (err) {
pr_warn_ratelimited("IRQ%u: set affinity failed(%d).\n",
d->irq, err);
brokeaff = false;
}
if (maskchip && chip->irq_unmask)
chip->irq_unmask(d);
return brokeaff;
}
void irq_migrate_all_off_this_cpu(void)
{
struct irq_desc *desc;
unsigned int irq;
for_each_active_irq(irq) {
bool affinity_broken;
desc = irq_to_desc(irq);
raw_spin_lock(&desc->lock);
affinity_broken = migrate_one_irq(desc);
raw_spin_unlock(&desc->lock);
if (affinity_broken) {
pr_warn_ratelimited("IRQ %u: no longer affine to CPU%u\n",
irq, smp_processor_id());
}
}
}
static void irq_restore_affinity_of_irq(struct irq_desc *desc, unsigned int cpu)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
const struct cpumask *affinity = irq_data_get_affinity_mask(data);
if (!irqd_affinity_is_managed(data) || !desc->action ||
!irq_data_get_irq_chip(data) || !cpumask_test_cpu(cpu, affinity))
return;
if (irqd_is_managed_and_shutdown(data)) {
irq_startup(desc, IRQ_RESEND, IRQ_START_COND);
return;
}
if (!irqd_is_single_target(data))
irq_set_affinity_locked(data, affinity, false);
}
int irq_affinity_online_cpu(unsigned int cpu)
{
struct irq_desc *desc;
unsigned int irq;
irq_lock_sparse();
for_each_active_irq(irq) {
desc = irq_to_desc(irq);
raw_spin_lock_irq(&desc->lock);
irq_restore_affinity_of_irq(desc, cpu);
raw_spin_unlock_irq(&desc->lock);
}
irq_unlock_sparse();
return 0;
}
