static int
ll_initxattrs(struct inode *inode, const struct xattr *xattr_array,
void *fs_info)
{
const struct xattr_handler *handler;
struct dentry *dentry = fs_info;
const struct xattr *xattr;
int err = 0;
handler = get_xattr_type(XATTR_SECURITY_PREFIX);
if (!handler)
return -ENXIO;
for (xattr = xattr_array; xattr->name; xattr++) {
err = handler->set(handler, dentry, inode, xattr->name,
xattr->value, xattr->value_len,
XATTR_CREATE);
if (err < 0)
break;
}
return err;
}
int
ll_init_security(struct dentry *dentry, struct inode *inode, struct inode *dir)
{
if (!selinux_is_enabled())
return 0;
return security_inode_init_security(inode, dir, NULL,
&ll_initxattrs, dentry);
}
