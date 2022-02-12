static unsigned int
hpsim_irq_startup(struct irq_data *data)
{
return 0;
}
static void
hpsim_irq_noop(struct irq_data *data)
{
}
static int
hpsim_set_affinity_noop(struct irq_data *d, const struct cpumask *b, bool f)
{
return 0;
}
void __init
hpsim_irq_init (void)
{
int i;
for_each_active_irq(i) {
struct irq_chip *chip = irq_get_chip(i);
if (chip == &no_irq_chip)
irq_set_chip(i, &irq_type_hp_sim);
}
}
