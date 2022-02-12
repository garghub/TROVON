static void uv_program_mmr(struct irq_cfg *cfg, struct uv_irq_2_mmr_pnode *info)
{
unsigned long mmr_value;
struct uv_IO_APIC_route_entry *entry;
BUILD_BUG_ON(sizeof(struct uv_IO_APIC_route_entry) !=
sizeof(unsigned long));
mmr_value = 0;
entry = (struct uv_IO_APIC_route_entry *)&mmr_value;
entry->vector = cfg->vector;
entry->delivery_mode = apic->irq_delivery_mode;
entry->dest_mode = apic->irq_dest_mode;
entry->polarity = 0;
entry->trigger = 0;
entry->mask = 0;
entry->dest = cfg->dest_apicid;
uv_write_global_mmr64(info->pnode, info->offset, mmr_value);
}
static void uv_noop(struct irq_data *data) { }
static void uv_ack_apic(struct irq_data *data)
{
ack_APIC_irq();
}
static int
uv_set_irq_affinity(struct irq_data *data, const struct cpumask *mask,
bool force)
{
struct irq_data *parent = data->parent_data;
struct irq_cfg *cfg = irqd_cfg(data);
int ret;
ret = parent->chip->irq_set_affinity(parent, mask, force);
if (ret >= 0) {
uv_program_mmr(cfg, data->chip_data);
send_cleanup_vector(cfg);
}
return ret;
}
static int uv_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
struct uv_irq_2_mmr_pnode *chip_data;
struct irq_alloc_info *info = arg;
struct irq_data *irq_data = irq_domain_get_irq_data(domain, virq);
int ret;
if (nr_irqs > 1 || !info || info->type != X86_IRQ_ALLOC_TYPE_UV)
return -EINVAL;
chip_data = kmalloc_node(sizeof(*chip_data), GFP_KERNEL,
irq_data->node);
if (!chip_data)
return -ENOMEM;
ret = irq_domain_alloc_irqs_parent(domain, virq, nr_irqs, arg);
if (ret >= 0) {
if (info->uv_limit == UV_AFFINITY_CPU)
irq_set_status_flags(virq, IRQ_NO_BALANCING);
else
irq_set_status_flags(virq, IRQ_MOVE_PCNTXT);
chip_data->pnode = uv_blade_to_pnode(info->uv_blade);
chip_data->offset = info->uv_offset;
irq_domain_set_info(domain, virq, virq, &uv_irq_chip, chip_data,
handle_percpu_irq, NULL, info->uv_name);
} else {
kfree(chip_data);
}
return ret;
}
static void uv_domain_free(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *irq_data = irq_domain_get_irq_data(domain, virq);
BUG_ON(nr_irqs != 1);
kfree(irq_data->chip_data);
irq_clear_status_flags(virq, IRQ_MOVE_PCNTXT);
irq_clear_status_flags(virq, IRQ_NO_BALANCING);
irq_domain_free_irqs_top(domain, virq, nr_irqs);
}
static void uv_domain_activate(struct irq_domain *domain,
struct irq_data *irq_data)
{
uv_program_mmr(irqd_cfg(irq_data), irq_data->chip_data);
}
static void uv_domain_deactivate(struct irq_domain *domain,
struct irq_data *irq_data)
{
unsigned long mmr_value;
struct uv_IO_APIC_route_entry *entry;
mmr_value = 0;
entry = (struct uv_IO_APIC_route_entry *)&mmr_value;
entry->mask = 1;
uv_program_mmr(irqd_cfg(irq_data), irq_data->chip_data);
}
static struct irq_domain *uv_get_irq_domain(void)
{
static struct irq_domain *uv_domain;
static DEFINE_MUTEX(uv_lock);
mutex_lock(&uv_lock);
if (uv_domain == NULL) {
uv_domain = irq_domain_add_tree(NULL, &uv_domain_ops, NULL);
if (uv_domain)
uv_domain->parent = x86_vector_domain;
}
mutex_unlock(&uv_lock);
return uv_domain;
}
int uv_setup_irq(char *irq_name, int cpu, int mmr_blade,
unsigned long mmr_offset, int limit)
{
struct irq_alloc_info info;
struct irq_domain *domain = uv_get_irq_domain();
if (!domain)
return -ENOMEM;
init_irq_alloc_info(&info, cpumask_of(cpu));
info.type = X86_IRQ_ALLOC_TYPE_UV;
info.uv_limit = limit;
info.uv_blade = mmr_blade;
info.uv_offset = mmr_offset;
info.uv_name = irq_name;
return irq_domain_alloc_irqs(domain, 1,
uv_blade_to_memory_nid(mmr_blade), &info);
}
void uv_teardown_irq(unsigned int irq)
{
irq_domain_free_irqs(irq, 1);
}
