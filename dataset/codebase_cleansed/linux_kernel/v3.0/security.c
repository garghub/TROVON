int jffs2_init_security(struct inode *inode, struct inode *dir,
const struct qstr *qstr)
{
int rc;
size_t len;
void *value;
char *name;
rc = security_inode_init_security(inode, dir, qstr, &name, &value, &len);
if (rc) {
if (rc == -EOPNOTSUPP)
return 0;
return rc;
}
rc = do_jffs2_setxattr(inode, JFFS2_XPREFIX_SECURITY, name, value, len, 0);
kfree(name);
kfree(value);
return rc;
}
static int jffs2_security_getxattr(struct dentry *dentry, const char *name,
void *buffer, size_t size, int type)
{
if (!strcmp(name, ""))
return -EINVAL;
return do_jffs2_getxattr(dentry->d_inode, JFFS2_XPREFIX_SECURITY,
name, buffer, size);
}
static int jffs2_security_setxattr(struct dentry *dentry, const char *name,
const void *buffer, size_t size, int flags, int type)
{
if (!strcmp(name, ""))
return -EINVAL;
return do_jffs2_setxattr(dentry->d_inode, JFFS2_XPREFIX_SECURITY,
name, buffer, size, flags);
}
static size_t jffs2_security_listxattr(struct dentry *dentry, char *list,
size_t list_size, const char *name, size_t name_len, int type)
{
size_t retlen = XATTR_SECURITY_PREFIX_LEN + name_len + 1;
if (list && retlen <= list_size) {
strcpy(list, XATTR_SECURITY_PREFIX);
strcpy(list + XATTR_SECURITY_PREFIX_LEN, name);
}
return retlen;
}
