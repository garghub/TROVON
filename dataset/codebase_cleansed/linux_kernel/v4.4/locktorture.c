static int torture_lock_busted_write_lock(void)
{
return 0;
}
static void torture_lock_busted_write_delay(struct torture_random_state *trsp)
{
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (cxt.nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_lock_busted_write_unlock(void)
{
}
static void torture_boost_dummy(struct torture_random_state *trsp)
{
}
static int torture_spin_lock_write_lock(void) __acquires(torture_spinlock)
{
spin_lock(&torture_spinlock);
return 0;
}
static void torture_spin_lock_write_delay(struct torture_random_state *trsp)
{
const unsigned long shortdelay_us = 2;
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms);
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2 * shortdelay_us)))
udelay(shortdelay_us);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (cxt.nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_spin_lock_write_unlock(void) __releases(torture_spinlock)
{
spin_unlock(&torture_spinlock);
}
static int torture_spin_lock_write_lock_irq(void)
__acquires(torture_spinlock)
{
unsigned long flags;
spin_lock_irqsave(&torture_spinlock, flags);
cxt.cur_ops->flags = flags;
return 0;
}
static void torture_lock_spin_write_unlock_irq(void)
__releases(torture_spinlock)
{
spin_unlock_irqrestore(&torture_spinlock, cxt.cur_ops->flags);
}
static int torture_rwlock_write_lock(void) __acquires(torture_rwlock)
{
write_lock(&torture_rwlock);
return 0;
}
static void torture_rwlock_write_delay(struct torture_random_state *trsp)
{
const unsigned long shortdelay_us = 2;
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms);
else
udelay(shortdelay_us);
}
static void torture_rwlock_write_unlock(void) __releases(torture_rwlock)
{
write_unlock(&torture_rwlock);
}
static int torture_rwlock_read_lock(void) __acquires(torture_rwlock)
{
read_lock(&torture_rwlock);
return 0;
}
static void torture_rwlock_read_delay(struct torture_random_state *trsp)
{
const unsigned long shortdelay_us = 10;
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealreaders_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms);
else
udelay(shortdelay_us);
}
static void torture_rwlock_read_unlock(void) __releases(torture_rwlock)
{
read_unlock(&torture_rwlock);
}
static int torture_rwlock_write_lock_irq(void) __acquires(torture_rwlock)
{
unsigned long flags;
write_lock_irqsave(&torture_rwlock, flags);
cxt.cur_ops->flags = flags;
return 0;
}
static void torture_rwlock_write_unlock_irq(void)
__releases(torture_rwlock)
{
write_unlock_irqrestore(&torture_rwlock, cxt.cur_ops->flags);
}
static int torture_rwlock_read_lock_irq(void) __acquires(torture_rwlock)
{
unsigned long flags;
read_lock_irqsave(&torture_rwlock, flags);
cxt.cur_ops->flags = flags;
return 0;
}
static void torture_rwlock_read_unlock_irq(void)
__releases(torture_rwlock)
{
read_unlock_irqrestore(&torture_rwlock, cxt.cur_ops->flags);
}
static int torture_mutex_lock(void) __acquires(torture_mutex)
{
mutex_lock(&torture_mutex);
return 0;
}
static void torture_mutex_delay(struct torture_random_state *trsp)
{
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms * 5);
else
mdelay(longdelay_ms / 5);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (cxt.nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_mutex_unlock(void) __releases(torture_mutex)
{
mutex_unlock(&torture_mutex);
}
static int torture_rtmutex_lock(void) __acquires(torture_rtmutex)
{
rt_mutex_lock(&torture_rtmutex);
return 0;
}
static void torture_rtmutex_boost(struct torture_random_state *trsp)
{
int policy;
struct sched_param param;
const unsigned int factor = 50000;
if (!rt_task(current)) {
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * factor))) {
policy = SCHED_FIFO;
param.sched_priority = MAX_RT_PRIO - 1;
} else
return;
} else {
if (!trsp || !(torture_random(trsp) %
(cxt.nrealwriters_stress * factor * 2))) {
policy = SCHED_NORMAL;
param.sched_priority = 0;
} else
return;
}
sched_setscheduler_nocheck(current, policy, &param);
}
static void torture_rtmutex_delay(struct torture_random_state *trsp)
{
const unsigned long shortdelay_us = 2;
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms);
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2 * shortdelay_us)))
udelay(shortdelay_us);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (cxt.nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_rtmutex_unlock(void) __releases(torture_rtmutex)
{
rt_mutex_unlock(&torture_rtmutex);
}
static int torture_rwsem_down_write(void) __acquires(torture_rwsem)
{
down_write(&torture_rwsem);
return 0;
}
static void torture_rwsem_write_delay(struct torture_random_state *trsp)
{
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms * 10);
else
mdelay(longdelay_ms / 10);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (cxt.nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_rwsem_up_write(void) __releases(torture_rwsem)
{
up_write(&torture_rwsem);
}
static int torture_rwsem_down_read(void) __acquires(torture_rwsem)
{
down_read(&torture_rwsem);
return 0;
}
static void torture_rwsem_read_delay(struct torture_random_state *trsp)
{
const unsigned long longdelay_ms = 100;
if (!(torture_random(trsp) %
(cxt.nrealwriters_stress * 2000 * longdelay_ms)))
mdelay(longdelay_ms * 2);
else
mdelay(longdelay_ms / 2);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (cxt.nrealreaders_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_rwsem_up_read(void) __releases(torture_rwsem)
{
up_read(&torture_rwsem);
}
void torture_percpu_rwsem_init(void)
{
BUG_ON(percpu_init_rwsem(&pcpu_rwsem));
}
static int torture_percpu_rwsem_down_write(void) __acquires(pcpu_rwsem)
{
percpu_down_write(&pcpu_rwsem);
return 0;
}
static void torture_percpu_rwsem_up_write(void) __releases(pcpu_rwsem)
{
percpu_up_write(&pcpu_rwsem);
}
static int torture_percpu_rwsem_down_read(void) __acquires(pcpu_rwsem)
{
percpu_down_read(&pcpu_rwsem);
return 0;
}
static void torture_percpu_rwsem_up_read(void) __releases(pcpu_rwsem)
{
percpu_up_read(&pcpu_rwsem);
}
static int lock_torture_writer(void *arg)
{
struct lock_stress_stats *lwsp = arg;
static DEFINE_TORTURE_RANDOM(rand);
VERBOSE_TOROUT_STRING("lock_torture_writer task started");
set_user_nice(current, MAX_NICE);
do {
if ((torture_random(&rand) & 0xfffff) == 0)
schedule_timeout_uninterruptible(1);
cxt.cur_ops->task_boost(&rand);
cxt.cur_ops->writelock();
if (WARN_ON_ONCE(lock_is_write_held))
lwsp->n_lock_fail++;
lock_is_write_held = 1;
if (WARN_ON_ONCE(lock_is_read_held))
lwsp->n_lock_fail++;
lwsp->n_lock_acquired++;
cxt.cur_ops->write_delay(&rand);
lock_is_write_held = 0;
cxt.cur_ops->writeunlock();
stutter_wait("lock_torture_writer");
} while (!torture_must_stop());
cxt.cur_ops->task_boost(NULL);
torture_kthread_stopping("lock_torture_writer");
return 0;
}
static int lock_torture_reader(void *arg)
{
struct lock_stress_stats *lrsp = arg;
static DEFINE_TORTURE_RANDOM(rand);
VERBOSE_TOROUT_STRING("lock_torture_reader task started");
set_user_nice(current, MAX_NICE);
do {
if ((torture_random(&rand) & 0xfffff) == 0)
schedule_timeout_uninterruptible(1);
cxt.cur_ops->readlock();
lock_is_read_held = 1;
if (WARN_ON_ONCE(lock_is_write_held))
lrsp->n_lock_fail++;
lrsp->n_lock_acquired++;
cxt.cur_ops->read_delay(&rand);
lock_is_read_held = 0;
cxt.cur_ops->readunlock();
stutter_wait("lock_torture_reader");
} while (!torture_must_stop());
torture_kthread_stopping("lock_torture_reader");
return 0;
}
static void __torture_print_stats(char *page,
struct lock_stress_stats *statp, bool write)
{
bool fail = 0;
int i, n_stress;
long max = 0;
long min = statp[0].n_lock_acquired;
long long sum = 0;
n_stress = write ? cxt.nrealwriters_stress : cxt.nrealreaders_stress;
for (i = 0; i < n_stress; i++) {
if (statp[i].n_lock_fail)
fail = true;
sum += statp[i].n_lock_acquired;
if (max < statp[i].n_lock_fail)
max = statp[i].n_lock_fail;
if (min > statp[i].n_lock_fail)
min = statp[i].n_lock_fail;
}
page += sprintf(page,
"%s: Total: %lld Max/Min: %ld/%ld %s Fail: %d %s\n",
write ? "Writes" : "Reads ",
sum, max, min, max / 2 > min ? "???" : "",
fail, fail ? "!!!" : "");
if (fail)
atomic_inc(&cxt.n_lock_torture_errors);
}
static void lock_torture_stats_print(void)
{
int size = cxt.nrealwriters_stress * 200 + 8192;
char *buf;
if (cxt.cur_ops->readlock)
size += cxt.nrealreaders_stress * 200 + 8192;
buf = kmalloc(size, GFP_KERNEL);
if (!buf) {
pr_err("lock_torture_stats_print: Out of memory, need: %d",
size);
return;
}
__torture_print_stats(buf, cxt.lwsa, true);
pr_alert("%s", buf);
kfree(buf);
if (cxt.cur_ops->readlock) {
buf = kmalloc(size, GFP_KERNEL);
if (!buf) {
pr_err("lock_torture_stats_print: Out of memory, need: %d",
size);
return;
}
__torture_print_stats(buf, cxt.lrsa, false);
pr_alert("%s", buf);
kfree(buf);
}
}
static int lock_torture_stats(void *arg)
{
VERBOSE_TOROUT_STRING("lock_torture_stats task started");
do {
schedule_timeout_interruptible(stat_interval * HZ);
lock_torture_stats_print();
torture_shutdown_absorb("lock_torture_stats");
} while (!torture_must_stop());
torture_kthread_stopping("lock_torture_stats");
return 0;
}
static inline void
lock_torture_print_module_parms(struct lock_torture_ops *cur_ops,
const char *tag)
{
pr_alert("%s" TORTURE_FLAG
"--- %s%s: nwriters_stress=%d nreaders_stress=%d stat_interval=%d verbose=%d shuffle_interval=%d stutter=%d shutdown_secs=%d onoff_interval=%d onoff_holdoff=%d\n",
torture_type, tag, cxt.debug_lock ? " [debug]": "",
cxt.nrealwriters_stress, cxt.nrealreaders_stress, stat_interval,
verbose, shuffle_interval, stutter, shutdown_secs,
onoff_interval, onoff_holdoff);
}
static void lock_torture_cleanup(void)
{
int i;
if (torture_cleanup_begin())
return;
if (writer_tasks) {
for (i = 0; i < cxt.nrealwriters_stress; i++)
torture_stop_kthread(lock_torture_writer,
writer_tasks[i]);
kfree(writer_tasks);
writer_tasks = NULL;
}
if (reader_tasks) {
for (i = 0; i < cxt.nrealreaders_stress; i++)
torture_stop_kthread(lock_torture_reader,
reader_tasks[i]);
kfree(reader_tasks);
reader_tasks = NULL;
}
torture_stop_kthread(lock_torture_stats, stats_task);
lock_torture_stats_print();
if (atomic_read(&cxt.n_lock_torture_errors))
lock_torture_print_module_parms(cxt.cur_ops,
"End of test: FAILURE");
else if (torture_onoff_failures())
lock_torture_print_module_parms(cxt.cur_ops,
"End of test: LOCK_HOTPLUG");
else
lock_torture_print_module_parms(cxt.cur_ops,
"End of test: SUCCESS");
torture_cleanup_end();
}
static int __init lock_torture_init(void)
{
int i, j;
int firsterr = 0;
static struct lock_torture_ops *torture_ops[] = {
&lock_busted_ops,
&spin_lock_ops, &spin_lock_irq_ops,
&rw_lock_ops, &rw_lock_irq_ops,
&mutex_lock_ops,
#ifdef CONFIG_RT_MUTEXES
&rtmutex_lock_ops,
#endif
&rwsem_lock_ops,
&percpu_rwsem_lock_ops,
};
if (!torture_init_begin(torture_type, verbose, &torture_runnable))
return -EBUSY;
for (i = 0; i < ARRAY_SIZE(torture_ops); i++) {
cxt.cur_ops = torture_ops[i];
if (strcmp(torture_type, cxt.cur_ops->name) == 0)
break;
}
if (i == ARRAY_SIZE(torture_ops)) {
pr_alert("lock-torture: invalid torture type: \"%s\"\n",
torture_type);
pr_alert("lock-torture types:");
for (i = 0; i < ARRAY_SIZE(torture_ops); i++)
pr_alert(" %s", torture_ops[i]->name);
pr_alert("\n");
firsterr = -EINVAL;
goto unwind;
}
if (cxt.cur_ops->init)
cxt.cur_ops->init();
if (nwriters_stress >= 0)
cxt.nrealwriters_stress = nwriters_stress;
else
cxt.nrealwriters_stress = 2 * num_online_cpus();
#ifdef CONFIG_DEBUG_MUTEXES
if (strncmp(torture_type, "mutex", 5) == 0)
cxt.debug_lock = true;
#endif
#ifdef CONFIG_DEBUG_RT_MUTEXES
if (strncmp(torture_type, "rtmutex", 7) == 0)
cxt.debug_lock = true;
#endif
#ifdef CONFIG_DEBUG_SPINLOCK
if ((strncmp(torture_type, "spin", 4) == 0) ||
(strncmp(torture_type, "rw_lock", 7) == 0))
cxt.debug_lock = true;
#endif
lock_is_write_held = 0;
cxt.lwsa = kmalloc(sizeof(*cxt.lwsa) * cxt.nrealwriters_stress, GFP_KERNEL);
if (cxt.lwsa == NULL) {
VERBOSE_TOROUT_STRING("cxt.lwsa: Out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < cxt.nrealwriters_stress; i++) {
cxt.lwsa[i].n_lock_fail = 0;
cxt.lwsa[i].n_lock_acquired = 0;
}
if (cxt.cur_ops->readlock) {
if (nreaders_stress >= 0)
cxt.nrealreaders_stress = nreaders_stress;
else {
if (nwriters_stress < 0)
cxt.nrealwriters_stress = num_online_cpus();
cxt.nrealreaders_stress = cxt.nrealwriters_stress;
}
lock_is_read_held = 0;
cxt.lrsa = kmalloc(sizeof(*cxt.lrsa) * cxt.nrealreaders_stress, GFP_KERNEL);
if (cxt.lrsa == NULL) {
VERBOSE_TOROUT_STRING("cxt.lrsa: Out of memory");
firsterr = -ENOMEM;
kfree(cxt.lwsa);
goto unwind;
}
for (i = 0; i < cxt.nrealreaders_stress; i++) {
cxt.lrsa[i].n_lock_fail = 0;
cxt.lrsa[i].n_lock_acquired = 0;
}
}
lock_torture_print_module_parms(cxt.cur_ops, "Start of test");
if (onoff_interval > 0) {
firsterr = torture_onoff_init(onoff_holdoff * HZ,
onoff_interval * HZ);
if (firsterr)
goto unwind;
}
if (shuffle_interval > 0) {
firsterr = torture_shuffle_init(shuffle_interval);
if (firsterr)
goto unwind;
}
if (shutdown_secs > 0) {
firsterr = torture_shutdown_init(shutdown_secs,
lock_torture_cleanup);
if (firsterr)
goto unwind;
}
if (stutter > 0) {
firsterr = torture_stutter_init(stutter);
if (firsterr)
goto unwind;
}
writer_tasks = kzalloc(cxt.nrealwriters_stress * sizeof(writer_tasks[0]),
GFP_KERNEL);
if (writer_tasks == NULL) {
VERBOSE_TOROUT_ERRSTRING("writer_tasks: Out of memory");
firsterr = -ENOMEM;
goto unwind;
}
if (cxt.cur_ops->readlock) {
reader_tasks = kzalloc(cxt.nrealreaders_stress * sizeof(reader_tasks[0]),
GFP_KERNEL);
if (reader_tasks == NULL) {
VERBOSE_TOROUT_ERRSTRING("reader_tasks: Out of memory");
firsterr = -ENOMEM;
goto unwind;
}
}
for (i = 0, j = 0; i < cxt.nrealwriters_stress ||
j < cxt.nrealreaders_stress; i++, j++) {
if (i >= cxt.nrealwriters_stress)
goto create_reader;
firsterr = torture_create_kthread(lock_torture_writer, &cxt.lwsa[i],
writer_tasks[i]);
if (firsterr)
goto unwind;
create_reader:
if (cxt.cur_ops->readlock == NULL || (j >= cxt.nrealreaders_stress))
continue;
firsterr = torture_create_kthread(lock_torture_reader, &cxt.lrsa[j],
reader_tasks[j]);
if (firsterr)
goto unwind;
}
if (stat_interval > 0) {
firsterr = torture_create_kthread(lock_torture_stats, NULL,
stats_task);
if (firsterr)
goto unwind;
}
torture_init_end();
return 0;
unwind:
torture_init_end();
lock_torture_cleanup();
return firsterr;
}
