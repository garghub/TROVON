static inline void check_zero(void)
{
u8 ret;
u8 old = ACCESS_ONCE(zero_stats);
if (unlikely(old)) {
ret = cmpxchg(&zero_stats, old, 0);
if (ret == old)
memset(&spinlock_stats, 0, sizeof(spinlock_stats));
}
}
static inline void add_stats(enum xen_contention_stat var, u32 val)
{
check_zero();
spinlock_stats.contention_stats[var] += val;
}
static inline u64 spin_time_start(void)
{
return xen_clocksource_read();
}
static void __spin_time_accum(u64 delta, u32 *array)
{
unsigned index = ilog2(delta);
check_zero();
if (index < HISTO_BUCKETS)
array[index]++;
else
array[HISTO_BUCKETS]++;
}
static inline void spin_time_accum_blocked(u64 start)
{
u32 delta = xen_clocksource_read() - start;
__spin_time_accum(delta, spinlock_stats.histo_spin_blocked);
spinlock_stats.time_blocked += delta;
}
static inline void add_stats(enum xen_contention_stat var, u32 val)
{
}
static inline u64 spin_time_start(void)
{
return 0;
}
static inline void spin_time_accum_blocked(u64 start)
{
}
__visible void xen_lock_spinning(struct arch_spinlock *lock, __ticket_t want)
{
int irq = __this_cpu_read(lock_kicker_irq);
struct xen_lock_waiting *w = &__get_cpu_var(lock_waiting);
int cpu = smp_processor_id();
u64 start;
unsigned long flags;
if (irq == -1)
return;
start = spin_time_start();
local_irq_save(flags);
w->lock = NULL;
smp_wmb();
w->want = want;
smp_wmb();
w->lock = lock;
cpumask_set_cpu(cpu, &waiting_cpus);
add_stats(TAKEN_SLOW, 1);
xen_clear_irq_pending(irq);
barrier();
__ticket_enter_slowpath(lock);
if (ACCESS_ONCE(lock->tickets.head) == want) {
add_stats(TAKEN_SLOW_PICKUP, 1);
goto out;
}
local_irq_restore(flags);
xen_poll_irq(irq);
add_stats(TAKEN_SLOW_SPURIOUS, !xen_test_irq_pending(irq));
local_irq_save(flags);
kstat_incr_irq_this_cpu(irq);
out:
cpumask_clear_cpu(cpu, &waiting_cpus);
w->lock = NULL;
local_irq_restore(flags);
spin_time_accum_blocked(start);
}
static void xen_unlock_kick(struct arch_spinlock *lock, __ticket_t next)
{
int cpu;
add_stats(RELEASED_SLOW, 1);
for_each_cpu(cpu, &waiting_cpus) {
const struct xen_lock_waiting *w = &per_cpu(lock_waiting, cpu);
if (ACCESS_ONCE(w->lock) == lock &&
ACCESS_ONCE(w->want) == next) {
add_stats(RELEASED_SLOW_KICKED, 1);
xen_send_IPI_one(cpu, XEN_SPIN_UNLOCK_VECTOR);
break;
}
}
}
static irqreturn_t dummy_handler(int irq, void *dev_id)
{
BUG();
return IRQ_HANDLED;
}
void xen_init_lock_cpu(int cpu)
{
int irq;
char *name;
if (!xen_pvspin)
return;
WARN(per_cpu(lock_kicker_irq, cpu) >= 0, "spinlock on CPU%d exists on IRQ%d!\n",
cpu, per_cpu(lock_kicker_irq, cpu));
name = kasprintf(GFP_KERNEL, "spinlock%d", cpu);
irq = bind_ipi_to_irqhandler(XEN_SPIN_UNLOCK_VECTOR,
cpu,
dummy_handler,
IRQF_PERCPU|IRQF_NOBALANCING,
name,
NULL);
if (irq >= 0) {
disable_irq(irq);
per_cpu(lock_kicker_irq, cpu) = irq;
per_cpu(irq_name, cpu) = name;
}
printk("cpu %d spinlock event irq %d\n", cpu, irq);
}
void xen_uninit_lock_cpu(int cpu)
{
if (!xen_pvspin)
return;
unbind_from_irqhandler(per_cpu(lock_kicker_irq, cpu), NULL);
per_cpu(lock_kicker_irq, cpu) = -1;
kfree(per_cpu(irq_name, cpu));
per_cpu(irq_name, cpu) = NULL;
}
void __init xen_init_spinlocks(void)
{
if (!xen_pvspin) {
printk(KERN_DEBUG "xen: PV spinlocks disabled\n");
return;
}
printk(KERN_DEBUG "xen: PV spinlocks enabled\n");
pv_lock_ops.lock_spinning = PV_CALLEE_SAVE(xen_lock_spinning);
pv_lock_ops.unlock_kick = xen_unlock_kick;
}
static __init int xen_init_spinlocks_jump(void)
{
if (!xen_pvspin)
return 0;
if (!xen_domain())
return 0;
static_key_slow_inc(&paravirt_ticketlocks_enabled);
return 0;
}
static __init int xen_parse_nopvspin(char *arg)
{
xen_pvspin = false;
return 0;
}
static int __init xen_spinlock_debugfs(void)
{
struct dentry *d_xen = xen_init_debugfs();
if (d_xen == NULL)
return -ENOMEM;
if (!xen_pvspin)
return 0;
d_spin_debug = debugfs_create_dir("spinlocks", d_xen);
debugfs_create_u8("zero_stats", 0644, d_spin_debug, &zero_stats);
debugfs_create_u32("taken_slow", 0444, d_spin_debug,
&spinlock_stats.contention_stats[TAKEN_SLOW]);
debugfs_create_u32("taken_slow_pickup", 0444, d_spin_debug,
&spinlock_stats.contention_stats[TAKEN_SLOW_PICKUP]);
debugfs_create_u32("taken_slow_spurious", 0444, d_spin_debug,
&spinlock_stats.contention_stats[TAKEN_SLOW_SPURIOUS]);
debugfs_create_u32("released_slow", 0444, d_spin_debug,
&spinlock_stats.contention_stats[RELEASED_SLOW]);
debugfs_create_u32("released_slow_kicked", 0444, d_spin_debug,
&spinlock_stats.contention_stats[RELEASED_SLOW_KICKED]);
debugfs_create_u64("time_blocked", 0444, d_spin_debug,
&spinlock_stats.time_blocked);
debugfs_create_u32_array("histo_blocked", 0444, d_spin_debug,
spinlock_stats.histo_spin_blocked, HISTO_BUCKETS + 1);
return 0;
}
