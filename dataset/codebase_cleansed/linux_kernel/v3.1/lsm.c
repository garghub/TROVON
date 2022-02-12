static void apparmor_cred_free(struct cred *cred)
{
aa_free_task_context(cred->security);
cred->security = NULL;
}
static int apparmor_cred_alloc_blank(struct cred *cred, gfp_t gfp)
{
struct aa_task_cxt *cxt = aa_alloc_task_context(gfp);
if (!cxt)
return -ENOMEM;
cred->security = cxt;
return 0;
}
static int apparmor_cred_prepare(struct cred *new, const struct cred *old,
gfp_t gfp)
{
struct aa_task_cxt *cxt = aa_alloc_task_context(gfp);
if (!cxt)
return -ENOMEM;
aa_dup_task_context(cxt, old->security);
new->security = cxt;
return 0;
}
static void apparmor_cred_transfer(struct cred *new, const struct cred *old)
{
const struct aa_task_cxt *old_cxt = old->security;
struct aa_task_cxt *new_cxt = new->security;
aa_dup_task_context(new_cxt, old_cxt);
}
static int apparmor_ptrace_access_check(struct task_struct *child,
unsigned int mode)
{
int error = cap_ptrace_access_check(child, mode);
if (error)
return error;
return aa_ptrace(current, child, mode);
}
static int apparmor_ptrace_traceme(struct task_struct *parent)
{
int error = cap_ptrace_traceme(parent);
if (error)
return error;
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
*effective = cred->cap_effective;
*inheritable = cred->cap_inheritable;
*permitted = cred->cap_permitted;
if (!unconfined(profile) && !COMPLAIN_MODE(profile)) {
*effective = cap_intersect(*effective, profile->caps.allow);
*permitted = cap_intersect(*permitted, profile->caps.allow);
}
rcu_read_unlock();
return 0;
}
static int apparmor_capable(struct task_struct *task, const struct cred *cred,
struct user_namespace *ns, int cap, int audit)
{
struct aa_profile *profile;
int error = cap_capable(task, cred, ns, cap, audit);
if (!error) {
profile = aa_cred_profile(cred);
if (!unconfined(profile))
error = aa_capable(task, profile, cap, audit);
}
return error;
}
static int common_perm(int op, struct path *path, u32 mask,
struct path_cond *cond)
{
struct aa_profile *profile;
int error = 0;
profile = __aa_current_profile();
if (!unconfined(profile))
error = aa_path_perm(op, profile, path, 0, mask, cond);
return error;
}
static int common_perm_dir_dentry(int op, struct path *dir,
struct dentry *dentry, u32 mask,
struct path_cond *cond)
{
struct path path = { dir->mnt, dentry };
return common_perm(op, &path, mask, cond);
}
static int common_perm_mnt_dentry(int op, struct vfsmount *mnt,
struct dentry *dentry, u32 mask)
{
struct path path = { mnt, dentry };
struct path_cond cond = { dentry->d_inode->i_uid,
dentry->d_inode->i_mode
};
return common_perm(op, &path, mask, &cond);
}
static int common_perm_rm(int op, struct path *dir,
struct dentry *dentry, u32 mask)
{
struct inode *inode = dentry->d_inode;
struct path_cond cond = { };
if (!inode || !dir->mnt || !mediated_filesystem(inode))
return 0;
cond.uid = inode->i_uid;
cond.mode = inode->i_mode;
return common_perm_dir_dentry(op, dir, dentry, mask, &cond);
}
static int common_perm_create(int op, struct path *dir, struct dentry *dentry,
u32 mask, umode_t mode)
{
struct path_cond cond = { current_fsuid(), mode };
if (!dir->mnt || !mediated_filesystem(dir->dentry->d_inode))
return 0;
return common_perm_dir_dentry(op, dir, dentry, mask, &cond);
}
static int apparmor_path_unlink(struct path *dir, struct dentry *dentry)
{
return common_perm_rm(OP_UNLINK, dir, dentry, AA_MAY_DELETE);
}
static int apparmor_path_mkdir(struct path *dir, struct dentry *dentry,
int mode)
{
return common_perm_create(OP_MKDIR, dir, dentry, AA_MAY_CREATE,
S_IFDIR);
}
static int apparmor_path_rmdir(struct path *dir, struct dentry *dentry)
{
return common_perm_rm(OP_RMDIR, dir, dentry, AA_MAY_DELETE);
}
static int apparmor_path_mknod(struct path *dir, struct dentry *dentry,
int mode, unsigned int dev)
{
return common_perm_create(OP_MKNOD, dir, dentry, AA_MAY_CREATE, mode);
}
static int apparmor_path_truncate(struct path *path)
{
struct path_cond cond = { path->dentry->d_inode->i_uid,
path->dentry->d_inode->i_mode
};
if (!path->mnt || !mediated_filesystem(path->dentry->d_inode))
return 0;
return common_perm(OP_TRUNC, path, MAY_WRITE | AA_MAY_META_WRITE,
&cond);
}
static int apparmor_path_symlink(struct path *dir, struct dentry *dentry,
const char *old_name)
{
return common_perm_create(OP_SYMLINK, dir, dentry, AA_MAY_CREATE,
S_IFLNK);
}
static int apparmor_path_link(struct dentry *old_dentry, struct path *new_dir,
struct dentry *new_dentry)
{
struct aa_profile *profile;
int error = 0;
if (!mediated_filesystem(old_dentry->d_inode))
return 0;
profile = aa_current_profile();
if (!unconfined(profile))
error = aa_path_link(profile, old_dentry, new_dir, new_dentry);
return error;
}
static int apparmor_path_rename(struct path *old_dir, struct dentry *old_dentry,
struct path *new_dir, struct dentry *new_dentry)
{
struct aa_profile *profile;
int error = 0;
if (!mediated_filesystem(old_dentry->d_inode))
return 0;
profile = aa_current_profile();
if (!unconfined(profile)) {
struct path old_path = { old_dir->mnt, old_dentry };
struct path new_path = { new_dir->mnt, new_dentry };
struct path_cond cond = { old_dentry->d_inode->i_uid,
old_dentry->d_inode->i_mode
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
static int apparmor_path_chmod(struct dentry *dentry, struct vfsmount *mnt,
mode_t mode)
{
if (!mediated_filesystem(dentry->d_inode))
return 0;
return common_perm_mnt_dentry(OP_CHMOD, mnt, dentry, AA_MAY_CHMOD);
}
static int apparmor_path_chown(struct path *path, uid_t uid, gid_t gid)
{
struct path_cond cond = { path->dentry->d_inode->i_uid,
path->dentry->d_inode->i_mode
};
if (!mediated_filesystem(path->dentry->d_inode))
return 0;
return common_perm(OP_CHOWN, path, AA_MAY_CHOWN, &cond);
}
static int apparmor_inode_getattr(struct vfsmount *mnt, struct dentry *dentry)
{
if (!mediated_filesystem(dentry->d_inode))
return 0;
return common_perm_mnt_dentry(OP_GETATTR, mnt, dentry,
AA_MAY_META_READ);
}
static int apparmor_dentry_open(struct file *file, const struct cred *cred)
{
struct aa_file_cxt *fcxt = file->f_security;
struct aa_profile *profile;
int error = 0;
if (!mediated_filesystem(file->f_path.dentry->d_inode))
return 0;
if (current->in_execve) {
fcxt->allow = MAY_EXEC | MAY_READ | AA_EXEC_MMAP;
return 0;
}
profile = aa_cred_profile(cred);
if (!unconfined(profile)) {
struct inode *inode = file->f_path.dentry->d_inode;
struct path_cond cond = { inode->i_uid, inode->i_mode };
error = aa_path_perm(OP_OPEN, profile, &file->f_path, 0,
aa_map_file_to_perms(file), &cond);
fcxt->allow = aa_map_file_to_perms(file);
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
struct aa_file_cxt *cxt = file->f_security;
aa_free_file_context(cxt);
}
static int common_file_perm(int op, struct file *file, u32 mask)
{
struct aa_file_cxt *fcxt = file->f_security;
struct aa_profile *profile, *fprofile = aa_cred_profile(file->f_cred);
int error = 0;
BUG_ON(!fprofile);
if (!file->f_path.mnt ||
!mediated_filesystem(file->f_path.dentry->d_inode))
return 0;
profile = __aa_current_profile();
if (!unconfined(profile) && !unconfined(fprofile) &&
((fprofile != profile) || (mask & ~fcxt->allow)))
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
static int common_mmap(int op, struct file *file, unsigned long prot,
unsigned long flags)
{
struct dentry *dentry;
int mask = 0;
if (!file || !file->f_security)
return 0;
if (prot & PROT_READ)
mask |= MAY_READ;
if ((prot & PROT_WRITE) && !(flags & MAP_PRIVATE))
mask |= MAY_WRITE;
if (prot & PROT_EXEC)
mask |= AA_EXEC_MMAP;
dentry = file->f_path.dentry;
return common_file_perm(op, file, mask);
}
static int apparmor_file_mmap(struct file *file, unsigned long reqprot,
unsigned long prot, unsigned long flags,
unsigned long addr, unsigned long addr_only)
{
int rc = 0;
rc = cap_file_mmap(file, reqprot, prot, flags, addr, addr_only);
if (rc || addr_only)
return rc;
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
struct aa_profile *profile;
const struct cred *cred = get_task_cred(task);
struct aa_task_cxt *cxt = cred->security;
profile = aa_cred_profile(cred);
if (strcmp(name, "current") == 0)
error = aa_getprocattr(aa_newest_version(cxt->profile),
value);
else if (strcmp(name, "prev") == 0 && cxt->previous)
error = aa_getprocattr(aa_newest_version(cxt->previous),
value);
else if (strcmp(name, "exec") == 0 && cxt->onexec)
error = aa_getprocattr(aa_newest_version(cxt->onexec),
value);
else
error = -EINVAL;
put_cred(cred);
return error;
}
static int apparmor_setprocattr(struct task_struct *task, char *name,
void *value, size_t size)
{
char *command, *args = value;
size_t arg_size;
int error;
if (size == 0)
return -EINVAL;
if (args[size - 1] != '\0') {
if (size == PAGE_SIZE)
return -EINVAL;
args[size] = '\0';
}
if (current != task)
return -EACCES;
args = value;
args = strim(args);
command = strsep(&args, " ");
if (!args)
return -EINVAL;
args = skip_spaces(args);
if (!*args)
return -EINVAL;
arg_size = size - (args - (char *) value);
if (strcmp(name, "current") == 0) {
if (strcmp(command, "changehat") == 0) {
error = aa_setprocattr_changehat(args, arg_size,
!AA_DO_TEST);
} else if (strcmp(command, "permhat") == 0) {
error = aa_setprocattr_changehat(args, arg_size,
AA_DO_TEST);
} else if (strcmp(command, "changeprofile") == 0) {
error = aa_setprocattr_changeprofile(args, !AA_ONEXEC,
!AA_DO_TEST);
} else if (strcmp(command, "permprofile") == 0) {
error = aa_setprocattr_changeprofile(args, !AA_ONEXEC,
AA_DO_TEST);
} else if (strcmp(command, "permipc") == 0) {
error = aa_setprocattr_permipc(args);
} else {
struct common_audit_data sa;
COMMON_AUDIT_DATA_INIT(&sa, NONE);
sa.aad.op = OP_SETPROCATTR;
sa.aad.info = name;
sa.aad.error = -EINVAL;
return aa_audit(AUDIT_APPARMOR_DENIED,
__aa_current_profile(), GFP_KERNEL,
&sa, NULL);
}
} else if (strcmp(name, "exec") == 0) {
error = aa_setprocattr_changeprofile(args, AA_ONEXEC,
!AA_DO_TEST);
} else {
return -EINVAL;
}
if (!error)
error = size;
return error;
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
int error = strict_strtoul(str, 0, &enabled);
if (!error)
apparmor_enabled = enabled ? 1 : 0;
return 1;
}
static int param_set_aalockpolicy(const char *val, const struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (aa_g_lock_policy)
return -EACCES;
return param_set_bool(val, kp);
}
static int param_get_aalockpolicy(char *buffer, const struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return param_get_bool(buffer, kp);
}
static int param_set_aabool(const char *val, const struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return param_set_bool(val, kp);
}
static int param_get_aabool(char *buffer, const struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return param_get_bool(buffer, kp);
}
static int param_set_aauint(const char *val, const struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return param_set_uint(val, kp);
}
static int param_get_aauint(char *buffer, const struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return param_get_uint(buffer, kp);
}
static int param_get_audit(char *buffer, struct kernel_param *kp)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return sprintf(buffer, "%s", audit_mode_names[aa_g_audit]);
}
static int param_set_audit(const char *val, struct kernel_param *kp)
{
int i;
if (!capable(CAP_MAC_ADMIN))
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
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
return sprintf(buffer, "%s", profile_mode_names[aa_g_profile_mode]);
}
static int param_set_mode(const char *val, struct kernel_param *kp)
{
int i;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (!apparmor_enabled)
return -EINVAL;
if (!val)
return -EINVAL;
for (i = 0; i < APPARMOR_NAMES_MAX_INDEX; i++) {
if (strcmp(val, profile_mode_names[i]) == 0) {
aa_g_profile_mode = i;
return 0;
}
}
return -EINVAL;
}
static int __init set_init_cxt(void)
{
struct cred *cred = (struct cred *)current->real_cred;
struct aa_task_cxt *cxt;
cxt = aa_alloc_task_context(GFP_KERNEL);
if (!cxt)
return -ENOMEM;
cxt->profile = aa_get_profile(root_ns->unconfined);
cred->security = cxt;
return 0;
}
static int __init apparmor_init(void)
{
int error;
if (!apparmor_enabled || !security_module_enable(&apparmor_ops)) {
aa_info_message("AppArmor disabled by boot time parameter");
apparmor_enabled = 0;
return 0;
}
error = aa_alloc_root_ns();
if (error) {
AA_ERROR("Unable to allocate default profile namespace\n");
goto alloc_out;
}
error = set_init_cxt();
if (error) {
AA_ERROR("Failed to set context on init task\n");
goto register_security_out;
}
error = register_security(&apparmor_ops);
if (error) {
AA_ERROR("Unable to register AppArmor\n");
goto set_init_cxt_out;
}
apparmor_initialized = 1;
if (aa_g_profile_mode == APPARMOR_COMPLAIN)
aa_info_message("AppArmor initialized: complain mode enabled");
else if (aa_g_profile_mode == APPARMOR_KILL)
aa_info_message("AppArmor initialized: kill mode enabled");
else
aa_info_message("AppArmor initialized");
return error;
set_init_cxt_out:
aa_free_task_context(current->real_cred->security);
register_security_out:
aa_free_root_ns();
alloc_out:
aa_destroy_aafs();
apparmor_enabled = 0;
return error;
}
