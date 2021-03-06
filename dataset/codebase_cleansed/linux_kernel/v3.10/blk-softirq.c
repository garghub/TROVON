static void blk_done_softirq(struct softirq_action *h)
{
struct list_head *cpu_list, local_list;
local_irq_disable();
cpu_list = &__get_cpu_var(blk_cpu_done);
list_replace_init(cpu_list, &local_list);
local_irq_enable();
while (!list_empty(&local_list)) {
struct request *rq;
rq = list_entry(local_list.next, struct request, csd.list);
list_del_init(&rq->csd.list);
rq->q->softirq_done_fn(rq);
}
}
static void trigger_softirq(void *data)
{
struct request *rq = data;
unsigned long flags;
struct list_head *list;
local_irq_save(flags);
list = &__get_cpu_var(blk_cpu_done);
list_add_tail(&rq->csd.list, list);
if (list->next == &rq->csd.list)
raise_softirq_irqoff(BLOCK_SOFTIRQ);
local_irq_restore(flags);
}
static int raise_blk_irq(int cpu, struct request *rq)
{
if (cpu_online(cpu)) {
struct call_single_data *data = &rq->csd;
data->func = trigger_softirq;
data->info = rq;
data->flags = 0;
__smp_call_function_single(cpu, data, 0);
return 0;
}
return 1;
}
static int raise_blk_irq(int cpu, struct request *rq)
{
return 1;
}
static int __cpuinit blk_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_DEAD || action == CPU_DEAD_FROZEN) {
int cpu = (unsigned long) hcpu;
local_irq_disable();
list_splice_init(&per_cpu(blk_cpu_done, cpu),
&__get_cpu_var(blk_cpu_done));
raise_softirq_irqoff(BLOCK_SOFTIRQ);
local_irq_enable();
}
return NOTIFY_OK;
}
void __blk_complete_request(struct request *req)
{
int ccpu, cpu;
struct request_queue *q = req->q;
unsigned long flags;
bool shared = false;
BUG_ON(!q->softirq_done_fn);
local_irq_save(flags);
cpu = smp_processor_id();
if (req->cpu != -1) {
ccpu = req->cpu;
if (!test_bit(QUEUE_FLAG_SAME_FORCE, &q->queue_flags))
shared = cpus_share_cache(cpu, ccpu);
} else
ccpu = cpu;
if (ccpu == cpu || shared) {
struct list_head *list;
do_local:
list = &__get_cpu_var(blk_cpu_done);
list_add_tail(&req->csd.list, list);
if (list->next == &req->csd.list)
raise_softirq_irqoff(BLOCK_SOFTIRQ);
} else if (raise_blk_irq(ccpu, req))
goto do_local;
local_irq_restore(flags);
}
void blk_complete_request(struct request *req)
{
if (unlikely(blk_should_fake_timeout(req->q)))
return;
if (!blk_mark_rq_complete(req))
__blk_complete_request(req);
}
static __init int blk_softirq_init(void)
{
int i;
for_each_possible_cpu(i)
INIT_LIST_HEAD(&per_cpu(blk_cpu_done, i));
open_softirq(BLOCK_SOFTIRQ, blk_done_softirq);
register_hotcpu_notifier(&blk_cpu_notifier);
return 0;
}
