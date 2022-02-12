static ssize_t rproc_trace_read(struct file *filp, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct rproc_mem_entry *trace = filp->private_data;
int len = strnlen(trace->va, trace->len);
return simple_read_from_buffer(userbuf, count, ppos, trace->va, len);
}
static ssize_t rproc_state_read(struct file *filp, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct rproc *rproc = filp->private_data;
unsigned int state;
char buf[30];
int i;
state = rproc->state > RPROC_LAST ? RPROC_LAST : rproc->state;
i = snprintf(buf, 30, "%.28s (%d)\n", rproc_state_string[state],
rproc->state);
return simple_read_from_buffer(userbuf, count, ppos, buf, i);
}
static ssize_t rproc_name_read(struct file *filp, char __user *userbuf,
size_t count, loff_t *ppos)
{
struct rproc *rproc = filp->private_data;
char buf[100];
int i;
i = snprintf(buf, sizeof(buf), "%.98s\n", rproc->name);
return simple_read_from_buffer(userbuf, count, ppos, buf, i);
}
void rproc_remove_trace_file(struct dentry *tfile)
{
debugfs_remove(tfile);
}
struct dentry *rproc_create_trace_file(const char *name, struct rproc *rproc,
struct rproc_mem_entry *trace)
{
struct dentry *tfile;
tfile = debugfs_create_file(name, 0400, rproc->dbg_dir,
trace, &trace_rproc_ops);
if (!tfile) {
dev_err(rproc->dev, "failed to create debugfs trace entry\n");
return NULL;
}
return tfile;
}
void rproc_delete_debug_dir(struct rproc *rproc)
{
if (!rproc->dbg_dir)
return;
debugfs_remove_recursive(rproc->dbg_dir);
}
void rproc_create_debug_dir(struct rproc *rproc)
{
struct device *dev = rproc->dev;
if (!rproc_dbg)
return;
rproc->dbg_dir = debugfs_create_dir(dev_name(dev), rproc_dbg);
if (!rproc->dbg_dir)
return;
debugfs_create_file("name", 0400, rproc->dbg_dir,
rproc, &rproc_name_ops);
debugfs_create_file("state", 0400, rproc->dbg_dir,
rproc, &rproc_state_ops);
}
void __init rproc_init_debugfs(void)
{
if (debugfs_initialized()) {
rproc_dbg = debugfs_create_dir(KBUILD_MODNAME, NULL);
if (!rproc_dbg)
pr_err("can't create debugfs dir\n");
}
}
void __exit rproc_exit_debugfs(void)
{
if (rproc_dbg)
debugfs_remove(rproc_dbg);
}
