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
bool irq_work_queue_on(struct irq_work *work, int cpu)
{
WARN_ON_ONCE(cpu_is_offline(cpu));
WARN_ON_ONCE(in_nmi());
if (!irq_work_claim(work))
return false;
if (llist_add(&work->llnode, &per_cpu(raised_list, cpu)))
arch_send_call_function_single_ipi(cpu);
return true;
}
bool irq_work_queue(struct irq_work *work)
{
if (!irq_work_claim(work))
return false;
preempt_disable();
if (work->flags & IRQ_WORK_LAZY) {
if (llist_add(&work->llnode, this_cpu_ptr(&lazy_list)) &&
tick_nohz_tick_stopped())
arch_irq_work_raise();
} else {
if (llist_add(&work->llnode, this_cpu_ptr(&raised_list)))
arch_irq_work_raise();
}
preempt_enable();
return true;
}
bool irq_work_needs_cpu(void)
{
struct llist_head *raised, *lazy;
raised = this_cpu_ptr(&raised_list);
lazy = this_cpu_ptr(&lazy_list);
if (llist_empty(raised) || arch_irq_work_has_interrupt())
if (llist_empty(lazy))
return false;
WARN_ON_ONCE(cpu_is_offline(smp_processor_id()));
return true;
}
static void irq_work_run_list(struct llist_head *list)
{
unsigned long flags;
struct irq_work *work;
struct llist_node *llnode;
BUG_ON(!irqs_disabled());
if (llist_empty(list))
return;
llnode = llist_del_all(list);
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
irq_work_run_list(this_cpu_ptr(&raised_list));
irq_work_run_list(this_cpu_ptr(&lazy_list));
}
void irq_work_tick(void)
{
struct llist_head *raised = this_cpu_ptr(&raised_list);
if (!llist_empty(raised) && !arch_irq_work_has_interrupt())
irq_work_run_list(raised);
irq_work_run_list(this_cpu_ptr(&lazy_list));
}
void irq_work_sync(struct irq_work *work)
{
WARN_ON_ONCE(irqs_disabled());
while (work->flags & IRQ_WORK_BUSY)
cpu_relax();
}
