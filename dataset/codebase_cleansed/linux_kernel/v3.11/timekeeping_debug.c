static int tk_debug_show_sleep_time(struct seq_file *s, void *data)
{
unsigned int bin;
seq_puts(s, " time (secs) count\n");
seq_puts(s, "------------------------------\n");
for (bin = 0; bin < 32; bin++) {
if (sleep_time_bin[bin] == 0)
continue;
seq_printf(s, "%10u - %-10u %4u\n",
bin ? 1 << (bin - 1) : 0, 1 << bin,
sleep_time_bin[bin]);
}
return 0;
}
static int tk_debug_sleep_time_open(struct inode *inode, struct file *file)
{
return single_open(file, tk_debug_show_sleep_time, NULL);
}
static int __init tk_debug_sleep_time_init(void)
{
struct dentry *d;
d = debugfs_create_file("sleep_time", 0444, NULL, NULL,
&tk_debug_sleep_time_fops);
if (!d) {
pr_err("Failed to create sleep_time debug file\n");
return -ENOMEM;
}
return 0;
}
void tk_debug_account_sleep_time(struct timespec *t)
{
sleep_time_bin[fls(t->tv_sec)]++;
}
