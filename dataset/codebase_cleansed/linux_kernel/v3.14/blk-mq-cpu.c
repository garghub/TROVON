static int blk_mq_main_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned long) hcpu;
struct blk_mq_cpu_notifier *notify;
raw_spin_lock(&blk_mq_cpu_notify_lock);
list_for_each_entry(notify, &blk_mq_cpu_notify_list, list)
notify->notify(notify->data, action, cpu);
raw_spin_unlock(&blk_mq_cpu_notify_lock);
return NOTIFY_OK;
}
void blk_mq_register_cpu_notifier(struct blk_mq_cpu_notifier *notifier)
{
BUG_ON(!notifier->notify);
raw_spin_lock(&blk_mq_cpu_notify_lock);
list_add_tail(&notifier->list, &blk_mq_cpu_notify_list);
raw_spin_unlock(&blk_mq_cpu_notify_lock);
}
void blk_mq_unregister_cpu_notifier(struct blk_mq_cpu_notifier *notifier)
{
raw_spin_lock(&blk_mq_cpu_notify_lock);
list_del(&notifier->list);
raw_spin_unlock(&blk_mq_cpu_notify_lock);
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
hotcpu_notifier(blk_mq_main_cpu_notify, 0);
}
