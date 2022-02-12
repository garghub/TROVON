static int
xfs_xattr_get(const struct xattr_handler *handler, struct dentry *unused,
struct inode *inode, const char *name, void *value, size_t size)
{
int xflags = handler->flags;
struct xfs_inode *ip = XFS_I(inode);
int error, asize = size;
if (!size) {
xflags |= ATTR_KERNOVAL;
value = NULL;
}
error = xfs_attr_get(ip, (unsigned char *)name, value, &asize, xflags);
if (error)
return error;
return asize;
}
void
xfs_forget_acl(
struct inode *inode,
const char *name,
int xflags)
{
if (xflags & ATTR_ROOT) {
#ifdef CONFIG_XFS_POSIX_ACL
if (!strcmp(name, SGI_ACL_FILE))
forget_cached_acl(inode, ACL_TYPE_ACCESS);
else if (!strcmp(name, SGI_ACL_DEFAULT))
forget_cached_acl(inode, ACL_TYPE_DEFAULT);
#endif
}
}
static int
xfs_xattr_set(const struct xattr_handler *handler, struct dentry *unused,
struct inode *inode, const char *name, const void *value,
size_t size, int flags)
{
int xflags = handler->flags;
struct xfs_inode *ip = XFS_I(inode);
int error;
if (flags & XATTR_CREATE)
xflags |= ATTR_CREATE;
if (flags & XATTR_REPLACE)
xflags |= ATTR_REPLACE;
if (!value)
return xfs_attr_remove(ip, (unsigned char *)name, xflags);
error = xfs_attr_set(ip, (unsigned char *)name,
(void *)value, size, xflags);
if (!error)
xfs_forget_acl(inode, name, xflags);
return error;
}
static int
__xfs_xattr_put_listent(
struct xfs_attr_list_context *context,
char *prefix,
int prefix_len,
unsigned char *name,
int namelen)
{
char *offset;
int arraytop;
if (!context->alist)
goto compute_size;
arraytop = context->count + prefix_len + namelen + 1;
if (arraytop > context->firstu) {
context->count = -1;
context->seen_enough = 1;
return 0;
}
offset = (char *)context->alist + context->count;
strncpy(offset, prefix, prefix_len);
offset += prefix_len;
strncpy(offset, (char *)name, namelen);
offset += namelen;
*offset = '\0';
compute_size:
context->count += prefix_len + namelen + 1;
return 0;
}
static int
xfs_xattr_put_listent(
struct xfs_attr_list_context *context,
int flags,
unsigned char *name,
int namelen,
int valuelen)
{
char *prefix;
int prefix_len;
ASSERT(context->count >= 0);
if (flags & XFS_ATTR_ROOT) {
#ifdef CONFIG_XFS_POSIX_ACL
if (namelen == SGI_ACL_FILE_SIZE &&
strncmp(name, SGI_ACL_FILE,
SGI_ACL_FILE_SIZE) == 0) {
int ret = __xfs_xattr_put_listent(
context, XATTR_SYSTEM_PREFIX,
XATTR_SYSTEM_PREFIX_LEN,
XATTR_POSIX_ACL_ACCESS,
strlen(XATTR_POSIX_ACL_ACCESS));
if (ret)
return ret;
} else if (namelen == SGI_ACL_DEFAULT_SIZE &&
strncmp(name, SGI_ACL_DEFAULT,
SGI_ACL_DEFAULT_SIZE) == 0) {
int ret = __xfs_xattr_put_listent(
context, XATTR_SYSTEM_PREFIX,
XATTR_SYSTEM_PREFIX_LEN,
XATTR_POSIX_ACL_DEFAULT,
strlen(XATTR_POSIX_ACL_DEFAULT));
if (ret)
return ret;
}
#endif
if (!capable(CAP_SYS_ADMIN))
return 0;
prefix = XATTR_TRUSTED_PREFIX;
prefix_len = XATTR_TRUSTED_PREFIX_LEN;
} else if (flags & XFS_ATTR_SECURE) {
prefix = XATTR_SECURITY_PREFIX;
prefix_len = XATTR_SECURITY_PREFIX_LEN;
} else {
prefix = XATTR_USER_PREFIX;
prefix_len = XATTR_USER_PREFIX_LEN;
}
return __xfs_xattr_put_listent(context, prefix, prefix_len, name,
namelen);
}
ssize_t
xfs_vn_listxattr(
struct dentry *dentry,
char *data,
size_t size)
{
struct xfs_attr_list_context context;
struct attrlist_cursor_kern cursor = { 0 };
struct inode *inode = d_inode(dentry);
int error;
memset(&context, 0, sizeof(context));
context.dp = XFS_I(inode);
context.cursor = &cursor;
context.resynch = 1;
context.alist = size ? data : NULL;
context.bufsize = size;
context.firstu = context.bufsize;
context.put_listent = xfs_xattr_put_listent;
error = xfs_attr_list_int(&context);
if (error)
return error;
if (context.count < 0)
return -ERANGE;
return context.count;
}
