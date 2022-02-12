static int my_open(struct inode *inode, struct file *file)
{
int i;
trace_subsys_event(inode, file);
for (i = 0; i < 10; i++)
trace_subsys_eventb();
return -EPERM;
}
static int __init sample_init(void)
{
printk(KERN_ALERT "sample init\n");
pentry_sample = proc_create("tracepoint-sample", 0444, NULL,
&mark_ops);
if (!pentry_sample)
return -EPERM;
return 0;
}
static void __exit sample_exit(void)
{
printk(KERN_ALERT "sample exit\n");
remove_proc_entry("tracepoint-sample", NULL);
}
