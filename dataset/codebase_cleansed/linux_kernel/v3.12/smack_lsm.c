static struct smack_known *smk_fetch(const char *name, struct inode *ip,
struct dentry *dp)
{
int rc;
char *buffer;
struct smack_known *skp = NULL;
if (ip->i_op->getxattr == NULL)
return NULL;
buffer = kzalloc(SMK_LONGLABEL, GFP_KERNEL);
if (buffer == NULL)
return NULL;
rc = ip->i_op->getxattr(dp, name, buffer, SMK_LONGLABEL);
if (rc > 0)
skp = smk_import_entry(buffer, rc);
kfree(buffer);
return skp;
}
struct inode_smack *new_inode_smack(char *smack)
{
struct inode_smack *isp;
isp = kzalloc(sizeof(struct inode_smack), GFP_NOFS);
if (isp == NULL)
return NULL;
isp->smk_inode = smack;
isp->smk_flags = 0;
mutex_init(&isp->smk_lock);
return isp;
}
static struct task_smack *new_task_smack(struct smack_known *task,
struct smack_known *forked, gfp_t gfp)
{
struct task_smack *tsp;
tsp = kzalloc(sizeof(struct task_smack), gfp);
if (tsp == NULL)
return NULL;
tsp->smk_task = task;
tsp->smk_forked = forked;
INIT_LIST_HEAD(&tsp->smk_rules);
mutex_init(&tsp->smk_rules_lock);
return tsp;
}
static int smk_copy_rules(struct list_head *nhead, struct list_head *ohead,
gfp_t gfp)
{
struct smack_rule *nrp;
struct smack_rule *orp;
int rc = 0;
INIT_LIST_HEAD(nhead);
list_for_each_entry_rcu(orp, ohead, list) {
nrp = kzalloc(sizeof(struct smack_rule), gfp);
if (nrp == NULL) {
rc = -ENOMEM;
break;
}
*nrp = *orp;
list_add_rcu(&nrp->list, nhead);
}
return rc;
}
static int smack_ptrace_access_check(struct task_struct *ctp, unsigned int mode)
{
int rc;
struct smk_audit_info ad;
struct smack_known *skp;
rc = cap_ptrace_access_check(ctp, mode);
if (rc != 0)
return rc;
skp = smk_of_task(task_security(ctp));
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_TASK);
smk_ad_setfield_u_tsk(&ad, ctp);
rc = smk_curacc(skp->smk_known, MAY_READWRITE, &ad);
return rc;
}
static int smack_ptrace_traceme(struct task_struct *ptp)
{
int rc;
struct smk_audit_info ad;
struct smack_known *skp;
rc = cap_ptrace_traceme(ptp);
if (rc != 0)
return rc;
skp = smk_of_task(task_security(ptp));
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_TASK);
smk_ad_setfield_u_tsk(&ad, ptp);
rc = smk_curacc(skp->smk_known, MAY_READWRITE, &ad);
return rc;
}
static int smack_syslog(int typefrom_file)
{
int rc = 0;
struct smack_known *skp = smk_of_current();
if (smack_privileged(CAP_MAC_OVERRIDE))
return 0;
if (skp != &smack_known_floor)
rc = -EACCES;
return rc;
}
static int smack_sb_alloc_security(struct super_block *sb)
{
struct superblock_smack *sbsp;
sbsp = kzalloc(sizeof(struct superblock_smack), GFP_KERNEL);
if (sbsp == NULL)
return -ENOMEM;
sbsp->smk_root = smack_known_floor.smk_known;
sbsp->smk_default = smack_known_floor.smk_known;
sbsp->smk_floor = smack_known_floor.smk_known;
sbsp->smk_hat = smack_known_hat.smk_known;
sb->s_security = sbsp;
return 0;
}
static void smack_sb_free_security(struct super_block *sb)
{
kfree(sb->s_security);
sb->s_security = NULL;
}
static int smack_sb_copy_data(char *orig, char *smackopts)
{
char *cp, *commap, *otheropts, *dp;
otheropts = (char *)get_zeroed_page(GFP_KERNEL);
if (otheropts == NULL)
return -ENOMEM;
for (cp = orig, commap = orig; commap != NULL; cp = commap + 1) {
if (strstr(cp, SMK_FSDEFAULT) == cp)
dp = smackopts;
else if (strstr(cp, SMK_FSFLOOR) == cp)
dp = smackopts;
else if (strstr(cp, SMK_FSHAT) == cp)
dp = smackopts;
else if (strstr(cp, SMK_FSROOT) == cp)
dp = smackopts;
else if (strstr(cp, SMK_FSTRANS) == cp)
dp = smackopts;
else
dp = otheropts;
commap = strchr(cp, ',');
if (commap != NULL)
*commap = '\0';
if (*dp != '\0')
strcat(dp, ",");
strcat(dp, cp);
}
strcpy(orig, otheropts);
free_page((unsigned long)otheropts);
return 0;
}
static int smack_sb_kern_mount(struct super_block *sb, int flags, void *data)
{
struct dentry *root = sb->s_root;
struct inode *inode = root->d_inode;
struct superblock_smack *sp = sb->s_security;
struct inode_smack *isp;
char *op;
char *commap;
char *nsp;
int transmute = 0;
if (sp->smk_initialized)
return 0;
sp->smk_initialized = 1;
for (op = data; op != NULL; op = commap) {
commap = strchr(op, ',');
if (commap != NULL)
*commap++ = '\0';
if (strncmp(op, SMK_FSHAT, strlen(SMK_FSHAT)) == 0) {
op += strlen(SMK_FSHAT);
nsp = smk_import(op, 0);
if (nsp != NULL)
sp->smk_hat = nsp;
} else if (strncmp(op, SMK_FSFLOOR, strlen(SMK_FSFLOOR)) == 0) {
op += strlen(SMK_FSFLOOR);
nsp = smk_import(op, 0);
if (nsp != NULL)
sp->smk_floor = nsp;
} else if (strncmp(op, SMK_FSDEFAULT,
strlen(SMK_FSDEFAULT)) == 0) {
op += strlen(SMK_FSDEFAULT);
nsp = smk_import(op, 0);
if (nsp != NULL)
sp->smk_default = nsp;
} else if (strncmp(op, SMK_FSROOT, strlen(SMK_FSROOT)) == 0) {
op += strlen(SMK_FSROOT);
nsp = smk_import(op, 0);
if (nsp != NULL)
sp->smk_root = nsp;
} else if (strncmp(op, SMK_FSTRANS, strlen(SMK_FSTRANS)) == 0) {
op += strlen(SMK_FSTRANS);
nsp = smk_import(op, 0);
if (nsp != NULL) {
sp->smk_root = nsp;
transmute = 1;
}
}
}
isp = inode->i_security;
if (inode->i_security == NULL) {
inode->i_security = new_inode_smack(sp->smk_root);
isp = inode->i_security;
} else
isp->smk_inode = sp->smk_root;
if (transmute)
isp->smk_flags |= SMK_INODE_TRANSMUTE;
return 0;
}
static int smack_sb_statfs(struct dentry *dentry)
{
struct superblock_smack *sbp = dentry->d_sb->s_security;
int rc;
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
rc = smk_curacc(sbp->smk_floor, MAY_READ, &ad);
return rc;
}
static int smack_sb_mount(const char *dev_name, struct path *path,
const char *type, unsigned long flags, void *data)
{
struct superblock_smack *sbp = path->dentry->d_sb->s_security;
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_PATH);
smk_ad_setfield_u_fs_path(&ad, *path);
return smk_curacc(sbp->smk_floor, MAY_WRITE, &ad);
}
static int smack_sb_umount(struct vfsmount *mnt, int flags)
{
struct superblock_smack *sbp;
struct smk_audit_info ad;
struct path path;
path.dentry = mnt->mnt_root;
path.mnt = mnt;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_PATH);
smk_ad_setfield_u_fs_path(&ad, path);
sbp = path.dentry->d_sb->s_security;
return smk_curacc(sbp->smk_floor, MAY_WRITE, &ad);
}
static int smack_bprm_set_creds(struct linux_binprm *bprm)
{
struct inode *inode = file_inode(bprm->file);
struct task_smack *bsp = bprm->cred->security;
struct inode_smack *isp;
int rc;
rc = cap_bprm_set_creds(bprm);
if (rc != 0)
return rc;
if (bprm->cred_prepared)
return 0;
isp = inode->i_security;
if (isp->smk_task == NULL || isp->smk_task == bsp->smk_task)
return 0;
if (bprm->unsafe)
return -EPERM;
bsp->smk_task = isp->smk_task;
bprm->per_clear |= PER_CLEAR_ON_SETID;
return 0;
}
static void smack_bprm_committing_creds(struct linux_binprm *bprm)
{
struct task_smack *bsp = bprm->cred->security;
if (bsp->smk_task != bsp->smk_forked)
current->pdeath_signal = 0;
}
static int smack_bprm_secureexec(struct linux_binprm *bprm)
{
struct task_smack *tsp = current_security();
int ret = cap_bprm_secureexec(bprm);
if (!ret && (tsp->smk_task != tsp->smk_forked))
ret = 1;
return ret;
}
static int smack_inode_alloc_security(struct inode *inode)
{
struct smack_known *skp = smk_of_current();
inode->i_security = new_inode_smack(skp->smk_known);
if (inode->i_security == NULL)
return -ENOMEM;
return 0;
}
static void smack_inode_free_security(struct inode *inode)
{
kfree(inode->i_security);
inode->i_security = NULL;
}
static int smack_inode_init_security(struct inode *inode, struct inode *dir,
const struct qstr *qstr, const char **name,
void **value, size_t *len)
{
struct inode_smack *issp = inode->i_security;
struct smack_known *skp = smk_of_current();
char *isp = smk_of_inode(inode);
char *dsp = smk_of_inode(dir);
int may;
if (name)
*name = XATTR_SMACK_SUFFIX;
if (value) {
rcu_read_lock();
may = smk_access_entry(skp->smk_known, dsp, &skp->smk_rules);
rcu_read_unlock();
if (may > 0 && ((may & MAY_TRANSMUTE) != 0) &&
smk_inode_transmutable(dir)) {
isp = dsp;
issp->smk_flags |= SMK_INODE_CHANGED;
}
*value = kstrdup(isp, GFP_NOFS);
if (*value == NULL)
return -ENOMEM;
}
if (len)
*len = strlen(isp) + 1;
return 0;
}
static int smack_inode_link(struct dentry *old_dentry, struct inode *dir,
struct dentry *new_dentry)
{
char *isp;
struct smk_audit_info ad;
int rc;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, old_dentry);
isp = smk_of_inode(old_dentry->d_inode);
rc = smk_curacc(isp, MAY_WRITE, &ad);
if (rc == 0 && new_dentry->d_inode != NULL) {
isp = smk_of_inode(new_dentry->d_inode);
smk_ad_setfield_u_fs_path_dentry(&ad, new_dentry);
rc = smk_curacc(isp, MAY_WRITE, &ad);
}
return rc;
}
static int smack_inode_unlink(struct inode *dir, struct dentry *dentry)
{
struct inode *ip = dentry->d_inode;
struct smk_audit_info ad;
int rc;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
rc = smk_curacc(smk_of_inode(ip), MAY_WRITE, &ad);
if (rc == 0) {
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_INODE);
smk_ad_setfield_u_fs_inode(&ad, dir);
rc = smk_curacc(smk_of_inode(dir), MAY_WRITE, &ad);
}
return rc;
}
static int smack_inode_rmdir(struct inode *dir, struct dentry *dentry)
{
struct smk_audit_info ad;
int rc;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
rc = smk_curacc(smk_of_inode(dentry->d_inode), MAY_WRITE, &ad);
if (rc == 0) {
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_INODE);
smk_ad_setfield_u_fs_inode(&ad, dir);
rc = smk_curacc(smk_of_inode(dir), MAY_WRITE, &ad);
}
return rc;
}
static int smack_inode_rename(struct inode *old_inode,
struct dentry *old_dentry,
struct inode *new_inode,
struct dentry *new_dentry)
{
int rc;
char *isp;
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, old_dentry);
isp = smk_of_inode(old_dentry->d_inode);
rc = smk_curacc(isp, MAY_READWRITE, &ad);
if (rc == 0 && new_dentry->d_inode != NULL) {
isp = smk_of_inode(new_dentry->d_inode);
smk_ad_setfield_u_fs_path_dentry(&ad, new_dentry);
rc = smk_curacc(isp, MAY_READWRITE, &ad);
}
return rc;
}
static int smack_inode_permission(struct inode *inode, int mask)
{
struct smk_audit_info ad;
int no_block = mask & MAY_NOT_BLOCK;
mask &= (MAY_READ|MAY_WRITE|MAY_EXEC|MAY_APPEND);
if (mask == 0)
return 0;
if (no_block)
return -ECHILD;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_INODE);
smk_ad_setfield_u_fs_inode(&ad, inode);
return smk_curacc(smk_of_inode(inode), mask, &ad);
}
static int smack_inode_setattr(struct dentry *dentry, struct iattr *iattr)
{
struct smk_audit_info ad;
if (iattr->ia_valid & ATTR_FORCE)
return 0;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
return smk_curacc(smk_of_inode(dentry->d_inode), MAY_WRITE, &ad);
}
static int smack_inode_getattr(struct vfsmount *mnt, struct dentry *dentry)
{
struct smk_audit_info ad;
struct path path;
path.dentry = dentry;
path.mnt = mnt;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_PATH);
smk_ad_setfield_u_fs_path(&ad, path);
return smk_curacc(smk_of_inode(dentry->d_inode), MAY_READ, &ad);
}
static int smack_inode_setxattr(struct dentry *dentry, const char *name,
const void *value, size_t size, int flags)
{
struct smk_audit_info ad;
int rc = 0;
if (strcmp(name, XATTR_NAME_SMACK) == 0 ||
strcmp(name, XATTR_NAME_SMACKIPIN) == 0 ||
strcmp(name, XATTR_NAME_SMACKIPOUT) == 0 ||
strcmp(name, XATTR_NAME_SMACKEXEC) == 0 ||
strcmp(name, XATTR_NAME_SMACKMMAP) == 0) {
if (!smack_privileged(CAP_MAC_ADMIN))
rc = -EPERM;
if (size == 0 || size >= SMK_LONGLABEL ||
smk_import(value, size) == NULL)
rc = -EINVAL;
} else if (strcmp(name, XATTR_NAME_SMACKTRANSMUTE) == 0) {
if (!smack_privileged(CAP_MAC_ADMIN))
rc = -EPERM;
if (size != TRANS_TRUE_SIZE ||
strncmp(value, TRANS_TRUE, TRANS_TRUE_SIZE) != 0)
rc = -EINVAL;
} else
rc = cap_inode_setxattr(dentry, name, value, size, flags);
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
if (rc == 0)
rc = smk_curacc(smk_of_inode(dentry->d_inode), MAY_WRITE, &ad);
return rc;
}
static void smack_inode_post_setxattr(struct dentry *dentry, const char *name,
const void *value, size_t size, int flags)
{
struct smack_known *skp;
struct inode_smack *isp = dentry->d_inode->i_security;
if (strcmp(name, XATTR_NAME_SMACKTRANSMUTE) == 0) {
isp->smk_flags |= SMK_INODE_TRANSMUTE;
return;
}
skp = smk_import_entry(value, size);
if (strcmp(name, XATTR_NAME_SMACK) == 0) {
if (skp != NULL)
isp->smk_inode = skp->smk_known;
else
isp->smk_inode = smack_known_invalid.smk_known;
} else if (strcmp(name, XATTR_NAME_SMACKEXEC) == 0) {
if (skp != NULL)
isp->smk_task = skp;
else
isp->smk_task = &smack_known_invalid;
} else if (strcmp(name, XATTR_NAME_SMACKMMAP) == 0) {
if (skp != NULL)
isp->smk_mmap = skp;
else
isp->smk_mmap = &smack_known_invalid;
}
return;
}
static int smack_inode_getxattr(struct dentry *dentry, const char *name)
{
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
return smk_curacc(smk_of_inode(dentry->d_inode), MAY_READ, &ad);
}
static int smack_inode_removexattr(struct dentry *dentry, const char *name)
{
struct inode_smack *isp;
struct smk_audit_info ad;
int rc = 0;
if (strcmp(name, XATTR_NAME_SMACK) == 0 ||
strcmp(name, XATTR_NAME_SMACKIPIN) == 0 ||
strcmp(name, XATTR_NAME_SMACKIPOUT) == 0 ||
strcmp(name, XATTR_NAME_SMACKEXEC) == 0 ||
strcmp(name, XATTR_NAME_SMACKTRANSMUTE) == 0 ||
strcmp(name, XATTR_NAME_SMACKMMAP)) {
if (!smack_privileged(CAP_MAC_ADMIN))
rc = -EPERM;
} else
rc = cap_inode_removexattr(dentry, name);
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_DENTRY);
smk_ad_setfield_u_fs_path_dentry(&ad, dentry);
if (rc == 0)
rc = smk_curacc(smk_of_inode(dentry->d_inode), MAY_WRITE, &ad);
if (rc == 0) {
isp = dentry->d_inode->i_security;
isp->smk_task = NULL;
isp->smk_mmap = NULL;
}
return rc;
}
static int smack_inode_getsecurity(const struct inode *inode,
const char *name, void **buffer,
bool alloc)
{
struct socket_smack *ssp;
struct socket *sock;
struct super_block *sbp;
struct inode *ip = (struct inode *)inode;
char *isp;
int ilen;
int rc = 0;
if (strcmp(name, XATTR_SMACK_SUFFIX) == 0) {
isp = smk_of_inode(inode);
ilen = strlen(isp) + 1;
*buffer = isp;
return ilen;
}
sbp = ip->i_sb;
if (sbp->s_magic != SOCKFS_MAGIC)
return -EOPNOTSUPP;
sock = SOCKET_I(ip);
if (sock == NULL || sock->sk == NULL)
return -EOPNOTSUPP;
ssp = sock->sk->sk_security;
if (strcmp(name, XATTR_SMACK_IPIN) == 0)
isp = ssp->smk_in;
else if (strcmp(name, XATTR_SMACK_IPOUT) == 0)
isp = ssp->smk_out->smk_known;
else
return -EOPNOTSUPP;
ilen = strlen(isp) + 1;
if (rc == 0) {
*buffer = isp;
rc = ilen;
}
return rc;
}
static int smack_inode_listsecurity(struct inode *inode, char *buffer,
size_t buffer_size)
{
int len = strlen(XATTR_NAME_SMACK);
if (buffer != NULL && len <= buffer_size) {
memcpy(buffer, XATTR_NAME_SMACK, len);
return len;
}
return -EINVAL;
}
static void smack_inode_getsecid(const struct inode *inode, u32 *secid)
{
struct inode_smack *isp = inode->i_security;
*secid = smack_to_secid(isp->smk_inode);
}
static int smack_file_permission(struct file *file, int mask)
{
return 0;
}
static int smack_file_alloc_security(struct file *file)
{
struct smack_known *skp = smk_of_current();
file->f_security = skp->smk_known;
return 0;
}
static void smack_file_free_security(struct file *file)
{
file->f_security = NULL;
}
static int smack_file_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int rc = 0;
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_PATH);
smk_ad_setfield_u_fs_path(&ad, file->f_path);
if (_IOC_DIR(cmd) & _IOC_WRITE)
rc = smk_curacc(file->f_security, MAY_WRITE, &ad);
if (rc == 0 && (_IOC_DIR(cmd) & _IOC_READ))
rc = smk_curacc(file->f_security, MAY_READ, &ad);
return rc;
}
static int smack_file_lock(struct file *file, unsigned int cmd)
{
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_PATH);
smk_ad_setfield_u_fs_path(&ad, file->f_path);
return smk_curacc(file->f_security, MAY_WRITE, &ad);
}
static int smack_file_fcntl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct smk_audit_info ad;
int rc = 0;
switch (cmd) {
case F_GETLK:
case F_SETLK:
case F_SETLKW:
case F_SETOWN:
case F_SETSIG:
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_PATH);
smk_ad_setfield_u_fs_path(&ad, file->f_path);
rc = smk_curacc(file->f_security, MAY_WRITE, &ad);
break;
default:
break;
}
return rc;
}
static int smack_mmap_file(struct file *file,
unsigned long reqprot, unsigned long prot,
unsigned long flags)
{
struct smack_known *skp;
struct smack_known *mkp;
struct smack_rule *srp;
struct task_smack *tsp;
char *osmack;
struct inode_smack *isp;
int may;
int mmay;
int tmay;
int rc;
if (file == NULL)
return 0;
isp = file_inode(file)->i_security;
if (isp->smk_mmap == NULL)
return 0;
mkp = isp->smk_mmap;
tsp = current_security();
skp = smk_of_current();
rc = 0;
rcu_read_lock();
list_for_each_entry_rcu(srp, &skp->smk_rules, list) {
osmack = srp->smk_object;
if (mkp->smk_known == osmack)
continue;
may = smk_access_entry(srp->smk_subject->smk_known, osmack,
&tsp->smk_rules);
if (may == -ENOENT)
may = srp->smk_access;
else
may &= srp->smk_access;
if (may == 0)
continue;
mmay = smk_access_entry(mkp->smk_known, osmack,
&mkp->smk_rules);
if (mmay == -ENOENT) {
rc = -EACCES;
break;
}
tmay = smk_access_entry(mkp->smk_known, osmack,
&tsp->smk_rules);
if (tmay != -ENOENT)
mmay &= tmay;
if ((may | mmay) != mmay) {
rc = -EACCES;
break;
}
}
rcu_read_unlock();
return rc;
}
static int smack_file_set_fowner(struct file *file)
{
struct smack_known *skp = smk_of_current();
file->f_security = skp->smk_known;
return 0;
}
static int smack_file_send_sigiotask(struct task_struct *tsk,
struct fown_struct *fown, int signum)
{
struct smack_known *skp;
struct smack_known *tkp = smk_of_task(tsk->cred->security);
struct file *file;
int rc;
struct smk_audit_info ad;
file = container_of(fown, struct file, f_owner);
skp = smk_find_entry(file->f_security);
rc = smk_access(skp, tkp->smk_known, MAY_WRITE, NULL);
if (rc != 0 && has_capability(tsk, CAP_MAC_OVERRIDE))
rc = 0;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_TASK);
smk_ad_setfield_u_tsk(&ad, tsk);
smack_log(file->f_security, tkp->smk_known, MAY_WRITE, rc, &ad);
return rc;
}
static int smack_file_receive(struct file *file)
{
int may = 0;
struct smk_audit_info ad;
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_TASK);
smk_ad_setfield_u_fs_path(&ad, file->f_path);
if (file->f_mode & FMODE_READ)
may = MAY_READ;
if (file->f_mode & FMODE_WRITE)
may |= MAY_WRITE;
return smk_curacc(file->f_security, may, &ad);
}
static int smack_file_open(struct file *file, const struct cred *cred)
{
struct inode_smack *isp = file_inode(file)->i_security;
file->f_security = isp->smk_inode;
return 0;
}
static int smack_cred_alloc_blank(struct cred *cred, gfp_t gfp)
{
struct task_smack *tsp;
tsp = new_task_smack(NULL, NULL, gfp);
if (tsp == NULL)
return -ENOMEM;
cred->security = tsp;
return 0;
}
static void smack_cred_free(struct cred *cred)
{
struct task_smack *tsp = cred->security;
struct smack_rule *rp;
struct list_head *l;
struct list_head *n;
if (tsp == NULL)
return;
cred->security = NULL;
list_for_each_safe(l, n, &tsp->smk_rules) {
rp = list_entry(l, struct smack_rule, list);
list_del(&rp->list);
kfree(rp);
}
kfree(tsp);
}
static int smack_cred_prepare(struct cred *new, const struct cred *old,
gfp_t gfp)
{
struct task_smack *old_tsp = old->security;
struct task_smack *new_tsp;
int rc;
new_tsp = new_task_smack(old_tsp->smk_task, old_tsp->smk_task, gfp);
if (new_tsp == NULL)
return -ENOMEM;
rc = smk_copy_rules(&new_tsp->smk_rules, &old_tsp->smk_rules, gfp);
if (rc != 0)
return rc;
new->security = new_tsp;
return 0;
}
static void smack_cred_transfer(struct cred *new, const struct cred *old)
{
struct task_smack *old_tsp = old->security;
struct task_smack *new_tsp = new->security;
new_tsp->smk_task = old_tsp->smk_task;
new_tsp->smk_forked = old_tsp->smk_task;
mutex_init(&new_tsp->smk_rules_lock);
INIT_LIST_HEAD(&new_tsp->smk_rules);
}
static int smack_kernel_act_as(struct cred *new, u32 secid)
{
struct task_smack *new_tsp = new->security;
struct smack_known *skp = smack_from_secid(secid);
if (skp == NULL)
return -EINVAL;
new_tsp->smk_task = skp;
return 0;
}
static int smack_kernel_create_files_as(struct cred *new,
struct inode *inode)
{
struct inode_smack *isp = inode->i_security;
struct task_smack *tsp = new->security;
tsp->smk_forked = smk_find_entry(isp->smk_inode);
tsp->smk_task = tsp->smk_forked;
return 0;
}
static int smk_curacc_on_task(struct task_struct *p, int access,
const char *caller)
{
struct smk_audit_info ad;
struct smack_known *skp = smk_of_task(task_security(p));
smk_ad_init(&ad, caller, LSM_AUDIT_DATA_TASK);
smk_ad_setfield_u_tsk(&ad, p);
return smk_curacc(skp->smk_known, access, &ad);
}
static int smack_task_setpgid(struct task_struct *p, pid_t pgid)
{
return smk_curacc_on_task(p, MAY_WRITE, __func__);
}
static int smack_task_getpgid(struct task_struct *p)
{
return smk_curacc_on_task(p, MAY_READ, __func__);
}
static int smack_task_getsid(struct task_struct *p)
{
return smk_curacc_on_task(p, MAY_READ, __func__);
}
static void smack_task_getsecid(struct task_struct *p, u32 *secid)
{
struct smack_known *skp = smk_of_task(task_security(p));
*secid = skp->smk_secid;
}
static int smack_task_setnice(struct task_struct *p, int nice)
{
int rc;
rc = cap_task_setnice(p, nice);
if (rc == 0)
rc = smk_curacc_on_task(p, MAY_WRITE, __func__);
return rc;
}
static int smack_task_setioprio(struct task_struct *p, int ioprio)
{
int rc;
rc = cap_task_setioprio(p, ioprio);
if (rc == 0)
rc = smk_curacc_on_task(p, MAY_WRITE, __func__);
return rc;
}
static int smack_task_getioprio(struct task_struct *p)
{
return smk_curacc_on_task(p, MAY_READ, __func__);
}
static int smack_task_setscheduler(struct task_struct *p)
{
int rc;
rc = cap_task_setscheduler(p);
if (rc == 0)
rc = smk_curacc_on_task(p, MAY_WRITE, __func__);
return rc;
}
static int smack_task_getscheduler(struct task_struct *p)
{
return smk_curacc_on_task(p, MAY_READ, __func__);
}
static int smack_task_movememory(struct task_struct *p)
{
return smk_curacc_on_task(p, MAY_WRITE, __func__);
}
static int smack_task_kill(struct task_struct *p, struct siginfo *info,
int sig, u32 secid)
{
struct smk_audit_info ad;
struct smack_known *skp;
struct smack_known *tkp = smk_of_task(task_security(p));
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_TASK);
smk_ad_setfield_u_tsk(&ad, p);
if (secid == 0)
return smk_curacc(tkp->smk_known, MAY_WRITE, &ad);
skp = smack_from_secid(secid);
return smk_access(skp, tkp->smk_known, MAY_WRITE, &ad);
}
static int smack_task_wait(struct task_struct *p)
{
return 0;
}
static void smack_task_to_inode(struct task_struct *p, struct inode *inode)
{
struct inode_smack *isp = inode->i_security;
struct smack_known *skp = smk_of_task(task_security(p));
isp->smk_inode = skp->smk_known;
}
static int smack_sk_alloc_security(struct sock *sk, int family, gfp_t gfp_flags)
{
struct smack_known *skp = smk_of_current();
struct socket_smack *ssp;
ssp = kzalloc(sizeof(struct socket_smack), gfp_flags);
if (ssp == NULL)
return -ENOMEM;
ssp->smk_in = skp->smk_known;
ssp->smk_out = skp;
ssp->smk_packet = NULL;
sk->sk_security = ssp;
return 0;
}
static void smack_sk_free_security(struct sock *sk)
{
kfree(sk->sk_security);
}
static char *smack_host_label(struct sockaddr_in *sip)
{
struct smk_netlbladdr *snp;
struct in_addr *siap = &sip->sin_addr;
if (siap->s_addr == 0)
return NULL;
list_for_each_entry_rcu(snp, &smk_netlbladdr_list, list)
if ((&snp->smk_host.sin_addr)->s_addr ==
(siap->s_addr & (&snp->smk_mask)->s_addr)) {
if (snp->smk_label == smack_cipso_option)
return NULL;
return snp->smk_label;
}
return NULL;
}
static int smack_netlabel(struct sock *sk, int labeled)
{
struct smack_known *skp;
struct socket_smack *ssp = sk->sk_security;
int rc = 0;
local_bh_disable();
bh_lock_sock_nested(sk);
if (ssp->smk_out == smack_net_ambient ||
labeled == SMACK_UNLABELED_SOCKET)
netlbl_sock_delattr(sk);
else {
skp = ssp->smk_out;
rc = netlbl_sock_setattr(sk, sk->sk_family, &skp->smk_netlabel);
}
bh_unlock_sock(sk);
local_bh_enable();
return rc;
}
static int smack_netlabel_send(struct sock *sk, struct sockaddr_in *sap)
{
struct smack_known *skp;
int rc;
int sk_lbl;
char *hostsp;
struct socket_smack *ssp = sk->sk_security;
struct smk_audit_info ad;
rcu_read_lock();
hostsp = smack_host_label(sap);
if (hostsp != NULL) {
#ifdef CONFIG_AUDIT
struct lsm_network_audit net;
smk_ad_init_net(&ad, __func__, LSM_AUDIT_DATA_NET, &net);
ad.a.u.net->family = sap->sin_family;
ad.a.u.net->dport = sap->sin_port;
ad.a.u.net->v4info.daddr = sap->sin_addr.s_addr;
#endif
sk_lbl = SMACK_UNLABELED_SOCKET;
skp = ssp->smk_out;
rc = smk_access(skp, hostsp, MAY_WRITE, &ad);
} else {
sk_lbl = SMACK_CIPSO_SOCKET;
rc = 0;
}
rcu_read_unlock();
if (rc != 0)
return rc;
return smack_netlabel(sk, sk_lbl);
}
static void smk_ipv6_port_label(struct socket *sock, struct sockaddr *address)
{
struct sock *sk = sock->sk;
struct sockaddr_in6 *addr6;
struct socket_smack *ssp = sock->sk->sk_security;
struct smk_port_label *spp;
unsigned short port = 0;
if (address == NULL) {
list_for_each_entry(spp, &smk_ipv6_port_list, list) {
if (sk != spp->smk_sock)
continue;
spp->smk_in = ssp->smk_in;
spp->smk_out = ssp->smk_out;
return;
}
return;
}
addr6 = (struct sockaddr_in6 *)address;
port = ntohs(addr6->sin6_port);
if (port == 0)
return;
list_for_each_entry(spp, &smk_ipv6_port_list, list) {
if (spp->smk_port != port)
continue;
spp->smk_port = port;
spp->smk_sock = sk;
spp->smk_in = ssp->smk_in;
spp->smk_out = ssp->smk_out;
return;
}
spp = kzalloc(sizeof(*spp), GFP_KERNEL);
if (spp == NULL)
return;
spp->smk_port = port;
spp->smk_sock = sk;
spp->smk_in = ssp->smk_in;
spp->smk_out = ssp->smk_out;
list_add(&spp->list, &smk_ipv6_port_list);
return;
}
static int smk_ipv6_port_check(struct sock *sk, struct sockaddr_in6 *address,
int act)
{
__be16 *bep;
__be32 *be32p;
struct smk_port_label *spp;
struct socket_smack *ssp = sk->sk_security;
struct smack_known *skp;
unsigned short port = 0;
char *object;
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
struct lsm_network_audit net;
#endif
if (act == SMK_RECEIVING) {
skp = smack_net_ambient;
object = ssp->smk_in;
} else {
skp = ssp->smk_out;
object = smack_net_ambient->smk_known;
}
port = ntohs(address->sin6_port);
bep = (__be16 *)(&address->sin6_addr);
be32p = (__be32 *)(&address->sin6_addr);
if (be32p[0] || be32p[1] || be32p[2] || bep[6] || ntohs(bep[7]) != 1)
goto auditout;
if (act == SMK_RECEIVING) {
skp = &smack_known_web;
goto auditout;
}
list_for_each_entry(spp, &smk_ipv6_port_list, list) {
if (spp->smk_port != port)
continue;
object = spp->smk_in;
if (act == SMK_CONNECTING)
ssp->smk_packet = spp->smk_out->smk_known;
break;
}
auditout:
#ifdef CONFIG_AUDIT
smk_ad_init_net(&ad, __func__, LSM_AUDIT_DATA_NET, &net);
ad.a.u.net->family = sk->sk_family;
ad.a.u.net->dport = port;
if (act == SMK_RECEIVING)
ad.a.u.net->v6info.saddr = address->sin6_addr;
else
ad.a.u.net->v6info.daddr = address->sin6_addr;
#endif
return smk_access(skp, object, MAY_WRITE, &ad);
}
static int smack_inode_setsecurity(struct inode *inode, const char *name,
const void *value, size_t size, int flags)
{
struct smack_known *skp;
struct inode_smack *nsp = inode->i_security;
struct socket_smack *ssp;
struct socket *sock;
int rc = 0;
if (value == NULL || size > SMK_LONGLABEL || size == 0)
return -EACCES;
skp = smk_import_entry(value, size);
if (skp == NULL)
return -EINVAL;
if (strcmp(name, XATTR_SMACK_SUFFIX) == 0) {
nsp->smk_inode = skp->smk_known;
nsp->smk_flags |= SMK_INODE_INSTANT;
return 0;
}
if (inode->i_sb->s_magic != SOCKFS_MAGIC)
return -EOPNOTSUPP;
sock = SOCKET_I(inode);
if (sock == NULL || sock->sk == NULL)
return -EOPNOTSUPP;
ssp = sock->sk->sk_security;
if (strcmp(name, XATTR_SMACK_IPIN) == 0)
ssp->smk_in = skp->smk_known;
else if (strcmp(name, XATTR_SMACK_IPOUT) == 0) {
ssp->smk_out = skp;
if (sock->sk->sk_family == PF_INET) {
rc = smack_netlabel(sock->sk, SMACK_CIPSO_SOCKET);
if (rc != 0)
printk(KERN_WARNING
"Smack: \"%s\" netlbl error %d.\n",
__func__, -rc);
}
} else
return -EOPNOTSUPP;
if (sock->sk->sk_family == PF_INET6)
smk_ipv6_port_label(sock, NULL);
return 0;
}
static int smack_socket_post_create(struct socket *sock, int family,
int type, int protocol, int kern)
{
if (family != PF_INET || sock->sk == NULL)
return 0;
return smack_netlabel(sock->sk, SMACK_CIPSO_SOCKET);
}
static int smack_socket_bind(struct socket *sock, struct sockaddr *address,
int addrlen)
{
if (sock->sk != NULL && sock->sk->sk_family == PF_INET6)
smk_ipv6_port_label(sock, address);
return 0;
}
static int smack_socket_connect(struct socket *sock, struct sockaddr *sap,
int addrlen)
{
int rc = 0;
if (sock->sk == NULL)
return 0;
switch (sock->sk->sk_family) {
case PF_INET:
if (addrlen < sizeof(struct sockaddr_in))
return -EINVAL;
rc = smack_netlabel_send(sock->sk, (struct sockaddr_in *)sap);
break;
case PF_INET6:
if (addrlen < sizeof(struct sockaddr_in6))
return -EINVAL;
rc = smk_ipv6_port_check(sock->sk, (struct sockaddr_in6 *)sap,
SMK_CONNECTING);
break;
}
return rc;
}
static int smack_flags_to_may(int flags)
{
int may = 0;
if (flags & S_IRUGO)
may |= MAY_READ;
if (flags & S_IWUGO)
may |= MAY_WRITE;
if (flags & S_IXUGO)
may |= MAY_EXEC;
return may;
}
static int smack_msg_msg_alloc_security(struct msg_msg *msg)
{
struct smack_known *skp = smk_of_current();
msg->security = skp->smk_known;
return 0;
}
static void smack_msg_msg_free_security(struct msg_msg *msg)
{
msg->security = NULL;
}
static char *smack_of_shm(struct shmid_kernel *shp)
{
return (char *)shp->shm_perm.security;
}
static int smack_shm_alloc_security(struct shmid_kernel *shp)
{
struct kern_ipc_perm *isp = &shp->shm_perm;
struct smack_known *skp = smk_of_current();
isp->security = skp->smk_known;
return 0;
}
static void smack_shm_free_security(struct shmid_kernel *shp)
{
struct kern_ipc_perm *isp = &shp->shm_perm;
isp->security = NULL;
}
static int smk_curacc_shm(struct shmid_kernel *shp, int access)
{
char *ssp = smack_of_shm(shp);
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_IPC);
ad.a.u.ipc_id = shp->shm_perm.id;
#endif
return smk_curacc(ssp, access, &ad);
}
static int smack_shm_associate(struct shmid_kernel *shp, int shmflg)
{
int may;
may = smack_flags_to_may(shmflg);
return smk_curacc_shm(shp, may);
}
static int smack_shm_shmctl(struct shmid_kernel *shp, int cmd)
{
int may;
switch (cmd) {
case IPC_STAT:
case SHM_STAT:
may = MAY_READ;
break;
case IPC_SET:
case SHM_LOCK:
case SHM_UNLOCK:
case IPC_RMID:
may = MAY_READWRITE;
break;
case IPC_INFO:
case SHM_INFO:
return 0;
default:
return -EINVAL;
}
return smk_curacc_shm(shp, may);
}
static int smack_shm_shmat(struct shmid_kernel *shp, char __user *shmaddr,
int shmflg)
{
int may;
may = smack_flags_to_may(shmflg);
return smk_curacc_shm(shp, may);
}
static char *smack_of_sem(struct sem_array *sma)
{
return (char *)sma->sem_perm.security;
}
static int smack_sem_alloc_security(struct sem_array *sma)
{
struct kern_ipc_perm *isp = &sma->sem_perm;
struct smack_known *skp = smk_of_current();
isp->security = skp->smk_known;
return 0;
}
static void smack_sem_free_security(struct sem_array *sma)
{
struct kern_ipc_perm *isp = &sma->sem_perm;
isp->security = NULL;
}
static int smk_curacc_sem(struct sem_array *sma, int access)
{
char *ssp = smack_of_sem(sma);
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_IPC);
ad.a.u.ipc_id = sma->sem_perm.id;
#endif
return smk_curacc(ssp, access, &ad);
}
static int smack_sem_associate(struct sem_array *sma, int semflg)
{
int may;
may = smack_flags_to_may(semflg);
return smk_curacc_sem(sma, may);
}
static int smack_sem_semctl(struct sem_array *sma, int cmd)
{
int may;
switch (cmd) {
case GETPID:
case GETNCNT:
case GETZCNT:
case GETVAL:
case GETALL:
case IPC_STAT:
case SEM_STAT:
may = MAY_READ;
break;
case SETVAL:
case SETALL:
case IPC_RMID:
case IPC_SET:
may = MAY_READWRITE;
break;
case IPC_INFO:
case SEM_INFO:
return 0;
default:
return -EINVAL;
}
return smk_curacc_sem(sma, may);
}
static int smack_sem_semop(struct sem_array *sma, struct sembuf *sops,
unsigned nsops, int alter)
{
return smk_curacc_sem(sma, MAY_READWRITE);
}
static int smack_msg_queue_alloc_security(struct msg_queue *msq)
{
struct kern_ipc_perm *kisp = &msq->q_perm;
struct smack_known *skp = smk_of_current();
kisp->security = skp->smk_known;
return 0;
}
static void smack_msg_queue_free_security(struct msg_queue *msq)
{
struct kern_ipc_perm *kisp = &msq->q_perm;
kisp->security = NULL;
}
static char *smack_of_msq(struct msg_queue *msq)
{
return (char *)msq->q_perm.security;
}
static int smk_curacc_msq(struct msg_queue *msq, int access)
{
char *msp = smack_of_msq(msq);
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_IPC);
ad.a.u.ipc_id = msq->q_perm.id;
#endif
return smk_curacc(msp, access, &ad);
}
static int smack_msg_queue_associate(struct msg_queue *msq, int msqflg)
{
int may;
may = smack_flags_to_may(msqflg);
return smk_curacc_msq(msq, may);
}
static int smack_msg_queue_msgctl(struct msg_queue *msq, int cmd)
{
int may;
switch (cmd) {
case IPC_STAT:
case MSG_STAT:
may = MAY_READ;
break;
case IPC_SET:
case IPC_RMID:
may = MAY_READWRITE;
break;
case IPC_INFO:
case MSG_INFO:
return 0;
default:
return -EINVAL;
}
return smk_curacc_msq(msq, may);
}
static int smack_msg_queue_msgsnd(struct msg_queue *msq, struct msg_msg *msg,
int msqflg)
{
int may;
may = smack_flags_to_may(msqflg);
return smk_curacc_msq(msq, may);
}
static int smack_msg_queue_msgrcv(struct msg_queue *msq, struct msg_msg *msg,
struct task_struct *target, long type, int mode)
{
return smk_curacc_msq(msq, MAY_READWRITE);
}
static int smack_ipc_permission(struct kern_ipc_perm *ipp, short flag)
{
char *isp = ipp->security;
int may = smack_flags_to_may(flag);
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_IPC);
ad.a.u.ipc_id = ipp->id;
#endif
return smk_curacc(isp, may, &ad);
}
static void smack_ipc_getsecid(struct kern_ipc_perm *ipp, u32 *secid)
{
char *smack = ipp->security;
*secid = smack_to_secid(smack);
}
static void smack_d_instantiate(struct dentry *opt_dentry, struct inode *inode)
{
struct super_block *sbp;
struct superblock_smack *sbsp;
struct inode_smack *isp;
struct smack_known *skp;
struct smack_known *ckp = smk_of_current();
char *final;
char trattr[TRANS_TRUE_SIZE];
int transflag = 0;
int rc;
struct dentry *dp;
if (inode == NULL)
return;
isp = inode->i_security;
mutex_lock(&isp->smk_lock);
if (isp->smk_flags & SMK_INODE_INSTANT)
goto unlockandout;
sbp = inode->i_sb;
sbsp = sbp->s_security;
final = sbsp->smk_default;
if (opt_dentry->d_parent == opt_dentry) {
isp->smk_inode = sbsp->smk_root;
isp->smk_flags |= SMK_INODE_INSTANT;
goto unlockandout;
}
switch (sbp->s_magic) {
case SMACK_MAGIC:
final = smack_known_star.smk_known;
break;
case PIPEFS_MAGIC:
final = smack_known_star.smk_known;
break;
case DEVPTS_SUPER_MAGIC:
final = ckp->smk_known;
break;
case SOCKFS_MAGIC:
final = smack_known_star.smk_known;
break;
case PROC_SUPER_MAGIC:
break;
case TMPFS_MAGIC:
final = smack_known_star.smk_known;
default:
if (S_ISSOCK(inode->i_mode)) {
final = smack_known_star.smk_known;
break;
}
if (inode->i_op->getxattr == NULL)
break;
dp = dget(opt_dentry);
skp = smk_fetch(XATTR_NAME_SMACK, inode, dp);
if (skp != NULL)
final = skp->smk_known;
if (S_ISDIR(inode->i_mode)) {
if (isp->smk_flags & SMK_INODE_CHANGED) {
isp->smk_flags &= ~SMK_INODE_CHANGED;
rc = inode->i_op->setxattr(dp,
XATTR_NAME_SMACKTRANSMUTE,
TRANS_TRUE, TRANS_TRUE_SIZE,
0);
} else {
rc = inode->i_op->getxattr(dp,
XATTR_NAME_SMACKTRANSMUTE, trattr,
TRANS_TRUE_SIZE);
if (rc >= 0 && strncmp(trattr, TRANS_TRUE,
TRANS_TRUE_SIZE) != 0)
rc = -EINVAL;
}
if (rc >= 0)
transflag = SMK_INODE_TRANSMUTE;
}
isp->smk_task = smk_fetch(XATTR_NAME_SMACKEXEC, inode, dp);
isp->smk_mmap = smk_fetch(XATTR_NAME_SMACKMMAP, inode, dp);
dput(dp);
break;
}
if (final == NULL)
isp->smk_inode = ckp->smk_known;
else
isp->smk_inode = final;
isp->smk_flags |= (SMK_INODE_INSTANT | transflag);
unlockandout:
mutex_unlock(&isp->smk_lock);
return;
}
static int smack_getprocattr(struct task_struct *p, char *name, char **value)
{
struct smack_known *skp = smk_of_task(task_security(p));
char *cp;
int slen;
if (strcmp(name, "current") != 0)
return -EINVAL;
cp = kstrdup(skp->smk_known, GFP_KERNEL);
if (cp == NULL)
return -ENOMEM;
slen = strlen(cp);
*value = cp;
return slen;
}
static int smack_setprocattr(struct task_struct *p, char *name,
void *value, size_t size)
{
struct task_smack *tsp;
struct cred *new;
struct smack_known *skp;
if (p != current)
return -EPERM;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (value == NULL || size == 0 || size >= SMK_LONGLABEL)
return -EINVAL;
if (strcmp(name, "current") != 0)
return -EINVAL;
skp = smk_import_entry(value, size);
if (skp == NULL)
return -EINVAL;
if (skp == &smack_known_web)
return -EPERM;
new = prepare_creds();
if (new == NULL)
return -ENOMEM;
tsp = new->security;
tsp->smk_task = skp;
commit_creds(new);
return size;
}
static int smack_unix_stream_connect(struct sock *sock,
struct sock *other, struct sock *newsk)
{
struct smack_known *skp;
struct socket_smack *ssp = sock->sk_security;
struct socket_smack *osp = other->sk_security;
struct socket_smack *nsp = newsk->sk_security;
struct smk_audit_info ad;
int rc = 0;
#ifdef CONFIG_AUDIT
struct lsm_network_audit net;
smk_ad_init_net(&ad, __func__, LSM_AUDIT_DATA_NET, &net);
smk_ad_setfield_u_net_sk(&ad, other);
#endif
if (!smack_privileged(CAP_MAC_OVERRIDE)) {
skp = ssp->smk_out;
rc = smk_access(skp, osp->smk_in, MAY_WRITE, &ad);
}
if (rc == 0) {
nsp->smk_packet = ssp->smk_out->smk_known;
ssp->smk_packet = osp->smk_out->smk_known;
}
return rc;
}
static int smack_unix_may_send(struct socket *sock, struct socket *other)
{
struct socket_smack *ssp = sock->sk->sk_security;
struct socket_smack *osp = other->sk->sk_security;
struct smack_known *skp;
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
struct lsm_network_audit net;
smk_ad_init_net(&ad, __func__, LSM_AUDIT_DATA_NET, &net);
smk_ad_setfield_u_net_sk(&ad, other->sk);
#endif
if (smack_privileged(CAP_MAC_OVERRIDE))
return 0;
skp = ssp->smk_out;
return smk_access(skp, osp->smk_in, MAY_WRITE, &ad);
}
static int smack_socket_sendmsg(struct socket *sock, struct msghdr *msg,
int size)
{
struct sockaddr_in *sip = (struct sockaddr_in *) msg->msg_name;
struct sockaddr_in6 *sap = (struct sockaddr_in6 *) msg->msg_name;
int rc = 0;
if (sip == NULL)
return 0;
switch (sip->sin_family) {
case AF_INET:
rc = smack_netlabel_send(sock->sk, sip);
break;
case AF_INET6:
rc = smk_ipv6_port_check(sock->sk, sap, SMK_SENDING);
break;
}
return rc;
}
static struct smack_known *smack_from_secattr(struct netlbl_lsm_secattr *sap,
struct socket_smack *ssp)
{
struct smack_known *skp;
int found = 0;
int acat;
int kcat;
if ((sap->flags & NETLBL_SECATTR_MLS_LVL) != 0) {
rcu_read_lock();
list_for_each_entry(skp, &smack_known_list, list) {
if (sap->attr.mls.lvl != skp->smk_netlabel.attr.mls.lvl)
continue;
if ((sap->flags & NETLBL_SECATTR_MLS_CAT) == 0) {
if ((skp->smk_netlabel.flags &
NETLBL_SECATTR_MLS_CAT) == 0)
found = 1;
break;
}
for (acat = -1, kcat = -1; acat == kcat; ) {
acat = netlbl_secattr_catmap_walk(
sap->attr.mls.cat, acat + 1);
kcat = netlbl_secattr_catmap_walk(
skp->smk_netlabel.attr.mls.cat,
kcat + 1);
if (acat < 0 || kcat < 0)
break;
}
if (acat == kcat) {
found = 1;
break;
}
}
rcu_read_unlock();
if (found)
return skp;
if (ssp != NULL && ssp->smk_in == smack_known_star.smk_known)
return &smack_known_web;
return &smack_known_star;
}
if ((sap->flags & NETLBL_SECATTR_SECID) != 0) {
skp = smack_from_secid(sap->attr.secid);
BUG_ON(skp == NULL);
return skp;
}
return smack_net_ambient;
}
static int smk_skb_to_addr_ipv6(struct sk_buff *skb, struct sockaddr_in6 *sip)
{
u8 nexthdr;
int offset;
int proto = -EINVAL;
struct ipv6hdr _ipv6h;
struct ipv6hdr *ip6;
__be16 frag_off;
struct tcphdr _tcph, *th;
struct udphdr _udph, *uh;
struct dccp_hdr _dccph, *dh;
sip->sin6_port = 0;
offset = skb_network_offset(skb);
ip6 = skb_header_pointer(skb, offset, sizeof(_ipv6h), &_ipv6h);
if (ip6 == NULL)
return -EINVAL;
sip->sin6_addr = ip6->saddr;
nexthdr = ip6->nexthdr;
offset += sizeof(_ipv6h);
offset = ipv6_skip_exthdr(skb, offset, &nexthdr, &frag_off);
if (offset < 0)
return -EINVAL;
proto = nexthdr;
switch (proto) {
case IPPROTO_TCP:
th = skb_header_pointer(skb, offset, sizeof(_tcph), &_tcph);
if (th != NULL)
sip->sin6_port = th->source;
break;
case IPPROTO_UDP:
uh = skb_header_pointer(skb, offset, sizeof(_udph), &_udph);
if (uh != NULL)
sip->sin6_port = uh->source;
break;
case IPPROTO_DCCP:
dh = skb_header_pointer(skb, offset, sizeof(_dccph), &_dccph);
if (dh != NULL)
sip->sin6_port = dh->dccph_sport;
break;
}
return proto;
}
static int smack_socket_sock_rcv_skb(struct sock *sk, struct sk_buff *skb)
{
struct netlbl_lsm_secattr secattr;
struct socket_smack *ssp = sk->sk_security;
struct smack_known *skp;
struct sockaddr_in6 sadd;
int rc = 0;
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
struct lsm_network_audit net;
#endif
switch (sk->sk_family) {
case PF_INET:
netlbl_secattr_init(&secattr);
rc = netlbl_skbuff_getattr(skb, sk->sk_family, &secattr);
if (rc == 0)
skp = smack_from_secattr(&secattr, ssp);
else
skp = smack_net_ambient;
netlbl_secattr_destroy(&secattr);
#ifdef CONFIG_AUDIT
smk_ad_init_net(&ad, __func__, LSM_AUDIT_DATA_NET, &net);
ad.a.u.net->family = sk->sk_family;
ad.a.u.net->netif = skb->skb_iif;
ipv4_skb_to_auditdata(skb, &ad.a, NULL);
#endif
rc = smk_access(skp, ssp->smk_in, MAY_WRITE, &ad);
if (rc != 0)
netlbl_skbuff_err(skb, rc, 0);
break;
case PF_INET6:
rc = smk_skb_to_addr_ipv6(skb, &sadd);
if (rc == IPPROTO_UDP || rc == IPPROTO_TCP)
rc = smk_ipv6_port_check(sk, &sadd, SMK_RECEIVING);
else
rc = 0;
break;
}
return rc;
}
static int smack_socket_getpeersec_stream(struct socket *sock,
char __user *optval,
int __user *optlen, unsigned len)
{
struct socket_smack *ssp;
char *rcp = "";
int slen = 1;
int rc = 0;
ssp = sock->sk->sk_security;
if (ssp->smk_packet != NULL) {
rcp = ssp->smk_packet;
slen = strlen(rcp) + 1;
}
if (slen > len)
rc = -ERANGE;
else if (copy_to_user(optval, rcp, slen) != 0)
rc = -EFAULT;
if (put_user(slen, optlen) != 0)
rc = -EFAULT;
return rc;
}
static int smack_socket_getpeersec_dgram(struct socket *sock,
struct sk_buff *skb, u32 *secid)
{
struct netlbl_lsm_secattr secattr;
struct socket_smack *ssp = NULL;
struct smack_known *skp;
int family = PF_UNSPEC;
u32 s = 0;
int rc;
if (skb != NULL) {
if (skb->protocol == htons(ETH_P_IP))
family = PF_INET;
else if (skb->protocol == htons(ETH_P_IPV6))
family = PF_INET6;
}
if (family == PF_UNSPEC && sock != NULL)
family = sock->sk->sk_family;
if (family == PF_UNIX) {
ssp = sock->sk->sk_security;
s = ssp->smk_out->smk_secid;
} else if (family == PF_INET || family == PF_INET6) {
if (sock != NULL && sock->sk != NULL)
ssp = sock->sk->sk_security;
netlbl_secattr_init(&secattr);
rc = netlbl_skbuff_getattr(skb, family, &secattr);
if (rc == 0) {
skp = smack_from_secattr(&secattr, ssp);
s = skp->smk_secid;
}
netlbl_secattr_destroy(&secattr);
}
*secid = s;
if (s == 0)
return -EINVAL;
return 0;
}
static void smack_sock_graft(struct sock *sk, struct socket *parent)
{
struct socket_smack *ssp;
struct smack_known *skp = smk_of_current();
if (sk == NULL ||
(sk->sk_family != PF_INET && sk->sk_family != PF_INET6))
return;
ssp = sk->sk_security;
ssp->smk_in = skp->smk_known;
ssp->smk_out = skp;
}
static int smack_inet_conn_request(struct sock *sk, struct sk_buff *skb,
struct request_sock *req)
{
u16 family = sk->sk_family;
struct smack_known *skp;
struct socket_smack *ssp = sk->sk_security;
struct netlbl_lsm_secattr secattr;
struct sockaddr_in addr;
struct iphdr *hdr;
char *hsp;
int rc;
struct smk_audit_info ad;
#ifdef CONFIG_AUDIT
struct lsm_network_audit net;
#endif
if (family == PF_INET6) {
if (skb->protocol == htons(ETH_P_IP))
family = PF_INET;
else
return 0;
}
netlbl_secattr_init(&secattr);
rc = netlbl_skbuff_getattr(skb, family, &secattr);
if (rc == 0)
skp = smack_from_secattr(&secattr, ssp);
else
skp = &smack_known_huh;
netlbl_secattr_destroy(&secattr);
#ifdef CONFIG_AUDIT
smk_ad_init_net(&ad, __func__, LSM_AUDIT_DATA_NET, &net);
ad.a.u.net->family = family;
ad.a.u.net->netif = skb->skb_iif;
ipv4_skb_to_auditdata(skb, &ad.a, NULL);
#endif
rc = smk_access(skp, ssp->smk_in, MAY_WRITE, &ad);
if (rc != 0)
return rc;
req->peer_secid = skp->smk_secid;
hdr = ip_hdr(skb);
addr.sin_addr.s_addr = hdr->saddr;
rcu_read_lock();
hsp = smack_host_label(&addr);
rcu_read_unlock();
if (hsp == NULL)
rc = netlbl_req_setattr(req, &skp->smk_netlabel);
else
netlbl_req_delattr(req);
return rc;
}
static void smack_inet_csk_clone(struct sock *sk,
const struct request_sock *req)
{
struct socket_smack *ssp = sk->sk_security;
struct smack_known *skp;
if (req->peer_secid != 0) {
skp = smack_from_secid(req->peer_secid);
ssp->smk_packet = skp->smk_known;
} else
ssp->smk_packet = NULL;
}
static int smack_key_alloc(struct key *key, const struct cred *cred,
unsigned long flags)
{
struct smack_known *skp = smk_of_task(cred->security);
key->security = skp->smk_known;
return 0;
}
static void smack_key_free(struct key *key)
{
key->security = NULL;
}
static int smack_key_permission(key_ref_t key_ref,
const struct cred *cred, key_perm_t perm)
{
struct key *keyp;
struct smk_audit_info ad;
struct smack_known *tkp = smk_of_task(cred->security);
keyp = key_ref_to_ptr(key_ref);
if (keyp == NULL)
return -EINVAL;
if (keyp->security == NULL)
return 0;
if (tkp == NULL)
return -EACCES;
#ifdef CONFIG_AUDIT
smk_ad_init(&ad, __func__, LSM_AUDIT_DATA_KEY);
ad.a.u.key_struct.key = keyp->serial;
ad.a.u.key_struct.key_desc = keyp->description;
#endif
return smk_access(tkp, keyp->security, MAY_READWRITE, &ad);
}
static int smack_audit_rule_init(u32 field, u32 op, char *rulestr, void **vrule)
{
char **rule = (char **)vrule;
*rule = NULL;
if (field != AUDIT_SUBJ_USER && field != AUDIT_OBJ_USER)
return -EINVAL;
if (op != Audit_equal && op != Audit_not_equal)
return -EINVAL;
*rule = smk_import(rulestr, 0);
return 0;
}
static int smack_audit_rule_known(struct audit_krule *krule)
{
struct audit_field *f;
int i;
for (i = 0; i < krule->field_count; i++) {
f = &krule->fields[i];
if (f->type == AUDIT_SUBJ_USER || f->type == AUDIT_OBJ_USER)
return 1;
}
return 0;
}
static int smack_audit_rule_match(u32 secid, u32 field, u32 op, void *vrule,
struct audit_context *actx)
{
struct smack_known *skp;
char *rule = vrule;
if (!rule) {
audit_log(actx, GFP_ATOMIC, AUDIT_SELINUX_ERR,
"Smack: missing rule\n");
return -ENOENT;
}
if (field != AUDIT_SUBJ_USER && field != AUDIT_OBJ_USER)
return 0;
skp = smack_from_secid(secid);
if (op == Audit_equal)
return (rule == skp->smk_known);
if (op == Audit_not_equal)
return (rule != skp->smk_known);
return 0;
}
static void smack_audit_rule_free(void *vrule)
{
}
static int smack_ismaclabel(const char *name)
{
return (strcmp(name, XATTR_SMACK_SUFFIX) == 0);
}
static int smack_secid_to_secctx(u32 secid, char **secdata, u32 *seclen)
{
struct smack_known *skp = smack_from_secid(secid);
if (secdata)
*secdata = skp->smk_known;
*seclen = strlen(skp->smk_known);
return 0;
}
static int smack_secctx_to_secid(const char *secdata, u32 seclen, u32 *secid)
{
*secid = smack_to_secid(secdata);
return 0;
}
static void smack_release_secctx(char *secdata, u32 seclen)
{
}
static int smack_inode_notifysecctx(struct inode *inode, void *ctx, u32 ctxlen)
{
return smack_inode_setsecurity(inode, XATTR_SMACK_SUFFIX, ctx, ctxlen, 0);
}
static int smack_inode_setsecctx(struct dentry *dentry, void *ctx, u32 ctxlen)
{
return __vfs_setxattr_noperm(dentry, XATTR_NAME_SMACK, ctx, ctxlen, 0);
}
static int smack_inode_getsecctx(struct inode *inode, void **ctx, u32 *ctxlen)
{
int len = 0;
len = smack_inode_getsecurity(inode, XATTR_SMACK_SUFFIX, ctx, true);
if (len < 0)
return len;
*ctxlen = len;
return 0;
}
static __init void init_smack_known_list(void)
{
mutex_init(&smack_known_huh.smk_rules_lock);
mutex_init(&smack_known_hat.smk_rules_lock);
mutex_init(&smack_known_floor.smk_rules_lock);
mutex_init(&smack_known_star.smk_rules_lock);
mutex_init(&smack_known_invalid.smk_rules_lock);
mutex_init(&smack_known_web.smk_rules_lock);
INIT_LIST_HEAD(&smack_known_huh.smk_rules);
INIT_LIST_HEAD(&smack_known_hat.smk_rules);
INIT_LIST_HEAD(&smack_known_star.smk_rules);
INIT_LIST_HEAD(&smack_known_floor.smk_rules);
INIT_LIST_HEAD(&smack_known_invalid.smk_rules);
INIT_LIST_HEAD(&smack_known_web.smk_rules);
smk_insert_entry(&smack_known_huh);
smk_insert_entry(&smack_known_hat);
smk_insert_entry(&smack_known_star);
smk_insert_entry(&smack_known_floor);
smk_insert_entry(&smack_known_invalid);
smk_insert_entry(&smack_known_web);
}
static __init int smack_init(void)
{
struct cred *cred;
struct task_smack *tsp;
if (!security_module_enable(&smack_ops))
return 0;
tsp = new_task_smack(&smack_known_floor, &smack_known_floor,
GFP_KERNEL);
if (tsp == NULL)
return -ENOMEM;
printk(KERN_INFO "Smack: Initializing.\n");
cred = (struct cred *) current->cred;
cred->security = tsp;
init_smack_known_list();
if (register_security(&smack_ops))
panic("smack: Unable to register with kernel.\n");
return 0;
}
