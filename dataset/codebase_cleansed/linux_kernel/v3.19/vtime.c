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
static int do_account_vtime(struct task_struct *tsk, int hardirq_offset)
{
struct thread_info *ti = task_thread_info(tsk);
u64 timer, clock, user, system, steal;
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
return virt_timer_forward(user + system);
}
void vtime_task_switch(struct task_struct *prev)
{
struct thread_info *ti;
do_account_vtime(prev, 0);
ti = task_thread_info(prev);
ti->user_timer = S390_lowcore.user_timer;
ti->system_timer = S390_lowcore.system_timer;
ti = task_thread_info(current);
S390_lowcore.user_timer = ti->user_timer;
S390_lowcore.system_timer = ti->system_timer;
}
void vtime_account_user(struct task_struct *tsk)
{
if (do_account_vtime(tsk, HARDIRQ_OFFSET))
virt_timer_expire();
}
void vtime_account_irq_enter(struct task_struct *tsk)
{
struct thread_info *ti = task_thread_info(tsk);
u64 timer, system;
timer = S390_lowcore.last_update_timer;
S390_lowcore.last_update_timer = get_vtimer();
S390_lowcore.system_timer += timer - S390_lowcore.last_update_timer;
system = S390_lowcore.system_timer - ti->system_timer;
S390_lowcore.steal_timer -= system;
ti->system_timer = S390_lowcore.system_timer;
account_system_time(tsk, 0, system, system);
virt_timer_forward(system);
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
}
