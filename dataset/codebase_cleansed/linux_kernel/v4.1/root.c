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
sync_filesystem(sb);
return !proc_parse_options(data, pid);
}
static struct dentry *proc_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
int err;
struct super_block *sb;
struct pid_namespace *ns;
char *options;
if (flags & MS_KERNMOUNT) {
ns = (struct pid_namespace *)data;
options = NULL;
} else {
ns = task_active_pid_ns(current);
options = data;
if (!capable(CAP_SYS_ADMIN) && !fs_fully_visible(fs_type))
return ERR_PTR(-EPERM);
if (!ns_capable(ns->user_ns, CAP_SYS_ADMIN))
return ERR_PTR(-EPERM);
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
return dget(sb->s_root);
}
static void proc_kill_sb(struct super_block *sb)
{
struct pid_namespace *ns;
ns = (struct pid_namespace *)sb->s_fs_info;
if (ns->proc_self)
dput(ns->proc_self);
if (ns->proc_thread_self)
dput(ns->proc_thread_self);
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
proc_self_init();
proc_thread_self_init();
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
proc_mkdir("bus", NULL);
proc_sys_init();
}
static int proc_root_getattr(struct vfsmount *mnt, struct dentry *dentry, struct kstat *stat
)
{
generic_fillattr(d_inode(dentry), stat);
stat->nlink = proc_root.nlink + nr_processes();
return 0;
}
static struct dentry *proc_root_lookup(struct inode * dir, struct dentry * dentry, unsigned int flags)
{
if (!proc_pid_lookup(dir, dentry, flags))
return NULL;
return proc_lookup(dir, dentry, flags);
}
static int proc_root_readdir(struct file *file, struct dir_context *ctx)
{
if (ctx->pos < FIRST_PROCESS_ENTRY) {
int error = proc_readdir(file, ctx);
if (unlikely(error <= 0))
return error;
ctx->pos = FIRST_PROCESS_ENTRY;
}
return proc_pid_readdir(file, ctx);
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
