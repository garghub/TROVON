static void irq_sim_irqmask(struct irq_data *data)
{
struct irq_sim_irq_ctx *irq_ctx = irq_data_get_irq_chip_data(data);
irq_ctx->enabled = false;
}
static void irq_sim_irqunmask(struct irq_data *data)
{
struct irq_sim_irq_ctx *irq_ctx = irq_data_get_irq_chip_data(data);
irq_ctx->enabled = true;
}
static void irq_sim_handle_irq(struct irq_work *work)
{
struct irq_sim_work_ctx *work_ctx;
work_ctx = container_of(work, struct irq_sim_work_ctx, work);
handle_simple_irq(irq_to_desc(work_ctx->irq));
}
int irq_sim_init(struct irq_sim *sim, unsigned int num_irqs)
{
int i;
sim->irqs = kmalloc_array(num_irqs, sizeof(*sim->irqs), GFP_KERNEL);
if (!sim->irqs)
return -ENOMEM;
sim->irq_base = irq_alloc_descs(-1, 0, num_irqs, 0);
if (sim->irq_base < 0) {
kfree(sim->irqs);
return sim->irq_base;
}
for (i = 0; i < num_irqs; i++) {
sim->irqs[i].irqnum = sim->irq_base + i;
sim->irqs[i].enabled = false;
irq_set_chip(sim->irq_base + i, &irq_sim_irqchip);
irq_set_chip_data(sim->irq_base + i, &sim->irqs[i]);
irq_set_handler(sim->irq_base + i, &handle_simple_irq);
irq_modify_status(sim->irq_base + i,
IRQ_NOREQUEST | IRQ_NOAUTOEN, IRQ_NOPROBE);
}
init_irq_work(&sim->work_ctx.work, irq_sim_handle_irq);
sim->irq_count = num_irqs;
return 0;
}
void irq_sim_fini(struct irq_sim *sim)
{
irq_work_sync(&sim->work_ctx.work);
irq_free_descs(sim->irq_base, sim->irq_count);
kfree(sim->irqs);
}
static void devm_irq_sim_release(struct device *dev, void *res)
{
struct irq_sim_devres *this = res;
irq_sim_fini(this->sim);
}
int devm_irq_sim_init(struct device *dev, struct irq_sim *sim,
unsigned int num_irqs)
{
struct irq_sim_devres *dr;
int rv;
dr = devres_alloc(devm_irq_sim_release, sizeof(*dr), GFP_KERNEL);
if (!dr)
return -ENOMEM;
rv = irq_sim_init(sim, num_irqs);
if (rv) {
devres_free(dr);
return rv;
}
dr->sim = sim;
devres_add(dev, dr);
return 0;
}
void irq_sim_fire(struct irq_sim *sim, unsigned int offset)
{
if (sim->irqs[offset].enabled) {
sim->work_ctx.irq = irq_sim_irqnum(sim, offset);
irq_work_queue(&sim->work_ctx.work);
}
}
int irq_sim_irqnum(struct irq_sim *sim, unsigned int offset)
{
return sim->irqs[offset].irqnum;
}
