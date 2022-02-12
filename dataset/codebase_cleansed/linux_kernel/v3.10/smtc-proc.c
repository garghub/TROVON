static int smtc_proc_show(struct seq_file *m, void *v)
{
int i;
extern unsigned long ebase;
seq_printf(m, "SMTC Status Word: 0x%08x\n", smtc_status);
seq_printf(m, "Config7: 0x%08x\n", read_c0_config7());
seq_printf(m, "EBASE: 0x%08lx\n", ebase);
seq_printf(m, "Counter Interrupts taken per CPU (TC)\n");
for (i=0; i < NR_CPUS; i++)
seq_printf(m, "%d: %ld\n", i, smtc_cpu_stats[i].timerints);
seq_printf(m, "Self-IPIs by CPU:\n");
for(i = 0; i < NR_CPUS; i++)
seq_printf(m, "%d: %ld\n", i, smtc_cpu_stats[i].selfipis);
seq_printf(m, "%d Recoveries of \"stolen\" FPU\n",
atomic_read(&smtc_fpu_recoveries));
return 0;
}
static int smtc_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, smtc_proc_show, NULL);
}
void init_smtc_stats(void)
{
int i;
for (i=0; i<NR_CPUS; i++) {
smtc_cpu_stats[i].timerints = 0;
smtc_cpu_stats[i].selfipis = 0;
}
atomic_set(&smtc_fpu_recoveries, 0);
proc_create("smtc", 0444, NULL, &smtc_proc_fops);
}
