static int exitcode_proc_show(struct seq_file *m, void *v)
{
int val;
val = uml_exitcode;
seq_printf(m, "%d\n", val);
return 0;
}
static int exitcode_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, exitcode_proc_show, NULL);
}
static ssize_t exitcode_proc_write(struct file *file,
const char __user *buffer, size_t count, loff_t *pos)
{
char *end, buf[sizeof("nnnnn\0")];
int tmp;
if (copy_from_user(buf, buffer, count))
return -EFAULT;
tmp = simple_strtol(buf, &end, 0);
if ((*end != '\0') && !isspace(*end))
return -EINVAL;
uml_exitcode = tmp;
return count;
}
static int make_proc_exitcode(void)
{
struct proc_dir_entry *ent;
ent = proc_create("exitcode", 0600, NULL, &exitcode_proc_fops);
if (ent == NULL) {
printk(KERN_WARNING "make_proc_exitcode : Failed to register "
"/proc/exitcode\n");
return 0;
}
return 0;
}
