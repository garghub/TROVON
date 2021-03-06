static inline void check_zero(void)
{
if (unlikely(zero_stats)) {
memset(&spinlock_stats, 0, sizeof(spinlock_stats));
zero_stats = 0;
}
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
static inline void spin_time_accum_spinning(u64 start)
{
u32 delta = xen_clocksource_read() - start;
__spin_time_accum(delta, spinlock_stats.histo_spin_spinning);
spinlock_stats.time_spinning += delta;
}
static inline void spin_time_accum_total(u64 start)
{
u32 delta = xen_clocksource_read() - start;
__spin_time_accum(delta, spinlock_stats.histo_spin_total);
spinlock_stats.time_total += delta;
}
static inline void spin_time_accum_blocked(u64 start)
{
u32 delta = xen_clocksource_read() - start;
__spin_time_accum(delta, spinlock_stats.histo_spin_blocked);
spinlock_stats.time_blocked += delta;
}
static inline u64 spin_time_start(void)
{
return 0;
}
static inline void spin_time_accum_total(u64 start)
{
}
static inline void spin_time_accum_spinning(u64 start)
{
}
static inline void spin_time_accum_blocked(u64 start)
{
}
static int xen_spin_is_locked(struct arch_spinlock *lock)
{
struct xen_spinlock *xl = (struct xen_spinlock *)lock;
return xl->lock != 0;
}
static int xen_spin_is_contended(struct arch_spinlock *lock)
{
struct xen_spinlock *xl = (struct xen_spinlock *)lock;
return xl->spinners != 0;
}
static int xen_spin_trylock(struct arch_spinlock *lock)
{
struct xen_spinlock *xl = (struct xen_spinlock *)lock;
u8 old = 1;
asm("xchgb %b0,%1"
: "+q" (old), "+m" (xl->lock) : : "memory");
return old == 0;
}
static inline struct xen_spinlock *spinning_lock(struct xen_spinlock *xl)
{
struct xen_spinlock *prev;
prev = __this_cpu_read(lock_spinners);
__this_cpu_write(lock_spinners, xl);
wmb();
inc_spinners(xl);
return prev;
}
static inline void unspinning_lock(struct xen_spinlock *xl, struct xen_spinlock *prev)
{
dec_spinners(xl);
wmb();
__this_cpu_write(lock_spinners, prev);
}
static noinline int xen_spin_lock_slow(struct arch_spinlock *lock, bool irq_enable)
{
struct xen_spinlock *xl = (struct xen_spinlock *)lock;
struct xen_spinlock *prev;
int irq = __this_cpu_read(lock_kicker_irq);
int ret;
u64 start;
if (irq == -1)
return 0;
start = spin_time_start();
prev = spinning_lock(xl);
ADD_STATS(taken_slow, 1);
ADD_STATS(taken_slow_nested, prev != NULL);
do {
unsigned long flags;
xen_clear_irq_pending(irq);
ret = xen_spin_trylock(lock);
if (ret) {
ADD_STATS(taken_slow_pickup, 1);
if (prev != NULL)
xen_set_irq_pending(irq);
goto out;
}
flags = arch_local_save_flags();
if (irq_enable) {
ADD_STATS(taken_slow_irqenable, 1);
raw_local_irq_enable();
}
xen_poll_irq(irq);
raw_local_irq_restore(flags);
ADD_STATS(taken_slow_spurious, !xen_test_irq_pending(irq));
} while (!xen_test_irq_pending(irq));
kstat_incr_irqs_this_cpu(irq, irq_to_desc(irq));
out:
unspinning_lock(xl, prev);
spin_time_accum_blocked(start);
return ret;
}
static inline void __xen_spin_lock(struct arch_spinlock *lock, bool irq_enable)
{
struct xen_spinlock *xl = (struct xen_spinlock *)lock;
unsigned timeout;
u8 oldval;
u64 start_spin;
ADD_STATS(taken, 1);
start_spin = spin_time_start();
do {
u64 start_spin_fast = spin_time_start();
timeout = TIMEOUT;
asm("1: xchgb %1,%0\n"
" testb %1,%1\n"
" jz 3f\n"
"2: rep;nop\n"
" cmpb $0,%0\n"
" je 1b\n"
" dec %2\n"
" jnz 2b\n"
"3:\n"
: "+m" (xl->lock), "=q" (oldval), "+r" (timeout)
: "1" (1)
: "memory");
spin_time_accum_spinning(start_spin_fast);
} while (unlikely(oldval != 0 &&
(TIMEOUT == ~0 || !xen_spin_lock_slow(lock, irq_enable))));
spin_time_accum_total(start_spin);
}
static void xen_spin_lock(struct arch_spinlock *lock)
{
__xen_spin_lock(lock, false);
}
static void xen_spin_lock_flags(struct arch_spinlock *lock, unsigned long flags)
{
__xen_spin_lock(lock, !raw_irqs_disabled_flags(flags));
}
static noinline void xen_spin_unlock_slow(struct xen_spinlock *xl)
{
int cpu;
ADD_STATS(released_slow, 1);
for_each_online_cpu(cpu) {
if (per_cpu(lock_spinners, cpu) == xl) {
ADD_STATS(released_slow_kicked, 1);
xen_send_IPI_one(cpu, XEN_SPIN_UNLOCK_VECTOR);
break;
}
}
}
static void xen_spin_unlock(struct arch_spinlock *lock)
{
struct xen_spinlock *xl = (struct xen_spinlock *)lock;
ADD_STATS(released, 1);
smp_wmb();
xl->lock = 0;
mb();
if (unlikely(xl->spinners))
xen_spin_unlock_slow(xl);
}
static irqreturn_t dummy_handler(int irq, void *dev_id)
{
BUG();
return IRQ_HANDLED;
}
void __cpuinit xen_init_lock_cpu(int cpu)
{
int irq;
const char *name;
name = kasprintf(GFP_KERNEL, "spinlock%d", cpu);
irq = bind_ipi_to_irqhandler(XEN_SPIN_UNLOCK_VECTOR,
cpu,
dummy_handler,
IRQF_DISABLED|IRQF_PERCPU|IRQF_NOBALANCING,
name,
NULL);
if (irq >= 0) {
disable_irq(irq);
per_cpu(lock_kicker_irq, cpu) = irq;
}
printk("cpu %d spinlock event irq %d\n", cpu, irq);
}
void xen_uninit_lock_cpu(int cpu)
{
unbind_from_irqhandler(per_cpu(lock_kicker_irq, cpu), NULL);
}
void __init xen_init_spinlocks(void)
{
BUILD_BUG_ON(sizeof(struct xen_spinlock) > sizeof(arch_spinlock_t));
pv_lock_ops.spin_is_locked = xen_spin_is_locked;
pv_lock_ops.spin_is_contended = xen_spin_is_contended;
pv_lock_ops.spin_lock = xen_spin_lock;
pv_lock_ops.spin_lock_flags = xen_spin_lock_flags;
pv_lock_ops.spin_trylock = xen_spin_trylock;
pv_lock_ops.spin_unlock = xen_spin_unlock;
}
static int __init xen_spinlock_debugfs(void)
{
struct dentry *d_xen = xen_init_debugfs();
if (d_xen == NULL)
return -ENOMEM;
d_spin_debug = debugfs_create_dir("spinlocks", d_xen);
debugfs_create_u8("zero_stats", 0644, d_spin_debug, &zero_stats);
debugfs_create_u32("timeout", 0644, d_spin_debug, &lock_timeout);
debugfs_create_u64("taken", 0444, d_spin_debug, &spinlock_stats.taken);
debugfs_create_u32("taken_slow", 0444, d_spin_debug,
&spinlock_stats.taken_slow);
debugfs_create_u32("taken_slow_nested", 0444, d_spin_debug,
&spinlock_stats.taken_slow_nested);
debugfs_create_u32("taken_slow_pickup", 0444, d_spin_debug,
&spinlock_stats.taken_slow_pickup);
debugfs_create_u32("taken_slow_spurious", 0444, d_spin_debug,
&spinlock_stats.taken_slow_spurious);
debugfs_create_u32("taken_slow_irqenable", 0444, d_spin_debug,
&spinlock_stats.taken_slow_irqenable);
debugfs_create_u64("released", 0444, d_spin_debug, &spinlock_stats.released);
debugfs_create_u32("released_slow", 0444, d_spin_debug,
&spinlock_stats.released_slow);
debugfs_create_u32("released_slow_kicked", 0444, d_spin_debug,
&spinlock_stats.released_slow_kicked);
debugfs_create_u64("time_spinning", 0444, d_spin_debug,
&spinlock_stats.time_spinning);
debugfs_create_u64("time_blocked", 0444, d_spin_debug,
&spinlock_stats.time_blocked);
debugfs_create_u64("time_total", 0444, d_spin_debug,
&spinlock_stats.time_total);
xen_debugfs_create_u32_array("histo_total", 0444, d_spin_debug,
spinlock_stats.histo_spin_total, HISTO_BUCKETS + 1);
xen_debugfs_create_u32_array("histo_spinning", 0444, d_spin_debug,
spinlock_stats.histo_spin_spinning, HISTO_BUCKETS + 1);
xen_debugfs_create_u32_array("histo_blocked", 0444, d_spin_debug,
spinlock_stats.histo_spin_blocked, HISTO_BUCKETS + 1);
return 0;
}
