inline void do_gettimeofday_fast(struct fasttime_t *tv)
{
tv->tv_jiff = jiffies;
tv->tv_usec = GET_JIFFIES_USEC();
}
inline int fasttime_cmp(struct fasttime_t *t0, struct fasttime_t *t1)
{
if (time_before(t0->tv_jiff, t1->tv_jiff))
return -1;
else if (time_after(t0->tv_jiff, t1->tv_jiff))
return 1;
if (t0->tv_usec < t1->tv_usec)
return -1;
else if (t0->tv_usec > t1->tv_usec)
return 1;
return 0;
}
inline void start_timer_trig(unsigned long delay_us)
{
reg_timer_rw_ack_intr ack_intr = { 0 };
reg_timer_rw_intr_mask intr_mask;
reg_timer_rw_trig trig;
reg_timer_rw_trig_cfg trig_cfg = { 0 };
reg_timer_r_time r_time0;
reg_timer_r_time r_time1;
unsigned char trig_wrap;
unsigned char time_wrap;
r_time0 = REG_RD(timer, regi_timer0, r_time);
D1(printk("start_timer_trig : %d us freq: %i div: %i\n",
delay_us, freq_index, div));
intr_mask = REG_RD(timer, regi_timer0, rw_intr_mask);
intr_mask.trig = 0;
REG_WR(timer, regi_timer0, rw_intr_mask, intr_mask);
trig_wrap = (trig = r_time0 + delay_us*(1000/10)) < r_time0;
timer_div_settings[fast_timers_started % NUM_TIMER_STATS] = trig;
timer_delay_settings[fast_timers_started % NUM_TIMER_STATS] = delay_us;
ack_intr.trig = 1;
REG_WR(timer, regi_timer0, rw_ack_intr, ack_intr);
REG_WR(timer, regi_timer0, rw_trig, trig);
trig_cfg.tmr = regk_timer_time;
REG_WR(timer, regi_timer0, rw_trig_cfg, trig_cfg);
r_time1 = REG_RD(timer, regi_timer0, r_time);
time_wrap = r_time1 < r_time0;
if ((trig_wrap && !time_wrap) || (r_time1 < trig)) {
intr_mask = REG_RD(timer, regi_timer0, rw_intr_mask);
intr_mask.trig = 1;
REG_WR(timer, regi_timer0, rw_intr_mask, intr_mask);
fast_timers_started++;
fast_timer_running = 1;
} else {
trig_cfg.tmr = regk_timer_off;
REG_WR(timer, regi_timer0, rw_trig_cfg, trig_cfg);
REG_WR(timer, regi_timer0, rw_ack_intr, ack_intr);
INIT_WORK(&fast_work, timer_trig_handler);
schedule_work(&fast_work);
}
}
void start_one_shot_timer(struct fast_timer *t,
fast_timer_function_type *function,
unsigned long data,
unsigned long delay_us,
const char *name)
{
unsigned long flags;
struct fast_timer *tmp;
D1(printk("sft %s %d us\n", name, delay_us));
local_irq_save(flags);
do_gettimeofday_fast(&t->tv_set);
tmp = fast_timer_list;
#ifdef FAST_TIMER_SANITY_CHECKS
while (tmp != NULL) {
if (tmp == t) {
printk(KERN_DEBUG
"timer name: %s data: 0x%08lX already "
"in list!\n", name, data);
sanity_failed++;
goto done;
} else
tmp = tmp->next;
}
tmp = fast_timer_list;
#endif
t->delay_us = delay_us;
t->function = function;
t->data = data;
t->name = name;
t->tv_expires.tv_usec = t->tv_set.tv_usec + delay_us % 1000000;
t->tv_expires.tv_jiff = t->tv_set.tv_jiff + delay_us / 1000000 / HZ;
if (t->tv_expires.tv_usec > 1000000) {
t->tv_expires.tv_usec -= 1000000;
t->tv_expires.tv_jiff += HZ;
}
#ifdef FAST_TIMER_LOG
timer_added_log[fast_timers_added % NUM_TIMER_STATS] = *t;
#endif
fast_timers_added++;
if (tmp == NULL || fasttime_cmp(&t->tv_expires, &tmp->tv_expires) < 0) {
t->prev = NULL;
t->next = fast_timer_list;
if (fast_timer_list)
fast_timer_list->prev = t;
fast_timer_list = t;
#ifdef FAST_TIMER_LOG
timer_started_log[fast_timers_started % NUM_TIMER_STATS] = *t;
#endif
start_timer_trig(delay_us);
} else {
while (tmp->next &&
fasttime_cmp(&t->tv_expires, &tmp->next->tv_expires) > 0)
tmp = tmp->next;
t->prev = tmp;
t->next = tmp->next;
if (tmp->next)
{
tmp->next->prev = t;
}
tmp->next = t;
}
D2(printk("start_one_shot_timer: %d us done\n", delay_us));
done:
local_irq_restore(flags);
}
static inline int fast_timer_pending (const struct fast_timer * t)
{
return (t->next != NULL) || (t->prev != NULL) || (t == fast_timer_list);
}
static inline int detach_fast_timer (struct fast_timer *t)
{
struct fast_timer *next, *prev;
if (!fast_timer_pending(t))
return 0;
next = t->next;
prev = t->prev;
if (next)
next->prev = prev;
if (prev)
prev->next = next;
else
fast_timer_list = next;
fast_timers_deleted++;
return 1;
}
int del_fast_timer(struct fast_timer * t)
{
unsigned long flags;
int ret;
local_irq_save(flags);
ret = detach_fast_timer(t);
t->next = t->prev = NULL;
local_irq_restore(flags);
return ret;
}
static irqreturn_t
timer_trig_interrupt(int irq, void *dev_id)
{
reg_timer_r_masked_intr masked_intr;
masked_intr = REG_RD(timer, regi_timer0, r_masked_intr);
if (!masked_intr.trig)
return IRQ_NONE;
timer_trig_handler(NULL);
return IRQ_HANDLED;
}
static void timer_trig_handler(struct work_struct *work)
{
reg_timer_rw_ack_intr ack_intr = { 0 };
reg_timer_rw_intr_mask intr_mask;
reg_timer_rw_trig_cfg trig_cfg = { 0 };
struct fast_timer *t;
unsigned long flags;
local_irq_save(flags);
intr_mask = REG_RD(timer, regi_timer0, rw_intr_mask);
intr_mask.trig = 0;
REG_WR(timer, regi_timer0, rw_intr_mask, intr_mask);
trig_cfg.tmr = regk_timer_off;
REG_WR(timer, regi_timer0, rw_trig_cfg, trig_cfg);
ack_intr.trig = 1;
REG_WR(timer, regi_timer0, rw_ack_intr, ack_intr);
fast_timer_running = 0;
fast_timer_ints++;
fast_timer_function_type *f;
unsigned long d;
t = fast_timer_list;
while (t) {
struct fasttime_t tv;
do_gettimeofday_fast(&tv);
D1(printk(KERN_DEBUG
"t: %is %06ius\n", tv.tv_jiff, tv.tv_usec));
if (fasttime_cmp(&t->tv_expires, &tv) <= 0) {
#ifdef FAST_TIMER_LOG
timer_expired_log[fast_timers_expired % NUM_TIMER_STATS] = *t;
#endif
fast_timers_expired++;
if (t->prev)
t->prev->next = t->next;
else
fast_timer_list = t->next;
if (t->next)
t->next->prev = t->prev;
t->prev = NULL;
t->next = NULL;
f = t->function;
d = t->data;
if (f != NULL) {
local_irq_restore(flags);
f(d);
local_irq_save(flags);
} else
DEBUG_LOG("!trimertrig %i function==NULL!\n", fast_timer_ints);
} else {
D1(printk(".\n"));
}
t = fast_timer_list;
if (t != NULL) {
long us = 0;
struct fasttime_t tv;
do_gettimeofday_fast(&tv);
if (time_after_eq(t->tv_expires.tv_jiff, tv.tv_jiff))
us = ((t->tv_expires.tv_jiff - tv.tv_jiff) *
1000000 / HZ + t->tv_expires.tv_usec -
tv.tv_usec);
if (us > 0) {
if (!fast_timer_running) {
#ifdef FAST_TIMER_LOG
timer_started_log[fast_timers_started % NUM_TIMER_STATS] = *t;
#endif
start_timer_trig(us);
}
break;
} else {
D1(printk("e! %d\n", us));
}
}
}
local_irq_restore(flags);
if (!t)
D1(printk("ttrig stop!\n"));
}
static void wake_up_func(unsigned long data)
{
wait_queue_head_t *sleep_wait_p = (wait_queue_head_t*)data;
wake_up(sleep_wait_p);
}
void schedule_usleep(unsigned long us)
{
struct fast_timer t;
wait_queue_head_t sleep_wait;
init_waitqueue_head(&sleep_wait);
D1(printk("schedule_usleep(%d)\n", us));
start_one_shot_timer(&t, wake_up_func, (unsigned long)&sleep_wait, us,
"usleep");
wait_event(sleep_wait, !fast_timer_pending(&t));
D1(printk("done schedule_usleep(%d)\n", us));
}
static int proc_fasttimer_show(struct seq_file *m, void *v)
{
unsigned long flags;
int i = 0;
int num_to_show;
struct fasttime_t tv;
struct fast_timer *t, *nextt;
do_gettimeofday_fast(&tv);
seq_printf(m, "Fast timers added: %i\n", fast_timers_added);
seq_printf(m, "Fast timers started: %i\n", fast_timers_started);
seq_printf(m, "Fast timer interrupts: %i\n", fast_timer_ints);
seq_printf(m, "Fast timers expired: %i\n", fast_timers_expired);
seq_printf(m, "Fast timers deleted: %i\n", fast_timers_deleted);
seq_printf(m, "Fast timer running: %s\n",
fast_timer_running ? "yes" : "no");
seq_printf(m, "Current time: %lu.%06lu\n",
(unsigned long)tv.tv_jiff,
(unsigned long)tv.tv_usec);
#ifdef FAST_TIMER_SANITY_CHECKS
seq_printf(m, "Sanity failed: %i\n", sanity_failed);
#endif
seq_putc(m, '\n');
#ifdef DEBUG_LOG_INCLUDED
{
int end_i = debug_log_cnt;
i = 0;
if (debug_log_cnt_wrapped)
i = debug_log_cnt;
while ((i != end_i || debug_log_cnt_wrapped)) {
seq_printf(m, debug_log_string[i], debug_log_value[i]);
if (seq_has_overflowed(m))
return 0;
i = (i+1) % DEBUG_LOG_MAX;
}
}
seq_putc(m, '\n');
#endif
num_to_show = (fast_timers_started < NUM_TIMER_STATS ? fast_timers_started:
NUM_TIMER_STATS);
seq_printf(m, "Timers started: %i\n", fast_timers_started);
for (i = 0; i < num_to_show; i++) {
int cur = (fast_timers_started - i - 1) % NUM_TIMER_STATS;
#if 1
seq_printf(m, "div: %i delay: %i\n",
timer_div_settings[cur],
timer_delay_settings[cur]);
#endif
#ifdef FAST_TIMER_LOG
t = &timer_started_log[cur];
seq_printf(m, "%-14s s: %6lu.%06lu e: %6lu.%06lu d: %6li us data: 0x%08lX\n",
t->name,
(unsigned long)t->tv_set.tv_jiff,
(unsigned long)t->tv_set.tv_usec,
(unsigned long)t->tv_expires.tv_jiff,
(unsigned long)t->tv_expires.tv_usec,
t->delay_us,
t->data);
if (seq_has_overflowed(m))
return 0;
#endif
}
seq_putc(m, '\n');
#ifdef FAST_TIMER_LOG
num_to_show = (fast_timers_added < NUM_TIMER_STATS ? fast_timers_added:
NUM_TIMER_STATS);
seq_printf(m, "Timers added: %i\n", fast_timers_added);
for (i = 0; i < num_to_show; i++) {
t = &timer_added_log[(fast_timers_added - i - 1) % NUM_TIMER_STATS];
seq_printf(m, "%-14s s: %6lu.%06lu e: %6lu.%06lu d: %6li us data: 0x%08lX\n",
t->name,
(unsigned long)t->tv_set.tv_jiff,
(unsigned long)t->tv_set.tv_usec,
(unsigned long)t->tv_expires.tv_jiff,
(unsigned long)t->tv_expires.tv_usec,
t->delay_us,
t->data);
if (seq_has_overflowed(m))
return 0;
}
seq_putc(m, '\n');
num_to_show = (fast_timers_expired < NUM_TIMER_STATS ? fast_timers_expired:
NUM_TIMER_STATS);
seq_printf(m, "Timers expired: %i\n", fast_timers_expired);
for (i = 0; i < num_to_show; i++){
t = &timer_expired_log[(fast_timers_expired - i - 1) % NUM_TIMER_STATS];
seq_printf(m, "%-14s s: %6lu.%06lu e: %6lu.%06lu d: %6li us data: 0x%08lX\n",
t->name,
(unsigned long)t->tv_set.tv_jiff,
(unsigned long)t->tv_set.tv_usec,
(unsigned long)t->tv_expires.tv_jiff,
(unsigned long)t->tv_expires.tv_usec,
t->delay_us,
t->data);
if (seq_has_overflowed(m))
return 0;
}
seq_putc(m, '\n');
#endif
seq_puts(m, "Active timers:\n");
local_irq_save(flags);
t = fast_timer_list;
while (t != NULL){
nextt = t->next;
local_irq_restore(flags);
seq_printf(m, "%-14s s: %6lu.%06lu e: %6lu.%06lu d: %6li us data: 0x%08lX\n",
t->name,
(unsigned long)t->tv_set.tv_jiff,
(unsigned long)t->tv_set.tv_usec,
(unsigned long)t->tv_expires.tv_jiff,
(unsigned long)t->tv_expires.tv_usec,
t->delay_us,
t->data);
if (seq_has_overflowed(m))
return 0;
local_irq_save(flags);
if (t->next != nextt)
printk("timer removed!\n");
t = nextt;
}
local_irq_restore(flags);
return 0;
}
static int proc_fasttimer_open(struct inode *inode, struct file *file)
{
return single_open_size(file, proc_fasttimer_show, PDE_DATA(inode), BIG_BUF_SIZE);
}
static void test_timeout(unsigned long data)
{
do_gettimeofday_fast(&tv_exp[data]);
exp_num[data] = num_test_timeout;
num_test_timeout++;
}
static void test_timeout1(unsigned long data)
{
do_gettimeofday_fast(&tv_exp[data]);
exp_num[data] = num_test_timeout;
if (data < 7)
{
start_one_shot_timer(&tr[i], test_timeout1, i, 1000, "timeout1");
i++;
}
num_test_timeout++;
}
static void fast_timer_test(void)
{
int prev_num;
int j;
struct fasttime_t tv, tv0, tv1, tv2;
printk("fast_timer_test() start\n");
do_gettimeofday_fast(&tv);
for (j = 0; j < 1000; j++)
{
j_u[j] = GET_JIFFIES_USEC();
}
for (j = 0; j < 100; j++)
{
do_gettimeofday_fast(&tv_exp[j]);
}
printk(KERN_DEBUG "fast_timer_test() %is %06i\n", tv.tv_jiff, tv.tv_usec);
for (j = 0; j < 1000; j++)
{
printk(KERN_DEBUG "%i %i %i %i %i\n",
j_u[j], j_u[j+1], j_u[j+2], j_u[j+3], j_u[j+4]);
j += 4;
}
for (j = 0; j < 100; j++)
{
printk(KERN_DEBUG "%i.%i %i.%i %i.%i %i.%i %i.%i\n",
tv_exp[j].tv_jiff, tv_exp[j].tv_usec,
tv_exp[j+1].tv_jiff, tv_exp[j+1].tv_usec,
tv_exp[j+2].tv_jiff, tv_exp[j+2].tv_usec,
tv_exp[j+3].tv_jiff, tv_exp[j+3].tv_usec,
tv_exp[j+4].tv_jiff, tv_exp[j+4].tv_usec);
j += 4;
}
do_gettimeofday_fast(&tv0);
start_one_shot_timer(&tr[i], test_timeout, i, 50000, "test0");
DP(proc_fasttimer_read(buf0, NULL, 0, 0, 0));
i++;
start_one_shot_timer(&tr[i], test_timeout, i, 70000, "test1");
DP(proc_fasttimer_read(buf1, NULL, 0, 0, 0));
i++;
start_one_shot_timer(&tr[i], test_timeout, i, 40000, "test2");
DP(proc_fasttimer_read(buf2, NULL, 0, 0, 0));
i++;
start_one_shot_timer(&tr[i], test_timeout, i, 60000, "test3");
DP(proc_fasttimer_read(buf3, NULL, 0, 0, 0));
i++;
start_one_shot_timer(&tr[i], test_timeout1, i, 55000, "test4xx");
DP(proc_fasttimer_read(buf4, NULL, 0, 0, 0));
i++;
do_gettimeofday_fast(&tv1);
proc_fasttimer_read(buf5, NULL, 0, 0, 0);
prev_num = num_test_timeout;
while (num_test_timeout < i)
{
if (num_test_timeout != prev_num)
prev_num = num_test_timeout;
}
do_gettimeofday_fast(&tv2);
printk(KERN_INFO "Timers started %is %06i\n",
tv0.tv_jiff, tv0.tv_usec);
printk(KERN_INFO "Timers started at %is %06i\n",
tv1.tv_jiff, tv1.tv_usec);
printk(KERN_INFO "Timers done %is %06i\n",
tv2.tv_jiff, tv2.tv_usec);
DP(printk("buf0:\n");
printk(buf0);
printk("buf1:\n");
printk(buf1);
printk("buf2:\n");
printk(buf2);
printk("buf3:\n");
printk(buf3);
printk("buf4:\n");
printk(buf4);
);
printk("buf5:\n");
printk(buf5);
printk("timers set:\n");
for(j = 0; j<i; j++)
{
struct fast_timer *t = &tr[j];
printk("%-10s set: %6is %06ius exp: %6is %06ius "
"data: 0x%08X func: 0x%08X\n",
t->name,
t->tv_set.tv_jiff,
t->tv_set.tv_usec,
t->tv_expires.tv_jiff,
t->tv_expires.tv_usec,
t->data,
t->function
);
printk(" del: %6ius did exp: %6is %06ius as #%i error: %6li\n",
t->delay_us,
tv_exp[j].tv_jiff,
tv_exp[j].tv_usec,
exp_num[j],
(tv_exp[j].tv_jiff - t->tv_expires.tv_jiff) *
1000000 + tv_exp[j].tv_usec -
t->tv_expires.tv_usec);
}
proc_fasttimer_read(buf5, NULL, 0, 0, 0);
printk("buf5 after all done:\n");
printk(buf5);
printk("fast_timer_test() done\n");
}
int fast_timer_init(void)
{
if (!fast_timer_is_init)
{
printk("fast_timer_init()\n");
#ifdef CONFIG_PROC_FS
proc_create("fasttimer", 0, NULL, &proc_fasttimer_fops);
#endif
if (request_irq(TIMER0_INTR_VECT, timer_trig_interrupt,
IRQF_SHARED,
"fast timer int", &fast_timer_list))
printk(KERN_ERR "err: fasttimer irq\n");
fast_timer_is_init = 1;
#ifdef FAST_TIMER_TEST
printk("do test\n");
fast_timer_test();
#endif
}
return 0;
}
