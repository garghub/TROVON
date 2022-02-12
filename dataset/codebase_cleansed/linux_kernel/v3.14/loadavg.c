static int loadavg_proc_show(struct seq_file *m, void *v)
{
unsigned long avnrun[3];
get_avenrun(avnrun, FIXED_1/200, 0);
seq_printf(m, "%lu.%02lu %lu.%02lu %lu.%02lu %ld/%d %d\n",
LOAD_INT(avnrun[0]), LOAD_FRAC(avnrun[0]),
LOAD_INT(avnrun[1]), LOAD_FRAC(avnrun[1]),
LOAD_INT(avnrun[2]), LOAD_FRAC(avnrun[2]),
nr_running(), nr_threads,
task_active_pid_ns(current)->last_pid);
return 0;
}
static int loadavg_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, loadavg_proc_show, NULL);
}
static int __init proc_loadavg_init(void)
{
proc_create("loadavg", 0, NULL, &loadavg_proc_fops);
return 0;
}
