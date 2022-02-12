static int blk_mq_main_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long) hcpu;
struct blk_mq_cpu_notifier *notify;
spin_lock(&blk_mq_cpu_notify_lock);
list_for_each_entry(notify, &blk_mq_cpu_notify_list, list)
notify->notify(notify->data, action, cpu);
spin_unlock(&blk_mq_cpu_notify_lock);
return NOTIFY_OK;
}
static void blk_mq_cpu_notify(void *data, unsigned long action,
unsigned int cpu)
{
if (action == CPU_DEAD || action == CPU_DEAD_FROZEN) {
struct llist_node *node;
struct request *rq;
local_irq_disable();
node = llist_del_all(&per_cpu(ipi_lists, cpu));
while (node) {
struct llist_node *next = node->next;
rq = llist_entry(node, struct request, ll_list);
__blk_mq_end_io(rq, rq->errors);
node = next;
}
local_irq_enable();
}
}
void blk_mq_register_cpu_notifier(struct blk_mq_cpu_notifier *notifier)
{
BUG_ON(!notifier->notify);
spin_lock(&blk_mq_cpu_notify_lock);
list_add_tail(&notifier->list, &blk_mq_cpu_notify_list);
spin_unlock(&blk_mq_cpu_notify_lock);
}
void blk_mq_unregister_cpu_notifier(struct blk_mq_cpu_notifier *notifier)
{
spin_lock(&blk_mq_cpu_notify_lock);
list_del(&notifier->list);
spin_unlock(&blk_mq_cpu_notify_lock);
}
void blk_mq_init_cpu_notifier(struct blk_mq_cpu_notifier *notifier,
void (*fn)(void *, unsigned long, unsigned int),
void *data)
{
notifier->notify = fn;
notifier->data = data;
}
void __init blk_mq_cpu_init(void)
{
register_hotcpu_notifier(&blk_mq_main_cpu_notifier);
blk_mq_register_cpu_notifier(&cpu_notifier);
}
