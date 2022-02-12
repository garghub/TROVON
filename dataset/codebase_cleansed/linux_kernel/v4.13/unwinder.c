static struct unwinder *select_unwinder(void)
{
struct unwinder *best;
if (list_empty(&unwinder_list))
return NULL;
best = list_entry(unwinder_list.next, struct unwinder, list);
if (best == curr_unwinder)
return NULL;
return best;
}
static int unwinder_enqueue(struct unwinder *ops)
{
struct list_head *tmp, *entry = &unwinder_list;
list_for_each(tmp, &unwinder_list) {
struct unwinder *o;
o = list_entry(tmp, struct unwinder, list);
if (o == ops)
return -EBUSY;
if (o->rating >= ops->rating)
entry = tmp;
}
list_add(&ops->list, entry);
return 0;
}
int unwinder_register(struct unwinder *u)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&unwinder_lock, flags);
ret = unwinder_enqueue(u);
if (!ret)
curr_unwinder = select_unwinder();
spin_unlock_irqrestore(&unwinder_lock, flags);
return ret;
}
void unwind_stack(struct task_struct *task, struct pt_regs *regs,
unsigned long *sp, const struct stacktrace_ops *ops,
void *data)
{
unsigned long flags;
if (unwinder_faulted) {
spin_lock_irqsave(&unwinder_lock, flags);
if (unwinder_faulted && !list_is_singular(&unwinder_list)) {
list_del(&curr_unwinder->list);
curr_unwinder = select_unwinder();
unwinder_faulted = 0;
}
spin_unlock_irqrestore(&unwinder_lock, flags);
}
curr_unwinder->dump(task, regs, sp, ops, data);
}
