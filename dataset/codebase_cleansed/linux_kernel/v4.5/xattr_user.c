static int
user_get(const struct xattr_handler *handler, struct dentry *dentry,
const char *name, void *buffer, size_t size)
{
if (strlen(name) < sizeof(XATTR_USER_PREFIX))
return -EINVAL;
if (!reiserfs_xattrs_user(dentry->d_sb))
return -EOPNOTSUPP;
return reiserfs_xattr_get(d_inode(dentry), name, buffer, size);
}
static int
user_set(const struct xattr_handler *handler, struct dentry *dentry,
const char *name, const void *buffer, size_t size, int flags)
{
if (strlen(name) < sizeof(XATTR_USER_PREFIX))
return -EINVAL;
if (!reiserfs_xattrs_user(dentry->d_sb))
return -EOPNOTSUPP;
return reiserfs_xattr_set(d_inode(dentry), name, buffer, size, flags);
}
static bool user_list(struct dentry *dentry)
{
return reiserfs_xattrs_user(dentry->d_sb);
}
