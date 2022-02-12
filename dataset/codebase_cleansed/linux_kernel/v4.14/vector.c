void lock_vector_lock(void)
{
raw_spin_lock(&vector_lock);
}
void unlock_vector_lock(void)
{
raw_spin_unlock(&vector_lock);
}
static struct apic_chip_data *apic_chip_data(struct irq_data *irq_data)
{
if (!irq_data)
return NULL;
while (irq_data->parent_data)
irq_data = irq_data->parent_data;
return irq_data->chip_data;
}
struct irq_cfg *irqd_cfg(struct irq_data *irq_data)
{
struct apic_chip_data *data = apic_chip_data(irq_data);
return data ? &data->cfg : NULL;
}
struct irq_cfg *irq_cfg(unsigned int irq)
{
return irqd_cfg(irq_get_irq_data(irq));
}
static struct apic_chip_data *alloc_apic_chip_data(int node)
{
struct apic_chip_data *data;
data = kzalloc_node(sizeof(*data), GFP_KERNEL, node);
if (!data)
return NULL;
if (!zalloc_cpumask_var_node(&data->domain, GFP_KERNEL, node))
goto out_data;
if (!zalloc_cpumask_var_node(&data->old_domain, GFP_KERNEL, node))
goto out_domain;
return data;
out_domain:
free_cpumask_var(data->domain);
out_data:
kfree(data);
return NULL;
}
static void free_apic_chip_data(struct apic_chip_data *data)
{
if (data) {
free_cpumask_var(data->domain);
free_cpumask_var(data->old_domain);
kfree(data);
}
}
static int __assign_irq_vector(int irq, struct apic_chip_data *d,
const struct cpumask *mask,
struct irq_data *irqdata)
{
static int current_vector = FIRST_EXTERNAL_VECTOR + VECTOR_OFFSET_START;
static int current_offset = VECTOR_OFFSET_START % 16;
int cpu, vector;
if (d->move_in_progress ||
cpumask_intersects(d->old_domain, cpu_online_mask))
return -EBUSY;
cpumask_clear(d->old_domain);
cpumask_clear(searched_cpumask);
cpu = cpumask_first_and(mask, cpu_online_mask);
while (cpu < nr_cpu_ids) {
int new_cpu, offset;
apic->vector_allocation_domain(cpu, vector_cpumask, mask);
cpumask_and(vector_searchmask, vector_cpumask, cpu_online_mask);
if (!cpumask_intersects(vector_searchmask, mask))
goto next_cpu;
if (cpumask_subset(vector_cpumask, d->domain)) {
if (cpumask_equal(vector_cpumask, d->domain))
goto success;
cpumask_andnot(d->old_domain, d->domain, vector_cpumask);
vector = d->cfg.vector;
goto update;
}
vector = current_vector;
offset = current_offset;
next:
vector += 16;
if (vector >= FIRST_SYSTEM_VECTOR) {
offset = (offset + 1) % 16;
vector = FIRST_EXTERNAL_VECTOR + offset;
}
if (unlikely(current_vector == vector))
goto next_cpu;
if (test_bit(vector, used_vectors))
goto next;
for_each_cpu(new_cpu, vector_searchmask) {
if (!IS_ERR_OR_NULL(per_cpu(vector_irq, new_cpu)[vector]))
goto next;
}
current_vector = vector;
current_offset = offset;
if (d->cfg.vector)
cpumask_copy(d->old_domain, d->domain);
for_each_cpu(new_cpu, vector_searchmask)
per_cpu(vector_irq, new_cpu)[vector] = irq_to_desc(irq);
goto update;
next_cpu:
cpumask_or(searched_cpumask, searched_cpumask, vector_cpumask);
cpumask_andnot(vector_cpumask, mask, searched_cpumask);
cpu = cpumask_first_and(vector_cpumask, cpu_online_mask);
continue;
}
return -ENOSPC;
update:
cpumask_and(d->old_domain, d->old_domain, cpu_online_mask);
d->move_in_progress = !cpumask_empty(d->old_domain);
d->cfg.old_vector = d->move_in_progress ? d->cfg.vector : 0;
d->cfg.vector = vector;
cpumask_copy(d->domain, vector_cpumask);
success:
cpumask_and(vector_searchmask, vector_searchmask, mask);
BUG_ON(apic->cpu_mask_to_apicid(vector_searchmask, irqdata,
&d->cfg.dest_apicid));
return 0;
}
static int assign_irq_vector(int irq, struct apic_chip_data *data,
const struct cpumask *mask,
struct irq_data *irqdata)
{
int err;
unsigned long flags;
raw_spin_lock_irqsave(&vector_lock, flags);
err = __assign_irq_vector(irq, data, mask, irqdata);
raw_spin_unlock_irqrestore(&vector_lock, flags);
return err;
}
static int assign_irq_vector_policy(int irq, int node,
struct apic_chip_data *data,
struct irq_alloc_info *info,
struct irq_data *irqdata)
{
if (info && info->mask)
return assign_irq_vector(irq, data, info->mask, irqdata);
if (node != NUMA_NO_NODE &&
assign_irq_vector(irq, data, cpumask_of_node(node), irqdata) == 0)
return 0;
return assign_irq_vector(irq, data, apic->target_cpus(), irqdata);
}
static void clear_irq_vector(int irq, struct apic_chip_data *data)
{
struct irq_desc *desc;
int cpu, vector;
if (!data->cfg.vector)
return;
vector = data->cfg.vector;
for_each_cpu_and(cpu, data->domain, cpu_online_mask)
per_cpu(vector_irq, cpu)[vector] = VECTOR_UNUSED;
data->cfg.vector = 0;
cpumask_clear(data->domain);
if (!data->move_in_progress && cpumask_empty(data->old_domain))
return;
desc = irq_to_desc(irq);
for_each_cpu_and(cpu, data->old_domain, cpu_online_mask) {
for (vector = FIRST_EXTERNAL_VECTOR; vector < NR_VECTORS;
vector++) {
if (per_cpu(vector_irq, cpu)[vector] != desc)
continue;
per_cpu(vector_irq, cpu)[vector] = VECTOR_UNUSED;
break;
}
}
data->move_in_progress = 0;
}
void init_irq_alloc_info(struct irq_alloc_info *info,
const struct cpumask *mask)
{
memset(info, 0, sizeof(*info));
info->mask = mask;
}
void copy_irq_alloc_info(struct irq_alloc_info *dst, struct irq_alloc_info *src)
{
if (src)
*dst = *src;
else
memset(dst, 0, sizeof(*dst));
}
static void x86_vector_free_irqs(struct irq_domain *domain,
unsigned int virq, unsigned int nr_irqs)
{
struct apic_chip_data *apic_data;
struct irq_data *irq_data;
unsigned long flags;
int i;
for (i = 0; i < nr_irqs; i++) {
irq_data = irq_domain_get_irq_data(x86_vector_domain, virq + i);
if (irq_data && irq_data->chip_data) {
raw_spin_lock_irqsave(&vector_lock, flags);
clear_irq_vector(virq + i, irq_data->chip_data);
apic_data = irq_data->chip_data;
irq_domain_reset_irq_data(irq_data);
raw_spin_unlock_irqrestore(&vector_lock, flags);
free_apic_chip_data(apic_data);
#ifdef CONFIG_X86_IO_APIC
if (virq + i < nr_legacy_irqs())
legacy_irq_data[virq + i] = NULL;
#endif
}
}
}
static int x86_vector_alloc_irqs(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
struct irq_alloc_info *info = arg;
struct apic_chip_data *data;
struct irq_data *irq_data;
int i, err, node;
if (disable_apic)
return -ENXIO;
if ((info->flags & X86_IRQ_ALLOC_CONTIGUOUS_VECTORS) && nr_irqs > 1)
return -ENOSYS;
for (i = 0; i < nr_irqs; i++) {
irq_data = irq_domain_get_irq_data(domain, virq + i);
BUG_ON(!irq_data);
node = irq_data_get_node(irq_data);
#ifdef CONFIG_X86_IO_APIC
if (virq + i < nr_legacy_irqs() && legacy_irq_data[virq + i])
data = legacy_irq_data[virq + i];
else
#endif
data = alloc_apic_chip_data(node);
if (!data) {
err = -ENOMEM;
goto error;
}
irq_data->chip = &lapic_controller;
irq_data->chip_data = data;
irq_data->hwirq = virq + i;
err = assign_irq_vector_policy(virq + i, node, data, info,
irq_data);
if (err)
goto error;
if (!apic->irq_dest_mode)
irqd_set_single_target(irq_data);
}
return 0;
error:
x86_vector_free_irqs(domain, virq, i + 1);
return err;
}
int __init arch_probe_nr_irqs(void)
{
int nr;
if (nr_irqs > (NR_VECTORS * nr_cpu_ids))
nr_irqs = NR_VECTORS * nr_cpu_ids;
nr = (gsi_top + nr_legacy_irqs()) + 8 * nr_cpu_ids;
#if defined(CONFIG_PCI_MSI) || defined(CONFIG_HT_IRQ)
if (gsi_top <= NR_IRQS_LEGACY)
nr += 8 * nr_cpu_ids;
else
nr += gsi_top * 16;
#endif
if (nr < nr_irqs)
nr_irqs = nr;
return legacy_pic->probe();
}
static void __init init_legacy_irqs(void)
{
int i, node = cpu_to_node(0);
struct apic_chip_data *data;
for (i = 0; i < nr_legacy_irqs(); i++) {
data = legacy_irq_data[i] = alloc_apic_chip_data(node);
BUG_ON(!data);
data->cfg.vector = ISA_IRQ_VECTOR(i);
cpumask_setall(data->domain);
irq_set_chip_data(i, data);
}
}
static inline void init_legacy_irqs(void) { }
int __init arch_early_irq_init(void)
{
struct fwnode_handle *fn;
init_legacy_irqs();
fn = irq_domain_alloc_named_fwnode("VECTOR");
BUG_ON(!fn);
x86_vector_domain = irq_domain_create_tree(fn, &x86_vector_domain_ops,
NULL);
BUG_ON(x86_vector_domain == NULL);
irq_domain_free_fwnode(fn);
irq_set_default_host(x86_vector_domain);
arch_init_msi_domain(x86_vector_domain);
arch_init_htirq_domain(x86_vector_domain);
BUG_ON(!alloc_cpumask_var(&vector_cpumask, GFP_KERNEL));
BUG_ON(!alloc_cpumask_var(&vector_searchmask, GFP_KERNEL));
BUG_ON(!alloc_cpumask_var(&searched_cpumask, GFP_KERNEL));
return arch_early_ioapic_init();
}
static void __setup_vector_irq(int cpu)
{
struct apic_chip_data *data;
struct irq_desc *desc;
int irq, vector;
for_each_irq_desc(irq, desc) {
struct irq_data *idata = irq_desc_get_irq_data(desc);
data = apic_chip_data(idata);
if (!data || !cpumask_test_cpu(cpu, data->domain))
continue;
vector = data->cfg.vector;
per_cpu(vector_irq, cpu)[vector] = desc;
}
for (vector = 0; vector < NR_VECTORS; ++vector) {
desc = per_cpu(vector_irq, cpu)[vector];
if (IS_ERR_OR_NULL(desc))
continue;
data = apic_chip_data(irq_desc_get_irq_data(desc));
if (!cpumask_test_cpu(cpu, data->domain))
per_cpu(vector_irq, cpu)[vector] = VECTOR_UNUSED;
}
}
void setup_vector_irq(int cpu)
{
int irq;
lockdep_assert_held(&vector_lock);
for (irq = 0; irq < nr_legacy_irqs(); irq++)
per_cpu(vector_irq, cpu)[ISA_IRQ_VECTOR(irq)] = irq_to_desc(irq);
__setup_vector_irq(cpu);
}
static int apic_retrigger_irq(struct irq_data *irq_data)
{
struct apic_chip_data *data = apic_chip_data(irq_data);
unsigned long flags;
int cpu;
raw_spin_lock_irqsave(&vector_lock, flags);
cpu = cpumask_first_and(data->domain, cpu_online_mask);
apic->send_IPI_mask(cpumask_of(cpu), data->cfg.vector);
raw_spin_unlock_irqrestore(&vector_lock, flags);
return 1;
}
void apic_ack_edge(struct irq_data *data)
{
irq_complete_move(irqd_cfg(data));
irq_move_irq(data);
ack_APIC_irq();
}
static int apic_set_affinity(struct irq_data *irq_data,
const struct cpumask *dest, bool force)
{
struct apic_chip_data *data = irq_data->chip_data;
int err, irq = irq_data->irq;
if (!IS_ENABLED(CONFIG_SMP))
return -EPERM;
if (!cpumask_intersects(dest, cpu_online_mask))
return -EINVAL;
err = assign_irq_vector(irq, data, dest, irq_data);
return err ? err : IRQ_SET_MASK_OK;
}
static void __send_cleanup_vector(struct apic_chip_data *data)
{
raw_spin_lock(&vector_lock);
cpumask_and(data->old_domain, data->old_domain, cpu_online_mask);
data->move_in_progress = 0;
if (!cpumask_empty(data->old_domain))
apic->send_IPI_mask(data->old_domain, IRQ_MOVE_CLEANUP_VECTOR);
raw_spin_unlock(&vector_lock);
}
void send_cleanup_vector(struct irq_cfg *cfg)
{
struct apic_chip_data *data;
data = container_of(cfg, struct apic_chip_data, cfg);
if (data->move_in_progress)
__send_cleanup_vector(data);
}
asmlinkage __visible void __irq_entry smp_irq_move_cleanup_interrupt(void)
{
unsigned vector, me;
entering_ack_irq();
raw_spin_lock(&vector_lock);
me = smp_processor_id();
for (vector = FIRST_EXTERNAL_VECTOR; vector < NR_VECTORS; vector++) {
struct apic_chip_data *data;
struct irq_desc *desc;
unsigned int irr;
retry:
desc = __this_cpu_read(vector_irq[vector]);
if (IS_ERR_OR_NULL(desc))
continue;
if (!raw_spin_trylock(&desc->lock)) {
raw_spin_unlock(&vector_lock);
cpu_relax();
raw_spin_lock(&vector_lock);
goto retry;
}
data = apic_chip_data(irq_desc_get_irq_data(desc));
if (!data)
goto unlock;
if (data->move_in_progress ||
!cpumask_test_cpu(me, data->old_domain))
goto unlock;
if (vector == data->cfg.vector &&
cpumask_test_cpu(me, data->domain))
goto unlock;
irr = apic_read(APIC_IRR + (vector / 32 * 0x10));
if (irr & (1 << (vector % 32))) {
apic->send_IPI_self(IRQ_MOVE_CLEANUP_VECTOR);
goto unlock;
}
__this_cpu_write(vector_irq[vector], VECTOR_UNUSED);
cpumask_clear_cpu(me, data->old_domain);
unlock:
raw_spin_unlock(&desc->lock);
}
raw_spin_unlock(&vector_lock);
exiting_irq();
}
static void __irq_complete_move(struct irq_cfg *cfg, unsigned vector)
{
unsigned me;
struct apic_chip_data *data;
data = container_of(cfg, struct apic_chip_data, cfg);
if (likely(!data->move_in_progress))
return;
me = smp_processor_id();
if (vector == data->cfg.vector && cpumask_test_cpu(me, data->domain))
__send_cleanup_vector(data);
}
void irq_complete_move(struct irq_cfg *cfg)
{
__irq_complete_move(cfg, ~get_irq_regs()->orig_ax);
}
void irq_force_complete_move(struct irq_desc *desc)
{
struct irq_data *irqdata;
struct apic_chip_data *data;
struct irq_cfg *cfg;
unsigned int cpu;
irqdata = irq_domain_get_irq_data(x86_vector_domain,
irq_desc_get_irq(desc));
if (!irqdata)
return;
data = apic_chip_data(irqdata);
cfg = data ? &data->cfg : NULL;
if (!cfg)
return;
raw_spin_lock(&vector_lock);
cpumask_and(data->old_domain, data->old_domain, cpu_online_mask);
if (!data->move_in_progress && cpumask_empty(data->old_domain)) {
raw_spin_unlock(&vector_lock);
return;
}
if (data->move_in_progress) {
pr_warn("IRQ fixup: irq %d move in progress, old vector %d\n",
irqdata->irq, cfg->old_vector);
}
for_each_cpu(cpu, data->old_domain)
per_cpu(vector_irq, cpu)[cfg->old_vector] = VECTOR_UNUSED;
cpumask_clear(data->old_domain);
data->move_in_progress = 0;
raw_spin_unlock(&vector_lock);
}
static void __init print_APIC_field(int base)
{
int i;
printk(KERN_DEBUG);
for (i = 0; i < 8; i++)
pr_cont("%08x", apic_read(base + i*0x10));
pr_cont("\n");
}
static void __init print_local_APIC(void *dummy)
{
unsigned int i, v, ver, maxlvt;
u64 icr;
pr_debug("printing local APIC contents on CPU#%d/%d:\n",
smp_processor_id(), hard_smp_processor_id());
v = apic_read(APIC_ID);
pr_info("... APIC ID: %08x (%01x)\n", v, read_apic_id());
v = apic_read(APIC_LVR);
pr_info("... APIC VERSION: %08x\n", v);
ver = GET_APIC_VERSION(v);
maxlvt = lapic_get_maxlvt();
v = apic_read(APIC_TASKPRI);
pr_debug("... APIC TASKPRI: %08x (%02x)\n", v, v & APIC_TPRI_MASK);
if (APIC_INTEGRATED(ver)) {
if (!APIC_XAPIC(ver)) {
v = apic_read(APIC_ARBPRI);
pr_debug("... APIC ARBPRI: %08x (%02x)\n",
v, v & APIC_ARBPRI_MASK);
}
v = apic_read(APIC_PROCPRI);
pr_debug("... APIC PROCPRI: %08x\n", v);
}
if (!APIC_INTEGRATED(ver) || maxlvt == 3) {
v = apic_read(APIC_RRR);
pr_debug("... APIC RRR: %08x\n", v);
}
v = apic_read(APIC_LDR);
pr_debug("... APIC LDR: %08x\n", v);
if (!x2apic_enabled()) {
v = apic_read(APIC_DFR);
pr_debug("... APIC DFR: %08x\n", v);
}
v = apic_read(APIC_SPIV);
pr_debug("... APIC SPIV: %08x\n", v);
pr_debug("... APIC ISR field:\n");
print_APIC_field(APIC_ISR);
pr_debug("... APIC TMR field:\n");
print_APIC_field(APIC_TMR);
pr_debug("... APIC IRR field:\n");
print_APIC_field(APIC_IRR);
if (APIC_INTEGRATED(ver)) {
if (maxlvt > 3)
apic_write(APIC_ESR, 0);
v = apic_read(APIC_ESR);
pr_debug("... APIC ESR: %08x\n", v);
}
icr = apic_icr_read();
pr_debug("... APIC ICR: %08x\n", (u32)icr);
pr_debug("... APIC ICR2: %08x\n", (u32)(icr >> 32));
v = apic_read(APIC_LVTT);
pr_debug("... APIC LVTT: %08x\n", v);
if (maxlvt > 3) {
v = apic_read(APIC_LVTPC);
pr_debug("... APIC LVTPC: %08x\n", v);
}
v = apic_read(APIC_LVT0);
pr_debug("... APIC LVT0: %08x\n", v);
v = apic_read(APIC_LVT1);
pr_debug("... APIC LVT1: %08x\n", v);
if (maxlvt > 2) {
v = apic_read(APIC_LVTERR);
pr_debug("... APIC LVTERR: %08x\n", v);
}
v = apic_read(APIC_TMICT);
pr_debug("... APIC TMICT: %08x\n", v);
v = apic_read(APIC_TMCCT);
pr_debug("... APIC TMCCT: %08x\n", v);
v = apic_read(APIC_TDCR);
pr_debug("... APIC TDCR: %08x\n", v);
if (boot_cpu_has(X86_FEATURE_EXTAPIC)) {
v = apic_read(APIC_EFEAT);
maxlvt = (v >> 16) & 0xff;
pr_debug("... APIC EFEAT: %08x\n", v);
v = apic_read(APIC_ECTRL);
pr_debug("... APIC ECTRL: %08x\n", v);
for (i = 0; i < maxlvt; i++) {
v = apic_read(APIC_EILVTn(i));
pr_debug("... APIC EILVT%d: %08x\n", i, v);
}
}
pr_cont("\n");
}
static void __init print_local_APICs(int maxcpu)
{
int cpu;
if (!maxcpu)
return;
preempt_disable();
for_each_online_cpu(cpu) {
if (cpu >= maxcpu)
break;
smp_call_function_single(cpu, print_local_APIC, NULL, 1);
}
preempt_enable();
}
static void __init print_PIC(void)
{
unsigned int v;
unsigned long flags;
if (!nr_legacy_irqs())
return;
pr_debug("\nprinting PIC contents\n");
raw_spin_lock_irqsave(&i8259A_lock, flags);
v = inb(0xa1) << 8 | inb(0x21);
pr_debug("... PIC IMR: %04x\n", v);
v = inb(0xa0) << 8 | inb(0x20);
pr_debug("... PIC IRR: %04x\n", v);
outb(0x0b, 0xa0);
outb(0x0b, 0x20);
v = inb(0xa0) << 8 | inb(0x20);
outb(0x0a, 0xa0);
outb(0x0a, 0x20);
raw_spin_unlock_irqrestore(&i8259A_lock, flags);
pr_debug("... PIC ISR: %04x\n", v);
v = inb(0x4d1) << 8 | inb(0x4d0);
pr_debug("... PIC ELCR: %04x\n", v);
}
static __init int setup_show_lapic(char *arg)
{
int num = -1;
if (strcmp(arg, "all") == 0) {
show_lapic = CONFIG_NR_CPUS;
} else {
get_option(&arg, &num);
if (num >= 0)
show_lapic = num;
}
return 1;
}
static int __init print_ICs(void)
{
if (apic_verbosity == APIC_QUIET)
return 0;
print_PIC();
if (!boot_cpu_has(X86_FEATURE_APIC) && !apic_from_smp_config())
return 0;
print_local_APICs(show_lapic);
print_IO_APICs();
return 0;
}
