static int
posix_acl_set(struct dentry *dentry, const char *name, const void *value,
size_t size, int flags, int type)
{
struct inode *inode = dentry->d_inode;
struct posix_acl *acl;
int error, error2;
struct reiserfs_transaction_handle th;
size_t jcreate_blocks;
if (!reiserfs_posixacl(inode->i_sb))
return -EOPNOTSUPP;
if (!inode_owner_or_capable(inode))
return -EPERM;
if (value) {
acl = posix_acl_from_xattr(value, size);
if (IS_ERR(acl)) {
return PTR_ERR(acl);
} else if (acl) {
error = posix_acl_valid(acl);
if (error)
goto release_and_out;
}
} else
acl = NULL;
jcreate_blocks = reiserfs_xattr_jcreate_nblocks(inode) +
reiserfs_xattr_nblocks(inode, size) * 2;
reiserfs_write_lock(inode->i_sb);
error = journal_begin(&th, inode->i_sb, jcreate_blocks);
if (error == 0) {
error = reiserfs_set_acl(&th, inode, type, acl);
error2 = journal_end(&th, inode->i_sb, jcreate_blocks);
if (error2)
error = error2;
}
reiserfs_write_unlock(inode->i_sb);
release_and_out:
posix_acl_release(acl);
return error;
}
static int
posix_acl_get(struct dentry *dentry, const char *name, void *buffer,
size_t size, int type)
{
struct posix_acl *acl;
int error;
if (!reiserfs_posixacl(dentry->d_sb))
return -EOPNOTSUPP;
acl = reiserfs_get_acl(dentry->d_inode, type);
if (IS_ERR(acl))
return PTR_ERR(acl);
if (acl == NULL)
return -ENODATA;
error = posix_acl_to_xattr(acl, buffer, size);
posix_acl_release(acl);
return error;
}
static struct posix_acl *posix_acl_from_disk(const void *value, size_t size)
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
acl->a_entries[n].e_id = ACL_UNDEFINED_ID;
break;
case ACL_USER:
case ACL_GROUP:
value = (char *)value + sizeof(reiserfs_acl_entry);
if ((char *)value > end)
goto fail;
acl->a_entries[n].e_id = le32_to_cpu(entry->e_id);
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
static void *posix_acl_to_disk(const struct posix_acl *acl, size_t * size)
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
reiserfs_acl_entry *entry = (reiserfs_acl_entry *) e;
entry->e_tag = cpu_to_le16(acl->a_entries[n].e_tag);
entry->e_perm = cpu_to_le16(acl->a_entries[n].e_perm);
switch (acl->a_entries[n].e_tag) {
case ACL_USER:
case ACL_GROUP:
entry->e_id = cpu_to_le32(acl->a_entries[n].e_id);
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
acl = get_cached_acl(inode, type);
if (acl != ACL_NOT_CACHED)
return acl;
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
acl = posix_acl_from_disk(value, retval);
}
if (!IS_ERR(acl))
set_cached_acl(inode, type, acl);
kfree(value);
return acl;
}
static int
reiserfs_set_acl(struct reiserfs_transaction_handle *th, struct inode *inode,
int type, struct posix_acl *acl)
{
char *name;
void *value = NULL;
size_t size = 0;
int error;
if (S_ISLNK(inode->i_mode))
return -EOPNOTSUPP;
switch (type) {
case ACL_TYPE_ACCESS:
name = POSIX_ACL_XATTR_ACCESS;
if (acl) {
mode_t mode = inode->i_mode;
error = posix_acl_equiv_mode(acl, &mode);
if (error < 0)
return error;
else {
inode->i_mode = mode;
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
value = posix_acl_to_disk(acl, &size);
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
struct posix_acl *acl;
int err = 0;
if (S_ISLNK(inode->i_mode))
return 0;
if (get_inode_sd_version(dir) == STAT_DATA_V1)
goto apply_umask;
if (IS_PRIVATE(dir)) {
inode->i_flags |= S_PRIVATE;
goto apply_umask;
}
acl = reiserfs_get_acl(dir, ACL_TYPE_DEFAULT);
if (IS_ERR(acl))
return PTR_ERR(acl);
if (acl) {
struct posix_acl *acl_copy;
mode_t mode = inode->i_mode;
int need_acl;
if (S_ISDIR(inode->i_mode)) {
err = reiserfs_set_acl(th, inode, ACL_TYPE_DEFAULT,
acl);
if (err)
goto cleanup;
}
acl_copy = posix_acl_clone(acl, GFP_NOFS);
if (!acl_copy) {
err = -ENOMEM;
goto cleanup;
}
need_acl = posix_acl_create_masq(acl_copy, &mode);
if (need_acl >= 0) {
if (mode != inode->i_mode) {
inode->i_mode = mode;
}
if (need_acl > 0) {
err = reiserfs_set_acl(th, inode,
ACL_TYPE_ACCESS,
acl_copy);
if (err)
goto cleanup_copy;
}
}
cleanup_copy:
posix_acl_release(acl_copy);
cleanup:
posix_acl_release(acl);
} else {
apply_umask:
inode->i_mode &= ~current_umask();
}
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
struct posix_acl *acl, *clone;
int error;
if (S_ISLNK(inode->i_mode))
return -EOPNOTSUPP;
if (get_inode_sd_version(inode) == STAT_DATA_V1 ||
!reiserfs_posixacl(inode->i_sb)) {
return 0;
}
reiserfs_write_unlock(inode->i_sb);
acl = reiserfs_get_acl(inode, ACL_TYPE_ACCESS);
reiserfs_write_lock(inode->i_sb);
if (!acl)
return 0;
if (IS_ERR(acl))
return PTR_ERR(acl);
clone = posix_acl_clone(acl, GFP_NOFS);
posix_acl_release(acl);
if (!clone)
return -ENOMEM;
error = posix_acl_chmod_masq(clone, inode->i_mode);
if (!error) {
struct reiserfs_transaction_handle th;
size_t size = reiserfs_xattr_nblocks(inode,
reiserfs_acl_size(clone->a_count));
int depth;
depth = reiserfs_write_lock_once(inode->i_sb);
error = journal_begin(&th, inode->i_sb, size * 2);
if (!error) {
int error2;
error = reiserfs_set_acl(&th, inode, ACL_TYPE_ACCESS,
clone);
error2 = journal_end(&th, inode->i_sb, size * 2);
if (error2)
error = error2;
}
reiserfs_write_unlock_once(inode->i_sb, depth);
}
posix_acl_release(clone);
return error;
}
static size_t posix_acl_access_list(struct dentry *dentry, char *list,
size_t list_size, const char *name,
size_t name_len, int type)
{
const size_t size = sizeof(POSIX_ACL_XATTR_ACCESS);
if (!reiserfs_posixacl(dentry->d_sb))
return 0;
if (list && size <= list_size)
memcpy(list, POSIX_ACL_XATTR_ACCESS, size);
return size;
}
static size_t posix_acl_default_list(struct dentry *dentry, char *list,
size_t list_size, const char *name,
size_t name_len, int type)
{
const size_t size = sizeof(POSIX_ACL_XATTR_DEFAULT);
if (!reiserfs_posixacl(dentry->d_sb))
return 0;
if (list && size <= list_size)
memcpy(list, POSIX_ACL_XATTR_DEFAULT, size);
return size;
}
