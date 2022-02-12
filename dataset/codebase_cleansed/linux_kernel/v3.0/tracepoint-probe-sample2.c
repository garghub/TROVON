static void probe_subsys_event(void *ignore,
struct inode *inode, struct file *file)
{
printk(KERN_INFO "Event is encountered with inode number %lu\n",
inode->i_ino);
}
static int __init tp_sample_trace_init(void)
{
int ret;
ret = register_trace_subsys_event(probe_subsys_event, NULL);
WARN_ON(ret);
return 0;
}
static void __exit tp_sample_trace_exit(void)
{
unregister_trace_subsys_event(probe_subsys_event, NULL);
tracepoint_synchronize_unregister();
}
