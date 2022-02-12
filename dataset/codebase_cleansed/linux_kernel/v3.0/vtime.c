static inline __u64 get_vtimer(void)
{
__u64 timer;
asm volatile("STPT %0" : "=m" (timer));
return timer;
}
static inline void set_vtimer(__u64 expires)
{
__u64 timer;
asm volatile (" STPT %0\n"
" SPT %1"
: "=m" (timer) : "m" (expires) );
S390_lowcore.system_timer += S390_lowcore.last_update_timer - timer;
S390_lowcore.last_update_timer = expires;
}
static void do_account_vtime(struct task_struct *tsk, int hardirq_offset)
{
struct thread_info *ti = task_thread_info(tsk);
__u64 timer, clock, user, system, steal;
timer = S390_lowcore.last_update_timer;
clock = S390_lowcore.last_update_clock;
asm volatile (" STPT %0\n"
" STCK %1"
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock) );
S390_lowcore.system_timer += timer - S390_lowcore.last_update_timer;
S390_lowcore.steal_timer += S390_lowcore.last_update_clock - clock;
user = S390_lowcore.user_timer - ti->user_timer;
S390_lowcore.steal_timer -= user;
ti->user_timer = S390_lowcore.user_timer;
account_user_time(tsk, user, user);
system = S390_lowcore.system_timer - ti->system_timer;
S390_lowcore.steal_timer -= system;
ti->system_timer = S390_lowcore.system_timer;
account_system_time(tsk, hardirq_offset, system, system);
steal = S390_lowcore.steal_timer;
if ((s64) steal > 0) {
S390_lowcore.steal_timer = 0;
account_steal_time(steal);
}
}
void account_vtime(struct task_struct *prev, struct task_struct *next)
{
struct thread_info *ti;
do_account_vtime(prev, 0);
ti = task_thread_info(prev);
ti->user_timer = S390_lowcore.user_timer;
ti->system_timer = S390_lowcore.system_timer;
ti = task_thread_info(next);
S390_lowcore.user_timer = ti->user_timer;
S390_lowcore.system_timer = ti->system_timer;
}
void account_process_tick(struct task_struct *tsk, int user_tick)
{
do_account_vtime(tsk, HARDIRQ_OFFSET);
}
void account_system_vtime(struct task_struct *tsk)
{
struct thread_info *ti = task_thread_info(tsk);
__u64 timer, system;
timer = S390_lowcore.last_update_timer;
S390_lowcore.last_update_timer = get_vtimer();
S390_lowcore.system_timer += timer - S390_lowcore.last_update_timer;
system = S390_lowcore.system_timer - ti->system_timer;
S390_lowcore.steal_timer -= system;
ti->system_timer = S390_lowcore.system_timer;
account_system_time(tsk, 0, system, system);
}
void __kprobes vtime_start_cpu(__u64 int_clock, __u64 enter_timer)
{
struct s390_idle_data *idle = &__get_cpu_var(s390_idle);
struct vtimer_queue *vq = &__get_cpu_var(virt_cpu_timer);
__u64 idle_time, expires;
if (idle->idle_enter == 0ULL)
return;
idle_time = int_clock - idle->idle_enter;
account_idle_time(idle_time);
S390_lowcore.steal_timer +=
idle->idle_enter - S390_lowcore.last_update_clock;
S390_lowcore.last_update_clock = int_clock;
S390_lowcore.system_timer += S390_lowcore.last_update_timer - vq->idle;
S390_lowcore.last_update_timer = enter_timer;
if (vq->do_spt) {
expires = vq->idle - enter_timer;
expires += get_vtimer();
set_vtimer(expires);
} else {
vq->elapsed -= vq->idle - enter_timer;
}
idle->sequence++;
smp_wmb();
idle->idle_time += idle_time;
idle->idle_enter = 0ULL;
idle->idle_count++;
smp_wmb();
idle->sequence++;
}
void __kprobes vtime_stop_cpu(void)
{
struct s390_idle_data *idle = &__get_cpu_var(s390_idle);
struct vtimer_queue *vq = &__get_cpu_var(virt_cpu_timer);
psw_t psw;
psw.mask = psw_kernel_bits | PSW_MASK_WAIT | PSW_MASK_IO | PSW_MASK_EXT;
idle->nohz_delay = 0;
if (vq->do_spt) {
__u64 vmax = VTIMER_MAX_SLICE;
asm volatile(
#ifndef CONFIG_64BIT
" basr 1,0\n"
"0: ahi 1,1f-0b\n"
" st 1,4(%2)\n"
#else
" larl 1,1f\n"
" stg 1,8(%2)\n"
#endif
" stpt 0(%4)\n"
" spt 0(%5)\n"
" stck 0(%3)\n"
#ifndef CONFIG_64BIT
" lpsw 0(%2)\n"
#else
" lpswe 0(%2)\n"
#endif
"1:"
: "=m" (idle->idle_enter), "=m" (vq->idle)
: "a" (&psw), "a" (&idle->idle_enter),
"a" (&vq->idle), "a" (&vmax), "m" (vmax), "m" (psw)
: "memory", "cc", "1");
} else {
asm volatile(
#ifndef CONFIG_64BIT
" basr 1,0\n"
"0: ahi 1,1f-0b\n"
" st 1,4(%2)\n"
#else
" larl 1,1f\n"
" stg 1,8(%2)\n"
#endif
" stpt 0(%4)\n"
" stck 0(%3)\n"
#ifndef CONFIG_64BIT
" lpsw 0(%2)\n"
#else
" lpswe 0(%2)\n"
#endif
"1:"
: "=m" (idle->idle_enter), "=m" (vq->idle)
: "a" (&psw), "a" (&idle->idle_enter),
"a" (&vq->idle), "m" (psw)
: "memory", "cc", "1");
}
}
cputime64_t s390_get_idle_time(int cpu)
{
struct s390_idle_data *idle;
unsigned long long now, idle_time, idle_enter;
unsigned int sequence;
idle = &per_cpu(s390_idle, cpu);
now = get_clock();
repeat:
sequence = idle->sequence;
smp_rmb();
if (sequence & 1)
goto repeat;
idle_time = 0;
idle_enter = idle->idle_enter;
if (idle_enter != 0ULL && idle_enter < now)
idle_time = now - idle_enter;
smp_rmb();
if (idle->sequence != sequence)
goto repeat;
return idle_time;
}
static void list_add_sorted(struct vtimer_list *timer, struct list_head *head)
{
struct vtimer_list *event;
list_for_each_entry(event, head, entry) {
if (event->expires > timer->expires) {
list_add_tail(&timer->entry, &event->entry);
return;
}
}
list_add_tail(&timer->entry, head);
}
static void do_callbacks(struct list_head *cb_list)
{
struct vtimer_queue *vq;
struct vtimer_list *event, *tmp;
if (list_empty(cb_list))
return;
vq = &__get_cpu_var(virt_cpu_timer);
list_for_each_entry_safe(event, tmp, cb_list, entry) {
list_del_init(&event->entry);
(event->function)(event->data);
if (event->interval) {
event->expires = event->interval + vq->elapsed;
spin_lock(&vq->lock);
list_add_sorted(event, &vq->list);
spin_unlock(&vq->lock);
}
}
}
static void do_cpu_timer_interrupt(unsigned int ext_int_code,
unsigned int param32, unsigned long param64)
{
struct vtimer_queue *vq;
struct vtimer_list *event, *tmp;
struct list_head cb_list;
__u64 elapsed, next;
kstat_cpu(smp_processor_id()).irqs[EXTINT_TMR]++;
INIT_LIST_HEAD(&cb_list);
vq = &__get_cpu_var(virt_cpu_timer);
spin_lock(&vq->lock);
elapsed = vq->elapsed + (vq->timer - S390_lowcore.async_enter_timer);
BUG_ON((s64) elapsed < 0);
vq->elapsed = 0;
list_for_each_entry_safe(event, tmp, &vq->list, entry) {
if (event->expires < elapsed)
list_move_tail(&event->entry, &cb_list);
else
event->expires -= elapsed;
}
spin_unlock(&vq->lock);
vq->do_spt = list_empty(&cb_list);
do_callbacks(&cb_list);
next = VTIMER_MAX_SLICE;
spin_lock(&vq->lock);
if (!list_empty(&vq->list)) {
event = list_first_entry(&vq->list, struct vtimer_list, entry);
next = event->expires;
} else
vq->do_spt = 0;
spin_unlock(&vq->lock);
elapsed = S390_lowcore.async_enter_timer - get_vtimer();
set_vtimer(next - elapsed);
vq->timer = next - elapsed;
vq->elapsed = elapsed;
}
void init_virt_timer(struct vtimer_list *timer)
{
timer->function = NULL;
INIT_LIST_HEAD(&timer->entry);
}
static inline int vtimer_pending(struct vtimer_list *timer)
{
return (!list_empty(&timer->entry));
}
static void internal_add_vtimer(struct vtimer_list *timer)
{
struct vtimer_queue *vq;
unsigned long flags;
__u64 left, expires;
vq = &per_cpu(virt_cpu_timer, timer->cpu);
spin_lock_irqsave(&vq->lock, flags);
BUG_ON(timer->cpu != smp_processor_id());
if (list_empty(&vq->list)) {
list_add(&timer->entry, &vq->list);
set_vtimer(timer->expires);
vq->timer = timer->expires;
vq->elapsed = 0;
} else {
expires = timer->expires;
left = get_vtimer();
if (likely((s64) expires < (s64) left)) {
set_vtimer(expires);
vq->elapsed += vq->timer - left;
vq->timer = expires;
} else {
vq->elapsed += vq->timer - left;
vq->timer = left;
}
timer->expires += vq->elapsed;
list_add_sorted(timer, &vq->list);
}
spin_unlock_irqrestore(&vq->lock, flags);
put_cpu();
}
static inline void prepare_vtimer(struct vtimer_list *timer)
{
BUG_ON(!timer->function);
BUG_ON(!timer->expires || timer->expires > VTIMER_MAX_SLICE);
BUG_ON(vtimer_pending(timer));
timer->cpu = get_cpu();
}
void add_virt_timer(void *new)
{
struct vtimer_list *timer;
timer = (struct vtimer_list *)new;
prepare_vtimer(timer);
timer->interval = 0;
internal_add_vtimer(timer);
}
void add_virt_timer_periodic(void *new)
{
struct vtimer_list *timer;
timer = (struct vtimer_list *)new;
prepare_vtimer(timer);
timer->interval = timer->expires;
internal_add_vtimer(timer);
}
int __mod_vtimer(struct vtimer_list *timer, __u64 expires, int periodic)
{
struct vtimer_queue *vq;
unsigned long flags;
int cpu;
BUG_ON(!timer->function);
BUG_ON(!expires || expires > VTIMER_MAX_SLICE);
if (timer->expires == expires && vtimer_pending(timer))
return 1;
cpu = get_cpu();
vq = &per_cpu(virt_cpu_timer, cpu);
spin_lock_irqsave(&vq->lock, flags);
if (!vtimer_pending(timer)) {
spin_unlock_irqrestore(&vq->lock, flags);
if (periodic)
timer->interval = expires;
else
timer->interval = 0;
timer->expires = expires;
timer->cpu = cpu;
internal_add_vtimer(timer);
return 0;
}
BUG_ON(timer->cpu != cpu);
list_del_init(&timer->entry);
timer->expires = expires;
if (periodic)
timer->interval = expires;
spin_unlock_irqrestore(&vq->lock, flags);
internal_add_vtimer(timer);
return 1;
}
int mod_virt_timer(struct vtimer_list *timer, __u64 expires)
{
return __mod_vtimer(timer, expires, 0);
}
int mod_virt_timer_periodic(struct vtimer_list *timer, __u64 expires)
{
return __mod_vtimer(timer, expires, 1);
}
int del_virt_timer(struct vtimer_list *timer)
{
unsigned long flags;
struct vtimer_queue *vq;
if (!vtimer_pending(timer))
return 0;
vq = &per_cpu(virt_cpu_timer, timer->cpu);
spin_lock_irqsave(&vq->lock, flags);
list_del_init(&timer->entry);
spin_unlock_irqrestore(&vq->lock, flags);
return 1;
}
void init_cpu_vtimer(void)
{
struct vtimer_queue *vq;
vq = &__get_cpu_var(virt_cpu_timer);
INIT_LIST_HEAD(&vq->list);
spin_lock_init(&vq->lock);
__ctl_set_bit(0,10);
}
static int __cpuinit s390_nohz_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
struct s390_idle_data *idle;
long cpu = (long) hcpu;
idle = &per_cpu(s390_idle, cpu);
switch (action) {
case CPU_DYING:
case CPU_DYING_FROZEN:
idle->nohz_delay = 0;
default:
break;
}
return NOTIFY_OK;
}
void __init vtime_init(void)
{
if (register_external_interrupt(0x1005, do_cpu_timer_interrupt))
panic("Couldn't request external interrupt 0x1005");
init_cpu_vtimer();
cpu_notifier(s390_nohz_notify, 0);
}
