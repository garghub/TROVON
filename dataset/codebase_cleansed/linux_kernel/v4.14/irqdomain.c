static inline void debugfs_add_domain_dir(struct irq_domain *d) { }
static inline void debugfs_remove_domain_dir(struct irq_domain *d) { }
struct fwnode_handle *__irq_domain_alloc_fwnode(unsigned int type, int id,
const char *name, void *data)
{
struct irqchip_fwid *fwid;
char *n;
fwid = kzalloc(sizeof(*fwid), GFP_KERNEL);
switch (type) {
case IRQCHIP_FWNODE_NAMED:
n = kasprintf(GFP_KERNEL, "%s", name);
break;
case IRQCHIP_FWNODE_NAMED_ID:
n = kasprintf(GFP_KERNEL, "%s-%d", name, id);
break;
default:
n = kasprintf(GFP_KERNEL, "irqchip@%p", data);
break;
}
if (!fwid || !n) {
kfree(fwid);
kfree(n);
return NULL;
}
fwid->type = type;
fwid->name = n;
fwid->data = data;
fwid->fwnode.ops = &irqchip_fwnode_ops;
return &fwid->fwnode;
}
void irq_domain_free_fwnode(struct fwnode_handle *fwnode)
{
struct irqchip_fwid *fwid;
if (WARN_ON(!is_fwnode_irqchip(fwnode)))
return;
fwid = container_of(fwnode, struct irqchip_fwid, fwnode);
kfree(fwid->name);
kfree(fwid);
}
struct irq_domain *__irq_domain_add(struct fwnode_handle *fwnode, int size,
irq_hw_number_t hwirq_max, int direct_max,
const struct irq_domain_ops *ops,
void *host_data)
{
struct device_node *of_node = to_of_node(fwnode);
struct irqchip_fwid *fwid;
struct irq_domain *domain;
static atomic_t unknown_domains;
domain = kzalloc_node(sizeof(*domain) + (sizeof(unsigned int) * size),
GFP_KERNEL, of_node_to_nid(of_node));
if (WARN_ON(!domain))
return NULL;
if (fwnode && is_fwnode_irqchip(fwnode)) {
fwid = container_of(fwnode, struct irqchip_fwid, fwnode);
switch (fwid->type) {
case IRQCHIP_FWNODE_NAMED:
case IRQCHIP_FWNODE_NAMED_ID:
domain->name = kstrdup(fwid->name, GFP_KERNEL);
if (!domain->name) {
kfree(domain);
return NULL;
}
domain->flags |= IRQ_DOMAIN_NAME_ALLOCATED;
break;
default:
domain->fwnode = fwnode;
domain->name = fwid->name;
break;
}
#ifdef CONFIG_ACPI
} else if (is_acpi_device_node(fwnode)) {
struct acpi_buffer buf = {
.length = ACPI_ALLOCATE_BUFFER,
};
acpi_handle handle;
handle = acpi_device_handle(to_acpi_device_node(fwnode));
if (acpi_get_name(handle, ACPI_FULL_PATHNAME, &buf) == AE_OK) {
domain->name = buf.pointer;
domain->flags |= IRQ_DOMAIN_NAME_ALLOCATED;
}
domain->fwnode = fwnode;
#endif
} else if (of_node) {
char *name;
name = kstrdup(of_node_full_name(of_node), GFP_KERNEL);
if (!name) {
kfree(domain);
return NULL;
}
strreplace(name, '/', ':');
domain->name = name;
domain->fwnode = fwnode;
domain->flags |= IRQ_DOMAIN_NAME_ALLOCATED;
}
if (!domain->name) {
if (fwnode)
pr_err("Invalid fwnode type for irqdomain\n");
domain->name = kasprintf(GFP_KERNEL, "unknown-%d",
atomic_inc_return(&unknown_domains));
if (!domain->name) {
kfree(domain);
return NULL;
}
domain->flags |= IRQ_DOMAIN_NAME_ALLOCATED;
}
of_node_get(of_node);
INIT_RADIX_TREE(&domain->revmap_tree, GFP_KERNEL);
domain->ops = ops;
domain->host_data = host_data;
domain->hwirq_max = hwirq_max;
domain->revmap_size = size;
domain->revmap_direct_max_irq = direct_max;
irq_domain_check_hierarchy(domain);
mutex_lock(&irq_domain_mutex);
debugfs_add_domain_dir(domain);
list_add(&domain->link, &irq_domain_list);
mutex_unlock(&irq_domain_mutex);
pr_debug("Added domain %s\n", domain->name);
return domain;
}
void irq_domain_remove(struct irq_domain *domain)
{
mutex_lock(&irq_domain_mutex);
debugfs_remove_domain_dir(domain);
WARN_ON(!radix_tree_empty(&domain->revmap_tree));
list_del(&domain->link);
if (unlikely(irq_default_domain == domain))
irq_set_default_host(NULL);
mutex_unlock(&irq_domain_mutex);
pr_debug("Removed domain %s\n", domain->name);
of_node_put(irq_domain_get_of_node(domain));
if (domain->flags & IRQ_DOMAIN_NAME_ALLOCATED)
kfree(domain->name);
kfree(domain);
}
void irq_domain_update_bus_token(struct irq_domain *domain,
enum irq_domain_bus_token bus_token)
{
char *name;
if (domain->bus_token == bus_token)
return;
mutex_lock(&irq_domain_mutex);
domain->bus_token = bus_token;
name = kasprintf(GFP_KERNEL, "%s-%d", domain->name, bus_token);
if (!name) {
mutex_unlock(&irq_domain_mutex);
return;
}
debugfs_remove_domain_dir(domain);
if (domain->flags & IRQ_DOMAIN_NAME_ALLOCATED)
kfree(domain->name);
else
domain->flags |= IRQ_DOMAIN_NAME_ALLOCATED;
domain->name = name;
debugfs_add_domain_dir(domain);
mutex_unlock(&irq_domain_mutex);
}
struct irq_domain *irq_domain_add_simple(struct device_node *of_node,
unsigned int size,
unsigned int first_irq,
const struct irq_domain_ops *ops,
void *host_data)
{
struct irq_domain *domain;
domain = __irq_domain_add(of_node_to_fwnode(of_node), size, size, 0, ops, host_data);
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
domain = __irq_domain_add(of_node_to_fwnode(of_node), first_hwirq + size,
first_hwirq + size, 0, ops, host_data);
if (domain)
irq_domain_associate_many(domain, first_irq, first_hwirq, size);
return domain;
}
struct irq_domain *irq_find_matching_fwspec(struct irq_fwspec *fwspec,
enum irq_domain_bus_token bus_token)
{
struct irq_domain *h, *found = NULL;
struct fwnode_handle *fwnode = fwspec->fwnode;
int rc;
mutex_lock(&irq_domain_mutex);
list_for_each_entry(h, &irq_domain_list, link) {
if (h->ops->select && fwspec->param_count)
rc = h->ops->select(h, fwspec, bus_token);
else if (h->ops->match)
rc = h->ops->match(h, to_of_node(fwnode), bus_token);
else
rc = ((fwnode != NULL) && (h->fwnode == fwnode) &&
((bus_token == DOMAIN_BUS_ANY) ||
(h->bus_token == bus_token)));
if (rc) {
found = h;
break;
}
}
mutex_unlock(&irq_domain_mutex);
return found;
}
bool irq_domain_check_msi_remap(void)
{
struct irq_domain *h;
bool ret = true;
mutex_lock(&irq_domain_mutex);
list_for_each_entry(h, &irq_domain_list, link) {
if (irq_domain_is_msi(h) &&
!irq_domain_hierarchical_is_msi_remap(h)) {
ret = false;
break;
}
}
mutex_unlock(&irq_domain_mutex);
return ret;
}
void irq_set_default_host(struct irq_domain *domain)
{
pr_debug("Default domain set to @0x%p\n", domain);
irq_default_domain = domain;
}
static void irq_domain_clear_mapping(struct irq_domain *domain,
irq_hw_number_t hwirq)
{
if (hwirq < domain->revmap_size) {
domain->linear_revmap[hwirq] = 0;
} else {
mutex_lock(&revmap_trees_mutex);
radix_tree_delete(&domain->revmap_tree, hwirq);
mutex_unlock(&revmap_trees_mutex);
}
}
static void irq_domain_set_mapping(struct irq_domain *domain,
irq_hw_number_t hwirq,
struct irq_data *irq_data)
{
if (hwirq < domain->revmap_size) {
domain->linear_revmap[hwirq] = irq_data->irq;
} else {
mutex_lock(&revmap_trees_mutex);
radix_tree_insert(&domain->revmap_tree, hwirq, irq_data);
mutex_unlock(&revmap_trees_mutex);
}
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
domain->mapcount--;
irq_domain_clear_mapping(domain, hwirq);
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
domain->mapcount++;
irq_domain_set_mapping(domain, hwirq, irq_data);
mutex_unlock(&irq_domain_mutex);
irq_clear_status_flags(virq, IRQ_NOREQUEST);
return 0;
}
void irq_domain_associate_many(struct irq_domain *domain, unsigned int irq_base,
irq_hw_number_t hwirq_base, int count)
{
struct device_node *of_node;
int i;
of_node = irq_domain_get_of_node(domain);
pr_debug("%s(%s, irqbase=%i, hwbase=%i, count=%i)\n", __func__,
of_node_full_name(of_node), irq_base, (int)hwirq_base, count);
for (i = 0; i < count; i++) {
irq_domain_associate(domain, irq_base + i, hwirq_base + i);
}
}
unsigned int irq_create_direct_mapping(struct irq_domain *domain)
{
struct device_node *of_node;
unsigned int virq;
if (domain == NULL)
domain = irq_default_domain;
of_node = irq_domain_get_of_node(domain);
virq = irq_alloc_desc_from(1, of_node_to_nid(of_node));
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
struct device_node *of_node;
int virq;
pr_debug("irq_create_mapping(0x%p, 0x%lx)\n", domain, hwirq);
if (domain == NULL)
domain = irq_default_domain;
if (domain == NULL) {
WARN(1, "%s(, %lx) called with NULL domain\n", __func__, hwirq);
return 0;
}
pr_debug("-> using domain @%p\n", domain);
of_node = irq_domain_get_of_node(domain);
virq = irq_find_mapping(domain, hwirq);
if (virq) {
pr_debug("-> existing mapping on virq %d\n", virq);
return virq;
}
virq = irq_domain_alloc_descs(-1, 1, hwirq, of_node_to_nid(of_node), NULL);
if (virq <= 0) {
pr_debug("-> virq allocation failed\n");
return 0;
}
if (irq_domain_associate(domain, virq, hwirq)) {
irq_free_desc(virq);
return 0;
}
pr_debug("irq %lu on domain %s mapped to virtual irq %u\n",
hwirq, of_node_full_name(of_node), virq);
return virq;
}
int irq_create_strict_mappings(struct irq_domain *domain, unsigned int irq_base,
irq_hw_number_t hwirq_base, int count)
{
struct device_node *of_node;
int ret;
of_node = irq_domain_get_of_node(domain);
ret = irq_alloc_descs(irq_base, irq_base, count,
of_node_to_nid(of_node));
if (unlikely(ret < 0))
return ret;
irq_domain_associate_many(domain, irq_base, hwirq_base, count);
return 0;
}
static int irq_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
irq_hw_number_t *hwirq, unsigned int *type)
{
#ifdef CONFIG_IRQ_DOMAIN_HIERARCHY
if (d->ops->translate)
return d->ops->translate(d, fwspec, hwirq, type);
#endif
if (d->ops->xlate)
return d->ops->xlate(d, to_of_node(fwspec->fwnode),
fwspec->param, fwspec->param_count,
hwirq, type);
*hwirq = fwspec->param[0];
return 0;
}
static void of_phandle_args_to_fwspec(struct of_phandle_args *irq_data,
struct irq_fwspec *fwspec)
{
int i;
fwspec->fwnode = irq_data->np ? &irq_data->np->fwnode : NULL;
fwspec->param_count = irq_data->args_count;
for (i = 0; i < irq_data->args_count; i++)
fwspec->param[i] = irq_data->args[i];
}
unsigned int irq_create_fwspec_mapping(struct irq_fwspec *fwspec)
{
struct irq_domain *domain;
struct irq_data *irq_data;
irq_hw_number_t hwirq;
unsigned int type = IRQ_TYPE_NONE;
int virq;
if (fwspec->fwnode) {
domain = irq_find_matching_fwspec(fwspec, DOMAIN_BUS_WIRED);
if (!domain)
domain = irq_find_matching_fwspec(fwspec, DOMAIN_BUS_ANY);
} else {
domain = irq_default_domain;
}
if (!domain) {
pr_warn("no irq domain found for %s !\n",
of_node_full_name(to_of_node(fwspec->fwnode)));
return 0;
}
if (irq_domain_translate(domain, fwspec, &hwirq, &type))
return 0;
if (WARN_ON(type & ~IRQ_TYPE_SENSE_MASK))
type &= IRQ_TYPE_SENSE_MASK;
virq = irq_find_mapping(domain, hwirq);
if (virq) {
if (type == IRQ_TYPE_NONE || type == irq_get_trigger_type(virq))
return virq;
if (irq_get_trigger_type(virq) == IRQ_TYPE_NONE) {
irq_data = irq_get_irq_data(virq);
if (!irq_data)
return 0;
irqd_set_trigger_type(irq_data, type);
return virq;
}
pr_warn("type mismatch, failed to map hwirq-%lu for %s!\n",
hwirq, of_node_full_name(to_of_node(fwspec->fwnode)));
return 0;
}
if (irq_domain_is_hierarchy(domain)) {
virq = irq_domain_alloc_irqs(domain, 1, NUMA_NO_NODE, fwspec);
if (virq <= 0)
return 0;
} else {
virq = irq_create_mapping(domain, hwirq);
if (!virq)
return virq;
}
irq_data = irq_get_irq_data(virq);
if (!irq_data) {
if (irq_domain_is_hierarchy(domain))
irq_domain_free_irqs(virq, 1);
else
irq_dispose_mapping(virq);
return 0;
}
irqd_set_trigger_type(irq_data, type);
return virq;
}
unsigned int irq_create_of_mapping(struct of_phandle_args *irq_data)
{
struct irq_fwspec fwspec;
of_phandle_args_to_fwspec(irq_data, &fwspec);
return irq_create_fwspec_mapping(&fwspec);
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
if (irq_domain_is_hierarchy(domain)) {
irq_domain_free_irqs(virq, 1);
} else {
irq_domain_disassociate(domain, virq);
irq_free_desc(virq);
}
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
data = irq_domain_get_irq_data(domain, hwirq);
if (data && data->hwirq == hwirq)
return hwirq;
}
if (hwirq < domain->revmap_size)
return domain->linear_revmap[hwirq];
rcu_read_lock();
data = radix_tree_lookup(&domain->revmap_tree, hwirq);
rcu_read_unlock();
return data ? data->irq : 0;
}
static void virq_debug_show_one(struct seq_file *m, struct irq_desc *desc)
{
struct irq_domain *domain;
struct irq_data *data;
domain = desc->irq_data.domain;
data = &desc->irq_data;
while (domain) {
unsigned int irq = data->irq;
unsigned long hwirq = data->hwirq;
struct irq_chip *chip;
bool direct;
if (data == &desc->irq_data)
seq_printf(m, "%5d ", irq);
else
seq_printf(m, "%5d+ ", irq);
seq_printf(m, "0x%05lx ", hwirq);
chip = irq_data_get_irq_chip(data);
seq_printf(m, "%-15s ", (chip && chip->name) ? chip->name : "none");
seq_printf(m, data ? "0x%p " : " %p ",
irq_data_get_irq_chip_data(data));
seq_printf(m, " %c ", (desc->action && desc->action->handler) ? '*' : ' ');
direct = (irq == hwirq) && (irq < domain->revmap_direct_max_irq);
seq_printf(m, "%6s%-8s ",
(hwirq < domain->revmap_size) ? "LINEAR" : "RADIX",
direct ? "(DIRECT)" : "");
seq_printf(m, "%s\n", domain->name);
#ifdef CONFIG_IRQ_DOMAIN_HIERARCHY
domain = domain->parent;
data = data->parent_data;
#else
domain = NULL;
#endif
}
}
static int virq_debug_show(struct seq_file *m, void *private)
{
unsigned long flags;
struct irq_desc *desc;
struct irq_domain *domain;
struct radix_tree_iter iter;
void __rcu **slot;
int i;
seq_printf(m, " %-16s %-6s %-10s %-10s %s\n",
"name", "mapped", "linear-max", "direct-max", "devtree-node");
mutex_lock(&irq_domain_mutex);
list_for_each_entry(domain, &irq_domain_list, link) {
struct device_node *of_node;
const char *name;
int count = 0;
of_node = irq_domain_get_of_node(domain);
if (of_node)
name = of_node_full_name(of_node);
else if (is_fwnode_irqchip(domain->fwnode))
name = container_of(domain->fwnode, struct irqchip_fwid,
fwnode)->name;
else
name = "";
radix_tree_for_each_slot(slot, &domain->revmap_tree, &iter, 0)
count++;
seq_printf(m, "%c%-16s %6u %10u %10u %s\n",
domain == irq_default_domain ? '*' : ' ', domain->name,
domain->revmap_size + count, domain->revmap_size,
domain->revmap_direct_max_irq,
name);
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
virq_debug_show_one(m, desc);
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
if (intsize > 1)
*out_type = intspec[1] & IRQ_TYPE_SENSE_MASK;
else
*out_type = IRQ_TYPE_NONE;
return 0;
}
int irq_domain_alloc_descs(int virq, unsigned int cnt, irq_hw_number_t hwirq,
int node, const struct cpumask *affinity)
{
unsigned int hint;
if (virq >= 0) {
virq = __irq_alloc_descs(virq, virq, cnt, node, THIS_MODULE,
affinity);
} else {
hint = hwirq % nr_irqs;
if (hint == 0)
hint++;
virq = __irq_alloc_descs(-1, hint, cnt, node, THIS_MODULE,
affinity);
if (virq <= 0 && hint > 1) {
virq = __irq_alloc_descs(-1, 1, cnt, node, THIS_MODULE,
affinity);
}
}
return virq;
}
struct irq_domain *irq_domain_create_hierarchy(struct irq_domain *parent,
unsigned int flags,
unsigned int size,
struct fwnode_handle *fwnode,
const struct irq_domain_ops *ops,
void *host_data)
{
struct irq_domain *domain;
if (size)
domain = irq_domain_create_linear(fwnode, size, ops, host_data);
else
domain = irq_domain_create_tree(fwnode, ops, host_data);
if (domain) {
domain->parent = parent;
domain->flags |= flags;
}
return domain;
}
static void irq_domain_insert_irq(int virq)
{
struct irq_data *data;
for (data = irq_get_irq_data(virq); data; data = data->parent_data) {
struct irq_domain *domain = data->domain;
domain->mapcount++;
irq_domain_set_mapping(domain, data->hwirq, data);
if (!domain->name && data->chip)
domain->name = data->chip->name;
}
irq_clear_status_flags(virq, IRQ_NOREQUEST);
}
static void irq_domain_remove_irq(int virq)
{
struct irq_data *data;
irq_set_status_flags(virq, IRQ_NOREQUEST);
irq_set_chip_and_handler(virq, NULL, NULL);
synchronize_irq(virq);
smp_mb();
for (data = irq_get_irq_data(virq); data; data = data->parent_data) {
struct irq_domain *domain = data->domain;
irq_hw_number_t hwirq = data->hwirq;
domain->mapcount--;
irq_domain_clear_mapping(domain, hwirq);
}
}
static struct irq_data *irq_domain_insert_irq_data(struct irq_domain *domain,
struct irq_data *child)
{
struct irq_data *irq_data;
irq_data = kzalloc_node(sizeof(*irq_data), GFP_KERNEL,
irq_data_get_node(child));
if (irq_data) {
child->parent_data = irq_data;
irq_data->irq = child->irq;
irq_data->common = child->common;
irq_data->domain = domain;
}
return irq_data;
}
static void irq_domain_free_irq_data(unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *irq_data, *tmp;
int i;
for (i = 0; i < nr_irqs; i++) {
irq_data = irq_get_irq_data(virq + i);
tmp = irq_data->parent_data;
irq_data->parent_data = NULL;
irq_data->domain = NULL;
while (tmp) {
irq_data = tmp;
tmp = tmp->parent_data;
kfree(irq_data);
}
}
}
static int irq_domain_alloc_irq_data(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *irq_data;
struct irq_domain *parent;
int i;
for (i = 0; i < nr_irqs; i++) {
irq_data = irq_get_irq_data(virq + i);
irq_data->domain = domain;
for (parent = domain->parent; parent; parent = parent->parent) {
irq_data = irq_domain_insert_irq_data(parent, irq_data);
if (!irq_data) {
irq_domain_free_irq_data(virq, i + 1);
return -ENOMEM;
}
}
}
return 0;
}
struct irq_data *irq_domain_get_irq_data(struct irq_domain *domain,
unsigned int virq)
{
struct irq_data *irq_data;
for (irq_data = irq_get_irq_data(virq); irq_data;
irq_data = irq_data->parent_data)
if (irq_data->domain == domain)
return irq_data;
return NULL;
}
int irq_domain_set_hwirq_and_chip(struct irq_domain *domain, unsigned int virq,
irq_hw_number_t hwirq, struct irq_chip *chip,
void *chip_data)
{
struct irq_data *irq_data = irq_domain_get_irq_data(domain, virq);
if (!irq_data)
return -ENOENT;
irq_data->hwirq = hwirq;
irq_data->chip = chip ? chip : &no_irq_chip;
irq_data->chip_data = chip_data;
return 0;
}
void irq_domain_set_info(struct irq_domain *domain, unsigned int virq,
irq_hw_number_t hwirq, struct irq_chip *chip,
void *chip_data, irq_flow_handler_t handler,
void *handler_data, const char *handler_name)
{
irq_domain_set_hwirq_and_chip(domain, virq, hwirq, chip, chip_data);
__irq_set_handler(virq, handler, 0, handler_name);
irq_set_handler_data(virq, handler_data);
}
void irq_domain_reset_irq_data(struct irq_data *irq_data)
{
irq_data->hwirq = 0;
irq_data->chip = &no_irq_chip;
irq_data->chip_data = NULL;
}
void irq_domain_free_irqs_common(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *irq_data;
int i;
for (i = 0; i < nr_irqs; i++) {
irq_data = irq_domain_get_irq_data(domain, virq + i);
if (irq_data)
irq_domain_reset_irq_data(irq_data);
}
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}
void irq_domain_free_irqs_top(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
int i;
for (i = 0; i < nr_irqs; i++) {
irq_set_handler_data(virq + i, NULL);
irq_set_handler(virq + i, NULL);
}
irq_domain_free_irqs_common(domain, virq, nr_irqs);
}
static void irq_domain_free_irqs_hierarchy(struct irq_domain *domain,
unsigned int irq_base,
unsigned int nr_irqs)
{
if (domain->ops->free)
domain->ops->free(domain, irq_base, nr_irqs);
}
int irq_domain_alloc_irqs_hierarchy(struct irq_domain *domain,
unsigned int irq_base,
unsigned int nr_irqs, void *arg)
{
return domain->ops->alloc(domain, irq_base, nr_irqs, arg);
}
int __irq_domain_alloc_irqs(struct irq_domain *domain, int irq_base,
unsigned int nr_irqs, int node, void *arg,
bool realloc, const struct cpumask *affinity)
{
int i, ret, virq;
if (domain == NULL) {
domain = irq_default_domain;
if (WARN(!domain, "domain is NULL; cannot allocate IRQ\n"))
return -EINVAL;
}
if (!domain->ops->alloc) {
pr_debug("domain->ops->alloc() is NULL\n");
return -ENOSYS;
}
if (realloc && irq_base >= 0) {
virq = irq_base;
} else {
virq = irq_domain_alloc_descs(irq_base, nr_irqs, 0, node,
affinity);
if (virq < 0) {
pr_debug("cannot allocate IRQ(base %d, count %d)\n",
irq_base, nr_irqs);
return virq;
}
}
if (irq_domain_alloc_irq_data(domain, virq, nr_irqs)) {
pr_debug("cannot allocate memory for IRQ%d\n", virq);
ret = -ENOMEM;
goto out_free_desc;
}
mutex_lock(&irq_domain_mutex);
ret = irq_domain_alloc_irqs_hierarchy(domain, virq, nr_irqs, arg);
if (ret < 0) {
mutex_unlock(&irq_domain_mutex);
goto out_free_irq_data;
}
for (i = 0; i < nr_irqs; i++)
irq_domain_insert_irq(virq + i);
mutex_unlock(&irq_domain_mutex);
return virq;
out_free_irq_data:
irq_domain_free_irq_data(virq, nr_irqs);
out_free_desc:
irq_free_descs(virq, nr_irqs);
return ret;
}
static void irq_domain_fix_revmap(struct irq_data *d)
{
void __rcu **slot;
if (d->hwirq < d->domain->revmap_size)
return;
mutex_lock(&revmap_trees_mutex);
slot = radix_tree_lookup_slot(&d->domain->revmap_tree, d->hwirq);
if (slot)
radix_tree_replace_slot(&d->domain->revmap_tree, slot, d);
mutex_unlock(&revmap_trees_mutex);
}
int irq_domain_push_irq(struct irq_domain *domain, int virq, void *arg)
{
struct irq_data *child_irq_data;
struct irq_data *root_irq_data = irq_get_irq_data(virq);
struct irq_desc *desc;
int rv = 0;
desc = irq_to_desc(virq);
if (!desc)
return -EINVAL;
if (WARN_ON(desc->action))
return -EBUSY;
if (domain == NULL)
return -EINVAL;
if (WARN_ON(!irq_domain_is_hierarchy(domain)))
return -EINVAL;
if (!root_irq_data)
return -EINVAL;
if (domain->parent != root_irq_data->domain)
return -EINVAL;
child_irq_data = kzalloc_node(sizeof(*child_irq_data), GFP_KERNEL,
irq_data_get_node(root_irq_data));
if (!child_irq_data)
return -ENOMEM;
mutex_lock(&irq_domain_mutex);
*child_irq_data = *root_irq_data;
root_irq_data->parent_data = child_irq_data;
root_irq_data->domain = domain;
root_irq_data->mask = 0;
root_irq_data->hwirq = 0;
root_irq_data->chip = NULL;
root_irq_data->chip_data = NULL;
rv = irq_domain_alloc_irqs_hierarchy(domain, virq, 1, arg);
if (rv) {
*root_irq_data = *child_irq_data;
goto error;
}
irq_domain_fix_revmap(child_irq_data);
irq_domain_set_mapping(domain, root_irq_data->hwirq, root_irq_data);
error:
mutex_unlock(&irq_domain_mutex);
return rv;
}
int irq_domain_pop_irq(struct irq_domain *domain, int virq)
{
struct irq_data *root_irq_data = irq_get_irq_data(virq);
struct irq_data *child_irq_data;
struct irq_data *tmp_irq_data;
struct irq_desc *desc;
desc = irq_to_desc(virq);
if (!desc)
return -EINVAL;
if (WARN_ON(desc->action))
return -EBUSY;
if (domain == NULL)
return -EINVAL;
if (!root_irq_data)
return -EINVAL;
tmp_irq_data = irq_domain_get_irq_data(domain, virq);
if (WARN_ON(root_irq_data != tmp_irq_data))
return -EINVAL;
if (WARN_ON(root_irq_data->domain != domain))
return -EINVAL;
child_irq_data = root_irq_data->parent_data;
if (WARN_ON(!child_irq_data))
return -EINVAL;
mutex_lock(&irq_domain_mutex);
root_irq_data->parent_data = NULL;
irq_domain_clear_mapping(domain, root_irq_data->hwirq);
irq_domain_free_irqs_hierarchy(domain, virq, 1);
*root_irq_data = *child_irq_data;
irq_domain_fix_revmap(root_irq_data);
mutex_unlock(&irq_domain_mutex);
kfree(child_irq_data);
return 0;
}
void irq_domain_free_irqs(unsigned int virq, unsigned int nr_irqs)
{
struct irq_data *data = irq_get_irq_data(virq);
int i;
if (WARN(!data || !data->domain || !data->domain->ops->free,
"NULL pointer, cannot free irq\n"))
return;
mutex_lock(&irq_domain_mutex);
for (i = 0; i < nr_irqs; i++)
irq_domain_remove_irq(virq + i);
irq_domain_free_irqs_hierarchy(data->domain, virq, nr_irqs);
mutex_unlock(&irq_domain_mutex);
irq_domain_free_irq_data(virq, nr_irqs);
irq_free_descs(virq, nr_irqs);
}
int irq_domain_alloc_irqs_parent(struct irq_domain *domain,
unsigned int irq_base, unsigned int nr_irqs,
void *arg)
{
if (!domain->parent)
return -ENOSYS;
return irq_domain_alloc_irqs_hierarchy(domain->parent, irq_base,
nr_irqs, arg);
}
void irq_domain_free_irqs_parent(struct irq_domain *domain,
unsigned int irq_base, unsigned int nr_irqs)
{
if (!domain->parent)
return;
irq_domain_free_irqs_hierarchy(domain->parent, irq_base, nr_irqs);
}
static void __irq_domain_activate_irq(struct irq_data *irq_data)
{
if (irq_data && irq_data->domain) {
struct irq_domain *domain = irq_data->domain;
if (irq_data->parent_data)
__irq_domain_activate_irq(irq_data->parent_data);
if (domain->ops->activate)
domain->ops->activate(domain, irq_data);
}
}
static void __irq_domain_deactivate_irq(struct irq_data *irq_data)
{
if (irq_data && irq_data->domain) {
struct irq_domain *domain = irq_data->domain;
if (domain->ops->deactivate)
domain->ops->deactivate(domain, irq_data);
if (irq_data->parent_data)
__irq_domain_deactivate_irq(irq_data->parent_data);
}
}
void irq_domain_activate_irq(struct irq_data *irq_data)
{
if (!irqd_is_activated(irq_data)) {
__irq_domain_activate_irq(irq_data);
irqd_set_activated(irq_data);
}
}
void irq_domain_deactivate_irq(struct irq_data *irq_data)
{
if (irqd_is_activated(irq_data)) {
__irq_domain_deactivate_irq(irq_data);
irqd_clr_activated(irq_data);
}
}
static void irq_domain_check_hierarchy(struct irq_domain *domain)
{
if (domain->ops->alloc)
domain->flags |= IRQ_DOMAIN_FLAG_HIERARCHY;
}
bool irq_domain_hierarchical_is_msi_remap(struct irq_domain *domain)
{
for (; domain; domain = domain->parent) {
if (irq_domain_is_msi_remap(domain))
return true;
}
return false;
}
struct irq_data *irq_domain_get_irq_data(struct irq_domain *domain,
unsigned int virq)
{
struct irq_data *irq_data = irq_get_irq_data(virq);
return (irq_data && irq_data->domain == domain) ? irq_data : NULL;
}
void irq_domain_set_info(struct irq_domain *domain, unsigned int virq,
irq_hw_number_t hwirq, struct irq_chip *chip,
void *chip_data, irq_flow_handler_t handler,
void *handler_data, const char *handler_name)
{
irq_set_chip_and_handler_name(virq, chip, handler, handler_name);
irq_set_chip_data(virq, chip_data);
irq_set_handler_data(virq, handler_data);
}
static void irq_domain_check_hierarchy(struct irq_domain *domain)
{
}
static void
irq_domain_debug_show_one(struct seq_file *m, struct irq_domain *d, int ind)
{
seq_printf(m, "%*sname: %s\n", ind, "", d->name);
seq_printf(m, "%*ssize: %u\n", ind + 1, "",
d->revmap_size + d->revmap_direct_max_irq);
seq_printf(m, "%*smapped: %u\n", ind + 1, "", d->mapcount);
seq_printf(m, "%*sflags: 0x%08x\n", ind +1 , "", d->flags);
#ifdef CONFIG_IRQ_DOMAIN_HIERARCHY
if (!d->parent)
return;
seq_printf(m, "%*sparent: %s\n", ind + 1, "", d->parent->name);
irq_domain_debug_show_one(m, d->parent, ind + 4);
#endif
}
static int irq_domain_debug_show(struct seq_file *m, void *p)
{
struct irq_domain *d = m->private;
if (!d) {
if (!irq_default_domain)
return 0;
d = irq_default_domain;
}
irq_domain_debug_show_one(m, d, 0);
return 0;
}
static int irq_domain_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, irq_domain_debug_show, inode->i_private);
}
static void debugfs_add_domain_dir(struct irq_domain *d)
{
if (!d->name || !domain_dir || d->debugfs_file)
return;
d->debugfs_file = debugfs_create_file(d->name, 0444, domain_dir, d,
&dfs_domain_ops);
}
static void debugfs_remove_domain_dir(struct irq_domain *d)
{
debugfs_remove(d->debugfs_file);
}
void __init irq_domain_debugfs_init(struct dentry *root)
{
struct irq_domain *d;
domain_dir = debugfs_create_dir("domains", root);
if (!domain_dir)
return;
debugfs_create_file("default", 0444, domain_dir, NULL, &dfs_domain_ops);
mutex_lock(&irq_domain_mutex);
list_for_each_entry(d, &irq_domain_list, link)
debugfs_add_domain_dir(d);
mutex_unlock(&irq_domain_mutex);
}
