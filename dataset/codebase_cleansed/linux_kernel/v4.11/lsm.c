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
return aa_ptrace(current, child, mode);
}
static int apparmor_ptrace_traceme(struct task_struct *parent)
{
return aa_ptrace(parent, current, PTRACE_MODE_ATTACH);
}
static int apparmor_capget(struct task_struct *target, kernel_cap_t *effective,
kernel_cap_t *inheritable, kernel_cap_t *permitted)
{
struct aa_profile *profile;
const struct cred *cred;
rcu_read_lock();
cred = __task_cred(target);
profile = aa_cred_profile(cred);
if (!unconfined(profile) && !COMPLAIN_MODE(profile)) {
*effective = cap_intersect(*effective, profile->caps.allow);
*permitted = cap_intersect(*permitted, profile->caps.allow);
}
rcu_read_unlock();
return 0;
}
static int apparmor_capable(const struct cred *cred, struct user_namespace *ns,
int cap, int audit)
{
struct aa_profile *profile;
int error = 0;
profile = aa_cred_profile(cred);
if (!unconfined(profile))
error = aa_capable(profile, cap, audit);
return error;
}
static int common_perm(const char *op, const struct path *path, u32 mask,
struct path_cond *cond)
{
struct aa_profile *profile;
int error = 0;
profile = __aa_current_profile();
if (!unconfined(profile))
error = aa_path_perm(op, profile, path, 0, mask, cond);
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
return common_perm_cond(OP_TRUNC, path, MAY_WRITE | AA_MAY_META_WRITE);
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
struct aa_profile *profile;
int error = 0;
if (!path_mediated_fs(old_dentry))
return 0;
profile = aa_current_profile();
if (!unconfined(profile))
error = aa_path_link(profile, old_dentry, new_dir, new_dentry);
return error;
}
static int apparmor_path_rename(const struct path *old_dir, struct dentry *old_dentry,
const struct path *new_dir, struct dentry *new_dentry)
{
struct aa_profile *profile;
int error = 0;
if (!path_mediated_fs(old_dentry))
return 0;
profile = aa_current_profile();
if (!unconfined(profile)) {
struct path old_path = { .mnt = old_dir->mnt,
.dentry = old_dentry };
struct path new_path = { .mnt = new_dir->mnt,
.dentry = new_dentry };
struct path_cond cond = { d_backing_inode(old_dentry)->i_uid,
d_backing_inode(old_dentry)->i_mode
};
error = aa_path_perm(OP_RENAME_SRC, profile, &old_path, 0,
MAY_READ | AA_MAY_META_READ | MAY_WRITE |
AA_MAY_META_WRITE | AA_MAY_DELETE,
&cond);
if (!error)
error = aa_path_perm(OP_RENAME_DEST, profile, &new_path,
0, MAY_WRITE | AA_MAY_META_WRITE |
AA_MAY_CREATE, &cond);
}
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
return common_perm_cond(OP_GETATTR, path, AA_MAY_META_READ);
}
static int apparmor_file_open(struct file *file, const struct cred *cred)
{
struct aa_file_ctx *fctx = file->f_security;
struct aa_profile *profile;
int error = 0;
if (!path_mediated_fs(file->f_path.dentry))
return 0;
if (current->in_execve) {
fctx->allow = MAY_EXEC | MAY_READ | AA_EXEC_MMAP;
return 0;
}
profile = aa_cred_profile(cred);
if (!unconfined(profile)) {
struct inode *inode = file_inode(file);
struct path_cond cond = { inode->i_uid, inode->i_mode };
error = aa_path_perm(OP_OPEN, profile, &file->f_path, 0,
aa_map_file_to_perms(file), &cond);
fctx->allow = aa_map_file_to_perms(file);
}
return error;
}
static int apparmor_file_alloc_security(struct file *file)
{
file->f_security = aa_alloc_file_context(GFP_KERNEL);
if (!file->f_security)
return -ENOMEM;
return 0;
}
static void apparmor_file_free_security(struct file *file)
{
struct aa_file_ctx *ctx = file->f_security;
aa_free_file_context(ctx);
}
static int common_file_perm(const char *op, struct file *file, u32 mask)
{
struct aa_file_ctx *fctx = file->f_security;
struct aa_profile *profile, *fprofile = aa_cred_profile(file->f_cred);
int error = 0;
AA_BUG(!fprofile);
if (!file->f_path.mnt ||
!path_mediated_fs(file->f_path.dentry))
return 0;
profile = __aa_current_profile();
if (!unconfined(profile) && !unconfined(fprofile) &&
((fprofile != profile) || (mask & ~fctx->allow)))
error = aa_file_perm(op, profile, file, mask);
return error;
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
if (!file || !file->f_security)
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
static int apparmor_getprocattr(struct task_struct *task, char *name,
char **value)
{
int error = -ENOENT;
const struct cred *cred = get_task_cred(task);
struct aa_task_ctx *ctx = cred_ctx(cred);
struct aa_profile *profile = NULL;
if (strcmp(name, "current") == 0)
profile = aa_get_newest_profile(ctx->profile);
else if (strcmp(name, "prev") == 0 && ctx->previous)
profile = aa_get_newest_profile(ctx->previous);
else if (strcmp(name, "exec") == 0 && ctx->onexec)
profile = aa_get_newest_profile(ctx->onexec);
else
error = -EINVAL;
if (profile)
error = aa_getprocattr(profile, value);
aa_put_profile(profile);
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
!AA_DO_TEST);
} else if (strcmp(command, "permhat") == 0) {
error = aa_setprocattr_changehat(args, arg_size,
AA_DO_TEST);
} else if (strcmp(command, "changeprofile") == 0) {
error = aa_change_profile(args, !AA_ONEXEC,
!AA_DO_TEST, false);
} else if (strcmp(command, "permprofile") == 0) {
error = aa_change_profile(args, !AA_ONEXEC, AA_DO_TEST,
false);
} else
goto fail;
} else if (strcmp(name, "exec") == 0) {
if (strcmp(command, "exec") == 0)
error = aa_change_profile(args, AA_ONEXEC, !AA_DO_TEST,
false);
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
aad(&sa)->profile = aa_current_profile();
aad(&sa)->info = name;
aad(&sa)->error = error = -EINVAL;
aa_audit_msg(AUDIT_APPARMOR_DENIED, &sa, NULL);
goto out;
}
static int apparmor_task_setrlimit(struct task_struct *task,
unsigned int resource, struct rlimit *new_rlim)
{
struct aa_profile *profile = __aa_current_profile();
int error = 0;
if (!unconfined(profile))
error = aa_task_setrlimit(profile, task, resource, new_rlim);
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
if (!policy_admin_capable(NULL))
return -EPERM;
return param_set_bool(val, kp);
}
static int param_get_aalockpolicy(char *buffer, const struct kernel_param *kp)
{
if (!policy_view_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return param_get_bool(buffer, kp);
}
static int param_set_aabool(const char *val, const struct kernel_param *kp)
{
if (!policy_admin_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return param_set_bool(val, kp);
}
static int param_get_aabool(char *buffer, const struct kernel_param *kp)
{
if (!policy_view_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return param_get_bool(buffer, kp);
}
static int param_set_aauint(const char *val, const struct kernel_param *kp)
{
if (!policy_admin_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return param_set_uint(val, kp);
}
static int param_get_aauint(char *buffer, const struct kernel_param *kp)
{
if (!policy_view_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return param_get_uint(buffer, kp);
}
static int param_get_audit(char *buffer, struct kernel_param *kp)
{
if (!policy_view_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return sprintf(buffer, "%s", audit_mode_names[aa_g_audit]);
}
static int param_set_audit(const char *val, struct kernel_param *kp)
{
int i;
if (!policy_admin_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
if (!val)
return -EINVAL;
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
if (!policy_view_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return sprintf(buffer, "%s", aa_profile_mode_names[aa_g_profile_mode]);
}
static int param_set_mode(const char *val, struct kernel_param *kp)
{
int i;
if (!policy_admin_capable(NULL))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
if (!val)
return -EINVAL;
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
ctx->profile = aa_get_profile(root_ns->unconfined);
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
