static int
xen_assign_irq_vector(int irq)
{
struct physdev_irq irq_op;
irq_op.irq = irq;
if (HYPERVISOR_physdev_op(PHYSDEVOP_alloc_irq_vector, &irq_op))
return -ENOSPC;
return irq_op.vector;
}
static void
xen_free_irq_vector(int vector)
{
struct physdev_irq irq_op;
if (vector < IA64_FIRST_DEVICE_VECTOR ||
vector > IA64_LAST_DEVICE_VECTOR)
return;
irq_op.vector = vector;
if (HYPERVISOR_physdev_op(PHYSDEVOP_free_irq_vector, &irq_op))
printk(KERN_WARNING "%s: xen_free_irq_vector fail vector=%d\n",
__func__, vector);
}
static irqreturn_t
xen_dummy_handler(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static irqreturn_t
xen_resched_handler(int irq, void *dev_id)
{
scheduler_ipi();
return IRQ_HANDLED;
}
static void
__xen_register_percpu_irq(unsigned int cpu, unsigned int vec,
struct irqaction *action, int save)
{
int irq = 0;
if (xen_slab_ready) {
switch (vec) {
case IA64_TIMER_VECTOR:
snprintf(per_cpu(xen_timer_name, cpu),
sizeof(per_cpu(xen_timer_name, cpu)),
"%s%d", action->name, cpu);
irq = bind_virq_to_irqhandler(VIRQ_ITC, cpu,
action->handler, action->flags,
per_cpu(xen_timer_name, cpu), action->dev_id);
per_cpu(xen_timer_irq, cpu) = irq;
break;
case IA64_IPI_RESCHEDULE:
snprintf(per_cpu(xen_resched_name, cpu),
sizeof(per_cpu(xen_resched_name, cpu)),
"%s%d", action->name, cpu);
irq = bind_ipi_to_irqhandler(XEN_RESCHEDULE_VECTOR, cpu,
action->handler, action->flags,
per_cpu(xen_resched_name, cpu), action->dev_id);
per_cpu(xen_resched_irq, cpu) = irq;
break;
case IA64_IPI_VECTOR:
snprintf(per_cpu(xen_ipi_name, cpu),
sizeof(per_cpu(xen_ipi_name, cpu)),
"%s%d", action->name, cpu);
irq = bind_ipi_to_irqhandler(XEN_IPI_VECTOR, cpu,
action->handler, action->flags,
per_cpu(xen_ipi_name, cpu), action->dev_id);
per_cpu(xen_ipi_irq, cpu) = irq;
break;
case IA64_CMC_VECTOR:
snprintf(per_cpu(xen_cmc_name, cpu),
sizeof(per_cpu(xen_cmc_name, cpu)),
"%s%d", action->name, cpu);
irq = bind_virq_to_irqhandler(VIRQ_MCA_CMC, cpu,
action->handler,
action->flags,
per_cpu(xen_cmc_name, cpu),
action->dev_id);
per_cpu(xen_cmc_irq, cpu) = irq;
break;
case IA64_CMCP_VECTOR:
snprintf(per_cpu(xen_cmcp_name, cpu),
sizeof(per_cpu(xen_cmcp_name, cpu)),
"%s%d", action->name, cpu);
irq = bind_ipi_to_irqhandler(XEN_CMCP_VECTOR, cpu,
action->handler,
action->flags,
per_cpu(xen_cmcp_name, cpu),
action->dev_id);
per_cpu(xen_cmcp_irq, cpu) = irq;
break;
case IA64_CPEP_VECTOR:
snprintf(per_cpu(xen_cpep_name, cpu),
sizeof(per_cpu(xen_cpep_name, cpu)),
"%s%d", action->name, cpu);
irq = bind_ipi_to_irqhandler(XEN_CPEP_VECTOR, cpu,
action->handler,
action->flags,
per_cpu(xen_cpep_name, cpu),
action->dev_id);
per_cpu(xen_cpep_irq, cpu) = irq;
break;
case IA64_CPE_VECTOR:
case IA64_MCA_RENDEZ_VECTOR:
case IA64_PERFMON_VECTOR:
case IA64_MCA_WAKEUP_VECTOR:
case IA64_SPURIOUS_INT_VECTOR:
break;
default:
printk(KERN_WARNING "Percpu irq %d is unsupported "
"by xen!\n", vec);
break;
}
BUG_ON(irq < 0);
if (irq > 0) {
irq_set_status_flags(irq, IRQ_PER_CPU);
}
}
if (!cpu && save) {
BUG_ON(saved_irq_cnt == MAX_LATE_IRQ);
saved_percpu_irqs[saved_irq_cnt].irq = vec;
saved_percpu_irqs[saved_irq_cnt].action = action;
saved_irq_cnt++;
if (!xen_slab_ready)
late_irq_cnt++;
}
}
static void
xen_register_percpu_irq(ia64_vector vec, struct irqaction *action)
{
__xen_register_percpu_irq(smp_processor_id(), vec, action, 1);
}
static void
xen_bind_early_percpu_irq(void)
{
int i;
xen_slab_ready = 1;
for (i = 0; i < late_irq_cnt; i++)
__xen_register_percpu_irq(smp_processor_id(),
saved_percpu_irqs[i].irq,
saved_percpu_irqs[i].action, 0);
}
static int unbind_evtchn_callback(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long)hcpu;
if (action == CPU_DEAD) {
if (per_cpu(xen_cpep_irq, cpu) >= 0) {
unbind_from_irqhandler(per_cpu(xen_cpep_irq, cpu),
NULL);
per_cpu(xen_cpep_irq, cpu) = -1;
}
if (per_cpu(xen_cmcp_irq, cpu) >= 0) {
unbind_from_irqhandler(per_cpu(xen_cmcp_irq, cpu),
NULL);
per_cpu(xen_cmcp_irq, cpu) = -1;
}
if (per_cpu(xen_cmc_irq, cpu) >= 0) {
unbind_from_irqhandler(per_cpu(xen_cmc_irq, cpu), NULL);
per_cpu(xen_cmc_irq, cpu) = -1;
}
if (per_cpu(xen_ipi_irq, cpu) >= 0) {
unbind_from_irqhandler(per_cpu(xen_ipi_irq, cpu), NULL);
per_cpu(xen_ipi_irq, cpu) = -1;
}
if (per_cpu(xen_resched_irq, cpu) >= 0) {
unbind_from_irqhandler(per_cpu(xen_resched_irq, cpu),
NULL);
per_cpu(xen_resched_irq, cpu) = -1;
}
if (per_cpu(xen_timer_irq, cpu) >= 0) {
unbind_from_irqhandler(per_cpu(xen_timer_irq, cpu),
NULL);
per_cpu(xen_timer_irq, cpu) = -1;
}
}
return NOTIFY_OK;
}
void xen_smp_intr_init_early(unsigned int cpu)
{
#ifdef CONFIG_SMP
unsigned int i;
for (i = 0; i < saved_irq_cnt; i++)
__xen_register_percpu_irq(cpu, saved_percpu_irqs[i].irq,
saved_percpu_irqs[i].action, 0);
#endif
}
void xen_smp_intr_init(void)
{
#ifdef CONFIG_SMP
unsigned int cpu = smp_processor_id();
struct callback_register event = {
.type = CALLBACKTYPE_event,
.address = { .ip = (unsigned long)&xen_event_callback },
};
if (cpu == 0) {
#ifdef CONFIG_HOTPLUG_CPU
register_cpu_notifier(&unbind_evtchn_notifier);
#endif
return;
}
BUG_ON(HYPERVISOR_callback_op(CALLBACKOP_register, &event));
#endif
}
void __init
xen_irq_init(void)
{
struct callback_register event = {
.type = CALLBACKTYPE_event,
.address = { .ip = (unsigned long)&xen_event_callback },
};
xen_init_IRQ();
BUG_ON(HYPERVISOR_callback_op(CALLBACKOP_register, &event));
late_time_init = xen_bind_early_percpu_irq;
}
void
xen_platform_send_ipi(int cpu, int vector, int delivery_mode, int redirect)
{
#ifdef CONFIG_SMP
if (unlikely(vector == ap_wakeup_vector)) {
xen_smp_intr_init_early(cpu);
xen_send_ipi(cpu, vector);
return;
}
#endif
switch (vector) {
case IA64_IPI_VECTOR:
xen_send_IPI_one(cpu, XEN_IPI_VECTOR);
break;
case IA64_IPI_RESCHEDULE:
xen_send_IPI_one(cpu, XEN_RESCHEDULE_VECTOR);
break;
case IA64_CMCP_VECTOR:
xen_send_IPI_one(cpu, XEN_CMCP_VECTOR);
break;
case IA64_CPEP_VECTOR:
xen_send_IPI_one(cpu, XEN_CPEP_VECTOR);
break;
case IA64_TIMER_VECTOR: {
static int used = 0;
if (!used) {
xen_send_ipi(cpu, IA64_TIMER_VECTOR);
used = 1;
break;
}
}
default:
printk(KERN_WARNING "Unsupported IPI type 0x%x\n",
vector);
notify_remote_via_irq(0);
break;
}
}
static void __init
xen_register_ipi(void)
{
#ifdef CONFIG_SMP
register_percpu_irq(IA64_IPI_VECTOR, &xen_ipi_irqaction);
register_percpu_irq(IA64_IPI_RESCHEDULE, &xen_resched_irqaction);
register_percpu_irq(IA64_IPI_LOCAL_TLB_FLUSH, &xen_tlb_irqaction);
#endif
}
static void
xen_resend_irq(unsigned int vector)
{
(void)resend_irq_on_evtchn(vector);
}
