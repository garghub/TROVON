static int show_latency(struct seq_file *m, void *v)
{
u64 cpuclk, avg, max, min;
struct latency_info curr_li = li;
cpuclk = octeon_get_clock_rate();
max = (curr_li.max_latency * 1000000000) / cpuclk;
min = (curr_li.min_latency * 1000000000) / cpuclk;
avg = (curr_li.latency_sum * 1000000000) / (cpuclk * curr_li.interrupt_cnt);
seq_printf(m, "cnt: %10lld, avg: %7lld ns, max: %7lld ns, min: %7lld ns\n",
curr_li.interrupt_cnt, avg, max, min);
return 0;
}
static int oct_ilm_open(struct inode *inode, struct file *file)
{
return single_open(file, show_latency, NULL);
}
static int reset_statistics(void *data, u64 value)
{
reset_stats = true;
return 0;
}
static int init_debufs(void)
{
struct dentry *show_dentry;
dir = debugfs_create_dir("oct_ilm", 0);
if (!dir) {
pr_err("oct_ilm: failed to create debugfs entry oct_ilm\n");
return -1;
}
show_dentry = debugfs_create_file("statistics", 0222, dir, NULL,
&oct_ilm_ops);
if (!show_dentry) {
pr_err("oct_ilm: failed to create debugfs entry oct_ilm/statistics\n");
return -1;
}
show_dentry = debugfs_create_file("reset", 0222, dir, NULL,
&reset_statistics_ops);
if (!show_dentry) {
pr_err("oct_ilm: failed to create debugfs entry oct_ilm/reset\n");
return -1;
}
return 0;
}
static void init_latency_info(struct latency_info *li, int startup)
{
int interval = 1;
if (startup) {
li->io_interval = (octeon_get_io_clock_rate() * interval) / 1000;
li->cpu_interval = (octeon_get_clock_rate() * interval) / 1000;
}
li->timer_start1 = 0;
li->timer_start2 = 0;
li->max_latency = 0;
li->min_latency = (u64)-1;
li->latency_sum = 0;
li->interrupt_cnt = 0;
}
static void start_timer(int timer, u64 interval)
{
union cvmx_ciu_timx timx;
unsigned long flags;
timx.u64 = 0;
timx.s.one_shot = 1;
timx.s.len = interval;
raw_local_irq_save(flags);
li.timer_start1 = read_c0_cvmcount();
cvmx_write_csr(CVMX_CIU_TIMX(timer), timx.u64);
timx.u64 = cvmx_read_csr(CVMX_CIU_TIMX(timer));
li.timer_start2 = read_c0_cvmcount();
raw_local_irq_restore(flags);
}
static irqreturn_t cvm_oct_ciu_timer_interrupt(int cpl, void *dev_id)
{
u64 last_latency;
u64 last_int_cnt;
if (reset_stats) {
init_latency_info(&li, 0);
reset_stats = false;
} else {
last_int_cnt = read_c0_cvmcount();
last_latency = last_int_cnt - (li.timer_start1 + li.cpu_interval);
li.interrupt_cnt++;
li.latency_sum += last_latency;
if (last_latency > li.max_latency)
li.max_latency = last_latency;
if (last_latency < li.min_latency)
li.min_latency = last_latency;
}
start_timer(TIMER_NUM, li.io_interval);
return IRQ_HANDLED;
}
static void disable_timer(int timer)
{
union cvmx_ciu_timx timx;
timx.s.one_shot = 0;
timx.s.len = 0;
cvmx_write_csr(CVMX_CIU_TIMX(timer), timx.u64);
timx.u64 = cvmx_read_csr(CVMX_CIU_TIMX(timer));
}
static __init int oct_ilm_module_init(void)
{
int rc;
int irq = OCTEON_IRQ_TIMER0 + TIMER_NUM;
rc = init_debufs();
if (rc) {
WARN(1, "Could not create debugfs entries");
return rc;
}
rc = request_irq(irq, cvm_oct_ciu_timer_interrupt, IRQF_NO_THREAD,
"oct_ilm", 0);
if (rc) {
WARN(1, "Could not acquire IRQ %d", irq);
goto err_irq;
}
init_latency_info(&li, 1);
start_timer(TIMER_NUM, li.io_interval);
return 0;
err_irq:
debugfs_remove_recursive(dir);
return rc;
}
static __exit void oct_ilm_module_exit(void)
{
disable_timer(TIMER_NUM);
if (dir)
debugfs_remove_recursive(dir);
free_irq(OCTEON_IRQ_TIMER0 + TIMER_NUM, 0);
}
