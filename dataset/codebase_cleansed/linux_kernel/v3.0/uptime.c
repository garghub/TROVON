static int uptime_proc_show(struct seq_file *m, void *v)
{
struct timespec uptime;
struct timespec idle;
int i;
cputime_t idletime = cputime_zero;
for_each_possible_cpu(i)
idletime = cputime64_add(idletime, kstat_cpu(i).cpustat.idle);
do_posix_clock_monotonic_gettime(&uptime);
monotonic_to_bootbased(&uptime);
cputime_to_timespec(idletime, &idle);
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
