struct irq_domain *__irq_domain_add(struct device_node *of_node, int size,
irq_hw_number_t hwirq_max, int direct_max,
const struct irq_domain_ops *ops,
void *host_data)
{
struct irq_domain *domain;
domain = kzalloc_node(sizeof(*domain) + (sizeof(unsigned int) * size),
GFP_KERNEL, of_node_to_nid(of_node));
if (WARN_ON(!domain))
return NULL;
INIT_RADIX_TREE(&domain->revmap_tree, GFP_KERNEL);
domain->ops = ops;
domain->host_data = host_data;
domain->of_node = of_node_get(of_node);
domain->hwirq_max = hwirq_max;
domain->revmap_size = size;
domain->revmap_direct_max_irq = direct_max;
mutex_lock(&irq_domain_mutex);
list_add(&domain->link, &irq_domain_list);
mutex_unlock(&irq_domain_mutex);
pr_debug("Added domain %s\n", domain->name);
return domain;
}
void irq_domain_remove(struct irq_domain *domain)
{
mutex_lock(&irq_domain_mutex);
WARN_ON(domain->revmap_tree.height);
list_del(&domain->link);
if (unlikely(irq_default_domain == domain))
irq_set_default_host(NULL);
mutex_unlock(&irq_domain_mutex);
pr_debug("Removed domain %s\n", domain->name);
of_node_put(domain->of_node);
kfree(domain);
}
struct irq_domain *irq_domain_add_simple(struct device_node *of_node,
unsigned int size,
unsigned int first_irq,
const struct irq_domain_ops *ops,
void *host_data)
{
struct irq_domain *domain;
domain = __irq_domain_add(of_node, size, size, 0, ops, host_data);
if (!domain)
return NULL;
if (first_irq > 0) {
if (IS_ENABLED(CONFIG_SPARSE_IRQ)) {
int rc = irq_alloc_descs(first_irq, first_irq, size,
of_node_to_nid(of_node));
if (rc < 0)
pr_info("Cannot allocate irq_descs @ IRQ%d, assuming pre-allocated\n",
first_irq);
}
irq_domain_associate_many(domain, first_irq, 0, size);
}
return domain;
}
struct irq_domain *irq_domain_add_legacy(struct device_node *of_node,
unsigned int size,
unsigned int first_irq,
irq_hw_number_t first_hwirq,
const struct irq_domain_ops *ops,
void *host_data)
{
struct irq_domain *domain;
domain = __irq_domain_add(of_node, first_hwirq + size,
first_hwirq + size, 0, ops, host_data);
if (!domain)
return NULL;
irq_domain_associate_many(domain, first_irq, first_hwirq, size);
return domain;
}
struct irq_domain *irq_find_host(struct device_node *node)
{
struct irq_domain *h, *found = NULL;
int rc;
mutex_lock(&irq_domain_mutex);
list_for_each_entry(h, &irq_domain_list, link) {
if (h->ops->match)
rc = h->ops->match(h, node);
else
rc = (h->of_node != NULL) && (h->of_node == node);
if (rc) {
found = h;
break;
}
}
mutex_unlock(&irq_domain_mutex);
return found;
}
void irq_set_default_host(struct irq_domain *domain)
{
pr_debug("Default domain set to @0x%p\n", domain);
irq_default_domain = domain;
}
void irq_domain_disassociate(struct irq_domain *domain, unsigned int irq)
{
struct irq_data *irq_data = irq_get_irq_data(irq);
irq_hw_number_t hwirq;
if (WARN(!irq_data || irq_data->domain != domain,
"virq%i doesn't exist; cannot disassociate\n", irq))
return;
hwirq = irq_data->hwirq;
irq_set_status_flags(irq, IRQ_NOREQUEST);
irq_set_chip_and_handler(irq, NULL, NULL);
synchronize_irq(irq);
if (domain->ops->unmap)
domain->ops->unmap(domain, irq);
smp_mb();
irq_data->domain = NULL;
irq_data->hwirq = 0;
if (hwirq < domain->revmap_size) {
domain->linear_revmap[hwirq] = 0;
} else {
mutex_lock(&revmap_trees_mutex);
radix_tree_delete(&domain->revmap_tree, hwirq);
mutex_unlock(&revmap_trees_mutex);
}
}
int irq_domain_associate(struct irq_domain *domain, unsigned int virq,
irq_hw_number_t hwirq)
{
struct irq_data *irq_data = irq_get_irq_data(virq);
int ret;
if (WARN(hwirq >= domain->hwirq_max,
"error: hwirq 0x%x is too large for %s\n", (int)hwirq, domain->name))
return -EINVAL;
if (WARN(!irq_data, "error: virq%i is not allocated", virq))
return -EINVAL;
if (WARN(irq_data->domain, "error: virq%i is already associated", virq))
return -EINVAL;
mutex_lock(&irq_domain_mutex);
irq_data->hwirq = hwirq;
irq_data->domain = domain;
if (domain->ops->map) {
ret = domain->ops->map(domain, virq, hwirq);
if (ret != 0) {
if (ret != -EPERM) {
pr_info("%s didn't like hwirq-0x%lx to VIRQ%i mapping (rc=%d)\n",
domain->name, hwirq, virq, ret);
}
irq_data->domain = NULL;
irq_data->hwirq = 0;
mutex_unlock(&irq_domain_mutex);
return ret;
}
if (!domain->name && irq_data->chip)
domain->name = irq_data->chip->name;
}
if (hwirq < domain->revmap_size) {
domain->linear_revmap[hwirq] = virq;
} else {
mutex_lock(&revmap_trees_mutex);
radix_tree_insert(&domain->revmap_tree, hwirq, irq_data);
mutex_unlock(&revmap_trees_mutex);
}
mutex_unlock(&irq_domain_mutex);
irq_clear_status_flags(virq, IRQ_NOREQUEST);
return 0;
}
void irq_domain_associate_many(struct irq_domain *domain, unsigned int irq_base,
irq_hw_number_t hwirq_base, int count)
{
int i;
pr_debug("%s(%s, irqbase=%i, hwbase=%i, count=%i)\n", __func__,
of_node_full_name(domain->of_node), irq_base, (int)hwirq_base, count);
for (i = 0; i < count; i++) {
irq_domain_associate(domain, irq_base + i, hwirq_base + i);
}
}
unsigned int irq_create_direct_mapping(struct irq_domain *domain)
{
unsigned int virq;
if (domain == NULL)
domain = irq_default_domain;
virq = irq_alloc_desc_from(1, of_node_to_nid(domain->of_node));
if (!virq) {
pr_debug("create_direct virq allocation failed\n");
return 0;
}
if (virq >= domain->revmap_direct_max_irq) {
pr_err("ERROR: no free irqs available below %i maximum\n",
domain->revmap_direct_max_irq);
irq_free_desc(virq);
return 0;
}
pr_debug("create_direct obtained virq %d\n", virq);
if (irq_domain_associate(domain, virq, virq)) {
irq_free_desc(virq);
return 0;
}
return virq;
}
unsigned int irq_create_mapping(struct irq_domain *domain,
irq_hw_number_t hwirq)
{
unsigned int hint;
int virq;
pr_debug("irq_create_mapping(0x%p, 0x%lx)\n", domain, hwirq);
if (domain == NULL)
domain = irq_default_domain;
if (domain == NULL) {
WARN(1, "%s(, %lx) called with NULL domain\n", __func__, hwirq);
return 0;
}
pr_debug("-> using domain @%p\n", domain);
virq = irq_find_mapping(domain, hwirq);
if (virq) {
pr_debug("-> existing mapping on virq %d\n", virq);
return virq;
}
hint = hwirq % nr_irqs;
if (hint == 0)
hint++;
virq = irq_alloc_desc_from(hint, of_node_to_nid(domain->of_node));
if (virq <= 0)
virq = irq_alloc_desc_from(1, of_node_to_nid(domain->of_node));
if (virq <= 0) {
pr_debug("-> virq allocation failed\n");
return 0;
}
if (irq_domain_associate(domain, virq, hwirq)) {
irq_free_desc(virq);
return 0;
}
pr_debug("irq %lu on domain %s mapped to virtual irq %u\n",
hwirq, of_node_full_name(domain->of_node), virq);
return virq;
}
int irq_create_strict_mappings(struct irq_domain *domain, unsigned int irq_base,
irq_hw_number_t hwirq_base, int count)
{
int ret;
ret = irq_alloc_descs(irq_base, irq_base, count,
of_node_to_nid(domain->of_node));
if (unlikely(ret < 0))
return ret;
irq_domain_associate_many(domain, irq_base, hwirq_base, count);
return 0;
}
unsigned int irq_create_of_mapping(struct of_phandle_args *irq_data)
{
struct irq_domain *domain;
irq_hw_number_t hwirq;
unsigned int type = IRQ_TYPE_NONE;
unsigned int virq;
domain = irq_data->np ? irq_find_host(irq_data->np) : irq_default_domain;
if (!domain) {
pr_warn("no irq domain found for %s !\n",
of_node_full_name(irq_data->np));
return 0;
}
if (domain->ops->xlate == NULL)
hwirq = irq_data->args[0];
else {
if (domain->ops->xlate(domain, irq_data->np, irq_data->args,
irq_data->args_count, &hwirq, &type))
return 0;
}
virq = irq_create_mapping(domain, hwirq);
if (!virq)
return virq;
if (type != IRQ_TYPE_NONE &&
type != irq_get_trigger_type(virq))
irq_set_irq_type(virq, type);
return virq;
}
void irq_dispose_mapping(unsigned int virq)
{
struct irq_data *irq_data = irq_get_irq_data(virq);
struct irq_domain *domain;
if (!virq || !irq_data)
return;
domain = irq_data->domain;
if (WARN_ON(domain == NULL))
return;
irq_domain_disassociate(domain, virq);
irq_free_desc(virq);
}
unsigned int irq_find_mapping(struct irq_domain *domain,
irq_hw_number_t hwirq)
{
struct irq_data *data;
if (domain == NULL)
domain = irq_default_domain;
if (domain == NULL)
return 0;
if (hwirq < domain->revmap_direct_max_irq) {
data = irq_get_irq_data(hwirq);
if (data && (data->domain == domain) && (data->hwirq == hwirq))
return hwirq;
}
if (hwirq < domain->revmap_size)
return domain->linear_revmap[hwirq];
rcu_read_lock();
data = radix_tree_lookup(&domain->revmap_tree, hwirq);
rcu_read_unlock();
return data ? data->irq : 0;
}
static int virq_debug_show(struct seq_file *m, void *private)
{
unsigned long flags;
struct irq_desc *desc;
struct irq_domain *domain;
struct radix_tree_iter iter;
void *data, **slot;
int i;
seq_printf(m, " %-16s %-6s %-10s %-10s %s\n",
"name", "mapped", "linear-max", "direct-max", "devtree-node");
mutex_lock(&irq_domain_mutex);
list_for_each_entry(domain, &irq_domain_list, link) {
int count = 0;
radix_tree_for_each_slot(slot, &domain->revmap_tree, &iter, 0)
count++;
seq_printf(m, "%c%-16s %6u %10u %10u %s\n",
domain == irq_default_domain ? '*' : ' ', domain->name,
domain->revmap_size + count, domain->revmap_size,
domain->revmap_direct_max_irq,
domain->of_node ? of_node_full_name(domain->of_node) : "");
}
mutex_unlock(&irq_domain_mutex);
seq_printf(m, "%-5s %-7s %-15s %-*s %6s %-14s %s\n", "irq", "hwirq",
"chip name", (int)(2 * sizeof(void *) + 2), "chip data",
"active", "type", "domain");
for (i = 1; i < nr_irqs; i++) {
desc = irq_to_desc(i);
if (!desc)
continue;
raw_spin_lock_irqsave(&desc->lock, flags);
domain = desc->irq_data.domain;
if (domain) {
struct irq_chip *chip;
int hwirq = desc->irq_data.hwirq;
bool direct;
seq_printf(m, "%5d ", i);
seq_printf(m, "0x%05x ", hwirq);
chip = irq_desc_get_chip(desc);
seq_printf(m, "%-15s ", (chip && chip->name) ? chip->name : "none");
data = irq_desc_get_chip_data(desc);
seq_printf(m, data ? "0x%p " : " %p ", data);
seq_printf(m, " %c ", (desc->action && desc->action->handler) ? '*' : ' ');
direct = (i == hwirq) && (i < domain->revmap_direct_max_irq);
seq_printf(m, "%6s%-8s ",
(hwirq < domain->revmap_size) ? "LINEAR" : "RADIX",
direct ? "(DIRECT)" : "");
seq_printf(m, "%s\n", desc->irq_data.domain->name);
}
raw_spin_unlock_irqrestore(&desc->lock, flags);
}
return 0;
}
static int virq_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, virq_debug_show, inode->i_private);
}
static int __init irq_debugfs_init(void)
{
if (debugfs_create_file("irq_domain_mapping", S_IRUGO, NULL,
NULL, &virq_debug_fops) == NULL)
return -ENOMEM;
return 0;
}
int irq_domain_xlate_onecell(struct irq_domain *d, struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq, unsigned int *out_type)
{
if (WARN_ON(intsize < 1))
return -EINVAL;
*out_hwirq = intspec[0];
*out_type = IRQ_TYPE_NONE;
return 0;
}
int irq_domain_xlate_twocell(struct irq_domain *d, struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_type)
{
if (WARN_ON(intsize < 2))
return -EINVAL;
*out_hwirq = intspec[0];
*out_type = intspec[1] & IRQ_TYPE_SENSE_MASK;
return 0;
}
int irq_domain_xlate_onetwocell(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq, unsigned int *out_type)
{
if (WARN_ON(intsize < 1))
return -EINVAL;
*out_hwirq = intspec[0];
*out_type = (intsize > 1) ? intspec[1] : IRQ_TYPE_NONE;
return 0;
}
