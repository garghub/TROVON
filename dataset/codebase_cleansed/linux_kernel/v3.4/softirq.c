static void wakeup_softirqd(void)
{
struct task_struct *tsk = __this_cpu_read(ksoftirqd);
if (tsk && tsk->state != TASK_RUNNING)
wake_up_process(tsk);
}
static void __local_bh_disable(unsigned long ip, unsigned int cnt)
{
unsigned long flags;
WARN_ON_ONCE(in_irq());
raw_local_irq_save(flags);
preempt_count() += cnt;
if (softirq_count() == cnt)
trace_softirqs_off(ip);
raw_local_irq_restore(flags);
if (preempt_count() == cnt)
trace_preempt_off(CALLER_ADDR0, get_parent_ip(CALLER_ADDR1));
}
static inline void __local_bh_disable(unsigned long ip, unsigned int cnt)
{
add_preempt_count(cnt);
barrier();
}
void local_bh_disable(void)
{
__local_bh_disable((unsigned long)__builtin_return_address(0),
SOFTIRQ_DISABLE_OFFSET);
}
static void __local_bh_enable(unsigned int cnt)
{
WARN_ON_ONCE(in_irq());
WARN_ON_ONCE(!irqs_disabled());
if (softirq_count() == cnt)
trace_softirqs_on((unsigned long)__builtin_return_address(0));
sub_preempt_count(cnt);
}
void _local_bh_enable(void)
{
__local_bh_enable(SOFTIRQ_DISABLE_OFFSET);
}
static inline void _local_bh_enable_ip(unsigned long ip)
{
WARN_ON_ONCE(in_irq() || irqs_disabled());
#ifdef CONFIG_TRACE_IRQFLAGS
local_irq_disable();
#endif
if (softirq_count() == SOFTIRQ_DISABLE_OFFSET)
trace_softirqs_on(ip);
sub_preempt_count(SOFTIRQ_DISABLE_OFFSET - 1);
if (unlikely(!in_interrupt() && local_softirq_pending()))
do_softirq();
dec_preempt_count();
#ifdef CONFIG_TRACE_IRQFLAGS
local_irq_enable();
#endif
preempt_check_resched();
}
void local_bh_enable(void)
{
_local_bh_enable_ip((unsigned long)__builtin_return_address(0));
}
void local_bh_enable_ip(unsigned long ip)
{
_local_bh_enable_ip(ip);
}
asmlinkage void __do_softirq(void)
{
struct softirq_action *h;
__u32 pending;
int max_restart = MAX_SOFTIRQ_RESTART;
int cpu;
pending = local_softirq_pending();
account_system_vtime(current);
__local_bh_disable((unsigned long)__builtin_return_address(0),
SOFTIRQ_OFFSET);
lockdep_softirq_enter();
cpu = smp_processor_id();
restart:
set_softirq_pending(0);
local_irq_enable();
h = softirq_vec;
do {
if (pending & 1) {
unsigned int vec_nr = h - softirq_vec;
int prev_count = preempt_count();
kstat_incr_softirqs_this_cpu(vec_nr);
trace_softirq_entry(vec_nr);
h->action(h);
trace_softirq_exit(vec_nr);
if (unlikely(prev_count != preempt_count())) {
printk(KERN_ERR "huh, entered softirq %u %s %p"
"with preempt_count %08x,"
" exited with %08x?\n", vec_nr,
softirq_to_name[vec_nr], h->action,
prev_count, preempt_count());
preempt_count() = prev_count;
}
rcu_bh_qs(cpu);
}
h++;
pending >>= 1;
} while (pending);
local_irq_disable();
pending = local_softirq_pending();
if (pending && --max_restart)
goto restart;
if (pending)
wakeup_softirqd();
lockdep_softirq_exit();
account_system_vtime(current);
__local_bh_enable(SOFTIRQ_OFFSET);
}
asmlinkage void do_softirq(void)
{
__u32 pending;
unsigned long flags;
if (in_interrupt())
return;
local_irq_save(flags);
pending = local_softirq_pending();
if (pending)
__do_softirq();
local_irq_restore(flags);
}
void irq_enter(void)
{
int cpu = smp_processor_id();
rcu_irq_enter();
if (is_idle_task(current) && !in_interrupt()) {
local_bh_disable();
tick_check_idle(cpu);
_local_bh_enable();
}
__irq_enter();
}
static inline void invoke_softirq(void)
{
if (!force_irqthreads) {
#ifdef __ARCH_IRQ_EXIT_IRQS_DISABLED
__do_softirq();
#else
do_softirq();
#endif
} else {
__local_bh_disable((unsigned long)__builtin_return_address(0),
SOFTIRQ_OFFSET);
wakeup_softirqd();
__local_bh_enable(SOFTIRQ_OFFSET);
}
}
void irq_exit(void)
{
account_system_vtime(current);
trace_hardirq_exit();
sub_preempt_count(IRQ_EXIT_OFFSET);
if (!in_interrupt() && local_softirq_pending())
invoke_softirq();
#ifdef CONFIG_NO_HZ
if (idle_cpu(smp_processor_id()) && !in_interrupt() && !need_resched())
tick_nohz_irq_exit();
#endif
rcu_irq_exit();
sched_preempt_enable_no_resched();
}
inline void raise_softirq_irqoff(unsigned int nr)
{
__raise_softirq_irqoff(nr);
if (!in_interrupt())
wakeup_softirqd();
}
void raise_softirq(unsigned int nr)
{
unsigned long flags;
local_irq_save(flags);
raise_softirq_irqoff(nr);
local_irq_restore(flags);
}
void __raise_softirq_irqoff(unsigned int nr)
{
trace_softirq_raise(nr);
or_softirq_pending(1UL << nr);
}
void open_softirq(int nr, void (*action)(struct softirq_action *))
{
softirq_vec[nr].action = action;
}
void __tasklet_schedule(struct tasklet_struct *t)
{
unsigned long flags;
local_irq_save(flags);
t->next = NULL;
*__this_cpu_read(tasklet_vec.tail) = t;
__this_cpu_write(tasklet_vec.tail, &(t->next));
raise_softirq_irqoff(TASKLET_SOFTIRQ);
local_irq_restore(flags);
}
void __tasklet_hi_schedule(struct tasklet_struct *t)
{
unsigned long flags;
local_irq_save(flags);
t->next = NULL;
*__this_cpu_read(tasklet_hi_vec.tail) = t;
__this_cpu_write(tasklet_hi_vec.tail, &(t->next));
raise_softirq_irqoff(HI_SOFTIRQ);
local_irq_restore(flags);
}
void __tasklet_hi_schedule_first(struct tasklet_struct *t)
{
BUG_ON(!irqs_disabled());
t->next = __this_cpu_read(tasklet_hi_vec.head);
__this_cpu_write(tasklet_hi_vec.head, t);
__raise_softirq_irqoff(HI_SOFTIRQ);
}
static void tasklet_action(struct softirq_action *a)
{
struct tasklet_struct *list;
local_irq_disable();
list = __this_cpu_read(tasklet_vec.head);
__this_cpu_write(tasklet_vec.head, NULL);
__this_cpu_write(tasklet_vec.tail, &__get_cpu_var(tasklet_vec).head);
local_irq_enable();
while (list) {
struct tasklet_struct *t = list;
list = list->next;
if (tasklet_trylock(t)) {
if (!atomic_read(&t->count)) {
if (!test_and_clear_bit(TASKLET_STATE_SCHED, &t->state))
BUG();
t->func(t->data);
tasklet_unlock(t);
continue;
}
tasklet_unlock(t);
}
local_irq_disable();
t->next = NULL;
*__this_cpu_read(tasklet_vec.tail) = t;
__this_cpu_write(tasklet_vec.tail, &(t->next));
__raise_softirq_irqoff(TASKLET_SOFTIRQ);
local_irq_enable();
}
}
static void tasklet_hi_action(struct softirq_action *a)
{
struct tasklet_struct *list;
local_irq_disable();
list = __this_cpu_read(tasklet_hi_vec.head);
__this_cpu_write(tasklet_hi_vec.head, NULL);
__this_cpu_write(tasklet_hi_vec.tail, &__get_cpu_var(tasklet_hi_vec).head);
local_irq_enable();
while (list) {
struct tasklet_struct *t = list;
list = list->next;
if (tasklet_trylock(t)) {
if (!atomic_read(&t->count)) {
if (!test_and_clear_bit(TASKLET_STATE_SCHED, &t->state))
BUG();
t->func(t->data);
tasklet_unlock(t);
continue;
}
tasklet_unlock(t);
}
local_irq_disable();
t->next = NULL;
*__this_cpu_read(tasklet_hi_vec.tail) = t;
__this_cpu_write(tasklet_hi_vec.tail, &(t->next));
__raise_softirq_irqoff(HI_SOFTIRQ);
local_irq_enable();
}
}
void tasklet_init(struct tasklet_struct *t,
void (*func)(unsigned long), unsigned long data)
{
t->next = NULL;
t->state = 0;
atomic_set(&t->count, 0);
t->func = func;
t->data = data;
}
void tasklet_kill(struct tasklet_struct *t)
{
if (in_interrupt())
printk("Attempt to kill tasklet from interrupt\n");
while (test_and_set_bit(TASKLET_STATE_SCHED, &t->state)) {
do {
yield();
} while (test_bit(TASKLET_STATE_SCHED, &t->state));
}
tasklet_unlock_wait(t);
clear_bit(TASKLET_STATE_SCHED, &t->state);
}
static enum hrtimer_restart __hrtimer_tasklet_trampoline(struct hrtimer *timer)
{
struct tasklet_hrtimer *ttimer =
container_of(timer, struct tasklet_hrtimer, timer);
tasklet_hi_schedule(&ttimer->tasklet);
return HRTIMER_NORESTART;
}
static void __tasklet_hrtimer_trampoline(unsigned long data)
{
struct tasklet_hrtimer *ttimer = (void *)data;
enum hrtimer_restart restart;
restart = ttimer->function(&ttimer->timer);
if (restart != HRTIMER_NORESTART)
hrtimer_restart(&ttimer->timer);
}
static void __local_trigger(struct call_single_data *cp, int softirq)
{
struct list_head *head = &__get_cpu_var(softirq_work_list[softirq]);
list_add_tail(&cp->list, head);
if (head->next == &cp->list)
raise_softirq_irqoff(softirq);
}
static void remote_softirq_receive(void *data)
{
struct call_single_data *cp = data;
unsigned long flags;
int softirq;
softirq = cp->priv;
local_irq_save(flags);
__local_trigger(cp, softirq);
local_irq_restore(flags);
}
static int __try_remote_softirq(struct call_single_data *cp, int cpu, int softirq)
{
if (cpu_online(cpu)) {
cp->func = remote_softirq_receive;
cp->info = cp;
cp->flags = 0;
cp->priv = softirq;
__smp_call_function_single(cpu, cp, 0);
return 0;
}
return 1;
}
static int __try_remote_softirq(struct call_single_data *cp, int cpu, int softirq)
{
return 1;
}
void __send_remote_softirq(struct call_single_data *cp, int cpu, int this_cpu, int softirq)
{
if (cpu == this_cpu || __try_remote_softirq(cp, cpu, softirq))
__local_trigger(cp, softirq);
}
void send_remote_softirq(struct call_single_data *cp, int cpu, int softirq)
{
unsigned long flags;
int this_cpu;
local_irq_save(flags);
this_cpu = smp_processor_id();
__send_remote_softirq(cp, cpu, this_cpu, softirq);
local_irq_restore(flags);
}
static int __cpuinit remote_softirq_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
if (action == CPU_DEAD || action == CPU_DEAD_FROZEN) {
int cpu = (unsigned long) hcpu;
int i;
local_irq_disable();
for (i = 0; i < NR_SOFTIRQS; i++) {
struct list_head *head = &per_cpu(softirq_work_list[i], cpu);
struct list_head *local_head;
if (list_empty(head))
continue;
local_head = &__get_cpu_var(softirq_work_list[i]);
list_splice_init(head, local_head);
raise_softirq_irqoff(i);
}
local_irq_enable();
}
return NOTIFY_OK;
}
void __init softirq_init(void)
{
int cpu;
for_each_possible_cpu(cpu) {
int i;
per_cpu(tasklet_vec, cpu).tail =
&per_cpu(tasklet_vec, cpu).head;
per_cpu(tasklet_hi_vec, cpu).tail =
&per_cpu(tasklet_hi_vec, cpu).head;
for (i = 0; i < NR_SOFTIRQS; i++)
INIT_LIST_HEAD(&per_cpu(softirq_work_list[i], cpu));
}
register_hotcpu_notifier(&remote_softirq_cpu_notifier);
open_softirq(TASKLET_SOFTIRQ, tasklet_action);
open_softirq(HI_SOFTIRQ, tasklet_hi_action);
}
static int run_ksoftirqd(void * __bind_cpu)
{
set_current_state(TASK_INTERRUPTIBLE);
while (!kthread_should_stop()) {
preempt_disable();
if (!local_softirq_pending()) {
schedule_preempt_disabled();
}
__set_current_state(TASK_RUNNING);
while (local_softirq_pending()) {
if (cpu_is_offline((long)__bind_cpu))
goto wait_to_die;
local_irq_disable();
if (local_softirq_pending())
__do_softirq();
local_irq_enable();
sched_preempt_enable_no_resched();
cond_resched();
preempt_disable();
rcu_note_context_switch((long)__bind_cpu);
}
preempt_enable();
set_current_state(TASK_INTERRUPTIBLE);
}
__set_current_state(TASK_RUNNING);
return 0;
wait_to_die:
preempt_enable();
set_current_state(TASK_INTERRUPTIBLE);
while (!kthread_should_stop()) {
schedule();
set_current_state(TASK_INTERRUPTIBLE);
}
__set_current_state(TASK_RUNNING);
return 0;
}
void tasklet_kill_immediate(struct tasklet_struct *t, unsigned int cpu)
{
struct tasklet_struct **i;
BUG_ON(cpu_online(cpu));
BUG_ON(test_bit(TASKLET_STATE_RUN, &t->state));
if (!test_bit(TASKLET_STATE_SCHED, &t->state))
return;
for (i = &per_cpu(tasklet_vec, cpu).head; *i; i = &(*i)->next) {
if (*i == t) {
*i = t->next;
if (*i == NULL)
per_cpu(tasklet_vec, cpu).tail = i;
return;
}
}
BUG();
}
static void takeover_tasklets(unsigned int cpu)
{
local_irq_disable();
if (&per_cpu(tasklet_vec, cpu).head != per_cpu(tasklet_vec, cpu).tail) {
*__this_cpu_read(tasklet_vec.tail) = per_cpu(tasklet_vec, cpu).head;
this_cpu_write(tasklet_vec.tail, per_cpu(tasklet_vec, cpu).tail);
per_cpu(tasklet_vec, cpu).head = NULL;
per_cpu(tasklet_vec, cpu).tail = &per_cpu(tasklet_vec, cpu).head;
}
raise_softirq_irqoff(TASKLET_SOFTIRQ);
if (&per_cpu(tasklet_hi_vec, cpu).head != per_cpu(tasklet_hi_vec, cpu).tail) {
*__this_cpu_read(tasklet_hi_vec.tail) = per_cpu(tasklet_hi_vec, cpu).head;
__this_cpu_write(tasklet_hi_vec.tail, per_cpu(tasklet_hi_vec, cpu).tail);
per_cpu(tasklet_hi_vec, cpu).head = NULL;
per_cpu(tasklet_hi_vec, cpu).tail = &per_cpu(tasklet_hi_vec, cpu).head;
}
raise_softirq_irqoff(HI_SOFTIRQ);
local_irq_enable();
}
static int __cpuinit cpu_callback(struct notifier_block *nfb,
unsigned long action,
void *hcpu)
{
int hotcpu = (unsigned long)hcpu;
struct task_struct *p;
switch (action) {
case CPU_UP_PREPARE:
case CPU_UP_PREPARE_FROZEN:
p = kthread_create_on_node(run_ksoftirqd,
hcpu,
cpu_to_node(hotcpu),
"ksoftirqd/%d", hotcpu);
if (IS_ERR(p)) {
printk("ksoftirqd for %i failed\n", hotcpu);
return notifier_from_errno(PTR_ERR(p));
}
kthread_bind(p, hotcpu);
per_cpu(ksoftirqd, hotcpu) = p;
break;
case CPU_ONLINE:
case CPU_ONLINE_FROZEN:
wake_up_process(per_cpu(ksoftirqd, hotcpu));
break;
#ifdef CONFIG_HOTPLUG_CPU
case CPU_UP_CANCELED:
case CPU_UP_CANCELED_FROZEN:
if (!per_cpu(ksoftirqd, hotcpu))
break;
kthread_bind(per_cpu(ksoftirqd, hotcpu),
cpumask_any(cpu_online_mask));
case CPU_DEAD:
case CPU_DEAD_FROZEN: {
static const struct sched_param param = {
.sched_priority = MAX_RT_PRIO-1
};
p = per_cpu(ksoftirqd, hotcpu);
per_cpu(ksoftirqd, hotcpu) = NULL;
sched_setscheduler_nocheck(p, SCHED_FIFO, &param);
kthread_stop(p);
takeover_tasklets(hotcpu);
break;
}
#endif
}
return NOTIFY_OK;
}
static __init int spawn_ksoftirqd(void)
{
void *cpu = (void *)(long)smp_processor_id();
int err = cpu_callback(&cpu_nfb, CPU_UP_PREPARE, cpu);
BUG_ON(err != NOTIFY_OK);
cpu_callback(&cpu_nfb, CPU_ONLINE, cpu);
register_cpu_notifier(&cpu_nfb);
return 0;
}
int __init __weak early_irq_init(void)
{
return 0;
}
int __init __weak arch_probe_nr_irqs(void)
{
return NR_IRQS_LEGACY;
}
int __init __weak arch_early_irq_init(void)
{
return 0;
}
