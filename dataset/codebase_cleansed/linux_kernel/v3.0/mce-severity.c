static int error_context(struct mce *m)
{
if (m->mcgstatus & MCG_STATUS_EIPV)
return (m->ip && (m->cs & 3) == 3) ? IN_USER : IN_KERNEL;
return IN_KERNEL;
}
int mce_severity(struct mce *a, int tolerant, char **msg)
{
enum context ctx = error_context(a);
struct severity *s;
for (s = severities;; s++) {
if ((a->status & s->mask) != s->result)
continue;
if ((a->mcgstatus & s->mcgmask) != s->mcgres)
continue;
if (s->ser == SER_REQUIRED && !mce_ser)
continue;
if (s->ser == NO_SER && mce_ser)
continue;
if (s->context && ctx != s->context)
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
struct dentry *dmce = NULL, *fseverities_coverage = NULL;
dmce = mce_get_debugfs_dir();
if (dmce == NULL)
goto err_out;
fseverities_coverage = debugfs_create_file("severities-coverage",
0444, dmce, NULL,
&severities_coverage_fops);
if (fseverities_coverage == NULL)
goto err_out;
return 0;
err_out:
return -ENOMEM;
}
