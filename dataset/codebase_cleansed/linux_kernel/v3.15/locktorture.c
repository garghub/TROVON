static int torture_lock_busted_write_lock(void)
{
return 0;
}
static void torture_lock_busted_write_delay(struct torture_random_state *trsp)
{
const unsigned long longdelay_us = 100;
if (!(torture_random(trsp) %
(nrealwriters_stress * 2000 * longdelay_us)))
mdelay(longdelay_us);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_lock_busted_write_unlock(void)
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
const unsigned long longdelay_us = 100;
if (!(torture_random(trsp) %
(nrealwriters_stress * 2000 * longdelay_us)))
mdelay(longdelay_us);
if (!(torture_random(trsp) %
(nrealwriters_stress * 2 * shortdelay_us)))
udelay(shortdelay_us);
#ifdef CONFIG_PREEMPT
if (!(torture_random(trsp) % (nrealwriters_stress * 20000)))
preempt_schedule();
#endif
}
static void torture_spin_lock_write_unlock(void) __releases(torture_spinlock)
{
spin_unlock(&torture_spinlock);
}
static int torture_spin_lock_write_lock_irq(void)
__acquires(torture_spinlock_irq)
{
unsigned long flags;
spin_lock_irqsave(&torture_spinlock, flags);
cur_ops->flags = flags;
return 0;
}
static void torture_lock_spin_write_unlock_irq(void)
__releases(torture_spinlock)
{
spin_unlock_irqrestore(&torture_spinlock, cur_ops->flags);
}
static int lock_torture_writer(void *arg)
{
struct lock_writer_stress_stats *lwsp = arg;
static DEFINE_TORTURE_RANDOM(rand);
VERBOSE_TOROUT_STRING("lock_torture_writer task started");
set_user_nice(current, 19);
do {
schedule_timeout_uninterruptible(1);
cur_ops->writelock();
if (WARN_ON_ONCE(lock_is_write_held))
lwsp->n_write_lock_fail++;
lock_is_write_held = 1;
lwsp->n_write_lock_acquired++;
cur_ops->write_delay(&rand);
lock_is_write_held = 0;
cur_ops->writeunlock();
stutter_wait("lock_torture_writer");
} while (!torture_must_stop());
torture_kthread_stopping("lock_torture_writer");
return 0;
}
static void lock_torture_printk(char *page)
{
bool fail = 0;
int i;
long max = 0;
long min = lwsa[0].n_write_lock_acquired;
long long sum = 0;
for (i = 0; i < nrealwriters_stress; i++) {
if (lwsa[i].n_write_lock_fail)
fail = true;
sum += lwsa[i].n_write_lock_acquired;
if (max < lwsa[i].n_write_lock_fail)
max = lwsa[i].n_write_lock_fail;
if (min > lwsa[i].n_write_lock_fail)
min = lwsa[i].n_write_lock_fail;
}
page += sprintf(page, "%s%s ", torture_type, TORTURE_FLAG);
page += sprintf(page,
"Writes: Total: %lld Max/Min: %ld/%ld %s Fail: %d %s\n",
sum, max, min, max / 2 > min ? "???" : "",
fail, fail ? "!!!" : "");
if (fail)
atomic_inc(&n_lock_torture_errors);
}
static void lock_torture_stats_print(void)
{
int size = nrealwriters_stress * 200 + 8192;
char *buf;
buf = kmalloc(size, GFP_KERNEL);
if (!buf) {
pr_err("lock_torture_stats_print: Out of memory, need: %d",
size);
return;
}
lock_torture_printk(buf);
pr_alert("%s", buf);
kfree(buf);
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
"--- %s: nwriters_stress=%d stat_interval=%d verbose=%d shuffle_interval=%d stutter=%d shutdown_secs=%d onoff_interval=%d onoff_holdoff=%d\n",
torture_type, tag, nrealwriters_stress, stat_interval, verbose,
shuffle_interval, stutter, shutdown_secs,
onoff_interval, onoff_holdoff);
}
static void lock_torture_cleanup(void)
{
int i;
if (torture_cleanup())
return;
if (writer_tasks) {
for (i = 0; i < nrealwriters_stress; i++)
torture_stop_kthread(lock_torture_writer,
writer_tasks[i]);
kfree(writer_tasks);
writer_tasks = NULL;
}
torture_stop_kthread(lock_torture_stats, stats_task);
lock_torture_stats_print();
if (atomic_read(&n_lock_torture_errors))
lock_torture_print_module_parms(cur_ops,
"End of test: FAILURE");
else if (torture_onoff_failures())
lock_torture_print_module_parms(cur_ops,
"End of test: LOCK_HOTPLUG");
else
lock_torture_print_module_parms(cur_ops,
"End of test: SUCCESS");
}
static int __init lock_torture_init(void)
{
int i;
int firsterr = 0;
static struct lock_torture_ops *torture_ops[] = {
&lock_busted_ops, &spin_lock_ops, &spin_lock_irq_ops,
};
torture_init_begin(torture_type, verbose, &locktorture_runnable);
for (i = 0; i < ARRAY_SIZE(torture_ops); i++) {
cur_ops = torture_ops[i];
if (strcmp(torture_type, cur_ops->name) == 0)
break;
}
if (i == ARRAY_SIZE(torture_ops)) {
pr_alert("lock-torture: invalid torture type: \"%s\"\n",
torture_type);
pr_alert("lock-torture types:");
for (i = 0; i < ARRAY_SIZE(torture_ops); i++)
pr_alert(" %s", torture_ops[i]->name);
pr_alert("\n");
torture_init_end();
return -EINVAL;
}
if (cur_ops->init)
cur_ops->init();
if (nwriters_stress >= 0)
nrealwriters_stress = nwriters_stress;
else
nrealwriters_stress = 2 * num_online_cpus();
lock_torture_print_module_parms(cur_ops, "Start of test");
lock_is_write_held = 0;
lwsa = kmalloc(sizeof(*lwsa) * nrealwriters_stress, GFP_KERNEL);
if (lwsa == NULL) {
VERBOSE_TOROUT_STRING("lwsa: Out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nrealwriters_stress; i++) {
lwsa[i].n_write_lock_fail = 0;
lwsa[i].n_write_lock_acquired = 0;
}
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
writer_tasks = kzalloc(nrealwriters_stress * sizeof(writer_tasks[0]),
GFP_KERNEL);
if (writer_tasks == NULL) {
VERBOSE_TOROUT_ERRSTRING("writer_tasks: Out of memory");
firsterr = -ENOMEM;
goto unwind;
}
for (i = 0; i < nrealwriters_stress; i++) {
firsterr = torture_create_kthread(lock_torture_writer, &lwsa[i],
writer_tasks[i]);
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
