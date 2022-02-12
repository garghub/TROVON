int check_irq_used(int irq)
{
if (irq_status[irq] == IRQ_USED)
return 1;
return -1;
}
static inline int find_unassigned_irq(void)
{
int irq;
for (irq = IA64_FIRST_DEVICE_VECTOR; irq < NR_IRQS; irq++)
if (irq_status[irq] == IRQ_UNUSED)
return irq;
return -ENOSPC;
}
static inline int find_unassigned_vector(cpumask_t domain)
{
cpumask_t mask;
int pos, vector;
cpus_and(mask, domain, cpu_online_map);
if (cpus_empty(mask))
return -EINVAL;
for (pos = 0; pos < IA64_NUM_DEVICE_VECTORS; pos++) {
vector = IA64_FIRST_DEVICE_VECTOR + pos;
cpus_and(mask, domain, vector_table[vector]);
if (!cpus_empty(mask))
continue;
return vector;
}
return -ENOSPC;
}
static int __bind_irq_vector(int irq, int vector, cpumask_t domain)
{
cpumask_t mask;
int cpu;
struct irq_cfg *cfg = &irq_cfg[irq];
BUG_ON((unsigned)irq >= NR_IRQS);
BUG_ON((unsigned)vector >= IA64_NUM_VECTORS);
cpus_and(mask, domain, cpu_online_map);
if (cpus_empty(mask))
return -EINVAL;
if ((cfg->vector == vector) && cpus_equal(cfg->domain, domain))
return 0;
if (cfg->vector != IRQ_VECTOR_UNASSIGNED)
return -EBUSY;
for_each_cpu_mask(cpu, mask)
per_cpu(vector_irq, cpu)[vector] = irq;
cfg->vector = vector;
cfg->domain = domain;
irq_status[irq] = IRQ_USED;
cpus_or(vector_table[vector], vector_table[vector], domain);
return 0;
}
int bind_irq_vector(int irq, int vector, cpumask_t domain)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&vector_lock, flags);
ret = __bind_irq_vector(irq, vector, domain);
spin_unlock_irqrestore(&vector_lock, flags);
return ret;
}
static void __clear_irq_vector(int irq)
{
int vector, cpu;
cpumask_t mask;
cpumask_t domain;
struct irq_cfg *cfg = &irq_cfg[irq];
BUG_ON((unsigned)irq >= NR_IRQS);
BUG_ON(cfg->vector == IRQ_VECTOR_UNASSIGNED);
vector = cfg->vector;
domain = cfg->domain;
cpus_and(mask, cfg->domain, cpu_online_map);
for_each_cpu_mask(cpu, mask)
per_cpu(vector_irq, cpu)[vector] = -1;
cfg->vector = IRQ_VECTOR_UNASSIGNED;
cfg->domain = CPU_MASK_NONE;
irq_status[irq] = IRQ_UNUSED;
cpus_andnot(vector_table[vector], vector_table[vector], domain);
}
static void clear_irq_vector(int irq)
{
unsigned long flags;
spin_lock_irqsave(&vector_lock, flags);
__clear_irq_vector(irq);
spin_unlock_irqrestore(&vector_lock, flags);
}
int
ia64_native_assign_irq_vector (int irq)
{
unsigned long flags;
int vector, cpu;
cpumask_t domain = CPU_MASK_NONE;
vector = -ENOSPC;
spin_lock_irqsave(&vector_lock, flags);
for_each_online_cpu(cpu) {
domain = vector_allocation_domain(cpu);
vector = find_unassigned_vector(domain);
if (vector >= 0)
break;
}
if (vector < 0)
goto out;
if (irq == AUTO_ASSIGN)
irq = vector;
BUG_ON(__bind_irq_vector(irq, vector, domain));
out:
spin_unlock_irqrestore(&vector_lock, flags);
return vector;
}
void
ia64_native_free_irq_vector (int vector)
{
if (vector < IA64_FIRST_DEVICE_VECTOR ||
vector > IA64_LAST_DEVICE_VECTOR)
return;
clear_irq_vector(vector);
}
int
reserve_irq_vector (int vector)
{
if (vector < IA64_FIRST_DEVICE_VECTOR ||
vector > IA64_LAST_DEVICE_VECTOR)
return -EINVAL;
return !!bind_irq_vector(vector, vector, CPU_MASK_ALL);
}
void __setup_vector_irq(int cpu)
{
int irq, vector;
for (vector = 0; vector < IA64_NUM_VECTORS; ++vector)
per_cpu(vector_irq, cpu)[vector] = -1;
for (irq = 0; irq < NR_IRQS; ++irq) {
if (!cpu_isset(cpu, irq_cfg[irq].domain))
continue;
vector = irq_to_vector(irq);
per_cpu(vector_irq, cpu)[vector] = irq;
}
}
static cpumask_t vector_allocation_domain(int cpu)
{
if (vector_domain_type == VECTOR_DOMAIN_PERCPU)
return cpumask_of_cpu(cpu);
return CPU_MASK_ALL;
}
static int __irq_prepare_move(int irq, int cpu)
{
struct irq_cfg *cfg = &irq_cfg[irq];
int vector;
cpumask_t domain;
if (cfg->move_in_progress || cfg->move_cleanup_count)
return -EBUSY;
if (cfg->vector == IRQ_VECTOR_UNASSIGNED || !cpu_online(cpu))
return -EINVAL;
if (cpu_isset(cpu, cfg->domain))
return 0;
domain = vector_allocation_domain(cpu);
vector = find_unassigned_vector(domain);
if (vector < 0)
return -ENOSPC;
cfg->move_in_progress = 1;
cfg->old_domain = cfg->domain;
cfg->vector = IRQ_VECTOR_UNASSIGNED;
cfg->domain = CPU_MASK_NONE;
BUG_ON(__bind_irq_vector(irq, vector, domain));
return 0;
}
int irq_prepare_move(int irq, int cpu)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&vector_lock, flags);
ret = __irq_prepare_move(irq, cpu);
spin_unlock_irqrestore(&vector_lock, flags);
return ret;
}
void irq_complete_move(unsigned irq)
{
struct irq_cfg *cfg = &irq_cfg[irq];
cpumask_t cleanup_mask;
int i;
if (likely(!cfg->move_in_progress))
return;
if (unlikely(cpu_isset(smp_processor_id(), cfg->old_domain)))
return;
cpus_and(cleanup_mask, cfg->old_domain, cpu_online_map);
cfg->move_cleanup_count = cpus_weight(cleanup_mask);
for_each_cpu_mask(i, cleanup_mask)
platform_send_ipi(i, IA64_IRQ_MOVE_VECTOR, IA64_IPI_DM_INT, 0);
cfg->move_in_progress = 0;
}
static irqreturn_t smp_irq_move_cleanup_interrupt(int irq, void *dev_id)
{
int me = smp_processor_id();
ia64_vector vector;
unsigned long flags;
for (vector = IA64_FIRST_DEVICE_VECTOR;
vector < IA64_LAST_DEVICE_VECTOR; vector++) {
int irq;
struct irq_desc *desc;
struct irq_cfg *cfg;
irq = __get_cpu_var(vector_irq)[vector];
if (irq < 0)
continue;
desc = irq_to_desc(irq);
cfg = irq_cfg + irq;
raw_spin_lock(&desc->lock);
if (!cfg->move_cleanup_count)
goto unlock;
if (!cpu_isset(me, cfg->old_domain))
goto unlock;
spin_lock_irqsave(&vector_lock, flags);
__get_cpu_var(vector_irq)[vector] = -1;
cpu_clear(me, vector_table[vector]);
spin_unlock_irqrestore(&vector_lock, flags);
cfg->move_cleanup_count--;
unlock:
raw_spin_unlock(&desc->lock);
}
return IRQ_HANDLED;
}
static int __init parse_vector_domain(char *arg)
{
if (!arg)
return -EINVAL;
if (!strcmp(arg, "percpu")) {
vector_domain_type = VECTOR_DOMAIN_PERCPU;
no_int_routing = 1;
}
return 0;
}
static cpumask_t vector_allocation_domain(int cpu)
{
return CPU_MASK_ALL;
}
void destroy_and_reserve_irq(unsigned int irq)
{
unsigned long flags;
dynamic_irq_cleanup(irq);
spin_lock_irqsave(&vector_lock, flags);
__clear_irq_vector(irq);
irq_status[irq] = IRQ_RSVD;
spin_unlock_irqrestore(&vector_lock, flags);
}
int create_irq(void)
{
unsigned long flags;
int irq, vector, cpu;
cpumask_t domain = CPU_MASK_NONE;
irq = vector = -ENOSPC;
spin_lock_irqsave(&vector_lock, flags);
for_each_online_cpu(cpu) {
domain = vector_allocation_domain(cpu);
vector = find_unassigned_vector(domain);
if (vector >= 0)
break;
}
if (vector < 0)
goto out;
irq = find_unassigned_irq();
if (irq < 0)
goto out;
BUG_ON(__bind_irq_vector(irq, vector, domain));
out:
spin_unlock_irqrestore(&vector_lock, flags);
if (irq >= 0)
dynamic_irq_init(irq);
return irq;
}
void destroy_irq(unsigned int irq)
{
dynamic_irq_cleanup(irq);
clear_irq_vector(irq);
}
void
ia64_handle_irq (ia64_vector vector, struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
unsigned long saved_tpr;
#if IRQ_DEBUG
{
unsigned long bsp, sp;
bsp = ia64_getreg(_IA64_REG_AR_BSP);
sp = ia64_getreg(_IA64_REG_SP);
if ((sp - bsp) < 1024) {
static DEFINE_RATELIMIT_STATE(ratelimit, 5 * HZ, 5);
if (__ratelimit(&ratelimit)) {
printk("ia64_handle_irq: DANGER: less than "
"1KB of free stack space!!\n"
"(bsp=0x%lx, sp=%lx)\n", bsp, sp);
}
}
}
#endif
irq_enter();
saved_tpr = ia64_getreg(_IA64_REG_CR_TPR);
ia64_srlz_d();
while (vector != IA64_SPURIOUS_INT_VECTOR) {
int irq = local_vector_to_irq(vector);
struct irq_desc *desc = irq_to_desc(irq);
if (unlikely(IS_LOCAL_TLB_FLUSH(vector))) {
smp_local_flush_tlb();
kstat_incr_irqs_this_cpu(irq, desc);
} else if (unlikely(IS_RESCHEDULE(vector))) {
scheduler_ipi();
kstat_incr_irqs_this_cpu(irq, desc);
} else {
ia64_setreg(_IA64_REG_CR_TPR, vector);
ia64_srlz_d();
if (unlikely(irq < 0)) {
printk(KERN_ERR "%s: Unexpected interrupt "
"vector %d on CPU %d is not mapped "
"to any IRQ!\n", __func__, vector,
smp_processor_id());
} else
generic_handle_irq(irq);
local_irq_disable();
ia64_setreg(_IA64_REG_CR_TPR, saved_tpr);
}
ia64_eoi();
vector = ia64_get_ivr();
}
irq_exit();
set_irq_regs(old_regs);
}
void ia64_process_pending_intr(void)
{
ia64_vector vector;
unsigned long saved_tpr;
extern unsigned int vectors_in_migration[NR_IRQS];
vector = ia64_get_ivr();
irq_enter();
saved_tpr = ia64_getreg(_IA64_REG_CR_TPR);
ia64_srlz_d();
while (vector != IA64_SPURIOUS_INT_VECTOR) {
int irq = local_vector_to_irq(vector);
struct irq_desc *desc = irq_to_desc(irq);
if (unlikely(IS_LOCAL_TLB_FLUSH(vector))) {
smp_local_flush_tlb();
kstat_incr_irqs_this_cpu(irq, desc);
} else if (unlikely(IS_RESCHEDULE(vector))) {
kstat_incr_irqs_this_cpu(irq, desc);
} else {
struct pt_regs *old_regs = set_irq_regs(NULL);
ia64_setreg(_IA64_REG_CR_TPR, vector);
ia64_srlz_d();
if (unlikely(irq < 0)) {
printk(KERN_ERR "%s: Unexpected interrupt "
"vector %d on CPU %d not being mapped "
"to any IRQ!!\n", __func__, vector,
smp_processor_id());
} else {
vectors_in_migration[irq]=0;
generic_handle_irq(irq);
}
set_irq_regs(old_regs);
local_irq_disable();
ia64_setreg(_IA64_REG_CR_TPR, saved_tpr);
}
ia64_eoi();
vector = ia64_get_ivr();
}
irq_exit();
}
static irqreturn_t dummy_handler (int irq, void *dev_id)
{
BUG();
}
void
ia64_native_register_percpu_irq (ia64_vector vec, struct irqaction *action)
{
unsigned int irq;
irq = vec;
BUG_ON(bind_irq_vector(irq, vec, CPU_MASK_ALL));
irq_set_status_flags(irq, IRQ_PER_CPU);
irq_set_chip(irq, &irq_type_ia64_lsapic);
if (action)
setup_irq(irq, action);
irq_set_handler(irq, handle_percpu_irq);
}
void __init
ia64_native_register_ipi(void)
{
#ifdef CONFIG_SMP
register_percpu_irq(IA64_IPI_VECTOR, &ipi_irqaction);
register_percpu_irq(IA64_IPI_RESCHEDULE, &resched_irqaction);
register_percpu_irq(IA64_IPI_LOCAL_TLB_FLUSH, &tlb_irqaction);
#endif
}
void __init
init_IRQ (void)
{
#ifdef CONFIG_ACPI
acpi_boot_init();
#endif
ia64_register_ipi();
register_percpu_irq(IA64_SPURIOUS_INT_VECTOR, NULL);
#ifdef CONFIG_SMP
#if defined(CONFIG_IA64_GENERIC) || defined(CONFIG_IA64_DIG)
if (vector_domain_type != VECTOR_DOMAIN_NONE)
register_percpu_irq(IA64_IRQ_MOVE_VECTOR, &irq_move_irqaction);
#endif
#endif
#ifdef CONFIG_PERFMON
pfm_init_percpu();
#endif
platform_irq_init();
}
void
ia64_send_ipi (int cpu, int vector, int delivery_mode, int redirect)
{
void __iomem *ipi_addr;
unsigned long ipi_data;
unsigned long phys_cpu_id;
phys_cpu_id = cpu_physical_id(cpu);
ipi_data = (delivery_mode << 8) | (vector & 0xff);
ipi_addr = ipi_base_addr + ((phys_cpu_id << 4) | ((redirect & 1) << 3));
writeq(ipi_data, ipi_addr);
}
