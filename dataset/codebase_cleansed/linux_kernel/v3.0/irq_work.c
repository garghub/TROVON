static inline bool irq_work_is_set(struct irq_work *entry, int flags)
{
return (unsigned long)entry->next & flags;
}
static inline struct irq_work *irq_work_next(struct irq_work *entry)
{
unsigned long next = (unsigned long)entry->next;
next &= ~IRQ_WORK_FLAGS;
return (struct irq_work *)next;
}
static inline struct irq_work *next_flags(struct irq_work *entry, int flags)
{
unsigned long next = (unsigned long)entry;
next |= flags;
return (struct irq_work *)next;
}
static bool irq_work_claim(struct irq_work *entry)
{
struct irq_work *next, *nflags;
do {
next = entry->next;
if ((unsigned long)next & IRQ_WORK_PENDING)
return false;
nflags = next_flags(next, IRQ_WORK_FLAGS);
} while (cmpxchg(&entry->next, next, nflags) != next);
return true;
}
void __weak arch_irq_work_raise(void)
{
}
static void __irq_work_queue(struct irq_work *entry)
{
struct irq_work *next;
preempt_disable();
do {
next = __this_cpu_read(irq_work_list);
entry->next = next_flags(next, IRQ_WORK_FLAGS);
} while (this_cpu_cmpxchg(irq_work_list, next, entry) != next);
if (!irq_work_next(entry))
arch_irq_work_raise();
preempt_enable();
}
bool irq_work_queue(struct irq_work *entry)
{
if (!irq_work_claim(entry)) {
return false;
}
__irq_work_queue(entry);
return true;
}
void irq_work_run(void)
{
struct irq_work *list;
if (this_cpu_read(irq_work_list) == NULL)
return;
BUG_ON(!in_irq());
BUG_ON(!irqs_disabled());
list = this_cpu_xchg(irq_work_list, NULL);
while (list != NULL) {
struct irq_work *entry = list;
list = irq_work_next(list);
entry->next = next_flags(NULL, IRQ_WORK_BUSY);
entry->func(entry);
(void)cmpxchg(&entry->next,
next_flags(NULL, IRQ_WORK_BUSY),
NULL);
}
}
void irq_work_sync(struct irq_work *entry)
{
WARN_ON_ONCE(irqs_disabled());
while (irq_work_is_set(entry, IRQ_WORK_BUSY))
cpu_relax();
}
