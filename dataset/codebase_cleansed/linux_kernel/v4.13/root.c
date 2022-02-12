int proc_parse_options(char *options, struct pid_namespace *pid)
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
if (option < HIDEPID_OFF ||
option > HIDEPID_INVISIBLE) {
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
struct pid_namespace *ns;
if (flags & MS_KERNMOUNT) {
ns = data;
data = NULL;
} else {
ns = task_active_pid_ns(current);
}
return mount_ns(fs_type, flags, data, ns, ns->user_ns, proc_fill_super);
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
set_proc_pid_nlink();
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
proc_create_mount_point("fs/nfsd");
#if defined(CONFIG_SUN_OPENPROMFS) || defined(CONFIG_SUN_OPENPROMFS_MODULE)
proc_create_mount_point("openprom");
#endif
proc_tty_init();
proc_mkdir("bus", NULL);
proc_sys_init();
}
static int proc_root_getattr(const struct path *path, struct kstat *stat,
u32 request_mask, unsigned int query_flags)
{
generic_fillattr(d_inode(path->dentry), stat);
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
