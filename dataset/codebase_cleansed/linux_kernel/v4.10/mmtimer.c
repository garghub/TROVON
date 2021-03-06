static int mmtimer_int_pending(int comparator)
{
if (HUB_L((unsigned long *)LOCAL_MMR_ADDR(SH_EVENT_OCCURRED)) &
SH_EVENT_OCCURRED_RTC1_INT_MASK << comparator)
return 1;
else
return 0;
}
static void mmtimer_clr_int_pending(int comparator)
{
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_EVENT_OCCURRED_ALIAS),
SH_EVENT_OCCURRED_RTC1_INT_MASK << comparator);
}
static void mmtimer_setup_int_0(int cpu, u64 expires)
{
u64 val;
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC1_INT_ENABLE), 0UL);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_INT_CMPB), -1L);
mmtimer_clr_int_pending(0);
val = ((u64)SGI_MMTIMER_VECTOR << SH_RTC1_INT_CONFIG_IDX_SHFT) |
((u64)cpu_physical_id(cpu) <<
SH_RTC1_INT_CONFIG_PID_SHFT);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC1_INT_CONFIG), val);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC1_INT_ENABLE), 1UL);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_INT_CMPB), expires);
}
static void mmtimer_setup_int_1(int cpu, u64 expires)
{
u64 val;
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC2_INT_ENABLE), 0UL);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_INT_CMPC), -1L);
mmtimer_clr_int_pending(1);
val = ((u64)SGI_MMTIMER_VECTOR << SH_RTC2_INT_CONFIG_IDX_SHFT) |
((u64)cpu_physical_id(cpu) <<
SH_RTC2_INT_CONFIG_PID_SHFT);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC2_INT_CONFIG), val);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC2_INT_ENABLE), 1UL);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_INT_CMPC), expires);
}
static void mmtimer_setup_int_2(int cpu, u64 expires)
{
u64 val;
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC3_INT_ENABLE), 0UL);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_INT_CMPD), -1L);
mmtimer_clr_int_pending(2);
val = ((u64)SGI_MMTIMER_VECTOR << SH_RTC3_INT_CONFIG_IDX_SHFT) |
((u64)cpu_physical_id(cpu) <<
SH_RTC3_INT_CONFIG_PID_SHFT);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC3_INT_CONFIG), val);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC3_INT_ENABLE), 1UL);
HUB_S((u64 *)LOCAL_MMR_ADDR(SH_INT_CMPD), expires);
}
static int mmtimer_setup(int cpu, int comparator, unsigned long expires,
u64 *set_completion_time)
{
switch (comparator) {
case 0:
mmtimer_setup_int_0(cpu, expires);
break;
case 1:
mmtimer_setup_int_1(cpu, expires);
break;
case 2:
mmtimer_setup_int_2(cpu, expires);
break;
}
*set_completion_time = rtc_time();
if (*set_completion_time <= expires)
return 1;
return mmtimer_int_pending(comparator);
}
static int mmtimer_disable_int(long nasid, int comparator)
{
switch (comparator) {
case 0:
nasid == -1 ? HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC1_INT_ENABLE),
0UL) : REMOTE_HUB_S(nasid, SH_RTC1_INT_ENABLE, 0UL);
break;
case 1:
nasid == -1 ? HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC2_INT_ENABLE),
0UL) : REMOTE_HUB_S(nasid, SH_RTC2_INT_ENABLE, 0UL);
break;
case 2:
nasid == -1 ? HUB_S((u64 *)LOCAL_MMR_ADDR(SH_RTC3_INT_ENABLE),
0UL) : REMOTE_HUB_S(nasid, SH_RTC3_INT_ENABLE, 0UL);
break;
default:
return -EFAULT;
}
return 0;
}
static void mmtimer_add_list(struct mmtimer *n)
{
int nodeid = n->timer->it.mmtimer.node;
unsigned long expires = n->timer->it.mmtimer.expires;
struct rb_node **link = &timers[nodeid].timer_head.rb_node;
struct rb_node *parent = NULL;
struct mmtimer *x;
while (*link) {
parent = *link;
x = rb_entry(parent, struct mmtimer, list);
if (expires < x->timer->it.mmtimer.expires)
link = &(*link)->rb_left;
else
link = &(*link)->rb_right;
}
rb_link_node(&n->list, parent, link);
rb_insert_color(&n->list, &timers[nodeid].timer_head);
if (!timers[nodeid].next || expires < rb_entry(timers[nodeid].next,
struct mmtimer, list)->timer->it.mmtimer.expires)
timers[nodeid].next = &n->list;
}
static void mmtimer_set_next_timer(int nodeid)
{
struct mmtimer_node *n = &timers[nodeid];
struct mmtimer *x;
struct k_itimer *t;
u64 expires, exp, set_completion_time;
int i;
restart:
if (n->next == NULL)
return;
x = rb_entry(n->next, struct mmtimer, list);
t = x->timer;
if (!t->it.mmtimer.incr) {
if (!mmtimer_setup(x->cpu, COMPARATOR,
t->it.mmtimer.expires,
&set_completion_time)) {
tasklet_schedule(&n->tasklet);
}
return;
}
i = 0;
expires = exp = t->it.mmtimer.expires;
while (!mmtimer_setup(x->cpu, COMPARATOR, expires,
&set_completion_time)) {
int to;
i++;
expires = set_completion_time +
mmtimer_interval_retry_increment + (1 << i);
to = ((u64)(expires - exp) / t->it.mmtimer.incr);
if (to) {
t->it_overrun += to;
t->it.mmtimer.expires += t->it.mmtimer.incr * to;
exp = t->it.mmtimer.expires;
}
if (i > 20) {
printk(KERN_ALERT "mmtimer: cannot reschedule timer\n");
t->it.mmtimer.clock = TIMER_OFF;
n->next = rb_next(&x->list);
rb_erase(&x->list, &n->timer_head);
kfree(x);
goto restart;
}
}
}
static long mmtimer_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int ret = 0;
mutex_lock(&mmtimer_mutex);
switch (cmd) {
case MMTIMER_GETOFFSET:
if(PAGE_SIZE <= (1 << 16))
ret = (((long)RTC_COUNTER_ADDR) & (PAGE_SIZE-1)) / 8;
else
ret = -ENOSYS;
break;
case MMTIMER_GETRES:
if(copy_to_user((unsigned long __user *)arg,
&mmtimer_femtoperiod, sizeof(unsigned long)))
ret = -EFAULT;
break;
case MMTIMER_GETFREQ:
if(copy_to_user((unsigned long __user *)arg,
&sn_rtc_cycles_per_second,
sizeof(unsigned long)))
ret = -EFAULT;
break;
case MMTIMER_GETBITS:
ret = RTC_BITS;
break;
case MMTIMER_MMAPAVAIL:
ret = (PAGE_SIZE <= (1 << 16)) ? 1 : 0;
break;
case MMTIMER_GETCOUNTER:
if(copy_to_user((unsigned long __user *)arg,
RTC_COUNTER_ADDR, sizeof(unsigned long)))
ret = -EFAULT;
break;
default:
ret = -ENOTTY;
break;
}
mutex_unlock(&mmtimer_mutex);
return ret;
}
static int mmtimer_mmap(struct file *file, struct vm_area_struct *vma)
{
unsigned long mmtimer_addr;
if (vma->vm_end - vma->vm_start != PAGE_SIZE)
return -EINVAL;
if (vma->vm_flags & VM_WRITE)
return -EPERM;
if (PAGE_SIZE > (1 << 16))
return -ENOSYS;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
mmtimer_addr = __pa(RTC_COUNTER_ADDR);
mmtimer_addr &= ~(PAGE_SIZE - 1);
mmtimer_addr &= 0xfffffffffffffffUL;
if (remap_pfn_range(vma, vma->vm_start, mmtimer_addr >> PAGE_SHIFT,
PAGE_SIZE, vma->vm_page_prot)) {
printk(KERN_ERR "remap_pfn_range failed in mmtimer.c\n");
return -EAGAIN;
}
return 0;
}
static int sgi_clock_get(clockid_t clockid, struct timespec *tp)
{
u64 nsec;
nsec = rtc_time() * sgi_clock_period
+ sgi_clock_offset.tv_nsec;
*tp = ns_to_timespec(nsec);
tp->tv_sec += sgi_clock_offset.tv_sec;
return 0;
}
static int sgi_clock_set(const clockid_t clockid, const struct timespec *tp)
{
u64 nsec;
u32 rem;
nsec = rtc_time() * sgi_clock_period;
sgi_clock_offset.tv_sec = tp->tv_sec - div_u64_rem(nsec, NSEC_PER_SEC, &rem);
if (rem <= tp->tv_nsec)
sgi_clock_offset.tv_nsec = tp->tv_sec - rem;
else {
sgi_clock_offset.tv_nsec = tp->tv_sec + NSEC_PER_SEC - rem;
sgi_clock_offset.tv_sec--;
}
return 0;
}
static irqreturn_t
mmtimer_interrupt(int irq, void *dev_id)
{
unsigned long expires = 0;
int result = IRQ_NONE;
unsigned indx = cpu_to_node(smp_processor_id());
struct mmtimer *base;
spin_lock(&timers[indx].lock);
base = rb_entry(timers[indx].next, struct mmtimer, list);
if (base == NULL) {
spin_unlock(&timers[indx].lock);
return result;
}
if (base->cpu == smp_processor_id()) {
if (base->timer)
expires = base->timer->it.mmtimer.expires;
if ((mmtimer_int_pending(COMPARATOR) > 0) ||
(expires && (expires <= rtc_time()))) {
mmtimer_clr_int_pending(COMPARATOR);
tasklet_schedule(&timers[indx].tasklet);
result = IRQ_HANDLED;
}
}
spin_unlock(&timers[indx].lock);
return result;
}
static void mmtimer_tasklet(unsigned long data)
{
int nodeid = data;
struct mmtimer_node *mn = &timers[nodeid];
struct mmtimer *x;
struct k_itimer *t;
unsigned long flags;
spin_lock_irqsave(&mn->lock, flags);
if (!mn->next)
goto out;
x = rb_entry(mn->next, struct mmtimer, list);
t = x->timer;
if (t->it.mmtimer.clock == TIMER_OFF)
goto out;
t->it_overrun = 0;
mn->next = rb_next(&x->list);
rb_erase(&x->list, &mn->timer_head);
if (posix_timer_event(t, 0) != 0)
t->it_overrun++;
if(t->it.mmtimer.incr) {
t->it.mmtimer.expires += t->it.mmtimer.incr;
mmtimer_add_list(x);
} else {
t->it.mmtimer.clock = TIMER_OFF;
t->it.mmtimer.expires = 0;
kfree(x);
}
mmtimer_set_next_timer(nodeid);
t->it_overrun_last = t->it_overrun;
out:
spin_unlock_irqrestore(&mn->lock, flags);
}
static int sgi_timer_create(struct k_itimer *timer)
{
timer->it.mmtimer.clock = TIMER_OFF;
return 0;
}
static int sgi_timer_del(struct k_itimer *timr)
{
cnodeid_t nodeid = timr->it.mmtimer.node;
unsigned long irqflags;
spin_lock_irqsave(&timers[nodeid].lock, irqflags);
if (timr->it.mmtimer.clock != TIMER_OFF) {
unsigned long expires = timr->it.mmtimer.expires;
struct rb_node *n = timers[nodeid].timer_head.rb_node;
struct mmtimer *uninitialized_var(t);
int r = 0;
timr->it.mmtimer.clock = TIMER_OFF;
timr->it.mmtimer.expires = 0;
while (n) {
t = rb_entry(n, struct mmtimer, list);
if (t->timer == timr)
break;
if (expires < t->timer->it.mmtimer.expires)
n = n->rb_left;
else
n = n->rb_right;
}
if (!n) {
spin_unlock_irqrestore(&timers[nodeid].lock, irqflags);
return 0;
}
if (timers[nodeid].next == n) {
timers[nodeid].next = rb_next(n);
r = 1;
}
rb_erase(n, &timers[nodeid].timer_head);
kfree(t);
if (r) {
mmtimer_disable_int(cnodeid_to_nasid(nodeid),
COMPARATOR);
mmtimer_set_next_timer(nodeid);
}
}
spin_unlock_irqrestore(&timers[nodeid].lock, irqflags);
return 0;
}
static void sgi_timer_get(struct k_itimer *timr, struct itimerspec *cur_setting)
{
if (timr->it.mmtimer.clock == TIMER_OFF) {
cur_setting->it_interval.tv_nsec = 0;
cur_setting->it_interval.tv_sec = 0;
cur_setting->it_value.tv_nsec = 0;
cur_setting->it_value.tv_sec =0;
return;
}
cur_setting->it_interval = ns_to_timespec(timr->it.mmtimer.incr * sgi_clock_period);
cur_setting->it_value = ns_to_timespec((timr->it.mmtimer.expires - rtc_time()) * sgi_clock_period);
}
static int sgi_timer_set(struct k_itimer *timr, int flags,
struct itimerspec * new_setting,
struct itimerspec * old_setting)
{
unsigned long when, period, irqflags;
int err = 0;
cnodeid_t nodeid;
struct mmtimer *base;
struct rb_node *n;
if (old_setting)
sgi_timer_get(timr, old_setting);
sgi_timer_del(timr);
when = timespec_to_ns(&new_setting->it_value);
period = timespec_to_ns(&new_setting->it_interval);
if (when == 0)
return 0;
base = kmalloc(sizeof(struct mmtimer), GFP_KERNEL);
if (base == NULL)
return -ENOMEM;
if (flags & TIMER_ABSTIME) {
struct timespec n;
unsigned long now;
getnstimeofday(&n);
now = timespec_to_ns(&n);
if (when > now)
when -= now;
else
when = 0;
}
when = (when + sgi_clock_period - 1) / sgi_clock_period + rtc_time();
period = (period + sgi_clock_period - 1) / sgi_clock_period;
preempt_disable();
nodeid = cpu_to_node(smp_processor_id());
spin_lock_irqsave(&timers[nodeid].lock, irqflags);
base->timer = timr;
base->cpu = smp_processor_id();
timr->it.mmtimer.clock = TIMER_SET;
timr->it.mmtimer.node = nodeid;
timr->it.mmtimer.incr = period;
timr->it.mmtimer.expires = when;
n = timers[nodeid].next;
mmtimer_add_list(base);
if (timers[nodeid].next == n) {
spin_unlock_irqrestore(&timers[nodeid].lock, irqflags);
preempt_enable();
return err;
}
if (n)
mmtimer_disable_int(cnodeid_to_nasid(nodeid), COMPARATOR);
mmtimer_set_next_timer(nodeid);
spin_unlock_irqrestore(&timers[nodeid].lock, irqflags);
preempt_enable();
return err;
}
static int sgi_clock_getres(const clockid_t which_clock, struct timespec *tp)
{
tp->tv_sec = 0;
tp->tv_nsec = sgi_clock_period;
return 0;
}
static int __init mmtimer_init(void)
{
cnodeid_t node, maxn = -1;
if (!ia64_platform_is("sn2"))
return 0;
if (sn_rtc_cycles_per_second < 100000) {
printk(KERN_ERR "%s: unable to determine clock frequency\n",
MMTIMER_NAME);
goto out1;
}
mmtimer_femtoperiod = ((unsigned long)1E15 + sn_rtc_cycles_per_second /
2) / sn_rtc_cycles_per_second;
if (request_irq(SGI_MMTIMER_VECTOR, mmtimer_interrupt, IRQF_PERCPU, MMTIMER_NAME, NULL)) {
printk(KERN_WARNING "%s: unable to allocate interrupt.",
MMTIMER_NAME);
goto out1;
}
if (misc_register(&mmtimer_miscdev)) {
printk(KERN_ERR "%s: failed to register device\n",
MMTIMER_NAME);
goto out2;
}
for_each_online_node(node) {
maxn = node;
}
maxn++;
timers = kzalloc(sizeof(struct mmtimer_node)*maxn, GFP_KERNEL);
if (!timers) {
printk(KERN_ERR "%s: failed to allocate memory for device\n",
MMTIMER_NAME);
goto out3;
}
for_each_online_node(node) {
spin_lock_init(&timers[node].lock);
tasklet_init(&timers[node].tasklet, mmtimer_tasklet,
(unsigned long) node);
}
sgi_clock_period = NSEC_PER_SEC / sn_rtc_cycles_per_second;
posix_timers_register_clock(CLOCK_SGI_CYCLE, &sgi_clock);
printk(KERN_INFO "%s: v%s, %ld MHz\n", MMTIMER_DESC, MMTIMER_VERSION,
sn_rtc_cycles_per_second/(unsigned long)1E6);
return 0;
out3:
misc_deregister(&mmtimer_miscdev);
out2:
free_irq(SGI_MMTIMER_VECTOR, NULL);
out1:
return -1;
}
