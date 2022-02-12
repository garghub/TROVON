static u32 *get_indicator(void)
{
int i;
for (i = 0; i < TIQDIO_NR_NONSHARED_IND; i++)
if (!atomic_read(&q_indicators[i].count)) {
atomic_set(&q_indicators[i].count, 1);
return &q_indicators[i].ind;
}
atomic_inc(&q_indicators[TIQDIO_SHARED_IND].count);
return &q_indicators[TIQDIO_SHARED_IND].ind;
}
static void put_indicator(u32 *addr)
{
int i;
if (!addr)
return;
i = ((unsigned long)addr - (unsigned long)q_indicators) /
sizeof(struct indicator_t);
atomic_dec(&q_indicators[i].count);
}
void tiqdio_add_input_queues(struct qdio_irq *irq_ptr)
{
mutex_lock(&tiq_list_lock);
list_add_rcu(&irq_ptr->input_qs[0]->entry, &tiq_list);
mutex_unlock(&tiq_list_lock);
xchg(irq_ptr->dsci, 1 << 7);
}
void tiqdio_remove_input_queues(struct qdio_irq *irq_ptr)
{
struct qdio_q *q;
q = irq_ptr->input_qs[0];
if (!q || !q->entry.prev || !q->entry.next)
return;
mutex_lock(&tiq_list_lock);
list_del_rcu(&q->entry);
mutex_unlock(&tiq_list_lock);
synchronize_rcu();
}
static inline int has_multiple_inq_on_dsci(struct qdio_irq *irq_ptr)
{
return irq_ptr->nr_input_qs > 1;
}
static inline int references_shared_dsci(struct qdio_irq *irq_ptr)
{
return irq_ptr->dsci == &q_indicators[TIQDIO_SHARED_IND].ind;
}
static inline int shared_ind(struct qdio_irq *irq_ptr)
{
return references_shared_dsci(irq_ptr) ||
has_multiple_inq_on_dsci(irq_ptr);
}
void clear_nonshared_ind(struct qdio_irq *irq_ptr)
{
if (!is_thinint_irq(irq_ptr))
return;
if (shared_ind(irq_ptr))
return;
xchg(irq_ptr->dsci, 0);
}
int test_nonshared_ind(struct qdio_irq *irq_ptr)
{
if (!is_thinint_irq(irq_ptr))
return 0;
if (shared_ind(irq_ptr))
return 0;
if (*irq_ptr->dsci)
return 1;
else
return 0;
}
static inline u32 clear_shared_ind(void)
{
if (!atomic_read(&q_indicators[TIQDIO_SHARED_IND].count))
return 0;
return xchg(&q_indicators[TIQDIO_SHARED_IND].ind, 0);
}
static inline void tiqdio_call_inq_handlers(struct qdio_irq *irq)
{
struct qdio_q *q;
int i;
if (!references_shared_dsci(irq) &&
has_multiple_inq_on_dsci(irq))
xchg(irq->dsci, 0);
for_each_input_queue(irq, q, i) {
if (q->u.in.queue_start_poll) {
if (test_and_set_bit(QDIO_QUEUE_IRQS_DISABLED,
&q->u.in.queue_irq_state)) {
qperf_inc(q, int_discarded);
continue;
}
q->u.in.queue_start_poll(irq->cdev, q->nr,
irq->int_parm);
} else {
if (!shared_ind(irq))
xchg(irq->dsci, 0);
tasklet_schedule(&q->tasklet);
}
}
}
static void tiqdio_thinint_handler(struct airq_struct *airq)
{
u32 si_used = clear_shared_ind();
struct qdio_q *q;
last_ai_time = S390_lowcore.int_clock;
inc_irq_stat(IRQIO_QAI);
rcu_read_lock();
list_for_each_entry_rcu(q, &tiq_list, entry) {
struct qdio_irq *irq;
irq = q->irq_ptr;
if (unlikely(references_shared_dsci(irq))) {
if (!si_used)
continue;
} else if (!*irq->dsci)
continue;
tiqdio_call_inq_handlers(irq);
qperf_inc(q, adapter_int);
}
rcu_read_unlock();
}
static int set_subchannel_ind(struct qdio_irq *irq_ptr, int reset)
{
struct chsc_scssc_area *scssc = (void *)irq_ptr->chsc_page;
u64 summary_indicator_addr, subchannel_indicator_addr;
int rc;
if (reset) {
summary_indicator_addr = 0;
subchannel_indicator_addr = 0;
} else {
summary_indicator_addr = virt_to_phys(tiqdio_airq.lsi_ptr);
subchannel_indicator_addr = virt_to_phys(irq_ptr->dsci);
}
rc = chsc_sadc(irq_ptr->schid, scssc, summary_indicator_addr,
subchannel_indicator_addr);
if (rc) {
DBF_ERROR("%4x SSI r:%4x", irq_ptr->schid.sch_no,
scssc->response.code);
goto out;
}
DBF_EVENT("setscind");
DBF_HEX(&summary_indicator_addr, sizeof(summary_indicator_addr));
DBF_HEX(&subchannel_indicator_addr, sizeof(subchannel_indicator_addr));
out:
return rc;
}
int __init tiqdio_allocate_memory(void)
{
q_indicators = kzalloc(sizeof(struct indicator_t) * TIQDIO_NR_INDICATORS,
GFP_KERNEL);
if (!q_indicators)
return -ENOMEM;
return 0;
}
void tiqdio_free_memory(void)
{
kfree(q_indicators);
}
int __init tiqdio_register_thinints(void)
{
int rc;
rc = register_adapter_interrupt(&tiqdio_airq);
if (rc) {
DBF_EVENT("RTI:%x", rc);
return rc;
}
return 0;
}
int qdio_establish_thinint(struct qdio_irq *irq_ptr)
{
if (!is_thinint_irq(irq_ptr))
return 0;
return set_subchannel_ind(irq_ptr, 0);
}
void qdio_setup_thinint(struct qdio_irq *irq_ptr)
{
if (!is_thinint_irq(irq_ptr))
return;
irq_ptr->dsci = get_indicator();
DBF_HEX(&irq_ptr->dsci, sizeof(void *));
}
void qdio_shutdown_thinint(struct qdio_irq *irq_ptr)
{
if (!is_thinint_irq(irq_ptr))
return;
set_subchannel_ind(irq_ptr, 1);
put_indicator(irq_ptr->dsci);
}
void __exit tiqdio_unregister_thinints(void)
{
WARN_ON(!list_empty(&tiq_list));
unregister_adapter_interrupt(&tiqdio_airq);
}
