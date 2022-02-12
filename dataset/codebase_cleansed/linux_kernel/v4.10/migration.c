void irq_move_masked_irq(struct irq_data *idata)
{
struct irq_desc *desc = irq_data_to_desc(idata);
struct irq_chip *chip = desc->irq_data.chip;
if (likely(!irqd_is_setaffinity_pending(&desc->irq_data)))
return;
irqd_clr_move_pending(&desc->irq_data);
if (irqd_is_per_cpu(&desc->irq_data)) {
WARN_ON(1);
return;
}
if (unlikely(cpumask_empty(desc->pending_mask)))
return;
if (!chip->irq_set_affinity)
return;
assert_raw_spin_locked(&desc->lock);
if (cpumask_any_and(desc->pending_mask, cpu_online_mask) < nr_cpu_ids)
irq_do_set_affinity(&desc->irq_data, desc->pending_mask, false);
cpumask_clear(desc->pending_mask);
}
void irq_move_irq(struct irq_data *idata)
{
bool masked;
idata = irq_desc_get_irq_data(irq_data_to_desc(idata));
if (likely(!irqd_is_setaffinity_pending(idata)))
return;
if (unlikely(irqd_irq_disabled(idata)))
return;
masked = irqd_irq_masked(idata);
if (!masked)
idata->chip->irq_mask(idata);
irq_move_masked_irq(idata);
if (!masked)
idata->chip->irq_unmask(idata);
}
