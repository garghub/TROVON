STATIC struct posix_acl *
xfs_acl_from_disk(
struct xfs_acl *aclp,
int max_entries)
{
struct posix_acl_entry *acl_e;
struct posix_acl *acl;
struct xfs_acl_entry *ace;
unsigned int count, i;
count = be32_to_cpu(aclp->acl_cnt);
if (count > max_entries)
return ERR_PTR(-EFSCORRUPTED);
acl = posix_acl_alloc(count, GFP_KERNEL);
if (!acl)
return ERR_PTR(-ENOMEM);
for (i = 0; i < count; i++) {
acl_e = &acl->a_entries[i];
ace = &aclp->acl_entry[i];
acl_e->e_tag = be32_to_cpu(ace->ae_tag);
acl_e->e_perm = be16_to_cpu(ace->ae_perm);
switch (acl_e->e_tag) {
case ACL_USER:
acl_e->e_uid = xfs_uid_to_kuid(be32_to_cpu(ace->ae_id));
break;
case ACL_GROUP:
acl_e->e_gid = xfs_gid_to_kgid(be32_to_cpu(ace->ae_id));
break;
case ACL_USER_OBJ:
case ACL_GROUP_OBJ:
case ACL_MASK:
case ACL_OTHER:
break;
default:
goto fail;
}
}
return acl;
fail:
posix_acl_release(acl);
return ERR_PTR(-EINVAL);
}
STATIC void
xfs_acl_to_disk(struct xfs_acl *aclp, const struct posix_acl *acl)
{
const struct posix_acl_entry *acl_e;
struct xfs_acl_entry *ace;
int i;
aclp->acl_cnt = cpu_to_be32(acl->a_count);
for (i = 0; i < acl->a_count; i++) {
ace = &aclp->acl_entry[i];
acl_e = &acl->a_entries[i];
ace->ae_tag = cpu_to_be32(acl_e->e_tag);
switch (acl_e->e_tag) {
case ACL_USER:
ace->ae_id = cpu_to_be32(xfs_kuid_to_uid(acl_e->e_uid));
break;
case ACL_GROUP:
ace->ae_id = cpu_to_be32(xfs_kgid_to_gid(acl_e->e_gid));
break;
default:
ace->ae_id = cpu_to_be32(ACL_UNDEFINED_ID);
break;
}
ace->ae_perm = cpu_to_be16(acl_e->e_perm);
}
}
struct posix_acl *
xfs_get_acl(struct inode *inode, int type)
{
struct xfs_inode *ip = XFS_I(inode);
struct posix_acl *acl;
struct xfs_acl *xfs_acl;
unsigned char *ea_name;
int error;
int len;
acl = get_cached_acl(inode, type);
if (acl != ACL_NOT_CACHED)
return acl;
trace_xfs_get_acl(ip);
switch (type) {
case ACL_TYPE_ACCESS:
ea_name = SGI_ACL_FILE;
break;
case ACL_TYPE_DEFAULT:
ea_name = SGI_ACL_DEFAULT;
break;
default:
BUG();
}
len = XFS_ACL_MAX_SIZE(ip->i_mount);
xfs_acl = kmem_zalloc_large(len, KM_SLEEP);
if (!xfs_acl)
return ERR_PTR(-ENOMEM);
error = -xfs_attr_get(ip, ea_name, (unsigned char *)xfs_acl,
&len, ATTR_ROOT);
if (error) {
if (error == -ENOATTR) {
acl = NULL;
goto out_update_cache;
}
goto out;
}
acl = xfs_acl_from_disk(xfs_acl, XFS_ACL_MAX_ENTRIES(ip->i_mount));
if (IS_ERR(acl))
goto out;
out_update_cache:
set_cached_acl(inode, type, acl);
out:
kmem_free(xfs_acl);
return acl;
}
STATIC int
xfs_set_acl(struct inode *inode, int type, struct posix_acl *acl)
{
struct xfs_inode *ip = XFS_I(inode);
unsigned char *ea_name;
int error;
if (S_ISLNK(inode->i_mode))
return -EOPNOTSUPP;
switch (type) {
case ACL_TYPE_ACCESS:
ea_name = SGI_ACL_FILE;
break;
case ACL_TYPE_DEFAULT:
if (!S_ISDIR(inode->i_mode))
return acl ? -EACCES : 0;
ea_name = SGI_ACL_DEFAULT;
break;
default:
return -EINVAL;
}
if (acl) {
struct xfs_acl *xfs_acl;
int len = XFS_ACL_MAX_SIZE(ip->i_mount);
xfs_acl = kmem_zalloc_large(len, KM_SLEEP);
if (!xfs_acl)
return -ENOMEM;
xfs_acl_to_disk(xfs_acl, acl);
len -= sizeof(struct xfs_acl_entry) *
(XFS_ACL_MAX_ENTRIES(ip->i_mount) - acl->a_count);
error = -xfs_attr_set(ip, ea_name, (unsigned char *)xfs_acl,
len, ATTR_ROOT);
kmem_free(xfs_acl);
} else {
error = -xfs_attr_remove(ip, ea_name, ATTR_ROOT);
if (error == -ENOATTR)
error = 0;
}
if (!error)
set_cached_acl(inode, type, acl);
return error;
}
static int
xfs_set_mode(struct inode *inode, umode_t mode)
{
int error = 0;
if (mode != inode->i_mode) {
struct iattr iattr;
iattr.ia_valid = ATTR_MODE | ATTR_CTIME;
iattr.ia_mode = mode;
iattr.ia_ctime = current_fs_time(inode->i_sb);
error = -xfs_setattr_nonsize(XFS_I(inode), &iattr, XFS_ATTR_NOACL);
}
return error;
}
static int
xfs_acl_exists(struct inode *inode, unsigned char *name)
{
int len = XFS_ACL_MAX_SIZE(XFS_M(inode->i_sb));
return (xfs_attr_get(XFS_I(inode), name, NULL, &len,
ATTR_ROOT|ATTR_KERNOVAL) == 0);
}
int
posix_acl_access_exists(struct inode *inode)
{
return xfs_acl_exists(inode, SGI_ACL_FILE);
}
int
posix_acl_default_exists(struct inode *inode)
{
if (!S_ISDIR(inode->i_mode))
return 0;
return xfs_acl_exists(inode, SGI_ACL_DEFAULT);
}
int
xfs_inherit_acl(struct inode *inode, struct posix_acl *acl)
{
umode_t mode = inode->i_mode;
int error = 0, inherit = 0;
if (S_ISDIR(inode->i_mode)) {
error = xfs_set_acl(inode, ACL_TYPE_DEFAULT, acl);
if (error)
goto out;
}
error = posix_acl_create(&acl, GFP_KERNEL, &mode);
if (error < 0)
return error;
if (error > 0)
inherit = 1;
error = xfs_set_mode(inode, mode);
if (error)
goto out;
if (inherit)
error = xfs_set_acl(inode, ACL_TYPE_ACCESS, acl);
out:
posix_acl_release(acl);
return error;
}
int
xfs_acl_chmod(struct inode *inode)
{
struct posix_acl *acl;
int error;
if (S_ISLNK(inode->i_mode))
return -EOPNOTSUPP;
acl = xfs_get_acl(inode, ACL_TYPE_ACCESS);
if (IS_ERR(acl) || !acl)
return PTR_ERR(acl);
error = posix_acl_chmod(&acl, GFP_KERNEL, inode->i_mode);
if (error)
return error;
error = xfs_set_acl(inode, ACL_TYPE_ACCESS, acl);
posix_acl_release(acl);
return error;
}
static int
xfs_xattr_acl_get(struct dentry *dentry, const char *name,
void *value, size_t size, int type)
{
struct posix_acl *acl;
int error;
acl = xfs_get_acl(dentry->d_inode, type);
if (IS_ERR(acl))
return PTR_ERR(acl);
if (acl == NULL)
return -ENODATA;
error = posix_acl_to_xattr(&init_user_ns, acl, value, size);
posix_acl_release(acl);
return error;
}
static int
xfs_xattr_acl_set(struct dentry *dentry, const char *name,
const void *value, size_t size, int flags, int type)
{
struct inode *inode = dentry->d_inode;
struct posix_acl *acl = NULL;
int error = 0;
if (flags & XATTR_CREATE)
return -EINVAL;
if (type == ACL_TYPE_DEFAULT && !S_ISDIR(inode->i_mode))
return value ? -EACCES : 0;
if (!inode_owner_or_capable(inode))
return -EPERM;
if (!value)
goto set_acl;
acl = posix_acl_from_xattr(&init_user_ns, value, size);
if (!acl) {
goto out;
}
if (IS_ERR(acl)) {
error = PTR_ERR(acl);
goto out;
}
error = posix_acl_valid(acl);
if (error)
goto out_release;
error = -EINVAL;
if (acl->a_count > XFS_ACL_MAX_ENTRIES(XFS_M(inode->i_sb)))
goto out_release;
if (type == ACL_TYPE_ACCESS) {
umode_t mode = inode->i_mode;
error = posix_acl_equiv_mode(acl, &mode);
if (error <= 0) {
posix_acl_release(acl);
acl = NULL;
if (error < 0)
return error;
}
error = xfs_set_mode(inode, mode);
if (error)
goto out_release;
}
set_acl:
error = xfs_set_acl(inode, type, acl);
out_release:
posix_acl_release(acl);
out:
return error;
}
