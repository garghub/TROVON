static void apparmor_cred_free(struct cred *cred)
{
aa_free_task_context(cred_ctx(cred));
cred_ctx(cred) = NULL;
}
static int apparmor_cred_alloc_blank(struct cred *cred, gfp_t gfp)
{
struct aa_task_ctx *ctx = aa_alloc_task_context(gfp);
if (!ctx)
return -ENOMEM;
cred_ctx(cred) = ctx;
return 0;
}
static int apparmor_cred_prepare(struct cred *new, const struct cred *old,
gfp_t gfp)
{
struct aa_task_ctx *ctx = aa_alloc_task_context(gfp);
if (!ctx)
return -ENOMEM;
aa_dup_task_context(ctx, cred_ctx(old));
cred_ctx(new) = ctx;
return 0;
}
static void apparmor_cred_transfer(struct cred *new, const struct cred *old)
{
const struct aa_task_ctx *old_ctx = cred_ctx(old);
struct aa_task_ctx *new_ctx = cred_ctx(new);
aa_dup_task_context(new_ctx, old_ctx);
}
static int apparmor_ptrace_access_check(struct task_struct *child,
unsigned int mode)
{
struct aa_label *tracer, *tracee;
int error;
tracer = begin_current_label_crit_section();
tracee = aa_get_task_label(child);
error = aa_may_ptrace(tracer, tracee,
mode == PTRACE_MODE_READ ? AA_PTRACE_READ : AA_PTRACE_TRACE);
aa_put_label(tracee);
end_current_label_crit_section(tracer);
return error;
}
static int apparmor_ptrace_traceme(struct task_struct *parent)
{
struct aa_label *tracer, *tracee;
int error;
tracee = begin_current_label_crit_section();
tracer = aa_get_task_label(parent);
error = aa_may_ptrace(tracer, tracee, AA_PTRACE_TRACE);
aa_put_label(tracer);
end_current_label_crit_section(tracee);
return error;
}
static int apparmor_capget(struct task_struct *target, kernel_cap_t *effective,
kernel_cap_t *inheritable, kernel_cap_t *permitted)
{
struct aa_label *label;
const struct cred *cred;
rcu_read_lock();
cred = __task_cred(target);
label = aa_get_newest_cred_label(cred);
if (!unconfined(label)) {
struct aa_profile *profile;
struct label_it i;
label_for_each_confined(i, label, profile) {
if (COMPLAIN_MODE(profile))
continue;
*effective = cap_intersect(*effective,
profile->caps.allow);
*permitted = cap_intersect(*permitted,
profile->caps.allow);
}
}
rcu_read_unlock();
aa_put_label(label);
return 0;
}
static int apparmor_capable(const struct cred *cred, struct user_namespace *ns,
int cap, int audit)
{
struct aa_label *label;
int error = 0;
label = aa_get_newest_cred_label(cred);
if (!unconfined(label))
error = aa_capable(label, cap, audit);
aa_put_label(label);
return error;
}
static int common_perm(const char *op, const struct path *path, u32 mask,
struct path_cond *cond)
{
struct aa_label *label;
int error = 0;
label = __begin_current_label_crit_section();
if (!unconfined(label))
error = aa_path_perm(op, label, path, 0, mask, cond);
__end_current_label_crit_section(label);
return error;
}
static int common_perm_cond(const char *op, const struct path *path, u32 mask)
{
struct path_cond cond = { d_backing_inode(path->dentry)->i_uid,
d_backing_inode(path->dentry)->i_mode
};
if (!path_mediated_fs(path->dentry))
return 0;
return common_perm(op, path, mask, &cond);
}
static int common_perm_dir_dentry(const char *op, const struct path *dir,
struct dentry *dentry, u32 mask,
struct path_cond *cond)
{
struct path path = { .mnt = dir->mnt, .dentry = dentry };
return common_perm(op, &path, mask, cond);
}
static int common_perm_rm(const char *op, const struct path *dir,
struct dentry *dentry, u32 mask)
{
struct inode *inode = d_backing_inode(dentry);
struct path_cond cond = { };
if (!inode || !path_mediated_fs(dentry))
return 0;
cond.uid = inode->i_uid;
cond.mode = inode->i_mode;
return common_perm_dir_dentry(op, dir, dentry, mask, &cond);
}
static int common_perm_create(const char *op, const struct path *dir,
struct dentry *dentry, u32 mask, umode_t mode)
{
struct path_cond cond = { current_fsuid(), mode };
if (!path_mediated_fs(dir->dentry))
return 0;
return common_perm_dir_dentry(op, dir, dentry, mask, &cond);
}
static int apparmor_path_unlink(const struct path *dir, struct dentry *dentry)
{
return common_perm_rm(OP_UNLINK, dir, dentry, AA_MAY_DELETE);
}
static int apparmor_path_mkdir(const struct path *dir, struct dentry *dentry,
umode_t mode)
{
return common_perm_create(OP_MKDIR, dir, dentry, AA_MAY_CREATE,
S_IFDIR);
}
static int apparmor_path_rmdir(const struct path *dir, struct dentry *dentry)
{
return common_perm_rm(OP_RMDIR, dir, dentry, AA_MAY_DELETE);
}
static int apparmor_path_mknod(const struct path *dir, struct dentry *dentry,
umode_t mode, unsigned int dev)
{
return common_perm_create(OP_MKNOD, dir, dentry, AA_MAY_CREATE, mode);
}
static int apparmor_path_truncate(const struct path *path)
{
return common_perm_cond(OP_TRUNC, path, MAY_WRITE | AA_MAY_SETATTR);
}
static int apparmor_path_symlink(const struct path *dir, struct dentry *dentry,
const char *old_name)
{
return common_perm_create(OP_SYMLINK, dir, dentry, AA_MAY_CREATE,
S_IFLNK);
}
static int apparmor_path_link(struct dentry *old_dentry, const struct path *new_dir,
struct dentry *new_dentry)
{
struct aa_label *label;
int error = 0;
if (!path_mediated_fs(old_dentry))
return 0;
label = begin_current_label_crit_section();
if (!unconfined(label))
error = aa_path_link(label, old_dentry, new_dir, new_dentry);
end_current_label_crit_section(label);
return error;
}
static int apparmor_path_rename(const struct path *old_dir, struct dentry *old_dentry,
const struct path *new_dir, struct dentry *new_dentry)
{
struct aa_label *label;
int error = 0;
if (!path_mediated_fs(old_dentry))
return 0;
label = begin_current_label_crit_section();
if (!unconfined(label)) {
struct path old_path = { .mnt = old_dir->mnt,
.dentry = old_dentry };
struct path new_path = { .mnt = new_dir->mnt,
.dentry = new_dentry };
struct path_cond cond = { d_backing_inode(old_dentry)->i_uid,
d_backing_inode(old_dentry)->i_mode
};
error = aa_path_perm(OP_RENAME_SRC, label, &old_path, 0,
MAY_READ | AA_MAY_GETATTR | MAY_WRITE |
AA_MAY_SETATTR | AA_MAY_DELETE,
&cond);
if (!error)
error = aa_path_perm(OP_RENAME_DEST, label, &new_path,
0, MAY_WRITE | AA_MAY_SETATTR |
AA_MAY_CREATE, &cond);
}
end_current_label_crit_section(label);
return error;
}
static int apparmor_path_chmod(const struct path *path, umode_t mode)
{
return common_perm_cond(OP_CHMOD, path, AA_MAY_CHMOD);
}
static int apparmor_path_chown(const struct path *path, kuid_t uid, kgid_t gid)
{
return common_perm_cond(OP_CHOWN, path, AA_MAY_CHOWN);
}
static int apparmor_inode_getattr(const struct path *path)
{
return common_perm_cond(OP_GETATTR, path, AA_MAY_GETATTR);
}
static int apparmor_file_open(struct file *file, const struct cred *cred)
{
struct aa_file_ctx *fctx = file_ctx(file);
struct aa_label *label;
int error = 0;
if (!path_mediated_fs(file->f_path.dentry))
return 0;
if (current->in_execve) {
fctx->allow = MAY_EXEC | MAY_READ | AA_EXEC_MMAP;
return 0;
}
label = aa_get_newest_cred_label(cred);
if (!unconfined(label)) {
struct inode *inode = file_inode(file);
struct path_cond cond = { inode->i_uid, inode->i_mode };
error = aa_path_perm(OP_OPEN, label, &file->f_path, 0,
aa_map_file_to_perms(file), &cond);
fctx->allow = aa_map_file_to_perms(file);
}
aa_put_label(label);
return error;
}
static int apparmor_file_alloc_security(struct file *file)
{
int error = 0;
struct aa_label *label = begin_current_label_crit_section();
file->f_security = aa_alloc_file_ctx(label, GFP_KERNEL);
if (!file_ctx(file))
error = -ENOMEM;
end_current_label_crit_section(label);
return error;
}
static void apparmor_file_free_security(struct file *file)
{
aa_free_file_ctx(file_ctx(file));
}
static int common_file_perm(const char *op, struct file *file, u32 mask)
{
struct aa_label *label;
int error = 0;
if (file->f_path.dentry == aa_null.dentry)
return -EACCES;
label = __begin_current_label_crit_section();
error = aa_file_perm(op, label, file, mask);
__end_current_label_crit_section(label);
return error;
}
static int apparmor_file_receive(struct file *file)
{
return common_file_perm(OP_FRECEIVE, file, aa_map_file_to_perms(file));
}
static int apparmor_file_permission(struct file *file, int mask)
{
return common_file_perm(OP_FPERM, file, mask);
}
static int apparmor_file_lock(struct file *file, unsigned int cmd)
{
u32 mask = AA_MAY_LOCK;
if (cmd == F_WRLCK)
mask |= MAY_WRITE;
return common_file_perm(OP_FLOCK, file, mask);
}
static int common_mmap(const char *op, struct file *file, unsigned long prot,
unsigned long flags)
{
int mask = 0;
if (!file || !file_ctx(file))
return 0;
if (prot & PROT_READ)
mask |= MAY_READ;
if ((prot & PROT_WRITE) && !(flags & MAP_PRIVATE))
mask |= MAY_WRITE;
if (prot & PROT_EXEC)
mask |= AA_EXEC_MMAP;
return common_file_perm(op, file, mask);
}
static int apparmor_mmap_file(struct file *file, unsigned long reqprot,
unsigned long prot, unsigned long flags)
{
return common_mmap(OP_FMMAP, file, prot, flags);
}
static int apparmor_file_mprotect(struct vm_area_struct *vma,
unsigned long reqprot, unsigned long prot)
{
return common_mmap(OP_FMPROT, vma->vm_file, prot,
!(vma->vm_flags & VM_SHARED) ? MAP_PRIVATE : 0);
}
static int apparmor_sb_mount(const char *dev_name, const struct path *path,
const char *type, unsigned long flags, void *data)
{
struct aa_label *label;
int error = 0;
if ((flags & MS_MGC_MSK) == MS_MGC_VAL)
flags &= ~MS_MGC_MSK;
flags &= ~AA_MS_IGNORE_MASK;
label = __begin_current_label_crit_section();
if (!unconfined(label)) {
if (flags & MS_REMOUNT)
error = aa_remount(label, path, flags, data);
else if (flags & MS_BIND)
error = aa_bind_mount(label, path, dev_name, flags);
else if (flags & (MS_SHARED | MS_PRIVATE | MS_SLAVE |
MS_UNBINDABLE))
error = aa_mount_change_type(label, path, flags);
else if (flags & MS_MOVE)
error = aa_move_mount(label, path, dev_name);
else
error = aa_new_mount(label, dev_name, path, type,
flags, data);
}
__end_current_label_crit_section(label);
return error;
}
static int apparmor_sb_umount(struct vfsmount *mnt, int flags)
{
struct aa_label *label;
int error = 0;
label = __begin_current_label_crit_section();
if (!unconfined(label))
error = aa_umount(label, mnt, flags);
__end_current_label_crit_section(label);
return error;
}
static int apparmor_sb_pivotroot(const struct path *old_path,
const struct path *new_path)
{
struct aa_label *label;
int error = 0;
label = aa_get_current_label();
if (!unconfined(label))
error = aa_pivotroot(label, old_path, new_path);
aa_put_label(label);
return error;
}
static int apparmor_getprocattr(struct task_struct *task, char *name,
char **value)
{
int error = -ENOENT;
const struct cred *cred = get_task_cred(task);
struct aa_task_ctx *ctx = cred_ctx(cred);
struct aa_label *label = NULL;
if (strcmp(name, "current") == 0)
label = aa_get_newest_label(ctx->label);
else if (strcmp(name, "prev") == 0 && ctx->previous)
label = aa_get_newest_label(ctx->previous);
else if (strcmp(name, "exec") == 0 && ctx->onexec)
label = aa_get_newest_label(ctx->onexec);
else
error = -EINVAL;
if (label)
error = aa_getprocattr(label, value);
aa_put_label(label);
put_cred(cred);
return error;
}
static int apparmor_setprocattr(const char *name, void *value,
size_t size)
{
char *command, *largs = NULL, *args = value;
size_t arg_size;
int error;
DEFINE_AUDIT_DATA(sa, LSM_AUDIT_DATA_NONE, OP_SETPROCATTR);
if (size == 0)
return -EINVAL;
if (args[size - 1] != '\0') {
largs = args = kmalloc(size + 1, GFP_KERNEL);
if (!args)
return -ENOMEM;
memcpy(args, value, size);
args[size] = '\0';
}
error = -EINVAL;
args = strim(args);
command = strsep(&args, " ");
if (!args)
goto out;
args = skip_spaces(args);
if (!*args)
goto out;
arg_size = size - (args - (largs ? largs : (char *) value));
if (strcmp(name, "current") == 0) {
if (strcmp(command, "changehat") == 0) {
error = aa_setprocattr_changehat(args, arg_size,
AA_CHANGE_NOFLAGS);
} else if (strcmp(command, "permhat") == 0) {
error = aa_setprocattr_changehat(args, arg_size,
AA_CHANGE_TEST);
} else if (strcmp(command, "changeprofile") == 0) {
error = aa_change_profile(args, AA_CHANGE_NOFLAGS);
} else if (strcmp(command, "permprofile") == 0) {
error = aa_change_profile(args, AA_CHANGE_TEST);
} else if (strcmp(command, "stack") == 0) {
error = aa_change_profile(args, AA_CHANGE_STACK);
} else
goto fail;
} else if (strcmp(name, "exec") == 0) {
if (strcmp(command, "exec") == 0)
error = aa_change_profile(args, AA_CHANGE_ONEXEC);
else if (strcmp(command, "stack") == 0)
error = aa_change_profile(args, (AA_CHANGE_ONEXEC |
AA_CHANGE_STACK));
else
goto fail;
} else
goto fail;
if (!error)
error = size;
out:
kfree(largs);
return error;
fail:
aad(&sa)->label = begin_current_label_crit_section();
aad(&sa)->info = name;
aad(&sa)->error = error = -EINVAL;
aa_audit_msg(AUDIT_APPARMOR_DENIED, &sa, NULL);
end_current_label_crit_section(aad(&sa)->label);
goto out;
}
static void apparmor_bprm_committing_creds(struct linux_binprm *bprm)
{
struct aa_label *label = aa_current_raw_label();
struct aa_task_ctx *new_ctx = cred_ctx(bprm->cred);
if ((new_ctx->label->proxy == label->proxy) ||
(unconfined(new_ctx->label)))
return;
aa_inherit_files(bprm->cred, current->files);
current->pdeath_signal = 0;
__aa_transition_rlimits(label, new_ctx->label);
}
static void apparmor_bprm_committed_creds(struct linux_binprm *bprm)
{
return;
}
static int apparmor_task_setrlimit(struct task_struct *task,
unsigned int resource, struct rlimit *new_rlim)
{
struct aa_label *label = __begin_current_label_crit_section();
int error = 0;
if (!unconfined(label))
error = aa_task_setrlimit(label, task, resource, new_rlim);
__end_current_label_crit_section(label);
return error;
}
static int apparmor_task_kill(struct task_struct *target, struct siginfo *info,
int sig, u32 secid)
{
struct aa_label *cl, *tl;
int error;
if (secid)
return 0;
cl = __begin_current_label_crit_section();
tl = aa_get_task_label(target);
error = aa_may_signal(cl, tl, sig);
aa_put_label(tl);
__end_current_label_crit_section(cl);
return error;
}
static int __init apparmor_enabled_setup(char *str)
{
unsigned long enabled;
int error = kstrtoul(str, 0, &enabled);
if (!error)
apparmor_enabled = enabled ? 1 : 0;
return 1;
}
static int param_set_aalockpolicy(const char *val, const struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_admin_capable(NULL))
return -EPERM;
return param_set_bool(val, kp);
}
static int param_get_aalockpolicy(char *buffer, const struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_view_capable(NULL))
return -EPERM;
return param_get_bool(buffer, kp);
}
static int param_set_aabool(const char *val, const struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_admin_capable(NULL))
return -EPERM;
return param_set_bool(val, kp);
}
static int param_get_aabool(char *buffer, const struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_view_capable(NULL))
return -EPERM;
return param_get_bool(buffer, kp);
}
static int param_set_aauint(const char *val, const struct kernel_param *kp)
{
int error;
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized)
return -EPERM;
error = param_set_uint(val, kp);
pr_info("AppArmor: buffer size set to %d bytes\n", aa_g_path_max);
return error;
}
static int param_get_aauint(char *buffer, const struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_view_capable(NULL))
return -EPERM;
return param_get_uint(buffer, kp);
}
static int param_get_audit(char *buffer, struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_view_capable(NULL))
return -EPERM;
return sprintf(buffer, "%s", audit_mode_names[aa_g_audit]);
}
static int param_set_audit(const char *val, struct kernel_param *kp)
{
int i;
if (!apparmor_enabled)
return -EINVAL;
if (!val)
return -EINVAL;
if (apparmor_initialized && !policy_admin_capable(NULL))
return -EPERM;
for (i = 0; i < AUDIT_MAX_INDEX; i++) {
if (strcmp(val, audit_mode_names[i]) == 0) {
aa_g_audit = i;
return 0;
}
}
return -EINVAL;
}
static int param_get_mode(char *buffer, struct kernel_param *kp)
{
if (!apparmor_enabled)
return -EINVAL;
if (apparmor_initialized && !policy_view_capable(NULL))
return -EPERM;
return sprintf(buffer, "%s", aa_profile_mode_names[aa_g_profile_mode]);
}
static int param_set_mode(const char *val, struct kernel_param *kp)
{
int i;
if (!apparmor_enabled)
return -EINVAL;
if (!val)
return -EINVAL;
if (apparmor_initialized && !policy_admin_capable(NULL))
return -EPERM;
for (i = 0; i < APPARMOR_MODE_NAMES_MAX_INDEX; i++) {
if (strcmp(val, aa_profile_mode_names[i]) == 0) {
aa_g_profile_mode = i;
return 0;
}
}
return -EINVAL;
}
static int __init set_init_ctx(void)
{
struct cred *cred = (struct cred *)current->real_cred;
struct aa_task_ctx *ctx;
ctx = aa_alloc_task_context(GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->label = aa_get_label(ns_unconfined(root_ns));
cred_ctx(cred) = ctx;
return 0;
}
static void destroy_buffers(void)
{
u32 i, j;
for_each_possible_cpu(i) {
for_each_cpu_buffer(j) {
kfree(per_cpu(aa_buffers, i).buf[j]);
per_cpu(aa_buffers, i).buf[j] = NULL;
}
}
}
static int __init alloc_buffers(void)
{
u32 i, j;
for_each_possible_cpu(i) {
for_each_cpu_buffer(j) {
char *buffer;
if (cpu_to_node(i) > num_online_nodes())
buffer = kmalloc(aa_g_path_max, GFP_KERNEL);
else
buffer = kmalloc_node(aa_g_path_max, GFP_KERNEL,
cpu_to_node(i));
if (!buffer) {
destroy_buffers();
return -ENOMEM;
}
per_cpu(aa_buffers, i).buf[j] = buffer;
}
}
return 0;
}
static int apparmor_dointvec(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
if (!policy_admin_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return proc_dointvec(table, write, buffer, lenp, ppos);
}
static int __init apparmor_init_sysctl(void)
{
return register_sysctl_paths(apparmor_sysctl_path,
apparmor_sysctl_table) ? 0 : -ENOMEM;
}
static inline int apparmor_init_sysctl(void)
{
return 0;
}
static int __init apparmor_init(void)
{
int error;
if (!apparmor_enabled || !security_module_enable("apparmor")) {
aa_info_message("AppArmor disabled by boot time parameter");
apparmor_enabled = 0;
return 0;
}
error = aa_setup_dfa_engine();
if (error) {
AA_ERROR("Unable to setup dfa engine\n");
goto alloc_out;
}
error = aa_alloc_root_ns();
if (error) {
AA_ERROR("Unable to allocate default profile namespace\n");
goto alloc_out;
}
error = apparmor_init_sysctl();
if (error) {
AA_ERROR("Unable to register sysctls\n");
goto alloc_out;
}
error = alloc_buffers();
if (error) {
AA_ERROR("Unable to allocate work buffers\n");
goto buffers_out;
}
error = set_init_ctx();
if (error) {
AA_ERROR("Failed to set context on init task\n");
aa_free_root_ns();
goto buffers_out;
}
security_add_hooks(apparmor_hooks, ARRAY_SIZE(apparmor_hooks),
"apparmor");
apparmor_initialized = 1;
if (aa_g_profile_mode == APPARMOR_COMPLAIN)
aa_info_message("AppArmor initialized: complain mode enabled");
else if (aa_g_profile_mode == APPARMOR_KILL)
aa_info_message("AppArmor initialized: kill mode enabled");
else
aa_info_message("AppArmor initialized");
return error;
buffers_out:
destroy_buffers();
alloc_out:
aa_destroy_aafs();
aa_teardown_dfa_engine();
apparmor_enabled = 0;
return error;
}
