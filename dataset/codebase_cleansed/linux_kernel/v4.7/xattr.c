ssize_t v9fs_fid_xattr_get(struct p9_fid *fid, const char *name,
void *buffer, size_t buffer_size)
{
ssize_t retval;
u64 attr_size;
struct p9_fid *attr_fid;
struct kvec kvec = {.iov_base = buffer, .iov_len = buffer_size};
struct iov_iter to;
int err;
iov_iter_kvec(&to, READ | ITER_KVEC, &kvec, 1, buffer_size);
attr_fid = p9_client_xattrwalk(fid, name, &attr_size);
if (IS_ERR(attr_fid)) {
retval = PTR_ERR(attr_fid);
p9_debug(P9_DEBUG_VFS, "p9_client_attrwalk failed %zd\n",
retval);
return retval;
}
if (attr_size > buffer_size) {
if (!buffer_size)
retval = attr_size;
else
retval = -ERANGE;
} else {
iov_iter_truncate(&to, attr_size);
retval = p9_client_read(attr_fid, 0, &to, &err);
if (err)
retval = err;
}
p9_client_clunk(attr_fid);
return retval;
}
ssize_t v9fs_xattr_get(struct dentry *dentry, const char *name,
void *buffer, size_t buffer_size)
{
struct p9_fid *fid;
p9_debug(P9_DEBUG_VFS, "name = %s value_len = %zu\n",
name, buffer_size);
fid = v9fs_fid_lookup(dentry);
if (IS_ERR(fid))
return PTR_ERR(fid);
return v9fs_fid_xattr_get(fid, name, buffer, buffer_size);
}
int v9fs_xattr_set(struct dentry *dentry, const char *name,
const void *value, size_t value_len, int flags)
{
struct p9_fid *fid = v9fs_fid_lookup(dentry);
if (IS_ERR(fid))
return PTR_ERR(fid);
return v9fs_fid_xattr_set(fid, name, value, value_len, flags);
}
int v9fs_fid_xattr_set(struct p9_fid *fid, const char *name,
const void *value, size_t value_len, int flags)
{
struct kvec kvec = {.iov_base = (void *)value, .iov_len = value_len};
struct iov_iter from;
int retval;
iov_iter_kvec(&from, WRITE | ITER_KVEC, &kvec, 1, value_len);
p9_debug(P9_DEBUG_VFS, "name = %s value_len = %zu flags = %d\n",
name, value_len, flags);
fid = p9_client_walk(fid, 0, NULL, 1);
if (IS_ERR(fid))
return PTR_ERR(fid);
retval = p9_client_xattrcreate(fid, name, value_len, flags);
if (retval < 0)
p9_debug(P9_DEBUG_VFS, "p9_client_xattrcreate failed %d\n",
retval);
else
p9_client_write(fid, 0, &from, &retval);
p9_client_clunk(fid);
return retval;
}
ssize_t v9fs_listxattr(struct dentry *dentry, char *buffer, size_t buffer_size)
{
return v9fs_xattr_get(dentry, NULL, buffer, buffer_size);
}
static int v9fs_xattr_handler_get(const struct xattr_handler *handler,
struct dentry *dentry, struct inode *inode,
const char *name, void *buffer, size_t size)
{
const char *full_name = xattr_full_name(handler, name);
return v9fs_xattr_get(dentry, full_name, buffer, size);
}
static int v9fs_xattr_handler_set(const struct xattr_handler *handler,
struct dentry *dentry, struct inode *inode,
const char *name, const void *value,
size_t size, int flags)
{
const char *full_name = xattr_full_name(handler, name);
return v9fs_xattr_set(dentry, full_name, value, size, flags);
}
