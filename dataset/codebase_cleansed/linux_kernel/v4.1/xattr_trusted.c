static int hfsplus_trusted_getxattr(struct dentry *dentry, const char *name,
void *buffer, size_t size, int type)
{
return hfsplus_getxattr(dentry, name, buffer, size,
XATTR_TRUSTED_PREFIX,
XATTR_TRUSTED_PREFIX_LEN);
}
static int hfsplus_trusted_setxattr(struct dentry *dentry, const char *name,
const void *buffer, size_t size, int flags, int type)
{
return hfsplus_setxattr(dentry, name, buffer, size, flags,
XATTR_TRUSTED_PREFIX, XATTR_TRUSTED_PREFIX_LEN);
}
static size_t hfsplus_trusted_listxattr(struct dentry *dentry, char *list,
size_t list_size, const char *name, size_t name_len, int type)
{
return -EOPNOTSUPP;
}
