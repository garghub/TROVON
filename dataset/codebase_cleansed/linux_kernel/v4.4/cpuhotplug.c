static bool migrate_one_irq(struct irq_desc *desc)
{
struct irq_data *d = irq_desc_get_irq_data(desc);
const struct cpumask *affinity = d->common->affinity;
struct irq_chip *c;
bool ret = false;
if (irqd_is_per_cpu(d) ||
!cpumask_test_cpu(smp_processor_id(), affinity))
return false;
if (cpumask_any_and(affinity, cpu_online_mask) >= nr_cpu_ids) {
affinity = cpu_online_mask;
ret = true;
}
c = irq_data_get_irq_chip(d);
if (!c->irq_set_affinity) {
pr_debug("IRQ%u: unable to set affinity\n", d->irq);
} else {
int r = irq_do_set_affinity(d, affinity, false);
if (r)
pr_warn_ratelimited("IRQ%u: set affinity failed(%d).\n",
d->irq, r);
}
return ret;
}
void irq_migrate_all_off_this_cpu(void)
{
unsigned int irq;
struct irq_desc *desc;
unsigned long flags;
local_irq_save(flags);
for_each_active_irq(irq) {
bool affinity_broken;
desc = irq_to_desc(irq);
raw_spin_lock(&desc->lock);
affinity_broken = migrate_one_irq(desc);
raw_spin_unlock(&desc->lock);
if (affinity_broken)
pr_warn_ratelimited("IRQ%u no longer affine to CPU%u\n",
irq, smp_processor_id());
}
local_irq_restore(flags);
}
