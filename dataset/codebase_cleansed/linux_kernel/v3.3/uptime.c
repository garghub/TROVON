static int uptime_proc_show(struct seq_file *m, void *v)
{
struct timespec uptime;
struct timespec idle;
u64 idletime;
u64 nsec;
u32 rem;
int i;
idletime = 0;
for_each_possible_cpu(i)
idletime += (__force u64) kcpustat_cpu(i).cpustat[CPUTIME_IDLE];
do_posix_clock_monotonic_gettime(&uptime);
monotonic_to_bootbased(&uptime);
nsec = cputime64_to_jiffies64(idletime) * TICK_NSEC;
idle.tv_sec = div_u64_rem(nsec, NSEC_PER_SEC, &rem);
idle.tv_nsec = rem;
seq_printf(m, "%lu.%02lu %lu.%02lu\n",
(unsigned long) uptime.tv_sec,
(uptime.tv_nsec / (NSEC_PER_SEC / 100)),
(unsigned long) idle.tv_sec,
(idle.tv_nsec / (NSEC_PER_SEC / 100)));
return 0;
}
static int uptime_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, uptime_proc_show, NULL);
}
static int __init proc_uptime_init(void)
{
proc_create("uptime", 0, NULL, &uptime_proc_fops);
return 0;
}
