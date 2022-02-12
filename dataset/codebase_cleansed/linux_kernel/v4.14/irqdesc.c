static int __init irq_affinity_setup(char *str)
{
zalloc_cpumask_var(&irq_default_affinity, GFP_NOWAIT);
cpulist_parse(str, irq_default_affinity);
cpumask_set_cpu(smp_processor_id(), irq_default_affinity);
return 1;
}
static void __init init_irq_default_affinity(void)
{
#ifdef CONFIG_CPUMASK_OFFSTACK
if (!irq_default_affinity)
zalloc_cpumask_var(&irq_default_affinity, GFP_NOWAIT);
#endif
if (cpumask_empty(irq_default_affinity))
cpumask_setall(irq_default_affinity);
}
static void __init init_irq_default_affinity(void)
{
}
static int alloc_masks(struct irq_desc *desc, int node)
{
if (!zalloc_cpumask_var_node(&desc->irq_common_data.affinity,
GFP_KERNEL, node))
return -ENOMEM;
#ifdef CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK
if (!zalloc_cpumask_var_node(&desc->irq_common_data.effective_affinity,
GFP_KERNEL, node)) {
free_cpumask_var(desc->irq_common_data.affinity);
return -ENOMEM;
}
#endif
#ifdef CONFIG_GENERIC_PENDING_IRQ
if (!zalloc_cpumask_var_node(&desc->pending_mask, GFP_KERNEL, node)) {
#ifdef CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK
free_cpumask_var(desc->irq_common_data.effective_affinity);
#endif
free_cpumask_var(desc->irq_common_data.affinity);
return -ENOMEM;
}
#endif
return 0;
}
static void desc_smp_init(struct irq_desc *desc, int node,
const struct cpumask *affinity)
{
if (!affinity)
affinity = irq_default_affinity;
cpumask_copy(desc->irq_common_data.affinity, affinity);
#ifdef CONFIG_GENERIC_PENDING_IRQ
cpumask_clear(desc->pending_mask);
#endif
#ifdef CONFIG_NUMA
desc->irq_common_data.node = node;
#endif
}
static inline int
alloc_masks(struct irq_desc *desc, int node) { return 0; }
static inline void
desc_smp_init(struct irq_desc *desc, int node, const struct cpumask *affinity) { }
static void desc_set_defaults(unsigned int irq, struct irq_desc *desc, int node,
const struct cpumask *affinity, struct module *owner)
{
int cpu;
desc->irq_common_data.handler_data = NULL;
desc->irq_common_data.msi_desc = NULL;
desc->irq_data.common = &desc->irq_common_data;
desc->irq_data.irq = irq;
desc->irq_data.chip = &no_irq_chip;
desc->irq_data.chip_data = NULL;
irq_settings_clr_and_set(desc, ~0, _IRQ_DEFAULT_INIT_FLAGS);
irqd_set(&desc->irq_data, IRQD_IRQ_DISABLED);
irqd_set(&desc->irq_data, IRQD_IRQ_MASKED);
desc->handle_irq = handle_bad_irq;
desc->depth = 1;
desc->irq_count = 0;
desc->irqs_unhandled = 0;
desc->name = NULL;
desc->owner = owner;
for_each_possible_cpu(cpu)
*per_cpu_ptr(desc->kstat_irqs, cpu) = 0;
desc_smp_init(desc, node, affinity);
}
static ssize_t per_cpu_count_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
int cpu, irq = desc->irq_data.irq;
ssize_t ret = 0;
char *p = "";
for_each_possible_cpu(cpu) {
unsigned int c = kstat_irqs_cpu(irq, cpu);
ret += scnprintf(buf + ret, PAGE_SIZE - ret, "%s%u", p, c);
p = ",";
}
ret += scnprintf(buf + ret, PAGE_SIZE - ret, "\n");
return ret;
}
static ssize_t chip_name_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
ssize_t ret = 0;
raw_spin_lock_irq(&desc->lock);
if (desc->irq_data.chip && desc->irq_data.chip->name) {
ret = scnprintf(buf, PAGE_SIZE, "%s\n",
desc->irq_data.chip->name);
}
raw_spin_unlock_irq(&desc->lock);
return ret;
}
static ssize_t hwirq_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
ssize_t ret = 0;
raw_spin_lock_irq(&desc->lock);
if (desc->irq_data.domain)
ret = sprintf(buf, "%d\n", (int)desc->irq_data.hwirq);
raw_spin_unlock_irq(&desc->lock);
return ret;
}
static ssize_t type_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
ssize_t ret = 0;
raw_spin_lock_irq(&desc->lock);
ret = sprintf(buf, "%s\n",
irqd_is_level_type(&desc->irq_data) ? "level" : "edge");
raw_spin_unlock_irq(&desc->lock);
return ret;
}
static ssize_t name_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
ssize_t ret = 0;
raw_spin_lock_irq(&desc->lock);
if (desc->name)
ret = scnprintf(buf, PAGE_SIZE, "%s\n", desc->name);
raw_spin_unlock_irq(&desc->lock);
return ret;
}
static ssize_t actions_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
struct irqaction *action;
ssize_t ret = 0;
char *p = "";
raw_spin_lock_irq(&desc->lock);
for (action = desc->action; action != NULL; action = action->next) {
ret += scnprintf(buf + ret, PAGE_SIZE - ret, "%s%s",
p, action->name);
p = ",";
}
raw_spin_unlock_irq(&desc->lock);
if (ret)
ret += scnprintf(buf + ret, PAGE_SIZE - ret, "\n");
return ret;
}
static void irq_sysfs_add(int irq, struct irq_desc *desc)
{
if (irq_kobj_base) {
if (kobject_add(&desc->kobj, irq_kobj_base, "%d", irq))
pr_warn("Failed to add kobject for irq %d\n", irq);
}
}
static int __init irq_sysfs_init(void)
{
struct irq_desc *desc;
int irq;
irq_lock_sparse();
irq_kobj_base = kobject_create_and_add("irq", kernel_kobj);
if (!irq_kobj_base) {
irq_unlock_sparse();
return -ENOMEM;
}
for_each_irq_desc(irq, desc)
irq_sysfs_add(irq, desc);
irq_unlock_sparse();
return 0;
}
static void irq_sysfs_add(int irq, struct irq_desc *desc) {}
static void irq_insert_desc(unsigned int irq, struct irq_desc *desc)
{
radix_tree_insert(&irq_desc_tree, irq, desc);
}
struct irq_desc *irq_to_desc(unsigned int irq)
{
return radix_tree_lookup(&irq_desc_tree, irq);
}
static void delete_irq_desc(unsigned int irq)
{
radix_tree_delete(&irq_desc_tree, irq);
}
static void free_masks(struct irq_desc *desc)
{
#ifdef CONFIG_GENERIC_PENDING_IRQ
free_cpumask_var(desc->pending_mask);
#endif
free_cpumask_var(desc->irq_common_data.affinity);
#ifdef CONFIG_GENERIC_IRQ_EFFECTIVE_AFF_MASK
free_cpumask_var(desc->irq_common_data.effective_affinity);
#endif
}
static inline void free_masks(struct irq_desc *desc) { }
void irq_lock_sparse(void)
{
mutex_lock(&sparse_irq_lock);
}
void irq_unlock_sparse(void)
{
mutex_unlock(&sparse_irq_lock);
}
static struct irq_desc *alloc_desc(int irq, int node, unsigned int flags,
const struct cpumask *affinity,
struct module *owner)
{
struct irq_desc *desc;
desc = kzalloc_node(sizeof(*desc), GFP_KERNEL, node);
if (!desc)
return NULL;
desc->kstat_irqs = alloc_percpu(unsigned int);
if (!desc->kstat_irqs)
goto err_desc;
if (alloc_masks(desc, node))
goto err_kstat;
raw_spin_lock_init(&desc->lock);
lockdep_set_class(&desc->lock, &irq_desc_lock_class);
mutex_init(&desc->request_mutex);
init_rcu_head(&desc->rcu);
desc_set_defaults(irq, desc, node, affinity, owner);
irqd_set(&desc->irq_data, flags);
kobject_init(&desc->kobj, &irq_kobj_type);
return desc;
err_kstat:
free_percpu(desc->kstat_irqs);
err_desc:
kfree(desc);
return NULL;
}
static void irq_kobj_release(struct kobject *kobj)
{
struct irq_desc *desc = container_of(kobj, struct irq_desc, kobj);
free_masks(desc);
free_percpu(desc->kstat_irqs);
kfree(desc);
}
static void delayed_free_desc(struct rcu_head *rhp)
{
struct irq_desc *desc = container_of(rhp, struct irq_desc, rcu);
kobject_put(&desc->kobj);
}
static void free_desc(unsigned int irq)
{
struct irq_desc *desc = irq_to_desc(irq);
irq_remove_debugfs_entry(desc);
unregister_irq_proc(irq, desc);
kobject_del(&desc->kobj);
delete_irq_desc(irq);
call_rcu(&desc->rcu, delayed_free_desc);
}
static int alloc_descs(unsigned int start, unsigned int cnt, int node,
const struct cpumask *affinity, struct module *owner)
{
const struct cpumask *mask = NULL;
struct irq_desc *desc;
unsigned int flags;
int i;
if (affinity) {
for (i = 0, mask = affinity; i < cnt; i++, mask++) {
if (cpumask_empty(mask))
return -EINVAL;
}
}
flags = affinity ? IRQD_AFFINITY_MANAGED : 0;
mask = NULL;
for (i = 0; i < cnt; i++) {
if (affinity) {
node = cpu_to_node(cpumask_first(affinity));
mask = affinity;
affinity++;
}
desc = alloc_desc(start + i, node, flags, mask, owner);
if (!desc)
goto err;
irq_insert_desc(start + i, desc);
irq_sysfs_add(start + i, desc);
}
bitmap_set(allocated_irqs, start, cnt);
return start;
err:
for (i--; i >= 0; i--)
free_desc(start + i);
return -ENOMEM;
}
static int irq_expand_nr_irqs(unsigned int nr)
{
if (nr > IRQ_BITMAP_BITS)
return -ENOMEM;
nr_irqs = nr;
return 0;
}
int __init early_irq_init(void)
{
int i, initcnt, node = first_online_node;
struct irq_desc *desc;
init_irq_default_affinity();
initcnt = arch_probe_nr_irqs();
printk(KERN_INFO "NR_IRQS: %d, nr_irqs: %d, preallocated irqs: %d\n",
NR_IRQS, nr_irqs, initcnt);
if (WARN_ON(nr_irqs > IRQ_BITMAP_BITS))
nr_irqs = IRQ_BITMAP_BITS;
if (WARN_ON(initcnt > IRQ_BITMAP_BITS))
initcnt = IRQ_BITMAP_BITS;
if (initcnt > nr_irqs)
nr_irqs = initcnt;
for (i = 0; i < initcnt; i++) {
desc = alloc_desc(i, node, 0, NULL, NULL);
set_bit(i, allocated_irqs);
irq_insert_desc(i, desc);
}
return arch_early_irq_init();
}
int __init early_irq_init(void)
{
int count, i, node = first_online_node;
struct irq_desc *desc;
init_irq_default_affinity();
printk(KERN_INFO "NR_IRQS: %d\n", NR_IRQS);
desc = irq_desc;
count = ARRAY_SIZE(irq_desc);
for (i = 0; i < count; i++) {
desc[i].kstat_irqs = alloc_percpu(unsigned int);
alloc_masks(&desc[i], node);
raw_spin_lock_init(&desc[i].lock);
lockdep_set_class(&desc[i].lock, &irq_desc_lock_class);
desc_set_defaults(i, &desc[i], node, NULL, NULL);
}
return arch_early_irq_init();
}
struct irq_desc *irq_to_desc(unsigned int irq)
{
return (irq < NR_IRQS) ? irq_desc + irq : NULL;
}
static void free_desc(unsigned int irq)
{
struct irq_desc *desc = irq_to_desc(irq);
unsigned long flags;
raw_spin_lock_irqsave(&desc->lock, flags);
desc_set_defaults(irq, desc, irq_desc_get_node(desc), NULL, NULL);
raw_spin_unlock_irqrestore(&desc->lock, flags);
}
static inline int alloc_descs(unsigned int start, unsigned int cnt, int node,
const struct cpumask *affinity,
struct module *owner)
{
u32 i;
for (i = 0; i < cnt; i++) {
struct irq_desc *desc = irq_to_desc(start + i);
desc->owner = owner;
}
bitmap_set(allocated_irqs, start, cnt);
return start;
}
static int irq_expand_nr_irqs(unsigned int nr)
{
return -ENOMEM;
}
void irq_mark_irq(unsigned int irq)
{
mutex_lock(&sparse_irq_lock);
bitmap_set(allocated_irqs, irq, 1);
mutex_unlock(&sparse_irq_lock);
}
void irq_init_desc(unsigned int irq)
{
free_desc(irq);
}
int generic_handle_irq(unsigned int irq)
{
struct irq_desc *desc = irq_to_desc(irq);
if (!desc)
return -EINVAL;
generic_handle_irq_desc(desc);
return 0;
}
int __handle_domain_irq(struct irq_domain *domain, unsigned int hwirq,
bool lookup, struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
unsigned int irq = hwirq;
int ret = 0;
irq_enter();
#ifdef CONFIG_IRQ_DOMAIN
if (lookup)
irq = irq_find_mapping(domain, hwirq);
#endif
if (unlikely(!irq || irq >= nr_irqs)) {
ack_bad_irq(irq);
ret = -EINVAL;
} else {
generic_handle_irq(irq);
}
irq_exit();
set_irq_regs(old_regs);
return ret;
}
void irq_free_descs(unsigned int from, unsigned int cnt)
{
int i;
if (from >= nr_irqs || (from + cnt) > nr_irqs)
return;
mutex_lock(&sparse_irq_lock);
for (i = 0; i < cnt; i++)
free_desc(from + i);
bitmap_clear(allocated_irqs, from, cnt);
mutex_unlock(&sparse_irq_lock);
}
int __ref
__irq_alloc_descs(int irq, unsigned int from, unsigned int cnt, int node,
struct module *owner, const struct cpumask *affinity)
{
int start, ret;
if (!cnt)
return -EINVAL;
if (irq >= 0) {
if (from > irq)
return -EINVAL;
from = irq;
} else {
from = arch_dynirq_lower_bound(from);
}
mutex_lock(&sparse_irq_lock);
start = bitmap_find_next_zero_area(allocated_irqs, IRQ_BITMAP_BITS,
from, cnt, 0);
ret = -EEXIST;
if (irq >=0 && start != irq)
goto unlock;
if (start + cnt > nr_irqs) {
ret = irq_expand_nr_irqs(start + cnt);
if (ret)
goto unlock;
}
ret = alloc_descs(start, cnt, node, affinity, owner);
unlock:
mutex_unlock(&sparse_irq_lock);
return ret;
}
unsigned int irq_alloc_hwirqs(int cnt, int node)
{
int i, irq = __irq_alloc_descs(-1, 0, cnt, node, NULL, NULL);
if (irq < 0)
return 0;
for (i = irq; cnt > 0; i++, cnt--) {
if (arch_setup_hwirq(i, node))
goto err;
irq_clear_status_flags(i, _IRQ_NOREQUEST);
}
return irq;
err:
for (i--; i >= irq; i--) {
irq_set_status_flags(i, _IRQ_NOREQUEST | _IRQ_NOPROBE);
arch_teardown_hwirq(i);
}
irq_free_descs(irq, cnt);
return 0;
}
void irq_free_hwirqs(unsigned int from, int cnt)
{
int i, j;
for (i = from, j = cnt; j > 0; i++, j--) {
irq_set_status_flags(i, _IRQ_NOREQUEST | _IRQ_NOPROBE);
arch_teardown_hwirq(i);
}
irq_free_descs(from, cnt);
}
unsigned int irq_get_next_irq(unsigned int offset)
{
return find_next_bit(allocated_irqs, nr_irqs, offset);
}
struct irq_desc *
__irq_get_desc_lock(unsigned int irq, unsigned long *flags, bool bus,
unsigned int check)
{
struct irq_desc *desc = irq_to_desc(irq);
if (desc) {
if (check & _IRQ_DESC_CHECK) {
if ((check & _IRQ_DESC_PERCPU) &&
!irq_settings_is_per_cpu_devid(desc))
return NULL;
if (!(check & _IRQ_DESC_PERCPU) &&
irq_settings_is_per_cpu_devid(desc))
return NULL;
}
if (bus)
chip_bus_lock(desc);
raw_spin_lock_irqsave(&desc->lock, *flags);
}
return desc;
}
void __irq_put_desc_unlock(struct irq_desc *desc, unsigned long flags, bool bus)
{
raw_spin_unlock_irqrestore(&desc->lock, flags);
if (bus)
chip_bus_sync_unlock(desc);
}
int irq_set_percpu_devid_partition(unsigned int irq,
const struct cpumask *affinity)
{
struct irq_desc *desc = irq_to_desc(irq);
if (!desc)
return -EINVAL;
if (desc->percpu_enabled)
return -EINVAL;
desc->percpu_enabled = kzalloc(sizeof(*desc->percpu_enabled), GFP_KERNEL);
if (!desc->percpu_enabled)
return -ENOMEM;
if (affinity)
desc->percpu_affinity = affinity;
else
desc->percpu_affinity = cpu_possible_mask;
irq_set_percpu_devid_flags(irq);
return 0;
}
int irq_set_percpu_devid(unsigned int irq)
{
return irq_set_percpu_devid_partition(irq, NULL);
}
int irq_get_percpu_devid_partition(unsigned int irq, struct cpumask *affinity)
{
struct irq_desc *desc = irq_to_desc(irq);
if (!desc || !desc->percpu_enabled)
return -EINVAL;
if (affinity)
cpumask_copy(affinity, desc->percpu_affinity);
return 0;
}
void kstat_incr_irq_this_cpu(unsigned int irq)
{
kstat_incr_irqs_this_cpu(irq_to_desc(irq));
}
unsigned int kstat_irqs_cpu(unsigned int irq, int cpu)
{
struct irq_desc *desc = irq_to_desc(irq);
return desc && desc->kstat_irqs ?
*per_cpu_ptr(desc->kstat_irqs, cpu) : 0;
}
unsigned int kstat_irqs(unsigned int irq)
{
struct irq_desc *desc = irq_to_desc(irq);
int cpu;
unsigned int sum = 0;
if (!desc || !desc->kstat_irqs)
return 0;
for_each_possible_cpu(cpu)
sum += *per_cpu_ptr(desc->kstat_irqs, cpu);
return sum;
}
unsigned int kstat_irqs_usr(unsigned int irq)
{
unsigned int sum;
irq_lock_sparse();
sum = kstat_irqs(irq);
irq_unlock_sparse();
return sum;
}
