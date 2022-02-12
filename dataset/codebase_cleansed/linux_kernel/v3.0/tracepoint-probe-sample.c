static void probe_subsys_event(void *ignore,
struct inode *inode, struct file *file)
{
path_get(&file->f_path);
dget(file->f_path.dentry);
printk(KERN_INFO "Event is encountered with filename %s\n",
file->f_path.dentry->d_name.name);
dput(file->f_path.dentry);
path_put(&file->f_path);
}
static void probe_subsys_eventb(void *ignore)
{
printk(KERN_INFO "Event B is encountered\n");
}
static int __init tp_sample_trace_init(void)
{
int ret;
ret = register_trace_subsys_event(probe_subsys_event, NULL);
WARN_ON(ret);
ret = register_trace_subsys_eventb(probe_subsys_eventb, NULL);
WARN_ON(ret);
return 0;
}
static void __exit tp_sample_trace_exit(void)
{
unregister_trace_subsys_eventb(probe_subsys_eventb, NULL);
unregister_trace_subsys_event(probe_subsys_event, NULL);
tracepoint_synchronize_unregister();
}
