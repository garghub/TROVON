static int show_softirqs(struct seq_file *p, void *v)
{
int i, j;
seq_puts(p, " ");
for_each_possible_cpu(i)
seq_printf(p, "CPU%-8d", i);
seq_putc(p, '\n');
for (i = 0; i < NR_SOFTIRQS; i++) {
seq_printf(p, "%12s:", softirq_to_name[i]);
for_each_possible_cpu(j)
seq_printf(p, " %10u", kstat_softirqs_cpu(i, j));
seq_putc(p, '\n');
}
return 0;
}
static int softirqs_open(struct inode *inode, struct file *file)
{
return single_open(file, show_softirqs, NULL);
}
static int __init proc_softirqs_init(void)
{
proc_create("softirqs", 0, NULL, &proc_softirqs_operations);
return 0;
}
