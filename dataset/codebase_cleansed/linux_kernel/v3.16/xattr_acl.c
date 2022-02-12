int
reiserfs_set_acl(struct inode *inode, struct posix_acl *acl, int type)
{
int error, error2;
struct reiserfs_transaction_handle th;
size_t jcreate_blocks;
int size = acl ? posix_acl_xattr_size(acl->a_count) : 0;
jcreate_blocks = reiserfs_xattr_jcreate_nblocks(inode) +
reiserfs_xattr_nblocks(inode, size) * 2;
reiserfs_write_lock(inode->i_sb);
error = journal_begin(&th, inode->i_sb, jcreate_blocks);
reiserfs_write_unlock(inode->i_sb);
if (error == 0) {
error = __reiserfs_set_acl(&th, inode, type, acl);
reiserfs_write_lock(inode->i_sb);
error2 = journal_end(&th);
reiserfs_write_unlock(inode->i_sb);
if (error2)
error = error2;
}
return error;
}
static struct posix_acl *reiserfs_posix_acl_from_disk(const void *value, size_t size)
{
const char *end = (char *)value + size;
int n, count;
struct posix_acl *acl;
if (!value)
return NULL;
if (size < sizeof(reiserfs_acl_header))
return ERR_PTR(-EINVAL);
if (((reiserfs_acl_header *) value)->a_version !=
cpu_to_le32(REISERFS_ACL_VERSION))
return ERR_PTR(-EINVAL);
value = (char *)value + sizeof(reiserfs_acl_header);
count = reiserfs_acl_count(size);
if (count < 0)
return ERR_PTR(-EINVAL);
if (count == 0)
return NULL;
acl = posix_acl_alloc(count, GFP_NOFS);
if (!acl)
return ERR_PTR(-ENOMEM);
for (n = 0; n < count; n++) {
reiserfs_acl_entry *entry = (reiserfs_acl_entry *) value;
if ((char *)value + sizeof(reiserfs_acl_entry_short) > end)
goto fail;
acl->a_entries[n].e_tag = le16_to_cpu(entry->e_tag);
acl->a_entries[n].e_perm = le16_to_cpu(entry->e_perm);
switch (acl->a_entries[n].e_tag) {
case ACL_USER_OBJ:
case ACL_GROUP_OBJ:
case ACL_MASK:
case ACL_OTHER:
value = (char *)value +
sizeof(reiserfs_acl_entry_short);
break;
case ACL_USER:
value = (char *)value + sizeof(reiserfs_acl_entry);
if ((char *)value > end)
goto fail;
acl->a_entries[n].e_uid =
make_kuid(&init_user_ns,
le32_to_cpu(entry->e_id));
break;
case ACL_GROUP:
value = (char *)value + sizeof(reiserfs_acl_entry);
if ((char *)value > end)
goto fail;
acl->a_entries[n].e_gid =
make_kgid(&init_user_ns,
le32_to_cpu(entry->e_id));
break;
default:
goto fail;
}
}
if (value != end)
goto fail;
return acl;
fail:
posix_acl_release(acl);
return ERR_PTR(-EINVAL);
}
static void *reiserfs_posix_acl_to_disk(const struct posix_acl *acl, size_t * size)
{
reiserfs_acl_header *ext_acl;
char *e;
int n;
*size = reiserfs_acl_size(acl->a_count);
ext_acl = kmalloc(sizeof(reiserfs_acl_header) +
acl->a_count *
sizeof(reiserfs_acl_entry),
GFP_NOFS);
if (!ext_acl)
return ERR_PTR(-ENOMEM);
ext_acl->a_version = cpu_to_le32(REISERFS_ACL_VERSION);
e = (char *)ext_acl + sizeof(reiserfs_acl_header);
for (n = 0; n < acl->a_count; n++) {
const struct posix_acl_entry *acl_e = &acl->a_entries[n];
reiserfs_acl_entry *entry = (reiserfs_acl_entry *) e;
entry->e_tag = cpu_to_le16(acl->a_entries[n].e_tag);
entry->e_perm = cpu_to_le16(acl->a_entries[n].e_perm);
switch (acl->a_entries[n].e_tag) {
case ACL_USER:
entry->e_id = cpu_to_le32(
from_kuid(&init_user_ns, acl_e->e_uid));
e += sizeof(reiserfs_acl_entry);
break;
case ACL_GROUP:
entry->e_id = cpu_to_le32(
from_kgid(&init_user_ns, acl_e->e_gid));
e += sizeof(reiserfs_acl_entry);
break;
case ACL_USER_OBJ:
case ACL_GROUP_OBJ:
case ACL_MASK:
case ACL_OTHER:
e += sizeof(reiserfs_acl_entry_short);
break;
default:
goto fail;
}
}
return (char *)ext_acl;
fail:
kfree(ext_acl);
return ERR_PTR(-EINVAL);
}
struct posix_acl *reiserfs_get_acl(struct inode *inode, int type)
{
char *name, *value;
struct posix_acl *acl;
int size;
int retval;
switch (type) {
case ACL_TYPE_ACCESS:
name = POSIX_ACL_XATTR_ACCESS;
break;
case ACL_TYPE_DEFAULT:
name = POSIX_ACL_XATTR_DEFAULT;
break;
default:
BUG();
}
size = reiserfs_xattr_get(inode, name, NULL, 0);
if (size < 0) {
if (size == -ENODATA || size == -ENOSYS) {
set_cached_acl(inode, type, NULL);
return NULL;
}
return ERR_PTR(size);
}
value = kmalloc(size, GFP_NOFS);
if (!value)
return ERR_PTR(-ENOMEM);
retval = reiserfs_xattr_get(inode, name, value, size);
if (retval == -ENODATA || retval == -ENOSYS) {
acl = NULL;
} else if (retval < 0) {
acl = ERR_PTR(retval);
} else {
acl = reiserfs_posix_acl_from_disk(value, retval);
}
if (!IS_ERR(acl))
set_cached_acl(inode, type, acl);
kfree(value);
return acl;
}
static int
__reiserfs_set_acl(struct reiserfs_transaction_handle *th, struct inode *inode,
int type, struct posix_acl *acl)
{
char *name;
void *value = NULL;
size_t size = 0;
int error;
switch (type) {
case ACL_TYPE_ACCESS:
name = POSIX_ACL_XATTR_ACCESS;
if (acl) {
error = posix_acl_equiv_mode(acl, &inode->i_mode);
if (error < 0)
return error;
else {
if (error == 0)
acl = NULL;
}
}
break;
case ACL_TYPE_DEFAULT:
name = POSIX_ACL_XATTR_DEFAULT;
if (!S_ISDIR(inode->i_mode))
return acl ? -EACCES : 0;
break;
default:
return -EINVAL;
}
if (acl) {
value = reiserfs_posix_acl_to_disk(acl, &size);
if (IS_ERR(value))
return (int)PTR_ERR(value);
}
error = reiserfs_xattr_set_handle(th, inode, name, value, size, 0);
if (error == -ENODATA) {
error = 0;
if (type == ACL_TYPE_ACCESS) {
inode->i_ctime = CURRENT_TIME_SEC;
mark_inode_dirty(inode);
}
}
kfree(value);
if (!error)
set_cached_acl(inode, type, acl);
return error;
}
int
reiserfs_inherit_default_acl(struct reiserfs_transaction_handle *th,
struct inode *dir, struct dentry *dentry,
struct inode *inode)
{
struct posix_acl *default_acl, *acl;
int err = 0;
if (S_ISLNK(inode->i_mode))
return 0;
if (get_inode_sd_version(dir) == STAT_DATA_V1)
goto apply_umask;
if (IS_PRIVATE(dir)) {
inode->i_flags |= S_PRIVATE;
goto apply_umask;
}
err = posix_acl_create(dir, &inode->i_mode, &default_acl, &acl);
if (err)
return err;
if (default_acl) {
err = __reiserfs_set_acl(th, inode, ACL_TYPE_DEFAULT,
default_acl);
posix_acl_release(default_acl);
}
if (acl) {
if (!err)
err = __reiserfs_set_acl(th, inode, ACL_TYPE_ACCESS,
acl);
posix_acl_release(acl);
}
return err;
apply_umask:
inode->i_mode &= ~current_umask();
return err;
}
int reiserfs_cache_default_acl(struct inode *inode)
{
struct posix_acl *acl;
int nblocks = 0;
if (IS_PRIVATE(inode))
return 0;
acl = reiserfs_get_acl(inode, ACL_TYPE_DEFAULT);
if (acl && !IS_ERR(acl)) {
int size = reiserfs_acl_size(acl->a_count);
nblocks = reiserfs_xattr_jcreate_nblocks(inode);
nblocks += JOURNAL_BLOCKS_PER_OBJECT(inode->i_sb);
REISERFS_I(inode)->i_flags |= i_has_xattr_dir;
nblocks += reiserfs_xattr_nblocks(inode, size) * 4;
posix_acl_release(acl);
}
return nblocks;
}
int reiserfs_acl_chmod(struct inode *inode)
{
if (IS_PRIVATE(inode))
return 0;
if (get_inode_sd_version(inode) == STAT_DATA_V1 ||
!reiserfs_posixacl(inode->i_sb))
return 0;
return posix_acl_chmod(inode, inode->i_mode);
}
