static void xen_qlock_kick(int cpu)
{
int irq = per_cpu(lock_kicker_irq, cpu);
if (irq == -1)
return;
xen_send_IPI_one(cpu, XEN_SPIN_UNLOCK_VECTOR);
}
static void xen_qlock_wait(u8 *byte, u8 val)
{
int irq = __this_cpu_read(lock_kicker_irq);
if (irq == -1)
return;
xen_clear_irq_pending(irq);
barrier();
if (READ_ONCE(*byte) != val)
return;
xen_poll_irq(irq);
}
static irqreturn_t dummy_handler(int irq, void *dev_id)
{
BUG();
return IRQ_HANDLED;
}
void xen_init_lock_cpu(int cpu)
{
int irq;
char *name;
if (!xen_pvspin)
return;
WARN(per_cpu(lock_kicker_irq, cpu) >= 0, "spinlock on CPU%d exists on IRQ%d!\n",
cpu, per_cpu(lock_kicker_irq, cpu));
name = kasprintf(GFP_KERNEL, "spinlock%d", cpu);
irq = bind_ipi_to_irqhandler(XEN_SPIN_UNLOCK_VECTOR,
cpu,
dummy_handler,
IRQF_PERCPU|IRQF_NOBALANCING,
name,
NULL);
if (irq >= 0) {
disable_irq(irq);
per_cpu(lock_kicker_irq, cpu) = irq;
per_cpu(irq_name, cpu) = name;
}
printk("cpu %d spinlock event irq %d\n", cpu, irq);
}
void xen_uninit_lock_cpu(int cpu)
{
if (!xen_pvspin)
return;
unbind_from_irqhandler(per_cpu(lock_kicker_irq, cpu), NULL);
per_cpu(lock_kicker_irq, cpu) = -1;
kfree(per_cpu(irq_name, cpu));
per_cpu(irq_name, cpu) = NULL;
}
void __init xen_init_spinlocks(void)
{
if (!xen_pvspin) {
printk(KERN_DEBUG "xen: PV spinlocks disabled\n");
return;
}
printk(KERN_DEBUG "xen: PV spinlocks enabled\n");
__pv_init_lock_hash();
pv_lock_ops.queued_spin_lock_slowpath = __pv_queued_spin_lock_slowpath;
pv_lock_ops.queued_spin_unlock = PV_CALLEE_SAVE(__pv_queued_spin_unlock);
pv_lock_ops.wait = xen_qlock_wait;
pv_lock_ops.kick = xen_qlock_kick;
pv_lock_ops.vcpu_is_preempted = PV_CALLEE_SAVE(xen_vcpu_stolen);
}
static __init int xen_parse_nopvspin(char *arg)
{
xen_pvspin = false;
return 0;
}
