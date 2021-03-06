static int hfsplus_trusted_getxattr(struct dentry *dentry, const char *name,
void *buffer, size_t size, int type)
{
char *xattr_name;
int res;
if (!strcmp(name, ""))
return -EINVAL;
xattr_name = kmalloc(NLS_MAX_CHARSET_SIZE * HFSPLUS_ATTR_MAX_STRLEN + 1,
GFP_KERNEL);
if (!xattr_name)
return -ENOMEM;
strcpy(xattr_name, XATTR_TRUSTED_PREFIX);
strcpy(xattr_name + XATTR_TRUSTED_PREFIX_LEN, name);
res = hfsplus_getxattr(dentry, xattr_name, buffer, size);
kfree(xattr_name);
return res;
}
static int hfsplus_trusted_setxattr(struct dentry *dentry, const char *name,
const void *buffer, size_t size, int flags, int type)
{
char *xattr_name;
int res;
if (!strcmp(name, ""))
return -EINVAL;
xattr_name = kmalloc(NLS_MAX_CHARSET_SIZE * HFSPLUS_ATTR_MAX_STRLEN + 1,
GFP_KERNEL);
if (!xattr_name)
return -ENOMEM;
strcpy(xattr_name, XATTR_TRUSTED_PREFIX);
strcpy(xattr_name + XATTR_TRUSTED_PREFIX_LEN, name);
res = hfsplus_setxattr(dentry, xattr_name, buffer, size, flags);
kfree(xattr_name);
return res;
}
static size_t hfsplus_trusted_listxattr(struct dentry *dentry, char *list,
size_t list_size, const char *name, size_t name_len, int type)
{
return -EOPNOTSUPP;
}
