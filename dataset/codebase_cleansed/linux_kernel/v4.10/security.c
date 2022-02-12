static int jffs2_initxattrs(struct inode *inode,
const struct xattr *xattr_array, void *fs_info)
{
const struct xattr *xattr;
int err = 0;
for (xattr = xattr_array; xattr->name != NULL; xattr++) {
err = do_jffs2_setxattr(inode, JFFS2_XPREFIX_SECURITY,
xattr->name, xattr->value,
xattr->value_len, 0);
if (err < 0)
break;
}
return err;
}
int jffs2_init_security(struct inode *inode, struct inode *dir,
const struct qstr *qstr)
{
return security_inode_init_security(inode, dir, qstr,
&jffs2_initxattrs, NULL);
}
static int jffs2_security_getxattr(const struct xattr_handler *handler,
struct dentry *unused, struct inode *inode,
const char *name, void *buffer, size_t size)
{
return do_jffs2_getxattr(inode, JFFS2_XPREFIX_SECURITY,
name, buffer, size);
}
static int jffs2_security_setxattr(const struct xattr_handler *handler,
struct dentry *unused, struct inode *inode,
const char *name, const void *buffer,
size_t size, int flags)
{
return do_jffs2_setxattr(inode, JFFS2_XPREFIX_SECURITY,
name, buffer, size, flags);
}
