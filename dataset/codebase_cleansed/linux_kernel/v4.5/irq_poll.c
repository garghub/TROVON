void irq_poll_sched(struct irq_poll *iop)
{
unsigned long flags;
if (test_bit(IRQ_POLL_F_DISABLE, &iop->state))
return;
if (test_and_set_bit(IRQ_POLL_F_SCHED, &iop->state))
return;
local_irq_save(flags);
list_add_tail(&iop->list, this_cpu_ptr(&blk_cpu_iopoll));
__raise_softirq_irqoff(IRQ_POLL_SOFTIRQ);
local_irq_restore(flags);
}
static void __irq_poll_complete(struct irq_poll *iop)
{
list_del(&iop->list);
smp_mb__before_atomic();
clear_bit_unlock(IRQ_POLL_F_SCHED, &iop->state);
}
void irq_poll_complete(struct irq_poll *iop)
{
unsigned long flags;
local_irq_save(flags);
__irq_poll_complete(iop);
local_irq_restore(flags);
}
static void irq_poll_softirq(struct softirq_action *h)
{
struct list_head *list = this_cpu_ptr(&blk_cpu_iopoll);
int rearm = 0, budget = irq_poll_budget;
unsigned long start_time = jiffies;
local_irq_disable();
while (!list_empty(list)) {
struct irq_poll *iop;
int work, weight;
if (budget <= 0 || time_after(jiffies, start_time)) {
rearm = 1;
break;
}
local_irq_enable();
iop = list_entry(list->next, struct irq_poll, list);
weight = iop->weight;
work = 0;
if (test_bit(IRQ_POLL_F_SCHED, &iop->state))
work = iop->poll(iop, weight);
budget -= work;
local_irq_disable();
if (work >= weight) {
if (test_bit(IRQ_POLL_F_DISABLE, &iop->state))
__irq_poll_complete(iop);
else
list_move_tail(&iop->list, list);
}
}
if (rearm)
__raise_softirq_irqoff(IRQ_POLL_SOFTIRQ);
local_irq_enable();
}
void irq_poll_disable(struct irq_poll *iop)
{
set_bit(IRQ_POLL_F_DISABLE, &iop->state);
while (test_and_set_bit(IRQ_POLL_F_SCHED, &iop->state))
msleep(1);
clear_bit(IRQ_POLL_F_DISABLE, &iop->state);
}
void irq_poll_enable(struct irq_poll *iop)
{
BUG_ON(!test_bit(IRQ_POLL_F_SCHED, &iop->state));
smp_mb__before_atomic();
clear_bit_unlock(IRQ_POLL_F_SCHED, &iop->state);
}
void irq_poll_init(struct irq_poll *iop, int weight, irq_poll_fn *poll_fn)
{
memset(iop, 0, sizeof(*iop));
INIT_LIST_HEAD(&iop->list);
iop->weight = weight;
iop->poll = poll_fn;
}
static int irq_poll_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_DEAD || action == CPU_DEAD_FROZEN) {
int cpu = (unsigned long) hcpu;
local_irq_disable();
list_splice_init(&per_cpu(blk_cpu_iopoll, cpu),
this_cpu_ptr(&blk_cpu_iopoll));
__raise_softirq_irqoff(IRQ_POLL_SOFTIRQ);
local_irq_enable();
}
return NOTIFY_OK;
}
static __init int irq_poll_setup(void)
{
int i;
for_each_possible_cpu(i)
INIT_LIST_HEAD(&per_cpu(blk_cpu_iopoll, i));
open_softirq(IRQ_POLL_SOFTIRQ, irq_poll_softirq);
register_hotcpu_notifier(&irq_poll_cpu_notifier);
return 0;
}
