static int
ll_initxattrs(struct inode *inode, const struct xattr *xattr_array,
void *fs_info)
{
struct dentry *dentry = fs_info;
const struct xattr *xattr;
int err = 0;
for (xattr = xattr_array; xattr->name; xattr++) {
char *full_name;
full_name = kasprintf(GFP_KERNEL, "%s%s",
XATTR_SECURITY_PREFIX, xattr->name);
if (!full_name) {
err = -ENOMEM;
break;
}
err = __vfs_setxattr(dentry, inode, full_name, xattr->value,
xattr->value_len, XATTR_CREATE);
kfree(full_name);
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
