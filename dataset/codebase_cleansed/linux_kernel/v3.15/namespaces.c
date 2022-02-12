static char *ns_dname(struct dentry *dentry, char *buffer, int buflen)
{
struct inode *inode = dentry->d_inode;
const struct proc_ns_operations *ns_ops = PROC_I(inode)->ns.ns_ops;
return dynamic_dname(dentry, buffer, buflen, "%s:[%lu]",
ns_ops->name, inode->i_ino);
}
static struct dentry *proc_ns_get_dentry(struct super_block *sb,
struct task_struct *task, const struct proc_ns_operations *ns_ops)
{
struct dentry *dentry, *result;
struct inode *inode;
struct proc_inode *ei;
struct qstr qname = { .name = "", };
void *ns;
ns = ns_ops->get(task);
if (!ns)
return ERR_PTR(-ENOENT);
dentry = d_alloc_pseudo(sb, &qname);
if (!dentry) {
ns_ops->put(ns);
return ERR_PTR(-ENOMEM);
}
inode = iget_locked(sb, ns_ops->inum(ns));
if (!inode) {
dput(dentry);
ns_ops->put(ns);
return ERR_PTR(-ENOMEM);
}
ei = PROC_I(inode);
if (inode->i_state & I_NEW) {
inode->i_mtime = inode->i_atime = inode->i_ctime = CURRENT_TIME;
inode->i_op = &ns_inode_operations;
inode->i_mode = S_IFREG | S_IRUGO;
inode->i_fop = &ns_file_operations;
ei->ns.ns_ops = ns_ops;
ei->ns.ns = ns;
unlock_new_inode(inode);
} else {
ns_ops->put(ns);
}
d_set_d_op(dentry, &ns_dentry_operations);
result = d_instantiate_unique(dentry, inode);
if (result) {
dput(dentry);
dentry = result;
}
return dentry;
}
static void *proc_ns_follow_link(struct dentry *dentry, struct nameidata *nd)
{
struct inode *inode = dentry->d_inode;
struct super_block *sb = inode->i_sb;
struct proc_inode *ei = PROC_I(inode);
struct task_struct *task;
struct path ns_path;
void *error = ERR_PTR(-EACCES);
task = get_proc_task(inode);
if (!task)
goto out;
if (!ptrace_may_access(task, PTRACE_MODE_READ))
goto out_put_task;
ns_path.dentry = proc_ns_get_dentry(sb, task, ei->ns.ns_ops);
if (IS_ERR(ns_path.dentry)) {
error = ERR_CAST(ns_path.dentry);
goto out_put_task;
}
ns_path.mnt = mntget(nd->path.mnt);
nd_jump_link(nd, &ns_path);
error = NULL;
out_put_task:
put_task_struct(task);
out:
return error;
}
static int proc_ns_readlink(struct dentry *dentry, char __user *buffer, int buflen)
{
struct inode *inode = dentry->d_inode;
struct proc_inode *ei = PROC_I(inode);
const struct proc_ns_operations *ns_ops = ei->ns.ns_ops;
struct task_struct *task;
void *ns;
char name[50];
int res = -EACCES;
task = get_proc_task(inode);
if (!task)
goto out;
if (!ptrace_may_access(task, PTRACE_MODE_READ))
goto out_put_task;
res = -ENOENT;
ns = ns_ops->get(task);
if (!ns)
goto out_put_task;
snprintf(name, sizeof(name), "%s:[%u]", ns_ops->name, ns_ops->inum(ns));
res = readlink_copy(buffer, buflen, name);
ns_ops->put(ns);
out_put_task:
put_task_struct(task);
out:
return res;
}
static int proc_ns_instantiate(struct inode *dir,
struct dentry *dentry, struct task_struct *task, const void *ptr)
{
const struct proc_ns_operations *ns_ops = ptr;
struct inode *inode;
struct proc_inode *ei;
inode = proc_pid_make_inode(dir->i_sb, task);
if (!inode)
goto out;
ei = PROC_I(inode);
inode->i_mode = S_IFLNK|S_IRWXUGO;
inode->i_op = &proc_ns_link_inode_operations;
ei->ns.ns_ops = ns_ops;
d_set_d_op(dentry, &pid_dentry_operations);
d_add(dentry, inode);
if (pid_revalidate(dentry, 0))
return 0;
out:
return -ENOENT;
}
static int proc_ns_dir_readdir(struct file *file, struct dir_context *ctx)
{
struct task_struct *task = get_proc_task(file_inode(file));
const struct proc_ns_operations **entry, **last;
if (!task)
return -ENOENT;
if (!dir_emit_dots(file, ctx))
goto out;
if (ctx->pos >= 2 + ARRAY_SIZE(ns_entries))
goto out;
entry = ns_entries + (ctx->pos - 2);
last = &ns_entries[ARRAY_SIZE(ns_entries) - 1];
while (entry <= last) {
const struct proc_ns_operations *ops = *entry;
if (!proc_fill_cache(file, ctx, ops->name, strlen(ops->name),
proc_ns_instantiate, task, ops))
break;
ctx->pos++;
entry++;
}
out:
put_task_struct(task);
return 0;
}
static struct dentry *proc_ns_dir_lookup(struct inode *dir,
struct dentry *dentry, unsigned int flags)
{
int error;
struct task_struct *task = get_proc_task(dir);
const struct proc_ns_operations **entry, **last;
unsigned int len = dentry->d_name.len;
error = -ENOENT;
if (!task)
goto out_no_task;
last = &ns_entries[ARRAY_SIZE(ns_entries)];
for (entry = ns_entries; entry < last; entry++) {
if (strlen((*entry)->name) != len)
continue;
if (!memcmp(dentry->d_name.name, (*entry)->name, len))
break;
}
if (entry == last)
goto out;
error = proc_ns_instantiate(dir, dentry, task, *entry);
out:
put_task_struct(task);
out_no_task:
return ERR_PTR(error);
}
struct file *proc_ns_fget(int fd)
{
struct file *file;
file = fget(fd);
if (!file)
return ERR_PTR(-EBADF);
if (file->f_op != &ns_file_operations)
goto out_invalid;
return file;
out_invalid:
fput(file);
return ERR_PTR(-EINVAL);
}
struct proc_ns *get_proc_ns(struct inode *inode)
{
return &PROC_I(inode)->ns;
}
bool proc_ns_inode(struct inode *inode)
{
return inode->i_fop == &ns_file_operations;
}
