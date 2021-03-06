static bool irq_work_claim(struct irq_work *work)
{
unsigned long flags, nflags;
for (;;) {
flags = work->flags;
if (flags & IRQ_WORK_PENDING)
return false;
nflags = flags | IRQ_WORK_FLAGS;
if (cmpxchg(&work->flags, flags, nflags) == flags)
break;
cpu_relax();
}
return true;
}
void __weak arch_irq_work_raise(void)
{
}
static void __irq_work_queue(struct irq_work *work)
{
bool empty;
preempt_disable();
empty = llist_add(&work->llnode, &__get_cpu_var(irq_work_list));
if (empty)
arch_irq_work_raise();
preempt_enable();
}
bool irq_work_queue(struct irq_work *work)
{
if (!irq_work_claim(work)) {
return false;
}
__irq_work_queue(work);
return true;
}
void irq_work_run(void)
{
struct irq_work *work;
struct llist_head *this_list;
struct llist_node *llnode;
this_list = &__get_cpu_var(irq_work_list);
if (llist_empty(this_list))
return;
BUG_ON(!in_irq());
BUG_ON(!irqs_disabled());
llnode = llist_del_all(this_list);
while (llnode != NULL) {
work = llist_entry(llnode, struct irq_work, llnode);
llnode = llist_next(llnode);
work->flags = IRQ_WORK_BUSY;
work->func(work);
(void)cmpxchg(&work->flags, IRQ_WORK_BUSY, 0);
}
}
void irq_work_sync(struct irq_work *work)
{
WARN_ON_ONCE(irqs_disabled());
while (work->flags & IRQ_WORK_BUSY)
cpu_relax();
}
