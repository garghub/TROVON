static inline void closure_put_after_sub(struct closure *cl, int flags)
{
int r = flags & CLOSURE_REMAINING_MASK;
BUG_ON(flags & CLOSURE_GUARD_MASK);
BUG_ON(!r && (flags & ~CLOSURE_DESTRUCTOR));
if (r == 1 && (flags & CLOSURE_SLEEPING))
wake_up_process(cl->task);
if (!r) {
if (cl->fn && !(flags & CLOSURE_DESTRUCTOR)) {
atomic_set(&cl->remaining,
CLOSURE_REMAINING_INITIALIZER);
closure_queue(cl);
} else {
struct closure *parent = cl->parent;
closure_fn *destructor = cl->fn;
closure_debug_destroy(cl);
if (destructor)
destructor(cl);
if (parent)
closure_put(parent);
}
}
}
void closure_sub(struct closure *cl, int v)
{
closure_put_after_sub(cl, atomic_sub_return(v, &cl->remaining));
}
void closure_put(struct closure *cl)
{
closure_put_after_sub(cl, atomic_dec_return(&cl->remaining));
}
void __closure_wake_up(struct closure_waitlist *wait_list)
{
struct llist_node *list;
struct closure *cl, *t;
struct llist_node *reverse = NULL;
list = llist_del_all(&wait_list->list);
reverse = llist_reverse_order(list);
llist_for_each_entry_safe(cl, t, reverse, list) {
closure_set_waiting(cl, 0);
closure_sub(cl, CLOSURE_WAITING + 1);
}
}
bool closure_wait(struct closure_waitlist *waitlist, struct closure *cl)
{
if (atomic_read(&cl->remaining) & CLOSURE_WAITING)
return false;
closure_set_waiting(cl, _RET_IP_);
atomic_add(CLOSURE_WAITING + 1, &cl->remaining);
llist_add(&cl->list, &waitlist->list);
return true;
}
void closure_sync(struct closure *cl)
{
while (1) {
__closure_start_sleep(cl);
closure_set_ret_ip(cl);
if ((atomic_read(&cl->remaining) &
CLOSURE_REMAINING_MASK) == 1)
break;
schedule();
}
__closure_end_sleep(cl);
}
void closure_debug_create(struct closure *cl)
{
unsigned long flags;
BUG_ON(cl->magic == CLOSURE_MAGIC_ALIVE);
cl->magic = CLOSURE_MAGIC_ALIVE;
spin_lock_irqsave(&closure_list_lock, flags);
list_add(&cl->all, &closure_list);
spin_unlock_irqrestore(&closure_list_lock, flags);
}
void closure_debug_destroy(struct closure *cl)
{
unsigned long flags;
BUG_ON(cl->magic != CLOSURE_MAGIC_ALIVE);
cl->magic = CLOSURE_MAGIC_DEAD;
spin_lock_irqsave(&closure_list_lock, flags);
list_del(&cl->all);
spin_unlock_irqrestore(&closure_list_lock, flags);
}
static int debug_seq_show(struct seq_file *f, void *data)
{
struct closure *cl;
spin_lock_irq(&closure_list_lock);
list_for_each_entry(cl, &closure_list, all) {
int r = atomic_read(&cl->remaining);
seq_printf(f, "%p: %pF -> %pf p %p r %i ",
cl, (void *) cl->ip, cl->fn, cl->parent,
r & CLOSURE_REMAINING_MASK);
seq_printf(f, "%s%s%s%s\n",
test_bit(WORK_STRUCT_PENDING_BIT,
work_data_bits(&cl->work)) ? "Q" : "",
r & CLOSURE_RUNNING ? "R" : "",
r & CLOSURE_STACK ? "S" : "",
r & CLOSURE_SLEEPING ? "Sl" : "");
if (r & CLOSURE_WAITING)
seq_printf(f, " W %pF\n",
(void *) cl->waiting_on);
seq_printf(f, "\n");
}
spin_unlock_irq(&closure_list_lock);
return 0;
}
static int debug_seq_open(struct inode *inode, struct file *file)
{
return single_open(file, debug_seq_show, NULL);
}
void __init closure_debug_init(void)
{
debug = debugfs_create_file("closures", 0400, NULL, NULL, &debug_ops);
}
