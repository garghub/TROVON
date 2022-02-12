static bool irq_work_claim(struct irq_work *work)
{
unsigned long flags, oflags, nflags;
flags = work->flags & ~IRQ_WORK_PENDING;
for (;;) {
nflags = flags | IRQ_WORK_FLAGS;
oflags = cmpxchg(&work->flags, flags, nflags);
if (oflags == flags)
break;
if (oflags & IRQ_WORK_PENDING)
return false;
flags = oflags;
cpu_relax();
}
return true;
}
void __weak arch_irq_work_raise(void)
{
}
bool irq_work_queue(struct irq_work *work)
{
if (!irq_work_claim(work))
return false;
preempt_disable();
llist_add(&work->llnode, &__get_cpu_var(irq_work_list));
if (!(work->flags & IRQ_WORK_LAZY) || tick_nohz_tick_stopped()) {
if (!this_cpu_cmpxchg(irq_work_raised, 0, 1))
arch_irq_work_raise();
}
preempt_enable();
return true;
}
bool irq_work_needs_cpu(void)
{
struct llist_head *this_list;
this_list = &__get_cpu_var(irq_work_list);
if (llist_empty(this_list))
return false;
WARN_ON_ONCE(cpu_is_offline(smp_processor_id()));
return true;
}
static void __irq_work_run(void)
{
unsigned long flags;
struct irq_work *work;
struct llist_head *this_list;
struct llist_node *llnode;
__this_cpu_write(irq_work_raised, 0);
barrier();
this_list = &__get_cpu_var(irq_work_list);
if (llist_empty(this_list))
return;
BUG_ON(!irqs_disabled());
llnode = llist_del_all(this_list);
while (llnode != NULL) {
work = llist_entry(llnode, struct irq_work, llnode);
llnode = llist_next(llnode);
flags = work->flags & ~IRQ_WORK_PENDING;
xchg(&work->flags, flags);
work->func(work);
(void)cmpxchg(&work->flags, flags, flags & ~IRQ_WORK_BUSY);
}
}
void irq_work_run(void)
{
BUG_ON(!in_irq());
__irq_work_run();
}
void irq_work_sync(struct irq_work *work)
{
WARN_ON_ONCE(irqs_disabled());
while (work->flags & IRQ_WORK_BUSY)
cpu_relax();
}
static int irq_work_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
long cpu = (long)hcpu;
switch (action) {
case CPU_DYING:
if (WARN_ON_ONCE(cpu != smp_processor_id()))
break;
__irq_work_run();
break;
default:
break;
}
return NOTIFY_OK;
}
static __init int irq_work_init_cpu_notifier(void)
{
cpu_notify.notifier_call = irq_work_cpu_notify;
cpu_notify.priority = 0;
register_cpu_notifier(&cpu_notify);
return 0;
}
