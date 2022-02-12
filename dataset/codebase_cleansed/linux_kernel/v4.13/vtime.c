static inline u64 get_vtimer(void)
{
u64 timer;
asm volatile("stpt %0" : "=m" (timer));
return timer;
}
static inline void set_vtimer(u64 expires)
{
u64 timer;
asm volatile(
" stpt %0\n"
" spt %1"
: "=m" (timer) : "m" (expires));
S390_lowcore.system_timer += S390_lowcore.last_update_timer - timer;
S390_lowcore.last_update_timer = expires;
}
static inline int virt_timer_forward(u64 elapsed)
{
BUG_ON(!irqs_disabled());
if (list_empty(&virt_timer_list))
return 0;
elapsed = atomic64_add_return(elapsed, &virt_timer_elapsed);
return elapsed >= atomic64_read(&virt_timer_current);
}
static void update_mt_scaling(void)
{
u64 cycles_new[8], *cycles_old;
u64 delta, fac, mult, div;
int i;
stcctm5(smp_cpu_mtid + 1, cycles_new);
cycles_old = this_cpu_ptr(mt_cycles);
fac = 1;
mult = div = 0;
for (i = 0; i <= smp_cpu_mtid; i++) {
delta = cycles_new[i] - cycles_old[i];
div += delta;
mult *= i + 1;
mult += delta * fac;
fac *= i + 1;
}
div *= fac;
if (div > 0) {
__this_cpu_write(mt_scaling_mult, mult);
__this_cpu_write(mt_scaling_div, div);
memcpy(cycles_old, cycles_new,
sizeof(u64) * (smp_cpu_mtid + 1));
}
__this_cpu_write(mt_scaling_jiffies, jiffies_64);
}
static inline u64 update_tsk_timer(unsigned long *tsk_vtime, u64 new)
{
u64 delta;
delta = new - *tsk_vtime;
*tsk_vtime = new;
return delta;
}
static inline u64 scale_vtime(u64 vtime)
{
u64 mult = __this_cpu_read(mt_scaling_mult);
u64 div = __this_cpu_read(mt_scaling_div);
if (smp_cpu_mtid)
return vtime * mult / div;
return vtime;
}
static void account_system_index_scaled(struct task_struct *p, u64 cputime,
enum cpu_usage_stat index)
{
p->stimescaled += cputime_to_nsecs(scale_vtime(cputime));
account_system_index_time(p, cputime_to_nsecs(cputime), index);
}
static int do_account_vtime(struct task_struct *tsk)
{
u64 timer, clock, user, guest, system, hardirq, softirq, steal;
timer = S390_lowcore.last_update_timer;
clock = S390_lowcore.last_update_clock;
asm volatile(
" stpt %0\n"
#ifdef CONFIG_HAVE_MARCH_Z9_109_FEATURES
" stckf %1"
#else
" stck %1"
#endif
: "=m" (S390_lowcore.last_update_timer),
"=m" (S390_lowcore.last_update_clock));
clock = S390_lowcore.last_update_clock - clock;
timer -= S390_lowcore.last_update_timer;
if (hardirq_count())
S390_lowcore.hardirq_timer += timer;
else
S390_lowcore.system_timer += timer;
if (smp_cpu_mtid &&
time_after64(jiffies_64, this_cpu_read(mt_scaling_jiffies)))
update_mt_scaling();
user = update_tsk_timer(&tsk->thread.user_timer,
READ_ONCE(S390_lowcore.user_timer));
guest = update_tsk_timer(&tsk->thread.guest_timer,
READ_ONCE(S390_lowcore.guest_timer));
system = update_tsk_timer(&tsk->thread.system_timer,
READ_ONCE(S390_lowcore.system_timer));
hardirq = update_tsk_timer(&tsk->thread.hardirq_timer,
READ_ONCE(S390_lowcore.hardirq_timer));
softirq = update_tsk_timer(&tsk->thread.softirq_timer,
READ_ONCE(S390_lowcore.softirq_timer));
S390_lowcore.steal_timer +=
clock - user - guest - system - hardirq - softirq;
if (user) {
account_user_time(tsk, cputime_to_nsecs(user));
tsk->utimescaled += cputime_to_nsecs(scale_vtime(user));
}
if (guest) {
account_guest_time(tsk, cputime_to_nsecs(guest));
tsk->utimescaled += cputime_to_nsecs(scale_vtime(guest));
}
if (system)
account_system_index_scaled(tsk, system, CPUTIME_SYSTEM);
if (hardirq)
account_system_index_scaled(tsk, hardirq, CPUTIME_IRQ);
if (softirq)
account_system_index_scaled(tsk, softirq, CPUTIME_SOFTIRQ);
steal = S390_lowcore.steal_timer;
if ((s64) steal > 0) {
S390_lowcore.steal_timer = 0;
account_steal_time(cputime_to_nsecs(steal));
}
return virt_timer_forward(user + guest + system + hardirq + softirq);
}
void vtime_task_switch(struct task_struct *prev)
{
do_account_vtime(prev);
prev->thread.user_timer = S390_lowcore.user_timer;
prev->thread.guest_timer = S390_lowcore.guest_timer;
prev->thread.system_timer = S390_lowcore.system_timer;
prev->thread.hardirq_timer = S390_lowcore.hardirq_timer;
prev->thread.softirq_timer = S390_lowcore.softirq_timer;
S390_lowcore.user_timer = current->thread.user_timer;
S390_lowcore.guest_timer = current->thread.guest_timer;
S390_lowcore.system_timer = current->thread.system_timer;
S390_lowcore.hardirq_timer = current->thread.hardirq_timer;
S390_lowcore.softirq_timer = current->thread.softirq_timer;
}
void vtime_flush(struct task_struct *tsk)
{
if (do_account_vtime(tsk))
virt_timer_expire();
}
void vtime_account_irq_enter(struct task_struct *tsk)
{
u64 timer;
timer = S390_lowcore.last_update_timer;
S390_lowcore.last_update_timer = get_vtimer();
timer -= S390_lowcore.last_update_timer;
if ((tsk->flags & PF_VCPU) && (irq_count() == 0))
S390_lowcore.guest_timer += timer;
else if (hardirq_count())
S390_lowcore.hardirq_timer += timer;
else if (in_serving_softirq())
S390_lowcore.softirq_timer += timer;
else
S390_lowcore.system_timer += timer;
virt_timer_forward(timer);
}
static void list_add_sorted(struct vtimer_list *timer, struct list_head *head)
{
struct vtimer_list *tmp;
list_for_each_entry(tmp, head, entry) {
if (tmp->expires > timer->expires) {
list_add_tail(&timer->entry, &tmp->entry);
return;
}
}
list_add_tail(&timer->entry, head);
}
static void virt_timer_expire(void)
{
struct vtimer_list *timer, *tmp;
unsigned long elapsed;
LIST_HEAD(cb_list);
spin_lock(&virt_timer_lock);
elapsed = atomic64_read(&virt_timer_elapsed);
list_for_each_entry_safe(timer, tmp, &virt_timer_list, entry) {
if (timer->expires < elapsed)
list_move_tail(&timer->entry, &cb_list);
else
timer->expires -= elapsed;
}
if (!list_empty(&virt_timer_list)) {
timer = list_first_entry(&virt_timer_list,
struct vtimer_list, entry);
atomic64_set(&virt_timer_current, timer->expires);
}
atomic64_sub(elapsed, &virt_timer_elapsed);
spin_unlock(&virt_timer_lock);
list_for_each_entry_safe(timer, tmp, &cb_list, entry) {
list_del_init(&timer->entry);
timer->function(timer->data);
if (timer->interval) {
timer->expires = timer->interval +
atomic64_read(&virt_timer_elapsed);
spin_lock(&virt_timer_lock);
list_add_sorted(timer, &virt_timer_list);
spin_unlock(&virt_timer_lock);
}
}
}
void init_virt_timer(struct vtimer_list *timer)
{
timer->function = NULL;
INIT_LIST_HEAD(&timer->entry);
}
static inline int vtimer_pending(struct vtimer_list *timer)
{
return !list_empty(&timer->entry);
}
static void internal_add_vtimer(struct vtimer_list *timer)
{
if (list_empty(&virt_timer_list)) {
atomic64_set(&virt_timer_current, timer->expires);
atomic64_set(&virt_timer_elapsed, 0);
list_add(&timer->entry, &virt_timer_list);
} else {
timer->expires += atomic64_read(&virt_timer_elapsed);
if (likely((s64) timer->expires <
(s64) atomic64_read(&virt_timer_current)))
atomic64_set(&virt_timer_current, timer->expires);
list_add_sorted(timer, &virt_timer_list);
}
}
static void __add_vtimer(struct vtimer_list *timer, int periodic)
{
unsigned long flags;
timer->interval = periodic ? timer->expires : 0;
spin_lock_irqsave(&virt_timer_lock, flags);
internal_add_vtimer(timer);
spin_unlock_irqrestore(&virt_timer_lock, flags);
}
void add_virt_timer(struct vtimer_list *timer)
{
__add_vtimer(timer, 0);
}
void add_virt_timer_periodic(struct vtimer_list *timer)
{
__add_vtimer(timer, 1);
}
static int __mod_vtimer(struct vtimer_list *timer, u64 expires, int periodic)
{
unsigned long flags;
int rc;
BUG_ON(!timer->function);
if (timer->expires == expires && vtimer_pending(timer))
return 1;
spin_lock_irqsave(&virt_timer_lock, flags);
rc = vtimer_pending(timer);
if (rc)
list_del_init(&timer->entry);
timer->interval = periodic ? expires : 0;
timer->expires = expires;
internal_add_vtimer(timer);
spin_unlock_irqrestore(&virt_timer_lock, flags);
return rc;
}
int mod_virt_timer(struct vtimer_list *timer, u64 expires)
{
return __mod_vtimer(timer, expires, 0);
}
int mod_virt_timer_periodic(struct vtimer_list *timer, u64 expires)
{
return __mod_vtimer(timer, expires, 1);
}
int del_virt_timer(struct vtimer_list *timer)
{
unsigned long flags;
if (!vtimer_pending(timer))
return 0;
spin_lock_irqsave(&virt_timer_lock, flags);
list_del_init(&timer->entry);
spin_unlock_irqrestore(&virt_timer_lock, flags);
return 1;
}
void vtime_init(void)
{
set_vtimer(VTIMER_MAX_SLICE);
if (smp_cpu_mtid) {
__this_cpu_write(mt_scaling_jiffies, jiffies);
__this_cpu_write(mt_scaling_mult, 1);
__this_cpu_write(mt_scaling_div, 1);
stcctm5(smp_cpu_mtid + 1, this_cpu_ptr(mt_cycles));
}
}
