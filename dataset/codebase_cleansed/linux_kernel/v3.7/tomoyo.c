static int tomoyo_cred_alloc_blank(struct cred *new, gfp_t gfp)
{
new->security = NULL;
return 0;
}
static int tomoyo_cred_prepare(struct cred *new, const struct cred *old,
gfp_t gfp)
{
struct tomoyo_domain_info *domain = old->security;
new->security = domain;
if (domain)
atomic_inc(&domain->users);
return 0;
}
static void tomoyo_cred_transfer(struct cred *new, const struct cred *old)
{
tomoyo_cred_prepare(new, old, 0);
}
static void tomoyo_cred_free(struct cred *cred)
{
struct tomoyo_domain_info *domain = cred->security;
if (domain)
atomic_dec(&domain->users);
}
static int tomoyo_bprm_set_creds(struct linux_binprm *bprm)
{
int rc;
rc = cap_bprm_set_creds(bprm);
if (rc)
return rc;
if (bprm->cred_prepared)
return 0;
#ifndef CONFIG_SECURITY_TOMOYO_OMIT_USERSPACE_LOADER
if (!tomoyo_policy_loaded)
tomoyo_load_policy(bprm->filename);
#endif
atomic_dec(&((struct tomoyo_domain_info *)
bprm->cred->security)->users);
bprm->cred->security = NULL;
return 0;
}
static int tomoyo_bprm_check_security(struct linux_binprm *bprm)
{
struct tomoyo_domain_info *domain = bprm->cred->security;
if (!domain) {
const int idx = tomoyo_read_lock();
const int err = tomoyo_find_next_domain(bprm);
tomoyo_read_unlock(idx);
return err;
}
return tomoyo_check_open_permission(domain, &bprm->file->f_path,
O_RDONLY);
}
static int tomoyo_inode_getattr(struct vfsmount *mnt, struct dentry *dentry)
{
struct path path = { mnt, dentry };
return tomoyo_path_perm(TOMOYO_TYPE_GETATTR, &path, NULL);
}
static int tomoyo_path_truncate(struct path *path)
{
return tomoyo_path_perm(TOMOYO_TYPE_TRUNCATE, path, NULL);
}
static int tomoyo_path_unlink(struct path *parent, struct dentry *dentry)
{
struct path path = { parent->mnt, dentry };
return tomoyo_path_perm(TOMOYO_TYPE_UNLINK, &path, NULL);
}
static int tomoyo_path_mkdir(struct path *parent, struct dentry *dentry,
umode_t mode)
{
struct path path = { parent->mnt, dentry };
return tomoyo_path_number_perm(TOMOYO_TYPE_MKDIR, &path,
mode & S_IALLUGO);
}
static int tomoyo_path_rmdir(struct path *parent, struct dentry *dentry)
{
struct path path = { parent->mnt, dentry };
return tomoyo_path_perm(TOMOYO_TYPE_RMDIR, &path, NULL);
}
static int tomoyo_path_symlink(struct path *parent, struct dentry *dentry,
const char *old_name)
{
struct path path = { parent->mnt, dentry };
return tomoyo_path_perm(TOMOYO_TYPE_SYMLINK, &path, old_name);
}
static int tomoyo_path_mknod(struct path *parent, struct dentry *dentry,
umode_t mode, unsigned int dev)
{
struct path path = { parent->mnt, dentry };
int type = TOMOYO_TYPE_CREATE;
const unsigned int perm = mode & S_IALLUGO;
switch (mode & S_IFMT) {
case S_IFCHR:
type = TOMOYO_TYPE_MKCHAR;
break;
case S_IFBLK:
type = TOMOYO_TYPE_MKBLOCK;
break;
default:
goto no_dev;
}
return tomoyo_mkdev_perm(type, &path, perm, dev);
no_dev:
switch (mode & S_IFMT) {
case S_IFIFO:
type = TOMOYO_TYPE_MKFIFO;
break;
case S_IFSOCK:
type = TOMOYO_TYPE_MKSOCK;
break;
}
return tomoyo_path_number_perm(type, &path, perm);
}
static int tomoyo_path_link(struct dentry *old_dentry, struct path *new_dir,
struct dentry *new_dentry)
{
struct path path1 = { new_dir->mnt, old_dentry };
struct path path2 = { new_dir->mnt, new_dentry };
return tomoyo_path2_perm(TOMOYO_TYPE_LINK, &path1, &path2);
}
static int tomoyo_path_rename(struct path *old_parent,
struct dentry *old_dentry,
struct path *new_parent,
struct dentry *new_dentry)
{
struct path path1 = { old_parent->mnt, old_dentry };
struct path path2 = { new_parent->mnt, new_dentry };
return tomoyo_path2_perm(TOMOYO_TYPE_RENAME, &path1, &path2);
}
static int tomoyo_file_fcntl(struct file *file, unsigned int cmd,
unsigned long arg)
{
if (!(cmd == F_SETFL && ((arg ^ file->f_flags) & O_APPEND)))
return 0;
return tomoyo_check_open_permission(tomoyo_domain(), &file->f_path,
O_WRONLY | (arg & O_APPEND));
}
static int tomoyo_file_open(struct file *f, const struct cred *cred)
{
int flags = f->f_flags;
if (current->in_execve)
return 0;
return tomoyo_check_open_permission(tomoyo_domain(), &f->f_path, flags);
}
static int tomoyo_file_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
return tomoyo_path_number_perm(TOMOYO_TYPE_IOCTL, &file->f_path, cmd);
}
static int tomoyo_path_chmod(struct path *path, umode_t mode)
{
return tomoyo_path_number_perm(TOMOYO_TYPE_CHMOD, path,
mode & S_IALLUGO);
}
static int tomoyo_path_chown(struct path *path, kuid_t uid, kgid_t gid)
{
int error = 0;
if (uid_valid(uid))
error = tomoyo_path_number_perm(TOMOYO_TYPE_CHOWN, path,
from_kuid(&init_user_ns, uid));
if (!error && gid_valid(gid))
error = tomoyo_path_number_perm(TOMOYO_TYPE_CHGRP, path,
from_kgid(&init_user_ns, gid));
return error;
}
static int tomoyo_path_chroot(struct path *path)
{
return tomoyo_path_perm(TOMOYO_TYPE_CHROOT, path, NULL);
}
static int tomoyo_sb_mount(const char *dev_name, struct path *path,
const char *type, unsigned long flags, void *data)
{
return tomoyo_mount_permission(dev_name, path, type, flags, data);
}
static int tomoyo_sb_umount(struct vfsmount *mnt, int flags)
{
struct path path = { mnt, mnt->mnt_root };
return tomoyo_path_perm(TOMOYO_TYPE_UMOUNT, &path, NULL);
}
static int tomoyo_sb_pivotroot(struct path *old_path, struct path *new_path)
{
return tomoyo_path2_perm(TOMOYO_TYPE_PIVOT_ROOT, new_path, old_path);
}
static int tomoyo_socket_listen(struct socket *sock, int backlog)
{
return tomoyo_socket_listen_permission(sock);
}
static int tomoyo_socket_connect(struct socket *sock, struct sockaddr *addr,
int addr_len)
{
return tomoyo_socket_connect_permission(sock, addr, addr_len);
}
static int tomoyo_socket_bind(struct socket *sock, struct sockaddr *addr,
int addr_len)
{
return tomoyo_socket_bind_permission(sock, addr, addr_len);
}
static int tomoyo_socket_sendmsg(struct socket *sock, struct msghdr *msg,
int size)
{
return tomoyo_socket_sendmsg_permission(sock, msg, size);
}
static int __init tomoyo_init(void)
{
struct cred *cred = (struct cred *) current_cred();
if (!security_module_enable(&tomoyo_security_ops))
return 0;
if (register_security(&tomoyo_security_ops) ||
init_srcu_struct(&tomoyo_ss))
panic("Failure registering TOMOYO Linux");
printk(KERN_INFO "TOMOYO Linux initialized\n");
cred->security = &tomoyo_kernel_domain;
tomoyo_mm_init();
return 0;
}
