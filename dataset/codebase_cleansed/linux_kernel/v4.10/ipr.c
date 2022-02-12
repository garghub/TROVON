static inline struct ipr_desc *get_ipr_desc(struct irq_data *data)
{
struct irq_chip *chip = irq_data_get_irq_chip(data);
return container_of(chip, struct ipr_desc, chip);
}
static void disable_ipr_irq(struct irq_data *data)
{
struct ipr_data *p = irq_data_get_irq_chip_data(data);
unsigned long addr = get_ipr_desc(data)->ipr_offsets[p->ipr_idx];
__raw_writew(__raw_readw(addr) & (0xffff ^ (0xf << p->shift)), addr);
(void)__raw_readw(addr);
}
static void enable_ipr_irq(struct irq_data *data)
{
struct ipr_data *p = irq_data_get_irq_chip_data(data);
unsigned long addr = get_ipr_desc(data)->ipr_offsets[p->ipr_idx];
__raw_writew(__raw_readw(addr) | (p->priority << p->shift), addr);
}
void register_ipr_controller(struct ipr_desc *desc)
{
int i;
desc->chip.irq_mask = disable_ipr_irq;
desc->chip.irq_unmask = enable_ipr_irq;
for (i = 0; i < desc->nr_irqs; i++) {
struct ipr_data *p = desc->ipr_data + i;
int res;
BUG_ON(p->ipr_idx >= desc->nr_offsets);
BUG_ON(!desc->ipr_offsets[p->ipr_idx]);
res = irq_alloc_desc_at(p->irq, numa_node_id());
if (unlikely(res != p->irq && res != -EEXIST)) {
printk(KERN_INFO "can not get irq_desc for %d\n",
p->irq);
continue;
}
disable_irq_nosync(p->irq);
irq_set_chip_and_handler_name(p->irq, &desc->chip,
handle_level_irq, "level");
irq_set_chip_data(p->irq, p);
disable_ipr_irq(irq_get_irq_data(p->irq));
}
}
