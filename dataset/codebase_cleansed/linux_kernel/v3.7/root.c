static int proc_test_super(struct super_block *sb, void *data)
{
return sb->s_fs_info == data;
}
static int proc_set_super(struct super_block *sb, void *data)
{
int err = set_anon_super(sb, NULL);
if (!err) {
struct pid_namespace *ns = (struct pid_namespace *)data;
sb->s_fs_info = get_pid_ns(ns);
}
return err;
}
static int proc_parse_options(char *options, struct pid_namespace *pid)
{
char *p;
substring_t args[MAX_OPT_ARGS];
int option;
if (!options)
return 1;
while ((p = strsep(&options, ",")) != NULL) {
int token;
if (!*p)
continue;
args[0].to = args[0].from = NULL;
token = match_token(p, tokens, args);
switch (token) {
case Opt_gid:
if (match_int(&args[0], &option))
return 0;
pid->pid_gid = make_kgid(current_user_ns(), option);
break;
case Opt_hidepid:
if (match_int(&args[0], &option))
return 0;
if (option < 0 || option > 2) {
pr_err("proc: hidepid value must be between 0 and 2.\n");
return 0;
}
pid->hide_pid = option;
break;
default:
pr_err("proc: unrecognized mount option \"%s\" "
"or missing value\n", p);
return 0;
}
}
return 1;
}
int proc_remount(struct super_block *sb, int *flags, char *data)
{
struct pid_namespace *pid = sb->s_fs_info;
return !proc_parse_options(data, pid);
}
static struct dentry *proc_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
int err;
struct super_block *sb;
struct pid_namespace *ns;
struct proc_inode *ei;
char *options;
if (flags & MS_KERNMOUNT) {
ns = (struct pid_namespace *)data;
options = NULL;
} else {
ns = current->nsproxy->pid_ns;
options = data;
}
sb = sget(fs_type, proc_test_super, proc_set_super, flags, ns);
if (IS_ERR(sb))
return ERR_CAST(sb);
if (!proc_parse_options(options, ns)) {
deactivate_locked_super(sb);
return ERR_PTR(-EINVAL);
}
if (!sb->s_root) {
err = proc_fill_super(sb);
if (err) {
deactivate_locked_super(sb);
return ERR_PTR(err);
}
sb->s_flags |= MS_ACTIVE;
}
ei = PROC_I(sb->s_root->d_inode);
if (!ei->pid) {
rcu_read_lock();
ei->pid = get_pid(find_pid_ns(1, ns));
rcu_read_unlock();
}
return dget(sb->s_root);
}
static void proc_kill_sb(struct super_block *sb)
{
struct pid_namespace *ns;
ns = (struct pid_namespace *)sb->s_fs_info;
kill_anon_super(sb);
put_pid_ns(ns);
}
void __init proc_root_init(void)
{
int err;
proc_init_inodecache();
err = register_filesystem(&proc_fs_type);
if (err)
return;
err = pid_ns_prepare_proc(&init_pid_ns);
if (err) {
unregister_filesystem(&proc_fs_type);
return;
}
proc_symlink("mounts", NULL, "self/mounts");
proc_net_init();
#ifdef CONFIG_SYSVIPC
proc_mkdir("sysvipc", NULL);
#endif
proc_mkdir("fs", NULL);
proc_mkdir("driver", NULL);
proc_mkdir("fs/nfsd", NULL);
#if defined(CONFIG_SUN_OPENPROMFS) || defined(CONFIG_SUN_OPENPROMFS_MODULE)
proc_mkdir("openprom", NULL);
#endif
proc_tty_init();
#ifdef CONFIG_PROC_DEVICETREE
proc_device_tree_init();
#endif
proc_mkdir("bus", NULL);
proc_sys_init();
}
static int proc_root_getattr(struct vfsmount *mnt, struct dentry *dentry, struct kstat *stat
)
{
generic_fillattr(dentry->d_inode, stat);
stat->nlink = proc_root.nlink + nr_processes();
return 0;
}
static struct dentry *proc_root_lookup(struct inode * dir, struct dentry * dentry, unsigned int flags)
{
if (!proc_lookup(dir, dentry, flags))
return NULL;
return proc_pid_lookup(dir, dentry, flags);
}
static int proc_root_readdir(struct file * filp,
void * dirent, filldir_t filldir)
{
unsigned int nr = filp->f_pos;
int ret;
if (nr < FIRST_PROCESS_ENTRY) {
int error = proc_readdir(filp, dirent, filldir);
if (error <= 0)
return error;
filp->f_pos = FIRST_PROCESS_ENTRY;
}
ret = proc_pid_readdir(filp, dirent, filldir);
return ret;
}
int pid_ns_prepare_proc(struct pid_namespace *ns)
{
struct vfsmount *mnt;
mnt = kern_mount_data(&proc_fs_type, ns);
if (IS_ERR(mnt))
return PTR_ERR(mnt);
ns->proc_mnt = mnt;
return 0;
}
void pid_ns_release_proc(struct pid_namespace *ns)
{
kern_unmount(ns->proc_mnt);
}
