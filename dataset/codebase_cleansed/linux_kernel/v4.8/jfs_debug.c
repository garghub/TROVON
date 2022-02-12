static int jfs_loglevel_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\n", jfsloglevel);
return 0;
}
static int jfs_loglevel_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, jfs_loglevel_proc_show, NULL);
}
static ssize_t jfs_loglevel_proc_write(struct file *file,
const char __user *buffer, size_t count, loff_t *ppos)
{
char c;
if (get_user(c, buffer))
return -EFAULT;
if (c < '0' || c > '9')
return -EINVAL;
jfsloglevel = c - '0';
return count;
}
void jfs_proc_init(void)
{
int i;
if (!(base = proc_mkdir("fs/jfs", NULL)))
return;
for (i = 0; i < NPROCENT; i++)
proc_create(Entries[i].name, 0, base, Entries[i].proc_fops);
}
void jfs_proc_clean(void)
{
int i;
if (base) {
for (i = 0; i < NPROCENT; i++)
remove_proc_entry(Entries[i].name, base);
remove_proc_entry("fs/jfs", NULL);
}
}
