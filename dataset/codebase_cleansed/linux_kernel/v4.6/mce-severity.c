static int error_context(struct mce *m)
{
if ((m->cs & 3) == 3)
return IN_USER;
if (mc_recoverable(m->mcgstatus) && ex_has_fault_handler(m->ip))
return IN_KERNEL_RECOV;
return IN_KERNEL;
}
static int mce_severity_amd(struct mce *m, int tolerant, char **msg, bool is_excp)
{
enum context ctx = error_context(m);
if (m->status & MCI_STATUS_PCC)
return MCE_PANIC_SEVERITY;
if (m->status & MCI_STATUS_UC) {
if (mce_flags.overflow_recov) {
if (!(m->mcgstatus & MCG_STATUS_RIPV) && (ctx == IN_KERNEL))
return MCE_PANIC_SEVERITY;
return MCE_AR_SEVERITY;
} else {
if (m->status & MCI_STATUS_OVER)
return MCE_PANIC_SEVERITY;
}
return MCE_UC_SEVERITY;
}
if (m->status & MCI_STATUS_DEFERRED)
return MCE_DEFERRED_SEVERITY;
return MCE_KEEP_SEVERITY;
}
static int mce_severity_intel(struct mce *m, int tolerant, char **msg, bool is_excp)
{
enum exception excp = (is_excp ? EXCP_CONTEXT : NO_EXCP);
enum context ctx = error_context(m);
struct severity *s;
for (s = severities;; s++) {
if ((m->status & s->mask) != s->result)
continue;
if ((m->mcgstatus & s->mcgmask) != s->mcgres)
continue;
if (s->ser == SER_REQUIRED && !mca_cfg.ser)
continue;
if (s->ser == NO_SER && mca_cfg.ser)
continue;
if (s->context && ctx != s->context)
continue;
if (s->excp && excp != s->excp)
continue;
if (msg)
*msg = s->msg;
s->covered = 1;
if (s->sev >= MCE_UC_SEVERITY && ctx == IN_KERNEL) {
if (panic_on_oops || tolerant < 1)
return MCE_PANIC_SEVERITY;
}
return s->sev;
}
}
void __init mcheck_vendor_init_severity(void)
{
if (boot_cpu_data.x86_vendor == X86_VENDOR_AMD)
mce_severity = mce_severity_amd;
}
static void *s_start(struct seq_file *f, loff_t *pos)
{
if (*pos >= ARRAY_SIZE(severities))
return NULL;
return &severities[*pos];
}
static void *s_next(struct seq_file *f, void *data, loff_t *pos)
{
if (++(*pos) >= ARRAY_SIZE(severities))
return NULL;
return &severities[*pos];
}
static void s_stop(struct seq_file *f, void *data)
{
}
static int s_show(struct seq_file *f, void *data)
{
struct severity *ser = data;
seq_printf(f, "%d\t%s\n", ser->covered, ser->msg);
return 0;
}
static int severities_coverage_open(struct inode *inode, struct file *file)
{
return seq_open(file, &severities_seq_ops);
}
static ssize_t severities_coverage_write(struct file *file,
const char __user *ubuf,
size_t count, loff_t *ppos)
{
int i;
for (i = 0; i < ARRAY_SIZE(severities); i++)
severities[i].covered = 0;
return count;
}
static int __init severities_debugfs_init(void)
{
struct dentry *dmce, *fsev;
dmce = mce_get_debugfs_dir();
if (!dmce)
goto err_out;
fsev = debugfs_create_file("severities-coverage", 0444, dmce, NULL,
&severities_coverage_fops);
if (!fsev)
goto err_out;
return 0;
err_out:
return -ENOMEM;
}
