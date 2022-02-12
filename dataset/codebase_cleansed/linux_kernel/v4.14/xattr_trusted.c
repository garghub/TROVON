static int hfsplus_trusted_getxattr(const struct xattr_handler *handler,
struct dentry *unused, struct inode *inode,
const char *name, void *buffer, size_t size)
{
return hfsplus_getxattr(inode, name, buffer, size,
XATTR_TRUSTED_PREFIX,
XATTR_TRUSTED_PREFIX_LEN);
}
static int hfsplus_trusted_setxattr(const struct xattr_handler *handler,
struct dentry *unused, struct inode *inode,
const char *name, const void *buffer,
size_t size, int flags)
{
return hfsplus_setxattr(inode, name, buffer, size, flags,
XATTR_TRUSTED_PREFIX, XATTR_TRUSTED_PREFIX_LEN);
}
